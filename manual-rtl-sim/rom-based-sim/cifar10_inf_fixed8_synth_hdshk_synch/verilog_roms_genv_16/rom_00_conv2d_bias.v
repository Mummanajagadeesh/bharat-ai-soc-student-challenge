module rom_00_conv2d_bias (
    input  wire [15:0] row,
    input  wire [15:0] col,
    output reg signed [7:0] data
);

    // Q1.7 fixed-point format (8 bits total)
    reg signed [7:0] rom [0:15][0:0];

    initial begin
        rom[0][0] = -8'd5;
        rom[1][0] = 8'd0;
        rom[2][0] = 8'd1;
        rom[3][0] = 8'd7;
        rom[4][0] = 8'd3;
        rom[5][0] = 8'd6;
        rom[6][0] = 8'd1;
        rom[7][0] = 8'd7;
        rom[8][0] = 8'd12;
        rom[9][0] = 8'd12;
        rom[10][0] = 8'd18;
        rom[11][0] = 8'd18;
        rom[12][0] = 8'd8;
        rom[13][0] = 8'd8;
        rom[14][0] = 8'd1;
        rom[15][0] = -8'd14;
    end

    always @(*) begin
        data = rom[row][col];
    end

endmodule
