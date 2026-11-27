#include "../common/types.h"
// 002a4620 matched under -fno-strict-aliasing (w2423)
extern "C" {
void func_00138c10(u8*, s32);
void func_00138c68(u8*, u32, u32);
void func_00138c78(u8*, u32*, u32*);
void func_00242618(s32, s32);
void Tz__JmTreasure__UpdateNewMark(void);
s32 func_002a4990(s32);
s32 func_002a4a00(s32);
extern u8* D_0035f5e4;
extern u8* D_0035f5e8;
struct Pad2a { u8 p0[8]; u64 trig; u8 p1[8]; u64 rep; };

void func_002a4620(Pad2a* pad);  // 0x002a4620: definition moved into src/anon/unit_002a40c8.cpp

}
