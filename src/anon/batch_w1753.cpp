#include "../common/types.h"

struct W1753Pair { u32 a; u32 b; };
struct W1753Sub { u32 w[16]; };
struct W1753S1 { u32 x0; u32 x4; W1753Pair arr[8]; W1753Sub sub; };

extern "C" {
void func_001c0150(W1753Sub*, u32);

void func_0019f8f8(W1753S1* p, u32 v);  // 0x0019f8f8: definition moved into src/anon/unit_0019ee80.cpp

void YS__OBJ_ATTACK__OBJ_ATTACK(W1753S1* p, u32 v);  // 0x0019f950: definition moved into src/anon/unit_0019ee80.cpp
}
