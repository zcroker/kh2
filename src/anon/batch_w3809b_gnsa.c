// Builds the entry list at D_0035f230 from 80 source slots (filtered by category/flag), finds each entry's position, then counts entries per category.
// Partial inline asm: an empty memory barrier after the hi-bit test and an empty asm use of n after the loop (register order).
#include "../common/types.h"
u8* func_002859a0(void);
s32 func_00287bc0(void);
s32 func_0028b040(u32);
s32 func_002570a0(s32);
void func_0027aed8(s32, s32*, s32*);
u8* func_00281180(u32, s32);
u8* func_001a80c8(s32);
s32 func_002811b0(u32, s32);
s32 func_001b7818(s32);
void func_00279620(void);
void func_002793b0(void);
void Tz__CmAbility__GetFriendAbilityAI(void);
void func_002799b0(void);
void Tz__CmAbility__SortAbilityInfo(void);
typedef struct Ent_00279040 { u16 id; u8 hi; u8 idx; s8 cat; u8 b5; s8 b6; s8 pos; } Ent_00279040;
typedef struct Hdr_00279040 { u16 h0; u16 h2; u8 pad4[3]; s8 count; u8 cnt[4]; Ent_00279040 e[1]; } Hdr_00279040;
extern Hdr_00279040* D_0035f230;
extern u32 D_0035f010;
extern u32 D_0035f01c;

void func_00279040(void);  // 0x00279040: definition moved into src/anon/unit_00278dd0.cpp

