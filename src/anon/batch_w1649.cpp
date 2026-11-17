#include "../common/types.h"
extern "C" {
struct W1649Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1649Mtx { W1649Vec r[4]; };
f32 func_0011c050(f32);  // wraps an angle into (-pi, pi]
f32 W1649_asinf(f32) asm("func_002f8ab8");
f32 W1649_atan2(f32, f32) asm("f_atan2f");
// VU0 macro-mode dot product (hand-written vu0 library idiom; no memory clobber, like the original).
static inline f32 W1649Dot(const W1649Vec* a, const W1649Vec* b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
// Extract Euler angles from a rotation matrix, choosing the solution nearest to *prev, and store it there.
void func_0011bac8(W1649Mtx* m, W1649Vec* prev);  // 0x0011bac8: definition moved into src/anon/unit_0011b3f8.cpp
}
