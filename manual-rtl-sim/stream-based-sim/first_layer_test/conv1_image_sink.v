`timescale 1ns/1ps

module conv1_image_sink (
    input  wire        clk,
    input  wire        rst_n,

    input  wire        s_tvalid,
    input  wire [23:0] s_tdata,
    input  wire        s_tlast,
    output wire        s_tready
);

    assign s_tready = 1'b1;

    integer pix;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            pix <= 0;
        end else if (s_tvalid && s_tready) begin
            $display(
                "PIX %0d | R=%0d G=%0d B=%0d TLAST=%0d",
                pix,
                s_tdata[23:16],
                s_tdata[15:8],
                s_tdata[7:0],
                s_tlast
            );
            pix <= pix + 1;
            if (s_tlast)
                pix <= 0;
        end
    end

endmodule
