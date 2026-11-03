#include "../common/types.h"
extern "C" {
extern u32 D_003638d0;
u8* func_001c6f10(u32, u32, u32, void*);
void func_001c7420(void);
}
struct V4 { f32 x, y, z, w; };
static inline void setv(V4* p, f32 x, f32 y, f32 z) { p->y = y; p->x = x; p->w = 0; p->z = z; }
// LCG random offset in [-20,20) x [-40,-20) x [-20,20); pool literals at 0x36d4b8 (2^-32, 40, -20, 20, -40) verified against the ELF.
static inline f32 frand(f32 lo, f32 rng) { D_003638d0 = D_003638d0 * 0x10dcd; return lo + (f32)D_003638d0 * 2.3283064e-10f * rng; }
static inline f32 frand2(f32 rng, f32 lo) { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f * rng + lo; }
static inline f32 frnd() { D_003638d0 = D_003638d0 * 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f; }
static inline f32 add8(f32 lo, f32 r) { return lo + r; }
extern "C" {
u8* func_001a5420(u32 a, u32 b, u32 c) {
    u8* v = func_001c6f10(a, b, c, (void*)func_001c7420);
    if (v != 0) {
        V4* p = (V4*)(v + 0x30);
        f32 x = add8(-20.0f, frnd() * 40.0f);
        f32 y = add8(-40.0f, frnd() * 20.0f);
        f32 z = add8(-20.0f, frnd() * 40.0f);
        p->y = y; p->x = x; *(s32*)&p->w = 0; p->z = z;
    }
    return v;
}
}
