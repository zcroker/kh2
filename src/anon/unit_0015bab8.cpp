// Linked unit (extracted from the matched per-function sources).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include <stdarg.h>

// ---- 0x0015bab8 (src/anon/batch_w94.cpp)
namespace n0015bab8 {
void func_0014b1e0(u8*, s32, s16) asm("func_0014b1e0");
void func_0014bb00(u8*, s32, s16, s32, s32) asm("func_0014bb00");
void func_0015bab8(u8* p) asm("func_0015bab8");
void func_0015bab8(u8* p) {
    func_0014b1e0(p + 624, 408, *(s16*)(p + 2932) + 8);
    func_0014b1e0(p + 880, 408, *(s16*)(p + 2932));
    func_0014b1e0(p + 1136, 408, *(s16*)(p + 2932) + 88);
    func_0014b1e0(p + 1392, 400, *(s16*)(p + 2932) + 8);
    func_0014b1e0(p + 1648, 488, *(s16*)(p + 2932) + 8);
    func_0014b1e0(p + 1904, 400, *(s16*)(p + 2932));
    func_0014b1e0(p + 2160, 488, *(s16*)(p + 2932));
    func_0014b1e0(p + 2416, 400, *(s16*)(p + 2932) + 88);
    func_0014b1e0(p + 2672, 488, *(s16*)(p + 2932) + 88);
    func_0014bb00(p, 400, *(s16*)(p + 2932), 96, 96);
}
}  // namespace n0015bab8

// ---- 0x0015bbc8 (src/anon/batch_w54.cpp)
namespace n0015bbc8 {
void func_0014fc40(u8* p, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1) asm("func_0014fc40");
void func_0015b7c0(void*, s32) asm("func_0015b7c0");
void func_0015c068(void*, s32) asm("func_0015c068");
void func_001664c0(u32) asm("func_001664c0");
void func_0015bbc8(u8* p, s32 a1) asm("func_0015bbc8");
void func_0015bbc8(u8* p, s32 a1) {
    func_0014fc40(p, 18, 0, 5000, 0, 1);
    func_0015b7c0(p + 48, a1);
    func_0015c068(p, a1);
    func_001664c0(*(u32*)(p + 2976));
    *(f32*)(p + 2992) = 1.0f;
    *(u8*)(p + 3024) = 1;
    *(u8*)(p + 3025) = 96;
}
}  // namespace n0015bbc8

// ---- 0x0015bc50 (src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0015bc50 {
u32 func_0014fcd8(u32, u32, u32, u32) asm("func_0014fcd8");
u32 func_0015bc50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2dk5Radar6updateEv");
u32 func_0015bc50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0014fcd8(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(36));
    r15 = (u32)((s32)r15 + (16));
    *(u32*)((u32)r16 + (s32)(2980)) = r15;
    return r2;
}
}  // namespace n0015bc50

// ---- 0x0015bc80 (src/anon/sweep_0015bc80_nsa.cpp)
namespace n0015bc80 {
#define W1646_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1646Vec {
    f32 x, y, z, w;
    W1646Vec() {}
    W1646Vec(const W1646Vec& o) { W1646_QCOPY(this, &o); }
    W1646Vec& operator=(const W1646Vec& o) { if (this != &o) W1646_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1646SprVt { void* fn[3]; };
struct W1646Spr {
    W1646SprVt* vt;
    u8 pad[0xfc];
};
struct W1646Map {
    W1646Spr gauge;
    u8 pad100[0x50];
    W1646Spr arrow;
    u8 pad250[0x20];
    W1646Spr frame;
    W1646Spr ringA[4];
    W1646Spr ringB[4];
    void* texsrc;
    s32 yoff;
};
struct W1646Hud {
    u8 pad00[0x30];
    W1646Map map;
    u8 padba8[8];
    f32 scale;
    f32 div;
    s32 w;
    s32 h;
    s32 x;
    s32 y;
    u32 scrW;
    u32 scrH;
    u8 enabled;
    u8 alpha;
};
extern u8 D_0034ac00 asm("D_0034ac00");
void func_0013edd0(W1646Spr*, f32) asm("func_0013edd0");
void func_0013ee28(W1646Spr*, u64) asm("func_0013ee28");
void func_0013eeb8(W1646Spr*) asm("func_0013eeb8");
void func_0014b1e0(W1646Spr*, s16, s16) asm("func_0014b1e0");
void func_0014b208(W1646Spr*, u16, u16) asm("func_0014b208");
void func_0014b220(W1646Spr*, u8, u8, u8, u8) asm("func_0014b220");
void func_0014b628(W1646Spr*, u64) asm("func_0014b628");
void func_0014b698(W1646Spr*) asm("func_0014b698");
void func_0014bb30(W1646Spr*) asm("func_0014bb30");
void func_0015bab8(W1646Map*) asm("func_0015bab8");
u64 func_00166148(void*, s32, s32) asm("func_00166148");
W1646Vec func_0016af58(void*) asm("func_0016af58");
void* func_0016b0d0(void) asm("func_0016b0d0");
W1646Vec* func_0016c028(void*) asm("func_0016c028");
s32 func_00191c88(void) asm("func_00191c88");
s32 func_001949d0(void) asm("func_001949d0");
s32 func_00242ae8(void) asm("func_00242ae8");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
void func_0015bc80(W1646Hud* o) asm("func_0015bc80");
void func_0015bc80(W1646Hud* o) {
    if (!o->enabled) return;
    if (func_00191c88()) return;
    void* pl = func_0016b0d0();
    if (!pl) return;
    if (!func_00242ae8()) return;
    if (!func_001949d0()) return;
    W1646Map* m = &o->map;
    func_0015bab8(m);
    func_0014b220(&o->map.frame, 0x80, 0x80, 0x80, o->alpha);
    u64 tex = func_00166148(&D_0034ac00, 0x3500, 0x3520);
    func_0014b698(&o->map.frame);
    func_0014b628(&o->map.ringB[0], tex);
    for (s32 i = 0; i < 4; i++) {
        W1646Spr* a = &m->ringA[i];
        func_0014b220(a, 0x80, 0x80, 0x80, o->alpha);
        func_0014b628(a, tex);
        ((void (*)(W1646Spr*))a->vt->fn[2])(a);
        W1646Spr* b = &m->ringB[i];
        func_0014b220(b, 0x80, 0x80, 0x80, o->alpha);
        func_0014b628(b, tex);
        ((void (*)(W1646Spr*))b->vt->fn[2])(b);
    }
    W1646Spr* ar = &m->arrow;
    func_0014b628(&m->gauge, func_00166148(m->texsrc, 0x2800, 0x34e0));
    func_0014b220(&m->gauge, 0x80, 0x80, 0x80, o->alpha);
    func_0014b220(ar, 0x80, 0x80, 0x80, o->alpha);
    u32 hw = o->scrW >> 1;
    u32 hh = o->scrH >> 1;
    s32 minX = 48 - hw;
    s32 maxX = hw - 48;
    s32 minY = 48 - hh;
    s32 maxY = hh - 48;
    W1646Vec pos = *func_0016c028(pl);
    s32 dx = 0;
    s32 dy = 0;
    s32 x = o->x - (s32)(pos.x / o->div * o->scale);
    s32 y = (s32)(pos.z / o->div * o->scale) + o->y;
    W1646Vec d;
    d = func_0016af58(pl);
    func_0013edd0(ar, func_002f8ad0(d.x, d.z));
    if (x < minX) {
        dx = minX - x;
        x = minX;
    } else if (maxX < x) {
        dx = maxX - x;
        x = maxX;
    }
    if (y < minY) {
        dy = minY - y;
        y = minY;
    } else if (maxY < y) {
        dy = maxY - y;
        y = maxY;
    }
    s32 py = m->yoff;
    func_0014b1e0(ar, dx + 0x1c0, py + dy + 0x30);
    f32 sc = o->scale;
    u16 w = (s32)((f32)o->w * sc);
    u16 h = (s32)((f32)o->h * sc);
    u16 cx = (u16)o->x + (w >> 1);
    u16 cy = (u16)o->y + (h >> 1);
    func_0014b208(&m->gauge, w, h);
    s16 px = x - cx + 0x1c0;
    py = m->yoff;
    func_0014b1e0(&m->gauge, px, py + y - cy + 0x30);
    func_0014bb30(&m->gauge);
    func_0013ee28(ar, tex);
    func_0013eeb8(ar);
}
}  // namespace n0015bc80

// ---- 0x0015c068 (src/anon/batch_w56.cpp)
namespace n0015c068 {
s32 func_001665d8(void*, f32*, f32*, f32*, f32*, f32*, f32*) asm("func_001665d8");
void func_0015c068(u8* p, void* a) asm("func_0015c068");
void func_0015c068(u8* p, void* a)
{
    u32 n = func_001665d8(a, (f32*)(p + 3000), (f32*)(p + 3004), (f32*)(p + 3016), (f32*)(p + 3020), (f32*)(p + 3008), (f32*)(p + 3012));
    *(f32*)(p + 2996) = (f32)n * 100.0f * 0.001953125f;
}
}  // namespace n0015c068

// .rodata 0x36b3dc: a zero word between two files' constants (no code loads it)
extern "C" const s32 D_0036b3dc = 0;

// ---- 0x0015c0f8 (src/anon/batch_w68.cpp)
namespace n0015c0f8 {
struct Alloc1;
typedef void* (*AllocFn)(Alloc1*, u32, u32);
struct Alloc1 { AllocFn* vt; };
struct Holder1 { u32 f[5]; Alloc1* alloc; };
extern Holder1* D_00347f80 asm("D_00347f80");
extern void* D_0034af08 asm("D_0034af08");
extern void* D_0034ae80 asm("D_0034ae80");
extern s32 D_0034ece0 asm("D_0034ece0");
void func_0031daf0(void*) asm("func_0031daf0");
void* func_001492e8(void*, s32) asm("func_001492e8");
void func_0015bbc8(void*, void*) asm("func_0015bbc8");
void ctarget0_0015c0f8(void* p) asm("_Z17ctarget0_0015c0f8v");
void ctarget0_0015c0f8(void* p) asm("_Z17ctarget0_0015c0f8v");
void ctarget0_0015c0f8(void* p) {
    Alloc1* a = D_00347f80->alloc;
    u8* o = (u8*)a->vt[0](a, 3040, 0);
    *(u32*)(o + 12) = 0;
    *(void**)o = &D_0034af08;
    func_0031daf0(o + 48);
    D_0034ae80 = o;
    s32 id = D_0034ece0;
    if (id == 99) return;
    void* r = func_001492e8(p, id);
    if (r) func_0015bbc8(D_0034ae80, r);
}
}  // namespace n0015c0f8

// ---- 0x0015c1b0 (src/anon/tiny_auto80_queue.cpp)
namespace n0015c1b0 {
extern u8 D_0034ae80 asm("D_0034ae80");
void func_0015c1b0(void) asm("_Z16u_tail0_0015c1b0v");
void func_0015c1b0(void) {
    u32 s0 = (u32)&D_0034ae80;
    u32 t7 = *(volatile u32*)((u32)s0 + (s32)(0));
    if (t7 != 0u) {
        u32 a0 = t7;
        u32 t6 = *(volatile u32*)((u32)*(volatile u32*)((u32)t7 + (s32)(0)) + (s32)(16));
        ((void(*)(u32))t6)(a0);
        *(volatile u32*)((u32)s0 + (s32)(0)) = 0u;
    }
}
}  // namespace n0015c1b0

// ---- 0x0015c1f0 (src/anon/tiny_auto80_queue.cpp)
namespace n0015c1f0 {
void func_0015c1f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z16u_tail0_0015c1f0v");
void func_0015c1f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r15 = (u32)(0x0035u << 16);
    r14 = *(volatile u32*)((u32)r15 + (s32)(-20864));
    r15 = (u32)((s32)0u + (1));
    if (r14 != 0u) {
        *(volatile u8*)((u32)r14 + (s32)(3024)) = (u8)r15;
    }
}
}  // namespace n0015c1f0

// ---- 0x0015c210 (src/anon/tiny_auto80_queue.cpp)
namespace n0015c210 {
extern u8 D_0034ae80 asm("D_0034ae80");
extern u8 D_0034ae80 asm("D_0034ae80");
void func_0015c210(void) asm("_Z16u_tail0_0015c210v");
void func_0015c210(void) {
    u32 t7 = *(volatile u32*)(u32)&D_0034ae80;
    if (t7 != 0u) {
        *(volatile u8*)((u32)t7 + (s32)(3024)) = (u8)0u;
    }
}
}  // namespace n0015c210

// ---- 0x0015c228 (src/anon/batch_w1749_nsa.cpp)
namespace n0015c228 {
extern s32 D_0034af20 asm("D_0034af20");
extern u32 D_0034af24 asm("D_0034af24");
extern u64 D_0034af30 asm("D_0034af30");
void func_0015c228(s32* p) asm("func_0015c228");
void func_0015c228(s32* p)
{
    if (p == 0) {
        D_0034af24 = 0;
        D_0034af20 = 0;
        return;
    }
    D_0034af20 = (s32)p + p[0];
    D_0034af24 = (u32)p[1] / 104;
    D_0034af30 = 0;
}
}  // namespace n0015c228

// ---- 0x0015c280 (gap, written here)
namespace n0015c280 {
extern u32 D_0034af24 asm("D_0034af24");
extern "C" u32 func_0015c280(void) { return D_0034af24; }
}

// ---- 0x0015c290 (gap, written here)
namespace n0015c290 {
extern u32 D_0034af20 asm("D_0034af20");
extern "C" u32 func_0015c290(void) { return D_0034af20; }
}

// ---- 0x0015c2a0 (src/anon/batch_w1574.cpp)
namespace n0015c2a0 {
struct V4w1574 {
    f32 x, y, z, w;
    V4w1574() {}
    V4w1574(const V4w1574& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct E15c { f32 m[9]; s32 off; s32 bit; s32 a2c; s32 a30; s32 a34; u8 pad[104-56]; };
struct Alloc15c { union { void* (**vt)(Alloc15c*, s32, void*); f32 f; }; };
extern s32 D_0034af28 asm("D_0034af28");
extern E15c* D_0034af20 asm("D_0034af20");
extern s32 D_0034af24 asm("D_0034af24");
union U15c { u64 v; f32 f; };
extern U15c D_0034af30 asm("D_0034af30");
extern Alloc15c* D_0034c738 asm("D_0034c738");
void func_0015fe18(void*, E15c*, s32, V4w1574, V4w1574, V4w1574, s32, s32, s32, s32, s32) asm("func_0015fe18");
void func_0015c2a0(s32 base, u64 mask) asm("func_0015c2a0");
void func_0015c2a0(s32 base, u64 mask) {
    V4w1574 a, b, c;
    D_0034af28 = base;
    E15c* e = D_0034af20;
    c.w = 1.0f; b.w = 1.0f; a.w = 1.0f;
    s32 n = D_0034af24;
    s32 i = 0;
    if (n > 0) do {
        u64 bit = (u64)1 << e->bit;
        if (bit & mask) {
            D_0034af30.v |= bit;
            a.x = e->m[0]; a.y = e->m[1]; a.z = e->m[2];
            b.x = e->m[3]; b.y = e->m[4]; b.z = e->m[5];
            c.x = e->m[6]; c.y = e->m[7]; c.z = e->m[8];
            void* p = D_0034c738->vt[0](D_0034c738, 0x2f0, __builtin_return_address(0));
            func_0015fe18(p, e, base + e->off, a, b, c, i, e->a2c, e->a30, e->bit, e->a34);
        }
        i++; e++;
    } while (i < n);
}
}  // namespace n0015c2a0

// ---- 0x0015c450 (src/anon/batch_w34.cpp)
namespace n0015c450 {
void func_00160e50(u32) asm("func_00160e50");
void func_0015c2a0(u32, u64) asm("func_0015c2a0");
extern u64 D_0034af30 asm("D_0034af30");
extern u32 D_0034af28 asm("D_0034af28");
void func_0015c450(u32 n) asm("func_0015c450");
void func_0015c450(u32 n) {  // flag_test_global
    if ((u8)((D_0034af30 >> n) & 1)) func_00160e50(n);
    else func_0015c2a0(D_0034af28, 1ull << n);
}
}  // namespace n0015c450

// ---- 0x0015c4a0 (src/anon/tiny_wrappers_more.cpp)
namespace n0015c4a0 {
u32 func_00160de0(u32, u32, u32, u32) asm("func_00160de0");
u32 func_0015c4a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0015c4a0");
u32 func_0015c4a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00160de0(a0, a1, a2, a3);
}
}  // namespace n0015c4a0

// ---- 0x0015c4b8 (src/anon/tiny_auto80_queue.cpp)
namespace n0015c4b8 {
extern "C" u32 func_0014e140(...) asm("func_0014e140");
extern "C" u32 func_0015cb48(...) asm("func_0015cb48");
void func_0015c4b8(void) asm("func_0015c4b8");
void func_0015c4b8(void) {
    struct {
        u8 b0;
        u8 b1;
        u8 b2;
        u8 b3;
    } sp;
    sp.b0 = (u8)0u;
    sp.b1 = (u8)0u;
    sp.b2 = (u8)0u;
    sp.b3 = (u8)0u;
    func_0015cb48((u32)&sp, (u32)&sp.b1, (u32)&sp.b2, (u32)&sp.b3);
    func_0014e140((u32)sp.b0, (u32)sp.b1, (u32)sp.b2);
}
}  // namespace n0015c4b8

// ---- 0x0015c500 (src/anon/batch_w292.cpp)
namespace n0015c500 {
struct Fog15c { u8 r, g, b, a; f32 near, far, fmin, fmax; };
struct Cfg15c { u8 pad[0x44]; Fog15c fog; };
extern Cfg15c D_004f3700 asm("D_004f3700");
extern Cfg15c D_004f36a8 asm("D_004f36a8");
extern Cfg15c D_004f3650 asm("D_004f3650");
void func_0015cbb8(s32, s32, s32, s32) asm("func_0015cbb8");
void func_0015c4b8(void) asm("func_0015c4b8");
void func_0015cc18(s32, s32, s32, s32, s32) asm("func_0015cc18");
s32 func_0015cc80(Fog15c*) asm("func_0015cc80");
void func_0010a8a8(f32, f32) asm("func_0010a8a8");
void func_0010a828(f32, f32) asm("func_0010a828");
void func_0010a7d8(u8, u8, u8) asm("func_0010a7d8");
void func_001dd1e8(u8, u8) asm("func_001dd1e8");
void func_001dd1b0(f32, f32) asm("func_001dd1b0");
void func_001dd1c8(u8, u8, u8) asm("func_001dd1c8");
void func_0015c500(void) asm("func_0015c500");
void func_0015c500(void)
{
    s32 i;
    Fog15c* f;
    func_0015cbb8(0, 0, 0, 128);
    func_0015c4b8();
    for (i = 0; i < 16; i++) func_0015cc18(i, 128, 128, 128, 128);
    f = &D_004f3700.fog;
    f->near = 1000.0f;
    f->fmin = 0.0f;
    f->far = 1000000.0f;
    f->fmax = 255.0f;
    s32 c = 128;
    f->r = c;
    f->g = c;
    f->b = c;
    f->a = c;
    if (!func_0015cc80(f)) {  // test_float12_zero_and_bits
        func_0010a8a8(f->fmin, f->fmax);  // store_global_float_pair
        func_0010a828(f->near, f->far);
        func_0010a7d8(f->r, f->g, f->b);  // store_triple_bytes
    }
    func_001dd1e8((s32)f->fmin, (s32)f->fmax);
    func_001dd1b0(f->near, f->far);  // to_1e7018
    func_001dd1c8(f->r, f->g, f->b);  // to_1e7030_masked
    D_004f36a8 = D_004f3700;
    D_004f3650 = D_004f36a8;
}
}  // namespace n0015c500

// ---- 0x0015c6d0 (src/anon/batch_w287.cpp)
namespace n0015c6d0 {
struct T15 { u8 id; u8 b1; u8 b2; u8 pad; f32 f4; f32 f8; f32 f12; f32 f16; };
struct S15 { u8 pad[68]; T15 t; };
extern S15 D_004f36a8 asm("D_004f36a8");
extern S15 D_004f3650 asm("D_004f3650");
extern S15 D_004f3700 asm("D_004f3700");
extern T15 D_004f3744 asm("D_004f3744");
void func_0015c4b8(void) asm("func_0015c4b8");
s32 func_0015cc80(T15*) asm("func_0015cc80");
void func_0010a8a8(f32, f32) asm("func_0010a8a8");
void func_0010a828(f32, f32) asm("func_0010a828");
void func_0010a7d8(u8, u8, u8) asm("func_0010a7d8");
void func_001dd1e8(u8, u8) asm("func_001dd1e8");
void func_001dd1b0(f32, f32) asm("func_001dd1b0");
void func_001dd1c8(u8, u8, u8) asm("func_001dd1c8");
void func_0015c6d0(S15* a0) asm("func_0015c6d0");
void func_0015c6d0(S15* a0) {
    D_004f36a8 = *a0;
    D_004f3650 = D_004f36a8;
    D_004f3700 = *a0;
    func_0015c4b8();
    S15* p = &D_004f3700;
    if (p->t.f16 == 0.0f) p->t.f16 = 255.0f;
    T15* t = &p->t;
    T15* g = &D_004f3744;
    if (!func_0015cc80(t)) {  // test_float12_zero_and_bits
        func_0010a8a8(t->f12, t->f16);  // store_global_float_pair
        func_0010a828(t->f4, t->f8);
        func_0010a7d8(g->id, t->b1, t->b2);  // store_triple_bytes
    }
    func_001dd1e8((s32)t->f12, (s32)t->f16);
    func_001dd1b0(t->f4, t->f8);  // to_1e7018
    func_001dd1c8(g->id, t->b1, t->b2);  // to_1e7030_masked
}
}  // namespace n0015c6d0

// ---- 0x0015c880 (src/anon/batch_w3720.cpp)
namespace n0015c880 {
struct S4f3694 { u8 r, g, b, a; f32 x, y, z, w; };
extern u8 D_00340eb0 asm("D_00340eb0");
extern struct S4f3694 D_004f3694 asm("D_004f3694");
void func_0010a8a8(f32, f32) asm("func_0010a8a8");
void func_0010a828(f32, f32) asm("func_0010a828");
void func_0010a7d8(u8, u8, u8) asm("func_0010a7d8");
void func_001dd1e8(u8, u8) asm("func_001dd1e8");
void func_001dd1b0(f32, f32) asm("func_001dd1b0");
void func_001dd1c8(u8, u8, u8) asm("func_001dd1c8");
static inline __attribute__((always_inline)) void init_4f3694(f32 z, f32 w, f32 y) {
    s32 t;
    register f32 yy asm("$f2") = y;
    asm("swc1 %1,%0" : "=m"(D_004f3694.y) : "f"(yy), "m"(D_00340eb0));
    asm("li %0,128" : "=r"(t) : "m"(D_004f3694.y), "m"(D_004f3694.x), "m"(D_004f3694.z), "m"(D_004f3694.w));
    D_004f3694.r = 0;
    D_004f3694.g = 0;
    D_004f3694.x = z;
    D_004f3694.z = z;
    D_004f3694.w = w;
    asm("" : "+r"(t) : "m"(D_004f3694.x), "m"(D_004f3694.y), "m"(D_004f3694.z), "m"(D_004f3694.w));
    D_004f3694.a = t;
    D_004f3694.b = 0;
    func_0010a8a8(z, w);
}
void func_0015c880(f32 arg0) asm("func_0015c880");
void func_0015c880(f32 arg0) {
    register s32 one asm("$14") = 1;
    D_00340eb0 = one;
    init_4f3694(0.0f, 255.0f, arg0);
    func_0010a828(D_004f3694.x, D_004f3694.y);
    func_0010a7d8(D_004f3694.r, D_004f3694.g, D_004f3694.b);
    func_001dd1e8((s32)D_004f3694.z, (s32)D_004f3694.w);
    func_001dd1b0(D_004f3694.x, D_004f3694.y);
    func_001dd1c8(D_004f3694.r, D_004f3694.g, D_004f3694.b);
}
}  // namespace n0015c880
