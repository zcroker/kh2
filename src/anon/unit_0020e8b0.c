// Linked unit 0x0020e8b0-0x0020e960 (C, -fno-schedule-insns): GS packet fill before whole-asm 0x20e960.
#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct Pk20e { u8 pad[16]; u64 tag; u64 regs; union { u128 q; struct { u8 b[8]; u64 reg; } s; } m; u128 col; u128 v64; u128 v80; } Pk20e;
typedef struct Cnt20e { u32 x0; u32 x4; u32 x8; u32 xc; u32 x10; u32 x14; u32 x18; } Cnt20e;
extern u64 D_00370780;
extern u128 D_00370790;
extern u128 D_003707a0;
extern Cnt20e D_01da8cd0;
void func_0020e800(void*, s32, s32, s32);

// Fills a GS packet (tag, two-byte register pair, colour widened from RGBA bytes, two fixed qwords),
// sends it and bumps the packet counters. Returns the end of the packet.
// Partial asm: sq $0 (zero qword), pextlb/pextlh (MMI) and the sq of their result; keeping that sq inside the
// asm block lets sched2 issue li a1,6 right after it like the original.
u8* func_0020e8b0(Pk20e* p, u32 rgba, u8 a, u8 b)
{
    u128 c;
    p->tag = D_00370780;
    p->regs = 0x441e;
    asm volatile("sq $0,%0" : "=m"(p->m.q));
    p->m.s.b[0] = a;
    p->m.s.b[4] = b;
    p->m.s.reg = 0x42;
    asm volatile("pextlb %0,$0,%0\n\tpextlh %0,$0,%0\n\tsq %0,%1" : "=r"(c), "=m"(p->col) : "0"(rgba));
    { u128* g = &D_00370790; p->v64 = *g; }
    { u128* g = &D_003707a0; p->v80 = *g; }
    func_0020e800(p, 6, 0, 0);
    D_01da8cd0.x8++;
    D_01da8cd0.x18++;
    return (u8*)p + 96;
}
