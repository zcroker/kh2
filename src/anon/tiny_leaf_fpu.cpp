#include "../common/types.h"

static inline u32 bits_from_f(f32 x) { union { f32 f; u32 u; } v; v.f = x; return v.u; }
static inline f32 f_from_bits(u32 x) { union { u32 u; f32 f; } v; v.u = x; return v.f; }

void func_0013f5f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x0013f5f0: definition moved into src/anon/unit_0013ef70.cpp

void func_002e0870(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002e0870: definition moved into src/anon/unit_002de3c8.cpp

void func_002ed720(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    f32 f0 = 0.0f, f1 = 0.0f;
    r15 = (u32)(0x0035u << 16);
    f0 = *(f32*)((u32)r4 + (s32)(88));
    f1 = *(f32*)((u32)r15 + (s32)(-25072));
    f0 = f0 - f1;
    *(f32*)((u32)r4 + (s32)(88)) = f0;
}
