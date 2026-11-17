#include "../common/types.h"
extern "C" {
extern char D_0036b600[];
char* func_002ff2e8(char*, const char*);
char* func_002feee8(char*, const char*);
s32 strlen(const char*);  // strlen
s32 toupper(s32 c);
s32 func_0030e770(char*, u32, u32);
void wtarget_00167358(u32 a0, u32 a1, u32 a2, u32) asm("_Z16wtarget_00167358jjjj");
// 00167358: moved to src/anon/unit_00167358.cpp

struct Q { u8 pad[0x588]; u32 f588; u8 pad2[0xac8-0x58c]; s32 fac8; s32 facc; };
struct Obj;
struct ObjVt { void* s[7]; void (*f7)(Obj*, void*); };
struct Obj { ObjVt* vt; };
struct P { s32 mode; Q* q; u8 pad[0x10]; Obj* obj; u8 pad2[8]; s32 x24; u8 pad3[4]; u32 x2c; };
Obj* func_0013e610(s32);
void func_00190388(void*, Q**);  // vec4_from_arg
void func_0013e520(Obj*, s32);
void func_0019d228(P*);
void func_0019d260(P* p);  // 0x0019d260: definition moved into src/anon/unit_0019ba60.cpp

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
