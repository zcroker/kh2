#include "../common/types.h"

// Built with -fno-strict-aliasing (_nsa).
// 001db688 / 001db710: an inlined constructor with const sz/cnt members. The const
// member stores are RTX_UNCHANGING, so the epilogue's ld ra must wait for them.

struct W8009Al;
typedef struct W8009AlVt { u8* (*alloc)(struct W8009Al*, s32, s32); } W8009AlVt;
struct W8009Al { W8009AlVt* vt; };
extern "C" u8 D_00352a38[];

struct W8009Pool {
    void* vt;
    W8009Al* al;
    s32 p8;
    u8* buf;
    u8* end;
    const s32 sz;
    const s32 cnt;
    static void* operator new(unsigned int, void* p) { return p; }
    inline W8009Pool(W8009Al* a, s32 s, s32 c)
        : vt(D_00352a38), al(a), buf(a->vt->alloc(a, (s + 4) * c, 0)), end(buf + s * c), sz(s), cnt(c) {}
};

extern "C" {
void func_001db850(W8009Pool*);

void func_001db688(W8009Pool* p, W8009Al* a, s32 sz, s32 cnt) {
    new (p) W8009Pool(a, sz, cnt);
    func_001db850(p);
}

void func_001db710(W8009Pool* p, W8009Al* a, s32 sz, s32 cnt) {
    new (p) W8009Pool(a, sz, cnt);
    func_001db850(p);
}
}

// 001d5d80: one function-scope result variable reused at both add_item sites.
struct Buf1d5d80 { u8 d[80]; };
struct Ent1d5d80 { u8 pad0; u8 n; u16 snd; };
struct Cnt1d5d80 { u8 pad[2]; u8 cnt; u8 pad2[5]; u8 tbl[1]; };
struct Sub1d5d80 { u8 pad[580]; u8* tbl; Cnt1d5d80* c; };
struct Obj1d5d80 { u8 pad[1164]; Sub1d5d80* sub; };
struct NoTail1d5d80 { ~NoTail1d5d80() {} };
extern "C" {
Ent1d5d80* func_001d5b78(void*, u8);
void func_001b74b8(Buf1d5d80*);
void func_001b74c8(Buf1d5d80*, s32);
s32 func_001d5ec0(void*, s32, void*, s32);
void func_001b7538(Buf1d5d80*, s32);
void func_001a3188(s32, s32, s32);
void func_001b76c8(Buf1d5d80*, void*, s32);
void func_001a1460(Sub1d5d80*);
void func_001d7778(void);
void func_001d5d80(Obj1d5d80* o, void* a) {
    NoTail1d5d80 nt; s32 r;
    Buf1d5d80 b0, b1;
    Sub1d5d80* s = o->sub;
    Cnt1d5d80* c = s->c;
    u8* t = s->tbl;
    Ent1d5d80* e = func_001d5b78(a, ++c->cnt);
    func_001b74b8(&b0);
    func_001b74b8(&b1);
    func_001b74c8(&b0, 0xc3f2);
    if (((u8*)e)[-7] < e->n) {
        r = func_001d5ec0(c->tbl, 24, a, e->n); func_001b7538(&b0, r);
        r = func_001d5ec0(t + 84, 80, a, e->n - 1); func_001b7538(&b1, r);
    }
    if (e->snd) {
        func_001a3188(e->snd, 1, 0);
        func_001b7538(&b1, e->snd);
    }
    func_001b76c8(&b0, a, c->cnt);
    func_001b76c8(&b1, 0, c->cnt);
    func_001a1460(o->sub);
    func_001d7778();
}
}

// 001d2e68: VU0 macro asm (vsub, normalize) and lq/sq copy. Reading the D_00352130
// pointer through a u8 array keeps its load free of the register-save stores.
extern "C" {
struct V1d2e68 {
    f32 x, y, z, w;
    V1d2e68() {}
    V1d2e68& operator=(const V1d2e68& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V1d2e68 sub_1d2e68(const V1d2e68& a, const V1d2e68& b) {
    V1d2e68 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 norm_1d2e68(V1d2e68* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct P1d2e68 { u8 p0[256]; f32 f100; f32 f104; f32 f108; };
struct S1d2e68 { f32 a, b, c; s32 d; V1d2e68 pos; u8 pad[16]; };
struct O1d2e68 { u8 p0[2548]; u8 tgt[4]; };
extern u8 D_00352130[];
s32 func_00190140(void*) asm("_ZNK2YS6TARGET8is_existEv");
void func_001902a8(void*, S1d2e68*);
V1d2e68 func_0016bda8(O1d2e68*) asm("_Z16ctarget_0016bda8jjjj");
V1d2e68 func_0017d538(V1d2e68*, f32);
V1d2e68 func_0016af58(O1d2e68*);
V1d2e68 func_001d2e68(void* self, O1d2e68* o) {
    V1d2e68 r;
    P1d2e68* prm = *(P1d2e68**)D_00352130;
    S1d2e68 s;
    s.d = 0;
    if (func_00190140(o->tgt)) {
        func_001902a8(o->tgt, &s);
        r = sub_1d2e68(s.pos, func_0016bda8(o));
        f32 d = norm_1d2e68(&r) - s.b;
        if (d < 0.0f) d = 0.0f;
        if (d < prm->f104) {
            f32 t = (d - prm->f104) / (prm->f108 - prm->f104);
            f32 c;
            if (t < 0.0f) c = 0.0f;
            else if (1.0f < t) c = 1.0f;
            else c = t;
            r = func_0017d538(&r, prm->f100 * c);
        }
        r.w = d;
    } else {
        r = func_0016af58(o);
        *(s32*)&r.w = 0;
    }
    return r;
}
}

// 001eb668: the h8 store goes through a byte-offset cast. As a plain field store it
// ranks lhu above the lui of D_01d9e6e8 in sched2.
struct Prm1eb668 {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; s32 w76; s32 pad80[4];
};
struct Slot1eb668 { u8 pad[28]; u32* h; s32 w32; };
struct Sys1eb668 { u8 pad[16]; Slot1eb668* slots; };
struct Sys21eb668 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Arg11eb668 { s32 w0; s32 idx; u16 h8; };
struct Arg21eb668 { u8 pad[12]; s32* off; };
struct Pos1eb668 { s16 v[4]; };
extern Sys1eb668* D_01d9e6e4;
extern Sys21eb668* D_01d9e6e8;
extern s32 D_01d9eaa4;
extern u8 D_01d9eac0[];
extern u8 D_01d9e9c0[];
extern u8 D_01d9e980[];
extern "C" {
s32 func_0020f1e0(u32*, Prm1eb668*, s32);
void func_001eb668(u8* base, Arg11eb668* a, Arg21eb668* b) {
    Prm1eb668 prm;
    s32 idx = a->idx;
    if (idx == 0xffff) return;
    u8* q = base + *b->off;
    Pos1eb668* ps = (Pos1eb668*)(q + 0xa0);
    prm.c27 = ps->v[3] >> 7;
    if (prm.c27 == 0) return;
    Slot1eb668* s = &D_01d9e6e4->slots[idx];
    u32* h = s->h;
    prm.flags = 0x80;
    if (!(*h & 2)) prm.flags = 0x90;
    Sys21eb668* g = D_01d9e6e8;
    *(u16*)((u8*)&prm + 8) = a->h8;
    prm.b10 = 0;
    prm.w28 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    prm.c24 = ((Pos1eb668*)(q + 0xa0))->v[0] >> 7;
    prm.c25 = ps->v[1] >> 7;
    prm.c26 = ps->v[2] >> 7;
    prm.p32 = g->a80;
    prm.p36 = D_01d9e9c0;
    prm.p40 = D_01d9e980;
    prm.p44 = g->a16;
    prm.w52 = D_01d9eaa4;
    prm.w68 = 0;
    D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
}
}
