#include "../common/types.h"
struct W262In { u32 a[20]; u32 b[3]; u32 c[18]; u32 d[9]; u32 x200, x204; };
struct W262Q { u32 a[4]; u8 b; };
struct W262S {
    u8 pad[12];
    W262In in;
    u8 pad2[2108 - 12 - 208];
    u32 x83c, x840;
    W262Q q;
    u8 pad3[2136 - 2116 - 20];
};
struct W262Key { s32 t : 29; u32 type : 3; f32 v; f32 m1; f32 m0; };
extern "C" {
void func_00319d20(void*);  // zero_two_words
void func_00321198(void*);  // zero_3_words
void func_00319d58(void*);  // store_zero_byte
void func_00319a60(void*);  // clear_fixed_blocks
void func_00321068(u8* p);  // 0x00321068: definition moved into src/anon/unit_00320528.cpp

f32 func_00230de0(s32 i, W262Key* keys, W262Key* out, f32 t);  // 0x00230de0: definition moved into src/anon/unit_002302c0.cpp
}
