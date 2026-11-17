#include "../common/types.h"
typedef unsigned int W1836u128 __attribute__((mode(TI)));
struct W1836Vec { float x, y, z, w; } __attribute__((aligned(16)));
struct W1836Ebc { u8 pad[128]; u8* tbl; u8 pad2[36]; s64 flags; };
struct W1836EbOff { s32 a; s32 b; };
struct W1836EbArg2 { u8 pad[12]; W1836EbOff* off; };
struct W1836EbArg1 { s32 pad0; s32 idx; s32 ofs; u8 reset; u8 cnt; };
struct W1836V3c { f32 x, y, z; };
extern "C" {
void func_001e7da8(void);
void sceVu0MulMatrix(void*, void*, void*);
void sceVu0OuterProduct(void*, void*, void*);
void sceVu0Normalize(void*, void*);
extern u8 D_01d9e6f0[];
extern u8 D_01d9e730[];
extern float D_01d9e840[];
extern W1836Vec D_01d9e870;
extern W1836Vec D_01d9e880;
extern W1836Vec D_01d9e890;
extern W1836Vec D_01d9e8a0;
extern W1836Vec D_01d9e8b0;
extern u8 D_01d9e8c0[];
extern u8 D_01d9e900[];
extern u8 D_01d9e940[];

void func_001e3330(void);  // 0x001e3330: definition moved into src/anon/unit_001e0cb8.cpp

u8* func_001e7a98(W1836Ebc*, u8*);
extern s32 D_01d9ea9c;
extern W1836Ebc* D_01d9e6e0;

void func_001ebcf0(u8* a0, W1836EbArg1* a1, W1836EbArg2* a2);  // 0x001ebcf0: definition moved into src/anon/unit_001e8ac8.cpp
}
