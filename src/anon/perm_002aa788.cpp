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
s32 func_002a9d68() asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 func_00294000(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
u32 func_002aa5b8(s32, s32);
extern s32 D_0035f610;
s32 func_002aa788(s32 a, s32 id);  // 0x002aa788: definition moved into src/anon/unit_002a99c8.cpp

}
