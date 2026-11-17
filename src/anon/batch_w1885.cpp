#include "../common/types.h"
extern "C" {
struct M1885 { f32 m[16]; } __attribute__((aligned(16)));
struct G1885 { u8 pad[16]; M1885 mtx; };
union U1885 { G1885* p; f32 f; };
extern U1885 D_01d9e6e8;
extern M1885 D_00354bd0;
extern f32 D_00354bc0[3];
void func_0021ed18(M1885*, void*);
void sceVu0InversMatrix(M1885*, M1885*);
void sceVu0MulMatrix(M1885*, M1885*, void*);

static inline void ScaleRow1885(f32* row, f32 s)
{
    asm("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(s) : "memory");
}

// 00201510: model node matrix build (rotate, translate, multiply, VU0 row scale). Same shape as func_00200e80.
void func_00201510(u8* p, u32, u8* a2);  // 0x00201510: definition moved into src/anon/unit_00200578.cpp
}
