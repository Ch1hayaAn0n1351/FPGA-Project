// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard__pch.h"
#include "VDevelopmentBoard___024root.h"

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_static(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_static\n"); );
}

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_initial(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_clk__0 
        = vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_clk;
}

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_final(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__stl(VDevelopmentBoard___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VDevelopmentBoard___024root___eval_phase__stl(VDevelopmentBoard___024root* vlSelf);

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_settle(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VDevelopmentBoard___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("DevelopmentBoard.v", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VDevelopmentBoard___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__stl(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VDevelopmentBoard___024root___stl_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___stl_sequent__TOP__0\n"); );
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
    // Body
    vlSelf->led1 = vlSelf->reset;
    vlSelf->led2 = vlSelf->B2;
    vlSelf->led3 = vlSelf->B3;
    vlSelf->led4 = vlSelf->B4;
    vlSelf->led5 = vlSelf->B5;
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

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_stl(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_triggers__stl(VDevelopmentBoard___024root* vlSelf);

VL_ATTR_COLD bool VDevelopmentBoard___024root___eval_phase__stl(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VDevelopmentBoard___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VDevelopmentBoard___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__ico(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__act(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or negedge reset)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge DevelopmentBoard.ColorBar_inst.vga_clk or negedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VDevelopmentBoard___024root___dump_triggers__nba(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or negedge reset)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge DevelopmentBoard.ColorBar_inst.vga_clk or negedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VDevelopmentBoard___024root___ctor_var_reset(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->B2 = VL_RAND_RESET_I(1);
    vlSelf->B3 = VL_RAND_RESET_I(1);
    vlSelf->B4 = VL_RAND_RESET_I(1);
    vlSelf->B5 = VL_RAND_RESET_I(1);
    vlSelf->h_sync = VL_RAND_RESET_I(1);
    vlSelf->v_sync = VL_RAND_RESET_I(1);
    vlSelf->rgb = VL_RAND_RESET_I(16);
    vlSelf->led1 = VL_RAND_RESET_I(1);
    vlSelf->led2 = VL_RAND_RESET_I(1);
    vlSelf->led3 = VL_RAND_RESET_I(1);
    vlSelf->led4 = VL_RAND_RESET_I(1);
    vlSelf->led5 = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_clk = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pix_data = VL_RAND_RESET_I(16);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__pll_inst__DOT__cnt = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__char_color = VL_RAND_RESET_I(16);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__bit_val = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__in_char_area = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_h = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_ctrl_inst__DOT__cnt_v = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_clk__0 = VL_RAND_RESET_I(1);
}
