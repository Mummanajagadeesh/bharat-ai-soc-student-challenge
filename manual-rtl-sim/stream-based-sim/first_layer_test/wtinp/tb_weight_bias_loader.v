`timescale 1ns/1ps

module tb_weight_bias_loader;

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

    wire        mem_req_valid;
    wire [31:0] mem_req_addr;
    wire        mem_resp_valid;
    wire [7:0]  mem_resp_data;

    reg signed [7:0] exp_weight [0:W_COUNT-1];
    reg signed [7:0] exp_bias   [0:B_COUNT-1];

    simple_mem_weights mem (
        .clk(clk),
        .req_valid(mem_req_valid),
        .req_addr(mem_req_addr),
        .resp_valid(mem_resp_valid),
        .resp_data(mem_resp_data)
    );

    weight_bias_loader #(
        .W_COUNT(W_COUNT),
        .B_COUNT(B_COUNT)
    ) dut (
        .clk(clk),
        .rst_n(rst_n),
        .start(start),
        .done(done),
        .mem_req_valid(mem_req_valid),
        .mem_req_write(),
        .mem_req_addr(mem_req_addr),
        .mem_resp_valid(mem_resp_valid),
        .mem_resp_data(mem_resp_data)
    );

    integer i;
    integer errors;

    initial begin
        rst_n = 0;
        start = 0;
        errors = 0;

        #20 rst_n = 1;

        // expected
        $readmemh("model_weights_fixed8/01_conv2d_kernel.mem", exp_weight);
        $readmemh("model_weights_fixed8/01_conv2d_bias.mem",   exp_bias);

        // backing memory
        $readmemh("model_weights_fixed8/01_conv2d_kernel.mem", mem.mem, 0, W_COUNT-1);
        $readmemh("model_weights_fixed8/01_conv2d_bias.mem",   mem.mem, W_COUNT, W_COUNT+B_COUNT-1);

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
            $display("\n[PASS] Weight & bias loader verified");
        else
            $display("\n[FAIL] Errors = %0d", errors);

        $finish;
    end

endmodule
