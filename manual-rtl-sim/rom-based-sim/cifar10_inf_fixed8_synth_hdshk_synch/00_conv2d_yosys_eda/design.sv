`timescale 1ns / 1ps

module conv2d_mem #(
    parameter WIDTH    = 32,
    parameter HEIGHT   = 32,
    parameter CHANNELS = 3,
    parameter FILTERS  = 16,
    parameter K        = 3,
    parameter PAD      = 1,
    parameter BIAS_MODE_POST_ADD = 1
)(
    input  wire clk,
    input  wire rst,
    input  wire start,
    output reg  done,

    // Image ROM interface (broadcast addr to 3 channels)
    output reg  [9:0] image_addr,
    output reg        image_addr_valid,
    input  wire       image_addr_ready,
    input  wire [7:0] image_r_data,
    input  wire [7:0] image_g_data,
    input  wire [7:0] image_b_data,
    input  wire       image_data_valid,
    output reg        image_data_ready,

    // Kernel ROM interface
    output reg  [8:0] kernel_addr,
    output reg        kernel_addr_valid,
    input  wire       kernel_addr_ready,
    input  wire [7:0] kernel_data,
    input  wire       kernel_data_valid,
    output reg        kernel_data_ready,

    // Bias ROM interface
    output reg  [3:0] bias_addr,
    output reg        bias_addr_valid,
    input  wire       bias_addr_ready,
    input  wire [7:0] bias_data,
    input  wire       bias_data_valid,
    output reg        bias_data_ready,

    // Output stream
    output reg  [31:0] out_data,
    output reg         out_valid
);

    // -------------------------
    // Indices / counters
    // -------------------------
    integer f, i, j;          // filter, row, col
    integer m, n, c;          // K, K, channel
    integer in_x, in_y;
    integer kernel_row;

    // -------------------------
    // Datapath regs
    // -------------------------
    reg  signed [63:0] accum;
    reg  signed [63:0] numerator;
    reg  signed [47:0] kernel_mul;
    reg  signed [31:0] out_int;
    reg  signed [31:0] out_int_relu;
    reg  [7:0]         pix8;
    reg  signed [15:0] pix_signed;
    reg  signed [15:0] kern16;
    reg  signed [15:0] bias16;

    // Latched ROM outputs
    reg [7:0] image_r_q, image_g_q, image_b_q;
    reg [7:0] kernel_q;
    reg [7:0] bias_q;

    // -------------------------
    // FSM
    // -------------------------
    reg [5:0] state;

    localparam S_IDLE          = 0,
               S_START_FILTER  = 1,
               S_BIAS_REQ      = 2,
               S_BIAS_WAIT     = 3,
               S_SETUP_PIXEL   = 4,
               S_MAC_DECIDE    = 5,
               S_IMG_REQ       = 6,
               S_IMG_WAIT      = 7,
               S_KERN_REQ      = 8,
               S_KERN_WAIT     = 9,
               S_MAC_ACCUM     = 10,
               S_PIXEL_DONE    = 11,
               S_NEXT_PIXEL    = 12,
               S_NEXT_FILTER   = 13,
               S_DONE          = 14;

    // -------------------------
    // Main FSM
    // -------------------------
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state     <= S_IDLE;
            done      <= 1'b0;
            out_valid <= 1'b0;
            out_data  <= 32'd0;

            f <= 0; i <= 0; j <= 0;
            m <= 0; n <= 0; c <= 0;

            image_addr       <= 0;
            image_addr_valid <= 1'b0;
            image_data_ready <= 1'b0;

            kernel_addr       <= 0;
            kernel_addr_valid <= 1'b0;
            kernel_data_ready <= 1'b0;

            bias_addr       <= 0;
            bias_addr_valid <= 1'b0;
            bias_data_ready <= 1'b0;

            accum <= 64'sd0;
        end else begin
            // defaults
            image_addr_valid  <= 1'b0;
            image_data_ready  <= 1'b0;
            kernel_addr_valid <= 1'b0;
            kernel_data_ready <= 1'b0;
            bias_addr_valid   <= 1'b0;
            bias_data_ready   <= 1'b0;

            case (state)
                // -------------------
                S_IDLE: begin
                    done      <= 1'b0;
                    out_valid <= 1'b0;
                    if (start) begin
                        f <= 0; i <= 0; j <= 0;
                        state <= S_START_FILTER;
                    end
                end

                // -------------------
                // Request bias
                S_START_FILTER: begin
                    bias_addr       <= f[3:0];
                    bias_addr_valid <= 1'b1;
                    if (bias_addr_ready)
                        state <= S_BIAS_WAIT;
                end

                S_BIAS_WAIT: begin
                    if (bias_data_valid) begin
                        bias_data_ready <= 1'b1;
                        bias_q  <= bias_data;
                        bias16  <= $signed(bias_data);
                        state   <= S_SETUP_PIXEL;
                    end
                end

                // -------------------
                // Init accumulation for pixel
                S_SETUP_PIXEL: begin
                    accum <= 64'sd0;
                    m <= 0; n <= 0; c <= 0;
                    out_valid <= 1'b0;
                    state <= S_MAC_DECIDE;
                end

                // -------------------
                S_MAC_DECIDE: begin
                    in_y = i + m - PAD;
                    in_x = j + n - PAD;
                    if ((in_y < 0) || (in_y >= HEIGHT) || (in_x < 0) || (in_x >= WIDTH)) begin
                        state <= S_MAC_ACCUM;
                    end else begin
                        // request image
                        image_addr       <= in_y * WIDTH + in_x;
                        image_addr_valid <= 1'b1;
                        if (image_addr_ready)
                            state <= S_IMG_WAIT;
                    end
                end

                // wait image
                S_IMG_WAIT: begin
                    if (image_data_valid) begin
                        image_data_ready <= 1'b1;
                        image_r_q <= image_r_data;
                        image_g_q <= image_g_data;
                        image_b_q <= image_b_data;

                        // then request kernel
                        kernel_row  = m * K * CHANNELS + n * CHANNELS + c;
                        kernel_addr <= kernel_row * FILTERS + f;
                        kernel_addr_valid <= 1'b1;
                        if (kernel_addr_ready)
                            state <= S_KERN_WAIT;
                    end
                end

                // wait kernel
                S_KERN_WAIT: begin
                    if (kernel_data_valid) begin
                        kernel_data_ready <= 1'b1;
                        kernel_q <= kernel_data;
                        state <= S_MAC_ACCUM;
                    end
                end

                // -------------------
                // Accumulate
                S_MAC_ACCUM: begin
                    in_y = i + m - PAD;
                    in_x = j + n - PAD;
                    if (!((in_y < 0) || (in_y >= HEIGHT) || (in_x < 0) || (in_x >= WIDTH))) begin
                        case (c)
                            0: pix8 = image_r_q;
                            1: pix8 = image_g_q;
                            default: pix8 = image_b_q;
                        endcase
                        pix_signed = $signed({8'd0, pix8});
                        kern16     = $signed(kernel_q);
                        kernel_mul = kern16 * pix_signed;
                        accum      <= accum + kernel_mul;
                    end

                    if (c + 1 < CHANNELS) begin
                        c <= c + 1;
                        state <= S_MAC_DECIDE;
                    end else begin
                        c <= 0;
                        if (n + 1 < K) begin
                            n <= n + 1;
                            state <= S_MAC_DECIDE;
                        end else begin
                            n <= 0;
                            if (m + 1 < K) begin
                                m <= m + 1;
                                state <= S_MAC_DECIDE;
                            end else begin
                                state <= S_PIXEL_DONE;
                            end
                        end
                    end
                end

                // -------------------
                S_PIXEL_DONE: begin
                    if (BIAS_MODE_POST_ADD) begin
                        numerator = accum;
                        if (numerator >= 0)
                            out_int = ((numerator * 257) + (1<<15)) >>> 16;
                        else
                            out_int = -(((-numerator * 257) + (1<<15)) >>> 16);
                        out_int = out_int + bias16;
                    end else begin
                        numerator = accum + (bias16 * 32'sd255);
                        if (numerator >= 0)
                            out_int = ((numerator * 257) + (1<<15)) >>> 16;
                        else
                            out_int = -(((-numerator * 257) + (1<<15)) >>> 16);
                    end

                    if (out_int < 0)
                        out_int_relu = 32'sd0;
                    else
                        out_int_relu = out_int;

                    out_data  <= out_int_relu;
                    out_valid <= 1'b1;

                    state <= S_NEXT_PIXEL;
                end

                S_NEXT_PIXEL: begin
                    out_valid <= 1'b0;
                    if (j + 1 < WIDTH) begin
                        j <= j + 1;
                        state <= S_SETUP_PIXEL;
                    end else begin
                        j <= 0;
                        if (i + 1 < HEIGHT) begin
                            i <= i + 1;
                            state <= S_SETUP_PIXEL;
                        end else begin
                            i <= 0;
                            state <= S_NEXT_FILTER;
                        end
                    end
                end

                S_NEXT_FILTER: begin
                    if (f + 1 < FILTERS) begin
                        f <= f + 1;
                        state <= S_START_FILTER;
                    end else begin
                        state <= S_DONE;
                    end
                end

                S_DONE: begin
                    done <= 1'b1;
                    out_valid <= 1'b0;
                end

                default: state <= S_IDLE;
            endcase
        end
    end
endmodule
