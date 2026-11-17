#include "../common/types.h"
// w3716 _nsa, partial asm: empty asm keeps the offset base live to the end of the if block (no load gets its REG_DEAD), f4/f2 pins fix FP allocation.
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1e7da8;
typedef struct { V1e7da8 r[4]; } M1e7da8;
typedef struct { u8 pad0[128]; f32 tx, ty, tz; u8 pad1[144 - 140]; u8 m144[16]; f32 sx, sy, sz; u8 pad2[249 - 172]; u8 big; } Own1e7da8;
typedef struct {
    f32 x, y, z;
    u8 pad0[16 - 12];
    f32 rz, rx, ry;
    u8 pad1[32 - 28];
    f32 sx, sy, sz;
    u8 pad2[64 - 44];
    f32 bx, by, bz;
    u8 pad3[140 - 76];
    Own1e7da8* own;
    u8 pad4[170 - 144];
    u8 offset;
} Part1e7da8;
extern M1e7da8 D_01d9e6f0;
extern V1e7da8 D_01d9e7f0;
extern f32 D_00354be0[3];
extern f32 D_00354bd0[3];
extern u8 D_00354bc0[];
extern u8 D_01d9e720[];
void sceVu0UnitMatrix(M1e7da8*);
void sceVu0RotMatrixX(M1e7da8*, M1e7da8*, f32);
void sceVu0RotMatrixY(M1e7da8*, M1e7da8*, f32);
void sceVu0RotMatrixZ(M1e7da8*, M1e7da8*, f32);
void func_001e8fe0(M1e7da8*, void*);
void sceVu0MulMatrix(M1e7da8*, M1e7da8*, M1e7da8*);
void func_001e7d20(V1e7da8*, V1e7da8*);
f32 func_002f8ad0(f32, f32);
f32 func_002f8ab8(f32);
void sceVu0CopyVector(void*, void*);
/* libvu0 sceVu0ScaleVectorXYZ (VU0 macro code) */
static inline void scale1e7da8(V1e7da8* d, V1e7da8* v, f32 s)
{
    asm volatile("qmtc2 %2, $vf9\n\tlqc2 $vf10, 0(%1)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(d), "r"(v), "r"(s) : "memory");
}
void func_001e7da8(Part1e7da8* p);  // 0x001e7da8: definition moved into src/anon/unit_001e0cb8.cpp
