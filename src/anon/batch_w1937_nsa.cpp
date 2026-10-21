#include "../common/types.h"

namespace w1937_a {
struct W1937Obj;
struct W1937Msk { s32 m0, m1, m2; };
struct W1937VT {
    u8 pad[0x58];
    s32 (*f58)(W1937Obj*);
    u8 pad2[0x78 - 0x5c];
    s32 (*f78)(W1937Obj*, s32, u8, s32);
};
struct W1937Ent { s32 a; s32 b; s32 c; };
struct W1937Obj {
    W1937VT* vt;
    u8 pad[0x48c - 4];
    W1937Ent* ents;
    u8 pad2[0xabc - 0x490];
    W1937Msk m;
};
struct W1937Kind { u8 pad[4]; u8 k; u8 pad2[0x12 - 5]; u8 fl; };
struct W1937Owner { u8 pad[0xc]; W1937Obj* o; };
struct W1937Arg {
    u8 pad[0x18];
    s32 flags;
    W1937Owner* own;
    W1937Kind* kind;
    u8 pad2;
    u8 idx;
    u8 pad3[2];
    s32 val;
};
static inline u8 w1937_isKind(W1937Kind* k) { return k->k == 5 || k->k == 6; }
extern "C" {
s32 func_0018caf8(W1937Arg*);
s32 func_0018cef8(W1937Arg*);
void func_00186d48(W1937Obj* self, W1937Arg* a) {
    if (a->flags & 2) return;
    a->flags |= 2;
    W1937Ent* e0 = self->ents;
    if (e0 == 0) return;
    W1937Kind* k = a->kind;
    s32 v = a->val;
    s32 f;
    if (w1937_isKind(k)) {
        f = 0;
        if (a->own->o != self) { u32 t = k->fl; f = (t >> 4) & 1; }
        self->vt->f78(self, v, a->idx, f);
    } else {
        W1937Ent* e = &e0[a->idx];
        if (e->c >= e->a - v && self->vt->f58(self)) {
            v = e->a - e->c - 1;
            if (v < 0) v = 0;
        }
        if (v >= 2) {
            W1937Msk* m = &self->m;
            if (((m->m0 | m->m1) & ~m->m2 & 0x8000) && func_0018caf8(a)) {
                if (!func_0018cef8(a)) v = 1;
            }
        }
        self->vt->f78(self, -v, a->idx, 0);
    }
}
}
}

namespace w1937_b {
struct W1937V4 { f32 v[4]; };
extern "C" {
f32 func_002f8b30(f32, f32);
f32* func_0017d748(f32* out, W1937V4* p, f32 t) {
    s32 i = 0;
    f32* p0 = p[0].v; f32* p1 = p[1].v; f32* p2 = p[2].v; f32* p3 = p[3].v;
    f32 u = 1.0f - t;
    for (; i < 3; i++) {
        f32* o = &out[i];
        *o = p0[i] * func_002f8b30(u, 3.0f)
               + p1[i] * 3.0f * func_002f8b30(u, 2.0f) * t
               + p2[i] * 3.0f * u * func_002f8b30(t, 2.0f)
               + p3[i] * func_002f8b30(t, 3.0f);
    }
    return out;
}
}
}
