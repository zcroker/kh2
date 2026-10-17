/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1610Ent W1610Ent;
typedef struct W1610Mn W1610Mn;
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
typedef struct W1610Ent W1610Ent;
typedef struct W1610Mn W1610Mn;
struct W1610Ent
{
  u16 a;
  u16 b;
  u16 c;
};
struct W1610Mn
{
  u8 pad[0x20];
  s8 mode;
  u8 pad2[0x7a4 - 0x21];
  u8 buf[160];
};
extern W1610Mn *D_0035f0e4;
extern s32 D_0035f01c;
extern s32 D_0035f010;
extern u16 D_00373518[];
extern W1610Ent D_00373530[][10];
extern W1610Ent D_003735a8[][10];
extern W1610Ent D_00373620[][10];
extern u16 D_00373698[];
extern u16 D_003736a0[];
extern u16 D_003736a8[];
extern u16 D_003736b0[];
extern u16 D_003736b8[];
s32 func_00287bc0(void);
void func_002fde18(void *, s32, s32);
s32 func_0028b040(s32);
u32 func_002670a0(s32);
s32 func_00192048(u16);
s32 func_00281140(s32, s32);
s32 func_00192e50(s32, void *, s32, s32);
void func_00192b30(s32);
void func_00192c90(s32, void *);
void func_00263a90(void *, s32);
s32 func_00267248(void);
u32 func_00257070(s32);
s32 func_002671e8(s32);
void func_00263a58(u16, s32);
void func_002666a8(void)
{
  s32 new_var;
  W1610Ent *tab = 0;
  s32 obj;
  u32 st = func_00287bc0();
  func_002fde18(D_0035f0e4->buf, 0, 160);
  if (st == 23)
  {
    u32 v = func_002670a0(func_0028b040(D_0035f01c));
    u16 id = D_00373518[v];
    switch (v)
    {
      case 0:
      {
        ;
        func_00192b30(func_00192e50(func_00192048(id), D_0035f0e4->buf, 160, func_00281140(D_0035f010, 0)));
        break;
      }

      case 1:

      case 2:

      case 3:

      case 4:

      case 5:

      case 6:
        func_00192c90(func_00192048(id), D_0035f0e4->buf);
        break;

      case 7:

      case 8:

      case 9:
      {
        obj = v - 6;
        st = func_00192048(id);
        func_00192b30(func_00192e50(st, D_0035f0e4->buf, 160, func_00281140(D_0035f010, obj)));
        break;
      }

    }

    func_00263a90(D_0035f0e4->buf, 1);
    return;
  }
  obj = func_0028b040(func_00267248());
  st = func_00257070(23);
  switch (st)
  {
    case 0:

    case 7:

    case 8:

    case 9:
      tab = D_00373530[D_0035f0e4->mode];
      break;

    case 1:

    case 2:

    case 3:

    case 4:

    case 5:
      tab = D_003735a8[D_0035f0e4->mode];
      break;

    case 6:
      tab = D_00373620[D_0035f0e4->mode];
      break;

  }

  s32 r = func_002671e8(obj);
  obj = r;
  if (D_0035f0e4->mode)
  {
    obj = r - 10;
  }
  u16 id = tab[obj].b;
  new_var = r;
  if (((st - 1) < 5) && (((u32) new_var) < 4))
  {
    u16 *t = 0;
    switch (st)
    {
      case 1:
        t = D_00373698;
        break;

      case 2:
        t = D_003736a0;
        break;

      case 3:
        t = D_003736a8;
        break;

      case 4:
        t = D_003736b0;
        break;

      case 5:
        t = D_003736b8;
        break;

    }

    switch (r)
    {
      case 0:
        obj = 0;
        break;

      case 1:
        obj = 1;
        break;

      case 2:
        obj = 2;
        break;

      case 3:
        obj = 3;
        break;

    }

    id = t[obj];
  }
  func_00263a58(id, 1);
}

}
