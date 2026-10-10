#include "../common/types.h"
struct V265q { f32 v[4]; ~V265q() {} } __attribute__((aligned(16)));
extern "C" {
extern u8* D_0035f5b0;
s32 func_00139d78(void*);
void func_00139510(void*);
struct W265Sub { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); u8 pad[432]; };
struct W265Big { u8 pad[1744]; W265Sub arr[10]; };
void func_0029ac00(void) {
    s32 i;
    s32 off;
    if (D_0035f5b0 == 0) return;
    if (func_00139d78(D_0035f5b0)) func_00139510(D_0035f5b0);
    if (func_00139d78(D_0035f5b0 + 436)) func_00139510(D_0035f5b0 + 436);
    if (func_00139d78(D_0035f5b0 + 872)) func_00139510(D_0035f5b0 + 872);
    if (func_00139d78(D_0035f5b0 + 6104)) func_00139510(D_0035f5b0 + 6104);
    if (func_00139d78(D_0035f5b0 + 6512)) func_00139510(D_0035f5b0 + 6512);
    off = 0;
    for (i = 4; i >= 0; i--) {
        if (func_00139d78(&((W265Big*)D_0035f5b0)->arr[off])) ((W265Big*)D_0035f5b0)->arr[off].v5();
        if (func_00139d78(&((W265Big*)D_0035f5b0)->arr[off + 5])) ((W265Big*)D_0035f5b0)->arr[off].v5();
        off++;
    }
}
struct I265 { s32 id; s32 b; s32 c; s32 n; s32 x; s32 y; };
struct O265 { u8 pad[64]; s32 h; u8 pad2[260]; s32 x; s32 y; u8 pad3[8]; };
struct P265 { u8 pad[16]; u8* tbl; u8* recs; u8 pad2[24]; O265* objs; s32 cnt; s32 st; u8 padx[4]; f32 lim; u8 pad3[8]; s32 sel; u8 pad4[4]; s32 dx; s32 dy; };
void func_00236d60(void);
void func_00236830(s32);
void func_0023ade0(O265*);
void func_002367a0(void);
void func_0023cc18(P265* p) {
    I265* it;
    s32 last;
    s32 off;
    s32 i;
    if (p->st < 0) return;
    if (p->st < 2) return;
    if (p->st >= 4) return;
    { s32 k = p->sel * 20; u8* r = p->recs; it = (I265*)(p->tbl + *(u16*)(r + k) * 24); }
    func_00236d60();
    last = -1;
    for (i = 0; i < p->cnt; i++, it++) {
        O265* o = &p->objs[i];
        if ((f32)it->n <= p->lim) {
            if (last != it->id) {
                last = it->id;
                func_00236830(o->h);
            }
            s32 nx = it->x + p->dx;
            s32 ny = it->y + p->dy;
            o->x = nx;
            o->y = ny;
            func_0023ade0(o);
        }
    }
    func_002367a0();
}
extern char D_0036cbc0[];
void func_0017f488(u8*, s32, f32, f32);
s32 func_0019ba60(u8*);
s32 func_001b0498(u8*);
void func_001b0700(u8*, f32);
void func_0018c438(u8*);
s32 func_001883d8(u8*, const char*);
void func_001880b0(u8*, const char*);
struct Q265g { u8 pad[8]; u8* t; u8 pad1[2620]; s32 a; u8 pad2[180]; f32 f2816; u32 b0 : 1; u32 rest : 31; Q265g* o; };
void func_0018b338(Q265g* p, f32 x) {
    u8* q;
    if (p->t[4] != 15) return;
    { s32 a; if (p->b0) a = p->a; else a = 0; func_0017f488((u8*)p + 320, a, x, 0.0f); }
    if (p->o && func_0019ba60((u8*)p->o)) {
        s32 a; if (p->b0) a = p->a; else a = 0; func_0017f488((u8*)p->o + 320, a, x, 0.0f);
    }
    if (!p->b0) {
        q = (u8*)p + 1184;
        if (func_001b0498(q)) func_001b0700(q, 0.0f);
        *(s32*)((u8*)p + 2720) = 4;
        func_0018c438((u8*)p + 2624);
        p->f2816 = *(f32*)((u8*)p + 2840) + 60.0f;
    }
    p = (Q265g*)((u8*)p + 768);
    if (func_001883d8((u8*)p, D_0036cbc0)) func_001880b0((u8*)p, D_0036cbc0);
}
extern u8 D_00361aa0[];
extern u8* D_00361a90;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern void* D_00347f80;
void func_00170950(u32);
void func_00239870(u8*);
void func_0023c098(u8*);
void func_002369f0(u8*);
typedef void (*VF265)(u8*);
typedef void (*VF265b)(u8*, u8*);
void func_002c1320(u8* p) {
    *(void**)p = D_00361aa0;
    func_00170950(*(u32*)(p + 188));
    D_00361a90 = (D_00361a90 == p) ? 0 : D_00361a90;
    if (p + 2232 != 0) {
        u8* e = p + 3048;
    top1:
        if (p + 2232 == e) goto out1;
        e -= 408;
        (*(VF265**)e)[3](e);
        goto top1;
    out1:;
    }
    {
        u8* m = p + 1824;
        *(void**)m = D_00347e60;
        func_00239870(p + 1848);
        *(void**)m = D_00347f98;
        if (p + 600 != 0) {
        top2:
            if (p + 600 == m) goto out2;
            m -= 408;
            (*(VF265**)m)[3](m);
            goto top2;
        out2:;
        }
    }
    *(void**)(p + 192) = D_00347e60;
    func_00239870(p + 216);
    *(void**)(p + 192) = D_00347f98;
    *(void**)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);
    func_002369f0(p + 52);
    *(void**)(p + 28) = D_00347f98;
    *(void**)p = D_00347f98;
    {
        u8* o = *(u8**)((u8*)D_00347f80 + 20);
        (*(VF265b**)o)[1](o, p);
    }
}
struct N265q { u8 pad[208]; u8 d[40]; u32 fl; V265q* mp; u8 pad2[16]; N265q* next; };
struct Y265q { u8 pad[44]; N265q* head; };
void func_001471d8(u8*, N265q*);
void func_00147210(u8*, N265q*);
void func_00144b38(u8*, V265q*);
s32 func_001466b0(u8*, V265q*);
void func_00146250(u8* a, Y265q* y) {
    V265q m[8];
    N265q* n;
    for (n = y->head; n; n = n->next) {
        u32 fl = n->fl;
        if (fl & 0x1000) {
            if (!(fl & 0x20)) goto A;
            goto B;
        }
        if (!(fl & 0x800)) goto A;
        {
            V265q* mp;
            s32 r, r2;
            if (n->mp) mp = n->mp;
            else {
                mp = m;
                func_00144b38(n->d, m);
            }
            r = func_001466b0(a + 496, mp);
            if (r == 1) goto A;
            if (r < 2) continue;
            if (r != 2) continue;
            if (!(n->fl & 0x20)) goto A;
            r2 = func_001466b0(a + 560, mp);
            if (r2 == 1) goto A;
            if (r2 < 2) continue;
            if (r2 != r) continue;
            goto B;
        }
    B:
        func_00147210(a, n);
        continue;
    A:
        func_001471d8(a, n);
    }
}
}
