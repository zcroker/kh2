#include "../common/types.h"
extern "C" {

// VU0 macro helpers (libvu0-style inline asm): matrix copy, row clear,
// 3x3 inverse with translation, apply, normalize.
typedef f32 W2048V4[4] __attribute__((aligned(16)));
struct W2048M4 { W2048V4 r[4]; };
struct W2048V3 { f32 x, y, z; };
struct W2048Src { W2048V3 a[3]; W2048V3 b[4]; };
struct W2048Dst { W2048V4 r[3]; W2048V4 p[4]; };

static inline void w2048_mcopy(W2048M4* d, W2048M4* s) {
    asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)" : : "r"(d), "r"(s) : "$8","$9","$10","$11","memory");
}
static inline void w2048_vzero(f32* v) {
    asm volatile("vsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" : : "r"(v) : "memory");
}
static inline void w2048_vinv(W2048M4* d, W2048M4* s) {
    asm volatile(
"lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"vopmula.xyz ACC,$vf2,$vf3\n\tvopmsub.xyz $vf5,$vf3,$vf2\n\t"
"vopmula.xyz ACC,$vf3,$vf1\n\tvopmsub.xyz $vf6,$vf1,$vf3\n\t"
"vopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf7,$vf2,$vf1\n\t"
"vmul.xyz $vf8,$vf1,$vf5\n\tvmul.xyz $vf1,$vf4,$vf5\n\tvmul.xyz $vf2,$vf4,$vf6\n\tvmul.xyz $vf3,$vf4,$vf7\n\t"
"vaddy.x $vf8,$vf8,$vf8y\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddx.y $vf2,$vf2,$vf2x\n\tvaddx.z $vf3,$vf3,$vf3x\n\t"
"vaddz.x $vf8,$vf8,$vf8z\n\tvaddz.x $vf4,$vf1,$vf1z\n\tvaddz.y $vf4,$vf2,$vf2z\n\tvaddy.z $vf4,$vf3,$vf3y\n\t"
"vdiv Q,$vf0w,$vf8x\n\t"
"qmfc2 $8,$vf5\n\tqmfc2 $9,$vf6\n\tqmfc2 $10,$vf7\n\tqmfc2 $11,$vf0\n\t"
"pextlw $12,$9,$8\n\tpextuw $13,$9,$8\n\tpextlw $14,$11,$10\n\tpextuw $15,$11,$10\n\t"
"pcpyld $8,$14,$12\n\tpcpyud $9,$12,$14\n\tpcpyld $10,$15,$13\n\t"
"qmtc2 $8,$vf1\n\tqmtc2 $9,$vf2\n\tqmtc2 $10,$vf3\n\t"
"vsub.xyz $vf4,$vf0,$vf4\n\tvwaitq\n\t"
"vmulq.wxyz $vf1,$vf1,Q\n\tvmulq.wxyz $vf2,$vf2,Q\n\tvmulq.wxyz $vf3,$vf3,Q\n\tvmulq.xyz $vf4,$vf4,Q\n\t"
"sqc2 $vf1,0(%0)\n\tsqc2 $vf2,16(%0)\n\tsqc2 $vf3,32(%0)\n\tsqc2 $vf4,48(%0)"
    : : "r"(d), "r"(s) : "$8","$9","$10","$11","$12","$13","$14","$15","memory");
}
static inline void w2048_vapply(f32* o, W2048M4* m, f32* v) {
    asm volatile(
"lqc2 $vf5,0(%2)\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
"vmulax.xyz ACC,$vf1,$vf5x\n\tvmadday.xyz ACC,$vf2,$vf5y\n\tvmaddaz.xyz ACC,$vf3,$vf5z\n\tvmaddw.xyz $vf5,$vf4,$vf0w\n\t"
"vmove.w $vf5,$vf0\n\tsqc2 $vf5,0(%0)" : : "r"(o), "r"(m), "r"(v) : "memory");
}
static inline f32 w2048_vnorm(f32* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tvmul.xyz $vf2,$vf1,$vf1\n\tvaddy.x $vf2,$vf2,$vf2y\n\tvaddz.x $vf2,$vf2,$vf2z\n\tvsqrt Q,$vf2x\n\tvwaitq\n\tcfc2.ni $8,$vi22\n\tvaddq.x $vf2,$vf0,Q\n\tmtc1 $8,%0\n\tvnop\n\tvdiv Q,$vf0w,$vf2x\n\tvwaitq\n\tvmulq.xyz $vf1,$vf1,Q\n\tsqc2 $vf1,0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// builds a 3-row normal basis from the inverse of m and copies 4 points
void func_001349a8(W2048Dst* d, W2048M4* sm, W2048Src* s) {
    W2048M4 m; w2048_mcopy(&m, sm);
    W2048V4 v, o;
    f32* r0 = d->r[0]; w2048_vzero(r0);
    f32* r1 = d->r[1]; w2048_vzero(r1);
    f32* r2 = d->r[2]; w2048_vzero(r2);
    w2048_vinv(&m, &m);
    W2048V4* p = d->p;
    v[3] = 1.0f;
    for (s32 i = 0; i < 3; i++) {
        v[0] = s->a[i].x; v[1] = s->a[i].y; v[2] = s->a[i].z;
        w2048_vapply(o, &m, v);
        o[1] = -o[1]; o[2] = -o[2]; o[3] = 0.0f;
        w2048_vnorm(o);
        s32 k = i * 4;
        *(f32*)((u8*)r0 + k) = o[0]; *(f32*)((u8*)r1 + k) = o[1]; *(f32*)((u8*)r2 + k) = o[2];
        p[i][0] = s->b[i].x; p[i][1] = s->b[i].y; p[i][2] = s->b[i].z; p[i][3] = 1.0f;
    }
    d->p[3][0] = s->b[3].x; d->p[3][1] = s->b[3].y; d->p[3][2] = s->b[3].z; d->p[3][3] = 1.0f;
}
}
