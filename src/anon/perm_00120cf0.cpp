/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct B120cf0 B120cf0;
typedef struct S120cf0 S120cf0;
typedef struct VT120cf0 VT120cf0;
typedef union U120cf0 U120cf0;
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
typedef struct S120cf0 S120cf0;
typedef struct VT120cf0 VT120cf0;
typedef struct B120cf0 B120cf0;
typedef union U120cf0 U120cf0;
struct VT120cf0
{
  void *f[12];
  s32 (*count)(S120cf0 *);
};
struct S120cf0
{
  VT120cf0 *vt;
};
union U120cf0
{
  u32 u;
  VT120cf0 *v;
};
struct B120cf0
{
  u8 pad[0x108];
  U120cf0 base;
  U120cf0 mid;
};
u32 func_00120a20(S120cf0 *, B120cf0 *, u32, u32, s32);
void func_00120cf0(S120cf0 *s, B120cf0 *b, u32 base)
{
  U120cf0 new_var2;
  u32 end;
  b->base.u = base;
  b->mid.u = b->base.u + (s->vt->count(s) * 4);
  end = ((b->mid.u + (s->vt->count(s) * 4)) + 15) & (~15);
  base = func_00120a20(s, b, b->base.u, end, 0);
  func_00120a20(s, b, (new_var2 = b->mid).u, base, 1);
}

}
