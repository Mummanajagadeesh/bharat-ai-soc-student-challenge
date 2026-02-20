//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2022.2 (lin64) Build 3671981 Fri Oct 14 04:59:54 MDT 2022
//Date        : Fri Feb 20 14:44:24 2026
//Host        : 33e619815b19 running 64-bit Ubuntu 22.04.1 LTS
//Command     : generate_target finn_design_wrapper.bd
//Design      : finn_design_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module finn_design_wrapper
   (ap_clk,
    ap_rst_n,
    m_axis_0_tdata,
    m_axis_0_tready,
    m_axis_0_tvalid,
    maxcount,
    maxcount_1,
    maxcount_10,
    maxcount_11,
    maxcount_12,
    maxcount_13,
    maxcount_14,
    maxcount_2,
    maxcount_3,
    maxcount_4,
    maxcount_5,
    maxcount_6,
    maxcount_7,
    maxcount_8,
    maxcount_9,
    s_axis_0_tdata,
    s_axis_0_tready,
    s_axis_0_tvalid);
  input ap_clk;
  input ap_rst_n;
  output [23:0]m_axis_0_tdata;
  input m_axis_0_tready;
  output m_axis_0_tvalid;
  output [9:0]maxcount;
  output [9:0]maxcount_1;
  output [12:0]maxcount_10;
  output [7:0]maxcount_11;
  output [5:0]maxcount_12;
  output [10:0]maxcount_13;
  output [3:0]maxcount_14;
  output [11:0]maxcount_2;
  output [14:0]maxcount_3;
  output [13:0]maxcount_4;
  output [9:0]maxcount_5;
  output [7:0]maxcount_6;
  output [8:0]maxcount_7;
  output [12:0]maxcount_8;
  output [14:0]maxcount_9;
  input [23:0]s_axis_0_tdata;
  output s_axis_0_tready;
  input s_axis_0_tvalid;

  wire ap_clk;
  wire ap_rst_n;
  wire [23:0]m_axis_0_tdata;
  wire m_axis_0_tready;
  wire m_axis_0_tvalid;
  wire [9:0]maxcount;
  wire [9:0]maxcount_1;
  wire [12:0]maxcount_10;
  wire [7:0]maxcount_11;
  wire [5:0]maxcount_12;
  wire [10:0]maxcount_13;
  wire [3:0]maxcount_14;
  wire [11:0]maxcount_2;
  wire [14:0]maxcount_3;
  wire [13:0]maxcount_4;
  wire [9:0]maxcount_5;
  wire [7:0]maxcount_6;
  wire [8:0]maxcount_7;
  wire [12:0]maxcount_8;
  wire [14:0]maxcount_9;
  wire [23:0]s_axis_0_tdata;
  wire s_axis_0_tready;
  wire s_axis_0_tvalid;

  finn_design finn_design_i
       (.ap_clk(ap_clk),
        .ap_rst_n(ap_rst_n),
        .m_axis_0_tdata(m_axis_0_tdata),
        .m_axis_0_tready(m_axis_0_tready),
        .m_axis_0_tvalid(m_axis_0_tvalid),
        .maxcount(maxcount),
        .maxcount_1(maxcount_1),
        .maxcount_10(maxcount_10),
        .maxcount_11(maxcount_11),
        .maxcount_12(maxcount_12),
        .maxcount_13(maxcount_13),
        .maxcount_14(maxcount_14),
        .maxcount_2(maxcount_2),
        .maxcount_3(maxcount_3),
        .maxcount_4(maxcount_4),
        .maxcount_5(maxcount_5),
        .maxcount_6(maxcount_6),
        .maxcount_7(maxcount_7),
        .maxcount_8(maxcount_8),
        .maxcount_9(maxcount_9),
        .s_axis_0_tdata(s_axis_0_tdata),
        .s_axis_0_tready(s_axis_0_tready),
        .s_axis_0_tvalid(s_axis_0_tvalid));
endmodule
