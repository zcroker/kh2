/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Lst29be08 Lst29be08;
typedef struct Obj29be08 Obj29be08;
typedef union G29be08 G29be08;
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
typedef struct Lst29be08 Lst29be08;
typedef struct Obj29be08 Obj29be08;
typedef union G29be08 G29be08;
struct Lst29be08
{
  u8 pad[5];
  s8 count;
  u8 pad2[2];
  s16 ids[1];
};
struct Obj29be08
{
  u8 pad[420];
  u32 f420;
  u8 pad2[4];
  s32 f428;
  u8 pad3[4];
  void *f436;
};
extern s32 D_0035f3d4;
extern s32 D_0035f14c;
extern s32 D_0035f148;
extern s32 D_0035f210;
union G29be08
{
  void *p;
  u8 c;
};
extern G29be08 D_0035f200;
extern Lst29be08 *D_0035f5ac;
void *func_00276348(void);
void *func_002766d0(void);
void func_00293d80(s32 a);
void func_0029dd00(void);
void func_0029dd60(void);
void func_00276e78(void);
void func_0028d8c0(void *w, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);
void func_00139620(void *w);
void func_0028dcc0(void *a, void *b);
void func_00288d80(void *s, s32 a, s32 b, s32 c, s32 d, s32 e, s16 *f, s16 *g);
Obj29be08 *func_002891b8(void *s, s32 a);
void func_001395f8(void *o);
void func_0029d318(void);
void func_0029daa0(void);
void func_00276690(s32 a);
void func_0028af28(void *s, s32 a);
u8 *func_00294000(s32 a);
s32 func_002943b0(u8 *p);
u32 func_0028af88(void *s);
void func_0028af18(void *s, u32 a);
void func_0028b1e8(void *s, s32 a);
volatile unsigned short func_0029e960(void);
void func_0029ea30(void);
void func_00287cc0(s32 a);
void func_0029dba0(void);
void func_0029be08(void)
{
  s16 c[2][4];
  s32 i;
  s32 j;
  s32 n;
  s32 m;
  void *o = func_00276348();
  void *w = func_002766d0();
  u8 *t;
  u32 fl;
  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 4; j++)
    {
      c[i][j] = 2;
    }

  }

  m = D_0035f3d4 - 1;
  func_00293d80(5101);
  func_0029dd00();
  func_0029dd60();
  func_00276e78();
  n = 0;
  func_0028d8c0(w, m, D_0035f14c, D_0035f148, D_0035f210, 75, -1, 0);
  func_00139620(w);
  func_0028dcc0(w, o);
  func_00288d80(D_0035f200.p, 0, D_0035f14c, D_0035f148, D_0035f210, -1, c[0], c[1]);
  func_00139620(func_002891b8(D_0035f200.p, 0));
  func_0028dcc0(func_002891b8(D_0035f200.p, 0), w);
  func_002891b8(D_0035f200.p, 0)->f428 = 3;
  func_002891b8(D_0035f200.p, 0)->f420 = 0x60000008;
  func_002891b8(D_0035f200.p, 0)->f436 = (void *) func_0029dba0;
  func_001395f8(func_002891b8(D_0035f200.p, 0));
  func_0029d318();
  func_0029daa0();
  func_00276690(1);
  func_0028af28(D_0035f200.p, 16);
  t = func_00294000(3) + 16;
  for (i = 0; i < D_0035f5ac->count; i++)
  {
    if (func_002943b0(t + (D_0035f5ac->ids[i] * 36)))
    {
      n++;
    }
  }

  fl = func_0028af88(D_0035f200.p);
  if (n >= 2)
  {
    fl |= 0xc000;
  }
  func_0028af18(D_0035f200.p, fl | 0x200);
  func_0028b1e8(D_0035f200.p, 0);
  func_0029e960();
  func_0029ea30();
  func_00287cc0(0);
}

}
