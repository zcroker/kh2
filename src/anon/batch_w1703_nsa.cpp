#include "../common/types.h"
// Nine-slice (3x3) panel layout: sizes the current frame to (w, h) rounded down to even,
// centred on the origin, then places the nine parts: corners keep their size, edges stretch.
// Needs -fno-strict-aliasing (stack-slot order of the spilled locals).
extern "C" {
struct W1703Frame { u16 sprite; u16 pad2; u8 pad4[12]; s32 w; s32 h; u8 pad18[12]; };
struct W1703Sprite { u32 pad0; void* parts; u8 pad8[0x88]; };
struct W1703Layout { u8 pad0[0xb0]; W1703Sprite* sprites; W1703Frame* frames; u8 padb8[0x5c]; s32 cur; };
s32 func_00237508(void*, void*, s32);
s32 func_00237578(void*, void*, s32);
void func_00237458(void*, void*, s32, s32);
void func_002374c8(void*, void*, s32, s32);
void func_00237540(void*, void*, s32, s32);
void func_002375b0(void*, void*, s32, s32);
void func_00237640(void*, void*, s32, s32, s32);

// parts: 0..8 = TL, T, TR, L, C, R, BL, B, BR
void func_0023bc58(W1703Layout* l, s32 w, s32 h) {
    s32 w0, h0, h1, h2, w3, w6;
    W1703Frame* f = &l->frames[l->cur];
    h = (h + f->h) & ~1;
    w = (w + f->w) & ~1;
    s32 hw = w >> 1; s32 hh = h >> 1;
    W1703Sprite* sp = &l->sprites[f->sprite];
    void* o = sp->parts;
    w0 = func_00237508(l, o, 0);
    h0 = func_00237578(l, o, 0);
    h1 = func_00237578(l, o, 1);
    h2 = func_00237578(l, o, 2);
    w3 = func_00237508(l, o, 3);
    w6 = func_00237508(l, o, 6);
    s32 y = -h / 2;
    s32 x = -w / 2;
    s32 y0 = y - h0; s32 x6 = x - w6; s32 x0 = x - w0; s32 y1 = y - h1; s32 y2 = y - h2;
    func_00237458(l, o, 0, x0);
    func_002374c8(l, o, 0, y0);
    func_00237458(l, o, 1, x);
    func_002374c8(l, o, 1, y1);
    s32 x3 = x - w3;
    func_00237540(l, o, 1, w);
    func_00237458(l, o, 2, hw);
    func_002374c8(l, o, 2, y2);
    func_00237458(l, o, 3, x3);
    func_002374c8(l, o, 3, y);
    func_002375b0(l, o, 3, h);
    func_00237458(l, o, 4, x);
    func_002374c8(l, o, 4, y);
    func_00237640(l, o, 4, w, h);
    func_00237458(l, o, 5, hw);
    func_002374c8(l, o, 5, y);
    func_002375b0(l, o, 5, h);
    func_00237458(l, o, 6, x6);
    func_002374c8(l, o, 6, hh);
    func_00237458(l, o, 7, x);
    func_002374c8(l, o, 7, hh);
    func_00237540(l, o, 7, w);
    func_00237458(l, o, 8, hw);
    func_002374c8(l, o, 8, hh);
}
}
