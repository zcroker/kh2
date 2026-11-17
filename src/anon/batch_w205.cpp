#include "../common/types.h"

extern "C" {

struct V205 { f32 x, y, z, w; };
struct O205 { char pad[544]; V205 v; };

// 002eff58: moved to src/anon/unit_002efd68.cpp

void func_002be2d8(char* a0, s32 a1, V205* a2);  // 0x002be2d8: definition moved into src/anon/unit_002be020.cpp
}
