#include "../common/types.h"
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
extern "C" {
extern f32 D_00349e10;
extern f32 D_01d498c0;
void func_0011b6a8(QM1577*);
QM1577* func_0011b720(QM1577*, f32);
QV1577 func_0016be98(u32);
s32 func_0019ba60(u32);

}

// Steers a homing object: counts f40 down, turns v30 toward the target with a
// rotation limited by 150/(speed*t), then sets pos from v30 scaled by speed*t plus the target.
// Partial asm: the "+f"(w) tie stops gcc reusing the first w*t product (the original multiplies twice),
// the "+r"(pm) tie keeps &m in s0 as the original does, and a is pinned to $f0.
extern "C" {
s32 func_001c7720(Obj1c7720* p) {
    if ((p->f40 -= D_00349e10) <= 0.0f || !func_0019ba60(p->p48)) return 0;
    f32 w = p->v30.w;
    f32 t = p->f40 / 80.0f;
    QM1577 m;
    func_0011b6a8(&m);
    QM1577* pm = &m; asm("" : "+r"(pm) : "m"(m));
    register f32 a asm("$f0") = 150.0f / (w * t);
    asm("" : "+f"(w));
    if (!(a < D_01d498c0)) a = D_01d498c0;
    *pm = *func_0011b720(&m, a);
    p->v30 = m * p->v30;
    p->v30.w = w;
    p->pos = p->v30 * (w * t) + func_0016be98(p->p48);
    p->b16 = (s32)(t * 255.0f);
    return 1;
}
}
