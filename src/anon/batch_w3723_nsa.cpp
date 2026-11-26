// w3723 2026-11-04: 00243298 matched with -fno-strict-aliasing (_nsa). Partial asm: the four global high halves
// (lui) are hand-written into pinned t6/t7 so the byte stores to D_0035ed0c/D_0035ed14 keep the original lui placement;
// the loop invariants (e60 vtable copy, -1 bound) are pinned to s5/s6. Based on helper best/00243298.cpp.
#include "../common/types.h"
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
extern "C" {
extern Holder* D_00347f80;
extern u8 D_00347e60;
extern u8 D_00347e40;
extern u8 D_00347f98;
extern s32 D_0035ece8; extern s32 D_0035ecec; extern s32 D_0035ecf0; extern s32 D_0035ecf4;
extern s32 D_0035ecf8; extern void* D_0035ecfc; extern void* D_0035ed00; extern void* D_0035ed04;
extern s32 D_0035ed08; extern s8 D_0035ed0c; extern s32 D_0035ed10; extern s8 D_0035ed14;
void func_00287b18(s32, s32);
s32 func_00288be8(s32);
void func_002889f0(s32, s32, s32);
void func_00288f48(s32, s32, s32, s32, s32);
void func_002b3df8(s32);
s32 func_00103570(void);
s32 func_001063f0(s32, s32);
void func_002fde18(s32, s32, s32);
void func_00239700(void*);
void func_0031a838(void*);
void func_0028d068(s32, s32);
s32* func_00103eb0(void);
void TASK_MANAGER__create_thread(s32, s32, s32, void*, s32);
void PauseThread_243(void*) asm("_ZN2Tz4HEFT11PauseThreadEP4TASK");

typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
void Tz__HEFT__Init(void);  // 0x00243298: definition moved into src/anon/unit_00242478.cpp
}
