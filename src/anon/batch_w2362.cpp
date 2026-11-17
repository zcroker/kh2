#include "../common/types.h"

namespace w2362 {
// Effect set embedded in a game object at +0x80; list is non-zero once loaded.
struct EffSet { s32 list; };
struct Obj { u8 pad[0x80]; EffSet eff; };
struct Res { u32 a, b; s32 v; };
struct Holder { u8 pad[0x40]; void* tbl; };
struct Gauge { u8 pad[0x14]; s32 max; u32 p18; s32 cur; };
}
using namespace w2362;

extern "C" {
void* func_001de168(void*, s32, s32, s32, s32, void*);  // scan_list_by_half
Res* func_00168b38(void*, s32, s32);

// Starts effect id on the object's effect set; owner defaults to the object itself.
void* func_0016ac38(Obj* o, s32 id, s32 a, s32 b, Obj* owner);  // 0x0016ac38: definition moved into src/anon/unit_00169f98.cpp

// 00192450: moved to src/yasui/libys/message.cpp

// Looks up entry n (kind 9) in the holder's table and returns its value, 0 if none.
s32 func_00161548(Holder* h, s32 n);  // 0x00161548: definition moved into src/anon/unit_001614e8.cpp

s32 func_001d1760(Gauge* g, s32 n);  // 0x001d1760: definition moved into src/anon/unit_001d14e0.cpp
}
