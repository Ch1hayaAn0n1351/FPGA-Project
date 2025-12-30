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
    vlSelf->led1 = (1U & (~ (IData)(vlSelf->reset)));
    vlSelf->led2 = (1U & (~ (IData)(vlSelf->B2)));
    vlSelf->led3 = (1U & (~ (IData)(vlSelf->B3)));
    vlSelf->led4 = (1U & (~ (IData)(vlSelf->B4)));
    vlSelf->led5 = (1U & (~ (IData)(vlSelf->B5)));
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

VL_INLINE_OPT void VDevelopmentBoard___024root___act_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_sequent__TOP__0\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX 
        = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
            == ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX) 
                - (IData)(4U))) | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                    != ((IData)(4U) 
                                        + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX))) 
                                   & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX)));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___act_sequent__TOP__1(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_sequent__TOP__1\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY 
        = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
            == ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY) 
                - (IData)(4U))) | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                    != ((IData)(4U) 
                                        + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY))) 
                                   & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY)));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___act_sequent__TOP__2(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_sequent__TOP__2\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX 
        = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
            == ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                - (IData)(0x20U))) | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                       != ((IData)(0x1fU) 
                                           + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX))) 
                                      & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX)));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___act_sequent__TOP__3(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_sequent__TOP__3\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY 
        = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
            == ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY) 
                - (IData)(2U))) | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                    != ((IData)(1U) 
                                        + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY))) 
                                   & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY)));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___act_comb__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickCollision 
        = ((0U != (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___act_comb__TOP__1(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_comb__TOP__1\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject 
        = (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                 | ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle) 
                    | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks))));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___act_comb__TOP__2(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___act_comb__TOP__2\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle) 
           | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball));
    vlSelf->rgb = ((0x7c00U & ((- (IData)((1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state)
                                                  ? 
                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__game_win)
                                                   ? 
                                                  ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border) 
                                                   | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light))
                                                   : 
                                                  ((IData)(vlSelf->DevelopmentBoard__DOT__game_end)
                                                    ? 
                                                   (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                     ^ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                    >> 5U)
                                                    : 
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                                                    | ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                                       | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                                           >> 3U) 
                                                          | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle))))))
                                                  : 
                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border) 
                                                  | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text)))))) 
                               << 0xaU)) | ((0x3e0U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state)
                                                                ? 
                                                               ((IData)(vlSelf->DevelopmentBoard__DOT__game_win)
                                                                 ? (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light)
                                                                 : 
                                                                ((IData)(vlSelf->DevelopmentBoard__DOT__game_end)
                                                                  ? 
                                                                 (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                                   ^ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                                  >> 4U)
                                                                  : 
                                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                                                                  | (IData)(
                                                                            ((0U 
                                                                              != 
                                                                              (0xaU 
                                                                               & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks))) 
                                                                             | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0))))))
                                                                : 
                                                               ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
                                                                & ((0x78U 
                                                                    < (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                                                                   & ((0x2bcU 
                                                                       > (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                                                                      & ((0xfU 
                                                                          < (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                                         & ((~ 
                                                                             ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text) 
                                                                              | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border))) 
                                                                            & (0x1f4U 
                                                                               > (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY))))))))))) 
                                                << 5U)) 
                                            | (0x1fU 
                                               & (- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state)
                                                                 ? 
                                                                ((IData)(vlSelf->DevelopmentBoard__DOT__game_win)
                                                                  ? (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border)
                                                                  : 
                                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__game_end)
                                                                   ? 
                                                                  (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                                    ^ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                                   >> 3U)
                                                                   : 
                                                                  ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                                                                   | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                                                       >> 2U) 
                                                                      | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0)))))
                                                                 : (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border))))))));
}

void VDevelopmentBoard___024root___eval_act(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_act\n"); );
    // Body
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((3ULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_comb__TOP__0(vlSelf);
    }
    if ((0xcULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_comb__TOP__1(vlSelf);
    }
    if ((0xfULL & vlSelf->__VactTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_comb__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__num 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__num 
        = (0xffffffU & ((IData)(1U) + vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__1(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX;
    __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX = 0;
    CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY;
    __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY = 0;
    // Body
    __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY;
    __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cX 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cY 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY;
    vlSelf->h_sync = ((0x28cU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX))
                       ? 0U : ((0x2eaU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX))
                                ? 1U : (1U & (IData)(vlSelf->h_sync))));
    vlSelf->v_sync = (((0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                       & (0x1ecU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))
                       ? 0U : (((0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                                & (0x1eeU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))
                                ? 1U : (1U & (IData)(vlSelf->v_sync))));
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cX 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__hreset)
            ? 0U : (0x3ffU & ((IData)(1U) + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX))));
    if ((0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX))) {
        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cY 
            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vreset)
                          ? 0U : ((IData)(1U) + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY))));
        __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX = 1U;
    } else {
        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cY 
            = (0x3ffU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY));
        __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX 
            = ((0x27fU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX))
                ? 0U : (1U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX)));
    }
    __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vreset)
            ? 1U : ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vblankon)
                     ? 0U : (1U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY))));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX 
        = __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY 
        = __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY;
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__2(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v0 = 0U;
    vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v1 = 0U;
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__3(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState;
    vlSelf->__Vdly__DevelopmentBoard__DOT__game_end 
        = vlSelf->DevelopmentBoard__DOT__game_end;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX;
    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX 
        = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX;
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__4(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__4\n"); );
    // Body
    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i = 0x20U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks = 0U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 0U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((1U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    >= (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                              <= ((IData)(0x1dU) 
                                                  + 
                                                  vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                  [
                                                  (7U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    >= (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                             <= ((IData)(9U) 
                                                 + 
                                                 vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                 [(3U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 1U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((2U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[1U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    >= (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                              <= ((IData)(0x1dU) 
                                                  + 
                                                  vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                  [
                                                  (7U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[1U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    >= (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                             <= ((IData)(9U) 
                                                 + 
                                                 vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                 [(3U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [1U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [1U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [1U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [1U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [1U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [1U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [1U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [1U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 2U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((4U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[2U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [2U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[2U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [2U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [2U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [2U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [2U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [2U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [2U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [2U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [2U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [2U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 3U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((8U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[3U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [3U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[3U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [3U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [3U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [3U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [3U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [3U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [3U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [3U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [3U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [3U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 4U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((0x10U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[4U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [4U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[4U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [4U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [4U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [4U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [4U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [4U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [4U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [4U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [4U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [4U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 5U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((0x20U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[5U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [5U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[5U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [5U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [5U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [5U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [5U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [5U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [5U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [5U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [5U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [5U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 6U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((0x40U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[6U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [6U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[6U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [6U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [6U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [6U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [6U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [6U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [6U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [6U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [6U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [6U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 7U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 0U;
        if ((0x80U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[7U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [7U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[7U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [7U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [7U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [7U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [7U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [7U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [7U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [7U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [7U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [7U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 0U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x100U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[8U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [8U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[8U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [8U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [8U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [8U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [8U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [8U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [8U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [8U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [8U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [8U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 1U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x200U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[9U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [9U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[9U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [9U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [9U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [9U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [9U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [9U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [9U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [9U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [9U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [9U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 2U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x400U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0xaU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0xaU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0xaU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0xaU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0xaU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0xaU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xaU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xaU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xaU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xaU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xaU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xaU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 3U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x800U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0xbU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0xbU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0xbU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0xbU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0xbU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0xbU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xbU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xbU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xbU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xbU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xbU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xbU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 4U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x1000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0xcU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0xcU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0xcU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0xcU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0xcU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0xcU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xcU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xcU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xcU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xcU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xcU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xcU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 5U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x2000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0xdU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0xdU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0xdU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0xdU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0xdU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0xdU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xdU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xdU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xdU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xdU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xdU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xdU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 6U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x4000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0xeU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0xeU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0xeU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0xeU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0xeU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0xeU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xeU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xeU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xeU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xeU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xeU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xeU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 7U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 1U;
        if ((0x8000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0xfU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0xfU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0xfU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0xfU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0xfU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0xfU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xfU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xfU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xfU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xfU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0xfU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0xfU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 0U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x10000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x10U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x10U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x10U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x10U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x10U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x10U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x10U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x10U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x10U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x10U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x10U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x10U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 1U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x20000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x11U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x11U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x11U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x11U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x11U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x11U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x11U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x11U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x11U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x11U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x11U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x11U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 2U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x40000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x12U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x12U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x12U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x12U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x12U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x12U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x12U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x12U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x12U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x12U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x12U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x12U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 3U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x80000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x13U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x13U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x13U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x13U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x13U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x13U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x13U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x13U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x13U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x13U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x13U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x13U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 4U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x100000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x14U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x14U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x14U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x14U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x14U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x14U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x14U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x14U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x14U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x14U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x14U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x14U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 5U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x200000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x15U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x15U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x15U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x15U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x15U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x15U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x15U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x15U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x15U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x15U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x15U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x15U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 6U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x400000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x16U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x16U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x16U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x16U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x16U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x16U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x16U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x16U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x16U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x16U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x16U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x16U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 7U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 2U;
        if ((0x800000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x17U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x17U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x17U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x17U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x17U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x17U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x17U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x17U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x17U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x17U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x17U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x17U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 0U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x1000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x18U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x18U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x18U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x18U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x18U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x18U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x18U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x18U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x18U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x18U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x18U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x18U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 1U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x2000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x19U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x19U])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x19U] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x19U])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x19U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x19U]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x19U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x19U]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x19U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x19U]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x19U] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x19U]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 2U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x4000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x1aU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x1aU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x1aU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x1aU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x1aU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x1aU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1aU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1aU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1aU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1aU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1aU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1aU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 3U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x8000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x1bU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x1bU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x1bU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x1bU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x1bU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x1bU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1bU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1bU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1bU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1bU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1bU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1bU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 4U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x10000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x1cU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x1cU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x1cU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x1cU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x1cU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x1cU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1cU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1cU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1cU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1cU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1cU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1cU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 5U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x20000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x1dU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x1dU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x1dU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x1dU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x1dU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x1dU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1dU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1dU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1dU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1dU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1dU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1dU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 6U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((0x40000000U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x1eU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x1eU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x1eU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x1eU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x1eU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x1eU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1eU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1eU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1eU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1eU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1eU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1eU]) << 3U))));
            }
        }
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j = 7U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k = 3U;
        if ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState 
             >> 0x1fU)) {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX[0x1fU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                        [(7U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)] 
                        - (IData)(0x1eU))) ? 1U : (
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                    == 
                                                    ((IData)(0x1dU) 
                                                     + 
                                                     vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX
                                                     [
                                                     (7U 
                                                      & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__j)]))
                                                    ? 0U
                                                    : 
                                                   (1U 
                                                    & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                                    [0x1fU])));
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY[0x1fU] 
                = (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                    == (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                        [(3U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)] 
                        - (IData)(0xaU))) ? 1U : (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                                                   == 
                                                   ((IData)(9U) 
                                                    + 
                                                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY
                                                    [
                                                    (3U 
                                                     & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)]))
                                                   ? 0U
                                                   : 
                                                  (1U 
                                                   & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                                   [0x1fU])));
            if ((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                | (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                   [0x1fU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                   [0x1fU]))));
            } else if ((1U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xdU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (2U & ((0xfffffffeU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1fU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1fU]) << 1U))));
            } else if ((2U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((0xbU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (4U & ((0xfffffffcU & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1fU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1fU]) << 2U))));
            } else if ((3U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__k)) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks 
                    = ((7U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                       | (8U & ((0xfffffff8U & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
                                | ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                                    [0x1fU] & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                                    [0x1fU]) << 3U))));
            }
        }
    }
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__5(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__5\n"); );
    // Body
    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state) {
        if (vlSelf->reset) {
            if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickCollision) {
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = 0xffffffffU;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i = 0U;
                {
                    while (VL_GTS_III(32, 0x20U, vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i)) {
                        if ((vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickX
                             [(0x1fU & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i)] 
                             & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickY
                             [(0x1fU & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i)])) {
                            vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex 
                                = vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i;
                            goto __Vlabel1;
                        }
                        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i 
                            = ((IData)(1U) + vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__i);
                    }
                    __Vlabel1: ;
                }
            }
            if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame) {
                if ((((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                      & VL_LTES_III(32, 0U, vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex)) 
                     & VL_GTS_III(32, 0x20U, vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex))) {
                    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState 
                        = ((~ ((IData)(1U) << (0x1fU 
                                               & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex))) 
                           & vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState);
                    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY 
                        = (1U & (~ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY)));
                    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = 0xffffffffU;
                }
                if ((1U & (((~ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started)) 
                            & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_win))) 
                           & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_end))))) {
                    if (((~ (IData)(vlSelf->B2)) & 
                         (0x8cU < ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                                   - (IData)(0x20U))))) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX 
                            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                                         - (IData)(0xaU)));
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX 
                            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                                         - (IData)(0xaU)));
                    } else if (((~ (IData)(vlSelf->B3)) 
                                & (0x2a8U > ((IData)(0x20U) 
                                             + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX))))) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX 
                            = (0x3ffU & ((IData)(0xaU) 
                                         + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX)));
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX 
                            = (0x3ffU & ((IData)(0xaU) 
                                         + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX)));
                    }
                    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY = 0x1d2U;
                } else if ((((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                             & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_win))) 
                            & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_end)))) {
                    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = 0U;
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX = 0x94U;
                    } else if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = 1U;
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX = 0x2a0U;
                    } else {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX 
                            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX) 
                                         + ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX)
                                             ? 0x3fcU
                                             : 4U)));
                    }
                    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = 1U;
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY 
                            = (0x3ffU & ((((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY) 
                                           - (IData)(2U)) 
                                          - (IData)(4U)) 
                                         - (IData)(1U)));
                    } else if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = 0U;
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY = 0x2bU;
                    } else if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__game_end = 1U;
                    } else {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY 
                            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY) 
                                         + ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY)
                                             ? 0x3fcU
                                             : 4U)));
                    }
                    if (((~ (IData)(vlSelf->B2)) & 
                         (0x8cU < ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                                   - (IData)(0x20U))))) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX 
                            = (0x3ffU & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                                         - (IData)(0xaU)));
                    } else if (((~ (IData)(vlSelf->B3)) 
                                & (0x2a8U > ((IData)(0x20U) 
                                             + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX))))) {
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX 
                            = (0x3ffU & ((IData)(0xaU) 
                                         + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX)));
                    }
                }
            }
        } else {
            vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = 0xffffffffU;
        }
    }
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__7(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__7\n"); );
    // Body
    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state) {
        if (vlSelf->reset) {
            if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame) {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1 = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2 = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1 = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle = 0U;
            } else {
                if (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                     & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject) 
                         & (0x8cU >= ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX) 
                                      - (IData)(4U)))) 
                        & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                           == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY))))) {
                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1 = 1U;
                }
                if (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                     & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject) 
                         & (0x2a8U <= ((IData)(4U) 
                                       + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX)))) 
                        & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY) 
                           == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY))))) {
                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2 = 1U;
                }
                if (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                     & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject) 
                         & (0x23U >= ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY) 
                                      - (IData)(4U)))) 
                        & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                           == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX))))) {
                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1 = 1U;
                }
                if (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                     & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject) 
                         & (0x1e0U <= ((IData)(4U) 
                                       + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY)))) 
                        & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                           == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX))))) {
                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom = 1U;
                }
                if (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started) 
                     & ((((((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject) 
                            & (~ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY))) 
                           & (((IData)(4U) + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY)) 
                              >= ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY) 
                                  - (IData)(2U)))) 
                          & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY) 
                              - (IData)(4U)) <= ((IData)(2U) 
                                                 + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY)))) 
                         & (((IData)(4U) + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX)) 
                            >= ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX) 
                                - (IData)(0x20U)))) 
                        & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX) 
                            - (IData)(4U)) <= ((IData)(0x20U) 
                                               + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX)))))) {
                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle = 1U;
                }
            }
        } else {
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1 = 0U;
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2 = 0U;
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1 = 0U;
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom = 0U;
            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle = 0U;
        }
    }
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__8(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__8\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cY;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cX;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__hreset 
        = (0x319U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX));
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
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border 
        = ((0x8cU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
           | ((0x2a8U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
              | ((0x23U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                 | (0x1e0U == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__9(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__9\n"); );
    // Body
    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state) {
        if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state) {
            if (vlSelf->reset) {
                if ((1U & (((~ vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState) 
                            & (~ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickCollision))) 
                           & (~ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame))))) {
                    vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState 
                        = (1U | vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState);
                }
                if (vlSelf->DevelopmentBoard__DOT__game_win) {
                    if (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame) {
                        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x 
                            = ((0x2a8U <= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x))
                                ? 0x8cU : (0x3ffU & 
                                           ((IData)(2U) 
                                            + (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x))));
                    }
                    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__flash_en 
                        = (1U & (vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num 
                                 >> 0x11U));
                }
                if ((1U & (((~ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started)) 
                            & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_win))) 
                           & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_end))))) {
                    if (vlSelf->B4) {
                        if ((1U & (~ (IData)(vlSelf->B5)))) {
                            vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started = 1U;
                            vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = 0U;
                            vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = 1U;
                        }
                    } else {
                        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started = 1U;
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = 1U;
                        vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = 1U;
                    }
                }
                if (((0U == vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState) 
                     & (~ (IData)(vlSelf->DevelopmentBoard__DOT__game_end)))) {
                    vlSelf->DevelopmentBoard__DOT__game_win = 1U;
                }
            } else {
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_started = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x = 0x8cU;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX = 0x19fU;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY = 0x1d2U;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX = 0x19fU;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePY = 0x1d4U;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState = 0xffffffffU;
                vlSelf->__Vdly__DevelopmentBoard__DOT__game_end = 0U;
                vlSelf->DevelopmentBoard__DOT__game_win = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX1 = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionX2 = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionY1 = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom = 0U;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex = 0xffffffffU;
                vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v0 = 1U;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX = 1U;
                vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__flash_en = 0U;
                vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state = 1U;
                vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v1 = 1U;
            }
        }
    } else if ((1U & (~ (IData)(vlSelf->B2)))) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state = 1U;
    }
    if (vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v0) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[0U] = 0x37U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[0U] = 0xb7U;
    }
    if (vlSelf->__Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v1) {
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[1U] = 0x50U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[2U] = 0x69U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPY[3U] = 0x82U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[1U] = 0xf8U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[2U] = 0x139U;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[3U] = 0x17aU;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[4U] = 0x1bbU;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[5U] = 0x1fcU;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[6U] = 0x23dU;
        vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickPX[7U] = 0x27eU;
    }
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__10(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__10\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickState 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickIndex 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex;
    vlSelf->DevelopmentBoard__DOT__game_end = vlSelf->__Vdly__DevelopmentBoard__DOT__game_end;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPX 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballPY 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddlePX 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX;
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__11(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__11\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num 
        = vlSelf->__Vdly__DevelopmentBoard__DOT__u_breakout__DOT__num;
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock 
        = (1U & vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__num);
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_sequent__TOP__12(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_sequent__TOP__12\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__resetFrame 
        = ((0x27fU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
           & (0x1dfU == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__0(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__0\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__flash_en) 
           & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
              & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border)));
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
           & (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
               == (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__light_x)) 
              & ((0xf7U <= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                 & (0x10bU >= (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)))));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__5(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__5\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballX) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ballY));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__6(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__6\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleX) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddleY));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__7(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__7\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__brickCollision 
        = ((0U != (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks)) 
           & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__8(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__8\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject 
        = (1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                 | ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle) 
                    | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks))));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__9(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__9\n"); );
    // Body
    vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0 
        = ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle) 
           | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__ball));
}

VL_INLINE_OPT void VDevelopmentBoard___024root___nba_comb__TOP__10(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___nba_comb__TOP__10\n"); );
    // Body
    vlSelf->rgb = ((0x7c00U & ((- (IData)((1U & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state)
                                                  ? 
                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__game_win)
                                                   ? 
                                                  ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border) 
                                                   | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light))
                                                   : 
                                                  ((IData)(vlSelf->DevelopmentBoard__DOT__game_end)
                                                    ? 
                                                   (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                     ^ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                    >> 5U)
                                                    : 
                                                   ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                                                    | ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                                       | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                                           >> 3U) 
                                                          | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__paddle))))))
                                                  : 
                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border) 
                                                  | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text)))))) 
                               << 0xaU)) | ((0x3e0U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state)
                                                                ? 
                                                               ((IData)(vlSelf->DevelopmentBoard__DOT__game_win)
                                                                 ? (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_light)
                                                                 : 
                                                                ((IData)(vlSelf->DevelopmentBoard__DOT__game_end)
                                                                  ? 
                                                                 (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                                   ^ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                                  >> 4U)
                                                                  : 
                                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                                                                  | (IData)(
                                                                            ((0U 
                                                                              != 
                                                                              (0xaU 
                                                                               & (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks))) 
                                                                             | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0))))))
                                                                : 
                                                               ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__inDispArea) 
                                                                & ((0x78U 
                                                                    < (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                                                                   & ((0x2bcU 
                                                                       > (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX)) 
                                                                      & ((0xfU 
                                                                          < (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                                         & ((~ 
                                                                             ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text) 
                                                                              | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border))) 
                                                                            & (0x1f4U 
                                                                               > (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY))))))))))) 
                                                << 5U)) 
                                            | (0x1fU 
                                               & (- (IData)(
                                                            (1U 
                                                             & ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__game_state)
                                                                 ? 
                                                                ((IData)(vlSelf->DevelopmentBoard__DOT__game_win)
                                                                  ? (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__win_border)
                                                                  : 
                                                                 ((IData)(vlSelf->DevelopmentBoard__DOT__game_end)
                                                                   ? 
                                                                  (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cX) 
                                                                    ^ (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__cY)) 
                                                                   >> 3U)
                                                                   : 
                                                                  ((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__border) 
                                                                   | (((IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__bricks) 
                                                                       >> 2U) 
                                                                      | (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0)))))
                                                                 : (IData)(vlSelf->DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border))))))));
}

void VDevelopmentBoard___024root___eval_nba(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_nba\n"); );
    // Body
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((0x200ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__3(vlSelf);
    }
    if ((0x20ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__4(vlSelf);
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__5(vlSelf);
    }
    if ((0x40ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__7(vlSelf);
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__8(vlSelf);
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__9(vlSelf);
    }
    if ((0x200ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__10(vlSelf);
    }
    if ((0x80ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__11(vlSelf);
    }
    if ((0x100ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_sequent__TOP__12(vlSelf);
    }
    if ((0x110ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0x118ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__3(vlSelf);
    }
    if ((0x301ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__0(vlSelf);
    }
    if ((0x302ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__1(vlSelf);
    }
    if ((0x304ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___act_sequent__TOP__2(vlSelf);
    }
    if ((0x303ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__5(vlSelf);
    }
    if ((0x31cULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__6(vlSelf);
    }
    if ((0x323ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__7(vlSelf);
    }
    if ((0x33cULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__8(vlSelf);
    }
    if ((0x31fULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__9(vlSelf);
    }
    if ((0x33fULL & vlSelf->__VnbaTriggered.word(0U))) {
        VDevelopmentBoard___024root___nba_comb__TOP__10(vlSelf);
    }
}

void VDevelopmentBoard___024root___eval_triggers__act(VDevelopmentBoard___024root* vlSelf);

bool VDevelopmentBoard___024root___eval_phase__act(VDevelopmentBoard___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VDevelopmentBoard__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<10> __VpreTriggered;
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
