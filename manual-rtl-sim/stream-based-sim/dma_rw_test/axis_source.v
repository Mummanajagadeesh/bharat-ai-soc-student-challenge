`timescale 1ns/1ps

module axis_source #(
    parameter COUNT = 32
)(
    input  wire clk,
    input  wire rst_n,
    input  wire start,

    output reg         M_AXIS_TVALID,
    output reg  [7:0]  M_AXIS_TDATA,
    input  wire        M_AXIS_TREADY,

    output reg done
);

    reg [7:0] value;
    reg [31:0] sent;
    reg active;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            M_AXIS_TVALID <= 0;
            M_AXIS_TDATA  <= 0;
            value         <= 0;
            sent          <= 0;
            active        <= 0;
            done          <= 0;
        end else begin
            done <= 0;

            if (start && !active) begin
                active <= 1;
                value  <= 0;
                sent   <= 0;
            end

            if (active && !M_AXIS_TVALID && sent < COUNT) begin
                M_AXIS_TDATA  <= value;
                M_AXIS_TVALID <= 1;
            end

            if (M_AXIS_TVALID && M_AXIS_TREADY) begin
                M_AXIS_TVALID <= 0;
                value <= value + 1;
                sent  <= sent + 1;

                if (sent + 1 == COUNT) begin
                    active <= 0;
                    done   <= 1;
                end
            end
        end
    end

endmodule
