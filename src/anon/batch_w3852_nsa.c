#include "../common/types.h"

/* GS XYOFFSET register */
typedef struct { u64 x:16; u64 p0:16; u64 y:16; u64 p1:16; } Ofs7e90;
typedef struct {
    union { Ofs7e90 b; u64 q; } ofs; /* 0x00 */
    u64 tex0;        /* 0x08 */
    void* cam;       /* 0x10 */
    void* mtx;       /* 0x14 */
    u8* pkt;         /* 0x18 */
    u8* mdl;         /* 0x1c */
    f32 scale;       /* 0x20 */
    s32 f36;         /* 0x24 */
    u64 rect;        /* 0x28 */
    void* col0;      /* 0x30 */
    void* col1;      /* 0x34 */
    u8* cache;       /* 0x38 */
    s32 f60;         /* 0x3c */
    s32 f64;         /* 0x40 */
    u8* pts;         /* 0x44 */
} Req7e90;
typedef struct {
    u64 tag[2];      /* 0x00 */
    u64 tex0, tex0a; /* 0x10 */
    u64 pad20[2];
    u64 alpha, alphaa; /* 0x30 */
    u64 pad40[2];
    u64 clamp, clampa; /* 0x50 */
    s32 v[3][4];     /* 0x60 */
    f32 c[3][4];     /* 0x90 */
    s32 xy[4];       /* 0xc0 */
    u8* cache;       /* 0xd0 */
} Buf7e90;
typedef struct { u8 b0; u8 kind; s16 n; u8 pad[12]; } Hdr7e90;
typedef struct { u8 c[12]; u16 idx[3]; u16 pad; } Tri7e90;
typedef struct { s16 x, y, z; } Pt7e90;
extern u64 D_00370220; /* GIF tag: NLOOP 1, EOP, 12 regs */
extern u64 D_00370228;
Buf7e90* func_0020eaf8(s32);
void func_0020ebd8(s32);
void func_0020e858(u8*, s32, s32, s32);

/* 001f7e90 (partMng): draws a model's triangle lists as GS packets. Sets up TEX0/ALPHA/CLAMP
 * registers and the VU0 camera/matrix state, then for each triangle copies its 3 vertices and
 * colours to a scratch buffer and runs the VU0 projection/clip block; visible triangles are
 * added to the ordering table (func_0020e858) by depth.
 * Partial asm: the two VU0 blocks are hand-written in the original (setup: matrix/scale loads;
 * per triangle: transform, perspective divide, clip test, packet stores, optional vertex cache),
 * written here as asm volatile with C operands; the four setup pointers are pinned to t4-t7 and
 * the clip result/cache pointer to t7/t6 because the original's asm used those registers. */
void func_001f7e90(Req7e90* r);  // 0x001f7e90: definition moved into src/anon/unit_001f7b40.cpp
