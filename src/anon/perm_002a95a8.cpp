/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1610Base W1610Base;
typedef struct W1610LE W1610LE;
typedef struct W1610Lst W1610Lst;
typedef struct W1610Rec W1610Rec;
typedef struct W1610Slot W1610Slot;
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
struct W1610Slot
{
  u8 pad[408];
  s32 h;
  u8 pad2[436 - 412];
};
struct W1610LE
{
  s8 a;
  s8 b;
  u16 c;
};
struct W1610Lst
{
  s32 cnt;
  W1610LE e[1];
};
struct W1610Rec
{
  u8 pad[4];
  u16 id;
};
struct W1610Base
{
  u8 pad[0xa998];
  u8 lay[10][408];
  u8 pad2[(0x110a0 - 0xa998) - 4080];
  u8 name[10][64];
};
extern s32 D_0035f200;
extern s32 D_0035f214;
extern W1610Slot *D_0035f60c;
extern W1610Lst *D_0035f608;
extern s32 D_00374c38;
extern s32 D_00374c3c;
W1610Base *func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 func_0028b038(s32) asm("_ZN2Tz6Select12GetSelectTopEv");
void func_0028be78(s32, s32);
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void func_00138c10(void *, s32) asm("_ZN2dk6Sprite6setNumEi");
s32 func_00295430(s32, s32);
s32 func_002954e0(s32) asm("_ZN2Tz10JmWorldSel11isWorldOpenEi");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
s32 func_0028de08(s32, void *, s32);
s32 func_002a9c40(s32);
W1610Rec *func_002a92a0(s32);
s32 func_002a99c8(W1610Rec *);
s32 func_002aacd8(s32);
s32 func_002aad58(s32);
void func_002a95a8(void)
{
  W1610Base *base = func_002766d0();
  int new_var2;
  s32 new_var;
  s32 idx = func_0028b038(D_0035f200);
  func_0028be78(D_0035f214, idx);
  func_002fde18(base->name, 0, 640);
  s32 i;
  for (i = 0; i < 10; i++)
  {
    W1610Slot *p = &D_0035f60c[i];
    func_00138c10(p, 2);
    p->h = 0;
    func_00138c10(base->lay[i], 2);
  }

  s32 n = D_0035f608->cnt;
  if (n > 10)
  {
    n = 10;
  }
  for (i = 0; i < n; i++)
  {
    s32 a = D_0035f608->e[idx + i].a;
    W1610Slot *s = &D_0035f60c[i];
    u8 *buf = base->name[i];
    s32 h;
    if ((D_0035f608->e[idx + i].b < 0) && (D_0035f608->e[idx + i].c == 0))
    {
      func_00138c10(s, 102);
      h = (new_var = func_00295430(a, 1));
      if (func_002954e0(a))
      {
        s->h = func_00192048(h);
      }
      else
      {
        s->h = func_0028de08(h, buf, 64);
      }
    }
    else
      if ((D_0035f608->e[idx + i].b < 0) && (D_0035f608->e[idx + i].c != 0))
    {
      func_00138c10(s, 104);
      h = D_0035f608->e[idx + i].c;
      if (func_002a9c40(h))
      {
        s->h = func_00192048(h);
      }
      else
      {
        s->h = func_0028de08(h, buf, 64);
      }
    }
    else
    {
      h = 106;
      W1610Rec *r = func_002a92a0(D_0035f608->e[idx + i].b);
      new_var2 = 107;
      s32 v = func_002a99c8(r);
      if (v == 2)
      {
        h = new_var2;
      }
      func_00138c10(s, h);
      h = r->id;
      if (v != 3)
      {
        if (s)
        {
          a = func_00192048(h);
          s->h = a;
        }
        else
        {
          a = func_00192048(h);
          s->h = a;
        }
      }
      else
      {
        s->h = func_0028de08(h, buf, 64);
      }
      if (func_002aacd8(D_0035f608->e[idx + i].b))
      {
        if (func_002aad58(D_0035f608->e[idx + i].b))
        {
          h = D_00374c3c;
        }
        else
        {
          h = D_00374c38;
        }
        func_00138c10(base->lay[i], h);
      }
    }
  }

}

}
