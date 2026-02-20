`timescale 1ns / 1ps

module conv2d_sixth_q15_dump (
    input wire clk,
    input wire rst
);
    // Parameters
    parameter WIDTH    = 8;    // spatial dims after max_pool_2
    parameter HEIGHT   = 8;
    parameter CHANNELS = 32;   // input channels
    parameter FILTERS  = 64;   // conv4 output filters
    parameter K        = 3;
    parameter PAD      = 1;

    // Kernel / bias ROM interface
    reg  [15:0] kernel_row, kernel_col;
    wire signed [7:0] kernel_val;    // Q15 kernel
    reg  [15:0] bias_row, bias_col;
    wire signed [7:0] bias_val_raw;  // Q15 bias

    // Instantiate ROMs (must exist in project)
    rom_06_conv2d_4_kernel rom_k (.row(kernel_row), .col(kernel_col), .data(kernel_val));
    rom_06_conv2d_4_bias   bias_rom (.row(bias_row),  .col(bias_col),  .data(bias_val_raw));

    // Storage for integer Q15 *outputs from previous layers*.
    // Observed ranges exceed 16-bit; use 25 bits to avoid truncation/wrap.
    reg signed [24:0] input_fm [0:CHANNELS-1][0:WIDTH*HEIGHT-1];

    // Local variables
    integer f, i, j, c, m, n;
    integer fin, fout, ret;
    reg signed [24:0] tmp_in;               // matches input_fm
    reg [200*8:1] fname_in, fname_out;

    // Arithmetic widths (tight for 25-bit inputs × 16-bit kernels)
    // product: 25 + 16 = 41 bits
    // accum: 41 bits + ceil(log2(288)) (=9) = 50 bits
    reg signed [40:0] product41;            // 41-bit product
    reg signed [49:0] accum50;              // 50-bit accumulator
    // After (accum + 2^14) >>> 15 -> width = 50 - 15 = 35
    reg signed [34:0] rounded_div35;        // 35-bit post-shift value
    reg signed [34:0] bias35;               // bias sign-extended to 35
    reg signed [34:0] out35;                // final output (post-ReLU)

    integer in_x, in_y; // indices for input feature map

    // rounding constant (2^14) as 50-bit to align with accum before shift
    localparam signed [49:0] ROUND_CONST = 50'sd64; // 2^14

    initial begin
        $display("🔄 conv2d_sixth_q15_dump: Starting conv (Q15 integer) -> outputs to 06_conv2d_w_br/ ...");

        // === Read input feature-maps (integers) from max_pool_2_v folder ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "max_pool_2_v/feature_map_%0d.txt", c);
            fin = $fopen(fname_in, "r");
            if (fin == 0) begin
                $display("ERROR: cannot open input file %s", fname_in);
                $finish;
            end

            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    // reading decimal integer (these are integer Q15-scaled values, may be > 16-bit)
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

        // === Convolution: for each output filter produce a file of Q15 ints (post-ReLU) ===
        for (f = 0; f < FILTERS; f = f + 1) begin
            // open output file
            $sformat(fname_out, "06_conv2d_w_br/feature_map_%0d.txt", f);
            fout = $fopen(fname_out, "w");
            if (fout == 0) begin
                $display("ERROR: cannot open output file %s", fname_out);
                $finish;
            end

            // get bias for this filter (signed 16-bit) -> extend to 35-bit
            bias_row = f;
            bias_col = 0;
            #1;
            bias35 = $signed(bias_val_raw);

            // iterate over spatial positions
            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    accum50 = 50'sd0;

                    // convolution window
                    for (m = 0; m < K; m = m + 1) begin
                        for (n = 0; n < K; n = n + 1) begin
                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if (in_y < 0 || in_y >= HEIGHT || in_x < 0 || in_x >= WIDTH) begin
                                // zero padding -> no contribution
                            end else begin
                                for (c = 0; c < CHANNELS; c = c + 1) begin
                                    // read input integer (tight)
                                    tmp_in = input_fm[c][in_y*WIDTH + in_x];

                                    // read kernel for (m,n,c,f)
                                    kernel_row = m * K * CHANNELS + n * CHANNELS + c;
                                    kernel_col = f;
                                    #1;

                                    // signed multiply: 25-bit tmp_in * 16-bit kernel -> 41-bit product
                                    product41 = $signed(tmp_in) * $signed(kernel_val);

                                    // sign-extend product to 50-bit and accumulate
                                    accum50 = accum50 + $signed({{9{product41[40]}}, product41});
                                end
                            end
                        end
                    end

                    // rounded_div = round(accum / 2^15)
                    if (accum50 >= 0)
                        rounded_div35 = $signed((accum50 + ROUND_CONST) >>> 7);
                    else
                        rounded_div35 = -$signed(((-accum50 + ROUND_CONST) >>> 7));

                    // add bias (both 35-bit signed now)
                    out35 = bias35 + rounded_div35;

                    // ReLU (stay in signed space)
                    if (out35 < 0)
                        out35 = 35'sd0;

                    // write out (decimal integer)
                    $fwrite(fout, "%0d ", out35);

                    if (((j+1) % WIDTH) == 0) $fwrite(fout, "\n");
                end
            end

            $fclose(fout);
            $display("-> Wrote output filter %0d -> %s", f, fname_out);
        end

        $display("✅ conv2d_sixth_q15_dump done: outputs in 06_conv2d_w_br/");
        $finish;
    end
endmodule
