#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fmatrix.hpp"

// ---- 0011b3f8 gap: identity matrix address
namespace n0011b3f8 {
extern u8 D_003478f0 asm("D_003478f0");
void* func_0011b3f8(void) asm("func_0011b3f8");
void* func_0011b3f8(void) {
    return &D_003478f0;
}
}  // namespace n0011b3f8

// ---- 0011b408 from src/anon/batch_w269.cpp
namespace n0011b408 {
#define QCOPY269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV269 {
    f32 x, y, z, w;
    QV269() {}
    QV269(const QV269& o) { QCOPY269(this, &o); }
    QV269& operator=(const QV269& o) { if (this != &o) QCOPY269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline void normalize269(QV269* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
}
#define QCOPYL269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct LV269 {
    f32 x, y, z, w;
    LV269() {}
    LV269(const LV269& o) { QCOPYL269(this, &o); }
    LV269& operator=(const LV269& o) { if (this != &o) QCOPYL269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline LV269 operator*(const LV269& a, f32 k) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline LV269 operator+(const LV269& a, const LV269& b) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct NM269 {
    f32 m[16];
    NM269() {}
    NM269& operator=(const NM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0011b6a8(f32*) asm("func_0011b6a8");
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
void func_0011b408(f32* m, const QV269* a) asm("func_0011b408");
void func_0011b408(f32* m, const QV269* a) {
    func_0011b6a8(m);
    QV269 v;
    v = *a;
    normalize269(&v);
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = sinf(a->w);
    f32 c = cosf(a->w);
    f32 t = 1.0f - c;
    f32 xy = x * y, yz = y * z, zx = z * x;
    f32 xs = x * s, ys = y * s, zs = z * s;
    m[0] = x * x * t + c;
    m[1] = xy * t + zs;
    m[2] = zx * t - ys;
    m[4] = xy * t - zs;
    m[5] = y * y * t + c;
    m[6] = yz * t + xs;
    m[8] = zx * t + ys;
    m[9] = yz * t - xs;
    m[10] = z * z * t + c;
}
}  // namespace n0011b408

// ---- 0011b558 from src/anon/batch_w269.cpp
namespace n0011b558 {
#define QCOPY269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV269 {
    f32 x, y, z, w;
    QV269() {}
    QV269(const QV269& o) { QCOPY269(this, &o); }
    QV269& operator=(const QV269& o) { if (this != &o) QCOPY269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline void normalize269(QV269* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
}
#define QCOPYL269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct LV269 {
    f32 x, y, z, w;
    LV269() {}
    LV269(const LV269& o) { QCOPYL269(this, &o); }
    LV269& operator=(const LV269& o) { if (this != &o) QCOPYL269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline LV269 operator*(const LV269& a, f32 k) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline LV269 operator+(const LV269& a, const LV269& b) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct NM269 {
    f32 m[16];
    NM269() {}
    NM269& operator=(const NM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0011b6a8(f32*) asm("func_0011b6a8");
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
void func_0011b558(f32* m, const QV269* a) asm("func_0011b558");
void func_0011b558(f32* m, const QV269* a) {
    func_0011b6a8(m);
    QV269 v;
    v = *a;
    normalize269(&v);
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = sinf(a->w);
    f32 c = cosf(a->w);
    f32 t = 1.0f - c;
    f32 xy = x * y, yz = y * z, zx = z * x;
    f32 xs = x * s, ys = y * s, zs = z * s;
    m[0] = x * x * t + c;
    m[1] = xy * t + zs;
    m[2] = zx * t - ys;
    m[4] = xy * t - zs;
    m[5] = y * y * t + c;
    m[6] = yz * t + xs;
    m[8] = zx * t + ys;
    m[9] = yz * t - xs;
    m[10] = z * z * t + c;
}
}  // namespace n0011b558

// ---- 0011b6a8 from src/anon/batch_w15.cpp
namespace n0011b6a8 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_0011b6a8_impl(void* dst) asm("_Z13func_0011b6a8Pv");
extern Q16 D_003478f0[4] asm("D_003478f0");
void func_0011b6a8_impl(void* dst) {
    asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t"
                 ".set reorder"
                 : : "r"(dst), "r"(D_003478f0) : "$8", "$9", "$10", "$11", "memory");
}
}  // namespace n0011b6a8

// ---- 0011b6d8 from src/kn/fmatrix.cpp (rotateX/Y/Z)
namespace kn {
extern "C" f32 func_0011c050(...);  // float_bucket_index
extern "C" u32 sceVu0RotMatrixX(...);

u32 FMatrix::rotateX(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();  // float_bucket_index
    ((u32 (*)(f32, u32, u32))sceVu0RotMatrixX)(f0, s0, s0);
    return s0;
}

extern "C" u32 sceVu0RotMatrixY(...);
extern "C" u32 sceVu0RotMatrixZ(...);

u32 FMatrix::rotateY(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();  // float_bucket_index
    ((u32 (*)(f32, u32, u32))sceVu0RotMatrixY)(f0, s0, s0);
    return s0;
}

u32 FMatrix::rotateZ(f32 a1) {
    u32 s0 = (u32)this;
    if (a1 == 0.0f) return s0;
    f32 f0 = func_0011c050();  // float_bucket_index
    ((u32 (*)(f32, u32, u32))sceVu0RotMatrixZ)(f0, s0, s0);
    return s0;
}
}  // namespace kn

// ---- 0011b720 (in 0011b6d8 block)

// ---- 0011b768 (in 0011b6d8 block)

// ---- 0011b7b0 from src/anon/auto80_199_queue.cpp
namespace n0011b7b0 {
u32 func_0011b7b0(u32 a0, f32* a1) asm("_Z13func_0011b7b0jPf");
u32 func_0011b7b0(u32 a0, f32* a1) {
    f32 zero = 0.0f;

    f32 v = a1[0];
    if (v != zero) {
        v = func_0011c050(v);                       
        ((u32(*)(u32, u32, f32))sceVu0RotMatrixX)(a0, a0, v);
    }

    v = a1[1];
    if (v != zero) {
        v = func_0011c050(v);                       
        ((u32(*)(u32, u32, f32))sceVu0RotMatrixY)(a0, a0, v);
    }

    v = a1[2];
    if (v != zero) {
        v = func_0011c050(v);                       
        ((u32(*)(u32, u32, f32))sceVu0RotMatrixZ)(a0, a0, v);
    }

    return a0;
}
}  // namespace n0011b7b0

// ---- 0011b868 from src/anon/auto80_199_queue.cpp
namespace n0011b868 {
u32 func_0011b868(u32 a0, f32* a1) asm("_Z13func_0011b868jPf");
u32 func_0011b868(u32 a0, f32* a1) {
    f32 v[3];
    v[0] = func_0011c050(a1[0]);                       
    v[1] = func_0011c050(a1[1]);                       
    v[2] = func_0011c050(a1[2]);                       
    sceVu0RotMatrix(a0, a0, v);
    return a0;
}
}  // namespace n0011b868

// ---- 0011b8d0 from src/anon/batch_w299.cpp
namespace n0011b8d0 {
struct V299 {
    f32 x, y, z, w;
    V299() {}
    V299& operator=(const V299& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V299 operator-(const V299& a, const V299& b) {
    V299 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct M299 {
    f32 m[4][4];
    M299& operator=(const M299& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void MulM299(M299* d, const M299* a, const M299* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
void func_0011b6a8(void*) asm("_Z13func_0011b6a8Pv");
M299* func_0011b8d0(M299* m, const V299& axis, f32 ang) asm("func_0011b8d0");
M299* func_0011b8d0(M299* m, const V299& axis, f32 ang) {
    V299 v;
    v = axis;
    v.Normalize();
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = sinf(ang);
    f32 c = cosf(ang);
    M299 r;
    func_0011b6a8(&r);
    f32 t = 1.0f - c;
    r.m[0][0] = x * x * t + c;
    r.m[0][1] = x * y * t + z * s;
    r.m[0][2] = x * z * t - y * s;
    r.m[1][0] = x * y * t - z * s;
    r.m[1][1] = y * y * t + c;
    r.m[1][2] = y * z * t + x * s;
    r.m[2][0] = x * z * t + y * s;
    r.m[2][1] = y * z * t - x * s;
    r.m[2][2] = z * z * t + c;
    M299 tmp;
    MulM299(&tmp, &r, m);
    *m = tmp;
    return m;
}
}  // namespace n0011b8d0

// ---- 0011bac8 from src/anon/batch_w1649.cpp
namespace n0011bac8 {
struct W1649Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1649Mtx { W1649Vec r[4]; };
f32 func_0011c050(f32) asm("func_0011c050");
f32 W1649_asinf(f32) asm("func_002f8ab8");
f32 W1649_atan2(f32, f32) asm("f_atan2f");
static inline f32 W1649Dot(const W1649Vec* a, const W1649Vec* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
void func_0011bac8(W1649Mtx* m, W1649Vec* prev) asm("func_0011bac8");
void func_0011bac8(W1649Mtx* m, W1649Vec* prev)
{
    W1649Vec d0, d1, a;
    f32 s = m->r[0].z;
    if (s < -1.0f) s = -1.0f; else if (s > 1.0f) s = 1.0f;
    if (__builtin_sqrtf(m->r[0].x * m->r[0].x + m->r[0].y * m->r[0].y) > 1.9073486328125e-06f) {
        a.z = W1649_atan2(m->r[0].y, m->r[0].x);
        a.y = W1649_asinf(-s);
        a.x = W1649_atan2(m->r[1].z, m->r[2].z);
    } else {
        if (s > 0.0f) {
            a.x = W1649_atan2(-m->r[1].x, m->r[1].y) * 0.5f;
            a.y = W1649_asinf(-s);
            a.z = a.x;
        } else {
            a.x = W1649_atan2(m->r[1].x, m->r[1].y) * 0.5f;
            a.y = W1649_asinf(-s);
            a.z = -a.x;
        }
        if (s >= 0.0f) a.z = a.x; else a.z = -a.x;
    }
    W1649Vec* p1 = &d1;
    d0.x = func_0011c050(a.x - prev->x);
    d0.y = func_0011c050(a.y - prev->y);
    d0.z = func_0011c050(a.z - prev->z);
    a.x += 3.14159274f;
    a.z += 3.14159274f;
    a.y = 3.14159274f - a.y;
    d1.x = func_0011c050(a.x - prev->x);
    d1.y = func_0011c050(a.y - prev->y);
    d1.z = func_0011c050(a.z - prev->z);
    if (W1649Dot(&d0, &d0) <= W1649Dot(p1, p1)) {
        prev->x = d0.x + prev->x; prev->y = d0.y + prev->y; prev->z = d0.z + prev->z;
    } else {
        prev->x = d1.x + prev->x; prev->y = d1.y + prev->y; prev->z = d1.z + prev->z;
    }
}
}  // namespace n0011bac8

// ---- 0011bd70 from src/anon/batch_w24.cpp
namespace n0011bd70 {
f32 func_0011bd70(f32* m) asm("func_0011bd70");
f32 func_0011bd70(f32* m) {             
    f32 a = m[4] * m[8] - m[5] * m[7];
    f32 b = m[3] * m[8] - m[5] * m[6];
    f32 c = m[3] * m[7] - m[4] * m[6];
    return m[0] * a - m[1] * b + m[2] * c;
}
}  // namespace n0011bd70

// ---- 0011bdc0 from src/anon/auto80_199_queue.cpp
namespace n0011bdc0 {
f32 func_0011bdc0(f32* a0, u32 a1, u32 a2) asm("_Z13func_0011bdc0Pfjj");
f32 func_0011bdc0(f32* a0, u32 a1, u32 a2) {
    f32 m[9];
    s32 t3 = 0;
    s32 t2 = 0;

    while (t3 < 4) {
        if ((u32)t3 != a1) {
            s32 t4 = 0;
            u32 t7 = ((u32)t3 << 4);
            f32* t6 = (f32*)(t7 + (u32)a0);
            f32* t5 = (f32*)(t2 + (u32)m);
            while (t4 < 4) {
                if ((u32)t4 != a2) {
                    *t5 = *t6;
                    t5 = t5 + 1;
                }
                t4 = t4 + 1;
                t6 = t6 + 1;
            }
            t2 = t2 + 12;
        }
        t3 = t3 + 1;
    }

    if (((a1 + a2) & 1) != 0) {
        return -func_0011bd70(m);
    }
    return func_0011bd70(m);
}
}  // namespace n0011bdc0

// ---- 0011be50 from src/anon/batch_w269.cpp
namespace n0011be50 {
#define QCOPY4_269(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct RV269 {
    f32 v[4];
    RV269& operator*=(f32 k) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M269 {
    RV269 r[4];
    M269() {}
    M269& operator=(const M269& o) { if (this != &o) QCOPY4_269(this, &o); return *this; }
} __attribute__((aligned(16)));
#define QCOPYL269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct LV269 {
    f32 x, y, z, w;
    LV269() {}
    LV269(const LV269& o) { QCOPYL269(this, &o); }
    LV269& operator=(const LV269& o) { if (this != &o) QCOPYL269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline LV269 operator*(const LV269& a, f32 k) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline LV269 operator+(const LV269& a, const LV269& b) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct NM269 {
    f32 m[16];
    NM269() {}
    NM269& operator=(const NM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
f32 func_0011bdc0(M269*, s32, s32) asm("func_0011bdc0");
f32 func_0011be50(M269* m) asm("func_0011be50");
f32 func_0011be50(M269* m) {
    M269 t;
    s32 i, j;
    for (i = 0; i < 4; i++) {
        f32* p = t.r[i].v; for (j = 0; j < 4; j++) { *p++ = func_0011bdc0(m, j, i);
        }
    }
    f32 det = 0.0f;
    for (i = 0; i < 4; i++) det += t.r[i].v[0] * m->r[0].v[i];
    *m = t;
    f32 inv = 1.0f / det;
    m->r[0] *= inv;
    m->r[1] *= inv;
    m->r[2] *= inv;
    m->r[3] *= inv;
    return det;
}
}  // namespace n0011be50

// ---- 0011bfa0 from src/anon/batch_wcx2.cpp
namespace n0011bfa0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
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
#define QCOPY_11bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V11bfa0 {
    f32 x, y, z, w;
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V11bfa0& operator=(const V11bfa0& o) { if (this != &o) QCOPY_11bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
struct M11bfa0 { V11bfa0 r[4]; };
extern M11bfa0 D_003478f0 asm("D_003478f0");
void wtarget_0011bfa0(s32 init, s32 prio, u32, u32) asm("_Z16wtarget_0011bfa0jjjj");
void wtarget_0011bfa0(s32 init, s32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        M11bfa0 m;
        m.r[0].Set(1.0f, 0.0f, 0.0f, 0.0f);
        m.r[1].Set(0.0f, 1.0f, 0.0f, 0.0f);
        m.r[2].Set(0.0f, 0.0f, 1.0f, 0.0f);
        m.r[3].Set(0.0f, 0.0f, 0.0f, 1.0f);
        QCOPY_11bfa0(&D_003478f0.r[0], &m.r[0]);
        QCOPY_11bfa0(&D_003478f0.r[1], &m.r[1]);
        QCOPY_11bfa0(&D_003478f0.r[2], &m.r[2]);
        QCOPY_11bfa0(&D_003478f0.r[3], &m.r[3]);
    }
}
}  // namespace n0011bfa0

// ---- 0011c050 from src/anon/batch_w226.cpp
namespace n0011c050 {
float func_0011c050(float x) asm("func_0011c050");
float func_0011c050(float x) {                       
    if (x > 0.0f) {
        if (x > 3.14159274f) { while (x > 3.14159274f) x -= 6.2831855f; }
    } else if (x < -3.14159274f) { while (x < -3.14159274f) x += 6.2831855f; }
    return x;
}
}  // namespace n0011c050

// ---- 0011c0e8 gap: _GLOBAL__I_ stub
namespace n0011c0e8 {
u32 wtarget_0011bfa0(u32, u32, u32, u32) asm("_Z16wtarget_0011bfa0jjjj");
u32 func_0011c0e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0011c0e8");
u32 func_0011c0e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return wtarget_0011bfa0(1, 0x0000ffffu, a2, a3);
}
}  // namespace n0011c0e8

// ---- 0011c108 gap: _GLOBAL__D_ stub
namespace n0011c108 {
u32 wtarget_0011bfa0(u32, u32, u32, u32) asm("_Z16wtarget_0011bfa0jjjj");
u32 func_0011c108(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0011c108");
u32 func_0011c108(u32 a0, u32 a1, u32 a2, u32 a3) {
    return wtarget_0011bfa0(0, 0x0000ffffu, a2, a3);
}
}  // namespace n0011c108

