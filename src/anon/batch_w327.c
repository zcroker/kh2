#include "../common/types.h"

typedef union W327U { s32 i; f32 f; } W327U;
typedef union W327UF { f32 f; s16 h; s32 i; } W327UF;

s32 func_002061f0(s32) asm("_Z13func_002061f0xxxx");

typedef struct W327Item388 { f32 x, y, z, w; void* src; W327U h; s32 p18; u8 r, g; s16 q; u8 pad[16]; } W327Item388;
typedef struct W327Src388 { s32 a; s32 id; u8 pad[0x1c]; W327UF x, y, z; u8 pad2[0x10]; u8 r, g, b; } W327Src388;
typedef struct W327Mgr388 { s32 a, b; u32 n; s32 c, d; W327Item388* items; } W327Mgr388;

s32 func_00206388(W327Mgr388* m, W327Src388* s) {
    u32 i;
    if (m->items == 0) return 0;
    for (i = 0; i < m->n; i++) {
        W327Item388* it = &m->items[i];
        if (it->src == 0) {
            it->src = s;
            it->h.i = func_002061f0(s->id);
            it->r = s->r;
            it->g = s->g;
            it->q = 0x7fff / s->b;
            it->x += s->x.f; it->y += s->y.f; it->z += s->z.f; it->w = 1.0f;
            break;
        }
    }
    return 1;
}
