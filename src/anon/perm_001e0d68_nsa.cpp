/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct G G;
typedef struct M M;
typedef struct Obj Obj;
typedef union BD_VALUE BD_VALUE;
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
struct M
{
  f32 m[16];
};
struct G
{
  u8 pad[0xdc4];
  M *arr;
};
extern G *D_00352bd0;
struct Obj
{
  u8 pad[0x20];
  s32 idx;
};
inline static M *get(Obj *o)
{
  return &D_00352bd0->arr[o->idx];
}

void func_001e0d68(Obj *o, f32 *v)
{
  f32 y;
  Obj *new_var2;
  f32 new_var5;
  f32 z;
  M *new_var4;
  f32 x;
  f32 new_var6;
  Obj *new_var;
  short new_var3;
  new_var = o;
  new_var3 = 0;
  new_var6 = v[0];
  y = v[1];
  new_var5 = new_var6;
  new_var4 = get(o);
  do
  {
  }
  while (new_var3);
  z = v[2];
  new_var4->m[8] = new_var5;
  new_var2 = new_var;
  get(new_var2)->m[9 ^ 0] = y;
  get(o)->m[10] = z;
}

}
