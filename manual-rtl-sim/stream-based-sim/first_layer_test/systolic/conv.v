`timescale 1ns/1ps

module conv_3x3_systolic #(
    parameter DATA_W = 8,
    parameter ACC_W  = 24
)(
    input clk,
    input rst,
    input in_valid,

    input [DATA_W-1:0] px0,
    input [DATA_W-1:0] px1,
    input [DATA_W-1:0] px2,

    input [DATA_W-1:0] k00,k01,k02,
    input [DATA_W-1:0] k10,k11,k12,
    input [DATA_W-1:0] k20,k21,k22,

    output reg out_valid,
    output reg [ACC_W-1:0] out_pixel
);

    /* ================= INPUT PRE-STAGE ================= */
    reg [DATA_W-1:0] px0_s1, px1_s1, px2_s1;
    always @(posedge clk) begin
        if (rst) begin
            px0_s1 <= 0;
            px1_s1 <= 0;
            px2_s1 <= 0;
        end else begin
            px0_s1 <= px0;
            px1_s1 <= px1;
            px2_s1 <= px2;
        end
    end

    /* ================= ROW DELAYS ================= */
    reg [DATA_W-1:0] px1_d;
    reg [DATA_W-1:0] px2_d1, px2_d2;

    always @(posedge clk) begin
        if (rst) begin
            px1_d  <= 0;
            px2_d1 <= 0;
            px2_d2 <= 0;
        end else begin
            px1_d  <= px1_s1;
            px2_d1 <= px2_s1;
            px2_d2 <= px2_d1;
        end
    end

    /* ================= COLUMN SHIFTS ================= */
    reg [DATA_W-1:0] r0_1, r0_2;
    reg [DATA_W-1:0] r1_1, r1_2;
    reg [DATA_W-1:0] r2_1, r2_2;

    always @(posedge clk) begin
        if (rst) begin
            r0_1<=0; r0_2<=0;
            r1_1<=0; r1_2<=0;
            r2_1<=0; r2_2<=0;
        end else begin
            r0_2 <= r0_1; r0_1 <= px0_s1;
            r1_2 <= r1_1; r1_1 <= px1_d;
            r2_2 <= r2_1; r2_1 <= px2_d2;
        end
    end

    /* ================= ROW VALID ================= */
    reg [2:0] row_valid;
    always @(posedge clk) begin
        if (rst)
            row_valid <= 3'b000;
        else
            row_valid <= {row_valid[1:0], in_valid};
    end

    /* ================= PE ARRAY ================= */
    wire [ACC_W-1:0] c0_r0, c0_r1, c0_r2;
    wire [ACC_W-1:0] c1_r0, c1_r1, c1_r2;
    wire [ACC_W-1:0] c2_r0, c2_r1, c2_r2;

    /* ======= 🔥 FIX IS HERE: reset psums per window ======= */

    // Column 0 (WINDOW RESET APPLIED)
    pe_systolic PE00(
        clk, rst,
        row_valid[0],
        px0_s1,
        {ACC_W{1'b0}},
        k00,
        c0_r0
    );

    pe_systolic PE10(
        clk, rst,
        row_valid[1],
        px1_d,
        row_valid[1] ? c0_r0 : {ACC_W{1'b0}},
        k10,
        c0_r1
    );

    pe_systolic PE20(
        clk, rst,
        row_valid[2],
        px2_d2,
        row_valid[2] ? c0_r1 : {ACC_W{1'b0}},
        k20,
        c0_r2
    );

    // Column 1
    pe_systolic PE01(clk, rst, row_valid[0], r0_1, {ACC_W{1'b0}}, k01, c1_r0);
    pe_systolic PE11(clk, rst, row_valid[1], r1_1, c1_r0,         k11, c1_r1);
    pe_systolic PE21(clk, rst, row_valid[2], r2_1, c1_r1,         k21, c1_r2);

    // Column 2
    pe_systolic PE02(clk, rst, row_valid[0], r0_2, {ACC_W{1'b0}}, k02, c2_r0);
    pe_systolic PE12(clk, rst, row_valid[1], r1_2, c2_r0,         k12, c2_r1);
    pe_systolic PE22(clk, rst, row_valid[2], r2_2, c2_r1,         k22, c2_r2);

    /* ================= FINAL REDUCTION ================= */
    reg [ACC_W-1:0] sum_all;
    always @(posedge clk) begin
        if (rst)
            sum_all <= 0;
        else
            sum_all <= c0_r2 + c1_r2 + c2_r2;
    end

    /* ================= OUTPUT VALID PIPELINE ================= */
    reg [5:0] v;
    always @(posedge clk) begin
        if (rst) begin
            v <= 0;
            out_valid <= 0;
            out_pixel <= 0;
        end else begin
            v <= {v[4:0], in_valid};
            out_valid <= v[5];
            if (v[5])
                out_pixel <= sum_all;
        end
    end

endmodule
