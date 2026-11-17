// Linked unit 0x1fd530-0x1fded0: six ppp functions that were never written as separate matches (no
// layout.tsv row), between whole-asm 0x1fd368 and 0x1fded0. Flags -G0 -fno-strict-aliasing.
#include "../common/types.h"
// 001fd530 (was gap)
namespace n001fd530 {
struct In { s32 id; f32 x, y, z; f32 sx, sy, sz; u8 mode; };
struct M { f32 m[4][4]; } __attribute__((aligned(16)));
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern f32 D_00354be0[] asm("D_00354be0");
extern u8 D_01d9e6f0[] asm("D_01d9e6f0");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e880[] asm("D_01d9e880");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
void func_001fd530(u8* o, In* in, u8* t) asm("func_001fd530");
void func_001fd530(u8* o, In* in, u8* t)
{
    M m;
    u8* p = o + (*(s32**)(t + 12))[0] + 160;
    sceVu0ScaleVector(m.m[0], D_01d9e6e8 + 16, in->sx);
    sceVu0ScaleVector(m.m[1], D_01d9e6e8 + 32, in->sy);
    sceVu0ScaleVector(m.m[2], D_01d9e6e8 + 48, in->sz);
    sceVu0CopyVector(m.m[3], D_01d9e6e8 + 64);
    switch (in->mode) {
    case 0:
        m.m[3][0] += in->x;
        m.m[3][1] += in->y;
        m.m[3][2] += in->z;
        sceVu0MulMatrix(&m, D_01d9e840, &m);
        break;
    case 1:
        sceVu0MulMatrix(&m, D_01d9e840, &m);
        m.m[3][0] += in->x;
        m.m[3][1] += in->y;
        m.m[3][2] += in->z;
        break;
    case 2:
        sceVu0MulMatrix(&m, D_01d9e6f0, &m);
        m.m[3][0] += in->x * D_00354be0[0];
        m.m[3][1] += in->y * D_00354be0[1];
        m.m[3][2] += in->z * D_00354be0[2];
        sceVu0MulMatrix(&m, D_01d9e730, &m);
        break;
    case 3:
        sceVu0MulMatrix(&m, D_01d9e880, &m);
        m.m[3][0] += in->x;
        m.m[3][1] += in->y;
        m.m[3][2] += in->z;
        break;
    }
    sceVu0MulMatrix(p, D_01d9e8c0, &m);
}
}  // namespace n001fd530

// 001fd728 (was gap)
namespace n001fd728 {
struct In { s32 id; f32 x, y, z; f32 sx, sy, sz; u8 mode; };
struct M { f32 m[4][4]; } __attribute__((aligned(16)));
struct V { f32 x, y, z, w; } __attribute__((aligned(16)));
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern f32 D_00354be0[] asm("D_00354be0");
extern u8 D_01d9e6f0[] asm("D_01d9e6f0");
extern u8 D_01d9e730[] asm("D_01d9e730");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(void*, void*, f32) asm("sceVu0ScaleVector");
void sceVu0CopyVector(void*, void*) asm("sceVu0CopyVector");
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
void func_001fd728(u8* o, In* in, u8* t) asm("func_001fd728");
void func_001fd728(u8* o, In* in, u8* t)
{
    M m;
    V v;
    u8* p = o + (*(s32**)(t + 12))[0] + 160;
    sceVu0ScaleVector(m.m[0], D_01d9e6e8 + 16, D_00354be0[0]);
    sceVu0ScaleVector(m.m[1], D_01d9e6e8 + 32, D_00354be0[1]);
    sceVu0ScaleVector(m.m[2], D_01d9e6e8 + 48, D_00354be0[2]);
    sceVu0CopyVector(&v, D_01d9e6e8 + 64);
    v.x *= in->sx;
    v.y *= in->sy;
    v.z *= in->sz;
    switch (in->mode) {
    case 0:
        v.x += in->x;
        v.y += in->y;
        v.z += in->z;
        sceVu0ApplyMatrix(m.m[3], D_01d9e840, &v);
        break;
    case 1:
        sceVu0ApplyMatrix(m.m[3], D_01d9e840, &v);
        m.m[3][0] += in->x;
        m.m[3][1] += in->y;
        m.m[3][2] += in->z;
        break;
    case 2:
        sceVu0ApplyMatrix(m.m[3], D_01d9e6f0, &v);
        m.m[3][0] += in->x * D_00354be0[0];
        m.m[3][1] += in->y * D_00354be0[1];
        m.m[3][2] += in->z * D_00354be0[2];
        sceVu0ApplyMatrix(m.m[3], D_01d9e730, m.m[3]);
        break;
    }
    sceVu0MulMatrix(p, D_01d9e8c0, &m);
}
}  // namespace n001fd728

// 001fd948 (was gap)
namespace n001fd948 {
struct Prm {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; void* p48; s32 w52; s32 w56; s32 w60; s32 w64; void* w68; s32 w72; u8 b76, b77; u8 pad78[2]; s32 pad80[4];
};
struct Slot { u8 pad[28]; u32* h; s32 w32; };
struct Sys { u8 pad[16]; Slot* slots; };
struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg1 { s32 w0; s32 idx; u8 b8, b9, b10, b11, b12, b13, b14; };
struct Arg2 { u8 pad[12]; s32* off; };
struct Col { u8 pad[8]; u8 r, g, b, a; };
struct Mtx { f32 m[4][4]; } __attribute__((aligned(16)));
extern Sys* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
extern u8 D_01d9e840[] asm("D_01d9e840");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
s32 func_0020f1e0(u32*, Prm*, s32) asm("func_0020f1e0");
void func_001fd948(u8* base, Arg1* a, Arg2* b) asm("func_001fd948");
void func_001fd948(u8* base, Arg1* a, Arg2* b) {
    Prm prm;
    Mtx m;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    Col* c = (Col*)(base + b->off[0] + 0xa0);
    prm.c27 = c->a;
    if (prm.c27 == 0) return;
    Slot* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    prm.flags = 0; if (a->b8 & 2) { prm.flags = 4; u32 h1a = *h & 1; if (!h1a) prm.flags |= 8; } else { if ((u8)(a->b8 & 1)) prm.flags = 128; u32 h1 = *h & 1; if (!h1) prm.flags |= 8; }
    if (!(*h & 2)) prm.flags |= 0x10;
    if (a->b9) prm.flags |= 0x200;
    if (a->b11) prm.flags |= 0x100;
    if (a->b10) {
        prm.flags |= 0x2000;
        prm.p48 = &m;
        sceVu0MulMatrix(&m, D_01d9e840, D_01d9e6e8->a16);
    }
    if (a->b12) prm.w68 = base + b->off[2] + 0xa0; else prm.w68 = 0;
    Sys2* g;
    *(u16*)((u8*)&prm + 8) = ((u16*)h)[0x16 / 2];
    g = D_01d9e6e8;
    prm.w28 = 0;
    prm.b10 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.p32 = g->a80;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    prm.c24 = c->r;
    prm.c25 = c->g;
    prm.c26 = c->b;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    prm.p44 = g->a16;
    prm.w52 = D_01d9eaa4;
    prm.b76 = a->b13;
    prm.b77 = a->b14;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}  // namespace n001fd948

// 001fdb90 (was gap)
namespace n001fdb90 {
struct Prm {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; void* p48; s32 w52; s32 w56; s32 w60; s32 w64; void* w68; s32 w72; u8 b76, b77; u8 pad78[2]; s32 pad80[4];
};
struct Slot { u8 pad[28]; u32* h; s32 w32; };
struct Sys { u8 pad[16]; Slot* slots; };
struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg1 { s32 w0; s32 idx; u16 h8; u8 b10, b11, b12, b13, b14; };
struct Arg2 { u8 pad[12]; s32* off; };
struct Col { u8 pad[8]; u8 r, g, b, a; };
struct Mtx { f32 m[4][4]; } __attribute__((aligned(16)));
extern Sys* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
extern u8 D_01d9e840[] asm("D_01d9e840");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
s32 func_0020f1e0(u32*, Prm*, s32) asm("func_0020f1e0");
void func_001fdb90(u8* base, Arg1* a, Arg2* b) asm("func_001fdb90");
void func_001fdb90(u8* base, Arg1* a, Arg2* b) {
    Prm prm;
    Mtx m;
    Sys2* g;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    Col* c = (Col*)(base + b->off[0] + 0xa0);
    prm.c27 = c->a;
    if (prm.c27 == 0) return;
    Slot* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    prm.flags = 0; if (a->b10 & 2) { prm.flags = 4; u32 h1a = *h & 1; if (!h1a) prm.flags |= 8; } else { if ((u8)(a->b10 & 1)) prm.flags = 128; u32 h1 = *h & 1; if (!h1) prm.flags |= 8; }
    if (!(*h & 2)) prm.flags |= 0x10;
    if (a->b11) prm.flags |= 0x200;
    if (a->b13) prm.flags |= 0x100;
    if (a->b12) {
        prm.flags |= 0x2000;
        prm.p48 = &m;
        sceVu0MulMatrix(&m, D_01d9e840, D_01d9e6e8->a16);
    }
    if (a->b14) prm.w68 = base + b->off[2] + 0xa0; else prm.w68 = 0;
    // w28 through a cast (no field info, like the h8 store) and first: retail stores it before h8.
    *(s32*)((u8*)&prm + 28) = 0;
    *(u16*)((u8*)&prm + 8) = a->h8;
    g = D_01d9e6e8;
    prm.b10 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    prm.c24 = c->r;
    prm.c25 = c->g;
    prm.c26 = c->b;
    prm.p32 = g->a80;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    prm.p44 = g->a16;
    prm.w52 = D_01d9eaa4;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}  // namespace n001fdb90

// 001fddc8 (was gap)
namespace n001fddc8 {
struct V { f32 a, b, c, d, e, f; };
void func_001fddc8(u8* a0, u8* t) asm("func_001fddc8");
void func_001fddc8(u8* a0, u8* t) {
    V* v = (V*)(a0 + (*(s32**)(t + 12))[2] + 160);
    v->b = v->c = v->d = v->e = v->f = 0.0f;
    v->a = 0.0f;
}
}  // namespace n001fddc8

// 001fddf8 (was gap)
namespace n001fddf8 {
struct V { f32 x, vx, ax, y, vy, ay; };
struct In { s32 id; s32 pad; f32 x, vx, ax, y, vy, ay; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_001fddf8(u8* a0, In* in, u8* t) asm("func_001fddf8");
void func_001fddf8(u8* a0, In* in, u8* t) {
    V* m = (V*)(a0 + (*(s32**)(t + 12))[2] + 160);
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    m->vx += m->ax;
    m->x += m->vx;
    m->vy += m->ay;
    m->y += m->vy;
    if (in->id != *(s32*)(a0 + 12)) return;
    m->x += in->x;
    m->vx += in->vx;
    m->ax += in->ax;
    m->y += in->y;
    m->vy += in->vy;
    m->ay += in->ay;
}
}  // namespace n001fddf8

