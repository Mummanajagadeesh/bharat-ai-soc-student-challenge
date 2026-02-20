`timescale 1ns/1ps

module byte_fifo #(
    parameter DEPTH = 8
)(
    input  wire       clk,
    input  wire       rst_n,

    // AXI-Stream input
    input  wire       s_tvalid,
    input  wire [7:0] s_tdata,
    output wire       s_tready,

    // AXI-Stream output
    output wire       m_tvalid,
    output wire [7:0] m_tdata,
    input  wire       m_tready,

    output wire       empty
);

    reg [7:0] mem [0:DEPTH-1];
    reg [$clog2(DEPTH)-1:0] wr_ptr, rd_ptr;
    reg [$clog2(DEPTH+1)-1:0] count;

    wire do_write = s_tvalid && s_tready;
    wire do_read  = m_tvalid && m_tready;

    assign s_tready = (count < DEPTH);
    assign m_tvalid = (count > 0);
    assign m_tdata  = mem[rd_ptr];
    assign empty    = (count == 0);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= 0;
            rd_ptr <= 0;
            count  <= 0;
        end else begin
            if (do_write) begin
                mem[wr_ptr] <= s_tdata;
                wr_ptr <= wr_ptr + 1;
            end

            if (do_read)
                rd_ptr <= rd_ptr + 1;

            case ({do_write, do_read})
                2'b10: count <= count + 1;
                2'b01: count <= count - 1;
                default: count <= count;
            endcase
        end
    end

endmodule
