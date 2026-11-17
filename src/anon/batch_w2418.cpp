#include "../common/types.h"
extern "C" {
struct W2418M2b4 { u8 pad[0x4c]; };
struct W2418O2b4 { W2418M2b4* a; W2418M2b4* b; W2418M2b4* c; };
struct W2418P2b4 { u8 pad[0x14]; u16 h[4]; };
void func_0023f1e0(W2418M2b4*, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023f7d8(W2418M2b4*);
s32 func_0023aa98(s32);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_0023f6c0(W2418M2b4*, s32);
void func_0023f688(W2418M2b4*, s32);
void func_001395f8(W2418M2b4*);

void func_002b4070(W2418O2b4* o, s32 a1, s32 a2, s32 a3, s32 e0, s32 e1, s32 e2, s32 e3, s32 e4, s32 c0, W2418P2b4* p, s32 x, s32 y);  // 0x002b4070: definition moved into src/anon/unit_002b3ac8.cpp
}
