module tb_conv;

    parameter IMG_W  = 5;
    parameter IMG_H  = 5;
    parameter K      = 3;
    parameter DATA_W = 8;

    localparam OUT_W = IMG_W-K+1;
    localparam OUT_H = IMG_H-K+1;
    localparam OUT_CNT = OUT_W * OUT_H;

    reg clk = 0;
    always #5 clk = ~clk;

    reg valid_pixel;
    reg signed [DATA_W-1:0] pixel_in;
    wire signed [2*DATA_W+8:0] conv_out;
    wire valid_out;

    reg signed [DATA_W-1:0] image [0:IMG_H-1][0:IMG_W-1];
    reg signed [DATA_W*K*K-1:0] kernel_flat;

    integer r, c, i, j;
    integer golden;
    integer errors;
    integer out_seen;

    conv_top #(
        .IMG_W(IMG_W),
        .IMG_H(IMG_H),
        .K(K),
        .DATA_W(DATA_W)
    ) dut (
        .clk(clk),
        .valid_pixel(valid_pixel),
        .pixel_in(pixel_in),
        .kernel_flat(kernel_flat),
        .conv_out(conv_out),
        .valid_out(valid_out)
    );

    initial begin
        for (r = 0; r < IMG_H; r = r + 1)
            for (c = 0; c < IMG_W; c = c + 1)
                image[r][c] = r*IMG_W + c + 1;

        for (i = 0; i < K*K; i = i + 1)
            kernel_flat[i*DATA_W +: DATA_W] = 1;

        valid_pixel = 0;
        pixel_in = 0;
        errors = 0;
        out_seen = 0;

        @(posedge clk);

        for (r = 0; r < IMG_H; r = r + 1)
            for (c = 0; c < IMG_W; c = c + 1) begin
                @(posedge clk);
                valid_pixel = 1;
                pixel_in = image[r][c];
            end

        valid_pixel = 0;
    end

    always @(posedge clk) begin
        if (valid_out) begin
            r = out_seen / OUT_W;
            c = out_seen % OUT_W;

            golden = 0;
            for (i = 0; i < K; i = i + 1)
                for (j = 0; j < K; j = j + 1)
                    golden = golden + image[r+i][c+j];

            $display("OUT[%0d,%0d] = %0d (exp %0d)",
                     r, c, conv_out, golden);

            if (conv_out !== golden)
                errors = errors + 1;

            out_seen = out_seen + 1;

            if (out_seen == OUT_CNT) begin
                if (errors == 0)
                    $display("✅ TEST PASSED");
                else
                    $display("❌ TEST FAILED (%0d errors)", errors);
                $finish;
            end
        end
    end

endmodule
