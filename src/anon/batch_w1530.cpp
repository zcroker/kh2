#include "../common/types.h"
struct W1530_E { s16 h; u8 pad[30]; };
struct W1530_T { u8 pad[8]; s32 n; u8 pad2[4]; W1530_E e[1]; };
struct W1530_B { u8 pad[0x74]; W1530_T* t[3]; u8 pad2[0x8000 - 0x80]; u8 p6c[0x6c]; u8 c6c; u8 pad3[7]; s32 v74; u8 pad4[0x18]; u8 c90; };
extern "C" {
W1530_E* func_002dd650(W1530_B* b);  // 0x002dd650: definition moved into src/anon/unit_002dd650.cpp
}
