/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Obj Obj;
typedef struct Sub Sub;
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
struct Sub
{
  u8 pad[0x188];
  s32 m188;
  u8 pad2[0xc];
  s32 m198;
};
struct Obj
{
  u8 pad[0x30];
  Sub a;
  u8 pad2[(0x230 - 0x30) - (sizeof(Sub))];
  Sub b;
  u32 f0 : 1;
  u32 f1 : 1;
};
void func_00138c10(Sub *, s32) asm("_ZN2dk6Sprite6setNumEi");
void func_001508a0(Obj *, s32);
inline static void setm(Sub *p, s32 x)
{
  p->m198 = x;
}

void func_00150940(Obj *o, s32 x);  // 0x00150940: definition moved into src/anon/unit_0014ecb8.cpp

}
