// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vfinn_design_wrapper.h"
#include "Vfinn_design_wrapper__Syms.h"

//============================================================
// Constructors

Vfinn_design_wrapper::Vfinn_design_wrapper(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vfinn_design_wrapper__Syms(_vcontextp__, _vcname__, this)}
    , ap_clk{vlSymsp->TOP.ap_clk}
    , ap_rst_n{vlSymsp->TOP.ap_rst_n}
    , m_axis_0_tvalid{vlSymsp->TOP.m_axis_0_tvalid}
    , s_axis_0_tready{vlSymsp->TOP.s_axis_0_tready}
    , maxcount{vlSymsp->TOP.maxcount}
    , maxcount_13{vlSymsp->TOP.maxcount_13}
    , m_axis_0_tdata{vlSymsp->TOP.m_axis_0_tdata}
    , maxcount_14{vlSymsp->TOP.maxcount_14}
    , maxcount_12{vlSymsp->TOP.maxcount_12}
    , maxcount_1{vlSymsp->TOP.maxcount_1}
    , maxcount_2{vlSymsp->TOP.maxcount_2}
    , maxcount_4{vlSymsp->TOP.maxcount_4}
    , m_axis_0_tready{vlSymsp->TOP.m_axis_0_tready}
    , s_axis_0_tvalid{vlSymsp->TOP.s_axis_0_tvalid}
    , maxcount_3{vlSymsp->TOP.maxcount_3}
    , maxcount_6{vlSymsp->TOP.maxcount_6}
    , maxcount_10{vlSymsp->TOP.maxcount_10}
    , maxcount_7{vlSymsp->TOP.maxcount_7}
    , s_axis_0_tdata{vlSymsp->TOP.s_axis_0_tdata}
    , maxcount_5{vlSymsp->TOP.maxcount_5}
    , maxcount_8{vlSymsp->TOP.maxcount_8}
    , maxcount_11{vlSymsp->TOP.maxcount_11}
    , maxcount_9{vlSymsp->TOP.maxcount_9}
    , rootp{&(vlSymsp->TOP)}
{
}

Vfinn_design_wrapper::Vfinn_design_wrapper(const char* _vcname__)
    : Vfinn_design_wrapper(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vfinn_design_wrapper::~Vfinn_design_wrapper() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vfinn_design_wrapper___024root___eval_initial(Vfinn_design_wrapper___024root* vlSelf);
void Vfinn_design_wrapper___024root___eval_settle(Vfinn_design_wrapper___024root* vlSelf);
void Vfinn_design_wrapper___024root___eval(Vfinn_design_wrapper___024root* vlSelf);
#ifdef VL_DEBUG
void Vfinn_design_wrapper___024root___eval_debug_assertions(Vfinn_design_wrapper___024root* vlSelf);
#endif  // VL_DEBUG
void Vfinn_design_wrapper___024root___final(Vfinn_design_wrapper___024root* vlSelf);

static void _eval_initial_loop(Vfinn_design_wrapper__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vfinn_design_wrapper___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vfinn_design_wrapper___024root___eval_settle(&(vlSymsp->TOP));
        Vfinn_design_wrapper___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vfinn_design_wrapper::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vfinn_design_wrapper::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vfinn_design_wrapper___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vfinn_design_wrapper___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Utilities

VerilatedContext* Vfinn_design_wrapper::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vfinn_design_wrapper::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vfinn_design_wrapper::final() {
    Vfinn_design_wrapper___024root___final(&(vlSymsp->TOP));
}
