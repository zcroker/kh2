#include "../common/types.h"

struct W1618V4 {
    f32 x, y, z, w;
    W1618V4() {}
    W1618V4(const W1618V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1618V4& operator=(const W1618V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1618M4 {
    W1618V4 r[4];
    W1618M4() {}
    W1618M4(const W1618M4& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    // In-place inverse of a rigid (rotation + translation) matrix.
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    W1618V4 operator*(const W1618V4& v) const {
        W1618V4 o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));

struct W1618MG;
struct W1618Ob;

extern "C" {
extern W1618MG* D_00361f60;
extern f32 D_00362e78;
s32 W1618_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
s32 W1618_be_ready(void) asm("_ZN2Ti8MiniGame8be_readyEv");
W1618M4* func_002e2930(W1618MG*);
W1618M4* func_002e2920(W1618MG*);
W1618V4* func_0016c028(W1618Ob*);
void W1618_set_pos(W1618Ob*, const W1618V4&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W1618_set_dir(W1618Ob*, const W1618V4&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");

// Re-projects the object's position through the minigame's two frames
// (flattening it onto the plane z = D_00362e78) and aligns its facing.
void func_002e2f90(u32 self, W1618Ob* o) {
    if (W1618_IsExec()) return;
    W1618MG* mg = D_00361f60;
    if (!W1618_be_ready()) return;
    W1618M4 a(*func_002e2930(mg));
    W1618M4 b(*func_002e2920(mg));
    b.invOrtho();
    W1618V4 p = b * *func_0016c028(o);
    p.z = D_00362e78;
    W1618V4 q = a * p;
    W1618M4 c(a);
    c.invOrtho();
    W1618V4 r = c * q;
    q = a * r;
    W1618_set_pos(o, q);
    W1618_set_dir(o, a.r[2]);
}
}
