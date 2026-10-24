// 00137458: diff 0 (try.sh, only relocations differ) ONLY with OPT="-O2 -fno-strength-reduce" (both forms below).
// -O1 leaves 2 diffs (li t6 / addiu order); default -O2 fully unrolls the 2-element ctor loop (18 diffs) because
// loop.c unrolls inside strength_reduce. Not in batch: needs a new Makefile suffix rule (e.g. _nsr).
// gcc-generated __static_initialization_and_destruction_0 for a 2-element global array whose ctor zeroes +12.
#include "../common/types.h"
struct E347 { u32 a, b, c, d; E347() { d = 0; } };
extern "C" { extern E347 D_00347d30[]; }
inline void* operator new[](unsigned int, void* p) { return p; }
void wt_00137458(int init, int prio) asm("_Z16wtarget_00137458jjjj");
void wt_00137458(int init, int prio) {
    if (prio == 0xffff && init == 1) new (D_00347d30) E347[2];
}
// Equivalent plain form (also diff 0 under the same flags):
// if (b == 0xffff && a == 1) { E347* p = D_00347d30; s32 i = 1; while (i != -1) { p->d = 0; i--; p++; } }
