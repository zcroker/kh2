#include "../common/types.h"

// YS::PRIZE / PRIZE_CA, second part (0x1cc868-0x1cd078): prize motion callbacks (fall, scatter,
// fly to the owner), the pick-up area check, a second effect set (D_003520c0) and the
// HP-orb drop on hit. unit_001cc048.cpp has the start of the file.

extern "C" {
extern f32 D_00349e10;
extern u32 D_003638d0;
}

// ---- 0x1cc868 / 0x1cc888: falling prize
namespace p888 {
struct W63Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void vsub(W63Vec* d, const W63Vec* a, const W63Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vadd(W63Vec* d, const W63Vec* a, const W63Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vscale(W63Vec* d, const W63Vec* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
struct W63Body { W63Vec pos; u8 pad[32]; W63Vec vel; };
extern "C" {
s32 func_001cc888(W63Body* b);
s32 func_001cc868(W63Body* b) {
    s32 (*move)(W63Body*) = func_001cc888;
    return move(b);
}
// Moves pos a fifth of the way towards vel, with gravity on y; returns pos.y < 0.
s32 func_001cc888(W63Body* b) {
    W63Vec d;
    W63Vec t;
    vsub(&t, &b->vel, &b->pos);
    vscale(&d, &t, 0.2f);
    d.y = b->vel.y * D_00349e10;
    b->vel.y += D_00349e10 * 0.4f;
    vadd(&b->pos, &b->pos, &d);
    return b->pos.y < 0.0f;
}
}
}  // namespace p888

extern "C" {
extern u8* D_00352050;
struct V920 { f32 x, y, z, w; } __attribute__((aligned(16)));
void func_0016bda8(V920*, u8*) asm("func_0016bda8");
u8* func_001cc128(u8*, V920*) asm("_ZN2YS5PRIZE6appearEPKNS_11PRIZEEFFECT5PARAMERKN2kn7FVectorE");
void func_001ccac0(u8*, u32);

// Scatter up to n of the object's prizes towards `to`; 1 when it ran out.
u32 c_001cc920(u8* to, u8* from, s32 n) asm("_Z16ctarget_001cc920jjjj");
u32 c_001cc920(u8* to, u8* from, s32 n) {
    V920 pos;
    func_0016bda8(&pos, from);
    s32 i = 0;
    if (n > 0) {
        while (1) {
            if (*(u32*)(from + 2760) == 0) {
                return 1;
            }
            u8* obj = func_001cc128(D_00352050, &pos);
            if (obj == 0) {
                return 1;
            }
            func_001ccac0(obj, (u32)to);
            i = i + 1;
            *(u32*)(from + 2760) = *(u32*)(from + 2760) - 1;
            if (!(i < n)) {
                break;
            }
        }
    }
    return 0;
}
}

// ---- 0x1cc9c8: send every free prize within r of the object to it
namespace p9c8 {
struct Vc {
    f32 x, y, z, w;
    Vc() {}
    Vc(const Vc& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
extern "C" {
u8* func_0016c028(u8*);
u8* func_001c16f0(u8*, u8*);
void func_001cc9c8(u8* o, f32 r) {
    Vc pos(*(Vc*)func_0016c028(o));  // obj_get_attach_or_alt
    u8* e = 0;
    while ((e = func_001c16f0(*(u8**)(D_00352050 + 2548), e)) != 0) {
        if (*(u32*)(e + 72)) continue;
        Vc d;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(e), "r"(&pos) : "memory");
        d.y = 0.0f;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8");
        if (len < r) func_001ccac0(e, (u32)o);
    }
}
}
}  // namespace p9c8

// ---- 0x1ccaa0 / 0x1ccac0 / 0x1ccc38: prize flying to its owner
namespace pac0 {
static inline u32 rnd(void) { return D_003638d0 *= 0x10dcd; }
static inline f32 frnd(void) { return (f32)rnd() * 2.3283064365386963e-10f; }
static inline f32 rng(f32 a, f32 b) { return b + frnd() * a; }
struct V4 { f32 x, y, z, w; };
struct VH {
    f32 x, y, z, w;
    VH() {}
    VH(const VH& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    VH& operator=(const VH& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    VH& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    VH& operator+=(const VH& b) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline VH operator-(const VH& a, const VH& b) {
    VH r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline VH operator*(const VH& a, f32 s) {
    VH r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline VH Lerp(const VH& a, const VH& b, f32 t) {
    VH r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct ObjH { VH pos; u8 pad[32]; VH vel; u8 pad2[8]; u8* owner; };
extern "C" {
VH func_0016bda8h(u8*) asm("func_0016bda8");
s32 func_001ccc38(ObjH* a0);
s32 func_001ccaa0(ObjH* a0) {
    s32 (*move)(ObjH*) = func_001ccc38;
    return move(a0);
}
void func_001ccac0(u8* a0, u32 a1) {
    *(u32*)(a0 + 16) = (u32)func_001ccaa0;
    *(u32*)(a0 + 72) = a1;
    V4* v = (V4*)(a0 + 48);
    f32 x = rng(20.0f, -10.0f);
    f32 y = rng(10.0f, -30.0f);
    f32 z = rng(20.0f, -10.0f);
    v->x = x; v->y = y; v->z = z; v->w = 0;
}
s32 func_001ccc38(ObjH* a0) {
    VH d = func_0016bda8h(a0->owner) - a0->pos;
    f32 len = d.Normalize();
    d *= 20.0f;
    a0->vel = Lerp(a0->vel, d, 0.1f);
    a0->pos += a0->vel * D_00349e10;
    if (len < 100.0f) {
        ++*(s32*)(a0->owner + 2760);
        return 0;
    }
    return 1;
}
}
}  // namespace pac0

extern "C" {
u32 GetAppearNum(void) asm("_ZN2YS8PRIZE_CA12GetAppearNumEv");
u32 GetAppearNum(void) {
    u8* t7 = D_00352050;
    if (t7 != 0) {
        u8* t7b = *(u8**)(t7 + 2548);
        return *(u32*)(t7b + 52);
    }
    u32 v0 = 0;
    return v0;
}

void func_001c6ee8(u8*);
void* func_001c16f0v(void*, void*) asm("func_001c16f0");
void* func_00186078v(void*) asm("func_00186078");
// Drains two iterators.
void func_001ccda0(u8* p) {
    func_001c6ee8(p);
    for (void* v = 0; (v = func_001c16f0v(*(void**)(p + 0x9f4), v)) != 0;) ;
    for (void* w = 0; (w = func_00186078v(w)) != 0;) ;
}

void func_001ccdf0(void) {}

// ---- the second effect set (vtable D_003520d0, instance D_003520c0)
extern u8 D_003520d0;
extern void* D_003520c0;
u32 func_001a4db0(u32, u32, u32, u32);
u32 func_001a4e30(...);
void func_001a4e30v(void*) asm("func_001a4e30");
void func_00105110(void*);

u32 func_001ccdf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_003520d0;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8384)) = r16;
    return r2;
}

u32 func_001cce38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_003520d0;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8384)) = r16;
    return r2;
}

u32 func_001cce78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_003520d0;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8384)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = (u32 (*)(u32, u32, u32, u32))func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}

u32 func_001ccea8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_003520d0;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8384)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = (u32 (*)(u32, u32, u32, u32))func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}

void func_001cced8(void* p) {
    *(void**)p = &D_003520d0;
    D_003520c0 = 0;
    func_001a4e30v(p);
    func_00105110(p);
}

extern u8 D_0036e278[][16];
u8* func_001a5420(void*, void*, void*);
void func_001ccf18(void* a0, s32 a1, s32 n) {
    if (D_003520c0) {
        s32 i;
        for (i = 0; i < n; i++) {
            u8* r = func_001a5420(D_003520c0, D_0036e278[a1], a0);
            *(u32*)(r + 40) |= 4;
        }
    }
}

s32 func_00186ce8(u8*);
s32 func_00186d18(u8*);  // check_size140to150
s32 func_001c7950b(void*, void*, f32, f32) asm("func_001c7950");
void func_001c79a0b(void*, void*, s32) asm("func_001c79a0");
void func_001d86a0(s32, s32);
u8* func_00186078b(u8*) asm("func_00186078");
struct Fl40 { u32 on:1; u32 rest:31; };
void func_001ccfa0(void* self, u8* a) {
    if (((Fl40*)(a + 40))->on) {
        u8* it = 0;
        while ((it = func_00186078b(it)) != 0) {
            if (func_00186ce8(it)) continue;
            if (func_00186d18(it)) continue;
            if (*(u32*)(it + 360) & 0x40) continue;
            if (!func_001c7950b(a, it, 0.0f, 0.0f)) continue;
            func_001c79a0b(a, it, 0);
            u32 m = *(u32*)(it + 1416) & 0x80;
            func_001d86a0(1, m == 0);
            return;
        }
    }
}
}
