`timescale 1ns/1ps

module tb_axi_weight_bias_loader;

    reg clk;
    reg rst_n;

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    localparam W_COUNT = 756;
    localparam B_COUNT = 28;
    localparam CHECK_N = 16;

    reg start;
    wire done;

    wire        arvalid;
    wire        arready;
    wire [31:0] araddr;
    wire        rvalid;
    wire        rready;
    wire [31:0] rdata;
    wire [1:0]  rresp;

    reg signed [7:0] exp_weight [0:W_COUNT-1];
    reg signed [7:0] exp_bias   [0:B_COUNT-1];

    axi_simple_mem mem (
        .clk(clk),
        .rst_n(rst_n),
        .S_AXI_ARVALID(arvalid),
        .S_AXI_ARREADY(arready),
        .S_AXI_ARADDR (araddr),
        .S_AXI_RVALID (rvalid),
        .S_AXI_RREADY (rready),
        .S_AXI_RDATA  (rdata),
        .S_AXI_RRESP  (rresp)
    );

    axi_weight_bias_loader #(
        .W_COUNT(W_COUNT),
        .B_COUNT(B_COUNT)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .done(done),

        .M_AXI_ARVALID(arvalid),
        .M_AXI_ARREADY(arready),
        .M_AXI_ARADDR (araddr),

        .M_AXI_RVALID (rvalid),
        .M_AXI_RREADY (rready),
        .M_AXI_RDATA  (rdata),
        .M_AXI_RRESP  (rresp)
    );

    integer i;
    integer errors;

    initial begin
        rst_n = 0;
        start = 0;
        errors = 0;

        #20 rst_n = 1;

        $readmemh("model_weights_fixed8/01_conv2d_kernel.mem", exp_weight);
        $readmemh("model_weights_fixed8/01_conv2d_bias.mem",   exp_bias);

        $readmemh("model_weights_fixed8/01_conv2d_kernel.mem",
                  mem.mem, 0, W_COUNT-1);
        $readmemh("model_weights_fixed8/01_conv2d_bias.mem",
                  mem.mem, W_COUNT, W_COUNT+B_COUNT-1);

        @(posedge clk);
        start <= 1;
        @(posedge clk);
        start <= 0;

        wait(done);

        $display("\n[TB] CHECK WEIGHTS");
        for (i = 0; i < CHECK_N; i = i + 1) begin
            $display("W[%0d] = %0d (exp %0d)",
                     i, dut.weight_mem[i], exp_weight[i]);
            if (dut.weight_mem[i] !== exp_weight[i])
                errors = errors + 1;
        end

        $display("\n[TB] CHECK BIASES");
        for (i = 0; i < B_COUNT; i = i + 1) begin
            $display("B[%0d] = %0d (exp %0d)",
                     i, dut.bias_mem[i], exp_bias[i]);
            if (dut.bias_mem[i] !== exp_bias[i])
                errors = errors + 1;
        end

        if (errors == 0)
            $display("\n[PASS] AXI-MM weight & bias loader verified");
        else
            $display("\n[FAIL] Errors = %0d", errors);

        $finish;
    end

endmodule
