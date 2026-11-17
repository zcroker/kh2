#include "../common/types.h"
// Built with -g (see BRIEF_G): camera parameter defaults (0x141100).
extern "C" {
extern f32 D_004573d0;
extern f32 D_004573d4;
extern f32 D_004573d8;
extern f32 D_004573dc;
extern f32 D_004573e0;
extern f32 D_004573e4;
extern f32 D_004573e8;
extern f32 D_004573ec;
extern f32 D_004573f0;
extern f32 D_004573f4;
extern f32 D_004573f8[4][6];  // camera presets: 4 rows of 6 params
extern u8 D_00348710[];
void func_0013f538(u8*);

#define W1625_INIT(var, val) if (id == 0xffff && kind == 1) var = val

void func_00141100_ii(s32 kind, s32 id) asm("_Z13func_00141100ii");
void func_00141100_ii(s32 kind, s32 id);  // 0x00141100: definition moved into src/anon/unit_00141100.cpp
}
