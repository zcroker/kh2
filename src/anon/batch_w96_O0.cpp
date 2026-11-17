#include "../common/types.h"

extern "C" {
struct Slot64_w96 { s32 state; s32 owner; u8 pad[56]; };
extern Slot64_w96 D_01e22080[];
extern Slot64_w96 D_01e22084[];
void func_003058a0(u32);

// Counts slots (owner read via the +4 view of the table, as the original addresses it) in state 15 (optionally only those owned by who).
s32 func_002b7148(s32 who);  // 0x002b7148: definition moved into src/anon/unit_002b6f28.cpp

}
