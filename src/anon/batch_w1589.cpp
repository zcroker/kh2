#include "../common/types.h"

extern "C" {

s32 func_00103570(void);
void* func_001063c0(s32, s32);
void func_002fde18(void*, s32, s32);
void func_0029dfc0(void);
void func_0029e4c8(s32);
void func_00276690(s32);
u32 func_0028af88(s32);
void func_0028af18(s32, u32);
void func_00287cc0(s32);
extern s32 D_0035f200;
s32 func_00287bc0(void);
s32 func_0028b040(s32);
s32 func_002570a0(s32);
u8* func_00273140(s32);
s32 func_001a6598(u16);
void func_00273760(s32, s32);
extern s32 D_0035f01c;

struct W1589En { u8 x[2]; s8 a; u8 y[2]; s8 b; u8 z[2]; };
struct W1589S { u8 pad[4]; u16 h4; u8 pad6; s8 n; u8 p8[4]; W1589En e[1]; };
/* union with a u16 member: the original reloads the pointer after each u16 store */
union W1589G { W1589S* p; void* v; u16 h; s8 c; };
extern W1589G D_0035f230;

void func_00277020(void);  // 0x00277020: definition moved into src/anon/unit_002748a0.cpp

void func_002799b0(void);  // 0x002799b0: definition moved into src/anon/unit_002793b0.cpp

void func_0029c568(void);  // 0x0029c568: definition moved into src/anon/unit_0029ba88.cpp

void func_002736f8(void);  // 0x002736f8: definition moved into src/anon/unit_00271e08.cpp

}
