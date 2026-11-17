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
void func_00239700(S239* p) asm("_ZN2YI8SEQUENCEC1Ev");  // YI::SEQUENCE::SEQUENCE
void func_00239700(S239* p);  // 0x00239700: definition moved into src/anon/unit_002384f8.cpp
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
void func_002b4c88(void* p);  // 0x002b4c88: definition moved into src/anon/unit_002b3ac8.cpp
extern char D_00362dc8[];
extern char D_00375eb8[];
extern char D_00362d90[];
extern u8* D_0034e948;
void func_002ce958(void*, s32, u32, s32);
void func_002e34b8(void*);
void func_002ceae8(void*, char*, char*);
u32 func_001708f8(char*, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
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
void func_002e0be0(S2e0* p, u32 a1);  // 0x002e0be0: definition moved into src/anon/unit_002de3c8.cpp
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
// 00186740: moved to src/anon/unit_00185d10.cpp
void func_00186740(u8* p, V186* v, u32 a2, u32 a3, f32 y, f32 w);
}
