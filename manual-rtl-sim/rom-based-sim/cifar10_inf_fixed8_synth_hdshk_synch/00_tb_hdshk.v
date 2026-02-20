`timescale 1ns / 1ps

module conv2d_mem_tb;

    reg clk;
    reg rst;
    reg start;

    // DUT <-> ROM signals
    wire [9:0] image_addr;
    wire       image_addr_valid;
    wire       image_addr_ready;
    wire [7:0] image_r_data, image_g_data, image_b_data;
    wire       image_data_valid;
    wire       image_data_ready;

    wire [8:0] kernel_addr;
    wire       kernel_addr_valid;
    wire       kernel_addr_ready;
    wire [7:0] kernel_data;
    wire       kernel_data_valid;
    wire       kernel_data_ready;

    wire [3:0] bias_addr;
    wire       bias_addr_valid;
    wire       bias_addr_ready;
    wire [7:0] bias_data;
    wire       bias_data_valid;
    wire       bias_data_ready;

    // DUT outputs
    wire        out_valid;
    wire [31:0] out_data;
    wire        done;

    initial clk = 1'b0;
    always #5 clk = ~clk;

    // Instantiate ROMs
    image_r_rom u_img_r (
        .clk(clk), .rst(rst),
        .addr(image_addr), .addr_valid(image_addr_valid), .addr_ready(image_addr_ready),
        .data(image_r_data), .data_valid(image_data_valid), .data_ready(image_data_ready)
    );
    image_g_rom u_img_g (
        .clk(clk), .rst(rst),
        .addr(image_addr), .addr_valid(image_addr_valid), .addr_ready(), // share addr_ready
        .data(image_g_data), .data_valid(), .data_ready(image_data_ready)
    );
    image_b_rom u_img_b (
        .clk(clk), .rst(rst),
        .addr(image_addr), .addr_valid(image_addr_valid), .addr_ready(), // share addr_ready
        .data(image_b_data), .data_valid(), .data_ready(image_data_ready)
    );

    rom_00_conv2d_kernel u_kern (
        .clk(clk), .rst(rst),
        .addr(kernel_addr), .addr_valid(kernel_addr_valid), .addr_ready(kernel_addr_ready),
        .data(kernel_data), .data_valid(kernel_data_valid), .data_ready(kernel_data_ready)
    );

    rom_00_conv2d_bias u_bias (
        .clk(clk), .rst(rst),
        .addr(bias_addr), .addr_valid(bias_addr_valid), .addr_ready(bias_addr_ready),
        .data(bias_data), .data_valid(bias_data_valid), .data_ready(bias_data_ready)
    );

    // DUT
    conv2d_mem dut (
        .clk(clk), .rst(rst), .start(start), .done(done),

        .image_addr(image_addr),
        .image_addr_valid(image_addr_valid),
        .image_addr_ready(image_addr_ready),
        .image_r_data(image_r_data),
        .image_g_data(image_g_data),
        .image_b_data(image_b_data),
        .image_data_valid(image_data_valid),
        .image_data_ready(image_data_ready),

        .kernel_addr(kernel_addr),
        .kernel_addr_valid(kernel_addr_valid),
        .kernel_addr_ready(kernel_addr_ready),
        .kernel_data(kernel_data),
        .kernel_data_valid(kernel_data_valid),
        .kernel_data_ready(kernel_data_ready),

        .bias_addr(bias_addr),
        .bias_addr_valid(bias_addr_valid),
        .bias_addr_ready(bias_addr_ready),
        .bias_data(bias_data),
        .bias_data_valid(bias_data_valid),
        .bias_data_ready(bias_data_ready),

        .out_data(out_data),
        .out_valid(out_valid)
    );

    // File I/O
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
                $display("ERROR: failed to open %0s", fname);
                $finish;
            end
            writing_en = 1'b1;
            $display("Opened %0s", fname);
        end
    endtask

    initial begin
        $display("Starting conv2d_mem_tb...");
        rst  = 1'b1;
        start = 1'b0;
        writing_en = 1'b0;
        fout = 0;
        filter_idx = 0;
        pixel_count = 0;

        repeat (6) @(posedge clk);
        rst = 1'b0;

        pixels_per_filter = dut.WIDTH * dut.HEIGHT;

        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;

        open_next_file();

        wait (done === 1'b1);

        if (fout != 0) begin
            $fclose(fout);
            fout = 0;
        end

        $display("✓ conv2d_mem_tb completed.");
        $finish;
    end

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
                    if (filter_idx < dut.FILTERS) open_next_file();
                end
            end
        end
    end

    always @(posedge clk) begin
        if (done) writing_en = 1'b0;
    end

endmodule
