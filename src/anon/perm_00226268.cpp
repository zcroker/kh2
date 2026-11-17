/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Area Area;
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
typedef struct Area
{
  u8 world;
  u8 area;
  u8 entrance;
  u8 pad3;
  u16 layout;
  u16 event;
  u16 btl;
} Area;
extern Area D_0032bae0;
extern s32 D_0035de58;
u32 func_00225a30(void);
u32 func_00228378(void);
s32 func_002ef7b8(void);
s32 func_001979d8(Area *);
s32 func_001051a0(Area *, Area *);
void func_00168808(u32);
s32 func_00170e80(void);
void func_00149370(Area *, char *);
s32 func_001688c8(const char *);
void func_00170518(const char *, s32, u32);
void func_00170888(void *);
const char *func_001921d8(u32);
void func_00192260(u32, s32);
void func_00226268(void);  // 0x00226268: definition moved into src/anon/unit_00224780.cpp

}
