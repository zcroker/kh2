#include "../common/types.h"

extern "C" {

extern float D_004f35a4;
extern float D_004f35a8;
void wtarget_00158fd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_00158fd8jjjj");
// 00158fd8 (static initialiser, now made by gcc): moved to src/harata/libdk/bookcamera.cpp

struct S146 { u8 pad[235]; u8 b; u8 pad2[12]; u32 w; };
u32 func_00146ed8(void* a0, S146* p);  // 0x00146ed8: definition moved into src/anon/unit_00145600.cpp

struct E197 { u8 pad[48]; s32 st; };
extern E197* D_0035037c;
extern s32 func_002283f8();
float GetRestTime_00197b98() asm("_ZN2YS5EVENT11GetRestTimeEv");
float GetRestTime_00197b98();  // 0x00197b98: definition moved into src/anon/unit_00195d00.cpp

struct S1b0 { u32 a; u32 pad[2]; u32 b; };
struct R16 { u8 pad[6]; u16 h; };
extern R16* func_0016bc20(u32, u32, s32);
// 001b0448: moved to src/yasui/libys/lookat.cpp

}
