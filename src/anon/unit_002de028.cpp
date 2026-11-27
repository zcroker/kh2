// 002de028 S67 2026-11-27: MATCH (0 words). From S62 draft; fix = arg var x reused for func_002de968 result, branch-3 split subtraction.
namespace n002de028 {

typedef unsigned char bool__;
typedef struct Cfg Cfg;
typedef struct P P;
typedef struct Prm Prm;
typedef struct Ref Ref;
typedef struct V V;
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;
typedef struct V V;
struct V
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} __attribute__((aligned(16)));
inline static void vcpy(V *d, const V *s)
{
  asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

inline static void vset(V *d, const V *s)
{
  if (d != s)
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

inline static V vsub(const V *a, const V *b)
{
  V r;
  asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(a), "r"(b) : "memory");
  return r;
}

inline static V vadd(const V *a, const V *b)
{
  V r;
  asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(a), "r"(b) : "memory");
  return r;
}

inline static void vaddeq(V *a, const V *b)
{
  asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "r"(b) : "memory");
}

inline static void vmuleq(V *a, f32 s)
{
  asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(s) : "$8", "memory");
}

inline static f32 vnorm(V *a)
{
  f32 r;
  asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(a) : "$8", "memory");
  return r;
}

typedef struct Prm Prm;
struct Prm
{
  u8 p0[6];
  s16 ang;
  s16 time;
  u8 pa[2];
  u16 kind;
  u8 pe[6];
  s16 f20;
};
typedef struct Ref Ref;
struct Ref
{
  u8 p0[4];
  f32 x;
  f32 y;
  f32 z;
  u8 p10[20];
  f32 ang;
};
typedef struct Cfg Cfg;
struct Cfg
{
  u8 p0[124];
  f32 spd[4];
  u8 p8c[36];
  f32 f176;
};
typedef struct P P;
struct P
{
  u8 p0[264];
  u32 f264;
  u32 f268;
  u8 p110[1344 - 272];
  V pos;
  u8 p550[2800 - 1360];
  u8 st[8];
  Prm *prm;
  Ref *r2812;
  Ref *r2816;
  u8 pb04[2844 - 2820];
  u8 b2844;
  u8 pb1d[3];
  f32 time;
  f32 spd;
  u8 pb28[8];
  V dir;
  V start;
  f32 t1;
  f32 f2900;
  u8 pb58[8];
  V v2912;
  f32 f2928;
  u8 b2932;
  u8 pb75[11];
  V v2944;
  V v2960;
  V v2976;
  u8 pbb0[3056 - 2992];
  f32 f3056;
  f32 f3060;
};
extern void *D_00361f60 asm("D_00361f60");
extern f32 D_00349e10 asm("D_00349e10");
s32 lflag_check(u8 *, u32) asm("_ZN2Ti5LFlag5checkEj");
void lflag_set(u8 *, s32, s32) asm("_Z16wtarget_002cf280jjjj");
f32 sinf(f32) asm("sinf");
Cfg *config(void *) asm("_ZN2Ti6MGJump6configEv");
void func_0016a9a0(P *) asm("func_0016a9a0");
void func_0016ac38(P *, s32, s32, s32, s32) asm("func_0016ac38");
f32 func_002de968(f32) asm("func_002de968");
void func_002de028(P *o) asm("func_002de028");
void func_002de028(P *o)
{
  void *g;
  V *pos;
  f32 lim, len, t, t1, f, x;
  func_0016a9a0(o);
  g = D_00361f60;
  if (g == 0) return;
  pos = &o->pos;
  V p0;
  vcpy(&p0, pos);
  if (o->prm == 0) return;
  if (lflag_check(o->st, 4)) return;
  if (lflag_check(o->st, 8)) {
    o->f3060 -= config(g)->f176 * D_00349e10;
    if (o->f3060 < 0.0f) o->f3060 = 0.0f;
    o->pos.y += o->f3060 * D_00349e10;
    return;
  }
  if (o->b2844 != 0) {
    t = o->f3056;
    t1 = o->t1;
    if (t < t1) {
      V d;
      vcpy(&d, &o->dir);
      vmuleq(&d, o->time * t);
      V *q = &o->v2960;
      V s = vadd(&o->start, &d);
      vset(q, &s);
    } else if (t < t1 + o->f2928) {
      f = t - t1;
      vset(&o->v2960, &o->v2912);
      x = f / o->f2928 * 2.0f * 3.1415927f * o->f2900;
      x = func_002de968(x);
      f = sinf(x) * o->spd * 0.5f;
      t = o->v2960.x;
      o->v2960.x = o->b2932 ? t + f : t - f;
    } else {
      t1 = t - t1;
      t1 -= o->f2928;
      V d;
      vcpy(&d, &o->v2944);
      vmuleq(&d, o->time * t1);
      V *q = &o->v2960;
      V s = vadd(&o->v2912, &d);
      vset(q, &s);
    }
    lim = o->time * D_00349e10 * 1.5f;
  } else {
    V d;
    vcpy(&d, &o->v2976);
    vmuleq(&d, d.w * D_00349e10);
    vaddeq(&o->v2960, &d);
    o->v2960.z = 0.0f;
    lim = o->v2976.w * D_00349e10 * 1.5f;
  }
  V d = vsub(&o->v2960, pos);
  len = vnorm(&d);
  if (600.0f < len) {
    func_0016ac38(o, 0, 1, 0, 0);
    lflag_set(o->st, 4, 0);
    lflag_set(o->st, 0x4000, 0);
  }
  if (lim < len) len = lim;
  vmuleq(&d, len);
  vaddeq(pos, &d);
  o->f3056 += D_00349e10;
}

}
