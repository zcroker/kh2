#include "../common/types.h"

struct W1699Pkt { u8* start; u8* end; u8* cur; };
struct W1699AD { u64 data; u64 addr; };
struct W1699UV { s32 u, v, pad0, pad1; };
struct W1699XYZ { s32 x, y, z, adc; };
struct W1699Vtx { W1699UV uv; W1699AD rgba; W1699XYZ xyz; };
struct W1699Quad { W1699AD clamp; W1699Vtx v[4]; };
struct W1699GifTag { u64 tag; u64 regs; };

struct W1699Rect { s32 pad0; s32 u0, v0, u1, v1; f32 su, sv; u32 col[4]; };
struct W1699Spr { s32 x0, y0, x1, y1; s32 rect; };
struct W1699Tex { u8 pad0[8]; s32 w, h; };
struct W1699Obj {
    u8 pad0[4];
    W1699Rect* rects;   /* 0x04 */
    u8 pad8[8];
    u32 flags;          /* 0x10 */
    W1699Spr* sprs;     /* 0x14 */
    s32 count;          /* 0x18 */
    f32 m[4];           /* 0x1c */
    f32 sx, sy;         /* 0x2c */
    u8 pad34[0xc];
    W1699Tex* tex;      /* 0x40 */
    u8 pad44[4];
    f32 time;           /* 0x48 */
    u8 pad4c[0x20];
    f32 alpha;          /* 0x6c */
    u8 pad70[0x18];
    s32 colArg;         /* 0x88 */
    s32 a1, a2, a3, a4; /* 0x8c */
    s32 z;              /* 0x9c */
    u16 ovU[4];
    u16 ovV[4];
    u32 NoScale() { return (flags >> 4) & 1; }
    u32 NoRot() { return (flags >> 3) & 1; }
    u32 RawCol() { return (flags >> 5) & 1; }

};

#define W1699_CLAMP(wms, wmt, minu, maxu, minv, maxv) \
    ((u64)(wms) | ((u64)(wmt) << 2) | ((u64)(minu) << 4) | ((u64)(maxu) << 14) | \
     ((u64)(minv) << 24) | ((u64)(maxv) << 34))

static inline u64 W1699Regs(u64 r0, u64 r1, u64 r2, u64 r3, u64 r4, u64 r5, u64 r6,
                            u64 r7, u64 r8, u64 r9, u64 r10, u64 r11, u64 r12)
{
    return r0 | (r1 << 4) | (r2 << 8) | (r3 << 12) | (r4 << 16) | (r5 << 20) | (r6 << 24) |
           (r7 << 28) | (r8 << 32) | (r9 << 36) | (r10 << 40) | (r11 << 44) | (r12 << 48);
}
static inline u64 W1699Tag(u32 nloop, u32 eop, u32 pre, u32 prim, u32 flg, u32 nreg)
{
    return (u64)(nloop | (eop << 15)) | ((u64)flg << 58) | ((u64)prim << 47) | ((u64)pre << 46) | ((u64)nreg << 60);
}

extern "C" {
void func_001b7e68(W1699Pkt*, s32);
void func_001b7f30(W1699Pkt*);
void func_001b7ff8(W1699Pkt*, s32);
void func_001b80d8(W1699Pkt*);
u32 func_00233708(u32, s32);
u32 func_002338a8(f32, u32);

/* Build a GIF packet of textured sprite quads (UV scroll, rotation, per-vertex colour) for a 2D layout object. */
void func_00238570(W1699Obj* obj, s32 a1, s32 a2, s32 a3, s32 a4);  // 0x00238570: definition moved into src/anon/unit_002384f8.cpp
}
