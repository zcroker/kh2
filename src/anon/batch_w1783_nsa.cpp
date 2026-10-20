#include "../common/types.h"

extern "C" {

// ---- 002ec4a8 (needs -fno-strict-aliasing for the sb/lw order)
struct EO { u8 _0[0x90]; u32 _90; };
struct EA { u8 _0[0x508]; EO* _508; };
void func_001d14b0(EA*, s32);
u8 func_002cd008(EO*, u32);
void func_002eda90(u32, s32, f32);
void func_002edaf8(u32);
extern u32 D_00363560;
extern u8 D_01e2c064;
extern u32 D_003637d0;
extern f32 D_0036354c;

void func_002ec4a8(u32 a0, EA* a1) {
    func_001d14b0(a1, 3);
    D_01e2c064 = func_002cd008(a1->_508, D_00363560) ^ 1;
    u8 v = D_01e2c064;
    D_00363560 = a1->_508->_90;
    if (v) func_002eda90(D_003637d0, 20, 60.0f);
    else func_002edaf8(D_003637d0);
    D_0036354c = 12.0f;
}

}
