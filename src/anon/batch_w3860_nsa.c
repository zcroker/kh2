// func_001ff958: trail colour/position history update (sibling of 001f95d8 in batch_w3854_nsa.c).
// C, -fno-strict-aliasing. Plain u16 colour rows; prm rows added in order 0,2,3,1,4,5 as in the sibling.
#include "../common/types.h"
typedef struct { f32 x, y, z, w; } Vq __attribute__((aligned(16)));
typedef struct { u16 x, y, z, w; } R4;
typedef struct { R4 r[6]; Vq q[28]; u8 pad[10]; u8 idx; } Trail;
typedef struct { u8 pad[12]; s32 frame; u8 pad2[141]; u8 off; } PObj;
typedef struct { u8 pad[12]; s32* ofs; } PWork;
typedef struct { u8 pad[168]; u64 flags; } PCam;
extern s32 D_01d9ea9c;
extern PCam* D_01d9e6e0;
extern u8* D_01d9e6e8;
extern f32 D_01d9e6f0[4][4];
void func_002f3cd8(Vq* out, f32 (*m)[4], Vq* in);
void func_002f3f88(Vq* d, Vq* s);
typedef struct { s32 frame:32; u8 pad[28]; R4 d[6]; u8 pad2[3]; u8 local; } PPrm;


void func_001ff958(u8* obj, PPrm* prm, PWork* wk)
{
    Vq tmp;
    Trail* t;
    s32 i;
    u32 idx;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    t = (Trail*)(obj + *wk->ofs + 160);
    if (*(s32*)(obj + 12) == 0 && obj[157] == 0) {
        if (prm->local) { func_002f3cd8(&tmp, D_01d9e6f0, (Vq*)(D_01d9e6e8 + 64)); tmp.w = 1.0f; }
        else { func_002f3f88(&tmp, (Vq*)(D_01d9e6e8 + 64)); tmp.w = 1.0f; }
        { Vq* p = t->q; for (i = 28; i > 0; i--) { func_002f3f88(p, &tmp); p++; } }
    }
    if (t->idx == 0) t->idx = 28;
    t->idx--;
    if (prm->local) { func_002f3cd8(&t->q[t->idx], D_01d9e6f0, (Vq*)(D_01d9e6e8 + 64)); t->q[t->idx].w = 1.0f; }
    else func_002f3f88(&t->q[t->idx], (Vq*)(D_01d9e6e8 + 64));
    t->r[2].x += t->r[3].x; t->r[0].x += t->r[2].x;
    t->r[2].y += t->r[3].y; t->r[0].y += t->r[2].y;
    t->r[2].z += t->r[3].z; t->r[0].z += t->r[2].z;
    t->r[2].w += t->r[3].w; t->r[0].w += t->r[2].w;
    t->r[4].x += t->r[5].x; t->r[1].x += t->r[4].x;
    t->r[4].y += t->r[5].y; t->r[1].y += t->r[4].y;
    t->r[4].z += t->r[5].z; t->r[1].z += t->r[4].z;
    t->r[4].w += t->r[5].w; t->r[1].w += t->r[4].w;
    if (*(s32*)(obj + 12) != prm->frame) return;
    t->r[0].x += prm->d[0].x;
    t->r[0].y += prm->d[0].y;
    t->r[0].z += prm->d[0].z;
    t->r[0].w += prm->d[0].w;
    t->r[2].x += prm->d[2].x;
    t->r[2].y += prm->d[2].y;
    t->r[2].z += prm->d[2].z;
    t->r[2].w += prm->d[2].w;
    t->r[3].x += prm->d[3].x;
    t->r[3].y += prm->d[3].y;
    t->r[3].z += prm->d[3].z;
    t->r[3].w += prm->d[3].w;
    t->r[1].x += prm->d[1].x;
    t->r[1].y += prm->d[1].y;
    t->r[1].z += prm->d[1].z;
    t->r[1].w += prm->d[1].w;
    t->r[4].x += prm->d[4].x;
    t->r[4].y += prm->d[4].y;
    t->r[4].z += prm->d[4].z;
    t->r[4].w += prm->d[4].w;
    t->r[5].x += prm->d[5].x;
    t->r[5].y += prm->d[5].y;
    t->r[5].z += prm->d[5].z;
    t->r[5].w += prm->d[5].w;
}
