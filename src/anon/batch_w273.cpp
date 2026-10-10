#include "../common/types.h"
struct V4w273 {
  f32 x, y, z, w;
  V4w273& operator=(const V4w273& o) {
    if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory");
    return *this;
  }
} __attribute__((aligned(16)));
struct Src273 { V4w273* v[4]; s32 n; };
extern char D_0036e978[];
extern char D_0036ed60[];
extern char D_0036e9d0[];
extern char D_0036e998[];
extern char D_0036ed78[];
extern char D_0036ed98[];
extern u8 D_00354bf0[];
extern s32 D_00352c38;
#define ASSERT(c, s, l) if (!(c)) assert_fail_1e4f40(s, D_0036e9d0, l)
struct Obj273;
struct Obj273Vt { void* p[6]; void (*f6)(Obj273*, s32, u32, s32, s32, s32, s32); };
struct Obj273 { Obj273Vt* vt; };
struct Pair273 { u32 a; s32 b; };
extern s32 D_0035f3d4;
extern Pair273* D_0035f11c;
extern s32 D_0035f108;
extern s32 D_0035f100;
struct N273 { u8 pad[36]; s32 f36; s32 f40; u32 f44; u32 f48; u8 pad2[8]; N273* next; };
extern u32 D_0034dc9c;
extern N273* D_0034dca0;
extern u32 D_0034dcb0;
extern u32 D_01c5f460[];
extern u8 D_004fa440[];
typedef unsigned long long u64_273 __attribute__((mode(DI)));
struct Ent273 { s8 id; s8 w; };
struct Tbl273 { u8 pad[4]; Ent273 e[5]; };
extern u32 D_003638d0;
struct SE273 { u32 w; u8 pad[28]; };
struct Sub273 { u8 pad[28]; s32 n; SE273 e[1]; };
struct Own273 { u8 pad[4]; Sub273* sub; };
extern "C" {
void func_001626e0(Src273* p, V4w273* m) {
  if (p->n == 3) {
    m[0] = m[3] = m[6] = *p->v[0];
    m[1] = m[4] = m[7] = *p->v[1];
    m[2] = m[5] = *p->v[2];
  } else {
    m[0] = m[4] = *p->v[0];
    m[1] = m[5] = *p->v[1];
    m[2] = m[6] = *p->v[2];
    m[3] = m[7] = *p->v[3];
  }
  m[0].w = m[1].w = m[2].w = m[3].w = m[4].w = m[5].w = m[6].w = m[7].w = 1.0f;
}

s32 func_002fdfc8(const char*, ...);  // device_vprintf_va
void func_001e3898(void*, void*);
s32* func_001e3650(void*);  // ptr_add4
void func_001e8180(s32, void*);
void func_001e4f00(void*);
static inline void assert_fail_1e4f40(const char* e, const char* f, s32 l) {
  func_002fdfc8(D_0036e978, e);  // device_vprintf_va
  func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
  asm volatile("break");
}
void func_001e4f40(void* p) asm("_Z13func_001e4f40Pv");
void func_001e4f40(void* p) {
  struct NoTail { ~NoTail(){} } nt;
  ASSERT(p, D_0036ed60, 1389);
  ASSERT(((u32)p & 0xf) == 0, D_0036ed78, 1390);
  func_001e3898(p, p);
  s32* q = func_001e3650(p);  // ptr_add4
  s32 n = *q;
  s32 i;
  q++;
  for (i = 0; i < n; i++) {
    s32 x = *q++;
    ASSERT((x & 0xf) == 0, D_0036ed98, 1422);
    func_001e8180(x, D_00354bf0);
  }
  if (D_00352c38) func_001e4f00(p);
}

void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
Obj273* func_00287dc0(void);
void func_0023d808(Obj273*, s32);
void func_0023e5d0(Obj273*, s32, s32);
void func_0023e858(Obj273*, s32, f32);
void func_0023e8b8(Obj273*, s32, f32);
void func_0023e8d8(Obj273*, s32, f32);
void func_0023e9c8(Obj273*, s32, s32);
void func_0026e1e0(void) {
  s32 n = D_0035f3d4 - 1;
  if (D_0035f11c == 0 || D_0035f11c->a == 0 || D_0035f11c->b == 0) return;
  func_0028d8c0(D_0035f108, n, 0, 0, D_0035f100, 16, 17, 0);
  Obj273* o = func_00287dc0();
  func_0023d808(o, n);
  o->vt->f6(o, 0, D_0035f11c->a | 0x20000000, -1, 2, 0, 0);
  func_0023e5d0(o, 0, D_0035f11c->b);
  func_0023e858(o, 0, -100.0f);
  func_0023e8b8(o, 0, 0.0f);
  func_0023e8d8(o, 0, 0.0f);
  func_0023e9c8(o, 0, D_0035f108);
}

void func_001705a8(void);
s32 func_00170d38(s32);
void func_001700e8(N273*, s32);
void func_00170670(void) {
  u32 a[7];
  s32 i;
  s32 n = 0;
  func_001705a8();
  for (i = 1; i < 7; i++) a[i] = 0;
  a[0] = (u32)D_004fa440;
  u32 lim = D_0034dc9c;
  N273* p = D_0034dca0;
  while (p) {
    s32 t = p->f40;
    p->f36 = 0;
    N273* nx = p->next;
    if (t >= 0) {
      s32 k = func_00170d38(t);
      if (a[k] == 0) {
        a[k] = a[0];
        a[0] += D_01c5f460[k];
      }
      p->f48 = a[k];
      a[k] += p->f44;
      if (a[0] < a[k]) a[0] = a[k];
      u8 big = p->f40 >= 10000;
      if (big) {
        if (lim < a[k] || n >= 128) func_001700e8(p, 0);
      }
    } else {
      lim -= p->f44;
      p->f48 = lim;
    }
    p = nx;
    n++;
  }
  D_0034dcb0 = lim;
}

u64_273 func_00312db8(u64_273, u64_273);
s32 func_001b0148(void*, s32, s32, s32);
static inline u32 rnd273(void) {
  D_003638d0 = D_003638d0 * 0x10dcd;
  return D_003638d0;
}
s32 func_001affe0(Tbl273* t, s32 a1, s32 a2) {
  s32 out[5];
  s32 cnt = 0;
  s32 i = 0;
  s32 pct = func_00312db8(rnd273(), 0x28f5c29);
  u8* e = (u8*)t;
  s32* o = out;
  for (; i < 5; i++, e += 2) {
    s32 r = func_001b0148(t, a1, (s8)e[4], a2);
    if (r >= 0) {
      if ((s8)e[5] > 0) {
        pct -= (s8)e[5];
        if (pct < 0) return r;
      } else {
        *o++ = r;
        cnt++;
      }
    }
  }
  if (cnt > 0) {
    u32 s = rnd273();
    u64_273 d = func_00312db8((u64_273)(u32)(cnt - 1) + 0x100000000ULL, (u32)cnt);
    return out[(s32)func_00312db8(s, d)];
  }
  return -1;
}

Sub273* func_00120800(Own273*);  // obj_get_sub_ptr_by12
void func_0011efe8(Own273*, u8*);
void func_00121218(Own273* o, u8* fl, u16* list) {
  Sub273* a = o->sub;
  Sub273* b = func_00120800(o);  // obj_get_sub_ptr_by12
  s32 i;
  func_0011efe8(o, fl);
  while ((s16)*list != -1) {
    s16 m = *list & 0x8000;
    u8 bit = m ? 2 : 1;
    for (i = 0; i < a->n; i++)
      if (((a->e[i].w >> 6) & 0x1f) == (u32)(*list & 0x7fff)) fl[i] |= bit;
    if (b)
      for (i = 0; i < b->n; i++)
        if ((b->e[i].w & 0x1f) == (u32)(*list & 0x7fff)) fl[a->n + i] |= bit;
    list++;
  }
}
}
