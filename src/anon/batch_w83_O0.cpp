#include "../common/types.h"

extern "C" {
struct Ent64 { s32 hdr[2]; u8 pad[56]; };
extern Ent64 D_01e22080[512];
s32 func_002b9404(s32, s32, s32*, s32*);
void func_003058a0(s32);

// Count type-25 entries whose id matches the looked-up handle.
s32 func_002b986c(s32 a, s32 b);  // 0x002b986c: definition moved into src/anon/unit_002b95e8.cpp
}
