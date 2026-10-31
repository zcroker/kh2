/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Base2990 Base2990;
typedef struct Ctl2990 Ctl2990;
typedef struct Q2990 Q2990;
typedef struct Sub2990 Sub2990;
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
struct Sub2990
{
  u8 p[184];
  u32 flags;
};
struct Ctl2990
{
  u8 p0[24];
  Sub2990 sub;
  u8 p1[(392 - 24) - 188];
  s32 mode;
  u8 p2[405 - 396];
  u8 b195;
};
struct Q2990
{
  u8 p[400];
  u8 b190;
};
struct Base2990
{
  u8 p0[24];
  u8 s18[17304 - 24];
  Ctl2990 ctl;
  u8 p1[(0xdca0 - 17304) - (sizeof(Ctl2990))];
  Q2990 q;
};
inline static void SetQ(Q2990 *q, s32 v)
{
  q->b190 = v;
}

inline static void SetC(Ctl2990 *c, s32 v)
{
  c->b195 = v;
}

Base2990 *func_002766d0() asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 func_00139d78(Ctl2990 *) asm("_Z16u_call4_00139d78jjjj");
void func_00298fe8(s32) asm("_ZN2Tz7JmAlbum14RequestGraLoadEi");
s32 func_00292630() asm("_ZN2Tz18LoadDataIsFlushingEv");
void func_00298ee0();
s32 func_0023f1b0(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 func_0023c4b8(s32, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 func_0023f988(s32, s32) asm("_ZNK2Tz7LayFile13getImdAddressEi");
void func_002362b0(Q2990 *, s32);
void func_001386e0(Ctl2990 *, s32, s32, Q2990 *, s32, s32);
void func_00139620(Ctl2990 *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_0028dcc0(Ctl2990 *, Base2990 *) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
s32 func_0023aa18(void *) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 func_0023aa38(void *) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void func_00138c68(Ctl2990 *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
extern s32 D_0035f210;
extern s32 D_0035f3d4;
extern s32 D_0035f59c;
extern s8 D_0035f5a1;
extern u8 D_0035f5a3;
void func_00299090(void)
{
  Base2990 *base = func_002766d0();
  Ctl2990 *new_var;
  Ctl2990 *c = &base->ctl;
  if (func_00139d78(c))
  {
    return;
  }
  if ((D_0035f5a3 == 0) && (D_0035f5a1 >= 0))
  {
    func_00298fe8(D_0035f5a1);
    return;
  }
  if ((double) ((D_0035f5a1 < 0) || func_00292630()))
  {
    return;
  }
  func_00298ee0();
  Q2990 *q = &base->q;
  s32 f = D_0035f210;
  s32 x = D_0035f3d4;
  void *s = base->s18;
  s32 r = func_0023c4b8(func_0023f1b0(f), 1);
  func_002362b0(q, func_0023f988(D_0035f59c, 0));
  q->b190 = 1;
  func_001386e0(c, x, r, q, 1, 0);
  c->mode = 2;
  new_var = c;
  func_00139620(new_var);
  Sub2990 *sb = &base->ctl.sub;
  sb->flags |= 8;
  SetC(c, 1);
  func_0028dcc0(c, base);
  s32 a = func_0023aa18(s);
  D_0035f3d4 += 0;
  func_00138c68(c, a, func_0023aa38(s));
  D_0035f5a1 = -1;
  D_0035f5a3 = 0;
}

}
