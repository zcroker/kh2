#include "../common/types.h"

typedef void (*VFn)(void*);

extern "C" {
void func_00167ea8(void);
void func_00169308(void);
void func_00108080(void);
void func_00149db8(void);
void func_00102688(u32, s32, s32);
void func_00169350(void);
void func_00149ec0(void*);
void func_001de910(void);
void func_0013a958(void*);
void func_00181ba0(void);
void func_001053c0(void);
s32 func_002fea18(void);
void func_00132270(void*);
void func_00108398(void*);
void func_0014fcd8(void*);
s32 func_00139538(void*);
void func_00138c40(void*, s32, u32);
void func_0023acd8(void*);
void* func_0023ee30(u32);
void func_0031a838(void*);
void func_002369a0(void*);
void func_0023c008(void*);
void func_00153ea0(void*, u32, s32, u32, s32);
void func_002fee78(char*, const char*, ...);
void func_001447e0(void*, void*, void*);
void func_00167658(void*, s32);
s32 func_00141080(u32);
s32 func_001b9d40(u32);
void func_001835a0(u32, f32);
void func_00175b68(u32);
void func_0016d110(void);
u32 func_0016cd48(u32, s32);
u8* func_00198bd0(u32, s32);
void func_00198ee8(u8*);
void func_002ba2e8(s32, s32);
void func_001ac728(u32);
void func_001abbf0(void*);
void func_001c1060(void);
void func_001b5400(void);
void func_00102750(u32);
void func_0013b320(void*);
s32 func_001d3c78(void*);
void func_002fde18(void*, s32, s32);
s32 func_00105c30(void);
s32 func_00242e48(void);
u32 func_00252110(void);
s32 func_001a6d08(u8);
u8* func_00256b68(s32);
s32 func_00139d78(void*);
s32 func_0028acc8(u32);
void func_0028abe0(u32);
s32 func_0028be58(u32);
void func_0028be18(u32);
u8* func_002859a0(void);
void func_0028e438(void*, s32, s32, u32);
s32 func_00287bc0(void);
u8* func_002766d0(void);
u8* func_002983d8(s32);
u8* func_002891b8(u32, s32);
u32 func_00192048(s32);
void func_002b7fbc(s32);
void func_002bc798(void);
void func_002ba9c0(void);
void func_002bc470(s32);
void func_002bcf58(void*);
void func_002bcfa0(void*);
void func_002baa60(void);
void func_002bc608(s32);
void func_002bbf98(void);
void func_002be148(void*);
void func_00170950(u32);
void func_001b86e0(u32);
void func_00170320(s32);
void func_0017f540(void*, s32, f32, f32);
u32 func_002d1260(void);
void func_001c0d38(void*, u32, s32, s32);
void func_002e7568(void*, s32, void*, f32);
void func_002db968(void*, s32);
void func_002eb9d8(u32, u8*, s32, f32);

extern u8 D_0032bad8;
extern u8 D_0032baf0;
extern u32 D_0032b96c;
extern u8 D_00347c30[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0034a7a0[];
extern char D_0036b3c0[];
extern u32 D_0034d788[];
extern u32 D_0034d7ac;
extern u8 D_0034d6c0[];
extern s32 D_004f5250;
extern f32 D_00349e10;
extern s16 D_0034a458[19][3];
extern u32 D_0034f240;
extern u8* D_01d48da0;
extern u32 D_00351214;
extern u32 D_0033caf0;
extern u32 D_0033caf4;
extern u8 D_003712d0;
extern u8 D_00372600[];
extern u32 D_0035f01c;
extern u32 D_0035f04c;
extern s8 D_0035f5a0;
extern s16* D_0035f598;
extern u32 D_0035f200;
extern u8 D_01e2a410;
extern union { u32 v; u8 c; } D_003617fc;
extern u8 D_003637e0[];
extern u8 D_003628f0;
extern f32 D_01e2c044;

// Frame/system reset sequence.
void func_00104e18(void) {
    D_0032bad8 = 0;
    func_00167ea8();
    func_00169308();
    func_00108080();
    func_00149db8();
    func_00102688(D_0032b96c, 1, 1);
    func_00169350();
    func_00149ec0(&D_0032baf0);
    func_001de910();
    func_0013a958(&D_0032baf0);
    func_00181ba0();
    func_001053c0();
}

// Scales x by a random integer normalised to [0, 1].
f32 func_00106558(f32 x) {
    return x * (f32)func_002fea18() / 2147483520.0f;
}

// Constructor: base ctor, vtable, four 144-byte members, cleared tail fields.
void func_001324b8(u8* p) {
    func_00132270(p);
    *(void**)p = D_00347c30;
    u8* e = p + 48;
    for (s32 i = 3; i != -1; i--) {
        func_00108398(e + 16);
        e += 144;
    }
    *(u32*)(p + 624) = 0;
    *(u32*)(p + 628) = 0;
    *(u32*)(p + 632) = 0;
    *(u32*)(p + 636) = 0;
    *(u32*)(p + 8) = 1;
}

struct WNode { u16 h0; u16 h2; u32 w4; u32 w8; u32 tag; u64 idx : 15; u64 rest : 49; };
struct WCtx { u8 pad[24]; WNode* cur; u32 pad28; union { WNode* top; u16 h; }; };
void wtarget_00133ae8(u32, u32, u32, u32) asm("_Z16wtarget_00133ae8jjjj");
// Closes the current DMA packet: stores its qword count and an end tag.
void wtarget_00133ae8(u32 a0, u32 a1, u32, u32) {
    WCtx* c = (WCtx*)a0;
    WNode* t = c->top;
    t->idx = ((u32)c->cur - (u32)t - 32) >> 4;
    if ((u8)a1 && c->top->idx == 0) {
        c->cur = c->top;
    } else {
        c->top->h0 = c->top->idx + 1;
        c->top->tag = c->top->h0 | 0x50000000;
    }
    c->top = 0;
}

void func_0014fba0(void) {
    for (s32 i = 0; i < 19; i++)
        for (s32 j = 0; j < 3; j++)
            D_0034a458[i][j] = 0;
}

void func_00151f40(u8* p) {
    func_0014fcd8(p);
    if (func_00139538(p + 48)) {
        (*(VFn*)(*(u8**)p + 20))(p);
        return;
    }
    func_00138c40(p + 48, 0, *(u32*)(p + 36));
    for (s32 i = 0; i < *(s32*)(p + 2896); i++)
        func_0023acd8(p + 456 + i * 344);
}

void* cam_sxfs(u32, u32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
// Allocates and constructs a 164-byte cross-fade object.
void* cam_sxfs(u32 a0, u32 a1) {
    u8* p = (u8*)func_0023ee30(164);
    *(void**)p = D_00347f98;
    func_0031a838(p + 12);
    *(void**)p = D_0035eb98;
    func_002369a0(p + 24);
    func_0023c008(p + 48);
    *(void**)p = D_0034a7a0;
    func_00153ea0(p, a0, 4800, a1, 0);
    return p;
}

// Formats v as decimal and maps each digit through tbl; returns digit count.
s32 func_0015b4f8(s32* tbl, s32 v, s32* out) {
    char buf[16];
    func_002fee78(buf, D_0036b3c0, v);
    s32 n = 0;
    for (s32 i = 0; i < 16; i++) {
        if (!buf[i]) break;
        u32 d = buf[i] - '0';
        *out++ = tbl[d];
        n++;
    }
    return n;
}

typedef void (*VFn3)(void*, void*, void*);
void func_00161770(u8* p) {
    u8 a[16];
    u8 b[16];
    u8* o = *(u8**)(p + 72);
    (*(VFn3*)(*(u8**)o + 20))(o, a, b);
    func_001447e0(p + 84, a, b);
}

void func_00167f38(s32 idx) {
    D_0034d7ac = D_0034d788[idx];
    u8* p = D_0034d6c0;
    u8* end = p + 192;
    do {
        func_00167658(p, 255);
        p += 96;
    } while ((s32)p < (s32)end);
    D_004f5250 = idx;
}

struct E16 { u16 id; u16 pad; u32 w[3]; };
struct H16 { u32 f0; s32 count; u32 pad[2]; E16 e[1]; };
// Returns the n-th entry with the given id (id -1 matches any).
E16* func_00168b38(H16* h, s32 id, s32 n) {
    s32 i = 0;
    if (h->count > 0) {
        E16* e = h->e;
        do {
            if (id == -1 || e->id == id) {
                if (--n == -1) return e;
            }
            i++;
            e++;
        } while (i < h->count);
    }
    return 0;
}

void wtarget_001789b8(u32, u32, u32, u32) asm("_Z16wtarget_001789b8jjjj");
void wtarget_001789b8(u32 a0, u32, u32, u32) {
    if (func_00141080(a0) && func_001b9d40(a0)) {
        u64 fl = **(u64**)(a0 + 2872);
        if (fl & 0x100000) func_001835a0(a0, D_00349e10 * -0.052359879f);
        else if (fl & 0x200000) func_001835a0(a0, D_00349e10 * 0.052359879f);
    }
    func_00175b68(a0);
}

struct TGT { u32 w[5]; };
struct TPool { TGT items[128]; s32 freel[128]; s32 count; };
extern TPool D_01c60d50;
TGT* tgt_dup(TGT*) asm("_ZN2YS6TARGET3dupEv");
// Takes a slot from the free list and copies this target into it.
TGT* tgt_dup(TGT* self) {
    s32 n = --D_01c60d50.count;
    TGT* t = &D_01c60d50.items[D_01c60d50.freel[n]];
    *t = *self;
    return t;
}

struct P8 { u32 a; u32 b; };
extern P8 D_00350338[8];
void func_00196888(void) {
    func_0016d110();
    if (D_0034f240 & 0x20) return;
    P8* e = D_00350338;
    for (s32 i = 7; i >= 0; i--, e++) {
        if (e->b && !e->a) e->a = func_0016cd48(e->b, 0);
    }
}

struct S36 { u32 w[9]; };
S36 func_00199098(u32 a1) {
    u8* v = func_00198bd0(a1, -1);
    func_00198ee8(v);
    return *(S36*)(v + 52);
}

void func_001abe80(s32* a0, u32 a1, u8* a2) {
    switch (*a0) {
    case 0:
        break;
    case 1:
        if (*(u64*)(a2 + 8) & 0x40c) {
            func_002ba2e8(24, 0);
            func_001ac728(a1);
        }
        break;
    case 2:
        func_001abbf0((u8*)a0 + 348);
        break;
    }
}

struct B4 { u8 c0; u8 c1; u8 c2; u8 b0 : 1; u8 rest : 7; };
void func_001b6d88(B4* p, s32 a1) {
    if (a1 == 3 && p->c0 >= 3) {
        p->c0++;
        return;
    }
    p->c0 = a1;
    if (a1 == 2) p->b0 = 0;
}

static inline u8* b9next(u8* n) {
    if (!n) return D_01d48da0;
    return *(u8**)(n + 2228);
}
void func_001b92f8(void) {
    func_001c1060();
    func_001b5400();
    u8* n = 0;
    while ((n = b9next(n))) {
        if (!(*(u32*)(n + 264) & 0x80000)) (*(VFn*)(*(u8**)n + 40))(n);
    }
    func_00102750(D_00351214);
}

void func_001bdc88(u8* p) {
    if (*(u32*)(p + 32) & 0x40) {
        func_0013b320(p);
        *(u32*)(p + 32) &= ~0x40;
    }
}

struct T64 { u32 f0; s32 count; u8 e[1][64]; };
extern T64* D_01d5ba28;
// Finds the first valid 64-byte entry whose id matches.
u8* func_001d3fe0(u32 id) {
    for (s32 i = 0; i < D_01d5ba28->count; i++) {
        u8* e = D_01d5ba28->e[i];
        if (func_001d3c78(e) && *(u16*)(e + 40) == id) return e;
    }
    return 0;
}

void func_001d7f80(u8* p) {
    for (s32 i = 0; i < *(s32*)(p + 712); i++) {
        u8* o = ((u8**)(p + 676))[i];
        if (!(*(u32*)(o + 12) & 0x10)) (*(VFn*)(*(u8**)o + 4))(o);
    }
    *(u32*)(p + 4) |= 1;
}

void func_001e6b00(u8* p) {
    func_002fde18(p, 0, 336);
    f32* f = (f32*)p;
    u32* w = (u32*)p;
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    *(u16*)(p + 134) = 8;
    f[3] = 1.0f;
    f[8] = 1.0f;
    f[9] = 1.0f;
    f[10] = 1.0f;
    f[11] = 1.0f;
    w[4] = 0;
    w[5] = 0;
    w[6] = 0;
    w[7] = 0;
    f[12] = 1.0f;
    f[13] = 1.0f;
    f[14] = 1.0f;
    f[15] = 1.0f;
    f[16] = 1.0f;
    f[17] = 1.0f;
    f[18] = 1.0f;
    f[19] = 1.0f;
}

u32 func_00232348(void) {
    u32 r;
    if (func_00105c30() == 8) {
        if (func_00242e48()) r = (u32)&D_003712d0;
        else r = D_0033caf0;
    } else r = D_0033caf4;
    return r;
}

struct F184 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
void func_00239e60(u8* p, f32 x, f32 y, f32 z) {
    *(f32*)(p + 308) = x;
    *(f32*)(p + 312) = y;
    *(f32*)(p + 316) = z;
    ((F184*)(p + 184))->b1 = !(x == 1.0f && y == 1.0f && z == 1.0f);
}

s32 func_00252710(void) {
    s32 r = 0;
    u8 c = D_00372600[func_00252110()];
    if (c) r = func_001a6d08(c) != 0;
    return r;
}

void cmitem_leave(void) asm("_ZN2Tz6CmItem13LeaveCategoryEv");
void cmitem_leave(void) {
    u8* o = func_00256b68(1);
    if (func_00139d78(o)) (*(VFn*)(*(u8**)o + 20))(o);
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028be58(D_0035f04c)) func_0028be18(D_0035f04c);
}

// Sets a bit in the flag array at +204 if not already set.
void func_002865d0(u32 bit) {
    u32* a = (u32*)(func_002859a0() + 204);
    u32 i = bit >> 5;
    u32 m = 1 << (bit & 31);
    if (!(a[i] & m)) a[i] |= m;
}

void func_0028e560(void* p, s16* a, s32 n, u32 a3) {
    func_00139d78(p);
    for (s32 i = 0; i < n; i++) func_0028e438(p, i, *a++, a3);
}

void func_00298e48(void) {
    if (func_00287bc0() != 5) return;
    u8* v;
    u8* s = func_002766d0() + 3376;
    v = func_002983d8(D_0035f598[D_0035f5a0 + 2]);
    *(u32*)(s + 408) = func_00192048(*(u16*)(v + 8));
    u8* s2 = func_002891b8(D_0035f200, 0);
    *(u32*)(s2 + 408) = func_00192048(*(u16*)(v + 10));
}

void func_002b9f28(u8 a) {
    if (a) func_002b7fbc(1);
    else func_002b7fbc(0);
    func_002bc798();
    func_002ba9c0();
    func_002bc470(2);
    func_002bc470(3);
    func_002bcf58(&D_01e2a410);
    func_002bcfa0(&D_01e2a410);
    func_002baa60();
    func_002bc608(0);
    func_002bc608(1);
    func_002bc608(2);
    func_002bbf98();
}

void func_002bdac8(u8* p) {
    func_002be148(p);
    u8* o = *(u8**)(p + 16);
    while (o) {
        u8* next = *(u8**)(o + 32);
        if (o) (*(VFn*)(*(u8**)o + 4))(o);  // virtual deleting destructor
        o = next;
    }
    if (*(u32*)(p + 104)) func_00170950(*(u32*)(p + 104));
    func_001b86e0(*(u32*)(p + 4));
    func_00170320(-200);
    D_003617fc.v = 0;
    *(void**)(p + 8) = D_003637e0;
}

void func_002dbca0(u8* p, u8 flag) {
    func_0017f540(p + 320, 0, 0.0f, 0.0f);
    func_001c0d38(p, func_002d1260(), 67, 0);
    if (flag) func_002e7568(p, 2, &D_003628f0, 1.0f);
    func_002db968(p, 1);
}

void func_002ebac0(u32 a0, u8* a1) {
    *(f32*)(a1 + 276) = *(f32*)(a1 + 272) = 20.0f;
    *(f32*)(a1 + 284) = D_01e2c044;
    func_002eb9d8(a0, a1, 254, 4.0f);
}
}

struct W63Vec {
    f32 x, y, z, w;
    W63Vec& operator=(const W63Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline void vsub(W63Vec* d, const W63Vec* a, const W63Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vadd(W63Vec* d, const W63Vec* a, const W63Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vscale(W63Vec* d, const W63Vec* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
// Normalises xyz in place; returns the original length.
static inline f32 vnormalize(W63Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

struct W63Body { W63Vec pos; u8 pad[32]; W63Vec vel; };

extern "C" {
// Stores the horizontal (y = 0) unit direction from +1344 towards *target, and w.
void func_001837c0(u8* p, const W63Vec* target, f32 w) {
    W63Vec d;
    W63Vec t;
    vsub(&t, target, (W63Vec*)(p + 1344));
    d = t;
    d.y = 0.0f;
    vnormalize(&d);
    *(W63Vec*)(p + 16) = d;
    *(f32*)(p + 28) = w;
}

// Moves pos a fifth of the way towards vel, with gravity on y; returns pos.y < 0.
s32 func_001cc888(W63Body* b) {
    W63Vec d;
    W63Vec t;
    vsub(&t, &b->vel, &b->pos);
    vscale(&d, &t, 0.2f);
    d.y = b->vel.y * D_00349e10;
    b->vel.y += D_00349e10 * 0.4f;
    vadd(&b->pos, &b->pos, &d);
    return b->pos.y < 0.0f;
}

struct F112 { u32 b0 : 1; u32 b1 : 2; u32 b3 : 4; u32 rest : 25; };
struct F116 { u32 c0 : 1; u32 c1 : 1; u32 c2 : 1; u32 rest : 29; };
// Resets state flags and clears six vectors to (0,0,0,1) with VU0 vf0.
void func_0031b9e0(u8* p) {
    F112* a = (F112*)(p + 112);
    F116* b = (F116*)(p + 116);
    *(u32*)(p + 104) = 0;
    *(u32*)(p + 108) = 0;
    *(u32*)(p + 120) = 0;
    *(u32*)(p + 124) = 0;
    *(u32*)(p + 128) = 0;
    a->b0 = 0;
    a->b1 = 2;
    a->b3 = 6;
    *(s16*)(p + 96) = -1;
    *(s16*)(p + 98) = -1;
    *(s16*)(p + 100) = -1;
    b->c0 = 0;
    b->c1 = 1;
    b->c2 = 0;
    asm volatile(".set noreorder\n\tsqc2 $vf0, 0(%0)\n\tsqc2 $vf0, 0(%1)\n\tsqc2 $vf0, 0(%2)\n\tsqc2 $vf0, 0(%3)\n\tsqc2 $vf0, 0(%4)\n\tsqc2 $vf0, 0(%5)\n\t.set reorder"
        : : "r"(p), "r"(p + 16), "r"(p + 32), "r"(p + 48), "r"(p + 64), "r"(p + 80) : "memory");
}
}
