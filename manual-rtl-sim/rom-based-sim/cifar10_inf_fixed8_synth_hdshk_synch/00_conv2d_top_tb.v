`timescale 1ns / 1ps

// conv2d_mem.v
// Robust synchronous ROM read (two-cycle handshake) + small debug prints

module conv2d_mem (
    input wire clk
);
    parameter WIDTH    = 32;
    parameter HEIGHT   = 32;
    parameter CHANNELS = 3;
    parameter FILTERS  = 16;
    parameter K        = 3;
    parameter PAD      = 1;

    // addresses
    reg  [9:0]  image_addr;
    reg  [8:0]  kernel_addr;
    reg  [3:0]  bias_addr;

    // rom outputs (unsigned wires from ROMs)
    wire [7:0] image_r_data;
    wire [7:0] image_g_data;
    wire [7:0] image_b_data;
    wire [7:0] kernel_data;
    wire [7:0] bias_data;

    // instantiate ROMs (your generated modules)
    image_r_rom         rom_r (.clk(clk), .addr(image_addr),  .data(image_r_data));
    image_g_rom         rom_g (.clk(clk), .addr(image_addr),  .data(image_g_data));
    image_b_rom         rom_b (.clk(clk), .addr(image_addr),  .data(image_b_data));
    rom_00_conv2d_kernel rom_k (.clk(clk), .addr(kernel_addr), .data(kernel_data));
    rom_00_conv2d_bias   bias_k (.clk(clk), .addr(bias_addr),   .data(bias_data));

    // working regs
    integer f, i, j, c, m, n;
    integer fout;
    reg signed [63:0] accum;
    reg signed [63:0] numerator;
    reg signed [47:0] kernel_mul;
    reg signed [47:0] bias_times_255;
    reg signed [31:0] out_int;
    reg signed [31:0] out_int_relu;
    reg [7:0] pix8;
    reg signed [15:0] kern16;
    reg signed [15:0] bias16;
    reg signed [15:0] pix_signed;

    // sampled rom q regs (captured after 2 posedges)
    reg [7:0] image_r_q, image_g_q, image_b_q;
    reg [7:0] kernel_q;
    reg [7:0] bias_q;

    integer in_x, in_y;
    integer kernel_row;
    reg [200*8:1] fname_out_relu;

    // Debug control: prints only for first filter and first few pixels
    localparam DEBUG_PIX_ROWS = 3;
    localparam DEBUG_PIX_COLS = 3;

    initial begin
        $display("🔄 conv2d_mem: waiting 6 cycles for ROM init and stable clock...");
        repeat (6) @(posedge clk);

        $display("🔄 conv2d_mem: Starting conv (memory-backed ROMs) ...");

        for (f = 0; f < FILTERS; f = f + 1) begin
            $sformat(fname_out_relu, "00_conv2d_w_br/feature_map_%0d.txt", f);
            fout = $fopen(fname_out_relu, "w");
            if (fout == 0) begin
                $display("!! ERROR: Failed to open %s", fname_out_relu);
                $finish;
            end

            // read bias (two-cycle handshake)
            bias_addr = f;
            @(posedge clk); // ROM latches addr -> data will update on this posedge
            @(posedge clk); // ensure stable
            bias_q = bias_data;
            bias16 = $signed(bias_q);
            bias_times_255 = bias16 * 32'sd255;

            for (i = 0; i < HEIGHT; i = i + 1) begin
                for (j = 0; j < WIDTH; j = j + 1) begin
                    accum = bias_times_255; // start with bias*255

                    for (m = 0; m < K; m = m + 1) begin
                        for (n = 0; n < K; n = n + 1) begin
                            in_y = i + m - PAD;
                            in_x = j + n - PAD;

                            if (!(in_y < 0 || in_y >= HEIGHT || in_x < 0 || in_x >= WIDTH)) begin
                                for (c = 0; c < CHANNELS; c = c + 1) begin
                                    // set addresses
                                    image_addr = in_y * WIDTH + in_x;
                                    kernel_row = m * K * CHANNELS + n * CHANNELS + c;
                                    kernel_addr = kernel_row * FILTERS + f;

                                    // TWO-CYCLE READ HANDSHAKE (robust)
                                    @(posedge clk); // ROM sees addr and starts updating
                                    @(posedge clk); // ROM outputs now stable for this addr

                                    // capture rom outputs
                                    image_r_q = image_r_data;
                                    image_g_q = image_g_data;
                                    image_b_q = image_b_data;
                                    kernel_q  = kernel_data;

                                    // pick pixel channel
                                    case (c)
                                        0: pix8 = image_r_q;
                                        1: pix8 = image_g_q;
                                        default: pix8 = image_b_q;
                                    endcase

                                    // signed conversions
                                    pix_signed = $signed({8'd0, pix8}); // 0..255 -> signed 16-bit
                                    kern16 = $signed(kernel_q);        // sign-extend kernel byte

                                    // signed multiply
                                    kernel_mul = kern16 * pix_signed;
                                    accum = accum + kernel_mul;

                                    // small debug: only for first filter and first few pixel coords
                                    if ((f == 0) && (i < DEBUG_PIX_ROWS) && (j < DEBUG_PIX_COLS)) begin
                                        $display("DBG f=%0d i=%0d j=%0d m=%0d n=%0d c=%0d pix=%0d pix_signed=%0d kern=%0d kernel_mul=%0d accum=%0d",
                                            f, i, j, m, n, c, pix8, pix_signed, kern16, kernel_mul, accum);
                                    end
                                end // channels
                            end // in-bounds
                        end
                    end

                    numerator = accum;

                    // Divide by 255 with rounding
                    if (numerator >= 0)
                        out_int = (numerator + 32'sd127) / 32'sd255;
                    else
                        out_int = -(( -numerator + 32'sd127) / 32'sd255);

                    // ReLU
                    if (out_int < 0)
                        out_int_relu = 32'sd0;
                    else
                        out_int_relu = out_int;

                    $fwrite(fout, "%0d ", out_int_relu);
                    if (((j+1) % WIDTH) == 0)
                        $fwrite(fout, "\n");
                end
            end

            $fclose(fout);
            $display("-> Wrote filter %0d output -> %s", f, fname_out_relu);
        end

        $display("✅ conv2d_mem done: all %0d feature maps written to 00_conv2d_w_br/", FILTERS);
        $finish;
    end
endmodule


// testbench wrapper
module conv2d_mem_tb;
    reg clk;
    conv2d_mem dut (.clk(clk));
    initial clk = 0;
    always #5 clk = ~clk;
    initial $display("Starting conv2d_mem_tb...");
endmodule
