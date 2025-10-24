// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard__pch.h"
#include "VDevelopmentBoard__Syms.h"
#include "VDevelopmentBoard___024root.h"

// Parameter definitions for VDevelopmentBoard___024root
constexpr VlUnpacked<CData/*7:0*/, 512> VDevelopmentBoard___024root::DevelopmentBoard__DOT__ColorBar_inst__DOT__vga_pic_inst__DOT__CHAR_DATA;


void VDevelopmentBoard___024root___ctor_var_reset(VDevelopmentBoard___024root* vlSelf);

VDevelopmentBoard___024root::VDevelopmentBoard___024root(VDevelopmentBoard__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VDevelopmentBoard___024root___ctor_var_reset(this);
}

void VDevelopmentBoard___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

VDevelopmentBoard___024root::~VDevelopmentBoard___024root() {
}
