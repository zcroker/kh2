// Menu mode set-up hook 0x103100 (first function of the menu-mode file; the rest is unit_001031b0.cpp).
// Linked as its own unit: it matches only without interblock scheduling (-fno-sched-interblock), which
// the rest of the file does not take.
#include "types.h"

namespace g00103100 {
extern "C" {
extern s32 D_003a6a50 asm("D_003a6a50");
extern u8 D_0032ba30 asm("D_0032ba30");
extern void* D_0032ba14 asm("D_0032ba14");
struct MODE { u32 f0; u32 task; };
extern MODE D_0032b9e8 asm("D_0032b9e8");
void func_00167ee0(void) asm("func_00167ee0");
void func_00103748(void) asm("func_00103748");
void MENU__CreateAllocator(s32, void*) asm("MENU__CreateAllocator");
u32 func_001031b0(void) asm("_ZN4MENU17CreateTaskManagerEv");
s32 func_001033d8(s32) asm("func_001033d8");
void func_00252fe8(s32) asm("func_00252fe8");
void func_00242f00(s32) asm("func_00242f00");
void func_001ddc08(void) asm("func_001ddc08");
void func_001e0310(s32) asm("func_001e0310");
}
void func_00103100(void) asm("func_00103100");
void func_00103100(void)
{
    s32 cur;

    func_00167ee0();
    if (D_0032ba30 == 0) {
        func_00103748();
    }
    if (D_0032ba14 == 0) {
        MENU__CreateAllocator(0, 0);
    }
    D_0032b9e8.task = func_001031b0();
    cur = D_003a6a50;
    if ((u32)(cur - 100) >= 800) {
        func_00252fe8(func_001033d8(cur));
    } else {
        func_00242f00(func_001033d8(cur));
    }
    func_001ddc08();
    func_001e0310(3);
}
}  // namespace g00103100

