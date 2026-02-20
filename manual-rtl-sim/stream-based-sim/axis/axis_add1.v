`timescale 1ns/1ps

module axis_add1 #(
    parameter DATA_WIDTH = 8
)(
    input  wire clk,
    input  wire rst_n,

    // slave
    input  wire                 S_AXIS_TVALID,
    input  wire [DATA_WIDTH-1:0] S_AXIS_TDATA,
    output wire                 S_AXIS_TREADY,

    // master
    output reg                  M_AXIS_TVALID,
    output reg  [DATA_WIDTH-1:0] M_AXIS_TDATA,
    input  wire                 M_AXIS_TREADY
);

    assign S_AXIS_TREADY = !M_AXIS_TVALID || M_AXIS_TREADY;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            M_AXIS_TVALID <= 0;
            M_AXIS_TDATA  <= 0;
        end else begin
            if (S_AXIS_TVALID && S_AXIS_TREADY) begin
                M_AXIS_TVALID <= 1;
                M_AXIS_TDATA  <= S_AXIS_TDATA + 1;
            end else if (M_AXIS_TVALID && M_AXIS_TREADY) begin
                M_AXIS_TVALID <= 0;
            end
        end
    end

endmodule
