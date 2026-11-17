#include "../common/types.h"
extern "C" {
s32 func_00139d78(u8*);
extern u8* D_0035f038;

// 002577b0: runs check func_00139d78 over every slot of the D_0035f038 block (7 singles, then 24 rows of 4);
// returns the first nonzero result. The loop result lives in its own variable and leaves by break: that keeps
// a return copy at the loop exit until register allocation, so the exits lose their loop-exit mark and reorg
// fills them from the epilogue (bnezl + ld s0) like the original.
s32 func_002577b0(void);  // 0x002577b0: definition moved into src/anon/unit_00254020.cpp
}
