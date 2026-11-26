// Linked unit 0x1ca638-0x1ca8e0: effect class with vtable 0x351f78 and instance pointer 0x351f68
// (C2 constructor copy 0x1ca638 written here). Its const tables 0x36e0f8-0x36e140 stay retail data.

#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"

// ---- 001ca638 gap: C2 copy of the constructor at 0x1ca678
namespace n001ca638 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00351f78 asm("D_00351f78");
u32 func_001ca638(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001ca638");
u32 func_001ca638(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00351f78;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8040)) = r16;
    return r2;
}
}  // namespace n001ca638

// ---- 001ca678 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n001ca678 {
u32 func_001a4db0(u32, u32, u32, u32) asm("_Z13func_001a4db0jjjj");
extern u8 D_00351f78 asm("D_00351f78");
u32 func_001ca678(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ca678jjjj");
u32 func_001ca678(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00351f78;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8040)) = r16;
    return r2;
}
}  // namespace n001ca678

// ---- 001ca6b8 from src/anon/tiny_auto80_fptr4.cpp
namespace n001ca6b8 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00351f78 asm("D_00351f78");
u32 func_001ca6b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ca6b8jjjj");
u32 func_001ca6b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00351f78;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8040)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001ca6b8

// ---- 001ca6e8 from src/anon/tiny_auto80_fptr4.cpp
namespace n001ca6e8 {
u32 func_001a4e30(u32, u32, u32, u32) asm("_Z13func_001a4e30jjjj");
extern u8 D_00351f78 asm("D_00351f78");
u32 func_001ca6e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ca6e8jjjj");
u32 func_001ca6e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00351f78;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8040)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001ca6e8

// ---- 001ca718 from src/anon/batch_w13.cpp
namespace n001ca718 {
void func_00105110(void*) asm("func_00105110");
void func_001a4e30(void*) asm("func_001a4e30");
extern u8 D_00351f78 asm("D_00351f78");
extern void* D_00351f68 asm("D_00351f68");
void func_001ca718(void** p) asm("func_001ca718");
void func_001ca718(void** p) {
    *p = &D_00351f78;
    D_00351f68 = 0;
    func_001a4e30(p);
    func_00105110(p);
}
}  // namespace n001ca718

// ---- 001ca758 from src/anon/batch_w90.cpp
namespace n001ca758 {
extern void* D_00351f68 asm("D_00351f68");
extern const u8 D_0036e0f8[] asm("D_0036e0f8");
extern const u8 D_0036e108[][16] asm("D_0036e108");
void func_001a5420(void*, const void*, u32) asm("func_001a5420");
void func_001ca758(u32 a0, u8* cnt) asm("func_001ca758");
void func_001ca758(u32 a0, u8* cnt)
{
    if (!D_00351f68) return;
    for (s32 i = 0; i < 9; i++)
        for (s32 j = 0; j < cnt[i + 2]; j++)
            func_001a5420(D_00351f68, D_0036e108[D_0036e0f8[i]], a0);
}
}  // namespace n001ca758

// ---- 001ca830 from src/anon/auto80_199_queue.cpp
namespace n001ca830 {
void func_001ca830(u32, u8* a1) asm("_Z13func_001ca830jPh");
void func_001ca830(u32, u8* a1) {
    u32* base = (u32*)0x00350000;
    u32 s0 = *(u32*)((u8*)base + (s16)0xe948);
    if (YS__OBJ__is_exist(s0) == 0) {
        return;
    }
    if ((*(u32*)(a1 + 40) & 1u) == 0) {
        return;
    }
    if (((u32(*)(u32, u32, f32, f32))YS__PRIZEEFFECT__can_get)((u32)a1, s0, 0.0f, 0.0f) == 0) {
        return;
    }
    YS__PRIZEEFFECT__get(a1, s0, 0);
    func_001d86a0(D_0036e128[(u32)*(u8*)(a1 + 20)], 0);
}
}  // namespace n001ca830

