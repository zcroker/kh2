// w3736 batch (-fno-strict-aliasing).
#include "../common/types.h"
struct G { f32 x, y, z, pad0; f32 ox, ry, oz, pad1; f32 sx, pad2, sz, pad3; s32 nx, ny, ix, iy; };
struct V4 { f32 x, y, z, w; };
extern u32 D_003638d0;
static inline f32 frand(f32 max) { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f * max; }
extern "C" {
// Grid point iterator with optional random jitter. Partial asm (step 4): FP register pins (iy f7, sz f4,
// dz f2, y f3) reproduce the original local-alloc numbering, and an empty asm ties the y store after
// the w store (no code emitted).
s32 func_001c28f8(G* g, V4* o, u8 jit) {
    if (g->iy >= g->ny) return 0;
    f32 half = 0.5f; register f32 fiy asm("$f7") = (f32)g->iy; register f32 sz asm("$f4") = g->sz; f32 oz = g->oz;
    f32 dx = g->sx * (f32)g->ix - g->ox * half; register f32 dz asm("$f2") = sz * fiy - oz * half; register f32 y asm("$f3") = g->y; f32 x=g->x+dx, z=g->z+dz;
    o->w = 0; asm("" : "+f"(y) : "m"(o->w)); o->y = y; o->x = x; o->z = z;
    if (jit) {
        f32 r = frand(g->sx); f32 ry = g->ry; o->x += r;
        f32 r2 = frand(ry); f32 sz = g->sz; o->y -= r2;
        o->z += frand(sz);
    }
    if (++g->ix >= g->nx) { g->ix = 0; g->iy++; }
    return 1;
}

}
