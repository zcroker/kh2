// w3742: partial asm: VU0 dot is hand-written; m2 pinned to $f0, tied empty asm on b.z, empty volatile asm in the else arm keeps m0 live so sy gets $f3.
#include "../common/types.h"
struct V3_1577 {
    f32 x, y, z;
    f32 dot(const V3_1577& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o), "m"(*this), "m"(o) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Vec3_1577 { f32 x, y, z; };
extern "C" {
f32 func_002f8ad0(f32, f32);
f32 func_002d0e10(f32);

static inline void wrap3(V3_1577& o, const V3_1577& i) {
    o.x = func_002d0e10(i.x);
    o.y = func_002d0e10(i.y);
    o.z = func_002d0e10(i.z);
}
void func_002d08b8(Vec3_1577* out, f32* m) {
    V3_1577 a, b, r;
    f32 m0 = m[0];
    register f32 m2 asm("$f0") = m[2];
    f32 sy = -m2;
    f32 cy = __builtin_sqrtf(m0 * m0 + m[1] * m[1]);
    if (cy > 1.9073486328125e-06f) {
        r.z = func_002f8ad0(m[1], m[0]);
        r.y = func_002f8ad0(-m[2], cy);
        r.x = func_002f8ad0(m[6], m[10]);
    } else {
        asm volatile("" : : "f"(m0));
        r.z = 0.0f;
        r.y = func_002f8ad0(sy, cy);
        r.x = func_002f8ad0(-m[9], m[5]);
    }
    a.x = func_002d0e10(r.x);
    a.y = func_002d0e10(r.y);
    a.z = func_002d0e10(r.z);
    r.x += 3.1415927f;
    r.z += 3.1415927f;
    r.y = 3.1415927f - r.y;
    wrap3(b, r);
    f32 bz = b.z; asm("" : "=f"(bz) : "0"(bz), "m"(b.z));
    if (a.dot(a) <= b.dot(b)) {
        out->x = a.x; out->y = a.y; out->z = a.z;
    } else {
        out->x = b.x; out->y = b.y; out->z = bz;
    }
}
}
