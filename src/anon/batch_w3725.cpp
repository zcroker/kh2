// func_0029c5c8: register pins + empty asm (live-range keepers); see asm_review.tsv.
#include "../common/types.h"
extern "C" {
struct S29c { u8 p0[5]; s8 b5; };
extern s32 D_0035f200;
extern S29c* D_0035f5ac;
s32 func_00289380(s32);
s32 func_00287cd0(void);
s32 func_00287bc0(void);
s32 func_0029e2f8(s32);
void func_0029e4c8(s32);
s32 func_00292630(void);
void func_0029e430(void);
void func_00287c30(void);
void func_0028af18(s32, s32);
void func_0028af28(s32, s32);
s32 func_0028af88(s32);
void func_0028b1e8(s32, s32);
s32 func_0028afa8(s32);
void func_0028b218(s32, s32);
void func_0028b248(s32, s32);
void func_0029ea30(void);
void func_00287cc0(s32);
void func_00287f90(s32);
void func_0029e298(s32);
s32 func_00289310(s32);
s32 func_0029e0f8(void);
void func_0029e148(void);
void func_00287c90(s32);
void func_00242618(s32, s32);
void func_0029e050(void);
void func_0029e258(s32);
void func_00287c00(s32);
void func_0029e808(s32);
s32 func_00288040(void);
void func_00288018(void);
void func_0029c5c8(void);  // 0x0029c5c8: definition moved into src/anon/unit_0029ba88.cpp
}

// func_0020e198: empty asm keeps the shifted value live so the srl is not tied to a1; see asm_review.tsv.
struct B1882 { u8 b[96]; };
struct BF4 { u32 :6; u32 f:26; };
struct BF28 { u32 :5; u32 f:14; u32 :13; };
struct T1882 {
    u8 p0[4]; union { u32 w4; BF4 bf4; }; u32 w8; u8 p12[6]; u8 b18; u8 b19; u16 h20; s16 h22; u16 h24; u8 p26[2]; union { u32 w28; BF28 bf28; }; u8 p32[8]; u8 b40; u8 b41; u8 b42; u8 b43;
};
struct O1882 { u8 p0[15]; u8 b15; T1882 t; };
extern "C" {
extern u8 D_00359100[];
void sceGsSetDefLoadImage(B1882*, s32, s32, u8, s32, s32, s32, s32);
void sceGsSyncPath(s32, s32);
void func_003058a0(s32);
void sceGsExecLoadImage(B1882*, u8*);
void func_0020e198(O1882* o);  // 0x0020e198: definition moved into src/anon/unit_0020dde8.cpp
}
