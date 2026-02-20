// Auto-generated ROM for 07_conv2d_5_kernel
// Depth: 36864, Width: 8
module rom_07_conv2d_5_kernel (
    input  wire                   clk,
    input  wire [15:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:36863];

    initial begin
        $readmemh("verilog_roms_mems/07_conv2d_5_kernel.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
