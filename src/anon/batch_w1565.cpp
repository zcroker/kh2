#include "../common/types.h"

struct E_w1565 { u32 flag : 1; u32 : 31; u8 pad[28]; f32 val; u8 pad2[16]; };

extern "C" {

s32 func_001bb4b0(s32);
void* func_001bbcb0(void);
void func_001d8c70(s32, f32);

void func_001d8d08(s32 i, f32 v);  // 0x001d8d08: definition moved into src/anon/unit_001d7458.cpp

}
