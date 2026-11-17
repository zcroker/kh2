/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Heap24e850 Heap24e850;
typedef struct Heap24e850Vt Heap24e850Vt;
typedef struct Sys24e850 Sys24e850;
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
struct Heap24e850;
struct Heap24e850Vt
{
  u8 *(*alloc)(Heap24e850 *, s32, s32);
};
struct Heap24e850
{
  Heap24e850Vt *vt;
};
struct Sys24e850
{
  u8 pad[20];
  Heap24e850 *heap;
};
extern u8 D_0035eb98[];
extern u8 D_0035ebb8[];
extern u8 *D_0035ee08;
extern u8 *D_0035ee0c;
extern u32 D_0035ee04;
extern Sys24e850 *D_00347f80;
extern u8 D_00372380;
extern u8 D_00372388;
u8 *func_0023ee30(s32);
void func_002369a0(u8 *);
void func_0023c008(u8 *);
void func_0028d7f0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00288ce0(u32, s32, s32, s32, s32);
void func_002891f0(u32, s32, s32, s32, s32);
s32 func_002891e8(u32) asm("_ZN2Tz6Select10GetCurrentEv");
void func_0024f348(void);
void func_0023f1e0(u8 *, s32, u8 *, void *, void *, s32, s32, s32);
void func_0023f6c0(u8 *, s32);
void func_00287cc0(s32) asm("_ZN2Tz8Selector8SetStateEi");
void func_0024e850(void);  // 0x0024e850: definition moved into src/anon/unit_0024e7e8.cpp

}
