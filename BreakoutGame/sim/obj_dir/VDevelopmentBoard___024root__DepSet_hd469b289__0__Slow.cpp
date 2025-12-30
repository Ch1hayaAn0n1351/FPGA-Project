// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard__pch.h"
#include "VDevelopmentBoard___024root.h"

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_static__TOP(VDevelopmentBoard___024root* vlSelf);

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_static(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_static\n"); );
    // Body
    VDevelopmentBoard___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_static__TOP(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_static__TOP\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = 0xffffffffU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX = 0x19fU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY = 0x1d2U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX = 0x19fU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY = 0x1d4U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[0U] = 0xb7U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[1U] = 0xf8U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[2U] = 0x139U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[3U] = 0x17aU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[4U] = 0x1bbU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[5U] = 0x1fcU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[6U] = 0x23dU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[7U] = 0x27eU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[0U] = 0x37U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[1U] = 0x50U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[2U] = 0x69U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[3U] = 0x82U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState = 0xffffffffU;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1 = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2 = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1 = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = 1U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__flash_en = 0U;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x = 0x8cU;
}

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_initial(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__0 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY;
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
    if ((2ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 1 is active: @([hybrid] DevelopmentBoard.u_breakout.ballX)\n");
    }
    if ((4ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 2 is active: @([hybrid] DevelopmentBoard.u_breakout.ballY)\n");
    }
    if ((8ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 3 is active: @([hybrid] DevelopmentBoard.u_breakout.paddleX)\n");
    }
    if ((0x10ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 4 is active: @([hybrid] DevelopmentBoard.u_breakout.paddleY)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VDevelopmentBoard___024root___stl_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->led1 = (1U & (~ (IData)(vlSelf->reset)));
    vlSelf->led2 = (1U & (~ (IData)(vlSelf->B2)));
    vlSelf->led3 = (1U & (~ (IData)(vlSelf->B3)));
    vlSelf->led4 = (1U & (~ (IData)(vlSelf->B4)));
    vlSelf->led5 = (1U & (~ (IData)(vlSelf->B5)));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__hreset 
        = (0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock 
        = (1U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame 
        = ((0x27fU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
           & (0x1dfU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vreset 
        = ((0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
           & (0x20fU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vblankon 
        = ((0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
           & (0x1dfU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
           & ((0x78U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
              | ((0x2bcU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                 | ((0xfU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                    | (0x1f4U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY))))));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text 
        = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
            & ((0xfaU <= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
               & (0x226U >= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)))) 
           & (((0xc8U <= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
               & (0xdcU >= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY))) 
              | ((0xe6U <= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                 & (0xfaU >= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
           & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
               == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x)) 
              & ((0xf7U <= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                 & (0x10bU >= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border 
        = ((0x8cU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
           | ((0x2a8U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
              | ((0x23U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                 | (0x1e0U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__flash_en) 
           & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
              & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border)));
}

void VDevelopmentBoard___024root___act_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf);
void VDevelopmentBoard___024root___act_sequent__TOP__1(VDevelopmentBoard___024root* vlSelf);
void VDevelopmentBoard___024root___act_sequent__TOP__2(VDevelopmentBoard___024root* vlSelf);
void VDevelopmentBoard___024root___act_sequent__TOP__3(VDevelopmentBoard___024root* vlSelf);
void VDevelopmentBoard___024root___act_comb__TOP__0(VDevelopmentBoard___024root* vlSelf);
void VDevelopmentBoard___024root___act_comb__TOP__1(VDevelopmentBoard___024root* vlSelf);
void VDevelopmentBoard___024root___act_comb__TOP__2(VDevelopmentBoard___024root* vlSelf);

VL_ATTR_COLD void VDevelopmentBoard___024root___eval_stl(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___stl_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((5ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((9ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x11ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((7ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0x19ULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0x1fULL & vlSelf->__VstlTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_comb__TOP__2(vlSelf);
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
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @([hybrid] DevelopmentBoard.u_breakout.ballX)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @([hybrid] DevelopmentBoard.u_breakout.ballY)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([hybrid] DevelopmentBoard.u_breakout.paddleX)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([hybrid] DevelopmentBoard.u_breakout.paddleY)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @(posedge clk or negedge reset)\n");
    }
    if ((0x20ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 5 is active: @(posedge DevelopmentBoard.u_breakout.num[0])\n");
    }
    if ((0x40ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 6 is active: @(negedge reset or posedge DevelopmentBoard.u_breakout.num[0])\n");
    }
    if ((0x80ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 7 is active: @(posedge clk)\n");
    }
    if ((0x100ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 8 is active: @(posedge DevelopmentBoard.u_breakout.__Vcellinp__generator__clock)\n");
    }
    if ((0x200ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 9 is active: @(posedge clk or negedge reset or posedge DevelopmentBoard.u_breakout.num[0])\n");
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
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @([hybrid] DevelopmentBoard.u_breakout.ballX)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @([hybrid] DevelopmentBoard.u_breakout.ballY)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([hybrid] DevelopmentBoard.u_breakout.paddleX)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([hybrid] DevelopmentBoard.u_breakout.paddleY)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @(posedge clk or negedge reset)\n");
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 5 is active: @(posedge DevelopmentBoard.u_breakout.num[0])\n");
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 6 is active: @(negedge reset or posedge DevelopmentBoard.u_breakout.num[0])\n");
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 7 is active: @(posedge clk)\n");
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 8 is active: @(posedge DevelopmentBoard.u_breakout.__Vcellinp__generator__clock)\n");
    }
    if ((0x200ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 9 is active: @(posedge clk or negedge reset or posedge DevelopmentBoard.u_breakout.num[0])\n");
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
    vlSelf->DevelopmentBoard__DOT__game_end = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__game_win = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = VL_RAND_RESET_I(32);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = VL_RAND_RESET_I(32);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = VL_RAND_RESET_I(32);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickCollision = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num = VL_RAND_RESET_I(24);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY = VL_RAND_RESET_I(10);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[__Vi0] = VL_RAND_RESET_I(10);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[__Vi0] = VL_RAND_RESET_I(10);
    }
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState = VL_RAND_RESET_I(32);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1 = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2 = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1 = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__flash_en = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x = VL_RAND_RESET_I(10);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0 = 0;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__hreset = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vreset = VL_RAND_RESET_I(1);
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vblankon = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState = VL_RAND_RESET_I(32);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__DevelopmentBoard__DOT__game_end = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = VL_RAND_RESET_I(32);
    vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v0 = 0;
    vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v1 = 0;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__num = VL_RAND_RESET_I(24);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cX = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cY = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__0 = VL_RAND_RESET_I(1);
    vlSelf->__VstlDidInit = 0;
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__1 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr_hc9ffefd5__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock__0 = VL_RAND_RESET_I(1);
    vlSelf->__VactDidInit = 0;
}
