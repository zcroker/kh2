#include "../common/types.h"
extern "C" {
struct E36 { u8 b[36]; };
extern s32 D_0035ed4c;
extern s32 D_0035ed50;
extern s32 D_0035ed60;
extern E36 D_00371d90[];
extern s16 D_00371d18[];
s32 func_00287cd0(void);
s32 func_00289380(s32);
s32 func_0028acc8(s32);
s32 func_00289310(s32);
void func_0028abe0(s32);
s32 func_002891e8(s32);
void func_002b4388(s32, E36*, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_0028ae28(s32, s32);
void func_0028ab20(s32);
void func_00287c90(s32);
void func_00287df0(s32, s32, s32, s32, s32);
void func_0028aa40(s32);
void func_00287b08(s32);
void func_00287da0(void);
void func_00248b38(void);  // 0x00248b38: definition moved into src/anon/unit_00247ff0.cpp
extern s32 D_0035f654;
s32 Tz__MenuUtil__SprtIsLoop(s32);
s32 func_00287cd0(void);
void func_00287cc0(s32);
s32 func_00240ba0(void);
u32 func_00287d30(void);
s32 func_00233e70(s32);
void func_002419d0(s32);
s32 func_00234888(s32, s32);
s32 func_002348a8(s32, s32);
s32 func_00234848(s32, s32);
s32 func_00234868(s32, s32);
void func_002b5108(s32, s32);
void func_00287d20(s32);
void func_00240bb0(s32);
void func_00287bd0(s32, s32);
void func_00241450(s32);
void Tz__CmSLBase__SetupWarningConfirm(s32);
void func_00234570(s32, s32);
s32 func_00288040(void);
void func_00288018(void);
void func_0025a468(void);  // 0x0025a468: definition moved into src/anon/unit_002588e8.cpp
struct Ent { u8 p0[276]; s32 f114; u8 p118[68]; s32 f15c; u8 f160; u8 p161[3]; f32 f164; u8 p168[8]; f32 f170; f32 f174; s32 f178; };
struct Obj;
typedef void (*VFn)(Obj*);
struct Obj { VFn* vt; u8 p4[8]; u32 flags; u8 p10[8]; s32 n; u8 p1c[16]; f32 f2c; void* sub; u8 p34[4]; Ent* ents; };
s32 func_00139d78(void*);
s32 func_00239d10(s32);
void func_00139570(Obj*);
void YI__SEQUENCE__SetScaleX(f32, Ent*);
void func_00239f78(f32, Ent*);
void func_00239eb8(f32, Ent*);
void func_0023acd8(Ent*);
s32 func_00239d30(Ent*, s32);
s32 func_00239d10e(Ent*) asm("func_00239d10");
void func_0028e438(Obj*, s32, s32, s32);
void func_0028ebf8(Obj* o);  // 0028ebf8: moved to src/anon/unit_0028c878.cpp
}
