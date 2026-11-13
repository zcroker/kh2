#include "../common/types.h"

// Ts::ACTION_SKATEBOARD and its states (skate, trick, jump, land, rail grind, path follow), 0x2eaf38-0x2ecd98.
// Linked unit. The globals (0x363540.., 0x1e2c050..) stay retail data; the three angle constants
// set by the static initialiser are .bss at 0x1e2c040.

struct HV {
    f32 x, y, z, w;
    HV() {}
    HV(const HV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    HV& operator=(const HV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

typedef unsigned int u128 __attribute__((mode(TI)));
namespace YS { struct OBJ; }

void h_0017c4c8(void*, HV*) asm("func_0017c4c8");
void h_0017c430(void*) asm("func_0017c430");
void h_0017c660(void*, void*) asm("func_0017c660");
HV h_0017c870(void*, void*, f32, f32) asm("func_0017c870");
void h_change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void h_set_pos(void*, HV*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
HV h_get_current_pos(void*) asm("_ZN2Ti4Path15get_current_posEv");
void h_reset_current_pointer(void*, HV*) asm("_ZN2Ti4Path21reset_current_pointerERKN2kn7FVectorE");
HV* h_0016c028(void*) asm("func_0016c028");
void h_set_skateboard_mode(void*, s32) asm("_ZN2YS4SORA19set_skateboard_modeEi");
void h_score_stop(void*) asm("_ZN2Ts15SKATEBOARDSCORE4stopEv");
void h_0017f5f8(void*, s32, s32, f32, f32) asm("func_0017f5f8");
void h_motion_push(void*, s32, s32, f32, f32) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
HV h_00184540(void*, f32, f32) asm("func_00184540");
HV h_002eaf48(void*, s32) asm("func_002eaf48");
HV h_002eb4f0(void*) asm("func_002eb4f0");
void h_002eb4b0(void*) asm("func_002eb4b0");
void h_002eb6f8(void*, s32, f32) asm("func_002eb6f8");
void h_002eb778(void*, s32, s32, f32) asm("func_002eb778");
void h_002eb778_3(void*, s32, s32) asm("func_002eb778");
void h_002eb7f0(void*, s32, f32) asm("func_002eb7f0");
void h_002eb9d8(void*, void*, s32, f32) asm("func_002eb9d8");
void h_002eba78(void*, void*) asm("func_002eba78");
void h_002ebac0(void*, void*) asm("func_002ebac0");
extern s32 D_00363540 asm("D_00363540");
extern u32 D_00363560 asm("D_00363560");
extern u8 D_00363548 asm("D_00363548");
extern void* D_003637d0 asm("D_003637d0");
extern HV D_01e2c050 asm("D_01e2c050");

void func_002eaf38(void* p) {}

u8* func_002eaf40(void* p) {
    return *(u8**)((u8*)p + 572);
}

void wtarget_002eb460(u8* o, HV* q) asm("_Z16wtarget_002eb460jjjj");

extern f32 s_turn_small asm("D_01e2c040");   // set by the static initialiser in unit_002ec5f8.cpp
extern f32 s_turn_big asm("D_01e2c044");

// ---- 2eaf48 (src/anon/batch_w94.cpp)
namespace n2eaf48 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void qcopy(V4* d, V4* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
u8* func_0016c028(u8*) asm("func_0016c028");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
void func_002cbf08(void*, u32) asm("func_002cbf08");
void func_0016af58(void*, u8*) asm("func_0016af58");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
void* func_002cb8b8(u32) asm("func_002cb8b8");
void* func_002cb8e0(u32) asm("func_002cb8e0");
u8* func_0016c028(u8*) asm("func_0016c028");
void func_002cb7a0(u32, s32, void*) asm("func_002cb7a0");
struct V4e { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void qcopy(V4e* d, void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 vdot(V4e* a, V4e* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\t"
                 "vaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
extern "C" V4e* func_002eaf48(V4e* out, u8* obj, u8 notify) {
    u32 h = *(u32*)(obj + 1288);
    V4e t;
    func_002cbf08(&t, h);
    qcopy(out, &t);
    *(u32*)&out->y = 0;
    func_0016af58(&t, obj);
    if (func_003142e0(func_00313b80(vdot(out, &t)), 0.0) < 0) {  // double_compare
        qcopy(out, func_002cb8b8(h));
        if (notify) func_002cb7a0(h, 0, func_0016c028(obj));
    } else {
        qcopy(out, func_002cb8e0(h));
        if (notify) func_002cb7a0(h, 1, func_0016c028(obj));
    }
    return out;
}
}

// ---- 2eb068
extern "C" u32 func_002eb068(u8* p) {
    s32 t = *(s32*)(*(u8**)(p + 12) + 4);
    u32 r = 0;
    if ((t ^ 0x3d) == 0 || (t ^ 0x33) == 0) r = 1;
    return r;
}

// ---- 2eb098 (src/anon/batch_w1818.cpp)
namespace n2eb098 {
#define QCOPY1818(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec1818 {
    f32 x, y, z, w;
    Vec1818() {}
    Vec1818(const Vec1818& o) { QCOPY1818(this, &o); }
    Vec1818& operator=(const Vec1818& o) { if (this != &o) QCOPY1818(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline Vec1818 operator-(const Vec1818& a, const Vec1818& b) {
    Vec1818 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vlensq1818(const Vec1818& v) {
    f32 l;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(l) : "r"(&v) : "$8", "memory");
    return l;
}
struct Obj1818 { u32 a, b; s32* id; };
struct Act1818 { u8 pad[0x508]; u32 p; };
Vec1818* func_0016c028(Obj1818*) asm("func_0016c028");
Vec1818* func_0016c028_a(Act1818*) asm("func_0016c028");
Vec1818 func_002cbed8(u32) asm("func_002cbed8");
extern "C" s32 func_002eb098(Act1818* a) {
    s32 r = 0;
    if (a->p) {
        Vec1818 t = func_002cbed8(a->p);
        f32 h = 30.0f;
        if (func_0016c028_a(a)->y - h < t.y && t.y < func_0016c028_a(a)->y + h) {
            Vec1818 d;
            d = *func_0016c028_a(a) - t;
            d.y = 0;
            r = vlensq1818(d) < 2500.0f;
        }
    }
    return r;
}
}

// ---- 2eb1a0
extern "C" void func_002eb1a0(u8* o) {
    HV t = h_get_current_pos(*(void**)(o + 1288));
    h_set_pos(o, &t);
    h_change_action(o, 51);
}

// ---- 2eb1e8 (src/anon/batch_w3828.cpp)
namespace n2eb1e8 {
struct V3 {
    f32 x, y, z, w;
    V3() {}
    V3& operator=(const V3& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct B3 { f32 v[8]; };
#define F3(o, off, T) (*(T*)((u8*)(o) + (off)))
extern u8* D_0034e948 asm("D_0034e948");
s32 func_002eb068(u8*) asm("func_002eb068");
void* func_0019b260(s32) asm("func_0019b260");
s32 func_00184eb8(u8*, s32, void*) asm("func_00184eb8");
V3* func_0016c028(u8*) asm("func_0016c028");
void func_002cbec0(void*, V3*) asm("func_002cbec0");
V3 func_002cbed8(void*) asm("func_002cbed8");
V3 func_002eaf48(u8*, s32) asm("func_002eaf48");
s32 func_002eaf40(u8*) asm("func_002eaf40");
void func_00190128(B3*) asm("func_00190128");
void func_00190878(B3*, s32, s32) asm("func_00190878");
s32 func_001bd3e0(s32, s32, s32, B3*, s32, s32) asm("func_001bd3e0");
double func_00313b80(f32) asm("func_00313b80") __attribute__((const));
s32 func_003142e0(double, double) asm("func_003142e0") __attribute__((const));
static inline __attribute__((always_inline)) void vsub(const V3* a, const V3* b, V3* d) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
        : : "r"(a), "r"(b), "r"(d) : "memory");
}
static inline __attribute__((always_inline)) V3 operator-(const V3& a, const V3& b) {
    V3 r; vsub(&a, &b, &r); return r;
}
static inline __attribute__((always_inline)) f32 vlen(const V3* v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
V3* func_002cbed8r(V3*, void*) asm("func_002cbed8");
V3* func_002eaf48r(V3*, u8*, s32) asm("func_002eaf48");
extern "C" void func_002eb1e8(u8* self) {
    
    if (func_002eb068(self)) return;
    void* t = func_0019b260(F3(self, 0xb4c, s32));
    if (!t) return;
    if (!func_00184eb8(self, -1, t)) return;
    register void* m asm("$17") = F3(self, 0x508, void*);
    V3 d, B, A;
    register V3* ta asm("$20") = &A; asm("" : "+r"(ta));
    register V3* tb asm("$19") = &B;
    func_002cbec0(m, func_0016c028(self));
    { void* mm = m; asm("" : "+r"(mm)); func_002cbed8r(ta, mm); }
    asm volatile("" : "+r"(tb));
    vsub(ta, func_0016c028(self), tb);
    d = *tb;
    f32 len = vlen(&d);
    asm("" : "+r"(ta));
    func_002eaf48r(ta, self, 0);
    vsub(ta, func_0016c028(self), tb);
    d = *tb;
    if (func_003142e0(func_00313b80(len), 300.0) >= 0) return;
    if (!(300.0f < vlen(&d))) return;
    {
    register s32 o asm("$18") = F3(D_0034e948, 0xb44, s32);
    register s32 e asm("$17") = func_002eaf40(self);
    B3 b;
    register void* tc asm("$16") = &b;
    func_00190128((B3*)tc);
    func_00190878((B3*)tc, e, 0);
    func_001bd3e0(o, 1, 523, (B3*)tc, 1, 100);
    register int ph asm("$21"); asm volatile("" : "=r"(ph));
    }
}
}

// ---- 2eb3b8 (src/anon/batch_wcx.cpp)
namespace n2eb3b8 {
u32 func_002eaf40(u8*) asm("func_002eaf40");
s32 func_001c0cd8(u32) asm("func_001c0cd8");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
s32 func_0019c090(u8*) asm("func_0019c090");
void func_0017c430(u8*, s32, f32) asm("func_0017c430");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
extern "C" s32 func_002eb3b8(u8* p)
{
    u32 r = func_002eaf40(p);
    u8* q = p + 320;
    if ((*(u32*)(p + 352) & 0x4000) && func_001c0cd8(r)) return 0;
    if (*(u32*)(p + 352) & 0x4000) func_0017f488(q, 0, 0.0f, 0.0f);
    if (func_0019c090(p)) {  // obj_is_enabled
        func_0017c430(p, 0, 0.0f);
        func_0016bd60(p, 1);
    } else {
        func_0016bd60(p, 0);
    }
    return 1;
}
}

// ---- 2eb460
void wtarget_002eb460(u8* o, HV* q) {
    HV t(*q);
    h_0017c4c8(o, &t);
    *(u32*)(o + 256) = 256;
    *(u32*)(o + 260) = 257;
    h_change_action(o, 49);
}

// ---- 2eb4b0
extern "C" void func_002eb4b0(u8* p) {
    h_0017c430(p);
    *(u32*)(p + 256) = 256;
    *(u32*)(p + 260) = 257;
    h_change_action(p, 49);
}

// ---- 2eb4f0 (src/anon/batch_w1997.cpp)
namespace n2eb4f0 {
struct Vec4f0 {
    f32 x, y, z, w;
    Vec4f0() {}
    Vec4f0(const Vec4f0& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vec4f0& operator=(const Vec4f0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj4f0 { u8 pad[16]; Vec4f0 v10; Vec4f0 v20; u8 pad2[284 - 48]; f32 f11c; };
Vec4f0 func_0016af58(Obj4f0*) asm("func_0016af58");
void func_00184ad0(Obj4f0*, Vec4f0*, f32) asm("func_00184ad0");
void func_00184540(u8*, u32, f32, f32) asm("func_00184540");
f32 cosf(f32) asm("cosf");
f32 fabsf(f32) asm("fabsf");
u64 func_00313b80(f32) asm("func_00313b80") __attribute__((const));
s32 func_003142e0(u64, u64) asm("func_003142e0") __attribute__((const));
extern s8 D_01e2c068 asm("D_01e2c068");
extern f32 D_01e2c070 asm("D_01e2c070");
static inline f32 v4f0_len(const Vec4f0& v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
static inline Vec4f0 v4f0_scale(const Vec4f0& v, f32 s) {
    Vec4f0 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
static inline f32 v4f0_norm(Vec4f0* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 v4f0_dot(const Vec4f0& a, const Vec4f0& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
extern "C" u8* func_002eb4f0(u8* ret, Obj4f0* o) {
    if (!D_01e2c068) {
        D_01e2c070 = cosf(0.34906584f);
        D_01e2c068 = 1;
    }
    Vec4f0 a;
    if (func_003142e0(0, func_00313b80(o->v10.w)) < 0) {
        func_00184ad0(o, &o->v10, o->f11c);
        a = func_0016af58(o);
        f32 l = v4f0_len(o->v20);
        o->v20 = v4f0_scale(a, l);
        a.w = o->v10.w;
        o->v10 = a;
    }
    a = o->v20;
    v4f0_norm(&a);
    Vec4f0 b = func_0016af58(o);
    f32 d = fabsf(v4f0_dot(a, b));
    f32 k = d < D_01e2c070 ? 0.1f : 0.015f;
    func_00184540(ret, (u32)o, 0.4f, 1.0f - k);
    return ret;
}
}

// ---- 2eb6f8 (src/anon/batch_wcx2.cpp)
namespace n2eb6f8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00180c88(u8*, u32, f32) asm("func_00180c88");
u8* func_002eaf40(u8*) asm("func_002eaf40");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
extern "C" void func_002eb6f8(u8* p, s32 id, f32 x) {
    if (id < 0) return;
    func_00180c88(p + 320, id, x);
    func_002eaf40(p);
    func_0017f488(func_002eaf40(p) + 320, id - 101, x, 0.0f);
}
}

// ---- 2eb778 (src/anon/batch_w2432.cpp)
namespace n2eb778 {
void func_002eb6f8(u8*, s32, f32) asm("func_002eb6f8");
#define W2432_AI static inline __attribute__((always_inline))
W2432_AI bool w2432_c5(u32 f) { bool r = false; if (f & 4) goto y; if (f & 8) goto y; if (!(f & 0x10)) goto n; y: r = true; n: return r; }
extern "C" void func_002eb778(u8* p, s32 a1, bool a2, f32 x)
{
    if (!a2) {
        u32 f = *(u32*)(p + 0x160);
        if (!w2432_c5(f) && !(f & 0x10)) return;
        if (*(s32*)(p + 0x154) == a1) return;
    }
    func_002eb6f8(p, a1, x);
}
}

// ---- 2eb7f0
extern "C" void func_002eb7f0(u8* o, s32 n, f32 f) {
    h_0017f5f8(o + 320, n, 0, f, 0.0f);
    h_motion_push(func_002eaf40(o) + 320, n - 101, 0, f, 0.0f);
}

// ---- 2eb868
extern "C" void func_002eb868(u8* p) {
    D_00363540 = 0;
    h_002eb778_3(p, 252, 0);
}

// ---- 2eb890 (src/anon/batch_w1672.cpp)
namespace n2eb890 {
struct Q16w1672 {
    u32 w[4];
    Q16w1672& operator=(const Q16w1672& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n sq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u32 D_00363544 asm("D_00363544");
extern u32 D_00363560 asm("D_00363560");
void func_002edb38(void) asm("func_002edb38");
void set_special_command_w1672(u32, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void change_action_w1672(u8*, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_002eb868(u8*, f32) asm("func_002eb868");
extern "C" void func_002eb890(u8* p, u32 b) {
    Q16w1672 z;
    asm volatile("vsub.xyzw $vf1,$vf0,$vf0\n sqc2 $vf1,0(%0)" : : "r"(&z) : "memory");
    *(Q16w1672*)(p + 32) = z;
    *(u32*)(p + 0x100) = 4;
    *(u32*)(p + 0x104) = 5;
    D_00363544 = 0;
    D_00363560 = 0;
    func_002edb38();
    set_special_command_w1672(b, 2);
    change_action_w1672(p, 48);
    func_002eb868(p, 0.0f);
}
}

// ---- 2eb920
extern "C" void func_002eb920(u8* o, s32 n, f32 f) {
    func_002eaf38(o);
    h_002eb778(o, n, 1, f);
    if ((*(u32*)(*(u8**)(o + 12) + 4) ^ 0x31) == 0)
        *(u32*)(o + 268) &= ~1;
}

// ---- 2eb990
namespace Ts {
struct ACTION_SKATEBOARD {
    static void Trick(YS::OBJ* o, s32 n, f32 f);
};
void ACTION_SKATEBOARD::Trick(YS::OBJ* o, s32 n, f32 f) {
    func_002eaf38(o);
    h_002eb7f0(o, n, f);
}
}

// ---- 2eb9d8
extern "C" void func_002eb9d8(void* c, u8* o, s32 k, f32 f) {
    u32 fl = *(u32*)(o + 352);
    u8* m = o + 320;
    if (!(fl & 4)) {
        if (!(fl & 0x10)) return;
        if (k == 252) return;
    }
    if (*(s32*)(m + 20) == k) return;
    h_002eb6f8(o, k, f);
}

// ---- 2eba30
extern "C" void func_002eba30(void* c, u8* o) {
    D_00363540 = 0;
    h_002eb9d8(c, o, 252, 8.0f);
    u8* v = o + 32;
    asm volatile("vsub.xyzw $vf1,$vf0,$vf0\n sqc2 $vf1,0(%0)" : : "r"(v) : "memory");
}

// ---- 2eba78
extern "C" void func_002eba78(void* a, u8* b) {
    *(f32*)(b + 276) = *(f32*)(b + 272) = 16.0f;
    *(f32*)(b + 284) = s_turn_small;
    h_002eb9d8(a, b, 253, 8.0f);
}

// ---- 2ebac0
extern "C" void func_002ebac0(void* a, u8* b) {
    *(f32*)(b + 276) = *(f32*)(b + 272) = 20.0f;
    *(f32*)(b + 284) = s_turn_big;
    h_002eb9d8(a, b, 254, 4.0f);
}

void skate_2ebb08(void* c, u8* o) {
    D_00363560 = 0;
    *(f32*)(o + 280) = 385.0f;
    h_set_skateboard_mode(o, 1);
    HV v;
    v = *(HV*)(o + 2144);
    v.y = 0.0f;
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    if (8.0f <= len)
        h_002ebac0(c, o);
    else if (v.y < len)
        h_002eba78(c, o);
}

void skate_2ebbd8(void* c, u8* o) {
    f32* t = *(f32**)(o + 300);
    *(f32*)(o + 272) = t[0];
    *(f32*)(o + 276) = t[1];
    *(f32*)(o + 284) = t[3];
    *(f32*)(o + 280) = t[2];
}

extern "C" void func_002ebc00(void* c, u8* o, HV* q) {
    wtarget_002eb460(o, q);
}

void skate_2ebc20(void* c, u8* o) {
    h_002eb4b0(o);
}

extern "C" void func_002ebc38(void** c, u8* o) {
    (*(void (**)(void*, void*, f32))(*(u8**)c + 12))(c, o, 0.0f);
    *(u32*)(o + 264) |= 0x4000000;
}

void skate_2ebc78(void* c, u8* o) {}

// ---- 2ebc80 (src/anon/batch_wcx2_nsa.cpp)
namespace n2ebc80 {
inline void* operator new(unsigned int, void* p) { return p; }
#define W2db210_QCOPY(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct W2db210Vec {
    f32 x, y, z, w;
    W2db210Vec() {}
    W2db210Vec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    W2db210Vec operator*(f32 k) const
    {
        W2db210Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    void Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    W2db210Vec(const W2db210Vec& o) { W2db210_QCOPY(this, &o); }
    W2db210Vec& operator=(const W2db210Vec& o) { if (this != &o) W2db210_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline W2db210Vec operator*(f32 k, const W2db210Vec& v) { return v * k; }
struct V2ebc80 {
    f32 x, y, z, w;
    V2ebc80() {}
    V2ebc80& operator=(const V2ebc80& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 length() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct O2ebc80 {
    u8 pad0[16];
    f32 x, y, z, w;
    f32 tx, ty, tz, tw;
    u8 pad1[320 - 48];
    struct { u8 pad[20]; s32 id; } mot;
    s32 motion() { return mot.id; }
    u8 pad2[8];
    u32 flags;
    u8 pad3[2144 - 356];
    V2ebc80 vel;
};
extern s32 D_00363540 asm("D_00363540");
extern f32 D_01e2c044 asm("D_01e2c044");
void func_002eb1e8(O2ebc80*) asm("func_002eb1e8");
s32 func_002eb3b8(O2ebc80*) asm("func_002eb3b8");
void func_002eba30(void*, O2ebc80*) asm("func_002eba30");
void func_002eba78(void*, O2ebc80*) asm("func_002eba78");
void func_002ebac0(void*, O2ebc80*) asm("func_002ebac0");
void func_002eb778(O2ebc80*, s32, s32, f32) asm("func_002eb778");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_0017ce10(f32) asm("func_0017ce10");
extern "C" void func_002ebc80(void* c, O2ebc80* o)
{
    func_002eb1e8(o);
    if (func_002eb3b8(o)) return;
    V2ebc80 v;
    v = o->vel;
    v.y = 0.0f;
    f32 spd = v.length();
    if (o->w == v.y) {
        if (spd < 2.0f) {
            func_002eba30(c, o);
            return;
        }
        if (o->w == 0.0f) {
            if (o->motion() == 253 || o->motion() == 252 || (o->flags & 2)) {
                func_002eb778(o, 254, 0, 8.0f);
                if (spd < 16.0f) D_00363540 = 0;
            } else if (o->motion() == 262 || o->motion() == 261) {
                func_002eb778(o, 254, 0, 16.0f);
            }
            return;
        }
    }
    typeof(o->mot)* mo = &o->mot;
    if (mo->id == 252) {
        func_002eba78(c, o);
        return;
    }
    if (mo->id == 253) {
        if (!(o->flags & 2)) return;
        if (++D_00363540 <= 0) return;
        if (8.0f <= spd) func_002ebac0(c, o);
        return;
    }
    if (D_00363540 > 0) {
        s32 next = 254;
        f32 d = func_0017ce10(func_002f8ad0(o->tx, o->tz) - func_002f8ad0(o->x, o->z));
        if (D_01e2c044 * 0.6f < d) next = 261;
        else if (d < D_01e2c044 * -0.6f) next = 262;
        if (__builtin_expect(mo->id == 253, 1)) func_002eb778(o, next, 0, 4.0f);
        else func_002eb778(o, next, 0, 16.0f);
    } else {
        func_002eba78(c, o);
    }
}
}

// ---- 2ebf10
HV skate_2ebf10(void* c, u8* o) {
    HV r;
    r = h_002eb4f0(o);
    return r;
}

// ---- 2ebf50 (src/anon/batch_w3708_nsa.cpp)
namespace n2ebf50 {
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec(const Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 vnorm(Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct Obj { u8 pad[16]; Vec v16; Vec v32; u8 pad2[256 - 48]; s32 w256; s32 w260; u8 pad3[1300 - 264]; u8 b1300; };
extern void* D_003637d0 asm("D_003637d0");
void func_002eda90(void*, s32, f32) asm("func_002eda90");
Vec func_0017c030(Obj*, Vec*, u8) asm("func_0017c030");
void func_0017c4c8(Obj*, Vec) asm("func_0017c4c8");
void func_002eb778(Obj*, s32, s32, f32) asm("func_002eb778");
void fx0017c030(Vec*, Obj*, Vec*, u32) asm("func_0017c030");
static inline Vec get2ebf50(Obj* o, u8 k) { Vec t; Vec r; register Vec* a0 asm("$4") = &r; register Obj* a1 asm("$5") = o; register u32 a3 asm("$7") = k; register Vec* a2 asm("$6"); asm("la %0,%1" : "=r"(a2) : "m"(t), "r"(a0), "r"(a1), "r"(a3)); fx0017c030(a0, a1, a2, a3); return r; }
extern "C" void func_002ebf50(void* self, Obj* o, u8 k) {
    Vec v = o->v32;
    f32 len = vnorm(&v);
    v.w = len;
    if (o->v16.w < len) o->v16 = v;
    func_002eda90(D_003637d0, 1, 60.0f);
    v = get2ebf50(o, k);
    v.y = 385.0f;
    func_0017c4c8(o, v);
    o->b1300 = 8;
    func_002eb778(o, 255, 0, 0.0f);
    o->w256 = 256;
    o->w260 = 257;
}
}

// ---- 2ec088 (src/anon/batch_w36.cpp)
namespace n2ec088 {
extern f32 D_01e2c048 asm("D_01e2c048");
void func_001d14b0(u8*, u32) asm("func_001d14b0");
void func_0017c578(u32, u8*) asm("func_0017c578");
extern "C" void func_002ec088(u32 a, u8* p) {
    *(f32*)(p + 276) = *(f32*)(p + 272) = 20.0f;
    *(f32*)(p + 284) = D_01e2c048;
    *(f32*)(p + 284) = *(f32*)(*(u8**)(p + 300) + 12);
    func_001d14b0(p, 2);
    func_0017c578(a, p);
}
}

// ---- 2ec0f8
void jump_2ec0f8(void* c, u8* o) {
    h_0017c660(c, o);
    f32* t = *(f32**)(o + 300);
    *(f32*)(o + 272) = t[0];
    *(f32*)(o + 276) = t[1];
    *(f32*)(o + 284) = t[3];
}

extern "C" void func_002ec138(void* c, u8* o, HV* q) {
    wtarget_002eb460(o, q);
}

void jump_2ec158(void* c, u8* o) {
    h_002eb4b0(o);
}

// ---- 2ec170 (src/anon/batch_w49.cpp)
namespace n2ec170 {
void func_002eb778(u8*, u32, s32, f32) asm("func_002eb778");
extern "C" void func_002ec170(u32, u8* p) {
    func_002eb778(p, *(u32*)(p + 256), 0, 8.0f);
    *(u32*)(p + 268) &= ~1;
    *(u32*)(p + 264) |= 0x4000000;
}
}

// ---- 2ec1d0
namespace Ts {
struct ACTION_SKATEBOARDJUMP {
    void land(YS::OBJ* o);
};
void ACTION_SKATEBOARDJUMP::land(YS::OBJ* obj) {
    u8* o = (u8*)obj;
    h_002eb778(o, *(s32*)(o + 260), 1, 0.0f);
    h_002eb7f0(o, 252, 0.0f);
    h_change_action(o, 48);
    *(u32*)(o + 264) |= 0x8000000;
    h_score_stop(D_003637d0);
}
}

// ---- 2ec248
extern "C" void func_002eb1e8(u8*);
extern "C" s32 func_002eb3b8(u8*);
s32 h_0017cb48(void*, void*) asm("func_0017cb48");
extern f32* D_00352130 asm("D_00352130");

void rail_2ec248(void** c, u8* o) {
    func_002eb1e8(o);
    if (func_002eb3b8(o)) return;
    if (6.0f < *(f32*)(o + 208) && *(f32*)(o + 208) < *(f32*)(o + 212) && (*(u32*)(o + 264) & 0x400000)) {
        (*(void (**)(void*, void*))(*(u8**)c + 16))(c, o);
        void** m = *(void***)(o + 12);
        (*(void (**)(void*, void*, f32))(*(u8**)m + 12))(m, o, 0.0f);
        u32 f = *(u32*)(o + 264);
        f &= ~0x20000;
        f &= ~0x40000;
        *(u32*)(o + 264) = f;
        if (*(u32*)(o + 1416) & 4) *(f32*)(o + 2480) = D_00352130[1];
    }
    if ((*(u32*)(o + 264) & 0x40000) && 6.0f < *(f32*)(o + 208) && *(f32*)(o + 208) < *(f32*)(o + 212) - 5.0f) {
        (*(void (**)(void*, void*))(*(u8**)c + 16))(c, o);
        void** m = *(void***)(o + 12);
        (*(void (**)(void*, void*, f32))(*(u8**)m + 12))(m, o, 5.102040f);
        *(u32*)(o + 264) &= ~0x40000;
    } else if (h_0017cb48(c, o) && *(f32*)(o + 212) <= *(f32*)(o + 208) + 5.0f) {
        (*(void (**)(void*, void*))(*(u8**)c + 16))(c, o);
        *(u32*)(o + 264) &= ~0x20000;
    }
    HV v;
    v = *(HV*)(o + 2208);
    v.y = 0.0f;
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    if (5.0f < len) h_score_stop(D_003637d0);
}

HV rail_2ec468(void* c, void* o) {
    return h_0017c870(c, o, 0.9f, 0.985f);
}

// ---- 2ec4a8 (src/anon/batch_w1783_nsa.cpp)
namespace n2ec4a8 {
struct EO { u8 _0[0x90]; u32 _90; };
struct EA { u8 _0[0x508]; EO* _508; };
void func_001d14b0(EA*, s32) asm("func_001d14b0");
u8 func_002cd008(EO*, u32) asm("func_002cd008");
void func_002eda90(u32, s32, f32) asm("func_002eda90");
void func_002edaf8(u32) asm("func_002edaf8");
extern u32 D_00363560 asm("D_00363560");
extern u8 D_01e2c064 asm("D_01e2c064");
extern u32 D_003637d0 asm("D_003637d0");
extern f32 D_0036354c asm("D_0036354c");
extern "C" void func_002ec4a8(u32 a0, EA* a1) {
    func_001d14b0(a1, 3);
    D_01e2c064 = func_002cd008(a1->_508, D_00363560) ^ 1;
    u8 v = D_01e2c064;
    D_00363560 = a1->_508->_90;
    if (v) func_002eda90(D_003637d0, 20, 60.0f);
    else func_002edaf8(D_003637d0);
    D_0036354c = 12.0f;
}
}

// ---- 2ec550
void rail_2ec550(void) {
    D_00363548 = 0;
}

extern "C" void func_002ec560(void* c, u8* o, HV* q) {
    wtarget_002eb460(o, q);
}

void rail_2ec580(void* c, u8* o) {
    h_002eb4b0(o);
}

void rail_2ec598(void* c, u8* o) {
    *(u32*)(o + 264) |= 0x4000000;
}

extern "C" void func_002ec5b0(void* c, u8* o) {
    h_002eb778(o, 269, 0, 0.0f);
    *(u32*)(o + 264) |= 0x8000000;
}

