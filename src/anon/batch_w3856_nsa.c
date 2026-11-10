/* 001f46f8: partMng particle colour/size update (C, -fno-strict-aliasing). Parameter and particle colours share struct type C46 so gcc lets parameter loads pass stores of other fields. fdiv46 is a non-volatile "nop;nop;div.s" asm helper (partial asm): non-volatile so it is not a scheduling barrier, which fixes the last lhu/addu order. */
#include "../common/types.h"
typedef unsigned int u128_46 __attribute__((mode(TI)));
asm("dpmul = func_00313f40");
asm("litodp = func_00314330");
asm("dptofp = __truncdfsf2");

typedef struct { u16 r, g, b, a; } C46;
typedef struct { u8 pad[0x80]; u8* tbl; u8 pad84[0x24]; u64 flags; } M46;
typedef struct { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; } K46;

/* emitter parameters */
typedef struct {
    s32 id;          /* 0x00 */
    s32 tex;         /* 0x04 */
    s32 texofs;      /* 0x08 */
    C46 col[4];      /* 0x0c */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    f32 f40;         /* 0x40 */
    f32 f44;         /* 0x44 */
    f32 f48;         /* 0x48 */
    f32 f4c;         /* 0x4c */
    u16 angle;       /* 0x50 */
    u8 b52;          /* 0x52 */
    u8 b53;          /* 0x53 */
    u8 pad54;
    u8 fl55;         /* 0x55 */
    u8 fl56;         /* 0x56 */
    u8 fl57;         /* 0x57 */
    u8 fl58;         /* 0x58 */
} P46;

/* particle state at owner + ofs + 160 */
typedef struct {
    u8 pad0[4];
    u8 flags;        /* 0x04 */
    u8 pad5[0x10 - 5];
    u8 c0[8];        /* 0x10 */
    u8 pad18[4];
    f32 f1c;         /* 0x1c */
    s8 c1[8];        /* 0x20 */
    f32 f28;         /* 0x28 */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    f32 f40;         /* 0x40 */
    f32 f44;         /* 0x44 */
    f32 f48;         /* 0x48 */
    f32 f4c;         /* 0x4c */
    u8 b50;          /* 0x50 */
    u8 b51;          /* 0x51 */
    u8 n;            /* 0x52 */
    u8 pad53[0x60 - 0x53];
    u8* data;        /* 0x60 */
    void* tex;       /* 0x64 */
    f32 f68;         /* 0x68 */
    f32 f6c;         /* 0x6c */
    C46 col[4];      /* 0x70 */
} E46;

typedef struct {
    u8 c0[8];        /* 0x00 */
    u8 pad8[4];
    f32 size;        /* 0x0c */
    s8 c1[8];        /* 0x10 */
    f32 f18;         /* 0x18 */
    f32 f1c;         /* 0x1c */
    f32 f20;         /* 0x20 */
    f32 f24;         /* 0x24 */
    f32 f28;         /* 0x28 */
    f32 f2c;         /* 0x2c */
    f32 f30;         /* 0x30 */
    f32 f34;         /* 0x34 */
    f32 f38;         /* 0x38 */
    f32 f3c;         /* 0x3c */
    u8 b40;          /* 0x40 */
    u8 b41;          /* 0x41 */
    u8 n;            /* 0x42 */
} S46;
typedef struct { u8 pad[0xc]; s32 id; } O46;
typedef struct { u8 pad[0xc]; s32* ofs; } X46;
typedef struct { E46* e; void* tex; void* c0; u8* data; f32* v80; f32* v64; } A46;

extern s32 D_01d9ea9c;
extern M46* D_01d9e6e0;
extern K46* D_01d9e6e8;
extern u8 D_01d9e360[];
extern s32 D_00352c38;
void sceVu0CopyMatrix(f32*, f32*);
void sceVu0ApplyMatrix(f32*, f32*, void*);
void sceVu0Normalize(f32*, f32*);
void sceVu0CopyVector(f32*, f32*);
void func_00222080(E46*, u8*, f32*, f32*);
void func_00222170(A46*);

static inline f32 fdiv46(f32 a, f32 b)
{
    f32 r;
    asm(".set noreorder\n\tnop\n\tnop\n\tdiv.s %0,%1,%2\n\t.set reorder" : "=f"(r) : "f"(a), "f"(b));
    return r;
}
void func_001f46f8(O46* owner, P46* prm, X46* ctx)
{
    f32 m[16];
    f32 dir[4];
    f32 pos[4];
    A46 arg;
    E46* e;
    S46* s;
    u8 n;
    f32 sz;
    s32* ofs = ctx->ofs;
    e = (E46*)((u8*)owner + ofs[0] + 160);
    s = (S46*)((u8*)owner + ofs[0] + 176);
    {
    void* src = (u8*)owner + ofs[2] + 160;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    sceVu0CopyMatrix(m, D_01d9e6e8->m0);
    *(u128_46*)&m[12] = 0;
    m[15] = 1.0f;
    sceVu0ApplyMatrix(dir, m, src);
    }
    sceVu0Normalize(dir, dir);
    sceVu0CopyVector(pos, D_01d9e6e8->m1);
    if (owner->id == prm->id) {
        if (owner->id == 0) {
            u8* d = (u8*)owner + ctx->ofs[1] + 160;
            void* t;
            if (prm->tex != -1) t = *(u8**)(D_01d9e6e0->tbl + prm->tex * 16 + 4) + prm->texofs + 160;
            else t = D_01d9e360;
            if (e->tex == D_01d9e360) return;
            e->tex = t;
            e->data = d;
            if (prm->fl56 == 0) e->flags |= 8;
            if (prm->fl55 != 0) e->flags |= 4;
            if (prm->fl58 != 0) e->flags |= 0x10;
            if (prm->fl57 != 0) e->flags |= 0x20;
            func_00222080(e, e->data, pos, dir);
        }
        e->col[0].r += prm->col[0].r;
        e->col[0].g += prm->col[0].g;
        e->col[0].b += prm->col[0].b;
        e->col[0].a += prm->col[0].a;
        e->col[1].r += prm->col[1].r;
        e->col[1].g += prm->col[1].g;
        e->col[1].b += prm->col[1].b;
        e->col[1].a += prm->col[1].a;
        e->col[2].r += prm->col[2].r;
        e->col[2].g += prm->col[2].g;
        e->col[2].b += prm->col[2].b;
        e->col[2].a += prm->col[2].a;
        e->col[3].r += prm->col[3].r;
        e->col[3].g += prm->col[3].g;
        e->col[3].b += prm->col[3].b;
        e->col[3].a += prm->col[3].a;
        e->f68 = prm->f2c;
        e->f6c += prm->f48;
        s->n = e->data[1] - 1;
        { f32 t2c = s->f2c;
        sz = s->size + prm->f30;
        s->size = sz;
        s->f30 = prm->f38;
        s->f38 = prm->f3c;
        s->f3c = prm->f40;
        s->f24 += prm->f44;
        s->f2c = t2c + prm->f4c; }
        s->f28 = (f32)(prm->angle * 3.141592654 * 0.017453292522222223);
        s->b40 = prm->b52;
        s->b41 = prm->b53;
        s->f1c = fdiv46(-(sz - sz * prm->f34), (f32)s->n);
    }
    s->f20 = fdiv46(e->f68, (f32)s->n);
    s->f34 = fdiv46(e->f6c, s->f20);
    s->c0[0] = (s16)e->col[0].r >> 7;
    s->c0[1] = (s16)e->col[0].g >> 7;
    s->c0[2] = (s16)e->col[0].b >> 7;
    s->c0[3] = (s16)e->col[0].a >> 7;
    s->c0[4] = (s16)e->col[1].r >> 7;
    s->c0[5] = (s16)e->col[1].g >> 7;
    s->c0[6] = (s16)e->col[1].b >> 7;
    s->c0[7] = (s16)e->col[1].a >> 7;
    s->c1[0] = (s16)e->col[2].r >> 7;
    s->c1[1] = (s16)e->col[2].g >> 7;
    s->c1[2] = (s16)e->col[2].b >> 7;
    s->c1[3] = (s16)e->col[2].a >> 7;
    s->c1[4] = (s16)e->col[3].r >> 7;
    s->c1[5] = (s16)e->col[3].g >> 7;
    s->c1[6] = (s16)e->col[3].b >> 7;
    s->c1[7] = (s16)e->col[3].a >> 7;
    if (D_00352c38 != 0) {
        f32 y; s32 i;
        y = (f32)s->c0[0] * 0.3f + (f32)s->c0[1] * 0.59f + (f32)s->c0[2] * 0.11f;
        s->c0[0] = s->c0[1] = s->c0[2] = (s32)y;
        y = (f32)s->c0[4] * 0.3f + (f32)s->c0[5] * 0.59f + (f32)s->c0[6] * 0.11f;
        s->c0[4] = s->c0[5] = s->c0[6] = (s32)y;
        y = (f32)s->c1[0] * 0.3f + (f32)s->c1[1] * 0.59f + (f32)s->c1[2] * 0.11f;
        s->c1[0] = s->c1[1] = s->c1[2] = (s32)y;
        y = (f32)s->c1[4] * 0.3f + (f32)s->c1[5] * 0.59f + (f32)s->c1[6] * 0.11f;
        s->c1[4] = s->c1[5] = s->c1[6] = (s32)y;
    }
    arg.tex = e->tex;
    arg.data = e->data;
    arg.c0 = e->c0;
    arg.v80 = pos;
    arg.v64 = dir;
    arg.e = e;
    func_00222170(&arg);
}
