`timescale 1ns / 1ps

module max_pool_2_q31 (
    input wire clk,
    input wire rst,
    output reg done
);

    parameter WIDTH_IN  = 16;
    parameter HEIGHT_IN = 16;
    parameter CHANNELS  = 32;

    parameter POOL_SIZE = 2;
    parameter STRIDE    = 2;

    // Derived output dims: 8x8
    localparam WIDTH_OUT  = (WIDTH_IN  - POOL_SIZE) / STRIDE + 1;
    localparam HEIGHT_OUT = (HEIGHT_IN - POOL_SIZE) / STRIDE + 1;

    // Input feature maps (Q31 integers)
    reg signed [24:0] input_feature_map [0:CHANNELS-1][0:WIDTH_IN*HEIGHT_IN-1];

    // Output pooled feature maps (Q31 integers)
    reg signed [24:0] pooled_feature_map [0:CHANNELS-1][0:WIDTH_OUT*HEIGHT_OUT-1];

    integer c, i, j, ph, pw;
    integer fin, fout, ret;
    reg signed [31:0] tmp_in;
    reg signed [31:0] max_val;
    reg [200*8:1] fname_in, fname_out;

    integer in_x, in_y; // indices for input feature map
    reg signed [31:0] val;


    initial begin
        done = 0;
        $display("🔄 max_pool_2_q31: Starting integer max-pool (2x2 stride 2) ...");

        // create output dir if possible
        // $system("mkdir -p max_pool_2_v");

        // === Load input feature maps (integers) from 04_conv2d_w_br folder ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "04_conv2d_w_br/feature_map_%0d.txt", c);
            fin = $fopen(fname_in, "r");
            if (fin == 0) begin
                $display("ERROR: Could not open input feature map file %s", fname_in);
                $finish;
            end

            for (i = 0; i < HEIGHT_IN; i = i + 1) begin
                for (j = 0; j < WIDTH_IN; j = j + 1) begin
                    ret = $fscanf(fin, "%d ", tmp_in);
                    if (ret != 1) begin
                        $display("ERROR: Failed reading integer at %0d,%0d from %s", i, j, fname_in);
                        $finish;
                    end
                    input_feature_map[c][i*WIDTH_IN + j] = tmp_in;
                end
            end

            $fclose(fin);
            $display("-> Loaded input feature map %0d from %s", c, fname_in);
        end

        // === Max Pooling on integers ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            for (ph = 0; ph < HEIGHT_OUT; ph = ph + 1) begin
                for (pw = 0; pw < WIDTH_OUT; pw = pw + 1) begin
                    // initialize to very small signed value
                    max_val = -32'sd2147483648;

                    for (i = 0; i < POOL_SIZE; i = i + 1) begin
                        for (j = 0; j < POOL_SIZE; j = j + 1) begin
                            in_y = ph * STRIDE + i;
                            in_x = pw * STRIDE + j;
                            val = input_feature_map[c][in_y*WIDTH_IN + in_x];
                            if (val > max_val) max_val = val;
                        end
                    end

                    pooled_feature_map[c][ph*WIDTH_OUT + pw] = max_val;
                end
            end
        end

        // === Save pooled integer feature maps to max_pool_2_v folder ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_out, "max_pool_2_v/feature_map_%0d.txt", c);
            fout = $fopen(fname_out, "w");
            if (fout == 0) begin
                $display("ERROR: Could not open output file %s", fname_out);
                $finish;
            end

            for (ph = 0; ph < HEIGHT_OUT; ph = ph + 1) begin
                for (pw = 0; pw < WIDTH_OUT; pw = pw + 1) begin
                    $fwrite(fout, "%0d ", pooled_feature_map[c][ph*WIDTH_OUT + pw]);
                end
                $fwrite(fout, "\n");
            end

            $fclose(fout);
            $display("-> Wrote pooled feature map %0d -> %s", c, fname_out);
        end

        $display("✅ max_pool_2_q31 done. Outputs in max_pool_2_v/");
        done = 1;
        $finish;
    end

endmodule
