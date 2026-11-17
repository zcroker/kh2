// 001eb8a8: fills a draw-parameter block from the slot header and colour/position records and
// submits it via func_0020f1e0. Built without strict aliasing; the byte-offset stores keep
// the original store order.
#include "../common/types.h"
typedef struct Prm Prm; struct Prm {
    union { s32 flags; struct { u32 lo : 4; u32 b4 : 1; } bits; }; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s32 w16; s32 w20;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; u8 b76; u8 b77; u8 pad78[2]; s32 pad80[4];
};
typedef struct HB HB; struct HB { u32 b0 : 1; u32 b1 : 1; };
typedef struct Slot Slot; struct Slot { u8 pad[28]; u32* h; s32 w32; };
typedef struct Sys Sys; struct Sys { u8 pad[16]; Slot* slots; };
typedef struct Sys2 Sys2; struct Sys2 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
typedef struct Arg1 Arg1; struct Arg1 { s32 w0; s32 idx; };
typedef struct Arg2 Arg2; struct Arg2 { u8 pad[12]; s32* off; };
typedef struct Col Col; struct Col { u8 pad[8]; u8 r, g, b, a; };
typedef struct Pos Pos; struct Pos { f32 x, y, z, w; };
extern Sys* D_01d9e6e4;
extern Sys2* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
extern u8 D_01d9e9c0[];
extern u8 D_01d9e980[];
s32 func_0020f1e0(u32*, Prm*, s32);
void func_001eb8a8(u8* base, Arg1* a, Arg2* b);  // 0x001eb8a8: definition moved into src/anon/unit_001e8ac8.cpp
