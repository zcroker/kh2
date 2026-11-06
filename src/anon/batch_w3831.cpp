#include "../common/types.h"

// 00117970: takes a free 64-byte slot from the manager, fills its header and parameter
// block, clears its two vectors (VU0) and sets the owner/attribute flags.
struct W3831SlotH { u32 flags; s32 a; s32 pad8; s32 c; };
struct W3831SlotP { s32 d; s32 w; s32 z; s32 pad; };
struct W3831Slot64 { u8 pad[32]; W3831SlotH h; W3831SlotP p; f32 v0[4]; f32 v1[4]; };
struct W3831Slot { W3831SlotH h; W3831SlotP p; f32 v0[4]; f32 v1[4]; };
struct W3831SlotMgr { s32 pad0; s32 owner; u8 pad8[24]; W3831Slot slot[24]; };

extern "C" {
s32 func_001178d0(W3831SlotMgr*);
s32 func_00111e38(s32);

s32 func_00117970(W3831SlotMgr* m, s32 a, s32 y, s32 z, s32 w, u8 b, s32 c, s32 d)
{
    // Pins/empty asm (no code): w and d keep s0/s2, h stays a register in t5, and the
    // empty ties order the parameter stores like the original.
    register s32 w_ asm("$16") = w;
    register s32 d_ asm("$18") = d;
    asm("" : "+r"(d_));
    s32 i = func_001178d0(m);
    W3831Slot64* s = (W3831Slot64*)((i << 6) + (u32)m);
    W3831SlotP* p = &s->p;
    register W3831SlotH* h asm("$13") = &s->h;
    asm("" : "+r"(h), "+r"(w_) : "r"(p));
    p->w = w_;
    p->d = d_;
    h->c = c;
    asm("" : "+r"(s) : "r"(w_));
    p->z = z;
    s->h.flags = 0;
    h->a = a;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(s->v0) : "memory");
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(s->v1) : "memory");
    if (y != 0) {
        s32 o = func_00111e38(0);
        if (y == m->owner) {
            s->h.flags |= 1;
            if (a == 0) s->h.flags |= 0x20;
        } else if (y == o) {
            s->h.flags |= 2;
        }
    }
    if (b) m->slot[i].h.flags |= 8;
    return i;
}
}
