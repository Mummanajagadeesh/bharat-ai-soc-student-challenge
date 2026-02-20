// Auto-generated ROM for image channel b
// 32x32 = 1024 pixels, 8-bit
module image_b_rom (
    input  wire                  clk,
    input  wire                  rst,
    input  wire [9:0] addr,
    input  wire                  addr_valid,
    output reg                   addr_ready,

    output reg  [7:0]            data,
    output reg                   data_valid,
    input  wire                  data_ready
);

    reg [7:0] rom [0:1023];
    reg [9:0] addr_reg;

    initial begin
        $readmemh("image_roms_mem/image_b.mem", rom);
    end

    always @(posedge clk) begin
        if (rst) begin
            addr_ready  <= 1'b0;
            data_valid  <= 1'b0;
            addr_reg    <= { 10{1'b0} };
            data        <= 8'h00;
        end else begin
            // Accept new address if valid
            if (addr_valid && !addr_ready) begin
                addr_reg   <= addr;
                addr_ready <= 1'b1;
            end else begin
                addr_ready <= 1'b0;
            end

            // Output data one cycle later
            if (addr_ready) begin
                data       <= rom[addr_reg];
                data_valid <= 1'b1;
            end else if (data_valid && data_ready) begin
                data_valid <= 1'b0;
            end
        end
    end

endmodule
