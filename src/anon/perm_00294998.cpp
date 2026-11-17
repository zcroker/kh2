/* found by decomp-permuter (nightly.py) */
extern "C" {


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
extern s32 D_0035f200;
s32 func_0028afa8(s32) asm("_ZN2Tz6Select12GetSelectMaxEv");
u8 *func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 func_0023aa78(u8 *) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
s32 func_0023aa98(u8 *) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void func_00138c68(u8 *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
inline int inline_fn(s32 arg0, int arg1)
{
  return arg0 + arg1;
}

void func_00294998(void);  // 0x00294998: definition moved into src/anon/unit_00292e60.cpp

}
