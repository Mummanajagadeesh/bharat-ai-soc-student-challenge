// Auto-generated ROM for 00_conv2d_bias
// Depth: 16, Width: 8
module rom_00_conv2d_bias #(
    parameter DEPTH = 16,
    parameter WIDTH = 8
)(
    input  wire                   clk,
    input  wire                   rst,

    // Handshake interface for address request
    input  wire                   addr_valid,
    output reg                    addr_ready,
    input  wire [3:0] addr,

    // Handshake interface for data response
    output reg                    data_valid,
    input  wire                   data_ready,
    output reg  [WIDTH-1:0]       data
);
    reg [WIDTH-1:0] rom [0:DEPTH-1];
    reg [3:0] addr_reg;

    initial begin
        $readmemh("00_conv2d_bias.mem", rom);
    end

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            addr_ready <= 1'b1;
            data_valid <= 1'b0;
        end else begin
            // Accept an address if valid & ready
            if (addr_valid && addr_ready) begin
                addr_reg   <= addr;
                data       <= rom[addr];
                data_valid <= 1'b1;
                addr_ready <= 1'b0;   // wait until data is consumed
            end

            // Clear data_valid once consumer accepts it
            if (data_valid && data_ready) begin
                data_valid <= 1'b0;
                addr_ready <= 1'b1;   // ready for next request
            end
        end
    end
endmodule
