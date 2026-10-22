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
void func_00273228(s32 a0, s32 a1)
{
    s32 s1;
    u32 fl;
    s32 snd;
    if (a1 == 25) {
        func_00271b78();
        func_00272c90(1);
    } else if (a1 == 26 || a1 == 27) {
        func_00272ae0();
        func_00271ee8();
        func_00272c90(1);
    } else {
        func_002725d8();
        func_00272c90(1);
    }
    if (a1 == 26 || a1 == 27) {
        s1 = func_00272b60(func_0028b040(a0));
        fl = func_0028af88(a0);
        if (s1) fl |= 0x200; else fl &= ~0x200;
        snd = -1;
        if ((s1 == 2 && func_00283ab8(0)) || (s1 == 1 && func_00283ab8(1))) {
            fl |= 0x400;
            snd = 0xcbdd;
        } else {
            fl &= ~0x400;
        }
        func_00256cc0(0xb61a, snd, -1);
        func_0028af18(a0, fl);
    }
}
}
