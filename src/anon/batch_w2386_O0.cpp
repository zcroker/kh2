#include "../common/types.h"

extern "C" {
u32 func_002fdfc8(const char*, ...);
s32 func_002b803c(s32 a);
extern s32 D_01e22080[512][16];  // sound play slots, 64 bytes each

// 002b807c: with a == 0, print every active sound play slot; then forward a to func_002b803c.
void func_002b807c(s32 a);  // 0x002b807c: definition moved into src/anon/unit_002b6f28.cpp
}
