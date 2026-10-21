#include "../common/types.h"
#define QCOPY_x(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_x(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV_x {
    f32 x, y, z, w;
    QV_x() {}
    QV_x(const QV_x& o) { QCOPY_x(this, &o); }
    QV_x& operator=(const QV_x& o) { if (this != &o) QCOPY_x(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM_x {
    QV_x r[4];
    QM_x() {}
    QM_x(const QM_x& o) { QCOPY4_x(this, &o); }
    QM_x& operator=(const QM_x& o) { if (this != &o) QCOPY4_x(this, &o); return *this; }
    QV_x operator*(const QV_x& v) const {
        QV_x o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Obj_x { u8 pad[0xb0]; QM_x m; };
struct Ent_b { u16 id; u16 pad; };
struct Cmd_b { u16 op; u16 n; Ent_b e[1]; };
struct Obj_b { u8 b0, b1, b2, b3; };
extern "C" {
extern f32 D_00362e60;
f32 func_002f8a18(f32);
f32 func_002f8870(f32);
Obj_b* func_001b6d70(u16);
void func_001b6d88(Obj_b*, s32);
void func_001b8bf8(Cmd_b*, s32);
void func_001b8c70(Cmd_b*, s32);
void func_001c3670(u16);
void func_001c36e8(u16);
void func_001c8ec0(u16);
extern u8 D_0032fcc9;
extern u8 D_01d48d94;

void func_002e2a30(Obj_x* o, QV_x* v, const QV_x* lo, const QV_x* hi)
{
    QM_x inv = o->m;
    inv.invOrtho();
    v->w = 1.0f;
    *v = inv * *v;
    f32 t = func_002f8a18(D_00362e60 * 0.5f * 0.017453292f);
    t = t * func_002f8870(v->z);
    f32 h = t * 4.0f / 3.0f;
    f32 a = h - hi->x;
    if (a < v->x) v->x = a;
    a = lo->x - h;
    if (v->x < a) v->x = a;
    f32 b = t - hi->y;
    if (b < v->y) v->y = b;
    f32 c = lo->y - t;
    if (v->y < c) v->y = c;
    *v = o->m * *v;
}

s32 func_001b89d0(Cmd_b* p)
{
    s32 i;
    Obj_b* o;
    switch (p->op) {
    case 1: func_001b8bf8(p, 0); break;
    case 2: func_001b8bf8(p, 1); break;
    case 3: func_001b8bf8(p, 2); break;
    case 4:
        for (i = 0; i < p->n; i++) {
            o = func_001b6d70(p->e[i].id);
            func_001b6d88(o, 2);
            o->b3 &= ~2;
        }
        break;
    case 5:
        for (i = 0; i < p->n; i++) {
            o = func_001b6d70(p->e[i].id);
            o->b3 |= 2;
        }
        break;
    case 6:
        for (i = 0; i < p->n; i++) {
            o = func_001b6d70(p->e[i].id);
            o->b3 |= 1;
        }
        break;
    case 7: func_001b8bf8(p, 3); break;
    case 8: func_001b8c70(p, 0); break;
    case 9: func_001b8c70(p, 1); break;
    case 10: func_001b8c70(p, 2); break;
    case 11: func_001b8c70(p, 3); break;
    case 12:
        for (i = 0; i < p->n; i++)
            func_001c3670(p->e[i].id);
        break;
    case 13:
        for (i = 0; i < p->n; i++)
            func_001c36e8(p->e[i].id);
        break;
    case 15:
        if (D_01d48d94)
            func_001c8ec0(p->e[0].id);
        D_0032fcc9 = *(u8*)&p->e[0];
        break;
    }
    return 1;
}
}
