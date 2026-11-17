#include "../common/types.h"
// batch w1776 (helper). Built with -fno-strict-aliasing (the store order of the
// two sibling init functions only comes out right that way).

struct W1776V4 { f32 x, y, z, w; };
struct W1776Obj {
    u8 pad0[0x14]; u8 b14; u8 pad15; s8 b16; u8 pad17[0x11];
    s32 f28; u8 pad2c[4]; W1776V4 v30; f32 f40; u8 b44; u8 b45; u8 pad46[2]; s32 f48; u8* f4c; void* f50;
};
struct W1776Src { u8 pad[0x9f4]; u32 f9f4; };
extern char D_00371698[];

extern "C" {
void func_001c1748(W1776Obj*, u32, u32, u32);

// 001c6fa8: moved to src/anon/unit_001c6e58.cpp (linked unit)

// 001c7048: moved to src/anon/unit_001c6e58.cpp (linked unit)

void strcpy_w1776(char*, const char*) asm("_ZN2Tz16LayFileBuildDataEPvj");
s32 strlen(const char*);
void func_00240118(char*, u32, u32);

// Builds "/" + func_00240118's text in a buffer and copies it twice to dst.
void func_00240240(char* dst, u32 a, u32 b);  // 0x00240240: definition moved into src/anon/unit_0023f5b8.cpp
}
