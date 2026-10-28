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
}
