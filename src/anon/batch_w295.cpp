#include "../common/types.h"
extern "C" {
struct T40 { s32 w0; s32 w4; u32 w8; u8 pad[28]; };
struct T52 { s32 w0; s32 w4; u8 pad[38]; s16 h46; s16 h48; u8 pad2[2]; };
extern T40* D_0035dcfc;
extern T52* D_0035dcf4;
extern s32 D_0035de20;
s32 func_002282f0(s32);
void ut_1c0d38(u32, u32, s32, s32) asm("_Z16u_tail4_001c0d38jjjj");
struct S { u8 pad[4]; s16 h4; u8 p6[2]; s16 h8; s16 h10; s16 h12; s16 h14; s16 h16; };
void func_0022f018(S* s) {
  s32 b, a, i;
  if (func_002282f0(s->h4)) return;
  b = -1; a = -1;
  switch (s->h16) {
  case 1: {
    T40* e = D_0035dcfc;
    for (i = 0; i < 96; i++, e++) { if (e->w0 != -1 && e->w4 == s->h10) { a = i; break; } }
    e = D_0035dcfc;
    for (i = 0; i < 96; i++, e++) { if (e->w0 != -1 && e->w4 == s->h8) { b = i; break; } }
    break; }
  case 0: {
    T40* e = D_0035dcfc;
    for (i = 0; i < 96; i++, e++) { if (e->w0 != -1 && e->w4 == s->h8) { b = i; break; } }
    s32 d = D_0035de20;
    T52* f = D_0035dcf4;
    for (i = 0; i < 96; i++, f++) {
      if (f->w4 != -1 && f->w4 == s->h10 && f->w0 == s->h14 && !(d < f->h46)) { a = i; break; }
    }
    break; }
  }
  if (b < 0) return;
  if (a < 0) return;
  switch (s->h16) {
  case 0: D_0035dcf4[a].h48 = b; break;
  case 1: ut_1c0d38(D_0035dcfc[a].w8, D_0035dcfc[b].w8, s->h12, 0); break;
  }
}
typedef void (*VF5)(void*);
struct O408a { VF5* vt; u8 pad[404]; };
struct O436a { VF5* vt; u8 pad[432]; };
struct W5 { O408a a[5]; u8 p0[28]; O436a b[2]; O436a x; O436a c[24]; O436a d[24]; O436a e[24]; O408a f[24]; };
extern W5* D_0035f038;
s32 chk_139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void lv_139510(void*) asm("_ZN2dk5Obj2D5leaveEv");
void ctarget0_00257a00(void) asm("_Z17ctarget0_00257a00v");
void ctarget0_00257a00(void) {
  s32 i;
  if (chk_139d78(&D_0035f038->a[0])) lv_139510(&D_0035f038->a[0]);
  if (chk_139d78(&D_0035f038->a[1])) lv_139510(&D_0035f038->a[1]);
  if (chk_139d78(&D_0035f038->a[2])) lv_139510(&D_0035f038->a[2]);
  if (chk_139d78(&D_0035f038->a[3])) lv_139510(&D_0035f038->a[3]);
  if (chk_139d78(&D_0035f038->a[4])) lv_139510(&D_0035f038->a[4]);
  if (chk_139d78(&D_0035f038->b[0])) lv_139510(&D_0035f038->b[0]);
  if (chk_139d78(&D_0035f038->b[1])) lv_139510(&D_0035f038->b[1]);
  for (i = 0; i < 24; i++) {
    if (chk_139d78(&D_0035f038->c[i])) D_0035f038->c[i].vt[5](&D_0035f038->c[i]);
    if (chk_139d78(&D_0035f038->d[i])) D_0035f038->d[i].vt[5](&D_0035f038->d[i]);
    if (chk_139d78(&D_0035f038->e[i])) D_0035f038->e[i].vt[5](&D_0035f038->e[i]);
    if (chk_139d78(&D_0035f038->f[i])) D_0035f038->f[i].vt[5](&D_0035f038->f[i]);
  }
}
extern s32 D_0035f3d4;
struct T373 { u8 pad[8]; s16 t[1]; };
extern T373 D_00373e50;
extern u32 D_0035ef64, D_0035ef68, D_0035f03c, D_0035f01c;
extern s8* D_0035f230;
u8* cm_glb(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 mb_gm(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 cm_gsp(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
void func_0027aed8(s32, s32*, s32*);
s32 func_0028d008(void*);
s32 func_0027af58(void);  // check_state16_then_loop
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
u8* mc_gs(void*) asm("_ZN2Tz10MenuCursor9GetSpriteEi");
void sp_gop(u32, s32*, s32*) asm("_ZN2dk6Sprite12getOffsetPosERiS1_");
void sp_sop(void*, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
s32 jm_gd(u32) asm("_ZN2Tz8JmReport7GetDataEj");
void cm_csci(void*) asm("_ZN2Tz5CmTop18CreateShortCutInfoEPN2dk6SpriteE");
void cm_lsci(void) asm("_ZN2Tz5CmTop17LeaveShortCutInfoEv");
void func_0027bd40(void* p, u8 flag) {
  s32 v[4];
  u8* w = cm_glb();
  s32 m = mb_gm();
  u8* o = w + 816;
  { s32* q = &v[1]; func_0027aed8(cm_gsp(15), q - 1, q); }
  s32 act = chk_139d78(o);
  if (func_0028d008(p)) {
  if (!act) {
    s32 c = 249;
    s32 s = D_0035f3d4 + 2;
    if (m != 16) c = D_00373e50.t[func_0027af58()];
    pz_cfo(o, s, D_0035ef68, D_0035ef64, D_0035f03c, c, -1, 0);
    mc_as(o, w);
    sp_gop(*(u32*)(mc_gs(p) + 396), &v[2], &v[3]);
    sp_sop(o, v[2], v[3]);
  }
  if (flag) {
    sp_gop(*(u32*)(mc_gs(p) + 396), &v[2], &v[3]);
    sp_sop(o, v[2], v[3]);
  }
  if (chk_139d78(w + 2504) && !flag) return;
  s32 r = jm_gd(D_0035f01c);
  if (m == 16 && v[0] == 0 && D_0035f230[r * 8 + 17]) { cm_csci(mc_gs(p)); return; }
  } else {
    if (act) lv_139510(o);
  }
  cm_lsci();
}
extern u8 D_00340ed0[3];
extern u32 D_00340ed4;
extern u64 D_00340ed8[];
struct N7;
typedef void (*CB7)(N7*, s32);
struct N7 { u32* w0; u32 w4; u32 w8; u32 w12; N7* next; u8 pad20[4]; u32 w24; u8 b28, b29, b30, b31, b32, b33, b34; u8 pad35[5]; u64 d40; u64 d48; u8 pad56[24]; CB7 cb80; CB7 cb84; };
s32 func_00109f58(u32, u32, u8);
s32 func_00109ea8(u32, u32, u8);
void func_00108c00(u64*, u32, u64, u64, s32, s32, u64, u64);
s32 func_0011c8f8(u32*, u32*, s32, u32, u32, u32);
void func_00134490(void);
void func_00109fe8(N7* n) {
  while (n) {
    if (n->w0 != 0) {
      if (!(n->w24 & 2)) { n->b32 = D_00340ed0[0]; n->b33 = D_00340ed0[1]; n->b34 = D_00340ed0[2]; }
      if ((s8)n->b31 < 0) {
        s32 a = func_00109f58(D_00340ed4, *(u32*)(*(u32*)(*(u32*)((u8*)n->w0 + 20) + 4) + 4), n->b31);
        s32 b = func_00109ea8(D_00340ed4, *(u32*)(*(u32*)(*(u32*)((u8*)n->w0 + 20) + 4) + 4), n->b31);
        func_00108c00(D_00340ed8, 63, n->d40, n->d48 & ~(1ull << 32), b, a,
          ((u64)n->b32 << 0) | ((u64)n->b33 << 8) | ((u64)n->b34 << 16),
          ((u64)n->b28 << 0) | ((u64)n->b29 << 8) | ((u64)n->b30 << 16) | ((u64)n->b31 << 24) | ((u64)0x3f800000 << 32));
        u32* s = n->w0;
        if (n->cb80) n->cb80(n, 0);
        if (func_0011c8f8(n->w0, &n->w24, 0, n->w4, n->w8, n->w12)) s = 0;
        if (n->cb84) n->cb84(n, 0);
        n->w0 = s;
      }
    } else {
      if (n->cb80) n->cb80(n, 0);
      if (n->cb84) n->cb84(n, 0);
    }
    func_00134490();
    n = n->next;
  }
}
}

namespace w295_a {
#define QCOPY295(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define MCOPY295(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY295(this, &o); }
    QWord& operator=(const QWord& o) { if (this != &o) QCOPY295(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat(const QMat& o) { MCOPY295(this, &o); }
    QMat& operator=(const QMat& o) { if (this != &o) MCOPY295(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline void ScaleIn2(QWord& d, QWord& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&v), "f"(s) : "$8", "memory");
}
static inline void ScaleIn(QWord& v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&v), "f"(s) : "$8", "memory");
}
static inline void MulIn(QMat& a, QMat& b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
        "lqc2 $vf5, 0(%1)\n\tlqc2 $vf6, 16(%1)\n\tlqc2 $vf7, 32(%1)\n\tlqc2 $vf8, 48(%1)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&a), "r"(&b) : "memory");
}
struct Box { QWord mn, mx; };
struct Src;
typedef f32 (*SF)(Src*);
struct Src { SF* vt; };
struct Ob { u32 w0; Src* src; u8 p8[8]; QMat m16; u8 p80[64]; QMat m144; u8 p208[64]; QMat m272; u8 p336[20]; f32 f[6]; u8 p380[260]; QWord v640; };
extern "C" {
void bx_init(Box*) asm("_ZN2dk6Aabbox4initEv");
void bx_set(Box*, f32, f32, f32, f32, f32, f32) asm("_ZN2dk6Aabbox3setEffffff");
void func_00144b38(Box*, QMat*);
void func_001605a0(Ob*, QMat);
void func_001606e0(Ob* o) {
    Box b;
    bx_init(&b);
    QMat m;
    QWord& r1 = m.r[1]; QWord& r2 = m.r[2]; QWord& r3 = m.r[3];
    m = o->m16;
    f32 k = -1.0f;
    ScaleIn2(r1, r1, k);
    ScaleIn(r2, k);
    { QMat n = o->m272; MulIn(m, n); }
    o->v640 = r3;
    f32* f = o->f;
    f32 d = o->src->vt[3](o->src);
    bx_set(&b, f[0] - d, f[1] - d, f[2] - d, f[3] + d, f[4] + d, f[5] + d);
    func_00144b38(&b, &o->m144);
    func_001605a0(o, m);
}
}
}
