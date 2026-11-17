#include "../common/types.h"
extern "C" {
struct W1963Res { u32 f0; u32 f4; u32 data; };
struct W1963Ent { u8 pad[0x13]; u8 b13; u8 pad2[8]; u32 d1c; };
extern W1963Ent D_01c6cc60[6];
extern u32 D_01c6cec0;
extern u32 D_01c6cec4;
extern s32 D_00350a30;
extern char* D_00350a28;
extern s32 D_0033caf4;
extern s8 D_0036d740[8], D_0036d748[8], D_0036d750[8];
void func_001aabd8(void);
void func_002fee78(char*, const char*, ...);
void* func_001b1490(void*);
W1963Res* func_00168b38(void*, s32, s32);
W1963Res* func_00168b88(void*, s32, s32, s32);
s32 func_00105c30(void);
static inline u32 TAG(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }

void func_001aaa08(void);  // 0x001aaa08: definition moved into src/anon/unit_001aaa08.cpp
}
