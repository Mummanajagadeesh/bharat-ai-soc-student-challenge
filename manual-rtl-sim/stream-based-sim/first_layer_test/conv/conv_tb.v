`timescale 1ns/1ps
module conv_tb;

    parameter W = 7;
    parameter H = 7;

    reg [15:0] img_width;
    reg clk, rst, in_valid;
    reg [7:0] in_pixel;
    wire out_valid;
    wire [23:0] out_pixel;

    reg [7:0] k00,k01,k02,k10,k11,k12,k20,k21,k22;

    conv_3x3 dut (
        .clk(clk), .rst(rst),
        .in_valid(in_valid),
        .in_pixel(in_pixel),
        .img_width(img_width),
        .k00(k00),.k01(k01),.k02(k02),
        .k10(k10),.k11(k11),.k12(k12),
        .k20(k20),.k21(k21),.k22(k22),
        .out_valid(out_valid),
        .out_pixel(out_pixel)
    );

    always #5 clk = ~clk;

    integer x,y;

    initial begin
        clk = 0;
        rst = 1;
        in_valid = 0;
        in_pixel = 0;

        img_width = W;

        k00=1; k01=2; k02=3;
        k10=4; k11=5; k12=6;
        k20=7; k21=8; k22=9;

        #30 rst = 0;

        for (y=0;y<H;y=y+1)
            for (x=0;x<W;x=x+1) begin
                @(posedge clk);
                in_valid <= 1;
                in_pixel <= y*W + x + 1;
            end

        @(posedge clk) in_valid <= 0;
        repeat(20) @(posedge clk);
        $finish;
    end

    always @(posedge clk)
        if (out_valid)
            $display("OUT = %0d", out_pixel);

endmodule