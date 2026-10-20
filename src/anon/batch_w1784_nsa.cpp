#include "../common/types.h"
// Built with -fno-strict-aliasing (bitfield and tag stores keep the original's reloads).
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1784V3 { f32 x, y, z; };
struct W1784O1 {
    u8 pad0[0xc];
    f32 pos;      /* 0x0c */
    u8 pad10[4];
    u32 b0 : 1;   /* 0x14 */
    u32 b1 : 1;
    u32 rest : 30;
    f32 speed;    /* 0x18 */
    u8 pad1c[8];
    s32 ix;       /* 0x24 */
    s32 iy;       /* 0x28 */
};
// GIF tag: NLOOP, EOP, NREG, REGS
struct W1784Tag {
    u64 nloop : 15;
    u64 eop : 1;
    u64 pad : 44;
    u64 nreg : 4;
    u64 regs : 4;
    u64 rest : 60;
} __attribute__((aligned(16)));
struct W1784Pkt { u8 pad[16]; W1784Tag tag; };
struct W1784O2 {
    u8 pad0[0x18];
    W1784Pkt* buf;   /* 0x18 */
    u8 pad1c[4];
    W1784Pkt* pkt;   /* 0x20 */
};
extern "C" {
W1784V3* func_001333c8(W1784O1*);
void func_00133ba0(W1784O2*, s32, u32);
void func_001332e8(W1784O1* o, f32 dt) {
    W1784V3* v = func_001333c8(o);
    if (v) {
        u32 a = o->b0;
        if (!o->b1) {
            if ((u8)a) {
                o->b0 = 0;
            } else {
                f32 t = dt * o->speed;
                s32 d = (s32)(v->y * t);
                o->ix += d;
                d = (s32)(v->z * t);
                o->iy += d;
                o->pos += t;
            }
        }
    }
}
void wtarget_00133a18(W1784O2* o, u32, u32, u32) asm("_Z16wtarget_00133a18jjjj");
void wtarget_00133a18(W1784O2* o, u32, u32, u32) {
    if (o->pkt == 0) {
        W1784Pkt* t = o->buf;
        func_00133ba0(o, 1, 0x13000000);
        o->pkt = t;
        *(u128*)&t->tag = 0;
        o->pkt->tag.nloop = 0;
        o->pkt->tag.eop = 1;
        o->pkt->tag.nreg = 1;
        o->pkt->tag.regs = 0xe;
    }
}
}
