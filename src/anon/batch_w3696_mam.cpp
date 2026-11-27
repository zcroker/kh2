// 0026bc10: built with -fmove-all-movables (*_mam.cpp). The D_0035f0f4 / D_0035f010 reads in the third loop go through
// u8 unions so they are reloaded after the f1b0 store, like the original.
#include "../common/types.h"
extern "C" {
struct B4 { u8 b[4]; };
struct Elem { u8 pad0[0x18]; u8 f18[0x198 - 0x18]; s32 f198; u8 pad1[0x1b0 - 0x19c]; s32 f1b0; };
union HU { s16 h; u8 c; };
struct Big { u8 pad0[0x7f8]; Elem e[4]; HU arr[4][4]; };
extern B4* D_0035f0fc;
extern Big* D_0035f0f4;
union BigU { Big* p; u8 c; };
extern BigU D_f0f4u asm("D_0035f0f4");
union U32U { u32 v; u8 c; };
extern U32U D_f010u asm("D_0035f010");
extern u32 D_0035f01c;
extern u32 D_0035f024;
extern u32 D_0035f010;
extern u32 D_0035f03c;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern s32 D_0035f3d4;
extern s32 D_0037382c;
extern s32 D_00373830;
B4* func_00293bc0(void);
void func_002937c0(void);
void func_00288f48(u32, s32, s32, s32, s32);
void func_0028f4d8(s32, s32, s32);
s32 func_00256b68(s32);
void func_0028d8c0(s32, s32, u32, u32, u32, s32, s32, s32);
s32 func_00281100(u32);
s32 func_00281180(u32, s32);
s32 func_00281140(u32, s32);
void Tz__Select__SetItem(u32, s32, u32, u32, u32, s32, HU*, HU*);
u8* func_002891b8(u32, s32);
void func_00138c10(u8*, s32);
void Tz__Select__SetExOffset(u32, s32, s32, s32);
void func_0028dcc0(void*, s32);
s32 func_001a8c78(B4*, s32);
void func_0028d980(Elem*, s32, u32, u32, u32, s32, s32, s32, s32);
s32 func_0023aa98(void*);
void func_00138c68(Elem*, s32, s32);
void func_0028b1b0(u32, s32);
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32);
s32 func_0028af88(u32);
void func_0028af18(u32, s32);
void func_00257708(s32);
void func_00287cc0(s32);
void func_0026c140(void);
s32 func_00287bc0(void);
void func_0026c048(void);
void func_0026cb38(void);

void func_0026bc10(void);  // 0x0026bc10: definition moved into src/anon/unit_0026a900.cpp

}
