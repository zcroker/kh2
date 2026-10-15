/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Area Area;
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
typedef struct Area
{
  u8 world;
  u8 area;
  u8 entrance;
  u8 pad3;
  u16 layout;
  u16 event;
  u16 btl;
} Area;
extern Area D_0032bae0;
extern s32 D_0035de58;
u32 func_00225a30(void);
u32 func_00228378(void);
s32 func_002ef7b8(void);
s32 func_001979d8(Area *);
s32 func_001051a0(Area *, Area *);
void func_00168808(u32);
s32 func_00170e80(void);
void func_00149370(Area *, char *);
s32 func_001688c8(const char *);
void func_00170518(const char *, s32, u32);
void func_00170888(void *);
const char *func_001921d8(u32);
void func_00192260(u32, s32);
void func_00226268(void)
{
  Area area;
  unsigned char new_var;
  char name[48];
  s32 avail;
  s32 need;
  s32 st;
  if (func_00225a30())
  {
    return;
  }
  st = D_0035de58;
  if (st == 2)
  {
    return;
  }
  if (st == 0)
  {
    st = 2;
  }
  D_0035de58 = st;
  if (!func_00228378())
  {
    return;
  }
  if (func_002ef7b8())
  {
    return;
  }
  {
    u32 v = 0xffff;
    area.world = v;
    area.area = v;
    area.entrance = v;
    area.layout = v;
    area.event = v;
    area.btl = v;
  }
  if (!func_001979d8(&area))
  {
    return;
  }
  if (func_001051a0(&D_0032bae0, &area))
  {
    return;
  }
  if (D_0035de58 != 1)
  {
    if (new_var = D_0032bae0.world != area.world)
    {
      func_00168808(area.world);
      D_0035de58 = 1;
      return;
    }
  }
  D_0035de58 = 2;
  avail = func_00170e80();
  func_00149370(&area, name);
  need = (func_001688c8(name) + 0x7ff) & (~0x7ff);
  if (avail < need)
  {
    return;
  }
  func_00170518(name, -200, 0);
  if (D_0032bae0.world != area.world)
  {
    avail -= need;
    if (avail >= ((func_001688c8(func_001921d8(area.world)) + 0x7ff) & (~0x7ff)))
    {
      func_00192260(area.world, -200);
    }
  }
  func_00170888(0);
}

}
