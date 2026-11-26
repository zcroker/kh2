// 0x1c5b90-0x1c6a28: spawner nodes (vtable 0x351cd8 slots, node state functions).
// Part of the file that starts at 0x1c5168 (C2/C1 ctor, whole-asm spawner 0x1c51d8). The unwritten
// gap fn 0x1c5580-0x1c5b90 (vtable slot 5) before this unit and 0x1c6a28 (drop at a random ground
// point, state set by 0x1c6c60) after it stay outside. Flags: -G0 -fno-strict-aliasing (_nsa copies).
#include "../common/types.h"

// ---- 001c5b90 gap (vtable 0x351cd8 slot 14): read the two unit args
namespace n001c5b90 {
void func_0016bf38(u8*) asm("func_0016bf38");
s32 get_unit_arg(u8*, s32) asm("_ZN2YS3OBJ12get_unit_argEi");
extern s32 D_00351670 asm("D_00351670");
extern s32 D_00351674 asm("D_00351674");
void func_001c5b90(u8* o) asm("func_001c5b90");
void func_001c5b90(u8* o) {
    func_0016bf38(o);
    if (get_unit_arg(o, 1)) D_00351670 = get_unit_arg(o, 1);
    if (get_unit_arg(o, 2)) D_00351674 = get_unit_arg(o, 1);
}
}  // namespace n001c5b90

// ---- 001c5c08 from src/anon/auto80_199_queue.cpp
namespace n001c5c08 {
u32 func_001dbd68() asm("_Z13func_001dbd68v");
u32 func_001c6c60(void*) asm("_Z13func_001c6c60Pv");
extern s32 D_01d498a4 asm("D_01d498a4");
u32 func_001c5c08(void* a0) asm("_Z13func_001c5c08Pv");
u32 func_001c5c08(void* a0) {
    if (D_01d498a4 < 50) {
        if (func_001dbd68() != 0) {
            func_001c6c60(a0);
            return 1;
        }
    }
    return 0;
}
}  // namespace n001c5c08

// ---- 001c5c60 from src/anon/batch_w289.cpp
namespace n001c5c60 {
#define QCOPY289P(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY289P(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY289P(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot(const QWord& a, const QWord& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
extern u32 D_0035169c[] asm("D_0035169c");
extern QWord D_00352a60 asm("D_00352a60");
extern u32 D_0034e948 asm("D_0034e948");
QWord YS__OBJ__get_dir(u32) asm("YS__OBJ__get_dir");
void YS__CROWD_M_EX760___Blow(u8*, QWord*) asm("YS__CROWD_M_EX760___Blow");
s32 YS__CROWD_M_EX760__CheckAttack(u8* o) asm("YS__CROWD_M_EX760__CheckAttack");
s32 YS__CROWD_M_EX760__CheckAttack(u8* o) {
    if (D_0035169c[o[82] * 8] & 2) {
    QWord d = Sub(*(QWord*)o, D_00352a60);
    d.f[1] = 0.0f;
    QWord dir = YS__OBJ__get_dir(D_0034e948);
    f32 t = Dot(dir, d);
    if (t < 0.0f || 1000.0f < t) return 0;
    QWord up;
    up.f[0] = 0.0f;
    up.f[1] = -1.0f;
    up.f[2] = 0.0f;
    up.f[3] = 0.0f;
    QWord c = Cross(up, dir);
    d.f[0] = Dot(c, d);
    if (40000.0f < d.f[0] * d.f[0] + d.f[1] * d.f[1]) return 0;
    d = Sub(*(QWord*)o, D_00352a60);
    Normalize(&d);
    YS__CROWD_M_EX760___Blow(o, &d);
    return 1;
    }
    return 0;
}
}  // namespace n001c5c60

// ---- 001c5e18 gap (state set by 0x1c5e88): fall for p[80] frames
namespace n001c5e18 {
struct V {
    f32 x, y, z, w;
    V& operator+=(const V& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct N { V pos; u8 pad0[5]; u8 alpha; u8 pad1[42]; V vel; u8 cnt; u8 pad2[3]; void* fn; };
s32 func_001dbd68(N*) asm("func_001dbd68");
void func_001c5e18(N* p) asm("func_001c5e18");
void func_001c5e18(N* p) {
    if (func_001dbd68(p) != 0 || p->cnt == 0) {
        p->alpha = 0;
        p->fn = 0;
    } else {
        p->cnt--;
        p->pos += p->vel;
        p->pos.w = 1.0f;
    }
}
}  // namespace n001c5e18

// ---- 001c5e88 from src/anon/batch_w66.cpp
namespace n001c5e88 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Vi { f32 x, y, z; u32 w; Vi(f32 a, f32 b, f32 c, u32 d) { x = a; y = b; z = c; w = d; } } __attribute__((aligned(16)));
static inline Vq vscale(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
s32 func_001dbd68(u8*) asm("func_001dbd68");
extern Vq D_01d49880 asm("D_01d49880");
struct Sub1c5 { u32 a; s32 cnt; u8 pad[8]; };
struct E1c5 { u8 pad[16]; Sub1c5 sub; };
extern E1c5 D_00351680[] asm("D_00351680");
void func_001c5e18(void) asm("func_001c5e18");
static inline void dec1c5(Sub1c5* s) { s->cnt--; }
void YS__CROWD_M_EX760__ActionLeave(u8* p) asm("YS__CROWD_M_EX760__ActionLeave");
void YS__CROWD_M_EX760__ActionLeave(u8* p) {
    s32 v = func_001dbd68(p);
    if (v) {
        p[21] = 0;
        *(u32*)(p + 84) = 0;
    } else {
        p[21] = 0x80;
        p[80] = 10;
        *(Vq*)(p + 64) = vscale(D_01d49880, 40.0f);
        *(void**)(p + 84) = (void*)func_001c5e18;
    }
    E1c5* e = &D_00351680[p[82]];
    dec1c5(&e->sub);
}
}  // namespace n001c5e88

// ---- 001c5f38 from src/anon/batch_w11.cpp
namespace n001c5f38 {
struct E1c5 { u8 pad[20]; s32 n; u8 pad2[8]; };
extern E1c5 D_00351680[] asm("D_00351680");
void YS__CROWD_M_EX760__ActionLeave(void*) asm("YS__CROWD_M_EX760__ActionLeave");
s32 func_001c5f38(u8* p) asm("func_001c5f38");
s32 func_001c5f38(u8* p) {
    if (D_00351680[p[82]].n > 0) {
        YS__CROWD_M_EX760__ActionLeave(p);
        return 1;
    }
    return 0;
}
}  // namespace n001c5f38

// ---- 001c5f78 from src/anon/tiny_more.cpp
namespace n001c5f78 {
u32 func_001c5f78(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001c5f78jjjj");
u32 func_001c5f78(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (92)); u32 v = *(u32*)((u32)p + (4)); v ^= 0x5bdu; return (v < 1u); }
}  // namespace n001c5f78

// ---- 001c5f90 from src/anon/batch_w277.cpp
namespace n001c5f90 {
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
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void ScaleTo(QWord* d, const QWord* a, f32 s)
{
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
extern s32 D_01d498b0 asm("D_01d498b0");
extern QWord D_00352a60 asm("D_00352a60");
extern QWord D_01d49870 asm("D_01d49870");
void func_001dbb38(void) asm("func_001dbb38");
s32 func_00197920(void) asm("func_00197920");
s32 func_001c5f78(void) asm("func_001c5f78");
void* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
s32 func_0016a020(void*) asm("func_0016a020");
s32 func_001dbe78(void*, QWord*) asm("func_001dbe78");
struct Ob { QWord pos; u8 pad[72]; s32 x58; };
s32 func_001c5f90(Ob* o) asm("func_001c5f90");
s32 func_001c5f90(Ob* o) {
    void* ret = 0;
    QWord v;
    if (1000 - D_01d498b0 < 300) {
        o->x58 = 1000;
        func_001dbb38();
    } else if (func_001c5f78()) {
        s32 cnt = 0;
        while ((ret = YS__OBJ__Each(ret)) != 0) {
            if (func_0016a020(ret) == 1469) {
                if (++cnt >= 2) return 0;
            }
        }
        func_001dbb38();
    }
    if (func_00197920()) {
        v = Sub(D_00352a60, o->pos);
        if (400.0f < Normalize(&v)) ret = (void*)func_001dbe78(o, &v);
    } else {
        ScaleTo(&v, &D_01d49870, -1.0f);
        ret = (void*)func_001dbe78(o, &v);
    }
    return (s32)ret;
}
}  // namespace n001c5f90

// ---- 001c6108 gap (state set by 0x1c6310): approach the player
namespace n001c6108 {
struct V {
    f32 x, y, z, w;
    V() {}
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V operator-(const V& b) const
    {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V operator*(f32 k) const
    {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    V operator*(const V& v) const {
        V o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct N { V pos; u8 pad0[5]; u8 alpha; u8 pad1[60]; u8 slot; };
s32 func_001c5f38(N*) asm("func_001c5f38");
s32 YS__CROWD_M_EX760__CheckAttack(N*) asm("YS__CROWD_M_EX760__CheckAttack");
s32 func_001c5c08(N*) asm("_Z13func_001c5c08Pv");
s32 func_001c5f90(N*) asm("func_001c5f90");
void func_001c6748(N*) asm("func_001c6748");
void func_001c6400(N*, const V*) asm("func_001c6400");
void func_001dbb38(void) asm("func_001dbb38");
extern u32 D_0035169c[] asm("D_0035169c");
extern V D_00352a60 asm("D_00352a60");
extern M D_01d497f0 asm("D_01d497f0");
extern f32 D_01d498a0 asm("D_01d498a0");
void func_001c6108(N* o) asm("func_001c6108");
void func_001c6108(N* o) {
    if (func_001c5f38(o)) return;
    if (YS__CROWD_M_EX760__CheckAttack(o)) return;
    if (func_001c5c08(o)) return;
    if ((D_0035169c[o->slot * 8] & 1) == 1) {
        V v, p;
        {
            V d = D_00352a60 - o->pos;
            v = d;
        }
        v.y = 0.0f;
        f32 dist = v.normalize();
        if (dist < 700.0f) {
            if (func_001c5f90(o)) { func_001c6748(o); return; }
            if (dist < 400.0f) {
                func_001dbb38();
                if (func_001c5f90(o)) { func_001c6748(o); return; }
                {
                    V t = v * -1.0f;
                    func_001c6400(o, &t);
                }
                return;
            }
        }
        p = D_01d497f0 * o->pos;
        if (p.z < 1000.0f) {
            dist = p.lengthSq();
            if (dist < D_01d498a0) o->alpha = 0;
            else o->alpha = 0x80;
        }
    }
}
}  // namespace n001c6108

// ---- 001c6310 from src/anon/tiny.cpp
namespace n001c6310 {
extern u32 D_001c6108 asm("D_001c6108");
void func_001c6310(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001c6310jjjj");
void func_001c6310(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (84)) = (u32)&D_001c6108;
}
}  // namespace n001c6310

// ---- 001c6320 from src/anon/batch_w245.cpp
namespace n001c6320 {
struct QW { f32 f[4]; } __attribute__((aligned(16)));
struct P { QW pos; u8 pad[0x40-16]; QW vel; };
union FU { f32 f; u8 c; };
extern FU D_00349e10 asm("D_00349e10");
s32 func_001c5f38(P*) asm("func_001c5f38");
void func_001c6748(P*) asm("func_001c6748");
static inline void Scale(QW* d, QW* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
static inline void Add(QW* d, QW* a, QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
void func_001c6320(P* s) asm("func_001c6320");
void func_001c6320(P* s) {
    if (func_001c5f38(s)) return;
    if (0.0f < s->vel.f[3]) {
        s->vel.f[3] -= D_00349e10.f;
        QW t;
        Scale(&t, &s->vel, D_00349e10.f);
        Add(&s->pos, &s->pos, &t);
        s->pos.f[3] = 1.0f;
        if (s->vel.f[3] < 4.0f) ((u8*)s)[21] = (s32)(s->vel.f[3] * 0.25f * 128.0f);
    } else {
        func_001c6748(s);
    }
}
}  // namespace n001c6320

// ---- 001c6400 from src/anon/batch_w53.cpp
namespace n001c6400 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void func_001c6320(void) asm("func_001c6320");
void func_001c6400(u8* p, Q16* v) asm("func_001c6400");
void func_001c6400(u8* p, Q16* v) {
    Q16 t;
    f32 s = 30.0f;
    Q16* d = (Q16*)(p + 64);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&t), "r"(v), "f"(s) : "$8", "memory");
    if (d != &t) QCOPY(d, &t);
    *(f32*)(p + 76) = 12.0f;
    *(void**)(p + 84) = (void*)func_001c6320;
}
}  // namespace n001c6400

// ---- 001c6460 from src/anon/batch_wcx2_nsa.cpp
namespace n001c6460 {
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
struct V1c6460 {
    f32 x, y, z, w;
    V1c6460() {}
    V1c6460& operator=(const V1c6460& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1c6460 operator-(const V1c6460& b) const
    {
        V1c6460 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1c6460 operator+(const V1c6460& b) const
    {
        V1c6460 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1c6460& operator+=(const V1c6460& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V1c6460 operator*(f32 k) const
    {
        V1c6460 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct M1c6460 {
    V1c6460 r[4];
    V1c6460 operator*(const V1c6460& v) const {
        V1c6460 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct N1c6460 {
    V1c6460 pos;
    u8 pad0[5];
    u8 active;
    u8 pad1[26];
    V1c6460 home;
    u8 pad2[12];
    f32 timer;
    u8 cool;
};
extern V1c6460 D_00352a60 asm("D_00352a60");
extern M1c6460 D_01d497f0 asm("D_01d497f0");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001c5f38(N1c6460*) asm("func_001c5f38");
s32 func_001c5c08(N1c6460*) asm("func_001c5c08");
void func_001c6310(N1c6460*) asm("func_001c6310");
s32 func_001dbd68(N1c6460*) asm("func_001dbd68");
void func_001c5f90(N1c6460*) asm("func_001c5f90");
double func_00313b80(f32) asm("func_00313b80");
s32 func_003142e0(double, double) asm("func_003142e0");
void func_001c6460(N1c6460* n) asm("func_001c6460");
void func_001c6460(N1c6460* n)
{
    if (func_001c5f38(n)) return;
    if (func_001c5c08(n)) return;
    V1c6460 d, p;
    d = n->pos - D_00352a60;
    d.y = 0.0f;
    f32 dist = d.normalize();
    if (n->cool) {
        if (1400.0f < dist) n->cool = 1;
        if (--n->cool == 0) n->active = 0;
        return;
    }
    p = D_01d497f0 * n->pos;
    if (p.z < 1000.0f && p.lengthSq() < 90000.0f) {
        n->active = 0;
        return;
    }
    if (__builtin_expect(n->active != 0, 1)) {
        n->timer -= D_00349e10;
        n->pos += d * D_00349e10 * -30.0f;
        n->pos.w = 1.0f;
        if (func_003142e0(func_00313b80(n->timer), 0.0) > 0) return;
        func_001c6310(n);
    } else if (860.0f < dist) {
        n->pos = n->home + d * 12.0f * 30.0f;
        n->timer = 12.0f;
        n->active = 0x80;
    } else if (400.0f < dist) {
        if (func_001dbd68(n)) func_001c5f90(n);
    }
}
}  // namespace n001c6460

// ---- 001c6748 from src/anon/batch_w5.cpp
namespace n001c6748 {
void func_001c6460(void) asm("func_001c6460");
void func_001c6748(u8* p) asm("func_001c6748");
void func_001c6748(u8* p) {
    p[0x50] = 2;
    *(void (**)(void))(p + 0x54) = func_001c6460;
}
}  // namespace n001c6748

// ---- 001c6760 from src/anon/batch_w1811_nsa.cpp
namespace n001c6760 {
struct W1811V {
    f32 x, y, z, w;
    W1811V() {}
    W1811V& operator=(const W1811V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1811V operator-(const W1811V& o) const {
        W1811V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1811V operator*(f32 k) const {
        W1811V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1811V& operator+=(const W1811V& b) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1811Part { W1811V pos; u8 pad[5]; u8 alpha; u8 pad2[0x2a]; W1811V vel; };
extern f32 D_00349e10 asm("D_00349e10");
void func_001c6760(W1811Part* o) asm("func_001c6760");
void func_001c6760(W1811Part* o) {
    o->vel.x *= 0.95f;
    o->vel.z *= 0.95f;
    f32 y = o->vel.y + D_00349e10 * 0.41666666f;
    o->vel.y = (30.0f < y) ? 30.0f : y;
    o->pos += o->vel * D_00349e10;
    f32 tm = o->vel.w;
    if (tm < 4.0f) o->alpha = (s32)(tm * 0.25f * 128.0f);
    o->vel.w = tm - D_00349e10;
}
}  // namespace n001c6760

// ---- 001c6850 from src/anon/batch_w57.cpp
namespace n001c6850 {
u32 func_001c5f38(void*) asm("func_001c5f38");
void func_001c6760(void*) asm("func_001c6760");
u32 func_001dbd68(void*) asm("func_001dbd68");
void func_001c6748(void*) asm("func_001c6748");
struct T1c6 { u8 p[4]; f32 f4; u8 p2[13]; u8 b21; u8 p3[30]; f32 f52; u8 p4[20]; f32 f76; u8 b80; };
void func_001c6850(T1c6* t) asm("func_001c6850");
void func_001c6850(T1c6* t) {
    if (func_001c5f38(t)) return;
    if (t->f76 > 0.0f) {
        func_001c6760(t);
        return;
    }
    t->f4 = t->f52;
    t->b21 = 0;
    if (t->b80) {
        t->b80--;
        return;
    }
    if (func_001dbd68(t)) func_001c6748(t);
}
}  // namespace n001c6850

// ---- 001c68e0 gap (vtable 0x351cd8 slot 11): count event 75
namespace n001c68e0 {
extern s32 D_01d498b0 asm("D_01d498b0");
void func_001c68e0(u8* o, s32 id) asm("func_001c68e0");
void func_001c68e0(u8* o, s32 id) {
    if (id == 75) D_01d498b0++;
}
}  // namespace n001c68e0

// ---- 001c6900 from src/anon/batch_w8017_nsa.cpp
namespace n001c6900 {
struct QW {
    f32 x, y, z, w;
    QW() {}
    QW(const QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW& operator=(const QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline QW vscale(const QW& a, f32 k) {
    QW r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct Act { u8 p0[0x40]; QW vel; u8 p50; u8 p51[3]; void (*fn)(Act*); };
s32 func_001c5f78(Act*, QW*) asm("func_001c5f78");
s32 func_001db5a8(s32) asm("func_001db5a8");
void func_001b4198(s32, s32, Act*) asm("func_001b4198");
void func_001890a8(void*, s32) asm("func_001890a8");
void addcount_w8017(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void func_001c6850(Act*) asm("func_001c6850");
extern u8 D_0032e020[] asm("D_0032e020");
extern s32 D_0034e948 asm("D_0034e948");
extern s32 D_00351670 asm("D_00351670");
extern s32 D_00351674 asm("D_00351674");
extern s32 D_0036df78[] asm("D_0036df78");
extern s32 D_01d498b0 asm("D_01d498b0");
void YS__CROWD_M_EX760___Blow(Act* a, QW* v) asm("YS__CROWD_M_EX760___Blow");
void YS__CROWD_M_EX760___Blow(Act* a, QW* v) {
    s32 id;
    s32 r = 0;
    if (func_001c5f78(a, v) != 0) {
        id = 0x405;
        if (D_00351674 > 0) r = func_001db5a8(D_0036df78[D_00351674 - 1]);
    } else {
        id = 0x404;
        if (D_00351670 > 0) r = func_001db5a8(D_0036df78[D_00351670 - 1]);
    }
    if (r != 0) {
        func_001b4198(r, D_0034e948, a);
    }
    func_001890a8(D_0032e020, id);
    addcount_w8017(1, 0);
    D_01d498b0++;
    a->fn = func_001c6850;
    a->vel = vscale(*v, 60.0f);
    a->vel.y = -30.0f;
    a->vel.w = 14.0f;
    a->p50 = 20;
}
}  // namespace n001c6900

