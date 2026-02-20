`timescale 1ns/1ps

module conv_3x3
#(
    parameter DATA_W    = 8,
    parameter ACC_W     = 24,
    parameter MAX_WIDTH = 1024
)
(
    input                   clk,
    input                   rst,
    input                   in_valid,
    input  [DATA_W-1:0]     in_pixel,

    input  [DATA_W-1:0]     k00, k01, k02,
    input  [DATA_W-1:0]     k10, k11, k12,
    input  [DATA_W-1:0]     k20, k21, k22,

    input  [15:0]           img_width,

    output reg              out_valid,
    output reg [ACC_W-1:0]  out_pixel
);

    /* ================= LINE BUFFERS ================= */
    reg [DATA_W-1:0] line0 [0:MAX_WIDTH-1];
    reg [DATA_W-1:0] line1 [0:MAX_WIDTH-1];
    reg [DATA_W-1:0] line2 [0:MAX_WIDTH-1];

    reg [15:0] row, col;
    integer i;

    always @(posedge clk) begin
        if (rst) begin
            row <= 0;
            col <= 0;
            for (i = 0; i < MAX_WIDTH; i = i + 1) begin
                line0[i] <= 0;
                line1[i] <= 0;
                line2[i] <= 0;
            end
        end else if (in_valid) begin
            line0[col] <= line1[col];
            line1[col] <= line2[col];
            line2[col] <= in_pixel;

            if (col == img_width - 1) begin
                col <= 0;
                row <= row + 1;
            end else begin
                col <= col + 1;
            end
        end
    end

    /* ================= WINDOW TRIG/ COLUMN CAPTURE ================= */
    wire win_fire_c;
    reg  win_fire_d;

    assign win_fire_c = in_valid && (row >= 2) && (col >= 2);

    reg [15:0] col_w;

    always @(posedge clk) begin
        if (rst) begin
            win_fire_d <= 0;
            col_w <= 0;
        end else begin
            // capture column when window first becomes true
            if (win_fire_c)
                col_w <= col;
            // delay the window signal one cycle so the captured col_w is available
            win_fire_d <= win_fire_c;
        end
    end

    /* ================= WINDOW REGISTERS ================= */
    reg [DATA_W-1:0]
        a00,a01,a02,
        a10,a11,a12,
        a20,a21,a22;

    always @(posedge clk) begin
        if (rst) begin
            a00<=0; a01<=0; a02<=0;
            a10<=0; a11<=0; a12<=0;
            a20<=0; a21<=0; a22<=0;
        end else if (win_fire_d) begin
            a00 <= line0[col_w-2]; a01 <= line0[col_w-1]; a02 <= line0[col_w];
            a10 <= line1[col_w-2]; a11 <= line1[col_w-1]; a12 <= line1[col_w];
            a20 <= line2[col_w-2]; a21 <= line2[col_w-1]; a22 <= line2[col_w];
        end
    end

    /* ================= PEs (1-cycle latency) ================= */
    wire [ACC_W-1:0]
        m00,m01,m02,
        m10,m11,m12,
        m20,m21,m22;

    pe PE00 (.clk(clk),.rst(rst),.a(a00),.w(k00),.y(m00));
    pe PE01 (.clk(clk),.rst(rst),.a(a01),.w(k01),.y(m01));
    pe PE02 (.clk(clk),.rst(rst),.a(a02),.w(k02),.y(m02));

    pe PE10 (.clk(clk),.rst(rst),.a(a10),.w(k10),.y(m10));
    pe PE11 (.clk(clk),.rst(rst),.a(a11),.w(k11),.y(m11));
    pe PE12 (.clk(clk),.rst(rst),.a(a12),.w(k12),.y(m12));

    pe PE20 (.clk(clk),.rst(rst),.a(a20),.w(k20),.y(m20));
    pe PE21 (.clk(clk),.rst(rst),.a(a21),.w(k21),.y(m21));
    pe PE22 (.clk(clk),.rst(rst),.a(a22),.w(k22),.y(m22));

    /* ================= ADD TREE + VALID (aligned with win_fire_d) ================= */
    reg v0, v1, v2;
    reg [ACC_W-1:0] s0, s1, s2;

    always @(posedge clk) begin
        if (rst) begin
            v0 <= 0; v1 <= 0; v2 <= 0;
            out_valid <= 0;
            out_pixel <= 0;
            s0 <= 0; s1 <= 0; s2 <= 0;
        end else begin
            // v0 starts from win_fire_d because window registers are loaded on win_fire_d
            v0 <= win_fire_d;
            v1 <= v0;
            v2 <= v1;

            if (v1) begin
                s0 <= m00 + m01 + m02;
                s1 <= m10 + m11 + m12;
                s2 <= m20 + m21 + m22;
            end

            out_valid <= v2;
            if (v2)
                out_pixel <= s0 + s1 + s2;
        end
    end

endmodule
