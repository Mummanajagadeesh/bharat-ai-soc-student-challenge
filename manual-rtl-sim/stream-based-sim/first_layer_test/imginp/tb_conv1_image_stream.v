`timescale 1ns/1ps

module tb_conv1_image_stream;

    reg clk;
    reg rst_n;

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    localparam integer H  = 32;
    localparam integer W  = 32;
    localparam integer CH = 3;
    localparam integer IMG_PLANE   = H * W;
    localparam integer TOTAL_BYTES = IMG_PLANE * CH;

    // DMA
    reg        rd_start;
    wire       rd_done;
    wire       rd_valid;
    wire [7:0] rd_data;

    // DDR
    wire        mem_req_valid;
    wire [31:0] mem_req_addr;
    wire        mem_resp_valid;
    wire [7:0]  mem_resp_rdata;

    ddr_mem_dualport ddr (
        .clk(clk),
        .rst_n(rst_n),
        .a_req_valid (mem_req_valid),
        .a_req_addr  (mem_req_addr),
        .a_resp_valid(mem_resp_valid),
        .a_resp_rdata(mem_resp_rdata),
        .b_req_valid (),
        .b_req_addr  (),
        .b_req_wdata ()
    );

    dma_read dma_rd (
        .clk(clk),
        .rst_n(rst_n),
        .start(rd_start),
        .base_addr(32'd0),
        .length(TOTAL_BYTES[31:0]),
        .done(rd_done),
        .mem_req_valid(mem_req_valid),
        .mem_req_write(),
        .mem_req_addr(mem_req_addr),
        .mem_resp_valid(mem_resp_valid),
        .mem_resp_rdata(mem_resp_rdata),
        .m_valid(rd_valid),
        .m_data(rd_data),
        .m_ready(1'b1)
    );

    // Reference
    reg [7:0] img_r [0:IMG_PLANE-1];

    integer beat;

    initial begin
        rst_n    = 0;
        rd_start = 0;
        beat     = 0;

        #20 rst_n = 1;

        $readmemh("image_txt/image_r.mem", img_r);
        $readmemh("image_txt/image_r.mem", ddr.ddr_mem, 0, IMG_PLANE-1);
        $readmemh("image_txt/image_g.mem", ddr.ddr_mem, IMG_PLANE, 2*IMG_PLANE-1);
        $readmemh("image_txt/image_b.mem", ddr.ddr_mem, 2*IMG_PLANE, 3*IMG_PLANE-1);

        $display("\n[TB] DEBUG FIRST 45 BYTES (R PLANE)");
        $display("beat | data | expected");

        @(posedge clk);
        rd_start <= 1;
        @(posedge clk);
        rd_start <= 0;

        while (beat < 45) begin
            @(posedge clk);
            if (rd_valid) begin
                $display("%4d | %4d | %4d",
                         beat, rd_data, img_r[beat]);

                if (rd_data !== img_r[beat]) begin
                    $display("[FAIL] Mismatch at beat %0d", beat);
                    $finish;
                end

                beat = beat + 1;
            end
        end

        $display("\n[PASS] R-plane streaming verified");
        $finish;
    end

endmodule
