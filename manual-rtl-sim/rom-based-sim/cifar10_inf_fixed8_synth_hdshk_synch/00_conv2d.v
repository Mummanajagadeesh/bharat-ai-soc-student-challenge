`timescale 1ns / 1ps

// FULL K×K×CHANNELS convolution with two-cycle ROM reads (synchronous ROMs)
// Synthesizable: no $display/$fwrite/$fopen.
//
// Bias handling modes:
//   0 = PRE_SCALED  : accum starts at bias*255; out = round( (sum + bias*255)/255 ) == bias + round(sum/255)
//   1 = POST_ADD    : accum starts at 0; out = bias + round( sum/255 )
// Default = POST_ADD (matches your "expected" numbers that were exactly +5 vs prior outputs)

module conv2d_mem #(
    parameter WIDTH    = 32,
    parameter HEIGHT   = 32,
    parameter CHANNELS = 3,
    parameter FILTERS  = 16,
    parameter K        = 3,
    parameter PAD      = 1,
    parameter BIAS_MODE_POST_ADD = 1  // 1=POST_ADD (default), 0=PRE_SCALED
)(
    input  wire clk,
    input  wire rst,
    input  wire start,
    output reg  done,

    // Image ROM (3 channels share same address)
    output reg  [9:0] image_addr,
    input  wire [7:0] image_r_data,
    input  wire [7:0] image_g_data,
    input  wire [7:0] image_b_data,

    // Kernel ROM
    output reg  [8:0] kernel_addr,
    input  wire [7:0] kernel_data,

    // Bias ROM
    output reg  [3:0] bias_addr,
    input  wire [7:0] bias_data,

    // Output stream: one pixel per VALID
    output reg  [31:0] out_data,
    output reg  out_valid
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
    reg  signed [63:0] accum;        // sum of k*pix
    reg  signed [63:0] numerator;    // for division
    reg  signed [47:0] kernel_mul;   // product
    reg  signed [31:0] out_int;
    reg  signed [31:0] out_int_relu;
    reg  [7:0]         pix8;
    reg  signed [15:0] pix_signed;
    reg  signed [15:0] kern16;
    reg  signed [15:0] bias16;

    // Latches for synchronous ROM outputs (captured after two waits)
    reg [7:0] image_r_q, image_g_q, image_b_q;
    reg [7:0] kernel_q;
    reg [7:0] bias_q;

    // -------------------------
    // FSM
    // -------------------------
    reg [4:0] state;

    localparam S_IDLE          = 0,
               S_START_FILTER  = 1,
               S_BIAS_WAIT1    = 2,
               S_BIAS_WAIT2    = 3,
               S_SETUP_PIXEL   = 4,
               S_MAC_DECIDE    = 5,
               S_MAC_WAIT1     = 6,
               S_MAC_WAIT2     = 7,
               S_MAC_ACCUM     = 8,
               S_PIXEL_DONE    = 9,
               S_NEXT_PIXEL    = 10,
               S_NEXT_FILTER   = 11,
               S_DONE          = 12;

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

            image_addr  <= 0;
            kernel_addr <= 0;
            bias_addr   <= 0;

            accum <= 64'sd0;
        end else begin
            case (state)
                // -------------------
                S_IDLE: begin
                    done      <= 1'b0;
                    out_valid <= 1'b0;
                    if (start) begin
                        f <= 0;
                        i <= 0;
                        j <= 0;
                        state <= S_START_FILTER;
                    end
                end

                // -------------------
                // Load bias for filter f (two-cycle sync read)
                S_START_FILTER: begin
                    bias_addr <= f[3:0];
                    state <= S_BIAS_WAIT1;
                end

                S_BIAS_WAIT1: begin
                    state <= S_BIAS_WAIT2;
                end

                S_BIAS_WAIT2: begin
                    bias_q  <= bias_data;
                    bias16  <= $signed(bias_data);
                    // start first pixel
                    state <= S_SETUP_PIXEL;
                end

                // -------------------
                // Initialize accumulation for pixel (i,j)
                S_SETUP_PIXEL: begin
                    // accum holds only the Σ(k * pix). Bias is added at the end (POST_ADD),
                    // or equivalently pre-scaled to bias*255 then divided (PRE_SCALED).
                    accum <= 64'sd0;
                    m <= 0; n <= 0; c <= 0;
                    out_valid <= 1'b0;
                    state <= S_MAC_DECIDE;
                end

                // Decide whether current (m,n,c) contributes (padding check)
                S_MAC_DECIDE: begin
                    in_y = i + m - PAD;
                    in_x = j + n - PAD;

                    if ((in_y < 0) || (in_y >= HEIGHT) || (in_x < 0) || (in_x >= WIDTH)) begin
                        // Out of bounds: skip read, just advance indices via MAC_ACCUM
                        state <= S_MAC_ACCUM;
                    end else begin
                        // In bounds: set addresses and do 2-cycle wait
                        image_addr  <= in_y * WIDTH + in_x;
                        kernel_row  = m * K * CHANNELS + n * CHANNELS + c; // [0..K*K*C-1]
                        kernel_addr <= kernel_row * FILTERS + f;           // flatten with filter
                        state <= S_MAC_WAIT1;
                    end
                end

                // Two-cycle handshake for synchronous ROMs
                S_MAC_WAIT1: begin
                    state <= S_MAC_WAIT2;
                end

                S_MAC_WAIT2: begin
                    // capture after two waits
                    image_r_q <= image_r_data;
                    image_g_q <= image_g_data;
                    image_b_q <= image_b_data;
                    kernel_q  <= kernel_data;
                    state <= S_MAC_ACCUM;
                end

                // Accumulate (or just advance indices if OOB)
                S_MAC_ACCUM: begin
                    // If we actually fetched data (in-bounds), do MAC
                    in_y = i + m - PAD;
                    in_x = j + n - PAD;

                    if (!((in_y < 0) || (in_y >= HEIGHT) || (in_x < 0) || (in_x >= WIDTH))) begin
                        // pick pixel channel
                        case (c)
                            0: pix8 = image_r_q;
                            1: pix8 = image_g_q;
                            default: pix8 = image_b_q;
                        endcase

                        // sign conversions & MAC
                        pix_signed = $signed({8'd0, pix8});  // 0..255 -> signed 16
                        kern16     = $signed(kernel_q);      // sign-extend kernel byte (-128..127)
                        kernel_mul = kern16 * pix_signed;    // fits in 32; keep wide
                        accum      <= accum + kernel_mul;
                    end

                    // advance (c,n,m)
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
                                // finished all MACs for this pixel
                                state <= S_PIXEL_DONE;
                            end
                        end
                    end
                end

                // Finalize pixel: normalize by 255 with rounding, add bias (POST_ADD) or pre-scaled equivalent
                S_PIXEL_DONE: begin
                    if (BIAS_MODE_POST_ADD) begin
                        // out = bias + round( sum/255 )
                        numerator = accum;
                        if (numerator >= 0)
                            out_int = ((numerator * 257) + (1<<15)) >>> 16; // round((num*257)/65536)
                        else
                            out_int = -(((-numerator * 257) + (1<<15)) >>> 16);
                        out_int = out_int + bias16;
                    end else begin
                        // out = round( (sum + bias*255) / 255 )
                        numerator = accum + (bias16 * 32'sd255);
                        if (numerator >= 0)
                            out_int = ((numerator * 257) + (1<<15)) >>> 16;
                        else
                            out_int = -(((-numerator * 257) + (1<<15)) >>> 16);
                    end

                    // ReLU
                    if (out_int < 0)
                        out_int_relu = 32'sd0;
                    else
                        out_int_relu = out_int;

                    out_data  <= out_int_relu;
                    out_valid <= 1'b1;

                    state <= S_NEXT_PIXEL;
                end


                // Advance j/i; if done with image, advance filter
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
                            // finished all pixels for this filter
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

                default: begin
                    state <= S_IDLE;
                end
            endcase
        end
    end
endmodule
