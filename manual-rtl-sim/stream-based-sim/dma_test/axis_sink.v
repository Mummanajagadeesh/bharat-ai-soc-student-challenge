`timescale 1ns/1ps

module axis_sink #(
    parameter COUNT = 32
)(
    input  wire clk,
    input  wire rst_n,

    input  wire        S_AXIS_TVALID,
    input  wire [7:0]  S_AXIS_TDATA,
    output reg         S_AXIS_TREADY,

    output reg done,
    output reg error
);

    reg [7:0] expected;
    reg [31:0] received;
    reg [3:0] stall_ctr;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            expected  <= 0;
            received  <= 0;
            done      <= 0;
            error     <= 0;
            stall_ctr <= 0;
            S_AXIS_TREADY <= 1;
        end else begin
            done <= 0;

            if (stall_ctr == 5) begin
                S_AXIS_TREADY <= 0;
                stall_ctr <= stall_ctr + 1;
            end else if (stall_ctr == 7) begin
                S_AXIS_TREADY <= 1;
                stall_ctr <= 0;
            end else begin
                stall_ctr <= stall_ctr + 1;
            end

            if (S_AXIS_TVALID && S_AXIS_TREADY) begin
                $display("[SINK] RX %0d expected %0d",
                         S_AXIS_TDATA, expected);

                if (S_AXIS_TDATA !== expected)
                    error <= 1;

                expected <= expected + 1;
                received <= received + 1;

                if (received + 1 == COUNT)
                    done <= 1;
            end
        end
    end

endmodule
