// Linked unit 0x00237d38-0x00239988: YI::SPRITE draw tail, YI::SEQUENCE ctor/dtor and the GS packet setup.
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00237d38 (was unwritten gap: YI::SPRITE redraw at the stored position, twin of 0x238570)
namespace n00237d38 {
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
    u8 pad70[0xc];
    f32 scale;          /* 0x7c */
    f32 scx, scy;       /* 0x80 */
    s32 colArg;         /* 0x88 */
    s32 a1, a2, a3, a4; /* 0x8c */
    s32 z;              /* 0x9c */
    u16 ovU[4];
    u16 ovV[4];
    u32 B0() { return flags & 1; }
    u32 B1() { return (flags >> 1) & 1; }
    u32 B2() { return (flags >> 2) & 1; }
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
void func_001b7e68(W1699Pkt*, s32) asm("func_001b7e68");
void func_001b7f30(W1699Pkt*) asm("func_001b7f30");
void func_001b7ff8(W1699Pkt*, s32) asm("func_001b7ff8");
void func_001b80d8(W1699Pkt*) asm("func_001b80d8");
u32 func_00233708(u32, s32) asm("func_00233708");
u32 func_002338a8(f32, u32) asm("func_002338a8");
s32 func_002f35e8(s32) asm("func_002f35e8");
void func_002f3918(s32, void*) asm("func_002f3918");
extern u64 D_0035e3c0[6] asm("D_0035e3c0");
extern u64 D_0035e3f0[10] asm("D_0035e3f0");
void func_00237d38(W1699Obj* obj) asm("func_00237d38");
void func_00237d38(W1699Obj* obj)
{
    s32 u[2], v[2];
    s32 cx, cy, oy, ox;
    W1699Pkt pk;
    f32 sx, sy;
    s32 i;
    W1699Spr* spr;
    W1699Quad* q;
    W1699GifTag* tag;
    s32 adc;

    if ((u32)(obj->a1 + 512) > 1536) return;
    if (obj->a2 < -416) return;
    if (obj->a2 > 832) return;
    if (obj->B0()) {
        u8* p = (u8*)obj->tex + 256;
        func_002f3918(func_002f35e8(2), p);
    }
    if (obj->B1()) func_002f3918(func_002f35e8(2), D_0035e3c0);
    cx = (obj->a1 << 4) + 0x7000;
    cy = (obj->a2 << 4) + 0x7300;
    ox = obj->a3 << 4;
    oy = obj->a4 << 4;
    if (!obj->NoScale()) {
        sx = obj->scale * obj->scx;
        sy = obj->scale * obj->scy;
    } else {
        sy = 1.0f;
        sx = sy;
    }
    pk.cur = 0;
    pk.end = 0;
    pk.start = 0;
    func_001b7e68(&pk, obj->count * 13 + 1);
    tag = (W1699GifTag*)(pk.start + 0x10);
    q = (W1699Quad*)(pk.start + 0x20);
    spr = obj->sprs;
    adc = 0x8000;
    for (i = obj->count; i > 0; i--, spr++, q++) {
        W1699Rect* r;
        f32 x0, y0, x1, y1;

        r = &obj->rects[spr->rect];
        x0 = (f32)((spr->x0 << 4) + ox) * sx;
        y0 = (f32)((spr->y0 << 4) + oy) * sy;
        x1 = (f32)((spr->x1 << 4) + ox) * sx;
        y1 = (f32)((spr->y1 << 4) + oy) * sy;
        u[0] = (r->u0 << 4) + 8;
        v[0] = (r->v0 << 4) + 8;
        u[1] = (r->u1 << 4) + 8;
        v[1] = (r->v1 << 4) + 8;

        q->clamp.addr = 8;
        q->v[0].rgba.addr = 1;
        q->v[0].xyz.z = obj->z;
        q->v[1].rgba.addr = 1;
        q->v[0].xyz.adc = adc;
        q->v[1].xyz.z = obj->z;
        q->v[1].xyz.adc = adc;
        q->v[2].rgba.addr = 1;
        q->v[2].xyz.z = obj->z;
        q->v[2].xyz.adc = 0;
        q->v[3].rgba.addr = 1;
        q->v[3].xyz.z = obj->z;
        q->v[3].xyz.adc = 0;

        if (r->su != 0.0f || r->sv != 0.0f) {
            f32 t = obj->time;
            s32 du = (s32)(r->su * t * (f32)(obj->tex->w << 4)) & 0x1fff;
            s32 dv = (s32)(r->sv * t * (f32)(obj->tex->h << 4)) & 0x1fff;
            u[0] += du;
            v[0] += dv;
            u[1] += du;
            v[1] += dv;
            q->clamp.data = W1699_CLAMP(3, 3, (u32)(r->u1 - r->u0), (u32)r->u0,
                                        (u32)(r->v1 - r->v0), (u32)r->v0);
        } else {
            q->clamp.data = 0;
        }

        if (!obj->NoRot()) {
            f32 m0 = obj->m[0];
            f32 m2 = obj->m[2];
            f32 m1 = obj->m[1];
            f32 m3 = obj->m[3];
            q->v[0].xyz.x = cx + (s32)(x0 * m0 + y0 * m2);
            q->v[0].xyz.y = cy + (s32)(x0 * m1 + y0 * m3);
            q->v[1].xyz.x = cx + (s32)(x1 * m0 + y0 * m2);
            q->v[1].xyz.y = cy + (s32)(x1 * m1 + y0 * m3);
            q->v[2].xyz.x = cx + (s32)(x0 * m0 + y1 * m2);
            q->v[2].xyz.y = cy + (s32)(x0 * m1 + y1 * m3);
            q->v[3].xyz.x = cx + (s32)(x1 * m0 + y1 * m2);
            q->v[3].xyz.y = cy + (s32)(x1 * m1 + y1 * m3);
        } else {
            q->v[0].xyz.x = q->v[2].xyz.x = cx + (s32)x0;
            q->v[0].xyz.y = q->v[1].xyz.y = cy + (s32)y0;
            q->v[1].xyz.x = q->v[3].xyz.x = cx + (s32)x1;
            q->v[2].xyz.y = q->v[3].xyz.y = cy + (s32)y1;
        }

        if (!obj->RawCol()) {
            if (obj->alpha == 1.0f) {
                q->v[0].rgba.data = func_00233708(r->col[0], obj->colArg);
                q->v[1].rgba.data = func_00233708(r->col[1], obj->colArg);
                q->v[2].rgba.data = func_00233708(r->col[2], obj->colArg);
                q->v[3].rgba.data = func_00233708(r->col[3], obj->colArg);
            } else {
                q->v[0].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[0], obj->colArg));
                q->v[1].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[1], obj->colArg));
                q->v[2].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[2], obj->colArg));
                q->v[3].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[3], obj->colArg));
            }
        } else {
            q->v[0].rgba.data = r->col[0];
            q->v[1].rgba.data = r->col[1];
            q->v[2].rgba.data = r->col[2];
            q->v[3].rgba.data = r->col[3];
        }

        if (!(obj->flags & 0x40)) {
            q->v[0].uv.u = q->v[2].uv.u = u[0];
            q->v[0].uv.v = q->v[1].uv.v = v[0];
            q->v[1].uv.u = q->v[3].uv.u = u[1];
            q->v[2].uv.v = q->v[3].uv.v = v[1];
        } else {
            q->v[0].uv.u = (obj->ovU[0] << 4) + 8;
            q->v[0].uv.v = (obj->ovV[0] << 4) + 8;
            q->v[1].uv.u = (obj->ovU[1] << 4) + 8;
            q->v[1].uv.v = (obj->ovV[1] << 4) + 8;
            q->v[2].uv.u = (obj->ovU[2] << 4) + 8;
            q->v[2].uv.v = (obj->ovV[2] << 4) + 8;
            q->v[3].uv.u = (obj->ovU[3] << 4) + 8;
            q->v[3].uv.v = (obj->ovV[3] << 4) + 8;
        }
    }
    tag->tag = W1699Tag(obj->count, 1, 1, 0x15c, 0, 13);
    tag->regs = W1699Regs(0xE, 3, 0xE, 4, 3, 0xE, 4, 3, 0xE, 4, 3, 0xE, 4);
    func_001b7ff8(&pk, obj->count * 13 + 1);
    func_001b80d8(&pk);
    if (obj->B2()) func_002f3918(func_002f35e8(2), D_0035e3f0);
    func_001b7f30(&pk);
}
}  // namespace n00237d38

// 002384f8 (was src/anon/batch_w36.cpp)
namespace n002384f8 {
// 0x00234348: definition moved into src/anon/unit_002335e8.cpp

struct Key44 { u8 pad[20]; f32 x, y; u8 pad2[16]; };
struct Ref20 { u8 pad[16]; s32 idx; };
struct Tbl { u32 pad; Key44* keys; Ref20* refs; u16* ranges; };
/*TARGET 002384f8*/
s32 func_002384f8(Tbl* t, s32 i) asm("func_002384f8");
s32 func_002384f8(Tbl* t, s32 i) {
    u16* r = &t->ranges[i * 2];
    Ref20* e = &t->refs[r[0]];
    s32 n = r[1];
    for (; n > 0; n--, e++) {
        Key44* k = &t->keys[e->idx];
        if (k->x != 0.0f || k->y != 0.0f) return 1;
    }
    return 0;
}
}  // namespace n002384f8

// 00238570 (was src/anon/batch_w2476_nsa.cpp)
namespace n00238570 {
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
void func_001b7e68(W1699Pkt*, s32) asm("func_001b7e68");
void func_001b7f30(W1699Pkt*) asm("func_001b7f30");
void func_001b7ff8(W1699Pkt*, s32) asm("func_001b7ff8");
void func_001b80d8(W1699Pkt*) asm("func_001b80d8");
u32 func_00233708(u32, s32) asm("func_00233708");
u32 func_002338a8(f32, u32) asm("func_002338a8");
/*TARGET 00238570*/
/* Build a GIF packet of textured sprite quads (UV scroll, rotation, per-vertex colour) for a 2D layout object. */
void func_00238570(W1699Obj* obj, s32 a1, s32 a2, s32 a3, s32 a4) asm("func_00238570");
/* Build a GIF packet of textured sprite quads (UV scroll, rotation, per-vertex colour) for a 2D layout object. */
void func_00238570(W1699Obj* obj, s32 a1, s32 a2, s32 a3, s32 a4)
{
    s32 cx, cy, oy, ox;
    W1699Pkt pk;
    f32 sx, sy;
    s32 i;
    s32 adc;
    W1699Spr* spr;
    W1699Quad* q;
    W1699GifTag* tag;

    obj->a1 = a1;
    obj->a2 = a2;
    obj->a3 = a3;
    obj->a4 = a4;
    cx = (a1 << 4) + 0x7000;
    cy = (a2 << 4) + 0x7300;
    ox = a3 << 4;
    oy = a4 << 4;
    if (!obj->NoScale()) {
        sx = obj->sx;
        sy = obj->sy;
    } else {
        sy = 1.0f;
        sx = sy;
    }
    pk.cur = 0;
    pk.end = 0;
    pk.start = 0;
    func_001b7e68(&pk, obj->count * 13 + 1);
    tag = (W1699GifTag*)(pk.start + 0x10);
    q = (W1699Quad*)(pk.start + 0x20);
    spr = obj->sprs;
    adc = 0x8000;
    for (i = obj->count; i > 0; i--, spr++, q++) {
        W1699Rect* r;
        f32 x0, y0, x1, y1;

        q->v[0].rgba.addr = 1;
        q->clamp.addr = 8;
        q->v[0].xyz.z = obj->z;
        q->v[1].rgba.addr = 1;
        q->v[0].xyz.adc = adc;
        q->v[1].xyz.z = obj->z;
        q->v[1].xyz.adc = adc;
        q->v[2].rgba.addr = 1;
        q->v[2].xyz.z = obj->z;
        q->v[2].xyz.adc = 0;
        q->v[3].rgba.addr = 1;
        q->v[3].xyz.z = obj->z;
        q->v[3].xyz.adc = 0;

        r = &obj->rects[spr->rect];
        if ((r->su != 0.0f || r->sv != 0.0f) && !(obj->flags & 0x40)) {
            f32 t = obj->time;
            s32 du = (s32)(r->su * t * (f32)(obj->tex->w << 4)) & 0x1fff;
            s32 dv = (s32)(r->sv * t * (f32)(obj->tex->h << 4)) & 0x1fff;
            q->v[0].uv.u = q->v[2].uv.u = (r->u0 << 4) + du + 8;
            q->v[0].uv.v = q->v[1].uv.v = (r->v0 << 4) + dv + 8;
            q->v[1].uv.u = q->v[3].uv.u = (r->u1 << 4) + du + 8;
            q->v[2].uv.v = q->v[3].uv.v = (r->v1 << 4) + dv + 8;
            q->clamp.data = W1699_CLAMP(3, 3, (u32)(r->u1 - r->u0), (u32)r->u0,
                                        (u32)(r->v1 - r->v0), (u32)r->v0);
        } else {
            if (!(obj->flags & 0x40)) {
                q->v[0].uv.u = q->v[2].uv.u = (r->u0 << 4) + 8;
                q->v[0].uv.v = q->v[1].uv.v = (r->v0 << 4) + 8;
                q->v[1].uv.u = q->v[3].uv.u = (r->u1 << 4) + 8;
                q->v[2].uv.v = q->v[3].uv.v = (r->v1 << 4) + 8;
            } else {
                q->v[0].uv.u = (obj->ovU[0] << 4) + 8;
                q->v[0].uv.v = (obj->ovV[0] << 4) + 8;
                q->v[1].uv.u = (obj->ovU[1] << 4) + 8;
                q->v[1].uv.v = (obj->ovV[1] << 4) + 8;
                q->v[2].uv.u = (obj->ovU[2] << 4) + 8;
                q->v[2].uv.v = (obj->ovV[2] << 4) + 8;
                q->v[3].uv.u = (obj->ovU[3] << 4) + 8;
                q->v[3].uv.v = (obj->ovV[3] << 4) + 8;
            }
            q->clamp.data = 0;
        }

        x0 = (f32)((spr->x0 << 4) + ox) * sx;
        y0 = (f32)((spr->y0 << 4) + oy) * sy;
        x1 = (f32)((spr->x1 << 4) + ox) * sx;
        y1 = (f32)((spr->y1 << 4) + oy) * sy;
        if (!obj->NoRot()) {
            f32 m0 = obj->m[0];
            f32 m2 = obj->m[2];
            f32 m1 = obj->m[1];
            f32 m3 = obj->m[3];
            q->v[0].xyz.x = cx + (s32)(x0 * m0 + y0 * m2);
            q->v[0].xyz.y = cy + (s32)(x0 * m1 + y0 * m3);
            q->v[1].xyz.x = cx + (s32)(x1 * m0 + y0 * m2);
            q->v[1].xyz.y = cy + (s32)(x1 * m1 + y0 * m3);
            q->v[2].xyz.x = cx + (s32)(x0 * m0 + y1 * m2);
            q->v[2].xyz.y = cy + (s32)(x0 * m1 + y1 * m3);
            q->v[3].xyz.x = cx + (s32)(x1 * m0 + y1 * m2);
            q->v[3].xyz.y = cy + (s32)(x1 * m1 + y1 * m3);
        } else {
            q->v[0].xyz.x = q->v[2].xyz.x = cx + (s32)x0;
            q->v[0].xyz.y = q->v[1].xyz.y = cy + (s32)y0;
            q->v[1].xyz.x = q->v[3].xyz.x = cx + (s32)x1;
            q->v[2].xyz.y = q->v[3].xyz.y = cy + (s32)y1;
        }

        if (!obj->RawCol()) {
            if (obj->alpha == 1.0f) {
                q->v[0].rgba.data = func_00233708(r->col[0], obj->colArg);
                q->v[1].rgba.data = func_00233708(r->col[1], obj->colArg);
                q->v[2].rgba.data = func_00233708(r->col[2], obj->colArg);
                q->v[3].rgba.data = func_00233708(r->col[3], obj->colArg);
            } else {
                q->v[0].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[0], obj->colArg));
                q->v[1].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[1], obj->colArg));
                q->v[2].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[2], obj->colArg));
                q->v[3].rgba.data = func_002338a8(obj->alpha, func_00233708(r->col[3], obj->colArg));
            }
        } else {
            q->v[0].rgba.data = r->col[0];
            q->v[1].rgba.data = r->col[1];
            q->v[2].rgba.data = r->col[2];
            q->v[3].rgba.data = r->col[3];
        }
    }
    tag->tag = W1699Tag(obj->count, 1, 1, 0x15c, 0, 13);
    tag->regs = W1699Regs(0xE, 3, 0xE, 4, 3, 0xE, 4, 3, 0xE, 4, 3, 0xE, 4);
    func_001b7ff8(&pk, obj->count * 13 + 1);
    func_001b80d8(&pk);
    func_001b7f30(&pk);
}
}  // namespace n00238570

// 00238c90 (was src/anon/batch_w3881_nsa.cpp)
namespace n00238c90 {
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
void func_001b7e68(W1700Pkt*, s32) asm("func_001b7e68");
void* func_001b7ff8(W1700Pkt*, s32) asm("func_001b7ff8");
void func_001b80d8(W1700Pkt*) asm("func_001b80d8");
void func_001b7f30(W1700Pkt*) asm("func_001b7f30");
u32 func_00233708(u32, s32) asm("func_00233708");
u32 func_002338a8(f32, u32) asm("func_002338a8");
/*TARGET 00238c90*/
void func_00238c90(W1700Sprite* s, s32 x, s32 y, s32 ox, s32 oy) asm("func_00238c90");
void func_00238c90(W1700Sprite* s, s32 x, s32 y, s32 ox, s32 oy) {
    s32 sox, soy, bx, by;
    s->x = x;
    s->y = y;
    s->oy = oy;
    bx = x * 16 + 0x7000;
    by = y * 16 + 0x7300;
    s->ox = ox;
    sox = ox * 16;
    W1700Pkt pkt;
    soy = oy * 16;
    func_001b7e68(&pkt, s->count * 12 + 1);
    W1700GifTag* tag = (W1700GifTag*)(pkt.base + 0x10);
    W1700Vtx* q = (W1700Vtx*)(pkt.base + 0x20);
    W1700Piece* pc = s->pieces;
    s32 n = s->count;
    s32 i;
    for (i = n; i > 0; i--, pc++, q += 4) {
        q[0].adreg = 1;
        q[0].z = s->z;
        q[0].adc = 0x8000;
        q[1].adreg = 1;
        q[1].z = s->z;
        q[1].adc = 0x8000;
        q[2].adreg = 1;
        q[2].z = s->z;
        q[2].adc = 0;
        q[3].adreg = 1;
        q[3].z = s->z;
        q[3].adc = 0;
        W1700Cell* c = &s->cells[pc->cell];
        if (!(s->flags & 0x40)) {
            q[0].u = q[2].u = c->u0 * 16 + 8;
            q[0].v = q[1].v = c->v0 * 16 + 8;
            q[1].u = q[3].u = c->u1 * 16 + 8;
            q[2].v = q[3].v = c->v1 * 16 + 8;
        } else {
            q[0].u = s->u[0] * 16 + 8;
            q[0].v = s->v[0] * 16 + 8;
            q[1].u = s->u[1] * 16 + 8;
            q[1].v = s->v[1] * 16 + 8;
            q[2].u = s->u[2] * 16 + 8;
            q[2].v = s->v[2] * 16 + 8;
            q[3].u = s->u[3] * 16 + 8;
            q[3].v = s->v[3] * 16 + 8;
        }
        f32 x0 = pc->x0 * 16 + sox;
        f32 y0 = pc->y0 * 16 + soy;
        f32 x1 = pc->x1 * 16 + sox;
        f32 y1 = pc->y1 * 16 + soy;
        if (((s->flags >> 4) & 1) == 0) {
            x0 *= s->sx;
            y0 *= s->sy;
            x1 *= s->sx;
            y1 *= s->sy;
        }
        if (((s->flags >> 3) & 1) == 0) {
            f32 m00 = s->m00, m10 = s->m10, m01 = s->m01, m11 = s->m11;
            q[0].x = bx + (s32)(x0 * m00 + y0 * m10);
            q[0].y = by + (s32)(x0 * m01 + y0 * m11);
            q[1].x = bx + (s32)(x1 * m00 + y0 * m10);
            q[1].y = by + (s32)(x1 * m01 + y0 * m11);
            q[2].x = bx + (s32)(x0 * m00 + y1 * m10);
            q[2].y = by + (s32)(x0 * m01 + y1 * m11);
            q[3].x = bx + (s32)(x1 * m00 + y1 * m10);
            q[3].y = by + (s32)(x1 * m01 + y1 * m11);
        } else {
            q[0].x = q[2].x = bx + (s32)x0;
            q[0].y = q[1].y = by + (s32)y0;
            q[1].x = q[3].x = bx + (s32)x1;
            q[2].y = q[3].y = by + (s32)y1;
        }
        if (((s->flags >> 5) & 1) == 0) {
            if (s->alpha == 1.0f) {
                q[0].rgba = func_00233708(c->col[0], s->colorMode);
                q[1].rgba = func_00233708(c->col[1], s->colorMode);
                q[2].rgba = func_00233708(c->col[2], s->colorMode);
                q[3].rgba = func_00233708(c->col[3], s->colorMode);
            } else {
                q[0].rgba = func_002338a8(s->alpha, func_00233708(c->col[0], s->colorMode));
                q[1].rgba = func_002338a8(s->alpha, func_00233708(c->col[1], s->colorMode));
                q[2].rgba = func_002338a8(s->alpha, func_00233708(c->col[2], s->colorMode));
                q[3].rgba = func_002338a8(s->alpha, func_00233708(c->col[3], s->colorMode));
            }
        } else {
            q[0].rgba = c->col[0];
            q[1].rgba = c->col[1];
            q[2].rgba = c->col[2];
            q[3].rgba = c->col[3];
        }
    }
    u64 g0 = (u32)(s->count | 0x8000);
    u64 g1 = g0 | (12ULL << 60);
    u64 g2 = g1 | (0x15cULL << 47);
    u64 g3 = g2 | (1ULL << 46);
    *(u64*)tag = g3;
    ((u64*)tag)[1] = 0;
    tag->r0 = 3; tag->r1 = 0xe; tag->r2 = 4; tag->r3 = 3; tag->r4 = 0xe; tag->r5 = 4;
    tag->r6 = 3; tag->r7 = 0xe; tag->r8 = 4; tag->r9 = 3; tag->r10 = 0xe; tag->r11 = 4;
    func_001b7ff8(&pkt, s->count * 12 + 1);
    func_001b80d8(&pkt);
    func_001b7f30(&pkt);
}
}  // namespace n00238c90

// 00239230 (was src/anon/batch_w1668.cpp)
namespace n00239230 {
// 0x001b8290: definition moved into src/anon/unit_001b6a50.cpp

extern f32 D_00349e14 asm("D_00349e14");
/*TARGET 00239230*/
void func_00239230(u8* p) asm("func_00239230");
void func_00239230(u8* p) { *(f32*)(p + 0x48) += D_00349e14 * *(f32*)(p + 0x44); }
}  // namespace n00239230

// 00239250 (was src/anon/batch_w3728_nsa.cpp)
namespace n00239250 {
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
void func_001b7e68(W3728Pkt*, s32) asm("func_001b7e68");
void func_001b7ff8(W3728Pkt*, s32) asm("func_001b7ff8");
void func_001b80d8(W3728Pkt*) asm("func_001b80d8");
void func_001b7f30(W3728Pkt*) asm("func_001b7f30");
u32 func_00233708(u32, s32) asm("func_00233708");
u32 func_002338a8(f32, u32) asm("func_002338a8");
/*TARGET 00239250*/
// Builds a GIF packet of textured sprites for a 2D object (one quad per sprite).
void func_00239250(W3728Obj* obj, s32 x, s32 y, s32 ox, s32 oy) asm("func_00239250");
// Builds a GIF packet of textured sprites for a 2D object (one quad per sprite).
void func_00239250(W3728Obj* obj, s32 x, s32 y, s32 ox, s32 oy)
{
    s32 bx = (x << 4) + 0x7000;
    s32 by = (y << 4) + 0x7300;
    s32 dx = ox << 4;
    s32 dy = oy << 4;
    f32 sx, sy;
    W3728Pkt pk;
    if (((obj->flags >> 4) & 1) == 0) {
        sx = obj->sx;
        sy = obj->sy;
    } else {
        sy = 1.0f;
        sx = sy;
    }
    pk.cur = 0; pk.pad = 0; pk.start = 0;
    func_001b7e68(&pk, obj->num * 5 + 1);
    u64* tag = (u64*)(pk.start + 0x10);
    W3728Quad* q = (W3728Quad*)(pk.start + 0x20);
    W3728Spr* s = obj->sprs;
    for (s32 i = obj->num; i > 0; i--) {
        f32 one = 1.0f;
        s32 adc = 0x8000;
        // pins reproduce the original's loop-head registers (t6 = tex offset, t7 = flags, t5 = texs)
        register u32 off asm("$14") = s->tex * 44;
        register u32 fl asm("$15") = obj->flags;
        register W3728Tex* tb asm("$13") = obj->texs;
        W3728Tex* t = (W3728Tex*)((u8*)tb + off);
        if (((fl >> 5) & 1) == 0) {
            if (obj->alpha == one) {
                q->tex0 = func_00233708(t->tex0, obj->clut);
            } else {
                q->tex0 = func_002338a8(obj->alpha, func_00233708(t->tex0, obj->clut));
            }
        } else {
            q->tex0 = t->tex0;
        }
        q->rgba = 1;
        q->v[0].u = (t->u0 << 4) + 8;
        q->v[0].v = (t->v0 << 4) + 8;
        q->v[0].x = bx + (s32)((f32)((s->x0 << 4) + dx) * sx);
        q->v[0].y = by + (s32)((f32)((s->y0 << 4) + dy) * sy);
        q->v[0].z = obj->z;
        q->v[0].adc = adc;
        q->v[1].u = (t->u1 << 4) + 8;
        q->v[1].v = (t->v1 << 4) + 8;
        q->v[1].x = bx + (s32)((f32)((s->x1 << 4) + dx) * sx);
        q->v[1].y = by + (s32)((f32)((s->y1 << 4) + dy) * sy);
        q->v[1].z = obj->z;
        q->v[1].adc = 0;
        s++;
        q++;
    }
    u64 gt = (u32)(obj->num | 0x8000);
    gt |= (u64)5 << 60;
    gt |= (u64)0x156 << 47;
    gt |= (u64)1 << 46;
    tag[1] = 0x4343e;
    tag[0] = gt;
    func_001b7ff8(&pk, obj->num * 5 + 1);
    func_001b80d8(&pk);
    func_001b7f30(&pk);
}
}  // namespace n00239250

// 00239558 (was src/anon/batch_w51.cpp)
namespace n00239558 {
/*TARGET 00239558*/
// 0x00233410: definition moved into src/anon/unit_00232f08.cpp

void func_00239558(u8* p, u16* a, u16* b) asm("func_00239558");
// 0x00233410: definition moved into src/anon/unit_00232f08.cpp

void func_00239558(u8* p, u16* a, u16* b) {  // copy_4halfwords_and_set_flag
    *(u32*)(p + 16) |= 0x40;
    u8* q = p;
    for (s32 i = 0; i < 4; i++) {
        *(u16*)(q + 160) = a[i];
        *(u16*)(q + 168) = b[i];
        q += 2;
    }
}
}  // namespace n00239558

// 002395a0 (was gap)
namespace n002395a0 {
struct Obj237 {
    u32 vt; u32 f4, f8, f12;
    u32 b0:1, b1:1, b2:1, b3:1, b4:1, b5:1, b6:1;
};
void func_002395a0(Obj237* o) asm("func_002395a0");
void func_002395a0(Obj237* o) { o->b6 = 0; }
}  // namespace n002395a0

// 002395b8 (was src/anon/batch_wcx2.cpp)
namespace n002395b8 {
extern u8 D_0035eaf8[] asm("D_0035eaf8");
void func_00237068(void*) asm("func_00237068");
struct Obj20 {
    void* vt;
    u8 base[172];
    u32 f176, f180;
    u32 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 1, b6 : 1, b7 : 1, b8 : 1, b9 : 1, b10 : 1, b11 : 1, b12 : 1, b13 : 1, rest : 18;
    u8 f188;
    u32 f192, f196, f200, f204, f208;
    u8 f212;
    u32 f216, f220, f224, f228, f232, f236, f240, f244, f248, f252, f256, f260, f264, f268, f272, f276, f280, f284, f288;
    u32 f292, f296, f300, f304, f308, f312, f316, f320, f324, f328, f332;
};
/*TARGET 002395b8*/
// 002395b8: constructor (base init, then clear all state)
void func_002395b8(Obj20* p) asm("func_002395b8");
// 002395b8: constructor (base init, then clear all state)
void func_002395b8(Obj20* p)
{
    func_00237068(p);
    p->f176 = 0;
    p->f180 = 0;
    p->b0 = 0;
    p->b1 = 0;
    p->f188 = 0;
    p->b2 = 0;
    p->f192 = 0;
    p->f196 = 0;
    p->b3 = 0;
    p->f200 = 0;
    p->f204 = 0;
    p->b4 = 0;
    p->f208 = 0;
    p->f212 = 0;
    p->b5 = 0;
    p->f216 = 0;
    p->f220 = 0;
    p->b6 = 0;
    p->f224 = 0;
    p->f228 = 0;
    p->b7 = 0;
    p->f232 = 0;
    p->f236 = 0;
    p->b8 = 0;
    p->f240 = 0;
    p->f244 = 0;
    p->b9 = 0;
    p->f248 = 0;
    p->f252 = 0;
    p->b10 = 0;
    p->f256 = 0;
    p->f260 = 0;
    p->b11 = 0;
    p->f264 = 0;
    p->f268 = 0;
    p->b12 = 0;
    p->f272 = 0;
    p->f276 = 0;
    p->b13 = 0;
    p->f280 = 0;
    p->f284 = 0;
    p->f288 = 0;
    *(u32*)&p->vt = (u32)D_0035eaf8;
    p->f292 = 0;
    p->f296 = 0;
    p->f300 = 0;
    p->f304 = 0;
    p->f308 = 0;
    p->f312 = 0;
    p->f316 = 0;
    p->f320 = 0;
    p->f324 = 0;
    p->f328 = 0;
    p->f332 = 0;
}
}  // namespace n002395b8

// 00239700 (was src/anon/batch_w267.cpp)
namespace n00239700 {
extern char D_0035eaf8[] asm("D_0035eaf8");
void func_00237068(void*) asm("func_00237068");
struct S239 {
  void* vt; char pad[172];
  u32 a176; u32 a180;
  u32 b0:1; u32 b1:1; u32 b2:1; u32 b3:1; u32 b4:1; u32 b5:1; u32 b6:1; u32 b7:1;
  u32 b8:1; u32 b9:1; u32 b10:1; u32 b11:1; u32 b12:1; u32 b13:1; u32 rest:18;
  u8 c188; char p1[3];
  u32 a192, a196, a200, a204, a208;
  u8 c212; char p2[3];
  u32 a216, a220, a224, a228, a232, a236, a240, a244, a248, a252, a256, a260, a264, a268, a272, a276, a280, a284, a288, a292, a296, a300, a304, a308, a312, a316, a320, a324, a328, a332;
};
void func_00239700(S239* p) asm("_ZN2YI8SEQUENCEC1Ev");
/*TARGET 00239700*/
// YI::SEQUENCE::SEQUENCE
void func_00239700(S239* p) asm("_ZN2YI8SEQUENCEC1Ev");
// YI::SEQUENCE::SEQUENCE
void func_00239700(S239* p) {
  func_00237068(p); p->vt = D_0035eaf8;

  p->a176 = 0; p->a180 = 0; p->b0 = 0; p->c188 = 0; p->b1 = 0;
  p->a192 = 0; p->a196 = 0; p->b2 = 0; p->a200 = 0; p->a204 = 0; p->b3 = 0;
  p->a208 = 0; p->c212 = 0; p->b4 = 0; p->a216 = 0; p->a220 = 0; p->b5 = 0;
  p->a224 = 0; p->a228 = 0; p->b6 = 0; p->a232 = 0; p->a236 = 0; p->b7 = 0;
  p->a240 = 0; p->a244 = 0; p->b8 = 0; p->a248 = 0; p->a252 = 0; p->b9 = 0;
  p->a256 = 0; p->a260 = 0; p->b10 = 0; p->a264 = 0; p->a268 = 0; p->b11 = 0;
  p->a272 = 0; p->a276 = 0; p->b12 = 0; p->a280 = 0; p->a284 = 0; p->b13 = 0;
  p->a288 = 0; p->a292 = 0; p->a296 = 0; p->a300 = 0;
  p->a304 = 0; p->a308 = 0; p->a312 = 0; p->a316 = 0; p->a320 = 0; p->a324 = 0; p->a328 = 0; p->a332 = 0;
}
}  // namespace n00239700

// 00239848 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00239848 {
u32 func_00237238(u32, u32, u32, u32) asm("_Z13func_00237238jjjj");
u32 func_00239848(u32, u32, u32, u32) asm("_Z13func_00239848jjjj");
extern u8 D_0035eaf8 asm("D_0035eaf8");
/*TARGET 00239848*/
u32 func_00239848(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00239848jjjj");
u32 func_00239848(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_36eb28_then_call
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035eaf8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00237238)(u32, u32, u32, u32) = func_00237238;
    r2 = fp_call4_00237238(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00239848

// 00239870 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00239870 {
u32 func_00237238(u32, u32, u32, u32) asm("_Z13func_00237238jjjj");
extern u8 D_0035eaf8 asm("D_0035eaf8");
/*TARGET 00239870*/
u32 func_00239870(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00239870jjjj");
u32 func_00239870(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_0035eaf8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00237238)(u32, u32, u32, u32) = func_00237238;
    r2 = fp_call4_00237238(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00239870

// 00239898 (was src/anon/batch_w13.cpp)
namespace n00239898 {
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
void func_00237238(void*) asm("func_00237238");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8 D_0035eaf8 asm("D_0035eaf8");
void SEQUENCE_D0(void*) asm("_ZN2YI8SEQUENCED0Ev");
/*TARGET 00239898*/
// 0x00236148: definition moved into src/anon/unit_00234f60.cpp

void SEQUENCE_D0(void* self) asm("_ZN2YI8SEQUENCED0Ev");
// 0x00236148: definition moved into src/anon/unit_00234f60.cpp

void SEQUENCE_D0(void* self) {
    *(void**)self = &D_0035eaf8;
    func_00237238(self);
    func_00106420(self);
}
}  // namespace n00239898


// 002398d0 (was whole asm, src/anon/asm_002398d0.s)
namespace n002398d0 {
void func_003058a0(s32) asm("func_003058a0");
// One GS register packet: DMA end tag (2 qwords follow), GIF tag (1 A+D register), then data and register address.
struct GsPk { u64 tag, pad, gif, regs, data, reg; };
extern GsPk D_01dae590[2] asm("D_01dae590");    // TEX1_1 by filter: linear, nearest
extern u64 D_01dae5f0[3][6] asm("D_01dae5f0");  // ALPHA_1 by blend mode: normal, add, subtract
/*TARGET 002398d0*/
// Builds the five register packets the sprite draw sends (TEX1 filter x2, ALPHA blend x3).
// The filter packets are written as fields of the global, the blend packets through a plain u64 pointer:
// that mix (typed stores next to untyped ones) is what fixes retail's instruction order after reload.
void u_call0_002398d0(void) asm("_Z16u_call0_002398d0v");
void u_call0_002398d0(void) {
    u64* q;
    D_01dae590[0].tag = 0x70000002;
    D_01dae590[0].gif = 0x1000000000008001ULL;
    D_01dae590[0].regs = 14;
    D_01dae590[0].data = 0x60;
    D_01dae590[0].reg = 0x14;
    D_01dae590[1].tag = 0x70000002;
    D_01dae590[1].gif = 0x1000000000008001ULL;
    D_01dae590[1].regs = 14;
    D_01dae590[1].data = 0;
    D_01dae590[1].reg = 0x14;
    q = D_01dae5f0[0];
    q[0] = 0x70000002;
    q[2] = 0x1000000000008001ULL;
    q[3] = 14;
    q[4] = 0x44;
    q[5] = 0x42;
    q[6] = 0x70000002;
    q[8] = 0x1000000000008001ULL;
    q[9] = 14;
    q[10] = 0x48;
    q[11] = 0x42;
    q[12] = 0x70000002;
    q[14] = 0x1000000000008001ULL;
    q[15] = 14;
    q[16] = 0x42;
    q[17] = 0x42;
    func_003058a0(0);
}
}  // namespace n002398d0
