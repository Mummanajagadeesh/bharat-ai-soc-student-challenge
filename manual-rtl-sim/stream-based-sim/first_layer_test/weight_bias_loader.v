`timescale 1ns/1ps

module weight_bias_loader #(
    parameter W_COUNT = 756,
    parameter B_COUNT = 28
)(
    input  wire clk,
    input  wire rst_n,

    input  wire start,
    output reg  done,

    // DDR interface
    output reg        mem_req_valid,
    output wire       mem_req_write,
    output reg [31:0] mem_req_addr,
    input  wire       mem_resp_valid,
    input  wire [7:0] mem_resp_data
);

    assign mem_req_write = 1'b0;

    // internal storage
    reg signed [7:0] weight_mem [0:W_COUNT-1];
    reg signed [7:0] bias_mem   [0:B_COUNT-1];

    localparam ST_IDLE   = 2'd0;
    localparam ST_WEIGHT = 2'd1;
    localparam ST_BIAS   = 2'd2;
    localparam ST_DONE   = 2'd3;

    reg [1:0]  state;
    reg [31:0] idx;
    reg        req_pending;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state         <= ST_IDLE;
            idx           <= 0;
            mem_req_valid <= 0;
            mem_req_addr  <= 0;
            done          <= 0;
            req_pending   <= 0;
        end else begin
            mem_req_valid <= 0;
            done <= 0;

            case (state)

                ST_IDLE: begin
                    if (start) begin
                        idx <= 0;
                        req_pending <= 0;
                        state <= ST_WEIGHT;
                    end
                end

                ST_WEIGHT: begin
                    // issue request if none pending
                    if (!req_pending && idx < W_COUNT) begin
                        mem_req_valid <= 1;
                        mem_req_addr  <= idx;
                        req_pending   <= 1;
                    end

                    // capture response
                    if (mem_resp_valid && req_pending) begin
                        weight_mem[idx] <= mem_resp_data;
                        idx <= idx + 1;
                        req_pending <= 0;
                    end

                    if (idx == W_COUNT && !req_pending) begin
                        idx <= 0;
                        state <= ST_BIAS;
                    end
                end

                ST_BIAS: begin
                    if (!req_pending && idx < B_COUNT) begin
                        mem_req_valid <= 1;
                        mem_req_addr  <= W_COUNT + idx;
                        req_pending   <= 1;
                    end

                    if (mem_resp_valid && req_pending) begin
                        bias_mem[idx] <= mem_resp_data;
                        idx <= idx + 1;
                        req_pending <= 0;
                    end

                    if (idx == B_COUNT && !req_pending) begin
                        state <= ST_DONE;
                    end
                end

                ST_DONE: begin
                    done <= 1;
                    state <= ST_IDLE;
                end

            endcase
        end
    end

endmodule
