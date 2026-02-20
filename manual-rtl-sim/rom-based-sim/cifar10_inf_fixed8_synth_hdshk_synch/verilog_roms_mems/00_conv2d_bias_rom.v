// Auto-generated ROM for 00_conv2d_bias
// Depth: 16, Width: 8
module rom_00_conv2d_bias (
    input  wire                   clk,
    input  wire [3:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:15];

    initial begin
        $readmemh("verilog_roms_mems/00_conv2d_bias.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
