#include "../common/types.h"

extern "C" {
struct VtM { u8 p[8]; s32 (*get)(void*); };
struct M6 { VtM* vt; };
struct R6 { u8 p[8]; M6* m; };
struct Q6 { u8 p[8]; s32 v; };
struct C6 { u8 p[0x10c]; u32 f10c; };
struct O6 {
    u8 p0[8];
    C6* p8;       // 8
    M6* fc;       // c
    s32 f10;      // 10
    s32 f14, f18; // 14, 18
    u8 p1c[4];
    u32 f20;      // 20
    u32 f24;      // 24
    u8 p28[4];
    f32 f2c;      // 2c
    f32 f30;      // 30
    s32 f34;      // 34
    u8 p38[0x104 - 0x38];
    u32 f104;     // 104
    u8 p108[0x148 - 0x108];
    s32* ref;     // 148
    u8 p14c[0x194 - 0x14c];
    s32 f194;     // 194
};
s32 func_0019c6f0(C6*);
void func_001d7a50(void*);
void func_00180ce0(O6*);
void func_00189258(O6*);
R6* func_00168b38(void*, s32, s32);
void func_00180800(O6*, s32);
void func_001807d0(O6*, f32);
void func_0017eee8(O6*, f32, f32);
void func_0017f938(O6*);
void func_001807a0(O6*, f32, f32);

// 0017efa0: moved to src/yasui/libys/motion.cpp
}
