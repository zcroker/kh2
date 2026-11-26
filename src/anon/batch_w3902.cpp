// w3902 (helper). Plain -O2 C++.
#include "../common/types.h"

extern "C" {

struct Ent36
{
  u8 pad0[8];
  u8 name[8];
  s8 f10;
  u8 pad11;
  u16 f12;
  u8 pad14[16];
};
struct VObj
{
  struct VT
  {
    u8 pad[24];
    void (*f18)(VObj *, s32, u32, s32, s32, s32, s32);
  } *vt;
};
u8 *func_0023ee30(u32);
void func_0031a838(u8 *);
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8 *);
void YI__LAYOUT__LAYOUT(u8 *);
void Tz__MenuUtil__CreateLay(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
void Tz__Layout__SetImageCache(u8 *);
s32 func_00244938(s32);
s32 Tz__SubMenu__isSetNew(s32, s32);
void Tz__Select__SetItem(void *, s32, s32, s32, u8 *, s32, Ent36 *, u8 *);
u8 *func_002891b8(void *, s32);
s32 func_0023aa98(u8 *);
s32 func_0023aa78(u8 *);
s32 func_0028dd90(s32);
s32 func_0028ddd8(s32);
void func_001395f8(u8 *);
void func_00139620(u8 *);
s32 func_002892f8(void *);
void func_00138c68(u8 *, s32, s32);
void Tz__Select__SetCurrent(void *, s32, s32, s32, s32);
void func_002449c0(void);
s32 func_002891e8(void *);
s32 func_00244ee8(s32);
void func_002b4070(void *, s32, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, Ent36 *, s32, s32);
s32 func_001a6d08(s32);
s32 func_00244a10(void);
void func_0028af40(void *, s32);
void func_0028d980(u8 *, s32, s32, s32, u8 *, s32, s32, s32, s32);
void func_00244a60(void);
VObj *func_00287dc0(void);
void func_0023d808(VObj *, s32);
void func_0023e858(VObj *, s32, f32);
void func_0023e8b8(VObj *, s32, f32);
void func_0023e8d8(VObj *, s32, f32);
s32 func_00139d78(s32);
void func_0023e9b0(VObj *, s32, s32);
void func_0023e690(VObj *, s32, s32, s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);
s32 func_002887c8(void);
void Tz__HEFT__LoopAll(void);
void func_00288750(void (*)(void));
void func_00244058(void);
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035ed0c;
extern u8 D_0035ed14;
extern u8 *D_0035ecf0;
extern u8 *D_0035ecf4;
extern u8 *D_0035ecf8;
extern u8 *D_0035ecfc;
extern u8 *D_0035ed08;
extern void *D_0035ece8;
extern Ent36 D_003719a0[];
extern s16 D_00371968[][3];
extern u8 D_00371960[];
extern u8 D_00371978[];
extern u8 D_00371980[];
extern u8 D_00371988[];
extern u8 D_00371990[];
extern u8 D_00371998[];
inline static u8 *NewLayout(void)
{
  u8 *o = func_0023ee30(160);
  *((u8 **) o) = D_00347f98;
  func_0031a838(o + 12);
  *((u8 **) o) = D_0035eb98;
  YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);
  YI__LAYOUT__LAYOUT(o + 48);
  return o;
}

static inline s32 inline_fn(s32 arg0)
{
  return arg0;
}

// Builds the slot-select layout: two entries, a centred column, then the
// header/title objects (w3892/w3902, helper).
void Tz__HEFT__Setup(void);  // 0x00243740: definition moved into src/anon/unit_00242478.cpp

}
