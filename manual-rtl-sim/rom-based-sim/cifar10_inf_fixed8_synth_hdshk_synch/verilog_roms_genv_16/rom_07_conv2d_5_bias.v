module rom_07_conv2d_5_bias (
    input  wire [15:0] row,
    input  wire [15:0] col,
    output reg signed [7:0] data
);

    // Q1.7 fixed-point format (8 bits total)
    reg signed [7:0] rom [0:63][0:0];

    initial begin
        rom[0][0] = -8'd39;
        rom[1][0] = 8'd33;
        rom[2][0] = -8'd14;
        rom[3][0] = 8'd24;
        rom[4][0] = 8'd14;
        rom[5][0] = 8'd17;
        rom[6][0] = 8'd6;
        rom[7][0] = 8'd1;
        rom[8][0] = 8'd0;
        rom[9][0] = 8'd37;
        rom[10][0] = 8'd0;
        rom[11][0] = 8'd24;
        rom[12][0] = -8'd35;
        rom[13][0] = 8'd11;
        rom[14][0] = -8'd8;
        rom[15][0] = 8'd9;
        rom[16][0] = 8'd0;
        rom[17][0] = -8'd1;
        rom[18][0] = 8'd23;
        rom[19][0] = 8'd15;
        rom[20][0] = -8'd4;
        rom[21][0] = 8'd7;
        rom[22][0] = -8'd2;
        rom[23][0] = -8'd10;
        rom[24][0] = -8'd16;
        rom[25][0] = -8'd18;
        rom[26][0] = -8'd19;
        rom[27][0] = 8'd21;
        rom[28][0] = -8'd24;
        rom[29][0] = -8'd6;
        rom[30][0] = 8'd16;
        rom[31][0] = 8'd12;
        rom[32][0] = -8'd5;
        rom[33][0] = 8'd6;
        rom[34][0] = -8'd10;
        rom[35][0] = -8'd9;
        rom[36][0] = 8'd16;
        rom[37][0] = 8'd28;
        rom[38][0] = -8'd15;
        rom[39][0] = 8'd68;
        rom[40][0] = 8'd16;
        rom[41][0] = 8'd31;
        rom[42][0] = 8'd25;
        rom[43][0] = -8'd21;
        rom[44][0] = -8'd3;
        rom[45][0] = 8'd7;
        rom[46][0] = 8'd39;
        rom[47][0] = 8'd4;
        rom[48][0] = 8'd1;
        rom[49][0] = 8'd23;
        rom[50][0] = 8'd33;
        rom[51][0] = -8'd9;
        rom[52][0] = 8'd62;
        rom[53][0] = -8'd3;
        rom[54][0] = 8'd15;
        rom[55][0] = -8'd9;
        rom[56][0] = 8'd23;
        rom[57][0] = 8'd0;
        rom[58][0] = -8'd1;
        rom[59][0] = 8'd26;
        rom[60][0] = 8'd5;
        rom[61][0] = 8'd37;
        rom[62][0] = 8'd34;
        rom[63][0] = 8'd5;
    end

    always @(*) begin
        data = rom[row][col];
    end

endmodule
