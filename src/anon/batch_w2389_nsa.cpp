#include "../common/types.h"
struct W2389Vec { f32 x, y, z, w; W2389Vec() {} W2389Vec(const W2389Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
struct W2389Mtx {
    W2389Vec r[4];
    W2389Vec operator*(const W2389Vec& v) const {
        W2389Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W2389Cam {
    u8 pad0[0x130];
    W2389Mtx m;
    u8 pad170[0x40];
    u8 m1b0[0x5c4];
    f32 f774;
    u8 pad778[0x4cc];
    s32 c44, c48, c4c;
};
extern "C" {
extern u8 D_0034881c;
extern W2389Cam* D_00348800;
void* func_0016b0d0(void);
W2389Vec* func_0016c028(void*);
void func_002f47d8(void* d, void* m, void* v, u32 f);
// 001440e0: projects a target position through the camera matrix and sets screen offsets from two projections 200 units apart.
void func_001440e0(void) {
    if (D_0034881c != 0) {
        void* o = func_0016b0d0();
        if (o != 0) {
            W2389Vec v(*func_0016c028(o));
            W2389Vec r = D_00348800->m * v;
            s32 a[4], b[4];
            D_00348800->f774 = r.z;
            func_002f47d8(a, D_00348800->m1b0, &v, 0);
            v.y -= 200.0f;
            func_002f47d8(b, D_00348800->m1b0, &v, 0);
            s32 t = (a[1] - b[1]) >> 4;
            D_00348800->c4c = (s32)((f32)t * 1.6f);
            t = D_00348800->c4c / 2;
            D_00348800->c44 = (a[0] >> 4) - t - 0x700;
            D_00348800->c48 = (b[0] >> 4) - t / 2 - 0x730;
        } else {
            D_00348800->f774 = 0;
        }
    }
}
}
