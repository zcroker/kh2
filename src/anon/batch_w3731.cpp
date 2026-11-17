// 00299e70: empty asm on k in the -8 arm makes k conflict with mode, so k stays in s2; barrier asms keep the order lw a0, li a1, move s3,v0 before jal 0028af18.
#include "../common/types.h"
extern "C" {
extern s32 D_0035f200;
extern u16 D_00374910[];
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_00276368(void);
s32 func_0028acc8(s32);
s32 func_00276888(void);
void func_00287f90(s32);
void func_002995a8(void);
s32 func_00292630(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_00274cf0(s32);
void func_002925c0(void);
s32 func_00276358(void);
void func_00276220(s32, s32);
void func_002945e8(void);
void func_002958b0(void);
void func_0029ae40(void);
void func_0029ee68(void);
void func_002aed60(void);
void func_002a21b0(void);
void func_002a8ac8(void);
void func_002a77a0(void);
void func_002a4e38(void);
void func_002a6a50(void);
void func_002a0908(s32);
void func_0029a368(void);
s32 func_00289310(s32);
s32 func_00276398(void);
void func_00275b60(void);
void func_00287c90(s32);
void func_0029a780(void);
s32 func_00287df0(s32, s32, s32, void (*)(void), s32);
s32 func_00242848(s32);
void func_00287da0(void);
void func_00276150(s32, s32*, s32*);
void func_00276dc0(void);
void func_00287c00(s32);
void func_00287cc0(s32);
s32 func_0029a5f0(s32);
void func_0028fb28(s32, u16);
void func_00275dd0(void);
void func_002765e8(s32, s32, s32);
s32 func_00288040(void);
void func_00288018(void);
void func_00299e70(void);  // 0x00299e70: definition moved into src/anon/unit_00299920.cpp
}
