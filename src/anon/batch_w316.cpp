#include "../common/types.h"

struct I1E { u16 id; u16 h2; };
struct I1 { u8 b0; u8 b1; u8 n; u8 b3; I1E e[4]; u8 pad20[2]; s16 h22; u32 w24; };
extern "C" {
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036eb60[];
extern char D_0036eb90[];
extern char D_0036ebc8[];
extern char D_0036ebf0[];
extern char D_0036ec18[];
u32 func_002fdfc8(const char*, ...);  // device_vprintf_va
s32* func_001e3650(void*);  // ptr_add4
s32* func_001e3660_x(s32*, s32) asm("_Z13func_001e3660ji");
static inline void assert_fail_1e3690(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
s32 func_001e3690(u8* o) {
  s32 r = 0;
  s32* p;
  u8 idx;
  p = (s32*)*(void**)(o + 136);
  idx = o[147];
  p = func_001e3650(p);  // ptr_add4
  s32 n = *p++;
  s32 i;
  for (i = 0; i < n; i++, p++) {
    if (idx == i) { s32 v = *p; *(s32*)(o + 140) = v; r = v + 272; }
  }
  s32* q;
  q = func_001e3660_x(p, 4);
  if (q[0] == -1) goto none;
  if (q[0] < 12288) assert_fail_1e3690(D_0036eb60, D_0036e9d0, 822);
  s32 a, b;
  a = (q[1] - 12161) / 128;
  if (q[2] < 15872) assert_fail_1e3690(D_0036eb90, D_0036e9d0, 827);
  if (!(q[3] <= 16384)) assert_fail_1e3690(D_0036ebc8, D_0036e9d0, 828);
  b = (q[3] - 15841) / 32;
  if (!(a < 35)) assert_fail_1e3690(D_0036ebf0, D_0036e9d0, 833);
  if (!(b < 21)) assert_fail_1e3690(D_0036ec18, D_0036e9d0, 834);
  o[145] = a;
  o[146] = b;
  return r;
none:
  o[145] = 0; o[146] = 0;
  return r;
}

extern u32 D_0035f118;
#define G118 ((I1*)D_0035f118)
extern u32 D_0035f104;
extern u32* D_0035f11c;
extern u32 D_0035f100;
extern u32 D_0035f10c;
extern u16* D_0035f114;
extern s8 D_0035f120;
void func_0026e140(s32, s32, s32);
void gspxy_x(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void SetDisableButton_x(void*, u32) asm("_ZN2Tz6Select16SetDisableButtonEj");
u8* func_0028c198(s32, s32, s32, u32, u32, u32);
void func_00288ce0(void*, void*, s32, s16*, s16*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0026df30(void) {
  s16 a[4];
  s16 b[4];
  s32 i, n, k;
  if (G118->h22 >= 0) func_0026e140(0, G118->h22, -1);
  if (G118->w24) {
    func_0026e140(1, 14, -1);
    gspxy_x((u8*)D_0035f104 + 436);
    *(u32*)((u8*)D_0035f104 + 868) = 3;
    *(u32*)((u8*)D_0035f104 + 844) = G118->w24;
  }
  if (D_0035f11c && *D_0035f11c) func_0026e140(2, 13, -1);
  for (i = 0; i < 4; i++) { a[i] = 12; b[i] = 11; }
  n = G118->n;
  k = 0;
  for (i = 0; i < n; i++) {
    if (G118->e[i].id) {
      u8* v = func_0028c198(12, 0, 0, D_0035f100, G118->e[i].h2, 0);
      gspxy_x(v);
      *(u32*)(v + 432) = 2;
      func_00288ce0((void*)D_0035f10c, v, k, a, b);
      D_0035f114[k++] = G118->e[i].id;
    }
  }
  if (k) {
    s32 x = D_0035f120;
    func_002891f0((void*)D_0035f10c, x < 0 ? 0 : x, 1, 2, 2);
  } else {
    SetDisableButton_x((void*)D_0035f10c, 16);
  }
}

void setOffsetPos_x(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 u_call4_00139d78_x(void*) asm("_Z16u_call4_00139d78jjjj");
s32 GetParamEx_x(void*) asm("_ZN2YI8SEQUENCE10GetParamExEv");
u8* GetItemPtr_x(void*, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 GetItemMax_x(void*) asm("_ZN2Tz6Select10GetItemMaxEv");
void func_0026e3b0(void) {
  s32 w[11];
  s32 i, k, n, sum, x;
  for (i = 0; i < 11; i++) w[i] = 0;
  k = 0;
  for (i = 0; i < 3; i++) {
    if (u_call4_00139d78_x((u8*)D_0035f104 + i * 436)) {
      w[k] = GetParamEx_x((u8*)D_0035f104 + i * 436 + 24);
      k++;
    }
  }
  n = GetItemMax_x((void*)D_0035f10c);
  for (i = 0; i < n; i++) {
    w[k] = GetParamEx_x(GetItemPtr_x((void*)D_0035f10c, i) + 24);
    k++;
  }
  if (k < 2) return;
  sum = 0;
  for (i = 0; i < 11; i++) sum += w[i];
  x = -(sum / 2);
  k = 0;
  for (i = 0; i < 3; i++) {
    if (u_call4_00139d78_x((u8*)D_0035f104 + i * 436)) {
      setOffsetPos_x((u8*)D_0035f104 + i * 436, 0, x);
      x += w[k];
      k++;
    }
  }
  for (i = 0; i < n; i++) {
    setOffsetPos_x(GetItemPtr_x((void*)D_0035f10c, i), 0, x);
    x += w[k];
      k++;
  }
}

}
