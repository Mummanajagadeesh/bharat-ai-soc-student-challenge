`timescale 1ns/1ps

module axis_source #(
    parameter DATA_WIDTH = 8,
    parameter COUNT      = 32
)(
    input  wire clk,
    input  wire rst_n,

    input  wire start,
    output reg  done,

    output reg                  M_AXIS_TVALID,
    output reg [DATA_WIDTH-1:0] M_AXIS_TDATA,
    input  wire                 M_AXIS_TREADY
);

    reg [DATA_WIDTH-1:0] value;
    reg [$clog2(COUNT+1)-1:0] sent;
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
                sent   <= 0;
                value  <= 0;
                M_AXIS_TVALID <= 0;
            end

            // Load new data only when not already holding valid data
            if (active && !M_AXIS_TVALID && sent < COUNT) begin
                M_AXIS_TDATA  <= value;
                M_AXIS_TVALID <= 1;
            end

            // Handshake
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
