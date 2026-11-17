// Linked unit 0x0021e988-0x002200c0: draw/shape.c after whole-asm 0x21d048 (rodata from 0x370b48).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// gcc's soft double libcalls are the game's copies (libgcc would bring its own).
asm("fptodp = func_00313b80");
asm("dpadd = func_00313e80");
asm("dpmul = func_00313f40");
asm("dptoul = func_00314508");

// 0021e988 (was src/anon/tiny_more2.cpp)
namespace n0021e988 {
/*TARGET 0021e988*/
// 0x001ee5c8: definition moved into src/anon/unit_001ec098.cpp

u32 func_0021e988(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0021e988jjjj");
// 0x001ee5c8: definition moved into src/anon/unit_001ec098.cpp

u32 func_0021e988(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; return 0x70001e00u; }
}  // namespace n0021e988

// 0021e998 (was src/anon/tiny_more2.cpp)
namespace n0021e998 {
/*TARGET 0021e998*/
u32 func_0021e998(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0021e998jjjj");
u32 func_0021e998(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; return 0x70002f00u; }
}  // namespace n0021e998

// 0021e9a8 (was src/anon/tiny_leaf_more.cpp)
namespace n0021e9a8 {
/*TARGET 0021e9a8*/
// 0x0019ff78: definition moved into src/anon/unit_0019fb70.cpp

u32 func_0021e9a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0021e9a8jjjj");
// 0x0019ff78: definition moved into src/anon/unit_0019fb70.cpp

u32 func_0021e9a8(u32 a0, u32 a1, u32 a2, u32 a3) {  // select_vif_regs
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r13 = (u32)(0x01dau << 16);
    r14 = (u32)(0x7000u << 16);
    r15 = (u32)(*(u8*)((u32)r13 + (s32)(-6480)));
    r2 = (u32)(0x7000u << 16);
    r14 = (u32)(r14 | 0x1e00u);
    r2 = (u32)(r2 | 0x2f00u);
    r15 = (u32)(r15 ^ 0x0001u);
    *(u8*)((u32)r13 + (s32)(-6480)) = (u8)r15;
    if (r15 == 0u) r2 = r14;
    return r2;
}
}  // namespace n0021e9a8

// 0021e9d0 (was src/anon/batch_w64.cpp)
namespace n0021e9d0 {
// ---------------------------------------------------------------------------
extern f32 D_00359a20[] asm("D_00359a20");
/*TARGET 0021e9d0*/
// Rotation matrix about X from a 16-bit angle (sine table lookup).
void func_0021e9d0(f32* m, u32 a) asm("func_0021e9d0");
// Rotation matrix about X from a 16-bit angle (sine table lookup).
void func_0021e9d0(f32* m, u32 a) {  // table_float_pair_lookup_c
    f32 s = D_00359a20[(a >> 4) & 0xfff];
    f32 c = D_00359a20[((a + 0x4000) >> 4) & 0xfff];
    m[0] = 1.0f; m[4] = 0; m[8] = 0; m[12] = 0;
    m[1] = 0; m[5] = c; m[9] = -s; m[13] = 0;
    m[2] = 0; m[6] = s; m[10] = c; m[14] = 0;
    m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1.0f;
}
}  // namespace n0021e9d0

// 0021ea50 (was src/anon/batch_w65.cpp)
namespace n0021ea50 {
// 0x001d7cd0: definition moved into src/anon/unit_001d7458.cpp

// Y-axis rotation matrix from the sine table (angle in 1/65536 turns).
extern f32 D_00359a20[] asm("D_00359a20");
/*TARGET 0021ea50*/
void func_0021ea50(f32* m, u32 a) asm("func_0021ea50");
void func_0021ea50(f32* m, u32 a) {  // table_float_pair_lookup_b
    f32 s = D_00359a20[(a >> 4) & 0xfff];
    f32 c = D_00359a20[((a + 0x4000) >> 4) & 0xfff];
    m[0] = c; m[4] = 0; m[8] = s; m[12] = 0;
    m[1] = 0; m[5] = 1.0f; m[9] = 0; m[13] = 0;
    m[2] = -s; m[6] = 0; m[10] = c; m[14] = 0;
    m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1.0f;
}
}  // namespace n0021ea50

// 0021ead0 (was src/anon/batch_w50.cpp)
namespace n0021ead0 {
extern f32 D_00359a20[] asm("D_00359a20");
/*TARGET 0021ead0*/
// Rotation about Z from a 16-bit angle (4096-entry sine table).
void func_0021ead0(f32* m, u32 ang) asm("func_0021ead0");
// Rotation about Z from a 16-bit angle (4096-entry sine table).
void func_0021ead0(f32* m, u32 ang) {  // table_float_pair_lookup
    f32 s = D_00359a20[(ang >> 4) & 0xfff];
    f32 c = D_00359a20[((ang + 0x4000) >> 4) & 0xfff];
    m[0] = c; m[4] = -s; m[8] = 0; m[12] = 0;
    m[1] = s; m[5] = c; m[9] = 0; m[13] = 0;
    m[2] = 0; m[6] = 0; m[10] = 1.0f; m[14] = 0;
    m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1.0f;
}
}  // namespace n0021ead0

// 0021eb50 (was src/anon/auto80_199_queue.cpp)
namespace n0021eb50 {
/*TARGET 0021eb50*/
void func_0021eb50(void* a0, u32 a1) asm("_Z13func_0021eb50Pvj");
void func_0021eb50(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ea50(&b0, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    func_0021ead0(&b1, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021e9d0(&b3, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}
}  // namespace n0021eb50

// 0021ebe8 (was src/anon/auto80_199_queue.cpp)
namespace n0021ebe8 {
/*TARGET 0021ebe8*/
void func_0021ebe8(void* a0, u32 a1) asm("_Z13func_0021ebe8Pvj");
void func_0021ebe8(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021e9d0(&b0, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    func_0021ead0(&b1, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ea50(&b3, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}
}  // namespace n0021ebe8

// 0021ec80 (was src/anon/auto80_199_queue.cpp)
namespace n0021ec80 {
/*TARGET 0021ec80*/
void func_0021ec80(void* a0, u32 a1) asm("_Z13func_0021ec80Pvj");
void func_0021ec80(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ead0(&b0, *(u32*)(s0 + 8));  // table_float_pair_lookup
    func_0021e9d0(&b1, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ea50(&b3, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}
}  // namespace n0021ec80

// 0021ed18 (was src/anon/auto80_199_queue.cpp)
namespace n0021ed18 {
/*TARGET 0021ed18*/
void func_0021ed18(void* a0, u32 a1) asm("_Z13func_0021ed18Pvj");
void func_0021ed18(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021ea50(&b0, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    func_0021e9d0(&b1, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ead0(&b3, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}
}  // namespace n0021ed18

// 0021edb0 (was src/anon/auto80_199_queue.cpp)
namespace n0021edb0 {
/*TARGET 0021edb0*/
void func_0021edb0(void* a0, u32 a1) asm("_Z13func_0021edb0Pvj");
void func_0021edb0(void* a0, u32 a1) {
    u32 s0 = a1;
    S64 b0;
    S64 b1;
    S64 b2;
    S64 b3;

    func_0021e9d0(&b0, *(u32*)(s0 + 0));  // table_float_pair_lookup_c
    func_0021ea50(&b1, *(u32*)(s0 + 4));  // table_float_pair_lookup_b
    sceVu0MulMatrix((u32)&b2, (u32)&b0, (u32)&b1);
    func_0021ead0(&b3, *(u32*)(s0 + 8));  // table_float_pair_lookup
    sceVu0MulMatrix((u32)a0, (u32)&b2, (u32)&b3);
}
}  // namespace n0021edb0

// 0021ee48 (was src/anon/batch_w1887_nsa.cpp)
namespace n0021ee48 {
struct E24 { u8 pad[0x14]; s32 base; u8 p2[0x24-0x18]; };
struct G8 { s16 a; s16 n; u16* list; };
struct DA { u8 pad[0x10]; E24* e; u8 p1[4]; G8* g; };
struct DB { u8 pad[0x90]; s32 base; };
extern DA* D_01d9e6e4 asm("D_01d9e6e4");
extern DB* D_01d9e6e8 asm("D_01d9e6e8");
s32 func_00222568() asm("func_00222568");
typedef void (*CB)(s32, s32, s32);
/*TARGET 0021ee48*/
void func_0021ee48(s32 a0, s32 a1, CB cb, u16* pidx, s16 gi, u8 rnd, u8 cnt) asm("func_0021ee48");
void func_0021ee48(s32 a0, s32 a1, CB cb, u16* pidx, s16 gi, u8 rnd, u8 cnt) {
    G8* g = &D_01d9e6e4->g[gi];
    s32 base = D_01d9e6e8->base;
    s32 i;
    if (base == 0) base = D_01d9e6e4->e[g->a].base;
    if (rnd) i = func_00222568() % g->n;
    else i = *pidx;
    while (cnt != 0) {
        cb(a0, a1, base + g->list[i++] * 6);
        if (rnd) i = func_00222568() % g->n;
        else if (i >= g->n) i = 0;
        cnt--;
    }
    *pidx = i;
}
}  // namespace n0021ee48

// 0021efa8 (was src/anon/tiny_leaf.cpp)
namespace n0021efa8 {
/*TARGET 0021efa8*/
// 0x001e2760: definition moved into src/anon/unit_001e0cb8.cpp

void func_0021efa8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0021efa8jjjj");
// 0x001e2760: definition moved into src/anon/unit_001e0cb8.cpp

void func_0021efa8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r5 + (s32)(0));
    r14 = (u32)(*(u16*)((u32)r15 + (s32)(18)));
    *(u8*)((u32)r4 + (s32)(2)) = (u8)0u;
    *(u16*)((u32)r4 + (s32)(0)) = (u16)r14;
}
}  // namespace n0021efa8

// 0021efc0 (was src/anon/batch_w2368_nsa.cpp)
namespace n0021efc0 {
// 0021efc0: sprite animation frame table (header with frame count, then 8-byte frames).
struct W2368AnimFrame { u16 a; s16 dur; s8 flags; u8 pad[3]; };
struct W2368AnimHdr { u8 pad[6]; s16 count; u8 pad8[8]; W2368AnimFrame frm[1]; };
struct W2368AnimState { s16 time; u8 frame; };
struct W2368AnimObj { W2368AnimHdr** hdr; W2368AnimState* st; };
/*TARGET 0021efc0*/
// Advances the animation clock by 0x200; on reaching the frame's duration steps to the next
// frame, and at the end of the table either rewinds (flag 0x80) or holds the last frame.
void func_0021efc0(W2368AnimObj* o) asm("func_0021efc0");
// Advances the animation clock by 0x200; on reaching the frame's duration steps to the next
// frame, and at the end of the table either rewinds (flag 0x80) or holds the last frame.
void func_0021efc0(W2368AnimObj* o) {
    W2368AnimState* st = o->st;
    W2368AnimFrame* f = &(*o->hdr)->frm[st->frame];
    st->time += 0x200;
    if (st->time >= f->dur) {
        st->time -= f->dur;
        st->frame++;
        if (st->frame >= (*o->hdr)->count) {
            if (f->flags & 0x80) {
                st->frame = 0;
                st->time = 0;
            } else {
                st->frame--;
                st->time = 0;
            }
        }
    }
}
}  // namespace n0021efc0

// 0021f060 (was src/anon/batch_w1765_nsa.cpp)
namespace n0021f060 {
struct W1765E0 { u8 pad[0x10]; s16 h; };
struct W1765Hd { u8* base; };
struct W1765S3 { W1765Hd* a; u8* b; u8 pad8[8]; u8 p10[2]; u16 f12; u8 p14[4]; s32 f18; s16 f1c; u8 p1e[6]; s32 f24; u8 f28; };
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
s32 func_0021d048(u8*, void*, s32) asm("func_0021d048");
/*TARGET 0021f060*/
void func_0021f060(W1765S3* p) asm("func_0021f060");
void func_0021f060(W1765S3* p) {
    W1765Hd* a = p->a;
    W1765E0* e = (W1765E0*)(a->base + p->b[2] * 8);
    p->f18 = 0;
    p->f28 = 0;
    p->f24 = D_01d9eaa4;
    p->f1c = 0x12;
    p->f12 |= 0x30;
    D_01d9eaa4 = func_0021d048(a->base + e->h, &p->p10, 0);
}
}  // namespace n0021f060

// 0021f0d8 (was src/anon/batch_w3859_nsa.c)
namespace n0021f0d8 {
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct {
    f32 m[4][4];        /* 0x00 world matrix */
    f32 r[3][4];        /* 0x40 facing rows */
    f32 v[4];           /* 0x70 x, y, scale, alpha */
    f32 ofs[3];         /* 0x80 */
    u8 pad8c[2];
    u8 near;            /* 0x8e */
    u8 mode;            /* 0x8f */
    f32 dir[4];         /* 0x90 (w = cone) */
    f32 pada0;
    f32 len;            /* 0xa4 */
    f32 range;          /* 0xa8 */
} ObjF0d8;
typedef struct { ObjF0d8* obj; f32* pos; f32 (*mat)[4]; } ArgF0d8;
extern f32 D_01d9e840[4][4] asm("D_01d9e840");
extern f32 D_01d9e8c0[4][4] asm("D_01d9e8c0");
void sceVu0CopyMatrix(f32 (*)[4], f32 (*)[4]) asm("sceVu0CopyMatrix");
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*) asm("sceVu0ApplyMatrix");
void sceVu0ScaleVector(f32*, f32*, f32) asm("sceVu0ScaleVector");
void sceVu0SubVector(f32*, f32*, f32*) asm("sceVu0SubVector");
void sceVu0UnitMatrix(f32 (*)[4]) asm("sceVu0UnitMatrix");
void sceVu0CopyVector(f32*, f32*) asm("sceVu0CopyVector");
void sceVu0Normalize(f32*, f32*) asm("sceVu0Normalize");
f32 sceVu0InnerProduct(f32*, f32*) asm("sceVu0InnerProduct");
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]) asm("sceVu0MulMatrix");
f32 func_002229a0(f32*) asm("func_002229a0");
f32 func_002229d8(f32*) asm("func_002229d8");
/*TARGET 0021f0d8*/
void func_0021f0d8(ArgF0d8* a) asm("func_0021f0d8");
void func_0021f0d8(ArgF0d8* a)
{
    f32 m[4][4];
    f32 l[4][4];
    f32 va[4];
    f32 vb[4];
    f32 vc[4];
    ObjF0d8* o;
    f32 k, d, t;
    o = a->obj;
    sceVu0CopyMatrix(l, a->mat);
    if (o->mode) {
        sceVu0CopyMatrix(m, l);
        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        sceVu0ApplyMatrix(va, m, a->pos);
        sceVu0ScaleVector(vb, l[3], -1.0f);
        sceVu0SubVector(vc, vb, va);
    } else {
        k = 1.0f;
        *(u128*)va = 0;
        *(u128*)vb = 0;
        va[3] = k;
        vb[3] = k;
        sceVu0UnitMatrix(m);
        m[3][0] = D_01d9e840[3][0] + o->ofs[0];
        m[3][1] = D_01d9e840[3][1] + o->ofs[1];
        m[3][2] = D_01d9e840[3][2] + o->ofs[2];
        sceVu0MulMatrix(m, D_01d9e8c0, m);
        sceVu0ApplyMatrix(va, m, va);
        sceVu0ScaleVector(va, va, k / va[3]);
        sceVu0UnitMatrix(m);
        sceVu0CopyVector(m[3], D_01d9e840[3]);
        sceVu0MulMatrix(m, D_01d9e8c0, m);
        sceVu0ApplyMatrix(vb, m, vb);
        k = k / vb[3];
        sceVu0ScaleVector(vb, vb, k);
        sceVu0SubVector(vc, vb, va);
        vc[2] = 512.0f;
    }
    sceVu0UnitMatrix(o->m);
    sceVu0ApplyMatrix(o->m[3], l, a->pos);
    if (vc[0] == 0.0f && vc[1] == 0.0f) {
        sceVu0CopyVector(o->v, o->m[3]);
    } else {
        asm volatile(
            "lqc2 $vf18, 0(%0)\n"
            "vmul.xy $vf26, $vf18, $vf18\n"
            "vaddy.x $vf26, $vf26, $vf26y\n"
            "vsqrt Q, $vf26x\n"
            "vsub.wz $vf22, $vf0, $vf0\n"
            "vsub.w $vf21, $vf0, $vf0\n"
            "vsub.wxy $vf20, $vf0, $vf0\n"
            "vaddw.z $vf20, $vf0, $vf0w\n"
            "sqc2 $vf20, 32(%1)\n"
            "vwaitq\n"
            "vaddq.x $vf26, $vf0, Q\n"
            "vdiv Q, $vf0w, $vf26x\n"
            "lqc2 $vf17, 0(%2)\n"
            "sqc2 $vf17, 48(%1)\n"
            "vwaitq\n"
            "vmulq.xy $vf22, $vf18, Q\n"
            "sqc2 $vf22, 0(%1)\n"
            "vopmula.xyz ACC, $vf22, $vf20\n"
            "vopmsub.xyz $vf21, $vf20, $vf22\n"
            "sqc2 $vf21, 16(%1)\n"
            : : "r"(vc), "r"(o->r), "r"(o->m[3]) : "memory");
    }
    if (o->mode) {
        o->v[2] = o->m[3][2] * 0.001953125f;
    } else {
        o->v[2] = (D_01d9e840[3][2] + o->ofs[2]) * 0.001953125f;
    }
    sceVu0Normalize(vc, vc);
    o->v[0] = vc[0] * o->v[2];
    o->v[1] = vc[1] * o->v[2];
    sceVu0SubVector(vb, vb, va);
    d = func_002229a0(vb);
    o->len = func_002229d8(vb);
    sceVu0Normalize(va, vb);
    if (o->mode) {
        vb[0] = 0.0f;
        vb[1] = 0.0f;
        vb[2] = k = 1.0f;
        vb[0] = (k - (k - sceVu0InnerProduct(vb, va)) * 0.5f) / 0.3f;
        o->v[3] = (k < vb[0]) ? 0.0f : k - vb[0];
        if (o->dir[3] >= 0.0f) {
            sceVu0CopyMatrix(m, l);
            m[3][0] = 0.0f;
            m[3][1] = 0.0f;
            m[3][2] = 0.0f;
            sceVu0ApplyMatrix(vb, m, vb);
            vb[0] = (1.0f - sceVu0InnerProduct(o->dir, va)) * 0.5f;
            vb[0] = vb[0] / o->dir[3];
            vb[0] = (1.0f < vb[0]) ? 0.0f : 1.0f - vb[0];
            o->v[3] = o->v[3] * vb[0];
        }
        va[0] = o->range - o->near;
        if (va[0] > 0.0f) {
            va[0] = d / va[0];
            d = (1.0f <= va[0]) ? 0.0f : 1.0f - va[0];
            o->v[3] = o->v[3] * d;
        } else {
            o->v[3] = 0.0f;
        }
    } else {
        if (o->range > 0.0f) {
            o->v[3] = o->len / o->range;
            o->v[3] = (1.0f < o->v[3]) ? 0.0f : 1.0f - o->v[3];
        } else {
            o->v[3] = 0.0f;
        }
    }
}
}  // namespace n0021f0d8

// 0021f5d8 (was src/anon/batch_w34.cpp)
namespace n0021f5d8 {
// 0x001e60b0: definition moved into src/anon/unit_001e0cb8.cpp

void sceVu0UnitMatrix(void*) asm("sceVu0UnitMatrix");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
/*TARGET 0021f5d8*/
void func_0021f5d8(u8* p) asm("func_0021f5d8");
void func_0021f5d8(u8* p) {
    D_01d9e6e0[168] = 2;
    sceVu0UnitMatrix(p + 64);  // vu_store_w_splat
    *(f32*)(p + 172) = 1.0f;
}
}  // namespace n0021f5d8

// 0021f620 (was src/anon/batch_w2354_nsa.cpp)
namespace n0021f620 {
struct M21f620 { f32 m[4][4]; };
struct C21f620 { u8 r, g, b, a; };
struct E21f620 { s32 f0; f32 t; };
struct H21f620 { u8* obj; s32 n; u8 cnt; u8 pad9; s16 sx; s16 sy; u8 flip; u8 pad15; E21f620 e[1]; };
struct S21f620 { s32 n; E21f620* p; u8 pad8[8]; u16 f16; s16 f18; C21f620 col; s32 f24; s16 h28; s16 h30; M21f620* mtx; u8 pad36[8]; s32 f44; u8 pad48[16]; };
struct A21f620 { H21f620* h; s32 col; s32 f8; f32 scale; f32 fade; f32* rot; };
void U21f620_ucall4(M21f620*, u8*) asm("_Z16sceVu0CopyMatrixjjjj");
void sceVu0UnitMatrix(M21f620*) asm("sceVu0UnitMatrix");
void U21f620_wtarget(M21f620*, s32, M21f620*) asm("_Z15sceVu0MulMatrixjjjj");
void func_0021efc0(S21f620*) asm("func_0021efc0");
void func_0021f060(S21f620*) asm("func_0021f060");
extern u8 D_01d9e360 asm("D_01d9e360");
extern M21f620 D_01d9e840 asm("D_01d9e840");
/*TARGET 0021f620*/
/* Draw a strip of sprites along a line: per entry, step the position, fade the alpha
   and scale the sprite matrix, then submit it (sibling of func_0021fa28). */
void func_0021f620(A21f620* a, s32 id) asm("func_0021f620");
/* Draw a strip of sprites along a line: per entry, step the position, fade the alpha
   and scale the sprite matrix, then submit it (sibling of func_0021fa28). */
void func_0021f620(A21f620* a, s32 id) {
    M21f620 m;
    M21f620 w;
    S21f620 st;
    H21f620* h;
    u8* o;
    h = a->h;
    o = h->obj;
    if (o == &D_01d9e360) return;
    if (h->n == 0) return;
    if (*(f32*)(o + 124) == 0.0f) return;
    if (*(u8*)(o + 143)) {
        U21f620_ucall4(&m, o);
    } else {
        sceVu0UnitMatrix(&m);
        m.m[3][2] = D_01d9e840.m[3][2] + *(f32*)(o + 136);
    }
    *(s32*)&st.col = a->col;
    st.n = h->n;
    st.f18 = id;
    st.mtx = &w;
    st.f44 = 0;
    st.f24 = 0;
    st.h28 = 0;
    st.h30 = 0;
    f32 bx, by;
    if (*(u8*)(o + 143)) {
        bx = by = 0.0f;
    } else {
        bx = D_01d9e840.m[3][0];
        by = D_01d9e840.m[3][1];
    }
    f32 sy = h->sy;
    f32 sx = h->sx;
    f32 al = *(f32*)(o + 112);
    bx += al * sy;
    f32 dx = al * sx;
    al = *(f32*)(o + 116);
    by += al * sy;
    f32 dy = al * sx;
    al = *(f32*)(o + 164);
    al -= *(u8*)(o + 142);
    if (al <= 0.0f) al = 0.0f;
    else {
        al = al / (a->fade * *(f32*)(o + 120));
        if (1.0f < al) al = 1.0f;
    }
    if (h->flip) al = 1.0f - al;
    al *= (f32)st.col.a * *(f32*)(o + 124);
    E21f620* e = h->e;
    s32 n = h->cnt;
    while (n > 0) {
        f32 t = e->t;
        st.p = e;
        n--;
        func_0021efc0(&st);
        e++;
        bx += dx * t;
        by += dy * t;
        m.m[3][0] = bx;
        m.m[3][1] = by;
        st.col.a = (u8)(al * (t * 0.75 + 0.25));
        t *= a->scale;
        m.m[0][0] = *(f32*)o * t * a->rot[0];
        m.m[1][1] = *(f32*)(o + 20) * t * a->rot[1];
        U21f620_wtarget(&w, a->f8, &m);
        func_0021f060(&st);
    }
}
}  // namespace n0021f620

// 0021f908 (was src/anon/batch_w80.cpp)
namespace n0021f908 {
// ---- unit 6 (good21f.cpp)
struct U6_Osc { f32 f0; f32 val; };
struct U6_OscSet { u8 pad[4]; u32 f4; u8 n; u8 flags; u8 pad2[6]; U6_Osc e[1]; };
void func_0021efa8(U6_Osc*, u32) asm("func_0021efa8");
/*TARGET 0021f908*/
void func_0021f908(U6_OscSet* s, u32 a, u32 seed) asm("func_0021f908");
void func_0021f908(U6_OscSet* s, u32 a, u32 seed) {
    s32 i;
    s->f4 = a;
    for (i = 0; i < s->n; i++) func_0021efa8(&s->e[i], a);
    if (s->flags & 1) return;
    {
        u32 sd = seed;
        for (i = 0; i < s->n; i++) {
            sd = (u16)(sd * 2061 + 7);
            s->e[i].val = (f32)(s32)sd / 65535.0f;
        }
    }
    s->flags |= 1;
}
}  // namespace n0021f908

// 0021fa10 (was src/anon/tiny_auto80_solver.cpp)
namespace n0021fa10 {
void func_0021fa10(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0021fa10jjjjjjjj");
extern u8 D_01d9e360 asm("D_01d9e360");
/*TARGET 0021fa10*/
void func_0021fa10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0021fa10jjjjjjjj");
void func_0021fa10(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_01d9e360;
    *(u32*)((u32)r4 + (s32)(4)) = 0u;
    *(u8*)((u32)r4 + (s32)(9)) = (u8)0u;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
}
}  // namespace n0021fa10

// 0021fa28 (was src/anon/batch_w1652_nsa.cpp)
namespace n0021fa28 {
struct W1652M21fa28 { f32 m[4][4]; };
struct W1652C21fa28 { u8 r, g, b, a; };
struct W1652S21fa28 { s32 n; u8* p; u8 pad8[8]; u16 f16; s16 f18; W1652C21fa28 col; s32 f24; s32 f28; W1652M21fa28* mtx; u8 pad36[8]; s32 f44; u8 pad48[16]; };
struct W1652H21fa28 { u8* obj; s32 n; };
struct W1652A21fa28 { W1652H21fa28* h; s32 col; s32 f8; f32 scale; f32* rot; };
void W1652_ucall4(W1652M21fa28*, u8*) asm("_Z16sceVu0CopyMatrixjjjj");
void sceVu0UnitMatrix(W1652M21fa28*) asm("sceVu0UnitMatrix");
void sceVu0ScaleVector(f32, f32*, f32*) asm("sceVu0ScaleVector");
void W1652_wtarget(W1652M21fa28*, s32, W1652M21fa28*) asm("_Z15sceVu0MulMatrixjjjj");
void func_0021efc0(W1652S21fa28*) asm("func_0021efc0");
void func_0021f060(W1652S21fa28*) asm("func_0021f060");
extern u8 D_01d9e360 asm("D_01d9e360");
extern W1652M21fa28 D_01d9e840 asm("D_01d9e840");
/*TARGET 0021fa28*/
void func_0021fa28(W1652A21fa28* a, s32 id) asm("func_0021fa28");
void func_0021fa28(W1652A21fa28* a, s32 id) {
    W1652M21fa28 m;
    W1652S21fa28 st;
    W1652H21fa28* h;
    u8* o;
    h = a->h;
    o = h->obj;
    if (o == &D_01d9e360) return;
    if (h->n == 0) return;
    if (*(f32*)(o + 124) == 0.0f) return;
    if (*(u8*)(o + 143)) {
        W1652_ucall4(&m, o);
    } else {
        sceVu0UnitMatrix(&m);
        m.m[3][0] = D_01d9e840.m[3][0] + *(f32*)(o + 128);
        m.m[3][1] = D_01d9e840.m[3][1] + *(f32*)(o + 132);
        m.m[3][2] = D_01d9e840.m[3][2] + *(f32*)(o + 136);
    }
    m.m[0][0] *= a->scale;
    m.m[1][1] *= a->scale;
    sceVu0ScaleVector(a->rot[0], m.m[0], m.m[0]);
    sceVu0ScaleVector(a->rot[1], m.m[1], m.m[1]);
    sceVu0ScaleVector(a->rot[2], m.m[2], m.m[2]);
    W1652_wtarget(&m, a->f8, &m);
    *(s32*)&st.col = a->col;
    st.col.a = (s32)((f32)st.col.a * *(f32*)(o + 124));
    st.n = h->n;
    st.p = (u8*)h + 8;
    func_0021efc0(&st);
    st.f18 = id;
    st.mtx = &m;
    st.f44 = 0;
    st.f24 = 0;
    st.f28 = 0;
    func_0021f060(&st);
}
}  // namespace n0021fa28

// 0021fbc0 (was src/anon/tiny_auto80_solver.cpp)
namespace n0021fbc0 {
void func_0021fbc0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0021fbc0jjjjjjjj");
extern u8 D_01d9e360 asm("D_01d9e360");
/*TARGET 0021fbc0*/
void func_0021fbc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0021fbc0jjjjjjjj");
void func_0021fbc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_01d9e360;
    *(u32*)((u32)r4 + (s32)(4)) = 0u;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
}
}  // namespace n0021fbc0

// 0021fbd8 (was src/anon/batch_w110.cpp)
namespace n0021fbd8 {
struct V4r { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4r { V4r r[4]; };
struct Model {
    u8 pad0[48];
    V4r rows[4];
    u8 pad112[12];
    f32 scale;
    f32 off[3];
    u8 pad140[3];
    u8 noOffset;
    u8 pad144[20];
    f32 size;
};
struct DrawSrc { Model* model; u32 tex; u8 data[1]; };
struct DrawArg { DrawSrc* src; u32 color; void* mtx; f32 len; u16 div; u16 h; f32* scl; };
struct DrawReq {
    u32 tex;
    u32 data;
    u8 pad8[10];
    u16 id;
    union { u32 color; u8 c[4]; };
    u32 f24;
    u16 f28;
    u16 f30;
    M4r* mtx;
    u8 pad36[8];
    u32 f44;
    u8 pad48[16];
};
extern Model D_01d9e360 asm("D_01d9e360");
struct CamBlk { u8 pad[48]; f32 pos[3]; };
extern CamBlk D_01d9e840 asm("D_01d9e840");
void sceVu0CopyVector(V4r*, V4r*) asm("sceVu0CopyVector");
// memcpy16
void sceVu0ScaleVector(V4r*, V4r*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0MulMatrix(M4r*, void*, M4r*) asm("sceVu0MulMatrix");
void func_0021efc0(DrawReq*) asm("func_0021efc0");
void func_0021f060(DrawReq*) asm("func_0021f060");
/*TARGET 0021fbd8*/
// Builds a billboard matrix from the model rows (scaled by size/length) and queues the draw request.
void func_0021fbd8(DrawArg* a, u32 id) asm("func_0021fbd8");
// Builds a billboard matrix from the model rows (scaled by size/length) and queues the draw request.
void func_0021fbd8(DrawArg* a, u32 id) {
    M4r m;
    DrawReq req;
    DrawSrc* src = a->src;
    Model* md = src->model;
    if (md == &D_01d9e360) return;
    if (!src->tex) return;
    if (md->scale == 0.0f) return;
    sceVu0CopyVector(&m.r[0], &md->rows[1]);  // memcpy16
    sceVu0CopyVector(&m.r[1], &md->rows[2]);  // memcpy16
    sceVu0CopyVector(&m.r[2], &md->rows[3]);  // memcpy16
    sceVu0CopyVector(&m.r[3], &md->rows[0]);  // memcpy16
    f32 k = a->len * md->size / (f32)a->div;
    sceVu0ScaleVector(&m.r[0], &m.r[0], -k);  // vec_scale_by_f12
    sceVu0ScaleVector(&m.r[1], &m.r[1], k);  // vec_scale_by_f12
    if (!md->noOffset) {
        m.r[3].x = D_01d9e840.pos[0] + md->off[0];
        m.r[3].y = D_01d9e840.pos[1] + md->off[1];
        m.r[3].z = D_01d9e840.pos[2] + md->off[2];
    }
    sceVu0ScaleVector(&m.r[0], &m.r[0], a->scl[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(&m.r[1], &m.r[1], a->scl[1]);  // vec_scale_by_f12
    sceVu0ScaleVector(&m.r[2], &m.r[2], a->scl[2]);  // vec_scale_by_f12
    sceVu0MulMatrix(&m, a->mtx, &m);
    req.color = a->color;
    k = md->size / (f32)a->h;
    f32 lim = 1.0f;
    if (!(lim < k)) lim = k;
    req.c[3] = (s32)(req.c[3] * md->scale * lim);
    req.tex = src->tex;
    req.data = (u32)src->data;
    func_0021efc0(&req);
    req.id = id;
    req.mtx = &m;
    req.f44 = 0;
    req.f24 = 0;
    req.f28 = 0;
    req.f30 = 0;
    func_0021f060(&req);
}
}  // namespace n0021fbd8

// 0021fe08 (was src/anon/tiny_wrappers_more.cpp)
namespace n0021fe08 {
u32 func_0021efa8(u32, u32, u32, u32) asm("_Z13func_0021efa8jjjj");
/*TARGET 0021fe08*/
u32 func_0021fe08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0021fe08jjjj");
u32 func_0021fe08(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 4u) = (u32)(a1);
    return func_0021efa8(((u32)(a0) + 8u), a1, a2, a3);
}
}  // namespace n0021fe08

// 0021fe28 (was src/anon/tiny_auto80_solver.cpp)
namespace n0021fe28 {
void func_0021fe28(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0021fe28jjjjjjjj");
extern u8 D_01d9e360 asm("D_01d9e360");
/*TARGET 0021fe28*/
void func_0021fe28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0021fe28jjjjjjjj");
void func_0021fe28(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_01d9e360;
    *(u32*)((u32)r4 + (s32)(4)) = 0u;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
}
}  // namespace n0021fe28

// 0021fe40 (was src/anon/batch_w320.cpp)
namespace n0021fe40 {
struct V4r { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4r { V4r r[4]; };
struct Model {
    u8 pad0[124];
    f32 scale;
    f32 off[3];
    u8 pad140[3];
    u8 noOffset;
    u8 pad144[20];
    f32 size;
};
struct DrawSrc { Model* model; u32 tex; u8 data[1]; };
struct DrawArg { DrawSrc* src; u32 color; void* mtx; f32 len; u16 div; u8 mx; u8 my; f32* scl; };
struct DrawReq {
    u32 tex;
    u32 data;
    u8 pad8[10];
    u16 id;
    union { u32 color; u8 c[4]; };
    u32 f24;
    u16 f28;
    u16 f30;
    M4r* mtx;
    u8 pad36[8];
    u32 f44;
    u8 pad48[16];
};
struct CamBlk { u8 pad[48]; f32 pos[3]; };
extern Model D_01d9e360 asm("D_01d9e360");
extern CamBlk D_01d9e840 asm("D_01d9e840");
void sceVu0CopyMatrix(M4r*, Model*) asm("sceVu0CopyMatrix");
void sceVu0UnitMatrix(M4r*) asm("sceVu0UnitMatrix");
// vu_store_w_splat
void sceVu0ScaleVector(V4r*, V4r*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0MulMatrix(M4r*, void*, M4r*) asm("sceVu0MulMatrix");
void func_0021efc0(DrawReq*) asm("func_0021efc0");
void func_0021f060(DrawReq*) asm("func_0021f060");
/*TARGET 0021fe40*/
void func_0021fe40(DrawArg* a, u32 id) asm("func_0021fe40");
void func_0021fe40(DrawArg* a, u32 id) {
    M4r m;
    DrawReq req;
    DrawSrc* src = a->src;
    Model* md = src->model;
    if (md == &D_01d9e360) return;
    if (!src->tex) return;
    if (md->scale == 0.0f) return;
    f32 lim = 0.0f;
    f32 k = md->size / (f32)a->div;
    if (!(1.0f < k)) lim = 1.0f - k;
    if (md->noOffset) {
        sceVu0CopyMatrix(&m, md);
    } else {
        sceVu0UnitMatrix(&m);  // vu_store_w_splat
        m.r[3].x = D_01d9e840.pos[0] + md->off[0];
        m.r[3].y = D_01d9e840.pos[1] + md->off[1];
        m.r[3].z = D_01d9e840.pos[2] + md->off[2];
    }
    f32 s = a->len;
    m.r[0].x = s;
    switch (a->mx) {
    case 1: m.r[0].x = s * lim; break;
    case 2: m.r[0].x = s * (k + 1.0f); break;
    }
    m.r[1].y = s;
    switch (a->my) {
    case 1: m.r[1].y = s * lim; break;
    case 2: m.r[1].y = s * (k + 1.0f); break;
    }
    sceVu0ScaleVector(&m.r[0], &m.r[0], a->scl[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(&m.r[1], &m.r[1], a->scl[1]);  // vec_scale_by_f12
    sceVu0MulMatrix(&m, a->mtx, &m);
    req.color = a->color;
    req.c[3] = (s32)(req.c[3] * md->scale * lim);
    req.tex = src->tex;
    req.data = (u32)src->data;
    func_0021efc0(&req);
    req.id = id;
    req.mtx = &m;
    req.f44 = 0;
    req.f24 = 0;
    req.f28 = 0;
    req.f30 = 0;
    func_0021f060(&req);
}
}  // namespace n0021fe40

// 00220070 (was src/anon/tiny_auto80_solver.cpp)
namespace n00220070 {
void func_00220070(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00220070jjjjjjjj");
extern u8 D_01d9e360 asm("D_01d9e360");
/*TARGET 00220070*/
void func_00220070(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00220070jjjjjjjj");
void func_00220070(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_01d9e360;
    *(u32*)((u32)r4 + (s32)(4)) = 0u;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
}
}  // namespace n00220070

// 00220088 (was src/anon/tiny_auto80_queue.cpp)
namespace n00220088 {
/*TARGET 00220088*/
void func_00220088(u8* a0, u32 a1) asm("_Z13func_00220088Phj");
void func_00220088(u8* a0, u32 a1) {  // list_set_flag_clear
    u8* n = *(u8**)(a0 + 24);
    a1 |= 8;
    while (n != 0) {
        u32 f = *(u16*)(n + 62);
        *(u32*)(n + 12) = 0;
        f |= a1;
        *(u16*)(n + 62) = f;
        n = *(u8**)(n + 8);
    }
}
}  // namespace n00220088

