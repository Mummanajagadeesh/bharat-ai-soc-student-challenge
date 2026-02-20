`timescale 1ns/1ps

module tb_axis_stream;

    reg clk = 0;
    always #5 clk = ~clk;

    reg rst_n;
    reg start;

    wire src_done;
    wire sink_done;
    wire sink_error;

    wire tv_s, tr_s;
    wire [7:0] td_s;

    wire tv_m, tr_m;
    wire [7:0] td_m;

    axis_source #(.COUNT(32)) src (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .done(src_done),
        .M_AXIS_TVALID(tv_s),
        .M_AXIS_TDATA(td_s),
        .M_AXIS_TREADY(tr_s)
    );

    axis_add1 add1 (
        .clk(clk),
        .rst_n(rst_n),
        .S_AXIS_TVALID(tv_s),
        .S_AXIS_TDATA(td_s),
        .S_AXIS_TREADY(tr_s),
        .M_AXIS_TVALID(tv_m),
        .M_AXIS_TDATA(td_m),
        .M_AXIS_TREADY(tr_m)
    );

    axis_sink #(.COUNT(32)) sink (
        .clk(clk),
        .rst_n(rst_n),
        .S_AXIS_TVALID(tv_m),
        .S_AXIS_TDATA(td_m),
        .S_AXIS_TREADY(tr_m),
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
            $display("\nAXI-STREAM TEST FAILED");
        else
            $display("\nAXI-STREAM TEST PASSED");

        #20 $finish;
    end

endmodule
