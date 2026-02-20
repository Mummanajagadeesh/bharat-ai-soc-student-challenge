`timescale 1ns / 1ps

module conv2d_q17_core #(
    parameter WIDTH    = 32,
    parameter HEIGHT   = 32,
    parameter FILTERS  = 28,
    parameter K        = 3,
    parameter PAD      = 1
)(
    input  wire clk,
    input  wire rst,
    input  wire start,
    output reg  done,

    // Loop counters exposed to wrapper
    output reg  [5:0] i,
    output reg  [5:0] j,
    output reg  [4:0] f,
    output reg  [1:0] m,
    output reg  [1:0] n,
    output reg  [1:0] c,

    input  wire [7:0] pix_in,
    input  wire signed [7:0] kern_in,
    input  wire signed [7:0] bias_in,

    output reg signed [20:0] out_pixel,
    output reg write_en
);

    //--------------------------------------------------
    // Internal
    //--------------------------------------------------
    reg signed [28:0] accum;
    reg signed [28:0] numerator;
    reg signed [23:0] kernel_mul;
    reg signed [23:0] bias_times_255;
    reg signed [20:0] out_int;
    reg signed [20:0] out_int_relu;

    //--------------------------------------------------
    // FSM
    //--------------------------------------------------
    localparam IDLE=0, LOAD_BIAS=1, MAC=2, WRITE=3, NEXT=4, FIN=5;
    reg [2:0] state;

    always @(posedge clk or posedge rst) begin
        if(rst) begin
            state <= IDLE;
            done  <= 0;
            write_en <= 0;
        end else begin

            write_en <= 0;

            case(state)

            IDLE: begin
                done <= 0;
                if(start) begin
                    f<=0; i<=0; j<=0; m<=0; n<=0; c<=0;
                    state <= LOAD_BIAS;
                end
            end

            LOAD_BIAS: begin
                bias_times_255 = bias_in * 32'sd255;
                accum <= bias_times_255;
                m<=0; n<=0; c<=0;
                state <= MAC;
            end

            MAC: begin
                kernel_mul = kern_in * $signed({8'd0,pix_in});
                accum <= accum + kernel_mul;

                if(c==2) begin
                    c<=0;
                    if(n==2) begin
                        n<=0;
                        if(m==2)
                            state<=WRITE;
                        else m<=m+1;
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

                out_pixel <= out_int_relu;
                write_en  <= 1;
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
