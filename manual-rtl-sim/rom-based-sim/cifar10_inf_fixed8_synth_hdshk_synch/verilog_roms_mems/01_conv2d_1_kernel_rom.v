// Auto-generated ROM for 01_conv2d_1_kernel
// Depth: 2304, Width: 8
module rom_01_conv2d_1_kernel (
    input  wire                   clk,
    input  wire [11:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:2303];

    initial begin
        $readmemh("verilog_roms_mems/01_conv2d_1_kernel.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
