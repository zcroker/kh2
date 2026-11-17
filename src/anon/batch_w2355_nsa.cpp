#include "../common/types.h"

// 001c4520: spawns a 7x7 jittered grid of effect objects around a centre point (needs -fno-strict-aliasing).
struct Pos1c4520 {
    f32 x, y, z, w;
    Pos1c4520(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; w = 0; }
} __attribute__((aligned(16)));
struct Obj1c4520 { u8 p0[81]; u8 variant; u8 p52[2]; void* update; s32 height; u8 p5c[4]; };
extern u32 D_003638d0;
extern s32 D_00351604;
extern s32 D_00351608;
extern u8 D_0035160c;
extern Pos1c4520 D_01d49580;
void* area_alloc_1c4520(u32) asm("_ZN4AREA5AllocEj");
extern "C" void func_001c4498(struct Mgr1c4520*, void*);
struct Mgr1c4520 {
    u8 p0[2548]; Mgr1c4520* owner; u8 p9f8[2560 - 2552];
    static void* operator new(unsigned int n) { return area_alloc_1c4520(n); }
    Mgr1c4520(void* a) { func_001c4498(this, a); }
};
extern "C" {
Mgr1c4520* func_001dba18(void*);
void func_001a7610(Pos1c4520*, Pos1c4520*, s32, f32, f32);
Obj1c4520* func_001db888(void*, s32, void*);
void func_001dbc58(Obj1c4520*, Mgr1c4520*, Pos1c4520*, Pos1c4520*);
void func_001c4e30(void);

// Game LCG (seed *= 69069); float in [0, max).
static inline f32 frand_1c4520(f32 max) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)D_003638d0 * 2.3283064e-10f * max;
}
// Float in [lo, hi).
static inline f32 frange_1c4520(f32 lo, f32 hi) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return lo + (f32)D_003638d0 * 2.3283064e-10f * (hi - lo);
}
// Integer in [0, n).
static inline s32 irand_1c4520(s32 n) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return ((u64)D_003638d0 * n) >> 32;
}

Mgr1c4520* func_001c4520(void* parent, Pos1c4520* centre);  // 0x001c4520: definition moved into src/anon/unit_001c4120.cpp
}
