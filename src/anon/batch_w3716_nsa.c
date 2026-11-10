#include "../common/types.h"
// w3716 _nsa, partial asm: empty asm keeps the offset base live to the end of the if block (no load gets its REG_DEAD), f4/f2 pins fix FP allocation.
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1e7da8;
typedef struct { V1e7da8 r[4]; } M1e7da8;
typedef struct { u8 pad0[128]; f32 tx, ty, tz; u8 pad1[144 - 140]; u8 m144[16]; f32 sx, sy, sz; u8 pad2[249 - 172]; u8 big; } Own1e7da8;
typedef struct {
    f32 x, y, z;
    u8 pad0[16 - 12];
    f32 rz, rx, ry;
    u8 pad1[32 - 28];
    f32 sx, sy, sz;
    u8 pad2[64 - 44];
    f32 bx, by, bz;
    u8 pad3[140 - 76];
    Own1e7da8* own;
    u8 pad4[170 - 144];
    u8 offset;
} Part1e7da8;
extern M1e7da8 D_01d9e6f0;
extern V1e7da8 D_01d9e7f0;
extern f32 D_00354be0[3];
extern f32 D_00354bd0[3];
extern u8 D_00354bc0[];
extern u8 D_01d9e720[];
void sceVu0UnitMatrix(M1e7da8*);
void sceVu0RotMatrixX(M1e7da8*, M1e7da8*, f32);
void sceVu0RotMatrixY(M1e7da8*, M1e7da8*, f32);
void sceVu0RotMatrixZ(M1e7da8*, M1e7da8*, f32);
void func_001e8fe0(M1e7da8*, void*);
void sceVu0MulMatrix(M1e7da8*, M1e7da8*, M1e7da8*);
void func_001e7d20(V1e7da8*, V1e7da8*);
f32 func_002f8ad0(f32, f32);
f32 func_002f8ab8(f32);
void sceVu0CopyVector(void*, void*);
/* libvu0 sceVu0ScaleVectorXYZ (VU0 macro code) */
static inline void scale1e7da8(V1e7da8* d, V1e7da8* v, f32 s)
{
    asm volatile("qmtc2 %2, $vf9\n\tlqc2 $vf10, 0(%1)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(d), "r"(v), "r"(s) : "memory");
}
void func_001e7da8(Part1e7da8* p)
{
    M1e7da8* m = &D_01d9e6f0;
    M1e7da8 o;
    f32 ang[3];
    s32 i;
    sceVu0UnitMatrix(m);
    sceVu0RotMatrixX(m, m, p->rz);
    sceVu0RotMatrixY(m, m, p->rx);
    sceVu0RotMatrixZ(m, m, p->ry);
    scale1e7da8(&m->r[0], &m->r[0], p->sx);
    scale1e7da8(&m->r[1], &m->r[1], p->sy);
    scale1e7da8(&m->r[2], &m->r[2], p->sz);
    if (p->own->big) {
        scale1e7da8(&m->r[0], &m->r[0], p->bx);
        scale1e7da8(&m->r[1], &m->r[1], p->by);
        scale1e7da8(&m->r[2], &m->r[2], p->bz);
    }
    m->r[3].x = p->x;
    m->r[3].y = p->y;
    m->r[3].z = p->z;
    func_001e8fe0(&o, p->own->m144);
    scale1e7da8(&o.r[0], &o.r[0], p->own->sx);
    scale1e7da8(&o.r[1], &o.r[1], p->own->sy);
    scale1e7da8(&o.r[2], &o.r[2], p->own->sz);
    o.r[3].x = p->own->tx;
    o.r[3].y = p->own->ty;
    o.r[3].z = p->own->tz;
    sceVu0MulMatrix(m, m, &o);
    if (p->offset) {
        V1e7da8* off = &D_01d9e7f0;
        f32 mx;
        f32 ox;
        f32 my;
        f32 mz;
        register f32 oz asm("$f4");
        register f32 oy asm("$f2");
        mx = m->r[3].x;
        ox = off->x;
        my = m->r[3].y;
        mz = m->r[3].z;
        oz = off->z;
        oy = off->y;
        mx += ox; mz += oz; my += oy;
        m->r[3].x = mx; m->r[3].z = mz; m->r[3].y = my;
        asm("" : : "r"(off));
    }
    for (i = 0; i < 3; i++) {
        func_001e7d20(&o.r[i], (V1e7da8*)((i << 4) + (u32)&D_01d9e6f0));
        D_00354be0[i] = o.r[i].w;
        o.r[i].w = 0.0f;
    }
    ang[0] = func_002f8ad0(-o.r[1].z, o.r[0].z);
    ang[1] = func_002f8ab8(-o.r[2].z);
    ang[2] = func_002f8ad0(o.r[2].y, o.r[2].x);
    for (i = 0; i < 3; i++) D_00354bd0[i] = ang[i];
    sceVu0CopyVector(D_00354bc0, D_01d9e720);
}
