#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V20bef8;
typedef struct { V20bef8 r[4]; } M20bef8;
typedef struct {
    u8 pad0[16]; u16 life; u8 fadeIn; u8 fadeOut; u8 pad20[16]; f32 acc[4]; u8 pad52[28]; s32 anga[3];
    u8 pad92[36]; f32 rota[3]; u8 pad140[20]; f32 f160; u8 pad164[12]; f32 f176; u8 pad180[20]; f32 f200;
    u8 pad204[8]; f32 f212, f216, f220; u8 pad224[19];
    u8 s;
    u8 r;
} Src20bef8;
typedef struct {
    V20bef8 pos; V20bef8 vel; u16 h32; u8 pad34[6]; s32 ang[3]; s32 angv[3]; s32 anga[3]; u8 pad76[8];
    f32 rot[3]; f32 rotv[3]; f32 rota[3]; f32 speed; f32 u, v, du, dv; u8 pad140[8]; f32 alpha;
    union { u64 all; u8 cnt; } f;
} Dst20bef8;
typedef struct { f32 x, y, z, w, vx, vy, vz, vw; } Cf20bef8;
extern V20bef8 D_01d9e7f0;
extern V20bef8 D_01da8ba0;
extern M20bef8 D_01d9ea40;
void func_002f4870(V20bef8*, V20bef8*, f32);
void func_002f3ef8(V20bef8*, V20bef8*, V20bef8*);
void func_002f3f10(V20bef8*, V20bef8*, V20bef8*);
void func_002f3d98(V20bef8*, V20bef8*);
f32 func_002f3d70(V20bef8*, V20bef8*);
f32 func_0020b410(void);
void func_002f4298(M20bef8*, M20bef8*, V20bef8*);
void func_002f3cd8(V20bef8*, M20bef8*, V20bef8*);
void func_002f3f40(V20bef8*, V20bef8*, f32);
void func_0020b4e8(Src20bef8*, Dst20bef8*, f32*);
void func_0020bef8(void* unused, Src20bef8* s, Dst20bef8* d, void* unused2, Cf20bef8* cf)
{
    V20bef8 v;
    V20bef8 n;
    V20bef8 t;
    M20bef8 m;
    f32 dist;
    s32 i;
    if (cf) {
        cf->x += cf->vx;
        cf->y += cf->vy;
        cf->z += cf->vz;
        cf->w += cf->vw;
        cf->vx += s->acc[0];
        cf->vy += s->acc[1];
        cf->vz += s->acc[2];
        cf->vw += s->acc[3];
    }
    for (i = 0; i < 3; i++) d->ang[i] += d->angv[i];
    if (s->r & 0x10) {
        d->angv[0] += s->anga[0] + d->anga[0];
        d->angv[1] += s->anga[1] + d->anga[1];
        d->angv[2] += s->anga[2] + d->anga[2];
    } else {
        d->angv[0] += s->anga[0];
        d->angv[1] += s->anga[1];
        d->angv[2] += s->anga[2];
    }
    for (i = 0; i < 3; i++) {
        s32* w = (s32*)&d->h32; /* the original indexes this block as words from +32 */
        if (w[i + 2] > 0x7fff) {
            while (w[i + 2] > 0x7fff) w[i + 2] -= 0x10000;
        } else if (w[i + 2] < -0x8000) {
            while (w[i + 2] > 0x7fff) w[i + 2] += 0x10000;
        }
    }
    for (i = 0; i < 3; i++) d->rot[i] += d->rotv[i];
    if (s->s & 0x10) {
        d->rotv[0] += s->rota[0] + d->rota[0];
        d->rotv[1] += s->rota[1] + d->rota[1];
        d->rotv[2] += s->rota[2] + d->rota[2];
    } else {
        d->rotv[0] += s->rota[0];
        d->rotv[1] += s->rota[1];
        d->rotv[2] += s->rota[2];
    }
    d->speed += s->f200;
    func_002f4870(&n, &d->vel, d->speed);
    func_002f3ef8(&d->pos, &d->pos, &n);
    d->pos.w = 1.0f;
    func_002f3f10(&v, &d->pos, &D_01d9e7f0);
    func_002f3d98(&n, &v);
    n.w = 1.0f;
    {
        /* hand-written VU0 vector length */
        asm volatile("lqc2 $vf10, 0(%1)\n\tvmul.xyz $vf10, $vf10, $vf10\n\tvaddx.y $vf10, $vf10, $vf10x\n\tvaddy.z $vf10, $vf10, $vf10y\n\tvsqrt Q, $vf10z\n\tvwaitq\n\tvaddq.x $vf10, $vf0, Q\n\tqmfc2 %0, $vf10"
                     : "=r"(dist) : "r"(&v) );
    }
    d->u += d->du;
    d->v += d->dv;
    d->du += s->f160;
    d->dv += s->f176;
    while (d->u > 2048.0f) d->u -= 2048.0f;
    while (d->v > 2048.0f) d->v -= 2048.0f;
    if (d->du > 2048.0f) d->du = 2048.0f;
    if (d->dv > 2048.0f) d->dv = 2048.0f;
    if (s->life && s->life != 0xffff) d->h32--;
    if (d->f.all & 0x200) {
        if (d->f.cnt) {
            d->alpha = 1.0f - (f32)d->f.cnt / s->fadeIn;
            d->f.cnt--;
        } else {
            d->alpha = 1.0f;
            d->f.all &= ~0x200;
        }
    } else if (d->f.all & 0x400) {
        if (d->f.cnt) {
            d->alpha = (f32)d->f.cnt / (f32)s->fadeIn;
            d->f.cnt--;
        } else {
            d->alpha = 0.0f;
            d->f.all &= ~0x400;
        }
    } else {
        if (s->fadeOut && s->fadeOut >= d->h32) {
            d->f.cnt = s->fadeOut;
            d->f.all |= 0x400;
        }
        d->alpha = 1.0f;
    }
    if (s->f216 + s->f220 < dist) d->alpha = 0.0f;
    else if (s->f216 < dist) d->alpha *= 1.0f - (dist - s->f216) / s->f212;
    if (func_002f3d70(&n, &D_01da8ba0) < 0.0f) d->f.all |= 0x100;
    else d->f.all &= ~0x100;
    {
        f32 far = s->f216 + s->f220;
        if (far < dist) {
            for (i = 0; i < 3; i++) (&t.x)[i] = func_0020b410() * 1.2566371f - 0.62831855f;
            func_002f4298(&m, &D_01d9ea40, &t);
            func_002f3cd8(&t, &m, &n);
            func_002f3f40(&t, &t, -far);
            func_002f3ef8(&d->pos, &D_01d9e7f0, &t);
            d->pos.w = 1.0f;
            func_0020b4e8(s, d, (f32*)cf);
        }
    }
}
