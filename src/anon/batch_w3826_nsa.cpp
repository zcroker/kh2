// w3826: built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"
extern "C" {
struct V1d35e0 {
    f32 x, y, z, w;
    V1d35e0& operator=(const V1d35e0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct L1d35e0 { V1d35e0 a, b; };
struct O1d35e0 { u8 pad[16]; s32 hit; s32 id; };
s32 func_00143b88(L1d35e0*, O1d35e0*, u16*, s32*, u32);
s32 func_00143ae0(L1d35e0*, O1d35e0*, u16*);

// Line test from a to b (w forced to 1); fills o->hit / o->id. Returns whether something was hit.
s32 func_001d35e0(O1d35e0* o, const V1d35e0& a, const V1d35e0& b, u32 flags)
{
    L1d35e0 l; u16 id; V1d35e0* pb = &l.b;
    l.a = a; *pb = b; l.a.w = 1.0f; pb->w = 1.0f;
    o->id = -1;
    s32 r;
    if (flags & 0x10000) {
        // Two no-code ties: the first gives the entry copy move t5,a3; the second makes the
        // flags & 0xffff (andi t0) issue before the hit pointer (addiu a3) in sched2.
        asm("" : "+r"(flags));
        u32 f = flags & 0xffff;
        asm("" : "+r"(f));
        s32* hit = &o->hit;
        r = func_00143b88(&l, o, &id, hit, f);
    } else {
        o->hit = 0;
        r = func_00143ae0(&l, o, &id);
    }
    if (r) o->id = id;
    return o->id != -1;
}
}
