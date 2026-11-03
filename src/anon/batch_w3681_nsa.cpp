// 00224358 (nsa): the empty asm reading sys gives the D_01d9e6e4 load one more dependent, so sched2 puts it before the mult.
#include "../common/types.h"
struct Prm224358 {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; s32 w76; s32 pad80[4];
};
struct Hdr224358 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; u8 pad4[18]; u16 h22; };
struct Slot224358 { u8 pad[28]; Hdr224358* h; s32 w32; };
struct Sys224358 { u8 pad[16]; Slot224358* slots; };
struct Sys2224358 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Mtx224358 { f32 m[15]; f32 w; } __attribute__((aligned(16)));
extern Sys224358* D_01d9e6e4;
extern Sys2224358* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
extern Mtx224358 D_01d9ea00;
extern Mtx224358* D_00354688;
extern s32 D_0035468c;
extern "C" {
s32 func_0020f1e0(Hdr224358*, Prm224358*, s32);
void func_00224358(u32 idx, u8* rgba, u8 b2, u8 b3) {
    Prm224358 prm;
    if (idx == 0xffff) return;
    Sys224358* sys = D_01d9e6e4; Slot224358* s = &sys->slots[idx];
    Hdr224358* h = s->h; asm("" : "=r"(h) : "0"(h), "r"(sys));
    Sys2224358* g = D_01d9e6e8;
    prm.w68 = 0;
    prm.p44 = 0;
    prm.p40 = 0;
    prm.p36 = 0;
    prm.b10 = 0;
    prm.w28 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.p32 = g->a80;
    prm.flags = 36;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    if (!h->b0) prm.flags = 44;
    if (!h->b1) prm.flags |= 0x10;
    if (b2) prm.flags |= 0x200;
    if (b3) prm.flags |= 0x100;
    *(u16*)((u8*)&prm + 8) = h->h22;
    prm.c24 = rgba[0];
    prm.c25 = rgba[1];
    prm.c26 = rgba[2];
    prm.c27 = rgba[3];
    for (s32 i = 0; i < D_0035468c; i++) {
        Mtx224358* e = (Mtx224358*)((u8*)(i * 64) + (u32)D_00354688);
        u8* p = (u8*)&e->w;
        u8* col = 0;
        f32 sc = 1.0f;
        if (e->w != 1.0f) col = p;
        if (col) {
            if (!col[0]) continue;
            prm.c27 = col[0];
            sc = col[3];
            sc *= 0.1f;
        }
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\tvmove.w $vf4, $vf0\n\t"
                     "lqc2 $vf5, 0(%1)\n\tlqc2 $vf6, 16(%1)\n\tlqc2 $vf7, 32(%1)\n\tlqc2 $vf8, 48(%1)\n\t"
                     "qmtc2 %3, $vf9\n\tvmulx.xyz $vf1, $vf1, $vf9x\n\tvmulx.xyz $vf2, $vf2, $vf9x\n\tvmulx.xyz $vf3, $vf3, $vf9x\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf1x\n\tvmadday.wxyz ACC, $vf6, $vf1y\n\tvmaddaz.wxyz ACC, $vf7, $vf1z\n\tvmaddw.wxyz $vf1, $vf8, $vf1w\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf2x\n\tvmadday.wxyz ACC, $vf6, $vf2y\n\tvmaddaz.wxyz ACC, $vf7, $vf2z\n\tvmaddw.wxyz $vf2, $vf8, $vf2w\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf3x\n\tvmadday.wxyz ACC, $vf6, $vf3y\n\tvmaddaz.wxyz ACC, $vf7, $vf3z\n\tvmaddw.wxyz $vf3, $vf8, $vf3w\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf4x\n\tvmadday.wxyz ACC, $vf6, $vf4y\n\tvmaddaz.wxyz ACC, $vf7, $vf4z\n\tvmaddw.wxyz $vf4, $vf8, $vf4w\n\t"
                     "sqc2 $vf1, 0(%2)\n\tsqc2 $vf2, 16(%2)\n\tsqc2 $vf3, 32(%2)\n\tsqc2 $vf4, 48(%2)"
                     : : "r"(e), "r"(&D_01d9ea00), "r"(D_01d9e6e8->a80), "r"(sc) : "memory");
        prm.w52 = D_01d9eaa4;
        D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
    }
}
}
