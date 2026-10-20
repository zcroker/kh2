/* found by decomp-permuter (nightly.py) */
extern "C" {


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
extern f32 D_00349e10;
u8 *func_00167f18(u32) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
void func_0013fd78(f32, u8 *, u8 *) asm("_ZN2dk9ObjCamera10initRadiusEv");
void func_0013fdf0(f32, u8 *, u8 *);
f32 func_0013fd10(u8 *);
void func_001585e8(u8 *p)
{
  u8 *pad = func_00167f18(0);
  f32 t = D_00349e10;
  f32 new_var;
  if ((*((u64 *) (pad + 8))) & 0x20000)
  {
    new_var = t;
    func_0013fd78(new_var, p, pad);
  }
  else
  {
    func_0013fdf0(t, p, pad);
  }
  new_var = func_0013fd10(p);
  f32 r = new_var;
  *((f32 *) (p + 0x50)) = r;
  *((f32 *) (p + 0x4c)) = r;
}

}
