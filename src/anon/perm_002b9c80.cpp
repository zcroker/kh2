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
s32 func_001688c8(void *);
s32 func_00170b30(s32);
void func_001682b8(void *, s32);
void SOUND__sebTransfer(s32, s32, s32);
void func_002ba188(s32, s32, s32);
s32 func_002b6f78(void);
void func_002b6ab8(void);
void func_00170c00(s32);
extern u8 D_00374f30[];
extern u8 D_00374f40[];
extern u8 D_00374f50[];
extern u8 D_00374f60[];
void SOUND__initCommonSe(void);  // 0x002b9c80: definition moved into src/anon/unit_002b9ab8.cpp

}
