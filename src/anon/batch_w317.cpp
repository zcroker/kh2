#include "../common/types.h"
union W317YM { u8* p; u8 c; };
struct W317OF { s32 o0; s32 o4; s32 o8; };
struct W317Q { u8 pad[12]; W317OF* of; };
struct W317P { s32 a; s32 k; s32 off; u8 flag; };
struct W317Y { f32 f; W317YM m4; };
struct W317X { f32 v[4]; u8 flags; u8 pad[3]; u32 y; };
struct W317E16 { s32 a; s32 b; s32 c; s32 d; };
struct W317L { f32 a[4]; f32 b[4]; f32 t; f32 u; f32 pad[2]; f32 c[4]; };
struct W317E { u16 a; u16 id; u8 x; u8 b; u8 c; u8 d; u32 e; };
struct W317H { s32 kind; s32 pad; s32 count; W317E e[1]; };
struct W317Obj;
struct W317VT { void* f[5]; void (*f20)(W317Obj*); };
struct W317Obj { W317VT* vt; };
struct W317A { u8 d[408]; };
struct W317B { u8 d[436]; };
struct W317G { W317B b0; W317B b1; W317B b[4][4]; u8 pad[7848 - 872 - 436 * 16]; W317A a[4][4]; };
extern "C" {
extern u8* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern W317Y D_01d9e360;
void func_002f3f10(void*, void*, void*);
void func_002f3f88(void*, void*);
s32 func_002225a8(void*);
void func_002f3f40(void*, void*, f32);
void func_002f3ef8(void*, void*, void*);
void func_00222730(void*, void*, void*);
void func_001fc320(u8* self, W317P* p, W317Q* q) {
    W317X* x = (W317X*)(self + q->of->o8 + 160);
    W317L l;
    u8 fl = x->flags;
    bool b = fl & 1;
    if (b) return;
    if (*(s32*)(self + 12) == p->a) {
        s32 k = p->k;
        W317Y* y;
        if (k != -1) y = (W317Y*)((*(W317E16**)(D_01d9e6e0 + 128))[k].b + p->off + 160);
        else y = &D_01d9e360;
        x->y = (u32)y;
        if (p->flag) x->flags = fl | 2;
        if (*(s32*)(self + 12) == 0) { if (self[157] == 0) return; }
    }
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    W317Y* y = (W317Y*)x->y;
    if (y == &D_01d9e360) return;
    f32 f = y->f;
    u8* s4 = self + q->of->o0 + 160;
    u8* s3 = self + q->of->o4 + 160;
    if (f == 0.0f) return;
    l.t = f;
    func_002f3f10(&l, s4, y->m4.p);
    func_002f3f88(l.b, s3);
    if (!func_002225a8(&l)) return;
    f32 u = l.u;
    if (u < 0.0f) return;
    if (1.0f < u) return;
    x->flags |= 1;
    func_002f3f40(l.c, l.b, u);
    func_002f3ef8(l.c, l.c, &l);
    func_002f3ef8(x, ((W317Y*)x->y)->m4.p, l.c);
    if (x->flags & 2) {
        func_00222730(s3, x, s4);
        *(s32*)(self + 12) = 0xffff0000;
    }
}

s32 func_0013cb90(void);
u32 func_001b8e88(u32);
s32 func_0013b988(u8*, W317H*, u32, s32, s32, s32);
u32 func_00192048(u32);
void func_0013b5d0(u8*, s32, s32, void*, u32, s32, s32, u32, f32, u32, s32);
void func_0013c820(u8*, s32);
void func_0013ce08(u8*, s32);
extern s32 D_00348520[][5];
void func_0013cbb8(u8* self, W317H* h, u8 a2) {
    self[255] = 1;
    s32 idx = func_0013cb90();
    s32 c0 = D_00348520[idx][0];
    if (h->kind == 10) c0 = 8;
    func_0013b5d0(self, 0, c0, 0, a2, 28, 388 - h->count * 22, 0, 1.0f, 0x80b4b4b4, 2);
    s32 y = 410 - h->count * 22;
    s32 i = 0;
    if (h->count > 0) {
        W317E* e = h->e;
        W317H* p = h;
        do {
            u8* q = (u8*)func_001b8e88(p->e[0].id);
            s32 c = 0;
            s32 r = func_0013b988(self, h, p->e[0].b, i++, 0, 1);
            if (p->e[0].c) c = D_00348520[idx][p->e[0].c];
            p = (W317H*)((u8*)p + 12);
            u32 t = func_00192048(*(u32*)(q + 8));
            func_0013b5d0(self, 0, c, e, a2, 28, y, t, 1.0f, r, 2);
            y += 22;
            e++;
        } while (i < h->count);
    }
    *(s32*)(self + 220) = h->count;
    for (s32 j = h->count; j < 7; j++) func_0013c820(self, 0);
    __asm__("" : "+r"(self));
    func_0013ce08(self, h->count);
}

s32 func_00139d78(W317Obj*);
extern W317G* D_0035ed40;
static inline void w317upd(void* p) {
    W317Obj* o = (W317Obj*)p;
    if (func_00139d78(o)) o->vt->f20(o);
}
void func_00246f80(void) {
    w317upd(&D_0035ed40->b0);
    w317upd(&D_0035ed40->b1);
    s32 k = 0;
    s32 ob = 0;
    s32 oa = 0;
    do {
        w317upd((u8*)D_0035ed40 + oa + 7848);
        w317upd((u8*)D_0035ed40 + oa + 9480);
        w317upd((u8*)D_0035ed40 + oa + 11112);
        w317upd((u8*)D_0035ed40 + oa + 12744);
        w317upd((u8*)D_0035ed40 + ob + 872);
        w317upd((u8*)D_0035ed40 + ob + 2616);
        w317upd((u8*)D_0035ed40 + ob + 4360);
        w317upd((u8*)D_0035ed40 + ob + 6104);
        k++;
        __asm__("" : "+r"(k));
        ob += 436;
        oa += 408;
    } while (k < 4);
}
}
