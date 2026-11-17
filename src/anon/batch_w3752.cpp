#include "../common/types.h"
static inline bool TB(u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }
extern "C" {
s32 func_002a9d68();
extern s32 D_0035f610;

s32 func_002abce8(s32 x);  // 0x002abce8: definition moved into src/anon/unit_002a99c8.cpp
}
