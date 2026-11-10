#include "../common/types.h"

/* Strip builder 0x220da0 with its five GNU C nested functions (0x2200c0-0x220cf0).
   The nested functions get the parent frame (sp) as static chain in v0. */

typedef unsigned int u128 __attribute__((mode(TI)));
typedef float FVec[4] __attribute__((aligned(16)));

typedef struct Vtx { f32 pos[4]; f32 pad10[3]; f32 w28; f32 pad20[4]; } Vtx;     /* 48 bytes */
typedef struct Mdl {
    u8 pad0[48];
    f32 speed;          /* 0x30 */
    u16 base;           /* 0x34 */
    u16 pad36;
    u16 n0;             /* 0x38 */
    u16 pad3a;
    u16 n1;             /* 0x3c */
    u16 flags;          /* 0x3e */
    Vtx vtx[1];         /* 0x40 */
} Mdl;
typedef struct Col {
    u8 c0[4];
    u8 c1[4];
    u32 pad8;
    f32 f0c;
    s8 d0[4];
    s8 d1[4];
    u32 pad18;
    f32 f1c;
    u32 pad20[4];
    f32 f30;
    u32 pad34;
    f32 f38;
} Col;
typedef struct Arg {
    void* mtx;
    Mdl* mdl;
    u128* pkt;
    Col* col;
    f32* uv;
    u128* start;
    u64 alpha;
    u64 test;
} Arg;
typedef struct Scale { u8 pad[48]; f32 s[4]; } Scale;
extern Scale* D_01d9e6e0;

typedef union { u64 d[2]; u128 q; } Tag;

void sceVu0ScaleVector(void* d, void* s, f32 k);
void sceVu0CopyVector(void* d, void* s);
void sceVu0FTOI0Vector(void* d, void* s);
void sceVu0AddVector(void* d, void* a, void* b);
void sceVu0ClampVector(void* d, void* s, f32 lo, f32 hi);
void sceVu0SubVector(void* d, void* a, void* b);
void func_002226b8(void* d, void* s);
void func_00222790(void* d, void* a, void* b);
void func_00222800(void* d, void* s);
void func_00222898(void* d, void* m, void* s);
void func_00222868(void* d, void* s);
void func_00222770(void* d, void* a, void* b);
void func_00222710(void* d, void* a, void* b);
f32 func_00222678(f32 a, f32 b);
void func_002226a0(void* d, void* s);
void CopyMatrix(void* d, void* s) asm("_Z16sceVu0CopyMatrixjjjj");

typedef struct Work {
    FVec m[4];          /* 0 */
    FVec c0;            /* 64 */
    FVec c1;            /* 80 */
    FVec uvs;           /* 96: u, v, max, k */
    FVec d0;            /* 112 */
    FVec d1;            /* 128 */
    FVec q;             /* 144 */
    FVec p0;            /* 160 */
    FVec p1;            /* 176 */
    FVec p2;            /* 192 */
    FVec v208;          /* 208 */
    FVec v224;          /* 224 */
    FVec k240;          /* 240 */
    Tag tag0;           /* 256 */
    Tag tag1;           /* 272 */
    FVec pad288[2];     /* 288 */
    FVec s320;          /* 320 */
    Tag tag2;           /* 336 */
    FVec pad352;        /* 352 */
    FVec v368;          /* 368 */
    FVec v384;          /* 384 */
    FVec v400;          /* 400 */
    FVec v416;          /* 416 */
    FVec v432;          /* 432 */
    FVec v448;          /* 448 */
    FVec v464;          /* 464 */
    FVec t;             /* 480 */
    u128* pkt;          /* 496 */
    Vtx* vp;            /* 500 */
    s32 pad504[3];
    s32 stride;         /* 516 */
    u128* pkt0;         /* 520 */
    s32 cnt;            /* 524 */
    u128* head;         /* 528 */
    s32 pad532;
    s32 n[2];           /* 536 */
    Vtx* vl[2];         /* 544 */
} Work;

s32 func_00220da0(Arg* a)
{
    Work w;

    /* 0x2200c0 */
    void begin(void)
    {
        w.head = w.pkt;
        *w.pkt = w.tag2.q;
        w.pkt++;
        w.s320[3] = 1.0f - w.vp->w28 * w.q[2];
        sceVu0FTOI0Vector(w.t, w.c0);
        func_002226b8(w.v400, w.t);
        sceVu0CopyVector(w.pkt, w.v400);
        func_00222800(++w.pkt, w.p0);
        w.pkt++;
        sceVu0FTOI0Vector(w.v384, w.c1);
        sceVu0AddVector(w.t, w.c1, w.d1);
        sceVu0ClampVector(w.c1, w.t, 0.0f, w.uvs[2]);
        sceVu0FTOI0Vector(w.v368, w.c1);
        sceVu0CopyVector(w.t, w.vp);
        func_00222898(w.p2, w.m, w.t);
        w.s320[2] = 1.0f / w.p2[3];
        w.vp = (Vtx*)((u8*)w.vp + w.stride);
        func_00222770(w.t, w.p2, w.p1);
        func_00222868(w.v448, w.t);
        func_00222710(w.t, w.v208, w.v448);
        func_00222868(w.t, w.t);
        w.s320[0] += w.k240[3];
        w.s320[0] = func_00222678(w.s320[0], 0.0f);
        w.v464[0] = w.t[1];
        w.v464[1] = -w.t[0];
        w.v464[0] *= w.s320[0];
        w.v464[1] *= w.s320[0];
        w.v464[0] *= w.s320[1];
        w.v464[1] *= w.s320[1];
        w.v464[0] *= w.s320[3] * w.uvs[0];
        w.v464[1] *= w.s320[3] * w.uvs[1];
        func_002226a0(w.v208, w.v448);
        w.s320[1] = w.s320[2];
        func_002226b8(w.v400, w.v368);
        sceVu0CopyVector(w.pkt, w.v400);
        func_00222790(++w.pkt, w.p1, w.v464);
        w.pkt++;
        sceVu0CopyVector(w.v224, w.v464);
        sceVu0ScaleVector(w.v416, w.v464, w.uvs[3]);
        sceVu0CopyVector(w.pkt, w.v368);
        func_00222790(++w.pkt, w.p1, w.v416);
        w.pkt++;
        sceVu0AddVector(w.t, w.c0, w.d0);
        sceVu0ClampVector(w.c0, w.t, 0.0f, 255.0f);
        sceVu0FTOI0Vector(w.v448, w.c0);
        sceVu0CopyVector(w.pkt, w.v448);
        func_00222800(++w.pkt, w.p1);
        w.pkt++;
        sceVu0ScaleVector(w.v416, w.v464, w.k240[1]);
        sceVu0ScaleVector(w.v448, w.v416, w.uvs[3]);
        sceVu0CopyVector(w.pkt, w.v368);
        func_00222790(++w.pkt, w.p1, w.v448);
        w.pkt++;
        func_002226b8(w.v400, w.v368);
        sceVu0CopyVector(w.pkt, w.v400);
        func_00222790(++w.pkt, w.p1, w.v416);
        w.pkt++;
        sceVu0CopyVector(w.p0, w.p1);
        sceVu0CopyVector(w.p1, w.p2);
        w.cnt--;
    }

    /* 0x2204c8 */
    void strip(void)
    {
        while (w.cnt > 0) {
            w.s320[3] = 1.0f - w.vp->w28 * w.q[2];
            w.head = w.pkt;
            *w.pkt = w.tag1.q;
            w.pkt++;
            sceVu0FTOI0Vector(w.v384, w.c1);
            sceVu0AddVector(w.t, w.c1, w.d1);
            sceVu0ClampVector(w.c1, w.t, 0.0f, w.uvs[2]);
            sceVu0FTOI0Vector(w.v368, w.c1);
            sceVu0CopyVector(w.t, w.vp);
            func_00222898(w.p2, w.m, w.t);
            w.s320[2] = 1.0f / w.p2[3];
            w.vp = (Vtx*)((u8*)w.vp + w.stride);
            func_00222770(w.t, w.p2, w.p1);
            func_00222868(w.v448, w.t);
            func_00222710(w.t, w.v208, w.v448);
            func_00222868(w.t, w.t);
            w.s320[0] += w.k240[3];
            w.s320[0] = func_00222678(w.s320[0], 0.0f);
            w.v464[0] = w.t[1];
            w.v464[1] = -w.t[0];
            w.v464[0] *= w.s320[0];
            w.v464[1] *= w.s320[0];
            w.v464[0] *= w.s320[1];
            w.v464[1] *= w.s320[1];
            w.v464[0] *= w.s320[3] * w.uvs[0];
            w.v464[1] *= w.s320[3] * w.uvs[1];
            func_002226a0(w.v208, w.v448);
            w.s320[1] = w.s320[2];
            func_002226b8(w.v400, w.v384);
            sceVu0CopyVector(w.pkt, w.v400);
            func_00222790(++w.pkt, w.p0, w.v224);
            w.pkt++;
            func_002226b8(w.v400, w.v368);
            sceVu0CopyVector(w.pkt, w.v400);
            func_00222790(++w.pkt, w.p1, w.v464);
            w.pkt++;
            sceVu0ScaleVector(w.v448, w.v224, w.uvs[3]);
            sceVu0ScaleVector(w.v432, w.v224, w.k240[1]);
            sceVu0CopyVector(w.v224, w.v464);
            sceVu0ScaleVector(w.v416, w.v464, w.uvs[3]);
            sceVu0CopyVector(w.pkt, w.v384);
            func_00222790(++w.pkt, w.p0, w.v448);
            sceVu0CopyVector(++w.pkt, w.v368);
            func_00222790(++w.pkt, w.p1, w.v416);
            w.pkt++;
            sceVu0FTOI0Vector(w.v416, w.c0);
            sceVu0AddVector(w.t, w.c0, w.d0);
            sceVu0ClampVector(w.c0, w.t, 0.0f, 255.0f);
            sceVu0FTOI0Vector(w.v448, w.c0);
            sceVu0CopyVector(w.pkt, w.v416);
            func_00222800(++w.pkt, w.p0);
            sceVu0CopyVector(++w.pkt, w.v448);
            func_00222800(++w.pkt, w.p1);
            w.pkt++;
            sceVu0ScaleVector(w.v416, w.v464, w.k240[1]);
            sceVu0ScaleVector(w.v464, w.v432, w.uvs[3]);
            sceVu0ScaleVector(w.v448, w.v416, w.uvs[3]);
            sceVu0CopyVector(w.pkt, w.v384);
            func_00222790(++w.pkt, w.p0, w.v464);
            sceVu0CopyVector(++w.pkt, w.v368);
            func_00222790(++w.pkt, w.p1, w.v448);
            w.pkt++;
            func_002226b8(w.v400, w.v384);
            sceVu0CopyVector(w.pkt, w.v400);
            func_00222790(++w.pkt, w.p0, w.v432);
            w.pkt++;
            func_002226b8(w.v400, w.v368);
            sceVu0CopyVector(w.pkt, w.v400);
            func_00222790(++w.pkt, w.p1, w.v416);
            w.pkt++;
            sceVu0CopyVector(w.p0, w.p1);
            sceVu0CopyVector(w.p1, w.p2);
            w.cnt--;
        }
    }

    /* 0x2209f0 */
    void end(void)
    {
        w.head = w.pkt;
        *w.pkt = w.tag2.q;
        w.pkt++;
        sceVu0FTOI0Vector(w.v416, w.c0);
        sceVu0AddVector(w.t, w.c0, w.d0);
        sceVu0ClampVector(w.c0, w.t, 0.0f, 255.0f);
        sceVu0FTOI0Vector(w.v448, w.c0);
        func_002226b8(w.t, w.v448);
        sceVu0CopyVector(w.pkt, w.t);
        func_00222800(++w.pkt, w.p1);
        w.pkt++;
        sceVu0FTOI0Vector(w.v384, w.c1);
        func_002226b8(w.v400, w.v384);
        sceVu0CopyVector(w.pkt, w.v400);
        func_00222790(++w.pkt, w.p0, w.v224);
        w.pkt++;
        sceVu0ScaleVector(w.v448, w.v224, w.uvs[3]);
        sceVu0ScaleVector(w.v432, w.v224, w.k240[1]);
        sceVu0CopyVector(w.pkt, w.v384);
        func_00222790(++w.pkt, w.p0, w.v448);
        sceVu0CopyVector(++w.pkt, w.v416);
        func_00222800(++w.pkt, w.p0);
        w.pkt++;
        sceVu0ScaleVector(w.v464, w.v432, w.uvs[3]);
        sceVu0FTOI0Vector(w.v384, w.c1);
        sceVu0CopyVector(w.pkt, w.v384);
        func_00222790(++w.pkt, w.p0, w.v464);
        w.pkt++;
        func_002226b8(w.v400, w.v384);
        sceVu0CopyVector(w.pkt, w.v400);
        func_00222790(++w.pkt, w.p0, w.v432);
        w.pkt++;
        a->start = w.head;
        a->pkt = w.pkt;
    }

    /* 0x220c88 */
    void first(void)
    {
        sceVu0CopyVector(w.t, w.vp);
        func_00222898(w.p0, w.m, w.t);
        w.vp = (Vtx*)((u8*)w.vp + w.stride);
        w.cnt--;
    }

    /* 0x220cf0 */
    void second(void)
    {
        sceVu0CopyVector(w.t, w.vp);
        func_00222898(w.p1, w.m, w.t);
        w.s320[1] = 1.0f / w.p1[3];
        sceVu0SubVector(w.t, w.p1, w.p0);
        func_00222868(w.v208, w.t);
        w.vp = (Vtx*)((u8*)w.vp + w.stride);
        w.cnt--;
    }

    Scale* g;
    Col* c;

    if (a->mdl->n0 + a->mdl->n1 < 3)
        return 0;
    w.pkt = w.pkt0 = a->pkt;
    w.stride = 48;
    CopyMatrix(w.m, a->mtx);
    g = D_01d9e6e0;
    c = a->col;
    w.c0[0] = c->c0[0] * g->s[0];
    w.c0[1] = a->col->c0[1] * g->s[1];
    w.c0[2] = a->col->c0[2] * g->s[2];
    w.c0[3] = a->col->c0[3] * g->s[3];
    w.c1[0] = a->col->c1[0] * g->s[0];
    w.c1[1] = a->col->c1[1] * g->s[1];
    w.c1[2] = a->col->c1[2] * g->s[2];
    w.c1[3] = a->col->c1[3] * g->s[3];
    w.d0[0] = a->col->d0[0] * g->s[0];
    w.d0[1] = a->col->d0[1] * g->s[1];
    w.d0[2] = a->col->d0[2] * g->s[2];
    w.d0[3] = a->col->d0[3] * g->s[3];
    w.d1[0] = a->col->d1[0] * g->s[0];
    w.d1[1] = a->col->d1[1] * g->s[1];
    w.d1[2] = a->col->d1[2] * g->s[2];
    w.d1[3] = a->col->d1[3] * g->s[3];
    w.k240[1] = -1.0f;
    w.s320[0] = a->col->f0c;
    w.q[2] = a->col->f38;
    w.uvs[3] = a->col->f30;
    w.k240[3] = a->col->f1c;
    w.uvs[2] = 255.0f;
    w.v400[3] = 0.0f;
    *(s32*)&w.q[3] = 0x8000;
    w.q[0] = 4096.0f;
    w.q[1] = 4096.0f;
    w.uvs[0] = a->uv[0];
    w.uvs[1] = a->uv[1];
    w.tag0.d[0] = 0x2000000000000001ULL;
    w.tag0.d[1] = 0xee;
    w.tag1.d[0] = (0x8099ULL << 46) | 10;
    w.tag1.d[1] = 0x51;
    w.tag2.d[0] = (0x809bULL << 46) | 6;
    w.tag2.d[1] = 0x51;

    if (!(a->mdl->flags & 0x1000)) {
        w.v464[0] = a->mdl->speed;
        sceVu0ScaleVector(w.t, w.d0, w.v464[0]);
        sceVu0AddVector(w.t, w.c0, w.t);
        sceVu0ClampVector(w.c0, w.t, 0.0f, w.uvs[2]);
        sceVu0ScaleVector(w.t, w.d1, w.v464[0]);
        sceVu0AddVector(w.t, w.c1, w.t);
        sceVu0ClampVector(w.c1, w.t, 0.0f, w.uvs[2]);
        w.t[0] = w.s320[0] + w.k240[3] * w.v464[0];
        if (w.t[0] < 0.0f)
            w.s320[0] = 0.0f;
        else
            w.s320[0] = w.t[0];
        w.n[0] = a->mdl->n0;
        w.n[1] = a->mdl->n1;
        w.vl[0] = &a->mdl->vtx[a->mdl->base];
        w.vl[1] = &a->mdl->vtx[0];
    } else {
        w.n[0] = a->mdl->n1;
        w.n[1] = a->mdl->n0;
        w.vl[0] = &a->mdl->vtx[a->mdl->n1 - 1];
        w.vl[1] = &a->mdl->vtx[a->mdl->base] + a->mdl->n0 - 1;
        w.stride = -w.stride;
    }
    w.head = w.pkt;
    *w.pkt = w.tag0.q;
    w.pkt++;
    ((u64*)w.pkt)[0] = a->test;
    ((u64*)w.pkt)[1] = 0x47;
    w.pkt++;
    ((u64*)w.pkt)[0] = a->alpha;
    ((u64*)w.pkt)[1] = 0x42;
    w.pkt++;

    if (w.n[0] == 0)
        goto zero;
    w.cnt = w.n[0];
    w.vp = w.vl[0];
    first();
    if (w.cnt != 0)
        goto l1;
    w.vp = w.vl[1];
    w.cnt = w.n[1];
x:
    second();
y:
    begin();
z:
    strip();
e:
    end();
    return 1;
l1:
    second();
    if (w.cnt != 0)
        goto l2;
    w.vp = w.vl[1];
    w.cnt = w.n[1];
    goto y;
l2:
    begin();
    w.n[0]--;
    strip();
    if (w.n[1] == 0)
        goto e;
    w.cnt = w.n[1];
    w.vp = w.vl[1];
    goto z;
zero:
    w.vp = w.vl[1];
    w.cnt = w.n[1];
    first();
    goto x;
}
