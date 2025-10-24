// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard__pch.h"
#include "VDevelopmentBoard___024root.h"

VL_INLINE_OPT void VDevelopmentBoard___024root___ico_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->led1 = vlSelf->reset;
    vlSelf->led2 = vlSelf->B2;
    vlSelf->led3 = vlSelf->B3;
    vlSelf->led4 = vlSelf->B4;
    vlSelf->led5 = vlSelf->B5;
}

void VDevelopmentBoard___024root___eval_ico(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VDevelopmentBoard___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void VDevelopmentBoard___024root___eval_triggers__ico(VDevelopmentBoard___024root* vlSelf);

bool VDevelopmentBoard___024root___eval_phase__ico(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VDevelopmentBoard___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VDevelopmentBoard___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VDevelopmentBoard___024root___eval_act(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_act\n"); );
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x = 0;
    SData/*9:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y = 0;
    CData/*6:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_x;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_x = 0;
    CData/*4:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_y;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_y = 0;
    CData/*1:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_index;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_index = 0;
    CData/*4:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_x_in;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_x_in = 0;
    CData/*4:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_y_rel;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_y_rel = 0;
    CData/*1:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__byte_idx;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__byte_idx = 0;
    SData/*8:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__addr;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__addr = 0;
    CData/*7:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_byte;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_byte = 0;
    CData/*2:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_sel;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_sel = 0;
    CData/*0:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__pix_pre_req;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__pix_pre_req = 0;
    CData/*0:0*/ DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT____VdfgTmp_ha8b3968e__0;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT____VdfgTmp_ha8b3968e__0 = 0;
    SData/*15:0*/ __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color;
    __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color = 0;
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h = 0;
    // Body
    __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color 
        = vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color;
    __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    if (vlSelf->reset) {
        if ((1U & (~ (IData)(vlSelf->B2)))) {
            __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color 
                = ((0xf800U == (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color))
                    ? 0x7e0U : ((0x7e0U == (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color))
                                 ? 0x1fU : 0xf800U));
        }
        if ((0x31fU == (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) {
            __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h = 0U;
            vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v 
                = ((0x20cU == (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v))
                    ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v))));
        } else {
            __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
                = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h)));
        }
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_data 
            = ((IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__in_char_area)
                ? ((IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_val)
                    ? (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color)
                    : 0U) : 0U);
    } else {
        __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color = 0xf800U;
        __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h = 0U;
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v = 0U;
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_data = 0U;
    }
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color 
        = __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color;
    vlSelf->h_sync = (0x60U <= (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h));
    vlSelf->v_sync = (2U <= (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v));
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT____VdfgTmp_ha8b3968e__0 
        = ((0x23U <= (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v)) 
           & (0x203U > (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v)));
    vlSelf->rgb = (((0x90U <= (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
                    & ((0x310U > (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
                       & (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT____VdfgTmp_ha8b3968e__0)))
                    ? (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_data)
                    : 0U);
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__pix_pre_req 
        = ((0x8fU <= (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
           & ((0x30fU > (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
              & (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT____VdfgTmp_ha8b3968e__0)));
    if (DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__pix_pre_req) {
        DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x 
            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h) 
                         - (IData)(0x8fU)));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y 
            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v) 
                         - (IData)(0x23U)));
    } else {
        DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x = 0U;
        DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y = 0U;
    }
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__in_char_area = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_x = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_y = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_index = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_x_in = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_y_rel = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__byte_idx = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__addr = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_byte = 0U;
    DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_sel = 0U;
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_val = 0U;
    if (((((0x100U <= (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x)) 
           & (0x180U > (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x))) 
          & (0xe0U <= (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y))) 
         & (0x100U > (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y)))) {
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__in_char_area = 1U;
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_x 
            = (0x7fU & (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_x));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_y 
            = (0x1fU & (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_y));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_index 
            = (3U & ((IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_x) 
                     >> 5U));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_x_in 
            = (0x1fU & (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_x));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_y_rel 
            = DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__rel_y;
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__byte_idx 
            = (3U & ((IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_x_in) 
                     >> 3U));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__addr 
            = (0x1ffU & ((VL_SHIFTL_III(9,32,32, (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_index), 7U) 
                          + VL_SHIFTL_III(9,32,32, (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_y_rel), 2U)) 
                         + (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__byte_idx)));
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_byte 
            = vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__CHAR_DATA
            [DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__addr];
        DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_sel 
            = (7U & ((IData)(7U) - (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__pix_x_in)));
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_val 
            = (1U & ((IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_byte) 
                     >> (IData)(DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_sel)));
    }
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__1(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt;
    __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt = 0;
    // Body
    __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt 
        = vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt;
    if (vlSelf->reset) {
        __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt 
            = (1U & ((IData)(1U) + (IData)(vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt)));
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_clk 
            = vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt;
    } else {
        __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt = 0U;
        vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_clk = 0U;
    }
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt 
        = __Vdly__DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt;
}

void VDevelopmentBoard___024root___eval_nba(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void VDevelopmentBoard___024root___eval_triggers__act(VDevelopmentBoard___024root* vlSelf);

bool VDevelopmentBoard___024root___eval_phase__act(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VDevelopmentBoard___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VDevelopmentBoard___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VDevelopmentBoard___024root___eval_phase__nba(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VDevelopmentBoard___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__ico(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__nba(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__act(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG

void VDevelopmentBoard___024root___eval(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VDevelopmentBoard___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("DevelopmentBoard.v", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VDevelopmentBoard___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VDevelopmentBoard___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("DevelopmentBoard.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VDevelopmentBoard___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("DevelopmentBoard.v", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VDevelopmentBoard___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VDevelopmentBoard___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VDevelopmentBoard___024root___eval_debug_assertions(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->B2 & 0xfeU))) {
        Verilated::overWidthError("B2");}
    if (VL_UNLIKELY((vlSelf->B3 & 0xfeU))) {
        Verilated::overWidthError("B3");}
    if (VL_UNLIKELY((vlSelf->B4 & 0xfeU))) {
        Verilated::overWidthError("B4");}
    if (VL_UNLIKELY((vlSelf->B5 & 0xfeU))) {
        Verilated::overWidthError("B5");}
}
#endif  // VL_DEBUG
