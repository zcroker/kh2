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
void func_00141100_ii(s32 kind, s32 id)
{
    struct NoTail { ~NoTail() {} } nt;
    W1625_INIT(D_004573d0, 1.0471974611282349f);
    W1625_INIT(D_004573d4, 1.0471974611282349f);
    W1625_INIT(D_004573d8, 1.0471974611282349f);
    W1625_INIT(D_004573dc, 0.1745329201221466f);
    W1625_INIT(D_004573e0, 0.004363323096185923f);
    W1625_INIT(D_004573e4, 0.00017453290638513863f);
    W1625_INIT(D_004573e8, 0.05235987529158592f);
    W1625_INIT(D_004573ec, 0.05235987529158592f);
    W1625_INIT(D_004573f0, -1.221730351448059f);
    W1625_INIT(D_004573f4, 1.221730351448059f);
    if (id == 0xffff && kind == 1) {
        D_004573f8[0][0] = 1.5f;
        D_004573f8[0][1] = 420.0f;
        D_004573f8[0][2] = 380.0f;
        D_004573f8[0][3] = 250.0f;
        D_004573f8[0][4] = 500.0f;
        D_004573f8[0][5] = 0.008f;
        D_004573f8[1][0] = D_004573d4;
        D_004573f8[1][1] = 600.0f;
        D_004573f8[1][2] = 520.0f;
        D_004573f8[1][3] = 400.0f;
        D_004573f8[1][4] = 700.0f;
        D_004573f8[1][5] = 0.005f;
        D_004573f8[2][0] = D_004573d0;
        D_004573f8[2][1] = 600.0f;
        D_004573f8[2][2] = 520.0f;
        D_004573f8[2][3] = 400.0f;
        D_004573f8[2][4] = 633.0f;
        D_004573f8[2][5] = 0.005f;
        D_004573f8[3][0] = D_004573d8;
        D_004573f8[3][1] = 600.0f;
        D_004573f8[3][2] = 520.0f;
        D_004573f8[3][3] = 400.0f;
        D_004573f8[3][4] = 700.0f;
        D_004573f8[3][5] = 0.005f;
    }
    if (id == 0xffff && kind == 1) func_0013f538(D_00348710);
}
}
