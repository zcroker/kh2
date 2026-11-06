#include "../common/types.h"

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
extern u64 D_00370220; /* GIF tag: NLOOP 1, EOP, 12 regs */
extern u64 D_00370228;
Buf7e90* func_0020eaf8(s32);
void func_0020ebd8(s32);
void func_0020e858(u8*, s32, s32, s32);

/* 001f7e90 (partMng): draws a model's triangle lists as GS packets. Sets up TEX0/ALPHA/CLAMP
 * registers and the VU0 camera/matrix state, then for each triangle copies its 3 vertices and
 * colours to a scratch buffer and runs the VU0 projection/clip block; visible triangles are
 * added to the ordering table (func_0020e858) by depth.
 * Partial asm: the two VU0 blocks are hand-written in the original (setup: matrix/scale loads;
 * per triangle: transform, perspective divide, clip test, packet stores, optional vertex cache),
 * written here as asm volatile with C operands; the four setup pointers are pinned to t4-t7 and
 * the clip result/cache pointer to t7/t6 because the original's asm used those registers. */
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
        register void* p48 asm("$14") = r->col0;
        register void* p20 asm("$13") = r->mtx;
        register void* p16 asm("$12") = r->cam;
        register void* p52 asm("$15") = r->col1;
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
            register s32 clip asm("$15");
            register u8* cache asm("$14");
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
            : [clip] "=r"(clip) : [buf] "r"(b), [pkt] "r"(pkt), [f36] "r"(f36), [f64] "r"(f64), [f60] "r"(f60), [cache] "r"(cache) : "$2", "memory");
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
