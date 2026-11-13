#include "../common/types.h"

// 0x1056e8-0x105748: a stack of four jmpbuf pointers (grows down from index 4) used with the
// hand-written setjmp/longjmp at 0x105550-0x1056e8 (task coroutines, see func_00102350).

s32 D_0032bb28 = 4;
static u32 D_003a7b60[4];

extern "C" {

void func_001056e8(u32 value) { D_003a7b60[--D_0032bb28] = value; }

void func_00105710(void) { D_0032bb28++; }

u32 func_00105728(void) { return D_003a7b60[D_0032bb28]; }

}
