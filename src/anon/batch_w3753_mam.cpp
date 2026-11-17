// w2458: 0 diffs (c.sh, branch offsets checked) with OPT='-O2 -fmove-all-movables'; 18 diffs at plain -O2/-g/nsa.
// Only blocker: loop.c rejects hoisting HIGH(D_0035f0e4) out of loop 1 (life 1, 83 insns, 'not desirable'); the
// original hoisted+spilled it, which shifts reload's spill-reg rotation (t5/t6/t7). Needs a *_mam build rule (-fmove-all-movables).
#include "../common/types.h"
extern "C" {
struct Info28 { u8 pad[28]; u16 mask; };
extern Info28* D_0035f0e4;
extern u8 D_0035f0e8;
extern s32 D_0035f3d4;
extern u32 D_0035f01c;
extern u32 D_0035f03c;
extern u32 D_0035ef64;
extern u32 D_0035ef68;
extern s32 D_0035ef6c;
extern s32 D_003734f8;
extern s32 D_003734fc;
u8* func_00257770(void);
void func_00267320(void);
void func_0028f4d8(s32, s32, s32);
void func_00266c90(void);
s32 func_00257100(s32);
s32 func_00257118(s32);
void func_00288d80(u32, s32, u32, u32, u32, s32, s32, s32);
u8* func_002891b8(u32, s32);
s32 func_0023aa98(u8*);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_00138c68(u8*, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
s32 func_0028afa8(u32);
s32 func_00267408(s32);
s32 func_002670a0(s32);
s32 func_00286418(s32);
s32 func_002864f8(s32);
s32 func_00192048(s32);
void func_00138c10(u8*, s32);
s32 func_00257070(s32);
s32 func_002670f8(s32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002653a0(void);
void func_002657a8(void);
void func_00266988(void);
void func_002666a8(void);
void func_00287cc0(s32);
void func_002644a0(u8 flag);  // 0x002644a0: definition moved into src/anon/unit_002640a8.cpp
}
