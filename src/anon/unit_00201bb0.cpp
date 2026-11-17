// Linked unit 0x00201bb0-0x00201d60 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// 00201bb0 (was src/anon/batch_w77.cpp)
namespace n00201bb0 {
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e6f0 asm("D_01d9e6f0");
void sceVu0ApplyMatrix(f32*, void*, f32*) asm("sceVu0ApplyMatrix");
/*TARGET 00201bb0*/
void func_00201bb0(u8* p, f32* v1, f32* v2) asm("func_00201bb0");
void func_00201bb0(u8* p, f32* v1, f32* v2)
{
    f32 t[4];
    f32 a = *(f32*)(p + 16);
    f32 k = 0.5f;
    t[0] = 0;
    t[1] = a * k;
    t[2] = 0;
    t[3] = 1.0f;
    sceVu0ApplyMatrix(v1, D_01d9e6e8 + 16, t);
    t[1] = -a * k;
    sceVu0ApplyMatrix(v2, D_01d9e6e8 + 16, t);
    if (p[21]) {
        sceVu0ApplyMatrix(v1, &D_01d9e6f0, v1);
        sceVu0ApplyMatrix(v2, &D_01d9e6f0, v2);
    }
}
}  // namespace n00201bb0

// 00201ca0 (was src/anon/batch_w76.cpp)
namespace n00201ca0 {
/*TARGET 00201ca0*/
// 0x001fb9a8: definition moved into src/anon/unit_001fb350.cpp

void func_00201ca0(u8* p, s32* x, s32* w, s32* y, s32* h) asm("func_00201ca0");
// 0x001fb9a8: definition moved into src/anon/unit_001fb350.cpp

void func_00201ca0(u8* p, s32* x, s32* w, s32* y, s32* h)
{
    s32 ox = 0;
    s32 wv = 4096;
    s32 hv = 4096;
    switch (p[22]) {
    case 1: wv = 2048; break;
    case 2: wv = 1024; break;
    }
    switch (p[23]) {
    case 1: hv = 2048; break;
    case 2: hv = 1024; break;
    }
    switch (p[24]) {
    case 1: ox = 1024; wv += 1024; break;
    case 2: ox = 2048; wv += 2048; break;
    case 3: ox = 3072; wv += 3072; break;
    }
    *x = ox + 16;
    *w = wv - 16;
    *y = 16;
    *h = hv - 16;
}
}  // namespace n00201ca0

