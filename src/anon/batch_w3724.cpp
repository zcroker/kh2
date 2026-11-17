#include "../common/types.h"
// w3724: matched functions.
extern "C" {
void* func_001c3748(s32, void*);
s32 u_tail4(u32, void*) asm("_Z16u_tail4_00192048jjjj");
// Walks a list with func_001c3748 and passes the n-th entry (its u16 at +6) to u_tail4.
// Register pins: n in s1 and the cursor p in a1, as in the original (move a1,zero before the loop).
s32 func_002c2610(s32 a0, s32 n);  // 0x002c2610: definition moved into src/anon/unit_002c2228.cpp
}
