`timescale 1ns/1ps
module conv_tb;

    parameter W=7, H=6;

    reg clk=0, rst=1, in_valid=0;
    reg [7:0] img [0:H-1][0:W-1];
    reg [7:0] px0,px1,px2;

    wire out_valid;
    wire [23:0] out_pixel;

    conv_3x3_systolic dut(
        .clk(clk),.rst(rst),
        .in_valid(in_valid),
        .px0(px0),.px1(px1),.px2(px2),
        .k00(8'd1),.k01(8'd2),.k02(8'd3),
        .k10(8'd4),.k11(8'd5),.k12(8'd6),
        .k20(8'd7),.k21(8'd8),.k22(8'd9),
        .out_valid(out_valid),
        .out_pixel(out_pixel)
    );

    always #5 clk=~clk;

    integer x,y,gx=0,gy=0, golden;
    integer cycle = 0;

    // Cycle counter
    always @(posedge clk) begin
        if (!rst) cycle <= cycle + 1;
    end

    initial begin
        // Initialize image
        for(y=0;y<H;y=y+1)
            for(x=0;x<W;x=x+1)
                img[y][x]=y*W+x+1;

        // Print image
        $display("\n=== IMAGE DATA (7x6) ===");
        for(y=0;y<H;y=y+1) begin
            $write("Row %0d: ", y);
            for(x=0;x<W;x=x+1)
                $write("%3d ", img[y][x]);
            $display("");
        end
        $display("");

        #20 rst=0;

        for(y=0;y<H;y=y+1)
            for(x=0;x<W;x=x+1) begin
                @(posedge clk);
                in_valid <= (y>=2);
                px0 <= (y>=2)?img[y-2][x]:0;
                px1 <= (y>=2)?img[y-1][x]:0;
                px2 <= (y>=2)?img[y][x]:0;
            end

        in_valid<=0;
        repeat(40) @(posedge clk);
        $finish;
    end

    // Debug: Input values when valid (your original)
    always @(posedge clk) begin
        if (in_valid && !rst) begin
            $display("CYCLE %2d | IN_VALID | px0=%3d px1=%3d px2=%3d",
                     cycle, px0, px1, px2);
        end
    end

    // Debug: Partial sums (your original)
    always @(posedge clk) begin
        if (in_valid && !rst) begin
            $display("         | PSUM     | ROW0: %4d %4d %4d | ROW1: %4d %4d %4d | ROW2: %4d %4d %4d",
              dut.c0_r0, dut.c1_r0, dut.c2_r0,
              dut.c0_r1, dut.c1_r1, dut.c2_r1,
              dut.c0_r2, dut.c1_r2, dut.c2_r2
            );
        end
    end

    // === NEW: Deep per-cycle internal dump (added) ===
    // Prints a single long line per cycle (only when !rst) showing:
    // - px stage signals
    // - row delays
    // - horizontal shift regs
    // - row_valid
    // - all c*_r* partial sums
    // - sum_all and out-valid pipeline (v)
    always @(posedge clk) begin
        if (!rst) begin
            $display("DBG CYCLE %2d | in_valid=%b | px_s1: %3d %3d %3d | px_d: %3d %3d %3d | r0: %3d %3d | r1: %3d %3d | r2: %3d %3d | row_valid=%b | c0: %4d %4d %4d | c1: %4d %4d %4d | c2: %4d %4d %4d | sum_all=%4d | v=%b",
                cycle,
                // px pre-stage (the stage we added)
                dut.px0_s1, dut.px1_s1, dut.px2_s1,
                // row delays
                dut.px1_d, dut.px2_d1, dut.px2_d2,
                // horizontal shift regs
                dut.r0_1, dut.r0_2,
                dut.r1_1, dut.r1_2,
                dut.r2_1, dut.r2_2,
                // row_valid
                dut.row_valid,
                // partial sums
                dut.c0_r0, dut.c0_r1, dut.c0_r2,
                dut.c1_r0, dut.c1_r1, dut.c1_r2,
                dut.c2_r0, dut.c2_r1, dut.c2_r2,
                // sum_all and v (out pipeline)
                dut.sum_all,
                dut.v
            );
        end
    end

    // Output check with detailed golden calculation (your original)
    always @(posedge clk) begin
        if(out_valid && !rst) begin
            // Calculate golden for current window
            golden =
              img[gy][gx]*1 + img[gy][gx+1]*2 + img[gy][gx+2]*3 +
              img[gy+1][gx]*4 + img[gy+1][gx+1]*5 + img[gy+1][gx+2]*6 +
              img[gy+2][gx]*7 + img[gy+2][gx+1]*8 + img[gy+2][gx+2]*9;

            $display("\n*** OUTPUT(%0d,%0d) = %4d | GOLD = %4d | DIFF = %4d ***",
                     gy, gx, out_pixel, golden, $signed(out_pixel - golden));

            $display("    Window: [%2d %2d %2d]", img[gy][gx], img[gy][gx+1], img[gy][gx+2]);
            $display("            [%2d %2d %2d]", img[gy+1][gx], img[gy+1][gx+1], img[gy+1][gx+2]);
            $display("            [%2d %2d %2d]", img[gy+2][gx], img[gy+2][gx+1], img[gy+2][gx+2]);
            $display("    Expected: %d*1 + %d*2 + %d*3 + %d*4 + %d*5 + %d*6 + %d*7 + %d*8 + %d*9",
                     img[gy][gx], img[gy][gx+1], img[gy][gx+2],
                     img[gy+1][gx], img[gy+1][gx+1], img[gy+1][gx+2],
                     img[gy+2][gx], img[gy+2][gx+1], img[gy+2][gx+2]);

            if(gx==W-3) begin
                gx=0;
                gy=gy+1;
            end
            else gx=gx+1;
        end
    end

endmodule
