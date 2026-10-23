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

Mgr1c4520* func_001c4520(void* parent, Pos1c4520* centre)
{
    s32 i;
    Mgr1c4520* mgr = func_001dba18(parent);
    if (mgr == 0) {
        mgr = new Mgr1c4520(parent);
        D_00351604 = 30;
        D_00351608 = 0;
        D_0035160c = 0;
    }
    Mgr1c4520* owner = mgr->owner;
    for (i = 0; i < 7; i++) {
        f32 x0 = i * 142.8571319580078f - 500.0f;
        for (s32 j = 0; j < 7; j++) {
            f32 z0 = j * 142.8571319580078f - 500.0f;
            Pos1c4520 p(centre->x + (x0 + frand_1c4520(142.8571319580078f)), centre->y,
                        centre->z + (z0 + frand_1c4520(142.8571319580078f)));
            func_001a7610(&p, &p, 4, 1000.0f, 200.0f);
            f32 h = frange_1c4520(300.0f, 400.0f);
            p.w = 1.0f;
            p.y -= h + 64.0f;
            Obj1c4520* o = func_001db888((u8*)owner + 20, 96, __builtin_return_address(0));
            func_001dbc58(o, owner, &p, &D_01d49580);
            o->update = (void*)func_001c4e30;
            o->height = (s32)h;
            o->variant = irand_1c4520(8);
            D_00351604++;
        }
    }
    return mgr;
}
}
