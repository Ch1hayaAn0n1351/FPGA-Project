// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard__pch.h"
#include "VDevelopmentBoard__Syms.h"
#include "VDevelopmentBoard___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__ico(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG

void VDevelopmentBoard___024root___eval_triggers__ico(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDevelopmentBoard___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__act(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG

void VDevelopmentBoard___024root___eval_triggers__act(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__1)));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__1)));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__1)));
    vlSelf->__VactTriggered.set(3U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__1)));
    vlSelf->__VactTriggered.set(4U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((~ (IData)(vlSelf->reset)) 
                                        & (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0))));
    vlSelf->__VactTriggered.set(5U, (1U & (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num 
                                           & (~ (IData)(vlSelf->__Vtrigprevexpr_hc9ffefd5__0)))));
    vlSelf->__VactTriggered.set(6U, (1U & (((~ (IData)(vlSelf->reset)) 
                                            & (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0)) 
                                           | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num 
                                              & (~ (IData)(vlSelf->__Vtrigprevexpr_hc9ffefd5__0))))));
    vlSelf->__VactTriggered.set(7U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(8U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock__0))));
    vlSelf->__VactTriggered.set(9U, (1U & ((((IData)(vlSelf->clk) 
                                             & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                            | ((~ (IData)(vlSelf->reset)) 
                                               & (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0))) 
                                           | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num 
                                              & (~ (IData)(vlSelf->__Vtrigprevexpr_hc9ffefd5__0))))));
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__1 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__1 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__1 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__1 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY;
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
    vlSelf->__Vtrigprevexpr_hc9ffefd5__0 = (1U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VactDidInit))))) {
        vlSelf->__VactDidInit = 1U;
        vlSelf->__VactTriggered.set(0U, 1U);
        vlSelf->__VactTriggered.set(1U, 1U);
        vlSelf->__VactTriggered.set(2U, 1U);
        vlSelf->__VactTriggered.set(3U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDevelopmentBoard___024root___dump_triggers__act(vlSelf);
    }
#endif
}
