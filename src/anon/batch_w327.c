#include "../common/types.h"

typedef union W327U { s32 i; f32 f; } W327U;
typedef union W327UF { f32 f; s16 h; s32 i; } W327UF;

s32 func_002061f0(s32) asm("_Z13func_002061f0xxxx");

typedef struct W327Item388 { f32 x, y, z, w; void* src; W327U h; s32 p18; u8 r, g; s16 q; u8 pad[16]; } W327Item388;
typedef struct W327Src388 { s32 a; s32 id; u8 pad[0x1c]; W327UF x, y, z; u8 pad2[0x10]; u8 r, g, b; } W327Src388;
typedef struct W327Mgr388 { s32 a, b; u32 n; s32 c, d; W327Item388* items; } W327Mgr388;

s32 func_00206388(W327Mgr388* m, W327Src388* s);  // 0x00206388: definition moved into src/anon/unit_00206388.c
