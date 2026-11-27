/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Obj Obj;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
union BD_VALUE
{
  s32 i;
  f32 f;
  void *p;
  u32 u;
};
typedef struct Obj Obj;
struct Obj
{
  u8 pad[0x18c];
  s32 a18c;
  s32 a190;
};
Obj *Tz__MenuItem__start(s32, s32, s32, s32, s32, s32);
s32 func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void func_001396b0(Obj *) asm("_ZN2Tz6Select10BeginLeaveEz");
void func_0031a260(Obj *, s32) asm("_ZN2Tz6Select7SetFlagEz");
void func_00139620(Obj *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_00139660(Obj *) asm("_ZN2dk5Obj2D19getParentSeqColorOnEv");
void func_00139688(Obj *) asm("_ZN2dk5Obj2D21getParentSeqAlphaOnlyEv");
extern s32 D_0035f3d4;
extern s32 D_0035f640;
extern s32 D_0035f644;
extern s32 D_0035f648;
extern s32 D_0035f64c;
extern s32 D_0035f664;
extern Obj *D_0035f690[][4];
void func_002b57e0(void);  // 0x002b57e0: definition moved into src/anon/unit_002b3ac8.cpp

}
