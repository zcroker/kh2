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

void func_002eaf38(void* p);
u8* func_002eaf40(void* p);

void wtarget_002eb460(u8* o, HV* q) asm("_Z16wtarget_002eb460jjjj");

static inline f32 deg2rad(f32 d) { return d * 3.14159265f / 180.0f; }
static f32 s_turn_small __attribute__((aligned(4))) = deg2rad(6.0f);   // 0x1e2c040
static f32 s_turn_big __attribute__((aligned(4))) = deg2rad(7.5f);     // 0x1e2c044
static f32 s_turn_rail __attribute__((aligned(4))) = deg2rad(7.5f);    // 0x1e2c048
struct FVec2ec5f8 {
    f32 x, y, z, w;
    FVec2ec5f8() {}
    ~FVec2ec5f8() {}
} __attribute__((aligned(16)));
static FVec2ec5f8 s_target asm("D_01e2c050");                       // 0x1e2c050, path target

// ---- 2ec5f8
// ---- 2ec5f8 (src/anon/batch_w2038.cpp)
namespace n2ec5f8 {
struct EVR { f32 x, y, z, w; } __attribute__((aligned(16)));
struct EV {
    f32 x, y, z, w;
    EV() {}
    EV& operator=(const EVR& o) {
        if ((void*)this != (void*)&o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    EV& operator=(const EV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    EV operator-(const EV& b) const {
        EV r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 lensq() const {
        f32 l;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(l) : "r"(this) : "$8", "memory");
        return l;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct EActor {
    u8 pad0[0x10];
    EV dir;
    u8 pad20[0x134];
    s32 x154;
    u8 pad158[0x3b0];
    s32 x508;
};
struct EObj;
struct EObjVt { void* f[8]; void (*f20)(EObj*, EActor*, s32); };
struct EObj { EObjVt* vt; };
s32 func_002eb3b8(EActor*) asm("func_002eb3b8");
EV* func_0016c028(EActor*) asm("func_0016c028");
EVR func_0016af58(EActor*) asm("func_0016af58");
EVR func_002cba88(s32, const EV&, const EVR&, f32, f32) asm("func_002cba88");
void e_set_dir(EActor*, const EV&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
void func_002eda90(f32, s32, s32) asm("func_002eda90");
u64 func_00313b80(f32) asm("func_00313b80") __attribute__((const));
s32 func_003142e0(u64, u64) asm("func_003142e0") __attribute__((const));
extern u8 D_01e2c064 asm("D_01e2c064");
extern f32 D_0036354c asm("D_0036354c");
extern s32 D_003637d0 asm("D_003637d0");
extern f32 D_00349e10 asm("D_00349e10");
extern EV D_01e2c050 asm("D_01e2c050");
extern "C" void func_002ec5f8(EObj* self, EActor* a) {
    EV t;
    s32 id = a->x508;
    if (func_002eb3b8(a)) return;
    t = *func_0016c028(a);
    f32 r = 24.0f;
    a->dir = func_002cba88(id, t, func_0016af58(a), r, 0.5f);
    a->dir.normalize();
    a->dir.w = r;
    e_set_dir(a, a->dir);
    if (D_01e2c064) {
        if (D_0036354c < 0.0f && a->x154 == 269) {
            func_002eda90(60.0f, D_003637d0, 1);
            D_0036354c = 12.0f;
        } else {
            D_0036354c -= D_00349e10;
        }
    }
    EV d = D_01e2c050 - *func_0016c028(a);
    t = d;
    t.y = 0.0f;
    if (func_003142e0(func_00313b80(t.lensq()), 0x40e3880000000000ULL) < 0)
        self->vt->f20(self, a, 0);
}
}


// ---- 2ec818
HV rail_2ec818(void* c, void* o) {
    return h_00184540(o, 0.0f, 0.0f);
}

// ---- 2ec850 (src/anon/batch_w1821.cpp)
namespace n2ec850 {
struct W1821Vec {
    f32 x, y, z, w;
    W1821Vec() {}
    W1821Vec(const W1821Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1821Vec& operator=(const W1821Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1821Obj { u8 pad[16]; W1821Vec p10; W1821Vec p20; u8 pad2[0xd0]; s32 w100; s32 w104; u8 pad3[0x40c]; s8 b514; };
static inline f32 w1821_norm(W1821Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
W1821Vec func_0017c030(W1821Obj*, s32*, u8) asm("func_0017c030");
void func_0017c4c8(W1821Obj*, W1821Vec) asm("func_0017c4c8");
void func_002eb778(W1821Obj*, u32, s32, f32) asm("func_002eb778");
extern "C" void func_002ec850(void* unused, W1821Obj* p, u8 c) {
    W1821Vec v = p->p20;
    s32 k;
    f32 len = w1821_norm(&v);
    v.w = len;
    if (p->p10.w < len) p->p10 = v;
    v = func_0017c030(p, &k, c);
    v.y = 385.0f;
    func_0017c4c8(p, v);
    p->b514 = 8;
    func_002eb778(p, 255, 1, 0.0f);
    p->w100 = 0x100;
    p->w104 = 0x101;
}
}

// ---- 2ec960
void wtarget_002ec960(u8* o) asm("_Z16wtarget_002ec960jjjj");
void wtarget_002ec960(u8* o) {
    void* path = *(void**)(o + 1288);
    h_reset_current_pointer(path, h_0016c028(o));
    HV t = h_002eaf48(o, 1);
    D_01e2c050 = t;
    h_change_action(o, 61);
}

// ---- 2ec9d0 (src/anon/batch_w42.cpp)
namespace n2ec9d0 {
void func_0017c4c8(void*, void*) asm("func_0017c4c8");
void func_002eb6f8(void*, s32, f32) asm("func_002eb6f8");
extern "C" void func_002ec9d0(u8* p, u128* v, s32 n)
{
    u128 tmp;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(v) : "$8", "memory");
    func_0017c4c8(p, &tmp);
    p[1300] = 8;
    func_002eb6f8(p, n, 0.0f);
    *(s32*)(p + 256) = n + 1;
    *(s32*)(p + 260) = n + 2;
}
}

// ---- 2eca38 (src/anon/batch_w43.cpp)
namespace n2eca38 {
struct V4 {
    u32 w[4];
} __attribute__((aligned(16)));
u32 func_0016c028(void*) asm("func_0016c028");
void func_002eb6f8(u32, s32, f32) asm("func_002eb6f8");
extern f32 D_01e2c060 asm("D_01e2c060");
extern V4 D_00363550 asm("D_00363550");
V4* func_0016c028_v(u32) asm("func_0016c028");
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
extern "C" void func_002eca38(u32, u32 b) {
    func_002eb6f8(b, 269, 0.0f);
    D_01e2c060 = 0.0f;
    V4* v = func_0016c028_v(b);
    if (v != &D_00363550) cpq(&D_00363550, v);
}
}

// ---- 2eca9c
void path_2ecaa0(void* c, u8* o) {}

extern "C" void func_002ecaa8(void* c, u8* o, HV* q) {
    wtarget_002eb460(o, q);
}

void path_2ecac8(void* c, u8* o) {
    h_002eb4b0(o);
}

void path_2ecae0(void* c, u8* o) {
    *(u32*)(o + 264) |= 0x4000000;
}

void path_2ecaf8(void* c, u8* o) {
    *(u32*)(o + 264) |= 0x8000000;
}

// ---- 2ecb10 (src/anon/batch_w58.cpp)
namespace n2ecb10 {
s32 func_002eb3b8(u32) asm("func_002eb3b8");
s32 func_002eb098(u32) asm("func_002eb098");
void func_002eb1a0(u32) asm("func_002eb1a0");
extern f32 D_01e2c060 asm("D_01e2c060");
extern f32 D_00349e10 asm("D_00349e10");
extern "C" void func_002ecb10(u32 a0, u32 a1) {
    if (func_002eb3b8(a1)) return;
    D_01e2c060 += D_00349e10;
    if (10.0f < D_01e2c060 || func_002eb098(a1)) func_002eb1a0(a1);
}
}

// ---- 2ecb90 (src/anon/batch_w1840_nsa.cpp)
namespace n2ecb90 {
struct W1840Vec {
    f32 x, y, z, w;
    W1840Vec() {}
    W1840Vec(const W1840Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1840Vec& operator=(const W1840Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1840Vec operator-(const W1840Vec& b) const {
        W1840Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1840Vec operator+(const W1840Vec& b) const {
        W1840Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1840Vec operator*(f32 s) const {
        W1840Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    W1840Vec& operator-=(const W1840Vec& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1840Path;
struct W1840PathOwner { u8 pad[1288]; W1840Path* path; };
W1840Vec w1840_get_current_pos(W1840Path*) asm("_ZN2Ti4Path15get_current_posEv");
extern f32 D_01e2c060 asm("D_01e2c060");
extern W1840Vec D_00363550 asm("D_00363550");
u64 func_00313b80(f32) asm("func_00313b80");
u64 func_00313f40(u64, u64) asm("func_00313f40");
f32 __truncdfsf2(u64) asm("__truncdfsf2");
f32 sinf(f32) asm("sinf");
W1840Vec* func_0016c028(W1840PathOwner*) asm("func_0016c028");
extern "C" W1840Vec* func_002ecb90(W1840Vec* r, void* self, W1840PathOwner* o) {
    f32 s = D_01e2c060 / 10.0f;
    s = sinf(__truncdfsf2(func_00313f40(func_00313b80(s * 3.14159274f), 0x3fe0000000000000ULL)));
    W1840Vec p;
    p = w1840_get_current_pos(o->path);
    *r = p - D_00363550;
    *r = D_00363550 + *r * s;
    *r -= *func_0016c028(o);
    return r;
}
}

// ---- 2eccc8
void path_2eccc8(void* c, u8* o) {}
