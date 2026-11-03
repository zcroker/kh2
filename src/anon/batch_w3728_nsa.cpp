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

}
