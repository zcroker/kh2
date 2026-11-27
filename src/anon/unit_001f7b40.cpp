// Linked unit 0x001f7b40-0x001f87f0 (ppp programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"
#include <stdarg.h>

// 001f7b40 (was src/anon/batch_w3740_nsa.c)
namespace n001f7b40 {
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1f7b40;
typedef struct {
    u64 q0;
    u64 q8;
    void* p16;
    f32* p20;
    s32 w24;
    s32 w28;
    s32 w32;
    s32 w36;
    u64 q40;
    V1f7b40* p48;
    V1f7b40* p52;
    s32 w56;
    s32 w60;
    s32 w64;
    s32 w68;
} Req1f7b40;
typedef struct { s32 f0; s32 set; f32 f8, f12, f16; u8 b20; u8 b21; } Ent1f7b40;
typedef struct { u8 pad0[12]; s32* off; } Ctx1f7b40;
typedef struct { u8 pad0[16]; u8* sets; } Res1f7b40;
typedef struct { u8 pad0[168]; u64 flags; } Cur1f7b40;
typedef struct { u8 pad0[144]; s32 p144; } Ovr1f7b40;
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Cur1f7b40* D_01d9e6e0 asm("D_01d9e6e0");
extern Res1f7b40* D_01d9e6e4 asm("D_01d9e6e4");
extern Ovr1f7b40* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e8c0[] asm("D_01d9e8c0");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern s32 D_01d9eaa8 asm("D_01d9eaa8");
extern f32 D_00354be0[] asm("D_00354be0");
extern "C" s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18 asm("D_00352c18");
void sceVu0ScaleVector(V1f7b40*, V1f7b40*, f32) asm("sceVu0ScaleVector");
void func_001f7e90(Req1f7b40*) asm("func_001f7e90");
/*TARGET 001f7b40*/
void func_001f7b40(u8 *base, Ent1f7b40 *e, Ctx1f7b40 *c) asm("func_001f7b40");
void func_001f7b40(u8 *base, Ent1f7b40 *e, Ctx1f7b40 *c)
{
  f32 *pos = (f32 *) ((base + c->off[0]) + 160);
  f32 *p2 = (f32 *) ((base + c->off[2]) + 160);
  u8 *col;
  Req1f7b40 r;
  V1f7b40 v;
  if ((D_01d9ea9c == 0) && ((D_01d9e6e0->flags & 0xff0000ff00ULL) == 0))
  {
    f32 ax = pos[2];
    f32 vx = pos[1] + ax;
    f32 x = pos[0] + vx;
    pos[1] = vx;
    pos[0] = x;
    if ((*((s32 *) (base + 12))) == e->f0)
    {
      pos[0] = x + e->f8;
      pos[1] = vx + e->f12;
      if (e->b20 < 4)
      {
        pos[2] = ax + e->f16;
      }
    }
  }
  if (e->set == 0xffff)
  {
    return;
  }
  col = (base + c->off[1]) + 160;
  if (col[8] == 0)
  {
    return;
  }
  v.x = col[8];
  v.y = col[9];
  v.z = col[10];
  v.w = col[11];
  sceVu0ScaleVector(&v, &v, 0.00392156839f);
  r.p16 = D_01d9e8c0;
  r.p20 = p2;
  r.w24 = D_01d9eaa4;
  r.p48 = &v;
  r.p52 = &v;
  r.w28 = *((s32 *) ((D_01d9e6e4->sets + (e->set * 36)) + 28));
  *((f32 *) (&r.w32)) = pos[0] * D_00354be0[0];
  r.w36 = e->b21;
  r.w68 = D_01d9e6e8->p144;
  if ((e->b20 >= 4) && ((*((s32 **) (pos + 2))) != 0))
  {
    r.w64 = 1;
    r.w56 = *(*((s32 **) (pos + 2)));
    r.w60 = e->b20 & 8;
  }
  else
  {
    r.w64 = 0;
  }
  if (e->b20 == 0)
  {
    r.q8 = ((D_00352bf8 << 5) | (((u64) (D_00352bec / 64)) << 14)) | (((u64) 85) << 27);
    r.q0 = ((2048 - (D_00352bec / 2)) << 4) | (((u64) (2048 - (D_00352bf0 / 2))) << 36);
  }
  else
  {
    r.q8 = ((D_00352bfc << 5) | (((u64) (D_00352be4 / 64)) << 14)) | (((u64) 85) << 27);
    r.q0 = ((2048 - (D_00352be4 / 2)) << 4) | (((u64) (2048 - (D_00352be8 / 2))) << 36);
  }
  r.q40 = D_00352c18;
  func_001f7e90(&r);
  D_01d9eaa8 += r.w24 - D_01d9eaa4;
  D_01d9eaa4 = r.w24;
  if ((e->b20 >= 4) && ((*((s32 **) (pos + 2))) != 0))
  {
    *(*((s32 **) (pos + 2))) = r.w56;
  }
}
}  // namespace n001f7b40
// 0x37021c: zero word in .rodata (pad before the 8-aligned GIF tag in the original object).
extern "C" const u32 D_0037021c = 0;

// 001f7e60 (gap, written for the unit)
namespace n001f7e60 {
void func_001f7e60(u8* self, u8* t) asm("func_001f7e60");
void func_001f7e60(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    *(u64*)(b + 160) = 0;
    *(u32*)(b + 168) = 0;
}
}  // namespace n001f7e60

// 001f7e78 (gap, written for the unit)
namespace n001f7e78 {
void func_001f7e78(u8* self, u8* t) asm("func_001f7e78");
void func_001f7e78(u8* self, u8* t) {
    u8* b = self + **(s32**)(t + 12);
    *(u64*)(b + 160) = 0;
    *(u32*)(b + 168) = 0;
}
}  // namespace n001f7e78

// 001f7e90 (was src/anon/batch_w3852_nsa.c)
namespace n001f7e90 {
/* GS XYOFFSET register */
typedef struct { u64 x:16; u64 p0:16; u64 y:16; u64 p1:16; } Ofs7e90;
typedef struct {
    union { Ofs7e90 b; u64 q; } ofs; /* 0x00 */
    u64 tex0;        /* 0x08 */
    void* cam;       /* 0x10 */
    void* mtx;       /* 0x14 */
    u8* pkt;         /* 0x18 */
    u8* mdl;         /* 0x1c */
    f32 scale;       /* 0x20 */
    s32 f36;         /* 0x24 */
    u64 rect;        /* 0x28 */
    void* col0;      /* 0x30 */
    void* col1;      /* 0x34 */
    u8* cache;       /* 0x38 */
    s32 f60;         /* 0x3c */
    s32 f64;         /* 0x40 */
    u8* pts;         /* 0x44 */
} Req7e90;
typedef struct {
    u64 tag[2];      /* 0x00 */
    u64 tex0, tex0a; /* 0x10 */
    u64 pad20[2];
    u64 alpha, alphaa; /* 0x30 */
    u64 pad40[2];
    u64 clamp, clampa; /* 0x50 */
    s32 v[3][4];     /* 0x60 */
    f32 c[3][4];     /* 0x90 */
    s32 xy[4];       /* 0xc0 */
    u8* cache;       /* 0xd0 */
} Buf7e90;
typedef struct { u8 b0; u8 kind; s16 n; u8 pad[12]; } Hdr7e90;
typedef struct { u8 c[12]; u16 idx[3]; u16 pad; } Tri7e90;
typedef struct { s16 x, y, z; } Pt7e90;
extern u64 D_00370220 asm("D_00370220");
/* GIF tag: NLOOP 1, EOP, 12 regs */
extern u64 D_00370228 asm("D_00370228");
Buf7e90* func_0020eaf8(s32) asm("func_0020eaf8");
void func_0020ebd8(s32) asm("func_0020ebd8");
void func_0020e858(u8*, s32, s32, s32) asm("func_0020e858");
// The GIF tag pair lives in this file's .rodata (old code reads it as extern D_).
extern const u32 R_00370220[4] asm("D_00370220") __attribute__((aligned(4))) = { 0x8001, 0xc02dc000, 0x12412eee, 0x4124 };
/*TARGET 001f7e90*/
/* 001f7e90 (partMng): draws a model's triangle lists as GS packets. Sets up TEX0/ALPHA/CLAMP
 * registers and the VU0 camera/matrix state, then for each triangle copies its 3 vertices and
 * colours to a scratch buffer and runs the VU0 projection/clip block; visible triangles are
 * added to the ordering table (func_0020e858) by depth.
 * Partial asm: the two VU0 blocks are hand-written in the original (setup: matrix/scale loads;
 * per triangle: transform, perspective divide, clip test, packet stores, optional vertex cache),
 * written here as asm volatile with C operands (no register pins). */
void func_001f7e90(Req7e90* r) asm("func_001f7e90");
/* 001f7e90 (partMng): draws a model's triangle lists as GS packets. Sets up TEX0/ALPHA/CLAMP
 * registers and the VU0 camera/matrix state, then for each triangle copies its 3 vertices and
 * colours to a scratch buffer and runs the VU0 projection/clip block; visible triangles are
 * added to the ordering table (func_0020e858) by depth.
 * Partial asm: the two VU0 blocks are hand-written in the original (setup: matrix/scale loads;
 * per triangle: transform, perspective divide, clip test, packet stores, optional vertex cache),
 * written here as asm volatile with C operands (no register pins). */
void func_001f7e90(Req7e90* r)
{
    Hdr7e90* h;
    Buf7e90* b;
    u8* pkt;
    u8* pts;
    s32 f36, f60, f64;
    Tri7e90* t;
    s16 n;
    Pt7e90* p;
    h = (Hdr7e90*)(r->mdl + *(s32*)(r->mdl + 4));
    f64 = r->f64;
    f60 = r->f60;
    pts = r->pts;
    pkt = r->pkt;
    b = func_0020eaf8(224);
    if (pts == 0) pts = r->mdl + *(s32*)(r->mdl + 8);
    b->tag[0] = D_00370220;
    b->tag[1] = D_00370228;
    b->tex0 = r->tex0;
    b->tex0a = 6;
    b->alpha = 68;
    b->alphaa = 66;
    b->clamp = 2 | (2 << 2) | ((r->rect & 0x7ff) << 4) | ((((r->rect >> 16) & 0x7ff) - 1) << 14) | (((r->rect >> 32) & 0x7ff) << 24) | ((((r->rect >> 48) & 0x7ff) - 1) << 34);
    b->clampa = 8;
    b->xy[0] = (r->ofs.q & 0xffff) - 8;
    b->xy[1] = ((r->ofs.q >> 32) & 0xffff) - 8;
    f36 = r->f36;
    b->cache = r->cache;
    {
        void* p16 = r->cam;
        void* p20 = r->mtx;
        void* p48 = r->col0;
        void* p52 = r->col1;
        asm volatile(
    "vsub.xyzw $vf9,$vf0,$vf0\n"
    "lqc2 $vf31,0(%[p16])\n"
    "vmove.x $vf1,$vf31\n"
    "lqc2 $vf31,16(%[p16])\n"
    "vmove.y $vf1,$vf31\n"
    "lqc2 $vf2,32(%[p16])\n"
    "lqc2 $vf31,48(%[p16])\n"
    "vmove.zw $vf1,$vf31\n"
    "lqc2 $vf16,0(%[p20])\n"
    "lqc2 $vf17,16(%[p20])\n"
    "lqc2 $vf18,32(%[p20])\n"
    "lqc2 $vf19,48(%[p20])\n"
    "lqc2 $vf29,32(%[r])\n"
    "vmove.x $vf13,$vf1\n"
    "vmove.y $vf13,$vf1\n"
    "vmulx.xy $vf13,$vf13,$vf29x\n"
    "lqc2 $vf5,0(%[buf])\n"
    "lqc2 $vf6,16(%[buf])\n"
    "lqc2 $vf8,48(%[buf])\n"
    "lqc2 $vf10,80(%[buf])\n"
    "lui $2,0x3a80\n"
    "qmtc2 $2,$vf31\n"
    "vaddx.z $vf4,$vf0,$vf31x\n"
    "lqc2 $vf12,192(%[buf])\n"
    "vitof4.xyzw $vf12,$vf12\n"
    "lui $2,0x4580\n"
    "qmtc2 $2,$vf31\n"
    "vaddx.xy $vf4,$vf0,$vf31x\n"
    "lqc2 $vf23,0(%[p48])\n"
    "lqc2 $vf24,0(%[p52])\n"
        : : [r] "r"(r), [buf] "r"(b), [p16] "r"(p16), [p20] "r"(p20), [p48] "r"(p48), [p52] "r"(p52) : "$2", "memory");
    }
    do {
        t = (Tri7e90*)(h + 1);
        n = h->n;
        if ((s8)h->kind != 0) break;
        h = (Hdr7e90*)((u8*)t + n * 20);
        for (; n > 0; n--) {
            s32 clip;
            u8* cache;
            p = (Pt7e90*)(pts + t->idx[0] * 6);
            b->v[0][0] = p->x; b->v[0][1] = p->y; b->v[0][2] = p->z;
            p = (Pt7e90*)(pts + t->idx[1] * 6);
            b->v[1][0] = p->x; b->v[1][1] = p->y; b->v[1][2] = p->z;
            p = (Pt7e90*)(pts + t->idx[2] * 6);
            b->v[2][0] = p->x; b->v[2][1] = p->y; b->v[2][2] = p->z;
            b->c[0][0] = t->c[0]; b->c[0][1] = t->c[1]; b->c[0][2] = t->c[2]; b->c[0][3] = t->c[3];
            b->c[1][0] = t->c[4]; b->c[1][1] = t->c[5]; b->c[1][2] = t->c[6]; b->c[1][3] = t->c[7];
            b->c[2][0] = t->c[8]; b->c[2][1] = t->c[9]; b->c[2][2] = t->c[10]; b->c[2][3] = t->c[11];
            cache = b->cache;
            asm volatile(".set noreorder\n"
    "lqc2 $vf31,96(%[buf])\n"
    "vitof0.xyzw $vf31,$vf31\n"
    "vaddax.xyzw ACC,$vf19,$vf0x\n"
    "vmaddax.xyzw ACC,$vf16,$vf31x\n"
    "vmadday.xyzw ACC,$vf17,$vf31y\n"
    "vmaddz.xyz $vf22,$vf18,$vf31z\n"
    "vaddax.zw ACC,$vf1,$vf0x\n"
    "vmulax.x ACC,$vf1,$vf22x\n"
    "vmulay.y ACC,$vf1,$vf22y\n"
    "vmaddz.xyzw $vf11,$vf2,$vf22z\n"
    "vdiv Q,$vf0w,$vf11w\n"
    "vwaitq\n"
    "vaddq.w $vf22,$vf1,Q\n"
    "vmulq.xyz $vf11,$vf11,Q\n"
    "ctc2.ni $0,$vi16\n"
    "vsub.w $vf0,$vf11,$vf0\n"
    "vsub.xy $vf0,$vf11,$vf0\n"
    "vsub.xy $vf0,$vf4,$vf11\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "cfc2.ni $2,$vi16\n"
    "andi %[clip],$2,0xc0\n"
    "bnez %[clip],10f\n"
    "vnop\n"
    "lqc2 $vf31,112(%[buf])\n"
    "vitof0.xyzw $vf31,$vf31\n"
    "vaddax.xyzw ACC,$vf19,$vf0x\n"
    "vmaddax.xyzw ACC,$vf16,$vf31x\n"
    "vmadday.xyzw ACC,$vf17,$vf31y\n"
    "vmaddz.xyz $vf21,$vf18,$vf31z\n"
    "vaddax.zw ACC,$vf1,$vf0x\n"
    "vmulax.x ACC,$vf1,$vf21x\n"
    "vmulay.y ACC,$vf1,$vf21y\n"
    "vmaddz.xyzw $vf25,$vf2,$vf21z\n"
    "vdiv Q,$vf0w,$vf25w\n"
    "vwaitq\n"
    "vaddq.w $vf21,$vf1,Q\n"
    "vmulq.xyz $vf25,$vf25,Q\n"
    "ctc2.ni $0,$vi16\n"
    "vsub.w $vf0,$vf25,$vf0\n"
    "vsub.xy $vf0,$vf25,$vf0\n"
    "vsub.xy $vf0,$vf4,$vf25\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "cfc2.ni $2,$vi16\n"
    "andi %[clip],$2,0xc0\n"
    "bnez %[clip],10f\n"
    "vnop\n"
    "lqc2 $vf31,128(%[buf])\n"
    "vitof0.xyzw $vf31,$vf31\n"
    "vaddax.xyzw ACC,$vf19,$vf0x\n"
    "vmaddax.xyzw ACC,$vf16,$vf31x\n"
    "vmadday.xyzw ACC,$vf17,$vf31y\n"
    "vmaddz.xyz $vf20,$vf18,$vf31z\n"
    "vaddax.zw ACC,$vf1,$vf0x\n"
    "vmulax.x ACC,$vf1,$vf20x\n"
    "vmulay.y ACC,$vf1,$vf20y\n"
    "vmaddz.xyzw $vf26,$vf2,$vf20z\n"
    "vdiv Q,$vf0w,$vf26w\n"
    "vwaitq\n"
    "vaddq.w $vf20,$vf1,Q\n"
    "vmulq.xyz $vf26,$vf26,Q\n"
    "ctc2.ni $0,$vi16\n"
    "vsub.w $vf0,$vf26,$vf0\n"
    "vsub.xy $vf0,$vf26,$vf0\n"
    "vsub.xy $vf0,$vf4,$vf26\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "vnop\n"
    "cfc2.ni $2,$vi16\n"
    "andi %[clip],$2,0xc0\n"
    "bnez %[clip],10f\n"
    "vnop\n"
    "sqc2 $vf5,16(%[pkt])\n"
    "sqc2 $vf6,32(%[pkt])\n"
    "sqc2 $vf8,48(%[pkt])\n"
    "sqc2 $vf10,64(%[pkt])\n"
    "lqc2 $vf3,144(%[buf])\n"
    "vmul.xyzw $vf3,$vf3,$vf23\n"
    "vftoi0.xyzw $vf3,$vf3\n"
    "sqc2 $vf3,96(%[pkt])\n"
    "vsub.xyz $vf28,$vf22,$vf19\n"
    "vmul.xyz $vf31,$vf28,$vf28\n"
    "vaddy.x $vf31,$vf31,$vf31y\n"
    "vaddz.x $vf31,$vf31,$vf31z\n"
    "vsqrt Q,$vf31x\n"
    "vaddz.x $vf14,$vf0,$vf11z\n"
    "vftoi4.xyz $vf9,$vf11\n"
    "sqc2 $vf9,112(%[pkt])\n"
    "vaddw.z $vf15,$vf0,$vf0w\n"
    "vwaitq\n"
    "vaddq.z $vf12,$vf0,Q\n"
    "vdiv Q,$vf0w,$vf12z\n"
    "vwaitq\n"
    "vmulq.xyz $vf31,$vf28,Q\n"
    "beqz %[f36],1f\n"
    "nop\n"
    "vmulz.xy $vf31,$vf31,$vf31z\n"
    "1:\n"
    "vmul.xy $vf31,$vf31,$vf13\n"
    "vmulw.xyz $vf31,$vf31,$vf22w\n"
    "vadd.xy $vf31,$vf31,$vf11\n"
    "vsub.xy $vf31,$vf31,$vf12\n"
    "vmulz.xy $vf15,$vf31,$vf4z\n"
    "beqz %[f64],3f\n"
    "nop\n"
    "beqz %[f60],2f\n"
    "nop\n"
    "lqc2 $vf15,0(%[cache])\n"
    "j 3f\n"
    "nop\n"
    "2:\n"
    "sqc2 $vf15,0(%[cache])\n"
    "3:\n"
    "vaddw.z $vf15,$vf0,$vf22w\n"
    "vmulz.xy $vf15,$vf15,$vf15z\n"
    "sqc2 $vf15,80(%[pkt])\n"
    "lqc2 $vf30,160(%[buf])\n"
    "vmul.xyzw $vf30,$vf30,$vf23\n"
    "vftoi0.xyzw $vf30,$vf30\n"
    "sqc2 $vf30,144(%[pkt])\n"
    "vsub.xyz $vf28,$vf21,$vf19\n"
    "vmul.xyz $vf31,$vf28,$vf28\n"
    "vaddy.x $vf31,$vf31,$vf31y\n"
    "vaddz.x $vf31,$vf31,$vf31z\n"
    "vsqrt Q,$vf31x\n"
    "vaddz.y $vf14,$vf0,$vf25z\n"
    "vftoi4.xyz $vf9,$vf25\n"
    "sqc2 $vf9,160(%[pkt])\n"
    "vaddw.z $vf15,$vf0,$vf0w\n"
    "vwaitq\n"
    "vaddq.z $vf12,$vf0,Q\n"
    "vdiv Q,$vf0w,$vf12z\n"
    "vwaitq\n"
    "vmulq.xyz $vf31,$vf28,Q\n"
    "beqz %[f36],4f\n"
    "nop\n"
    "vmulz.xy $vf31,$vf31,$vf31z\n"
    "4:\n"
    "vmul.xy $vf31,$vf31,$vf13\n"
    "vmulw.xyz $vf31,$vf31,$vf21w\n"
    "vadd.xy $vf31,$vf31,$vf25\n"
    "vsub.xy $vf31,$vf31,$vf12\n"
    "vmulz.xy $vf15,$vf31,$vf4z\n"
    "beqz %[f64],6f\n"
    "nop\n"
    "beqz %[f60],5f\n"
    "nop\n"
    "lqc2 $vf15,16(%[cache])\n"
    "j 6f\n"
    "nop\n"
    "5:\n"
    "sqc2 $vf15,16(%[cache])\n"
    "6:\n"
    "vaddw.z $vf15,$vf0,$vf21w\n"
    "vmulz.xy $vf15,$vf15,$vf15z\n"
    "sqc2 $vf15,128(%[pkt])\n"
    "lqc2 $vf30,176(%[buf])\n"
    "vmul.xyzw $vf30,$vf30,$vf23\n"
    "vftoi0.xyzw $vf30,$vf30\n"
    "sqc2 $vf30,192(%[pkt])\n"
    "vsub.xyz $vf28,$vf20,$vf19\n"
    "vmul.xyz $vf31,$vf28,$vf28\n"
    "vaddy.x $vf31,$vf31,$vf31y\n"
    "vaddz.x $vf31,$vf31,$vf31z\n"
    "vsqrt Q,$vf31x\n"
    "vaddz.z $vf14,$vf0,$vf26z\n"
    "vftoi4.xyz $vf9,$vf26\n"
    "sqc2 $vf9,208(%[pkt])\n"
    "vaddw.z $vf15,$vf0,$vf0w\n"
    "vwaitq\n"
    "vaddq.z $vf12,$vf0,Q\n"
    "vdiv Q,$vf0w,$vf12z\n"
    "vwaitq\n"
    "vmulq.xyz $vf31,$vf28,Q\n"
    "beqz %[f36],7f\n"
    "nop\n"
    "vmulz.xy $vf31,$vf31,$vf31z\n"
    "7:\n"
    "vmul.xy $vf31,$vf31,$vf13\n"
    "vmulw.xyz $vf31,$vf31,$vf20w\n"
    "vadd.xy $vf31,$vf31,$vf26\n"
    "vsub.xy $vf31,$vf31,$vf12\n"
    "vmulz.xy $vf15,$vf31,$vf4z\n"
    "beqz %[f64],9f\n"
    "nop\n"
    "beqz %[f60],8f\n"
    "nop\n"
    "lqc2 $vf15,32(%[cache])\n"
    "j 9f\n"
    "nop\n"
    "8:\n"
    "sqc2 $vf15,32(%[cache])\n"
    "9:\n"
    "vaddw.z $vf15,$vf0,$vf20w\n"
    "vmulz.xy $vf15,$vf15,$vf15z\n"
    "sqc2 $vf15,176(%[pkt])\n"
    "vminix.y $vf31,$vf14,$vf14x\n"
    "vminiy.z $vf31,$vf14,$vf31y\n"
    "vftoi4.xyzw $vf31,$vf31\n"
    "sqc2 $vf31,192(%[buf])\n"
    "add %[clip],$0,$0\n"
    "10:\n"
            ".set reorder\n"
            : [clip] "=&r"(clip) : [buf] "r"(b), [pkt] "r"(pkt), [f36] "r"(f36), [f64] "r"(f64), [f60] "r"(f60), [cache] "r"(cache) : "$2", "memory");
            if (clip == 0) {
                func_0020e858(pkt, 14, b->xy[2] / 12288, 0);
                pkt += 224;
            }
            b->cache += 48;
            t++;
        }
    } while ((s8)h->kind != -1);
    r->pkt = pkt;
    r->cache = b->cache;
    func_0020ebd8(224);
}
}  // namespace n001f7e90

// 001f8598 (gap, written for the unit)
namespace n001f8598 {
void func_001f8598(void) asm("func_001f8598");
void func_001f8598(void) {}
}  // namespace n001f8598

// 001f85a0 (gap, written for the unit)
namespace n001f85a0 {
void func_001f85a0(void) asm("func_001f85a0");
void func_001f85a0(void) {}
}  // namespace n001f85a0

// 001f85a8 (gap, written for the unit)
namespace n001f85a8 {
void func_001f85a8(void) asm("func_001f85a8");
void func_001f85a8(void) {}
}  // namespace n001f85a8

// 001f85b0 (gap, written for the unit)
namespace n001f85b0 {
void func_001f85b0(void) asm("func_001f85b0");
void func_001f85b0(void) {}
}  // namespace n001f85b0

// 001f85b8 (was src/anon/batch_w321.cpp)
namespace n001f85b8 {
struct V16 { f32 x, y, z, w; };
struct E2 { u8 n; u8 cur; u16 f2; u16 f4; u16 f6; u8 pad[8]; V16 arr[1]; };
struct K8 { u16 f0; u16 f2; s8 f4; u8 f5; u16 f6; };
struct T1 { u8 p[6]; s16 f6; u8 p2[8]; K8 k[1]; };
struct A0 { u8 p[12]; s32 fc; u8 p2[141]; u8 f157; };
struct A1 { u8 p[4]; s32 f4; u16 f8; u8 p2[20]; u8 f30; u8 p3[4]; u8 f35; u8 p4[2]; u8 f38; };
struct A2 { u8 p[12]; s32* fc; };
struct G0 { u8 p[168]; u64 f168; };
struct G8 { u8 p[64]; V16 f64; };
union U4 { T1* t; u8 c; };
struct G4b { u8 p[20]; U4* f20; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern G0* D_01d9e6e0 asm("D_01d9e6e0");
extern G4b* D_01d9e6e4 asm("D_01d9e6e4");
extern G8* D_01d9e6e8 asm("D_01d9e6e8");
extern V16 D_01d9e6f0 asm("D_01d9e6f0");
void sceVu0ApplyMatrix(V16*, V16*, V16*) asm("sceVu0ApplyMatrix");
void sceVu0CopyVector(V16*, V16*) asm("sceVu0CopyVector");
// memcpy16
void func_002226b8(V16*, V16*) asm("func_002226b8");
/*TARGET 001f85b8*/
// vec3_copy

void func_001f85b8(A0* a, A1* b, A2* c) asm("func_001f85b8");
// vec3_copy

void func_001f85b8(A0* a, A1* b, A2* c)
{
    V16 tmp;
    E2* e;
    s32 i;
    V16* p;
    u8 cur;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->f168 & 0xff0000ff00LL) return;
    e = (E2*)((u8*)a + *c->fc + 160);
    if (a->fc == 0 && a->f157 == 0) {
        if (b->f30 != 0) { sceVu0ApplyMatrix(&tmp, &D_01d9e6f0, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        else { sceVu0CopyVector(&tmp, &D_01d9e6e8->f64); tmp.w = 1.0f; }
        for (i = e->n, p = e->arr; i > 0; i--, p++) sceVu0CopyVector(p, &tmp);  // memcpy16
    }
    if (e->cur == 0) e->cur = e->n;
    e->cur--;
    if (b->f30 != 0) {
        sceVu0ApplyMatrix(&e->arr[e->cur], &D_01d9e6f0, &D_01d9e6e8->f64);
        e->arr[e->cur].w = 1.0f;
    } else {
        func_002226b8(&e->arr[e->cur], &D_01d9e6e8->f64);  // vec3_copy
    }
    {
        T1* t = *(T1**)((u8*)D_01d9e6e4->f20 + (b->f4 << 3));
        K8* k = &t->k[e->f4];
        e->f2 += b->f8;
        if (e->f2 < (s16)k->f2) return;
        e->f2 -= k->f2;
        if (++e->f4 < t->f6) return;
        if (k->f4 & 0x80) { e->f4 = 0; e->f2 = 0; return; }
        e->f4--; e->f2 = 0;
    }
}
}  // namespace n001f85b8

