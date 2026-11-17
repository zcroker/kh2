#include "../common/types.h"
extern "C" {
void func_00271b78(void);
void func_00272ae0(void);
void func_00271ee8(void);
void func_002725d8(void);
void func_00272c90(s32);
s32 func_0028b040(s32);
s32 func_00272b60(s32);
u32 func_0028af88(s32);
s32 func_00283ab8(s32);
void func_00256cc0(s32, s32, s32);
void func_0028af18(s32, u32);

// One func_00272c90(1) call per branch: crossjumping merges them, and the
// merged label gets the original's alignment nop after the a1 == 25 path.
void func_00273228(s32 a0, s32 a1);  // 0x00273228: definition moved into src/anon/unit_00271e08.cpp
}
