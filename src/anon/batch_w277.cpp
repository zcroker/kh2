#include "../common/types.h"

namespace w277_a {
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
static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline void Zero(QWord* v)
{
    asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(v) : "memory");
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
extern "C" {
struct Mv {
    u8 pad0[16];
    QWord dir;      // 16
    QWord v2;       // 32
    u8 pad1[320 - 48];
    u8 sub[32];     // 320
    u32 flags160;   // 352
    u8 pad2[2040 - 356];
    u32 flags7f8;   // 2040
};
struct G1f34 { f32 a, b; };
extern G1f34* D_00351f34;
s32 func_001ca448(Mv*);
void func_001ca4a8(Mv*);
void func_0017f540(u8*, s32, f32, f32);
void func_001c9ee8(void* self, Mv* m) {
    s32 mot = 0;
    QWord unused;
    if (func_001ca448(m) && !(m->flags7f8 & 4)) func_001ca4a8(m);
    if (0.0f < m->dir.f[3]) {
        if (m->dir.f[0] < 0.0f) mot = 151;
        else if (0.0f < m->dir.f[0]) mot = 152;
        m->dir = Scale(m->dir, m->dir.f[3]);
    } else {
        Zero(&m->dir);
    }
    if (func_001ca448(m)) {
        m->dir.f[2] += D_00351f34->b;
    } else {
        Zero(&m->dir);
        Zero(&m->v2);
    }
    m->dir.f[3] = Normalize(&m->dir);
    u8* sub = m->sub;
    if (m->flags160 & 4) func_0017f540(sub, mot, 12.0f, 0.0f);
}
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
extern "C" {
extern s32 D_01d498b0;
extern QWord D_00352a60;
extern QWord D_01d49870;
void func_001dbb38(void);
s32 func_00197920(void);
s32 func_001c5f78(void);
void* func_001b9bc8(void*);
s32 func_0016a020(void*);
s32 func_001dbe78(void*, QWord*);
struct Ob { QWord pos; u8 pad[72]; s32 x58; };
s32 func_001c5f90(Ob* o) {
    void* ret = 0;
    QWord v;
    if (1000 - D_01d498b0 < 300) {
        o->x58 = 1000;
        func_001dbb38();
    } else if (func_001c5f78()) {
        s32 cnt = 0;
        while ((ret = func_001b9bc8(ret)) != 0) {
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
}

extern "C" {
QWord func_002cd770(void* p, const QWord* lo, const QWord* hi, f32 t);
void func_002cd518(void* p, f32* d, void* q, QWord* a, QWord* b);
f32 func_002cdb60(void* p, f32* out, void* q, const QWord* lo, const QWord* hi, f32 t0, f32 t1) {
    QWord a = *lo;
    QWord b = *hi;
    f32 d0, d1, mid, r;
    s32 i;
    for (i = 0; i < 33; i++) {
        mid = (t0 + t1) * 0.5f;
        QWord c = func_002cd770(p, lo, hi, mid);
        func_002cd518(p, &d0, q, &a, &c);
        func_002cd518(p, &d1, q, &c, &b);
        if (d0 < d1) { t1 = mid; b = c; r = d1; }
        else { t0 = mid; a = c; r = d0; }
    }
    *out = (t0 + t1) * 0.5f;
    return r;
}
}

}

namespace w277_b {
struct Mtx { f32 m[4][4]; } __attribute__((aligned(16)));
static inline void CopyMtx(Mtx* d, const Mtx* s)
{
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                 : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ScaleRow(f32* r, f32 s)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(r), "f"(s) : "$8", "memory");
}
extern "C" {
struct Cam { s32 x0; s32 type; u8 pad[136]; f32 a; f32 b4; f32 c; };
struct Obj { s32 x0; Cam* cam; };
struct Arg { u8 pad[24]; Obj* owner; };
union UF { f32 f; u8 c; };
extern UF D_00347b70;
void func_00127cf8(void*);
void func_00128480(Obj*, Arg*);
void func_00128b38(Obj*, Arg*, f32);
void func_00130c18(Obj*, f32);
void func_0012d728(Obj*, Arg*, Mtx*, void*, void*);
void func_00129c38(Obj*, Arg*, Mtx*, void*, void*);
void func_00130d28(Obj* o, Arg* a, const Mtx* mtx, void* p3, void* p4, f32 t) {
    func_00127cf8(p4);
    t += o->cam->a * 60.0f / o->cam->c;
    D_00347b70.f = o->cam->a + t * o->cam->c / 60.0f;
    if (a->owner != o) func_00128480(o, a);
    func_00128b38(o, a, t);
    func_00130c18(o, t);
    Mtx m;
    f32* r1 = m.m[1];
    f32* r2 = m.m[2];
    CopyMtx(&m, mtx);
    ScaleRow(r1, -1.0f);
    ScaleRow(r2, -1.0f);
    if (o->cam->type == 1) func_0012d728(o, a, &m, p3, p4);
    else func_00129c38(o, a, &m, p3, p4);
}
}

}

namespace w277_c {
extern "C" {
extern u32 D_003638d0;
void func_001ccaa0(void);
static inline u32 rnd(void) { return D_003638d0 *= 0x10dcd; }
static inline f32 frnd(void) { return (f32)rnd() * 2.3283064365386963e-10f; }
static inline f32 rng(f32 a, f32 b) { return b + frnd() * a; }
struct V4 { f32 x, y, z, w; };
void func_001ccac0(u8* a0, u32 a1) {
    *(u32*)(a0 + 16) = (u32)func_001ccaa0;
    *(u32*)(a0 + 72) = a1;
    V4* v = (V4*)(a0 + 48);
    f32 x = rng(20.0f, -10.0f);
    f32 y = rng(10.0f, -30.0f);
    f32 z = rng(20.0f, -10.0f);
    v->x = x; v->y = y; v->z = z; v->w = 0;
}
}
}
