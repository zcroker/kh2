/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct O2 O2;
typedef struct OB2 OB2;
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
typedef struct OB2
{
  u8 pad[4];
  u8 b4;
} OB2;
typedef struct O2
{
  u8 pad[0xae4];
  u8 kind;
  u8 pad2[0xaf8 - 0xae5];
  OB2 *q;
  u8 pad3[8];
  u8 w[4];
} O2;
void *func_001c3748(u8, void *);
s32 func_001c3888(void *);
void func_002f1900(void *, s32, void *);
void func_002bf8f0(O2 *p)
{
  O2 *new_var;
  void *e;
  if (p->kind < 2)
  {
    return;
  }
  e = 0;
  while ((e = func_001c3748(p->q->b4, e)) != 0)
  {
    if (func_001c3888(e))
    {
      new_var = p;
      func_002f1900(p->w, 4, new_var);
      return;
    }
  }

}

}
