`timescale 1ns/1ps

module simple_mem #(
    parameter DEPTH = 256,
    parameter READ_LATENCY = 2
)(
    input  wire clk,

    input  wire        rd_valid,
    input  wire [31:0] rd_addr,

    output reg         rd_resp_valid,
    output reg  [7:0]  rd_resp_data
);

    reg [7:0] mem [0:DEPTH-1];

    reg [31:0] addr_pipe [0:READ_LATENCY-1];
    reg        valid_pipe[0:READ_LATENCY-1];

    integer i;

    initial begin
        for (i = 0; i < DEPTH; i = i + 1)
            mem[i] = i[7:0];
    end

    always @(posedge clk) begin
        valid_pipe[0] <= rd_valid;
        addr_pipe[0]  <= rd_addr;

        for (i = 1; i < READ_LATENCY; i = i + 1) begin
            valid_pipe[i] <= valid_pipe[i-1];
            addr_pipe[i]  <= addr_pipe[i-1];
        end

        rd_resp_valid <= valid_pipe[READ_LATENCY-1];
        if (valid_pipe[READ_LATENCY-1])
            rd_resp_data <= mem[addr_pipe[READ_LATENCY-1]];
    end

endmodule
