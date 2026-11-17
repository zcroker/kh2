// Linked unit 0x002a52b0-0x002a5590.
#include "../common/types.h"

// 002a52b0 (was src/anon/batch_w120.cpp)
namespace n002a52b0 {
// 00180f28: moved to src/yasui/libys/progress.cpp


extern u32 D_0035f200 asm("D_0035f200");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287f90(s32) asm("func_00287f90");
s32 func_00292630(void) asm("func_00292630");
void func_00287c30(void) asm("func_00287c30");
void func_0028af18(u32, s32) asm("func_0028af18");
s32 func_00276358(void) asm("func_00276358");
void func_00276220(s32, s32) asm("func_00276220");
void func_00274cf0(s32) asm("func_00274cf0");
// state_dispatch_0_1_2
void func_002925c0(void) asm("func_002925c0");
void func_002995e8(void) asm("func_002995e8");
s32 func_00289310(u32) asm("func_00289310");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00287da0(void) asm("func_00287da0");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_00276dc0(void) asm("func_00276dc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_0028b038(u32) asm("func_0028b038");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
// 0x0026c470: definition moved into src/anon/unit_0026c450.cpp


s32 func_002a6718(void) asm("func_002a6718");
void func_002a67a8(void) asm("func_002a67a8");
void func_002a4df8(void) asm("func_002a4df8");
void func_002766b0(s32) asm("func_002766b0");
void func_002a5590(void) asm("func_002a5590");
void func_002a6878(void) asm("func_002a6878");
void func_002a4df0(void) asm("func_002a4df0");
/*TARGET 002a52b0*/
void func_002a52b0(void) asm("func_002a52b0");
void func_002a52b0(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_002a6718()) {
            if (sel != -1) {
                func_00287f90(0);
                func_002a67a8();
            }
            return;
        }
        if (func_00292630()) return;
        func_002a4df8();
        func_00287c30();
        s32 k = func_00287bc0();
        func_0028af18(D_0035f200, 115);
        func_00276220(func_00276358(), 0);
        if (k == 13) {
            func_00274cf0(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
            return;
        }
        if (k == 38) func_002a5590();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_002a6878, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4: {
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_00287da0();
            break;
        }
        case -2: {
            func_0028f6f0(0);  // record884_refresh_by_index
            func_002a4df0();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        default: {
            func_002a4df0();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287c00(38);
            func_00287cc0(2);
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002a52b0

