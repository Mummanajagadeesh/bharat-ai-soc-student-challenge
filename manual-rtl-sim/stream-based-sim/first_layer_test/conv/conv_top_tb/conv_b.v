`timescale 1ns / 1ps

module conv2d_q17_top #(
    parameter WIDTH    = 32,
    parameter HEIGHT   = 32,
    parameter CHANNELS = 3,
    parameter FILTERS  = 28,
    parameter K        = 3,
    parameter PAD      = 1
)(
    input  wire clk,
    input  wire rst,
    input  wire start,
    output reg  done
);

    //--------------------------------------------------
    // Memories
    //--------------------------------------------------
    reg [7:0] image_r [0:HEIGHT-1][0:WIDTH-1];
    reg [7:0] image_g [0:HEIGHT-1][0:WIDTH-1];
    reg [7:0] image_b [0:HEIGHT-1][0:WIDTH-1];

    reg signed [7:0] kernel [0:26][0:FILTERS-1];
    reg signed [7:0] bias   [0:FILTERS-1];

    reg signed [20:0] feature_map [0:FILTERS-1][0:HEIGHT-1][0:WIDTH-1];

    //--------------------------------------------------
    // Counters
    //--------------------------------------------------
    reg [5:0] i,j;
    reg [4:0] f;
    reg [1:0] m,n;
    reg [1:0] c;

    //--------------------------------------------------
    // Internal
    //--------------------------------------------------
    reg signed [28:0] accum;
    reg signed [28:0] numerator;
    reg signed [23:0] kernel_mul;
    reg signed [23:0] bias_times_255;
    reg signed [20:0] out_int;
    reg signed [20:0] out_int_relu;

    reg [7:0] pix8;
    reg signed [15:0] kern16;
    reg signed [15:0] bias16;

    integer in_x,in_y,row_idx;

    //--------------------------------------------------
    // FSM
    //--------------------------------------------------
    localparam IDLE=0, LOAD_BIAS=1, MAC=2, WRITE=3, NEXT=4, FIN=5;
    reg [2:0] state;

    //--------------------------------------------------
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            state <= IDLE;
            done  <= 0;
        end else begin

            case(state)

            IDLE: begin
                done <= 0;
                if(start) begin
                    f<=0; i<=0; j<=0; m<=0; n<=0; c<=0;
                    state <= LOAD_BIAS;
                end
            end

            LOAD_BIAS: begin
                bias16 = bias[f];
                bias_times_255 = bias16 * 32'sd255;
                accum <= bias_times_255;
                m<=0; n<=0; c<=0;
                state <= MAC;
            end

            MAC: begin

                in_y = i + m - PAD;
                in_x = j + n - PAD;

                if(!(in_y<0 || in_y>=HEIGHT ||
                     in_x<0 || in_x>=WIDTH)) begin

                    case(c)
                        0: pix8 = image_r[in_y][in_x];
                        1: pix8 = image_g[in_y][in_x];
                        2: pix8 = image_b[in_y][in_x];
                    endcase

                    row_idx = m*K*CHANNELS + n*CHANNELS + c;
                    kern16  = kernel[row_idx][f];

                    kernel_mul = kern16 * $signed({8'd0,pix8});
                    accum <= accum + kernel_mul;
                end

                // Advance kernel window
                if(c==2) begin
                    c<=0;
                    if(n==2) begin
                        n<=0;
                        if(m==2) begin
                            state<=WRITE;
                        end else m<=m+1;
                    end else n<=n+1;
                end else c<=c+1;
            end

            WRITE: begin

                numerator = accum;

                if(numerator>=0)
                    out_int = (numerator + 32'sd127)/32'sd255;
                else
                    out_int = -((-numerator + 32'sd127)/32'sd255);

                if(out_int<0)
                    out_int_relu = 0;
                else
                    out_int_relu = out_int;

                feature_map[f][i][j] <= out_int_relu;

                state <= NEXT;
            end

            NEXT: begin

                if(j==WIDTH-1) begin
                    j<=0;
                    if(i==HEIGHT-1) begin
                        i<=0;
                        if(f==FILTERS-1)
                            state<=FIN;
                        else begin
                            f<=f+1;
                            state<=LOAD_BIAS;
                        end
                    end else begin
                        i<=i+1;
                        state<=LOAD_BIAS;
                    end
                end else begin
                    j<=j+1;
                    state<=LOAD_BIAS;
                end
            end

            FIN: begin
                done<=1;
                state<=IDLE;
            end

            endcase
        end
    end

endmodule
