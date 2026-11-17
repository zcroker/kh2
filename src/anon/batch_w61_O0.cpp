#include "../common/types.h"

extern "C" {
void func_003058a0(u32);
struct E64 { u32 used; u8 pad[60]; };
extern E64 D_01e22080[512];

// Returns the index of the first free 64-byte slot, or -1.
s32 func_002b6678(void);  // 0x002b6678: definition moved into src/anon/unit_002b6678.cpp
}
