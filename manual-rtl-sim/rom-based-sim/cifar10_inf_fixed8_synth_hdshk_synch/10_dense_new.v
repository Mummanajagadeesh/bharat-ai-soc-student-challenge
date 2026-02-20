`timescale 1ns / 1ps

module dense_layer_q15_dump (
    input wire clk,
    input wire rst
);
    parameter INPUT_SIZE  = 64;
    parameter OUTPUT_SIZE = 10;

    // GAP vector in Q15 integer form (stored in 25 bits to avoid truncation)
    reg signed [24:0] gap_q15 [0:INPUT_SIZE-1];

    // Kernel / bias ROM interface
    reg  [15:0] rom_row, rom_col;
    wire signed [7:0] kernel_val_q15;
    wire signed [7:0] bias_val_q15;

    // ROM instances (must match your project naming)
    rom_10_dense_kernel kernel_rom (
        .row(rom_row),
        .col(rom_col),
        .data(kernel_val_q15)
    );

    rom_10_dense_bias bias_rom (
        .row(rom_row),
        .col(rom_col),
        .data(bias_val_q15)
    );

    // Local variables
    integer i, j, fin, fout, ret;
    reg signed [24:0] in_val;
    reg signed [49:0] product50; // Q15*Q15 = Q30, needs up to 50 bits for accumulation
    reg signed [54:0] accum;     // Enough for sum of 64 products
    reg signed [54:0] rounded_div;
    reg signed [24:0] bias25;
    reg signed [54:0] out55;
    reg signed [24:0] out25;
    reg [200*8:1] fname_in, fname_out;

    // Rounding constant for nearest rounding in Q15 multiply (2^14)
    localparam signed [54:0] ROUND_CONST = 55'sd64;

    initial begin
        $display("🔄 dense_layer_q15_dump: Starting dense layer integer computation...");

        // === Load Q15 GAP vector ===
        $sformat(fname_in, "gap_v.txt");
        fin = $fopen(fname_in, "r");
        if (fin == 0) begin
            $display("ERROR: Cannot open %s", fname_in);
            $finish;
        end

        for (i = 0; i < INPUT_SIZE; i = i + 1) begin
            ret = $fscanf(fin, "%d\n", in_val);
            if (ret != 1) begin
                $display("ERROR: Failed reading GAP[%0d] from %s", i, fname_in);
                $finish;
            end
            gap_q15[i] = in_val;
        end
        $fclose(fin);
        $display("-> Loaded GAP vector from %s", fname_in);

        // === Compute dense outputs ===
        $sformat(fname_out, "logits_v.txt");
        fout = $fopen(fname_out, "w");
        if (fout == 0) begin
            $display("ERROR: Cannot open %s", fname_out);
            $finish;
        end

        for (j = 0; j < OUTPUT_SIZE; j = j + 1) begin
            accum = 55'sd0;

            for (i = 0; i < INPUT_SIZE; i = i + 1) begin
                rom_row = i;
                rom_col = j;
                #1; // allow ROM to output
                product50 = $signed(gap_q15[i]) * $signed(kernel_val_q15); // Q15*Q15=Q30
                accum = accum + product50;
            end

            // Rounding divide by 2^15 to bring back to Q15 scale
            if (accum >= 0)
                rounded_div = (accum + ROUND_CONST) >>> 7;
            else
                rounded_div = -(((-accum) + ROUND_CONST) >>> 7);

            // Add bias (already Q15 integer)
            rom_row = j;
            rom_col = 0;
            #1;
            bias25 = $signed(bias_val_q15);
            out55  = rounded_div + bias25;

            // Final output in Q15 integer range
            out25 = out55[24:0];
            $fwrite(fout, "%0d\n", out25);
        end

        $fclose(fout);
        $display("✅ dense_layer_q15_dump done. Outputs in logits_v.txt");

        $finish;
    end
endmodule
