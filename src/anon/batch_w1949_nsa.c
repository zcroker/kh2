#include "../common/types.h"
extern s32 D_0035ec84;
extern u8* D_0035ec88;
extern u8* D_0035ec8c;
extern u8* D_0035ec90;
extern u8* D_0035ec94;
extern u8* D_0035ec98;
extern u8* D_0035ec9c;
extern u8* D_0035eca0;
extern void* D_0035eca4;
u8* func_001063f0(s32, s32);
u8* func_001063c0(s32, s32);
void* memset(void*, int, unsigned int) asm("_Z16wtarget_002fde18jjjj");
s32 func_00240440(s32);
void func_00241fd0(void*, s32);
typedef struct W1949_Hd { s8 a; u8 pad; s16 b; } W1949_Hd;
void func_0023fe60(void);  // 0x0023fe60: definition moved into src/anon/unit_0023f5b8.cpp

typedef struct W1949_Flags { u8 pad[80]; u32 f80[3]; u32 f92[8]; } W1949_Flags;
static inline s32 W1949_Bit(u32* a, u32 n) { return (a[n >> 5] & (1 << (n & 31))) != 0; }
extern W1949_Flags* D_0035f2e4;
s32 func_00258108(void);
s32 func_002811b0(s32, s32);
s32 func_001b7818(s32);
s32 Tz__CmNewFlg__isAbilityNewMember(s32 a, s32 b);  // 0x00286d28: definition moved into src/anon/unit_00286d28.cpp
