#include "../common/types.h"
extern "C" {
struct P191e40 { u8 pad[0x160]; u32 flags; u8 pad2[0xb50 - 0x164]; s32 state; };
extern P191e40* D_0034e948;
extern u8 D_00351ec0[];
s32 func_00191ab8();
s32 c191e40_001c8db8(void*, s32) asm("_Z16ctarget_001c8db8jjjj");
s32 c191e40_CanOpenCampMenu() asm("_ZN2YS8PROGRESS15CanOpenCampMenuEv");
s32 c191e40_0019ba60(P191e40*) asm("_Z16ctarget_0019ba60jjjj");
s32 func_001a6850();
s32 func_00191e40()
{
    if (func_00191ab8() || c191e40_001c8db8(D_00351ec0, 0) || !c191e40_CanOpenCampMenu()) return 1;
    P191e40* p = D_0034e948;
    if (!c191e40_0019ba60(p) || p->state == 12 || (p->flags & 0x4000)) return 1;
    return func_001a6850() != 0;
}
}
