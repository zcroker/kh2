#include "../common/types.h"

extern "C" {
/* 0031a790 */
extern char D_00347d70[]; extern char D_00347f98[];
void func_0031a508(void*);
void func_0031a3d8(void*);
void func_0031a790(char* t) {
  *(char**)t = D_00347d70;
  if ((u32)(t + 10692) != 0xfffffff8u) {
    char* s0 = t + 18316;
    char* s1 = t + 10700;
    l1: if (s1 == s0) goto o1;
    s0 -= 476; func_0031a508(s0); goto l1;
  }
  o1:
  if ((u32)(t + 48) != 0xfffffff0u) {
    char* s0 = t + 10688;
    char* s1 = t + 64;
    l2: if (s1 == s0) goto o2;
    s0 -= 1328; func_0031a3d8(s0); goto l2;
  }
  o2:
  *(char**)t = D_00347f98;
}

/* 002bea88 */
extern u8 D_00361898;
struct W230Z { char p[0x4c]; f32 f; };
extern W230Z* D_00352130;
void func_002be6f0(void);
void func_001c8e90(void);
void* func_002c6218(void);
void func_002c6190(void*);
void* func_001050d8(int);
void func_002bf098(void*);
void func_00191bf0(f32);
void func_00191c30(f32);
void func_002c1dc0(void);
void func_002c1750(void);
void func_002bf9d8(int);
void func_002bea88(void) {
  D_00361898 = 1;
  f32 k = 4.0f;
  func_002be6f0();
  func_001c8e90();
  func_002c6190(func_002c6218());
  func_002bf098(func_001050d8(160));
  func_00191bf0(k);
  func_00191c30(D_00352130->f * k + 500.0f);
  func_002c1dc0();
  func_002c1750();
  func_002bf9d8(0);
}

/* 00176dd8 */
union W230U16 { u16 h; u8 c; };
struct W230T { char p[0xb2c]; W230U16 h2c; u16 h2e; void* w30; };
struct W230A { char p[4]; u16 h4; };
void* func_0016a070(void*);
void func_0017f488(void*, int, f32, f32);
void func_0017f5e0(void*, int, int, f32, f32);
void func_00176dd8(W230T* t, W230A* a1, void** a2, u32 a3) {
  t->h2c.h = a1->h4;
  if (*a2) t->w30 = func_0016a070(*a2); else t->w30 = 0;
  t->h2e = a3;
  func_0017f488((char*)t + 320, 9, 8.0f, 0.0f);
  func_0017f5e0((char*)t + 320, 0, 0, 0.0f, 0.0f);
}
}
