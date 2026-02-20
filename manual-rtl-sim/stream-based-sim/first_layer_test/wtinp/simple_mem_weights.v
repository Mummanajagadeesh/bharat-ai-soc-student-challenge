`timescale 1ns/1ps

module simple_mem_weights #(
    parameter SIZE = 1024
)(
    input  wire clk,
    input  wire        req_valid,
    input  wire [31:0] req_addr,
    output reg         resp_valid,
    output reg  [7:0]  resp_data
);

    reg [7:0] mem [0:SIZE-1];

    always @(posedge clk) begin
        resp_valid <= req_valid;
        if (req_valid)
            resp_data <= mem[req_addr];
    end

endmodule
