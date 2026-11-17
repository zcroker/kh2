/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Q Q;
typedef struct S6 S6;
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
extern s32 D_0035f01c;
extern s32 D_0035f014;
s32 func_0028b040(s32) asm("_ZN2Tz8JmReport7GetDataEj");
u8 *func_00281f20(s32) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s16 func_001a3820(u16);
s32 func_002570a0(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
u8 *func_001058e8(void) asm("_Z10getSaveRamv");
typedef struct S6
{
  u16 a;
  u16 b;
  u16 c;
} S6;
typedef struct Q
{
  u8 pad[8];
  s16 a[8];
} Q;
void func_00273678(void);  // 0x00273678: definition moved into src/anon/unit_00271e08.cpp

}
