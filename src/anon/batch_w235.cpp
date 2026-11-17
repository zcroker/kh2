#include "../common/types.h"

extern "C" {
f32 func_002f8a18(f32);
f32 atanf(f32);
struct W235A { u8 p[76]; f32 w; f32 h; };
// 00106f40: moved to src/naka/libkn/camera.cpp

struct W235B { u8 p[352]; u32 fl; u8 q[1060]; u32 fl2; u8 r[644]; W235B* o2064; u8 r2[712]; f32 f; };
s32 func_0016a040(W235B*);
static inline bool w235_pos(f32 x) { return 0.0f < x; }
s32 func_0019c170(W235B* o);  // 0x0019c170: definition moved into src/anon/unit_0019ba60.cpp
}
