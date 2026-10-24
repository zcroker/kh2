#include "../common/types.h"
// Built with -fno-sched-interblock (the _nsi rule).
extern "C" {
struct V17 {
    f32 x, y, z, w;
    V17() {}
    V17& operator=(const V17& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// The flag word and the sub pointer are read through unions: gcc treats union member
// reads as aliasing everything, so they stay below the float stores like the original.
union UFlags17 { u32 flags; f32 f; };
struct Sub17 { u8 pad[0x10c]; UFlags17 fl; u8 pad2[0x140 - 0x110]; V17 pos; u8 pad3[0x698 - 0x150]; f32 x698; };
union USub17 { Sub17* p; u32 u; };
struct Obj17 { u32 x0; USub17 sub; u8 pad[0x630 - 8]; u32 flags; u8 pad2[0x640 - 0x634]; V17 v; u8 pad3[0x65c - 0x650]; f32 x65c; u8 pad4[0x6c0 - 0x660]; u8 x6c0[16]; };
void func_00117588(Obj17*, V17*);
void func_00194648(Sub17*, void*);
V17 func_0017ff68(V17*);

// Sets the object's target position, refreshes its sub-object when needed, then
// subtracts the sub-object's height from the target's w.
void func_00117808(Obj17* o, const V17* p)
{
    o->flags |= 1;
    o->v = *p;
    o->v.z = 1024.0f;
    o->x65c = o->v.w;
    Sub17* sb = o->sub.p;
    V17* ps = &sb->pos;
    if (!(sb->fl.flags & 0x40)) {
        func_00117588(o, ps);
        func_00194648(o->sub.p, o->x6c0);
        o->sub.p->x698 = 10000000.0f;
        sb = o->sub.p;
        ps = &sb->pos;
    }
    V17 r = func_0017ff68(ps);
    o->v.w -= r.w;
}
}
