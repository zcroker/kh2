// 002f1480: asm("" : "+r"(o) : "f"(x), "f"(y)) emits no code; one extra read each steers local-alloc (x above the 0.5 constant, y above x).
#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCOPY(this, &o); return *this; }
    QV operator+(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QV operator*(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Obj { f32 sx, sy, sz, pad; f32 f10, f14, p18, p1c; QV pos; };
extern "C" {
s32 func_002fea18(void);
s32 func_00106a60(s32);
void func_00107368(s32, QV*);
f32 func_001074b8(s32);
void func_0011b6a8(QM*);
void sceVu0RotMatrixZ(QM*, QM*, f32);
void func_00107330(s32, f32, f32, f32);
extern f32 D_00349e10;
static inline f32 rnd_h(f32 a) { return (f32)func_002fea18() / 2147483520.0f * a - a * 0.5f; }
static inline f32 rnd_h2(f32 a, f32 s) { return ((f32)func_002fea18() / 2147483520.0f * a - a * 0.5f) * s; }

s32 func_002f1480(Obj* o, f32 s);  // 0x002f1480: definition moved into src/anon/unit_002f12b0.cpp
}
