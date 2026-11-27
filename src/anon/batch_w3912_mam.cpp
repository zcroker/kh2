// helper w3912: matched under -fmove-all-movables (_mam). Keys: n+1 and n+2 written inline in the loop
// calls (loop.c hoists them, so n keeps few refs and lands in s8), the third argument of
// func_00138c68 written as i * h (a loop.c giv whose zero init sorts after the pointer giv init).
#include "../common/types.h"
namespace n002995e8 {
struct E { u8 pad[408]; };
struct Obj { u8 pad[30360]; E a[32]; E b[12]; };
extern "C" {
extern void* D_0035f200;
extern s32 D_0035f3d4;
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;
void* func_00276348(void);
Obj* func_002766d0(void);
void func_00276588(s32);
void func_00288e88(void*);
void Tz__JmAnsem__GetHaveReport(void);
void func_0029a2a0(void);
void func_00275a80(void);
s32 func_00287bc0(void);
void func_00276088(s32, s32*, s32*);
void Tz__Jiminy__SetMainFrameLRMess(s32, s32);
s32 Tz__JmWorldSel__GetId2WorldName(s32, s32);
void func_00275e68(s32);
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(void*);
void func_0028dcc0(void*, void*);
s32 func_0023aa78(void*);
void Tz__Select__SetItem(void*, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(void*, s32);
void func_00138c68(void*, s32, s32);
void Tz__JmCollection__CreateGra(s32);
s32 func_00276608(s32);
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32);
void func_002765e8(s32, s32, s32);
void Tz__JmCollection__SetupSelMess(void);
s32 func_0028af88(void*);
void func_0028af18(void*, s32);
void func_0029a740(void);
void func_00287cc0(s32);

void func_002995e8(void);  // 0x002995e8: definition moved into src/anon/unit_002982f0.cpp
}
}
