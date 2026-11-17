#include "../common/types.h"

extern "C" {
u32 func_002b82f8(void) asm("_Z13func_002b82f8Pv");
s32 func_002b6708(s32, s32, s32, s32, s32, s32);
s32 sceSifCallRpc(void*, s32, s32, void*, s32, void*, s32, s32, s32);
extern u8 D_01e22040[];
extern u32 D_01e21f40[];

s32 func_002b7d5c(s32 a, s32 b, s32 c, s32 d);  // 0x002b7d5c: definition moved into src/anon/unit_002b6f28.cpp

// Retry until the call succeeds (returns 0), then read the first result word.
u32 func_002b82f8(void);  // 0x002b82f8: definition moved into src/anon/unit_002b8274.cpp
}
