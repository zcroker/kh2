// Sub-object constructors of a big manager (00322e58 family): 48+1+2+3 408-byte elements, 6 436-byte elements.
// Built with -fno-strict-aliasing. The vtable-pointer stores are volatile (keeps the original store order).
#include "../common/types.h"
extern "C" {
void func_00239700(void*);
void func_0031a838(void*);
extern u8 D_00347f98[], D_00347e60[], D_00347e40[];

static inline __attribute__((always_inline)) void W1986_ctor436(u8* e)
{
    *(volatile u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
    *(volatile u32*)e = (u32)D_00347e60; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void W1986_ctor408(u8* e)
{
    *(u32*)(e + 12) = 0; *(volatile u32*)e = (u32)D_00347e60; func_00239700(e + 24);
}

static inline __attribute__((always_inline)) void H436(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(volatile u32*)e = b; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void H408(u8* e, u32 b)
{
    *(u32*)(e + 12) = 0; *(volatile u32*)e = b; func_00239700(e + 24);
}
static inline __attribute__((always_inline)) void H436b(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(volatile u32*)e = b; func_00239700(e + 24);
    *(volatile u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
}
void func_00324510(u8* t);  // 0x00324510: definition moved into src/anon/unit_00324380.cpp
}
