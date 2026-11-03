// 0010d918 (w3680): search the target list from the end for the first entry that passes
// both checks and copy it to *out.
#include "../common/types.h"
extern "C" void func_00190128(void*);
struct QW { f32 x, y, z, w; QW() {} } __attribute__((aligned(16)));
struct Tgt {
    s32 a, b, c, d, e;
    Tgt() { func_00190128(this); }
};
struct Hit { s32 p0; f32 r; s32 p8; s32 z; QW v; Hit() { z = 0; } };
extern "C" {
extern u32 D_00341788[8];
extern s32 D_003417a8;
void func_00190878(Tgt*, u32, s32);
s32 func_00190730(Tgt*, s32);
s32 func_001901c0(Tgt*);
s32 func_00112d28(u32, s32);
void func_0010d918(s32 a0, s32 a1, Tgt* out) {
    s32 i;
    for (i = D_003417a8 - 1; i >= 0; i--) {
        Hit hit;
        u32 id = D_00341788[i];
        Tgt it;
        func_00190878(&it, id, 0);
        s32 k = 0;
        while ((k = func_00190730(&it, k)) != 0) {
            if (it.a != D_00341788[i]) break;
            if (!func_001901c0(&it)) continue;
            {
                // The empty asm (copy of k, memory clobber) keeps sched1 from
                // hoisting the a1 argument above the previous test, so reorg
                // fills that branch's delay slot from its target like the original.
                s32 kk = k;
                asm("" : "+r"(kk) : : "memory");
                if (!func_00112d28(D_00341788[i], kk)) continue;
            }
            *out = it;
            break;
        }
    }
}
}
