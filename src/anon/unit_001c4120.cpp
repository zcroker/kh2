#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"

// ---- 001c40e0: C2 constructor copy (same body as 0x1c4120)
namespace n001c40e0 {
extern u8 D_00351580 asm("D_00351580");
u32 func_001b1d20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b1d20jjjj");
u32 func_001c40e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c40e0");
u32 func_001c40e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001b1d20(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(2748));
    r15 = (u32)&D_00351580;
    r14 = (u32)(r14 | 0x0080u);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r16 + (s32)(2748)) = r14;
    return r2;
}
}  // namespace n001c40e0

// ---- 001c4120 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001c4120 {
extern u8 D_00351580 asm("D_00351580");
u32 func_001b1d20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001b1d20jjjj");
u32 func_001c4120(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c4120jjjj");
u32 func_001c4120(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001b1d20(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(2748));
    r15 = (u32)&D_00351580;
    r14 = (u32)(r14 | 0x0080u);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r16 + (s32)(2748)) = r14;
    return r2;
}
}  // namespace n001c4120

// ---- 001c4160 from src/anon/tiny.cpp
namespace n001c4160 {
u32 func_001c4160(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c4160jjjj");
u32 func_001c4160(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u8*)((u32)b + (5644)));
}
}  // namespace n001c4160

// ---- 001c4170 from src/anon/batch_w4.cpp
namespace n001c4170 {
extern s32 D_00351604 asm("D_00351604");
extern s32 D_00351608 asm("D_00351608");
s32 func_001c4170(void) asm("func_001c4170");
s32 func_001c4170(void) {
    return D_00351604 - D_00351608;
}
}  // namespace n001c4170

// ---- 001c4188 from src/anon/batch_w1765.cpp
namespace n001c4188 {
struct W1765Ent { s32 a, b; f32 f; };
extern s32 D_00351600 asm("D_00351600");
extern W1765Ent D_01d49658[] asm("D_01d49658");
void func_001c4200(void*, s32) asm("func_001c4200");
void func_001c4188(void* p, f32 x) asm("func_001c4188");
void func_001c4188(void* p, f32 x) {
    s32 i;
    for (i = 0; i < D_00351600; i++) {
        if (D_01d49658[i].f < x) { func_001c4200(p, i); return; }
    }
    if (D_00351600 == 0) func_001c4200(p, 0);
}
}  // namespace n001c4188

// ---- 001c4200 from src/anon/batch_w2369_nsa.cpp
namespace n001c4200 {
struct ListEnt12 { u32 a; u32 b; f32 c; };
extern ListEnt12 D_01d49658[30] asm("D_01d49658");
extern s32 D_00351600 asm("D_00351600");
void func_001c4200(u32 a, s32 idx, f32 f) asm("func_001c4200");
void func_001c4200(u32 a, s32 idx, f32 f) {
    for (s32 i = D_00351600 - 2; i >= idx; i--) D_01d49658[i + 1] = D_01d49658[i];
    ListEnt12* e = &D_01d49658[idx];
    e->a = a;
    (&D_01d49658[0].b)[idx * 3] = 0;
    e->c = f;
    s32 n = D_00351600 + 1;
    D_00351600 = (n < 31) ? n : 30;
}
}  // namespace n001c4200

// ---- 001c42a0 from src/anon/tiny_auto80_solver.cpp
namespace n001c42a0 {
extern u8 D_01d49658 asm("D_01d49658");
void func_001c42a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001c42a0jjjjjjjj");
void func_001c42a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r14 = (u32)(0x0035u << 16);
    r15 = (u32)&D_01d49658;
    *(u32*)((u32)r14 + (s32)(5632)) = 0u;    *(u32*)((u32)r15 + (s32)(8)) = 0u;
    *(u32*)((u32)r15 + (s32)(4)) = 0u;
}
}  // namespace n001c42a0

// ---- 001c42c0 from src/anon/batch_w1882.cpp
namespace n001c42c0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q1882V4 {
    f32 x, y, z, w;
    Q1882V4() {}
    Q1882V4& operator=(const Q1882V4& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Q1882Obj { Q1882V4 pos; u8 pad[48]; Q1882V4 vel; u8 b80; u8 pad2[3]; void* fn; };
struct Q1882Ent { Q1882Obj* p; u32 flags; u32 pad; };
extern s32 D_00351600 asm("D_00351600");
extern Q1882V4 D_00352a60 asm("D_00352a60");
extern Q1882Ent D_01d49658[] asm("D_01d49658");
s32 func_001c4170(void) asm("func_001c4170");
void func_001c4ff0(void) asm("func_001c4ff0");
void func_001c42c0(void) asm("func_001c42c0");
void func_001c42c0(void) {
    s32 i;
    u32* fb = &D_01d49658[0].flags;
    for (i = 0; i < D_00351600; i++) {
        f32 k = 20.0f;
        u32* fp = fb + i * 3;
        u32 f = *fp;
        if ((f & 1) == 1) continue;
        *fp = f | 1;
        Q1882Obj* o = *(Q1882Obj**)(fp - 1);
        if (func_001c4170() > 100) {
            o->b80 = 0;
            asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&o->vel) : "memory");
        } else {
            o->b80 = 10;
            Q1882V4* d = &o->vel;
            Q1882V4 t;
            asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(&D_00352a60), "r"(&o->pos) : "memory");
            *d = t;
            o->vel.y += -1000.0f;
            f32 len;
            asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                : "=f"(len) : "r"(d) : "$8", "memory");
            asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(d), "f"(k) : "$8", "memory");
        }
        o->fn = (void*)func_001c4ff0;
        return;
    }
}
}  // namespace n001c42c0

// ---- 001c4410 gap: C2 copy of the 0x1c4498 ctor (Mgr base ctor, vptr, wave angle table)
namespace n001c4410 {
void func_001db8f8(void*, u32, s32, s32) asm("func_001db8f8");
extern u8 D_00351618[] asm("D_00351618");
struct E16f { u8 pad[12]; f32 v; };
extern E16f D_01d49590[] asm("D_01d49590");
void func_001c4410(u8* p, u32 a1) asm("func_001c4410");
void func_001c4410(u8* p, u32 a1) {
    func_001db8f8(p, a1, 0, 1500);
    *(void**)p = D_00351618;
    for (s32 i = 0; i < 8; i++) D_01d49590[i].v = (f32)i * 0.125f * 6.2831855f;
}
}  // namespace n001c4410

// ---- 001c4498 from src/anon/batch_w58.cpp
namespace n001c4498 {
void func_001db8f8(void*, u32, s32, s32) asm("func_001db8f8");
extern u8 D_00351618[] asm("D_00351618");
struct E16f { u8 pad[12]; f32 v; };
extern E16f D_01d49590[] asm("D_01d49590");
void func_001c4498(u8* p, u32 a1) asm("func_001c4498");
void func_001c4498(u8* p, u32 a1) {
    func_001db8f8(p, a1, 0, 1500);
    *(void**)p = D_00351618;
    for (s32 i = 0; i < 8; i++) D_01d49590[i].v = (f32)i * 0.125f * 6.2831855f;
}
}  // namespace n001c4498

// ---- 001c4520 from src/anon/batch_w2355_nsa.cpp
namespace n001c4520 {
struct Pos1c4520 {
    f32 x, y, z, w;
    Pos1c4520(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
struct Obj1c4520 { u8 p0[81]; u8 variant; u8 p52[2]; void* update; s32 height; u8 p5c[4]; };
extern u32 D_003638d0 asm("D_003638d0");
extern s32 D_00351604 asm("D_00351604");
extern s32 D_00351608 asm("D_00351608");
extern u8 D_0035160c asm("D_0035160c");
extern Pos1c4520 D_01d49580 asm("D_01d49580");
void* area_alloc_1c4520(u32) asm("_ZN4AREA5AllocEj");
void func_001c4498(struct Mgr1c4520*, void*) asm("func_001c4498");
struct Mgr1c4520 {
    u8 p0[2548]; Mgr1c4520* owner; u8 p9f8[2560 - 2552];
    static void* operator new(unsigned int n) { return area_alloc_1c4520(n); }
    Mgr1c4520(void* a) { func_001c4498(this, a); }
};
Mgr1c4520* func_001dba18(void*) asm("func_001dba18");
void func_001a7610(Pos1c4520*, Pos1c4520*, s32, f32, f32) asm("func_001a7610");
Obj1c4520* func_001db888(void*, s32, void*) asm("func_001db888");
void func_001dbc58(Obj1c4520*, Mgr1c4520*, Pos1c4520*, Pos1c4520*) asm("func_001dbc58");
void func_001c4e30(void) asm("func_001c4e30");
static inline f32 frand_1c4520(f32 max) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)D_003638d0 * 2.3283064e-10f * max;
}
static inline f32 frange_1c4520(f32 lo, f32 hi) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return lo + (f32)D_003638d0 * 2.3283064e-10f * (hi - lo);
}
static inline s32 irand_1c4520(s32 n) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return ((u64)D_003638d0 * n) >> 32;
}
Mgr1c4520* func_001c4520(void* parent, Pos1c4520* centre) asm("func_001c4520");
Mgr1c4520* func_001c4520(void* parent, Pos1c4520* centre)
{
    s32 i;
    Mgr1c4520* mgr = func_001dba18(parent);
    if (mgr == 0) {
        mgr = new Mgr1c4520(parent);
        D_00351604 = 30;
        D_00351608 = 0;
        D_0035160c = 0;
    }
    Mgr1c4520* owner = mgr->owner;
    for (i = 0; i < 7; i++) {
        f32 x0 = i * 142.8571319580078f - 500.0f;
        for (s32 j = 0; j < 7; j++) {
            f32 z0 = j * 142.8571319580078f - 500.0f;
            Pos1c4520 p(centre->x + (x0 + frand_1c4520(142.8571319580078f)), centre->y,
                        centre->z + (z0 + frand_1c4520(142.8571319580078f)));
            func_001a7610(&p, &p, 4, 1000.0f, 200.0f);
            f32 h = frange_1c4520(300.0f, 400.0f);
            p.w = 1.0f;
            p.y -= h + 64.0f;
            Obj1c4520* o = func_001db888((u8*)owner + 20, 96, __builtin_return_address(0));
            func_001dbc58(o, owner, &p, &D_01d49580);
            o->update = (void*)func_001c4e30;
            o->height = (s32)h;
            o->variant = irand_1c4520(8);
            D_00351604++;
        }
    }
    return mgr;
}
}  // namespace n001c4520

// ---- 001c48a8 gap: script hook, reads params 1 and 2
namespace n001c48a8 {
void func_0016bf38(void*) asm("func_0016bf38");
s32 func_0016c008(void*, s32) asm("func_0016c008");
extern s32 D_01d49650 asm("D_01d49650");
extern u8 D_0035160c asm("D_0035160c");
void func_001c48a8(void* p) asm("func_001c48a8");
void func_001c48a8(void* p) {
    func_0016bf38(p);
    if (func_0016c008(p, 1)) D_01d49650 = func_0016c008(p, 1);
    if (func_0016c008(p, 2) == 100) D_0035160c = 1;
}
}  // namespace n001c48a8

// ---- 001c4918: ambient wave update and random ground-effect spawn (was whole asm in batch_w3883.s)
// Notes: frange(lo, hi) is the same inline as in 0x1c4520; func_001a7610 takes two floats (the v.w zero stays in $f13
// as its 5th argument). The height step is an if/else on func_001c4170() with the same statement in both arms:
// cross-jumping merges the arms and removes the branch (leaving the unused call), but in cse the join is a new
// block, so func_0016f000's 0.0f is a fresh constant.
namespace n001c4918 {
struct FVec {
    f32 x, y, z, w;
    FVec() {}
    FVec(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    FVec& operator=(const FVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

static inline FVec operator+(const FVec& a, const FVec& b) {
    FVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

struct FMtx {
    FVec r[4];
    FMtx() {}
    FMtx& operator=(const FMtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // inverse of a rigid transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));

static inline FVec operator*(const FMtx& m, const FVec& v) {
    FVec r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}

struct Wave { f32 a; f32 b; f32 c; f32 ang; };

extern Wave D_01d49590[8] asm("D_01d49590");
extern FMtx D_01d49610 asm("D_01d49610");
extern s32 D_01d49650 asm("D_01d49650");
extern FVec D_00352a60 asm("D_00352a60");
extern u32 D_003638d0 asm("D_003638d0");
s32 func_001c4160(void) asm("func_001c4160");
void func_001c42a0(void) asm("func_001c42a0");
s32 func_001c4170(void) asm("func_001c4170");
f32 func_002f8960(f32) asm("func_002f8960");
f32 func_002f87c0(f32) asm("func_002f87c0");
f32 func_0017ce10(f32) asm("func_0017ce10");
u8* func_00106a60(s32) asm("func_00106a60");
void YS__CROWDOBJ___OVR_exec(void*) asm("YS__CROWDOBJ___OVR_exec");
s32 func_00197920(void) asm("func_00197920");
s32 YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
s32 func_0016c6e8(s32) asm("func_0016c6e8");
s32 func_001a7610(FVec*, FVec*, s32, f32, f32) asm("func_001a7610");
s32 func_001a7588(FVec*, FVec*, FVec*, s32) asm("func_001a7588");
void* func_0016f000(s32, FVec*, f32) asm("func_0016f000");
void func_0016c018(void*, s32, s32) asm("func_0016c018");

static inline f32 sgnsq2(f32 x) { f32 r; if (0.0f < x) r = x * x; else r = -(x * x); return r; }
static inline f32 frange(f32 lo, f32 hi) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return lo + (f32)D_003638d0 * 2.3283064e-10f * (hi - lo);
}

void YS__CROWD_M_EX660___OVR_exec(void* obj) asm("YS__CROWD_M_EX660___OVR_exec");
void YS__CROWD_M_EX660___OVR_exec(void* obj) {
    if (func_001c4160()) func_001c42a0();
    for (s32 i = 0; i < 8; i++) { f32 s = func_002f8960(D_01d49590[i].ang); f32 b = func_002f8960(D_01d49590[i].ang) * 50.0f; f32 c = func_002f87c0(D_01d49590[i].ang); f32 amp = 100.0f; D_01d49590[i].a = sgnsq2(s) * amp; Wave* w = &D_01d49590[i]; w->b = b; w->c = sgnsq2(c) * amp; D_01d49590[i].ang = func_0017ce10(D_01d49590[i].ang + 0.10471976f); }
    u8* p = func_00106a60(1);
    D_01d49610 = *(FMtx*)(p ? p + 16 : 0);
    YS__CROWDOBJ___OVR_exec(obj);
    if (!func_00197920() && YS__OBJ__is_exist(obj)) {
        s32 n = func_001c4170();
        if (func_0016c6e8(1368) < n) {
            FVec v(frange(-500.0f, 500.0f), -1000.0f, frange(300.0f, 500.0f), 0.0f);
            FVec base, hit;
            FMtx m;
            m = D_01d49610;
            m.invOrtho();
            FVec at = m * v + D_00352a60;
            if (func_001a7610(&at, &v, 2, 2000.0f, 0.0f)) {
                base = D_00352a60;
                base.y -= 100.0f;
                if (func_001a7588(&base, &v, &hit, 2) < 0) {
                    if (func_001c4170() < 50) v.y += -1000.0f;
                    else v.y += -1000.0f;
                    void* o = func_0016f000(1368, &v, 0.0f);
                    if (o) {
                        func_0016c018(o, 1, D_01d49650);
                        if (func_001c4170() < 50) func_0016c018(o, 2, 500);
                        else if (func_001c4170() < 100) func_0016c018(o, 2, 1000);
                    }
                }
            }
        }
    }
}
}  // namespace n001c4918
