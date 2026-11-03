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

void func_00269e20(void) {
    u32 p = func_00257770();
    s32 m = func_00287bc0();
    u32 t = m - 5;
    register s32 a0 asm("$4");
    asm volatile("li %0,2" : "=r"(a0));
    u32 c = t < 5;
    register s32 k asm("$5") = 0xe5;
    if (c) {
        s32 i = func_00269508(func_002570a0(a0, k));
        func_0028dac8(p, D_00373798[i].b);
        func_0028dac8(p + 0xb350, D_003737c8[i].b);
    } else {
        func_0028dac8(p, k);
        func_0028dac8(p + 0xb350, 0x121);
    }
    if (func_0028be58(D_0035f04c)) {
        func_0028bdb8(D_0035f04c);
    }
}
}
