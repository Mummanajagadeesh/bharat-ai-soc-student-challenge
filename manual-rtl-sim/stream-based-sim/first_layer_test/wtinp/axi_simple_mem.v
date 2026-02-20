`timescale 1ns/1ps

module axi_simple_mem #(
    parameter SIZE = 1024
)(
    input  wire clk,
    input  wire rst_n,

    // Read Address Channel
    input  wire        S_AXI_ARVALID,
    output reg         S_AXI_ARREADY,
    input  wire [31:0] S_AXI_ARADDR,

    // Read Data Channel
    output reg         S_AXI_RVALID,
    input  wire        S_AXI_RREADY,
    output reg [31:0]  S_AXI_RDATA,
    output reg [1:0]   S_AXI_RRESP
);

    reg [7:0] mem [0:SIZE-1];
    reg [31:0] latched_addr;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            S_AXI_ARREADY <= 1;
            S_AXI_RVALID  <= 0;
            S_AXI_RDATA   <= 0;
            S_AXI_RRESP   <= 2'b00; // OKAY
        end else begin
            // Address accept
            if (S_AXI_ARVALID && S_AXI_ARREADY) begin
                latched_addr <= S_AXI_ARADDR;
                S_AXI_RVALID <= 1;
                S_AXI_RDATA  <= {24'd0, mem[S_AXI_ARADDR]};
                S_AXI_RRESP  <= 2'b00;
            end

            // Data accept
            if (S_AXI_RVALID && S_AXI_RREADY)
                S_AXI_RVALID <= 0;
        end
    end

endmodule
