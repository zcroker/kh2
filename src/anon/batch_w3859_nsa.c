#include "../common/types.h"

/* 0021f0d8: builds an object's billboard/flare matrix and alpha from the camera (D_01d9e840 view, D_01d9e8c0 projection).
 * mode != 0: object-relative direction; otherwise projected screen positions. The facing matrix is built
 * with a VU0 macro sequence (partial inline asm). */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct {
    f32 m[4][4];        /* 0x00 world matrix */
    f32 r[3][4];        /* 0x40 facing rows */
    f32 v[4];           /* 0x70 x, y, scale, alpha */
    f32 ofs[3];         /* 0x80 */
    u8 pad8c[2];
    u8 near;            /* 0x8e */
    u8 mode;            /* 0x8f */
    f32 dir[4];         /* 0x90 (w = cone) */
    f32 pada0;
    f32 len;            /* 0xa4 */
    f32 range;          /* 0xa8 */
} ObjF0d8;
typedef struct { ObjF0d8* obj; f32* pos; f32 (*mat)[4]; } ArgF0d8;
extern f32 D_01d9e840[4][4];
extern f32 D_01d9e8c0[4][4];
void sceVu0CopyMatrix(f32 (*)[4], f32 (*)[4]);
void sceVu0ApplyMatrix(f32*, f32 (*)[4], f32*);
void sceVu0ScaleVector(f32*, f32*, f32);
void sceVu0SubVector(f32*, f32*, f32*);
void sceVu0UnitMatrix(f32 (*)[4]);
void sceVu0CopyVector(f32*, f32*);
void sceVu0Normalize(f32*, f32*);
f32 sceVu0InnerProduct(f32*, f32*);
void sceVu0MulMatrix(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
f32 func_002229a0(f32*);
f32 func_002229d8(f32*);

void func_0021f0d8(ArgF0d8* a)
{
    f32 m[4][4];
    f32 l[4][4];
    f32 va[4];
    f32 vb[4];
    f32 vc[4];
    ObjF0d8* o;
    f32 k, d, t;
    o = a->obj;
    sceVu0CopyMatrix(l, a->mat);
    if (o->mode) {
        sceVu0CopyMatrix(m, l);
        m[3][0] = 0.0f;
        m[3][1] = 0.0f;
        m[3][2] = 0.0f;
        sceVu0ApplyMatrix(va, m, a->pos);
        sceVu0ScaleVector(vb, l[3], -1.0f);
        sceVu0SubVector(vc, vb, va);
    } else {
        k = 1.0f;
        *(u128*)va = 0;
        *(u128*)vb = 0;
        va[3] = k;
        vb[3] = k;
        sceVu0UnitMatrix(m);
        m[3][0] = D_01d9e840[3][0] + o->ofs[0];
        m[3][1] = D_01d9e840[3][1] + o->ofs[1];
        m[3][2] = D_01d9e840[3][2] + o->ofs[2];
        sceVu0MulMatrix(m, D_01d9e8c0, m);
        sceVu0ApplyMatrix(va, m, va);
        sceVu0ScaleVector(va, va, k / va[3]);
        sceVu0UnitMatrix(m);
        sceVu0CopyVector(m[3], D_01d9e840[3]);
        sceVu0MulMatrix(m, D_01d9e8c0, m);
        sceVu0ApplyMatrix(vb, m, vb);
        k = k / vb[3];
        sceVu0ScaleVector(vb, vb, k);
        sceVu0SubVector(vc, vb, va);
        vc[2] = 512.0f;
    }
    sceVu0UnitMatrix(o->m);
    sceVu0ApplyMatrix(o->m[3], l, a->pos);
    if (vc[0] == 0.0f && vc[1] == 0.0f) {
        sceVu0CopyVector(o->v, o->m[3]);
    } else {
        asm volatile(
            "lqc2 $vf18, 0(%0)\n"
            "vmul.xy $vf26, $vf18, $vf18\n"
            "vaddy.x $vf26, $vf26, $vf26y\n"
            "vsqrt Q, $vf26x\n"
            "vsub.wz $vf22, $vf0, $vf0\n"
            "vsub.w $vf21, $vf0, $vf0\n"
            "vsub.wxy $vf20, $vf0, $vf0\n"
            "vaddw.z $vf20, $vf0, $vf0w\n"
            "sqc2 $vf20, 32(%1)\n"
            "vwaitq\n"
            "vaddq.x $vf26, $vf0, Q\n"
            "vdiv Q, $vf0w, $vf26x\n"
            "lqc2 $vf17, 0(%2)\n"
            "sqc2 $vf17, 48(%1)\n"
            "vwaitq\n"
            "vmulq.xy $vf22, $vf18, Q\n"
            "sqc2 $vf22, 0(%1)\n"
            "vopmula.xyz ACC, $vf22, $vf20\n"
            "vopmsub.xyz $vf21, $vf20, $vf22\n"
            "sqc2 $vf21, 16(%1)\n"
            : : "r"(vc), "r"(o->r), "r"(o->m[3]) : "memory");
    }
    if (o->mode) {
        o->v[2] = o->m[3][2] * 0.001953125f;
    } else {
        o->v[2] = (D_01d9e840[3][2] + o->ofs[2]) * 0.001953125f;
    }
    sceVu0Normalize(vc, vc);
    o->v[0] = vc[0] * o->v[2];
    o->v[1] = vc[1] * o->v[2];
    sceVu0SubVector(vb, vb, va);
    d = func_002229a0(vb);
    o->len = func_002229d8(vb);
    sceVu0Normalize(va, vb);
    if (o->mode) {
        vb[0] = 0.0f;
        vb[1] = 0.0f;
        vb[2] = k = 1.0f;
        vb[0] = (k - (k - sceVu0InnerProduct(vb, va)) * 0.5f) / 0.3f;
        o->v[3] = (k < vb[0]) ? 0.0f : k - vb[0];
        if (o->dir[3] >= 0.0f) {
            sceVu0CopyMatrix(m, l);
            m[3][0] = 0.0f;
            m[3][1] = 0.0f;
            m[3][2] = 0.0f;
            sceVu0ApplyMatrix(vb, m, vb);
            vb[0] = (1.0f - sceVu0InnerProduct(o->dir, va)) * 0.5f;
            vb[0] = vb[0] / o->dir[3];
            vb[0] = (1.0f < vb[0]) ? 0.0f : 1.0f - vb[0];
            o->v[3] = o->v[3] * vb[0];
        }
        va[0] = o->range - o->near;
        if (va[0] > 0.0f) {
            va[0] = d / va[0];
            d = (1.0f <= va[0]) ? 0.0f : 1.0f - va[0];
            o->v[3] = o->v[3] * d;
        } else {
            o->v[3] = 0.0f;
        }
    } else {
        if (o->range > 0.0f) {
            o->v[3] = o->len / o->range;
            o->v[3] = (1.0f < o->v[3]) ? 0.0f : 1.0f - o->v[3];
        } else {
            o->v[3] = 0.0f;
        }
    }
}



