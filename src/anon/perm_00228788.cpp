/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct O_w3 O_w3;
typedef struct W_w W_w;
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
typedef struct W_w
{
  u8 pad[0x188];
  s32 x188;
  void *x18c;
  s32 x190;
  u8 pad2[4];
} W_w;
typedef struct O_w3
{
  u8 pad[0x18];
  W_w w[3];
} O_w3;
void func_00229430(O_w3 *, s32);
s32 func_0022b9e0(void);
s32 func_0022b720(void);
void func_001386e0(W_w *, s32, s32, s32, s32, s32);
void func_001396b0(W_w *);
void func_0031a260(W_w *, s32);
inline static void Upd_w(W_w *w)
{
  func_001396b0(w);
  if (w->x18c)
  {
    w->x190 = 0;
    func_001396b0(w);
    if (w->x190)
      func_0031a260(w, 0);
  }
}

void func_00228788(O_w3 *o)
{
  func_00229430(o, 2800);
  W_w *w1 = &o->w[1];
  W_w *w2 = &o->w[2];
  s32 a = func_0022b9e0();
  s32 b = func_0022b720();
  W_w *w0 = &o->w[0];
  func_001386e0(w0, 2800, a, b, 32, 11);
  w0->x188 = 33;
  w0->x18c = 0;
  Upd_w(w0);
  func_001386e0(w1, 2800, a, b, 30, 11);
  w1->x18c = w0;
  Upd_w(w1);
  func_001386e0(w2, 2800, a, b, 35, 11);
  w2->x188 = 36;
  w2->x18c = 0;
  Upd_w(w2);
}

}
