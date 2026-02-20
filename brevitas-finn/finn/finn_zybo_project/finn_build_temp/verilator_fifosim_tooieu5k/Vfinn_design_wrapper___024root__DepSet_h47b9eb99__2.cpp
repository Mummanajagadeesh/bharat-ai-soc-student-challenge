// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vfinn_design_wrapper.h for the primary calling header

#include "verilated.h"

#include "Vfinn_design_wrapper___024root.h"

extern const VlUnpacked<CData/*0:0*/, 8> Vfinn_design_wrapper__ConstPool__TABLE_h2ceaafb2_0;
extern const VlUnpacked<SData/*8:0*/, 8> Vfinn_design_wrapper__ConstPool__TABLE_h354a826a_0;

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__38(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__38\n"); );
    // Init
    CData/*2:0*/ __Vtableidx1;
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
    __Vtableidx1 = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__State;
    if (Vfinn_design_wrapper__ConstPool__TABLE_h2ceaafb2_0
        [__Vtableidx1]) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__addr_incr 
            = Vfinn_design_wrapper__ConstPool__TABLE_h354a826a_0
            [__Vtableidx1];
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__state_next 
        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__State;
    if ((1U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__State))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__state_next = 1U;
    } else if (VL_GTS_III(32, 0U, VL_EXTENDS_II(32,2, (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__Counter_loop_simd)))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__state_next 
            = (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,3, (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__Counter_loop_kw)))
                ? 2U : (VL_LTES_III(32, 0U, VL_EXTENDS_II(32,3, (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__Counter_loop_kh)))
                         ? 3U : (VL_LTES_III(32, 0U, 
                                             VL_EXTENDS_II(32,6, (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__Counter_loop_w)))
                                  ? 4U : (VL_LTES_III(32, 0U, 
                                                      VL_EXTENDS_II(32,6, (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__controller_inst__DOT__Counter_loop_h)))
                                           ? 5U : 0U))));
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        if ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 1U;
        } else {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 0U;
        }
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state))) {
        if ((1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__i_b_reg) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ 
                    = ((0x30feU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr))
                        ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srl
                       [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr]
                        : 0U);
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x3fffU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x3fffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr) 
                                      - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x3fffU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if ((1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                = (0x3fffU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x30feU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__BRdy))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x30feU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x3fffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr) 
                                  - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__sen 
        = (1U & (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__i_b_reg)) 
                  | (~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                        >> 0x18U))) & (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_0__DOT__inst__DOT__impl__DOT__o_v_reg) 
                                        | (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__A 
                                           >> 0x18U)) 
                                       | (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__fwd)))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_2__DOT__inst__DOT__impl__DOT__i_b_reg 
        = ((IData)(vlSelf->ap_rst_n) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_2__DOT__inst__DOT__impl__DOT__addr_full_));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__10(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__10\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_2__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_2__DOT__inst__DOT__impl__DOT__state_)) 
           & (0xa8aU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_2__DOT__inst__DOT__impl__DOT__addr_)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__39(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__39\n"); );
    // Init
    IData/*31:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__unnamedblk3__DOT__unnamedblk4__DOT__ofs;
    CData/*2:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT____Vlvbound_hb5b993a6__0;
    CData/*0:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT____Vlvbound_hc80554e1__0;
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ 
            = (1U & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                     >> 0x18U));
        if ((0x1000000U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B)) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ 
                = (0xffffffU & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B);
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 1U;
        } else {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 0U;
        }
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state))) {
        if ((IData)(((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                      >> 0x18U) & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                     >> 0x18U) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ 
                = (0xffffffU & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B);
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                              >> 0x18U)) & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                        >> 0x18U)) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_full) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ 
                    = ((0x382U >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr))
                        ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srl
                       [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr]
                        : 0U);
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x3ffU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x3ffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr) 
                                     - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x3ffU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if ((IData)(((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                             >> 0x18U) & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                     >> 0x18U) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x382U >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                              >> 0x18U)) & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__B 
                        >> 0x18U)) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x382U >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x3ffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr) 
                                 - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__dd = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__aa = 0U;
    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__unnamedblk3__DOT__unnamedblk4__DOT__ofs = 0x15U;
    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT____Vlvbound_hb5b993a6__0 
        = (7U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__ww
           [0U]);
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__dd 
        = ((0x71fffffU & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__dd) 
           | ((IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT____Vlvbound_hb5b993a6__0) 
              << 0x15U));
    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT____Vlvbound_hc80554e1__0 
        = (1U & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__ww
                 [0U] >> 3U));
    if ((0x1aU >= (0x1fU & ((IData)(3U) + finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__unnamedblk3__DOT__unnamedblk4__DOT__ofs)))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__dd 
            = (((~ ((IData)(1U) << (0x1fU & ((IData)(3U) 
                                             + finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__unnamedblk3__DOT__unnamedblk4__DOT__ofs)))) 
                & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__dd) 
               | (0x7ffffffU & ((IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT____Vlvbound_hc80554e1__0) 
                                << (0x1fU & ((IData)(3U) 
                                             + finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__blkVectorize__DOT__unnamedblk3__DOT__unnamedblk4__DOT__ofs)))));
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__xen 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__sen) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__SCount));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x382U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_1__DOT__inst__DOT__impl__DOT__addr_)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__yen 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__xen) 
           & (0x1dU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__XCount)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__11(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__11\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__yclr 
        = (1U & ((~ (IData)(vlSelf->ap_rst_n)) | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__yen) 
                                                  & (0x1dU 
                                                     == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__FMPadding_rtl_0__DOT__inst__DOT__impl__DOT__padding__DOT__YCount)))));
}

extern const VlUnpacked<CData/*3:0*/, 256> Vfinn_design_wrapper__ConstPool__TABLE_h4379c313_0;
extern const VlUnpacked<CData/*1:0*/, 256> Vfinn_design_wrapper__ConstPool__TABLE_h3d35996a_0;

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__41(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__41\n"); );
    // Init
    CData/*7:0*/ __Vtableidx25;
    CData/*7:0*/ __Vtableidx26;
    VlWide<3>/*95:0*/ __Vtemp_h4174426a__0;
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4_out_V_TDATA 
        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CDat;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ 
            = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)
                ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4_out_V_TDATA)
                : 0U);
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state))) {
        if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
             & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4_out_V_TDATA;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_full) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY)
                    ? ((0x61eU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr))
                        ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srl
                       [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr]
                        : 0U) : 0U);
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x61eU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x61eU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_NS_fsm 
        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ 
            = ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state))
                ? 1U : 0U);
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state))) {
        if ((1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__i_b_reg) {
            if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY) {
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x3fU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x3fU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr) 
                                    - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x3fU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if ((1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                = (0x3fU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x3fU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr) 
                                - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x2fU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr_)));
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_28_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_28_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_28_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_28_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_27_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_27_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_27_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_27_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_26_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_26_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_26_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_26_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_25_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_25_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_25_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_25_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_U__DOT__ram__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_U__DOT__ram__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_U__DOT__ram[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_U__DOT__ram__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_U__DOT__ram__v0;
    }
    if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_loop_init) 
         & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_10_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_load_reg_1106;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_1_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_1_load_reg_1061;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_29_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_load_reg_1201;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_2_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_2_load_reg_1066;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_30_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_load_reg_1206;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_31_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_load_reg_1211;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_3_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_load_reg_1071;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_4_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_load_reg_1076;
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_10_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_10_fu_342;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_1_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_1_fu_306;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_29_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_29_fu_418;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_2_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_2_fu_310;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_30_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_30_fu_422;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_31_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_31_fu_426;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_3_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_3_fu_314;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_4_load 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__oldMax_V_4_fu_318;
    }
    __Vtemp_h4174426a__0[1U] = (IData)((((QData)((IData)(
                                                         (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_q0) 
                                                           << 0x1cU) 
                                                          | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_q0) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_q0) 
                                                                 << 0x14U) 
                                                                | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_28_q0) 
                                                                    << 0x10U) 
                                                                   | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_27_q0) 
                                                                       << 0xcU) 
                                                                      | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_26_q0) 
                                                                          << 8U) 
                                                                         | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_25_q0) 
                                                                             << 4U) 
                                                                            | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_q0)))))))))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_q0) 
                                                            << 0x1cU) 
                                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_q0) 
                                                               << 0x18U) 
                                                              | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_q0) 
                                                                  << 0x14U) 
                                                                 | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_20_q0) 
                                                                     << 0x10U) 
                                                                    | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_19_q0) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_18_q0) 
                                                                           << 8U) 
                                                                          | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_17_q0) 
                                                                              << 4U) 
                                                                             | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_16_q0))))))))))));
    __Vtemp_h4174426a__0[2U] = (IData)(((((QData)((IData)(
                                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_31_q0) 
                                                            << 0x1cU) 
                                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_q0) 
                                                               << 0x18U) 
                                                              | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_29_q0) 
                                                                  << 0x14U) 
                                                                 | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_28_q0) 
                                                                     << 0x10U) 
                                                                    | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_27_q0) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_26_q0) 
                                                                           << 8U) 
                                                                          | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_25_q0) 
                                                                              << 4U) 
                                                                             | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_q0)))))))))) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_q0) 
                                                             << 0x1cU) 
                                                            | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_q0) 
                                                                << 0x18U) 
                                                               | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_q0) 
                                                                   << 0x14U) 
                                                                  | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_20_q0) 
                                                                      << 0x10U) 
                                                                     | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_19_q0) 
                                                                         << 0xcU) 
                                                                        | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_18_q0) 
                                                                            << 8U) 
                                                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_17_q0) 
                                                                               << 4U) 
                                                                              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_16_q0))))))))))) 
                                        >> 0x20U));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TDATA[0U] 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_7_q0) 
            << 0x1cU) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_6_q0) 
                          << 0x18U) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_5_q0) 
                                        << 0x14U) | 
                                       (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_q0) 
                                         << 0x10U) 
                                        | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_q0) 
                                            << 0xcU) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_2_q0) 
                                               << 8U) 
                                              | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_1_q0) 
                                                  << 4U) 
                                                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_q0))))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TDATA[1U] 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_15_q0) 
            << 0x1cU) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_14_q0) 
                          << 0x18U) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_q0) 
                                        << 0x14U) | 
                                       (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_q0) 
                                         << 0x10U) 
                                        | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_q0) 
                                            << 0xcU) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_q0) 
                                               << 8U) 
                                              | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_q0) 
                                                  << 4U) 
                                                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_8_q0))))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TDATA[2U] 
        = __Vtemp_h4174426a__0[1U];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TDATA[3U] 
        = __Vtemp_h4174426a__0[2U];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_10_fu_1616_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[1U] 
                    >> 8U)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_10_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_1_fu_1391_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[0U] 
                    >> 4U)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_1_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_29_fu_2091_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[3U] 
                    >> 0x14U)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_29_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_2_fu_1416_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[0U] 
                    >> 8U)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_2_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_30_fu_2116_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[3U] 
                    >> 0x18U)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_30_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_31_fu_2141_p2 
        = ((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[3U] 
            >> 0x1cU) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_31_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_3_fu_1441_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[0U] 
                    >> 0xcU)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_3_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__icmp_ln1035_4_fu_1466_p2 
        = ((0xfU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out[0U] 
                    >> 0x10U)) > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_oldMax_V_4_load));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_done_int 
        = ((((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                 | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_condition_exit_pp0_iter0_stage0)) 
            & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm)) 
           | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_done_reg));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__in0_V_TREADY_int_regslice 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__ap_CS_fsm) 
            >> 2U) & (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                       >> 6U) & (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                      | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                         & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                                  & (2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1))) 
                                 & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))));
    if (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
         & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
            >> 3U))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_5_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_6_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_7_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_8_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_fu_809_p3;
    } else if ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_5_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_6_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_7_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_8_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__select_ln155_reg_886;
    } else if ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_5_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_6_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_7_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_8_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1;
    } else if ((2U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_5_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_6_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_7_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_8_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_address0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_sig_allocacmp_i_1;
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_22_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_23_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_24_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_4_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_5_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_6_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_7_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_8_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_address0 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_address0 = 0U;
    }
    __Vtableidx25 = ((0x80U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__ap_CS_fsm) 
                               << 5U)) | ((0x40U & 
                                           ((0xffffffc0U 
                                             & (((7U 
                                                  == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__yp_fu_56)) 
                                                 << 6U) 
                                                & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                                   << 4U))) 
                                            | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                                & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28_ap_start_reg))) 
                                               << 6U))) 
                                          | ((0x20U 
                                              & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__ap_CS_fsm) 
                                                 << 2U)) 
                                             | (((((3U 
                                                    == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                                                   & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__i_b_reg)) 
                                                  | (1U 
                                                     == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state))) 
                                                 << 4U) 
                                                | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__ap_CS_fsm)))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__ap_NS_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h4379c313_0
        [__Vtableidx25];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_done 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_done_int) 
           | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__flow_control_loop_pipe_sequential_init_U__DOT__ap_done_cache) 
              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TVALID 
        = (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
               >> 1U)) & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                             | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_condition_exit_pp0_iter0_stage0 
        = (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                    >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                              | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                 & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
            & (7U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm));
    __Vtableidx26 = ((0x80U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                               << 6U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg) 
                                           << 6U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm) 
                                            << 5U) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY) 
                                               << 4U) 
                                              | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702) 
                                                  << 3U) 
                                                 | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                                     << 2U) 
                                                    | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm)))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_NS_iter1_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h3d35996a_0
        [__Vtableidx26];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_10_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_11_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_12_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_13_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_14_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_17_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_18_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_20_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_21_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_30_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_3_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_9_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__buf_V_ce0 
        = (((0xeU != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
               >> 3U)) | ((0x40U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                           ? ((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_start_reg)) 
                                  | ((2U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_sig_allocacmp_kx_1)) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700__DOT__ap_CS_fsm))
                           : ((0x80U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                               ? (((~ ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)) 
                                       | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter1_fsm) 
                                           >> 1U) & 
                                          ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_block_state2_io) 
                                           | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__icmp_ln174_reg_702)) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_out_V_TREADY))))))) 
                                   & (7U != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_sig_allocacmp_outpix_1))) 
                                  & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_CS_iter0_fsm))
                               : (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_CS_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_NS_fsm 
        = (((((((((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm)) 
                  | (2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) 
                 | (4U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) 
                | (8U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) 
               | (0x10U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) 
              | (0x20U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) 
             | (0x40U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))) 
            | (0x80U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm)))
            ? ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                ? (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28_ap_start_reg))
                    ? 2U : 1U) : ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                                   ? ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__ap_done_int) 
                                        | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594__DOT__flow_control_loop_pipe_sequential_init_U__DOT__ap_done_cache) 
                                           & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_147_1_fu_594_ap_start_reg)))) 
                                       & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                          >> 1U)) ? 4U
                                       : 2U) : ((4U 
                                                 == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                                                 ? 
                                                (((7U 
                                                   == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__yp_fu_56)) 
                                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                                     >> 2U))
                                                  ? 1U
                                                  : 8U)
                                                 : 
                                                ((8U 
                                                  == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                                                  ? 
                                                 (((0xeU 
                                                    == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__indvar_flatten_reg_572)) 
                                                   & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                                      >> 3U))
                                                   ? 0x80U
                                                   : 0x10U)
                                                  : 
                                                 ((0x10U 
                                                   == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                                                   ? 0x20U
                                                   : 
                                                  ((0x20U 
                                                    == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                                                    ? 0x40U
                                                    : 
                                                   ((0x40U 
                                                     == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm))
                                                     ? 
                                                    (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_158_6_fu_700_ap_done) 
                                                      & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                                         >> 6U))
                                                      ? 8U
                                                      : 0x40U)
                                                     : 
                                                    ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__ap_done_int) 
                                                       | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662__DOT__flow_control_loop_pipe_sequential_init_U__DOT__ap_done_cache) 
                                                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__grp_StreamingMaxPool_Precision_Pipeline_VITIS_LOOP_174_8_fu_662_ap_start_reg)))) 
                                                      & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__grp_StreamingMaxPool_Precision_14u_2u_32u_ap_uint_4_0_128_s_fu_28__DOT__ap_CS_fsm) 
                                                         >> 7U))
                                                      ? 4U
                                                      : 0x80U))))))))
            : 0U);
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__42(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__42\n"); );
    // Body
    if (vlSelf->ap_rst_n) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__maxcount_reg 
            = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__count) 
                > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__maxcount_reg))
                ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__count)
                : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__maxcount_reg));
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter5_fsm;
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__maxcount_reg = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm = 1U;
    }
    vlSelf->maxcount_5 = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__maxcount_reg;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1_out_V_TVALID 
        = (1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_1__DOT__inst__DOT__impl__DOT__core__DOT__genUp__DOT__ACnt) 
                 >> 4U));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__count 
        = (0x3ffU & ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__state))
                      ? ((IData)(2U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__addr))
                      : ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__state))
                          ? 1U : 0U)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__i_b_reg 
        = ((IData)(vlSelf->ap_rst_n) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__addr_full_));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x30eU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_5__DOT__inst__DOT__impl__DOT__addr_)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x30feU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__addr_)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_sel_rd)
            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_payload_B)
            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_payload_A));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mac_muladd_8s_4s_15s_15_4_1_U2__DOT__MVAU_hls_0_mac_muladd_8s_4s_15s_15_4_1_DSP48_0_U__DOT__p 
        = (0xffffffffffffULL & (VL_EXTENDS_QQ(48,43, vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mac_muladd_8s_4s_15s_15_4_1_U2__DOT__MVAU_hls_0_mac_muladd_8s_4s_15s_15_4_1_DSP48_0_U__DOT__m_reg) 
                                + VL_EXTENDS_QI(48,15, 
                                                ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__icmp_ln272_reg_1630_pp0_iter2_reg)
                                                  ? 0U
                                                  : 
                                                 (0x7fffU 
                                                  & ((IData)(
                                                             (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm) 
                                                               >> 1U) 
                                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__icmp_ln249_reg_1577_pp0_iter3_reg))))
                                                      ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mac_muladd_8s_4s_15s_15_4_1_U2__DOT__MVAU_hls_0_mac_muladd_8s_4s_15s_15_4_1_DSP48_0_U__DOT__p_reg)
                                                      : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__add_i4_i338_fu_144)))))));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__12(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__12\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__window_buffer_inst__DOT__Out;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 1U;
        } else {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 0U;
        }
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state))) {
        if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID) 
             & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                   >> 1U)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0__DOT__inst__DOT__impl__DOT__window_buffer_inst__DOT__Out;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID)) 
                          & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                                >> 1U))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID)) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_full) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ 
                = (1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                         >> 1U));
            if ((2U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ 
                    = ((0x52aeU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr))
                        ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srl
                       [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr]
                        : 0U);
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x7fffU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x7fffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr) 
                                      - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x7fffU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID) 
                    & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                          >> 1U)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                = (0x7fffU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x52aeU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID)) 
                          & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                                >> 1U))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_0_out_V_TVALID)) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x52aeU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x7fffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr) 
                                  - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__43(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__43\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs2) 
           & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state) 
                 >> 1U)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__13(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__13\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x52aeU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_3__DOT__inst__DOT__impl__DOT__addr_)));
}

extern const VlUnpacked<CData/*1:0*/, 128> Vfinn_design_wrapper__ConstPool__TABLE_h760de937_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0;
extern const VlUnpacked<CData/*3:0*/, 256> Vfinn_design_wrapper__ConstPool__TABLE_h4f1a5408_0;

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__44(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__44\n"); );
    // Init
    CData/*7:0*/ __Vtableidx3;
    CData/*6:0*/ __Vtableidx4;
    CData/*6:0*/ __Vtableidx5;
    CData/*6:0*/ __Vtableidx6;
    CData/*6:0*/ __Vtableidx7;
    CData/*6:0*/ __Vtableidx8;
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__en 
        = (1U & (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure)) 
                  | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rb1)) 
                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__rollback 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure) 
           & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rb1) 
              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__rollback)
            ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
           [2U] : vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
           [0U]);
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_nxt 
        = ((0x3feU & ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff) 
                        >> 1U) + ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                                   ? 0U : ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                            ? 0x51U
                                            : 1U))) 
                      << 1U)) | (1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                                        ? (1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                        : ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                            ? 0U : 
                                           (0x1aeU 
                                            == (0x1ffU 
                                                & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff) 
                                                   >> 1U)))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm) 
            & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_loop_init))
            ? 0U : vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__sf_fu_136);
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_275_8_1_1_U1__DOT__mux_5_0 
        = ((0x10U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
            ? ((8U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                ? ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_26_fu_252)
                    : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_25_fu_248)
                        : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_24_fu_244)))
                : ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_23_fu_240)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_22_fu_236))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_21_fu_232)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_20_fu_228)))
                    : ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_19_fu_224)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_18_fu_220))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_17_fu_216)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_16_fu_212)))))
            : ((8U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                ? ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_15_fu_208)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_14_fu_204))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_13_fu_200)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_12_fu_196)))
                    : ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_11_fu_192)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_10_fu_188))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_9_fu_184)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_8_fu_180))))
                : ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_7_fu_176)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_6_fu_172))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_5_fu_168)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_4_fu_164)))
                    : ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_3_fu_160)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_2_fu_156))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_1_fu_152)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_fu_148))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TVALID 
        = (((~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
               >> 1U)) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__grp_fu_1358_ce 
        = (1U & (((((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                         >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                   | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                      & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm) 
                       >> 1U)) | ((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                       >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                 | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm) 
                                     >> 1U))) | ((~ 
                                                  (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                    >> 1U) 
                                                   & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                      | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                                         & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                                                 & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm) 
                                                    >> 1U))) 
                 | ((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                         >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                   | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                      & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm) 
                       >> 1U))));
    __Vtableidx8 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                              << 5U)) | ((0x20U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm) 
                                                   << 4U)) 
                                         | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                             << 4U) 
                                            | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                                << 3U) 
                                               | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                   << 2U) 
                                                  | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter6_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h760de937_0
        [__Vtableidx8];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_condition_exit_pp0_iter0_stage0 
        = (((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                  | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                     & (0x52b00U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                 | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                    >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                              | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                 & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
            & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)) 
           & (0x52b00U == vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1));
    __Vtableidx4 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm) 
                              << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                          << 5U) | 
                                         (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                           << 4U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                            << 3U) 
                                           | ((4U & 
                                               ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                << 1U)) 
                                              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter2_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx4];
    __Vtableidx5 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm) 
                              << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                          << 5U) | 
                                         (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                           << 4U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                            << 3U) 
                                           | ((4U & 
                                               ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                << 1U)) 
                                              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter3_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx5];
    __Vtableidx6 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm) 
                              << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                          << 5U) | 
                                         (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                           << 4U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                            << 3U) 
                                           | ((4U & 
                                               ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                << 1U)) 
                                              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter4_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx6];
    __Vtableidx7 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm) 
                              << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                          << 5U) | 
                                         (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                           << 4U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                            << 3U) 
                                           | ((4U & 
                                               ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                << 1U)) 
                                              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter5_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx7];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_condition_1254 
        = ((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                 | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                    & (0x52b00U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
               | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                             | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__in0_V_TREADY_int_regslice 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__ap_CS_fsm) 
            >> 2U) & (((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                             | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                & (0x52b00U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                            | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                               & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                               >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                         | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                            & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                       & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1)) 
                      & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__weights_V_TREADY_int_regslice 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__ap_CS_fsm) 
            >> 2U) & (((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                             | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                & (0x52b00U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                            | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                               & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                               >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                         | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                            & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                       & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)) 
                      & (0x52b00U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter1_fsm 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm))
            ? ((((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                      >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                 & (~ (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                        | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                           & (0x52b00U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                       | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))))) 
                & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm))
                ? 2U : ((1U & ((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                    >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                              | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                                 & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                               & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)) 
                                  | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm) 
                                     & (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                                         | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                            & (0x52b00U 
                                               != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                                        | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                                           & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))))))
                         ? 1U : 2U)) : ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm))
                                         ? (((~ (((
                                                   (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                                                   | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                                      & (0x52b00U 
                                                         != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                                                  | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op89_read_state1) 
                                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                                                 | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                     >> 1U) 
                                                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                       | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                                                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm))
                                             ? 2U : 1U)
                                         : 0U));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_done_int 
        = ((((~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                 | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op304_write_state7) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))) 
             & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                >> 1U)) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_loop_exit_ready_pp0_iter6_reg)) 
           | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_done_reg));
    __Vtableidx3 = ((0x80U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__ap_CS_fsm) 
                              << 5U)) | ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_done_int) 
                                           | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__flow_control_loop_pipe_sequential_init_U__DOT__ap_done_cache) 
                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)))) 
                                          << 6U) | 
                                         (((((3U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_4__DOT__inst__DOT__impl__DOT__i_b_reg)) 
                                            | (1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state))) 
                                           << 5U) | 
                                          ((0x10U & 
                                            ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__ap_CS_fsm) 
                                             << 1U)) 
                                           | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__ap_CS_fsm)))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_0__DOT__MVAU_hls_0__DOT__inst__DOT__ap_NS_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h4f1a5408_0
        [__Vtableidx3];
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__45(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__45\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_sel_wr 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_sel_wr;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__result_V_2_fu_3171_p2 
        = (0xfU & (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__add_ln840_12_reg_4313) 
                    + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__add_ln840_9_reg_4308)) 
                   + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__add_ln840_6_reg_4303)));
    if (vlSelf->ap_rst_n) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter5_fsm;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter3_fsm;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter2_fsm;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter1_fsm;
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm = 1U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm = 1U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm = 1U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm = 1U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_we = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_if__DOT__ip_wdata_wide = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_sel_rd 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_sel_rd;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_data_out 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_sel_rd)
            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_payload_B)
            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_payload_A));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_ce = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mac_muladd_4ns_4s_14s_14_4_1_U2__DOT__MVAU_hls_1_mac_muladd_4ns_4s_14s_14_4_1_DSP48_0_U__DOT__p 
        = (0xffffffffffffULL & (VL_EXTENDS_QQ(48,43, vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mac_muladd_4ns_4s_14s_14_4_1_U2__DOT__MVAU_hls_1_mac_muladd_4ns_4s_14s_14_4_1_DSP48_0_U__DOT__m_reg) 
                                + VL_EXTENDS_QI(48,14, 
                                                ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__icmp_ln272_reg_4129_pp0_iter2_reg)
                                                  ? 0U
                                                  : 
                                                 (0x3fffU 
                                                  & ((IData)(
                                                             (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm) 
                                                               >> 1U) 
                                                              & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__icmp_ln249_reg_4103_pp0_iter3_reg))))
                                                      ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mac_muladd_4ns_4s_14s_14_4_1_U2__DOT__MVAU_hls_1_mac_muladd_4ns_4s_14s_14_4_1_DSP48_0_U__DOT__p_reg)
                                                      : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__add_i4_i338_fu_378)))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_sel_wr 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_sel_wr;
    if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__en) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Data2 
            = ((0x11ffU >= (0x1fffU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
                                       [1U] >> 1U)))
                ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem
               [(0x1fffU & (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
                            [1U] >> 1U))] : 0U);
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[0U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v1) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v2) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[1U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v2;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v3) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[1U] = 0U;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v4) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[2U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v4;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v5) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[2U] = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__icmp_ln290_reg_4134_pp0_iter5_reg) 
           & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__icmp_ln249_reg_4103_pp0_iter5_reg)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__14(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__14\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TDATA;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 1U;
        } else {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 0U;
        }
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state))) {
        if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID) 
             & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                   >> 1U)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TDATA;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID)) 
                          & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                                >> 1U))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID)) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_full) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ 
                = (1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                         >> 1U));
            if ((2U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ 
                    = ((0x6e3eU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr))
                        ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srl
                       [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr]
                        : 0U);
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x7fffU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x7fffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr) 
                                      - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x7fffU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID) 
                    & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                          >> 1U)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                = (0x7fffU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x6e3eU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID)) 
                          & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                                >> 1U))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__ConvolutionInputGenerator_rtl_1_out_V_TVALID)) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state) 
                       >> 1U))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ 
                = ((0x6e3eU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr))
                    ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srl
                   [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr]
                    : 0U);
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x7fffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr) 
                                  - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__srlo_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__46(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__46\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs2) 
           & (~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state) 
                 >> 1U)));
    if (vlSelf->ap_rst_n) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter6_fsm;
        if ((2U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg = 1U;
        } else if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_condition_exit_pp0_iter0_stage0) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg = 0U;
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm = 1U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm 
        = (1U & ((~ (IData)(vlSelf->ap_rst_n)) | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter0_fsm)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__15(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__15\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x6e3eU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_9__DOT__inst__DOT__impl__DOT__addr_)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__47(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__47\n"); );
    // Init
    CData/*3:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0;
    CData/*3:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1;
    CData/*3:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2;
    CData/*3:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3;
    CData/*7:0*/ __Vtableidx12;
    CData/*6:0*/ __Vtableidx13;
    CData/*6:0*/ __Vtableidx14;
    CData/*6:0*/ __Vtableidx15;
    CData/*6:0*/ __Vtableidx16;
    CData/*6:0*/ __Vtableidx17;
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__en 
        = (1U & (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure)) 
                  | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rb1)) 
                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_ce)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__rollback 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure) 
           & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rb1) 
              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_ce)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter0_fsm 
        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__rollback)
            ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
           [2U] : vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
           [0U]);
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm 
        = ((IData)(vlSelf->ap_rst_n) ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_NS_fsm)
            : 1U);
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_loop_init 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__flow_control_loop_pipe_sequential_init_U__DOT__ap_loop_init_int) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_nxt 
        = ((0x3ffeU & ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff) 
                         >> 1U) + ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                                    ? 0U : ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                             ? 0xe01U
                                             : 1U))) 
                       << 1U)) | (1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                                         ? (1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                         : ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                             ? 0U : 
                                            (0x11feU 
                                             == (0x1fffU 
                                                 & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff) 
                                                    >> 1U)))))));
    if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm) 
         & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_loop_init))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_nf_2 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1 = 0U;
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_nf_2 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__nf_1_fu_958;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__i_fu_374;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__sf_fu_370;
    }
    if ((0x10U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
        if ((8U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            if ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                    if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_31_fu_506;
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_63_fu_634;
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_95_fu_762;
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_127_fu_890;
                    } else {
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_30_fu_502;
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_62_fu_630;
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_94_fu_758;
                        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_126_fu_886;
                    }
                } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_29_fu_498;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_61_fu_626;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_93_fu_754;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_125_fu_882;
                } else {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_28_fu_494;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_60_fu_622;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_92_fu_750;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_124_fu_878;
                }
            } else if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_27_fu_490;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_59_fu_618;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_91_fu_746;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_123_fu_874;
                } else {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_26_fu_486;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_58_fu_614;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_90_fu_742;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_122_fu_870;
                }
            } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_25_fu_482;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_57_fu_610;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_89_fu_738;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_121_fu_866;
            } else {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_24_fu_478;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_56_fu_606;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_88_fu_734;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_120_fu_862;
            }
        } else if ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_23_fu_474;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_55_fu_602;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_87_fu_730;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_119_fu_858;
                } else {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_22_fu_470;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_54_fu_598;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_86_fu_726;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_118_fu_854;
                }
            } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_21_fu_466;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_53_fu_594;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_85_fu_722;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_117_fu_850;
            } else {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_20_fu_462;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_52_fu_590;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_84_fu_718;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_116_fu_846;
            }
        } else if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_19_fu_458;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_51_fu_586;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_83_fu_714;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_115_fu_842;
            } else {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_18_fu_454;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_50_fu_582;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_82_fu_710;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_114_fu_838;
            }
        } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_17_fu_450;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_49_fu_578;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_81_fu_706;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_113_fu_834;
        } else {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_16_fu_446;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_48_fu_574;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_80_fu_702;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_112_fu_830;
        }
    } else if ((8U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
        if ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_15_fu_442;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_47_fu_570;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_79_fu_698;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_111_fu_826;
                } else {
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_14_fu_438;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_46_fu_566;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_78_fu_694;
                    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_110_fu_822;
                }
            } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_13_fu_434;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_45_fu_562;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_77_fu_690;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_109_fu_818;
            } else {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_12_fu_430;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_44_fu_558;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_76_fu_686;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_108_fu_814;
            }
        } else if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_11_fu_426;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_43_fu_554;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_75_fu_682;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_107_fu_810;
            } else {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_10_fu_422;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_42_fu_550;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_74_fu_678;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_106_fu_806;
            }
        } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_9_fu_418;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_41_fu_546;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_73_fu_674;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_105_fu_802;
        } else {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_8_fu_414;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_40_fu_542;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_72_fu_670;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_104_fu_798;
        }
    } else if ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
        if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_7_fu_410;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_39_fu_538;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_71_fu_666;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_103_fu_794;
            } else {
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_6_fu_406;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_38_fu_534;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_70_fu_662;
                finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_102_fu_790;
            }
        } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_5_fu_402;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_37_fu_530;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_69_fu_658;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_101_fu_786;
        } else {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_4_fu_398;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_36_fu_526;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_68_fu_654;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_100_fu_782;
        }
    } else if ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
        if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_3_fu_394;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_35_fu_522;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_67_fu_650;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_99_fu_778;
        } else {
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_2_fu_390;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_34_fu_518;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_66_fu_646;
            finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_98_fu_774;
        }
    } else if ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)) {
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_1_fu_386;
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_33_fu_514;
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_65_fu_642;
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_97_fu_770;
    } else {
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_fu_382;
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_32_fu_510;
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_64_fu_638;
        finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_96_fu_766;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1 
        = ((0U == vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_nf_2) 
           & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY 
        = (IData)((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm) 
                              >> 2U)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_8_0 
        = ((0x80U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
            ? ((8U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                ? ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_143_fu_954)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_142_fu_950))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_141_fu_946)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_140_fu_942)))
                    : ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_139_fu_938)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_138_fu_934))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_137_fu_930)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_136_fu_926))))
                : ((4U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_135_fu_922)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_134_fu_918))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_133_fu_914)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_132_fu_910)))
                    : ((2U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                        ? ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_131_fu_906)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_130_fu_902))
                        : ((1U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                            ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_129_fu_898)
                            : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__inputBuf_V_128_fu_894)))))
            : ((0x40U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                ? ((0x20U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? (IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_3)
                    : (IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_2))
                : ((0x20U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_sf_1)
                    ? (IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_1)
                    : (IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__mux_1448_4_1_1_U1__DOT__mux_5_0))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
           & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TVALID 
        = (((~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))) 
            & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
               >> 1U)) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__grp_fu_3182_ce 
        = (1U & (((((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                         >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                   | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                      & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm) 
                       >> 1U)) | ((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                       >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                 | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm) 
                                     >> 1U))) | ((~ 
                                                  (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                    >> 1U) 
                                                   & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                      | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                                         & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                                                 & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm) 
                                                    >> 1U))) 
                 | ((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                         >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                   | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                      & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm) 
                       >> 1U))));
    __Vtableidx17 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                               << 5U)) | ((0x20U & 
                                           ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm) 
                                            << 4U)) 
                                          | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                              << 4U) 
                                             | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                                 << 3U) 
                                                | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                    << 2U) 
                                                   | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter6_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h760de937_0
        [__Vtableidx17];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_condition_exit_pp0_iter0_stage0 
        = (((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                  | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                     & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                 | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                    >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                              | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                 & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
            & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)) 
           & (0xdc800U == vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1));
    __Vtableidx13 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm) 
                               << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                           << 5U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                            << 4U) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                               << 3U) 
                                              | ((4U 
                                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter2_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx13];
    __Vtableidx14 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter2_fsm) 
                               << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                           << 5U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                            << 4U) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                               << 3U) 
                                              | ((4U 
                                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter3_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx14];
    __Vtableidx15 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter3_fsm) 
                               << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                           << 5U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                            << 4U) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                               << 3U) 
                                              | ((4U 
                                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter4_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx15];
    __Vtableidx16 = ((0x40U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter4_fsm) 
                               << 5U)) | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY) 
                                           << 5U) | 
                                          (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                            << 4U) 
                                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                               << 3U) 
                                              | ((4U 
                                                  & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                     << 1U)) 
                                                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter5_fsm))))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter5_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h7621a6e4_0
        [__Vtableidx16];
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_condition_2547 
        = ((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                 | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                    & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
               | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                   >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                             | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__in0_V_TREADY_int_regslice 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm) 
            >> 2U) & (((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                             | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                            | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                               & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                               >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                         | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                            & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                       & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1)) 
                      & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__weights_V_TREADY_int_regslice 
        = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm) 
            >> 2U) & (((~ ((((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                             | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                            | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                               & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                           | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                               >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                         | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                            & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                       & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)) 
                      & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_NS_iter1_fsm 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm))
            ? ((((~ (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                      | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                         & (0xdc800U != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                     | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                        & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))) 
                 & (~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                        >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                  | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm))
                ? 2U : ((1U & ((~ (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                    >> 1U) & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                              | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                                 & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY)))))) 
                               & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm)) 
                                  | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm) 
                                     & (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                                         | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                            & (0xdc800U 
                                               != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                                        | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                                           & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state))))))))
                         ? 1U : 2U)) : ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter1_fsm))
                                         ? (((~ (((
                                                   (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)) 
                                                   | ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_weights_V_U__DOT__B_V_data_1_state)) 
                                                      & (0xdc800U 
                                                         != vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_sig_allocacmp_i_1))) 
                                                  | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op323_read_state1) 
                                                     & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_in0_V_U__DOT__B_V_data_1_state)))) 
                                                 | (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                                                     >> 1U) 
                                                    & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                                                       | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                                                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))))) 
                                             & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter0_fsm))
                                             ? 2U : 1U)
                                         : 0U));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_done_int 
        = ((((~ ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_block_state7_io) 
                 | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_predicate_op774_write_state7) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_out_V_TREADY))))) 
             & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_CS_iter6_fsm) 
                >> 1U)) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_loop_exit_ready_pp0_iter6_reg)) 
           | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_done_reg));
    __Vtableidx12 = ((0x80U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm) 
                               << 5U)) | ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__ap_done_int) 
                                            | ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60__DOT__flow_control_loop_pipe_sequential_init_U__DOT__ap_done_cache) 
                                               & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__grp_Matrix_Vector_Activate_Stream_Batch_fu_60_ap_start_reg)))) 
                                           << 6U) | 
                                          (((((3U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                                              & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_10__DOT__inst__DOT__impl__DOT__i_b_reg)) 
                                             | (1U 
                                                == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state))) 
                                            << 5U) 
                                           | ((0x10U 
                                               & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm) 
                                                  << 1U)) 
                                              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_CS_fsm)))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_hls_1__DOT__MVAU_hls_1__DOT__inst__DOT__ap_NS_fsm 
        = Vfinn_design_wrapper__ConstPool__TABLE_h4f1a5408_0
        [__Vtableidx12];
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__48(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__48\n"); );
    // Body
    if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2eU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2eU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2eU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2eU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2fU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2fU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2fU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2fU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2dU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2dU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2dU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2dU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2eU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2eU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2eU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2eU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2cU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2cU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2cU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2cU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2dU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2dU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2dU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2dU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2bU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2bU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2bU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2bU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2cU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2cU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2cU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2cU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2aU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2aU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2aU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x2aU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2bU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2bU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2bU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2bU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x29U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x29U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x29U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x29U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2aU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2aU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2aU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x2aU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x28U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x28U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x28U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x28U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x29U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x29U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x29U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x29U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x27U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x27U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x27U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x27U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x28U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x28U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x28U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x28U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x26U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x26U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x26U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x26U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x27U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x27U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x27U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x27U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x25U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x25U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x25U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x25U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x26U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x26U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x26U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x26U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x24U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x24U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x24U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x24U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x25U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x25U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x25U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x25U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x23U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x23U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x23U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x23U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x24U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x24U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x24U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x24U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x22U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x22U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x22U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x22U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x23U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x23U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x23U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x23U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x21U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x21U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x21U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x21U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x22U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x22U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x22U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x22U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x20U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x20U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x20U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x20U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x21U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x21U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x21U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x21U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1fU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1fU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1fU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1fU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x20U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x20U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x20U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x20U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1eU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1eU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1eU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1eU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1fU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1fU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1fU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1fU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1dU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1dU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1dU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1dU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1eU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1eU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1eU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1eU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1cU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1cU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1cU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1cU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1dU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1dU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1dU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1dU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1bU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1bU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1bU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1bU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1cU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1cU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1cU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1cU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1aU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1aU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1aU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x1aU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1bU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1bU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1bU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1bU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x19U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x19U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x19U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x19U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1aU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1aU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1aU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x1aU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x18U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x18U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x18U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x18U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x19U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x19U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x19U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x19U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x17U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x17U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x17U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x17U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x18U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x18U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x18U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x18U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x16U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x16U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x16U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x16U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x17U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x17U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x17U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x17U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x15U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x15U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x15U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x15U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x16U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x16U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x16U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x16U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x14U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x14U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x14U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x14U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x15U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x15U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x15U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x15U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x13U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x13U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x13U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x13U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x14U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x14U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x14U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x14U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x12U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x12U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x12U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x12U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x13U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x13U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x13U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x13U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x11U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x11U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x11U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x11U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x12U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x12U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x12U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x12U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x10U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x10U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x10U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0x10U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x11U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x11U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x11U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x11U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xfU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xfU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xfU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xfU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x10U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x10U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x10U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0x10U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xeU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xeU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xeU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xeU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xfU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xfU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xfU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xfU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xdU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xdU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xdU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xdU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xeU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xeU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xeU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xeU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xcU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xcU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xcU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xcU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xdU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xdU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xdU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xdU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xbU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xbU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xbU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xbU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xcU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xcU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xcU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xcU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xaU][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xaU][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xaU][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0xaU][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xbU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xbU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xbU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xbU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [9U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [9U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [9U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [9U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xaU][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xaU][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xaU][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0xaU][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [8U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [8U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [8U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [8U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[9U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[9U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[9U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[9U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [7U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [7U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [7U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [7U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[8U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[8U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[8U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[8U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [6U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [6U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [6U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [6U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[7U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[7U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[7U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[7U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [5U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [5U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [5U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [5U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[6U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[6U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[6U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[6U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [4U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [4U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [4U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [4U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[5U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[5U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[5U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[5U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [3U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [3U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [3U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [3U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[4U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[4U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[4U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[4U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [2U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [2U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [2U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [2U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[3U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[3U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[3U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[3U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [1U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [1U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [1U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [1U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[2U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[2U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[2U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[2U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0U][0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0U][1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0U][2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
            [0U][3U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[1U][0U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[1U][1U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[1U][2U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[1U][3U] 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT____Vlvbound_h01e5a1b5__0[3U];
    }
    if (vlSelf->ap_rst_n) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__i_b_reg 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_full_;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__maxcount_reg 
            = (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__count) 
                > (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__maxcount_reg))
                ? (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__count)
                : (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__maxcount_reg));
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__en) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Data1 
                = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                    ? (0xffU & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_if__DOT__ip_wdata_wide)
                    : 0U);
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__i_b_reg = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__maxcount_reg = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Data1 = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__blkRep__DOT__RepLst 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__blkRep__DOT__RepLst;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__blkRep__DOT__RepCnt 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__blkRep__DOT__RepCnt;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk3__DOT__Count 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk3__DOT__Count;
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage2__DOT__Mem__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0U][0U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl__v0[0U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0U][1U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl__v0[1U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0U][2U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl__v0[2U];
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl[0U][3U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl__v0[3U];
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[0U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v0;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v1) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[0U] = 0U;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v2) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[1U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v2;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v3) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[1U] = 0U;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v4) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[2U] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v4;
    }
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr__v5) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr[2U] = 0U;
    }
    vlSelf->maxcount_14 = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__maxcount_reg;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__count 
        = (0xfU & ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state))
                    ? ((IData)(2U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr))
                    : ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state))
                        ? 1U : 0U)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__i_b_reg 
        = ((IData)(vlSelf->ap_rst_n) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_full_));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__wr 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__o_v_reg));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk3__DOT__Last 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk3__DOT__Last;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__L 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__L;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 1U;
        } else {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 0U;
        }
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state))) {
        if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
             & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_full) {
            if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x7ffU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0x7ffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr) 
                                     - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x7ffU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
                    & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY)))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                = (0x7ffU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingDataWidthConverter_rtl_4__DOT__inst__DOT__impl__DOT__core__DOT__genDown__DOT__CVld)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__in0_V_1_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 1U;
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0x7ffU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr) 
                                 - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__shift_en_o_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__16(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__16\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ 
            = ((0x1000000U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B)
                ? 1U : 0U);
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state))) {
        if ((IData)(((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                      >> 0x18U) & (~ (IData)(vlSelf->m_axis_0_tready))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                     >> 0x18U) & (IData)(vlSelf->m_axis_0_tready))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if ((1U & ((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                              >> 0x18U)) & (~ (IData)(vlSelf->m_axis_0_tready))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        } else if (((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                        >> 0x18U)) & (IData)(vlSelf->m_axis_0_tready))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_full) {
            if (vlSelf->m_axis_0_tready) {
                if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 1U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0xfU & 0U);
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                        = (0xfU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr) 
                                   - (IData)(1U)));
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0xfU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr));
            }
        } else if ((IData)(((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                             >> 0x18U) & (~ (IData)(vlSelf->m_axis_0_tready))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                = (0xfU & ((IData)(1U) + (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr)));
        } else if (((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                     >> 0x18U) & (IData)(vlSelf->m_axis_0_tready))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr;
        } else if ((1U & ((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                              >> 0x18U)) & (~ (IData)(vlSelf->m_axis_0_tready))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr;
        } else if (((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                        >> 0x18U)) & (IData)(vlSelf->m_axis_0_tready))) {
            if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 1U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 2U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ 
                    = (0xfU & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr) 
                               - (IData)(1U)));
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_ = 0U;
    }
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__49(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__49\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__b_load 
        = (1U & ((~ (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__B 
                     >> 0x18U)) | (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__i_b_reg))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__state_)) 
           & (0x61eU == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_13__DOT__inst__DOT__impl__DOT__addr_)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_we = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_if__DOT__ip_wdata_wide = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
    if ((0U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state))) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        if ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[0U];
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[1U];
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[2U];
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[3U];
        } else {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
        }
    } else if ((1U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state))) {
        if ((1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                   & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[0U];
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[1U];
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[2U];
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_data_out[3U];
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
        }
    } else if ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__state))) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__i_b_reg) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY) {
                if ((0x2fU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr))) {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                        [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][0U];
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                        [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][1U];
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                        [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][2U];
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] 
                        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                        [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][3U];
                } else {
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
                    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
                }
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
            }
        } else if ((1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
        } else if (((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 1U;
            if ((0x2fU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][0U];
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][1U];
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][2U];
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][3U];
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
            }
        } else if ((1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                          & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
        } else if (((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingMaxPool_hls_1__DOT__inst__DOT__regslice_both_out_V_U__DOT__B_V_data_1_state)) 
                    & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12_out_V_TREADY))) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
            if ((0x2fU >= (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][0U];
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][1U];
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][2U];
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] 
                    = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srl
                    [vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__addr][3U];
            } else {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__shift_en_ = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[0U] = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[1U] = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[2U] = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_12__DOT__inst__DOT__impl__DOT__srlo_[3U] = 0U;
    }
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___combo__TOP__17(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___combo__TOP__17\n"); );
    // Body
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_full_ 
        = ((2U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__state_)) 
           & (8U == (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__StreamingFIFO_rtl_14__DOT__inst__DOT__impl__DOT__addr_)));
}

VL_INLINE_OPT void Vfinn_design_wrapper___024root___sequent__TOP__50(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___sequent__TOP__50\n"); );
    // Init
    CData/*0:0*/ finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure;
    // Body
    if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__rd) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__ODat 
            = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__Mem
            [(0x7ffU & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__RP))];
    }
    if (vlSelf->ap_rst_n) {
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__rd) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__OVld 
                = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__vld;
        }
        if ((0x1000000U & vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__A)) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genblk2__BRA__3__KET____DOT__genLo__DOT__Lo4 
                = (0xffffffU & (IData)((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__p3
                                        [0U] >> 0x15U)));
        }
        if (vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__en) {
            vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs1 = 0U;
            if ((1U & (~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)))) {
                vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs1 = 1U;
            }
        }
    } else {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__OVld = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genblk2__BRA__3__KET____DOT__genLo__DOT__Lo4 = 0U;
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs1 = 0U;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__p3[0U] 
        = vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__blkDsp__DOT__genblk2__DOT__core__DOT__genPipes__BRA__0__KET____DOT__genSIMD__BRA__0__KET____DOT__genBehav__DOT__P3;
    if (vlSelf->__Vdlyvset__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__Mem__v0) {
        vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__Mem[vlSelf->__Vdlyvdim0__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__Mem__v0] 
            = vlSelf->__Vdlyvval__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__Mem__v0;
    }
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__RP 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__RP;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__A 
        = vlSelf->__Vdly__finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__A;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__vld 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__RP) 
           != (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__WP));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__rd 
        = (1U & ((~ (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__OVld)) 
                 | ((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__A 
                     >> 0x18U) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs2))));
    finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rs2) 
           & (~ ((vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__A 
                  >> 0x18U) & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__OVld))));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__shift 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__rd) 
           & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0__DOT__inst__DOT__inst__DOT__activation_replay__DOT__genblk4__DOT__vld));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce = 0U;
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__en 
        = (1U & (((~ (IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure)) 
                  | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rb1)) 
                 | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__rollback 
        = ((IData)(finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__backpressure) 
           & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Rb1) 
              | (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)));
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff 
        = ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__rollback)
            ? vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
           [2U] : vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__Ptr
           [0U]);
    vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_nxt 
        = ((0x7ffeU & ((((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff) 
                         >> 1U) + ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                                    ? 0U : ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                             ? 0x2c1U
                                             : 1U))) 
                       << 1U)) | (1U & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__config_ce)
                                         ? (1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                         : ((1U & (IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff))
                                             ? 0U : 
                                            (0x3d3eU 
                                             == (0x3fffU 
                                                 & ((IData)(vlSelf->finn_design_wrapper__DOT__finn_design_i__DOT__MVAU_rtl_0__DOT__MVAU_rtl_0_wstrm__DOT__inst__DOT__core__DOT__mem__DOT__blkStage1__DOT__ptr_eff) 
                                                    >> 1U)))))));
}

#ifdef VL_DEBUG
void Vfinn_design_wrapper___024root___eval_debug_assertions(Vfinn_design_wrapper___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vfinn_design_wrapper__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vfinn_design_wrapper___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->ap_clk & 0xfeU))) {
        Verilated::overWidthError("ap_clk");}
    if (VL_UNLIKELY((vlSelf->ap_rst_n & 0xfeU))) {
        Verilated::overWidthError("ap_rst_n");}
    if (VL_UNLIKELY((vlSelf->m_axis_0_tready & 0xfeU))) {
        Verilated::overWidthError("m_axis_0_tready");}
    if (VL_UNLIKELY((vlSelf->s_axis_0_tdata & 0xff000000U))) {
        Verilated::overWidthError("s_axis_0_tdata");}
    if (VL_UNLIKELY((vlSelf->s_axis_0_tvalid & 0xfeU))) {
        Verilated::overWidthError("s_axis_0_tvalid");}
}
#endif  // VL_DEBUG
