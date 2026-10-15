/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Gw29dba0 Gw29dba0;
typedef struct Rc29dba0 Rc29dba0;
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
typedef struct Gw29dba0 Gw29dba0;
typedef struct Rc29dba0 Rc29dba0;
struct Gw29dba0
{
  u8 pad[6920];
  s16 id;
  u8 pad2[49];
  s8 col;
};
struct Rc29dba0
{
  u8 pad[20];
  s32 w;
};
extern void *D_0035f200;
extern u8 *D_0035f224;
extern Gw29dba0 *D_0035f5b0;
u8 *func_002766d0(void);
s32 func_0028b040(void *a);
void func_0014b950(void *p, s16 x, s16 y, u16 w, u16 c);
void func_0014b9a8(void *p);
s32 func_0023aa58(void *p);
s32 func_0023aa78(void *p);
Rc29dba0 *func_001aae68(s32 a);
s32 func_00192048(s16 id);
void func_001a98e8(void *t, s32 a, s32 b, s32 c, s32 d);
void func_001aa6d0(void *t, s32 w);
void func_001a9ae8(void *t, s32 x, s32 y, s32 z);
void func_0029dba0(s32 x, s32 y, s32 z)
{
  u8 buf[96];
  s32 lo = 15;
  u8 *ent;
  s32 sc;
  s32 *new_var;
  s32 a;
  s32 b;
  ent = func_002766d0() + 24;
  sc = func_0028b040(D_0035f200);
  func_0014b950(D_0035f224 + 32, x, y, 512 - x, D_0035f5b0->col * 7);
  func_0014b9a8(D_0035f224 + 32);
  a = func_0023aa58(ent);
  b = func_0023aa78(ent);
  if (a)
  {
    lo = a;
  }
  sc *= b;
  {
    Rc29dba0 *r = func_001aae68(3);
    b -= lo;
    y -= sc;
    b -= r->w;
  }
  if (b < 0)
  {
    b = 0;
  }
  func_001a98e8(buf, 3, func_00192048(D_0035f5b0->id), lo, 0);
  func_001aa6d0(buf, b);
  func_001a9ae8(buf, x, *(new_var = &y), z);
  func_0014b9a8(D_0035f224);
}

}
