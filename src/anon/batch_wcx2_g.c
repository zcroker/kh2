#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1f1488;
typedef struct { V1f1488 r[4]; } M1f1488;
typedef struct { u8 pad0[17]; u8 mode; } Ob1f1488;
typedef struct { u8 pad0[64]; M1f1488 m; } Cam1f1488;
extern M1f1488 D_01d9e6f0;
extern M1f1488 D_01d9e7b0;
extern Cam1f1488* D_00354688;
/* libvu0 sceVu0ApplyMatrix (VU0 macro code) */
static inline void apply1f1488(V1f1488* d, M1f1488* m, V1f1488* v)
{
    asm volatile(".set noreorder\n\tlqc2 $vf27, 0(%2)\n\tlqc2 $vf28, 0(%1)\n\tlqc2 $vf29, 16(%1)\n\tlqc2 $vf30, 32(%1)\n\tlqc2 $vf31, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf28, $vf27x\n\tvmadday.wxyz ACC, $vf29, $vf27y\n\tvmaddaz.wxyz ACC, $vf30, $vf27z\n\tvmaddw.wxyz $vf26, $vf31, $vf0w\n\tsqc2 $vf26, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(m), "r"(v) : "memory");
}
void func_001f1488(Ob1f1488* o, u8* mdl, V1f1488* a, V1f1488* b, f32 h)
{
    V1f1488 v;
    v.x = 0.0f;
    v.z = 0.0f;
    v.w = 1.0f;
    v.y = h * 0.5f;
    apply1f1488(a, (M1f1488*)(mdl + 48), &v);
    v.y = -h * 0.5f;
    apply1f1488(b, (M1f1488*)(mdl + 48), &v);
    switch (o->mode) {
    case 0:
        break;
    case 1:
        apply1f1488(a, &D_01d9e6f0, a);
        apply1f1488(b, &D_01d9e6f0, b);
        break;
    case 2:
        if (D_00354688) {
            apply1f1488(a, &D_01d9e6f0, a);
            apply1f1488(a, &D_00354688->m, a);
            apply1f1488(b, &D_01d9e6f0, b);
            apply1f1488(b, &D_00354688->m, b);
        }
        break;
    case 3:
        apply1f1488(a, &D_01d9e6f0, a);
        apply1f1488(a, &D_01d9e7b0, a);
        apply1f1488(b, &D_01d9e6f0, b);
        apply1f1488(b, &D_01d9e7b0, b);
        break;
    }
}
