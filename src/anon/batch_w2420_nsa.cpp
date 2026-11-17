#include "../common/types.h"
extern "C" {
struct Ent2a3 { u8 b0; u8 n; u8 b2; u8 b3; u8 pad[4]; };
struct G2a3 { u8 pad[0x1000]; Ent2a3 ent[15]; u8 pad2[0x1084 - 0x1078]; s32 lim; };
extern G2a3* D_0035f5e4;
extern u8* D_0035f5e8;
extern s32 D_0035f214;
extern u32 D_00374ba0;
extern u32 D_00374ba4;
extern s32 D_00374b9c;
extern s32 D_00374b98;
u8* func_002766d0(void);
void func_0028be78(s32, s32);
void func_002fde18(void*, s32, s32);
void func_00138c10(void*, s32);
u32 func_00295430(s32, s32);
s32 func_002954e0(s32);
void* func_00192048(u32);
void* func_0028de08(u32, void*, s32);
s32 func_002a43f0(void);
void func_002a3648(void);
void func_002a3950(void);

void func_002a3318(void);  // 0x002a3318: definition moved into src/anon/unit_002a3318.cpp
}
