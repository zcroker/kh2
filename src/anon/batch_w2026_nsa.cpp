#include "../common/types.h"
extern "C" {
struct V30 { u8 pad[8]; f32 f8; u8 pad2[8]; f32 f14; };
struct R30 { V30* p; f32 a, b, c, d, e, f; };
void func_001f0430(V30* v, R30* r) {
    f32 z = 0.0f;
    r->a = v->f8;
    r->d = v->f14;
    r->f = z;
    r->e = z;
    r->c = z;
    r->b = z;
    r->p = v;
}
}
