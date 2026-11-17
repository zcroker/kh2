#include "../common/types.h"

extern "C" {

void func_003058a0(s32);
struct E104 { u8 pad[4]; s8 used; u8 pad2[11]; s32 id; u8 pad3[16]; s32 val; u8 pad4[64]; };
extern E104 D_01e2a080[];

// 002b8534: look up the value of the live slot with this id
s32 func_002b8534(s32 id);  // 0x002b8534: definition moved into src/anon/unit_002b8274.cpp

}

extern "C" {

struct E104b { u8 pad[4]; s8 used; u8 pad2[11]; s32 id; u8 pad3[4]; s32 val; u8 pad4[76]; };
extern E104b D_01e2a080b[] asm("D_01e2a080");

// 002b85e4: same lookup as 002b8534, other field
s32 func_002b85e4(s32 id);  // 0x002b85e4: definition moved into src/anon/unit_002b8274.cpp

}

namespace w71_c0 {
extern "C" {
s32 func_002b9404(u32, u32, u32*, u16*);
s32 func_002b6708(s32, s32, s32, s32, u32);
s32 func_002b9728(u32 a, u32 b, s32 c, u32 d);  // 0x002b9728: definition moved into src/anon/unit_002b95e8.cpp
}

}
