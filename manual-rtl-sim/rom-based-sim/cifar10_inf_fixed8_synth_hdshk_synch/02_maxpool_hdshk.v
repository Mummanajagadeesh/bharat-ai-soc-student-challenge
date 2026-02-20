`timescale 1ns / 1ps
// max_pool_mem: streaming max-pool (2x2, stride 2) using IFM handshake reads.
// Inputs: IFM read handshake (addr, chan) -> data (signed [15:0], Q1.7)
// Outputs: streamed pooled outputs (out_data, out_valid), done.
module max_pool_mem #(
    parameter WIDTH_IN  = 32,
    parameter HEIGHT_IN = 32,
    parameter CHANNELS  = 16,
    parameter POOL_SIZE = 2,
    parameter STRIDE    = 2
)(
    input  wire clk,
    input  wire rst,
    input  wire start,
    output reg done,

    // IFM read handshake (served by TB)
    output reg  [9:0]            ifm_addr,
    output reg  [3:0]            ifm_chan,
    output reg                   ifm_addr_valid,
    input  wire                  ifm_addr_ready,

    input  wire signed [15:0]    ifm_data,       // Q1.7
    input  wire                  ifm_data_valid,
    output reg                   ifm_data_ready,

    // Output pooled stream (Q1.7 int)
    output reg signed [31:0]     out_data,
    output reg                   out_valid
);

    // Derived sizes
    localparam WIDTH_OUT  = (WIDTH_IN  - POOL_SIZE) / STRIDE + 1;
    localparam HEIGHT_OUT = (HEIGHT_IN - POOL_SIZE) / STRIDE + 1;

    // indices
    integer c, ph, pw;
    integer pi, pj;
    integer in_x, in_y;

    // temp regs
    reg signed [15:0] max_val;       // KEEP as 16-bit Q1.7
    reg signed [15:0] sample_q17;

    // FSM
    reg [4:0] state;
    localparam S_IDLE      = 0,
               S_START     = 1,
               S_INIT_CELL = 2,
               S_REQ       = 3,
               S_WAIT      = 4,
               S_ACC       = 5,
               S_OUTPUT    = 6,
               S_NEXT      = 7,
               S_DONE      = 8;

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= S_IDLE;
            done  <= 1'b0;
            out_valid <= 1'b0;
            out_data  <= 32'sd0;

            ifm_addr       <= 10'd0;
            ifm_chan       <= 4'd0;
            ifm_addr_valid <= 1'b0;
            ifm_data_ready <= 1'b0;

            c  <= 0; ph <= 0; pw <= 0;
            pi <= 0; pj <= 0;
            max_val <= -16'sd32768; // 16-bit min sentinel
        end else begin
            // defaults
            ifm_addr_valid <= 1'b0;
            ifm_data_ready <= 1'b0;
            out_valid      <= 1'b0;

            case (state)
                S_IDLE: begin
                    done <= 1'b0;
                    if (start) begin
                        c <= 0;
                        ph <= 0; pw <= 0;
                        state <= S_START;
                    end
                end

                S_START: begin
                    state <= S_INIT_CELL;
                end

                S_INIT_CELL: begin
                    pi <= 0; pj <= 0;
                    max_val <= -16'sd32768; // reset per cell
                    state <= S_REQ;
                end

                // Form request for the current (pi,pj) element within pool window
                S_REQ: begin
                    in_y = ph * STRIDE + pi;
                    in_x = pw * STRIDE + pj;
                    ifm_addr       <= in_y * WIDTH_IN + in_x;
                    ifm_chan       <= c[3:0];
                    ifm_addr_valid <= 1'b1;
                    if (ifm_addr_ready) state <= S_WAIT;
                end

                S_WAIT: begin
                    if (ifm_data_valid) begin
                        ifm_data_ready <= 1'b1;
                        sample_q17 <= ifm_data; // signed [15:0]
                        state <= S_ACC;
                    end
                end

                S_ACC: begin
                    // update max (both are signed 16-bit)
                    if (sample_q17 > max_val)
                        max_val <= sample_q17;

                    // advance window counters
                    if (pj + 1 < POOL_SIZE) begin
                        pj <= pj + 1;
                        state <= S_REQ;
                    end else begin
                        pj <= 0;
                        if (pi + 1 < POOL_SIZE) begin
                            pi <= pi + 1;
                            state <= S_REQ;
                        end else begin
                            // done on this pooled cell
                            state <= S_OUTPUT;
                        end
                    end
                end

                S_OUTPUT: begin
                    // sign-extend 16->32 and emit pooled value (Q1.7)
                    out_data  <= { {16{max_val[15]}}, max_val };
                    out_valid <= 1'b1;
                    state <= S_NEXT;
                end

                S_NEXT: begin
                    out_valid <= 1'b0;
                    // advance pw/ph/c
                    if (pw + 1 < WIDTH_OUT) begin
                        pw <= pw + 1;
                        state <= S_INIT_CELL;
                    end else begin
                        pw <= 0;
                        if (ph + 1 < HEIGHT_OUT) begin
                            ph <= ph + 1;
                            state <= S_INIT_CELL;
                        end else begin
                            ph <= 0;
                            if (c + 1 < CHANNELS) begin
                                c <= c + 1;
                                state <= S_INIT_CELL;
                            end else begin
                                state <= S_DONE;
                            end
                        end
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
