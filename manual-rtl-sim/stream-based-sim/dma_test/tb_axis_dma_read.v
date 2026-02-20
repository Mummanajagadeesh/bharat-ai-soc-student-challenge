`timescale 1ns/1ps

module tb_axis_dma_read;

    reg clk = 0;
    always #5 clk = ~clk;

    reg rst_n;
    reg start;

    wire done;
    wire sink_done;
    wire sink_error;

    wire mem_rd_valid;
    wire [31:0] mem_rd_addr;
    wire mem_rd_resp_valid;
    wire [7:0] mem_rd_resp_data;

    wire tv;
    wire [7:0] td;
    wire tr;

    simple_mem mem (
        .clk(clk),
        .rd_valid(mem_rd_valid),
        .rd_addr(mem_rd_addr),
        .rd_resp_valid(mem_rd_resp_valid),
        .rd_resp_data(mem_rd_resp_data)
    );

    axis_dma_read dma (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .base_addr(0),
        .length(32),
        .done(done),
        .mem_rd_valid(mem_rd_valid),
        .mem_rd_addr(mem_rd_addr),
        .mem_rd_resp_valid(mem_rd_resp_valid),
        .mem_rd_resp_data(mem_rd_resp_data),
        .M_AXIS_TVALID(tv),
        .M_AXIS_TDATA(td),
        .M_AXIS_TREADY(tr)
    );

    axis_sink #(.COUNT(32)) sink (
        .clk(clk),
        .rst_n(rst_n),
        .S_AXIS_TVALID(tv),
        .S_AXIS_TDATA(td),
        .S_AXIS_TREADY(tr),
        .done(sink_done),
        .error(sink_error)
    );

    initial begin
        rst_n = 0;
        start = 0;
        #20 rst_n = 1;

        @(posedge clk);
        start <= 1;
        @(posedge clk);
        start <= 0;

        wait (sink_done);

        if (sink_error)
            $display("AXI DMA READ TEST FAILED");
        else
            $display("AXI DMA READ TEST PASSED");

        #20 $finish;
    end

endmodule
