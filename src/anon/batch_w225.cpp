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

void func_001904f0(u32* a, u8* b);  // 0x001904f0: definition moved into src/anon/unit_001900d0.cpp

struct K_w225 { s32 a, b, c, d, e; u8 f0, f1, f2, f3; u8 g[24]; };
void func_0022f528(u8* o);  // 0x0022f528: definition moved into src/anon/unit_0022d358.cpp

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
