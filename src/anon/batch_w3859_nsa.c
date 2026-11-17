#include "../common/types.h"

/* 0021f0d8: builds an object's billboard/flare matrix and alpha from the camera (D_01d9e840 view, D_01d9e8c0 projection).
 * mode != 0: object-relative direction; otherwise projected screen positions. The facing matrix is built
 * with a VU0 macro sequence (partial inline asm). */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct {
    f32 m[4][4];        /* 0x00 world matrix */
    f32 r[3][4];        /* 0x40 facing rows */
    f32 v[4];           /* 0x70 x, y, scale, alpha */
    f32 ofs[3];         /* 0x80 */
    u8 pad8c[2];
    u8 near;            /* 0x8e */
    u8 mode;            /* 0x8f */
    f32 dir[4];         /* 0x90 (w = cone) */
    f32 pada0;
    f32 len;            /* 0xa4 */
    f32 range;          /* 0xa8 */
} ObjF0d8;
typedef struct { ObjF0d8* obj; f32* pos; f32 (*mat)[4]; } ArgF0d8;
extern f32 D_01d9e840[4][4];
extern f32 D_01d9e8c0[4][4];
void sceVu0CopyMatrix(f32 (*)[4], f32 (*)[4]);
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);
void sceVu0ScaleVector(f32*, f32*, f32);
void sceVu0SubVector(f32*, f32*, f32*);
void sceVu0UnitMatrix(f32 (*)[4]);
void sceVu0CopyVector(f32*, f32*);
void sceVu0Normalize(f32*, f32*);
f32 sceVu0InnerProduct(f32*, f32*);
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
f32 func_002229a0(f32*);
f32 func_002229d8(f32*);

void func_0021f0d8(ArgF0d8* a);  // 0x0021f0d8: definition moved into src/anon/unit_0021e988.cpp



