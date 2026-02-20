// Auto-generated ROM for 03_conv2d_2_kernel
// Depth: 4608, Width: 8
module rom_03_conv2d_2_kernel (
    input  wire                   clk,
    input  wire [12:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:4607];

    initial begin
        $readmemh("verilog_roms_mems/03_conv2d_2_kernel.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
