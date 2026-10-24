#include "../common/types.h"

/* VIF packet header built in front of a run of 48-byte items. */
typedef struct VifPkt_w2370 {
    u32 w0, w4, w8, wc;
    u32 self;       /* 0x10 */
    u32 w14, w18;
    u16 h1c; u8 b1e; u8 b1f;
    u16 qwc;        /* 0x20 DMA tag */
    u8 b22; u8 id;
    u32 w24;
    u32 vif0;       /* 0x28 */
    u32 w2c, w30;
    u16 h34; u8 b36; u8 count;
    u16 h38; u16 h3a; u16 h3c; u16 h3e;
    u8 pad40[0xc];
    f32 scale;      /* 0x4c */
    u32 w50, w54, w58;
} VifPkt_w2370;
typedef struct { u8 d[48]; } VifItem_w2370;
typedef struct { VifPkt_w2370* pkt; u8 count; } VifOwner_w2370;

void func_00221e28(VifOwner_w2370* o) {
    VifPkt_w2370* s = o->pkt;
    u32* t;
    s->h3e = 0;
    s->self = (u32)s;
    s->count = o->count;
    s->scale = 1.0f;
    s->id = 0x70;
    s->vif0 = 0x040000B0;
    s->h1c = 0;
    s->w18 = 0;
    s->qwc = (s->count * 48u >> 4) + 2;
    s->h34 = 0;
    s->b36 = 0;
    s->h3c = 0;
    s->h38 = 0;
    s->b1e = 0;
    s->w14 = 0;
    s->w4 = 0;
    s->w0 = 0;
    s->wc = 0;
    s->w8 = 0;
    s->w58 = 0;
    t = (u32*)&((VifItem_w2370*)((u8*)s + 0x40))[s->count];
    t[0] = 0;
    t[1] = 0x11000000;
    t[2] = 0x14000000;
    t[3] = 0x11000000;
}

/* ---- 001fc5b8 (partMng) ---- */
typedef unsigned int u128_w2370 __attribute__((mode(TI)));
typedef struct { s32 x, y, z; } PVec_w2370;
typedef PVec_w2370 PVec8_w2370 __attribute__((aligned(8)));
typedef struct {
    u8 pad[0x40];
    u8 work[0x30];       /* 0x40 */
    u128_w2370 m70;      /* 0x70 */
    PVec8_w2370 pos;     /* 0x80 */
} PartEnt_w2370;
typedef struct { u8 pad[0xc]; s32* offs; } PartCmd_w2370;
extern PartEnt_w2370* D_01d9ea94;
extern u128_w2370 D_0035da80;
void func_001e8fe0(void*, PVec_w2370*);

/* Moves entry 0 to entry 1's position, passing the move delta on. */
void func_001fc5b8(u8* base, s32 a1, PartCmd_w2370* cmd) {
    s32* o = cmd->offs;
    PartEnt_w2370* e;
    PVec_w2370* to;
    s32 x, y, z;
    PVec8_w2370 d;
    e = (PartEnt_w2370*)(base + o[0] + 0xa0);
    to = (PVec_w2370*)(base + o[1] + 0xa0);
    D_01d9ea94 = e;
    d = e->pos;
    x = to->x; y = to->y; z = to->z;
    d.x -= x; d.y -= y; d.z -= z;
    e->pos.x = x; e->pos.y = y; e->pos.z = z;
    func_001e8fe0(e->work, (PVec_w2370*)&d);
    e->m70 = D_0035da80;
}
