// w2501: matches only with -fno-strict-aliasing.
#include "../common/types.h"
struct Item { u8 a[6]; s8 on; u8 b; };
struct Grp { u16 id; u16 x; s8 sel; s8 cnt; s8 flag; u8 pad; s32 off; };
struct Tab { u8 pad[8]; s32 n; u8 pad2[4]; Grp g[1]; };
struct Dst { s8 count; u8 p1; s8 sel; u8 pad[77]; Item items[1]; };
extern "C" {
s8* func_00276568(void);
Tab* func_00294000(s32);
s32 func_00294408(Grp*);
extern Dst* D_0035f5d4;
}
extern "C" {
void func_002a18d0(s32 all, s32 sel);  // 0x002a18d0: definition moved into src/anon/unit_002a0908.cpp
}
