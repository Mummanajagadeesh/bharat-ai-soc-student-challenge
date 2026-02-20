`timescale 1ns / 1ps

module global_average_pooling_q31;

    parameter CHANNELS = 64;
    parameter WIDTH_OUT = 4;
    parameter HEIGHT_OUT = 4;
    parameter VALUES_PER_MAP = WIDTH_OUT * HEIGHT_OUT; // 16

    // --- NOTE ---
    // Upstream pipeline uses Q15 integer outputs that can exceed 16-bit.
    // We store feature-map values in 25-bit signed to avoid truncation/wrap.
    // GAP result is returned in the same integer format (25-bit signed).
    // ----------------

    // Feature maps: store Q15 *integer* outputs (wide enough to avoid truncation)
    reg signed [24:0] feature_map [0:CHANNELS-1][0:VALUES_PER_MAP-1];
    reg signed [24:0] gap_result  [0:CHANNELS-1]; // integer average result (keeps same scale)

    integer c, i;
    integer fin, fout, ret;
    // temp and sum widths:
    // - input magnitude up to 2^24-1; sum of 16 values needs up to 29 bits signed.
    reg signed [24:0] temp;
    reg signed [28:0] sum;
    reg [200*8:1] fname_in;
    reg [200*8:1] fname_out;

    initial begin
        $display("🔄 Starting Global Average Pooling (Q15 integer domain, stored in 25-bit)...");
        // $system("mkdir -p ."); // ensure dir exists if desired

        // === Load Q15 integer feature maps ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            $sformat(fname_in, "max_pool_3_v/feature_map_%0d.txt", c);
            fin = $fopen(fname_in, "r");
            if (fin == 0) begin
                $display("ERROR: Could not open %s", fname_in);
                $finish;
            end

            for (i = 0; i < VALUES_PER_MAP; i = i + 1) begin
                ret = $fscanf(fin, "%d ", temp);
                if (ret != 1) begin
                    $display("ERROR: Failed reading int %0d from %s", i, fname_in);
                    $finish;
                end
                feature_map[c][i] = temp;
            end

            $fclose(fin);
            $display("-> Loaded feature map %0d from %s", c, fname_in);
        end

        // === Compute GAP in integer domain ===
        for (c = 0; c < CHANNELS; c = c + 1) begin
            sum = 29'sd0;
            for (i = 0; i < VALUES_PER_MAP; i = i + 1) begin
                sum = sum + feature_map[c][i];
            end
            // Divide by number of elements (16) -- integer average
            // sum fits in 29 bits, result fits back into 25-bit range (>>4)
            gap_result[c] = sum / VALUES_PER_MAP;
        end

        // === Save GAP results (integer values) ===
        $sformat(fname_out, "gap_v.txt");
        fout = $fopen(fname_out, "w");
        if (fout == 0) begin
            $display("ERROR: Could not open %s", fname_out);
            $finish;
        end

        for (c = 0; c < CHANNELS; c = c + 1) begin
            $fwrite(fout, "%0d\n", gap_result[c]);
        end

        $fclose(fout);
        $display("✅ Global Average Pooling done. Output saved to %s", fname_out);

        $finish;
    end

endmodule
