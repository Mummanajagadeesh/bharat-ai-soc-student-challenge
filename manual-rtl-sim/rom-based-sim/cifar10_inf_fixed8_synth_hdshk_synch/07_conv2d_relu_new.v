`timescale 1ns / 1ps

module conv2d_seventh_q31_dump (
    input wire clk,
    input wire rst
);
    // Parameters
    parameter WIDTH    = 8;    // spatial dims
    parameter HEIGHT   = 8;
    parameter CHANNELS = 64;   // input channels (from 06_conv2d_w_br)
    parameter FILTERS  = 64;   // output filters
    parameter K        = 3;
    parameter PAD      = 1;

    // Kernel / bias ROM interface (Q15)
    reg  [15:0] kernel_row, kernel_col;
    wire signed [7:0] kernel_val;    // Q15 kernel values
    reg  [15:0] bias_row, bias_col;
    wire signed [7:0] bias_val_raw;  // Q15 bias values


    integer in_y, in_x; // indices for input feature map

    // Instantiate ROMs (must be in the project)
    rom_07_conv2d_5_kernel rom_k (.row(kernel_row), .col(kernel_col), .data(kernel_val));
    rom_07_conv2d_5_bias   bias_rom (.row(bias_row),  .col(bias_col),  .data(bias_val_raw));

    // Storage for integer Q15 input feature maps read from files
    // Observed dynamic range requires >16 bits; use 25-bit storage (signed)
    reg signed [24:0] input_fm [0:CHANNELS-1][0:WIDTH*HEIGHT-1];

    // Local variables
    integer f, i, j, c, m, n;
    integer fin, fout, ret;
    reg signed [24:0] tmp_in;
    reg [200*8:1] fname_in, fname_out;

    // Arithmetic widths (signed)
    // product: 25-bit input * 16-bit kernel = 41 bits
    // accum: 41 bits + ceil(log2(576)) = 41 + 10 = 51 bits
    // rounded_div after >>>15 -> 51 - 15 = 36 bits
    reg signed [40:0] product41;
    reg signed [50:0] accum51;
    reg signed [35:0] rounded_div36;
    reg signed [35:0] bias36;
    reg signed [35:0] out36;
    reg signed [63:0] out64; // for printing/truncation as before

    // rounding constant (2^14) as 51-bit to align with accum before shift
    localparam signed [50:0] ROUND_CONST = 51'sd64; // 2^14

    initial begin
        $display("🔄 conv2d_seventh_q31_dump: Starting conv7 (Q15 integer) -> outputs to 07_conv2d_w_br/ ...");

        // create output dir if possible
        // $system("mkdir -p 07_conv2d_w_br");

        // === Read input feature-maps (integers) from 06_conv2d_w_br folder ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "06_conv2d_w_br/feature_map_%0d.txt", c);
            fin = $fopen(fname_in, "r");
            if (fin == 0) begin
                $display("ERROR: cannot open input file %s", fname_in);
                $finish;
            end

            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    ret = $fscanf(fin, "%d ", tmp_in); // read decimal integer Q15 (stored in 25-bit)
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

        // === Convolution: for each output filter produce a file of Q15 ints (post-ReLU) ===
        for (f = 0; f < FILTERS; f = f + 1) begin
            // open output file
            $sformat(fname_out, "07_conv2d_w_br/feature_map_%0d.txt", f);
            fout = $fopen(fname_out, "w");
            if (fout == 0) begin
                $display("ERROR: cannot open output file %s", fname_out);
                $finish;
            end

            // get bias for this filter (signed 16-bit) -> extend to 36-bit
            bias_row = f;
            bias_col = 0;
            #1;
            bias36 = $signed(bias_val_raw);

            // iterate over spatial positions
            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    accum51 = 51'sd0;

                    // convolution window
                    for (m = 0; m < K; m = m + 1) begin
                        for (n = 0; n < K; n = n + 1) begin
                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if (in_y < 0 || in_y >= HEIGHT || in_x < 0 || in_x >= WIDTH) begin
                                // zero padding -> no contribution
                            end else begin
                                for (c = 0; c < CHANNELS; c = c + 1) begin
                                    // read input integer Q15 (stored 25-bit)
                                    tmp_in = input_fm[c][in_y*WIDTH + in_x];

                                    // read kernel for (m,n,c,f)
                                    kernel_row = m * K * CHANNELS + n * CHANNELS + c;
                                    kernel_col = f;
                                    #1;
                                    // signed multiply: 25-bit * 16-bit -> 41-bit product
                                    product41 = $signed(tmp_in) * $signed(kernel_val);

                                    // sign-extend product to 51-bit and accumulate
                                    accum51 = accum51 + $signed({{10{product41[40]}}, product41});
                                end
                            end
                        end
                    end

                    // rounded_div = round(accum / 2^15)
                    if (accum51 >= 0)
                        rounded_div36 = $signed((accum51 + ROUND_CONST) >>> 7);
                    else
                        rounded_div36 = -$signed(((-accum51 + ROUND_CONST) >>> 7));

                    // add bias (both 36-bit signed now)
                    out36 = bias36 + rounded_div36;

                    // apply ReLU: if negative -> zero
                    if (out36 < 0)
                        out36 = 36'sd0;

                    // write (truncate/sign-extend to 64-bit for printing)
                    out64 = out36;
                    $fwrite(fout, "%0d ", out64);

                    if (((j+1) % WIDTH) == 0) $fwrite(fout, "\n");
                end
            end

            $fclose(fout);
            $display("-> Wrote output filter %0d -> %s", f, fname_out);
        end

        $display("✅ conv2d_seventh_q31_dump done: outputs in 07_conv2d_w_br/");
        $finish;
    end
endmodule
