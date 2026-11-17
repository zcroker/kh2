// func_00294f78: builds menu entries from the item table (one per usable slot), sets them up and marks D_0035f581.
// Built with -fno-strict-aliasing -fmove-all-movables (_nsamam). The explicit down-counting do-while with the
// obj/menu pointer locals gives the original preheader order (move s3,t5 before move s4,s0).
#include "../common/types.h"
extern "C" {
extern u8 D_0035f580;
extern u8 D_0035f581;
extern s32 D_0035f3d4;
extern s32 D_0035f210;
extern s32 D_0035f57c;
extern s32 D_0035f200;
u8* func_002766d0();
u8* func_00294000(u32);
s32 func_002941a8(u8*);
s32 func_00276c18();
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f988(s32, s32);
void func_002362b0(u8*, s32);
void func_001386e0(u8*, s32, s32, u8*, s32, s32);
void func_00139620(u8*);
u8* func_002891b8(s32, s32);
void func_0028dcc0(u8*, u8*);

void func_00294f78(u8 flag);  // 0x00294f78: definition moved into src/anon/unit_00292e60.cpp

}
