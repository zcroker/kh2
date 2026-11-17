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
s32 func_001aafe8(Tex1aafe8* t, Pkt1aafe8* p, s32 x, s32 y, u32 color, s32 code, f32 scale, f32 aspect);  // 0x001aafe8: definition moved into src/anon/unit_001aaea8.cpp

}
