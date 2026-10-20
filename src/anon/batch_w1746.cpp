/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
#include "../common/types.h"

// 00311aa0 is libgcc's __muldi3 (libgcc2.c, gcc 3.2-ee-040921), byte-identical to the toolchain's libgcc.a.
typedef int W1746SItype __attribute__((mode(SI)));
typedef unsigned int W1746USItype __attribute__((mode(SI)));
typedef int W1746DItype __attribute__((mode(DI)));
typedef unsigned int W1746UDItype __attribute__((mode(DI)));
struct W1746DWstruct { W1746SItype low, high; };
typedef union { struct W1746DWstruct s; W1746DItype ll; } W1746DWunion;

// 16-byte element with an empty destructor; the array's destructor loop survives as an empty loop.
struct W1746Elem { u32 w[4]; ~W1746Elem() {} } __attribute__((aligned(16)));
struct W1746ElemArray { W1746Elem e[64]; };

extern "C" {
extern W1746ElemArray* D_0034c7a0;
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");

void func_00165968(void) {
    W1746ElemArray* p = D_0034c7a0;
    if (p) {
        p->~W1746ElemArray();
        LoadDataFree(p);
        D_0034c7a0 = 0;
    }
}

W1746DItype muldi3_00311aa0(W1746DItype u, W1746DItype v) asm("_Z13func_00311aa0xx");
W1746DItype muldi3_00311aa0(W1746DItype u, W1746DItype v)
{
    W1746DWunion w;
    W1746DWunion uu, vv;
    uu.ll = u, vv.ll = v;
    w.ll = (W1746UDItype)(W1746USItype)uu.s.low * (W1746USItype)vv.s.low;
    w.s.high += ((W1746USItype)uu.s.low * (W1746USItype)vv.s.high
                 + (W1746USItype)uu.s.high * (W1746USItype)vv.s.low);
    return w.ll;
}
}
