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

// 002ec4a8: moved to src/anon/unit_002eaf38.cpp

}
