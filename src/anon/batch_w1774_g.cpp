#include "../common/types.h"
extern "C" {

void func_002f25a0(s32, s32);
s32 func_00133d38(void);
void func_003058a0(s32);
s32 func_00133f60(void);
u32 func_001336f8(void*);
void func_002f3918(s32, u32);
extern s32 D_00347cac;
extern volatile u8 D_00347cb4;
extern u8 D_00347c88[];

/* sync.p is the EE pipeline barrier; gcc has no C form for it. */
s32 func_00133f80(void) {
    func_002f25a0(0, 0);
    D_00347cac = func_00133d38();
    *(volatile u32*)0x10003010 = 1;
    asm volatile("sync.p");
    func_003058a0(0);
    D_00347cb4 = 1;
    s32 r = func_00133f60();
    asm volatile("sync.p");
    func_002f3918(D_00347cac, func_001336f8(D_00347c88) & 0xcfffffff);
    asm volatile("sync.p");
    return r;
}

}
