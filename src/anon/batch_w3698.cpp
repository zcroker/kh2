#include "../common/types.h"
// 0025e450: case 15 pins a0/a1 so the li a1,2 comes before li a0,-1 (the a0 move fills the jal delay slot like the original).
extern "C" {
s32 func_00233e60(void);
s32 func_00233e70(s32);
s32 func_00234758(void);
s32 func_00234798(void);
s32 YI__MCARD__GetResultRead(void);
void func_002349c8(s32, s32);
void Tz__MCard__MakeFname(s32);
s32 func_00240a08(s32);
s32 func_00240ba0(void);
void func_00240bc0(s32);
s32 Tz__MCard__GetPos(void);
void func_00240c08(s32, s32, s32);
void Tz__MCard__GetDirInfo(s32);
s32 Tz__MCard__UpdateDirInfo(void);
void func_00240fd8(s32, s32);
s32 func_002413f0(void);
void func_00241450(s32);
void func_002415a0(s32, s32, s32);
void func_002417a0(void);
void func_00241850(s32, s32);
s32 Tz__MCard__ChkFileSize(s32);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_00287c00(s32);
s32 func_00287c10(void);
void func_00287c30(void);
void func_00287c90(s32);
s32 func_00287cd0(void);
void func_00287d20(s32);
s32 func_00287d30(void);
void func_00288018(void);
s32 func_00288040(void);
void func_0028f7e8(s32);
void func_0025dba8(void);
void Tz__CmSLBase__SetupWarningConfirm(s32);
void func_002b4ee0(void);
s32 func_002b4fb8(void);
s32 func_002b4ff8(void);
void func_002b5108(s32, s32);
void func_002b5188(void*, s32);
void func_002b5af0(void);
extern u8 D_00373110;
extern s8 D_0035f0b3;

void func_0025e450(void);  // 0x0025e450: definition moved into src/anon/unit_0025da20.cpp
}
