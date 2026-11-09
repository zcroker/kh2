/* zl90 w3917 2026-11-10: func_001ebe40 in plain C, built with -fno-strict-aliasing (_nsa). */
#include "../common/types.h"

typedef struct { f32 x, y, z; } SpV1ebe40;
typedef struct { u8 pad0[4]; f32 rad; f32 speed; s32 obj; s32 posOff; u8 pad1[4]; s32 velOff; u8 wait; } Spawn1ebe40;
typedef struct { u8 pad0[1]; u8 wait; } SpSt1ebe40;
typedef struct { u8 pad0[12]; s32* off; } SpCtx1ebe40;
typedef struct { u8 pad0[128]; u8* objs; u8 pad1[168 - 132]; u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24; } Part1ebe40;
typedef struct { u8 pad0[4]; u8* base; } SpObj1ebe40;

extern s32 D_01d9ea9c;
extern Part1ebe40* D_01d9e6e0;
extern f32 D_00359a20[]; /* sine table, 4096 entries for a 65536 turn */
SpObj1ebe40* func_001e7a98(Part1ebe40*, u8*);

#define SIN1ebe40(a) D_00359a20[((u32)(a) >> 4) & 0xfff]
#define COS1ebe40(a) D_00359a20[((u32)(a) + 16384 >> 4) & 0xfff]

/* VU0 random number in [1,2) - 1 (hand-written VU0 macro code in the original) */
#define RAND1ebe40(r) asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(r) : : "$8")

/* Particle emitter step: when the wait counter runs out, spawn one object at a random
   point on a sphere of radius e->rad around pos, moving outwards at e->speed. */
void func_001ebe40(u8* base, Spawn1ebe40* e, SpCtx1ebe40* c)
{
    SpSt1ebe40* st = (SpSt1ebe40*)(base + c->off[1] + 160);
    SpV1ebe40* pos;
    SpObj1ebe40* o;
    u8* tmpl;
    SpV1ebe40* p;
    SpV1ebe40* v;
    s32 a;
    f32 r, sa, ca, sb;

    if (D_01d9ea9c) return;
    if (D_01d9e6e0->stopA || D_01d9e6e0->stopB) return;
    if (st->wait == 0) {
        pos = (SpV1ebe40*)(base + c->off[0] + 160);
        if (e->obj == -1) return;
        tmpl = D_01d9e6e0->objs + e->obj * 16;
        if (!tmpl) {
            o = 0;
        } else {
            o = func_001e7a98(D_01d9e6e0, tmpl);
            o->base = base;
        }
        RAND1ebe40(r);
        a = r * 32768.0f - 16384.0f;
        sa = SIN1ebe40(a) * e->rad;
        ca = COS1ebe40(a) * e->rad;
        RAND1ebe40(r);
        a = r * 32768.0f * 2.0f;
        sb = SIN1ebe40(a) * ca;
        ca = ca * COS1ebe40(a);
        p = (SpV1ebe40*)((u8*)o + e->posOff + 160);
        v = (SpV1ebe40*)((u8*)o + e->velOff + 160);
        p->x = pos->x + sb;
        p->y = pos->y + sa;
        p->z = pos->z + ca;
        v->x = sb * e->speed;
        v->y = sa * e->speed;
        v->z = ca * e->speed;
        st->wait = e->wait;
    }
    st->wait--;
}
