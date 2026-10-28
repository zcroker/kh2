#include "../common/types.h"
// 00246ab8: builds the menu sprite/layout objects for up to 4 entries.
extern "C" {
struct O6ab8 {
    u8 pad[24];
    u8 sub[384];
    u32 f198;
    u8 pad19c[20];
    s32 f1b0;
};
struct Q6ab8 { u8 d[408]; };
struct R6ab8 { u8 d[32]; };
struct M6ab8 {
    O6ab8 o[18];
    Q6ab8 q[16];
    R6ab8 r[9];
};
union U6ab8 { M6ab8* p; s32 i; u32 u; };
extern U6ab8 D_0035ed40;
extern void* D_0035ed20;
extern s32 D_0035ed28;
extern s32 D_0035f3d4;
extern s16 D_00371cc8[];
void func_002fde18(void*, s32, s32);
s32 func_00246968(s32);
void* func_002891b8(void*, s32);
s32 func_002891e8(void*);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(void*, void*);
void func_00139620(void*);
void func_001395f8(void*);
u32 func_00192048(s32);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00138c68(void*, s32, s32);

void func_00246ab8(void) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r32;
    s16* hp;
    void* obj;
    O6ab8* o;
    Q6ab8* q;
    s32 x;
    s32 y;

    i = 0;
    j = 0;
    func_002fde18(&D_0035ed40.p->r[0], 0, 128);
    func_002fde18(&D_0035ed40.p->r[4], 0, 128);
    func_002fde18(&D_0035ed40.p->r[8], 0, 32);
    a = D_0035f3d4 + 1;
    b = D_0035f3d4 + 2;
    for (; i < 4; i++) {
        if (func_00246968(i)) {
            r32 = j * 32;
            obj = func_002891b8(D_0035ed20, j);
            q = &D_0035ed40.p->q[j];
            func_0028d8c0(q, a, 0, 0, D_0035ed28, 30, -1, 0);
            func_0028dcc0(q, obj);
            q = &D_0035ed40.p->q[4 + j];
            func_0028d8c0(q, b, 0, 0, D_0035ed28, D_00371cc8[i], -1, 0);
            func_0028dcc0(q, &D_0035ed40.p->q[j]);
            o = &D_0035ed40.p->o[2 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 38, -1, -1, 0);
            func_0028dcc0(o, obj);
            func_00139620(o);
            func_001395f8(o);
            o->f198 = func_00192048(0xcc0a);
            x = func_0023aa18(o->sub);
            y = func_0023aa38(o->sub);
            o = &D_0035ed40.p->o[6 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 96, -1, -1, 0);
            func_0028dcc0(o, &D_0035ed40.p->o[2 + j]);
            func_00139620(o);
            func_001395f8(o);
            func_00138c68(o, x, y);
            o->f198 = (u32)((u8*)D_0035ed40.p + r32) + 14376;
            o->f1b0 = 1;
            o = &D_0035ed40.p->o[10 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 39, -1, -1, 0);
            func_0028dcc0(o, obj);
            func_00139620(o);
            func_001395f8(o);
            o->f1b0 = 2;
            x = func_0023aa18(o->sub);
            y = func_0023aa38(o->sub);
            o = &D_0035ed40.p->o[14 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 96, -1, -1, 0);
            func_0028dcc0(o, &D_0035ed40.p->o[10 + j]);
            func_00139620(o);
            func_001395f8(o);
            func_00138c68(o, x, y);
            o->f198 = (u32)((u8*)D_0035ed40.p + r32) + 14504;
            o->f1b0 = 2;
            q = &D_0035ed40.p->q[12 + j];
            func_0028d8c0(q, a, 0, 0, D_0035ed28, 96, -1, 0);
            func_0028dcc0(q, obj);
            q = &D_0035ed40.p->q[8 + j];
            func_0028d8c0(q, b, 0, 0, D_0035ed28, 31, -1, 0);
            func_0028dcc0(q, &D_0035ed40.p->q[j]);
            j++;
        }
    }
    o = &D_0035ed40.p->o[1];
    func_0028d980(o, a + 2, 0, 0, D_0035ed28, 96, -1, -1, 0);
    func_0028dcc0(o, &D_0035ed40.p->q[8 + func_002891e8(D_0035ed20)]);
    func_00139620(o);
    func_001395f8(o);
    o->f198 = (u32)&D_0035ed40.p->r[8];
    o->f1b0 = 2;
}

}

// 00223e98: draws animation idx n times along a line for each D_00354688 matrix entry.
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
extern PrtMtx* D_00354688;
extern s32 D_0035468c;
void func_0021cda0(s32);
PrtReq* func_0021e988(void);
PrtReq* func_0021e998(void);
PrtReq* func_0021e9a8(void);
void func_0021cdd0(u8*, PrtReq*);
void func_001e7538(void);
void func_0020e0a0(void);

// VU0 macro code below is hand-written (no memory clobber, as in the original).
void func_00223e98(u32 idx, u8* rgba, u8 mode, s32 unused, u32 n, f32 scale, f32 len) {
    PrtAnim* anim; PrtFrame* fr;
    f32 step = len / n;
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
u8* ctl = 0; f32 sc = 1.0f; f32 off = -(n * 0.5f * step); u32 frame = 0;
        PrtMtx* e = (PrtMtx*)(i * 64 + (u32)D_00354688);
        u8* w = (u8*)&e->m[3][3];
        if (e->m[3][3] != 1.0f) ctl = w;
        if (ctl && !ctl[0]) continue;
        for (u32 j = 0; j < n; j++) {
            PrtReq* r = func_0021e9a8();
            if (ctl) {
                r->rgba[3] = ctl[0];
                sc = ctl[3];
                frame = ctl[1];
                sc *= scale * 0.1f;
            }
            u32 ofs = idx * 8;
            anim = ((PrtAnimRef*)((u8*)D_01d9e6e4->anims + ofs))->anim;
            fr = &anim->frames[frame];
            u8* data = (u8*)anim + fr->dataOfs;
            asm volatile(
            "vsub.wxyz $vf4, $vf0, $vf0\n\tvadd.w $vf4, $vf4, $vf0\n\t"
            "vmr32.wxyz $vf3, $vf4\n\tvmr32.wxyz $vf2, $vf3\n\tvmr32.wxyz $vf1, $vf2\n\t"
            "qmtc2 %0, $vf7\n\tvmulx.xyz $vf1, $vf1, $vf7x\n\tvmulx.xyz $vf2, $vf2, $vf7x\n\tvmulx.xyz $vf3, $vf3, $vf7x\n\t"
            "lqc2 $vf8, 48(%1)\n\tvmove.w $vf8, $vf0\n\t"
            "qmtc2 %2, $vf5\n\tlqc2 $vf6, 32(%1)\n\tvmulx.xyz $vf6, $vf6, $vf5x\n\tvadd.wxyz $vf8, $vf8, $vf6\n\tvmove.wxyz $vf4, $vf8\n\t"
            "lqc2 $vf9, 0(%3)\n\tlqc2 $vf10, 16(%3)\n\tlqc2 $vf11, 32(%3)\n\tlqc2 $vf12, 48(%3)\n\t"
            "lqc2 $vf13, 0(%4)\n\tlqc2 $vf14, 16(%4)\n\tlqc2 $vf15, 32(%4)\n\tlqc2 $vf16, 48(%4)\n\t"
            "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf1x\n\tvmadday.wxyz ACC, $vf14, $vf1y\n\tvmaddaz.wxyz ACC, $vf15, $vf1z\n\tvmaddw.wxyz $vf1, $vf16, $vf1w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf2x\n\tvmadday.wxyz ACC, $vf14, $vf2y\n\tvmaddaz.wxyz ACC, $vf15, $vf2z\n\tvmaddw.wxyz $vf2, $vf16, $vf2w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf3x\n\tvmadday.wxyz ACC, $vf14, $vf3y\n\tvmaddaz.wxyz ACC, $vf15, $vf3z\n\tvmaddw.wxyz $vf3, $vf16, $vf3w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf4x\n\tvmadday.wxyz ACC, $vf14, $vf4y\n\tvmaddaz.wxyz ACC, $vf15, $vf4z\n\tvmaddw.wxyz $vf4, $vf16, $vf4w\n\t"
            "sqc2 $vf1, 0(%5)\n\tsqc2 $vf2, 16(%5)\n\tsqc2 $vf3, 32(%5)\n\tsqc2 $vf4, 48(%5)"
            : : "r"(sc), "r"(&D_00354688[i]), "r"(off), "r"(D_01d9e730), "r"(D_01d9e8c0), "r"(D_01d9e6e8->view) );
            r->mtx[0] = D_01d9e6e8->view[0];
            r->mtx[1] = D_01d9e6e8->view[1];
            r->mtx[2] = D_01d9e6e8->view[2];
            r->mtx[3] = D_01d9e6e8->view[3];
            off += step;
            func_0021cdd0(data, r);
            r->type = 10;
        }
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
