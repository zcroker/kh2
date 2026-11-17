// Linked unit 0x0029b378-0x0029b698.
#include "../common/types.h"

// 0029b378 (was src/anon/batch_w120.cpp)
namespace n0029b378 {
// 00180f28: moved to src/yasui/libys/progress.cpp


extern u32 D_0035f200 asm("D_0035f200");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00276368(void) asm("func_00276368");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00276888(void) asm("func_00276888");
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
void func_002766b0(s32) asm("func_002766b0");
struct SelState { u32 f0; s8 cur; };
extern SelState* D_0035f5ac asm("D_0035f5ac");
s32 func_00287c10(void) asm("func_00287c10");
void func_0029aac0(s32) asm("func_0029aac0");
void func_0029b698(void) asm("func_0029b698");
void func_0029ecf0(void) asm("func_0029ecf0");
void func_0029aa30(void) asm("func_0029aa30");
s8 func_0029c9d8(s32) asm("func_0029c9d8");
s32 func_00295430(s32, s32) asm("func_00295430");
void func_0028fb28(s32, s32) asm("func_0028fb28");
/*TARGET 0029b378*/
void func_0029b378(void) asm("func_0029b378");
void func_0029b378(void)
{
    s32 sel = func_00289380(D_0035f200);
    s32 st = func_00287cd0();
    func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_0028acc8(D_0035f200) || func_00276888()) {
            if (sel != -1) {
                func_00287f90(0);
                func_0029aac0(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_0029aac0(func_00287c10());
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
        if (k == 15) func_0029b698();
        return;
    }
    if ((sel != -1 || func_00289310(D_0035f200)) && !func_00276398()) {
        func_00276220(0, 2);
        func_00275b60();
    }
    if (st == 0 && func_00276398()) func_00287c90(1);  // state_is_150
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, (s32)func_0029ecf0, 1)) == 0) {
        switch (sel) {
        case -1: break;
        case -4:
            func_00287da0();
            break;
        case -2:
            func_0028f6f0(0);  // record884_refresh_by_index
            func_0029aa30();
            func_00276dc0();
            func_00276220(1, 1);
            func_00287c00(13);
            func_00287cc0(2);
            break;
        default: {
            D_0035f5ac->cur = func_0029c9d8(-1);
            func_0028fb28(1, func_00295430(D_0035f5ac->cur, 0));
            func_0029aa30();
            func_00276dc0();
            s32 a = func_00287bc0();
            s32 b = func_002891e8(D_0035f200);
            func_002765e8(a, b, func_0028b038(D_0035f200));
            func_002765e8(15, 0, 0);
            func_00276220(0, 1);
            func_00287c00(15);
            func_00287cc0(2);
            break;
        }
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n0029b378

