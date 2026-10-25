#include "../common/types.h"

struct W2041Wave {
    f32 t;      // 0x00
    f32 per1;   // 0x04
    f32 ph1;    // 0x08
    f32 per2;   // 0x0c
    f32 ph2;    // 0x10
    f32 a1;     // 0x14
    f32 a2;     // 0x18
    f32 v1;     // 0x1c
    f32 v2;     // 0x20
};

static inline f32 w2041_clampf(f32 x, f32 lo, f32 hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}
static inline f32 w2041_maxf(f32 x, f32 lo) { return x > lo ? x : lo; }

extern "C" {
void func_00166c80(s16, s16);
void func_002f8870(f32);
f32 func_002f8960(f32);
extern f32 D_00349e10;

void w2041_wtarget(u32 arg0, u32, u32, u32) asm("_Z16wtarget_001e0448jjjj");
// 001e0448 PadWave::update: moved to src/anon/unit_001e0398.cpp
}
