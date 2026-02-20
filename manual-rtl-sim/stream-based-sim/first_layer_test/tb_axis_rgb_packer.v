`timescale 1ns/1ps

module tb_axis_rgb_packer_verify;

    reg clk;
    reg rst_n;

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    localparam IMG_PIXELS   = 1024;
    localparam [31:0] LEN   = IMG_PIXELS * 3;
    localparam CHECK_PIXELS = 16;

    // DMA control
    reg  start;
    wire done;

    // AXI-Stream byte stream (DMA → packer)
    wire        s_tvalid;
    wire [7:0]  s_tdata;
    wire        s_tready;

    // DDR interface
    wire        mem_req_valid;
    wire [31:0] mem_req_addr;
    wire        mem_resp_valid;
    wire [7:0]  mem_resp_data;

    // DDR model
    ddr_mem_dualport ddr (
        .clk(clk),
        .rst_n(rst_n),

        .a_req_valid(mem_req_valid),
        .a_req_addr (mem_req_addr),
        .a_resp_valid(mem_resp_valid),
        .a_resp_rdata(mem_resp_data),

        .b_req_valid(1'b0),
        .b_req_addr (32'd0),
        .b_req_wdata(8'd0)
    );

    // DMA → AXI-Stream bytes
    dma_read dma (
        .clk(clk),
        .rst_n(rst_n),

        .start(start),
        .base_addr(0),
        .length(LEN),
        .done(done),

        .mem_req_valid(mem_req_valid),
        .mem_req_write(),
        .mem_req_addr(mem_req_addr),
        .mem_resp_valid(mem_resp_valid),
        .mem_resp_rdata(mem_resp_data),

        .m_tvalid(s_tvalid),
        .m_tdata (s_tdata),
        .m_tready(s_tready)
    );

    // AXI-Stream RGB output
    wire        rgb_tvalid;
    wire [23:0] rgb_tdata;
    wire        rgb_tlast;

    axis_rgb_packer #(
        .IMG_PIXELS(IMG_PIXELS)
    ) packer (
        .clk(clk),
        .rst_n(rst_n),

        .s_tvalid(s_tvalid),
        .s_tdata (s_tdata),
        .s_tready(s_tready),

        .m_tvalid(rgb_tvalid),
        .m_tdata (rgb_tdata),
        .m_tlast (rgb_tlast),
        .m_tready(1'b1)
    );

    // Expected data
    reg [7:0] exp_r [0:IMG_PIXELS-1];
    reg [7:0] exp_g [0:IMG_PIXELS-1];
    reg [7:0] exp_b [0:IMG_PIXELS-1];

    integer pix;
    integer errors;

    initial begin
        rst_n  = 0;
        start = 0;
        pix   = 0;
        errors = 0;

        #20 rst_n = 1;

        // Expected pixel data
        $readmemh("image_txt/image_r.mem", exp_r);
        $readmemh("image_txt/image_g.mem", exp_g);
        $readmemh("image_txt/image_b.mem", exp_b);

        // DDR layout: R | G | B
        $readmemh("image_txt/image_r.mem", ddr.ddr_mem, 0, IMG_PIXELS-1);
        $readmemh("image_txt/image_g.mem", ddr.ddr_mem, IMG_PIXELS, 2*IMG_PIXELS-1);
        $readmemh("image_txt/image_b.mem", ddr.ddr_mem, 2*IMG_PIXELS, 3*IMG_PIXELS-1);

        @(posedge clk);
        start <= 1;
        @(posedge clk);
        start <= 0;
    end

    always @(posedge clk) begin
        if (rgb_tvalid && pix < CHECK_PIXELS) begin
            $display(
                "PIX %0d | R=%0d G=%0d B=%0d | TLAST=%0d | EXP_R=%0d EXP_G=%0d EXP_B=%0d",
                pix,
                rgb_tdata[23:16],
                rgb_tdata[15:8],
                rgb_tdata[7:0],
                rgb_tlast,
                exp_r[pix],
                exp_g[pix],
                exp_b[pix]
            );

            if (rgb_tdata[23:16] !== exp_r[pix] ||
                rgb_tdata[15:8]  !== exp_g[pix] ||
                rgb_tdata[7:0]   !== exp_b[pix]) begin
                $display("ERROR at pixel %0d", pix);
                errors = errors + 1;
            end

            pix = pix + 1;

            if (pix == CHECK_PIXELS) begin
                if (errors == 0)
                    $display("[PASS] RGB packing verified");
                else
                    $display("[FAIL] RGB packing errors = %0d", errors);
                $finish;
            end
        end
    end

endmodule
