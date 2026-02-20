// Auto-generated ROM for 01_conv2d_1_bias
// Depth: 16, Width: 8
module rom_01_conv2d_1_bias (
    input  wire                   clk,
    input  wire [3:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:15];

    initial begin
        $readmemh("verilog_roms_mems/01_conv2d_1_bias.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
