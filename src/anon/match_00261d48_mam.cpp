// 00261d48 w2502: 0 diffs (try harness) ONLY with -fmove-all-movables (-O2 -fmove-all-movables, with or without -fno-strict-aliasing, -g or -g0).
// Keys: func_00261fb8 takes NO argument (fixes jal nop), Slot261* s = &g->b[pos+j] local, pos += n; pos += n & 1;, pos declared before g.
#include "../common/types.h"
extern "C" {
extern s32 D_0035ef6c;
extern s32 D_0035f01c;
extern s16 D_00373240[];
struct Slot261 { u8 pad[408]; u8* ptr; u8 pad2[24]; };
struct G261 { u8 pad[13840]; Slot261 a[24]; Slot261 b[20]; };
struct E261d48 { u16 id; u8 a; u8 b; u16 pad; };
u8* func_00257770(void);
void func_00139d78(u8*);
s32 func_00257140(s32);
s32 func_00257130(void);
s32 func_00257158(u16, u8, s32);
void func_00138c10(u8*, s32);
s32 func_002891e8(s32);
s32 func_00289300(s32);
void func_00261fb8(void);
void func_00261ce8(s32);
s32 func_002827e0(s32, s32);
u8* func_00281f30(s32);
E261d48* func_00281f20(s32);
void func_00261d48(void);  // 0x00261d48: definition moved into src/anon/unit_0025f6b8.cpp
}
