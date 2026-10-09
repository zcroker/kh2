#include "../common/types.h"

struct NoTail_w256 { ~NoTail_w256() {} };
struct E27 { s8 a; u8 x; s8 b; u8 y; s8 c; u8 z[3]; };
struct T27 { u8 hdr[14]; E27 e[1]; };
struct I27 { u8 p[5]; u8 b5; u8 q[2]; };
struct H2d { u8 p[152]; s32 i152; };
struct R2d { u8 p[28]; f32 f28; };
struct C2d { u8 p[320]; u8 mo[1]; };
struct A2d { u8 p[320]; u8 mo[3056-320]; void* p3056; C2d* p3060; f32 f3064; u8 q[4]; f32 f3072; };
struct M256 { u8 pad[20]; s32 i20; s32 i24; u32 i28; };

extern "C" {
s32 func_0017ec98(M256*, s32);
s32 func_0017ebc8(M256*);
s32 func_0017f178(M256*, s32, f32, f32);
u32 mo_start_num_w256(M256*, s32) asm("_ZN2YS6MOTION9start_numEiff");
s32 mo_is_exist_w256(M256*, s32) asm("_ZN2YS6MOTION8is_existEi");
s32 mo_push_w256(M256*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");

s32 func_0017f268(M256* m, s32 a1, f32 x, f32 y) {
  s32 k = func_0017ec98(m, a1);
  if (func_0017ebc8(m) && !a1) {
    u32 v = mo_start_num_w256(m, k);
    u32 t = m->i28;
    if ((t < 2 && v - 2 < 2) || (t - 2 < 2 && v < 2)) {
      if (mo_is_exist_w256(m, 6)) {
        func_0017f268(m, 6, 0.0f, 0.0f);
        mo_push_w256(m, 0, 0.0f, 0.0f, 0);
        goto one;
      }
    }
  }
  if (!func_0017f178(m, k, x, y)) return 0;
  m->i20 = a1;
one:
  return 1;
}


extern u32 D_0035ee60, D_0035ee68, D_0035ee6c, D_0035ee7c, D_0035ee78, D_0035ee80;
extern u32 D_0035ee70, D_0035ee74, D_0035ee58, D_0035ee5c;
s32 call4_w256(u32) asm("_Z16u_call4_00139d78jjjj");
s32 iscreated_w256(u32) asm("_ZN2Tz6Select9isCreatedEz");

void func_00250fb8(void) {
  NoTail_w256 nt;
  if (call4_w256(D_0035ee60)) return;
  if (call4_w256(D_0035ee68)) return;
  if (call4_w256(D_0035ee6c)) return;
  if (call4_w256(D_0035ee7c)) return;
  if (call4_w256(D_0035ee78)) return;
  if (call4_w256(D_0035ee80)) return;
  for (s32 i = 0; i < 4; i++) {
    if (call4_w256(D_0035ee70 + i * 432)) return;
    if (call4_w256(D_0035ee74 + i * 432)) return;
  }
  if (iscreated_w256(D_0035ee58)) return;
  iscreated_w256(D_0035ee5c);
}

extern T27* D_0035f230;
extern u32 D_0035f01c;
u32 getselpos_w256(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 getitemtbl_w256(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
void func_0027aed8(u32, s32*, s32*);
s32 func_0027af58(void);
I27* func_00273180(s32, s32);
void func_002891f0(u32, s32, s32, s32, s32);
void func_0027b248(s32);
void func_0027afe0(void) {
  s32 a, b;
  s32 r = 0;
  func_0027aed8(getselpos_w256(15), &a, &b);
  s32 k = getselpos_w256(16);
  s32 v = func_0027af58();
  s8 f = D_0035f230->e[k].b;
  if (!D_0035f230->e[k].a) goto out;
  if (a) goto one;
  if (!b) goto one;
  if (v) goto one;
  if (f) goto one;
  if (getitemtbl_w256(k)) goto one;
  {
    I27* p = func_00273180(4, -1);
    s32 i;
    for (i = 0; i < 3; i++) if (p[i].b5 == D_0035f230->e[k].c) break;
    r = i + 1;
  }
  goto out;
one:
  r = 1;
out:
  func_002891f0(D_0035f01c, r, 0, -1, -1);
  func_0027b248(r != 0);
}


extern H2d* D_00361f60;
void* getgopher_w256(H2d*) asm("_ZN2Ti12MGHachimitsu10get_gopherEv");
s32 isattach_w256(void*) asm("_ZN2YS3OBJ9is_attachEv");
void addcount_w256(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
R2d* fmat_w256(H2d*) asm("_ZN2kn7FMatrixaSERKS0_");
void f17f488_w256(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void func_002db210(void*);
void func_002dbd30(void*, f32);
void func_002da120(A2d* a) {
  H2d* h = D_00361f60;
  void* g = getgopher_w256(h);
  if (g && isattach_w256(g)) {
    func_002db210(g);
  } else {
    if (h->i152 == 1) addcount_w256(-1, 0);
    f17f488_w256(a->mo, 14, 0.0f, 0.0f);
    mo_push_w256((M256*)a->mo, 0, 0.0f, 0.0f, 0);
    if (a->p3060) f17f488_w256(a->p3060->mo, 14, 0.0f, 0.0f);
    if (a->p3056 && isattach_w256(a->p3056)) func_002dbd30(a->p3056, a->f3064);
  }
  a->f3072 = fmat_w256(h)->f28;
}


void func_00239700(void*);
extern u8 D_00347f98[], D_00347e60[], D_0035e1b8[], D_0034a958[], D_0035e280[];
void func_0031a838(void*);
void func_0013ee88(void*);
void func_0014b668(void*);
void func_00322418(u8* t) {
  *(u32*)t = (u32)D_00347f98; func_0031a838(t + 12);
  *(u32*)t = (u32)D_00347e60; func_00239700(t + 24);
  *(u32*)(t + 432) = 0; t[436] = 0; *(u32*)t = (u32)D_0035e1b8;
  u8* m = t + 440;
  *(u32*)m = (u32)D_00347f98; func_0031a838(m + 12);
  *(u32*)m = (u32)D_00347e60; func_00239700(m + 24);
  *(u32*)m = (u32)D_0034a958;
  u8* e = t + 864;
  for (s32 i = 1; i != -1; i--, e += 848) {
    *(u32*)e = (u32)D_00347f98; func_0031a838(e + 12);
    *(u32*)e = (u32)D_0035e280; func_0013ee88(e + 32);
    func_0014b668(e + 320); func_0014b668(e + 576);
  }
  *(u32*)(t + 2572) = 0; *(u32*)(t + 2560) = (u32)D_00347e60; func_00239700(t + 2584);
}

}
