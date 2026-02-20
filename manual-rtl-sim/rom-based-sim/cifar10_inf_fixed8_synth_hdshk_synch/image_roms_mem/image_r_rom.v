// Auto-generated ROM for image channel r
// 32x32 = 1024 pixels, 8-bit
module image_r_rom (
    input  wire                  clk,
    input  wire [9:0] addr,
    output reg  [7:0]            data
);
    reg [7:0] rom [0:1023];

    initial begin
        $readmemh("image_roms_mem/image_r.mem", rom);
    end

    always @(posedge clk) begin
        data <= rom[addr];
    end
endmodule
