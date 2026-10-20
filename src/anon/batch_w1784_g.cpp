#include "../common/types.h"
// Built with -g: the jal delay slot stays empty like the original.
extern "C" {
u32* ctarget_002f35e8_w1784(u32) asm("_Z13func_002f35e8j"); // absolute alias: the C definition in sdk_w507.c links elsewhere
void FlushCache(s32);
u32* func_00133d38(void) {
    *(volatile u32*)0x1000e010 = 6;
    *(volatile u32*)0x1000e020 = 2;
    *(volatile u32*)0x10003c20 = 6;
    *(volatile u32*)0x10009010 = 0;
    *(volatile u32*)0x10009020 = 0;
    *(volatile u32*)0x10009030 = 0;
    *(volatile u32*)0x10009040 = 0;
    *(volatile u32*)0x10009050 = 0;
    u32* p = ctarget_002f35e8_w1784(1);
    *p = 0x45;
    FlushCache(0);
    asm volatile("sync.p");
    return p;
}
}
