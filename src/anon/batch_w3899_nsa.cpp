#include "../common/types.h"
extern "C" {
struct K850 { u16 type:4; s16 off:12; };
struct Anim850 { u8 pad[4]; u16 n; };
struct Obj850 {
    u8 pad0[0x14]; u32 flags; f32 speed; u8 pad1[4]; Obj850* link;
    u8 pad2[0x274 - 0x24]; s32 f274; u8* base; K850* cur; f32 dur; f32 time;
};
Anim850* func_00132c68(Obj850*);
void func_00132720(Obj850*, s32);
u32 func_00106520(u16, s32);

// Advance an object's key-frame cursor by dt * speed. A linked object copies
// the cursor and timing of its link. Type-2 keys jump, type-3 keys stop.
// Partial asm: the f0..f3 pins and empty "+f" ties keep the loop values in
// the original's FP registers and keep its mov.s copies; the .p2align gives
// the original's aligned loop head (the goto loop has no loop notes, so the
// li 2/li 3 constants stay in the loop as in the original).
void func_00132850(Obj850* o, f32 dt) {
    Anim850* a = func_00132c68(o);
    if (a == 0) return;
    if (!(o->flags & 4)) func_00132720(o, o->f274);
    else o->flags &= ~4;
    Obj850* l = o->link;
    if (l != 0) {
        if (l->cur != 0) o->cur = (K850*)((u8*)o->base + ((u8*)l->cur - (u8*)l->base));
        else o->cur = 0;
        *(u32*)&o->flags = l->flags;
        o->time = l->time;
        o->dur = l->dur;
        return;
    }
    K850* p = o->cur;
    if (p == 0) return;
    if (p->type == 3) return;
    if (p->type == 2) o->cur = (K850*)((u8*)p + p->off * (a->n * 2 + 8));
    u32 f = o->flags;
    if ((u8)(f & 1)) { o->flags = f & ~1; return; }

    register f32 sp asm("$f1");
    register f32 tm asm("$f2");
    register f32 dur asm("$f3");
    register f32 t0 asm("$f0");
    sp = dt * o->speed;
    dur = o->dur;
    t0 = o->time + sp;
    asm("" : "+f"(t0));
    tm = t0;
    o->time = t0;
    asm volatile(".p2align 3");
top:
    if (!(dur <= tm)) return;
    {
        register f32 r asm("$f0");
        r = tm - dur;
        asm("" : "+f"(r));
        o->time = r;
    }
    {
        s32 sz = a->n * 2 + 8;
        p = (K850*)((u8*)o->cur + sz);
        o->cur = p;
        if (p->type == 2) {
            if (o->flags & 2) goto Z;
            o->cur = (K850*)((u8*)p + p->off * (a->n * 2 + 8));
        } else if (p->type == 3) return;
        u16* q = (u16*)o->cur;
        register f32 nd asm("$f1");
        nd = (f32)func_00106520(q[1], q[2] + 1);
        asm("" : "+f"(nd));
        register f32 nt asm("$f0");
        nt = o->time;
        asm("" : "+f"(nt));
        dur = nd;
        tm = nt;
        o->dur = nd;
    }
    goto top;
Z:
    o->cur = 0;
}
}
