#include "../common/types.h"
struct V2c {
  f32 x, y, z, w;
  V2c() {}
  V2c(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
  V2c& operator=(const V2c& o) {
    if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    return *this;
  }
} __attribute__((aligned(16)));
struct Box2c { V2c a, b; };
struct Mat2c { V2c r[4]; };
extern "C" {
void func_001444c8(Box2c*, V2c*, V2c*);
void func_0011b6a8(Mat2c*);
void func_001449a8(Box2c*, Mat2c*);
s32 func_002cec08(void*, Box2c*);
extern void* D_00361f60;
u8 func_002cef80(void* a0, V2c* pos) {
  V2c lo(-100.0f, -100.0f, -100.0f, 0.0f);
  V2c hi(100.0f, 100.0f, 100.0f, 0.0f);
  Box2c box;
  Mat2c m;
  V2c* r3 = &m.r[3];
  func_001444c8(&box, &lo, &hi);
  func_0011b6a8(&m);
  *r3 = *pos;
  m.r[3].w = 1.0f;
  func_001449a8(&box, &m);
  return func_002cec08(D_00361f60, &box) != 0;
}
// register pins reproduce the original's counter/temp allocation
struct Hdr1e { s16 a; s16 b; s16 c; s16 fmt; u8 pad[16]; s32 off; };
Hdr1e** func_001e4248(s32* p) {
  register s32 n asm("$15") = p[0];
  Hdr1e** h = (Hdr1e**)(p + 1);
  register s32 i asm("$10");
  if (n > 0) for (i = n; i != 0; i--) {
    s32 cnt = 0;
    Hdr1e* t = *h++;
    u8* d = (u8*)t + t->off + 32;
    if (t->b == 0) continue;
    switch (t->fmt) {
    case 19: cnt = 256; break;
    case 20: cnt = 16; break;
    }
    for (; cnt != 0; cnt--) {
      s32 v = (s32)(d[0] * 0.3f + d[1] * 0.59f + d[2] * 0.11f);
      d[2] = v; d[1] = v; d[0] = v;
      d += 4;
    }
  }
  return h;
}
}
