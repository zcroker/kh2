#include "../common/types.h"

struct MsgFont {
    u8 pad0[0x11];
    u8 height;          // 0x11
};
struct MsgStyle {
    s32 f0;
    f32 scale;          // 0x04
    f32 width;          // 0x08
    u32 color;          // 0x0c
};
struct MsgSize {
    union {
        s32 w;          // 0x00
        u8 b;           // (keeps loads/stores ordered like the original)
    };
    u32 h;              // 0x04
};

extern "C" {
u8* func_00192388(u8*);                 // next character
s32 func_00192440(u8*, s32);            // is control code
s32 func_00192450(u8*, s32);            // character code
void func_00192f98(MsgStyle*);
f32 func_00192fb8(MsgStyle*);           // scale * width
s32 func_001aae80(MsgFont*, s32);       // glyph width
s32 func_001aae90(u8);
s32 func_001ab820(MsgFont*);
u32 func_00313bc0(f32);                 // __fixunssfsi

u8* func_00192528(u8* p, MsgFont* font, MsgStyle* st, MsgSize* out) asm("_Z13func_00192528Pv");
u8* func_00192528(u8* p, MsgFont* font, MsgStyle* st, MsgSize* out) {
    out->w = 0;
    s32 prev = -1;
    s32 stop = 0;
    s32 adv;
    out->h = (s32)((f32)font->height * st->scale);
    while (p != 0 && *p != 0x10 && !stop) {
        if (func_00192440(p, 0)) {
            switch (*p) {
            case 1:
                adv = (s32)((f32)func_001ab820(font) * func_00192fb8(st) + 0.5f);
                out->w += adv;
                break;
            case 2:
                stop = 1;
                break;
            case 3:
                func_00192f98(st);
                break;
            case 9: {
                out->w += func_001aae90(p[1]);
                u32 h = func_00313bc0((f32)font->height * st->scale);
                out->h = h < out->h ? out->h : h;
                break;
            }
            case 10:
                st->scale = (f32)p[1] / (f32)font->height;
                break;
            case 11:
                st->width = (f32)p[1] / 100.0f;
                break;
            case 12:
                st->color = p[1];
                break;
            case 21:
                out->w += 32;
                break;
            case 22: {
                out->w += 32;
                u32 h = func_00313bc0((f32)font->height * st->scale);
                out->h = h < out->h ? out->h : h;
                break;
            }
            }
        } else {
            s32 c = func_00192450(p, 0);
            u32 w = func_001aae80(font, c);
            if (c == 0x46 && prev == c) {
                w -= 2;
            } else {
                prev = c;
            }
            f32 fw = (f32)w;
            f32 sw = fw * func_00192fb8(st);
            u32 h = (s32)((f32)font->height * st->scale);
            adv = (s32)(sw + 0.5f);
            out->w += adv;
            out->h = h < out->h ? out->h : h;
        }
        p = func_00192388(p);
    }
    return p;
}
}
