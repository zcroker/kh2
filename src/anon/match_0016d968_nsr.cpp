#include "../common/types.h"
// Built with -O2 -fno-strength-reduce (_nsr): with strength reduction on, loop.c deletes the empty
// counter loop at the end of func_0016d968; the original keeps it (li 4 / slti 2 / short-loop nops / beqzl).

struct W2437V4 {
    f32 x, y, z, w;
    W2437V4& operator=(const W2437V4& o) {
        // 128-bit copy (lq/sq), skipped for self-assignment
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2437M4 { W2437V4 r[4]; };

// VU0 macro code: scale the first three matrix rows by s.x, s.y, s.z
static inline void W2437_scaleM(W2437M4* m, W2437V4* s) {
    asm volatile(".set noreorder\n\tlqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\t.set reorder" : : "r"(m), "r"(s) : "memory");
}

struct W2437Obj { W2437V4* pos; f32 scale; };

extern "C" {
void func_0011b6a8(W2437M4*);

// 0016d968: moved to src/anon/unit_0016d2e0.cpp
}
