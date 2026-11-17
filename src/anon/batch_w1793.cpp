#include "../common/types.h"
extern "C" {

struct E436 { u8 pad[408]; u32 x; u8 pad2[24]; };
struct B0f4 { u8 pad[2040]; E436 e[8]; };
union U0f4 { B0f4* p; u32 u; };
extern U0f4 D_0035f0f4;
extern u32 D_0035f010;
extern u32 D_0035f01c;
extern u32 D_0035f024;
s32 func_002891e8(u32);
u32 func_00293bc0();
void func_001a8ff8(u32, s32, s32);
void func_002810c8(u32, u32);
u32 func_00287dc0();
void func_0023ebe0(u32, s32, s32);

void func_0026d748(void);  // 0x0026d748: definition moved into src/anon/unit_0026c450.cpp

void func_001a9a28(u32 m, u32* p, u32* x, u32* y);  // 0x001a9a28: definition moved into src/anon/unit_001a9130.cpp

}
