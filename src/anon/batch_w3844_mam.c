// 0029cdf8: rebuilds a list of up to 10 names: for each set bit i >= n of the list mask, looks up id (i-1, or 16 for bit 0),
// writes its name into names[k], links it to entry k and sets sprite k from D_00374ad4/ad0. Built with -fmove-all-movables (_mam).
#include "../common/types.h"
typedef struct Spr9cd { u8 pad[408]; } Spr9cd;
typedef struct Big9cd { u8 pad[0xa998]; Spr9cd spr[10]; } Big9cd;
typedef struct Lst9cd { s32 mask; u8 pad[260]; char names[10][64]; } Lst9cd;
typedef struct Ent9cd { u8 pad[408]; char* name; } Ent9cd;
Big9cd* func_002766d0(void);
s32 func_0028b038(u32);
void func_0028be78(u32, s32);
void func_00138c10(Spr9cd*, u32);
void func_002fde18(void*, s32, s32);
s32 func_0028afa8(u32);
s32 func_00295430(s32, s32);
s32 func_002954e0(s32);
s32 func_00192048(s32);
void func_00192c90(s32, char*);
void func_0028de08(s32, char*, s32);
Ent9cd* func_002891b8(u32, s32);
s32 func_002aa098(s32);
s32 func_002aa148(s32);
extern u32 D_0035f200;
extern u32 D_0035f214;
extern Lst9cd* D_0035f5ac;
extern u32 D_00374ad0;
extern u32 D_00374ad4;
void func_0029cdf8(void);  // 0x0029cdf8: definition moved into src/anon/unit_0029cdf8.c
