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
void func_002d08b8(Vec3_1577* out, f32* m);  // 0x002d08b8: definition moved into src/anon/unit_002cf260.cpp
}
