// Linked unit 0x1aaea8-0x1ab598 (YS file 0x1a8618-0x1abad8, part).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"

#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif

// 001aaea8 (from src/anon/batch_w1811.cpp)
namespace n001aaea8 {
struct W1811Tex { s32 fmt; s32 tbp; s32 tw; s32 th; u8 pad[2]; u8 dw; u8 dh; };
u64 func_001aaea8(W1811Tex* t, s32 n) asm("func_001aaea8");
u64 func_001aaea8(W1811Tex* t, s32 n) {
    s32 q = n / (((1 << t->tw) / t->dw) * ((1 << t->th) / t->dh));
    s32 cbp = 36;
    if (q >= 2) cbp = 44;
    s32 psm = (q & 1) + 8;
    switch (t->fmt) {
    case 0: case 1: case 2: case 5: break;
    case 3: psm += 2; break;
    case 4: psm += 4; break;
    }
    return (u64)t->tbp | ((u64)((1 << t->tw) / 64) << 14) | ((u64)cbp << 20) | ((u64)t->tw << 26) | ((u64)t->th << 30) | ((u64)1 << 34) | ((u64)0 << 35) | ((u64)0x3ffc << 37) | ((u64)0 << 51) | ((u64)0 << 55) | ((u64)psm << 56) | ((u64)0 << 61);
}
} // n001aaea8

// 001aaf98 (from src/anon/batch_w57.cpp)
namespace n001aaf98 {
u32 func_001aaf98(u32 z, s32 a, s32 b, s32 c, s32 d) asm("func_001aaf98");
u32 func_001aaf98(u32 z, s32 a, s32 b, s32 c, s32 d) {                        
    u32 r = 0;
    if (a + c < 0x7000 || a > 0x9000 || b < 0x7300 || b - d > 0x8d00) r = 1;
    return r;
}
} // n001aaf98

// 001aafe8 (from src/anon/batch_w3829_nsa.cpp)
namespace n001aafe8 {
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
static inline void ad1aafe8(Pkt1aafe8* p, u64 reg, u64 data)
{
    ((T1aafe8*)p->cur)->tag = data;
    ((T1aafe8*)p->cur)->reg = reg;
    p->cur++;
}
extern s32 D_00350a30 asm("D_00350a30");
s32 func_001aaf98(Tex1aafe8*, s32, s32, s32, s32) asm("func_001aaf98");
u64 func_001aaea8(Tex1aafe8*, s32) asm("func_001aaea8");
s32 func_001aafe8(Tex1aafe8* t, Pkt1aafe8* p, s32 x, s32 y, u32 color, s32 code, f32 scale, f32 aspect) asm("func_001aafe8");
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
    ad1aafe8(p, 6, func_001aaea8(t, code));
    put1aafe8(p, color & 0xff, (color >> 8) & 0xff, (color >> 16) & 0xff, color >> 24);
    put1aafe8(p, u, v, 0, 0);
    put1aafe8(p, x, y - h, 0, 0x8000);
    u += t->cw * 16;
    v += t->ch * 16;
    put1aafe8(p, u, v, 0, 0);
    put1aafe8(p, x + w, y, 0, 0);
    return 1;
}
} // n001aafe8

// 001ab260 (was whole asm in src/anon/asm_001ab260.s)
namespace n001ab260 {
struct Tex1ab260 { u8 pad[8]; s32 tw; s32 th; u8 pad2[2]; u8 cw; u8 ch; };
struct Q1ab260 { s32 x, y, z, w; };
struct T1ab260 { u64 tag, reg; };
struct Pkt1ab260 { u8 pad[8]; Q1ab260* cur; };
static inline void put1ab260(Pkt1ab260* p, s32 x, s32 y, s32 z, s32 w)
{
    p->cur->x = x;
    p->cur->y = y;
    p->cur->z = z;
    p->cur->w = w;
    p->cur++;
}
static inline void ad1ab260(Pkt1ab260* p, u64 reg, u64 data)
{
    ((T1ab260*)p->cur)->tag = data;
    ((T1ab260*)p->cur)->reg = reg;
    p->cur++;
}
extern s32 D_00350a30 asm("D_00350a30");
s32 func_001aaf98(Tex1ab260*, s32, s32, s32, s32) asm("func_001aaf98");
u64 func_001aaea8(Tex1ab260*, s32) asm("func_001aaea8");
// Slanted twin of 001aafe8: one glyph as a triangle strip (4 UV/XYZ pairs); returns 0 when clipped.
// The glyph number is copied to a local and the parameter is then used as a scratch variable: cleared
// at the top (a dead store) and later set to the texel width (cw - 1) * 16. The parameter's pseudo so
// has two lives (the entry copy from t1, then the width) and is allocated globally with a preference
// for its incoming register t1: the width lands in t1, tied neither to cw - 1 (t7) nor to u2 (t2).
// Without the `c = 0` the copy is forwarded back into the parameter and it takes s0 for the whole
// function. (Same code without the dead store: -fno-gcse -fno-cse-follow-jumps -fno-cse-skip-blocks.)
s32 func_001ab260(Tex1ab260* t, Pkt1ab260* p, s32 x, s32 y, u32 color, s32 c, s32 slant, f32 scale, f32 aspect) asm("func_001ab260");
s32 func_001ab260(Tex1ab260* t, Pkt1ab260* p, s32 x, s32 y, u32 color, s32 c, s32 slant, f32 scale, f32 aspect)
{
    s32 code = c;
    c = 0;
    y += D_00350a30;
    s32 w = (s32)(t->cw * 16 * scale * aspect);
    s32 h = (s32)(t->ch * 16 * scale);
    if (func_001aaf98(t, x, y, w + slant, h)) return 0;
    s32 cols = (1 << t->tw) / t->cw;
    s32 rows = (1 << t->th) / t->ch;
    s32 v = code % (cols * rows) / cols * t->ch * 16 + 8;
    s32 u = code % cols * t->cw * 16 + 8;
    ad1ab260(p, 6, func_001aaea8(t, code));
    put1ab260(p, color & 0xff, (color >> 8) & 0xff, (color >> 16) & 0xff, color >> 24);
    c = (t->cw - 1) << 4;
    s32 u2 = u + c;
    s32 v2 = v + t->ch * 16;
    put1ab260(p, u, v, 0, 0);
    put1ab260(p, x + slant, y - h, 0, 0x8000);
    put1ab260(p, u2, v, 0, 0);
    put1ab260(p, x + w + slant, y - h, 0, 0x8000);
    put1ab260(p, u, v2, 0, 0);
    put1ab260(p, x - slant, y, 0, 0);
    put1ab260(p, u2, v2, 0, 0);
    put1ab260(p, x + w - slant, y, 0, 0);
    return 1;
}
} // n001ab260
