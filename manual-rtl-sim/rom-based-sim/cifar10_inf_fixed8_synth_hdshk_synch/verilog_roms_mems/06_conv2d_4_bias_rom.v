// Auto-generated ROM for 06_conv2d_4_bias
// Depth: 64, Width: 8
module rom_06_conv2d_4_bias (
    input  wire                   clk,
    input  wire [5:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:63];

    initial begin
        $readmemh("verilog_roms_mems/06_conv2d_4_bias.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
