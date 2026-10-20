#include "../common/types.h"
// 001e7470: DMA kick (replaces the earlier whole-body asm in batch_w220.cpp). Built with -g.
extern "C" {
void func_001e7470(u32 a) {
    volatile u32* p = (volatile u32*)0x1000a000;
    u32 t;
    do {
        t = *p & 0x100;
        asm volatile("nop\n\tnop\n\tnop");  // hazard nops
    } while (t);
    *(volatile u32*)0x1000a020 = 0;
    *(volatile u32*)0x1000a030 = a | 0x80000000;
    *(volatile u32*)0x1000e010 = 2;
    *(volatile u32*)0x1000a000 = 0x145;
}
}
