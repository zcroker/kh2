#include "../common/types.h"
extern "C" {

// ---- a.cpp
struct Gw2a63a0 { u8 pad[2]; s8 col; u8 pad3; u16 id; };
struct Rc2a63a0 { u8 pad[20]; s32 w; };
extern void *D_0035f200;
extern u8 *D_0035f224;
extern Gw2a63a0 *D_0035f5ec;
u8 *func_002766d0(void);
s32 func_0028b040(void *a);
void func_0014b950(void *p, s16 x, s16 y, u16 w, u16 c);
void func_0014b9a8(void *p);
s32 func_0023aa58(void *p);
s32 func_0023aa78(void *p);
Rc2a63a0 *func_001aae68(s32 a);
s32 func_00192048(u16 id);
void func_001a98e8(void *t, s32 a, s32 b, s32 c, s32 d);
void func_001aa6d0(void *t, s32 w);
void func_001a9ae8(void *t, s32 x, s32 y, s32 z);
void func_002a63a0(s32 x, s32 y, s32 z)
{
  u8 buf[96];
  s32 lo = 15;
  u8 *ent;
  s32 sc;
  s32 *new_var;
  s32 a;
  s32 b;
  ent = func_002766d0() + 24;
  sc = func_0028b040(D_0035f200);
  func_0014b950(D_0035f224 + 32, x, y, 512 - x, D_0035f5ec->col * 9);
  func_0014b9a8(D_0035f224 + 32);
  a = func_0023aa58(ent);
  b = func_0023aa78(ent);
  if (a)
  {
    lo = a;
  }
  sc *= b;
  {
    Rc2a63a0 *r = func_001aae68(3);
    b -= lo;
    y -= sc;
    b -= r->w;
  }
  if (b < 0)
  {
    b = 0;
  }
  func_001a98e8(buf, 3, func_00192048(D_0035f5ec->id), lo, 0);
  func_001aa6d0(buf, b);
  func_001a9ae8(buf, x, *(new_var = &y), z);
  func_0014b9a8(D_0035f224);
}

// ---- b3.cpp
extern u16 D_0035f090;
extern u16 D_0035f092;
extern u16 D_0035f096;
void func_0014cbe0(u32*, u32*, u32*, u32*);
void func_0028e560(s32, u16*, s32, s32);
void func_00258eb8_i(s32 a) asm("_Z13func_00258eb8i");
void func_00258eb8_i(s32 a)
{
  u16 buf[16];
  u32 h, m, s, f;
  s32 i, j, n;
  u16* p = buf;
  for (i = 8; i >= 0; i--) *p++ = D_0035f090;
  func_0014cbe0(&h, &m, &s, &f);
  n = 0;
  for (i = 0; i < 2; i++) {
    u32 v, lead; s32 nd;
    if (i == 0) { v = m; nd = 2; lead = *(volatile u32*)&h; } else { v = h; lead = 0; nd = 3; }
    if (i != 0) buf[n++] = D_0035f092;
    for (j = 0; j < nd; j++) {
      u32 r = v % 10;
      v = v / 10;
      if (i != 0 && j != 0 && r == 0 && v == 0 && lead == 0) break;
      buf[n++] = r + D_0035f096;
    }
    if (j < nd) break;
  }
  func_0028e560(a, buf, 9, -1);
}

// ---- c4.cpp
union UG_0028f280 { u8* p; u32 i; };
extern UG_0028f280 D_0035f480;
extern u32 D_0035f458;
extern u32 D_0035f45c;
extern u32 D_0035f460;
extern u16 D_0035f468[];
extern u16 D_0035f470[];
extern u16 D_0035f478[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
u32 func_00103570(void);
void* func_001063f0(u32, u32);
void func_00239700(u8*);
void func_0028d140(u8*);
struct Rec0028f280 {
    u8 a[436];
    u8 b[444];
    u32 f880;
    void* operator new[](unsigned int sz, u32 h) { return func_001063f0(sz, h); }
    inline Rec0028f280() __attribute__((always_inline));
    ~Rec0028f280() {}
};
inline Rec0028f280::Rec0028f280() {
        *(u32*)(a + 12) = 0;
        *(u32*)a = (u32)D_00347e60;
        func_00239700(a + 24);
        *(u32*)a = (u32)D_00347e40;
        *(u32*)(a + 408) = 0;
        func_0028d140(b);
}
void func_0028f280(u32 a, u32 b, u32 c, u16* d, u16* e)
{
    s32 k;
    D_0035f458 = a;
    D_0035f45c = b;
    D_0035f460 = c;
    D_0035f480.p = (u8*)new (func_00103570()) Rec0028f280[4];
    for (k = 0; k < 4; k++) ((Rec0028f280*)D_0035f480.p)[k].f880 = 0;
    for (k = 0; k < 3; k++) {
        D_0035f468[k] = d[k];
        D_0035f470[k] = d[k];
        D_0035f478[k] = e[k];
    }
}

// ---- g1.cpp
typedef void (*VFn26cc30)(u8*);
#define VCALL26cc30(p) (*(VFn26cc30*)(*(u8**)(p) + 20))(p)
extern u8* D_0035f0f4;
extern s32 D_0035f01c;
extern s32 D_0035f024;
s32 func_00287bc0(void);
u8* func_00256b68(s32);
s32 func_00139d78(u8*);
void func_00139510(u8*);
s32 func_0028acc8(s32);
void func_0028abe0(s32);
void func_00288e88(s32);
void func_0026c450(void);
void func_0026d828(void);
void Tz_CmParty_LeaveList_26cc30(void) asm("_ZN2Tz7CmParty9LeaveListEv");
void Tz_CmParty_LeaveList_26cc30(void)
{
    s32 i;
    if (func_00287bc0() == 20) {
        u8* o = func_00256b68(1);
        if (func_00139d78(o)) VCALL26cc30(o);
        if (func_00139d78(D_0035f0f4)) func_00139510(D_0035f0f4);
        for (i = 0; i < 4; i++) {
            if (func_00139d78(D_0035f0f4 + i * 408 + 408)) VCALL26cc30(D_0035f0f4 + i * 408 + 408);
        }
        for (i = 0; i < 4; i++) {
            if (func_00139d78(D_0035f0f4 + i * 436 + 2040)) VCALL26cc30(D_0035f0f4 + i * 436 + 2040);
        }
        if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
        if (func_0028acc8(D_0035f024)) func_00288e88(D_0035f024);
        func_0026c450();
        func_0026d828();
    }
}
}
