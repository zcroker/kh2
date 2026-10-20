#include "../common/types.h"

namespace w1744 {
// lq/sq quadword copy (128-bit move, no C equivalent).
#define W1744_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { W1744_QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) W1744_QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// VU0 outer product (cross product), xyz; w = 0.
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct VPair { QWord* a; QWord* b; };
}
using namespace w1744;

extern "C" {
extern QWord D_004f62a0;

void func_0016d888(VPair* p) {
    D_004f62a0 = Cross(*p->a, *p->b);
    p->a = &D_004f62a0;
}

s32 func_0018c528(u32 a) {
    s32 r = 0;
    switch (a) {
    case 2: r = 287; break;
    case 0: case 1: r = 0; break;
    case 3: break;
    case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
        r = a + 279; break;
    }
    return r;
}

s32 YS_DAMAGE_GetReactionType(s32 a) asm("_ZN2YS6DAMAGE15GetReactionTypeEi");
s32 YS_DAMAGE_GetReactionType(s32 a) {
    switch (a) {
    case 1: case 12: return 1;
    default: return a;
    case 4: case 7: case 9: case 11: case 15: case 17: return 4;
    case 3: case 6: case 8: case 10: case 13: case 16: case 18: return 3;
    }
}
}
