#include "../common/types.h"
struct L2bc7f0 { s32 a; s32 b; };
struct E2bc7f0 { u8 d[0x40]; ~E2bc7f0() {} };
struct P2bc7f0 { E2bc7f0 e[64]; s32 idx[64]; s32 n; };
extern L2bc7f0 D_01e2aa80;
extern L2bc7f0 D_01e2aa88;
extern P2bc7f0 D_01e2aa90;
extern "C" {
void func_00324710(void*);
void wtarget_002bc7f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002bc7f0jjjj");
void wtarget_002bc7f0(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x002bc7f0: definition moved into src/anon/unit_002bb8b0.cpp
}
