#include "../common/types.h"
extern "C" {
struct Pk120a20 { u32 addr; };
struct Ent120a20 { u16 qwc; u8 pad[2]; s32 off; s32 a; s32 b; };
struct Lst120a20 { s32 n; s32 ids[1]; };
struct Grp120a20 { u8 pad[16]; s32 ent; s32 lst; u8 pad2[8]; };
struct Mdl120a20 { u8 pad[28]; s32 count; Grp120a20 grp[1]; };
struct Obj120a20 { u8 pad[4]; Mdl120a20* mdl; };
struct Tx120a20 { u8 pad[44]; u32 addr[1]; };
Mdl120a20* func_00120800(Obj120a20*);
void func_001339d0(Pk120a20*, u32, s32, s32, s32);
void func_00133848(Pk120a20*, s32, u32, s32);
void func_00133898(Pk120a20*, s32, u32, s32);
/* Builds the DMA packet for a model and its second model group list. */
u32 func_00120a20(Obj120a20* o, Tx120a20* tx, u32* outs, u32 addr, s32 n)
{
    Mdl120a20* m = o->mdl;
    Mdl120a20* m2 = func_00120800(o);
    Pk120a20 p;
    s32 i, j;
    p.addr = addr;
    for (i = 0; i < m->count; i++) {
        outs[i] = p.addr;
        Ent120a20* e = (Ent120a20*)((u8*)m + m->grp[i].ent);
        Lst120a20* l = (Lst120a20*)((u8*)m + m->grp[i].lst);
        func_001339d0(&p, (u32)m + e->off, e->qwc, e->a, e->b);
        e++;
        for (j = 0; j < l->n; j++) {
            s32 t = l->ids[j];
            if (t < 0) {
                func_00133848(&p, 0, 0x17000000, 0);
                e++;
                func_001339d0(&p, (u32)m + e->off, e->qwc, e->a, e->b);
            } else {
                func_001339d0(&p, tx->addr[n] + t * 64, 4, e->a, e->b);
            }
            e++;
            asm volatile(""); /* keeps e++ ahead of j++ (sched2 tie) */
        }
        func_00133898(&p, 0, 0x17000000, 0);
    }
    if (m2) {
        for (i = 0; i < m2->count; i++) {
            outs[m->count + i] = p.addr;
            Ent120a20* e = (Ent120a20*)((u8*)m2 + m2->grp[i].ent);
            Lst120a20* l = (Lst120a20*)((u8*)m2 + m2->grp[i].lst);
            func_001339d0(&p, (u32)m2 + e->off, e->qwc, e->a, e->b);
            e++;
            for (j = 0; j < l->n; j++) {
                s32 t = l->ids[j];
                if (t < 0) {
                    func_00133848(&p, 0, 0x17000000, 0);
                    e++;
                    func_001339d0(&p, (u32)m2 + e->off, e->qwc, e->a, e->b);
                } else {
                    func_001339d0(&p, tx->addr[n] + t * 64, 4, e->a, e->b);
                }
                e++;
                asm volatile(""); /* keeps e++ ahead of j++ (sched2 tie) */
            }
            func_00133898(&p, 0, 0x17000000, 0);
        }
    }
    return p.addr;
}
}
