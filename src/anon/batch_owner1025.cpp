#include "../common/types.h"
extern "C" {
extern u8* D_0034e948;
extern void* D_00361a50;
void* func_00102c48(s32, s32, void (*)(void), s32);
void* func_001050d8(s32);
void func_002bfa98(void*, void*, void*);
void func_002bfd90(void);
void func_002bfdb0(void);
void func_001c1130(s32);
void func_00197760(void);
void func_00197c90(void);
void func_001398d0(s32);

// 002bf9d8: create the task object and hand it to 002bfa98.
void func_002bf9d8(void* arg)
{
    u8* t = (u8*)func_00102c48(1, 15000, func_002bfd90, 16384);
    *(void (**)(void))(t + 48) = func_002bfdb0;
    func_002bfa98(func_001050d8(8), t, arg);
}

void func_002bfa40(void** p, void* a, void* b)
{
    p[0] = a;
    p[1] = b;
    D_00361a50 = p;
    func_001c1130(12);
    *(u32*)(*(u8**)(D_0034e948 + 2880) + 44) |= 1;
    func_00197760();
    func_00197c90();
    func_001398d0(201);
}
}
