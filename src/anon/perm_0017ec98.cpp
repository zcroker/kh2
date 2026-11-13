/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Chr Chr;
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
struct Chr
{
  u8 pad[0x588];
  u32 flags;
};
struct Obj
{
  void *a;
  void *b;
  Chr *c;
};
extern u8 D_0036c5e0[][4];
s32 func_0017ebc8(Obj *);
s32 func_0019bf00(Chr *);
s32 func_00176258(Chr *);
s32 func_001a97b8(void *, s32) asm("_ZNK2YS9MOTIONSET9is_playerEv");
// 0017ec98: moved to src/yasui/libys/motion.cpp

}
