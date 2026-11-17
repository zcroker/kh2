#include "../common/types.h"

struct RingEnt { s32 v; s32 t; };
struct Ring16 { s32 head; s32 tail; RingEnt ent[16]; };

extern "C" {
void func_0031cc28(s32*);

// Push v into a 16-entry ring buffer (if not full); the entry's second word is filled by func_0031cc28.
// 00187ef0: moved to src/anon/unit_00185d10.cpp
void func_00187ef0(Ring16* r, s32 v);
}

struct FindEnt { u8 pad[12]; s32 flags; u8 pad2[34 - 16]; u16 id; };
struct FindPl { u8 pad[0x160]; u32 st; u8 pad2[0x50c - 0x164]; u32 id; };
struct FindWk { u8 pad[0x9e0]; FindPl* pl; };
struct FindCtx { FindWk** w; };

extern "C" {
FindEnt* func_001b8e88(s32);
s32 func_001917c0(void);

// Look up entity id; reject it by flag bits 4/6 and the player's state/id.
FindEnt* func_0019e5f8(FindCtx* c, s32 id);  // 0x0019e5f8: definition moved into src/anon/unit_0019ba60.cpp
}

struct Blk36 { u32 w[9]; };

extern "C" {
extern u8 D_00352770;
extern u8 D_00350379;
s32 func_001bb4a0(void);
void func_00199098(Blk36*, s32);

// If both flags are set and func_001bb4a0() reports 0, fill *out via func_00199098 and return 1.
s32 func_001d5a58(void* self, Blk36* out);  // 0x001d5a58: definition moved into src/anon/unit_001d4f40.cpp
}

struct CallSub { f32 a; u32 b; u32 c; u32 d; u32 e; };
struct CallMgr { u8 pad[24]; CallSub s0; u8 pad2[9644 - 44]; CallSub s1; u8 pad3[12064 - 9664]; CallSub s2; };

extern "C" {
extern u32 D_0034a6f0; // CallMgr*, kept as an integer (it is reloaded after the u32 stores)
void func_001398d0(s32);
void func_001397d8(s32);
}

// Reset three sub-records of the manager and set bit 0 of each one's c word.
void u_call0_00153158(void);  // 0x00153158: definition moved into src/anon/unit_00153158.cpp
