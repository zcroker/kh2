#include "../common/types.h"

struct W1717Q { u8 v[16] __attribute__((aligned(16))); W1717Q() {} ~W1717Q() {} };
struct W1717Pad { u64 a, b, c, d; W1717Q q[2]; f32 f; W1717Pad() {} };

extern "C" {
struct W1717Obj {
    u8 p0[2]; s16 m2; s16 m4; u8 p6[0xc]; u16 m12; u16 m14; s16 m16;
    u8 p18[0xd]; u8 f25; u8 p26; u8 f27;
};

s16 func_0028b040(W1717Obj*);
void* func_00167f18(s32);
void func_00323af8(W1717Pad*, void*);
s32 func_00288040(void);
W1717Pad* func_00288008(void);
s32 func_002899e0(W1717Obj*, W1717Pad*);
s32 func_00289ef8(W1717Obj*, W1717Pad*);
s32 func_0028af78(W1717Obj*, s32);

s16 func_00289380(W1717Obj* o);  // 0x00289380: definition moved into src/anon/unit_00288b00.cpp
}
