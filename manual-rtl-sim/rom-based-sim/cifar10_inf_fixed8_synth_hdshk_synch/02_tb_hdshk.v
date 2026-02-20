`timescale 1ns/1ps

// Combined TB: conv1 -> conv2 -> maxpool
// - runs conv2d_mem (conv1), captures its outputs to ifm_mem1
// - runs conv2d2_mem (conv2) consuming ifm_mem1 via handshake, captures outputs to ifm_mem2
// - runs max_pool_mem consuming ifm_mem2 via handshake, dumps pooled outputs to files
module conv2d2_maxpool_tb;

    // clock / reset
    reg clk;
    reg rst;
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Common parameters (keep in TB so modules can be parameterized)
    localparam W  = 32;
    localparam H  = 32;
    localparam F1 = 16;   // conv1 filters / conv2 channels
    localparam F2 = 16;   // conv2 filters (output channels)
    localparam NPIX = W * H;

    // -------------------------
    // --- Conv1 (existing) ---
    // -------------------------
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

    // image ROMs (handshake)
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

    // 00 kernel/bias ROMs (handshake)
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

    // Capture conv1 outputs into ifm_mem1 (Q1.7 signed [15:0])
    reg signed [15:0] ifm_mem1 [0:F1-1][0:NPIX-1];
    integer pix_cnt1, ch_idx1;
    initial begin pix_cnt1 = 0; ch_idx1 = 0; end

    always @(posedge clk) begin
        if (rst) begin
            pix_cnt1 <= 0; ch_idx1 <= 0;
        end else if (out1_valid && (ch_idx1 < F1)) begin
            ifm_mem1[ch_idx1][pix_cnt1] <= out1_data[15:0];
            pix_cnt1 <= pix_cnt1 + 1;
            if (pix_cnt1 + 1 == NPIX) begin
                pix_cnt1 <= 0;
                ch_idx1 <= ch_idx1 + 1;
            end
        end
    end

    // -------------------------
    // --- Conv2 (existing) ---
    // -------------------------
    reg start2;
    wire done2;

    // IFM handshake for conv2 (TB will serve ifm_mem1)
    wire [9:0] ifm_addr2;
    wire [3:0] ifm_chan2;
    wire       ifm_addr_valid2;
    wire       ifm_addr_ready2;
    wire signed [15:0] ifm_data2;
    wire       ifm_data_valid2;
    wire       ifm_data_ready2;

    wire [11:0] kern1_addr;
    wire        kern1_addr_valid;
    wire        kern1_addr_ready;
    wire signed [7:0] kern1_data;
    wire        kern1_data_valid;
    wire        kern1_data_ready;

    wire [3:0] bias1_addr;
    wire       bias1_addr_valid;
    wire       bias1_addr_ready;
    wire signed [7:0] bias1_data;
    wire       bias1_data_valid;
    wire       bias1_data_ready;

    wire        out2_valid;
    wire [31:0] out2_data;

    // 01 kernel/bias ROMs
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

    // TB IFM-servicer for conv2 (serves ifm_mem1)
    reg [9:0] ifm1_addr_lat;
    reg [3:0] ifm1_chan_lat;
    reg       ifm1_addr_ready_q;
    reg       ifm1_data_valid_q;

    assign ifm_addr_ready2 = ifm1_addr_ready_q;
    assign ifm_data2       = ifm_mem1[ifm1_chan_lat][ifm1_addr_lat];
    assign ifm_data_valid2 = ifm1_data_valid_q;

    always @(posedge clk) begin
        if (rst) begin
            ifm1_addr_ready_q <= 1'b0;
            ifm1_data_valid_q <= 1'b0;
            ifm1_addr_lat <= 10'd0;
            ifm1_chan_lat <= 4'd0;
        end else begin
            if (ifm_addr_valid2 && !ifm1_addr_ready_q) begin
                ifm1_addr_lat <= ifm_addr2;
                ifm1_chan_lat <= ifm_chan2;
                ifm1_addr_ready_q <= 1'b1;
            end else begin
                ifm1_addr_ready_q <= 1'b0;
            end

            if (ifm1_addr_ready_q) begin
                ifm1_data_valid_q <= 1'b1;
            end else if (ifm_data_valid2 && ifm_data_ready2) begin
                ifm1_data_valid_q <= 1'b0;
            end
        end
    end

    // Capture conv2 outputs into ifm_mem2
    reg signed [15:0] ifm_mem2 [0:F2-1][0:NPIX-1];
    integer pix_cnt2, ch_idx2;
    initial begin pix_cnt2 = 0; ch_idx2 = 0; end

    always @(posedge clk) begin
        if (rst) begin
            pix_cnt2 <= 0; ch_idx2 <= 0;
        end else if (out2_valid && (ch_idx2 < F2)) begin
            ifm_mem2[ch_idx2][pix_cnt2] <= out2_data[15:0];
            pix_cnt2 <= pix_cnt2 + 1;
            if (pix_cnt2 + 1 == NPIX) begin
                pix_cnt2 <= 0;
                ch_idx2 <= ch_idx2 + 1;
            end
        end
    end

    // -------------------------
    // --- MaxPool (new) ---
    // -------------------------
    reg start3;
    wire done3;

    // IFM handshake for maxpool (serves ifm_mem2)
    wire [9:0] ifm_addr3;
    wire [3:0] ifm_chan3;
    wire       ifm_addr_valid3;
    wire       ifm_addr_ready3;
    wire signed [15:0] ifm_data3;
    wire       ifm_data_valid3;
    wire       ifm_data_ready3;

    wire        out3_valid;
    wire signed [31:0] out3_data;

    max_pool_mem #(
        .WIDTH_IN(W),
        .HEIGHT_IN(H),
        .CHANNELS(F2),
        .POOL_SIZE(2),
        .STRIDE(2)
    ) u_maxpool (
        .clk(clk), .rst(rst), .start(start3), .done(done3),

        .ifm_addr(ifm_addr3),
        .ifm_chan(ifm_chan3),
        .ifm_addr_valid(ifm_addr_valid3),
        .ifm_addr_ready(ifm_addr_ready3),

        .ifm_data(ifm_data3),
        .ifm_data_valid(ifm_data_valid3),
        .ifm_data_ready(ifm_data_ready3),

        .out_data(out3_data),
        .out_valid(out3_valid)
    );

    // TB IFM-servicer for maxpool (serves ifm_mem2)
    reg [9:0] ifm2_addr_lat;
    reg [3:0] ifm2_chan_lat;
    reg       ifm2_addr_ready_q;
    reg       ifm2_data_valid_q;

    assign ifm_addr_ready3 = ifm2_addr_ready_q;
    assign ifm_data3       = ifm_mem2[ifm2_chan_lat][ifm2_addr_lat];
    assign ifm_data_valid3 = ifm2_data_valid_q;

    always @(posedge clk) begin
        if (rst) begin
            ifm2_addr_ready_q <= 1'b0;
            ifm2_data_valid_q <= 1'b0;
            ifm2_addr_lat <= 10'd0;
            ifm2_chan_lat <= 4'd0;
        end else begin
            if (ifm_addr_valid3 && !ifm2_addr_ready_q) begin
                ifm2_addr_lat <= ifm_addr3;
                ifm2_chan_lat <= ifm_chan3;
                ifm2_addr_ready_q <= 1'b1;
            end else begin
                ifm2_addr_ready_q <= 1'b0;
            end

            if (ifm2_addr_ready_q) begin
                ifm2_data_valid_q <= 1'b1;
            end else if (ifm_data_valid3 && ifm_data_ready3) begin
                ifm2_data_valid_q <= 1'b0;
            end
        end
    end

    // Output dump for maxpool (Q1.7 ints)
    integer fout3;
    integer pix_cnt3;
    integer filt_idx3;
    integer pixels_per_filter3;
    reg [200*8:1] fname3;
    reg writing_en3;

    task open_next_file3;
        begin
            $sformat(fname3, "max_pool_1_v/feature_map_%0d.txt", filt_idx3);
            fout3 = $fopen(fname3, "w");
            if (fout3 == 0) begin
                $display("ERROR: failed to open %0s", fname3);
                $finish;
            end
            writing_en3 = 1'b1;
            $display("Opened %0s", fname3);
        end
    endtask

    // TB sequence
    initial begin
        $display("Starting conv2d2_maxpool_tb...");
        rst = 1'b1;
        start1 = 1'b0; start2 = 1'b0; start3 = 1'b0;
        fout3 = 0; writing_en3 = 1'b0;
        filt_idx3 = 0; pix_cnt3 = 0;

        repeat (6) @(posedge clk);
        rst = 1'b0;

        // run conv1
        @(posedge clk);
        start1 = 1'b1;
        @(posedge clk);
        start1 = 1'b0;

        // wait conv1 done and captured into ifm_mem1
        wait (done1 === 1'b1);

        // run conv2 (consumes ifm_mem1)
        @(posedge clk);
        start2 = 1'b1;
        @(posedge clk);
        start2 = 1'b0;
        wait (done2 === 1'b1);

        // now run maxpool (consumes ifm_mem2)
        pixels_per_filter3 = (W/2) * (H/2);
        open_next_file3();

        @(posedge clk);
        start3 = 1'b1;
        @(posedge clk);
        start3 = 1'b0;
        wait (done3 === 1'b1);

        if (fout3 != 0) begin
            $fclose(fout3);
            fout3 = 0;
        end

        $display("✓ conv2d2_maxpool_tb completed.");
        $finish;
    end

    // Write outputs of maxpool
    always @(posedge clk) begin
        if (out3_valid && writing_en3 && (filt_idx3 < F2)) begin
            if (fout3 != 0) begin
                $fwrite(fout3, "%0d ", $signed(out3_data));   // Q1.7 integer printed as signed decimal
                pix_cnt3 = pix_cnt3 + 1;

                if ((pix_cnt3 % (W/2)) == 0)
                    $fwrite(fout3, "\n");

                if (pix_cnt3 == pixels_per_filter3) begin
                    $fclose(fout3);
                    $display("-> Wrote pooled feature_map_%0d.txt", filt_idx3);
                    fout3 = 0;
                    writing_en3 = 1'b0;
                    pix_cnt3 = 0;
                    filt_idx3 = filt_idx3 + 1;
                    if (filt_idx3 < F2) open_next_file3();
                end
            end
        end
    end

    always @(posedge clk) begin
        if (done3) writing_en3 = 1'b0;
    end

endmodule
