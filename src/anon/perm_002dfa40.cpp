/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W W;
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
extern s32 D_00361f60;
extern u8 D_00362c00[];
s32 func_001b0320(s32);
u8 *func_002dc7c8(s32);
void func_002e7568(f32, void *, s32, void *);
typedef struct W
{
  u8 pad[0x9b8];
  s32 h;
} W;
inline f32 inline_fn(s32 arg0)
{
  return ((f32 *) func_002dc7c8(arg0))[0xcc / 4];
}

void func_002dfa40(void *a0, W *p)
{
  s32 r;
  s32 g = D_00361f60;
  u8 *new_var;
  s32 h;
  r = 0;
  h = p->h;
  new_var = D_00362c00;
  if (h)
  {
    r = func_001b0320(h);
  }
  if (!((u8) r))
  {
    func_002e7568(inline_fn(g), p, 6, new_var);
  }
}

}
