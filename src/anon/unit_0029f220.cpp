// Linked unit 0x0029f220-0x0029f520.
#include "../common/types.h"

// 0029f220 (was src/anon/batch_w1611.cpp)
namespace n0029f220 {
extern void* D_0035f200 asm("D_0035f200");
s32 func_00242848(s32) asm("func_00242848");
void func_00274cf0(s32) asm("func_00274cf0");
void func_00275b60() asm("func_00275b60");
void func_00276220(s32, s32) asm("func_00276220");
s32 func_00276358() asm("func_00276358");
s32 func_00276368() asm("func_00276368");
s32 func_00276398() asm("func_00276398");
void func_002765e8(s32, s32, s32) asm("func_002765e8");
void func_002766b0(s32) asm("func_002766b0");
s32 func_00276888() asm("func_00276888");
void func_00276dc0() asm("func_00276dc0");
s32 func_00287bc0() asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30() asm("func_00287c30");
void func_00287c90(s32) asm("func_00287c90");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0() asm("func_00287cd0");
void func_00287da0() asm("func_00287da0");
s32 func_00287df0(s32, s32, s32, void*, s32) asm("func_00287df0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018() asm("func_00288018");
s32 func_00288040() asm("func_00288040");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_00289310(void*) asm("func_00289310");
s32 func_00289380(void*) asm("func_00289380");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028af18(void*, s32) asm("func_0028af18");
s32 func_0028b038(void*) asm("func_0028b038");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_002925c0() asm("func_002925c0");
s32 func_00292630() asm("func_00292630");
void func_002995e8() asm("func_002995e8");
void func_0029ee30() asm("func_0029ee30");
void func_0029ee38() asm("func_0029ee38");
void func_0029f520() asm("func_0029f520");
extern char D_002a0518[] asm("D_002a0518");
/*TARGET 0029f220*/
void func_0029f220(void) asm("func_0029f220");
void func_0029f220(void) {
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_0029ee38();
            }
            return;
        }
        if (func_00292630()) return;
        func_0029ee38();
        func_00287c30();
        s32 mode = func_00287bc0();
        func_0028af18(D_0035f200, 0x73);
        func_00276220(func_00276358(), 0);
        if (mode == 13) {
            func_00274cf0(13);
            func_002925c0();
            func_002766b0(0);
            func_002995e8();
        } else if (mode == 25) {
            func_0029f520();
        }
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) {
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, D_002a0518, 1))) {
        switch (sel) {
        default:
            func_0029ee30();
            func_00276dc0();
            func_00276220(0, 1);
            func_00287c00(25);
            func_00287cc0(2);
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            break;
        case -4:
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            func_00287da0();
            break;
        case -1:
            break;
        case -2:
            func_0028f6f0(0);
            func_0029ee30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            {
                s32 a = func_00287bc0();
                s32 b = func_002891e8(D_0035f200);
                func_002765e8(a, b, func_0028b038(D_0035f200));
            }
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0029f220

