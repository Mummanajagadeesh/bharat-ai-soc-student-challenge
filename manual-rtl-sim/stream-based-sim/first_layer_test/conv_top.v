module conv_top
#(
    parameter IMG_W  = 5,
    parameter IMG_H  = 5,
    parameter K      = 3,
    parameter DATA_W = 8
)
(
    input                     clk,
    input                     valid_pixel,
    input  signed [DATA_W-1:0] pixel_in,
    input  signed [DATA_W*K*K-1:0] kernel_flat,
    output signed [2*DATA_W+8:0] conv_out,
    output                    valid_out
);

    localparam VEC_LEN = K*K;

    reg signed [DATA_W-1:0] linebuf [0:K-1][0:IMG_W-1];
    reg [7:0] row, col;

    reg signed [DATA_W*K*K-1:0] window_flat;
    reg valid_window;

    integer i, j;

    initial begin
        row = 0;
        col = 0;
        valid_window = 0;
    end

    always @(posedge clk) begin
        if (valid_pixel) begin
            // shift rows
            for (i = K-1; i > 0; i = i - 1)
                linebuf[i][col] <= linebuf[i-1][col];

            linebuf[0][col] <= pixel_in;

            // window valid BEFORE col increments
            if (row >= K-1 && col >= K-1)
                valid_window <= 1'b1;
            else
                valid_window <= 1'b0;

            // update column/row
            if (col == IMG_W-1) begin
                col <= 0;
                row <= row + 1;
            end else begin
                col <= col + 1;
            end
        end else begin
            valid_window <= 0;
        end
    end

    always @(*) begin
        window_flat = 0;
        if (row >= K-1 && col >= K-1) begin
            for (i = 0; i < K; i = i + 1)
                for (j = 0; j < K; j = j + 1)
                    window_flat[(i*K+j)*DATA_W +: DATA_W] =
                        linebuf[i][col-j];
        end
    end

    conv_core #(
        .DATA_W(DATA_W),
        .VEC_LEN(VEC_LEN)
    ) u_core (
        .clk(clk),
        .valid_in(valid_window),
        .img_vec(window_flat),
        .ker_vec(kernel_flat),
        .result(conv_out),
        .valid_out(valid_out)
    );

endmodule
