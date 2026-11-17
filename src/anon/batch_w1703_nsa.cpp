#include "../common/types.h"
// Nine-slice (3x3) panel layout: sizes the current frame to (w, h) rounded down to even,
// centred on the origin, then places the nine parts: corners keep their size, edges stretch.
// Needs -fno-strict-aliasing (stack-slot order of the spilled locals).
extern "C" {
struct W1703Frame { u16 sprite; u16 pad2; u8 pad4[12]; s32 w; s32 h; u8 pad18[12]; };
struct W1703Sprite { u32 pad0; void* parts; u8 pad8[0x88]; };
struct W1703Layout { u8 pad0[0xb0]; W1703Sprite* sprites; W1703Frame* frames; u8 padb8[0x5c]; s32 cur; };
s32 func_00237508(void*, void*, s32);
s32 func_00237578(void*, void*, s32);
void func_00237458(void*, void*, s32, s32);
void func_002374c8(void*, void*, s32, s32);
void func_00237540(void*, void*, s32, s32);
void func_002375b0(void*, void*, s32, s32);
void func_00237640(void*, void*, s32, s32, s32);

// parts: 0..8 = TL, T, TR, L, C, R, BL, B, BR
void func_0023bc58(W1703Layout* l, s32 w, s32 h);  // 0x0023bc58: definition moved into src/anon/unit_0023bc58.cpp
}
