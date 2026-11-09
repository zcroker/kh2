#include "../common/types.h"

/* Plain C (partMng family), built with -fno-strict-aliasing -fmove-all-movables.
   00204bd0: per-frame update of an emitter's particle array. Live particles run the physics step
   and advance their frame animation; dead ones are respawned while the emit threshold allows it. */
typedef struct Pt204bd0 Pt204bd0; typedef struct Cl204bd0 Cl204bd0; typedef struct Cf204bd0 Cf204bd0;
typedef struct Em204bd0 Em204bd0; typedef struct Pr204bd0 Pr204bd0; typedef struct Fr204bd0 Fr204bd0;
typedef struct An204bd0 An204bd0; typedef struct Set204bd0 Set204bd0; typedef struct Bk204bd0 Bk204bd0;
typedef struct Sys204bd0 Sys204bd0;
struct Pt204bd0 { u8 pad0[32]; u16 time; u16 frame; u16 prev; u16 active; u8 pad40[96 - 40]; };
struct Cl204bd0 { u8 pad[64]; };
struct Cf204bd0 { u8 pad[32]; };
struct Em204bd0 { u8 pad0[80]; Pt204bd0* pt; Cl204bd0* col; Cf204bd0* cf; s32 n; u16 tick; };
struct Pr204bd0 { u8 pad0[4]; s32 anim; u16 speed; u8 pad10[30 - 10]; u16 max; u16 thr; };
struct Fr204bd0 { u8 pad0[2]; u16 dur; s8 flags; u8 pad5[3]; };
struct An204bd0 { u8 pad0[6]; s16 count; u8 pad8[16 - 8]; Fr204bd0 fr[1]; };
struct Set204bd0 { An204bd0* an; u32 pad4; };
struct Bk204bd0 { u8 pad0[20]; Set204bd0* sets; };
struct Sys204bd0 { u8 pad0[168]; u64 flags; };
extern s32 D_01d9ea9c;
extern Sys204bd0* D_01d9e6e0;
extern Bk204bd0* D_01d9e6e4;
void func_00204850(Em204bd0*, Pr204bd0*, Pt204bd0*, s32, Cf204bd0*);
void func_00203b48(s32, Em204bd0*, Pr204bd0*, s32, Pt204bd0*, Cl204bd0*, Cf204bd0*);

void func_00204bd0(s32 owner, Em204bd0* em, Pr204bd0* pr, s32 col)
{
    s32 born = 0;
    s32 i;
    Pt204bd0* pt = em->pt;
    Cl204bd0* cl = em->col;
    Cf204bd0* cf = em->cf;
    s32 n = em->n;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (pr->anim == 0xffff) return;
    em->tick++;
    for (i = 0; i < n; i++) {
        if (pt->active != 0) {
            func_00204850(em, pr, pt, col, cf);
            u16 frame = pt->frame;
            Set204bd0* sets = D_01d9e6e4->sets;
            u32 off = pr->anim * 8;
            An204bd0* an = *(An204bd0**)((u8*)sets + off);
            u16 prev = pt->prev;
            pt->prev = frame;
            Fr204bd0* fr = &an->fr[prev];
            s32 time = pt->time + pr->speed;
            pt->time = time;
            if ((u16)time >= (s16)fr->dur) {
                pt->time = time - fr->dur;
                pt->frame = frame + 1;
                if (pt->frame >= an->count) {
                    if (fr->flags & 0x80) { pt->frame = 0; pt->time = 0; }
                    else { pt->frame = frame; pt->time = 0; }
                }
            }
        } else if (pr->thr <= em->tick) {
            if (born < pr->max) {
                func_00203b48(owner, em, pr, col, pt, cl, cf);
                born++;
            }
        }
        pt++;
        if (cl) cl++;
        if (cf) cf++;
    }
    if (born > 0) em->tick = 0;
}
