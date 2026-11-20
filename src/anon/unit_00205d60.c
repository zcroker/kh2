/* 0x00205d60: particle/emitter draw. Per-entry scale matrices, then for each live point: packet alloc, colour from the
   emitter entry, frame pick (VU0 random frame when frame == 255 and the last frame is flagged), model matrix via VU0,
   packet submit, frame advance.
   Partial asm: the two VU0 blocks (hand-written in the original, same idiom as batch_w3719_nsa.c).
   Matching notes: p->frame is read directly at the compare and the frames[] index (gcse keeps the byte in a QImode reg,
   hence the andi before bne 255); the random value is a float in a GPR operand; &pos is listed before the matrix globals
   in the asm operands (global-alloc tie broken by pseudo number); `pts = D_00354680; p = &pts[i]`. */
#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V205d60;
typedef struct { V205d60 r[4]; } M205d60;
typedef struct { s32 set; u8 r, g, b, pad7; f32 scale; } Ent205d60;
typedef struct { u8 pad0[4]; Ent205d60 ent[10]; } Emit205d60;
typedef struct { f32 x, y, z; u8 ent, on, alpha, frame; } Pt205d60;
typedef struct { s16 off; s16 pad2; s8 flags; u8 pad5[3]; } Frame205d60;
typedef struct { u8 pad0[6]; s16 count; u8 pad8[8]; Frame205d60 frames[1]; } Shape205d60;
typedef struct { Shape205d60* sh; s32 pad; } ShapeEnt205d60;
typedef struct { u8 pad0[20]; ShapeEnt205d60* shapes; } Res205d60;
typedef struct { u8 pad0[80]; M205d60 m80; } Ovr205d60;
typedef struct { s32 w0; u8 pad4[4]; f32 f8; u8 pad12[4]; s32 r, g, b, a; u8 pad32[16]; V205d60 m[4]; } Pk205d60;
typedef struct { u8 pad0[168]; u64 flags; } Cur205d60;
extern Pt205d60* D_00354680;
extern s32 D_00354684;
extern Res205d60* D_01d9e6e4;
extern Ovr205d60* D_01d9e6e8;
extern Cur205d60* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern M205d60 D_01d9e730;
extern M205d60 D_01d9e8c0;
void func_0021cda0(s32);
Pk205d60* func_0021e988(void);
Pk205d60* func_0021e998(void);
Pk205d60* func_0021e9a8(void);
void func_0021cdd0(u8*, Pk205d60*);
void func_002f4000(M205d60*);
void func_002f3f40(V205d60*, V205d60*, f32);
void func_001e7538(void);
void func_0020e0a0(void);
void func_00205d60(void* unused, Emit205d60* e)
{
    M205d60 m[10];
    V205d60 pos;
    f32 sc;
    Pk205d60* pk;
    Pk205d60* b;
    s32 i;
    Ent205d60* ents = e->ent;
    if (!D_00354680) return;
    if (D_00354684 <= 0) return;
    func_0021cda0(0);
    pk = func_0021e988();
    b = func_0021e998();
    b->w0 = 0;
    pk->w0 = 0;
    for (i = 0; i < 10; i++) {
        if (ents[i].pad7 >= 255) {
            b->w0 = 2;
            pk->w0 = 2;
            break;
        }
    }
    pk->f8 = b->f8 = 0.0f;
    for (i = 0; i < 10; i++) {
        Ent205d60* en2 = &ents[i];
        func_002f4000(&m[i]);
        func_002f3f40(&m[i].r[0], &m[i].r[0], en2->scale);
        func_002f3f40(&m[i].r[1], &m[i].r[1], en2->scale);
        func_002f3f40(&m[i].r[2], &m[i].r[2], en2->scale);
    }
    for (i = 0; i < D_00354684; i++) {
        Pt205d60* pts = D_00354680;
        Pt205d60* p = &pts[i];
        Ent205d60* en;
        Shape205d60* sh;
        Frame205d60* fr;
        u8 on = p->on;
        u8 idx;
        M205d60* mm;
        u8* data;
        ShapeEnt205d60* se;
        if (!on) continue;
        idx = p->ent;
        if (ents[idx].set == 0xffff) continue;
        en = &ents[idx];
        pk = func_0021e9a8();
        se = (ShapeEnt205d60*)((u8*)D_01d9e6e4->shapes + en->set * 8);
        mm = &m[idx];
        pk->r = en->r;
        pk->g = en->g;
        pk->b = en->b;
        pk->a = on;
        sh = se->sh;
        if (p->frame == 255) {
            { Frame205d60* lf = &sh->frames[sh->count - 1]; if (lf->flags & 0x80) {
                f32 r;
                s32 k;
                /* hand-written VU0 random number */
                asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1"
                             : "=r"(r) : : "$8", "memory");
                k = r * (f32)(sh->count - 1);
                if (k < 0 || k >= sh->count) k = 0;
                p->frame = k;
            } }
        }
        fr = &sh->frames[p->frame];
        data = (u8*)sh + fr->off;
        sc = p->alpha / 255.0f;
        pos.x = p->x;
        pos.y = p->y;
        pos.z = p->z;
        pos.w = 1.0f;
        /* hand-written VU0: model = view * (world * scale(m) with translation pos) */
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "lqc2 $vf9, 0(%3)\n\tlqc2 $vf10, 16(%3)\n\tlqc2 $vf11, 32(%3)\n\tlqc2 $vf12, 48(%3)\n\t"
                     "lqc2 $vf13, 0(%0)\n\tlw $1, 0(%4)\n\tqmtc2 $1, $vf14\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf13x\n\tvmadday.wxyz ACC, $vf6, $vf13y\n\tvmaddaz.wxyz ACC, $vf7, $vf13z\n\tvmaddw.wxyz $vf4, $vf8, $vf13w\n\t"
                     "vmulx.wxyz $vf1, $vf1, $vf14x\n\tvmulx.wxyz $vf2, $vf2, $vf14x\n\tvmulx.wxyz $vf3, $vf3, $vf14x\n\t"
                     "vmulax.wxyz ACC, $vf9, $vf1x\n\tvmadday.wxyz ACC, $vf10, $vf1y\n\tvmaddaz.wxyz ACC, $vf11, $vf1z\n\tvmaddw.wxyz $vf1, $vf12, $vf1w\n\t"
                     "vmulax.wxyz ACC, $vf9, $vf2x\n\tvmadday.wxyz ACC, $vf10, $vf2y\n\tvmaddaz.wxyz ACC, $vf11, $vf2z\n\tvmaddw.wxyz $vf2, $vf12, $vf2w\n\t"
                     "vmulax.wxyz ACC, $vf9, $vf3x\n\tvmadday.wxyz ACC, $vf10, $vf3y\n\tvmaddaz.wxyz ACC, $vf11, $vf3z\n\tvmaddw.wxyz $vf3, $vf12, $vf3w\n\t"
                     "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
                     "sqc2 $vf1, 0(%5)\n\tsqc2 $vf2, 16(%5)\n\tsqc2 $vf3, 32(%5)\n\tsqc2 $vf4, 48(%5)"
                     : : "r"(&pos), "r"(mm), "r"(&D_01d9e730), "r"(&D_01d9e8c0), "r"(&sc), "r"(&D_01d9e6e8->m80) : "$1");
        pk->m[0] = D_01d9e6e8->m80.r[0];
        pk->m[1] = D_01d9e6e8->m80.r[1];
        pk->m[2] = D_01d9e6e8->m80.r[2];
        pk->m[3] = D_01d9e6e8->m80.r[3];
        func_0021cdd0(data, pk);
        pk->w0 = 10;
        if (D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
            u8 o = p->frame;
            p->frame = o + 1;
            if (p->frame >= sh->count) {
                if (fr->flags & 0x80) p->frame = 0;
                else p->frame = o;
            }
        }
    }
    func_001e7538();
    func_0020e0a0();
}
