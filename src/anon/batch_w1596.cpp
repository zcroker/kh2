#include "../common/types.h"

extern "C" {

// ---- 00285828
struct O285828 { s32 a[20]; s32 b[3]; s32 c[18]; s32 d[9]; s32 e; u8 f[0x11c - 0xcc]; };
extern O285828* volatile D_0035f2e4;
s32 func_00103570();
O285828* func_001063c0(s32, s32);
void func_00323ad0(void*);
void func_002fde18(void*, s32, s32);
void func_002859c0();
void func_00285828();  // 0x00285828: definition moved into src/anon/unit_002853b8.cpp

// ---- 002822c0
struct E2822c0 { u16 id; u8 kind; u8 z; s16 v; };
struct L2822c0 { union { s32 n; s16 nh; }; E2822c0 e[682]; s32 pad; s32 h; s32 m; s32 sel; };
void func_00281f90(L2822c0*);
s32 func_002811f8(s32, s32);
u16* func_001a8110(u16*);
s32 func_00282228(L2822c0*, u8, s32);
u8 func_001a3570(u16);
s32 func_00282ec0(u16);
void func_002822c0(L2822c0* l, s32 a1, s32 a2);  // 0x002822c0: definition moved into src/anon/unit_00281cf0.cpp

// ---- 00273a28
struct S273a28 { u8 pad[4]; s8 n; };
extern S273a28* D_0035f12c;
extern s32 D_0035f01c;
extern s32 D_0035f04c;
s32 func_00257070(s32);
s32 func_002891e8(s32);
s32 func_0028b038(s32);
s32 func_002892f8(s32);
void func_0028bfc0(s32, s32);
void func_0028be78(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);
void func_0028afd0(s32, s32);
void func_0028af90(s32, s32);
void func_00273a28();  // 0x00273a28: definition moved into src/anon/unit_00271e08.cpp

}
