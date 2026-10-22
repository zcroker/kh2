#include "../common/types.h"
// 002728c8 (pro, split row from 00272758).
extern "C" {
u8* func_00257770();
s32 func_00257140(s32);
void func_00138c10(u8*, s32);
s32 func_00192048(u16);
extern u16 D_00373a78[];
void func_002728c8()
{
    u8* p = func_00257770() + 24740;
    u16* id = D_00373a78;
    for (s32 i = 0; i < 2; i++) {
        func_00138c10(p, func_00257140(0));
        *(s32*)(p + 408) = func_00192048(*id++);
        p += 436;
    }
}
}
