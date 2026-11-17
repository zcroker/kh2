/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct E E;
typedef struct Obj Obj;
typedef struct PR PR;
typedef struct R R;
typedef struct Tbl Tbl;
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
typedef struct E
{
  u8 b0;
  u8 b1;
  u16 id;
  u8 cnt;
  u8 b5;
  u8 pad[6];
} E;
typedef struct Tbl
{
  u8 pad[8];
  s32 count;
  E e[1];
} Tbl;
typedef struct PR
{
  u8 pad[18];
  u8 n;
  u8 pad2[33];
  u16 a[8];
  u16 b[8];
} PR;
typedef struct R
{
  u8 pad[16];
  u16 id;
} R;
typedef struct Obj
{
  u8 pad[268];
  Tbl t;
  u8 pad2[(2528 - 268) - (sizeof(Tbl))];
  void *party;
} Obj;
void _ZN2YS12COMMAND_MENU5clearEv(Tbl *);
PR *_ZN2YS5PARTY11get_partramEv(void *);
R* func_001a80c8(u32);
void func_001bc780(Tbl *, u32, s32, s32);
void func_001bce00(Tbl *);
void func_001be9a0(Obj *o);  // 0x001be9a0: definition moved into src/anon/unit_001bc568.cpp

}
