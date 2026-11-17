#include "../common/types.h"

struct T2437Tbl { u8 pad[8]; u16 lo; u16 hi; u16 n; u16 pad2; u8 pad3[8]; s32 off; };

extern "C" {
T2437Tbl* func_00132c68(s32);

// The shared fail block sits in the mask == 0 arm, so that arm's compare falls into it
// (bnez -> out, b fail), and the two failure tests of the mask arm are separate gotos.
s32 func_001325c8(s32 a0, u32 mask, u32 id);  // 0x001325c8: definition moved into src/anon/unit_00131418.cpp
}
