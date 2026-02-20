`timescale 1ns / 1ps

module conv2d_third_q15_dump (
    input wire clk,
    input wire rst
);
    parameter WIDTH    = 16;
    parameter HEIGHT   = 16;
    parameter CHANNELS = 16;
    parameter FILTERS  = 32;
    parameter K        = 3;
    parameter PAD      = 1;

    // Kernel / bias ROM interface (Q15)
    reg  [15:0] kernel_row, kernel_col;
    wire signed [7:0] kernel_val;
    reg  [15:0] bias_row, bias_col;
    wire signed [7:0] bias_val_raw;

    // Q15 kernel & bias ROMs
    rom_03_conv2d_2_kernel rom_k (.row(kernel_row), .col(kernel_col), .data(kernel_val));
    rom_03_conv2d_2_bias   bias_rom (.row(bias_row),  .col(bias_col),  .data(bias_val_raw));

    // storage for Q15 input feature maps
    reg signed [16:0] input_fm [0:CHANNELS-1][0:WIDTH*HEIGHT-1];

    integer f, i, j, c, m, n;
    integer fin, fout, ret;
    reg signed [16:0] tmp_in;
    reg [200*8:1] fname_in, fname_out;

    integer in_y, in_x;

    // wide accumulator
    reg signed [43:0] accum;
    reg signed [31:0] product128;
    reg signed [30:0] rounded_div;
    reg signed [31:0] bias128;
    reg signed [31:0] out128;
    reg signed [31:0] out64;

    // rounding constant for Q15 scaling
    localparam signed [14:0] ROUND_CONST = 128'sd64; // 2^14

    initial begin
        $display("🔄 conv2d_third_q15_dump: Starting conv2d_2 (Q15 integer) ...");

        // === Read Q15 input feature-maps from max_pool_1_v_q15 ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "max_pool_1_v/feature_map_%0d.txt", c);
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
            $display("-> Loaded pooled input feature map %0d from %s", c, fname_in);
        end

        // === Convolution with Q15 scaling ===
        for (f = 0; f < FILTERS; f = f + 1) begin
            $sformat(fname_out, "03_conv2d_w_br/feature_map_%0d.txt", f);
            fout = $fopen(fname_out, "w");
            if (fout == 0) begin
                $display("ERROR: cannot open output file %s", fname_out);
                $finish;
            end

            bias_row = f;
            bias_col = 0;
            #1;
            bias128 = $signed(bias_val_raw);

            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    accum = 44'sd0;

                    for (m = 0; m < K; m = m + 1) begin
                        for (n = 0; n < K; n = n + 1) begin
                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if (!(in_y < 0 || in_y >= HEIGHT || in_x < 0 || in_x >= WIDTH)) begin
                                for (c = 0; c < CHANNELS; c = c + 1) begin
                                    tmp_in = input_fm[c][in_y*WIDTH + in_x];
                                    kernel_row = m * K * CHANNELS + n * CHANNELS + c;
                                    kernel_col = f;
                                    #1;
                                    product128 = $signed(tmp_in) * $signed(kernel_val);
                                    accum = accum + product128;
                                end
                            end
                        end
                    end

                    // Q15 scaling: divide by 2^15 with rounding
                    if (accum >= 0)
                        rounded_div = (accum + ROUND_CONST) >>> 7;
                    else
                        rounded_div = -(((-accum + ROUND_CONST) >>> 7));

                    out128 = bias128 + rounded_div;

                    if (out128 < 0)
                        out128 = 32'sd0;

                    out64 = out128;
                    $fwrite(fout, "%0d ", out64);

                    if (((j+1) % WIDTH) == 0) $fwrite(fout, "\n");
                end
            end

            $fclose(fout);
            $display("-> Wrote output filter %0d -> %s", f, fname_out);
        end

        $display("✅ conv2d_third_q15_dump done: outputs in 03_conv2d_w_br/");
        $finish;
    end
endmodule
