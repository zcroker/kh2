/* 001ea4d8: particle emitter tick (partMng, C): every `reset` frames spawn n particles, either cycling or random frames. */
#include "../common/types.h"
typedef struct { u8 pad0[0xa8]; u64 flags; } St4d8;
typedef struct { s16 x0; s16 x2; s32 x4; } Ent4d8;
typedef struct { u8 pad0[0x18]; Ent4d8* tbl; } Bank4d8;
typedef struct { u8 pad0[4]; s16 idx; u8 n; u8 reset; u8 mode; } Obj4d8;
typedef struct { u8 pad0[0xc]; s32* ofs; } Arg4d8;
typedef struct { u16 cur; u16 wait; } Cnt4d8;
extern St4d8* D_01d9e6e0;
extern Bank4d8* D_01d9e6e4;
extern s32 D_01d9ea9c;
extern s32 D_01d9eab4;
void func_001ea458(s32 a, Obj4d8* o, u16 v);
static __inline__ f32 VRand(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}
void func_001ea4d8(s32 base, Obj4d8* o, Arg4d8* arg)
{
    Cnt4d8* c = (Cnt4d8*)(base + *arg->ofs + 0xa0);
    s16 idx;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (D_01d9eab4 != 0) return;
    idx = o->idx;
    if (idx < 0) return;
    if (c->wait == 0) {
        s32 n = o->n;
        Ent4d8* e = &D_01d9e6e4->tbl[idx];
        switch (o->mode) {
        case 0:
            while (--n != -1) {
                if (c->cur >= e->x2) c->cur = 0;
                func_001ea458(base, o, c->cur++);
            }
            break;
        case 1:
            while (--n != -1) {
                func_001ea458(base, o, (u16)(s32)(VRand() * (f32)e->x2));
            }
            break;
        }
        c->wait = o->reset;
    }
    c->wait--;
}
