`timescale 1ns/1ps

module tb_axis_dma_write;

    reg clk = 0;
    always #5 clk = ~clk;

    reg rst_n;
    reg start_dma;
    reg start_src;
    reg start_chk;

    wire src_done;
    wire dma_done;
    wire chk_done;
    wire chk_error;

    wire tv;
    wire [7:0] td;
    wire tr;

    wire mem_wr_valid;
    wire [31:0] mem_wr_addr;
    wire [7:0] mem_wr_data;

    wire mem_rd_valid;
    wire [31:0] mem_rd_addr;
    wire [7:0] mem_rd_data;

    integer cycle;

    axis_source src (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_src),
        .M_AXIS_TVALID(tv),
        .M_AXIS_TDATA(td),
        .M_AXIS_TREADY(tr),
        .done(src_done)
    );

    axis_dma_write dma (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_dma),
        .base_addr(0),
        .length(32),
        .done(dma_done),
        .S_AXIS_TVALID(tv),
        .S_AXIS_TDATA(td),
        .S_AXIS_TREADY(tr),
        .mem_wr_valid(mem_wr_valid),
        .mem_wr_addr(mem_wr_addr),
        .mem_wr_data(mem_wr_data)
    );

    simple_mem_rw mem (
        .clk(clk),
        .rd_valid(mem_rd_valid),
        .rd_addr(mem_rd_addr),
        .rd_data(mem_rd_data),
        .wr_valid(mem_wr_valid),
        .wr_addr(mem_wr_addr),
        .wr_data(mem_wr_data)
    );

    axis_sink_memcheck memchk (
        .clk(clk),
        .rst_n(rst_n),
        .start(start_chk),
        .rd_valid(mem_rd_valid),
        .rd_addr(mem_rd_addr),
        .rd_data(mem_rd_data),
        .done(chk_done),
        .error(chk_error)
    );

    initial begin
        rst_n = 0;
        start_dma = 0;
        start_src = 0;
        start_chk = 0;
        cycle = 0;

        #20 rst_n = 1;

        @(posedge clk);
        $display("[TB] Starting DMA_WRITE");
        start_dma <= 1;
        @(posedge clk);
        start_dma <= 0;

        @(posedge clk);
        $display("[TB] Starting AXIS_SOURCE");
        start_src <= 1;
        @(posedge clk);
        start_src <= 0;

        wait (dma_done);
        $display("[TB] DMA WRITE DONE");

        @(posedge clk);
        $display("[TB] Starting MEMORY CHECK");
        start_chk <= 1;
        @(posedge clk);
        start_chk <= 0;

        wait (chk_done);

        if (chk_error)
            $display("[TB] AXI DMA WRITE TEST FAILED");
        else
            $display("[TB] AXI DMA WRITE TEST PASSED");

        #20 $finish;
    end

endmodule
