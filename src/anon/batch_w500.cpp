#include "../common/types.h"

extern "C" {

// 2D sprite keyframe animation (func_0023ade0 draws one animated sprite).
// One keyframe of the track (0x90 bytes).
struct SprKey {
    u32 flags;        // 0x00
    s32 image;        // 0x04
    s32 start;        // 0x08 first frame
    s32 end;          // 0x0c last frame
    s32 x[2];         // 0x10
    s32 y[2];         // 0x18
    s32 u[2];         // 0x20
    s32 v[2];         // 0x28
    f32 pos[3][2];    // 0x30 (x0,x1,y0,y1,z0,z1)
    f32 scale[3][2];  // 0x48
    f32 ease[2][2];   // 0x60
    f32 amp[2][2];    // 0x70 wobble amplitude x, y
    u16 freq[2];      // 0x80 wobble frequency x, y
    s32 blend;        // 0x84
    u8 rgba[2][4];    // 0x88
};

struct SprAnim;
typedef void (*SprAnimCb)(SprAnim*, s32);

struct SprAnim {
    u8 pad00[0x10];
    union { u32 state; f32 stateF; };        // 0x10
    u8 pad14[0x40 - 0x14];
    void* image;      // 0x40
    u8 pad44[0x68 - 0x44];
    s32 imageNo;      // 0x68
    u8 pad6c[0x88 - 0x6c];
    u32 color;        // 0x88
    u8 pad8c[0xb8 - 0x8c];
    s32 mode;         // 0xb8
    u8 padbc[0xc4 - 0xbc];
    SprKey* keys;     // 0xc4
    s32 nkeys;        // 0xc8
    f32 time;         // 0xcc
    u32 baseColor;    // 0xd0
    u8 padd4[0xf0 - 0xd4];
    SprAnimCb cb;     // 0xf0
    u8 padf4[0xfc - 0xf4];
    s32 visible;      // 0xfc
    u8 pad100[0x110 - 0x100];
    s32 cbCount;      // 0x110
    u8 pad114[0x118 - 0x114];
    f32 colorMul[4];  // 0x118 r,g,b,a
    f32 ofs[3];       // 0x128
    f32 scl[3];       // 0x134
    u8 pad140[0x148 - 0x140];
    s32 px;           // 0x148
    s32 py;           // 0x14c
};

void YI_IMAGE_LoadImage(void*) asm("_ZN2YI5IMAGE9LoadImageEv");
u32 func_002f35e8(s32);
void func_002f3918(u32, void*);
void func_002376d8(SprAnim*, s32);
void func_00237740(SprAnim*, f32, f32, f32);
void func_00237a68(SprAnim*, f32, f32, f32);
void func_00238570(SprAnim*, s32, s32, s32, s32);
void func_00238c90(SprAnim*, s32, s32, s32, s32);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
u32 func_00313bc0(f32) __attribute__((const)); // __fixunssfsi (float -> u32)

extern u8 D_0035e3c0[];
extern u8 D_01dae590[][0x30];
extern u8 D_01dae5f0[][0x30];

#define ILERP(a, b, t) ((a) + (s32)((f32)((b) - (a)) * (t)))
#define FLERP(a, b, t) ((a) + ((b) - (a)) * (t))

void func_0023ade0(SprAnim* o)
{
    if (o->visible == 0) return;
    if ((u32)(o->px + 0x200) > 0x600) return;
    if (o->py < -0x1a0) return;
    if (o->py > 0x340) return;

    if ((u8)((o->mode >> 3) & 1)) YI_IMAGE_LoadImage(o->image);
    u8* img = (u8*)o->image;
    func_002f3918(func_002f35e8(2), img + 0x100);
    if (((o->state >> 1) & 1) == 1) func_002f3918(func_002f35e8(2), D_0035e3c0);

    s32 n = o->nkeys;
    SprKey* k = o->keys;
    for (; n > 0; n--, k++) {
        f32 fr[2]; // key start/end frame (kept in memory like the original)
        fr[0] = (f32)k->start;
        if (!(fr[0] <= o->time)) continue;
        if (fr[0] == o->time && o->cb && (k->flags & 0x80000)) {
            o->cb(o, o->cbCount++);
        }
        fr[1] = (f32)k->end;
        if (fr[1] < o->time) continue;
        if (o->time == fr[1] && (k->flags & 0x8000)) continue;

        if (o->imageNo != k->image) func_002376d8(o, k->image);

        if (!(o->mode & 0x10)) {
            func_002f3918(func_002f35e8(2), D_01dae590[(k->flags >> 2) & 1]);
        } else if (o->mode & 0x2000) {
            func_002f3918(func_002f35e8(2), D_01dae590[1]);
        }
        if (!(o->mode & 0x20)) {
            func_002f3918(func_002f35e8(2), D_01dae5f0[k->blend]);
        }

        f32 d = fr[1] - fr[0];
        f32 t;
        if (d != 0.0f) t = (o->time - fr[0]) / d;
        else t = 1.0f;

        // Unless the key is linear, ease t with a cubic Bezier (control points 1, 1-e0, 1-e1, 0).
        if ((k->flags & 1) != 1) {
            f32 u = 1.0f - t;
            f32 c3 = 3.0f;
            f32 tt = t * t;
            f32 uu = u * u;
            t = 1.0f - (uu * u + uu * c3 * t * (1.0f - k->ease[0][1])
                        + u * c3 * tt * (1.0f - k->ease[1][1]) + tt * t * 0.0f);
        }

        if ((o->mode & 1) == 1) {
            o->state &= ~8;
            if (k->flags & 0x20) {
                func_00237740(o, o->ofs[0], o->ofs[1], o->ofs[2]);
            } else {
                f32 z = FLERP(k->pos[2][0], k->pos[2][1], t) + o->ofs[2];
                f32 y = FLERP(k->pos[1][0], k->pos[1][1], t) + o->ofs[1];
                f32 x = FLERP(k->pos[0][0], k->pos[0][1], t) + o->ofs[0];
                func_00237740(o, x, y, z);
            }
        } else if (k->flags & 0x20) {
            o->state |= 8;
        } else {
            o->state &= ~8;
            f32 z = FLERP(k->pos[2][0], k->pos[2][1], t);
            f32 y = FLERP(k->pos[1][0], k->pos[1][1], t);
            f32 x = FLERP(k->pos[0][0], k->pos[0][1], t);
            func_00237740(o, x, y, z);
        }

        if (o->mode & 2) {
            o->state &= ~0x10;
            if (k->flags & 0x40) {
                func_00237a68(o, o->scl[0], o->scl[1], o->scl[2]);
            } else {
                f32 z = o->scl[2] * FLERP(k->scale[2][0], k->scale[2][1], t);
                f32 y = o->scl[1] * FLERP(k->scale[1][0], k->scale[1][1], t);
                f32 x = o->scl[0] * FLERP(k->scale[0][0], k->scale[0][1], t);
                func_00237a68(o, x, y, z);
            }
        } else if (k->flags & 0x40) {
            o->state |= 0x10;
        } else {
            o->state &= ~0x10;
            f32 z = FLERP(k->scale[2][0], k->scale[2][1], t);
            f32 y = FLERP(k->scale[1][0], k->scale[1][1], t);
            f32 x = FLERP(k->scale[0][0], k->scale[0][1], t);
            func_00237a68(o, x, y, z);
        }

        if (o->mode & 4) {
            o->state &= ~0x20;
            if (k->flags & 0x400) {
                o->color = o->baseColor;
            } else {
                if (k->flags & 0x80) {
                    u32 r = func_00313bc0((f32)k->rgba[0][0] * o->colorMul[0]);
                    r |= func_00313bc0((f32)k->rgba[0][3] * o->colorMul[3]) << 24;
                    u32 b = func_00313bc0((f32)k->rgba[0][2] * o->colorMul[2]) << 16;
                    b |= func_00313bc0((f32)k->rgba[0][1] * o->colorMul[1]) << 8;
                    r |= b;
                    o->color = r;
                } else {
                    u32 r = func_00313bc0((f32)ILERP(k->rgba[0][0], k->rgba[1][0], t) * o->colorMul[0]);
                    r |= func_00313bc0((f32)ILERP(k->rgba[0][3], k->rgba[1][3], t) * o->colorMul[3]) << 24;
                    u32 b = func_00313bc0((f32)ILERP(k->rgba[0][2], k->rgba[1][2], t) * o->colorMul[2]) << 16;
                    b |= func_00313bc0((f32)ILERP(k->rgba[0][1], k->rgba[1][1], t) * o->colorMul[1]) << 8;
                    r |= b;
                    o->color = r;
                }
            }
        } else if (k->flags & 0x400) {
            o->state |= 0x20;
        } else if (k->flags & 0x80) {
            o->state &= ~0x20;
            o->color = *(u32*)k->rgba[0];
        } else {
            o->state &= ~0x20;
            o->color = ILERP(k->rgba[0][0], k->rgba[1][0], t) | ((ILERP(k->rgba[0][3], k->rgba[1][3], t) << 24) | ((ILERP(k->rgba[0][2], k->rgba[1][2], t) << 16) | (ILERP(k->rgba[0][1], k->rgba[1][1], t) << 8)));
        }

        s32 x, y;
        if (o->mode & 0x400) {
            x = k->x[0];
            y = k->y[0];
        } else {
            x = ILERP(k->x[0], k->x[1], t);
            y = ILERP(k->y[0], k->y[1], t);
            if (!(k->flags & 0x10)) {
                f32 ax = FLERP(k->amp[0][0], k->amp[0][1], t);
                f32 ay = FLERP(k->amp[1][0], k->amp[1][1], t);
                if (!(k->flags & 8)) {
                    f32 a = t * 3.1415927f;
                    x += (s32)(ax * func_002f8960(a * (f32)k->freq[0]));
                    y += (s32)(ay * func_002f8960(a * (f32)k->freq[1]));
                } else {
                    f32 a = t * 3.1415927f;
                    x += (s32)(ax * func_002f87c0(a * (f32)k->freq[0]));
                    y += (s32)(ay * func_002f87c0(a * (f32)k->freq[1]));
                }
            }
        }

        s32 cu = 0, cv = 0;
        if (!(k->flags & 0x4000)) {
            cu = ILERP(k->u[0], k->u[1], t);
            cv = ILERP(k->v[0], k->v[1], t);
        }
        if (!(o->mode & 0x200)) {
            func_00238570(o, o->px + x, o->py + y, cu, cv);
        } else {
            func_00238c90(o, o->px + x, o->py + y, cu, cv);
        }
    }
}

}
