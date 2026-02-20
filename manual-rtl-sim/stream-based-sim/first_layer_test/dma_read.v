`timescale 1ns/1ps

module dma_read #(
    parameter MAX_OUTSTANDING = 8
)(
    input  wire        clk,
    input  wire        rst_n,

    input  wire        start,
    input  wire [31:0] base_addr,
    input  wire [31:0] length,
    output reg         done,

    // memory interface
    output reg         mem_req_valid,
    output wire        mem_req_write,
    output reg  [31:0] mem_req_addr,
    input  wire        mem_resp_valid,
    input  wire [7:0]  mem_resp_rdata,

    // AXI-Stream output (bytes)
    output wire        m_tvalid,
    output wire [7:0]  m_tdata,
    input  wire        m_tready
);

    assign mem_req_write = 1'b0;

    reg active;
    reg [31:0] req_count;
    reg [31:0] resp_count;

    wire fifo_empty;

    byte_fifo #(
        .DEPTH(8)
    ) fifo (
        .clk     (clk),
        .rst_n   (rst_n),

        .s_tvalid(mem_resp_valid),
        .s_tdata (mem_resp_rdata),
        .s_tready(),

        .m_tvalid(m_tvalid),
        .m_tdata (m_tdata),
        .m_tready(m_tready),

        .empty   (fifo_empty)
    );

    wire [31:0] outstanding = req_count - resp_count;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            active        <= 0;
            done          <= 0;
            mem_req_valid <= 0;
            mem_req_addr  <= 0;
            req_count     <= 0;
            resp_count    <= 0;
        end else begin
            done          <= 0;
            mem_req_valid <= 0;

            if (start && !active) begin
                active     <= 1;
                req_count  <= 0;
                resp_count <= 0;
            end

            if (active &&
                req_count < length &&
                outstanding < MAX_OUTSTANDING) begin
                mem_req_valid <= 1;
                mem_req_addr  <= base_addr + req_count;
                req_count     <= req_count + 1;
            end

            if (mem_resp_valid)
                resp_count <= resp_count + 1;

            if (active &&
                req_count  == length &&
                resp_count == length &&
                fifo_empty) begin
                done   <= 1;
                active <= 0;
            end
        end
    end

endmodule
