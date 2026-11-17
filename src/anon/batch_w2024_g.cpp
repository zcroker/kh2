#include "../common/types.h"
struct W2024d_St { s32 mode; s32 f4; s32 step; u8 flag; u8 pad[3]; s32 f10; u8 f14[0x1c]; u8 f30[4]; };
struct W2024d_Pl { u8 pad[0xfc]; s32 fc; };
extern s32 D_0034e948;
extern u8 D_00351eb8[];
extern u8 D_00351ec0[];
extern "C" {
void func_002bc788(void);
s32 func_00197920(void);
W2024d_Pl* func_0014ac08(void);
void func_002bc798(void);
void func_001852b8(s32);
void func_001af938(void);
void func_001a58f8(void);
void func_00197738(void);
void func_001c8948(void);
s32 func_001c8db8(void*, s32);
s32 func_00170cd0(void);
void func_001c8d80(void*, s32);
void func_001c98f0(f32);
void func_001d0068(void);
void func_001af8d8(W2024d_St*);
void func_00170888(s32);
s32 func_001c9df8(void);
s32 func_001c10f8(s32);
void func_00253410(s32, void*);
void func_001af778(W2024d_St*);
void func_001373d8(void);
void func_001d00a8(void);
s32 func_001af420(W2024d_St* self);  // 0x001af420: definition moved into src/anon/unit_001ada38.cpp
}
