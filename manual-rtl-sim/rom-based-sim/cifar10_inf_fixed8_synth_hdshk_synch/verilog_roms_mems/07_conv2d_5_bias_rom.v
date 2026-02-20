// Auto-generated ROM for 07_conv2d_5_bias
// Depth: 64, Width: 8
module rom_07_conv2d_5_bias (
    input  wire                   clk,
    input  wire [5:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:63];

    initial begin
        $readmemh("verilog_roms_mems/07_conv2d_5_bias.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
