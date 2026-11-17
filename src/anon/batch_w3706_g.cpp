// Built with -g (the original leaves the first jal delay slot empty).
#include "../common/types.h"
extern "C" {
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_00323fd8(s32);
void func_0023d4f8(s32, u32);
typedef s32 (*VFn)(u32, s32, s32);
extern u32 D_00347f80;
extern s32 D_0035f5ac;
extern s32 D_0035f5b0;
extern s8 D_0035f5b4;
extern s16 D_0035f5b6;
extern s32 D_0035f5b8;
extern s32 D_0035f5bc;
extern s32 D_0035f5c0;
extern s8 D_0035f5c4;
// Allocates two work buffers, then asks the manager object (D_00347f80 + 20) for entry 0x14f0.
void func_0029a820(void);  // 0x0029a820: definition moved into src/anon/unit_00299920.cpp
}
