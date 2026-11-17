#include "../common/types.h"
// Built with -g -fno-strict-aliasing -fno-gcse. Without gcse, loop invariant
// motion keeps the separate copy of the entry base (move t3,t7).
struct W8003Src { s32 f0; s32 f4; u8 pad[0x18]; f32 x, y, z; };
struct W8003Ent { f32 x, y, z, w; W8003Src* src; s32 f14; s32 pad[2]; };
struct W8003Tbl { u32 n; s32 f4, f8; W8003Ent* e; };
struct W8003Src2 { s32 pad0; s32 id; s32 pad[6]; f32 x, y, z; };
struct W8003Ent2 { f32 x, y, z, w; W8003Src2* src; s32 h; s32 pad[2]; };
struct W8003Mgr { s32 pad0; u32 num; s32 pad[2]; W8003Ent2* ents; };
extern "C" {
s32 func_002061f0(s32) asm("_Z13func_002061f0xxxx");

s32 func_002061f8(W8003Tbl* t, W8003Src* s);  // 0x002061f8: definition moved into src/anon/unit_002061d8.cpp

s32 func_002062c0(W8003Mgr* m, W8003Src2* s);  // 0x002062c0: definition moved into src/anon/unit_002061d8.cpp
}
