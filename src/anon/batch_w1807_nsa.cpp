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
void func_001fa668(u8* a, u32 a1, u8* c) {
    u8* d = a + **(u32**)(c + 12);
    u8* s = d + 160;
    W1807V4 v;
    if (s[143]) {
        *(w1807_u128*)&v = 0;
        v.w = v.z = 1.0f;
        sceVu0ApplyMatrix(&v, D_01d9e6e8 + 16, &v);
        func_002226b8(d + 304, &v);
    }
    *(f32*)(s + 128) = *(f32*)(D_01d9e6e8 + 64);
    *(f32*)(s + 132) = *(f32*)(D_01d9e6e8 + 68);
    *(f32*)(s + 136) = *(f32*)(D_01d9e6e8 + 72);
    W1807Arg g;
    g.a = D_01d9e840; g.m = D_01d9e6e8 + 64; g.b = D_01d9e8c0; g.s = s;
    func_0021f0d8(&g);
}

// ---- 0021c8c8: DMA header + 8 GIF packets (tag, TEX0, A+D, 4 x ST/RGBAQ/XYZ)
union W1807Q { w1807_u128 q; struct { f32 x, y, z; u32 w; } f; u32 w[4]; u64 d[2]; };
W1807Q* func_0021c8c8(W1807Q* p, s32 a1, s32 a2);  // 0x0021c8c8: definition moved into src/anon/unit_0021aee8.cpp

}
