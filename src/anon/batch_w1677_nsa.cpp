#include "../common/types.h"

// 00142c90: builds the scene objects described by a setup block.
// Needs -fno-strict-aliasing (the heap store stays before the m->res reload).

struct W1677ResVtbl { void* fn[10]; };
struct W1677Res { W1677ResVtbl* vt; };

// 0x90-byte model object allocated from the caller's heap.
struct W1677Model {
    s32 handle;          // 0x00: returned by res->vt->fn[9]
    W1677Res* res;       // 0x04
    u8 pad08[8];
    u8 work[0x40];       // 0x10: filled by func_0011b6a8
    u8 sub50[0x24];      // 0x50: initialised by func_00108698
    void* tex;           // 0x74
    u8 pad78[0x10];
    s32 heap;            // 0x88
    u8 flag;             // 0x8c
};

extern "C" {
extern void* D_00348800;
extern void* D_00348804;
extern void* D_00348808;
extern void* D_0034880c;
extern void* D_00348810;
extern void* D_00348814;
extern W1677Model* D_00348818;
extern u8 D_0034881c;
extern u8 D_0034881d;
void* func_001063c0(s32 size, s32 heap);
void func_00108698(void*);
void func_0011b6a8(void*);
void func_0011e260(s32, void*);
void func_0011e880(s32, s32, s32, s32);
void kn__ModelObj__setDefaultTexanm(s32, s32);
void func_001415e8(void*, s32, u64);
void func_00142bf8(void*);
void func_00143278(void);
void func_00143298(void);
void dk__OctDrawFile__OctDrawFile(void*, s32, u8, u64);
W1677Res* func_00149288(void*);
void* func_00149290(void*);
s32 func_00149298(void*);
s32 func_001492a0(void*);
s32 func_001492a8(void*);
s32 func_001492b0(void*);
s32 func_001492b8(void*);
s32 func_001492c0(void*);
s32 func_001492d0(void*);
s32 func_001492d8(void*);
void func_0014ecb8(void);
void func_00153678(s32, u64, s32);
void func_0015c500(void);
void func_0015c6d0(s32);

void dk__Octree__create(void* setup, s32 heap, u8 flag, u64 mask);  // 0x00142c90: definition moved into src/anon/unit_00142c90.cpp
}
