#include "../common/types.h"

extern "C" {
s32 sceSifCallRpc(void*, s32, s32, void*, s32, void*, s32, s32, s32);
extern u8 D_01e22040;
extern u32 D_01e21f40[64];

// Retries an RPC call (send/receive through the same 256-byte buffer) until it succeeds.
u32 func_002b8434(u32 a);  // 0x002b8434: definition moved into src/anon/unit_002b8274.cpp
}
