module conv_core
#(
    parameter DATA_W  = 8,
    parameter VEC_LEN = 9
)
(
    input                     clk,
    input                     valid_in,
    input  signed [DATA_W*VEC_LEN-1:0] img_vec,
    input  signed [DATA_W*VEC_LEN-1:0] ker_vec,
    output reg signed [2*DATA_W+8:0]   result,
    output reg                valid_out
);

    integer i;
    reg signed [2*DATA_W+8:0] acc;

    always @(posedge clk) begin
        if (valid_in) begin
            acc = 0;
            for (i = 0; i < VEC_LEN; i = i + 1)
                acc = acc +
                      img_vec[i*DATA_W +: DATA_W] *
                      ker_vec[i*DATA_W +: DATA_W];
            result    <= acc;
            valid_out <= 1'b1;
        end else begin
            valid_out <= 1'b0;
        end
    end

endmodule
