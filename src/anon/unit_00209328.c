// Linked unit 0x00209328-0x00209d68 (was whole asm). Projected sprite/quad -> GIF packet:
// two edge widths from the camera, 8 corners, colour scale + clamp, ST/RGBA/XYZ2 vertices, DMA kick.
// Plain C except one empty asm in the vertex loop (asm("" :: "r"(&uv[i]))): without it the uv giv and the
// i<4 flag swap s1/s2 and i / the i*16 giv swap s4/s5 (priority order in global-alloc).
// The clamp loop reuses i as its counter: that is what makes the live-range pass split i around the first
// corner loop (retail's `move s0,s4`) without an extra `li s4,8`.
// 0x01da8be0 is a qword constant (no symbol in the retail data map).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vq;
typedef struct { s32 x, y, z, w; } __attribute__((aligned(16))) Vi;
typedef struct { Vq r[4]; } Mq;
typedef struct { u8 pad0[4]; s32 tex; f32 size; f32 ofs; f32 scale[2][4]; u8 persp; } Spr;
typedef struct { u8 pad[12]; s32* offs; } SprSrc;
typedef struct { u8 pad[16]; Mq view; Mq proj; } Cam;
typedef struct { u8 pad0[4]; s32 sub; u8 pad8[14]; u8 a0; u8 a1; } TexHdr;
typedef struct { u8 pad0[8]; u32 tex0[2]; } TexSub;
typedef struct { u8 pad0[28]; TexHdr* hdr; u8 pad32[4]; } TexEnt;
typedef struct { u8 pad0[16]; TexEnt* ents; } TexMgr;
typedef struct {
    u128 dma;
    u64 gif[2];
    u32 tex0[2]; u64 tex0Reg;
    u32 alpha[2]; u64 alphaReg;
    u128 q64;
    u64 tag[2];
    u32 data[1];
} Pkt;
extern Cam* D_01d9e6e8;
extern TexMgr* D_01d9e6e4;
extern u128 D_01da8be0;
extern Mq D_01d9e840;
extern Mq D_01d9e8c0;
extern s32 D_00359780;
extern u8* D_00359788[];
float sqrtf(float);
void func_002f3d08(Mq*, Mq*, Mq*);
void func_002f3cd8(Vq*, Mq*, Vq*);
void func_002f3f88(Vq*, Vq*);
void func_002f4870(Vq*, Vq*, f32);
void func_002f3f10(Vq*, Vq*, Vq*);
void func_002f3ef8(Vq*, Vq*, Vq*);
void func_002f3f40(Vq*, Vq*, f32);
void func_002f3d98(Vq*, Vq*);
void func_002f3fc0(Vi*, Vq*);
s32 func_002f4888(Vq*);
void func_003058a0(s32);
s32 func_002f35e8(s32);
void func_002f3918(s32, u32);
void func_002f25a0(s32, s32);

void func_00209328(u8* base, Spr* s, SprSrc* src)
{
    Vq q[2];
    Vq c[8];
    s32 o[8][4];
    s32 col[2][4];
    f32 iw[2];
    Vq d;
    Vq e;
    Vq t;
    Vq* uv;
    u8* cb;
    f32 l0, l1;
    s32 i, k, n;
    TexHdr* h;
    TexSub* ts;
    Pkt* pk;
    u32* w;
    u32 up;
    u64* tg;
    s32 slot;

    uv = (Vq*)(base + src->offs[2] + 160);
    cb = base + src->offs[0] + 160;
    if (s->tex == 0xffff) return;
    q[0].x = -s->size;
    q[0].y = 0.0f;
    q[0].z = 0.0f;
    q[0].w = 1.0f;
    q[1].x = s->size;
    q[1].y = 0.0f;
    q[1].z = 0.0f;
    q[1].w = 1.0f;
    if (s->persp) {
        Vq a, b;
        Mq m;
        func_002f3d08(&m, &D_01d9e840, &D_01d9e6e8->view);
        func_002f3cd8(&a, &m, &q[0]);
        func_002f3f88(&b, &a);
        b.x += s->ofs;
        func_002f3cd8(&a, &D_01d9e8c0, &a);
        func_002f3cd8(&b, &D_01d9e8c0, &b);
        if (a.w > 0.0f && b.w > 0.0f) {
            a.w = 1.0f / a.w;
            func_002f4870(&a, &a, a.w);
            b.w = 1.0f / b.w;
            func_002f4870(&b, &b, b.w);
            func_002f3f10(&a, &a, &b);
            l0 = sqrtf(a.x * a.x + a.y * a.y);
        } else {
            l0 = 0.0f;
        }
        func_002f3cd8(&a, &m, &q[1]);
        func_002f3f88(&b, &a);
        b.x += s->ofs;
        func_002f3cd8(&a, &D_01d9e8c0, &a);
        func_002f3cd8(&b, &D_01d9e8c0, &b);
        if (a.w > 0.0f && b.w > 0.0f) {
            a.w = 1.0f / a.w;
            func_002f4870(&a, &a, a.w);
            b.w = 1.0f / b.w;
            func_002f4870(&b, &b, b.w);
            func_002f3f10(&a, &a, &b);
            l1 = sqrtf(a.x * a.x + a.y * a.y);
        } else {
            l1 = 0.0f;
        }
        if (l0 == 0.0f && l1 == 0.0f) return;
    } else {
        Vq a, b;
        Mq m;
        func_002f3d08(&m, &D_01d9e840, &D_01d9e6e8->view);
        a.x = a.y = a.z = 0.0f;
        a.w = 1.0f;
        func_002f3cd8(&a, &m, &a);
        func_002f3f88(&b, &a);
        b.x += s->ofs;
        func_002f3cd8(&a, &D_01d9e8c0, &a);
        func_002f3cd8(&b, &D_01d9e8c0, &b);
        if (a.w > 0.0f && b.w > 0.0f) {
            a.w = 1.0f / a.w;
            func_002f4870(&a, &a, a.w);
            b.w = 1.0f / b.w;
            func_002f4870(&b, &b, b.w);
            func_002f3f10(&a, &a, &b);
            l0 = l1 = sqrtf(a.x * a.x + a.y * a.y);
        } else {
            l0 = l1 = 0.0f;
        }
    }
    func_002f3cd8(&c[2], &D_01d9e6e8->proj, &q[0]);
    func_002f3cd8(&c[4], &D_01d9e6e8->proj, &q[1]);
    if (c[2].w <= 0.0f && c[4].w <= 0.0f) return;
    if (c[2].w > 0.0f) {
        iw[0] = c[2].w = 1.0f / c[2].w;
        func_002f4870(&c[2], &c[2], c[2].w);
    }
    if (c[4].w > 0.0f) {
        iw[1] = c[4].w = 1.0f / c[4].w;
        func_002f4870(&c[4], &c[4], c[4].w);
    }
    d.x = c[4].x - c[2].x;
    d.y = c[4].y - c[2].y;
    d.z = 0.0f;
    d.w = 0.0f;
    func_002f3d98(&d, &d);
    e.x = -d.y;
    e.y = d.x;
    e.z = 0.0f;
    e.w = 0.0f;
    func_002f3f40(&t, &e, l0);
    func_002f3ef8(&c[3], &c[2], &t);
    func_002f3f40(&t, &e, l1);
    func_002f3ef8(&c[5], &c[4], &t);
    e.x = -e.x;
    e.y = -e.y;
    func_002f3f40(&t, &e, l0);
    func_002f3ef8(&c[2], &c[2], &t);
    func_002f3f40(&t, &e, l1);
    func_002f3ef8(&c[4], &c[4], &t);
    func_002f3f40(&t, &d, l0);
    func_002f3f10(&c[0], &c[2], &t);
    func_002f3f10(&c[1], &c[3], &t);
    func_002f3f40(&t, &d, l1);
    func_002f3ef8(&c[6], &c[4], &t);
    func_002f3ef8(&c[7], &c[5], &t);
    for (i = 0; i < 8; i++) func_002f3fc0((Vi*)o[i], &c[i]);
    col[0][0] = (f32)cb[8] * s->scale[0][0];
    col[0][1] = (f32)cb[9] * s->scale[0][1];
    col[0][2] = (f32)cb[10] * s->scale[0][2];
    col[0][3] = (f32)cb[11] * s->scale[0][3];
    col[1][0] = (f32)cb[8] * s->scale[1][0];
    col[1][1] = (f32)cb[9] * s->scale[1][1];
    col[1][2] = (f32)cb[10] * s->scale[1][2];
    col[1][3] = (f32)cb[11] * s->scale[1][3];
    for (i = 0; i < 4; i++) {
        if (col[0][i] < 0) col[0][i] = 0;
        else if (col[0][i] > 255) col[0][i] = 255;
        if (col[1][i] < 0) col[1][i] = 0;
        else if (col[1][i] > 255) col[1][i] = 255;
    }
    { TexEnt* te = &D_01d9e6e4->ents[s->tex]; h = te->hdr; }
    ts = (TexSub*)((u8*)h + h->sub);
    slot = D_00359780;
    pk = (Pkt*)D_00359788[slot++];
    D_00359780 = slot;
    D_00359788[slot] = (u8*)pk + 0x800;
    w = pk->data;
    up = ((u32)pk & 0x0fffffff) | 0x80000000;
    tg = pk->tag;
    pk->gif[0] = 0x3000000000000001ULL;
    pk->gif[1] = 0xeee;
    pk->tex0[0] = ts->tex0[0];
    pk->tex0[1] = ts->tex0[1];
    pk->tex0Reg = 6;
    pk->alpha[0] = h->a0;
    pk->alpha[1] = h->a1;
    pk->alphaReg = 66;
    pk->q64 = D_01da8be0;
    n = 0;
    for (i = 0; i < 8; i++) {
        if (func_002f4888(&c[i]) == 0) {
            asm("" :: "r"(&uv[i]));
            if (s->persp) {
                f32 f = i < 4 ? iw[0] : iw[1];
                func_002f3f40(&t, &uv[i], f);
                *(f32*)w++ = t.x;
                *(f32*)w++ = t.y;
                *(f32*)w++ = t.z;
            } else {
                *(f32*)w++ = uv[i].x;
                *(f32*)w++ = uv[i].y;
                *(f32*)w++ = uv[i].z;
            }
            *w++ = 0;
            if (i < 4) {
                for (k = 0; k < 4; k++) *w++ = col[0][k];
            } else {
                for (k = 0; k < 4; k++) *w++ = col[1][k];
            }
            *w++ = o[i][0];
            *w++ = o[i][1];
            *w++ = o[i][2];
            *w++ = 0;
            n++;
        }
    }
    tg[0] = ((u64)0xc0b9 << 46) | (n | 0x8000);
    tg[1] = 0x412;
    asm volatile("sync");
    pk->dma = 0;
    *(u32*)pk = ((s32)((u8*)w - (u8*)pk) >> 4) - 1 | 0x70000000;
    func_003058a0(0);
    func_002f3918(func_002f35e8(2), up);
    func_002f25a0(0, 0);
    D_00359780--;
}
