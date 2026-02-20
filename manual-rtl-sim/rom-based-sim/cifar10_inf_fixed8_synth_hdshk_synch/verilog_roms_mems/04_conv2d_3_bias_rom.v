// Auto-generated ROM for 04_conv2d_3_bias
// Depth: 32, Width: 8
module rom_04_conv2d_3_bias (
    input  wire                   clk,
    input  wire [4:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:31];

    initial begin
        $readmemh("verilog_roms_mems/04_conv2d_3_bias.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
