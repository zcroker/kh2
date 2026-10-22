#include "../common/types.h"
extern "C" {
void func_0023d320();
s32 func_002888c8();
s32 func_002535d0(s32);
void func_00242740(s32);
s32 func_0028cbf8();
s16 func_0028d0c8(s32);
void func_00287910(s32, s32, s32);
s32 func_00103570();
void func_0028c878(s32, s32);
void func_002530c8();
void func_002425d0(s32);
struct W1595Fns { void (*f0)(); void (*f4)(); };
W1595Fns* func_00253330(s32);
extern s32 D_0035f3d4;
union W1595U { s32 i; u8 c; };
extern W1595U D_0035f3d4u asm("D_0035f3d4");
extern volatile s32 D_0035f3d4v asm("D_0035f3d4");
struct W1595Pair { s16 a, b; };
extern W1595Pair D_01dae6a8;

void func_00252fe8(s32 id) {
    func_0023d320();
    s32 k = id;
    if (id == 10) k = func_002888c8();
    if (k != 9 && k != 15 && k != 8) func_00242740(func_002535d0(k));
    D_01dae6a8.a = D_0035f3d4v;
    D_01dae6a8.b = !func_0028cbf8() ? -1 : func_0028d0c8(0);
    func_00287910(id, 4, 0);
    func_0028c878(func_00103570(), 3);
    func_002530c8();
    func_002425d0(1);
    func_00253330(id)->f4();
}
}
