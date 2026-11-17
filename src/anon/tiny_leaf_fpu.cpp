#include "../common/types.h"

static inline u32 bits_from_f(f32 x) { union { f32 f; u32 u; } v; v.f = x; return v.u; }
static inline f32 f_from_bits(u32 x) { union { u32 u; f32 f; } v; v.u = x; return v.f; }

void func_0013f5f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013f5f0: definition moved into src/anon/unit_0013ef70.cpp

void func_002e0870(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002e0870: definition moved into src/anon/unit_002de3c8.cpp

void func_002ed720(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002ed720: definition moved into src/anon/unit_002ecdb0.cpp
