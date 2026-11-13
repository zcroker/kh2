#include "../../common/types.h"

// YS::PLAYER (0x177dc8-0x17a7e0): Sora as a party object: construction (C2/C1), control, commands,
// damage and the PLAYER vtable entries (retail data at 0x34e950), incl. the never-written entries
// 0x178e80, 0x178eb0, 0x179898, 0x17a1b8, 0x17a208 and 0x17a260. The static initialiser (the global
// player object at 0x1c5f530 with its member ctors/dtors) and the I/D stubs 0x17a7e0-0x17a8f8 stay
// outside. Each function keeps the declarations of the source it was matched in (namespace qN); every
// symbol is bound by asm label.


// 00177dc8 (src/anon/batch_wcx2.cpp)
namespace q_7dc8 {
extern u8 D_0034e958[] asm("D_0034e958");
extern u8 D_01c5f530[] asm("D_01c5f530");
extern u32 D_0034e948__48451 asm("D_0034e948");
void func_00175670(u8*, u32, s32, u32) asm("func_00175670");
s32 func_0016a070__48451(u8*) asm("func_0016a070");
u8* func_001a15d0(s32, s32) asm("func_001a15d0");
s32 func_001818a0(void) asm("func_001818a0");
u32 func_0016f6a0(u32, s32) asm("func_0016f6a0");
void func_00176168(u8*, u32, s32) asm("func_00176168");
void func_001781a8(u8*) asm("func_001781a8");
static inline bool HasSub7(s32 k)
{
    return k != 0 && k < 7;
}
void func_00177dc8(u8* p, u32 res, s32 kind, u32 a3, u32 t0) asm("func_00177dc8");
void func_00177dc8(u8* p, u32 res, s32 kind, u32 a3, u32 t0)
{
    func_00175670(p, res, 0, t0);
    *(u32*)(p + 2872) = a3;
    *(u32*)p = (u32)D_0034e958;
    *(s32*)(p + 2896) = kind;
    *(u32*)(p + 2884) = (u32)D_01c5f530;
    *(s32*)(p + 2892) = -1;
    *(u32*)(p + 2876) = (u32)D_01c5f530;
    *(u32*)(p + 2880) = (u32)(D_01c5f530 + 2752);
    *(u32*)(p + 2904) = 0xffff;
    *(u32*)(p + 1416) |= 0x80;
    *(u32*)(p + 2888) = 0;
    *(u32*)(p + 2900) = 0;
    *(u32*)(p + 2912) = 0;
    p[2916] = 0;
    D_0034e948__48451 = (u32)p;
    *(u32*)(p + 1896) |= 0x10;
    u8* o = func_001a15d0(func_0016a070__48451(p), *(s32*)(p + 2896));
    *(u32*)(p + 1164) = (u32)o;
    if (o) {
        *(u32*)(o + 604) = (u32)p;
        ((u8*)*(u32*)(p + 1164))[431] = 0;
        if (!func_001818a0()) {
            *(u32*)(*(u32*)(p + 1164) + 592) |= 2;
            *(u32*)(*(u32*)(p + 1164) + 592) |= 4;
        }
    }
    u32 x = func_0016f6a0(res, 0);
    if (x) func_00176168(p, x, 0);
    s32 k = *(s32*)(p + 2896);
    if (HasSub7(k) || k == 10) {
        x = func_0016f6a0(res, 1);
        if (x) func_00176168(p, x, 1);
    }
    func_001781a8(p);
}
}  // namespace q_7dc8

// 00177f50 (src/anon/batch_wcx2.cpp)
namespace q_7f50 {
extern u8 D_0034e958[] asm("D_0034e958");
extern u8 D_01c5f530[] asm("D_01c5f530");
extern u32 D_0034e948__48451 asm("D_0034e948");
void func_00175670(u8*, u32, s32, u32) asm("func_00175670");
s32 func_0016a070__48451(u8*) asm("func_0016a070");
u8* func_001a15d0(s32, s32) asm("func_001a15d0");
s32 func_001818a0(void) asm("func_001818a0");
u32 func_0016f6a0(u32, s32) asm("func_0016f6a0");
void func_00176168(u8*, u32, s32) asm("func_00176168");
void func_001781a8(u8*) asm("func_001781a8");
static inline bool HasSub7(s32 k)
{
    return k != 0 && k < 7;
}
void func_00177f50(u8* p, u32 res, s32 kind, u32 a3, u32 t0) asm("func_00177f50");
void func_00177f50(u8* p, u32 res, s32 kind, u32 a3, u32 t0)
{
    func_00175670(p, res, 0, t0);
    *(u32*)(p + 2872) = a3;
    *(u32*)p = (u32)D_0034e958;
    *(s32*)(p + 2896) = kind;
    *(u32*)(p + 2884) = (u32)D_01c5f530;
    *(s32*)(p + 2892) = -1;
    *(u32*)(p + 2876) = (u32)D_01c5f530;
    *(u32*)(p + 2880) = (u32)(D_01c5f530 + 2752);
    *(u32*)(p + 2904) = 0xffff;
    *(u32*)(p + 1416) |= 0x80;
    *(u32*)(p + 2888) = 0;
    *(u32*)(p + 2900) = 0;
    *(u32*)(p + 2912) = 0;
    p[2916] = 0;
    D_0034e948__48451 = (u32)p;
    *(u32*)(p + 1896) |= 0x10;
    u8* o = func_001a15d0(func_0016a070__48451(p), *(s32*)(p + 2896));
    *(u32*)(p + 1164) = (u32)o;
    if (o) {
        *(u32*)(o + 604) = (u32)p;
        ((u8*)*(u32*)(p + 1164))[431] = 0;
        if (!func_001818a0()) {
            *(u32*)(*(u32*)(p + 1164) + 592) |= 2;
            *(u32*)(*(u32*)(p + 1164) + 592) |= 4;
        }
    }
    u32 x = func_0016f6a0(res, 0);
    if (x) func_00176168(p, x, 0);
    s32 k = *(s32*)(p + 2896);
    if (HasSub7(k) || k == 10) {
        x = func_0016f6a0(res, 1);
        if (x) func_00176168(p, x, 1);
    }
    func_001781a8(p);
}
}  // namespace q_7f50

// 001780d8 (src/anon/tiny_auto80_solver.cpp)
namespace q2 {
u32 func_001758b0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001758b0");
u32 func_001780d8(u32) asm("func_001780d8");
u32 func_0017a718(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0017a718");

u32 func_001780d8(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))func_001758b0)(a0);
    return ((u32(*)(u32))func_0017a718)(s0);
}
}  // namespace q2

// 00178100 (src/anon/batch_w66.cpp)
namespace q3 {
extern s32 D_0034ece8 asm("D_0034ece8");
u32 func_00194898(void) asm("func_00194898");
void func_00140d38(u32, s32) asm("func_00140d38");
void func_001586b8(void) asm("func_001586b8");
void func_00159700(void) asm("func_00159700");

void func_00178100(u32 a) {
    switch (D_0034ece8) {
    case 0: func_00140d38(a, func_00194898() != 0); break;
    case 1: func_00140d38(a, 0); func_00159700(); break;
    case 2: func_00140d38(a, 2); break;
    case 3: func_00140d38(a, 0); func_001586b8(); break;
    }
}
}  // namespace q3

// 001781a8 (src/anon/tiny_auto80_solver.cpp)
namespace q4 {
u32 func_00178100(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00178100");
u32 func_001781a8(u32) asm("func_001781a8");
u32 func_00182f28(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00182f28");  // store_global_35ed04
u32 func_001d6938(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d6938");
extern u8 D_01c5f530 asm("D_01c5f530");

u32 func_001781a8(u32 a0) {
    u32 s0 = a0;
    ((u32(*)(u32))func_00178100)(a0);
    ((u32(*)(u32))func_00182f28)(s0);
    u32 tex = (u32)&D_01c5f530;
    *(u32*)(s0 + 2876) = tex;
    return ((u32(*)(u32, u32))func_001d6938)(tex, s0);
}
}  // namespace q4

// 001781e8 (src/anon/batch_w14.cpp)
namespace q5 {
void func_0014d358(void*, s32, void (*)(void), s32) asm("func_0014d358");
void func_00140db0(void*) asm("func_00140db0");
void func_00182f28(s32) asm("func_00182f28");  // store_global_35ed04
void func_001d69d0(void*) asm("func_001d69d0");
void* func_00102c18(s32, s32, void (*)(void)) asm("func_00102c18");

void func_001781e8(u8* p) {
    func_00140db0(p);
    func_00182f28(0);  // store_global_35ed04
    func_001d69d0(*(void**)(p + 2876));
    *(void**)(p + 2876) = 0;
}
}  // namespace q5

// 00178220 (src/anon/batch_w48.cpp)
namespace q6 {
struct S10 { u8 a; u8 b; s16 c[4]; };
extern S10 D_0032bae0 asm("D_0032bae0");
extern S10 D_0032bb10 asm("D_0032bb10");
void func_0019ee80(s32, s32) asm("func_0019ee80");
void func_001d5198(S10*) asm("func_001d5198");

void func_00178220(void) {
    func_0019ee80(D_0032bae0.a, D_0032bae0.b);
    D_0032bb10 = D_0032bae0;
    func_001d5198(&D_0032bae0);
}
}  // namespace q6

// 00178280 (src/anon/batch_w32.cpp)
namespace q7 {
void func_001781e8(void*) asm("func_001781e8");
void func_001dc920(void*) asm("func_001dc920");
void func_00175928(void*) asm("func_00175928");
extern void* D_0034e948 asm("D_0034e948");

void wtarget_00178280(void*, u32, u32, u32) asm("_Z16wtarget_00178280jjjj");
void wtarget_00178280(void* a0, u32, u32, u32) {
    u8* p = (u8*)a0;
    *(u32*)&D_0034e948 = 0;
    func_001781e8(p);
    void* e = *(void**)(p + 0xb60);
    if (e) {
        func_001dc920(e);
        *(void**)(p + 0xb60) = 0;
    }
    func_00175928(p);
}
}  // namespace q7

// 001782c8 (src/anon/auto80_199_queue.cpp)
namespace q8 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
void func_001785b8(u32) asm("func_001785b8");
void func_00178570(u32) asm("func_00178570");
void func_001786e0(u32) asm("func_001786e0");
void func_001784a8(u32) asm("func_001784a8");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_001782c8(u32 a0) {
    u32 t6 = *(u32*)(a0 + 12);
    u32 t7 = *(u32*)(t6 + 8);

    if ((t7 & 8) != 0) {
        return func_001785b8(a0);
    }

    t6 = *(u32*)(t6 + 4);
    if ((t6 ^ 0x2) == 0) {
        return func_00178570(a0);
    }

    u32 t5 = t6 ^ 0x18;
    if (t5 == 0) {
        return func_001786e0(a0);
    }

    if ((t6 ^ 0x35) == 0) {
        return func_001786e0(a0);
    }

    return func_001784a8(a0);
}
}  // namespace q8

// 00178330 (src/anon/batch_w3679.cpp)
namespace q9 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Mtx {
    QWord r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    void transpose() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tlq $11, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tpcpyud $11, $13, $15\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    QWord operator*(const QWord& v) const {
        QWord o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct CamBase { u8 pad[16]; };
struct Cam : CamBase, Mtx {};
Cam* func_00106a60(s32) asm("func_00106a60");

QWord* ctarget_00178330(QWord* out, const QWord* in) asm("_Z16ctarget_00178330jjjj");
QWord* ctarget_00178330(QWord* out, const QWord* in) {
    if (in->f[3] > 0.0f) {
        Mtx m;
        QWord v;
        v.f[0] = in->f[0];
        v.f[1] = 0.0f;
        v.f[2] = -in->f[1];
        v.f[3] = 0.0f;
        Cam* c = func_00106a60(1);
        // Partial asm (no instructions): the original saves s2 without using it (a pseudo dropped after
        // reload); an empty asm writing $18 reproduces the save.
        { register u32 r18 asm("$18"); asm volatile("" : "=r"(r18)); }
        m = *static_cast<Mtx*>(c);
        m.transpose();
        *out = m * v;
        out->f[1] = 0.0f;
        Normalize(out);
        out->f[3] = in->f[3];
    } else {
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return out;
}
}  // namespace q9

// 001784a8 (src/anon/batch_w2375.cpp)
namespace q10 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V4_784 {
    f32 x, y, z, w;
    V4_784& operator=(const V4_784& o) { if (this != &o) QCOPY(this, &o); return *this; }
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct Tgt_784 { u8 pad[0xa30]; V4_784 pos; };
struct Ob_784 {
    u8 pad[0x10]; V4_784 dir; u8 p2[0x110 - 0x20]; f32 f110, f114;
    u8 p3[0x66c - 0x118]; f32 angle; u8 p4[0xb44 - 0x670]; Tgt_784* target;
};
V4_784 func_00178330(V4_784*) asm("_Z16ctarget_00178330jjjj");
f32 sinf(f32) asm("sinf");  // sinf
f32 cosf(f32) asm("cosf");  // cosf

/* 001784a8: aim direction toward the target if it has one (w > 0), else from the facing angle.
   The inline V4::set in the else branch leaves its `this` copy's save slot (unused s1) behind. */
void func_001784a8(Ob_784* o) {
    if (o->target->pos.w > 0.0f) {
        o->dir = func_00178330(&o->target->pos);
        o->dir.w = (o->dir.w < 0.8f) ? o->f110 : o->f114;
    } else {
        o->dir.set(sinf(o->angle), 0.0f, cosf(o->angle), 0.0f);
    }
}
}  // namespace q10

// 00178570 (src/anon/batch_w210.cpp)
namespace q11 {
void func_001ad990(void* a, f32 b, f32 c, f32 d) asm("_Z13func_001ad990jfff");
u32 u_tail4_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
u32 CopyMessage(u32, u32) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");

void func_00178570(char* a) {
    // VU0: zero vector store
    asm volatile("vsub.xyzw $vf1,$vf0,$vf0\n sqc2 $vf1,0(%0)" :: "r"(a + 16) : "memory");
    char* t = *(char**)(a + 0xb44);
    if (0.0f < *(f32*)(t + 0xa3c) && *(f32*)(t + 0xa34) < 0.0f) *(f32*)(a + 0x14) = -1.0f;
}
}  // namespace q11

// 001785b8 (src/anon/batch_w259.cpp)
namespace q12 {
struct __attribute__((aligned(16))) W259V4 {
    f32 x, y, z, w;
    W259V4& operator=(const W259V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline void w259_vscale(W259V4* d, const W259V4* a, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
static inline f32 w259_vnorm(W259V4* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void w259_vzero(W259V4* d) {
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(d) : "memory");
}
struct P178 { u64 fl; u8 pad[48 - 8]; u8 m48[12]; f32 f60; };
struct O178 { u8 pad[16]; W259V4 v; u8 p1[272 - 32]; f32 f272; f32 f276; u8 p2[292 - 280]; f32 f292; u8 p3[2872 - 296]; P178* f2872; };
W259V4 func_00178330(void*) asm("func_00178330");

void func_001785b8(O178* o) {
    w259_vzero(&o->v);
    if (0.0f < o->f2872->f60) {
        o->v = func_00178330(o->f2872->m48);
        f32 k = (o->f2872->f60 < 0.8f) ? o->f272 : o->f276;
        w259_vscale(&o->v, &o->v, k);
    }
    u64 fl = o->f2872->fl;
    if (!(fl & (1ull << 32))) {
        if (fl & 0x20000000) o->v.y = -o->f292;
        else if (fl & 0x40000000) o->v.y = o->f292;
    }
    o->v.w = w259_vnorm(&o->v);
}
}  // namespace q12

// 001786e0 (src/anon/batch_w41.cpp)
namespace q13 {
typedef unsigned int u128  asm("u128")__attribute__((mode(TI)));
struct Vec16 { f32 x, y, z, w; } __attribute__((aligned(16)));
void operator delete(void*) asm("func_001e0158");
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block
struct W41VObj2 { void** vt; };
extern W41VObj2* D_00361f60_obj asm("D_00361f60");
extern u32 D_00361f60 asm("D_00361f60");
u32 func_002cebb0(void) asm("func_002cebb0");  // get_global_361f60

void func_001786e0(u8* p) {
    Vec16 t;
    u8* d = p + 16;
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(d) : "memory");
    if (func_002cebb0()) {  // get_global_361f60
        W41VObj2* o = D_00361f60_obj;
        ((void (*)(Vec16*, W41VObj2*, u32))o->vt[9])(&t, o, *(u32*)(p + 0xb38) + 48);
        if (d != (u8*)&t)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&t) : "$8", "memory");
    }
}
}  // namespace q13

// 00178758 (src/anon/batch_wcx2.cpp)
namespace q_8758 {
u8* func_00177860(u8*) asm("_ZN2YS5PARTY11get_abilityEv");
extern f32 D_00349e10 asm("D_00349e10");
extern u8* D_00352130 asm("D_00352130");
void func_00175af8(u8*) asm("func_00175af8");
void func_00179718(u8*) asm("func_00179718");
s32 func_00197920(void) asm("func_00197920");
s32 func_001917c0(void) asm("func_001917c0");
void func_001a1b68(u8*, f32) asm("func_001a1b68");
void func_00179cb8(u8*) asm("func_00179cb8");
s32 func_001b9d40(u8*) asm("func_001b9d40");  // vtable_call_slot64_flags
void func_00178220(u8*) asm("func_00178220");
void func_0017a3b0(u8*) asm("func_0017a3b0");
void func_00178758(u8* p) asm("func_00178758");
void func_00178758(u8* p)
{
    func_00175af8(p);
    func_00179718(p);
    if ((*(s32 (**)(u8*))(*(u8**)p + 64))(p) && *(u8**)(p + 1164) && !func_00197920()
        && (u32)((*(u8**)(p + 1164))[431] - 2) < 2) {
        f32 s = D_00349e10;
        if (!func_001917c0()) s *= *(f32*)(D_00352130 + 108);
        switch ((*(u8**)(p + 1164))[431]) {
        case 2:
            s *= *(f32*)(func_00177860(p) + 64);
            break;
        case 3:
            s *= *(f32*)(func_00177860(p) + 108);
            break;
        }
        func_001a1b68(*(u8**)(p + 1164), -s);
    }
    func_00179cb8(p);
    if (func_001b9d40(p)) {  // vtable_call_slot64_flags
        if (!(*(u32*)(p + 2040) & 0x20)) {
            func_00178220(p);
            *(u32*)(p + 2040) |= 0x20;
        }
        *(u32*)(p + 2888) = 0;
    }
    func_0017a3b0(p);
}
}  // namespace q_8758

// 00178888 (src/anon/tiny_auto80_queue.cpp)
namespace q15 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_001d6ba0(...) asm("func_001d6ba0");

void func_00178888(u32 a0) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(2876));
    if (t7 != 0u) {
        func_001d6ba0(t7);
    }
}
}  // namespace q15

// 001788b8 (src/anon/batch_w1815_nsa.cpp)
namespace q16 {
void wtarget_0018cf18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_0018cf18jjjj");
struct B178 { u16 id; u16 pad; u32 flags; };
struct D178 { u32 a; B178 b; };
struct O178 {
    void** vt; u8 p4[0xc]; u8 v10[16]; u8 p20[0x10c - 0x20]; u32 f10c; u8 p110[0x160 - 0x110]; u32 f160;
    u8 p164[0x7f8 - 0x164]; u32 f7f8; u8 p7fc[0xb44 - 0x7fc]; D178* b44; u32 b48;
};
void func_00179dd0(O178*, u16) asm("func_00179dd0");
void func_001991a8(s32, u16) asm("func_001991a8");
void* func_00175c88(O178*, B178*) asm("func_00175c88");
void func_001bbcf8(void*) asm("func_001bbcf8");
void func_0017a2d0(O178*) asm("func_0017a2d0");
void func_001774e0(O178*) asm("func_001774e0");
static inline __attribute__((always_inline)) u32 tA(u32 x) { return x & 4; }
static inline __attribute__((always_inline)) u32 tB(u32 x) { return x & 8; }
static inline __attribute__((always_inline)) u32 tC(u32 x) { return x & 0x10; }
static inline __attribute__((always_inline)) bool busyC(u32 x) { return tA(x) || tB(x) || tC(x); }

// VU0 asm: zero a 128-bit vector (vsub + sqc2), no C equivalent.
void func_001788b8(O178* o) {
    if (!(o->f7f8 & 4)) {
        ((void (*)(O178*))o->vt[0x90 / 4])(o);
        D178* p = o->b44;
        if (p->b.id) {
            o->b48 = 0;
            if (p->b.flags & 0x10) func_00179dd0(o, p->b.id);
            func_001991a8(31, o->b44->b.id);
        }
        void* r = func_00175c88(o, o->b44 ? &o->b44->b : 0);
        if (r) {
            o->f10c &= ~2;
            func_001bbcf8(r);
        }
        u32 x = o->f160;
        bool b = busyC(x);
        if (!b && (s32)x >= 0) {
            asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" :: "r"(o->v10) : "memory");
        }
        func_0017a2d0(o);
    }
    func_001774e0(o);
}
}  // namespace q16

// 001789b8 (src/anon/batch_w63.cpp)
namespace q17 {
typedef void (*VFn)(void*);
s32 func_00141080(u32) asm("func_00141080");
s32 func_001b9d40(u32) asm("func_001b9d40");  // vtable_call_slot64_flags
void func_001835a0(u32, f32) asm("func_001835a0");
void func_00175b68(u32) asm("func_00175b68");
extern f32 D_00349e10 asm("D_00349e10");
typedef void (*VFn3)(void*, void*, void*);

void wtarget_001789b8(u32, u32, u32, u32) asm("_Z16wtarget_001789b8jjjj");
void wtarget_001789b8(u32 a0, u32, u32, u32) {
    if (func_00141080(a0) && func_001b9d40(a0)) {
        u64 fl = **(u64**)(a0 + 2872);
        if (fl & 0x100000) func_001835a0(a0, D_00349e10 * -0.052359879f);
        else if (fl & 0x200000) func_001835a0(a0, D_00349e10 * 0.052359879f);
    }
    func_00175b68(a0);
}
}  // namespace q17

// 00178a50 (src/anon/batch_w64.cpp)
namespace q18 {
typedef void (*VFn)(void*);
typedef s32 (*IFn)(void*);
s32 func_00190140(u8*) asm("func_00190140");
void func_00159130(u8*) asm("func_00159130");

void func_00178a50(u8* p, u8* q) {
    if (!func_00190140(*(u8**)(p + 2884) + 12)) return;
    switch (q[29]) {
    case 1:
        func_00159130(*(u8**)(p + 2884) + 12);
        break;
    case 3:
        if (*(u8**)(p + 2880) && func_00190140(*(u8**)(p + 2880) + 4))
            func_00159130(*(u8**)(p + 2880) + 4);
        break;
    }
}
}  // namespace q18

// 00178ae8 (src/anon/batch_w1819.cpp)
namespace q19 {
struct S2 { u16 a; u16 id; };
struct B { u8 pad[6]; u16 h; u8 pad2[4]; s32 v; };
struct A { u8 pad[0xb44]; B* b; };
void func_00178bf0(A*, S2*) asm("func_00178bf0");
void func_00178cf8(A*) asm("func_00178cf8");
void func_00179648(A*, s32) asm("func_00179648");
void func_001991a8(u32, s32) asm("func_001991a8");
void func_001a6e88(s32, A*, void*) asm("func_001a6e88");
void func_001a70a0(s32, A*, void*) asm("func_001a70a0");
void func_001a8778(s32, A*) asm("func_001a8778");

void func_00178ae8(A* a, S2* m) {
    switch (m->id) {
    case 0x1f:
        func_00178cf8(a);
        func_001a70a0(a->b->v + 0x500, a, &a->b->v);
        return;
    case 0x1e:
        func_00178cf8(a);
        func_001a6e88(a->b->v + 0x500, a, &a->b->v);
        return;
    case 0x7f:
        func_001991a8(a->b->h, 0);
        return;
    case 0x37:
        func_00179648(a, a->b->v);
        return;
    case 0x20:
        func_001a8778(a->b->v, a);
        return;
    default:
        func_00178bf0(a, m);
        return;
    }
}
}  // namespace q19

// 00178bf0 (src/anon/batch_w82.cpp)
namespace q20 {
extern u8 D_0032e020[] asm("D_0032e020");
struct V82z { f32 v[4]; } __attribute__((aligned(16)));
static inline void VZero82(void* p) { asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory"); }
s32 func_00181a70(u8*) asm("func_00181a70");
void func_00189228(u8*, u16) asm("func_00189228");
s32 func_001ba028(u32) asm("func_001ba028");  // list_contains_ptr
void func_00177a28(u8*) asm("func_00177a28");  // set_bytes_2820_2821
void func_0016bae8(u32, u8*, u16, u8*) asm("func_0016bae8");
void func_0016bd60(u8*, s32) asm("func_0016bd60");

void func_00178bf0(u8* a0, u8* a1)
{
    u8* t;
    if (*(u16*)(a1 + 38) && func_00181a70(a0))
        func_00189228(D_0032e020, *(u16*)(a1 + 38));
    if (!func_001ba028(*(u32*)(*(u8**)(a0 + 2884) + 12))) return;
    func_00177a28(a0);  // set_bytes_2820_2821
    switch (a1[37]) {
    case 0:
        break;
    case 1:
        if (*(u32*)(*(u8**)(a0 + 12) + 4)) func_0016bd60(a0, 0);
        VZero82(a0 + 2768);
        break;
    case 2: {
        V82z tmp;
        VZero82(a0 + 32);
        VZero82(&tmp);
        {
            u8* o = *(u8**)(a0 + 12);
            (*(void (**)(u8*, u8*, V82z*))(*(u8**)o + 8))(o, a0, &tmp);
        }
        VZero82(a0 + 2768);
        break;
    }
    }
    t = *(u8**)(a0 + 2884);
    func_0016bae8(*(u32*)(t + 12), a0, *(u16*)(t + 4), t + 12);
}
}  // namespace q20

// 00178cf8 (src/anon/batch_w6.cpp)
namespace q21 {
void ys_area_read(void* task) asm("_ZN2YS8AreaReadEP4TASK");
void ys_prepare_scene(void) asm("_ZN2YS5EVENT12PrepareSceneEv");
u32 ys_is_mark_history(void) asm("_ZN2YS8FIELDOBJ15is_mark_historyEv");
u32 ys_can_end(void) asm("_ZN2YS9SACRIFICE6CanEndEv");
void func_00170888(void*) asm("func_00170888");
void func_001badd8(void) asm("func_001badd8");
void func_001afaf0(void*) asm("func_001afaf0");

// Zero three VU0 vectors.
void func_00178cf8(u8* p) {  // clear_vecs_three
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 32) : "memory");
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(*(u8**)(p + 0xb44) + 0xa30) : "memory");
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(p + 16) : "memory");
}
}  // namespace q21

// 00178d28 (src/anon/batch_w98.cpp)
namespace q22 {
struct Tmp178 { u8 pad[112]; };
u8* func_00176fb0(u8*, s32) asm("func_00176fb0");
s32 func_001a0920(u8*, u8*) asm("func_001a0920");
void func_001cda88(Tmp178*, u8*, u32) asm("func_001cda88");
u8* func_001cde58(Tmp178*) asm("func_001cde58");
void func_00177008(u8*, u8*, u32) asm("func_00177008");
void func_0017f488(u8*, u16, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_001bbd58(u8*) asm("func_001bbd58");
void func_00178e80(void) asm("func_00178e80");
extern u8* D_00351068 asm("D_00351068");

// Picks or builds the effect entry for this object, then applies it.
void func_00178d28(u8* p) {
    u8* m = p + 320;
    u8* e = 0;
    if (*(s32*)(m + 20) == 42) {
        e = func_00176fb0(p, 39);
        if (e && !func_001a0920(e, p)) e = 0;
    }
    u32 k = *(u32*)(*(u8**)(p + 12) + 4);
    if ((k ^ 0x16) == 0 || (k ^ 0x1a) == 0) {
        e = func_00176fb0(p, 41);
        if (e && !func_001a0920(e, p)) e = 0;
    }
    if (!e) {
        Tmp178 t;
        func_001cda88(&t, p, *(u32*)(p + 2880) + 4);
        e = func_001cde58(&t);
    }
    func_00177008(p, e, *(u32*)(p + 2880) + 4);
    if (*(u32*)(*(u8**)(p + 12) + 8) & 0x20) {
        u16 id = *(u16*)(e + 8);
        if (id > 210) {
        func_0017f488(D_00351068 + 320, id, 0.0f, 0.0f);
        func_0017f5e0(D_00351068 + 320, 0, 0, 0.0f, 0.0f);
        *(void**)(m + 404) = (void*)func_00178e80;
        }
    }
    func_001bbd58(e);
}
}  // namespace q22

// 00178e80 .. 00178eb0 (never written before; PLAYER vtable entries)
namespace q_8e80 {
extern u8* D_00351068 asm("D_00351068");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
s32 func_00177a28(u8*) asm("func_00177a28");
s32 func_00179450(u8*) asm("func_00179450");
s32 func_00179308(u8*) asm("func_00179308");
s32 func_00178fe8(u8*, s32) asm("func_00178fe8");
s32 func_001790c0(u8*) asm("func_001790c0");
s32 func_00179530(u8*) asm("func_00179530");
s32 func_00179148(u8*) asm("func_00179148");

static inline bool BitTest(u32 v, u32 m) { return (v & m) != 0; }

static inline bool Moving(u8* o) { u32 fl = *(u32*)(o + 352); return BitTest(fl, 4) || BitTest(fl, 8) || BitTest(fl, 0x10); }
// 00178e80: reset the player's motion
void func_00178e80(void) asm("func_00178e80");
void func_00178e80(void) {
    func_0017f488(D_00351068 + 320, 0, 0.0f, 0.0f);
}

// 00178eb0: the player's command decision chain
s32 func_00178eb0(u8* o) asm("func_00178eb0");
s32 func_00178eb0(u8* o) {
    if (*(u32*)(*(u8**)(o + 12) + 8) & 0x800) return 0;
    if (Moving(o)) func_00177a28(o);
    s32 r = 0;
    if (func_00179450(o) || func_00179308(o) || func_00178fe8(o, 37) || func_00178fe8(o, 12) ||
        func_00178fe8(o, 38) || (*(f32*)(o + 28) == 0.0f && func_001790c0(o)) || func_00179530(o) ||
        func_00179148(o) || func_001790c0(o))
        r = 1;
    return r;
}
}  // namespace q_8e80

// 00178fe8 (src/anon/batch_w1800.cpp)
namespace q23 {
struct Cc30Obj { u8 pad[0x104]; s32 action; u32 flags108; u8 pad2[0x140 - 0x10c]; u8 mot[0x28]; u32 flags168; };
struct Fe8Atk { u32 x0; u32 b0 : 1; u32 b1 : 1; u32 combo : 1; bool isCombo() { return combo; } };
struct Fe8Party { u8 pad[0x108]; u32 f108; u8 pad2[0x160 - 0x10c]; u32 f160; u32 pad3; u32 f168; u8 pad4[0xb40 - 0x16c]; s32 fb40; bool chk108(u32 m) { return (f108 & m) != 0; } u32 get108(u32 m) { return f108 & m; } };
/* 0017cc30 */
void func_00180c88(u8*, s32, f32) asm("func_00180c88");
void cc30_17f488(u8*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void cc30_push(u8*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
s32 cc30_is_exist(u8*, s32) asm("_ZN2YS6MOTION8is_existEi");
void cc30_change_action(Cc30Obj*, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void wtarget_0017cc30(u32, Cc30Obj*, u32, u32) asm("_Z16wtarget_0017cc30jjjj");
void wtarget_0017cc30(u32 a0, Cc30Obj* o, u32 act, u32 a3) asm("func_0017cc30");
/* 001cb0a8 */
void* b0a8_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
/* 00178fe8 */
Fe8Atk* fe8_get_partyattack(Fe8Party*, s32) asm("_ZN2YS5PARTY15get_partyattackEi");
bool fe8_is_combo_finish(Fe8Party*, s32) asm("_ZN2YS5PARTY15is_combo_finishEi");
bool func_001a0920(Fe8Atk*, Fe8Party*) asm("func_001a0920");
bool func_00177ab8(Fe8Party*, bool) asm("func_00177ab8");
void func_00177008(Fe8Party*, Fe8Atk*, s32) asm("func_00177008");

bool func_00178fe8(Fe8Party* self, s32 i) {
    Fe8Atk* a = fe8_get_partyattack(self, i);
    if (a) {
        if (func_001a0920(a, self)) {
            if (a->isCombo() || !fe8_is_combo_finish(self, 0)) {
                if ((self->f160 & 0x400) || (self->f168 & 0x20)) {
                    if (func_00177ab8(self, self->chk108(0x2000000))) {
                        func_00177008(self, a, self->fb40 + 4);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}
}  // namespace q23

// 001790c0 (src/anon/batch_w61.cpp)
namespace q24 {
union HP;
u8* wtarget_00133980(HP*, u32, u32, u32, u32) asm("_Z16wtarget_00133980jjjj");
u32 ctarget_00188fe0(u32, u32, u32, u32) asm("_Z16ctarget_00188fe0jjjj");
void wtarget_002eccd0(u32, u32, u32, u32) asm("_Z16wtarget_002eccd0jjjj");
u8* func_00176fb0(u8*, u32) asm("func_00176fb0");
s32 func_001a0920(u8*, u8*) asm("func_001a0920");
s32 func_001b9d40(u8*) asm("func_001b9d40");  // vtable_call_slot64_flags
void func_00177008(u8*, u8*, u32) asm("func_00177008");

s32 func_001790c0(u8* a0) {
    u8* v = func_00176fb0(a0, 11);
    if (v && func_001a0920(v, a0) && func_001b9d40(a0)) {
        func_00177008(a0, v, *(u32*)(a0 + 2880) + 4);
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(a0 + 16) : "memory");
        return 1;
    }
    return 0;
}
}  // namespace q24

// 00179148 (src/anon/batch_w1775.cpp)
namespace q25 {
struct W1775Ctl { u8 pad[8]; u32 flags; };
struct W1775Obj { u8 pad0[0xc]; W1775Ctl* ctl; u8 pad10[0x160 - 0x10]; u32 flags160; };
s32 func_0019c090(W1775Obj*) asm("func_0019c090");
s32 func_001b9d40(W1775Obj*) asm("func_001b9d40");
u8 func_001791e8(W1775Obj*, void*) asm("func_001791e8");
static inline bool W1775_CtlBusy(W1775Obj* o) { return (o->ctl->flags & 2) || (o->flags160 & 0x40); }
static inline bool W1775_CanAct(W1775Obj* o) { bool r = false; if (func_0019c090(o) || W1775_CtlBusy(o)) r = true; return !r; }

s32 func_00179148(W1775Obj* o) {
    if (W1775_CanAct(o)) {
        if (func_001b9d40(o)) return func_001791e8(o, (u8*)o + 0x10);
        return 0;
    }
    return 0;
}
}  // namespace q25

// 001791e8 (src/anon/batch_w99.cpp)
namespace q26 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V1791 {
    f32 x, y, z, w;
    V1791& operator=(const V1791& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

static inline V1791 operator*(const V1791& v, f32 s)
{
    V1791 r;
    asm("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}

union W1791 { f32 f; u32 u; };
struct D1791 { u8 pad[12]; f32 f12; f32 scale; f32 f20; f32 f24; f32 f28; };
u32 func_00177860(u8*) asm("func_00177860");
s32 func_001c3618(u32, s32) asm("func_001c3618");
D1791* func_001ce300(s32) asm("func_001ce300");  // to_1ce2a0_index_minus1
void func_0016aef0(u8*, V1791*) asm("func_0016aef0");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_00176a60(u8*, f32) asm("func_00176a60");

s32 func_001791e8(u8* o, V1791* v) asm("func_001791e8");
s32 func_001791e8(u8* o, V1791* v)
{
    s32 n = func_001c3618(func_00177860(o), 1);
    if (n > 0) {
    D1791* d = func_001ce300(n);  // to_1ce2a0_index_minus1
    *(V1791*)(o + 32) = *v * d->scale;
    *(f32*)(o + 240) = d->f20;
    *(f32*)(o + 244) = d->f12;
    *(f32*)(o + 248) = d->f24;
    func_0016aef0(o, v);
    func_0017f488(o + 320, 203, 0.0f, 0.0f);
    if (n >= 2) func_0016ac38(o, n + 108, 1, 0, 0);
    func_0016bd60(o, 16);
    ((W1791*)(o + 268))->u |= 4;
    func_00176a60(o, d->f28);
    return 1;
    }
    return 0;
}

}  // namespace q26

// 00179308 (src/anon/batch_w94.cpp)
namespace q27 {
u32 func_00177860(u8*) asm("func_00177860");
s32 func_001c3618(u32, s32) asm("func_001c3618");
s32 func_0019c090(u8*) asm("func_0019c090");  // obj_is_enabled
s32 func_001b9d40(u8*) asm("func_001b9d40");  // vtable_call_slot64_flags
u8* func_001ce300(s32) asm("func_001ce300");  // to_1ce2a0_index_minus1
f32 func_00184a90(u8*) asm("func_00184a90");
u8* func_0016c028(u8*) asm("func_0016c028");  // obj_get_attach_or_alt
void func_0016bd60(u8*, s32) asm("func_0016bd60");
static inline u8 busy(u8* p) {
    u8 r = 0;
    if ((*(u32*)(*(u8**)(p + 12) + 8) & 2) || (*(u32*)(p + 352) & 0x40)) r = 1;
    return r;
}

s32 func_00179308(u8* p) {
    s32 r = func_001c3618(func_00177860(p), 3);
    if (r > 0 && !busy(p) && func_0019c090(p) && func_001b9d40(p)) {  // obj_is_enabled
        u8* e = func_001ce300(r);  // to_1ce2a0_index_minus1
        f32 d = func_00184a90(p) - *(f32*)(func_0016c028(p) + 4) > 0.0f
                    ? func_00184a90(p) - *(f32*)(func_0016c028(p) + 4) : 0.0f;
        if (*(f32*)(e + 52) < d) {
            *(u8**)(p + 240) = e;
            if (*(f32*)(p + 28) == 0.0f) func_0016bd60(p, 17);
            else func_0016bd60(p, 18);
            *(u32*)(p + 268) |= 4;
            return 1;
        }
    }
    return 0;
}
}  // namespace q27

// 00179450 (src/anon/batch_w80.cpp)
namespace q28 {
struct U0_Sub { u32 f0; u32 f4; u32 f8; };
struct U0_Act { u8 pad[12]; U0_Sub* sub; u8 pad2[12]; f32 f28; u8 pad3[352 - 32]; u32 f352; u8 pad4[2896 - 356]; s32 state; };
struct U0_Mot { u8 pad[20]; u32 f20; };
struct HasF4 { u32 f0; f32 f4; };
struct U11_CurObj { u8 pad[24]; u8 sub[184]; u32 f208; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
struct U21_DObj;
struct U21_DObjVt { void (*dtor)(U21_DObj*); };
struct U21_DObj { U21_DObjVt* vt; u8 pad[340]; };
#define U21_W80_DTOR_ARR(base, off, n) \
    if ((u32)(base) != (u32)-(off)) { \
        U21_DObj* e_ = (U21_DObj*)((base) + (off)) + (n); \
        U21_DObj* b_ = (U21_DObj*)((base) + (off)); \
        for (;;) { \
            if (b_ == e_) break; \
            e_--; \
            e_->vt->dtor(e_); \
        } \
    }
struct U23_W80Vec {
    f32 x, y, z, w;
    U23_W80Vec() {}
    U23_W80Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    U23_W80Vec operator-(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec operator+(const U23_W80Vec& b) const {
        U23_W80Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    U23_W80Vec& operator=(const U23_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Vec {
    f32 x, y, z, w;
    U24_W80Vec& operator=(const U24_W80Vec& v) {
        if (this != &v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&v) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct U24_W80Param { u32 a, b, c, d, e; };
struct U24_W80Eff { u8 pad[64]; U24_W80Vec pos; u8 pad2[100 - 80]; U24_W80Param prm; };
struct U24_W80Own { u8 pad[2548]; u8* heap; };
s32 func_0019c090(U0_Act*) asm("func_0019c090");  // obj_is_enabled
s32 func_001b9d40(U0_Act*) asm("func_001b9d40");  // vtable_call_slot64_flags
U0_Mot* func_00177860(U0_Act*) asm("func_00177860");
void func_0016bd60(U0_Act*, u32) asm("func_0016bd60");
HasF4* func_0016c028(void*) asm("func_0016c028");  // obj_get_attach_or_alt
void func_00102818(u32, u32, u32, void (*)(void), u32) asm("func_00102818");
U23_W80Vec* w80_pos_vec(void*) asm("func_0016c028");
void func_002ed558(U24_W80Eff*, U24_W80Own*, u32, u32, void (*)(void)) asm("func_002ed558");
void w80_MenuCursor_Create(U11_CurObj* c, u32 a1, u32 a2, u32 a3, u32 sprA, u32 t1, u32 t2, s32 t3, u32 st) asm("_ZN2Tz10MenuCursor6CreateEz");
void w80_JmBattle_LeaveAllInner(void) asm("_ZN2Tz8JmBattle13LeaveAllInnerEv");
static inline bool func_00179450_flag(U0_Act* a) { return (a->sub->f8 & 2) || (a->f352 & 0x40); }
static inline bool func_00179450_busy(U0_Act* a) { bool b = func_0019c090(a) || func_00179450_flag(a); return b == false; }

s32 func_00179450(U0_Act* a) {
    if (a->state == 7) {
        if (!func_00179450_busy(a)) return 0;
        if (a->sub->f4 == 0 && func_001b9d40(a)) {  // vtable_call_slot64_flags
            if (!(a->f28 > 0.0f)) return 0;
            if (func_00177860(a)->f20 & 0x40) {
                func_0016bd60(a, 22);
                return 1;
            }
        }
    }
    return 0;
}
}  // namespace q28

// 00179530 (src/anon/batch_w100.cpp)
namespace q29 {
u32 func_00177860(u8*) asm("func_00177860");
s32 func_001c3618(u32, s32) asm("func_001c3618");
s32 func_0019c090(u8*) asm("func_0019c090");  // obj_is_enabled
s32 func_001b9d40(u8*) asm("func_001b9d40");  // vtable_call_slot64_flags
void func_0016aef0(u8*, u8*) asm("func_0016aef0");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
u8* func_001ce300(s32) asm("func_001ce300");  // to_1ce2a0_index_minus1
void func_00176a60(u8*, f32) asm("func_00176a60");
static inline bool IsLocked(u8* o) {
    bool r = false;
    if ((*(u32*)(*(u8**)(o + 12) + 8) & 2) || (*(u32*)(o + 352) & 0x40)) r = true;
    return r;
}
static inline bool IsBusy(u8* o) {
    bool r = false;
    if (func_0019c090(o) || IsLocked(o)) r = true;
    return r;
}
static inline bool CanAct3(u8* o) { return !IsBusy(o); }

s32 func_00179530(u8* o) {
    s32 n = func_001c3618(func_00177860(o), 4);
    if (n > 0 && CanAct3(o) && func_001b9d40(o)) {  // vtable_call_slot64_flags
        func_0016aef0(o, o + 16);
        func_0017f488(o + 320, 209, 0.0f, 0.0f);
        func_0017f5e0(o + 320, 0, 0, 0.0f, 0.0f);
        func_00176a60(o, *(f32*)(func_001ce300(n) + 64));
        return 1;
    }
    return 0;
}
}  // namespace q29

// 00179648 (src/anon/batch_w55.cpp)
namespace q30 {
typedef void (*CbW55)(u8*, u32);
void func_001ada38(s32) asm("func_001ada38");
void func_00177710(void) asm("func_00177710");
extern u8 D_0032bb30[] asm("D_0032bb30");
u8 func_0016c008(u32, s32) asm("func_0016c008");
s32 func_0016a070(u32) asm("func_0016a070");
s32 func_0016a020(u32) asm("func_0016a020");
void func_00253180(s32, s32) asm("func_00253180");
void func_002fd188(void (*)(void)) asm("func_002fd188");  // pool_alloc_block

void func_00179648(u32 a, u32 b) {
    func_001ada38(7);
    func_00177710();
    u8* s = D_0032bb30;
    s[14] = func_0016c008(b, 1);
    if (func_0016a070(a) == 14) *(u32*)(s + 9372) |= 1;
    else *(u32*)(s + 9372) &= ~1;
    func_00253180(1, func_0016a020(b) == 0x239 ? 0 : 2);
}
}  // namespace q30

// 001796e8 (src/anon/tiny_jal_wrappers_flex.cpp)
namespace q31 {
u32 func_00178330(u32, u32, u32, u32) asm("func_00178330");

u32 func_001796e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r5 = *(u32*)((u32)r5 + (s32)(2884));
    r5 = (u32)((s32)r5 + (2608));
    r2 = func_00178330(r4, r5, r6, r7);
    r2 = r16;
    return r2;
}
}  // namespace q31

// 00179718 (src/anon/batch_w279.cpp)
namespace q32 {
struct W279Vq {
    f32 x, y, z, w;
    W279Vq& operator=(const W279Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
u8* item_get_info(void*) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s32 menu_get_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 cmtop_get_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 cmtop_get_cur_pos(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
s32 jm_report_get_data(u32) asm("_ZN2Tz8JmReport7GetDataEj");
u8* party_get_sheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
s32 map_is_pax_exist(void) asm("_ZN2dk3Map10isPaxExistEv");
void* map_get_pax(void) asm("_ZN2dk3Map6getPaxEv");
s32 effect_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
void effect_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
W279Vq* effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
W279Vq* effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
s32 pax_search_id(void*, u64) asm("_ZN3ryj3PAX9search_idEy");
void* func_001de168(void*, s32, s32, s32, s32, s32) asm("func_001de168");  // scan_list_by_half
W279Vq octree_get_normal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
W279Vq func_0017d050(const W279Vq&) asm("func_0017d050");
extern f32 D_00349e10 asm("D_00349e10");
typedef void (*W279VFn1)(u8*, s32);

void func_00179718(u8* o) {
    if (!map_is_pax_exist()) return;
    if (*(void**)(o + 2900)) {
        if (!effect_is_alive(*(void**)(o + 2900))) {
            effect_kill(*(void**)(o + 2900));
            *(void**)(o + 2900) = 0;
        }
    }
    u32 id = *(u16*)(o + 1522);
    if (id != 0xffff) {
        if (*(void**)(o + 2900) == 0 && id != *(s32*)(o + 2904)) {
            s32 k = pax_search_id(map_get_pax(), 1);
            if (k >= 0) {
                void* h = func_001de168(map_get_pax(), k, 0, 2, 40000, 0);  // scan_list_by_half
                *(void**)(o + 2900) = h;
                if (h) {
                    W279Vq n = octree_get_normal(id, 0);
                    *effect_pos(*(void**)(o + 2900)) = *(W279Vq*)(o + 1488);
                    *effect_angle(*(void**)(o + 2900)) = func_0017d050(n);
                }
            }
            s32 v = *(u16*)(o + 1522);
            *(s32*)(o + 2904) = v;
            (*(W279VFn1**)o)[37](o, v);
        }
        *(f32*)(o + 2908) = 30.0f;
    } else {
        f32 t = *(f32*)(o + 2908);
        if (0.0f < t) {
            f32 t2 = t - D_00349e10;
            *(f32*)(o + 2908) = t2;
            if (t2 <= 0.0f) *(s32*)(o + 2904) = id;
        }
    }
}
}  // namespace q32

// 00179898 (never written before; PLAYER vtable entry)
namespace q_9898 {
void func_00176458(u8*, u8*, u8**) asm("func_00176458");
void func_00179898(u8* a, u8* b, u8** c) asm("func_00179898");
void func_00179898(u8* a, u8* b, u8** c) {
    func_00176458(a, b, c);
    if (c) {
        u8* x = *c;
        *(u32*)(*(u8**)(x + 12) + 2724) = *(u16*)(*(u8**)(x + 40) + 32);
    }
}
}  // namespace q_9898

// 001798d8 (src/anon/batch_wcx2.cpp)
namespace q_98d8 {
struct Tune37 { u8 pad[96]; f32 f96; f32 f100; u8 pad2[12]; f32 f116; };
extern Tune37* D_00352130__67414 asm("D_00352130");
struct Sub37 { u8 pad[431]; u8 st; u8 pad2[4]; f32 f436; };
struct Arg37 { u8 pad[41]; u8 k; };
u8* func_0017df58(s32) asm("func_0017df58");
s32 func_0019ba60(u8*) asm("func_0019ba60");
void func_0016cce8__67414(u32, s32, u32*, s32, s32) asm("func_0016cce8");
void func_00179a68(u8*, f32) asm("func_00179a68");
void func_001a1b68__67414(Sub37*, f32) asm("func_001a1b68");
void func_00177760(u8*, u8*, u32, Arg37*) asm("func_00177760");
void func_001798d8(u8* o, u8* t, u32 v, Arg37* a) asm("func_001798d8");
void func_001798d8(u8* o, u8* t, u32 v, Arg37* a)
{
    for (s32 i = 0; i < 2; i++) {
        u8* e = func_0017df58(i);
        if (!e) continue;
        if (!func_0019ba60(e)) continue;
        if (!*(u32*)(e + 1156)) continue;
        u32 m[2];
        m[0] = (u32)t;
        m[1] = v;
        func_0016cce8__67414(*(u32*)(e + 1156), 15, m, 2, 0);
    }
    if (a->k && (*(u32*)(t + 1416) & 0x10)) {
        u32 fl = *(u32*)(t + 1416);
        f32 f = a->k;
        Sub37* s = *(Sub37**)(o + 1164);
        switch (s->st) {
        case 3:
            if (s->f436 == 0.0f) break;
        case 1:
            if (fl & 0x800) f *= D_00352130__67414->f96;
            func_00179a68(o, f);
            break;
        case 2:
            f = -f * D_00352130__67414->f116;
            if (fl & 0x800) f *= D_00352130__67414->f100;
            func_001a1b68__67414(s, f);
            break;
        }
    }
    func_00177760(o, t, v, a);
}
}  // namespace q_98d8

// 00179a68 (src/anon/batch_w84.cpp)
namespace q34 {
typedef void (*VFn)(void*);
struct Cfg {
    u8 _0[60];
    f32 f60;
    u8 _64[20];
    f32 f84;
    u8 _88[24];
    f32 f112;
    u8 _116[4];
    f32 f120;
};
extern Cfg* D_00352130 asm("D_00352130");
s32 func_001a1de0(void*) asm("func_001a1de0");
Cfg* func_00177860(void*) asm("func_00177860");
f32 func_001bbfd0(void) asm("func_001bbfd0");
void func_001a1aa0(void*, s32) asm("func_001a1aa0");  // ring_buffer_index
void func_001a1b68(void*, f32) asm("func_001a1b68");
static inline bool Is12(u8* p) { return *(s32*)(p + 2896) == 12; }

void func_00179a68(u8* p, f32 f) {
    u8* q = *(u8**)(p + 1164);
    switch (q[431]) {
    case 2:
        if (Is12(p)) break;
    case 3:
        func_001a1b68(q, f * D_00352130->f112);
        break;
    case 1:
        if (func_001a1de0(q)) {
            f *= D_00352130->f120 * func_00177860(p)->f60;
        }
        f *= func_001bbfd0();
        func_001a1aa0(*(u8**)(p + 1164), (s32)f);  // ring_buffer_index
        break;
    }
}
}  // namespace q34

// 00179b68 (src/anon/batch_w49.cpp)
namespace q35 {
u8* func_001a6a20(u32, u32) asm("func_001a6a20");
s32 func_00176a90(u32) asm("func_00176a90");

s32 func_00179b68(u32 a) {
    s32 r = 0;
    if (*(u32*)(func_001a6a20(0x10002, 12) + 4) || func_00176a90(a)) r = 1;
    return r;
}
}  // namespace q35

// 00179bc8 (src/anon/tiny_wrappers_more80_reloc.cpp)
namespace q36 {
u32 func_001d68e0(u32, u32, u32, u32) asm("func_001d68e0");
extern u8 D_01c5f530 asm("D_01c5f530");

u32 func_00179bc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d68e0((u32)&D_01c5f530, a1, a2, a3);
}
}  // namespace q36

// 00179be8 (src/anon/tiny_wrappers_more80_reloc.cpp)
namespace q37 {
u32 func_001d68f8(u32, u32, u32, u32) asm("func_001d68f8");
extern u8 D_01c5f530 asm("D_01c5f530");

u32 func_00179be8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d68f8((u32)&D_01c5f530, a1, a2, a3);
}
}  // namespace q37

// 00179c08 (src/anon/auto80_199_queue.cpp)
namespace q38 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_001b90f0(u32, u32) asm("func_001b90f0");
u32 func_0019c218(u32, u32) asm("func_0019c218");
s32 func_001bc2a8(u32, u32, u32) asm("func_001bc2a8");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef s32 (*Cb_0028d730)(u32);
typedef u32 (*Method1)(u32);

u32 func_00179c08(u32 a0, u32 a1) {
    u32 s1 = a0;
    u32 s0 = a1;
    u32 s2 = 0;

    if (func_001b90f0(s0, s1) != 0) {
        u32 a2v = 0;
        if (func_0019c218(s1, s0) != 0) {
            s32 v0 = func_001bc2a8(s0, s1, a2v);
            s2 = (u32)(v0 < 4);
        }
    }

    return s2;
}
}  // namespace q38

// 00179c80 (src/anon/batch_w13.cpp)
namespace q39 {
extern void (*D_0035e380[])(void);
typedef s32 (*VFn2)(void*, s32);

s32 func_00179c80(u8* p) {
    s32 r = 0;
    if (*(s32*)(p + 2896) == 7) {
        s32 x = *(s32*)(p + 340);
        if (x == 203) goto yes;
        if (x == 204) goto yes;
        goto no;
    yes:
        r = 1;
    }
no:
    return r;
}
}  // namespace q39

// 00179cb8 (src/anon/batch_wcx2.cpp)
namespace q40 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
void func_0016af58(Vec4*, u8*) asm("func_0016af58");
typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
s32 func_00179c80(u8*) asm("func_00179c80");
void func_001dc818(u32) asm("func_001dc818");
u32* func_0015ef28(void) asm("func_0015ef28");
s32 func_001de2e0(u32*, u64) asm("func_001de2e0");
u32 func_001de168(u32*, s32, s32, s32, s32, s32) asm("func_001de168");  // scan_list_by_half
Vec4* func_001dc5f8(u32) asm("func_001dc5f8");
Vec4* func_0016c028(u8*) asm("func_0016c028");  // obj_get_attach_or_alt
Vec4* func_001dc648(u32) asm("func_001dc648");
void func_0017d050(Vec4*, Vec4*) asm("func_0017d050");

void func_00179cb8(u8* p)
{
    if (func_00179c80(p)) {
        u32 h = *(u32*)(p + 2912);
        if (!h) {
            u32* o = func_0015ef28();
            if (*o) {
                s32 k = func_001de2e0(o, 1LL << 50);
                if (k >= 0) {
                    h = *(u32*)(p + 2912) = func_001de168(o, k, 1, 2, 10001, 0);  // scan_list_by_half
                    goto have;
                }
            }
            h = *(u32*)(p + 2912);
        have:
            if (!h) return;
        }
        Vec4* d = func_001dc5f8(h);
        Vec4* s = func_0016c028(p);  // obj_get_attach_or_alt
        if (d != s) QCOPY(d, s);
        Vec4* m = func_001dc648(*(u32*)(p + 2912));
        Vec4 b, a;
        func_0016af58(&a, p);
        func_0017d050(&b, &a);
        if (m != &b) QCOPY(m, &b);
    } else if (*(u32*)(p + 2912)) {
        func_001dc818(*(u32*)(p + 2912));
        *(u32*)(p + 2912) = 0;
    }
}
}  // namespace q40

// 00179dd0 (src/anon/tiny_auto80_fptr4.cpp)
namespace q41 {
u32 func_001b8e88(u32, u32, u32, u32) asm("func_001b8e88");

u32 func_00179dd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15, r16, r17;
    r17 = r4;
    r16 = r5;
    r4 = r5;
    u32 (*fp_call4_001b8e88)(u32, u32, u32, u32) = func_001b8e88;
    r2 = fp_call4_001b8e88(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r2 + (s32)(12));
    r15 = (u32)((s32)r15 >> 9);
    r15 = (u32)(r15 & 0x0001u);
    if (r15 != 0u) r16 = 0u;
    *(u32*)((u32)r17 + (s32)(2888)) = r16;
    return r2;
}
}  // namespace q41

// 00179e18 (src/anon/batch_w7.cpp)
namespace q42 {
void func_001d6a80(u32) asm("func_001d6a80");
void func_00176ec8(u32) asm("func_00176ec8");

void func_00179e18(u8* a0) {
    func_001d6a80(*(u32*)(a0 + 2876));
    *(u32*)(a0 + 2888) = 0;
    func_00176ec8((u32)a0);
}
}  // namespace q42

// 00179e48 (src/anon/auto80_199_queue.cpp)
namespace q43 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
extern u32 D_0034e948 asm("D_0034e948");
u32 func_0019ba60(...) asm("func_0019ba60");
void func_00179ea0(u32) asm("func_00179ea0");
extern u32 D_0034e94c asm("D_0034e94c");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

u32 func_00179e48() {
    if (D_0034e94c == 0) {
        func_0019ba60(D_0034e948);
    }

    func_00179ea0(D_0034e948);

    u32 t7 = D_0034e948;
    D_0034e948 = 0;
    D_0034e94c = t7;
    return t7;
}
}  // namespace q43

// 00179ea0 (src/anon/tiny.cpp)
namespace q44 {
void func_001781e8(void*) asm("func_001781e8");

// 001688a0: moved to src/yasui/libys/file.cpp
void func_00179ea0(BD_VALUE* bd) { func_001781e8(bd); }
}  // namespace q44

// 00179eb8 (src/anon/auto80_199_queue.cpp)
namespace q45 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
extern u32 D_0034e948 asm("D_0034e948");
u32 func_0019ba60(...) asm("func_0019ba60");
extern u32 D_0034e94c asm("D_0034e94c");
void func_00179f58(u32) asm("func_00179f58");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

u32 func_00179eb8() {
    if (D_0034e948 == 0) {
        func_0019ba60(D_0034e94c);
    }

    u32 t7 = D_0034e94c;
    D_0034e94c = 0;
    D_0034e948 = t7;

    func_00179f58(t7);

    return D_0034e948;
}
}  // namespace q45

// 00179f10 (src/anon/tiny_auto80_solver.cpp)
namespace q46 {
u32 func_0016bd10(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_0016bd10");
u32 func_0016bd60(u32, u32) asm("func_0016bd60");
u32 func_00179f10(u32) asm("func_00179f10");
u32 func_001852b8(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001852b8");
u32 func_0016bd60(u32 a0, u32 a1) asm("func_0016bd60");

u32 func_00179f10(u32 a0) {
    u32 s0 = a0;
    *(u32*)(a0 + 2040) &= (u32)-5;
    ((u32(*)(u32))func_001852b8)(a0);
    u32 v0 = ((u32(*)(u32, u32))func_0016bd60)(s0, 0);
    *(u32*)(*(u32*)(s0 + 2884) + 2528) = s0;
    return v0;
}
}  // namespace q46

// 00179f58 (src/anon/batch_w1.cpp)
namespace q47 {
void func_00179f10(void*) asm("func_00179f10");
void func_001781a8(void*) asm("func_001781a8");

void func_00179f58(void* p) {
    func_00179f10(p);
    func_001781a8(p);
}
}  // namespace q47

// 00179f80 (src/anon/batch_w31.cpp)
namespace q48 {
typedef void (*VFn)(void*);
void func_00179f10(void*) asm("func_00179f10");
void func_001d6ab0(u32) asm("func_001d6ab0");
typedef int (*VFn4)(void*, u32, int, int);

int func_00179f80(u8* p) {
    func_00179f10(p);
    func_001d6ab0(*(u32*)(p + 2876));
    u32 a = *(u32*)(*(u8**)(p + 1164) + 4);
    return (*(VFn4*)(*(u8**)p + 120))(p, a, 0, 0);
}
}  // namespace q48

// 00179fd0 (src/anon/batch_w112.cpp)
namespace q49 {
u32 func_00167f18(u32) asm("func_00167f18");
void* func_001050d8(u32) asm("func_001050d8");
void func_002d49c0(void*, u32*, u32, u32, f32) asm("func_002d49c0");
void func_002d9730(void*, u32*, u32, u32, f32) asm("func_002d9730");
void func_002dd700(void*, u32*, u32, u32, f32) asm("func_002dd700");
void func_001d1540(void*, u32*, u32, u32, f32) asm("func_001d1540");
void func_001cf698(void*, u32*, u32, u32, f32) asm("func_001cf698");
void func_001ced68(void*, u32*, u32, u32, f32) asm("func_001ced68");
void func_001d0980(void*, u32*, u32, u32, u32, f32) asm("func_001d0980");

// Creates the object class matching the spawn entry's type id.
void* func_00179fd0(u32* info, u32 a1, u32 a2, f32 t) {
    u32 m = func_00167f18(0);
    void* o;
    switch (*info) {
    case 859:
        o = func_001050d8(3136);
        func_002d49c0(o, info, m, a2, t);
        break;
    case 860:
        o = func_001050d8(3360);
        func_002d9730(o, info, m, a2, t);
        break;
    case 861:
        o = func_001050d8(3088);
        func_002dd700(o, info, m, a2, t);
        break;
    case 958:
        o = func_001050d8(2928);
        func_001d1540(o, info, m, a2, t);
        break;
    case 968:
        o = func_001050d8(2992);
        func_001cf698(o, info, m, a2, t);
        break;
    case 1525:
        o = func_001050d8(2944);
        func_001ced68(o, info, m, a2, t);
        break;
    default:
        o = func_001050d8(2944);
        func_001d0980(o, info, a1, m, a2, t);
        break;
    }
    return o;
}
}  // namespace q49

// 0017a1b8 (never written before; PLAYER vtable entry)
namespace q_a1b8 {
u32 func_0017a1b8(u8* o) asm("func_0017a1b8");
u32 func_0017a1b8(u8* o) { return *(u32*)(o + 2896) == 0; }
}  // namespace q_a1b8

// 0017a1c8 (src/anon/batch_w22.cpp)
namespace q_a1c8 {
void func_001762f8(void*) asm("func_001762f8");
void func_00112ab8(u32, void*) asm("func_00112ab8");
void BTLOBJ_exec_damage(u8*, void*) asm("_ZN2YS6BTLOBJ6VTABLEINS_6PLAYEREE11exec_damageEPS0_PNS_6DAMAGEE");
void BTLOBJ_exec_damage(u8* o, void* dmg) {
    *(u32*)(o + 268) &= ~2;
    func_001762f8(o);
    func_00112ab8(0, dmg);
}
}  // namespace q_a1c8

// 0017a208 (never written before; PLAYER vtable entry)
namespace q_a208 {
void func_00186160(u8*) asm("func_00186160");
void func_0017a208(u8* o) asm("func_0017a208");
void func_0017a208(u8* o) {
    if (!(*(u32*)(o + 2040) & 4)) func_00186160(o);
}
}  // namespace q_a208

// 0017a230 (src/anon/batch_w16.cpp)
namespace q51 {
typedef void (*VFn)(void*);
typedef void (*VFn1)(void*, void*);
typedef u32 (*VFnR)(void*);
void func_001bdab0(u32) asm("func_001bdab0");
void func_001776f8(void*) asm("func_001776f8");

void func_0017a230(u8* p) {
    func_001bdab0(*(u32*)(p + 2884));
    func_001776f8(p);
}
}  // namespace q51

// 0017a260 (never written before; PLAYER vtable entry)
namespace q_a260 {
void func_001a11b0(u8*, u32) asm("func_001a11b0");
void func_00177678(u8*) asm("func_00177678");
void func_0017a260(u8* o) asm("func_0017a260");
void func_0017a260(u8* o) {
    u8* p = *(u8**)(o + 1164);
    if (p) func_001a11b0(p, *(u32*)(o + 2896));
    func_00177678(o);
}
}  // namespace q_a260

// 0017a298 (src/anon/tiny_auto80_queue.cpp)
namespace q52 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_00140dc0(...) asm("func_00140dc0");
extern "C" u32 func_001410b8(...) asm("func_001410b8");
u32 func_00141080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00141080");
extern "C" u32 func_00175bb8(...) asm("func_00175bb8");

u32 func_0017a298(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00175bb8)();
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_00141080)();
        r15 = ((u32)r2 < 0x00000001u);
    }
    r2 = r15;
    return r2;
}
}  // namespace q52

// 0017a2d0 (src/anon/batch_w81.cpp)
namespace q53 {
struct Vq81 {
    f32 x, y, z, w;
    Vq81& operator=(const Vq81& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vnorm81(Vq81& v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, $f0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&v) : "$8", "$f0", "memory");
}
static inline Vq81 vscale81(const Vq81& a, f32 s) {
    Vq81 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
typedef s32 (*VFn81)(...);
typedef void (*VFnV81)(...);
struct VObj0 { void (**vt)(VObj0*); };
extern VObj0* D_003485f8 asm("D_003485f8");
extern VObj0* D_003485f4 asm("D_003485f4");
extern VObj0* D_003485f0 asm("D_003485f0");
extern VObj0* D_003485ec asm("D_003485ec");
extern VObj0* D_003485e8 asm("D_003485e8");
void u_call0_0013d9e0(void) asm("_Z16u_call0_0013d9e0v");
void u_call0_0013d9e0(void) asm("func_0013d9e0");
extern u32 D_0034ece4 asm("D_0034ece4");
void func_00143e50(Vq81*, u16, u32) asm("func_00143e50");
s32 func_0019c778(u8*, Vq81*) asm("func_0019c778");
u32 func_00192048(u32) asm("func_00192048");
void func_0015b268(u32, f32) asm("func_0015b268");

void func_0017a2d0(u8* o) {
    u32 id = *(u16*)(o + 1524);
    if (id == 0xffff) return;
    if (!D_0034ece4) return;
    Vq81 v;
    func_00143e50(&v, id, 0);
    v.y = 0;
    vnorm81(v);
    Vq81 d = vscale81(v, -1.0f);
    if (func_0019c778(o, &d)) func_0015b268(func_00192048(D_0034ece4), 60.0f);
}
}  // namespace q53

// 0017a3b0 (src/anon/auto80_199_queue.cpp)
namespace q54 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_001ad938() asm("func_001ad938");
void func_0017a418(u32, u32) asm("func_0017a418");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
u32 fn(...) asm("fn");
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_0017a3b0(u32 a0) {
    u32 s0 = a0;

    if (*(u8*)(a0 + 2916) != 0) {
        return;
    }

    u32 t7 = *(u32*)(a0 + 0);
    u32 fn = *(u32*)(t7 + 64);

    if (((u32(*)(u32))fn)(a0) != 0 || func_001ad938() != 0) {
        return func_0017a418(s0, 1);
    }
}
}  // namespace q54

// 0017a418 (src/anon/batch_w46.cpp)
namespace q55 {
void func_001d6ae0(u32) asm("func_001d6ae0");
void func_001d6b40(u32) asm("func_001d6b40");

void func_0017a418(u8* p, s32 m) {
    switch (m) {
    case 1: func_001d6ae0(*(u32*)(p + 2876)); break;
    case 2: func_001d6b40(*(u32*)(p + 2876)); break;
    }
    p[2916] = m;
}
}  // namespace q55

// 0017a480 (src/anon/auto80_199_queue.cpp)
namespace q56 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_00177860(...) asm("func_00177860");
void func_00179a68(u32, f32) asm("func_00179a68");
void func_00177c50(u32, u32, u32, u32) asm("func_00177c50");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef s32 (*Cb_0028d730)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_0017a480(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 s2 = a2;
    u32 s3 = a3 & 0xff;

    u32 t5 = *(u32*)(a0 + 1164);
    if (t5 != 0) {
        u8 t6 = *(u8*)(t5 + 431);
        if (t6 == 1) {
            if ((s32)s1 < 0) {
                u32 t7 = (u32)(-(s32)s1);
                s32 i0 = *(s32*)(t5 + 4);
                f32 f0 = (f32)i0;
                f32 f20 = (f32)(s32)t7;
                f20 = f20 / f0;

                u32 v0 = func_00177860(s0);
                f0 = *(f32*)(v0 + 84);
                f20 = f20 * f0;
                func_00179a68(s0, f20);
            }
        }
    }

    return func_00177c50(s0, s1, s2, s3);
}
}  // namespace q56

// 0017a538 (src/anon/batch_w34.cpp)
namespace q57 {
s32 func_0016a070(void*) asm("func_0016a070");
static inline s32 inRange(s32 v) {
    if (v == 0) return 0;
    if (v < 7) return 1;
    return 0;
}

s32 func_0017a538(u8* p) {
    s32 r = 0;
    if (func_0016a070(p) == 1) r = inRange(*(s32*)(p + 2896));
    return r;
}
}  // namespace q57

// 0017a590 (src/anon/auto80_199_queue.cpp)
namespace q58 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_00177870(u32) asm("func_00177870");
u32 func_00177860(...) asm("func_00177860");
u32 func_0019c090(...) asm("func_0019c090");
u32 func_001778c0(u32, u32) asm("func_001778c0");
u32 func_001a6178(u32, u32, u32) asm("func_001a6178");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef s32 (*Cb_0028d730)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);
u32 func_001778c0(u32 a0, u32 a1) asm("func_001778c0");

void func_0017a590(u32 a0, u32 a1) {
    u32 v0 = 0;
    u32 s0 = a0;
    u32 s1 = a1;

    if (*(u32*)(a0 + 2896) != 7) {
        v0 = func_001778c0(a0, 0);
    }

    v0 = func_001a6178(s0, s1, v0);
    *(u32*)(s0 + 2856) = v0;
    *(u32*)(s0 + 268) |= 0x00040000;
}
}  // namespace q58

// 0017a600 (src/anon/batch_w53.cpp)
namespace q59 {
typedef void (*Fn0)(u8*);
typedef void (*Fn1)(void*, void*);
typedef void (*Fn3)(u32, u32, u32);
typedef u32 (*Fn8)(u8*, u32, u32, u32, u32, u32, u8, u32);
typedef void (*VFn)(u8*);
typedef void (*VFn0)(void);
u32 func_00190140(u8*) asm("func_00190140");
void func_00190f80(u8*, u8*, f32) asm("func_00190f80");
void func_0019ca90(u32, u32, u8*) asm("func_0019ca90");
void func_0019d358(u32) asm("func_0019d358");

void func_0017a600(u8* p) {
    u8* s = p + 2548;
    if (!func_00190140(s)) {
        func_00190f80(s, p, 0.0f);
        if (func_00190140(s)) {
            func_0019ca90(*(u32*)(p + 2880), 1, s);
            func_0019d358(*(u32*)(p + 2880));
        }
    }
}
}  // namespace q59

// 0017a680 (src/anon/tiny_auto80_queue.cpp)
namespace q60 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_001779d0(...) asm("func_001779d0");
extern "C" u32 func_001bc0e0(...) asm("func_001bc0e0");

u32 func_0017a680(u32 a0) {
    u32 r4 = a0, r2, r16, r17;
    r16 = r4;
    r17 = 0u;
    r2 = ((u32(*)(u32))func_001bc0e0)(r4);
    r4 = r16;
    if (r2 != 0u) {
        r2 = ((u32(*)(u32))func_001779d0)(r4);
        r17 = ((u32)0u < (u32)r2);
    }
    r2 = r17;
    return r2;
}
}  // namespace q60

// 0017a6c8 (src/anon/batch_w32.cpp)
namespace q61 {
extern void* D_0034e948 asm("D_0034e948");
s32 func_0019ba60(void*) asm("func_0019ba60");

u32 func_0017a6c8(void) {
    u32 r = 0;
    if (func_0019ba60(D_0034e948)) {
        u32 m = *(u32*)((u8*)D_0034e948 + 0x160) & 0x4000;
        r = m != 0;
    }
    return r;
}
}  // namespace q61

// 0017a718 (src/anon/batch_w54.cpp)
namespace q62 {
extern void (*D_0032ba34)(void);
typedef s32 (*VFn124)(void*, s32, s32, s32, s32, s32, u8, s32);
s32 func_001a35f8(u32, s32) asm("func_001a35f8");
void func_00194070(void*, u8) asm("func_00194070");
extern u16 D_0036c4e8[3] asm("D_0036c4e8");
extern u8 D_0036c4f0[] asm("D_0036c4f0");

void func_0017a718(void* p) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 3; i++) n += func_001a35f8(D_0036c4e8[i], 100) > 0;
    func_00194070(p, D_0036c4f0[n]);
}
}  // namespace q62

// 0017a798 (src/anon/tiny_auto80_queue.cpp)
namespace q63 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_0019ba60(...) asm("func_0019ba60");
extern "C" u32 func_0017a718(...) asm("func_0017a718");
extern u8 D_0034e948 asm("D_0034e948");

void func_0017a798() {
    if (func_0019ba60(*(volatile u32*)((u32)&D_0034e948 + (s32)(0))) == 0u) {
        return;
    }
    func_0017a718(*(volatile u32*)((u32)&D_0034e948 + (s32)(0)));
}
}  // namespace q63

// 0017a7d8 YS::PLAYER::lockon_end (src/yasui/libys/player.cpp)
namespace q_a7d8 {
void PLAYER_lockon_end(u8*) asm("_ZN2YS6PLAYER10lockon_endEv");
void PLAYER_lockon_end(u8*) {}
}  // namespace q_a7d8
