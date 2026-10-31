/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent Ent;
typedef struct Tbl Tbl;
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
s32 func_00257770(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 func_00287bc0(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_002fde18(s32, s32, s32) asm("_Z16wtarget_002fde18jjjj");
s32 func_0028b040(s32) asm("_ZN2Tz8JmReport7GetDataEj");
s32 func_002570a0(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
void func_0027aed8(s32, s32 *, s32 *);
void func_00263a58(s32, s32) asm("_ZN2Tz9CMenuHelp6CreateEib");
volatile short func_00263a90(s32, s32);
u8 *func_0027bba0(s32) asm("_Z16ctarget_0027bba0jjjj");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
s32 func_00192b30(s32) asm("_ZNK2YS7MESSAGE8get_sizeEv");
void func_00192c90(s32, s32) asm("_ZNK2YS7MESSAGE3dupEPc");
s32 func_0027af58(void);
s32 func_0027c3b8(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
u8 *func_00273180(s32, s32);
void func_002595e8(s32, s32) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
extern s32 D_0035f01c;
extern s32 D_00373e04[2];
extern u16 D_00373e68[2];
struct Ent
{
  u16 id;
  s8 on;
  u8 p0;
  s8 col;
  u8 p1;
  s8 kind;
  u8 p2;
};
struct Tbl
{
  u8 pad[7];
  s8 n;
  u8 pad2[4];
  Ent e[1];
};
extern Tbl *D_0035f230;
void func_0027b6b8(void)
{
  s32 b = func_00257770();
  s32 mode = func_00287bc0();
  s32 buf = b + 0xB1D0;
  s32 r0;
  s32 r1;
  s32 s2;
  s32 s5;
  s32 s1;
  s32 s0;
  func_002fde18(buf, 0, 0xC0);
  if (mode == 15)
  {
    func_0027aed8(func_0028b040(D_0035f01c), &r0, &r1);
    if (r0 == 0)
    {
      s0 = D_00373e04[0];
    }
    else
    {
      s0 = D_00373e04[1];
    }
    func_00263a58(s0, 1);
    return;
  }
  if (mode == 16)
  {
    if (D_0035f230->n == 0)
    {
      func_00263a58(-1, 1);
      return;
    }
    s2 = func_0028b040(D_0035f01c);
    s0 = *((u16 *) (func_0027bba0(s2) + 0xA));
    s5 = func_00192b30(func_00192048(s0));
    s32 h = func_00192048(s0);
    func_00192c90(h, buf);
    func_00263a90(buf, 1);
  }
  else
  {
    s2 = func_0028b040(D_0035f01c);
    s0 = D_00373e68[(s2 == 0) ? (0) : (1)];
    s5 = func_00192b30(func_00192048(s0));
    func_00192c90(func_00192048(s0), buf);
    func_00263a90(buf, 1);
    if (s2 == 0)
    {
      return;
    }
  }
  func_0027aed8(func_002570a0(15), &r0, &r1);
  s0 = func_0027af58();
  if (mode == 16)
  {
    s1 = s2;
  }
  else
  {
    s1 = func_002570a0(16);
  }
  if (r0 != 0)
  {
    return;
  }
  if (r1 == 0)
  {
    return;
  }
  if (s0 != 0)
  {
    return;
  }
  if (func_0027c3b8(s1))
  {
    return;
  }
  u8 *t = func_00273180(4, -1);
  s32 j;
  if (mode == 16)
  {
    Tbl *tb = D_0035f230;
    if (tb->e[s1].kind < 0)
    {
      return;
    }
    if (!tb->e[s1].on)
    {
      return;
    }
    for (j = 0; j < 3; j++)
    {
      if (t[(j * 8) + 5] == tb->e[s2].kind)
      {
        break;
      }
    }

  }
  else
  {
    j = s2 - 1;
  }
  s0 = *((u16 *) ((t + (j * 8)) + 2));
  func_002595e8((b + s5) + 0xB1D0, func_00192048(s0));
}

}
