#include "../common/types.h"
struct QV1881 {
    f32 x, y, z, w;
    QV1881() {}
    QV1881(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV1881& operator=(const QV1881& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct QM1881 {
    QV1881 r[4];
    QM1881& operator=(const QM1881& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // VU0 orthonormal matrix inverse (hand-written VU0 macro sequence)
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Src1881 { u8 pad[4]; f32 p[3]; f32 q[3]; u8 pad2[4]; f32 rot; };
struct Obj1881 { void* vt; u8 pad[12]; QM1881 m; QV1881 v; u8 pad2[8]; u32 f68; Src1881* src; };
extern u8 D_00352a20[];
static inline __attribute__((always_inline)) void initv1881(QV1881* v, f32 a, f32 b, f32 c, f32 d) {
    v->x = a;
    v->w = d;
    v->z = c;
    v->y = b;
}
extern "C" {
void func_0011b6a8(QM1881*);
QM1881* func_0011b720(QM1881*, f32);

void func_001daef8(Obj1881* o, Src1881* s) {
    *(u32*)o = (u32)D_00352a20;
    initv1881(&o->v, s->q[0], s->q[1], s->q[2], 0.0f);
    o->f68 = 0;
    o->src = s;
    QV1881 t(s->p[0], s->p[1], s->p[2], 0.0f);
    func_0011b6a8(&o->m);
    o->m = *func_0011b720(&o->m, -s->rot);
    o->m.r[3] = t;
    o->m.r[3].w = 1.0f;
    o->m.invOrtho();
}
}
