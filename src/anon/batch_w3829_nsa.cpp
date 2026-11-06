#include "../common/types.h"
extern "C" {

// 001aafe8: emits a GS sprite packet for one font glyph (tag, RGBAQ, UV, XYZ, UV, XYZ).
struct Tex1aafe8 { u8 pad[8]; s32 tw; s32 th; u8 pad2[2]; u8 cw; u8 ch; };
struct Q1aafe8 { s32 x, y, z, w; };
struct T1aafe8 { u64 tag, reg; };
struct Pkt1aafe8 { u8 pad[8]; Q1aafe8* cur; };
static inline void put1aafe8(Pkt1aafe8* p, s32 x, s32 y, s32 z, s32 w)
{
    p->cur->x = x;
    p->cur->y = y;
    p->cur->z = z;
    p->cur->w = w;
    p->cur++;
}
extern s32 D_00350a30;
s32 func_001aaf98(Tex1aafe8*, s32, s32, s32, s32);
u64 func_001aaea8(Tex1aafe8*, s32);
s32 func_001aafe8(Tex1aafe8* t, Pkt1aafe8* p, s32 x, s32 y, u32 color, s32 code, f32 scale, f32 aspect)
{
    y += D_00350a30;
    s32 w = (s32)(t->cw * 16 * scale * aspect);
    s32 h = (s32)(t->ch * 16 * scale);
    if (func_001aaf98(t, x, y, w, h)) return 0;
    s32 cols = (1 << t->tw) / t->cw;
    s32 rows = (1 << t->th) / t->ch;
    s32 u = code % cols * t->cw * 16 + 8;
    s32 v = code % (cols * rows) / cols * t->ch * 16 + 8;
    u64 tag = func_001aaea8(t, code);
    u32 g = (color >> 8) & 0xff;
    ((T1aafe8*)p->cur)->tag = tag;
    ((T1aafe8*)p->cur)->reg = 6;
    p->cur++;
    // Empty asm, no code: one extra reader of g (so g wins local-alloc over b: g=t5, b=t4)
    // and of the new p->cur, so sched2 issues it in an existing stall cycle.
    asm("" : "+r"(t) : "r"(g), "r"(p->cur));
    put1aafe8(p, color & 0xff, g, (color >> 16) & 0xff, color >> 24);
    put1aafe8(p, u, v, 0, 0);
    put1aafe8(p, x, y - h, 0, 0x8000);
    u += t->cw * 16;
    v += t->ch * 16;
    put1aafe8(p, u, v, 0, 0);
    put1aafe8(p, x + w, y, 0, 0);
    return 1;
}

}
