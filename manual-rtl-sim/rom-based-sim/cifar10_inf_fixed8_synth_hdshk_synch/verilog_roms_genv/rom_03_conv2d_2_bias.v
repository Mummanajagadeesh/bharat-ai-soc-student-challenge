module rom_03_conv2d_2_bias (
    input  wire [15:0] row,
    input  wire [15:0] col,
    output reg signed [7:0] data
);

    // Q1.7 fixed-point format (8 bits total)
    reg signed [7:0] rom [0:31][0:0];

    initial begin
        rom[0][0] = 8'd31;
        rom[1][0] = 8'd14;
        rom[2][0] = 8'd24;
        rom[3][0] = -8'd3;
        rom[4][0] = -8'd1;
        rom[5][0] = 8'd60;
        rom[6][0] = 8'd13;
        rom[7][0] = -8'd5;
        rom[8][0] = -8'd32;
        rom[9][0] = 8'd16;
        rom[10][0] = 8'd7;
        rom[11][0] = 8'd20;
        rom[12][0] = 8'd27;
        rom[13][0] = 8'd49;
        rom[14][0] = 8'd27;
        rom[15][0] = -8'd10;
        rom[16][0] = -8'd55;
        rom[17][0] = 8'd6;
        rom[18][0] = 8'd46;
        rom[19][0] = 8'd24;
        rom[20][0] = 8'd0;
        rom[21][0] = 8'd16;
        rom[22][0] = 8'd5;
        rom[23][0] = 8'd14;
        rom[24][0] = 8'd42;
        rom[25][0] = 8'd25;
        rom[26][0] = 8'd3;
        rom[27][0] = 8'd14;
        rom[28][0] = 8'd23;
        rom[29][0] = 8'd34;
        rom[30][0] = 8'd5;
        rom[31][0] = 8'd12;
    end

    always @(*) begin
        data = rom[row][col];
    end

endmodule
