/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1572_VObj W1572_VObj;
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
typedef void (*W1572_VFn)(void *);
typedef struct W1572_VObj
{
  W1572_VFn *vt;
} W1572_VObj;
extern W1572_VObj *D_0035f2c4;
extern W1572_VObj *D_0035f2c8;
extern u8 *D_0035f2cc;
extern s32 D_0035f2d4;
extern W1572_VObj *D_0035f2d8;
extern s32 D_0035f2dc;
extern W1572_VObj *D_0035f2e0;
extern u8 D_00347e60[];
void func_00285460(void);
void func_00284ea8(void);
void func_0031acc0(void *);
void func_00239870(void *);
void func_0031a840(void *);
void func_00106420(void *);
void func_00288b00(s32);
void func_00288c20(s32);
void func_00284220(void)
{
  u8 *o;
  W1572_VObj *p;
  W1572_VObj *q;
  s32 h;
  if (o)
  {
    func_00285460();
  }
  else
  {
    func_00285460();
  }
  if (D_0035f2d4 != 1)
  {
    func_00284ea8();
  }
  if (D_0035f2c4)
  {
    D_0035f2c4->vt[1](D_0035f2c4);
    D_0035f2c4 = 0;
  }
  if (D_0035f2c8)
  {
    D_0035f2c8->vt[4](D_0035f2c8);
    D_0035f2c8 = 0;
  }
  o = D_0035f2cc;
  if (o)
  {
    if (o + 4360)
    {
      p = (W1572_VObj *) (o + 7848);
      top1:
      if (((W1572_VObj *) (o + 4360)) == p)
      {
        goto out1;
      }

      p = (W1572_VObj *) (((u8 *) p) - 436);
      p->vt[3](p);
      goto top1;
    }
    out1:
    if (o + 872)
    {
      q = (W1572_VObj *) (o + 4360);
      top2:
      if (((W1572_VObj *) (o + 872)) == q)
      {
        goto out2;
      }

      q = (W1572_VObj *) (((u8 *) q) - 436);
      q->vt[3](q);
      goto top2;
    }

    out2:
    func_0031acc0(o + 436);

    *((u32 *) o) = (u32) D_00347e60;
    func_00239870(o + 24);
    func_0031a840(o);
    func_00106420(o);
    D_0035f2cc = 0;
  }
  if (D_0035f2d8)
  {
    D_0035f2d8->vt[4](D_0035f2d8);
    D_0035f2d8 = 0;
  }
  h = D_0035f2dc;
  if (h)
  {
    func_00288b00(h);
    func_00288c20(h);
    D_0035f2dc = 0;
  }
  if (D_0035f2e0)
  {
    D_0035f2e0->vt[4](D_0035f2e0);
    D_0035f2e0 = 0;
  }
}

}
