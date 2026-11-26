// Linked unit 0x1c7148-0x1c7b88: rest of the file that src/anon/unit_001c6e58.cpp starts (effect
// objects that fly out of D_01d498d0, their step callbacks, and the static init + I/D stubs).
// The .bss globals (D_01d498c0, D_01d498c4, D_01d498d0) stay extern (symbols.ld provides them);
// the static init and both stubs are plain functions, so the retail .ctors entry stays as it is.
#include "../common/types.h"

struct NoTail { ~NoTail() {} };

// 001c7148 (from src/anon/batch_w49.cpp)
namespace n001c7148 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M1c7148 { Vq a, b; };
extern M1c7148 D_01d498d0 asm("D_01d498d0");
void func_00143928(M1c7148*) asm("func_00143928");
void func_001c7148(u8* p) asm("func_001c7148");
void func_001c7148(u8* p) {
    M1c7148* m = &D_01d498d0;
    m->a = *(Vq*)p;
    m->a.y += *(f32*)(*(u8**)(p + 76) + 4);
    m->a.w = 1.0f;
    m->b = *(Vq*)(p + 48);
    m->b.w = 1.0f;
    func_00143928(m);
}
} // n001c7148

// 001c71b8 (from src/anon/tiny_auto80_queue.cpp)
namespace n001c71b8 {
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001c71b8(u8* a0) asm("func_001c71b8");
s32 func_001c71b8(u8* a0) {
    if ((*(u32*)(a0 + 40) & 4) != 0) {
        return 1;
    }

    f32 f1 = *(f32*)(a0 + 64) - D_00349e10;
    *(f32*)(a0 + 64) = f1;

    if (0.0f < f1) {
        return 1;
    }
    return 0;
}
} // n001c71b8

// 001c71f8 (from src/anon/batch_w1972.cpp)
namespace n001c71f8 {
struct W1972Vq {
    f32 x, y, z, w;
    W1972Vq& operator=(const W1972Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1972Glob { W1972Vq a, b, c, res; u8 pad40[0x30]; u64 flags; };
struct W1972Own { u8 pad0[4]; f32 y; s32 f8; };
struct W1972Ent {
    W1972Vq pos;        // 0x00
    u32 state;          // 0x10
    u8 pad14[0x14];
    u32 flags;          // 0x28
    u8 pad2c[4];
    W1972Vq vel;        // 0x30
    u8 pad40[4];
    u8 cnt;             // 0x44
    u8 pad45[7];
    W1972Own* own;      // 0x4c
};

extern W1972Glob D_01d498d0 asm("D_01d498d0");
extern u8 D_001c7520[] asm("func_001c7520");

static inline W1972Vq w1972_vsub(const W1972Vq& a, const W1972Vq& b) {
    W1972Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void w1972_vzero(W1972Vq* v) {
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory");
}

void func_001c7148(W1972Ent*) asm("func_001c7148");
void func_002bc188(s32, W1972Ent*) asm("func_002bc188");
f32 fabsf(f32) asm("fabsf");

void func_001c71f8(W1972Ent* o, f32 k) asm("func_001c71f8");
void func_001c71f8(W1972Ent* o, f32 k) {
    func_001c7148(o);
    f32 vy = o->vel.y;
    if (0.0f <= vy && !(D_01d498d0.flags & (1ULL << 32))) {
        if (5.0f < vy) {
            o->vel.y = vy * k;
            if (o->cnt < 2) func_002bc188(o->own->f8, o);
            o->cnt++;
        } else {
            w1972_vzero(&o->vel);
            o->state = (u32)D_001c7520;
        }
    }
    W1972Vq d;
    d = w1972_vsub(D_01d498d0.res, D_01d498d0.a);
    f32 lim = 0.1f;
    if (lim < fabsf(d.x - o->vel.x)) o->vel.x = -o->vel.x;
    if (lim < fabsf(d.z - o->vel.z)) o->vel.z = -o->vel.z;
    o->pos = D_01d498d0.res;
    o->pos.y -= o->own->y;
    f32 v = o->vel.y + 3.0f;
    o->vel.y = v;
    if (50.0f < v) o->vel.y = 50.0f;
    o->vel.x *= 0.95f;
    o->vel.z *= 0.95f;
    if (0.0f <= o->vel.y) o->flags |= 1;
}
} // n001c71f8

// 001c73e0 (from src/anon/batch_wlit.cpp)
namespace n001c73e0 {
u8 func_001c71f8(u32 p, f32 f) asm("func_001c71f8");
u8 func_001c7440(u32 p, u32 z) asm("func_001c7440");
u32 u_call4_001c73e0(u32 p, u32, u32, u32) asm("_Z16u_call4_001c73e0jjjj");
u32 u_call4_001c73e0(u32 p, u32, u32, u32) { func_001c71f8(p, -0.8f); return func_001c7440(p, 0); }
} // n001c73e0

// 001c7420 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001c7420 {
u32 func_001c73e0(u32, u32, u32, u32) asm("_Z16u_call4_001c73e0jjjj");
u32 func_001c7420(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c7420");
u32 func_001c7420(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001c73e0)(u32, u32, u32, u32) = func_001c73e0;
    r2 = fp_call4_001c73e0(r4, r5, r6, r7);
    return r2;
}
} // n001c7420

// 001c7440 (from src/anon/batch_w90.cpp)
// Fade-in alpha while timer < 12, otherwise tick a countdown and call a hook.
namespace n001c7440 {
struct VObj { void** vt; };
void func_001c7148(void*) asm("func_001c7148");
void func_001c71b8(void*) asm("func_001c71b8");
void func_001c7420(void) asm("func_001c7420");
extern u64 D_01d49940 asm("D_01d49940");
void func_001c7440(u8* self, u8 flag) asm("func_001c7440");
void func_001c7440(u8* self, u8 flag)
{
    NoTail g;
    f32 lim = 12.0f;
    f32 t = *(f32*)(self + 64);
    if (t < lim) {
        self[22] = (s32)(t * 255.0f / lim);
    } else {
        if (flag) {
            if (--self[69] == 0) {
                func_001c7148(self);
                if (D_01d49940 & (1ULL << 32)) *(u32*)(self + 16) = (u32)func_001c7420;
                self[69] = 30;
            }
        }
        VObj* o = *(VObj**)(self + 80);
        ((void (*)(void*, void*))o->vt[22])(o, self);
    }
    func_001c71b8(self);
}
} // n001c7440

// 001c7520 (gap, never written before): step callback, func_001c7440(self, 1).
namespace n001c7520 {
void func_001c7440(u8* self, u8 flag) asm("func_001c7440");
void func_001c7520(u8* self) asm("func_001c7520");
void func_001c7520(u8* self) {
    NoTail g;
    func_001c7440(self, 1);
}
} // n001c7520

// 001c7540 (from src/anon/batch_w289.cpp)
namespace n001c7540 {
#define QCOPY289(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY289(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY289(this, &o);
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
#undef QCOPY289
static inline QWord Add(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline QWord MulV(const QMat& m, const QWord& v)
{
    QWord r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
extern f32 D_01d498c4 asm("D_01d498c4");
extern f32 D_00349e10 asm("D_00349e10");
s32 func_0019ba60(u32) asm("func_0019ba60");
void func_0011b6a8(QMat*) asm("func_0011b6a8");
QMat* func_0011b720(QMat*, f32) asm("func_0011b720");
QWord func_0016be98(u32) asm("func_0016be98");
s32 func_001c7540(u8* o) asm("func_001c7540");
s32 func_001c7540(u8* o) {
    f32 t = *(f32*)(o + 64) - D_00349e10;
    *(f32*)(o + 64) = t;
    if (t <= 0.0f || !func_0019ba60(*(u32*)(o + 72))) return 0;
    f32 w = *(f32*)(o + 60);
    f32 r = *(f32*)(o + 64) / 40.0f;
    QMat m;
    func_0011b6a8(&m);
    f32 s = 30.0f / (w * r);
    m = *func_0011b720(&m, s < D_01d498c4 ? s : D_01d498c4);
    *(QWord*)(o + 48) = MulV(m, *(QWord*)(o + 48));
    *(f32*)(o + 60) = w;
    *(QWord*)o = Add(Scale(*(QWord*)(o + 48), w * r), func_0016be98(*(u32*)(o + 72)));
    *(u8*)(o + 22) = (s32)(r * 255.0f);
    return 1;
}
} // n001c7540

// 001c7700 (gap, never written before): step callback, func_001c7540(self).
namespace n001c7700 {
u32 func_001c7540(u32, u32, u32, u32) asm("func_001c7540");
u32 func_001c7700(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c7700");
u32 func_001c7700(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 (*fp)(u32, u32, u32, u32) = func_001c7540;
    return fp(a0, a1, a2, a3);
}
} // n001c7700

// 001c7720 (from src/anon/batch_w3777.cpp)
// Steers a homing object: counts f40 down, turns v30 toward the target with a
// rotation limited by 150/(speed*t), then sets pos from v30 scaled by speed*t plus the target.
// Partial asm: the "+f"(w) tie stops gcc reusing the first w*t product (the original multiplies twice),
// the "+r"(pm) tie keeps &m in s0 as the original does, and a is pinned to $f0.
namespace n001c7720 {
#define QCOPY1577(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_1577(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV1577 {
    f32 x, y, z, w;
    QV1577() {}
    QV1577(const QV1577& o) { QCOPY1577(this, &o); }
    QV1577& operator=(const QV1577& o) { if (this != &o) QCOPY1577(this, &o); return *this; }
    QV1577 operator*(f32 s) const {
        QV1577 d;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(this), "f"(s) : "$8", "memory");
        return d;
    }
    QV1577 operator+(const QV1577& b) const {
        QV1577 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct QM1577 {
    QV1577 r[4];
    QM1577() {}
    QM1577& operator=(const QM1577& o) { if (this != &o) QCOPY4_1577(this, &o); return *this; }
    QV1577 operator*(const QV1577& v) const {
        QV1577 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
#undef QCOPY1577
#undef QCOPY4_1577
struct Obj1c7720 {
    QV1577 pos;
    u8 pad10[6];
    u8 b16;
    u8 pad17[0x19];
    QV1577 v30;
    f32 f40;
    u32 pad44;
    u32 p48;
};
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_01d498c0 asm("D_01d498c0");
void func_0011b6a8(QM1577*) asm("func_0011b6a8");
QM1577* func_0011b720(QM1577*, f32) asm("func_0011b720");
QV1577 func_0016be98(u32) asm("func_0016be98");
s32 func_0019ba60(u32) asm("func_0019ba60");
s32 func_001c7720(Obj1c7720* p) asm("func_001c7720");
s32 func_001c7720(Obj1c7720* p) {
    if ((p->f40 -= D_00349e10) <= 0.0f || !func_0019ba60(p->p48)) return 0;
    f32 w = p->v30.w;
    f32 t = p->f40 / 80.0f;
    QM1577 m;
    QM1577* pm = &m;
    func_0011b6a8(pm);
    f32 x = 150.0f / (w * t);
    f32 a = (x < D_01d498c0) ? x : D_01d498c0;
    *pm = *func_0011b720(&m, a);
    p->v30 = m * p->v30;
    p->v30.w = w;
    p->pos = p->v30 * (w * t) + func_0016be98(p->p48);
    p->b16 = (s32)(t * 255.0f);
    return 1;
}
} // n001c7720

// 001c78e0 (gap, never written before): step callback, func_001c7720(self).
namespace n001c78e0 {
u32 func_001c7720(u32, u32, u32, u32) asm("func_001c7720");
u32 func_001c78e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c78e0");
u32 func_001c78e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 (*fp)(u32, u32, u32, u32) = func_001c7720;
    return fp(a0, a1, a2, a3);
}
} // n001c78e0

// 001c7900 (from src/anon/tiny_auto80_solver.cpp)
namespace n001c7900 {
u32 func_001c7900(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001c7900");
u32 func_001c7900(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 obj = *(u32*)(a0 + 80);
    void (**vt)() = *(void (***)())obj;
    ((void (*)(u32, u32, u32, u32, u32, u32, u32, u32))vt[22])(obj, a0, a2, a3, a4, a5, a6, a7);
    return 1;
}
} // n001c7900

// 001c7930 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001c7930 {
u32 func_001c7900(u32, u32, u32, u32) asm("func_001c7900");
u32 func_001c7930(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c7930");
u32 func_001c7930(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_001c7900)(u32, u32, u32, u32) = func_001c7900;
    r2 = fp_call4_001c7900(r4, r5, r6, r7);
    return r2;
}
} // n001c7930

// 001c7950 (from src/anon/batch_w30.cpp)
namespace n001c7950 {
s32 func_001a4ff8(void*, void*) asm("func_001a4ff8");
struct F28 {
    u8 pad[0x28];
    u32 on : 1;
};
s32 func_001c7950(u8* p, void* o) asm("func_001c7950");
s32 func_001c7950(u8* p, void* o) {  // copy_quad_if_flag
    if (!((F28*)p)->on) return 0;
    f32 v[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(p) : "$8", "memory");
    v[1] += *(f32*)(*(u8**)(p + 0x4c) + 4);
    return func_001a4ff8(o, v);
}
} // n001c7950

// 001c79a0 (from src/anon/batch_w95.cpp)
namespace n001c79a0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator-(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(Vq& d) {
    f32 len;
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, %0\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&d) : "$8", "memory");
    return len;
}
struct Homing { Vq pos; void (*step)(void); u8 pad20[28]; Vq dir; f32 speed; u32 pad68; u32 target; u32* owner; };
Vq func_0016be98(u32) asm("func_0016be98");
void func_002bc188(u32, Vq*) asm("func_002bc188");
void func_001c7700(void) asm("func_001c7700");
void func_001c78e0(void) asm("func_001c78e0");
void func_001c79a0(Homing* h, u32 target, s32 mode) asm("func_001c79a0");
void func_001c79a0(Homing* h, u32 target, s32 mode) {
    h->target = target;
    Vq v;
    v = func_0016be98(target);
    h->dir = h->pos - v;
    h->dir.w = Normalize(h->dir);
    switch (mode) {
    case 0:
        h->speed = 40.0f;
        h->step = func_001c7700;
        break;
    case 1:
        h->speed = 80.0f;
        h->step = func_001c78e0;
        break;
    }
    func_002bc188(h->owner[3], &v);
}
} // n001c79a0

// 001c7ab8 (from src/anon/batch_w2032_g.cpp): static initializer (initialize, priority)
namespace n001c7ab8 {
extern f32 D_01d498c0 asm("D_01d498c0");
extern f32 D_01d498c4 asm("D_01d498c4");
extern u8 D_01d498d0 asm("D_01d498d0");
void func_0031b9e0(u8*) asm("func_0031b9e0");
void wtarget_001c7ab8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001c7ab8jjjj");
void wtarget_001c7ab8(u32 a, u32 b, u32, u32) {
    NoTail nt;
    if (b == 0xffff) { if (a == 1) D_01d498c0 = 0.52359873f; }
    if (b == 0xffff) { if (a == 1) D_01d498c4 = 0.5934119f; }
    if (b == 0xffff) { if (a == 1) func_0031b9e0(&D_01d498d0); }
}
} // n001c7ab8

// 001c7b48 _GLOBAL__I_ stub (from src/anon/tiny_wrappers_more.cpp)
namespace n001c7b48 {
u32 func_001c7ab8(u32, u32, u32, u32) asm("_Z16wtarget_001c7ab8jjjj");
u32 func_001c7b48(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c7b48");
u32 func_001c7b48(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c7ab8(0x00000001u, 0x0000ffffu, a2, a3);
}
} // n001c7b48

// 001c7b68 _GLOBAL__D_ stub (gap, never written before)
namespace n001c7b68 {
u32 func_001c7ab8(u32, u32, u32, u32) asm("_Z16wtarget_001c7ab8jjjj");
u32 func_001c7b68(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001c7b68");
u32 func_001c7b68(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001c7ab8(0x00000000u, 0x0000ffffu, a2, a3);
}
} // n001c7b68
