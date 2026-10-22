#include "../common/types.h"

struct O161030 {
    u8 pad[0x80];
    O161030* next;
    u8 pad2[0x1b0 - 0x84];
    s32 f1b0;
};

extern "C" {
void func_0013efe8(void);
void* c8006_getFieldMode(void) asm("_Z12getFieldModev");
void* c8006_create_task(void*, int, int, void*) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void func_00102818(s32, s32, s32, void (*)(), s32);
void c8006_clear(void) asm("_ZN2dk20clearDrawFrameEnableEv");
s32 c8006_getAllFade(void) asm("_ZN2dk10getAllFadeEv");
s32 c8006_getImd(int) asm("_ZN2dk8Field2DD6getImdEi");
s32 c8006_getSqd(int) asm("_ZN2dk8Field2DD6getSqdEi");
void c8006_239bf8(void*, u32) asm("_Z16wtarget_00239bf8jjjj");
void func_0015d4e8(void);
void func_0015d5d0(void);
void func_0014aa80(s32, s32, s32);
void func_002362b0(void*, s32);
/* Declared as returning s32: this gives the original a2, a0, a1 argument move order. */
s32 func_00239988(void*, s32, void*);
extern u8 D_0034af40[];
extern u8 D_0034b0e0[];
extern O161030* D_004f3b38;

void func_0015d540(void) {
    func_0013efe8();
    func_00102818(*(s32*)((u8*)c8006_getFieldMode() + 4), 0, 0x1d4c0, func_0015d4e8, 0x1000);
    func_002362b0(D_0034af40, c8006_getImd(2));
    func_00239988(D_0034b0e0, c8006_getSqd(2), D_0034af40);
    c8006_239bf8(D_0034b0e0, 1);
}

void func_0015d690(void) {
    c8006_clear();
    c8006_create_task(*(void**)((u8*)c8006_getFieldMode() + 4), 1, 0x1D4C0, (void*)func_0015d5d0);
    func_0014aa80(c8006_getAllFade(), 1, 0);
    func_002362b0(D_0034af40, c8006_getImd(2));
    func_00239988(D_0034b0e0, c8006_getSqd(2), D_0034af40);
    c8006_239bf8(D_0034b0e0, 0);
}

static inline O161030* next_161030(O161030* p) {
    if (p == 0) return D_004f3b38;
    return p->next;
}

O161030* func_00161030(s32 n) {
    O161030* p = 0;
    s32 i = 0;
    while ((p = next_161030(p)) != 0) {
        if (p->f1b0 == 0) {
            if (i == n) return p;
            i++;
        }
    }
    return 0;
}
}
