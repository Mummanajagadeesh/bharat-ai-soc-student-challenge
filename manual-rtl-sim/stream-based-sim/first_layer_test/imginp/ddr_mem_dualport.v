`timescale 1ns/1ps

module ddr_mem_dualport #(
    parameter DDR_SIZE = 1 << 16,
    parameter READ_LATENCY = 3
)(
    input  wire clk,
    input  wire rst_n,

    // PORT A (READ)
    input  wire        a_req_valid,
    input  wire [31:0] a_req_addr,
    output reg         a_resp_valid,
    output reg  [7:0]  a_resp_rdata,

    // PORT B (WRITE)
    input  wire        b_req_valid,
    input  wire [31:0] b_req_addr,
    input  wire [7:0]  b_req_wdata
);

    reg [7:0] ddr_mem [0:DDR_SIZE-1];

    reg [31:0] rd_addr_pipe [0:READ_LATENCY-1];
    reg        rd_valid_pipe[0:READ_LATENCY-1];

    integer i;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (i=0;i<READ_LATENCY;i=i+1) begin
                rd_valid_pipe[i] <= 0;
                rd_addr_pipe[i]  <= 0;
            end
            a_resp_valid <= 0;
            a_resp_rdata <= 0;
        end else begin
            for (i=READ_LATENCY-1;i>0;i=i-1) begin
                rd_valid_pipe[i] <= rd_valid_pipe[i-1];
                rd_addr_pipe[i]  <= rd_addr_pipe[i-1];
            end

            rd_valid_pipe[0] <= a_req_valid;
            rd_addr_pipe[0]  <= a_req_addr;

            a_resp_valid <= rd_valid_pipe[READ_LATENCY-1];
            if (rd_valid_pipe[READ_LATENCY-1])
                a_resp_rdata <= ddr_mem[rd_addr_pipe[READ_LATENCY-1]];
        end
    end

    always @(posedge clk) begin
        if (b_req_valid)
            ddr_mem[b_req_addr] <= b_req_wdata;
    end

endmodule
