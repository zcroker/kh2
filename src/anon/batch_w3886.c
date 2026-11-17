#include "../common/types.h"

/* GS packet qword, written as two dwords or four words. */
typedef union Pk598 { u64 d[2]; u32 w[4]; } Pk598;
typedef struct Ctx598 { u32 a; u32 b; union { Pk598* p; u64 q; }; } Ctx598;
extern volatile u64 D_0036d770; /* GIF tag for the sprite packet */
s32 func_001aaf98(u32, s32, s32, s32, s32);

/* Sprite for cell idx (10 per row, 24x24) of a texture page at (x, y). Returns 1 if a packet was written. */
s32 func_001ab598(u32 a0, Ctx598* c, s32 x, s32 y, u32 col, s32 idx);  // 0x001ab598: definition moved into src/anon/unit_001ab598.cpp
