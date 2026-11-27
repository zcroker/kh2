#include "../common/types.h"
extern "C" {
struct Ent { s16 a; s16 b; };
struct Tbl { s32 n; Ent e[1]; };
struct Item { u8 pad[6]; u16 k; };
extern Tbl* D_0035f600;
extern s32 D_0035f200;
u8* func_002a9d68();
s32 func_00287bc0();
s32 func_0028b038(s32);
Item* func_002a7f20(s32);
u8* func_001d56c8(u32);
void func_002ab258(s32);

// Built with -fno-strength-reduce (_nsr).
void Tz__JmMiniGame__UpdateNewMark(void);  // 0x002a8768: definition moved into src/anon/unit_002a8748.cpp
}
