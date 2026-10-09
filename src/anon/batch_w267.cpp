#include "../common/types.h"
extern "C" {
extern char D_0035eaf8[];
void func_00237068(void*);
struct S239 {
  void* vt; char pad[172];
  u32 a176; u32 a180;
  u32 b0:1; u32 b1:1; u32 b2:1; u32 b3:1; u32 b4:1; u32 b5:1; u32 b6:1; u32 b7:1;
  u32 b8:1; u32 b9:1; u32 b10:1; u32 b11:1; u32 b12:1; u32 b13:1; u32 rest:18;
  u8 c188; char p1[3];
  u32 a192, a196, a200, a204, a208;
  u8 c212; char p2[3];
  u32 a216, a220, a224, a228, a232, a236, a240, a244, a248, a252, a256, a260, a264, a268, a272, a276, a280, a284, a288, a292, a296, a300, a304, a308, a312, a316, a320, a324, a328, a332;
};
void func_00239700(S239* p) {
  func_00237068(p); p->vt = D_0035eaf8;

  p->a176 = 0; p->a180 = 0; p->b0 = 0; p->c188 = 0; p->b1 = 0;
  p->a192 = 0; p->a196 = 0; p->b2 = 0; p->a200 = 0; p->a204 = 0; p->b3 = 0;
  p->a208 = 0; p->c212 = 0; p->b4 = 0; p->a216 = 0; p->a220 = 0; p->b5 = 0;
  p->a224 = 0; p->a228 = 0; p->b6 = 0; p->a232 = 0; p->a236 = 0; p->b7 = 0;
  p->a240 = 0; p->a244 = 0; p->b8 = 0; p->a248 = 0; p->a252 = 0; p->b9 = 0;
  p->a256 = 0; p->a260 = 0; p->b10 = 0; p->a264 = 0; p->a268 = 0; p->b11 = 0;
  p->a272 = 0; p->a276 = 0; p->b12 = 0; p->a280 = 0; p->a284 = 0; p->b13 = 0;
  p->a288 = 0; p->a292 = 0; p->a296 = 0; p->a300 = 0;
  p->a304 = 0; p->a308 = 0; p->a312 = 0; p->a316 = 0; p->a320 = 0; p->a324 = 0; p->a328 = 0; p->a332 = 0;
}
extern u32 D_0035f650;
extern u32 D_0035f654;
extern u32 D_0035f644;
extern u32 D_0035f640;
extern u32 D_0035f664;
extern u32* D_0035f6cc;
void func_002b6418(void*);
void func_00259108(u32, s32, u32, u32, u32, void*, u32);
void func_00288f48(u32, s32, s32, s32, s32);
void func_0028af28(u32, s32);
s32 func_00139d78(u32);
s32 func_002892f8(u32);
u32 func_002891b8(u32, s32);
void func_0028dcc0(u32, u32);
void func_00138c78(u32, s32*, s32*);
s32 func_0023aa18(u32);
s32 func_0023aa38(u32);
void func_00138c68(u32, s32, s32);
void func_002b4c88(void* p) {
  s32 pos[2];
  func_002b6418(p);
  func_00259108(D_0035f650, 30064, D_0035f644, D_0035f640, D_0035f664, p, D_0035f6cc[4]);
  func_00288f48(D_0035f650, 128, 64, 0, 0);
  func_0028af28(D_0035f650, 64);
  if (func_00139d78(D_0035f654)) {
    s32 i = 0;
    while (i < func_002892f8(D_0035f650)) {
      func_0028dcc0(func_002891b8(D_0035f650, i), D_0035f654);
      func_00138c78(func_002891b8(D_0035f650, i), &pos[0], &pos[1]);
      pos[0] += func_0023aa18(D_0035f654 + 24);
      pos[1] += func_0023aa38(D_0035f654 + 24);
      func_00138c68(func_002891b8(D_0035f650, i), pos[0], pos[1]);
      i++;
    }
  }
}
extern char D_00362dc8[];
extern char D_00375eb8[];
extern char D_00362d90[];
extern u8* D_0034e948;
void func_002ce958(void*, s32, u32, s32);
void func_002e34b8(void*);
void func_002ceae8(void*, char*, char*);
u32 func_001708f8(char*, s32);
u8* func_00168b38(u32, s32, s32);
void func_002e34c0(void*, u32);
u32 func_001050c8(void);
void* func_001063c0(s32, u32);
void func_002e6fc0(void*, u32);
void func_00102c80(void);
void func_002e1020(void*);
void func_002cedd0(s32, char*);
void func_0016bd60(u8*, s32);
u8* func_0016b740(s32);
struct S2e0 {
  void* vt; char pad[84];
  u8 f88; char pad2[7];
  u32 f96; u32 pad3;
  char f104[4];
  u32 f108;
  void* f112;
};
void func_002e0be0(S2e0* p, u32 a1) {
  char buf[64];
  u8* o;
  void* n;
  u32 v;
  func_002ce958(p, 4, a1, 0);
  p->vt = D_00362dc8;
  func_002e34b8(p->f104);
  p->f108 = 0;
  func_002ceae8(p, buf, D_00375eb8);
  v = func_001708f8(buf, -1);
  p->f96 = v;
  func_002e34c0(p->f104, *(u32*)(func_00168b38(v, 42, 0) + 8));
  p->f108 = *(u32*)(func_00168b38(v, 42, 1) + 8);
  n = func_001063c0(12, func_001050c8());
  func_002e6fc0(n, p->f108);
  p->f112 = n;
  func_00102c80();
  func_002e1020(p);
  func_002cedd0(3, D_00362d90);
  o = D_0034e948;
  func_0016bd60(o, 24);
  *(u32*)(o + 264) |= 1;
  o = func_0016b740(1514);
  func_0016bd60(o, 25);
  *(u32*)(o + 264) |= 1;
  p->f88 = 1;
}
f32* func_002e4588(f32* m, f32* q) {
  m[0] = 1.0f - (q[1] * q[1] + q[2] * q[2]) * 2.0f;
  m[1] = (q[0] * q[1] + q[3] * q[2]) * 2.0f;
  m[2] = (q[0] * q[2] - q[3] * q[1]) * 2.0f;
  m[3] = 0.0f;
  m[4] = (q[0] * q[1] - q[3] * q[2]) * 2.0f;
  m[5] = 1.0f - (q[0] * q[0] + q[2] * q[2]) * 2.0f;
  m[6] = (q[1] * q[2] + q[3] * q[0]) * 2.0f;
  m[7] = 0.0f;
  m[8] = (q[0] * q[2] + q[3] * q[1]) * 2.0f;
  m[9] = (q[1] * q[2] - q[3] * q[0]) * 2.0f;
  m[10] = 1.0f - (q[0] * q[0] + q[1] * q[1]) * 2.0f;
  m[11] = 0.0f;
  m[12] = 0.0f;
  m[13] = 0.0f;
  m[14] = 0.0f;
  m[15] = 1.0f;
  return m;
}
#define QCOPY267(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV267 {
  f32 x, y, z, w;
  QV267() {}
  QV267(const QV267& o) { QCOPY267(this, &o); }
  QV267& operator=(const QV267& o) {
    if (this != &o) QCOPY267(this, &o);
    return *this;
  }
} __attribute__((aligned(16)));
static inline QV267 ScaleQ267(const QV267& a, f32 k) {
  QV267 r;
  asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
  return r;
}
struct V186 { QV267 v; s32 pad[2]; u32 f24; };
s32 func_001860b0(u8*, V186*, u32, u32);
void func_0016aef0(u8*, QV267*);
void func_0017f488(u8*, u32, f32, f32);
void func_00186888(u8*, QV267*);
s32 func_0018cac0(V186*);
void func_001bfcc8(u8*, s32);
void func_00186740(u8* p, V186* v, u32 a2, u32 a3, f32 y, f32 w) {
  QV267 c;
  QV267 b;
  u32 m;
  if (func_001860b0(p, v, a2, a3)) {
    m = a2;
    b = ScaleQ267(v->v, -1.0f);
  } else {
    m = a3;
    b = v->v;
  }
  func_0016aef0(p, &b);
  c = v->v;
  c.y = y;
  c.w = w;
  func_0017f488(p + 320, m, 0.0f, 0.0f);
  func_00186888(p, &c);
  if (func_0018cac0(v)) *(u32*)(p + 268) |= 0x20000;
  v->f24 |= 1;
  if (*(u32*)(p + 1416) & 0x80) func_001bfcc8(p, 1);
}
}
