/* 00223af8: shadow/marker draw (sibling of 002236d0). zl90 w3910, C++ -O2 -fno-strict-aliasing.
   Partial asm: the VU0 matrix block, two register pins ($14 for the anim table pointer and the
   scale word) and one empty asm use of ctl (lifts ctl over the anim/offset local for s1). */
#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef f32 FMTX[4][4] __attribute__((aligned(16)));

// Shared render-work types (same layout as batch_w1674_nsa.cpp).
struct PrtMtx { f32 m[4][4]; } __attribute__((aligned(16)));
struct PrtWork { u8 pad0[0x10]; FMTX world; u128 view[4]; };
struct PrtState { u8 pad0[0xa8]; u64 flags; };
struct PrtFrame { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct PrtAnim { u8 pad0[6]; s16 count; u8 pad8[8]; PrtFrame frames[1]; };
struct PrtAnimRef { PrtAnim* anim; s32 x4; };
struct PrtBank { u8 pad0[0x14]; PrtAnimRef* anims; };
// Draw request (scratchpad packet header).
struct PrtReq { s32 type; s32 w4; f32 f8; s32 w12; s32 rgba[4]; u8 pad32[16]; u128 mtx[4]; };
// Shadow/marker entry: position; w is either 1.0f or 4 control bytes
// (alpha, frame, angle, scale).
struct PrtEnt { f32 pos[3]; f32 w; } __attribute__((aligned(16)));

extern "C" {
extern PrtWork* D_01d9e6e8;
extern PrtBank* D_01d9e6e4;
extern PrtState* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern FMTX D_01d9e730;
extern FMTX D_01d9e8c0;
struct PrtEnt64 { u8 pad0[48]; f32 pos[3]; f32 w; } __attribute__((aligned(16)));
extern PrtEnt64* D_00354688;
extern s32 D_0035468c;
void func_0021cda0(s32);
PrtReq* func_0021e988(void);
PrtReq* func_0021e998(void);
PrtReq* func_0021e9a8(void);
void func_0021cdd0(u8*, PrtReq*);
void func_001e7538(void);
void func_0020e0a0(void);


void func_00223af8(u32 idx, u8* rgba, u8 mode) {
    func_0021cda0(mode);
    PrtReq* r0 = func_0021e988();
    PrtReq* r1 = func_0021e998();
    if (rgba[3] >= 255) r0->type = r1->type = 2;
    else r0->type = r1->type = 0;
    r0->f8 = r1->f8 = 0.0f;
    r0->rgba[0] = r1->rgba[0] = rgba[0];
    r0->rgba[1] = r1->rgba[1] = rgba[1];
    r0->rgba[2] = r1->rgba[2] = rgba[2];
    r0->rgba[3] = r1->rgba[3] = rgba[3];
    if (idx == 0xffff) return;
    for (s32 i = 0; i < D_0035468c; i++) {
        u8* ctl = 0;
        f32 tenth = 0.1f;
        u32 fv = 0;
        f32 sc = 1.0f;
        u32 av = i * 64;
        PrtEnt64* e = (PrtEnt64*)(av + (u32)D_00354688);
        u8* w = (u8*)&e->w;
        if (e->w != sc) ctl = w;
        if (ctl && !ctl[0]) continue;
        PrtReq* r = func_0021e9a8();
        if (ctl) {
            r->rgba[3] = ctl[0];
            sc = ctl[3];
            fv = ctl[1];
            sc *= tenth;
        }
        u32 ofs = idx * 8;
        u32 eo = (u32)&D_00354688[i];
        { register u8* ab asm("$14") = (u8*)D_01d9e6e4->anims + ofs; av = (u32)((PrtAnimRef*)ab)->anim; }
#define anim ((PrtAnim*)av)
        fv = (u32)&anim->frames[fv];
        u8* data = (u8*)anim + ((PrtFrame*)fv)->dataOfs;
        register f32 sci asm("$14") = sc;
        asm volatile(
            "vsub.wxyz $vf4, $vf0, $vf0\n\tvadd.w $vf4, $vf4, $vf0\n\t"
            "vmr32.wxyz $vf3, $vf4\n\tvmr32.wxyz $vf2, $vf3\n\tvmr32.wxyz $vf1, $vf2\n\t"
            "qmtc2 %0, $vf7\n\tvmulx.xyz $vf1, $vf1, $vf7x\n\tvmulx.xyz $vf2, $vf2, $vf7x\n\tvmulx.xyz $vf3, $vf3, $vf7x\n\t"
            "lqc2 $vf8, 48(%1)\n\tvmove.w $vf8, $vf0\n\tvmove.wxyz $vf4, $vf8\n\t"
            "lqc2 $vf9, 0(%2)\n\tlqc2 $vf10, 16(%2)\n\tlqc2 $vf11, 32(%2)\n\tlqc2 $vf12, 48(%2)\n\t"
            "lqc2 $vf13, 0(%3)\n\tlqc2 $vf14, 16(%3)\n\tlqc2 $vf15, 32(%3)\n\tlqc2 $vf16, 48(%3)\n\t"
            "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf1x\n\tvmadday.wxyz ACC, $vf14, $vf1y\n\tvmaddaz.wxyz ACC, $vf15, $vf1z\n\tvmaddw.wxyz $vf1, $vf16, $vf1w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf2x\n\tvmadday.wxyz ACC, $vf14, $vf2y\n\tvmaddaz.wxyz ACC, $vf15, $vf2z\n\tvmaddw.wxyz $vf2, $vf16, $vf2w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf3x\n\tvmadday.wxyz ACC, $vf14, $vf3y\n\tvmaddaz.wxyz ACC, $vf15, $vf3z\n\tvmaddw.wxyz $vf3, $vf16, $vf3w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf4x\n\tvmadday.wxyz ACC, $vf14, $vf4y\n\tvmaddaz.wxyz ACC, $vf15, $vf4z\n\tvmaddw.wxyz $vf4, $vf16, $vf4w\n\t"
            "sqc2 $vf1, 0(%4)\n\tsqc2 $vf2, 16(%4)\n\tsqc2 $vf3, 32(%4)\n\tsqc2 $vf4, 48(%4)"
            : : "r"(sci), "r"(eo), "r"(D_01d9e730), "r"(D_01d9e8c0), "r"(D_01d9e6e8->view) : "memory");
        for (s32 k = 0; k < 1; k++) ;
        r->mtx[0] = D_01d9e6e8->view[0];
        r->mtx[1] = D_01d9e6e8->view[1];
        r->mtx[2] = D_01d9e6e8->view[2];
        r->mtx[3] = D_01d9e6e8->view[3];
        func_0021cdd0(data, r);
        asm("" :: "r"(ctl)); // extra use of ctl: it takes s1 like the original
        r->type = 10;
        if (ctl && D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
            if (++ctl[1] >= anim->count) {
                if (((PrtFrame*)fv)->flags & 0x80) {
                    ctl[1] = 0;
                } else {
                    ctl[0] = 0;
                    ctl[1] = 0;
                }
            }
        }
    }
    func_001e7538();
    func_0020e0a0();
}
#undef anim
}
