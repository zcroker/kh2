// Linked unit 0x1ad990-0x1ada38: fade value helpers (set target, step toward 0 or 1).
// .rodata at 0x36d7a4 (1.0f only, 4-aligned), so this file ends before 0x1ada38.
#include "../common/types.h"

// ---- 001ad990 from src/anon/batch_w21.cpp
namespace n001ad990 {
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
void func_001ad990(u32 p, f32 a, f32 b, f32 t) {
    f32* o = (f32*)p;
    if (0.0f < t) {
        o[0] = a;
        o[1] = (b - a) / t;
    } else {
        o[0] = b;
        o[1] = 0.0f;
    }
}
}  // namespace n001ad990

// ---- 001ad9c8 from src/anon/batch_w43.cpp
namespace n001ad9c8 {
extern f32 D_00349e10 asm("D_00349e10");
s32 func_001ad9c8(f32* p) asm("func_001ad9c8");
s32 func_001ad9c8(f32* p) {                             
    if (p[1] == 0.0f) return 0;
    f32 v = p[0] + p[1] * D_00349e10;
    p[0] = v;
    if (v <= 0.0f) {
        p[0] = 0.0f;
        p[1] = 0.0f;
    } else if (1.0f <= v) {
        p[0] = 1.0f;
        p[1] = 0.0f;
    }
    return 1;
}
}  // namespace n001ad9c8

