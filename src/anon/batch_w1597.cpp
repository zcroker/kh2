#include "../common/types.h"

extern "C" {

// 00280ef8: fill the 4 slots of a list object from key's entries; o->n = number of valid ones
struct W1597E20 { s16 id; s16 v; s16 w; s16 pad; s32 a; s32 b; s32 c; };
struct W1597C20 { s32 pad0; s16 id; s16 v; s16 w; s16 pad; s32 a; s32 b; s32 c[0]; };
union W1597KU { s32 v; s16 h; };
struct W1597Obj { s32 n; W1597E20 e[4]; W1597KU key; };
void func_002fde18(void*, s32, s32);
s32 func_001a8c10(s32, s32);
s32 func_00281108(W1597Obj*, s32);
s32 func_001b77a8(s32);
s32 func_001a1658(s32, s32);
s32 func_001a8bf8(s32, s32);
void wtarget_00280ef8(W1597Obj* o, s32 key) asm("_Z16wtarget_00280ef8jjjj");
void wtarget_00280ef8(W1597Obj* o, s32 key);  // 0x00280ef8: definition moved into src/anon/unit_0027f2b0.cpp

// 00271710: refresh a message slot; returns a1
struct W1597It { u16 h0; u8 b2; u8 pad[5]; u16 h8; };
struct W1597Rec { u8 pad[8]; s32 f8; };
W1597It* func_001a80c8(s32);
void func_00259570(u8, s32, u8, s32);
void func_002595b8(s32, s32, s32);
s32 func_001a3820(u16);
W1597Rec* func_001b8e88(s32);
s32 func_002595e0();
u32 func_00192048(u32);
u32 func_002595e8(u32, u32);
s32 func_00271710(s32 a0, u32 a1, u8 a2, u8 a3, s32 t0);  // 0x00271710: definition moved into src/anon/unit_002713c8.cpp

}
