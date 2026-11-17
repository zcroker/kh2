#include "../common/types.h"

// Ts lock-on helpers (0x2ea2b8-0x2ea450): two small classes with vtable 0x363410 (C2/C1 ctor pairs;
// 0x2ea2b8, 0x2ea2f8 and 0x2ea318 were never written before), a motion reset callback (0x2ea338, never
// written before) and the turn-toward helper 0x2ea360. Every symbol is bound by asm label.

namespace n002ea2b8 {
extern u32 D_00363410 asm("D_00363410");
void func_002ea2b8(u32* p) asm("func_002ea2b8");
void func_002ea2b8(u32* p) {
    p[1] = 1;
    p[2] = 385;
    p[0] = (u32)&D_00363410;
}
}  // namespace n002ea2b8

// 002ea2d8 (from src/anon/batch_w5.cpp)
namespace n002ea2d8 {
extern u32 D_00363410 asm("D_00363410");
void func_002ea2d8(u32* p) asm("func_002ea2d8");
void func_002ea2d8(u32* p) {
    p[1] = 1;
    p[2] = 385;
    p[0] = (u32)&D_00363410;
}
}  // namespace n002ea2d8

namespace n002ea2f8 {
extern u32 D_00363410 asm("D_00363410");
void func_002ea2f8(u32* p, u32 a) asm("func_002ea2f8");
void func_002ea2f8(u32* p, u32 a) {
    p[1] = a;
    p[2] = 257;
    p[0] = (u32)&D_00363410;
}
void func_002ea318(u32* p, u32 a) asm("func_002ea318");
void func_002ea318(u32* p, u32 a) {
    p[1] = a;
    p[2] = 257;
    p[0] = (u32)&D_00363410;
}
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_002ea338(void*, u8* o) asm("func_002ea338");
void func_002ea338(void*, u8* o) {
    func_0017f488(o + 320, 3, 0.0f, 0.0f);
}
}  // namespace n002ea2f8

// 002ea360 (from src/anon/batch_w83.cpp)
namespace n002ea360 {
// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
f32 func_0017ce10(f32) asm("func_0017ce10");
Vec4 func_0017d0e8(f32) asm("func_0017d0e8");
// Turn cur's heading toward tgt by at most lim.
Vec4 func_002ea360(f32 lim, f32* cur, f32* tgt) asm("func_002ea360");
Vec4 func_002ea360(f32 lim, f32* cur, f32* tgt) {
    Vec4 r;
    f32 m = lim * D_00349e10;
    f32 d = func_002f8ad0(tgt[0], tgt[2]);
    f32 c = func_002f8ad0(cur[0], cur[2]);
    d = d - c;
    cur[3] = c;
    f32 e = func_0017ce10(d);
    if (m < e) r = func_0017d0e8(func_0017ce10(cur[3] + m));
    else if (e < -m) r = func_0017d0e8(func_0017ce10(cur[3] - m));
    else r = *(Vec4*)tgt;
    return r;
}
}  // namespace n002ea360

