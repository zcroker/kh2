#include "../common/types.h"
// w2441 (helper retry): built with -fno-strict-aliasing.
extern "C" {
u8* func_002a9d68();
struct W2441Ent { s8 slot; u8 f1; u8 pad[14]; };
struct W2441Hdr { u8 h[16]; W2441Ent e[1]; };
struct W2441Bits { u32 w[2]; };
struct W2441Rec { u8 pad[324]; W2441Bits b[1]; };
W2441Hdr* func_00294000(s32);

s32 func_002b3ac8(s8);
extern W2441Rec* D_0035f610;
struct W1595Ent { s8 kind; u8 pad[35]; };
struct W1595Hdr { s32 a, b, count, c; W1595Ent e[1]; };
struct W1595List { s32 a; s8 kind; u8 n; u16 pad; s16 list[1]; };
s32 func_002943b0(W1595Ent*);
s32 func_00276c18();
extern W1595List* D_0035f5ac;
void func_002ac678(s32 idx);  // 0x002ac678: definition moved into src/anon/unit_002a99c8.cpp

void func_0029ca50(void);  // 0x0029ca50: definition moved into src/anon/unit_0029ba88.cpp
}
