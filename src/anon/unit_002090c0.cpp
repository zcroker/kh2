// Linked unit 0x00208cb0-0x00209328 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
typedef f32 FMTX65b[4][4] __attribute__((aligned(16)));
typedef f32 FMTX206[4][4] __attribute__((aligned(16)));
typedef f32 FMTX208[4][4] __attribute__((aligned(16)));

// 00208cb0 (was gap, written for the unit; was whole asm asm_00208cb0.s)
namespace n00208cb0 {
typedef f32 MtxD[4][4] __attribute__((aligned(16)));
struct VecD { f32 x, y, z, w; } __attribute__((aligned(16)));
struct ObjD { u8 pad[64]; } __attribute__((aligned(16)));
struct PkD {
    u32 flags;      /* 00 */
    void* tex;      /* 04 */
    u16 h08;        /* 08 */
    u8 b0a;         /* 0a */
    u8 pad0b;
    s32 f0c;        /* 0c */
    s64 pos;        /* 10 */
    u8 c[4];        /* 18 */
    s32 f1c;        /* 1c */
    void* mtx;      /* 20 */
    void* p24;      /* 24 */
    void* p28;      /* 28 */
    void* p2c;      /* 2c */
    void* p30;      /* 30 */
    s32 prev;       /* 34 */
    s32 f38;        /* 38 */
    s32 f3c;        /* 3c */
    s32 f40;        /* 40 */
    void* m2;       /* 44 */
    u8 pad48[4];
    u8 b4c;         /* 4c */
    u8 b4d;         /* 4d */
    u8 pad4e[0x12];
};
struct ModelD { u32 w0; u8 pad4[18]; u16 h22; };
struct EntD { u8 pad0[28]; ModelD* model; s32 f32; u8 pad36[0]; };
struct BankD { u8 pad0[16]; EntD* ents; };
struct ViewD { u8 pad0[144]; s32 f90; s32 f94; };
struct PartD { u8 pad0[64]; u16 on; s8 c[4]; u8 pad70[152 - 70]; f32 x, y; u8 pad160[168 - 160]; f32 fade; u8 pad172[4]; };
struct ColD { f32 r, g, b, a; u8 pad[16]; };
struct EmD { f32 v[4]; PartD* parts; u8* p20; ColD* cols; s32 count; };
struct ParD { u8 pad0[4]; s32 id; u8 b8, b9, b10, b11, b12, b13; u8 pad14[2]; f32 x, y, z; u8 pad28[266 - 28]; u8 b266; };
struct CtxD { u8 pad0[12]; s32* off; };
extern BankD* D_01d9e6e4 asm("D_01d9e6e4");
extern ViewD* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern f32 D_01d9e8c0[4][4] asm("D_01d9e8c0");
s32 func_00207308(EmD*, ParD*) asm("func_00207308");
void func_00208978(ObjD*, ParD*, EmD*) asm("func_00208978");
void func_00208a30(ObjD*, f32 (*)[4], ParD*, PartD*, u8*, f32 (*)[4], u8) asm("func_00208a30");
void sceVu0AddVector(f32*, f32*, VecD*) asm("sceVu0AddVector");
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]) asm("sceVu0MulMatrix");
s32 func_0020f1e0(ModelD*, PkD*, s32) asm("func_0020f1e0");
void func_00208cb0(u8* base, ParD* d, CtxD* c) asm("func_00208cb0");
static inline void ini(PkD* q, void* m) { q->f1c = 0; q->f38 = D_01d9e6e8->f90; q->f3c = D_01d9e6e8->f94; q->tex = D_01d9eac0; q->f0c = 0; q->flags = 32; q->mtx = m; q->pos = 0; q->f40 = 0; }
void func_00208cb0(u8* base, ParD* d, CtxD* c)
{
    EmD* e = (EmD*)(base + c->off[2] + 160);
    u8* col = base + c->off[1] + 160;
    PartD* pt = e->parts;
    u8* w = e->p20;
    ColD* cl = e->cols;
    s32 n = e->count;
    ObjD o;
    MtxD m;
    MtxD m2;
    VecD v;
    PkD p;
    EntD* ent;
    ModelD* md;
    s32 cr, cg, ca, cb;
    if (!func_00207308(e, d)) return;
    if (d->id == 0xffff) return;
    func_00208978(&o, d, e);
    ent = &D_01d9e6e4->ents[d->id];
    md = ent->model;
    if (d->b13) {
        p.m2 = m2;
        v.x = d->x;
        v.y = d->y;
        v.z = d->z;
        *(s32*)&v.w = 0;
    } else {
        p.m2 = 0;
    }
    p.p2c = 0;
    p.p28 = 0;
    p.p24 = 0;
    p.b0a = 0;
    ini(&p, m);
    if (d->b8 & 2) { p.flags = 36; if ((md->w0 & 1) == 0) p.flags |= 8; }
    else { if (d->b8 & 1) p.flags = 160; if ((md->w0 & 1) == 0) p.flags |= 8; }
    if ((md->w0 & 2) == 0) p.flags |= 0x10;
    if (d->b9) p.flags |= 0x200;
    if (d->b11) p.flags |= 0x100;
    p.h08 = md->h22;
    p.b4c = d->b12;
    p.b4d = d->b266;
    cr = col[8];
    cg = col[9];
    cb = col[10];
    ca = col[11];
    for (s32 i = 0; i < n; i++) {
        if (pt->on) {
            s32 r, g, b, a;
            func_00208a30(&o, m, d, pt, w, m2, d->b13);
            if (d->b13) {
                sceVu0AddVector(m2[3], m2[3], &v);
                sceVu0MulMatrix(m2, D_01d9e8c0, m2);
            }
            a = (s32)((f32)ca + (f32)pt->c[3] - pt->fade);
            r = cr + pt->c[0];
            g = cg + pt->c[1];
            b = cb + pt->c[2];
            if (cl) {
                r += (s32)cl->r;
                g += (s32)cl->g;
                b += (s32)cl->b;
                a += (s32)cl->a;
            }
            if (r < 0) r = 0; else if (r >= 256) r = 255;
            if (g < 0) g = 0; else if (g >= 256) g = 255;
            if (b < 0) b = 0; else if (b >= 256) b = 255;
            if (a < 0) a = 0; else if (a >= 128) a = 127;
            p.c[0] = r;
            p.c[1] = g;
            p.c[2] = b;
            p.c[3] = a;
            *(s32*)&p.pos = (s32)(pt->x * 65536.0f);
            *((s32*)&p.pos + 1) = (s32)(pt->y * 65536.0f);
            p.prev = D_01d9eaa4;
            D_01d9eaa4 = func_0020f1e0(md, &p, ent->f32);
        }
        if (w) w += 64;
        if (cl) cl++;
        pt++;
    }
}
}  // namespace n00208cb0

// 002090c0 (was gap, written for the unit)
namespace n002090c0 {
typedef unsigned int u128g __attribute__((mode(TI)));
struct EmH { u128g v; u8* parts; u8* p20; u8* p24; s32 count; u16 h32; u16 h34; };
void func_002090c0(u8* base, u8* c) asm("func_002090c0");
void func_002090c0(u8* base, u8* c) {
    u8* b = base + (*(s32**)(c + 12))[2];
    *(u128g*)(b + 160) = 0;
    EmH* e = (EmH*)(b + 160);
    e->parts = 0;
    e->p20 = 0;
    e->p24 = 0;
    e->count = 0;
    e->h32 = 0;
    e->h34 = 0;
}
}  // namespace n002090c0

// 002090f8 (was src/anon/auto80_199_queue.cpp)
namespace n002090f8 {
/*TARGET 002090f8*/
void func_002090f8(u32 a0, u32 a1) asm("_Z13func_002090f8jj");
void func_002090f8(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6 + 160;

    u32 p0 = *(u32*)(s0 + 16);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 16) = 0;
    }

    u32 p1 = *(u32*)(s0 + 20);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s0 + 20) = 0;
    }

    u32 p2 = *(u32*)(s0 + 24);
    if (p2 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p2);
        *(u32*)(s0 + 24) = 0;
    }
}
}  // namespace n002090f8

// 00209178 (was src/anon/batch_w274.cpp)
namespace n00209178 {
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
static inline V4 operator*(const M4& m, const V4& v) {
    V4 r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
/*TARGET 00209178*/
void func_00209178(u8* a0, f32* m) asm("func_00209178");
void func_00209178(u8* a0, f32* m) {
    f32 w, h, b;
    switch (a0[49]) { case 1: w = 0.48999998f; break; case 2: w = 0.24f; break; case 0: default: w = 0.98999995f; break; }
    switch (a0[50]) { case 1: h = 0.48999998f; break; case 2: h = 0.24f; break; case 0: default: h = 0.98999995f; break; }
    switch (a0[51]) { case 1: b = 0.25f; break; case 2: b = 0.5f; break; case 3: b = 0.75f; break; case 0: default: b = 0.0f; break; }
    f32 x1 = b + w;
    f32 y0 = 0.01f;
    f32 x0 = b + y0;
    f32 z = 1.0f;
    m[0] = m[4] = m[24] = m[28] = x0;
    m[8] = m[12] = m[16] = m[20] = x1;
    m[5] = m[13] = m[21] = m[29] = h;
    m[1] = m[9] = m[17] = m[25] = y0;
    m[2] = m[6] = m[10] = m[14] = m[18] = m[22] = m[26] = m[30] = z;
}
}  // namespace n00209178

// 002092e0 (was src/anon/batch_w35.cpp)
namespace n002092e0 {
// 0x001e2c00: definition moved into src/anon/unit_001e0cb8.cpp

u8 func_00209178(void*, void*) asm("func_00209178");
/*TARGET 002092e0*/
void func_002092e0(u8* a, u32* b, u8* c) asm("func_002092e0");
void func_002092e0(u8* a, u32* b, u8* c) {
    u8* t = a + *(s32*)(*(u8**)(c + 12) + 8) + 160;
    if (*b == *(u32*)(a + 12)) {
        struct NoTail { ~NoTail() {} } g; // keeps the call a jal
        func_00209178(b, t);
    }
}
}  // namespace n002092e0

