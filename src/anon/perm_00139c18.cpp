/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Pair139 Pair139;
typedef struct VObj139 VObj139;
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
typedef struct VObj139 VObj139;
struct VObj139
{
  void (**vt)(VObj139 *);
};
typedef struct Pair139
{
  VObj139 a;
  u8 pad[20];
  VObj139 b;
} Pair139;
s32 u_call4_00139d78(void *) asm("_Z16u_call4_00139d78jjjj");
s32 func_00139c18(Pair139 *p);  // 0x00139c18: definition moved into src/anon/unit_001393c8.cpp

}
