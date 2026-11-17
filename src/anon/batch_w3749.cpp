// 0013a240: static init/destroy of Obj[2]; second loop pointer q = p + 96 written out by hand.
#include "../common/types.h"
struct Obj { s32 a0; s32 a4; s32 a8; s32 ac; s32 b0; s32 b4; u8 pad[8]; u8 sub[0x40]; s32 c0; u8 pad2[0xc]; ~Obj() {} };
extern Obj D_00347ea0[2];
extern "C" {
void func_0031ae00(void*);
void func_0013a240(int a, int b) asm("_Z13func_0013a240ii");
void func_0013a240(int a, int b);  // 0x0013a240: definition moved into src/anon/unit_001393c8.cpp
}
