// 00269e20 (-g): partial inline asm. li a0,2 is one asm instruction so it is scheduled
// before the sltiu like the original; a1 = 0xe5 is shared by both branches (pinned to $5).
#include "../common/types.h"
extern "C" {
u32 func_00257770(void);
s32 func_00287bc0(void);
s32 func_002570a0(s32, s32);
s32 func_00269508(s32);
void func_0028dac8(u32, s32);
s32 func_0028be58(u32);
void func_0028bdb8(u32);
struct E6 { s16 a; s16 b; s16 c; };
extern E6 D_00373798[];
extern E6 D_003737c8[];
extern u32 D_0035f04c;

void Tz__CmEquip__FadeOutList(void);  // 0x00269e20: definition moved into src/anon/unit_00269a60.cpp
}
