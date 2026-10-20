#include "../common/types.h"
struct W262In { u32 a[20]; u32 b[3]; u32 c[18]; u32 d[9]; u32 x200, x204; };
struct W262Q { u32 a[4]; u8 b; };
struct W262S {
    u8 pad[12];
    W262In in;
    u8 pad2[2108 - 12 - 208];
    u32 x83c, x840;
    W262Q q;
    u8 pad3[2136 - 2116 - 20];
};
struct W262Key { s32 t : 29; u32 type : 3; f32 v; f32 m1; f32 m0; };
extern "C" {
void func_00319d20(void*);  // zero_two_words
void func_00321198(void*);  // zero_3_words
void func_00319d58(void*);  // store_zero_byte
void func_00319a60(void*);  // clear_fixed_blocks
void func_00321068(u8* p) {  // clear_19_words
    W262S* s = (W262S*)p;
    W262In* in = &s->in;
    W262Q* q;
    int i;
    for (i = 0; i < 20; i++) in->a[i] = 0;
    for (i = 0; i < 3; i++) in->b[i] = 0;
    for (i = 0; i < 18; i++) in->c[i] = 0;
    for (i = 0; i < 9; i++) in->d[i] = 0;
    in->x200 = 0; in->x204 = 0;
    s->x83c = 0; s->x840 = 0;
    q = &s->q;
    for (i = 0; i < 4; i++) q->a[i] = 0;
    q->b = 0;
    func_00319d20(p + 2136);  // zero_two_words
    func_00319d20(p + 2144);  // zero_two_words
    func_00321198(p + 2152);  // zero_3_words
    func_00321198(p + 2164);  // zero_3_words
    func_00321198(p + 2176);  // zero_3_words
    func_00319d20(p + 2188);  // zero_two_words
    func_00319d58(p + 2713);  // store_zero_byte
    func_00319a60(p + 2716);  // clear_fixed_blocks
}

f32 func_00230de0(s32 i, W262Key* keys, W262Key* out, f32 t) {
    W262Key* k = (W262Key*)((u32)(i << 4) + (u32)keys);
    W262Key* n;
    f32 p0 = k->v;
    f32 m0 = k->m0;
    f32 t0 = (f32)k->t * 0.001953125f;
    f32 t1, p1, m1;
    f32 r;
    if (out) out->m0 = m0;
    n = k + 1;
    p1 = n->v;
    m1 = n->m1;
    t1 = (f32)n->t * 0.001953125f;
    switch (k->type) {
    case 0:
        r = p0;
        break;
    case 1:
        r = p0 + (p1 - p0) * (t - t0) / (t1 - t0);
        break;
    case 2: case 3: case 4: {
        f32 inv = 1.0f / (t1 - t0);
        f32 s = t - t0;
        f32 s2 = s * s;
        f32 inv2 = inv * inv;
        f32 a = s2 * s * inv2;
        f32 b = s2 * 3.0f * inv2;
        f32 c = s2 * inv;
        f32 a2 = (a + a) * inv;
        r = p0 * (a2 - b + 1.0f) + p1 * (b - a2) + m0 * (a - (c + c) + s) + m1 * (a - c);
        break;
    }
    default:
        r = 0.0f;
        break;
    }
    return r;
}
}
