#include "../common/types.h"
struct Heap1956;
struct HeapVt1956 { void* (*alloc)(Heap1956*, u32, u32); };
struct Heap1956 { HeapVt1956* vt; };
struct Sys1956 { u8 pad[20]; Heap1956* heap; };
struct Obj13d820w1956 { u32 vt; u32 f4; u32 f8; u32 f12; u8 pad[16]; u8 sub[1]; };
extern "C" {
extern Sys1956* D_00347f80;
extern u8 D_00347e80[];
extern u8 D_003485fc;
extern Obj13d820w1956* D_003485e8;
extern void* D_003485ec;
extern void* D_003485f0;
extern void* D_003485f4;
extern void* D_003485f8;
void func_002361a0(void*);
void func_0031b130(void*);
void func_0031b3b8(void*);
void func_0031b4f0(void*);
s32 func_0013a7d0(s32);
void func_00138650(void*, s32, s32, s32);
s32 func_0013dda0(s32);
void func_00154f30(void*, s32, s32);
void func_001569d8(void*, s32);
void func_00154558(void*);
void func_0013db60(void);

void ttarget0_0013d820(void) asm("_Z17ttarget0_0013d820v");
void ttarget0_0013d820(void);  // 0x0013d820: definition moved into src/anon/unit_0013a8b8.cpp
}
