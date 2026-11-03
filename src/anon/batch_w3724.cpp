#include "../common/types.h"
// w3724: matched functions.
extern "C" {
void* func_001c3748(s32, void*);
s32 u_tail4(u32, void*) asm("_Z16u_tail4_00192048jjjj");
// Walks a list with func_001c3748 and passes the n-th entry (its u16 at +6) to u_tail4.
// Register pins: n in s1 and the cursor p in a1, as in the original (move a1,zero before the loop).
s32 func_002c2610(s32 a0, s32 n) {
    register s32 nn asm("$17") = n; s32 i = 0; s32 aa = a0; register void* p asm("$5") = 0;
    while ((p = func_001c3748(aa, p)) != 0) {
        if (i == nn) { return u_tail4(((u16*)p)[3], p); }
        i++;
    }
    return 0;
}
}
