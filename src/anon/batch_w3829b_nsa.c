#include "../common/types.h"
typedef struct { f32 x, y, z, w; } W2417Vec;
typedef struct { s16 x, y, z; } W2417Pt;
typedef struct { u8 pad[0x80]; u8* tbl; u8 pad84[0x24]; u64 flags; } W2417Mgr;
typedef struct { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; u8 pad50[0x40]; W2417Pt* pts; } W2417Cam;
typedef struct { u8 pad[4]; void* owner; } W2417Ent;
typedef struct { s16 a; s16 cnt; u16* list; } W2417Grp;
typedef struct { u8 pad[0x14]; W2417Pt* pts; u8 pad18[0xc]; } W2417Mdl;
typedef struct { u8 pad[0x10]; W2417Mdl* mdl; u8 pad14[4]; W2417Grp* grp; } W2417Tab;
typedef struct { u8 pad[4]; s16 g0; s16 g1; u8 n; u8 mask; u8 rnd; u8 padb; s32 idx; s32 o10; s32 o14; s32 o18; } W2417Prm;
typedef struct { u8 pad[0xc]; s32* ofs; } W2417Ctx;
extern s32 D_01d9ea9c;
extern W2417Mgr* D_01d9e6e0;
extern W2417Tab* D_01d9e6e4;
extern W2417Cam* D_01d9e6e8;
s32 func_00222568(void);
W2417Ent* func_001e7a98(W2417Mgr*, u8*);
void sceVu0CopyMatrix(f32*, f32*);
void sceVu0ApplyMatrix(void*, void*, W2417Vec*);
void func_00222730(void*, W2417Vec*, void*);

// 001f59b0: particle emitter variant (partMng): picks a point index (random or sequential), spawns an
// object per point, transforms the s16 point pairs by two matrices and stores the result.
// Partial asm (no extra code): the lui/lw of D_01d9e6e8 are single-instruction asms pinned to t7/a1 so
// sched2 keeps them after the arg setup like the original; the empty asm ties only add sched2 readers
// (t: idx so idx++ is issued before move v0,zero; a/q inputs place the lui after addiu s0 and before addu t6).
void func_001f59b0(void* owner, W2417Prm* prm_, W2417Ctx* c)
{
    register W2417Prm* prm asm("$18") = prm_;
    register s32 r asm("$17");
    W2417Grp* g;
    W2417Grp* g2;
    u8* base;
    u16* slot;
    W2417Pt* p0;
    W2417Pt* p1;
    s32 rnd;
    s32 idx;
    s32 n;
    f32 m[16];
    W2417Vec v;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    r = func_00222568();
    if (prm->mask == 255) return;
    if ((r >> 8) & prm->mask) return;
    if (prm->idx == -1) return;
    if (prm->o14 == -1) return;
    g = &D_01d9e6e4->grp[prm->g0];
    g2 = (W2417Grp*)((u32)(prm->g1 * 8) + (u32)D_01d9e6e4->grp);
    base = (u8*)owner + *c->ofs;
    slot = (u16*)(base + 160);
    p0 = D_01d9e6e8->pts;
    p1 = D_01d9e6e4->mdl[g2->a].pts;
    if (g->cnt != g2->cnt) return;
    if (p0 == 0) p0 = D_01d9e6e4->mdl[g->a].pts;
    rnd = prm->rnd;
    v.w = 1.0f;
    sceVu0CopyMatrix(m, D_01d9e6e8->m0);
    if (rnd != 0) idx = r % g->cnt;
    else idx = *slot;
    for (n = prm->n; n > 0; n--) {
        W2417Mgr* st; s32 k; register u8* t asm("$15"); W2417Ent* e; u8* a; u8* q;
        { register u16* lp asm("$13") = (u16*)(idx * 2); lp = (u16*)((u8*)lp + (u32)g->list); idx++; k = *lp; }
        st = D_01d9e6e0;
        t = st->tbl + prm->idx * 16;
        asm("" : "+r"(t) : "r"(idx));
        e = 0;
        if (t != 0) {
            e = func_001e7a98(st, t);
            e->owner = owner;
        }
        k *= 6;
        a = (u8*)e + prm->o10 + 160;
        q = (u8*)e + prm->o18 + 160;
        {
        register u32 h asm("$15");
        register W2417Cam* cam asm("$5");
        u8* pp = (u8*)p0 + k;
        asm("lui %0,%%hi(D_01d9e6e8)" : "=r"(h) : "r"(a));
        asm("lw %0,%%lo(D_01d9e6e8)(%2)" : "=r"(cam), "+r"(pp) : "r"(h), "r"(q));
        v.x = *(s16*)(pp + 0);
        v.y = *(s16*)(pp + 2);
        v.z = *(s16*)(pp + 4);
        sceVu0ApplyMatrix(a, cam->m0, &v);
        }
        v.x = *(s16*)((u8*)p1 + k + 0);
        v.y = *(s16*)((u8*)p1 + k + 2);
        v.z = *(s16*)((u8*)p1 + k + 4);
        sceVu0ApplyMatrix(&v, m, &v);
        func_00222730(q, &v, D_01d9e6e8->m1);
        if (rnd != 0) {
            idx = func_00222568() % g->cnt;
        } else {
            if (!(idx < g->cnt)) idx = 0;
        }
    }
    *slot = idx;
}
