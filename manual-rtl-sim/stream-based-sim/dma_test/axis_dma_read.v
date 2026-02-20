`timescale 1ns/1ps

module axis_dma_read #(
    parameter MAX_OUTSTANDING = 4,
    parameter FIFO_DEPTH = 8
)(
    input  wire clk,
    input  wire rst_n,

    input  wire        start,
    input  wire [31:0] base_addr,
    input  wire [31:0] length,
    output reg         done,

    output reg         mem_rd_valid,
    output reg  [31:0] mem_rd_addr,
    input  wire        mem_rd_resp_valid,
    input  wire [7:0]  mem_rd_resp_data,

    output wire        M_AXIS_TVALID,
    output wire [7:0]  M_AXIS_TDATA,
    input  wire        M_AXIS_TREADY
);

    reg active;
    reg [31:0] req_count;
    reg [31:0] resp_count;

    wire fifo_empty;
    wire fifo_full;

    byte_fifo #(
        .DEPTH(FIFO_DEPTH)
    ) fifo (
        .clk     (clk),
        .rst_n   (rst_n),

        .s_valid (mem_rd_resp_valid),
        .s_data  (mem_rd_resp_data),
        .s_ready (),

        .m_valid (M_AXIS_TVALID),
        .m_data  (M_AXIS_TDATA),
        .m_ready (M_AXIS_TREADY),

        .empty   (fifo_empty)
    );

    wire [31:0] outstanding = req_count - resp_count;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            active        <= 0;
            req_count     <= 0;
            resp_count    <= 0;
            mem_rd_valid  <= 0;
            mem_rd_addr   <= 0;
            done          <= 0;
        end else begin
            mem_rd_valid <= 0;
            done <= 0;

            if (start && !active) begin
                active     <= 1;
                req_count  <= 0;
                resp_count <= 0;
            end

            if (active &&
                req_count < length &&
                outstanding < MAX_OUTSTANDING) begin
                mem_rd_valid <= 1;
                mem_rd_addr  <= base_addr + req_count;
                req_count    <= req_count + 1;
            end

            if (mem_rd_resp_valid)
                resp_count <= resp_count + 1;

            if (active &&
                req_count == length &&
                resp_count == length &&
                fifo_empty) begin
                done   <= 1;
                active <= 0;
            end
        end
    end

endmodule
