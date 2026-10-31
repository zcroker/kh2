/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Obj Obj;
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
typedef struct Obj Obj;
struct Obj
{
  u8 pad[0x18c];
  s32 a18c;
  s32 a190;
};
Obj *func_0028c198(s32, s32, s32, s32, s32, s32);
s32 func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void func_001396b0(Obj *) asm("_ZN2Tz6Select10BeginLeaveEz");
void func_0031a260(Obj *, s32) asm("_ZN2Tz6Select7SetFlagEz");
void func_00139620(Obj *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_00139660(Obj *) asm("_ZN2dk5Obj2D19getParentSeqColorOnEv");
void func_00139688(Obj *) asm("_ZN2dk5Obj2D21getParentSeqAlphaOnlyEv");
extern s32 D_0035f3d4;
extern s32 D_0035f640;
extern s32 D_0035f644;
extern s32 D_0035f648;
extern s32 D_0035f64c;
extern s32 D_0035f664;
extern Obj *D_0035f690[][4];
void func_002b57e0(void)
{
  int new_var;
  s32 i;
  s32 a;
  int new_var2;
  s32 saved = D_0035f3d4;
  for (i = 0; i < 3; i++)
  {
    new_var = 1;
    a = 0;
    s32 b = new_var;
    s32 c = 1;
    switch (i)
    {
      case 1:
        break;

      case 0:
        c = 2;
        b = 2;
        break;

      case 2:

      default:
        D_0035f3d4 = 0x7561;
        c = D_0035f644;
        b = D_0035f640;
        a = D_0035f648;
        break;

    }

    new_var2 = 0;
    s32 j;
    for (j = new_var2; j < 4; j++)
    {
      Obj *o = func_0028c198(a, c, b, D_0035f664, -1, new_var2);
      D_0035f690[i][j] = o;
      (*o).a18c = func_002891b8(D_0035f64c, j);
      func_001396b0(o);
      if (o->a18c != new_var2)
      {
        o->a190 = new_var2;
        func_001396b0(o);
        if (o->a190 != (new_var2 * new_var2))
        {
          func_0031a260(o, new_var2);
 do { } while (new_var2);
        }
      }
      func_00139620(D_0035f690[i][j]);
      func_00139660(D_0035f690[i][j]);
      func_00139688(D_0035f690[i][j]);
    }

    if (i == 2)
    {
      D_0035f3d4 = saved;
    }
  }

}

}
