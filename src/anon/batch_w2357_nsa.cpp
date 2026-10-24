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
extern PrtMtx D_01d9ea40;
extern f32 D_00359a20[];
extern PrtEnt* D_00354680;
extern s32 D_00354684;
void func_0021cda0(s32);
PrtReq* func_0021e988(void);
PrtReq* func_0021e998(void);
PrtReq* func_0021e9a8(void);
void func_0021cdd0(u8*, PrtReq*);
void func_001e7538(void);
void func_0020e0a0(void);

// Draws animation idx once per entry of the D_00354680 list: rotated about Z
// and scaled by the entry's control bytes, then steps the entry's frame.
void func_002236d0(u32 idx, u8* rgba, u8 mode) {
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
    for (s32 i = 0; i < D_00354684; i++) {
        PrtMtx m;
        u8* ctl = 0;
        u32 ang = 0;
        u32 frame = 0;
        f32 sc = 1.0f;
        PrtEnt* e = (PrtEnt*)(i * 16 + (u32)D_00354680);
        u8* w = (u8*)&e->w;
        if (e->w != sc) ctl = w;
        if (ctl && !ctl[0]) continue;
        PrtReq* r = func_0021e9a8();
        if (ctl) {
            r->rgba[3] = ctl[0];
            sc = ctl[3];
            sc *= 0.1f;
            frame = ctl[1];
            if (ctl[2]) {
                ang = ctl[2];
                ang <<= 8;
            }
        }
        if (ang == 0) {
            // 128-bit copy of the unit matrix
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(&m), "r"(&D_01d9ea40) : "$8", "$9", "$10", "$11", "memory");
        } else {
            f32 s = D_00359a20[ang >> 4];
            f32 c = D_00359a20[((ang + 0x4000) >> 4) & 0xfff];
            m.m[0][0] = c; m.m[1][0] = -s; m.m[2][0] = 0.0f; m.m[3][0] = 0.0f;
            m.m[0][1] = s; m.m[1][1] = c; m.m[2][1] = 0.0f; m.m[3][1] = 0.0f;
            m.m[0][2] = 0.0f; m.m[1][2] = 0.0f; m.m[2][2] = 1.0f; m.m[3][2] = 0.0f;
            m.m[0][3] = 0.0f; m.m[1][3] = 0.0f; m.m[2][3] = 0.0f; m.m[3][3] = 1.0f;
        }
        u32 ofs = idx * 8;
        PrtAnim* anim = ((PrtAnimRef*)((u8*)D_01d9e6e4->anims + ofs))->anim;
        PrtFrame* fr = &anim->frames[frame];
        u8* data = (u8*)anim + fr->dataOfs;
        // VU0: scale the rotation, local = A * pos, view = B * [rot | local]
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "qmtc2 %1, $vf7\n\tvmulx.xyz $vf1, $vf1, $vf7x\n\tvmulx.xyz $vf2, $vf2, $vf7x\n\tvmulx.xyz $vf3, $vf3, $vf7x\n\t"
            "lqc2 $vf4, 0(%2)\n\tvmove.w $vf4, $vf0\n\t"
            "lqc2 $vf9, 0(%3)\n\tlqc2 $vf10, 16(%3)\n\tlqc2 $vf11, 32(%3)\n\tlqc2 $vf12, 48(%3)\n\t"
            "lqc2 $vf13, 0(%4)\n\tlqc2 $vf14, 16(%4)\n\tlqc2 $vf15, 32(%4)\n\tlqc2 $vf16, 48(%4)\n\t"
            "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf1x\n\tvmadday.wxyz ACC, $vf14, $vf1y\n\tvmaddaz.wxyz ACC, $vf15, $vf1z\n\tvmaddw.wxyz $vf1, $vf16, $vf1w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf2x\n\tvmadday.wxyz ACC, $vf14, $vf2y\n\tvmaddaz.wxyz ACC, $vf15, $vf2z\n\tvmaddw.wxyz $vf2, $vf16, $vf2w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf3x\n\tvmadday.wxyz ACC, $vf14, $vf3y\n\tvmaddaz.wxyz ACC, $vf15, $vf3z\n\tvmaddw.wxyz $vf3, $vf16, $vf3w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf4x\n\tvmadday.wxyz ACC, $vf14, $vf4y\n\tvmaddaz.wxyz ACC, $vf15, $vf4z\n\tvmaddw.wxyz $vf4, $vf16, $vf4w\n\t"
            "sqc2 $vf1, 0(%5)\n\tsqc2 $vf2, 16(%5)\n\tsqc2 $vf3, 32(%5)\n\tsqc2 $vf4, 48(%5)"
            : : "r"(&m), "r"(sc), "r"(&D_00354680[i]), "r"(D_01d9e730), "r"(D_01d9e8c0), "r"(D_01d9e6e8->view) : "memory");
        // An empty one-trip loop: the original has a basic-block boundary here
        // (the view-pointer lui after the VU0 block is not shared with the copies).
        for (s32 k = 0; k < 1; k++) ;
        r->mtx[0] = D_01d9e6e8->view[0];
        r->mtx[1] = D_01d9e6e8->view[1];
        r->mtx[2] = D_01d9e6e8->view[2];
        r->mtx[3] = D_01d9e6e8->view[3];
        func_0021cdd0(data, r);
        r->type = 10;
        if (ctl && D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
            if (++ctl[1] >= anim->count) {
                if (fr->flags & 0x80) {
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
}
