#include "../common/types.h"
// Built with -g: the jal delay slot stays empty like the original.
extern "C" {
u32* ctarget_002f35e8_w1784(u32) asm("_Z13func_002f35e8j"); // absolute alias: the C definition in sdk_w507.c links elsewhere
void FlushCache(s32);
u32* func_00133d38(void);  // 0x00133d38: definition moved into src/anon/unit_00133cf0.cpp
}
