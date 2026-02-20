`timescale 1ns / 1ps

module conv2d_mem_tb;

    // Clock / Reset / Start
    reg clk;
    reg rst;
    reg start;

    // DUT <-> ROM signals
    wire [9:0] image_addr;
    wire [8:0] kernel_addr;
    wire [3:0] bias_addr;

    wire [7:0] image_r_data;
    wire [7:0] image_g_data;
    wire [7:0] image_b_data;
    wire [7:0] kernel_data;
    wire [7:0] bias_data;

    // DUT outputs
    wire        out_valid;
    wire [31:0] out_data;
    wire        done;

    // Clock
    initial clk = 1'b0;
    always #5 clk = ~clk; // 100 MHz

    // Instantiate ROMs
    image_r_rom           u_img_r (.clk(clk), .addr(image_addr),  .data(image_r_data));
    image_g_rom           u_img_g (.clk(clk), .addr(image_addr),  .data(image_g_data));
    image_b_rom           u_img_b (.clk(clk), .addr(image_addr),  .data(image_b_data));
    rom_00_conv2d_kernel  u_kern  (.clk(clk), .addr(kernel_addr), .data(kernel_data));
    rom_00_conv2d_bias    u_bias  (.clk(clk), .addr(bias_addr),   .data(bias_data));

    // DUT (default POST_ADD bias mode to match your expected)
    conv2d_mem #(
        .WIDTH(32),
        .HEIGHT(32),
        .CHANNELS(3),
        .FILTERS(16),
        .K(3),
        .PAD(1),
        .BIAS_MODE_POST_ADD(1)
    ) dut (
        .clk(clk),
        .rst(rst),
        .start(start),
        .done(done),

        .image_addr(image_addr),
        .image_r_data(image_r_data),
        .image_g_data(image_g_data),
        .image_b_data(image_b_data),

        .kernel_addr(kernel_addr),
        .kernel_data(kernel_data),

        .bias_addr(bias_addr),
        .bias_data(bias_data),

        .out_data(out_data),
        .out_valid(out_valid)
    );

    // ------------- File I/O -------------
    integer fout;
    integer pixel_count;
    integer filter_idx;
    integer pixels_per_filter;
    reg [200*8:1] fname;
    reg writing_en;

    task open_next_file;
        begin
            $sformat(fname, "00_conv2d_w_br/feature_map_%0d.txt", filter_idx);
            fout = $fopen(fname, "w");
            if (fout == 0) begin
                $display("ERROR: failed to open %0s (create folder 00_conv2d_w_br)", fname);
                $finish;
            end
            writing_en = 1'b1;
            $display("Opened %0s", fname);
        end
    endtask

    // Stimulus
    initial begin
        $display("Starting conv2d_mem_tb...");
        rst  = 1'b1;
        start = 1'b0;
        writing_en = 1'b0;
        fout = 0;
        filter_idx = 0;
        pixel_count = 0;

        // Wait a few cycles (like your original)
        repeat (6) @(posedge clk);
        rst = 1'b0;

        // Derived
        pixels_per_filter = dut.WIDTH * dut.HEIGHT;

        // Start DUT
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;

        // Open first feature map file (ensure folder exists beforehand)
        open_next_file();

        // Run to completion
        wait (done === 1'b1);

        // Close last file if still open
        if (fout != 0) begin
            $fclose(fout);
            fout = 0;
        end

        $display("✓ conv2d_mem_tb completed.");
        $finish;
    end

    // Capture streaming outputs
    always @(posedge clk) begin
        if (out_valid && writing_en && (filter_idx < dut.FILTERS)) begin
            if (fout != 0) begin
                $fwrite(fout, "%0d ", out_data);
                pixel_count = pixel_count + 1;

                if ((pixel_count % dut.WIDTH) == 0)
                    $fwrite(fout, "\n");

                if (pixel_count == pixels_per_filter) begin
                    $fclose(fout);
                    $display("-> Wrote feature_map_%0d.txt", filter_idx);
                    fout = 0;
                    writing_en = 1'b0;

                    pixel_count = 0;
                    filter_idx  = filter_idx + 1;

                    if (filter_idx < dut.FILTERS) begin
                        open_next_file();
                    end
                end
            end
        end
    end

    // After done, hard-disable writes
    always @(posedge clk) begin
        if (done) writing_en = 1'b0;
    end

endmodule
