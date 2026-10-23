#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QV ScaleQ(const QV& a, f32 k) {
    QV r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline void ScaleQIn(QV* a, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline void AddIn(QV* a, const QV& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "r"(&b) : "memory");
}
static inline QV SubQ(const QV& a, const QV& b) {
    QV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 NormQ(QV* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct CB470 {
    QV pos;
    u32 f10;
    u8 pad14[0x2c];
    f32 t;
    u8 pad44[8];
    s32* f4c;
    u8 pad50[0x10];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0x14];
    QV accel;
    QV vel;
};
extern "C" {
extern void* D_00361f60;
extern f32 D_00349e10;
extern f32 D_00351fd8;
void func_001cb088(void);
void func_001ca910(CB470*);
bool func_001ca9c0(CB470*);
s32 func_001cbab0(CB470*);
void* func_002d1260(void);
QV* func_002d1f30(void*);
typedef void* (*CB470Fa0)(void*);
typedef void (*CB470F28)(void*, s32, s32);


s32 u_call4_001cb470(CB470* o) asm("_Z16u_call4_001cb470jjjj");
/* 001cb470: projectile step - integrate velocity, follow the camera offset, and when the hit test fires
   re-aim at the player (vcall +0xa0, +48 = position), switch the update callback and notify the manager. */
s32 u_call4_001cb470(CB470* o) {
    if (o->t >= o->f60) {
        QV v = o->vel;
        ScaleQIn(&v, v.w);
        AddIn(&o->pos, ScaleQ(v, D_00349e10));
        AddIn(&v, ScaleQ(o->accel, D_00349e10));
        v.w = NormQ(&v);
        o->vel = v;
    }
    if (D_00361f60) {
        AddIn(&o->pos, *func_002d1f30(D_00361f60));
    }
    if (o->t > o->f68 && func_001cbab0(o)) {
        {
            QV* pv = &o->vel;
            void* x = func_002d1260();
            *pv = SubQ(o->pos, *(QV*)((u8*)((CB470Fa0)(*(void***)x)[0xa0 / 4])(x) + 48));
            f32 len = NormQ(pv);
            o->vel.w = len;
            s32* q = o->f4c;
            o->t = D_00351fd8;
            o->f10 = (u32)func_001cb088;
            ((CB470F28)(*(void***)D_00361f60)[0x28 / 4])(D_00361f60, 1, *q);
            func_001ca910(o);
            return 1;
        }
    }
    o->t += D_00349e10;
    if (o->t < o->f64) return 1;
    return !func_001ca9c0(o);
}
}
