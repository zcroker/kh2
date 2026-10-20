#include "../common/types.h"
extern "C" {
extern s32 D_0035eebc;
extern u8 D_0035f06b;
extern u8 D_0035f0b4;
extern s32 D_0035f0f8;
extern u8 D_0035f4b8;
extern u8 D_00347d28;
extern u8 D_0034c740;
extern s8 D_00361800;
extern u8* D_00348818;
s32 func_002535c0(void) { return D_0035eebc; }
void func_00258b28(s32 a) { D_0035f06b = a; }
u8 func_0025f568(void) { return D_0035f0b4; }
void func_0025f578(void) { D_0035f0b4 = 0; }
s32 func_0026d818(void) { return D_0035f0f8; }
void func_00292540(void) { D_0035f4b8 = 0; }
void func_0010f908(u8* p) { *(u32*)(p + 2940) |= 0x400; }
u32 func_00112c70(u8* p) { return (*(s32*)(p + 2940) >> 30) & 1; }
void func_00136a40(void) { D_00347d28 = 1; }
void func_00161238(void) { D_0034c740 = 1; }
u32 func_002be750(void) { return D_00361800 != 0; }
void func_00113408(u8* p) { *(u32*)(p + 2940) &= ~0x1000; }
void func_00113420(u8* p) { *(u32*)(p + 2940) |= 0x20000; }
u8* func_001178b8(u8* d, u8* s) {
    s += 1600;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    return d;
}
void func_001431d0(void) { D_00348818[140] = 1; }
}
