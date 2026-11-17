// 001449a8: transforms the 8 corners of a box by a matrix (VU0) and takes the min/max of the results.
// Partial asm: the QV copy and QM*QV VU0 sequences, the operator* temp pinned to $11, and empty asm
// outputs pinned to $7/$9/$10 (live across the loop) and $11 (live across the c[] dtor loop) so the
// remaining values land in the original's registers (px a2, temp t3, dtor pointer t7).
#include "../common/types.h"
struct QV {
    f32 x, y, z, w;
    QV() {}
    ~QV() {}
    QV(const QV& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QV& operator=(const QV& o) { if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QV operator*(const QV& v) const {
        QV o;
        register QV* po asm("$11") = &o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(po), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
void func_00144b38(void*, QV*);
void func_001447e0(void*, QV*);
void func_001449a8(void* a, QM* m);  // 0x001449a8: definition moved into src/anon/unit_00144450.cpp
}
