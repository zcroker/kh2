// 002a3648: built with -fmove-all-movables (*_mam.cpp). One function-scope index j is reused by every
// inner loop, and one address variable d is shared by both draw loops (keeps D_0035f5e8 out of a0).
#include "../common/types.h"
extern "C" {
struct It2a3 { u8 a; u8 on; u8 p[6]; };
struct Grp2a3 { u8 n; u8 cnt; u8 p[2]; It2a3* items; };
struct Big2a3 { u8 p0[0x1000]; Grp2a3 g[16]; u8 p1080[4]; s32 sel; };
extern Big2a3* D_0035f5e4;
extern u8* D_0035f5e8;
void func_00138c10(u8*, s32);
s32 func_002a4430(void);
s32 func_002a43f0(void);

// Redraws a 9-row list of 8 cells: clears every cell, finds the group holding the selected item,
// then draws the items from that group onwards, highlighted ones with a second style.
void func_002a3648(void);  // 0x002a3648: definition moved into src/anon/unit_002a3648.cpp
}
