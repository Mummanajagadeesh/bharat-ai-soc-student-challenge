`timescale 1ns/1ps

module axi_weight_bias_loader #(
    parameter W_COUNT = 756,
    parameter B_COUNT = 28
)(
    input  wire clk,
    input  wire rst_n,

    input  wire start,
    output reg  done,

    // =============================
    // AXI4-Lite Read Address Channel
    // =============================
    output reg         M_AXI_ARVALID,
    input  wire        M_AXI_ARREADY,
    output reg [31:0]  M_AXI_ARADDR,

    // =============================
    // AXI4-Lite Read Data Channel
    // =============================
    input  wire        M_AXI_RVALID,
    output reg         M_AXI_RREADY,
    input  wire [31:0] M_AXI_RDATA,
    input  wire [1:0]  M_AXI_RRESP
);

    // internal storage
    reg signed [7:0] weight_mem [0:W_COUNT-1];
    reg signed [7:0] bias_mem   [0:B_COUNT-1];

    localparam ST_IDLE   = 2'd0;
    localparam ST_WEIGHT = 2'd1;
    localparam ST_BIAS   = 2'd2;
    localparam ST_DONE   = 2'd3;

    reg [1:0]  state;
    reg [31:0] idx;
    reg        ar_inflight;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state          <= ST_IDLE;
            idx            <= 0;
            done           <= 0;
            M_AXI_ARVALID  <= 0;
            M_AXI_ARADDR   <= 0;
            M_AXI_RREADY   <= 0;
            ar_inflight    <= 0;
        end else begin
            done <= 0;

            // default
            M_AXI_ARVALID <= M_AXI_ARVALID && !M_AXI_ARREADY;
            M_AXI_RREADY  <= 0;

            case (state)

                ST_IDLE: begin
                    idx <= 0;
                    ar_inflight <= 0;
                    if (start)
                        state <= ST_WEIGHT;
                end

                ST_WEIGHT: begin
                    if (!ar_inflight && idx < W_COUNT) begin
                        M_AXI_ARVALID <= 1;
                        M_AXI_ARADDR  <= idx;
                        ar_inflight   <= 1;
                    end

                    if (M_AXI_RVALID && ar_inflight) begin
                        M_AXI_RREADY <= 1;
                        weight_mem[idx] <= M_AXI_RDATA[7:0];
                        idx <= idx + 1;
                        ar_inflight <= 0;
                    end

                    if (idx == W_COUNT && !ar_inflight) begin
                        idx <= 0;
                        state <= ST_BIAS;
                    end
                end

                ST_BIAS: begin
                    if (!ar_inflight && idx < B_COUNT) begin
                        M_AXI_ARVALID <= 1;
                        M_AXI_ARADDR  <= W_COUNT + idx;
                        ar_inflight   <= 1;
                    end

                    if (M_AXI_RVALID && ar_inflight) begin
                        M_AXI_RREADY <= 1;
                        bias_mem[idx] <= M_AXI_RDATA[7:0];
                        idx <= idx + 1;
                        ar_inflight <= 0;
                    end

                    if (idx == B_COUNT && !ar_inflight)
                        state <= ST_DONE;
                end

                ST_DONE: begin
                    done <= 1;
                    state <= ST_IDLE;
                end

            endcase
        end
    end

endmodule
