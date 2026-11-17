#include "../common/types.h"
extern "C" {
struct W1652M21fa28 { f32 m[4][4]; };
struct W1652C21fa28 { u8 r, g, b, a; };
struct W1652S21fa28 { s32 n; u8* p; u8 pad8[8]; u16 f16; s16 f18; W1652C21fa28 col; s32 f24; s32 f28; W1652M21fa28* mtx; u8 pad36[8]; s32 f44; u8 pad48[16]; };
struct W1652H21fa28 { u8* obj; s32 n; };
struct W1652A21fa28 { W1652H21fa28* h; s32 col; s32 f8; f32 scale; f32* rot; };
void W1652_ucall4(W1652M21fa28*, u8*) asm("_Z16sceVu0CopyMatrixjjjj");
void sceVu0UnitMatrix(W1652M21fa28*);
void sceVu0ScaleVector(f32, f32*, f32*);
void W1652_wtarget(W1652M21fa28*, s32, W1652M21fa28*) asm("_Z15sceVu0MulMatrixjjjj");
void func_0021efc0(W1652S21fa28*);
void func_0021f060(W1652S21fa28*);
extern u8 D_01d9e360;
extern W1652M21fa28 D_01d9e840;
void func_0021fa28(W1652A21fa28* a, s32 id);  // 0x0021fa28: definition moved into src/anon/unit_0021e988.cpp
}
