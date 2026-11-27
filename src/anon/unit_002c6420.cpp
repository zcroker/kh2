// Linked unit 0x2c6420-0x2c6eb8: world map camera target (a blend camera base with Init/Update,
// a derived target class with ctor C2/C1, dtors D2/D1/D0 and a world-map Update, a factory,
// the instance getter and the static init of five offset vectors with its I/D stubs).
// The vtables (0x361da8 base, 0x361dc8 derived), the instance pointer (0x361db8) and the five
// vectors (.bss 0x1e2bdc0..) stay retail data; the functions are written as plain functions.
#include "../common/types.h"

// ---- 002c6420: base Init (from batch_w46.cpp)
namespace n002c6420 {
u8* func_00106a60(u32) asm("func_00106a60");  // buffer_get_by_index
void kn__Camera__getPosition(u8*, u8*) asm("kn__Camera__getPosition");  // vec_copy_at80_if_diff
void func_00107478(u8*, u8*) asm("func_00107478");  // vec_copy_at96_if_diff
u8* kn__getProjection(u32) asm("kn__getProjection");  // buffer_get_256
f32 func_00106f30(u8*, u32) asm("func_00106f30");
void worldmap__Camera__initialize(u8* p) asm("worldmap__Camera__initialize");
void worldmap__Camera__initialize(u8* p) {
    *(u32*)(p + 84) = 0;
    u8* v = func_00106a60(1);  // buffer_get_by_index
    kn__Camera__getPosition(v, p + 16);  // vec_copy_at80_if_diff
    func_00107478(v, p + 32);  // vec_copy_at96_if_diff
    f32 f = func_00106f30(kn__getProjection(1), 0);
    *(f32*)(p + 80) = f;
    *(u32*)(p + 88) = 0;
}
}

// ---- 002c6490: base Update (from batch_w274.cpp)
namespace n002c6490 {
struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V4 Lerp(const V4& a, const V4& b, f32 t) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct C6490 {
    u8 pad[16];
    V4 a0;    // 16
    V4 b0;    // 32
    V4 a1;    // 48
    V4 b1;    // 64
    f32 f80;
    u32 flags;
    f32 t;
    f32 dur;
};
void* func_00106a60(s32) asm("func_00106a60");  // buffer_get_by_index
extern f32 D_00349e10 asm("D_00349e10");
void worldmap__Camera__initialize(C6490*) asm("worldmap__Camera__initialize");
f32 sinf(f32) asm("sinf");
void* kn__getProjection(s32) asm("kn__getProjection");  // buffer_get_256
void func_00107300(void*, V4*, V4*, f32) asm("func_00107300");  // copy_blocks_and_store_float
void kn__Projection__setFOV(void*, s32, f32) asm("kn__Projection__setFOV");
s32 worldmap__Camera__update(C6490* p) asm("worldmap__Camera__update");
s32 worldmap__Camera__update(C6490* p) {
    u32 m = p->flags & 1;
    if (m == 0) worldmap__Camera__initialize(p);
    V4 a = p->a1;
    V4 b = p->b1;
    if (p->t < p->dur) {
        p->t += D_00349e10;
        if (p->t < p->dur) {
            f32 s = sinf(p->t / p->dur * 1.5707964f);
            a = Lerp(p->a0, p->a1, s);
            b = Lerp(p->b0, p->b1, s);
        }
    }
    func_00107300(func_00106a60(1), &a, &b, 0.0f);  // copy_blocks_and_store_float
    kn__Projection__setFOV(kn__getProjection(1), 0, p->f80);
    p->flags |= 1;
    return 1;
}
}

// ---- 002c65f8: clear flag bit 0 (from tiny.cpp)
namespace n002c65f8 {
void func_002c65f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c65f8");
void func_002c65f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (84));
    v &= (u32)((s32)-2);
    *(u32*)((u32)a0 + (84)) = v;
}
}

// ---- 002c6610: scaled step towards a target, clamped (from batch_wcx.cpp)
namespace n002c6610 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern f32 D_00349e18 asm("D_00349e18");
extern f32 D_00349e10 asm("D_00349e10");
static inline void VSub(V4* d, V4* a, V4* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
V4* func_002c6610(V4* out, u32, V4* a, V4* b, f32 k, f32 lim) asm("func_002c6610");
V4* func_002c6610(V4* out, u32, V4* a, V4* b, f32 k, f32 lim)
{
    V4 t, d;
    VSub(&d, b, a);
    VScale(&t, &d, k);
    f32 s = VNormalize(&t, &t) * D_00349e18;
    if (lim < s) s = lim;
    VScale(out, &t, s * D_00349e10);
    return out;
}
}

// ---- 002c66b8: derived ctor, C2 copy (from batch_w82.cpp)
namespace n002c66b8 {
union PU82 { u8* p; u32 u; f32 f; };
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361dc8[] asm("D_00361dc8");
extern u8 D_01e2bdd0[] asm("D_01e2bdd0");
extern u8 D_01e2bdc0[] asm("D_01e2bdc0");
extern PU82 D_00361db8 asm("D_00361db8");
static inline void QCopy82(void* d, const void* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
void worldmap__Camera__initialize(u8*) asm("worldmap__Camera__initialize");
void func_002c66b8(u8* a0, u32 a1, u32 a2) asm("func_002c66b8");
void func_002c66b8(u8* a0, u32 a1, u32 a2)
{
    *(u32*)(a0 + 84) = 0;
    *(u32*)a0 = (u32)D_00361da8;
    *(u32*)(a0 + 92) = 0;
    worldmap__Camera__initialize(a0);
    *(u32*)(a0 + 96) = a1;
    *(u32*)a0 = (u32)D_00361dc8;
    *(u32*)(a0 + 100) = a2;
    QCopy82(a0 + 112, D_01e2bdd0);
    QCopy82(a0 + 128, D_01e2bdc0);
    D_00361db8.p = a0;
    *(u32*)(a0 + 84) |= 1;
    *(f32*)(a0 + 144) = 65.0f;
    *(f32*)(a0 + 92) = 60.0f;
    *(f32*)(a0 + 88) = 60.0f;
}
}

// ---- 002c6780: derived ctor, C1 copy (calls the out-of-line flag member ctor) (from batch_wcx2.cpp)
namespace n002c6780 {
#define QCOPYS_2c6780(d, s) asm volatile("lq $8, 0(%0)\n\tsq $8, 0(%1)" : : "r"(s), "r"(d) : "$8", "memory")
union UA_002c6780 { u32 i; f32 f; u8* p; };
void func_0031cc28(u8*) asm("_Z13func_0031cc28Ph");
void worldmap__Camera__initialize(u8*) asm("worldmap__Camera__initialize");
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361dc8[] asm("D_00361dc8");
extern UA_002c6780 D_00361db8 asm("D_00361db8");
extern u8 D_01e2bdd0[] asm("D_01e2bdd0");
extern u8 D_01e2bdc0[] asm("D_01e2bdc0");
void func_002c6780(u8* p, u32 a1, u32 a2) asm("func_002c6780");
void func_002c6780(u8* p, u32 a1, u32 a2) {
    *(u32*)p = (u32)D_00361da8;
    func_0031cc28(p + 84);
    ((UA_002c6780*)(p + 92))->i = 0;
    worldmap__Camera__initialize(p);
    *(u32*)p = (u32)D_00361dc8;
    ((UA_002c6780*)(p + 96))->i = a1;
    ((UA_002c6780*)(p + 100))->i = a2;
    QCOPYS_2c6780(p + 112, D_01e2bdd0);
    QCOPYS_2c6780(p + 128, D_01e2bdc0);
    D_00361db8.p = p;
    ((UA_002c6780*)(p + 92))->f = 60.0f;
    ((UA_002c6780*)(p + 84))->i |= 1;
    ((UA_002c6780*)(p + 144))->f = 65.0f;
    ((UA_002c6780*)(p + 88))->f = 60.0f;
}
#undef QCOPYS_2c6780
}

// ---- 002c6850 / 002c6880 / 002c68b0: derived dtor D2, D1 and D0 (never written before)
namespace n002c6850 {
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361dc8[] asm("D_00361dc8");
extern u8* D_00361db8 asm("D_00361db8");
void func_00105110(u8*) asm("func_00105110");  // operator delete
static inline void Dtor(u8* p) {
    *(u8**)p = D_00361dc8;
    u8* s = D_00361db8;
    D_00361db8 = (s == p) ? 0 : s;
    *(u8**)p = D_00361da8;
}
void func_002c6850(u8* p) asm("func_002c6850");
void func_002c6850(u8* p) { Dtor(p); }
void func_002c6880(u8* p) asm("func_002c6880");
void func_002c6880(u8* p) { Dtor(p); }
void func_002c68b0(u8* p) asm("func_002c68b0");
void func_002c68b0(u8* p) { Dtor(p); func_00105110(p); }
}

// ---- 002c68f0: derived Update, world map camera target (from batch_w3771.cpp, partial asm)
namespace n002c68f0 {
struct W1636V4 {
    f32 x, y, z, w;
    W1636V4() {}
    W1636V4(const W1636V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1636V4& operator=(const W1636V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    W1636V4& operator=(const struct W1636V4L& o);
} __attribute__((aligned(16)));
struct W1636V4L { f32 x, y, z, w; } __attribute__((aligned(16)));
inline W1636V4& W1636V4::operator=(const W1636V4L& o) { if ((void*)this != (void*)&o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
static inline W1636V4L W1636Lerp(const W1636V4& a, const W1636V4& b, f32 t) {
    W1636V4L r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline W1636V4 operator-(const W1636V4& a, const W1636V4& b) {
    W1636V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W1636V4 operator+(const W1636V4& a, const W1636V4& b) {
    W1636V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void W1636LerpTo(W1636V4* r, const W1636V4& a, const W1636V4& b, f32 t) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
}
static inline f32 W1636Clamp(f32 v, f32 lo, f32 hi) {
    if (v < lo) return lo;
    if (hi < v) return hi;
    return v;
}
struct W1636Cam {
    u8 pad[16];
    W1636V4 a0;    // 16
    W1636V4 b0;    // 32
    W1636V4 a1;    // 48
    W1636V4 b1;    // 64
    f32 f80;
    u32 flags;
    f32 t;
    f32 dur;
    void* obj;     // 96
    u8 pad100[44];
    f32 f144;
};
struct W1636Flags { u8 state; u8 pad[2]; u8 bits; };
static inline bool W1636Ready(W1636Flags* f) { return f->state >= 2 && !(f->bits & 2); }
extern W1636V4 D_01e2bdc0 asm("D_01e2bdc0");
extern W1636V4 D_01e2bdd0 asm("D_01e2bdd0");
extern W1636V4 D_01e2bde0 asm("D_01e2bde0");
extern W1636V4 D_01e2bdf0 asm("D_01e2bdf0");
extern W1636V4 D_01e2be00 asm("D_01e2be00");
s32 YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
W1636V4* YS__OBJ__get_pos(void*) asm("YS__OBJ__get_pos");  // obj_get_attach_or_alt
W1636Flags* func_001b6d70(s32) asm("func_001b6d70");  // table_entry_ptr_b
void* func_0016b740(s32) asm("func_0016b740");
f32 sinf(f32) asm("sinf");
s32 worldmap__Camera__update(W1636Cam*) asm("worldmap__Camera__update");

// Worldmap camera target update (blends the a/b offsets by distance to object 1110 and by depth).
// Register pins: p in s1, an unused s0 kept live (the original saves s0 but never uses it),
// the VU0 length result in $f2 and the clamp floor in $f0.
s32 worldmap__ObjCamera__update(W1636Cam* pp) asm("worldmap__ObjCamera__update");
s32 worldmap__ObjCamera__update(W1636Cam* pp)
{
    register W1636Cam* p asm("$17") = pp;
    register s32 ph asm("$16");
    if (!YS__OBJ__is_exist(pp->obj)) return 0;

    W1636V4 pos = *YS__OBJ__get_pos(p->obj);
    if (pos.z < -14000.0f) pos.z = -14000.0f;
    W1636V4 a;
    W1636V4 b;
    if (W1636Ready(func_001b6d70(18))) {
        W1636V4 d = *YS__OBJ__get_pos(func_0016b740(1110)) - pos;
        d.y = 0.0f;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        register f32 lo asm("$f0") = d.y;
        f32 t = W1636Clamp((len - 5000.0f) / 8000.0f, lo, 1.0f);
        f32 s = sinf(t * 3.1415927f * 0.5f);
        a = W1636Lerp(D_01e2bdf0, D_01e2bdd0, s);
        b = W1636Lerp(D_01e2bde0, D_01e2bdc0, s);
    } else {
        a = D_01e2bdd0;
        b = D_01e2bdc0;
    }
    if (pos.z < -8000.0f) {
        f32 t = W1636Clamp((pos.z - -14000.0f) / 6000.0f, 0.0f, 1.0f);
        f32 s = sinf(t * 3.1415927f * 0.5f);
        W1636V4 e;
        W1636LerpTo(&e, D_01e2be00, a, s);
        a = e;
    }
    p->a1 = pos + a;
    p->b1 = pos + b;
    p->f80 = p->f144 * 0.017453292f;
    worldmap__Camera__update(p);
    asm("" : : "r"(ph));
    return 1;
}
}

// ---- 002c6c60: create the target and register it (from auto80_199_queue.cpp)
namespace n002c6c60 {
u32 func_001050d8(...) asm("func_001050d8");
u32 func_002c6218() asm("func_002c6218");
u32 func_002c6228(...) asm("func_002c6228");
void func_002c6780(u32, u32, u32) asm("func_002c6780");
void func_002c6c60(u32 a0, u32 a1) asm("func_002c6c60");
void func_002c6c60(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s2 = a1;

    u32 s0 = func_001050d8(160);
    func_002c6780(s0, s1, s2);

    u32 v0 = func_002c6218();
    func_002c6228(v0, 0, s0);
}
}

// ---- 002c6cc8: instance getter (never written before)
namespace n002c6cc8 {
extern u8* D_00361db8 asm("D_00361db8");
u8* func_002c6cc8() asm("func_002c6cc8");
u8* func_002c6cc8() { return D_00361db8; }
}

// ---- 002c6cd8: static initializer for five vectors (from batch_w284.cpp)
namespace n002c6cd8 {
struct V4w284 { f32 x, y, z, w; };
static inline void set4w284(V4w284* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
extern V4w284 D_01e2bdc0 asm("D_01e2bdc0");
extern V4w284 D_01e2bdd0 asm("D_01e2bdd0");
extern V4w284 D_01e2bde0 asm("D_01e2bde0");
extern V4w284 D_01e2bdf0 asm("D_01e2bdf0");
extern V4w284 D_01e2be00 asm("D_01e2be00");
void wtarget_002c6cd8(u32, u32, u32, u32) asm("_Z16wtarget_002c6cd8jjjj");
void wtarget_002c6cd8(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) { f32 z = 0.0f; set4w284(&D_01e2bdc0, z, -500.0f, z, 1.0f); }
    if (b == 0xffff && a == 1) set4w284(&D_01e2bdd0, 0.0f, -2300.0f, -3000.0f, 1.0f);
    if (b == 0xffff && a == 1) set4w284(&D_01e2bde0, 0.0f, -1760.0f, -3180.0f, 1.0f);
    if (b == 0xffff && a == 1) set4w284(&D_01e2bdf0, 0.0f, -790.0f, -8580.0f, 1.0f);
    if (b == 0xffff && a == 1) set4w284(&D_01e2be00, 0.0f, -2500.0f, -2000.0f, 1.0f);
}
}

// ---- 002c6e78 / 002c6e98: _GLOBAL__I_ stub (from tiny_wrappers_more.cpp) and _GLOBAL__D_ stub (never written)
namespace n002c6e78 {
u32 func_002c6cd8(u32, u32, u32, u32) asm("_Z16wtarget_002c6cd8jjjj");
u32 func_002c6e78(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c6e78");
u32 func_002c6e78(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002c6cd8(0x00000001u, 0x0000ffffu, a2, a3);
}
u32 func_002c6e98(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c6e98");
u32 func_002c6e98(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002c6cd8(0, 0x0000ffffu, a2, a3);
}
}
