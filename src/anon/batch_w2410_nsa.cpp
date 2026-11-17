#include "../common/types.h"
extern "C" {
struct Sub28d { u8 p0[0x148]; s32 x; s32 y; };
struct Obj28d {
    u8 p0[0xc]; u32 flags; u8 p10[8];
    Sub28d sub;
    u8 p168[0x170 - 0x168];
    s32 x; s32 y; s32 ox; s32 oy;
    u8 p180[0x18c - 0x180];
    Obj28d* parent; Sub28d* other;
    u8 p194[0x19c - 0x194];
    u8 started; u8 trig; u8 p19e[2];
    f32 t; s32 sx; s32 sy; s32 dx; s32 dy; s32 lx; s32 ly;
};
extern f32 D_00374448[];
s32 func_00139d78(Obj28d*);
s32 func_00239d20(Sub28d*);
void func_00138cd0(Obj28d*, s32*, s32*);
void func_00138c50(Obj28d*, s32*, s32*);
s32 func_0023aa18(Sub28d*);
s32 func_0023aa38(Sub28d*);
void func_0023a9c0(Sub28d*, s32*, s32*);
double func_00313b80(f32);
s32 func_003142e0(double, double);
f32 func_0028f1e0(f32*, f32*, f32);
void func_0023ade0(Sub28d*);
void func_0028d320(Obj28d* o);  // 0028d320: moved to src/anon/unit_0028c878.cpp
}
