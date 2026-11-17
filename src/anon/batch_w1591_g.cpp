#include "../common/types.h"
// Built by the original with debug info (-g): see Makefile rule for *_g.cpp.
extern "C" {
s32 func_00103570();
s32 func_001063c0(s32, s32);
s32 func_001063f0(s32, s32);
void func_002907c0(s32, s32, s32);
void func_00324380(s32);
extern s32 D_0035f5f4;
extern s32 D_0035f5f8;
extern s8 D_0035f5fc;
extern s8 D_0035f5fd;
void func_002a68e8(void) {
    s32 v = func_001063c0(0xE20, func_00103570());
    func_00324380(v);
    D_0035f5f4 = v;
    s32 s = func_001063c0(0x18, func_00103570());
    func_002907c0(s, func_00103570(), 10);
    D_0035f5f8 = s;
    D_0035f5fc = -1;
    D_0035f5fd = -1;
}
void func_00324510(s32);
void func_0023f800(s32);
void func_002815d8();
void func_002aeb28();
extern s32 D_0035f630;
extern s32 D_0035f634;
extern s32 D_0035f638;
void func_002aea98(void);  // 0x002aea98: definition moved into src/anon/unit_002a99c8.cpp
}
