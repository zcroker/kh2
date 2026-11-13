// w8019 (zl90 retry): 0013c938 matches as plain C (two call results share m).
#include "../common/types.h"
typedef struct Q { u8 p0[32]; u32 f20; u8 p1[2240 - 36]; u32** cur; u8 p2[2536 - 2244]; u32* arr[4]; } Q;
typedef struct P { u8 p0[204]; s32 fcc[4]; u8 p1[236 - 220]; u32 fec; u8 p2[248 - 240]; u32 ff8; u8 p3[668 - 252]; Q* q; } P;
extern u32 D_004573c0[4];
void func_0013d3f8(P*);
u32 w8019_GetMode(void) asm("_ZN2YS6STATUS7GetModeEv");
void func_0013ce08(P*, s32);
void func_0013b838(P*);
s32 func_001bcf38(u32*);
void func_0013c900(P*, s32, u32*, s32);
u32 func_0013c878(P*);
void func_0013cbb8(P*, u32*, u32);
u32 func_0013c888(P*, u32);
void func_0013c3b8(P*, u32*, s32, u32, u32);

void func_0013c938(P* p);  // 0x0013c938: definition moved into src/anon/unit_0013a8b8.cpp
