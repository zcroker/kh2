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

void func_001e0d08(Obj *o, f32 *v)
{
  f32 z = v[2];
  int new_var4;
  M *new_var3;
  M *new_var5;
  f32 new_var;
  f32 x = v[0];
  Obj *new_var2;
  f32 y = v[1];
  new_var4 = 0;
  new_var5 = get(o);
  do
  {
    new_var = z;
    new_var5->m[12] = x;
    z = y;
    (new_var3 = get(o))->m[13] = z;
    new_var2 = o;
    get(new_var2)->m[14] = new_var;
  }
  while (new_var4);
}

}
