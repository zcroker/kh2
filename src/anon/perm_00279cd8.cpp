/* found by decomp-permuter (nightly.py) */
extern "C" {


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
extern s32 D_0035ef64;
extern s32 D_0035ef68;
extern s32 D_0035ef6c;
extern s32 D_0035f03c;
u8 *func_00257770(void);
void func_00139d78(void *);
void func_0028d8c0(void *, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(void *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_0023aa98(void *);
s32 func_0023aa78(void *);
s32 func_0023aa18(void *);
s32 func_0023aa38(void *);
void func_00138c10(void *, s32);
void func_00138c68(void *, s32, s32);
void func_0028dcc0(void *, void *);
void func_00139688(void *);
void func_00139620(void *);
void func_001395f8(void *);
s32 func_00257140(s32);
void func_001398d0(s32);
void func_00279cd8(void)
{
  int new_var;
  s32 i = 0;
  u8 *base = func_00257770();
  func_00139d78(base);
  u8 *p = base;
  func_0028d8c0(base, 30013, D_0035ef68, D_0035ef64, D_0035f03c, 140, 141, 100);
  do
  {
    u8 *a = p + 13840;
    u8 *q = p + 13864;
    u8 *b = p + 3376;
    new_var = 1;
    func_0028d980(a, 30014, D_0035ef68, D_0035ef64, D_0035f03c, 150, -new_var, -new_var, 100);
    s32 w = func_0023aa98(q);
    s32 h = func_0023aa78(q);
    s32 x = func_0023aa18(q);
    s32 y = func_0023aa38(q);
    func_00138c10(a, D_0035ef6c);
    func_00138c68(a, (i % 2) * w, (i / 2) * h);
    i++;
    func_0028dcc0(a, base);
    func_00139688(a);
    func_00139620(a);
    func_0028d980(b, 30015, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -new_var, -new_var, 100);
    func_0028dcc0(b, a);
    func_00138c68(b, x, y);
    func_00139620(b);
    func_001395f8(b);
    *((s32 *) (p + 3808)) = new_var;
    p += 436;
  }
  while (i < 20);
  if (p || D_0035f03c)
  {
    func_001398d0(100);
  }
  else
  {
    func_001398d0(100);
  }
}

}
