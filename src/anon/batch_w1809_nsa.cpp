#include "../common/types.h"

// 16-byte vector with an lq/sq copy (self-assignment checked) and a VU0 zero.
struct W1809V4 {
    f32 x, y, z, w;
    W1809V4() {}
    W1809V4& operator=(const W1809V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct W1809O76;
struct W1809C76 { virtual void m0(); virtual void m1(); virtual void fn(W1809O76*, W1809V4*); };
struct W1809S76 { u8 pad[0x50]; f32 f50; f32 f54; };
struct W1809O76 {
    u8 pad0[12]; W1809C76* p0c; W1809V4 v10; u8 pad20[0x110]; W1809S76* p130; u8 pad134[0xc]; u8 x140[0x10];
};

struct W1809S19a1 { u8 type; u8 pad; u16 h2; };
struct W1809O19a1 { u8 pad[8]; W1809S19a1* p; };

struct W1809Heap;
struct W1809HeapVt { void* (*alloc)(W1809Heap*, u32, void*); };
struct W1809Heap { W1809HeapVt* vt; };
struct W1809InfoC8 { u8 pad[16]; s32 n10; u32 sz14; u32 sz18; };
struct W1809RefC8 { u8 pad[0x488]; s32 refs; };
struct W1809ObjC8 {
    W1809InfoC8* info; s32 f4; void* f8; void* fc; void* f10; void* f14; void* f18;
    s32 f1c, f20, f24; s32 f28; s32 f2c, f30; void* f34; W1809RefC8* f38;
};

struct W1809V2d5 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1809R2d5 { u8 pad[16]; s16 h10; };

extern "C" {
s32 func_0019a480();
void func_0019a808();
void func_0019af98();
void func_0019b4d0();
void func_0019b500();
void func_0019b5d8();
void Ti__ACTION_PO_JUMP__exec_jump();
extern u8* D_0034e948;

s32 func_0019a1a0(W1809O19a1* o, s32 a1);  // 0x0019a1a0: definition moved into src/anon/unit_00199688.cpp

void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_0016aef0(W1809O76*, W1809V4*);

// 00176970: moved to src/yasui/libys/party.cpp
extern W1809Heap* D_004f6288;
void* func_0016d1a0(s32);
void* func_0016d1d8(void*);

// 0016c808: moved to src/anon/unit_0016c770.cpp

// 0016c8f8: moved to src/anon/unit_0016c770.cpp

extern s32 D_00361f60;
s32 func_001c0cd8(void*);
W1809R2d5* func_0016bc20(void*, s32, s32);
void YS__OBJ__get_target_pos(W1809V2d5*, void*);

// VU0 macro code: d = a - b, then the xyz length of d.
s32 Ti__MGOarashiPlayer__is_combine_ready(u8* a0);  // 0x002d55b8: definition moved into src/anon/unit_002d4548.cpp
}
