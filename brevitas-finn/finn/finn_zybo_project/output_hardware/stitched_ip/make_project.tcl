create_project finn_vivado_stitch_proj /tmp/finn_build_temp/vivado_stitch_proj_hr_ai0ak -part xc7z010clg400-1
set_msg_config -id {[BD 41-1753]} -suppress
set_property ip_repo_paths [list $::env(FINN_ROOT)/finn-rtllib/memstream /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_0_5fgk3b0m /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_0_2_eluc6w /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_1_btul5lb1 /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_0_bsubnyo7 /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_2_n83wlczx /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_0_u0kafh78 /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_3_yza_nuyj /tmp/finn_build_temp/code_gen_ipgen_MVAU_hls_0_abe2epdn/project_MVAU_hls_0/sol1/impl/ip /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_4_tg3fq0lj /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_1_rx16jc3l /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_5_jscpcr7l /tmp/finn_build_temp/code_gen_ipgen_StreamingMaxPool_hls_0_3742g_zy/project_StreamingMaxPool_hls_0/sol1/impl/ip /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_6_c3m5pyyr /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_1_b8xjfpwf /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_7_91tqdnz3 /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_2_unoej2n1 /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_8_jp58tokm /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_1_z4o8kewb /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_9_pxchce00 /tmp/finn_build_temp/code_gen_ipgen_MVAU_hls_1_c3fojq2h/project_MVAU_hls_1/sol1/impl/ip /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_10_pbbv408u /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_3_7zgrws2n /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_11_kgupmulb /tmp/finn_build_temp/code_gen_ipgen_StreamingMaxPool_hls_1_j0gy4fl3/project_StreamingMaxPool_hls_1/sol1/impl/ip /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_12_4fduznwj /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_4_p21vizja /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_13_7y9hiqg2 /tmp/finn_build_temp/code_gen_ipgen_MVAU_rtl_0_bqbp8ror /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_14_fbo0yhkd] [current_project]
update_ip_catalog
create_bd_design "finn_design"
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_0_5fgk3b0m/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_0_5fgk3b0m/StreamingFIFO_rtl_0.v
create_bd_cell -type module -reference StreamingFIFO_rtl_0 StreamingFIFO_rtl_0
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_0_2_eluc6w/fmpadding_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_0_2_eluc6w/fmpadding.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_0_2_eluc6w/axi2we.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_0_2_eluc6w/FMPadding_rtl_0.v
create_bd_cell -type module -reference FMPadding_rtl_0 FMPadding_rtl_0
create_bd_cell -type hier StreamingFIFO_rtl_1
create_bd_pin -dir I -type clk /StreamingFIFO_rtl_1/ap_clk
create_bd_pin -dir I -type rst /StreamingFIFO_rtl_1/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_1/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_1/in0_V
create_bd_cell -type ip -vlnv xilinx.com:ip:axis_data_fifo:2.0 /StreamingFIFO_rtl_1/fifo
set_property -dict [list CONFIG.FIFO_DEPTH {1024}] [get_bd_cells /StreamingFIFO_rtl_1/fifo]
set_property -dict [list CONFIG.FIFO_MEMORY_TYPE {auto}] [get_bd_cells /StreamingFIFO_rtl_1/fifo]
set_property -dict [list CONFIG.TDATA_NUM_BYTES {3}] [get_bd_cells /StreamingFIFO_rtl_1/fifo]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_1/fifo/M_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_1/out_V]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_1/fifo/S_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_1/in0_V]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_1/ap_rst_n] [get_bd_pins StreamingFIFO_rtl_1/fifo/s_axis_aresetn]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_1/ap_clk] [get_bd_pins StreamingFIFO_rtl_1/fifo/s_axis_aclk]
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_0_bsubnyo7/dwc_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_0_bsubnyo7/dwc.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_0_bsubnyo7/StreamingDataWidthConverter_rtl_0.v
create_bd_cell -type module -reference StreamingDataWidthConverter_rtl_0 StreamingDataWidthConverter_rtl_0
create_bd_cell -type hier StreamingFIFO_rtl_2
create_bd_pin -dir I -type clk /StreamingFIFO_rtl_2/ap_clk
create_bd_pin -dir I -type rst /StreamingFIFO_rtl_2/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_2/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_2/in0_V
create_bd_cell -type ip -vlnv xilinx.com:ip:axis_data_fifo:2.0 /StreamingFIFO_rtl_2/fifo
set_property -dict [list CONFIG.FIFO_DEPTH {4096}] [get_bd_cells /StreamingFIFO_rtl_2/fifo]
set_property -dict [list CONFIG.FIFO_MEMORY_TYPE {auto}] [get_bd_cells /StreamingFIFO_rtl_2/fifo]
set_property -dict [list CONFIG.TDATA_NUM_BYTES {1}] [get_bd_cells /StreamingFIFO_rtl_2/fifo]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_2/fifo/M_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_2/out_V]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_2/fifo/S_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_2/in0_V]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_2/ap_rst_n] [get_bd_pins StreamingFIFO_rtl_2/fifo/s_axis_aresetn]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_2/ap_clk] [get_bd_pins StreamingFIFO_rtl_2/fifo/s_axis_aclk]
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_0_u0kafh78/swg_pkg.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_0_u0kafh78/ConvolutionInputGenerator_rtl_0_wrapper.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_0_u0kafh78/ConvolutionInputGenerator_rtl_0_impl.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_0_u0kafh78/swg_common.sv
create_bd_cell -type module -reference ConvolutionInputGenerator_rtl_0 ConvolutionInputGenerator_rtl_0
create_bd_cell -type hier StreamingFIFO_rtl_3
create_bd_pin -dir I -type clk /StreamingFIFO_rtl_3/ap_clk
create_bd_pin -dir I -type rst /StreamingFIFO_rtl_3/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_3/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_3/in0_V
create_bd_cell -type ip -vlnv xilinx.com:ip:axis_data_fifo:2.0 /StreamingFIFO_rtl_3/fifo
set_property -dict [list CONFIG.FIFO_DEPTH {32768}] [get_bd_cells /StreamingFIFO_rtl_3/fifo]
set_property -dict [list CONFIG.FIFO_MEMORY_TYPE {auto}] [get_bd_cells /StreamingFIFO_rtl_3/fifo]
set_property -dict [list CONFIG.TDATA_NUM_BYTES {1}] [get_bd_cells /StreamingFIFO_rtl_3/fifo]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_3/fifo/M_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_3/out_V]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_3/fifo/S_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_3/in0_V]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_3/ap_rst_n] [get_bd_pins StreamingFIFO_rtl_3/fifo/s_axis_aresetn]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_3/ap_clk] [get_bd_pins StreamingFIFO_rtl_3/fifo/s_axis_aclk]
create_bd_cell -type hier MVAU_hls_0
create_bd_pin -dir I -type clk /MVAU_hls_0/ap_clk
create_bd_pin -dir I -type rst /MVAU_hls_0/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /MVAU_hls_0/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /MVAU_hls_0/in0_V
create_bd_cell -type ip -vlnv xilinx.com:hls:MVAU_hls_0:1.0 /MVAU_hls_0/MVAU_hls_0
create_bd_cell -type ip -vlnv amd.com:finn:memstream:1.0 /MVAU_hls_0/MVAU_hls_0_wstrm
set_property -dict [list CONFIG.DEPTH {432} CONFIG.WIDTH {8} CONFIG.INIT_FILE {/tmp/finn_build_temp/code_gen_ipgen_MVAU_hls_0_abe2epdn/memblock.dat} CONFIG.RAM_STYLE {auto} ] [get_bd_cells /MVAU_hls_0/MVAU_hls_0_wstrm]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_0/MVAU_hls_0_wstrm/m_axis_0] [get_bd_intf_pins MVAU_hls_0/MVAU_hls_0/weights_V]
connect_bd_net [get_bd_pins MVAU_hls_0/ap_rst_n] [get_bd_pins MVAU_hls_0/MVAU_hls_0_wstrm/ap_rst_n]
connect_bd_net [get_bd_pins MVAU_hls_0/ap_clk] [get_bd_pins MVAU_hls_0/MVAU_hls_0_wstrm/ap_clk]
connect_bd_net [get_bd_pins MVAU_hls_0/ap_rst_n] [get_bd_pins MVAU_hls_0/MVAU_hls_0/ap_rst_n]
connect_bd_net [get_bd_pins MVAU_hls_0/ap_clk] [get_bd_pins MVAU_hls_0/MVAU_hls_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_0/in0_V] [get_bd_intf_pins MVAU_hls_0/MVAU_hls_0/in0_V]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_0/out_V] [get_bd_intf_pins MVAU_hls_0/MVAU_hls_0/out_V]
save_bd_design
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_4_tg3fq0lj/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_4_tg3fq0lj/StreamingFIFO_rtl_4.v
create_bd_cell -type module -reference StreamingFIFO_rtl_4 StreamingFIFO_rtl_4
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_1_rx16jc3l/dwc_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_1_rx16jc3l/dwc.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_1_rx16jc3l/StreamingDataWidthConverter_rtl_1.v
create_bd_cell -type module -reference StreamingDataWidthConverter_rtl_1 StreamingDataWidthConverter_rtl_1
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_5_jscpcr7l/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_5_jscpcr7l/StreamingFIFO_rtl_5.v
create_bd_cell -type module -reference StreamingFIFO_rtl_5 StreamingFIFO_rtl_5
create_bd_cell -type ip -vlnv xilinx.com:hls:StreamingMaxPool_hls_0:1.0 StreamingMaxPool_hls_0
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_6_c3m5pyyr/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_6_c3m5pyyr/StreamingFIFO_rtl_6.v
create_bd_cell -type module -reference StreamingFIFO_rtl_6 StreamingFIFO_rtl_6
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_1_b8xjfpwf/fmpadding_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_1_b8xjfpwf/fmpadding.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_1_b8xjfpwf/axi2we.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_FMPadding_rtl_1_b8xjfpwf/FMPadding_rtl_1.v
create_bd_cell -type module -reference FMPadding_rtl_1 FMPadding_rtl_1
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_7_91tqdnz3/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_7_91tqdnz3/StreamingFIFO_rtl_7.v
create_bd_cell -type module -reference StreamingFIFO_rtl_7 StreamingFIFO_rtl_7
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_2_unoej2n1/dwc_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_2_unoej2n1/dwc.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_2_unoej2n1/StreamingDataWidthConverter_rtl_2.v
create_bd_cell -type module -reference StreamingDataWidthConverter_rtl_2 StreamingDataWidthConverter_rtl_2
create_bd_cell -type hier StreamingFIFO_rtl_8
create_bd_pin -dir I -type clk /StreamingFIFO_rtl_8/ap_clk
create_bd_pin -dir I -type rst /StreamingFIFO_rtl_8/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_8/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_8/in0_V
create_bd_cell -type ip -vlnv xilinx.com:ip:axis_data_fifo:2.0 /StreamingFIFO_rtl_8/fifo
set_property -dict [list CONFIG.FIFO_DEPTH {2048}] [get_bd_cells /StreamingFIFO_rtl_8/fifo]
set_property -dict [list CONFIG.FIFO_MEMORY_TYPE {auto}] [get_bd_cells /StreamingFIFO_rtl_8/fifo]
set_property -dict [list CONFIG.TDATA_NUM_BYTES {1}] [get_bd_cells /StreamingFIFO_rtl_8/fifo]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_8/fifo/M_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_8/out_V]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_8/fifo/S_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_8/in0_V]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_8/ap_rst_n] [get_bd_pins StreamingFIFO_rtl_8/fifo/s_axis_aresetn]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_8/ap_clk] [get_bd_pins StreamingFIFO_rtl_8/fifo/s_axis_aclk]
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_1_z4o8kewb/swg_pkg.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_1_z4o8kewb/ConvolutionInputGenerator_rtl_1_wrapper.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_1_z4o8kewb/ConvolutionInputGenerator_rtl_1_impl.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_ConvolutionInputGenerator_rtl_1_z4o8kewb/swg_common.sv
create_bd_cell -type module -reference ConvolutionInputGenerator_rtl_1 ConvolutionInputGenerator_rtl_1
create_bd_cell -type hier StreamingFIFO_rtl_9
create_bd_pin -dir I -type clk /StreamingFIFO_rtl_9/ap_clk
create_bd_pin -dir I -type rst /StreamingFIFO_rtl_9/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_9/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /StreamingFIFO_rtl_9/in0_V
create_bd_cell -type ip -vlnv xilinx.com:ip:axis_data_fifo:2.0 /StreamingFIFO_rtl_9/fifo
set_property -dict [list CONFIG.FIFO_DEPTH {32768}] [get_bd_cells /StreamingFIFO_rtl_9/fifo]
set_property -dict [list CONFIG.FIFO_MEMORY_TYPE {auto}] [get_bd_cells /StreamingFIFO_rtl_9/fifo]
set_property -dict [list CONFIG.TDATA_NUM_BYTES {1}] [get_bd_cells /StreamingFIFO_rtl_9/fifo]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_9/fifo/M_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_9/out_V]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_9/fifo/S_AXIS] [get_bd_intf_pins StreamingFIFO_rtl_9/in0_V]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_9/ap_rst_n] [get_bd_pins StreamingFIFO_rtl_9/fifo/s_axis_aresetn]
connect_bd_net [get_bd_pins StreamingFIFO_rtl_9/ap_clk] [get_bd_pins StreamingFIFO_rtl_9/fifo/s_axis_aclk]
create_bd_cell -type hier MVAU_hls_1
create_bd_pin -dir I -type clk /MVAU_hls_1/ap_clk
create_bd_pin -dir I -type rst /MVAU_hls_1/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /MVAU_hls_1/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /MVAU_hls_1/in0_V
create_bd_cell -type ip -vlnv xilinx.com:hls:MVAU_hls_1:1.0 /MVAU_hls_1/MVAU_hls_1
create_bd_cell -type ip -vlnv amd.com:finn:memstream:1.0 /MVAU_hls_1/MVAU_hls_1_wstrm
set_property -dict [list CONFIG.DEPTH {4608} CONFIG.WIDTH {8} CONFIG.INIT_FILE {/tmp/finn_build_temp/code_gen_ipgen_MVAU_hls_1_c3fojq2h/memblock.dat} CONFIG.RAM_STYLE {auto} ] [get_bd_cells /MVAU_hls_1/MVAU_hls_1_wstrm]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_1/MVAU_hls_1_wstrm/m_axis_0] [get_bd_intf_pins MVAU_hls_1/MVAU_hls_1/weights_V]
connect_bd_net [get_bd_pins MVAU_hls_1/ap_rst_n] [get_bd_pins MVAU_hls_1/MVAU_hls_1_wstrm/ap_rst_n]
connect_bd_net [get_bd_pins MVAU_hls_1/ap_clk] [get_bd_pins MVAU_hls_1/MVAU_hls_1_wstrm/ap_clk]
connect_bd_net [get_bd_pins MVAU_hls_1/ap_rst_n] [get_bd_pins MVAU_hls_1/MVAU_hls_1/ap_rst_n]
connect_bd_net [get_bd_pins MVAU_hls_1/ap_clk] [get_bd_pins MVAU_hls_1/MVAU_hls_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_1/in0_V] [get_bd_intf_pins MVAU_hls_1/MVAU_hls_1/in0_V]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_1/out_V] [get_bd_intf_pins MVAU_hls_1/MVAU_hls_1/out_V]
save_bd_design
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_10_pbbv408u/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_10_pbbv408u/StreamingFIFO_rtl_10.v
create_bd_cell -type module -reference StreamingFIFO_rtl_10 StreamingFIFO_rtl_10
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_3_7zgrws2n/dwc_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_3_7zgrws2n/dwc.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_3_7zgrws2n/StreamingDataWidthConverter_rtl_3.v
create_bd_cell -type module -reference StreamingDataWidthConverter_rtl_3 StreamingDataWidthConverter_rtl_3
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_11_kgupmulb/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_11_kgupmulb/StreamingFIFO_rtl_11.v
create_bd_cell -type module -reference StreamingFIFO_rtl_11 StreamingFIFO_rtl_11
create_bd_cell -type ip -vlnv xilinx.com:hls:StreamingMaxPool_hls_1:1.0 StreamingMaxPool_hls_1
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_12_4fduznwj/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_12_4fduznwj/StreamingFIFO_rtl_12.v
create_bd_cell -type module -reference StreamingFIFO_rtl_12 StreamingFIFO_rtl_12
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_4_p21vizja/dwc_axi.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_4_p21vizja/dwc.sv
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingDataWidthConverter_rtl_4_p21vizja/StreamingDataWidthConverter_rtl_4.v
create_bd_cell -type module -reference StreamingDataWidthConverter_rtl_4 StreamingDataWidthConverter_rtl_4
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_13_7y9hiqg2/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_13_7y9hiqg2/StreamingFIFO_rtl_13.v
create_bd_cell -type module -reference StreamingFIFO_rtl_13 StreamingFIFO_rtl_13
create_bd_cell -type hier MVAU_rtl_0
create_bd_pin -dir I -type clk /MVAU_rtl_0/ap_clk
create_bd_pin -dir I -type rst /MVAU_rtl_0/ap_rst_n
create_bd_intf_pin -mode Master -vlnv xilinx.com:interface:axis_rtl:1.0 /MVAU_rtl_0/out_V
create_bd_intf_pin -mode Slave -vlnv xilinx.com:interface:axis_rtl:1.0 /MVAU_rtl_0/in0_V
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_MVAU_rtl_0_bqbp8ror/MVAU_rtl_0_wrapper.v
add_files -norecurse /home/robotics/Documents/bharat-ai-soc-student-challenge/New_Train/new_res_brevitas/finn/finn-rtllib/mvu/mvu_vvu_axi.sv
add_files -norecurse /home/robotics/Documents/bharat-ai-soc-student-challenge/New_Train/new_res_brevitas/finn/finn-rtllib/mvu/replay_buffer.sv
add_files -norecurse /home/robotics/Documents/bharat-ai-soc-student-challenge/New_Train/new_res_brevitas/finn/finn-rtllib/mvu/mvu_4sx4u.sv
add_files -norecurse /home/robotics/Documents/bharat-ai-soc-student-challenge/New_Train/new_res_brevitas/finn/finn-rtllib/mvu/mvu_vvu_8sx9_dsp58.sv
add_files -norecurse /home/robotics/Documents/bharat-ai-soc-student-challenge/New_Train/new_res_brevitas/finn/finn-rtllib/mvu/mvu_8sx8u_dsp48.sv
create_bd_cell -type hier -reference MVAU_rtl_0 /MVAU_rtl_0/MVAU_rtl_0
create_bd_cell -type ip -vlnv amd.com:finn:memstream:1.0 /MVAU_rtl_0/MVAU_rtl_0_wstrm
set_property -dict [list CONFIG.DEPTH {15680} CONFIG.WIDTH {8} CONFIG.INIT_FILE {/tmp/finn_build_temp/code_gen_ipgen_MVAU_rtl_0_bqbp8ror/memblock.dat} CONFIG.RAM_STYLE {auto} ] [get_bd_cells /MVAU_rtl_0/MVAU_rtl_0_wstrm]
connect_bd_intf_net [get_bd_intf_pins MVAU_rtl_0/MVAU_rtl_0_wstrm/m_axis_0] [get_bd_intf_pins MVAU_rtl_0/MVAU_rtl_0/weights_V]
connect_bd_net [get_bd_pins MVAU_rtl_0/ap_rst_n] [get_bd_pins MVAU_rtl_0/MVAU_rtl_0_wstrm/ap_rst_n]
connect_bd_net [get_bd_pins MVAU_rtl_0/ap_clk] [get_bd_pins MVAU_rtl_0/MVAU_rtl_0_wstrm/ap_clk]
connect_bd_net [get_bd_pins MVAU_rtl_0/ap_rst_n] [get_bd_pins MVAU_rtl_0/MVAU_rtl_0/ap_rst_n]
connect_bd_net [get_bd_pins MVAU_rtl_0/ap_clk] [get_bd_pins MVAU_rtl_0/MVAU_rtl_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins MVAU_rtl_0/in0_V] [get_bd_intf_pins MVAU_rtl_0/MVAU_rtl_0/in0_V]
connect_bd_intf_net [get_bd_intf_pins MVAU_rtl_0/out_V] [get_bd_intf_pins MVAU_rtl_0/MVAU_rtl_0/out_V]
save_bd_design
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_14_fbo0yhkd/Q_srl.v
add_files -norecurse /tmp/finn_build_temp/code_gen_ipgen_StreamingFIFO_rtl_14_fbo0yhkd/StreamingFIFO_rtl_14.v
create_bd_cell -type module -reference StreamingFIFO_rtl_14 StreamingFIFO_rtl_14
make_bd_pins_external [get_bd_pins StreamingFIFO_rtl_0/ap_clk]
set_property name ap_clk [get_bd_ports ap_clk_0]
make_bd_pins_external [get_bd_pins StreamingFIFO_rtl_0/ap_rst_n]
set_property name ap_rst_n [get_bd_ports ap_rst_n_0]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins FMPadding_rtl_0/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins FMPadding_rtl_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_0/out_V] [get_bd_intf_pins FMPadding_rtl_0/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_1/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins FMPadding_rtl_0/out_V] [get_bd_intf_pins StreamingFIFO_rtl_1/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingDataWidthConverter_rtl_0/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingDataWidthConverter_rtl_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_1/out_V] [get_bd_intf_pins StreamingDataWidthConverter_rtl_0/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_2/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_2/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingDataWidthConverter_rtl_0/out_V] [get_bd_intf_pins StreamingFIFO_rtl_2/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins ConvolutionInputGenerator_rtl_0/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins ConvolutionInputGenerator_rtl_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_2/out_V] [get_bd_intf_pins ConvolutionInputGenerator_rtl_0/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_3/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_3/ap_clk]
connect_bd_intf_net [get_bd_intf_pins ConvolutionInputGenerator_rtl_0/out_V] [get_bd_intf_pins StreamingFIFO_rtl_3/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins MVAU_hls_0/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins MVAU_hls_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_3/out_V] [get_bd_intf_pins MVAU_hls_0/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_4/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_4/ap_clk]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_0/out_V] [get_bd_intf_pins StreamingFIFO_rtl_4/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingDataWidthConverter_rtl_1/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingDataWidthConverter_rtl_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_4/out_V] [get_bd_intf_pins StreamingDataWidthConverter_rtl_1/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_5/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_5/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingDataWidthConverter_rtl_1/out_V] [get_bd_intf_pins StreamingFIFO_rtl_5/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingMaxPool_hls_0/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingMaxPool_hls_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_5/out_V] [get_bd_intf_pins StreamingMaxPool_hls_0/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_6/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_6/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingMaxPool_hls_0/out_V] [get_bd_intf_pins StreamingFIFO_rtl_6/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins FMPadding_rtl_1/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins FMPadding_rtl_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_6/out_V] [get_bd_intf_pins FMPadding_rtl_1/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_7/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_7/ap_clk]
connect_bd_intf_net [get_bd_intf_pins FMPadding_rtl_1/out_V] [get_bd_intf_pins StreamingFIFO_rtl_7/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingDataWidthConverter_rtl_2/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingDataWidthConverter_rtl_2/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_7/out_V] [get_bd_intf_pins StreamingDataWidthConverter_rtl_2/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_8/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_8/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingDataWidthConverter_rtl_2/out_V] [get_bd_intf_pins StreamingFIFO_rtl_8/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins ConvolutionInputGenerator_rtl_1/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins ConvolutionInputGenerator_rtl_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_8/out_V] [get_bd_intf_pins ConvolutionInputGenerator_rtl_1/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_9/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_9/ap_clk]
connect_bd_intf_net [get_bd_intf_pins ConvolutionInputGenerator_rtl_1/out_V] [get_bd_intf_pins StreamingFIFO_rtl_9/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins MVAU_hls_1/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins MVAU_hls_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_9/out_V] [get_bd_intf_pins MVAU_hls_1/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_10/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_10/ap_clk]
connect_bd_intf_net [get_bd_intf_pins MVAU_hls_1/out_V] [get_bd_intf_pins StreamingFIFO_rtl_10/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingDataWidthConverter_rtl_3/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingDataWidthConverter_rtl_3/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_10/out_V] [get_bd_intf_pins StreamingDataWidthConverter_rtl_3/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_11/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_11/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingDataWidthConverter_rtl_3/out_V] [get_bd_intf_pins StreamingFIFO_rtl_11/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingMaxPool_hls_1/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingMaxPool_hls_1/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_11/out_V] [get_bd_intf_pins StreamingMaxPool_hls_1/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_12/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_12/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingMaxPool_hls_1/out_V] [get_bd_intf_pins StreamingFIFO_rtl_12/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingDataWidthConverter_rtl_4/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingDataWidthConverter_rtl_4/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_12/out_V] [get_bd_intf_pins StreamingDataWidthConverter_rtl_4/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_13/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_13/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingDataWidthConverter_rtl_4/out_V] [get_bd_intf_pins StreamingFIFO_rtl_13/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins MVAU_rtl_0/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins MVAU_rtl_0/ap_clk]
connect_bd_intf_net [get_bd_intf_pins StreamingFIFO_rtl_13/out_V] [get_bd_intf_pins MVAU_rtl_0/in0_V]
connect_bd_net [get_bd_ports ap_rst_n] [get_bd_pins StreamingFIFO_rtl_14/ap_rst_n]
connect_bd_net [get_bd_ports ap_clk] [get_bd_pins StreamingFIFO_rtl_14/ap_clk]
connect_bd_intf_net [get_bd_intf_pins MVAU_rtl_0/out_V] [get_bd_intf_pins StreamingFIFO_rtl_14/in0_V]
make_bd_intf_pins_external [get_bd_intf_pins StreamingFIFO_rtl_0/in0_V]
set_property name s_axis_0 [get_bd_intf_ports in0_V_0]
make_bd_intf_pins_external [get_bd_intf_pins StreamingFIFO_rtl_14/out_V]
set_property name m_axis_0 [get_bd_intf_ports out_V_0]
set_property CONFIG.FREQ_HZ 100000000 [get_bd_ports /ap_clk]
validate_bd_design
save_bd_design
make_wrapper -files [get_files /tmp/finn_build_temp/vivado_stitch_proj_hr_ai0ak/finn_vivado_stitch_proj.srcs/sources_1/bd/finn_design/finn_design.bd] -top
add_files -norecurse /tmp/finn_build_temp/vivado_stitch_proj_hr_ai0ak/finn_vivado_stitch_proj.srcs/sources_1/bd/finn_design/hdl/finn_design_wrapper.v
set_property top finn_design_wrapper [current_fileset]
ipx::package_project -root_dir /tmp/finn_build_temp/vivado_stitch_proj_hr_ai0ak/ip -vendor xilinx_finn -library finn -taxonomy /UserIP -module finn_design -import_files
set_property ipi_drc {ignore_freq_hz true} [ipx::current_core]
ipx::remove_segment -quiet m_axi_gmem0:APERTURE_0 [ipx::get_address_spaces m_axi_gmem0 -of_objects [ipx::current_core]]
set_property core_revision 2 [ipx::find_open_core xilinx_finn:finn:finn_design:1.0]
ipx::create_xgui_files [ipx::find_open_core xilinx_finn:finn:finn_design:1.0]
set_property value_resolve_type user [ipx::get_bus_parameters -of [ipx::get_bus_interfaces -of [ipx::current_core ]]]

set core [ipx::current_core]

# Add rudimentary driver
file copy -force data ip/
set file_group [ipx::add_file_group -type software_driver {} $core]
set_property type mdd       [ipx::add_file data/finn_design.mdd $file_group]
set_property type tclSource [ipx::add_file data/finn_design.tcl $file_group]

# Remove all XCI references to subcores
set impl_files [ipx::get_file_groups xilinx_implementation -of $core]
foreach xci [ipx::get_files -of $impl_files {*.xci}] {
    ipx::remove_file [get_property NAME $xci] $impl_files
}

# Construct a single flat memory map for each AXI-lite interface port
foreach port [get_bd_intf_ports -filter {CONFIG.PROTOCOL==AXI4LITE}] {
    set pin $port
    set awidth ""
    while { $awidth == "" } {
        set pins [get_bd_intf_pins -of [get_bd_intf_nets -boundary_type lower -of $pin]]
        set kill [lsearch $pins $pin]
        if { $kill >= 0 } { set pins [lreplace $pins $kill $kill] }
        if { [llength $pins] != 1 } { break }
        set pin [lindex $pins 0]
        set awidth [get_property CONFIG.ADDR_WIDTH $pin]
    }
    if { $awidth == "" } {
       puts "CRITICAL WARNING: Unable to construct address map for $port."
    } {
       set range [expr 2**$awidth]
       set range [expr $range < 4096 ? 4096 : $range]
       puts "INFO: Building address map for $port: 0+:$range"
       set name [get_property NAME $port]
       set addr_block [ipx::add_address_block Reg0 [ipx::add_memory_map $name $core]]
       set_property range $range $addr_block
       set_property slave_memory_map_ref $name [ipx::get_bus_interfaces $name -of $core]
    }
}

# Finalize and Save
ipx::update_checksums $core
ipx::save_core $core

# Remove stale subcore references from component.xml
file rename -force ip/component.xml ip/component.bak
set ifile [open ip/component.bak r]
set ofile [open ip/component.xml w]
set buf [list]
set kill 0
while { [eof $ifile] != 1 } {
    gets $ifile line
    if { [string match {*<spirit:fileSet>*} $line] == 1 } {
        foreach l $buf { puts $ofile $l }
        set buf [list $line]
    } elseif { [llength $buf] > 0 } {
        lappend buf $line

        if { [string match {*</spirit:fileSet>*} $line] == 1 } {
            if { $kill == 0 } { foreach l $buf { puts $ofile $l } }
            set buf [list]
            set kill 0
        } elseif { [string match {*<xilinx:subCoreRef>*} $line] == 1 } {
            set kill 1
        }
    } else {
        puts $ofile $line
    }
}
close $ifile
close $ofile

set all_v_files [get_files -filter {USED_IN_SYNTHESIS == 1 && (FILE_TYPE == Verilog || FILE_TYPE == SystemVerilog || FILE_TYPE =="Verilog Header")}]
set fp [open /tmp/finn_build_temp/vivado_stitch_proj_hr_ai0ak/all_verilog_srcs.txt w]
foreach vf $all_v_files {puts $fp $vf}
close $fp
