#include "../common/types.h"

// 0x15d440-0x15d828 (unit: 0x15d540-0x15d828): the field 2D-demo sequence player. It owns a YI::IMAGE (0x34af40) and a
// YI::SEQUENCE (0x34b0e0), and runs them from a field task.

namespace YI {
class IMAGE {
public:
    IMAGE();   // 0x2361a0
    ~IMAGE();  // 0x2361d0
    u8 data[0x1a0];
};
class SEQUENCE {
public:
    SEQUENCE();   // 0x239700
    ~SEQUENCE();  // 0x239870
    u8 pad0[276];
    u32 loop;     // 276
    u8 pad1[48];
    u32 f148;     // 328
    u32 f14c;     // 332
};
}  // namespace YI

YI::IMAGE D_0034af40;
YI::SEQUENCE D_0034b0e0;

extern "C" {
void func_00236788(void*);  // to_236830
s32 func_00239d30(void*, u32);
s32 func_00239d10(void*);
u8* func_0014aba8(void);
void func_0014aa58(u8*, s32, s32);
void func_0013f020(void);
void func_0023acd8(void*);
void func_0023ade0(void*);
void func_00102448(u32, s32);  // Tz::TaskYield
void func_0014e098(s32);
void func_0013efe8(void);
void* c8006_getFieldMode(void) asm("_Z12getFieldModev");
void* c8006_create_task(void*, int, int, void*) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void func_00102818(s32, s32, s32, void (*)(), s32);
void c8006_clear(void) asm("_ZN2dk20clearDrawFrameEnableEv");
s32 c8006_getAllFade(void) asm("_ZN2dk10getAllFadeEv");
s32 c8006_getImd(int) asm("_ZN2dk8Field2DD6getImdEi");
s32 c8006_getSqd(int) asm("_ZN2dk8Field2DD6getSqdEi");
void c8006_239bf8(void*, u32) asm("_Z16wtarget_00239bf8jjjj");
void func_0014aa80(s32, s32, s32);
void func_002362b0(void*, s32);
/* Declared as returning s32: this gives the original a2, a0, a1 argument move order. */
s32 func_00239988(void*, s32, void*);
s32 func_0013ef80(u32);  // get_global_byte_358700
void func_001024a8(u32);
void func_0013f048(void);

// 0x15d440 (one step of the player) and 0x15d4e8 (the task that waits for it to finish) open this
// file, but are not linked here yet: retail sets the TaskYield arguments before the loop label of
// 0x15d4e8 and leaves that jal's delay slot empty, which no C form tried so far gives.
s32 func_0015d440();
void func_0015d4e8(u32 task);

void func_0015d540(void) {
    func_0013efe8();
    func_00102818(*(s32*)((u8*)c8006_getFieldMode() + 4), 0, 0x1d4c0, (void (*)())func_0015d4e8, 0x1000);
    func_002362b0(&D_0034af40, c8006_getImd(2));
    func_00239988(&D_0034b0e0, c8006_getSqd(2), &D_0034af40);
    c8006_239bf8(&D_0034b0e0, 1);
}

void func_0015d5d0(u32 a0) {
    if (!func_0013ef80(a0)) { func_001024a8(a0); func_0013f048(); }
    func_00236788(&D_0034af40);
    if (!(u8)func_00239d30(&D_0034b0e0, D_0034b0e0.loop) && !func_00239d10(&D_0034b0e0)
        && !*(s32*)(func_0014aba8() + 252)) { func_001024a8(a0); func_0013f048(); }
    func_0023acd8(&D_0034b0e0);
    D_0034b0e0.f148 = 0;
    D_0034b0e0.f14c = 0;
    func_0023ade0(&D_0034b0e0);
}

void func_0015d690(void) {
    c8006_clear();
    c8006_create_task(*(void**)((u8*)c8006_getFieldMode() + 4), 1, 0x1D4C0, (void*)func_0015d5d0);
    func_0014aa80(c8006_getAllFade(), 1, 0);
    func_002362b0(&D_0034af40, c8006_getImd(2));
    func_00239988(&D_0034b0e0, c8006_getSqd(2), &D_0034af40);
    c8006_239bf8(&D_0034b0e0, 0);
}

}
