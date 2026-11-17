/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent Ent;
typedef struct M64 M64;
typedef struct Mgr Mgr;
typedef struct Q Q;
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
struct M64
{
  u8 d[64];
};
struct Ent
{
  u8 pad[0x1c4];
  s32 p2;
  s32 a0;
  s32 z;
  s32 a3;
  s32 a4;
  M64 m1;
  M64 m2;
  u8 pad2[0x258 - 0x258];
};
struct Q
{
  s32 head;
  s32 tail;
  Ent e[4];
};
struct Mgr
{
  u8 pad[0x25b8];
  Q q;
};
extern Mgr *D_0034a6f0;
void func_00192c90(s32, M64 *) asm("_ZNK2YS7MESSAGE3dupEPc");
void func_00192b30(s32) asm("_ZNK2YS7MESSAGE8get_sizeEv");
void func_00153350(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);  // 0x00153350: definition moved into src/anon/unit_00153158.cpp

}
