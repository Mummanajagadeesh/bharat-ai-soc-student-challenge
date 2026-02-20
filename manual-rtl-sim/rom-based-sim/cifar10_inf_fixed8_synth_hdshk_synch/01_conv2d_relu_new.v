`timescale 1ns / 1ps

module conv2d_second_q15_dump (
    input wire clk,
    input wire rst
);
    parameter WIDTH    = 32;
    parameter HEIGHT   = 32;
    parameter CHANNELS = 16;
    parameter FILTERS  = 16;
    parameter K        = 3;
    parameter PAD      = 1;

    // Kernel / bias ROM interface (Q15)
    reg  [15:0] kernel_row, kernel_col;
    wire signed [7:0] kernel_val;   // Q15
    reg  [15:0] bias_row, bias_col;
    wire signed [7:0] bias_val_raw; // Q15

    // instantiate ROMs (must be present in project)
    rom_01_conv2d_1_kernel rom_k (.row(kernel_row), .col(kernel_col), .data(kernel_val));
    rom_01_conv2d_1_bias   bias_rom (.row(bias_row),  .col(bias_col),  .data(bias_val_raw));

    // storage for integer Q15 input feature maps read from files
    reg signed [16:0] input_fm [0:CHANNELS-1][0:WIDTH*HEIGHT-1];

    integer f, i, j, c, m, n;
    integer fin, fout, ret;
    reg signed [16:0] tmp_in;
    reg [200*8:1] fname_in, fname_out;

    // wide accumulator
    reg signed [35:0] accum;
    reg signed [30:0] product128;
    reg signed [15:0] bias128;
    reg signed [20:0] out128;
    reg signed [20:0]  out64; 

    integer in_x, in_y;

    initial begin
        $display("🔄 conv2d_second_q15_dump: Starting second conv (integer Q15 inputs) ...");

        // Read input feature maps (Q15) from previous layer
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "00_conv2d_w_br/feature_map_%0d.txt", c);
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

        // Convolution for each output filter
        for (f = 0; f < FILTERS; f = f + 1) begin
            $sformat(fname_out, "01_conv2d_w_br/feature_map_%0d.txt", f);
            fout = $fopen(fname_out, "w");
            if (fout == 0) begin
                $display("ERROR: cannot open output file %s", fname_out);
                $finish;
            end

            // Read bias (Q15)
            bias_row = f;
            bias_col = 0;
            #1;
            bias128 = $signed(bias_val_raw);

            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    accum = 36'sd0;

                    for (m = 0; m < K; m = m + 1) begin
                        for (n = 0; n < K; n = n + 1) begin
                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if (!(in_y < 0 || in_y >= HEIGHT || in_x < 0 || in_x >= WIDTH)) begin
                                for (c = 0; c < CHANNELS; c = c + 1) begin
                                    tmp_in = input_fm[c][in_y*WIDTH + in_x]; // Q15

                                    kernel_row = m * K * CHANNELS + n * CHANNELS + c;
                                    kernel_col = f;
                                    #1;

                                    // Multiply Q15 * Q15 -> Q30
                                    product128 = $signed(tmp_in) * $signed(kernel_val);
                                    accum = accum + product128;
                                end
                            end
                        end
                    end

                    // Shift back from Q30 to Q15
                    accum = accum >>> 7;

                    // Add bias (Q15)
                    out128 = bias128 + accum;

                    // ReLU
                    if (out128 < 0)
                        out128 = 27'sd0;

                    out64 = out128;
                    $fwrite(fout, "%0d ", out64);

                    if (((j+1) % WIDTH) == 0) $fwrite(fout, "\n");
                end
            end

            $fclose(fout);
            $display("-> Wrote output filter %0d -> %s", f, fname_out);
        end

        $display("✅ conv2d_second_q15_dump done: outputs in 01_conv2d_w_br/");
        $finish;
    end
endmodule
