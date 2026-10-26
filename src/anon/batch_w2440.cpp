#include "../common/types.h"

/* 001c5060: static init/destruction hook. The 64.0f literal is at 0x36de94
   (lui 0x37 + -8556), inside file data (word 0x42800000). */
struct T16_w2440 { u32 w[4]; ~T16_w2440() {} } __attribute__((aligned(16)));
struct Arr_w2440 { T16_w2440 e[8]; };

extern "C" {

/* 001a0920 */
struct A2_w2440 { u8 pad0[3]; s8 id; s32 fl; u16 h8; u8 pad[0x36]; u16 h40; };
struct BB_w2440 { u8 pad[0x1cc]; u32 bits[1]; };
struct B_w2440 { u8 pad[0x48c]; BB_w2440* p; };
s32 func_001778c0(B_w2440*, s8);
s32 func_00177958(B_w2440*);
u32 func_0019c090(B_w2440*);

/* The whole body is an inline helper: its return variable (t2) is shared by
   every return and copied to v0 once at the end. */
static inline __attribute__((always_inline)) s32 check_001a0920(A2_w2440* a, B_w2440* b) {
    if (a->h8 == 0) return 0;
    u32 f = a->h40;
    if (f != 0 && !(*(u32*)((u8*)b->p->bits + ((f >> 5) << 2)) & (1 << (f & 0x1f)))) return 0;
    if (func_0019c090(b) != (u32)(a->fl & 1)) return 0;
    if ((u8)((a->fl >> 2) & 1)) { if (!func_001778c0(b, a->id)) return 0; }
    else if (func_00177958(b)) return 0;
    return 1;
}

s32 func_001a0920(A2_w2440* a, B_w2440* b) {
    return check_001a0920(a, b);
}

/* 001c5060 */
struct W3_w2440 { u32 a; u32 b; f32 c; };
extern W3_w2440 D_01d49580;
extern W3_w2440 D_01d49658[30];
extern Arr_w2440 D_01d49590;
void wt_001c5060(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c5060jjjj");
void wt_001c5060(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d49580.a = 0;
        D_01d49580.b = 1368;
        D_01d49580.c = 64.0f;
    }
    if (b == 0xffff && a == 1) {
        W3_w2440* p = D_01d49658;
        s32 i = 29;
        do { p->b = 0; i--; p++; } while (i != -1);
    }
    if (b == 0xffff && a == 0) {
        D_01d49590.~Arr_w2440();
    }
}

}
