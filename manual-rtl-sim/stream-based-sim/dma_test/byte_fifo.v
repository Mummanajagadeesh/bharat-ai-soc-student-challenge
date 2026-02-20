`timescale 1ns/1ps

module byte_fifo #(
    parameter DEPTH = 8
)(
    input  wire       clk,
    input  wire       rst_n,

    // input stream
    input  wire       s_valid,
    input  wire [7:0] s_data,
    output wire       s_ready,

    // output stream
    output wire       m_valid,
    output wire [7:0] m_data,
    input  wire       m_ready,

    // status
    output wire       empty
);

    reg [7:0] mem [0:DEPTH-1];
    reg [$clog2(DEPTH)-1:0] wr_ptr, rd_ptr;
    reg [$clog2(DEPTH+1)-1:0] count;

    wire do_write = s_valid && s_ready;
    wire do_read  = m_valid && m_ready;

    assign s_ready = (count < DEPTH);
    assign m_valid = (count > 0);
    assign m_data  = mem[rd_ptr];
    assign empty   = (count == 0);

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= 0;
            rd_ptr <= 0;
            count  <= 0;
        end else begin
            if (do_write) begin
                mem[wr_ptr] <= s_data;
                wr_ptr <= wr_ptr + 1;
            end

            if (do_read) begin
                rd_ptr <= rd_ptr + 1;
            end

            case ({do_write, do_read})
                2'b10: count <= count + 1;
                2'b01: count <= count - 1;
                default: count <= count;
            endcase
        end
    end

endmodule
