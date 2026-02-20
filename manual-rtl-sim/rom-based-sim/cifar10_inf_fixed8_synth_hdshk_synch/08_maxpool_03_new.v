`timescale 1ns / 1ps

module max_pool_3_q15_dump (
    input wire clk,
    input wire rst
);

    parameter WIDTH_IN  = 8;
    parameter HEIGHT_IN = 8;
    parameter CHANNELS  = 64;

    parameter POOL_SIZE = 2;
    parameter STRIDE    = 2;

    parameter WIDTH_OUT  = (WIDTH_IN  - POOL_SIZE) / STRIDE + 1; // 4
    parameter HEIGHT_OUT = (HEIGHT_IN - POOL_SIZE) / STRIDE + 1; // 4

    // Q15 post-conv integers (±~350k) → fits in signed [24:0]
    reg signed [24:0] input_feature_map  [0:CHANNELS-1][0:WIDTH_IN*HEIGHT_IN-1];
    reg signed [24:0] pooled_feature_map [0:CHANNELS-1][0:WIDTH_OUT*HEIGHT_OUT-1];

    integer c, ph, pw, i, j;
    integer fin, fout, ret;
    reg signed [24:0] val, max_val;
    reg [200*8:1] fname_in, fname_out;

    initial begin
        $display("🔄 Starting max_pool_3_q15_dump...");

        // === Load input Q15 integers ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "07_conv2d_w_br/feature_map_%0d.txt", c);
            fin = $fopen(fname_in, "r");
            if (fin == 0) begin
                $display("ERROR: Could not open input file %s", fname_in);
                $finish;
            end

            for (i = 0; i < HEIGHT_IN; i = i + 1) begin
                for (j = 0; j < WIDTH_IN; j = j + 1) begin
                    ret = $fscanf(fin, "%d ", val);
                    if (ret != 1) begin
                        $display("ERROR: Failed reading integer at %0d,%0d from %s", i, j, fname_in);
                        $finish;
                    end
                    input_feature_map[c][i*WIDTH_IN + j] = val;
                end
            end

            $fclose(fin);
        end

        // === Max Pooling ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            for (ph = 0; ph < HEIGHT_OUT; ph = ph + 1) begin
                for (pw = 0; pw < WIDTH_OUT; pw = pw + 1) begin
                    max_val = -25'sd16777216; // min for signed [24:0]

                    for (i = 0; i < POOL_SIZE; i = i + 1) begin
                        for (j = 0; j < POOL_SIZE; j = j + 1) begin
                            val = input_feature_map[c][(ph*STRIDE + i)*WIDTH_IN + (pw*STRIDE + j)];
                            if (val > max_val) max_val = val;
                        end
                    end

                    pooled_feature_map[c][ph*WIDTH_OUT + pw] = max_val;
                end
            end
        end

        // === Save output ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_out, "max_pool_3_v/feature_map_%0d.txt", c);
            fout = $fopen(fname_out, "w");
            for (i = 0; i < HEIGHT_OUT; i = i + 1) begin
                for (j = 0; j < WIDTH_OUT; j = j + 1) begin
                    $fwrite(fout, "%0d ", pooled_feature_map[c][i*WIDTH_OUT + j]);
                end
                $fwrite(fout, "\n");
            end
            $fclose(fout);
        end

        $display("✅ max_pool_3_q15_dump done.");
        $finish;
    end

endmodule
