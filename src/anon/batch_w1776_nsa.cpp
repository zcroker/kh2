#include "../common/types.h"
// batch w1776 (zl90). Built with -fno-strict-aliasing (the store order of the
// two sibling init functions only comes out right that way).

struct W1776V4 { f32 x, y, z, w; };
struct W1776Obj {
    u8 pad0[0x14]; u8 b14; u8 pad15; s8 b16; u8 pad17[0x11];
    s32 f28; u8 pad2c[4]; W1776V4 v30; f32 f40; u8 b44; u8 b45; u8 pad46[2]; s32 f48; u8* f4c; void* f50;
};
struct W1776Src { u8 pad[0x9f4]; u32 f9f4; };
extern char D_00371698[];

extern "C" {
void func_001c1748(W1776Obj*, u32, u32, u32);

void func_001c6fa8(W1776Obj* o, W1776Src* s, u8* p, u32 a, u32 b) {
    func_001c1748(o, s->f9f4, a, b);
    o->f28 = 0;
    W1776V4* v = &o->v30;
    v->x = v->w = v->z = v->y = 0.0f;
    o->f40 = 900.0f;
    o->f50 = s;
    o->f4c = p;
    o->b44 = 0;
    o->b45 = 30;
    o->f48 = 0;
    o->b14 = *p;
    o->b16 = -1;
}

void func_001c7048(W1776Obj* o, W1776Src* s, u8* p, u32 a, u32 b) {
    func_001c1748(o, s->f9f4, a, b);
    o->f28 = 0;
    W1776V4* v = &o->v30;
    v->x = v->w = v->z = v->y = 0.0f;
    o->f40 = 900.0f;
    o->f50 = s;
    o->f4c = p;
    o->b44 = 0;
    o->b45 = 30;
    o->f48 = 0;
    o->b14 = *p;
    o->b16 = -1;
}

void strcpy_w1776(char*, const char*) asm("_ZN2Tz16LayFileBuildDataEPvj");
s32 func_002ff3fc(const char*);
void func_00240118(char*, u32, u32);

// Builds "/" + func_00240118's text in a buffer and copies it twice to dst.
void func_00240240(char* dst, u32 a, u32 b) {
    char buf[80];
    strcpy_w1776(buf, D_00371698);
    s32 l = func_002ff3fc(buf);
    func_00240118(&buf[l], a, b);
    l = func_002ff3fc(buf);
    for (s32 i = 0; i < 2; i++)
        strcpy_w1776(&dst[l * i], buf);
}
}
