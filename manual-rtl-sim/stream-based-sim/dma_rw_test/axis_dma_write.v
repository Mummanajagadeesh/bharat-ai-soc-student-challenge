`timescale 1ns/1ps

module axis_dma_write (
    input  wire clk,
    input  wire rst_n,

    input  wire        start,
    input  wire [31:0] base_addr,
    input  wire [31:0] length,
    output reg         done,

    // AXI-Stream slave
    input  wire        S_AXIS_TVALID,
    input  wire [7:0]  S_AXIS_TDATA,
    output wire        S_AXIS_TREADY,

    // memory write
    output reg         mem_wr_valid,
    output reg  [31:0] mem_wr_addr,
    output reg  [7:0]  mem_wr_data
);

    reg active;
    reg [31:0] count;
    reg have_data;
    reg [7:0] data_buf;

    assign S_AXIS_TREADY = active && !have_data;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            active       <= 0;
            count        <= 0;
            done         <= 0;
            have_data    <= 0;
            mem_wr_valid <= 0;
        end else begin
            done         <= 0;
            mem_wr_valid <= 0;

            if (start && !active) begin
                active    <= 1;
                count     <= 0;
                have_data <= 0;
            end

            if (active && S_AXIS_TVALID && S_AXIS_TREADY) begin
                data_buf  <= S_AXIS_TDATA;
                have_data <= 1;
            end

            if (active && have_data) begin
                mem_wr_valid <= 1;
                mem_wr_addr  <= base_addr + count;
                mem_wr_data  <= data_buf;

                count     <= count + 1;
                have_data <= 0;

                if (count + 1 == length) begin
                    done   <= 1;
                    active <= 0;
                end
            end
        end
    end

endmodule
