#include "../common/types.h"

static inline u64 W3728GifTag(u32 nloop, u32 eop, u32 pre, u32 prim, u32 flg, u32 nreg)
{
    return (u64)nloop | ((u64)eop << 15) | ((u64)pre << 46) |
           ((u64)prim << 47) | ((u64)flg << 58) | ((u64)nreg << 60);
}

extern "C" {

struct W3728Pkt { u8* start; u32 pad; u8* cur; };

struct W3728Spr { s32 x0, y0, x1, y1, tex; };

struct W3728Tex {
    u32 pad0;
    s32 u0, v0, u1, v1;
    u8 pad14[0x1c - 0x14];
    u32 tex0;
    u8 pad20[0x2c - 0x20];
};

struct W3728Obj {
    u32 pad0;
    W3728Tex* texs;
    u8 pad8[0x10 - 0x8];
    u32 flags;
    W3728Spr* sprs;
    s32 num;
    u8 pad1c[0x2c - 0x1c];
    f32 sx;
    f32 sy;
    u8 pad34[0x6c - 0x34];
    f32 alpha;
    u8 pad70[0x88 - 0x70];
    s32 clut;
    u8 pad8c[0x9c - 0x8c];
    s32 z;
};

struct W3728Vtx { s32 u, v, pad0, pad1; s32 x, y, z, adc; };
struct W3728Quad { u64 tex0; u64 rgba; W3728Vtx v[2]; };

void func_001b7e68(W3728Pkt*, s32);
void func_001b7ff8(W3728Pkt*, s32);
void func_001b80d8(W3728Pkt*);
void func_001b7f30(W3728Pkt*);
u32 func_00233708(u32, s32);
u32 func_002338a8(f32, u32);

// Builds a GIF packet of textured sprites for a 2D object (one quad per sprite).
void func_00239250(W3728Obj* obj, s32 x, s32 y, s32 ox, s32 oy);  // 0x00239250: definition moved into src/anon/unit_002384f8.cpp

}
