#include "../common/types.h"
struct NM1567 {
    f32 m[16];
    NM1567() {}
    NM1567& operator=(const NM1567& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
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
struct QV1567 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
extern f32 D_00362e60;
s32 func_00197920(void);
s32 func_00106a18(s32);
void func_00106de8(f32, s32, s32);
void func_00106c08(s32);
u8* func_00106a60(s32);
NM1567 func_002e71a0(s32, u8, s32);
void func_001072d0(u8*, u8*, QV1567*);
void wt1567(u8* a0, u32, u32, u32) asm("_Z16wtarget_002e27c8jjjj");
void wt1567(u8* a0, u32, u32, u32) {
    if (func_00197920() == 0) {
        s32 b = func_00106a18(1);
        func_00106de8(D_00362e60 * 0.017453292f, b, 1);
        func_00106c08(b);
        u8* cam = func_00106a60(1);
        NM1567 m = func_002e71a0(*(s32*)(a0 + 0x6c), (*(u8**)(a0 + 0x64))[8], 1);
        asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(&m), "r"(a0 + 0xf0) : "memory");
        NM1567* d = (NM1567*)(cam + 0x10);
        *d = m;
        QV1567 t;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(cam + 0x40), "r"(cam + 0x30), "r"(&t) : "memory");
        func_001072d0(cam, cam + 0x40, &t);
        d->invOrtho();
    }
}
}

struct QV1567b {
    f32 x, y, z, w;
    QV1567b() {}
    QV1567b(const QV1567b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV1567b& operator=(const QV1567b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct QM1567b {
    QV1567b r[4];
    QV1567b operator*(const QV1567b& v) const {
        QV1567b o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Pl1567;
struct PlVt1567 { u8 pad[0xa0]; u8* (*get)(Pl1567*); };
struct Pl1567 { PlVt1567* vt; };
extern "C" {
extern f32 D_00349e10;
extern f32 D_00351fd8;
extern f32 D_00351fe0;
Pl1567* func_002d1260(void);
s32 func_0019ba60(Pl1567*);
void func_0011b6a8(QM1567b*);
void func_0011b768(QM1567b*, f32);
f32 func_001cbf50(f32);
s32 uc1567(u8* o, u32, u32, u32) asm("_Z16u_call4_001caf00jjjj");
s32 uc1567(u8* o, u32, u32, u32) {
    Pl1567* pl = func_002d1260();
    *(f32*)(o + 0x40) -= D_00349e10;
    if (*(f32*)(o + 0x40) <= 0.0f || !func_0019ba60(pl)) return 0;
    f32 t = *(f32*)(o + 0x40) / D_00351fd8;
    QV1567b v(*(QV1567b*)(o + 0x90));
    v.scale(*(f32*)(o + 0x9c) * t);
    v.w = 1.0f;
    QM1567b m;
    func_0011b6a8(&m);
    func_0011b768(&m, func_001cbf50(D_00351fe0 * (1.0f - t)));
    m.r[3] = *(QV1567b*)(pl->vt->get(pl) + 0x30);
    *(QV1567b*)o = m * v;
    *(s8*)(o + 0x16) = (s32)(t * 255.0f);
    return 1;
}
}
