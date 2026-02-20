`timescale 1ns/1ps

module simple_mem_rw #(
    parameter DEPTH = 256
)(
    input  wire clk,

    // read
    input  wire        rd_valid,
    input  wire [31:0] rd_addr,
    output reg  [7:0]  rd_data,

    // write
    input  wire        wr_valid,
    input  wire [31:0] wr_addr,
    input  wire [7:0]  wr_data
);

    reg [7:0] mem [0:DEPTH-1];

    integer i;
    initial begin
        for (i = 0; i < DEPTH; i = i + 1)
            mem[i] = 8'h00;
    end

    always @(posedge clk) begin
        if (wr_valid)
            mem[wr_addr] <= wr_data;

        if (rd_valid)
            rd_data <= mem[rd_addr];
    end

endmodule
