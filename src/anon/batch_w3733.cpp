#include "../common/types.h"
extern "C" {
s32 func_00242618(s32, u8);

// Picks a mode for a selection value a and passes it to func_00242618 with e.
// k is pinned to t5 (the original keeps it there; unpinned gcc puts it in t6).
s32 func_00287df0(s32 a, u8 b, u8 c, s32 (*d)(void), u8 e);  // 0x00287df0: definition moved into src/anon/unit_00286d28.cpp
}
