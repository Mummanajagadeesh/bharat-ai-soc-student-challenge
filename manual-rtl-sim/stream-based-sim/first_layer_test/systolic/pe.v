module pe_systolic #(
    parameter DATA_W = 8,
    parameter ACC_W  = 24
)(
    input                   clk,
    input                   rst,
    input                   en,
    input  [DATA_W-1:0]     a_in,
    input  [ACC_W-1:0]      psum_in,
    input  [DATA_W-1:0]     w,
    output reg [ACC_W-1:0]  psum_out
);

    always @(posedge clk) begin
        if (rst)
            psum_out <= {ACC_W{1'b0}};
        else if (en)
            psum_out <= psum_in + a_in * w;
        else
            psum_out <= psum_in;
    end

endmodule
