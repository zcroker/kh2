// Linked unit 0x0020c580-0x0020cfd8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 0020c580 (was src/anon/batch_w1673.cpp)
namespace n0020c580 {
struct I20c580 { u8 pad[0x20]; u16 busy; u8 pad2[0xa0 - 0x22]; };
struct M20c580 { I20c580* items; u8* buf; s32 n; s32 pad; u16 tick; };
struct C20c580 { s32 pad; s32 x4; u8 pad2[4]; u16 max; u16 period; };
struct G20c580 { u8 pad[0xa8]; u64 flags; };
extern G20c580* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
void func_0020bdb0(void*, void*, void*, u8*) asm("func_0020bdb0");
void func_0020bef8(M20c580*, C20c580*, I20c580*, s32, u8*) asm("func_0020bef8");
/*TARGET 0020c580*/
void func_0020c580(M20c580* m, C20c580* c, s32 a2) asm("func_0020c580");
void func_0020c580(M20c580* m, C20c580* c, s32 a2) {
    s32 cnt = 0;
    I20c580* it = m->items;
    u8* buf = m->buf;
    s32 n = m->n;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (c->x4 == 0xffff) return;
    m->tick++;
    for (s32 i = 0; i < n; i++) {
        if (it->busy) {
            func_0020bef8(m, c, it, a2, buf);
        } else if (c->period <= m->tick) {
            if (cnt < c->max) {
                func_0020bdb0(m, c, it, buf);
                cnt++;
            }
        }
        it++;
        if (buf) buf += 32;
    }
    if (cnt > 0) m->tick = 0;
}
}  // namespace n0020c580

// 0020c6c0 (was gap, written for the unit)
namespace n0020c6c0 {
struct VG { f32 x, y, z, w; } __attribute__((aligned(16)));
struct EmG { u8* parts; u8* work; s32 count; f32 f12; u16 timer; u8 on; };
struct CtxG { u8 pad0[12]; s32* off; };
extern u8* D_01d9e6e4 asm("D_01d9e6e4");
extern VG D_01d9e7f0 asm("D_01d9e7f0");
extern VG D_00354bc0 asm("D_00354bc0");
u8* func_001e7698(u8*, s32) asm("func_001e7698");
void wtarget_002fde18(u8*, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void sceVu0SubVector(VG*, VG*, VG*) asm("sceVu0SubVector");
s32 func_0020a060(EmG*, u8*) asm("_Z13func_0020b4b8PhS_");
void func_0020c580(EmG*, u8*, u8*) asm("func_0020c580");
void func_0020c6c0(u8* base, u8* d, CtxG* c) asm("func_0020c6c0");
void func_0020c6c0(u8* base, u8* d, CtxG* c) {
    u8* b = base + c->off[2];
    u8* w = base + c->off[1] + 160;
    EmG* e = (EmG*)(b + 160);
    if (*(u8**)(b + 160) == 0) {
        e->count = *(u16*)(d + 10);
        if ((*(u8**)(b + 160) = func_001e7698(D_01d9e6e4, e->count * 160)) != 0)
            wtarget_002fde18(*(u8**)(b + 160), 0, e->count * 160);
        if (d[242]) {
            if ((e->work = func_001e7698(D_01d9e6e4, e->count << 5)) != 0)
                wtarget_002fde18(e->work, 0, e->count << 5);
        }
    }
    if (!func_0020a060(e, d)) return;
    if (d[240]) {
        VG v;
        f32 len;
        sceVu0SubVector(&v, &D_01d9e7f0, &D_00354bc0);
        asm volatile(
            "lqc2 $vf10,0(%1)\n"
            "vmul.xyz $vf10,$vf10,$vf10\n"
            "vaddx.y $vf10,$vf10,$vf10x\n"
            "vaddy.z $vf10,$vf10,$vf10y\n"
            "vsqrt Q,$vf10z\n"
            "vwaitq\n"
            "vaddq.x $vf10,$vf0,Q\n"
            "qmfc2 %0,$vf10\n" : "=r"(len) : "r"(&v));
        if (*(f32*)(d + 232) < len) {
            e->on = 0;
        } else {
            e->on = 1;
            if (*(f32*)(d + 232) - len < *(f32*)(d + 236)) e->f12 = (*(f32*)(d + 232) - len) / *(f32*)(d + 236);
            else e->f12 = 1.0f;
        }
    }
    if (e->on) func_0020c580(e, d, w);
}
}  // namespace n0020c6c0

// 0020c858 (was src/anon/misc_2.cpp)
namespace n0020c858 {
/*TARGET 0020c858*/
void func_0020c858(void* self) asm("_Z13func_0020c858Pv");
void func_0020c858(void* self) {}
}  // namespace n0020c858

// 0020c860 (was src/anon/batch_wcx2.cpp)
namespace n0020c860 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// 0x0024f528: definition moved into src/anon/unit_0024e7e8.cpp

// --------------------
// Build an object's world matrix: rotation (fixed-point angles), per-axis scale, translation, then the height offset.
struct Src20c860 { f32 pos[4]; u8 pad16[24]; union { u64 xy; s32 r[2]; } rot; s32 rz; u8 pad52[32]; f32 scl[3]; };
struct Par20c860 { u8 pad[224]; f32 hs; f32 ho; };
extern u8 D_01d9ea40[] asm("D_01d9ea40");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void func_002f4000_x15402(f32* m) asm("sceVu0UnitMatrix");
void sceVu0RotMatrix(f32* o, void* a, f32* v) asm("sceVu0RotMatrix");
void func_002f3d08_x15404(f32* o, void* a, void* b) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(f32* o, f32* a, f32 s) asm("sceVu0ScaleVector");
void func_002f3f88_x15406(f32* o, Src20c860* a) asm("sceVu0CopyVector");
void func_002f3cd8_x15407(f32* o, void* a, f32* b) asm("sceVu0ApplyMatrix");
/*TARGET 0020c860*/
f32 func_0020c860(void* self, f32* m, Par20c860* par, void* a3, Src20c860* src) asm("func_0020c860");
f32 func_0020c860(void* self, f32* m, Par20c860* par, void* a3, Src20c860* src)
{
    f32 rm[16];
    f32 ang[4];
    s32 i;
    f32* row;
    f32 z;
    func_002f4000_x15402(m);
    if (src->rot.xy || src->rz) {
        for (i = 0; i < 3; i++)
            ang[i] = (f32)src->rot.r[i] * 3.1415927f * 3.0517578125e-05f;
        sceVu0RotMatrix(rm, D_01d9ea40, ang);
        func_002f3d08_x15404(m, m, rm);
    }
    for (i = 0; i < 3; i++)
        sceVu0ScaleVector(m + i * 4, m + i * 4, src->scl[i]);
    func_002f3f88_x15406(m + 12, src);
    func_002f3cd8_x15407(m + 12, D_01d9e730, m + 12);
    m[13] *= par->hs;
    z = m[14];
    m[13] += par->ho;
    func_002f3d08_x15404(m, D_01d9e8c0, m);
    return z;
}
}  // namespace n0020c860

// 0020c9d0 (was src/anon/batch_w2425_nsa.cpp)
namespace n0020c9d0 {
/* ---- 0020c9d0 ---- */
struct Ent20c9d0 { u8 pad[0x1c]; u16* data; s32 f20; };
struct Tbl20c9d0 { u8 pad[0x10]; Ent20c9d0* ents; };
struct Ctx20c9d0 { u8 pad[0x90]; s32 f90; s32 f94; };
struct Param20c9d0 {
    u32 flags;      /* 00 */
    void* p04;      /* 04 */
    u16 h08;        /* 08 */
    u8 b0a;         /* 0a */
    u8 pad0b;
    s32 f0c;        /* 0c */
    union { s64 xy; struct { s32 x, y; } s; } pos; /* 10 */
    u8 c[4];        /* 18 */
    s32 f1c;        /* 1c */
    void* p20;      /* 20 */
    void* p24;      /* 24 */
    void* p28;      /* 28 */
    void* p2c;      /* 2c */
    void* p30;      /* 30 */
    s32 prev;       /* 34 */
    s32 f38;        /* 38 */
    s32 f3c;        /* 3c */
    s32 f40;        /* 40 */
    s32 f44;        /* 44 */
    u8 pad48[5];
    u8 b4d;         /* 4d */
    u8 pad4e[0x12];
};
struct Elem20c9d0 {
    u8 pad0[0x20];
    u16 on;         /* 20 */
    s8 c[4];        /* 22 */
    u8 pad26[0x7c - 0x26];
    f32 x;          /* 7c */
    f32 y;          /* 80 */
    u8 pad84[0x94 - 0x84];
    f32 fade;       /* 94 */
    u64 flags;      /* 98 */
};
struct Col20c9d0 { f32 r, g, b, a; u8 pad[16]; };
struct Grp20c9d0 {
    Elem20c9d0* elems;
    Col20c9d0* cols;
    s32 n;
    f32 alpha;
    u8 pad10[2];
    u8 f12;
};
struct Base20c9d0 { u8 pad[8]; u8 r, g, b, a; };
struct Hdr20c9d0 { u8 pad[4]; s32 off4; s32 off8; };
struct Arg20c9d0 { u8 pad[12]; Hdr20c9d0* h; };
struct Par20c9d0 { u8 pad[4]; s32 idx; u8 f8; u8 pad9[0xd0 - 9]; f32 dist; f32 range; };
struct Obj20c9d0 { u8 pad[64]; };
extern Tbl20c9d0* D_01d9e6e4 asm("D_01d9e6e4");
extern Ctx20c9d0* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
s32 func_0020b4b8(Grp20c9d0*, Par20c9d0*) asm("func_0020b4b8");
void func_0020c858(Obj20c9d0*, Par20c9d0*, Grp20c9d0*) asm("func_0020c858");
f32 func_0020c860(Obj20c9d0*, f32*, Par20c9d0*, Grp20c9d0*, Elem20c9d0*) asm("func_0020c860");
s32 func_0020f1e0(u16*, Param20c9d0*, s32) asm("func_0020f1e0");
/*TARGET 0020c9d0*/
void func_0020c9d0(u8* base, Par20c9d0* par, Arg20c9d0* arg) asm("func_0020c9d0");
void func_0020c9d0(u8* base, Par20c9d0* par, Arg20c9d0* arg)
{
    Grp20c9d0* g = (Grp20c9d0*)(base + arg->h->off8 + 160);
    Elem20c9d0* e = g->elems;
    Col20c9d0* col = g->cols;
    Base20c9d0* bc = (Base20c9d0*)(base + arg->h->off4 + 160);
    s32 n = g->n;
    if (!func_0020b4b8(g, par)) return;
    if (!g->f12) return;
    s32 idx = par->idx;
    if (idx == 0xffff) return;
    Obj20c9d0 o;
    f32 m[16];
    Param20c9d0 p;
    func_0020c858(&o, par, g);
    Ent20c9d0* ent = &D_01d9e6e4->ents[idx];
    u16* d = ent->data;
    p.f44 = 0;
    p.p2c = 0;
    p.p28 = 0;
    p.p24 = 0;
    p.b0a = 0;
    p.f1c = 0;
    p.f38 = D_01d9e6e8->f90;
    p.f3c = D_01d9e6e8->f94;
    p.p04 = D_01d9eac0;
    p.flags = 4;
    p.f0c = 0;
    p.pos.xy = 0;
    p.f40 = 0;
    p.p20 = m;
    if (par->f8) p.flags = 0x204;
    s32 ba;
    u8 br, bg, bb;
    p.b4d = 1;
    br = bc->r;
    bg = bc->g;
    p.h08 = d[0x16 / 2];
    bb = bc->b;
    ba = bc->a;
    if (n > 0) {
        s32 i = n;
        do {
            if (e->on && !(e->flags & 0x100)) {
                f32 z = func_0020c860(&o, m, par, g, e);
                if (z < par->dist - par->range) {
                    e->fade = 0.0f;
                } else if (z < par->dist) {
                    e->fade *= 1.0f - (par->dist - z) / par->range;
                }
                s32 r = br + e->c[0];
                s32 gg = bg + e->c[1];
                s32 b = bb + e->c[2];
                s32 a = ba + e->c[3];
                if (col) {
                    r += (s32)col->r;
                    gg += (s32)col->g;
                    b += (s32)col->b;
                    a += (s32)col->a;
                }
                if (r < 0) {
                    r = 0;
                } else if (r >= 256) {
                    r = 255;
                }
                if (gg < 0) {
                    gg = 0;
                } else if (gg >= 256) {
                    gg = 255;
                }
                if (b < 0) {
                    b = 0;
                } else if (b >= 256) {
                    b = 255;
                }
                if (a < 0) {
                    a = 0;
                } else if (a >= 128) {
                    a = 127;
                }
                p.c[3] = a;
                p.c[0] = r;
                p.c[1] = gg;
                p.c[2] = b;
                p.c[3] = (s32)(p.c[3] * e->fade * g->alpha);
                p.pos.s.x = (s32)(e->x * 65536.0f);
                p.pos.s.y = (s32)(e->y * 65536.0f);
                if (p.c[3]) {
                    p.prev = D_01d9eaa4;
                    D_01d9eaa4 = func_0020f1e0(d, &p, ent->f20);
                }
            }
            e++;
            if (col) col++;
        } while (--i);
    }
}
}  // namespace n0020c9d0

// 0020cd50 (was gap, written for the unit)
namespace n0020cd50 {
struct VG { f32 x, y, z, w; } __attribute__((aligned(16)));
extern VG D_01d9e7f0 asm("D_01d9e7f0");
extern VG D_01d9e800 asm("D_01d9e800");
extern VG D_01da8ba0 asm("D_01da8ba0");
void sceVu0SubVector(VG*, VG*, VG*) asm("sceVu0SubVector");
void sceVu0Normalize(VG*, VG*) asm("sceVu0Normalize");
void func_0020cd50(void) asm("func_0020cd50");
void func_0020cd50(void) {
    sceVu0SubVector(&D_01da8ba0, &D_01d9e800, &D_01d9e7f0);
    sceVu0Normalize(&D_01da8ba0, &D_01da8ba0);
    D_01da8ba0.w = 1.0f;
}
}  // namespace n0020cd50

// 0020cda8 (was gap, written for the unit)
namespace n0020cda8 {
struct EmG { u8* parts; u8* work; s32 count; f32 f12; u16 timer; u8 on; };
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_0020cda8(u8* base, u8* c) asm("func_0020cda8");
void func_0020cda8(u8* base, u8* c) {
    EmG* e = (EmG*)(base + (*(s32**)(c + 12))[2] + 160);
    e->on = 1;
    e->work = 0;
    e->count = 0;
    e->timer = 0;
    e->f12 = 1.0f;
    e->parts = 0;
    D_01d9e6e0[171] = 1;
}
}  // namespace n0020cda8

// 0020cdf0 (was src/anon/auto80_199_queue.cpp)
namespace n0020cdf0 {
/*TARGET 0020cdf0*/
void func_0020cdf0(u32 a0, u32 a1) asm("_Z13func_0020cdf0jj");
void func_0020cdf0(u32 a0, u32 a1) {
    u32 t7 = *(u32*)(a1 + 12);
    u32 t6 = *(u32*)(t7 + 8);
    u32 s0 = a0 + t6;
    u32 s1 = s0 + 160;

    u32 p0 = *(u32*)(s0 + 160);
    if (p0 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p0);
        *(u32*)(s0 + 160) = 0;
    }

    u32 p1 = *(u32*)(s1 + 4);
    if (p1 != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), p1);
        *(u32*)(s1 + 4) = 0;
    }
}
}  // namespace n0020cdf0

// 0020ce60 (was src/anon/tiny_auto80_queue.cpp)
namespace n0020ce60 {
extern u8  D_00350000 asm("D_00350000");
// vec3_length
extern "C" void func_002236d0(...) asm("func_002236d0");
/*TARGET 0020ce60*/
void func_0020ce60(u32 a0, u8* a1) asm("_Z13func_0020ce60jPh");
void func_0020ce60(u32 a0, u8* a1) {
    (void)a0;
    if (*(s32*)((u8*)&D_00350000 + 18048u) != 0) {
        u8* t5 = a1;
        if (*(s32*)((u8*)&D_00350000 + 18052u) > 0) {
            func_002236d0(*(u32*)(t5 + 4), (u32)(a1 + 8), *(u8*)(a1 + 16), *(u8*)(t5 + 17));
        }
    }
}
}  // namespace n0020ce60

// 0020ceb0 (was gap, written for the unit)
namespace n0020ceb0 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_0020ceb0(void) asm("func_0020ceb0");
void func_0020ceb0(void) {
    D_01d9e6e0[171] = 1;
    D_01d9e6e0[168] = 3;
}
}  // namespace n0020ceb0

// 0020ced0 (was src/anon/auto80_199_queue.cpp)
namespace n0020ced0 {
/*TARGET 0020ced0*/
void func_0020ced0(u32 a0, u32 a1) asm("_Z13func_0020ced0jj");
void func_0020ced0(u32 a0, u32 a1) {
    (void)a0;
    u32 s0 = a1;
    if (*(s32*)(D_00350000 + 18056) != 0) {
        if (*(s32*)(D_00350000 + 18060) > 0) {
            u32 a2 = *(u8*)(s0 + 24);
            u32 a3 = *(u8*)(s0 + 25);
            func_00224358(*(u32*)(s0 + 16), s0 + 20, a2, a3);

            a2 = *(u8*)(s0 + 24);
            a3 = *(u8*)(s0 + 25);
            func_00223af8(*(u32*)(s0 + 4), s0 + 8, a2, a3);
        }
    }
}
}  // namespace n0020ced0

// 0020cf40 (was gap, written for the unit)
namespace n0020cf40 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_0020cf40(void) asm("func_0020cf40");
void func_0020cf40(void) {
    D_01d9e6e0[171] = 1;
    D_01d9e6e0[168] = 3;
}
}  // namespace n0020cf40

// 0020cf60 (was src/anon/batch_w29.cpp)
namespace n0020cf60 {
void func_00223e98(u32, u8*, u32, u32, f32, f32, u32) asm("func_00223e98");
extern u32 D_00354688 asm("D_00354688");
extern s32 D_0035468c asm("D_0035468c");
/*TARGET 0020cf60*/
// 0x001e01e8: definition moved into src/anon/unit_001deb58.cpp

void func_0020cf60(u32 a, u8* e) asm("func_0020cf60");
// 0x001e01e8: definition moved into src/anon/unit_001deb58.cpp

void func_0020cf60(u32 a, u8* e) {
    if (D_00354688 && D_0035468c > 0)
        func_00223e98(*(u32*)(e + 4), e + 8, e[28], e[29], *(f32*)(e + 12), *(f32*)(e + 16), *(u32*)(e + 20));
}
}  // namespace n0020cf60

// 0020cfb8 (was gap, written for the unit)
namespace n0020cfb8 {
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_0020cfb8(void) asm("func_0020cfb8");
void func_0020cfb8(void) {
    D_01d9e6e0[171] = 1;
    D_01d9e6e0[168] = 3;
}
}  // namespace n0020cfb8

