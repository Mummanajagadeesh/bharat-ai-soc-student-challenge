`timescale 1ns/1ps
module conv_full_pipeline_tb;

    // basic clock/reset
    reg clk;
    reg rst;
    initial clk = 1'b0;
    always #5 clk = ~clk;

    // repeat (0) @(posedge clk);

    // ----------------------------
    // Parameters used by TB
    // ----------------------------
    localparam W1 = 32;
    localparam H1 = 32;
    localparam F1 = 16; // conv1 filters
    localparam F2 = 16; // conv2 output filters / maxpool channels
    localparam W2 = 16; // after pooling width
    localparam H2 = 16; // after pooling height
    localparam F3 = 32; // conv3 filters
    localparam NPIX1 = W1 * H1;
    localparam NPIX2 = W2 * H2;

    // ----------------------------
    // Instantiate conv1 (conv2d_mem) and its ROMs
    // ----------------------------
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
    wire signed [31:0] out1_data;

    // image ROMs (handshake)
    image_r_rom u_img_r (
        .clk(clk), .rst(rst),
        .addr(img_addr), .addr_valid(img_addr_valid), .addr_ready(img_addr_ready),
        .data(img_r_data), .data_valid(img_data_valid), .data_ready(img_data_ready)
    );
    image_g_rom u_img_g (
        .clk(clk), .rst(rst),
        .addr(img_addr), .addr_valid(img_addr_valid), .addr_ready(), // shared ready
        .data(img_g_data), .data_valid(), .data_ready(img_data_ready)
    );
    image_b_rom u_img_b (
        .clk(clk), .rst(rst),
        .addr(img_addr), .addr_valid(img_addr_valid), .addr_ready(), // shared ready
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

    // capture conv1 outputs into ifm_mem1 (Q1.7 signed [15:0])
    reg signed [15:0] ifm_mem1 [0:F1-1][0:NPIX1-1];
    integer pix1_cnt, ch1_idx;
    initial begin pix1_cnt = 0; ch1_idx = 0; end

    always @(posedge clk) begin
        if (rst) begin
            pix1_cnt <= 0; ch1_idx <= 0;
        end else if (out1_valid && (ch1_idx < F1)) begin
            ifm_mem1[ch1_idx][pix1_cnt] <= out1_data[15:0];
            pix1_cnt <= pix1_cnt + 1;
            if (pix1_cnt + 1 == NPIX1) begin
                pix1_cnt <= 0;
                ch1_idx <= ch1_idx + 1;
            end
        end
    end

    // ----------------------------
    // Instantiate conv2 (conv2d2_mem) and its ROMs
    // ----------------------------
    reg start2;
    wire done2;

    wire [9:0] ifm2_addr;
    wire [3:0] ifm2_chan;
    wire       ifm2_addr_valid;
    wire       ifm2_addr_ready;
    wire signed [15:0] ifm2_data;
    wire       ifm2_data_valid;
    wire       ifm2_data_ready;

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

    wire signed [31:0] out2_data;
    wire        out2_valid;

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

        .ifm_addr(ifm2_addr),
        .ifm_chan(ifm2_chan),
        .ifm_addr_valid(ifm2_addr_valid),
        .ifm_addr_ready(ifm2_addr_ready),
        .ifm_data(ifm2_data),
        .ifm_data_valid(ifm2_data_valid),
        .ifm_data_ready(ifm2_data_ready),

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
    reg [9:0]  ifm1_addr_lat;
    reg [3:0]  ifm1_chan_lat;
    reg        ifm1_addr_ready_q;
    reg        ifm1_data_valid_q;

    assign ifm2_addr_ready = ifm1_addr_ready_q;
    assign ifm2_data = ifm_mem1[ifm1_chan_lat][ifm1_addr_lat];
    assign ifm2_data_valid = ifm1_data_valid_q;

    always @(posedge clk) begin
        if (rst) begin
            ifm1_addr_ready_q <= 1'b0;
            ifm1_data_valid_q <= 1'b0;
            ifm1_addr_lat <= 10'd0;
            ifm1_chan_lat <= 4'd0;
        end else begin
            if (ifm2_addr_valid && !ifm1_addr_ready_q) begin
                ifm1_addr_lat <= ifm2_addr;
                ifm1_chan_lat <= ifm2_chan;
                ifm1_addr_ready_q <= 1'b1;
            end else begin
                ifm1_addr_ready_q <= 1'b0;
            end

            if (ifm1_addr_ready_q) begin
                ifm1_data_valid_q <= 1'b1;
            end else if (ifm2_data_valid && ifm2_data_ready) begin
                ifm1_data_valid_q <= 1'b0;
            end
        end
    end

    // capture conv2 outputs into ifm_mem2 (Q1.7)
    reg signed [15:0] ifm_mem2 [0:F2-1][0:NPIX1-1];
    integer pix2_cnt, ch2_idx;
    initial begin pix2_cnt = 0; ch2_idx = 0; end

    always @(posedge clk) begin
        if (rst) begin
            pix2_cnt <= 0; ch2_idx <= 0;
        end else if (out2_valid && (ch2_idx < F2)) begin
            ifm_mem2[ch2_idx][pix2_cnt] <= out2_data[15:0];
            pix2_cnt <= pix2_cnt + 1;
            if (pix2_cnt + 1 == NPIX1) begin
                pix2_cnt <= 0;
                ch2_idx <= ch2_idx + 1;
            end
        end
    end

    // ----------------------------
    // Maxpool (consumes ifm_mem2) - using previously provided max_pool_mem
    // ----------------------------
    reg start3;
    wire done3;

    wire [9:0] ifm3_addr;
    wire [3:0] ifm3_chan;
    wire       ifm3_addr_valid;
    wire       ifm3_addr_ready;
    wire signed [15:0] ifm3_data;
    wire       ifm3_data_valid;
    wire       ifm3_data_ready;

    wire signed [31:0] out3_data;
    wire        out3_valid;

    max_pool_mem #(
        .WIDTH_IN(W1), .HEIGHT_IN(H1), .CHANNELS(F2), .POOL_SIZE(2), .STRIDE(2)
    ) u_maxpool (
        .clk(clk), .rst(rst), .start(start3), .done(done3),
        .ifm_addr(ifm3_addr), .ifm_chan(ifm3_chan), .ifm_addr_valid(ifm3_addr_valid),
        .ifm_addr_ready(ifm3_addr_ready),
        .ifm_data(ifm3_data), .ifm_data_valid(ifm3_data_valid), .ifm_data_ready(ifm3_data_ready),
        .out_data(out3_data), .out_valid(out3_valid)
    );

    // TB IFM-servicer for maxpool (serves ifm_mem2)
    reg [9:0] ifm2_addr_lat;
    reg [3:0] ifm2_chan_lat;
    reg       ifm2_addr_ready_q;
    reg       ifm2_data_valid_q;

    assign ifm3_addr_ready = ifm2_addr_ready_q;
    assign ifm3_data = ifm_mem2[ifm2_chan_lat][ifm2_addr_lat];
    assign ifm3_data_valid = ifm2_data_valid_q;

    always @(posedge clk) begin
        if (rst) begin
            ifm2_addr_ready_q <= 1'b0;
            ifm2_data_valid_q <= 1'b0;
            ifm2_addr_lat <= 10'd0;
            ifm2_chan_lat <= 4'd0;
        end else begin
            if (ifm3_addr_valid && !ifm2_addr_ready_q) begin
                ifm2_addr_lat <= ifm3_addr;
                ifm2_chan_lat <= ifm3_chan;
                ifm2_addr_ready_q <= 1'b1;
            end else begin
                ifm2_addr_ready_q <= 1'b0;
            end

            if (ifm2_addr_ready_q) begin
                ifm2_data_valid_q <= 1'b1;
            end else if (ifm3_data_valid && ifm3_data_ready) begin
                ifm2_data_valid_q <= 1'b0;
            end
        end
    end

    // capture maxpool outputs into ifm_mem3 (Q1.7)
    reg signed [15:0] ifm_mem3 [0:F2-1][0:NPIX2-1]; // F2 channels after pooling
    integer pix3_cnt, ch3_idx;
    initial begin pix3_cnt = 0; ch3_idx = 0; end

    always @(posedge clk) begin
        if (rst) begin
            pix3_cnt <= 0; ch3_idx <= 0;
        end else if (out3_valid && (ch3_idx < F2)) begin
            ifm_mem3[ch3_idx][pix3_cnt] <= out3_data[15:0];
            pix3_cnt <= pix3_cnt + 1;
            if (pix3_cnt + 1 == NPIX2) begin
                pix3_cnt <= 0;
                ch3_idx <= ch3_idx + 1;
            end
        end
    end

    // ----------------------------
    // Conv3 (conv2d_third_mem) and its ROMs (03_*)
    // ----------------------------
    reg start4;
    wire done4;

    wire [9:0] ifm4_addr;
    wire [3:0] ifm4_chan;
    wire       ifm4_addr_valid;
    wire       ifm4_addr_ready;
    wire signed [15:0] ifm4_data;
    wire       ifm4_data_valid;
    wire       ifm4_data_ready;

    wire [12:0] kern3_addr;
    wire        kern3_addr_valid;
    wire        kern3_addr_ready;
    wire signed [7:0] kern3_data;
    wire        kern3_data_valid;
    wire        kern3_data_ready;

    wire [4:0] bias3_addr;
    wire       bias3_addr_valid;
    wire       bias3_addr_ready;
    wire signed [7:0] bias3_data;
    wire       bias3_data_valid;
    wire       bias3_data_ready;

    wire signed [31:0] out4_data;
    wire        out4_valid;

    // 03 kernel/bias ROMs (handshake versions you posted)
    rom_03_conv2d_2_kernel u_kern3 (
        .clk(clk), .rst(rst),
        .addr_valid(kern3_addr_valid), .addr_ready(kern3_addr_ready), .addr(kern3_addr),
        .data_valid(kern3_data_valid), .data_ready(kern3_data_ready), .data(kern3_data)
    );

    rom_03_conv2d_2_bias u_bias3 (
        .clk(clk), .rst(rst),
        .addr_valid(bias3_addr_valid), .addr_ready(bias3_addr_ready), .addr(bias3_addr),
        .data_valid(bias3_data_valid), .data_ready(bias3_data_ready), .data(bias3_data)
    );

    conv2d_third_mem #(
        .WIDTH(W2),
        .HEIGHT(H2),
        .CHANNELS(F2),
        .FILTERS(F3),
        .K(3),
        .PAD(1)
    ) dut4 (
        .clk(clk), .rst(rst), .start(start4), .done(done4),

        .ifm_addr(ifm4_addr),
        .ifm_chan(ifm4_chan),
        .ifm_addr_valid(ifm4_addr_valid),
        .ifm_addr_ready(ifm4_addr_ready),
        .ifm_data(ifm4_data),
        .ifm_data_valid(ifm4_data_valid),
        .ifm_data_ready(ifm4_data_ready),

        .kernel_addr(kern3_addr),
        .kernel_addr_valid(kern3_addr_valid),
        .kernel_addr_ready(kern3_addr_ready),
        .kernel_data(kern3_data),
        .kernel_data_valid(kern3_data_valid),
        .kernel_data_ready(kern3_data_ready),

        .bias_addr(bias3_addr),
        .bias_addr_valid(bias3_addr_valid),
        .bias_addr_ready(bias3_addr_ready),
        .bias_data(bias3_data),
        .bias_data_valid(bias3_data_valid),
        .bias_data_ready(bias3_data_ready),

        .out_data(out4_data),
        .out_valid(out4_valid)
    );

    // TB IFM-servicer for conv3 (serves ifm_mem3)
    reg [9:0] ifm3_addr_lat;
    reg [3:0] ifm3_chan_lat;
    reg       ifm3_addr_ready_q;
    reg       ifm3_data_valid_q;

    assign ifm4_addr_ready = ifm3_addr_ready_q;
    assign ifm4_data = ifm_mem3[ifm3_chan_lat][ifm3_addr_lat];
    assign ifm4_data_valid = ifm3_data_valid_q;

    always @(posedge clk) begin
        if (rst) begin
            ifm3_addr_ready_q <= 1'b0;
            ifm3_data_valid_q <= 1'b0;
            ifm3_addr_lat <= 10'd0;
            ifm3_chan_lat <= 4'd0;
        end else begin
            if (ifm4_addr_valid && !ifm3_addr_ready_q) begin
                ifm3_addr_lat <= ifm4_addr;
                ifm3_chan_lat <= ifm4_chan;
                ifm3_addr_ready_q <= 1'b1;
            end else begin
                ifm3_addr_ready_q <= 1'b0;
            end

            if (ifm3_addr_ready_q) begin
                ifm3_data_valid_q <= 1'b1;
            end else if (ifm4_data_valid && ifm4_data_ready) begin
                ifm3_data_valid_q <= 1'b0;
            end
        end
    end

    // ----------------------------
    // TB: write conv3 outputs to files 03_conv2d_w_br/feature_map_%0d.txt (Q1.7)
    // ----------------------------
    integer fout4;
    integer pix4_cnt;
    integer filt4_idx;
    integer pixels_per_filter4;
    reg [200*8:1] fname4;
    reg writing_en4;

    task open_next_file4;
        begin
            $sformat(fname4, "03_conv2d_w_br/feature_map_%0d.txt", filt4_idx);
            fout4 = $fopen(fname4, "w");
            if (fout4 == 0) begin
                $display("ERROR: failed to open %0s", fname4);
                $finish;
            end
            writing_en4 = 1'b1;
            $display("Opened %0s", fname4);
        end
    endtask

    // ----------------------------
    // TB sequence
    // ----------------------------
    initial begin
        $display("Starting full pipeline TB...");
        rst = 1'b1;

        start1 = 1'b0; start2 = 1'b0; start3 = 1'b0; start4 = 1'b0;
        fout4 = 0; writing_en4 = 1'b0;
        filt4_idx = 0; pix4_cnt = 0;

        repeat (6) @(posedge clk);
        rst = 1'b0;

        // run conv1
        @(posedge clk);
        start1 = 1'b1;
        @(posedge clk);
        start1 = 1'b0;
        wait (done1 === 1'b1);

        // run conv2
        @(posedge clk);
        start2 = 1'b1;
        @(posedge clk);
        start2 = 1'b0;
        wait (done2 === 1'b1);

        // run maxpool (consumes ifm_mem2)
        @(posedge clk);
        start3 = 1'b1;
        @(posedge clk);
        start3 = 1'b0;
        wait (done3 === 1'b1);

        // prepare to run conv3 (consume pooled IFMs)
        pixels_per_filter4 = NPIX2;
        open_next_file4();

        @(posedge clk);
        start4 = 1'b1;
        @(posedge clk);
        start4 = 1'b0;
        wait (done4 === 1'b1);

        if (fout4 != 0) begin
            $fclose(fout4);
            fout4 = 0;
        end

        $display("✓ full pipeline TB completed.");
        $finish;
    end

    // write outputs of conv3
    always @(posedge clk) begin
        if (out4_valid && writing_en4 && (filt4_idx < F3)) begin
            if (fout4 != 0) begin
                $fwrite(fout4, "%0d ", $signed(out4_data));  // Q1.7 integer
                pix4_cnt = pix4_cnt + 1;

                if ((pix4_cnt % W2) == 0)
                    $fwrite(fout4, "\n");

                if (pix4_cnt == pixels_per_filter4) begin
                    $fclose(fout4);
                    $display("-> Wrote conv3 feature_map_%0d.txt", filt4_idx);
                    fout4 = 0;
                    writing_en4 = 1'b0;
                    pix4_cnt = 0;
                    filt4_idx = filt4_idx + 1;
                    if (filt4_idx < F3) open_next_file4();
                end
            end
        end
    end

    always @(posedge clk) begin
        if (done4) writing_en4 = 1'b0;
    end

endmodule
