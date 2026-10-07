#include "../common/types.h"

typedef void (*VFn)(void*);
struct VObj { VFn* vt; };
struct NoTail { ~NoTail() {} };
struct E64 { u8 d[64]; ~E64() {} };
struct Arr24 { E64 e[24]; };

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq VSub(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vq VScale(const Vq& v, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
    return r;
}
static inline f32 VLength(const Vq& v) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(d) : "r"(&v) : "$8", "memory");
    return d;
}

extern "C" {
void* func_001050d8(u32);
void* func_001daef8(void*, void*);
extern void* D_00352a08[];
extern void* D_003529f0[];
extern void* D_003529d8[];
}

// Creates the event object matching the record type.
struct W84Ev {
    void** vt;
    u8 pad[108];
    static void* operator new(unsigned int n) { return func_001050d8(n); }
    W84Ev(u16* p) { func_001daef8(this, p); }
};
struct W84Ev0 : W84Ev { W84Ev0(u16* p) : W84Ev(p) { vt = D_00352a08; } };
struct W84Ev1 : W84Ev { W84Ev1(u16* p) : W84Ev(p) { vt = D_003529f0; } };
struct W84Ev2 : W84Ev { W84Ev2(u16* p) : W84Ev(p) { vt = D_003529d8; } };

extern "C" {

// Formats a 3-letter code (or three numbers) into the shared text buffer.
extern char D_003a7b20[];
extern char D_00369e58[];
extern char D_00369e60[];
extern char D_00369e70[];
s32 func_00105140(void*, s32);
s32 func_002fee78(char*, const char*, ...);
s32 func_002ff3fc(const char*);
struct Dt {
    u8 a, b, c, pad;
    u16 x, y, z;
};
char* func_001051b8(Dt* p) {
    func_002fee78(D_003a7b20, D_00369e58, func_00105140(p, 0), p->c);
    if (p->x < 25 && p->y < 25 && p->z < 25) {
        func_002fee78(D_003a7b20 + func_002ff3fc(D_003a7b20), D_00369e60, p->x + 97, p->y + 97, p->z + 97);
    } else {
        func_002fee78(D_003a7b20 + func_002ff3fc(D_003a7b20), D_00369e70, p->x, p->y, p->z);
    }
    return D_003a7b20;
}

// Destructor: release the 24 slot objects, then the member array and base.
extern void* D_003476f0[];
void func_001dc920(void*);
void func_00117910(void*, s32);
void func_0018f028(void*);
void func_00113668(void*);
void func_00117d18(u8* p) {
    NoTail nt;
    *(void**)p = D_003476f0;
    s32 i = 0;
    void** e = (void**)(p + 40);
    do {
        void* o = *e;
        e += 16;
        if (o) func_001dc920(o);
        func_00117910(p, i);
        i++;
    } while (i < 24);
    void* x = *(void**)(p + 1568);
    if (x) {
        func_0018f028(x);
        *(void**)(p + 1568) = 0;
    }
    ((Arr24*)(p + 32))->~Arr24();
    func_00113668(p);
}

extern s32 D_0034a7d8[];
extern s32 D_0034a7e8[];
u32 func_0013d7e0(void*);
s32 func_00236490(u32);
s32 func_002364f8(u32);
void func_00154100(u8* p, s32* a, s32* b) {
    *a = 0;
    *b = 0;
    for (s32 i = 0; i < *(s32*)(p + 832); i++) {
        *a += D_0034a7d8[i];
        *b += D_0034a7e8[i];
    }
    u32 o = func_0013d7e0(p);
    *a += func_00236490(o) + 13568;
    *b += func_002364f8(o) + 10240;
}

void func_00158300(void*);
void func_00157758(void*);
void func_001577c8(void*);
void func_001578d8(void*);
void func_00157a00(void*);
void func_00157ae0(void*);
s32 func_00157100(void*);
void func_001571c0(void*);
s32 func_00157130(void*);
void func_001574d8(void*);
void func_00156d20(void*);
s32 func_001570a0(void*);
void func_00157068(void*);
s32 func_001570d0(void*);
void func_00157c88(void*);
void func_00157f08(u8* p) {
    func_00158300(p);
    func_00157758(p);
    func_001577c8(p);
    if (*(u32*)(p + 52) == 0) return;
    if (*(u32*)(p + 12) & 0x100) return;
    func_001578d8(p);
    func_00157a00(p);
    func_00157ae0(p);
    if (func_00157100(p)) {
        func_001571c0(p);
    } else if (func_00157130(p)) {
        func_001574d8(p);
        func_00156d20(p);
    } else if (func_001570a0(p)) {
        func_00157068(p);
    } else if (func_001570d0(p)) {
        func_00156d20(p);
    } else {
        func_00157c88(p);
    }
    *(u32*)(p + 15600) = *(*(u8**)(*(u8**)(p + 52) + 1164) + 431);
}

// Runs every entry flagged in the 64-bit mask, then sweeps the 64 lists.
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void func_00143228(void);
void func_00160de0(s32);
void* func_001de4b0(void*, s32, void*);
s32 func_001dc9e0(void*);
void func_001dcc30(void*);
void func_0015f618(void) {
    func_00143228();
    for (s32 i = 0; i < 64; i++) {
        u64 m = (u64)1 << i;
        if (D_0034c710 & m) func_00160de0(i);
    }
    void* o = 0;
    if (D_0034c70c == 1) {
        for (s32 i = 0; i < 64; i++) {
            while ((o = func_001de4b0(D_0034c6f0, i, o)) != 0) {
                if (func_001dc9e0(o)) func_001dcc30(o);
            }
        }
    }
}

s32 func_001c0cd8(void*);
void func_001c0e60(void*);
void func_00177498(void*);
void func_001a1840(void*);
void func_00186020(void*);
void func_00175928(u8* p) {
    if (*(u32*)(p + 264) & 0x10000000) return;
    if (func_001c0cd8(p)) func_001c0e60(p);
    func_00177498(p);
    VObj** a = (VObj**)(p + 2808);
    for (s32 i = 1; i >= 0; i--) {
        VObj* o = *a++;
        if (o) o->vt[8](o);
    }
    if (*(void**)(p + 1164)) func_001a1840(*(void**)(p + 1164));
    func_00186020(p);
}

struct Cfg {
    u8 _0[60];
    f32 f60;
    u8 _64[20];
    f32 f84;
    u8 _88[24];
    f32 f112;
    u8 _116[4];
    f32 f120;
};
extern Cfg* D_00352130;
s32 func_001a1de0(void*);
Cfg* func_00177860(void*);
f32 func_001bbfd0(void);
void func_001a1aa0(void*, s32);
void func_001a1b68(void*, f32);
static inline bool Is12(u8* p) { return *(s32*)(p + 2896) == 12; }
void func_00179a68(u8* p, f32 f) {
    u8* q = *(u8**)(p + 1164);
    switch (q[431]) {
    case 2:
        if (Is12(p)) break;
    case 3:
        func_001a1b68(q, f * D_00352130->f112);
        break;
    case 1:
        if (func_001a1de0(q)) {
            f *= D_00352130->f120 * func_00177860(p)->f60;
        }
        f *= func_001bbfd0();
        func_001a1aa0(*(u8**)(p + 1164), (s32)f);
        break;
    }
}

// Drops every node of the list at +396 that is no longer alive.
struct LNode { u8 _0[44]; LNode* next; };
struct LList {
    LNode* head;
    LNode* tail;
};
struct LOwner { u8 _0[396]; LList list; };
static inline __attribute__((always_inline)) void LRemove(LList* l, LNode* n) {
    LNode* prev;
    if (n == l->head) {
        prev = 0;
        l->head = n->next;
    } else {
        for (prev = l->head; prev->next != n; prev = prev->next) {}
        prev->next = n->next;
    }
    if (n == l->tail) l->tail = prev;
    n->next = 0;
}
static inline __attribute__((always_inline)) LNode* LNext(LOwner* o, LNode* n) {
    if (!n) return o->list.head;
    return n->next;
}
s32 func_001dc9d0(void*);
void func_00180e28(LOwner* p) {
    LNode* n = p->list.head;
    LNode* it = n;
    while (n) {
        it = LNext(p, it);
        if (!func_001dc9d0(n)) LRemove(&p->list, n);
        n = it;
    }
}

u8* func_001b9bc8(u8*);
s32 func_0019bb18(u8*);
s32 func_00144d10(u8*, u8*);
s32 func_002cf1f8(u8*, u8*);
void func_001b7a18(u32, u32, u32);
void func_00183848(u8* a, u32 b) {
    u8* o = 0;
    while ((o = func_001b9bc8(o)) != 0) {
        if (!func_0019bb18(o)) continue;
        if (*(u8**)(a + 1392) == o) continue;
        if (*(u8**)(o + 1392) == a) continue;
        if (o == a) continue;
        if (*(u32*)(a + 2224) && *(u32*)(o + 2224)) {
            if (!func_00144d10(a + 1856, o + 1856)) continue;
        }
        if (!func_002cf1f8(a, o)) continue;
        func_001b7a18(*(u32*)(a + 2088), *(u32*)(o + 2088), b);
    }
}

void func_001980d0(void*);
void func_0018c420(void*);
extern void* D_0034ee90[];
void func_0018aba0(u8* p) {
    func_001980d0(p);
    *(void**)p = D_0034ee90;
    *(f32*)(p + 2596) = *(f32*)(p + 2592) = 0.0f;
    *(u32*)(p + 2608) = 0;
    func_0018c420(p + 2624);
    func_0018c420(p + 2720);
    *(f32*)(p + 2816) = 0.0f;
    *(u32*)(p + 1416) |= 8;
    *(u32*)(p + 1536) = (*(u32*)(p + 1536) & ~0x78) | 0x18;
    *(u32*)(p + 2824) = 0;
    *(u32*)(p + 2820) = 0;
    *(u32*)(p + 2828) = 0;
    *(f32*)(p + 2832) = 360.0f;
    *(f32*)(p + 2836) = 720.0f;
    *(f32*)(p + 2840) = 60.0f;
    *(f32*)(p + 2844) = 360.0f;
    *(f32*)(p + 2848) = 720.0f;
    *(f32*)(p + 2852) = 180.0f;
    *(f32*)(p + 2856) = 360.0f;
    *(f32*)(p + 2860) = 720.0f;
    *(f32*)(p + 2864) = 180.0f;
}

u8 func_001c0298(u8*, u8*, u8*);
u8* func_0019fee8(u32, u32);
void func_001c0410(u8*, u8*, u8*);
static inline void SetBit(u32* bits, u32 k) {
    u32* w = bits + (k >> 5);
    *w |= 1 << (k & 31);
}
u8* func_001c0320(u8* a, u8* b, u8* out) {
    u8 r = func_001c0298(a, b, out);
    *out = r;
    if (r) {
        if (*(u32*)(b + 32) != *(u32*)(a + 36)) {
            *(u32*)(a + 36) = *(u32*)(b + 32);
            *(u32*)(a + 40) = 0;
        } else {
            (*(u32*)(a + 40))++;
        }
        if (*(u8**)a && (*(u32*)(*(u8**)a + 1416) & 4)) *(f32*)(a + 44) = 30.0f;
    }
    u8* v = func_0019fee8(*(u32*)(b + 40), *(u32*)(a + 40));
    if (*(u16*)(v + 38)) func_001c0410(a, b, v);
    SetBit((u32*)(a + 4), *(u32*)(b + 28));
    return v;
}

void func_001980d0x(void*, u32, s32, void*, f32) asm("func_001980d0");
extern u8 D_01d49520[];
extern void* D_00351408[];
u32 func_001de168(void*, u32, s32, s32, s32, s32);
void func_001dcc00(u32, u32);
void* func_001050d8(u32);
void func_001c1308(void*, u32, u32, u32, u32);
void func_001c2490(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6) {
    func_001980d0x(p, a1, 4, D_01d49520, 0.0f);
    *(void**)p = D_00351408;
    *(u32*)(p + 1416) |= 0x100000;
    u32 h = func_001de168(p + 156, a2, 0, 1, 0, 0);
    func_001dcc00(h, a3);
    void* o = func_001050d8(56);
    func_001c1308(o, h, a4, a5, a6);
    *(void**)(p + 2548) = o;
}

// Converts a radian rotation to fixed angles and applies it.
struct V3 { f32 x, y, z; };
extern V3 D_00354bd0;
extern V3 D_00354bc0;
void func_0021ebe8(void*, s32*);
void func_00201438(u8* a, u8* c) {
    s32 r[3];
    u8* s = a + *(u32*)(*(u8**)(c + 12) + 12) + 160;
    r[0] = (s32)(D_00354bd0.x * 32768.0f / 3.1415927f);
    r[1] = (s32)(D_00354bd0.y * 32768.0f / 3.1415927f);
    r[2] = (s32)(D_00354bd0.z * 32768.0f / 3.1415927f);
    func_0021ebe8(s, r);
    *(f32*)(s + 48) = D_00354bc0.x;
    *(f32*)(s + 52) = D_00354bc0.y;
    *(f32*)(s + 56) = D_00354bc0.z;
}

extern u8* D_01d9e6e8;
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void func_002f4000(void*);
void func_002f3d08(void*, void*, void*);
void func_002f3f40(void*, void*, f32);
void func_002f3cd8(void*, void*, void*);
void func_002f3f98(void*, void*);
void func_00209ed0(u8* a, u32, u8* c) {
    f32 m[16] __attribute__((aligned(16)));
    u8* s = a + *(u32*)(*(u8**)(c + 12) + 4);
    func_002f4000(m);
    f32* v = (f32*)(s + 160);
    m[12] = v[16];
    m[13] = v[17];
    m[14] = v[18];
    func_002f3d08(m, D_01d9e730, m);
    func_002f3f40(D_01d9e6e8 + 80, D_01d9e6e8 + 16, v[20]);
    func_002f3f40(D_01d9e6e8 + 96, D_01d9e6e8 + 32, v[21]);
    func_002f3f40(D_01d9e6e8 + 112, D_01d9e6e8 + 48, v[22]);
    func_002f3cd8(D_01d9e6e8 + 128, m, D_01d9e6e8 + 64);
    func_002f3f98(v, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}

s32 func_00289310(u32);
u32 func_002891e8(u32);
void func_002890e0(u32, s32, s32, s32, s32);
void func_00289038(u32, u32, s32, s32, s32, s32, s32);
s32 func_0028d008(u32);
u32 func_002891d0(u32);
void func_0028cf28(u32, u32);
s32 func_0028d6e8(u32);
void func_0028d660(u32, u32);
extern u32 D_0035f110;
void func_0026eae8(u32 a) {
    if (!func_00289310(a)) return;
    u32 s = func_002891e8(a);
    func_002890e0(a, 1, 2, 0, -1);
    func_00289038(a, s, 1, 1, 2, 0, -1);
    if (func_0028d008(0)) func_0028cf28(0, func_002891d0(a));
    if (func_0028d6e8(D_0035f110)) func_0028d660(D_0035f110, func_002891d0(a));
}

// Creates the manager object and a 4-element array of 5116-byte entries.
struct Heap20 { u8 _0[20]; VObj* a; };
extern Heap20* D_00347f80;
extern void* D_00347e60[];
extern void* D_0035f244;
extern u8* D_0035f248;
extern u8 D_0035f24c;
extern u8 D_0035f24d;
extern u8 D_0035f24e;
void func_00239700(void*);
u32 func_00103570(void);
u8* func_001063f0(u32, u32);
void func_003237e0(void*);
typedef u8* (*AllocFn)(void*, u32, u32);
void func_0027dc40(void) {
    VObj* h = D_00347f80->a;
    u8* o = ((AllocFn*)h->vt)[0](h, 408, 0);
    *(u32*)(o + 12) = 0;
    *(void**)o = D_00347e60;
    func_00239700(o + 24);
    D_0035f244 = o;
    u8* m = func_001063f0(20468, func_00103570());
    *(u32*)m = 4;
    u8* arr = m + 4;
    u8* q = arr;
    for (s32 i = 3; i != -1; i--) {
        func_003237e0(q);
        q += 5116;
    }
    D_0035f248 = arr;
    D_0035f24c = 0xff;
    D_0035f24d = 0xff;
    D_0035f24e = 0xff;
}

u32 func_00316e00(void);
s32* func_00316e10(void);
s32 func_003060f0(void);
s32 func_00305510(void);
void func_002fd408(void*);
extern s32 D_01e4c7a0;
void func_003168d8(void* p) {
    s32 id = D_01e4c7a0;
    if (p) {
        u32* a = (u32*)func_00316e00();
        s32* b = func_00316e10();
        if (id < 9 && b[id]) {
            s32 t = 0;
            if (func_003060f0() != 1) t = func_00305510();
            a[t * 8 + id] = 0;
        }
    }
    if (p) func_002fd408(p);
}

void func_00288c58(void*, s16);
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028af18(void*, s32);
void func_0028b1b0(void*, s32);
union PU { s16 (*p)[4]; s16 s; };
struct Tbl {
    s16 f0, f2, f4, f6_, f8_, f10_, f12_, f14;
    s16 n, f18, f20, f22, f24, f26, f28, f30;
    u32 f32_;
    u8 c36, c37, c38, c39;
    u32 f40;
    PU a;
    PU b;
};
void func_002889f0(Tbl* p, s32 n, u8 c) {
    p->f0 = 0;
    p->n = n;
    p->f2 = -1;
    p->f28 = 1;
    p->c36 = c;
    p->f20 = -1;
    p->f4 = 0;
    p->f18 = 0;
    p->f22 = 0;
    p->f24 = 0;
    p->f26 = 0;
    p->c37 = 0;
    p->c38 = 0;
    p->c39 = 0;
    func_00288c58(p, n);
    func_00288f48(p, 16, 32, 0, 0);
    for (s32 i = 0; i < p->n; i++) {
        for (s32 j = 0; j < 4; j++) {
            p->a.p[i][j] = -1;
            p->b.p[i][j] = -1;
        }
    }
    p->f14 = 0;
    func_0028af18(p, 115);
    func_0028b1b0(p, 0);
}

// Tz::Select::Start
union S16U { s16 v; s32 i; };
struct Sel {
    u8 _0[4];
    S16U n;
    u8 _8[6];
    s16 done;
    u8 _16[24];
    u8** arr;
};
s32 func_0028acc8(Sel*);
u8* func_0028ac98(Sel*, s32);
void func_00138c10(void*, s32);
void sel_start(Sel* s) asm("_ZN2Tz6Select5StartEz");
void sel_start(Sel* s) {
    if (func_0028acc8(s)) {
        for (s32 i = 0; i < s->n.v; i++) {
            if (s->arr[i] == 0) continue;
            u8* r = func_0028ac98(s, i);
            if (!r) continue;
            s16 v = *(s16*)(r + 2);
            if (*(s32*)(s->arr[i] + 388) == v) continue;
            func_00138c10(s->arr[i], v);
            *(s32*)(s->arr[i] + 392) = -1;
        }
    }
    s->done = 1;
}

// Quaternion product o = a * b.
struct Qt { f32 x, y, z, w; };
void func_002e3f58(Qt*, Qt*, Qt*);
Qt* func_002e46d0(Qt* o, Qt* a, Qt* b) {
    func_002e3f58(o, a, b);
    o->w = a->w * b->w - (a->x * b->x + a->y * b->y + a->z * b->z);
    o->x = (a->w * b->x + b->w * a->x) + (a->y * b->z - a->z * b->y);
    o->y = (a->w * b->y + b->w * a->y) + (a->z * b->x - a->x * b->z);
    o->z = (a->w * b->z + b->w * a->z) + (a->x * b->y - a->y * b->x);
    return o;
}

extern void* D_0034a5b0[];
extern void* D_00347e80[];
void func_002361a0(void*);
void func_0031bd98(u8* p) {
    *(u32*)p = (u32)D_0034a5b0;
    *(u32*)(p + 48) = (u32)D_00347e80;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 60) = 0;
    func_002361a0(p + 80);
    u8* e = p + 496;
    for (s32 i = 9; i != -1; i--) {
        *(u32*)(e + 12) = 0;
        *(void**)e = D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
    e = p + 4576;
    for (s32 i = 3; i != -1; i--) {
        *(u32*)(e + 12) = 0;
        *(void**)e = D_00347e60;
        func_00239700(e + 24);
        e += 408;
    }
    func_00239700(p + 6208);
    *(u32*)(p + 6552) = 0;
}

// Destructor: virtual-destroy two 4-element member arrays, then members and base.
struct E344 { VFn* vt; u8 pad[340]; };
extern void* D_00350ab0[];
extern void* D_00350bb0[];
extern void* D_0034e8a8[];
void func_00239870(void*);
void func_00239848(void*);
void func_001ac5b8(void*);
void func_0031fc78(u8* p) {
    NoTail nt;
    *(void**)p = D_00350ab0;
    if (p + 3280 != 0) {
        E344* q = (E344*)(p + 4656);
        E344* b = (E344*)(p + 3280);
        while (1) {
            if (b == q) break;
            --q;
            q->vt[0](q);
        }
    }
    func_00239870(p + 2936);
    *(void**)p = D_00350bb0;
    if (p + 1544 != 0) {
        E344* q = (E344*)(p + 2920);
        E344* b = (E344*)(p + 1544);
        while (1) {
            if (b == q) break;
            --q;
            q->vt[0](q);
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(void**)(p + 132) = D_0034e8a8;
    func_00239848(p + 132);
    func_001ac5b8(p);
}

// Adds each id from the list that is not present yet and passes the mask.
u16 func_002642a8(u16);
struct Lst { u8 _0[10]; u16 cnt; u8 _12[4]; u16 ids[1]; };
void func_002641c8(Lst* p, u16* list, s32 n, u16 mask) {
    for (s32 i = 0; i < n; i++) {
        u16 id = list[i];
        s32 j;
        for (j = 0; j < p->cnt; j++) {
            if (id == ((u16*)((u8*)p + 16))[j]) break;
        }
        if (j < p->cnt) continue;
        if (mask & func_002642a8(id)) {
            p->ids[p->cnt] = id;
            p->cnt++;
        }
    }
}

struct E12 { u32 a; s8 k; u8 pad[7]; };
u8* func_00294000(s32);
s32 func_00294480(void*);
s32 func_002ae1b0(s32 a, s32 b) {
    s32 found = 0;
    s32 r = 1;
    b = (a == 0) ? b : 16;
    u8* t = func_00294000(5);
    E12* e = (E12*)(t + 16);
    for (s32 i = 0; i < *(s32*)(t + 8); i++) {
        if (e[i].k != b) {
            if (found) break;
        } else {
            if (!found) found = 1;
            if (!func_00294480(&e[i])) {
                r = 0;
                break;
            }
        }
    }
    return r;
}

union GP { struct E16* p; u32 u; s16 h; };
union GS { s16 v; u32 u; };
struct E16 { u32 a, b, c, d; };
extern s16* D_0035f4dc;
extern s32 D_0035f4bc;
extern s16 D_0035f4e0;
extern GS D_0035f4d8;
extern u8 D_0035f4e2;
extern GP D_0035f4d4;
void func_002fde18(void*, s32, u32);
void func_00292998(void) {
    D_0035f4e0 = 0;
    func_002fde18(D_0035f4dc, 0, D_0035f4bc * 4);
    s16 k = D_0035f4dc[D_0035f4e0 * 2 + 1];
    D_0035f4d8.v = k;
    if (D_0035f4e2) {
        D_0035f4d4.p[D_0035f4d8.v].a = 0;
        D_0035f4d4.p[D_0035f4d8.v].b = 0;
        D_0035f4d4.p[D_0035f4d8.v].d = 0;
        D_0035f4d4.p[D_0035f4d8.v].c = 0;
    }
}

s32 func_0019ba60(u32);
extern s32 D_0032dfc8;
s32 func_001a2108(u8* a, s32 v, u8* b) {
    if (v > 0 && func_0019ba60(*(u32*)(a + 604))) {
        s32 m1, m2;
        switch (D_0032dfc8) {
        case 0: m1 = 50; m2 = 150; break;
        case 2: m1 = 200; m2 = 100; break;
        case 3: m1 = 200; m2 = 125; break;
        default: return v;
        }
        if (*(u32*)(*(u8**)(a + 604) + 1416) & 4) {
            v = (v * m1 + 99) / 100;
        } else if (func_0019ba60((u32)b) && (*(u32*)(b + 1416) & 4)) {
            v = (v * m2 + 99) / 100;
        }
    }
    return v;
}

// Tracks a position: keeps the previous one and flags a jump longer than twice the limit.
struct Trk { u32 _0; u32 flags; u8 _8[216]; Vq cur; Vq prev; };
extern f32 D_00349e10;
void func_001a48c0(Trk* t, Vq* v) {
    u32 f = t->flags & 1;
    if (f) {
        t->prev = t->cur;
        Vq d;
        d = VSub(*v, t->cur);
        f32 len = VLength(d);
        if (D_00349e10 * 2.0f < len) t->flags |= 4;
        else t->flags &= ~4;
    } else {
        t->prev = *v;
    }
    t->cur = *v;
    t->flags = (t->flags | 1) & ~0x20;
}

struct Mv { Vq v; u8 _16[8]; u32 flags; };
s32 func_001860b0(u8*, Mv*);
void func_0016aef0(u8*, Vq*);
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, s32, f32, f32);
void func_00186a90(u8*, Mv*, f32);
void func_00186988(u8* p, Mv* m, f32 f) {
    Vq t;
    s32 k;
    if (func_001860b0(p, m)) {
        k = 23;
        t = VScale(m->v, -1.0f);
    } else {
        k = 24;
        t = m->v;
    }
    func_0016aef0(p, &t);
    func_0017f488(p + 320, k, 0.0f, 0.0f);
    func_0017f5e0(p + 320, 0, 0, 0.0f, 0.0f);
    func_00186a90(p, m, f);
    m->flags |= 1;
}

s32 func_002e9a38(u8*, u32, s32);
u8* func_0016bba8(u32, s32, u8*);
void func_002e9b10(u8*);
void wt3_2e9b58(u32, u32, u32) asm("_Z16wtarget_002e9b58jjjj");
extern u32 D_0035f620;
extern u32 D_0035f62c;
extern u32 D_0035f628;
void func_002acda8(void);
void func_002acf48(void);
void func_002ae280(u32*, u32*);
void func_002aceb0(void);
u64 func_00312db8(u64, u64);
void func_001ddd10(void*);
void func_001ddd88(void*);

// Lazily records the owner, copies the name and sets the size limit.
struct G3 { void* a; s32 b, c; };
extern G3 D_0035db50;
extern u32 D_0035db18;
extern char D_01dad918[];
void func_002ff2e8(char*, const char*);
void func_00224cf0(u32);
void func_00227130(u8* p) {
    if (D_0035db50.a == 0) goto init;
cont:
    for (s32 i = 0; i < 32; i++) D_01dad918[i] = 0;
    func_002ff2e8(D_01dad918, (char*)p + 10);
    func_002ff3fc(D_01dad918);
    {
        u32 x = *(u32*)(p + 4);
        D_0035db18 = x;
        if (x) {
            s32 y = x + 0x40000;
            if (0x400000 < y) y = 0x400000;
            D_0035db18 = y;
            func_00224cf0(x);
        }
    }
    return;
init:
    D_0035db50.a = p;
    D_0035db50.b = 0;
    D_0035db50.c = 0;
    goto cont;
}

// Converts a degree rotation (y offset by 180) to radians and applies it.
void func_0016b070(void*, f32*);
void func_0016aeb8(void*, f32);
s32 func_002283b0(void*, f32*);
static inline void DegToRad(u8* p, f32* v) {
    v[0] = v[0] * 0.0174532924f;
    v[1] = (v[1] + 180.0f) * 0.0174532924f;
    v[2] = -(v[2] * 0.0174532924f);
    func_0016b070(p, v);
}
void func_0022f6b8(u8* p, f32* v) {
    if (*(u32*)(p + 1416) & 0x800000) {
        DegToRad(p, v);
        return;
    }
    if ((v[0] == 0.0f && v[2] == 0.0f) || !func_002283b0(p, v)) {
        func_0016aeb8(p, v[1] * 0.0174532924f);
        return;
    }
    DegToRad(p, v);
}

typedef unsigned int u128 __attribute__((mode(TI)));
union PQ { u8* p; u128 q; };
extern PQ D_01d9e6e8u asm("D_01d9e6e8");
extern u8 D_01d9e940[];
void func_00200a78(u8* a, u32, u8* c) {
    f32 m[16] __attribute__((aligned(16)));
    u8* s = a + *(u32*)(*(u8**)(c + 12) + 4);
    func_002f4000(m);
    f32* v = (f32*)(s + 160);
    m[12] = v[0];
    m[13] = v[1];
    m[14] = v[2];
    func_002f3d08(m, D_01d9e730, m);
    func_002f3d08(m, D_01d9e8c0, m);
    func_002f3f40(D_01d9e6e8u.p + 80, D_01d9e6e8u.p + 16, v[4]);
    func_002f3f40(D_01d9e6e8u.p + 96, D_01d9e6e8u.p + 32, v[5]);
    func_002f3f40(D_01d9e6e8u.p + 112, D_01d9e6e8u.p + 48, v[6]);
    *(u128*)(D_01d9e6e8u.p + 128) = *(u128*)(D_01d9e6e8u.p + 64);
    func_002f3d08(D_01d9e6e8u.p + 80, D_01d9e940, D_01d9e6e8u.p + 80);
    func_002f3cd8(D_01d9e6e8u.p + 128, m, D_01d9e6e8u.p + 64);
}

// Linear interpolation over a table of 96-byte keys (40 steps).
struct K96 { f32 x; u8 _4[16]; f32 v; u8 _24[72]; };
static inline K96* KeyAt(K96* k, s32 i) {
    K96* r = k + i;
    return r;
}
f32 func_002e51b0(K96* k, f32 t) {
    f32 r = 0.0f;
    f32 x = k->x;
    t += x * 0.5f;
    t /= x;
    if (t < 0.0f || 1.0f < t) return r;
    f32 s = t * 40.0f;
    s32 i = (s32)s;
    s32 j = i + 1;
    t = s - (f32)i;
    if (t < 9.99999975e-05f) return KeyAt(k, i)->v;
    return KeyAt(k, i)->v * (1.0f - t) + KeyAt(k, j)->v * t;
}

u8* func_00257770(void);
u32 func_00257140(s32);
u32 func_00192048(u16);
s32 func_00257070(s32);
extern u16 D_00373a88[];
void func_00272938(void) {
    s32 i;
    u16* t;
    u8* s;
    u8* b = func_00257770();
    s = b + 24740;
    for (i = 0; i < 2; i++) {
        func_00138c10(s, func_00257140(0));
        *(u32*)(s + 408) = func_00192048(D_00373a88[i]);
        s += 436;
    }
    if (func_00257070(25)) {
        s = b + 25612;
        for (i = 0; i < 2; i++) {
            func_00138c10(s, func_00257140(0));
            *(u32*)(s + 408) = func_00192048(D_00373a88[i]);
            s += 436;
        }
    }
}


W84Ev* func_001db440(u16* p) {
    switch (*p) {
    case 0: return new W84Ev0(p);
    case 1: return new W84Ev1(p);
    case 2: return new W84Ev2(p);
    }
    return 0;
}

}

// Recursively registers o (or all its children when k < 0).
void wtarget_002e9b58(u32 a0, u32 o, u32 k, u32) {
    u8* p = (u8*)a0;
    if (!o) return;
    if (!func_0019ba60(o)) return;
    if ((s32)k < 0) {
        u8* r = 0;
        while ((r = func_0016bba8(o, 3, r)) != 0) wt3_2e9b58(a0, o, *r);
        return;
    }
    if (func_002e9a38(p, o, k)) return;
    *(u32*)(p + p[4] * 8 + 28) = o;
    *(u32*)(p + p[4] * 8 + 32) = k;
    if (*(s32*)(p + 8) < *(s32*)p) *(s32*)(p + 8) += 1;
    func_002e9b10(p);
}

// Accumulates two counters and returns their ratio as a percentage.
s32 wtarget_002ad018(u32, u32, u32, u32) {
    if (D_0035f620 == 0) func_002acda8();
    func_002acf48();
    u32 a, b;
    b = 0;
    a = 0;
    func_002ae280(&a, &b);
    D_0035f62c += a;
    D_0035f628 += b;
    func_002aceb0();
    return (s32)((f32)D_0035f62c / (f32)D_0035f628 * 100.0f);
}

// Clears 5 slots and marks one at random (avoiding slot n when n >= 0).
extern u32 D_003638d0;
static inline u32 Rand() { return D_003638d0 = D_003638d0 * 69069; }
void wtarget_001d9a18(u32 a0, u32 a1, u32, u32) {
    u8* p = (u8*)a0;
    s32 n = a1;
    for (s32 i = 0; i < 5; i++) p[i] = 0;
    s32 r;
    if (n < 0) {
        r = func_00312db8(Rand(), 0x33333334);
    } else {
        r = (s32)((s64)((u64)Rand() << 2) >> 32);
        if (!(r < n)) r++;
    }
    p[r] = 2;
}

extern u8 D_01c6cae0[];
extern u32 D_01c6cb00[];
void wtarget_001a3d70(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) func_001ddd10(D_01c6cae0);
    if (a1 == 0xffff && a0 == 1) {
        u32* base = D_01c6cb00;
        u32* q = base;
        for (s32 i = 3; i >= 0; i--) *q++ = 0;
        base[4] = 0;
    }
    if (a1 == 0xffff && a0 == 0) func_001ddd88(D_01c6cae0);
}

