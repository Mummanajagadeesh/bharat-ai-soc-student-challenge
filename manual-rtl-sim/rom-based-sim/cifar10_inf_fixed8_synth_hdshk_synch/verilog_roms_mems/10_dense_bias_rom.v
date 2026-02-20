// Auto-generated ROM for 10_dense_bias
// Depth: 10, Width: 8
module rom_10_dense_bias (
    input  wire                   clk,
    input  wire [3:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:9];

    initial begin
        $readmemh("verilog_roms_mems/10_dense_bias.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
