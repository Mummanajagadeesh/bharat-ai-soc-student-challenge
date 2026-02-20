`timescale 1ns/1ps

module axis_sink_memcheck #(
    parameter COUNT = 32
)(
    input  wire clk,
    input  wire rst_n,
    input  wire start,

    output reg         rd_valid,
    output reg  [31:0] rd_addr,
    input  wire [7:0]  rd_data,

    output reg done,
    output reg error
);

    reg active;

    // address generation
    reg [31:0] issue_idx;

    // two-stage pipeline for synchronous read
    reg        vld_d1, vld_d2;
    reg [31:0] addr_d1, addr_d2;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            active   <= 0;
            issue_idx <= 0;
            rd_valid <= 0;
            rd_addr  <= 0;
            done     <= 0;
            error    <= 0;

            vld_d1  <= 0;
            vld_d2  <= 0;
            addr_d1 <= 0;
            addr_d2 <= 0;
        end else begin
            done <= 0;

            // start checker
            if (start && !active) begin
                active    <= 1;
                issue_idx <= 0;
                rd_valid  <= 1;
                vld_d1    <= 0;
                vld_d2    <= 0;
            end

            if (active) begin
                // issue read
                rd_addr <= issue_idx;

                // pipeline address
                vld_d1  <= 1;
                addr_d1 <= issue_idx;

                vld_d2  <= vld_d1;
                addr_d2 <= addr_d1;

                // check data aligned to addr_d2
                if (vld_d2) begin
                    if (rd_data !== addr_d2[7:0]) begin
                        $display("[MEMCHK] ERROR addr=%0d got=%0d expected=%0d",
                                 addr_d2, rd_data, addr_d2[7:0]);
                        error <= 1;
                    end else begin
                        $display("[MEMCHK] OK addr=%0d data=%0d",
                                 addr_d2, rd_data);
                    end
                end

                issue_idx <= issue_idx + 1;

                // stop after last address has been issued AND checked
                if (issue_idx + 1 == COUNT) begin
                    rd_valid <= 0;
                    active   <= 0;
                    done     <= 1;
                end
            end
        end
    end

endmodule
