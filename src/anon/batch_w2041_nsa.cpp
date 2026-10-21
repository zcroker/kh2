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
void w2041_wtarget(u32 arg0, u32, u32, u32) {
    W2041Wave* p = (W2041Wave*)arg0;
    f32 per1, per2, a, b;
    if (p->t <= 0.0f) {
        func_00166c80(0, 0);
        return;
    }
    per1 = p->per1;
    if (per1 > 0.0f) {
        p->ph1 += D_00349e10;
        while (p->ph1 >= per1) p->ph1 -= per1;
    }
    per2 = p->per2;
    if (per2 > 0.0f) {
        f32 d = D_00349e10;
        f32 ph = p->ph2 + d;
        p->ph2 = ph;
        if (ph >= per2) {
            do ph -= per2; while (ph >= per2);
            p->ph2 = ph;
        }
    }
    p->a1 += p->v1 * D_00349e10;
    p->a1 = w2041_clampf(p->a1, 0.0f, 16.0f);
    p->a2 += p->v2 * D_00349e10;
    p->a2 = w2041_clampf(p->a2, 0.0f, 16.0f);
    a = func_002f8960(p->ph1 / per1 * 3.1415927f * 2.0f - 3.1415927f) * p->a1;
    b = func_002f8960(p->ph2 / p->per2 * 3.1415927f * 2.0f - 3.1415927f) * p->a2;
    func_002f8870(a);
    func_002f8870(b);
    func_00166c80((s16)(s32)a, (s16)(s32)b);
    p->t -= D_00349e10;
    p->t = w2041_maxf(p->t, 0.0f);
}
}
