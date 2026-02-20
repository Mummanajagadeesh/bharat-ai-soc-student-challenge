module rom_10_dense_bias (
    input  wire [15:0] row,
    input  wire [15:0] col,
    output reg signed [7:0] data
);

    // Q1.7 fixed-point format (8 bits total)
    reg signed [7:0] rom [0:9][0:0];

    initial begin
        rom[0][0] = 8'd9;
        rom[1][0] = -8'd30;
        rom[2][0] = -8'd4;
        rom[3][0] = 8'd16;
        rom[4][0] = 8'd28;
        rom[5][0] = -8'd33;
        rom[6][0] = 8'd35;
        rom[7][0] = -8'd22;
        rom[8][0] = 8'd9;
        rom[9][0] = -8'd16;
    end

    always @(*) begin
        data = rom[row][col];
    end

endmodule
