// Auto-generated ROM for 00_conv2d_kernel
// Depth: 432, Width: 8
module rom_00_conv2d_kernel (
    input  wire                   clk,
    input  wire [8:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:431];

    initial begin
        $readmemh("verilog_roms_mems/00_conv2d_kernel.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
