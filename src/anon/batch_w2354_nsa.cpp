#include "../common/types.h"
/* Soft-double libcalls bind to the game's own copies. */
asm("fptodp = func_00313b80");
asm("dpmul = func_00313f40");
asm("dpadd = func_00313e80");
asm("dptoul = func_00314508");
extern "C" {
struct M21f620 { f32 m[4][4]; };
struct C21f620 { u8 r, g, b, a; };
struct E21f620 { s32 f0; f32 t; };
struct H21f620 { u8* obj; s32 n; u8 cnt; u8 pad9; s16 sx; s16 sy; u8 flip; u8 pad15; E21f620 e[1]; };
struct S21f620 { s32 n; E21f620* p; u8 pad8[8]; u16 f16; s16 f18; C21f620 col; s32 f24; s16 h28; s16 h30; M21f620* mtx; u8 pad36[8]; s32 f44; u8 pad48[16]; };
struct A21f620 { H21f620* h; s32 col; s32 f8; f32 scale; f32 fade; f32* rot; };
void U21f620_ucall4(M21f620*, u8*) asm("_Z16sceVu0CopyMatrixjjjj");
void sceVu0UnitMatrix(M21f620*);
void U21f620_wtarget(M21f620*, s32, M21f620*) asm("_Z15sceVu0MulMatrixjjjj");
void func_0021efc0(S21f620*);
void func_0021f060(S21f620*);
extern u8 D_01d9e360;
extern M21f620 D_01d9e840;
/* Draw a strip of sprites along a line: per entry, step the position, fade the alpha
   and scale the sprite matrix, then submit it (sibling of func_0021fa28). */
void func_0021f620(A21f620* a, s32 id);  // 0x0021f620: definition moved into src/anon/unit_0021e988.cpp
}
