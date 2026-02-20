`timescale 1ns / 1ps

module conv2d_fourth_q15_dump (
    input wire clk,
    input wire rst
);
    parameter WIDTH    = 16;
    parameter HEIGHT   = 16;
    parameter CHANNELS = 32;
    parameter FILTERS  = 32;
    parameter K        = 3;
    parameter PAD      = 1;

    // Kernel / bias ROM interface (Q15)
    reg  [15:0] kernel_row, kernel_col;
    wire signed [7:0] kernel_val;
    reg  [15:0] bias_row, bias_col;
    wire signed [7:0] bias_val_raw;

    rom_04_conv2d_3_kernel rom_k (.row(kernel_row), .col(kernel_col), .data(kernel_val));
    rom_04_conv2d_3_bias   bias_rom (.row(bias_row),  .col(bias_col),  .data(bias_val_raw));

    // Storage for input feature maps (Q31 from previous layer)
    reg signed [17:0] input_fm [0:CHANNELS-1][0:WIDTH*HEIGHT-1];

    integer f, i, j, c, m, n;
    integer fin, fout, ret;
    reg signed [17:0] tmp_in;
    reg [200*8:1] fname_in, fname_out;
    integer in_y, in_x;

    // Wide accumulator
    reg signed [43:0] accum;
    reg signed [43:0] product64;
    reg signed [31:0] rounded_div;
    reg signed [31:0] bias32;
    reg signed [31:0] out32;

    // rounding constant for Q15 scaling
    localparam signed [31:0] ROUND_CONST = 32'sd64; // 2^14

    initial begin
        $display("🔄 conv2d_fourth_q15_dump: Starting conv2d_4 (Q15 kernel, Q31 input) ...");

        // Load input feature maps
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "03_conv2d_w_br/feature_map_%0d.txt", c);
            fin = $fopen(fname_in, "r");
            if (fin == 0) begin
                $display("ERROR: cannot open input file %s", fname_in);
                $finish;
            end
            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    ret = $fscanf(fin, "%d ", tmp_in);
                    if (ret != 1) begin
                        $display("ERROR: failed reading integer from %s at %0d,%0d", fname_in, i, j);
                        $finish;
                    end
                    input_fm[c][i*WIDTH + j] = tmp_in;
                end
            end
            $fclose(fin);
            $display("-> Loaded input feature map %0d from %s", c, fname_in);
        end

        // Convolution
        for (f = 0; f < FILTERS; f = f + 1) begin
            $sformat(fname_out, "04_conv2d_w_br/feature_map_%0d.txt", f);
            fout = $fopen(fname_out, "w");
            if (fout == 0) begin
                $display("ERROR: cannot open output file %s", fname_out);
                $finish;
            end

            bias_row = f;
            bias_col = 0;
            #1;
            bias32 = $signed(bias_val_raw);

            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    accum = 0;

                    for (m = 0; m < K; m = m + 1) begin
                        for (n = 0; n < K; n = n + 1) begin
                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if (in_y >= 0 && in_y < HEIGHT && in_x >= 0 && in_x < WIDTH) begin
                                for (c = 0; c < CHANNELS; c = c + 1) begin
                                    tmp_in = input_fm[c][in_y*WIDTH + in_x];
                                    kernel_row = m * K * CHANNELS + n * CHANNELS + c;
                                    kernel_col = f;
                                    #1;
                                    product64 = $signed(tmp_in) * $signed(kernel_val);
                                    accum = accum + product64;
                                end
                            end
                        end
                    end

                    // Q15 scaling
                    if (accum >= 0)
                        rounded_div = (accum + ROUND_CONST) >>> 7;
                    else
                        rounded_div = -(((-accum + ROUND_CONST) >>> 7));

                    out32 = bias32 + rounded_div;

                    // ReLU
                    if (out32 < 0)
                        out32 = 0;

                    $fwrite(fout, "%0d ", out32);
                    if ((j+1) % WIDTH == 0) $fwrite(fout, "\n");
                end
            end

            $fclose(fout);
            $display("-> Wrote output filter %0d -> %s", f, fname_out);
        end

        $display("✅ conv2d_fourth_q15_dump done: outputs in 04_conv2d_w_br/");
        $finish;
    end
endmodule
