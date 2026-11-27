// Constructor of a big manager (00322e58 family): 4 408-byte nodes, 6 436-byte nodes, 4x32 408-byte arrays,
// 32 YI::IMAGE. Built with -fno-strict-aliasing; vtable stores are volatile (keeps the original store order).
#include "../common/types.h"
extern "C" {
void func_0031a838(void*);
void func_00239700(void*);
void W2505_ImageCtor(void*) asm("_ZN2YI5IMAGEC1Ev");
extern u8 D_00347f98[], D_00347e60[], D_00347e40[];
static inline __attribute__((always_inline)) void H436(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(volatile u32*)e = b; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void H436b(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(volatile u32*)e = b; func_00239700(e + 24);
    *(volatile u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
}
static inline __attribute__((always_inline)) void H408(u8* e, u32 b)
{
    *(u32*)(e + 12) = 0; *(volatile u32*)e = b; func_00239700(e + 24);
}
static inline __attribute__((always_inline)) void L408(u8* q)
{
    s32 i = 31; do { *(u32*)(q + 12) = 0; *(volatile u32*)q = (u32)D_00347e60; func_00239700(q + 24); i--; q += 408; } while (i != -1);
}
void dk__INFORMATION__init(u8* p);  // 0x00323540: definition moved into src/anon/unit_00321728.cpp
}
