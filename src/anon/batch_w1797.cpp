#include "../common/types.h"
extern "C" {
struct Ray_002225a8 { f32 ox, oy, oz, pad0; f32 dx, dy, dz, pad1; f32 r; f32 t; };
f32 func_00222978(f32);
s32 func_002225a8(Ray_002225a8* s) {
    s32 ret = 0;
    f32 a = s->dx * s->dx + s->dy * s->dy + s->dz * s->dz;
    f32 b = s->dx * s->ox + s->dy * s->oy + s->dz * s->oz;
    b = b + b;
    f32 c = s->ox * s->ox + s->oy * s->oy + s->oz * s->oz - s->r * s->r;
    f32 disc = b * b - 4.0f * a * c;
    c = -b;
    b = a + a;
    if (!(disc < 0.0f)) {
        ret = 1;
        s->t = (c - func_00222978(disc)) / b;
    }
    return ret;
}
}
