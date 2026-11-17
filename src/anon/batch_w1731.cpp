#include "../common/types.h"
// sceGsResetPath is whole-body asm that links elsewhere: C++ linkage makes the call bind to
// the absolute alias _Z14sceGsResetPathv.
void sceGsResetPath();
extern "C" {

// --- 002d5588: true when the linked object's id is 0x38 or 0x37
struct I_w1731 { u8 pad[4]; s32 id; };
struct P_w1731 { u8 pad[12]; I_w1731* i; };
s32 func_002d5588(P_w1731* p);  // 0x002d5588: definition moved into src/anon/unit_002d4548.cpp

// --- 002ef340: by-value struct params (spilled, unused), call member at +0x40 then a global update
struct A_w1731 { u32 x, y; };
struct B_w1731 { u16 z, w; };
void func_0023cc18(void*);
void func_002ef618();
// 002ef340: moved to src/anon/unit_002ef1f8.cpp

// --- 0014d680
void func_002f1e18(s32, s32, s32, s32);
void func_0014d6b0();
void u_call0_0014d680(void) asm("_Z16u_call0_0014d680v");
// 0014d680: moved to src/anon/unit_0014d680.cpp

}
