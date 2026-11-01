/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef union BD_VALUE BD_VALUE;

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
extern s32 D_0035f3d4;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
extern u16 D_00373288[];
u8 *func_00257770(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 func_00139d78(u8 *) asm("_Z16u_call4_00139d78jjjj");
void func_0028d980(u8 *, s32, u32, u32, u32, s32, s32, s32, s32) asm("_ZN2Tz10MenuCursor6CreateEz");
s32 func_0023aa98(u8 *) asm("_ZN2YI8SEQUENCE10GetParamExEv");
s32 func_0023aa58(u8 *) asm("_ZN2YI8SEQUENCE12GetParamSizeEv");
s32 func_00257140(s32) asm("_ZN2Tz5CmTop18GetFontColorSeqNumEi");
void func_0028dcc0(u8 *, u8 *) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_00139620(u8 *) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void func_00138c68(u8 *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
void func_00262768(void) asm("_ZN2Tz6CmItem11ChgCategoryEi");
void func_002623c8(void)
{
  unsigned short new_var2;
  s32 y = 0;
  u8 *p = func_00257770();
  u8 *new_var;
  u8 *hdr = p + 2504;
  u8 *sz;
  func_00139d78(hdr);
  new_var = hdr;
  new_var2 = 241;
  u8 *e = p + 3376;
  s32 id = D_0035f3d4;
  func_0028d980(new_var, id++, D_0035ef68, D_0035ef64, D_0035f03c, new_var2, 242, -1, 0);
  s32 step = func_0023aa98(p + 2528);
  s32 i = 4;
  s32 w = func_0023aa58(p + 2528);
  s32 k = func_00257140(0);
  u16 *t = D_00373288;
  do
  {
    if (1)
    {
      func_0028d980(e, id, D_0035ef68, D_0035ef64, D_0035f03c, k, -1, -1, 0);
      func_0028dcc0(e, hdr);
      func_00139620(e);
      *((s32 *) (e + 432)) = 2;
    }
    new_var = e;
    func_00138c68(new_var, y, 0);
    y += step;
    *((s32 *) (e + 408)) = func_00192048(*(t++));
    *((s32 *) (e + 424)) = w;
    i--;
    e += 436;
  }
  while (i >= 0);
  func_00262768();
}

}
