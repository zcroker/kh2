#include "../common/types.h"

struct Obj_w2370 { u8 pad[0x588]; u32 flags; u8 pad2[0xa70 - 0x58c]; u8 busy; };

extern "C" {
Obj_w2370* func_0018bc60(void*, s32);
s32 func_0018bae8(void*, void*);

// Finds the partner object of a; when it is flagged (8) and idle, links both ways
// and writes the two link results to out. (The original has no return on the
// "flag clear / busy" path: v0 still holds p there.)
Obj_w2370* func_0018b8e0(void* a, s32* out);  // 0x0018b8e0: definition moved into src/yasui/libys/npc.cpp
}
