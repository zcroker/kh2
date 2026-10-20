#include "../common/types.h"
// VU0 macro matrix*vector (inline asm), 16-byte vector class with lq/sq copy and self-check.
#define QC1770(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV1770 {
    f32 x, y, z, w;
    QV1770() {}
    QV1770(const QV1770& o) { QC1770(this, &o); }
    QV1770& operator=(const QV1770& o) { if (this != &o) QC1770(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1770 {
    QV1770 r[4];
    QV1770 operator*(const QV1770& v) const {
        QV1770 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Ob1770 { u8 pad[16]; QM1770 m; f32 f50; };

extern "C" {
f32 func_001db510(Ob1770* o, const QV1770* p) {
    QV1770 v;
    v = *p;
    v.w = 1.0f;
    v = o->m * v;
    return (v.x + o->f50) / (o->f50 + o->f50);
}

u64 func_00109f58(u32 a0, u32 a1, u8 a2) {
    switch (a0) {
    case 7:
        if (a1 == 0) return 0x8000000044ULL;
    case 1: case 3: case 5:
        if (a2 != 0x80) return 0x8000000044ULL;
        return 42;
    case 11:
        if (a1 == 0) return 0x8000000044ULL;
    case 2: case 4: case 8:
        return 0x8000000044ULL;
    default:
        return 0x44;
    }
}
}
