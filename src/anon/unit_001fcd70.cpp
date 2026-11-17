// Linked unit 0x001fcd70-0x001fd368 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>

// 001fcd70 (was src/anon/batch_w91.cpp)
namespace n001fcd70 {
// 0x001e1070: definition moved into src/anon/unit_001e0cb8.cpp

// --- 001ead10
// Scales the work matrix rows by the bone's scale and copies its translation.
union GP91 { u8* p; f32 f; };
extern GP91 D_01d9e6e8 asm("D_01d9e6e8");
// 0x001f6778: definition moved into src/anon/unit_001f6298.cpp

// --- 001fb790
// Sets the RGBA bytes of a node from 0..255 inputs scaled by the global colour.
extern f32 D_00354be0[] asm("D_00354be0");
// --- 001fcd70
extern u8 D_01dad890[] asm("D_01dad890");
extern u8 D_01dad8d0[] asm("D_01dad8d0");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(u8*, u8*, f32) asm("sceVu0ScaleVector");
// vec_scale_by_f12
void sceVu0ApplyMatrix(u8*, u8*, u8*) asm("sceVu0ApplyMatrix");
/*TARGET 001fcd70*/
void func_001fcd70(void) asm("func_001fcd70");
void func_001fcd70(void) {
    sceVu0MulMatrix(D_01dad890, D_01d9e840, D_01dad8d0);
    sceVu0ScaleVector(D_01d9e6e8.p + 80, D_01d9e6e8.p + 16, D_00354be0[0]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8.p + 96, D_01d9e6e8.p + 32, D_00354be0[1]);  // vec_scale_by_f12
    sceVu0ScaleVector(D_01d9e6e8.p + 112, D_01d9e6e8.p + 48, D_00354be0[2]);  // vec_scale_by_f12
    sceVu0ApplyMatrix(D_01d9e6e8.p + 128, D_01d9e840, D_01d9e6e8.p + 64);
    sceVu0MulMatrix(D_01d9e6e8.p + 80, D_01d9e8c0, D_01d9e6e8.p + 80);
}
}  // namespace n001fcd70

// 001fce30 (was gap)
namespace n001fce30 {
extern u8* D_01d9e6e8 asm("D_01d9e6e8");
extern f32 D_00354be0[] asm("D_00354be0");
extern u8 D_01dad890[] asm("D_01dad890");
extern u8 D_01dad8d0[] asm("D_01dad8d0");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
void sceVu0MulMatrix(u8*, u8*, u8*) asm("sceVu0MulMatrix");
void sceVu0ScaleVector(u8*, u8*, f32) asm("sceVu0ScaleVector");
void sceVu0ApplyMatrix(u8*, u8*, u8*) asm("sceVu0ApplyMatrix");
void func_001fce30(void) asm("func_001fce30");
void func_001fce30(void) {
    sceVu0ScaleVector(D_01dad890, D_01dad8d0, D_00354be0[0]);
    sceVu0ScaleVector(D_01dad890 + 16, D_01dad8d0 + 16, D_00354be0[1]);
    sceVu0ScaleVector(D_01dad890 + 32, D_01dad8d0 + 32, D_00354be0[2]);
    sceVu0ApplyMatrix(D_01dad890 + 48, D_01d9e840, D_01dad8d0 + 48);
    sceVu0ScaleVector(D_01d9e6e8 + 80, D_01d9e6e8 + 16, D_00354be0[0]);
    sceVu0ScaleVector(D_01d9e6e8 + 96, D_01d9e6e8 + 32, D_00354be0[1]);
    sceVu0ScaleVector(D_01d9e6e8 + 112, D_01d9e6e8 + 48, D_00354be0[2]);
    sceVu0ApplyMatrix(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    sceVu0MulMatrix(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
}  // namespace n001fce30

// 001fcf48 (was gap)
namespace n001fcf48 {
struct Prm {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; void* w68; s32 w72; u8 b76, b77; u8 pad78[2]; s32 pad80[4];
};
struct Slot { u8 pad[28]; u32* h; s32 w32; };
struct Sys { u8 pad[16]; Slot* slots; };
struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg1 { s32 w0; s32 idx; u8 b8, b9, b10; };
struct Arg2 { u8 pad[12]; s32* off; };
struct Col { u8 pad[8]; u8 r, g, b, a; };
extern Sys* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
s32 func_0020f1e0(u32*, Prm*, s32) asm("func_0020f1e0");
void func_001fcf48(u8* base, Arg1* a, Arg2* b) asm("func_001fcf48");
void func_001fcf48(u8* base, Arg1* a, Arg2* b) {
    Prm prm;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    Col* c = (Col*)(base + *b->off + 0xa0);
    prm.c27 = c->a;
    if (prm.c27 == 0) return;
    Slot* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    prm.flags = 0; if (a->b8 & 2) { prm.flags = 4; u32 h1a = *h & 1; if (!h1a) prm.flags |= 8; } else { if ((u8)(a->b8 & 1)) prm.flags = 128; u32 h1 = *h & 1; if (!h1) prm.flags |= 8; }
    if (!(*h & 2)) prm.flags |= 0x10;
    Sys2* g = D_01d9e6e8;
    *(u16*)((u8*)&prm + 8) = ((u16*)h)[0x16 / 2];
    prm.b10 = 0;
    prm.w28 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    prm.w68 = g->a80;
    prm.c24 = c->r;
    prm.c25 = c->g;
    prm.c26 = c->b;
    prm.p32 = g->a80;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    prm.p44 = g->a16;
    prm.w52 = D_01d9eaa4;
    prm.b76 = a->b9;
    prm.b77 = a->b10;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}  // namespace n001fcf48

// 001fd0d8 (was gap)
namespace n001fd0d8 {
struct Prm {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; void* w68; s32 w72; u8 b76, b77; u8 pad78[2]; s32 pad80[4];
};
struct Slot { u8 pad[28]; u32* h; s32 w32; };
struct Sys { u8 pad[16]; Slot* slots; };
struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg1 { s32 w0; s32 idx; u16 h8; u8 b10; };
struct Arg2 { u8 pad[12]; s32* off; };
struct Col { u8 pad[8]; u8 r, g, b, a; };
extern Sys* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern u8 D_01d9e980[] asm("D_01d9e980");
s32 func_0020f1e0(u32*, Prm*, s32) asm("func_0020f1e0");
void func_001fd0d8(u8* base, Arg1* a, Arg2* b) asm("func_001fd0d8");
void func_001fd0d8(u8* base, Arg1* a, Arg2* b) {
    Prm prm;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    Col* c = (Col*)(base + *b->off + 0xa0);
    prm.c27 = c->a;
    if (prm.c27 == 0) return;
    Slot* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    prm.flags = 0; if (a->b10 & 2) { prm.flags = 4; u32 h1a = *h & 1; if (!h1a) prm.flags |= 8; } else { if ((u8)(a->b10 & 1)) prm.flags = 128; u32 h1 = *h & 1; if (!h1) prm.flags |= 8; }
    if (!(*h & 2)) prm.flags |= 0x10;
    Sys2* g = D_01d9e6e8;
    *(u16*)((u8*)&prm + 8) = a->h8;
    prm.b10 = 0;
    prm.w28 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    prm.w68 = g->a80;
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
}  // namespace n001fd0d8

// 001fd260 (was gap)
namespace n001fd260 {
struct V { f32 a, b, c, d, e, f; };
void func_001fd260(u8* a0, u8* t) asm("func_001fd260");
void func_001fd260(u8* a0, u8* t) {
    V* v = (V*)(a0 + (*(s32**)(t + 12))[2] + 160);
    v->b = v->c = v->d = v->e = v->f = 0.0f;
    v->a = 0.0f;
}
}  // namespace n001fd260

// 001fd290 (was gap)
namespace n001fd290 {
struct V { f32 x, vx, ax, y, vy, ay; };
struct In { s32 id; s32 pad; f32 x, vx, ax, y, vy, ay; };
extern u32 D_01d9ea9c asm("D_01d9ea9c");
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_001fd290(u8* a0, In* in, u8* t) asm("func_001fd290");
void func_001fd290(u8* a0, In* in, u8* t) {
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
}  // namespace n001fd290

