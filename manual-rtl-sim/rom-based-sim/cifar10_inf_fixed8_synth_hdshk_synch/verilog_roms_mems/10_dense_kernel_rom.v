// Auto-generated ROM for 10_dense_kernel
// Depth: 640, Width: 8
module rom_10_dense_kernel (
    input  wire                   clk,
    input  wire [9:0] addr,
    output reg  [7:0] data
);
    reg [7:0] rom [0:639];

    initial begin
        $readmemh("verilog_roms_mems/10_dense_kernel.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
