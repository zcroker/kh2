#include "../common/types.h"

extern "C" {

struct V205 { f32 x, y, z, w; };
struct O205 { char pad[544]; V205 v; };

u32 func_002eff58(char* a0) {
    f32 t = (*(f32*)(a0 + 272) + *(f32*)(a0 + 276)) * 0.5f;
    return t <= *(f32*)(a0 + 28);
}

void func_002be2d8(char* a0, s32 a1, V205* a2) {
    O205* o = *(O205**)(a0 + a1 * 4 + 44);
    o->v.x = a2->x;
    V205* q = &o->v;
    q->y = a2->y;
    q->z = a2->z;
    q->w = 1.0f;
}
}
