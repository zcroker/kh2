#include "../common/types.h"

extern "C" {
void func_0019ba60(u32);
u32 func_0016bc20(u32, u32, u32);
void func_0018a818(void*, void*, u32);
void func_001902a8(void*, void*);
void func_002ff2e8(void*, void*);
void func_00227da8(void*);
void func_00239700(void*);
extern u8 D_0034a660;
extern u8 D_00347e60;

void func_001904f0(u32* a, u8* b) {
    func_0019ba60(a[0]);
    u32 r = func_0016bc20(a[0], 19, a[1]);
    if (r) {
        func_0018a818(b, (void*)a[0], r);
    } else {
        func_001902a8(a, b);
    }
    *(f32*)(b + 28) = 1.0f;
}

struct K_w225 { s32 a, b, c, d, e; u8 f0, f1, f2, f3; u8 g[24]; };
void func_0022f528(u8* o) {
    {
        K_w225 t; t.a = -1; t.b = -1; t.c = 0; t.f2 = 0; t.f3 = 0;
        func_002ff2e8(&t.f3, o + 8);
    }
    K_w225 k; k.a = *(s16*)(o + 4); k.b = *(s16*)(o + 6); k.c = 0; k.d = -1; k.e = -1; k.f0 = 0; k.f1 = 0;
    func_00227da8(&k);
}

void func_0031bed8(u8* t) {
    *(u32*)t = (u32)&D_0034a660;
    *(u32*)(t + 0x30) = (u32)&D_00347e60;
    *(u32*)(t + 0xc) = 0;
    *(u32*)(t + 0x3c) = 0;
    func_00239700(t + 0x48);
    s32 i = 6;
    u8* p = t + 456;
    do { func_00239700(p); p += 344; } while (--i != -1);
}
}
