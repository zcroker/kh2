#include "../common/types.h"

// func_00128e98: bone midpoint helper (MotCtx/MotPose, see func_0012d728).
struct W1888eV {
    f32 x, y, z, w;
    W1888eV() {}
    W1888eV(const W1888eV& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1888eV& operator=(const W1888eV& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1888eV operator+(const W1888eV& b) const {
        W1888eV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1888eV operator*(f32 k) const {
        W1888eV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1888eM {
    W1888eV r[4];
} __attribute__((aligned(16)));
static inline W1888eV operator*(const W1888eM& m, const W1888eV& v) {
    W1888eV r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
struct W1888eH { u8 pad0[0x10]; u16 boneCount; };
struct W1888eC { u8 pad0[4]; W1888eH* mot; W1888eM* work; W1888eM* localX; W1888eM* worldX; };
struct W1888eP { u8 pad0[0x2c]; W1888eM* world; };
static inline W1888eM* w1888eWorld(W1888eC* ctx, W1888eP* pose, s32 i) {
    W1888eH* m = ctx->mot;
    if (i < m->boneCount) return &pose->world[i];
    return &ctx->worldX[i - m->boneCount];
}
extern "C" {
void func_00128e98(W1888eC* ctx, W1888eP* pose, s32 i, s32 j, W1888eV* out, W1888eM* m, W1888eV* out2)
{
    if (j >= 0) {
        W1888eV a = w1888eWorld(ctx, pose, i)->r[3];
        W1888eV b = w1888eWorld(ctx, pose, j)->r[3];
        *out = (a + b) * 0.5f;
    } else {
        *out = w1888eWorld(ctx, pose, i)->r[3];
    }
    if (m && out2) *out2 = *m * *out;
}
}

// func_002c1f90: rotation matrix with translation, premultiplied by the global view matrix.
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCP4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1888cV {
    f32 x, y, z, w;
    W1888cV() {}
    W1888cV& operator=(const W1888cV& o) { if (this != &o) QCP(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1888cM {
    W1888cV r[4];
    W1888cM() {}
    W1888cM& operator=(const W1888cM& o) { if (this != &o) QCP4(this, &o); return *this; }
    W1888cM operator*(const W1888cM& b) const {
        W1888cM o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
            "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
            : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1888cA { s32 a, b; };
struct W1888cB { u8 c[4]; };
struct W1888cO { u8 pad[0x150]; W1888cM m150; u8 pad2[0x210 - 0x190]; W1888cV v210; W1888cV v220; };
extern "C" {
extern W1888cM D_01e2bcc0;
void func_0011b6a8(W1888cM*);
W1888cM* func_0011b7b0(W1888cM*, W1888cV*);
void func_002eee68(W1888cO*, W1888cA, W1888cB);
void func_002c1f90(W1888cO* o, W1888cA a, W1888cB b)
{
    W1888cM m;
    W1888cV* t = &m.r[3];
    func_0011b6a8(&m);
    m = *func_0011b7b0(&m, &o->v210);
    *t = o->v220;
    {
        W1888cM r = D_01e2bcc0 * m;
        o->m150 = r;
    }
    func_002eee68(o, a, b);
}
}
