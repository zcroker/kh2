/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct I26b0f8 I26b0f8;
typedef struct P26b0f8 P26b0f8;
typedef struct Q26b0f8 Q26b0f8;
typedef union BD_VALUE BD_VALUE;
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
struct Q26b0f8
{
  u8 pad[18];
  u8 n;
  u8 pad2[33];
  u16 h52[8];
  u16 h68[8];
};
struct P26b0f8
{
  u8 pad[580];
  Q26b0f8 *q;
};
struct I26b0f8
{
  u16 id;
  u8 a;
  u8 flag;
  u8 pad[2];
};
extern u32 D_0035f01c;
extern u32 D_0035f010;
s32 func_0028b040(u32) asm("_ZN2Tz8JmReport7GetDataEj");
s32 func_00257130() asm("_ZN2Tz5CmTop11GetItemInfoEv");
I26b0f8 *func_00281f20(s32) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s32 func_00257070(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
P26b0f8 *func_00281180(u32, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
s32 func_00281198(u32, s32) asm("_ZN2Tz9PartyInfo8GetPartyEi");
void func_00282240(s32, s32, s32);
void Tz__ItemInfo__MakeMsgTbl(s32, s32, s32);
void Tz__CmEquip__CtrlAutoConfirm();  // 0x0026b0f8: definition moved into src/anon/unit_0026a900.cpp

}
