// 00238c90: sprite draw into a GIF packet. Builds -O2 -fno-strict-aliasing (_nsa).
// The prologue statement order places the ox*16 spill store before the packet constructor stores.
// GIF tag word 0 is a chain of separate u64 values (nreg, prim, pre): with bitfields the PRIM and REGS10 constants swap registers.
#include "../common/types.h"

extern "C" {

// Sprite cell: texture rectangle and four corner colors.
struct W1700Cell {
    s32 id;      // 0x00
    s32 u0;      // 0x04
    s32 v0;      // 0x08
    s32 u1;      // 0x0c
    s32 v1;      // 0x10
    u8 pad14[8]; // 0x14
    u32 col[4];  // 0x1c
};

// Screen rectangle of one sprite piece.
struct W1700Piece {
    s32 x0, y0, x1, y1; // 0x00
    s32 cell;           // 0x10
};

struct W1700Sprite {
    u8 pad0[4];
    W1700Cell* cells;   // 0x04
    u8 pad8[8];
    u32 flags;          // 0x10
    W1700Piece* pieces; // 0x14
    s32 count;          // 0x18
    f32 m00, m01;       // 0x1c
    f32 m10, m11;       // 0x24
    f32 sx, sy;         // 0x2c
    u8 pad34[0x6c - 0x34];
    f32 alpha;          // 0x6c
    u8 pad70[0x88 - 0x70];
    s32 colorMode;      // 0x88
    s32 x;              // 0x8c
    s32 y;              // 0x90
    s32 ox;             // 0x94
    s32 oy;             // 0x98
    s32 z;              // 0x9c
    u16 u[4];           // 0xa0
    u16 v[4];           // 0xa8
};

// GS packed vertex: UV, A+D RGBAQ, XYZF2.
struct W1700Vtx {
    s32 u, v;   // 0x00
    u8 pad8[8];
    u64 rgba;   // 0x10
    u64 adreg;  // 0x18
    s32 x, y;   // 0x20
    s32 z;      // 0x28
    s32 adc;    // 0x2c
};

struct W1700GifTag {
    u64 nloop : 15; u64 eop : 1; u64 pad16 : 30; u64 pre : 1; u64 prim : 11; u64 flg : 2; u64 nreg : 4;
    u64 r0 : 4, r1 : 4, r2 : 4, r3 : 4, r4 : 4, r5 : 4, r6 : 4, r7 : 4;
    u64 r8 : 4, r9 : 4, r10 : 4, r11 : 4, r12 : 4, r13 : 4, r14 : 4, r15 : 4;
};

struct W1700Pkt {
    u8* base;
    u32 b;
    u32 c;
    W1700Pkt() { c = 0; b = 0; base = 0; }
};

void func_001b7e68(W1700Pkt*, s32);
void* func_001b7ff8(W1700Pkt*, s32);
void func_001b80d8(W1700Pkt*);
void func_001b7f30(W1700Pkt*);
u32 func_00233708(u32, s32);
u32 func_002338a8(f32, u32);

void YI__SPRITE___Draw2(W1700Sprite* s, s32 x, s32 y, s32 ox, s32 oy);  // 0x00238c90: definition moved into src/anon/unit_002384f8.cpp

}
