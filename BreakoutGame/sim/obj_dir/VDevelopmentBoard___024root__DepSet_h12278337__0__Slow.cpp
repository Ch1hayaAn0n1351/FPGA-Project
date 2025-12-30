// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard__pch.h"
#include "VDevelopmentBoard__Syms.h"
#include "VDevelopmentBoard___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__stl(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_triggers__stl(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
    vlSelf->__VstlTriggered.set(1U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__0)));
    vlSelf->__VstlTriggered.set(2U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__0)));
    vlSelf->__VstlTriggered.set(3U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__0)));
    vlSelf->__VstlTriggered.set(4U, ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY) 
                                     != (IData)(vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__0)));
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY;
    if (VL_UNLIKELY((1U & (~ (IData)(vlSelf->__VstlDidInit))))) {
        vlSelf->__VstlDidInit = 1U;
        vlSelf->__VstlTriggered.set(1U, 1U);
        vlSelf->__VstlTriggered.set(2U, 1U);
        vlSelf->__VstlTriggered.set(3U, 1U);
        vlSelf->__VstlTriggered.set(4U, 1U);
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VDevelopmentBoard___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
