#include "../common/types.h"
extern "C" {
struct O { u8 pad[0x188]; s32 a; u8 p2[0x20]; s32 b; };
struct T { s16 a; s16 b; s16 c; };
O* func_0028c198(s32, s32, s32, s32, s32, s32);
void func_00288ce0(s32, O*, s32, T*, s32);
// Empty asm and pin keep the first lh in its own pseudo (t7), which sched1 issues in the prologue.
void func_00288d80(s32 a0, s32 a1, s32 a2, s32 a3, s32 t0, s32 t1, T* t2, s32 t3) {
    register s32 v asm("$15") = t2->a;
    asm("" : "+r"(v));
    O* o = func_0028c198(v, a2, a3, t0, t1, 0);
    o->a = t2->c;
    o->b = 1;
    func_00288ce0(a0, o, a1, t2, t3);
}
}
