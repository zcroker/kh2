// Linked unit 0x0015d440-0x0015d540.
#include "../common/types.h"

// 0015d440 (was src/anon/batch_w233.cpp)
namespace n0015d440 {
extern u8 D_0034af40[] asm("D_0034af40");
struct G { u8 p0[276]; u32 f114; u8 p1[48]; u32 f148; u32 f14c; };
extern G D_0034b0e0 asm("D_0034b0e0");
void func_00236788(void*) asm("func_00236788");
// to_236830
u32 func_00239d30(void*, u32) asm("func_00239d30");
s32 func_00239d10(void*) asm("func_00239d10");
u32 func_0014aba8() asm("func_0014aba8");
void func_0014aa58(u32, s32, s32) asm("func_0014aa58");
void func_0013f020() asm("func_0013f020");
void func_0023acd8(void*) asm("func_0023acd8");
void YI__SEQUENCE__Draw(void*) asm("YI__SEQUENCE__Draw");
/*TARGET 0015d440*/
s32 dk__KeyHoleJumpEffect__jumpEffectOut_task() asm("dk__KeyHoleJumpEffect__jumpEffectOut_task");
s32 dk__KeyHoleJumpEffect__jumpEffectOut_task() {
    func_00236788(D_0034af40);  // to_236830
    if (!(u8)func_00239d30(&D_0034b0e0, D_0034b0e0.f114)) {
        if (!func_00239d10(&D_0034b0e0)) {
            func_0014aa58(func_0014aba8(), 1, 0);
            func_0013f020();
            return 1;
        }
    }
    func_0023acd8(&D_0034b0e0);
    D_0034b0e0.f148 = 0;
    D_0034b0e0.f14c = 0;
    YI__SEQUENCE__Draw(&D_0034b0e0);
    return 0;
}
}  // namespace n0015d440


// 0015d4e8 (gap: the field task that waits until the demo sequence ends). The first step is written out
// before the loop; cross-jumping merges the two TaskYield calls, which puts the argument moves before the loop label.
namespace n0015d4e8 {
s32 dk__KeyHoleJumpEffect__jumpEffectOut_task() asm("dk__KeyHoleJumpEffect__jumpEffectOut_task");
void func_00102448(u32, s32) asm("func_00102448");  // Tz::TaskYield
void func_0014e098(s32) asm("func_0014e098");
/*TARGET 0015d4e8*/
void func_0015d4e8(u32 task) asm("func_0015d4e8");
void func_0015d4e8(u32 task) {
    if (dk__KeyHoleJumpEffect__jumpEffectOut_task()) return;
    func_00102448(task, 0);
    func_0014e098(216);
    while (!dk__KeyHoleJumpEffect__jumpEffectOut_task()) {
        func_00102448(task, 0);
        func_0014e098(216);
    }
}
}  // namespace n0015d4e8
