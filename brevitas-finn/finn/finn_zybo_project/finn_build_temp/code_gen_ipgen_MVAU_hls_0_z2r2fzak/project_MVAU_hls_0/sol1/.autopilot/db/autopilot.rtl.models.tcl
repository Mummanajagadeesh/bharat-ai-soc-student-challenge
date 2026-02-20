set SynModuleInfo {
  {SRCNAME Matrix_Vector_Activate_Stream_Batch MODELNAME Matrix_Vector_Activate_Stream_Batch RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch
    SUBMODULES {
      {MODELNAME MVAU_hls_0_mux_275_8_1_1 RTLNAME MVAU_hls_0_mux_275_8_1_1 BINDTYPE op TYPE mux IMPL auto LATENCY 0 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_mac_muladd_8s_4s_15s_15_4_1 RTLNAME MVAU_hls_0_mac_muladd_8s_4s_15s_15_4_1 BINDTYPE op TYPE all IMPL dsp48 LATENCY 3 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_0_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_0_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_1_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_1_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_2_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_2_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_3_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_3_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_4_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_4_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_5_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_5_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_6_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_6_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_7_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_7_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_8_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_8_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_9_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_9_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_10_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_10_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_11_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_11_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_12_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_12_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_13_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_13_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_14_ROM_AUTO_1R RTLNAME MVAU_hls_0_Matrix_Vector_Activate_Stream_Batch_p_ZL7threshs_14_ROM_AUTO_1R BINDTYPE storage TYPE rom IMPL auto LATENCY 2 ALLOW_PRAGMA 1}
      {MODELNAME MVAU_hls_0_flow_control_loop_pipe_sequential_init RTLNAME MVAU_hls_0_flow_control_loop_pipe_sequential_init BINDTYPE interface TYPE internal_upc_flow_control INSTNAME MVAU_hls_0_flow_control_loop_pipe_sequential_init_U}
    }
  }
  {SRCNAME MVAU_hls_0 MODELNAME MVAU_hls_0 RTLNAME MVAU_hls_0 IS_TOP 1
    SUBMODULES {
      {MODELNAME MVAU_hls_0_regslice_both RTLNAME MVAU_hls_0_regslice_both BINDTYPE interface TYPE interface_regslice INSTNAME MVAU_hls_0_regslice_both_U}
    }
  }
}
