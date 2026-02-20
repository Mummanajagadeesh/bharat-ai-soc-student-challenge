`timescale 1ns/1ps

module conv2d2_mem_tb;

    // ------------------------------------------------
    // Clock/reset
    // ------------------------------------------------
    reg clk;
    reg rst;
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // ------------------------------------------------
    // DUT #1: First conv (already verified)
    // ------------------------------------------------
    reg start1;
    wire done1;

    wire [9:0] img_addr;
    wire       img_addr_valid;
    wire       img_addr_ready;
    wire [7:0] img_r_data, img_g_data, img_b_data;
    wire       img_data_valid;
    wire       img_data_ready;

    wire [8:0] kern0_addr;
    wire       kern0_addr_valid;
    wire       kern0_addr_ready;
    wire [7:0] kern0_data;
    wire       kern0_data_valid;
    wire       kern0_data_ready;

    wire [3:0] bias0_addr;
    wire       bias0_addr_valid;
    wire       bias0_addr_ready;
    wire [7:0] bias0_data;
    wire       bias0_data_valid;
    wire       bias0_data_ready;

    wire        out1_valid;
    wire [31:0] out1_data;

    // Image ROMs (handshake versions — same as your earlier image_*_rom)
    image_r_rom u_img_r (
        .clk(clk), .rst(rst),
        .addr(img_addr), .addr_valid(img_addr_valid), .addr_ready(img_addr_ready),
        .data(img_r_data), .data_valid(img_data_valid), .data_ready(img_data_ready)
    );
    image_g_rom u_img_g (
        .clk(clk), .rst(rst),
        .addr(img_addr), .addr_valid(img_addr_valid), .addr_ready(), // shared
        .data(img_g_data), .data_valid(), .data_ready(img_data_ready)
    );
    image_b_rom u_img_b (
        .clk(clk), .rst(rst),
        .addr(img_addr), .addr_valid(img_addr_valid), .addr_ready(), // shared
        .data(img_b_data), .data_valid(), .data_ready(img_data_ready)
    );

    // 00 kernel/bias ROMs (handshake versions)
    rom_00_conv2d_kernel u_kern0 (
        .clk(clk), .rst(rst),
        .addr(kern0_addr), .addr_valid(kern0_addr_valid), .addr_ready(kern0_addr_ready),
        .data(kern0_data), .data_valid(kern0_data_valid), .data_ready(kern0_data_ready)
    );
    rom_00_conv2d_bias u_bias0 (
        .clk(clk), .rst(rst),
        .addr(bias0_addr), .addr_valid(bias0_addr_valid), .addr_ready(bias0_addr_ready),
        .data(bias0_data), .data_valid(bias0_data_valid), .data_ready(bias0_data_ready)
    );

    // First conv
    conv2d_mem dut1 (
        .clk(clk), .rst(rst), .start(start1), .done(done1),

        .image_addr(img_addr),
        .image_addr_valid(img_addr_valid),
        .image_addr_ready(img_addr_ready),
        .image_r_data(img_r_data),
        .image_g_data(img_g_data),
        .image_b_data(img_b_data),
        .image_data_valid(img_data_valid),
        .image_data_ready(img_data_ready),

        .kernel_addr(kern0_addr),
        .kernel_addr_valid(kern0_addr_valid),
        .kernel_addr_ready(kern0_addr_ready),
        .kernel_data(kern0_data),
        .kernel_data_valid(kern0_data_valid),
        .kernel_data_ready(kern0_data_ready),

        .bias_addr(bias0_addr),
        .bias_addr_valid(bias0_addr_valid),
        .bias_addr_ready(bias0_addr_ready),
        .bias_data(bias0_data),
        .bias_data_valid(bias0_data_valid),
        .bias_data_ready(bias0_data_ready),

        .out_data(out1_data),
        .out_valid(out1_valid)
    );

    // ------------------------------------------------
    // Capture L1 outputs into TB memory (Q1.7 ints)
    // ------------------------------------------------
localparam W  = 32;   // must match conv2d_mem.WIDTH
localparam H  = 32;   // must match conv2d_mem.HEIGHT
localparam C1 = 16;   // must match conv2d_mem.FILTERS
        // 16 channels out of layer 1
    localparam NPIX = W*H;

    reg signed [15:0] ifm_mem [0:C1-1][0:NPIX-1]; // store Q1.7 ints (truncate/clip from 32b)
    integer pix_cnt1;
    integer ch_idx1;

    // We rely on dut1’s emission order: per filter, raster scan (row-major).
    // Re-create the same counters as your first TB did.
    initial begin
        pix_cnt1 = 0;
        ch_idx1  = 0;
    end

    always @(posedge clk) begin
        if (rst) begin
            pix_cnt1 <= 0;
            ch_idx1  <= 0;
        end else if (out1_valid && (ch_idx1 < C1)) begin
            // store pixel
            ifm_mem[ch_idx1][pix_cnt1] <= out1_data[15:0]; // Q1.7 integer domain
            pix_cnt1 <= pix_cnt1 + 1;

            if (pix_cnt1 + 1 == NPIX) begin
                pix_cnt1 <= 0;
                ch_idx1  <= ch_idx1 + 1;
            end
        end
    end

    // ------------------------------------------------
    // DUT #2: Second conv (handshake, Q1.7×Q1.7, >>>7, +bias, ReLU)
    // ------------------------------------------------
    reg  start2;
    wire done2;

    wire [9:0]        ifm_addr2;
    wire [3:0]        ifm_chan2;
    wire              ifm_addr_valid2;
    wire              ifm_addr_ready2;
    wire signed [15:0] ifm_data2;
    wire              ifm_data_valid2;
    wire              ifm_data_ready2;

    wire [11:0]       kern1_addr;
    wire              kern1_addr_valid;
    wire              kern1_addr_ready;
    wire signed [7:0] kern1_data;
    wire              kern1_data_valid;
    wire              kern1_data_ready;

    wire [3:0]        bias1_addr;
    wire              bias1_addr_valid;
    wire              bias1_addr_ready;
    wire signed [7:0] bias1_data;
    wire              bias1_data_valid;
    wire              bias1_data_ready;

    wire        out2_valid;
    wire [31:0] out2_data;

    // 01 kernel/bias ROMs (handshake versions)
    rom_01_conv2d_1_kernel u_kern1 (
        .clk(clk), .rst(rst),
        .addr(kern1_addr), .addr_valid(kern1_addr_valid), .addr_ready(kern1_addr_ready),
        .data(kern1_data), .data_valid(kern1_data_valid), .data_ready(kern1_data_ready)
    );
    rom_01_conv2d_1_bias u_bias1 (
        .clk(clk), .rst(rst),
        .addr(bias1_addr), .addr_valid(bias1_addr_valid), .addr_ready(bias1_addr_ready),
        .data(bias1_data), .data_valid(bias1_data_valid), .data_ready(bias1_data_ready)
    );

    // Second conv
    conv2d2_mem dut2 (
        .clk(clk), .rst(rst), .start(start2), .done(done2),

        .ifm_addr(ifm_addr2),
        .ifm_chan(ifm_chan2),
        .ifm_addr_valid(ifm_addr_valid2),
        .ifm_addr_ready(ifm_addr_ready2),
        .ifm_data(ifm_data2),
        .ifm_data_valid(ifm_data_valid2),
        .ifm_data_ready(ifm_data_ready2),

        .kernel_addr(kern1_addr),
        .kernel_addr_valid(kern1_addr_valid),
        .kernel_addr_ready(kern1_addr_ready),
        .kernel_data(kern1_data),
        .kernel_data_valid(kern1_data_valid),
        .kernel_data_ready(kern1_data_ready),

        .bias_addr(bias1_addr),
        .bias_addr_valid(bias1_addr_valid),
        .bias_addr_ready(bias1_addr_ready),
        .bias_data(bias1_data),
        .bias_data_valid(bias1_data_valid),
        .bias_data_ready(bias1_data_ready),

        .out_data(out2_data),
        .out_valid(out2_valid)
    );

    // -----------------------------------------------
    // TB-driven IFM handshake for dut2
    // (serves values from ifm_mem[chan][addr])
    // -----------------------------------------------
    // Simple 1-cycle latency like your image_*_rom
    reg [9:0]  ifm_addr_lat;
    reg [3:0]  ifm_chan_lat;
    reg        ifm_addr_ready_q;
    reg        ifm_data_valid_q;

    assign ifm_addr_ready2 = ifm_addr_ready_q;
    assign ifm_data2       = ifm_mem[ifm_chan_lat][ifm_addr_lat];
    assign ifm_data_valid2 = ifm_data_valid_q;

    always @(posedge clk) begin
        if (rst) begin
            ifm_addr_ready_q <= 1'b0;
            ifm_data_valid_q <= 1'b0;
            ifm_addr_lat     <= 10'd0;
            ifm_chan_lat     <= 4'd0;
        end else begin
            // accept address
            if (ifm_addr_valid2 && !ifm_addr_ready_q) begin
                ifm_addr_lat     <= ifm_addr2;
                ifm_chan_lat     <= ifm_chan2;
                ifm_addr_ready_q <= 1'b1;
            end else begin
                ifm_addr_ready_q <= 1'b0;
            end

            // drive data one cycle later
            if (ifm_addr_ready_q) begin
                ifm_data_valid_q <= 1'b1;
            end else if (ifm_data_valid2 && ifm_data_ready2) begin
                ifm_data_valid_q <= 1'b0;
            end
        end
    end

    // ------------------------------------------------
    // Output dump for second conv (Q1.7 ints)
    // ------------------------------------------------
    integer fout2;
    integer pix_cnt2;
    integer filt_idx2;
    integer pixels_per_filter2;
    reg [200*8:1] fname2;
    reg writing_en2;

    task open_next_file2;
        begin
            $sformat(fname2, "01_conv2d_w_br/feature_map_%0d.txt", filt_idx2);
            fout2 = $fopen(fname2, "w");
            if (fout2 == 0) begin
                $display("ERROR: failed to open %0s", fname2);
                $finish;
            end
            writing_en2 = 1'b1;
            $display("Opened %0s", fname2);
        end
    endtask

    // ------------------------------------------------
    // TB sequence
    // ------------------------------------------------
    initial begin
        $display("Starting conv2d2_mem_tb...");
        rst       = 1'b1;
        start1    = 1'b0;
        start2    = 1'b0;

        fout2 = 0; writing_en2 = 1'b0;
        filt_idx2 = 0; pix_cnt2 = 0;

        repeat (6) @(posedge clk);
        rst = 1'b0;

        // ----- Run first conv and capture its outputs -----
        @(posedge clk);
        start1 = 1'b1;
        @(posedge clk);
        start1 = 1'b0;

        // Wait until first conv is done and we have captured all 16 maps
        wait (done1 === 1'b1);

        // ----- Now run second conv consuming captured IFMs -----
        pixels_per_filter2 = dut2.WIDTH * dut2.HEIGHT;
        open_next_file2();

        @(posedge clk);
        start2 = 1'b1;
        @(posedge clk);
        start2 = 1'b0;

        // Wait until second conv finishes
        wait (done2 === 1'b1);

        if (fout2 != 0) begin
            $fclose(fout2);
            fout2 = 0;
        end

        $display("✓ conv2d2_mem_tb completed.");
        $finish;
    end

    // write outputs of second conv
    always @(posedge clk) begin
        if (out2_valid && writing_en2 && (filt_idx2 < dut2.FILTERS)) begin
            if (fout2 != 0) begin
                $fwrite(fout2, "%0d ", out2_data);  // Q1.7 integer
                pix_cnt2 = pix_cnt2 + 1;

                if ((pix_cnt2 % dut2.WIDTH) == 0)
                    $fwrite(fout2, "\n");

                if (pix_cnt2 == pixels_per_filter2) begin
                    $fclose(fout2);
                    $display("-> Wrote feature_map_%0d.txt", filt_idx2);
                    fout2 = 0;
                    writing_en2 = 1'b0;
                    pix_cnt2 = 0;
                    filt_idx2  = filt_idx2 + 1;
                    if (filt_idx2 < dut2.FILTERS) open_next_file2();
                end
            end
        end
    end

    always @(posedge clk) begin
        if (done2) writing_en2 = 1'b0;
    end

endmodule
