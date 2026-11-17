#include "../common/types.h"

extern "C" {
struct Ent64 { s32 h[3]; u8 pad[52]; };
extern Ent64 D_01e22080[512];
void func_003058a0(s32);
}

// Count live entries of kind 29 (matching a/b) or kind 25 (matching c).
extern "C" {
s32 ctarget_002b79cc(s32 a, s32 b, s32 c) asm("_Z16ctarget_002b79ccjjjj");
}
s32 ctarget_002b79cc(s32 a, s32 b, s32 c);  // 0x002b79cc: definition moved into src/anon/unit_002b6f28.cpp
