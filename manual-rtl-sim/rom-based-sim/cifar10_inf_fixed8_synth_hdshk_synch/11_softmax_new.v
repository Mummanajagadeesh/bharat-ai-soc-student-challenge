`timescale 1ns / 1ps

module softmax_and_class_q15 (
    input wire clk,
    input wire rst,
    output reg done
);
    parameter CLASS_NUM = 10;
    parameter LABEL_LEN = 10; // max chars per label

    // Storage for Q15 inputs
    reg signed [24:0] logits_q15 [0:CLASS_NUM-1];
    real logits_f [0:CLASS_NUM-1];
    real exps [0:CLASS_NUM-1];
    real sum_exp;
    real softmax_f [0:CLASS_NUM-1];

    reg signed [24:0] softmax_q15 [0:CLASS_NUM-1];

    integer fin, fout, ret;
    integer i, max_idx;
    real max_val;

    reg [200*8:1] fname_in, fname_out;
    reg [8*LABEL_LEN-1:0] labels [0:CLASS_NUM-1];
    integer char_i;

    // Scaling constant for Q15
    real SCALE_Q15;

    initial begin
        done = 0;
        SCALE_Q15 = 2.0**15; // Q15 scaling

        $display("🔄 Starting softmax computation (Q15 I/O)...");

        // === Initialize label mapping ===
        labels[0] = {    "airplane   "};
        labels[1] = {    "automobile"};
        labels[2] = {    "bird      "};
        labels[3] = {    "cat       "};
        labels[4] = {    "deer      "};
        labels[5] = {    "dog       "};
        labels[6] = {    "frog      "};
        labels[7] = {    "horse     "};
        labels[8] = {    "ship      "};
        labels[9] = {    "truck     "};

        // === Load logits from file ===
        $sformat(fname_in, "logits_v.txt");
        fin = $fopen(fname_in, "r");
        if (fin == 0) begin
            $display("ERROR: Could not open logits file %s", fname_in);
            $finish;
        end

        for (i = 0; i < CLASS_NUM; i = i + 1) begin
            ret = $fscanf(fin, "%d\n", logits_q15[i]);
            if (ret != 1) begin
                $display("ERROR: Failed reading logits[%0d] from %s", i, fname_in);
                $finish;
            end
            logits_f[i] = logits_q15[i] / SCALE_Q15; // Q15 → float
        end
        $fclose(fin);

        // === Compute softmax in float ===
        max_val = logits_f[0];
        for (i = 1; i < CLASS_NUM; i = i + 1) begin
            if (logits_f[i] > max_val) max_val = logits_f[i];
        end

        sum_exp = 0.0;
        for (i = 0; i < CLASS_NUM; i = i + 1) begin
            exps[i] = $pow(2.718281828, logits_f[i] - max_val);
            sum_exp = sum_exp + exps[i];
        end

        for (i = 0; i < CLASS_NUM; i = i + 1) begin
            softmax_f[i] = exps[i] / sum_exp;
            softmax_q15[i] = $rtoi(softmax_f[i] * SCALE_Q15); // float → Q15
        end

        // === Find predicted class ===
        max_idx = 0;
        max_val = softmax_f[0];
        for (i = 1; i < CLASS_NUM; i = i + 1) begin
            if (softmax_f[i] > max_val) begin
                max_val = softmax_f[i];
                max_idx = i;
            end
        end

        // === Write Q15 softmax probs to file ===
        $sformat(fname_out, "softmax_v.txt");
        fout = $fopen(fname_out, "w");
        if (fout == 0) begin
            $display("ERROR: Could not open %s", fname_out);
            $finish;
        end

        for (i = 0; i < CLASS_NUM; i = i + 1) begin
            $fwrite(fout, "%0d\n", softmax_q15[i]);
        end
        $fclose(fout);

        $display("✅ Softmax Q15 done. Probabilities saved in %s", fname_out);

        // Print predicted label
        $write("🎯 Predicted class: %0d (", max_idx);
        for (char_i = LABEL_LEN-1; char_i >= 0; char_i = char_i - 1) begin
            $write("%s", labels[max_idx][8*char_i +: 8]);
        end
        $write(") with probability %f\n", softmax_f[max_idx]);

        done = 1;
        $finish;
    end
endmodule
