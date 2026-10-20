#include "../common/types.h"
// VU0 helpers (inline asm: the original uses the VU0 macro library).
#define W1784_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1784_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1784QV {
    f32 x, y, z, w;
    W1784QV() {}
    W1784QV(const W1784QV& o) { W1784_QCOPY(this, &o); }
    W1784QV& operator=(const W1784QV& o) { if (this != &o) W1784_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1784QM {
    W1784QV r[4];
    W1784QM() {}
    W1784QM(const W1784QM& o) { W1784_QCOPY4(this, &o); }
    W1784QM& operator=(const W1784QM& o) { if (this != &o) W1784_QCOPY4(this, &o); return *this; }
    W1784QV operator*(const W1784QV& v) const {
        W1784QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
static inline f32 w1784_norm(W1784QV* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W1784QV w1784_scale(const W1784QV* v, f32 s) {
    W1784QV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(v), "f"(s) : "$8", "memory");
    return r;
}
struct W1784C4 { u8 pad[0xc0]; W1784QV dir; };
struct W1784It { u8 b0; u8 b1; u8 f : 1; u8 : 7; bool ok() { return !f; } };
struct W1784Iter { void* p; u32 type; };
extern "C" {
void func_0017c430(W1784C4*, f32);
void func_0017c4c8(W1784C4* c, W1784QV* v) {
    func_0017c430(c, v->y);
    v->y = 0.0f;
    f32 w = v->w;
    w1784_norm(v);
    c->dir = w1784_scale(v, w);
    c->dir.w = 1.0f;
}
f32 func_0017ce10(void);
W1784QM func_0017d1d8(f32, void*);
W1784QV func_0017d698(const W1784QV& v, void* p) {
    W1784QM m;
    m = func_0017d1d8(func_0017ce10(), p);
    return m * v;
}
void* func_001b9bc8(void*);
s32 func_0019bc38(void*);
W1784It* func_0016bba8(void*, s32, W1784It*);
W1784It* func_00190730(W1784Iter* it, W1784It* cur) {
    if (it->p == 0) {
        cur = 0;
        it->p = func_001b9bc8(0);
    }
    for (; it->p; cur = 0, it->p = func_001b9bc8(it->p)) {
        if (!func_0019bc38(it->p)) continue;
        while ((cur = func_0016bba8(it->p, 3, cur)) != 0) {
            if (cur->ok()) { it->type = cur->b0; return cur; }
        }
    }
    return 0;
}
}
