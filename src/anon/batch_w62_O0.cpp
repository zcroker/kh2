#include "../common/types.h"

extern "C" {
extern s32 D_01e21f40;
extern u8 D_01e22040[];
s32 sceSifCallRpc(u8*, s32, s32, s32*, s32, s32*, s32, s32, s32);

// Byte-swaps a 32-bit word.
s32 func_002b8694(s32 x);  // 0x002b8694: definition moved into src/anon/unit_002b8274.cpp
}

// Retries the request until it is accepted; returns the value sent.
s32 func_002b8274(s32 x);  // 0x002b8274: definition moved into src/anon/unit_002b8274.cpp
