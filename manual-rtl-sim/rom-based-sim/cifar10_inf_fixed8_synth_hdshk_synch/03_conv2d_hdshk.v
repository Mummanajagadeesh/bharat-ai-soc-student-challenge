`timescale 1ns / 1ps
module conv2d_third_mem #(
    parameter WIDTH    = 16,
    parameter HEIGHT   = 16,
    parameter CHANNELS = 16,
    parameter FILTERS  = 32,
    parameter K        = 3,
    parameter PAD      = 1
)(
    input  wire clk,
    input  wire rst,
    input  wire start,
    output reg  done,

    // IFM read handshake (served by TB)
    output reg  [9:0]            ifm_addr,
    output reg  [3:0]            ifm_chan,
    output reg                   ifm_addr_valid,
    input  wire                  ifm_addr_ready,

    input  wire signed [15:0]    ifm_data,       // Q1.7
    input  wire                  ifm_data_valid,
    output reg                   ifm_data_ready,

    // Kernel ROM (03_conv2d_2_kernel) handshake
    output reg  [12:0]           kernel_addr,    // depth 4608
    output reg                   kernel_addr_valid,
    input  wire                  kernel_addr_ready,

    input  wire signed [7:0]     kernel_data,    // Q1.7
    input  wire                  kernel_data_valid,
    output reg                   kernel_data_ready,

    // Bias ROM (03_conv2d_2_bias) handshake
    output reg  [4:0]            bias_addr,
    output reg                   bias_addr_valid,
    input  wire                  bias_addr_ready,

    input  wire signed [7:0]     bias_data,      // Q1.7
    input  wire                  bias_data_valid,
    output reg                   bias_data_ready,

    // Output stream (Q1.7 int after ReLU)
    output reg signed [31:0]     out_data,
    output reg                   out_valid
);

    // indices
    integer f, i, j;
    integer m, n, c;
    integer in_x, in_y;
    integer kernel_row;

    // datapath
    reg signed [63:0] accum;         // wide accumulator
    reg signed [31:0] tmp_q17;
    reg signed [31:0] out_q17_relu;
    reg signed [15:0] ifm_q;
    reg signed [7:0]  w_q;
    reg signed [7:0]  b_q;
    reg signed [31:0] prod;

    // FSM
    reg [5:0] state;
    localparam S_IDLE         = 0,
               S_START_FILTER = 1,
               S_BIAS_REQ     = 2,
               S_BIAS_WAIT    = 3,
               S_SETUP_PIXEL  = 4,
               S_MAC_DECIDE   = 5,
               S_IFM_REQ      = 6,
               S_IFM_WAIT     = 7,
               S_KERN_REQ     = 8,
               S_KERN_WAIT    = 9,
               S_MAC_ACCUM    = 10,
               S_PIXEL_DONE   = 11,
               S_NEXT_PIXEL   = 12,
               S_NEXT_FILTER  = 13,
               S_DONE         = 14;

    // rounding constant (2^(7-1) = 64) for shifting >>>7
    localparam signed [31:0] ROUND = 32'sd64;

    // helper: compute kernel addr = (m*K*C + n*C + c) * FILTERS + f
    function automatic [12:0] calc_kernel_addr;
        input integer mm, nn, cc, ff;
        integer krow;
        begin
            krow = mm * K * CHANNELS + nn * CHANNELS + cc;
            calc_kernel_addr = krow * FILTERS + ff;
        end
    endfunction

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= S_IDLE;
            done <= 1'b0;
            out_valid <= 1'b0;
            out_data  <= 32'sd0;

            f <= 0; i <= 0; j <= 0;
            m <= 0; n <= 0; c <= 0;

            ifm_addr_valid <= 1'b0;
            ifm_data_ready <= 1'b0;

            kernel_addr_valid <= 1'b0;
            kernel_data_ready <= 1'b0;

            bias_addr_valid <= 1'b0;
            bias_data_ready <= 1'b0;

            accum <= 64'sd0;
            b_q   <= 8'sd0;
        end else begin
            // defaults
            ifm_addr_valid    <= 1'b0;
            ifm_data_ready    <= 1'b0;
            kernel_addr_valid <= 1'b0;
            kernel_data_ready <= 1'b0;
            bias_addr_valid   <= 1'b0;
            bias_data_ready   <= 1'b0;
            out_valid         <= 1'b0;

            case (state)
                S_IDLE: begin
                    done <= 1'b0;
                    if (start) begin
                        f <= 0; i <= 0; j <= 0;
                        state <= S_START_FILTER;
                    end
                end

                S_START_FILTER: begin
                    bias_addr <= f[4:0];
                    bias_addr_valid <= 1'b1;
                    if (bias_addr_ready) state <= S_BIAS_WAIT;
                end

                S_BIAS_WAIT: begin
                    if (bias_data_valid) begin
                        bias_data_ready <= 1'b1;
                        b_q <= bias_data;   // Q1.7 s8
                        state <= S_SETUP_PIXEL;
                    end
                end

                S_SETUP_PIXEL: begin
                    accum <= 64'sd0;
                    m <= 0; n <= 0; c <= 0;
                    state <= S_MAC_DECIDE;
                end

                S_MAC_DECIDE: begin
                    in_y = i + m - PAD;
                    in_x = j + n - PAD;
                    if ((in_y < 0) || (in_y >= HEIGHT) || (in_x < 0) || (in_x >= WIDTH)) begin
                        // padding: skip
                        state <= S_MAC_ACCUM;
                    end else begin
                        // request IFM (channel c)
                        ifm_addr <= in_y * WIDTH + in_x;
                        ifm_chan <= c[3:0];
                        ifm_addr_valid <= 1'b1;
                        if (ifm_addr_ready) state <= S_IFM_WAIT;
                    end
                end

                S_IFM_WAIT: begin
                    if (ifm_data_valid) begin
                        ifm_data_ready <= 1'b1;
                        ifm_q <= ifm_data;   // Q1.7 int
                        // request kernel
                        kernel_addr <= calc_kernel_addr(m, n, c, f);
                        kernel_addr_valid <= 1'b1;
                        if (kernel_addr_ready) state <= S_KERN_WAIT;
                    end
                end

                S_KERN_WAIT: begin
                    if (kernel_data_valid) begin
                        kernel_data_ready <= 1'b1;
                        w_q <= kernel_data;  // Q1.7 s8
                        state <= S_MAC_ACCUM;
                    end
                end

                S_MAC_ACCUM: begin
                    in_y = i + m - PAD;
                    in_x = j + n - PAD;
                    if (!((in_y < 0) || (in_y >= HEIGHT) || (in_x < 0) || (in_x >= WIDTH))) begin
                        // prod = ifm_q * w_q  (Q1.7 * Q1.7 -> Q14 held in 32 bits)
                        prod = $signed(ifm_q) * $signed(w_q);
                        accum <= accum + $signed(prod);
                    end

                    // advance c,n,m
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

                S_PIXEL_DONE: begin
                    // accum contains sum of Q14 terms. Round & shift by 7 (>>>7) to bring to Q1.7 domain.
                    if (accum >= 0)
                        tmp_q17 = (accum + ROUND) >>> 7;
                    else
                        tmp_q17 = -(((-accum + ROUND) >>> 7));

                    // add bias (b_q is s8 Q1.7, sign-extend)
                    tmp_q17 = tmp_q17 + $signed(b_q);

                    // ReLU
                    if (tmp_q17 < 0) out_q17_relu = 32'sd0;
                    else out_q17_relu = tmp_q17;

                    out_data <= out_q17_relu;
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
                end

                default: state <= S_IDLE;
            endcase
        end
    end
endmodule
