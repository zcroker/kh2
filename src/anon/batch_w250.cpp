#include "../common/types.h"
extern "C" {
extern char D_0036b600[];
char* func_002ff2e8(char*, const char*);
char* func_002feee8(char*, const char*);
s32 func_002ff3fc(const char*);  // strlen
s32 func_002ffbe0(s32 c);
s32 func_0030e770(char*, u32, u32);
void wtarget_00167358(u32 a0, u32 a1, u32 a2, u32) asm("_Z16wtarget_00167358jjjj");
void wtarget_00167358(u32 a0, u32 a1, u32 a2, u32) {
  char buf[256];
  func_002ff2e8(buf, D_0036b600);
  func_002feee8(buf, (const char*)a0);
  s32 n0 = func_002ff3fc(D_0036b600);  // strlen
  s32 n = func_002ff3fc(buf);  // strlen
  for (s32 i = n0; i < n; i++) {
    char* p = &buf[i];
    if (*p == '/') *p = '\\';
    else *p = func_002ffbe0(*p);
  }
  while (func_0030e770(buf, a1, a2) < 0) {}
}

struct Q { u8 pad[0x588]; u32 f588; u8 pad2[0xac8-0x58c]; s32 fac8; s32 facc; };
struct Obj;
struct ObjVt { void* s[7]; void (*f7)(Obj*, void*); };
struct Obj { ObjVt* vt; };
struct P { s32 mode; Q* q; u8 pad[0x10]; Obj* obj; u8 pad2[8]; s32 x24; u8 pad3[4]; u32 x2c; };
Obj* func_0013e610(s32);
void func_00190388(void*, Q**);  // vec4_from_arg
void func_0013e520(Obj*, s32);
void func_0019d228(P*);
void func_0019d260(P* p) {
  u32 m = p->x2c & 1;
  if (m) {
    func_0019d228(p);
  } else {
    switch (p->mode) {
    case 2:
      if (!p->obj) p->obj = func_0013e610(p->x24 == 0 ? 27 : 23);
      break;
    case 1:
      if (!p->obj) p->obj = func_0013e610(p->x24 == 0 ? 5 : 1);
      break;
    default:
      func_0019d228(p);
      break;
    }
  }
  if (p->obj) {
    u8 buf[16] __attribute__((aligned(16)));
    func_00190388(buf, &p->q);  // vec4_from_arg
    p->obj->vt->f7(p->obj, buf);
    s32 flag = 0;
    Q* q = p->q;
    if (q->f588 & 2) {
      if (q->fac8 > 0 || q->facc > 0) flag = 1;
    }
    func_0013e520(p->obj, flag);
  }
}

static const float
half =  5.0000000000e-01f,
S1  = -1.666666567e-01f,
S2  =  8.3333337680e-03f,
S3  = -1.9841270114e-04f,
S4  =  2.755731202e-06f,
S5  = -2.5050759689e-08f,
S6  =  1.589690879e-10f;
f32 func_002fb460(f32 x, f32 y, s32 iy) {  // float_to_int
  f32 z, r, v;
  s32 ix;
  union { f32 f; s32 i; } u;
  u.f = x; ix = u.i;
  ix &= 0x7fffffff;
  if (ix < 0x32000000) { if ((s32)x == 0) return x; }
  z = x * x;
  v = z * x;
  r = S2 + z * (S3 + z * (S4 + z * (S5 + z * S6)));
  if (iy == 0) return x + v * (S1 + z * r);
  else return x - ((z * (half * y - v * r) - y) - v * S1);
}
}
