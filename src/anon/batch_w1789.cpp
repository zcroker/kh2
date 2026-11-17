#include "../common/types.h"

struct W1789Ent { s16 id; u8 f; u8 pad; u32 x; };
struct W1789Tbl { u32 a; s8 n; u8 pad[3]; W1789Ent e[1]; };
struct W1789Rec { u32 a; u16 id; };

extern "C" {
extern W1789Tbl* D_0035f12c;
W1789Rec* func_00273140();
void func_001a6510(s32);
void func_001a6548(s32);
s32 func_001a6598(s32);

void func_00273760(s32 idx, u8 on);  // 0x00273760: definition moved into src/anon/unit_00271e08.cpp
}
