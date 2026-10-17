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
void func_0011bac8(W1649Mtx* m, W1649Vec* prev)
{
    W1649Vec d0, d1, a;
    f32 s = m->r[0].z;
    if (s < -1.0f) s = -1.0f; else if (s > 1.0f) s = 1.0f;
    if (__builtin_sqrtf(m->r[0].x * m->r[0].x + m->r[0].y * m->r[0].y) > 1.9073486328125e-06f) {
        a.z = W1649_atan2(m->r[0].y, m->r[0].x);
        a.y = W1649_asinf(-s);
        a.x = W1649_atan2(m->r[1].z, m->r[2].z);
    } else {
        if (s > 0.0f) {
            a.x = W1649_atan2(-m->r[1].x, m->r[1].y) * 0.5f;
            a.y = W1649_asinf(-s);
            a.z = a.x;
        } else {
            a.x = W1649_atan2(m->r[1].x, m->r[1].y) * 0.5f;
            a.y = W1649_asinf(-s);
            a.z = -a.x;
        }
        if (s >= 0.0f) a.z = a.x; else a.z = -a.x;
    }
    W1649Vec* p1 = &d1;
    d0.x = func_0011c050(a.x - prev->x);
    d0.y = func_0011c050(a.y - prev->y);
    d0.z = func_0011c050(a.z - prev->z);
    a.x += 3.14159274f;
    a.z += 3.14159274f;
    a.y = 3.14159274f - a.y;
    d1.x = func_0011c050(a.x - prev->x);
    d1.y = func_0011c050(a.y - prev->y);
    d1.z = func_0011c050(a.z - prev->z);
    if (W1649Dot(&d0, &d0) <= W1649Dot(p1, p1)) {
        prev->x = d0.x + prev->x; prev->y = d0.y + prev->y; prev->z = d0.z + prev->z;
    } else {
        prev->x = d1.x + prev->x; prev->y = d1.y + prev->y; prev->z = d1.z + prev->z;
    }
}
}
