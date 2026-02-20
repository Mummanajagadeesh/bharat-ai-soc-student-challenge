// Auto-generated ROM for 06_conv2d_4_kernel
// Depth: 18432, Width: 8
module rom_06_conv2d_4_kernel (
    input  wire                   clk,
    input  wire [14:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:18431];

    initial begin
        $readmemh("verilog_roms_mems/06_conv2d_4_kernel.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
