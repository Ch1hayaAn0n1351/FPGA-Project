// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VDevelopmentBoard.h for the primary calling header

#ifndef VERILATED_VDEVELOPMENTBOARD___024ROOT_H_
#define VERILATED_VDEVELOPMENTBOARD___024ROOT_H_  // guard

#include "verilated.h"


class VDevelopmentBoard__Syms;

class alignas(VL_CACHE_LINE_BYTES) VDevelopmentBoard___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(reset,0,0);
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock;
        VL_IN8(B2,0,0);
        VL_IN8(B3,0,0);
        VL_IN8(B4,0,0);
        VL_IN8(B5,0,0);
        VL_OUT8(h_sync,0,0);
        VL_OUT8(v_sync,0,0);
        VL_OUT8(led1,0,0);
        VL_OUT8(led2,0,0);
        VL_OUT8(led3,0,0);
        VL_OUT8(led4,0,0);
        VL_OUT8(led5,0,0);
        CData/*0:0*/ DevelopmentBoard__DOT__game_end;
        CData/*0:0*/ DevelopmentBoard__DOT__game_win;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__inDispArea;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__border;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ball;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ballX;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ballY;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__paddle;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__paddleX;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__paddleY;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__bouncingObject;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__resetFrame;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__brickCollision;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__game_state;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__game_started;
        CData/*3:0*/ DevelopmentBoard__DOT__u_breakout__DOT__bricks;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__collisionX1;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__collisionX2;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__collisionY1;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__collisionPaddle;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__collisionBottom;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__flash_en;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__start_screen_border;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__start_screen_text;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__win_border;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__win_light;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT____VdfgTmp_hbcde4c15__0;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaX;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__inDispAreaY;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__hreset;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vreset;
        CData/*0:0*/ DevelopmentBoard__DOT__u_breakout__DOT__generator__DOT__vblankon;
        CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirX;
        CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ball_dirY;
        CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__game_end;
        CData/*0:0*/ __Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v0;
        CData/*0:0*/ __Vdlyvset__DevelopmentBoard__DOT__u_breakout__DOT__brickPX__v1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__0;
        CData/*0:0*/ __VstlDidInit;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballX__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__ballY__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleX__1;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT__paddleY__1;
    };
    struct {
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
        CData/*0:0*/ __Vtrigprevexpr_hc9ffefd5__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__DevelopmentBoard__DOT__u_breakout__DOT____Vcellinp__generator__clock__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        VL_OUT16(rgb,15,0);
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__cX;
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__cY;
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ballPX;
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__ballPY;
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__paddlePX;
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__paddlePY;
        SData/*9:0*/ DevelopmentBoard__DOT__u_breakout__DOT__light_x;
        SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPX;
        SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__ballPY;
        SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__paddlePX;
        SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cX;
        SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__cY;
        IData/*31:0*/ DevelopmentBoard__DOT__u_breakout__DOT__i;
        IData/*31:0*/ DevelopmentBoard__DOT__u_breakout__DOT__j;
        IData/*31:0*/ DevelopmentBoard__DOT__u_breakout__DOT__k;
        IData/*31:0*/ DevelopmentBoard__DOT__u_breakout__DOT__brickIndex;
        IData/*23:0*/ DevelopmentBoard__DOT__u_breakout__DOT__num;
        IData/*31:0*/ DevelopmentBoard__DOT__u_breakout__DOT__brickState;
        IData/*31:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickState;
        IData/*31:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__brickIndex;
        IData/*23:0*/ __Vdly__DevelopmentBoard__DOT__u_breakout__DOT__num;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 32> DevelopmentBoard__DOT__u_breakout__DOT__brickX;
        VlUnpacked<CData/*0:0*/, 32> DevelopmentBoard__DOT__u_breakout__DOT__brickY;
        VlUnpacked<SData/*9:0*/, 8> DevelopmentBoard__DOT__u_breakout__DOT__brickPX;
        VlUnpacked<SData/*9:0*/, 4> DevelopmentBoard__DOT__u_breakout__DOT__brickPY;
    };
    VlTriggerVec<5> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<10> __VactTriggered;
    VlTriggerVec<10> __VnbaTriggered;

    // INTERNAL VARIABLES
    VDevelopmentBoard__Syms* const vlSymsp;

    // CONSTRUCTORS
    VDevelopmentBoard___024root(VDevelopmentBoard__Syms* symsp, const char* v__name);
    ~VDevelopmentBoard___024root();
    VL_UNCOPYABLE(VDevelopmentBoard___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
