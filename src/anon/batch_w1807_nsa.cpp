#include "../common/types.h"
typedef unsigned int w1807_u128 __attribute__((mode(TI)));
extern "C" {

// ---- 001fa668
extern u8* D_01d9e6e8;
extern u8 D_01d9e840[];
extern u8 D_01d9e8c0[];
void func_002f3cd8(void*, void*, void*);
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
        func_002f3cd8(&v, D_01d9e6e8 + 16, &v);
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
W1807Q* func_0021c8c8(W1807Q* p, s32 a1, s32 a2) {
    p->q = 0;
    if (!a1) p->w[3] = 0x6c78008f;
    else p->w[3] = 0x6c78027f;
    p++;
    for (s32 i = 8; i != 0; i--) {
        if (a2) p[0].d[0] = 0xe03a400000008001ULL; else p[0].d[0] = 0xe02a400000008001ULL;
        p[0].d[1] = 0x00412412412412e6ULL;
        p[1].q = 0;
        p[2].d[0] = 0; p[2].d[1] = 0x42;
        p[14].q = 0;
        p[13].q = 0;
        p[12].q = 0;
        p[11].q = 0;
        p[10].q = 0;
        p[9].q = 0;
        p[8].q = 0;
        p[7].q = 0;
        p[6].q = 0;
        p[5].q = 0;
        p[4].q = 0;
        p[3].q = 0;
        p[8].w[3] = 0x8000;
        p[5].w[3] = 0x8000;
        p[12].f.z = 1.0f;
        p[9].f.z = 1.0f;
        p[6].f.z = 1.0f;
        p[3].f.z = 1.0f;
        p += 15;
    }
    return p;
}

}
