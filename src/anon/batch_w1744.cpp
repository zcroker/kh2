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

// 0016d888: moved to src/anon/unit_0016d2e0.cpp

s32 func_0018c528(u32 a);  // 0x0018c528: definition moved into src/yasui/libys/npc.cpp

s32 YS_DAMAGE_GetReactionType(s32 a) asm("_ZN2YS6DAMAGE15GetReactionTypeEi");
// 0018ca48: moved to src/yasui/libys/damage.cpp
}
