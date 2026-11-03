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
void u_call0_0020df70() {
    W3728_NoTail nt;
    register w3728_u128 v asm("$13") = 0x20000000;   // t5: the tag quadword
    W3728_Tag* p = D_01dac450;
    register s32 i asm("$12");                      // t4: loop counter
    for (i = 287; i >= 0; i--) {
        p->q = v;
        p->w.x4 = p + 1;
        p->w.x8 = p;
        asm volatile("");                           // keeps the decrement after the stores
        p++;
    }
    p->q = v;
    // the original issues lui a0 before the store and addiu a0 right after it
    register u8* a asm("$4");
    asm("lui %0,%%hi(D_01da8bb0)" : "=r"(a));
    p->w.x0 = 0x70000000;
    asm volatile("addiu %0,%0,%%lo(D_01da8bb0)" : "+r"(a));
    func_0020e7a8(a, 9, 0, 0);
    func_0020e800(D_01da8c40, 9, 15, 0);
}
