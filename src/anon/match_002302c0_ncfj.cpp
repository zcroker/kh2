// 002302c0: built with -fno-cse-follow-jumps (_ncfj); with it on, cse2 follows the type-test jump and folds the loop start to p+56.
// Spline arc-length lookup:
// t in [0,100] -> distance along spline; walks keys (dist = cumulative length at +0x24), samples 0022fe08
#include "../common/types.h"
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline void Vec_sub(Vec* r, const Vec* a, const Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline Vec operator-(const Vec& a, const Vec& b) { Vec r; Vec_sub(&r, &a, &b); return r; }
struct Rot { f32 x, y, z; };
struct PathKey { u8 pad[0x24]; f32 dist; };
struct Path {
    u8 pad0[6];
    s16 count;
    s16 type;
    u8 pad1[2];
    f32 length;
    PathKey keys[1];
};
extern "C" {
void func_0022fe08(Vec* out, f32 s, Path* p, s32 i);
void func_00230260(Vec* a, Vec* b, Rot* rot);

s32 func_002302c0(f32 t, Path* p, Vec* out, Rot* rot);  // 0x002302c0: definition moved into src/anon/unit_002302c0.cpp
}
