// 0010ef48: calls every enabled entry's handler (pointer to member) except the current one; built with -g -fno-strict-aliasing -fno-gcse.
#include "../common/types.h"
struct C1882 { void* vt; };
struct E1882;
typedef s32 (C1882::*PM1882)(E1882*, void*, void*, s32);
struct E1882 { u32 flags; u32 ptr; s32 delta; u8 pad[24]; };
typedef s32 (*Fn1882)(C1882*, E1882*, void*, void*, s32);
struct L1882 { u8 b[32]; };
struct M1882 { u8 b[16]; };
struct S1882 { u8 pad[2912]; C1882* obj; u8 pad2[24]; u32 f2940; };
extern "C" {
s32 func_001137e0(C1882*);
E1882* func_001137e8(C1882*);
void func_00190128(L1882*);
E1882* func_0010fea0(S1882*);
s32 func_0010ef48(S1882* self);  // 0x0010ef48: definition moved into src/anon/unit_0010ef48.cpp
}
