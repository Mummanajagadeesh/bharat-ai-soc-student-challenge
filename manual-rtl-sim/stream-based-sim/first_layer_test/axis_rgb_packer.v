`timescale 1ns/1ps

module axis_rgb_packer #(
    parameter IMG_PIXELS = 1024
)(
    input  wire        clk,
    input  wire        rst_n,

    // AXI-Stream input (bytes)
    input  wire        s_tvalid,
    input  wire [7:0]  s_tdata,
    output wire        s_tready,

    // AXI-Stream output (RGB pixels)
    output reg         m_tvalid,
    output reg  [23:0] m_tdata,
    output reg         m_tlast,
    input  wire        m_tready
);

    localparam ST_R = 2'd0;
    localparam ST_G = 2'd1;
    localparam ST_B = 2'd2;

    reg [1:0] state;
    reg [31:0] r_idx, g_idx, pix_idx;

    reg [7:0] r_buf [0:IMG_PIXELS-1];
    reg [7:0] g_buf [0:IMG_PIXELS-1];

    assign s_tready =
        (state != ST_B) ||
        (state == ST_B && (!m_tvalid || m_tready));

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state   <= ST_R;
            r_idx   <= 0;
            g_idx   <= 0;
            pix_idx <= 0;
            m_tvalid <= 0;
            m_tdata  <= 0;
            m_tlast  <= 0;
        end else begin
            if (m_tvalid && m_tready) begin
                m_tvalid <= 0;
                m_tlast  <= 0;
            end

            if (s_tvalid && s_tready) begin
                case (state)
                    ST_R: begin
                        r_buf[r_idx] <= s_tdata;
                        r_idx <= r_idx + 1;
                        if (r_idx == IMG_PIXELS-1) begin
                            r_idx <= 0;
                            state <= ST_G;
                        end
                    end

                    ST_G: begin
                        g_buf[g_idx] <= s_tdata;
                        g_idx <= g_idx + 1;
                        if (g_idx == IMG_PIXELS-1) begin
                            g_idx <= 0;
                            state <= ST_B;
                        end
                    end

                    ST_B: begin
                        if (!m_tvalid || m_tready) begin
                            m_tdata <= {
                                r_buf[pix_idx],
                                g_buf[pix_idx],
                                s_tdata
                            };
                            m_tvalid <= 1;
                            m_tlast  <= (pix_idx == IMG_PIXELS-1);
                            pix_idx  <= (pix_idx == IMG_PIXELS-1) ? 0 : pix_idx + 1;
                            if (pix_idx == IMG_PIXELS-1)
                                state <= ST_R;
                        end
                    end
                endcase
            end
        end
    end

endmodule
