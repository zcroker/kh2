#include "../common/types.h"
// Built with -fno-strict-aliasing (see Makefile *_nsa rule).
typedef unsigned int u128 __attribute__((mode(TI)));
struct W1764ObjB { s32 a, b, c; };
struct W1764Arg { void* a; u32 b; void* c; f32 d; s16 x, y; void* e; };
struct W1764Pkt { u32 a, b; u128* p; };

extern "C" {
void* W1764_AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
void func_001ad0f8(void*, s32, s32);
extern u8 D_01d9e8c0[];
void func_0021fbd8(W1764Arg*, s32);
void func_001b7e68(W1764Pkt*, s32);
void func_001b80d8(W1764Pkt*);
void func_001b7f30(W1764Pkt*);

// 001ad158: moved to src/anon/unit_001abb28.cpp

void func_001fb8b8(u8* o);  // 0x001fb8b8: definition moved into src/anon/unit_001fb350.cpp

void func_0014b9a8(u128* src);  // 0x0014b9a8: definition moved into src/anon/unit_0014b838.cpp
}
