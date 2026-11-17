#include "../common/types.h"

// Builds a chain of 289 DMA tags (each points to the next and to itself), ends the chain, then inits two lists.
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
struct W3728_Tag { union { w3728_u128 q; struct { u32 x0; W3728_Tag* x4; W3728_Tag* x8; u32 xc; } w; }; };
extern W3728_Tag D_01dac450[289];
extern u8 D_01da8bb0[];
extern u8 D_01da8c40[];
struct W3728_NoTail { ~W3728_NoTail() {} };
extern "C" {
void func_0020e7a8(void*, s32, s32, s32);
void func_0020e800(void*, s32, s32, s32);
}
void u_call0_0020df70();  // 0x0020df70: definition moved into src/anon/unit_0020dde8.cpp
