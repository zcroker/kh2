#include "../common/types.h"

struct WT324750 { u8 pad[10]; u16 count; u8 pad2[4]; s32 offs[1]; };

extern "C" {
s32 wt_00324750(WT324750* p, s32 idx) asm("_Z16wtarget_00324750jjjj");

/* 00324750: return the 16-bit value of entry idx (for idx == -1, of the first valid entry), or -1.
   Needs -fno-gcse: the original re-extends the u16 count on every loop test. */
s32 wt_00324750(WT324750* p, s32 idx);  // 0x00324750: definition moved into src/anon/unit_00324750.cpp
}
