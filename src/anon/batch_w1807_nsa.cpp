#include "../common/types.h"
typedef unsigned int w1807_u128 __attribute__((mode(TI)));
extern "C" {

// ---- 001fa668
extern u8* D_01d9e6e8;
extern u8 D_01d9e840[];
extern u8 D_01d9e8c0[];
void sceVu0ApplyMatrix(void*, void*, void*);
void func_002226b8(u8*, void*);
void func_0021f0d8(void*);
struct W1807V4 { f32 x, y, z, w; };
struct W1807Arg { u8* s; u8* m; void* a; void* b; };
void pppKeLnsLpDraw(u8* a, u32 a1, u8* c);  // 0x001fa668: definition moved into src/anon/unit_001fa1b8.cpp

// ---- 0021c8c8: DMA header + 8 GIF packets (tag, TEX0, A+D, 4 x ST/RGBAQ/XYZ)
union W1807Q { w1807_u128 q; struct { f32 x, y, z; u32 w; } f; u32 w[4]; u64 d[2]; };
W1807Q* func_0021c8c8(W1807Q* p, s32 a1, s32 a2);  // 0x0021c8c8: definition moved into src/anon/unit_0021aee8.cpp

}
