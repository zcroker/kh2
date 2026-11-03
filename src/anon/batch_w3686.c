#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V20a658;
typedef struct { V20a658 r[4]; } M20a658;
typedef struct {
    u8 pad0[20]; u16 life; u8 fadeIn; u8 fadeOut; u8 pad24[16]; f32 acc[4]; u8 pad56[28]; f32 f84, f88;
    u8 pad92[24]; f32 f116; u8 pad120[20]; f32 f140; u8 pad144[8]; f32 f152, f156, f160; u8 pad164[19];
    u8 s;
    u8 r;
} Src20a658;
typedef struct {
    V20a658 pos; V20a658 vel; u8 pad32[6]; u16 h38; u8 pad40[4]; f32 f44, f48, f52, f56, f60, f64, f68, f72, f76, f80, f84;
    union { u64 all; u8 cnt; } f;
} Dst20a658;
typedef struct { f32 x, y, z, w, vx, vy, vz, vw; } Cf20a658;
extern V20a658 D_01d9e7f0;
extern V20a658 D_01da8b90;
extern M20a658 D_01d9ea40;
void func_002f4870(V20a658*, V20a658*, f32);
void func_002f3ef8(V20a658*, V20a658*, V20a658*);
void func_002f3f10(V20a658*, V20a658*, V20a658*);
void func_002f3d98(V20a658*, V20a658*);
f32 func_002f3d70(V20a658*, V20a658*);
f32 func_00209fb8(void);
void func_002f4298(M20a658*, M20a658*, V20a658*);
void func_002f3cd8(V20a658*, M20a658*, V20a658*);
void func_002f3f40(V20a658*, V20a658*, f32);
void func_0020a090(Src20a658*, Dst20a658*, f32*);
void func_0020a658(void* unused, Src20a658* s, Dst20a658* d, void* unused2, Cf20a658* cf)
{
    V20a658 v;
    V20a658 n;
    V20a658 t;
    M20a658 m;
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
    d->f44 += d->f48;
    if (s->r & 0x10) d->f48 += s->f116 + d->f52;
    else d->f48 += s->f116;
    while (d->f44 >= 180.0f) d->f44 -= 360.0f;
    while (d->f44 < -180.0f) d->f44 += 360.0f;
    d->f56 += d->f64;
    d->f60 += d->f68;
    if (s->s & 0x10) {
        d->f64 += s->f84 + d->f72;
        d->f68 += s->f88 + d->f76;
    } else {
        d->f64 += s->f84;
        d->f68 += s->f88;
    }
    d->f80 += s->f140;
    func_002f4870(&n, &d->vel, d->f80);
    func_002f3ef8(&d->pos, &d->pos, &n);
    d->pos.w = 1.0f;
    func_002f3f10(&v, &d->pos, &D_01d9e7f0);
    func_002f3d98(&n, &v);
    n.w = 1.0f;
    {
        union { s32 i; f32 f; } r;
        /* hand-written VU0 vector length */
        asm volatile("lqc2 $vf10, 0(%1)\n\tvmul.xyz $vf10, $vf10, $vf10\n\tvaddx.y $vf10, $vf10, $vf10x\n\tvaddy.z $vf10, $vf10, $vf10y\n\tvsqrt Q, $vf10z\n\tvwaitq\n\tvaddq.x $vf10, $vf0, Q\n\tqmfc2 %0, $vf10"
                     : "=r"(r.i) : "r"(&v) : "memory");
        dist = r.f;
    }
    if (s->life && s->life != 0xffff) d->h38--;
    if (d->f.all & 0x200) {
        if (d->f.cnt) {
            {
f32 a, b, one;
a = (f32)d->f.cnt;
b = (f32)s->fadeIn;
d->f.cnt--;
/* empty asm: keeps the 1.0 literal load (reload reg) after fadeIn dies */
asm volatile("");
one = 1.0f;
/* empty asm: keeps the decremented counter live across the literal load */
asm volatile("" : : "r"(d->f.cnt), "f"(one));
                d->f84 = one - a / b;
            }
        } else {
            d->f84 = 1.0f;
            d->f.all &= ~0x200;
        }
    } else if (d->f.all & 0x400) {
        if (d->f.cnt) {
            d->f84 = (f32)d->f.cnt / (f32)s->fadeIn;
            d->f.cnt--;
        } else {
            d->f84 = 0.0f;
            d->f.all &= ~0x400;
        }
    } else {
        if (s->fadeOut && s->fadeOut >= d->h38) {
            d->f.cnt = s->fadeOut;
            d->f.all |= 0x400;
        }
        d->f84 = 1.0f;
    }
    if (s->f156 + s->f160 < dist) d->f84 = 0.0f;
    else if (s->f156 < dist) d->f84 *= 1.0f - (dist - s->f156) / s->f152;
    if (func_002f3d70(&n, &D_01da8b90) < 0.0f) d->f.all |= 0x100;
    else d->f.all &= ~0x100;
    {
        f32 far = s->f156 + s->f160;
        if (far < dist) {
            for (i = 0; i < 3; i++) (&t.x)[i] = func_00209fb8() * 1.2566371f - 0.62831855f;
            func_002f4298(&m, &D_01d9ea40, &t);
            func_002f3cd8(&t, &m, &n);
            func_002f3f40(&t, &t, -far);
            func_002f3ef8(&d->pos, &D_01d9e7f0, &t);
            d->pos.w = 1.0f;
            func_0020a090(s, d, (f32*)cf);
        }
    }
}
