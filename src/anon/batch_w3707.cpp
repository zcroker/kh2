#include "../common/types.h"

typedef struct JumpCfg { u8 pad[0xa0]; f32 max; } JumpCfg;
JumpCfg* MGJump_config(void) asm("_ZN2Ti6MGJump6configEv");
extern f32 D_00349e10; /* 1.0f */
typedef struct JS { u8 pad[0x68]; f32 v; u8 flag; } JS;

extern "C" {
/* Ramp a value up toward the jump config's maximum, or back down to 0, by 1.0 per call.
   Register pins ($14 for the offset, $13 for the flag) reproduce the original's t6/t5 numbering. */
void func_002dcf18(u8* a0);  // 0x002dcf18: definition moved into src/anon/unit_002da040.cpp
}
