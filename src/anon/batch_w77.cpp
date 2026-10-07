#include "../common/types.h"

// ---- 00124a40
namespace n00124a40 {
struct VObj;
typedef u8* (*GetFn)(VObj*);
typedef s32 (*CountFn)(VObj*);
struct VObj { void** vt; };
extern "C" {
void func_00124848(u8*, s32, u32);
void func_00124a40(u8* p)
{
    if (p[25]) return;
    VObj* o = *(VObj**)(p + 20);
    u8* arr = ((GetFn)o->vt[8])(o);
    s32 i = 0;
    o = *(VObj**)(p + 20);
    s32 n = ((CountFn)o->vt[7])(o);
    for (; i < n; i++) {
        if (!(*(u64*)(arr + i * 64 + 8) & (1ULL << 32)))
            func_00124848(p, i, *(u32*)(p + 4) + i * 64);
    }
    p[25] = 1;
}
}
}

// ---- 00135ad0
namespace n00135ad0 {
extern "C" {
s32 func_0019ba60(u32);
struct List { u8 pad[12]; s32 count; u32 items[32]; };

void func_00135ad0(List* l)
{
    u32 tmp[32];
    s32 n = 0;
    s32 i;
    for (i = 0; i < l->count; i++) {
        if (l->items[i] && func_0019ba60(l->items[i]))
            tmp[n++] = l->items[i];
    }
    for (i = 0; i < n; i++) l->items[i] = tmp[i];
    for (; i < 32; i++) l->items[i] = 0;
    l->count = n;
}
}
}

// ---- 00140e30
namespace n00140e30 {
extern "C" {
void wtarget_00140e30(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00140e30jjjj");
extern f32 D_004573f8[];
void func_0013f5f0(u8*);
void func_0013f608(u8*);
void func_0013fd78(u8*);
static inline f32 Get(s32 i)
{
    return D_004573f8[i];
}
void wtarget_00140e30(u32 a, u32 b, u32 c, u32 d)
{
    u8* p = (u8*)a;
    s32 i = b * 6;
    *(f32*)(p + 220) = Get(i);
    *(f32*)(p + 224) = 0.0f;
    func_0013f5f0(p);
    func_0013f608(p);
    *(f32*)(p + 200) = Get(i + 1);
    *(f32*)(p + 204) = Get(i + 2);
    *(f32*)(p + 208) = Get(i + 3);
    *(f32*)(p + 212) = Get(i + 4);
    *(f32*)(p + 216) = Get(i + 5);
    func_0013fd78(p);
}
}
}

// ---- 00149de0
namespace n00149de0 {
extern "C" {
extern u8 D_0032bae0;
s32 func_00242ea8(void);
s32 func_001051a0(u8*, u8*);
void func_001703a8(s32);
void func_002bea00(void);
void func_002bea10(void);
void func_00149de0(u8* p)
{
    if (func_00242ea8()) return;
    if (!func_001051a0(&D_0032bae0, p)) func_001703a8(1070);
    if (*p != D_0032bae0) {
        func_001703a8(900);
        func_001703a8(950);
        func_001703a8(1080);
        func_001703a8(1090);
    }
    func_002bea00();
    if (D_0032bae0 != 15) return;
    if (*p != D_0032bae0) {
        func_001703a8(1040);
        func_001703a8(1040);
        func_001703a8(2500);
    } else {
        func_002bea10();
    }
}
}
}

// ---- 00151c70
namespace n00151c70 {
extern "C" {
struct VObj { void** vt; };
typedef void (*VFn)(void*);
struct Elem { void** vt; u8 pad[392]; u32 f396; u32 f400; u8 pad2[4]; };
struct Own { void** vt; u8 pad[44]; u8 sub[792]; Elem e[5]; };
s32 func_00139d78(void*);
void func_00139510(void*);
void func_001396b0(void*);
void func_0031a260(void*, s32);
void func_00151c70(Own* p)
{
    if (func_00139d78(p)) ((VFn)p->vt[5])(p);
    if (func_00139d78(p->sub)) func_00139510(p->sub);
    Elem* e = p->e;
    for (s32 i = 0; i < 5; i++, e++) {
        if (func_00139d78(e)) {
            p->e[i].f396 = 0;
            func_001396b0(e);
            if (p->e[i].f396) {
                p->e[i].f400 = 0;
                func_001396b0(e);
                if (p->e[i].f400) func_0031a260(e, 0);
            }
            ((VFn)p->e[i].vt[5])(e);
        }
    }
}
}
}

// ---- 00155568
namespace n00155568 {
extern "C" {
u8* func_0013d7f0(void);
s32 func_0013dda0(s32);
void func_00138c10(u8*, s32);
u32 func_00154ee8(u8*);
u32 func_0023aa98(u8*);
void func_00138c40(u8*, s32, u32);
void func_00155568(u8* p)
{
    if (!p[32]) return;
    s32 s = *(s32*)(p + 48);
    if (s != 1) return;
    u8* g = func_0013d7f0();
    if (!g[5536]) return;
    g[5536] = 0;
    if (!func_0013dda0(1)) {
        if (p[5537]) return;
        u8* q = p + 916;
        func_00138c10(q, 73);
        *(u32*)(q + 392) = func_00154ee8(p);
        func_0023aa98(p + 940);
        func_00138c40(q, 0, 0);
        p[5537] = s;
    } else {
        if (p[5537] != s) return;
        u8* q = p + 916;
        func_00138c10(q, 74);
        *(u32*)(q + 392) = func_00154ee8(p);
        func_00138c40(q, 0, func_0023aa98(p + 940));
        p[5537] = 0;
    }
}
}
}

// ---- 001559e8
namespace n001559e8 {
extern "C" {
void func_00139598(u8*);
void func_001395a8(u8*);
s32 func_00155830(u32, f32*, f32*, f32*);
void func_00239f18(u8*, f32);
void func_00138d30(u8*, f32);
void func_00138c68(u8*, s32, s32);
void func_001559e8(u8* p, u32 a, s32 idx)
{
    u8* e = p + idx * 412;
    f32 x, y, z;
    func_00139598(e + 6704);
    if (func_00155830(a, &x, &y, &z)) return;
    func_00239f18(e + 6728, x);
    func_001395a8(e + 6704);
    if (idx == 4) {
        func_00138d30(p + 9588, z);
        func_00138c68(p + 9588, (s32)-y, 0);
    }
}
}
}

// ---- 0016cab8
namespace n0016cab8 {
extern "C" {
struct VObj { void** vt; };
typedef void (*RelFn)(VObj*, u32);
struct Node { u8 pad[20]; u32 h20; u32 h24; u8 pad28[8]; u32 f36; Node* next; Node* child; u8 pad48[4]; u32 f52; };
extern VObj* D_004f6288;
extern u8 D_0034dbf8;
void func_001da458(Node*, u32, s32, s32);
void func_001da558(Node*, void*, s32, s32);
void func_0016c7d8(Node*);
void func_0016d1f0(u32);
void func_0016ce90(Node*);
void func_0016cab8(Node* p);
static inline void Kill(Node* c)
{
    if (c) {
        func_0016cab8(c);
        func_0016c7d8(c);
    }
}
void func_0016cab8(Node* p)
{
    if (p->f36) {
        func_001da458(p, p->f36, 0, 0);
        func_001da558(p, &D_0034dbf8, 0, 0);
    }
    Node* c = p->child;
    while (c) {
        Node* n = c->next;
        Kill(c);
        c = n;
    }
    ((RelFn)D_004f6288->vt[1])(D_004f6288, p->h20);
    ((RelFn)D_004f6288->vt[1])(D_004f6288, p->h24);
    if (p->f52) func_0016d1f0(p->f52);
    func_0016ce90(p);
}
}
}

// ---- 0017e720
namespace n0017e720 {
extern "C" {
extern f32 D_0034ebb8;
extern f32 D_00349e10;
extern u8* D_00352130;
u32 func_001a8bd0(s32);
u32 func_001a8c10(u32, s32);
s32 func_0017e668(u32);
u8* func_001a1658(u32, s32);
void func_001a1950(u8*, s32, s32, s32);
void func_001a17c8(u8*);
void func_0017e720(void)
{
    if ((D_0034ebb8 -= D_00349e10) <= 0.0f) {
        u32 h = func_001a8bd0(-1);
        for (s32 i = 1; i < 4; i++) {
            u32 o = func_001a8c10(h, i);
            if (o && !func_0017e668(o)) {
                u8* q = func_001a1658(o, -1);
                if (*(u32*)(q + 476) & 0x10) func_001a1950(q, 1, 0, 0);
                func_001a17c8(q);
            }
        }
        D_0034ebb8 = *(f32*)(D_00352130 + 360);
    }
}
}
}

// ---- 0017f178
namespace n0017f178 {
extern "C" {
struct Nd { u32 h; u32 f4; u32 f8; u8 p12[12]; u32 f24; u8 p28[120]; Nd* child; u8 p152[4]; Nd* next; u8 p160[80]; u32 f240; u8 p244[8]; u32 f252; u32 f256; };
s32 func_001a9798(u32);
u32 func_0017edf0(Nd*, u32);
s32 func_0017efa0(Nd*, u32, f32, f32);
u32 func_0017eda8(Nd*, u32);
void func_00180800(Nd*, u32);
s32 func_0017f178(Nd* p, u32 a, f32 x, f32 y);
static inline Nd* Next(Nd* p, Nd* c)
{
    if (!c) return p->child;
    return c->next;
}
s32 func_0017f178(Nd* p, u32 a, f32 x, f32 y)
{
    if (func_001a9798(p->h)) x = 0.0f;
    p->f252 = 0;
    p->f256 = 0;
    p->f240 = p->f8 + 128;
    if (!func_0017efa0(p, func_0017edf0(p, a), x, y)) return 0;
    p->f24 = a;
    func_00180800(p, func_0017eda8(p, a));
    Nd* c = 0;
    while ((c = Next(p, c))) func_0017f178(c, a, x, y);
    return 1;
}
}
}

// ---- 00186a90
namespace n00186a90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Scale(const QWord& a, f32 k)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Ent { u8 pad[1164]; u8* tgt; u8 pad2[2768 - 1168]; QWord dir; f32 f2784; };
extern "C" {
void ctarget_00186a90(Ent* p, QWord* v, f32 k) asm("_Z16ctarget_00186a90jjjj");
s32 func_0019c838(Ent*);
void ctarget_00186a90(Ent* p, QWord* v, f32 k)
{
    if (!func_0019c838(p)) return;
    if (k < 0.0f) {
        k = -k;
        p->dir = Scale(*v, -1.0f);
    } else {
        p->dir = *v;
    }
    if (p->tgt) k += *(f32*)(p->tgt + 456);
    Normalize(&p->dir);
    *(f32*)((u8*)p + 2780) = k * 0.1f;
}
}
}

// ---- 0018ba28
namespace n0018ba28 {
extern "C" {
void func_0018c438(u8*);
void func_0018bfa0(u8*, u8*, f32);
void func_0018ba28(u8* a, u8* b)
{
    u8* hi = a;
    u8* lo = b;
    if (!(*(f32*)(a + 28) > *(f32*)(b + 28))) {
        hi = b;
        lo = a;
    }
    f32 k = 120.0f;
    func_0018c438(hi + 2624);
    *(f32*)(hi + 2704) = k;
    hi[2673] = 1;
    *(u32*)(hi + 2628) = 1;
    *(u8**)(hi + 2636) = lo;
    hi[2660] = 0;
    *(u32*)(hi + 2624) = 3;
    func_0018bfa0(hi, lo, 200.0f);
    func_0018c438(lo + 2624);
    *(f32*)(lo + 2704) = k;
    lo[2673] = 1;
    *(u32*)(lo + 2624) = 7;
}
}
}

// ---- 0019aec0
namespace n0019aec0 {
extern "C" {
extern u8 D_0034f250;
s32 func_0019ac30(void*, u16);
void func_001956e8(void*, u16);
struct Rec { u8 pad[30]; u16 id; u8 pad2[16]; u8 lv; u8 pad3[15]; };
struct Def { u8 pad[72]; u8 kind; u8 pad2[63]; };
struct Tbl { u8 pad[4]; u16 count; u8 pad2[2]; Def d[1]; };
struct Own { u8 pad[8]; Tbl* tbl; u8 pad2[20]; u8 lv; u8 pad3[3]; Rec* recs; };
void func_0019aec0(Own* p, s32 lv)
{
    for (s32 i = 0; i < p->tbl->count; i++) {
        if (*((u8*)p->tbl + i * 64 + 72) != 2) continue;
        if (p->recs[i].lv < lv) continue;
        if (func_0019ac30(p, p->recs[i].id))
            func_001956e8(&D_0034f250, p->recs[i].id);
    }
    p->lv = lv;
}
}
}

// ---- 001a5c88
namespace n001a5c88 {
extern "C" void func_0016cab8(void*);
struct Node {
    ~Node() { func_0016cab8(this); }
    static void operator delete(void*) asm("func_0016c7d8");
};
extern "C" {
struct Obj { Node* node; u8 pad[4]; f32 f8; Obj* next; };
struct List { Obj* head; Obj* tail; };
extern List D_01c6cb20;
void func_001826c8(f32);
void func_001a5c88(Obj* o)
{
    if (o->f8 > 0.0f) func_001826c8(-o->f8);
    delete o->node;
    Obj* prev;
    if (o == D_01c6cb20.head) {
        D_01c6cb20.head = o->next;
        prev = 0;
    } else {
        prev = D_01c6cb20.head;
        while (prev->next != o) prev = prev->next;
        prev->next = o->next;
    }
    if (o == D_01c6cb20.tail) D_01c6cb20.tail = prev;
    o->next = 0;
}
}
}

// ---- 001b0250
namespace n001b0250 {
extern "C" {
struct Obj;
typedef u32 (*MkFn)(Obj*, s32, u32);
struct Obj { void** vt; u32 f4; s32 id; u32 f12; u32 h16; u32 f20; u32 h24; };
void func_001b0330(Obj*);
s32 func_001b0320(Obj*);
u32 func_0016c028(u32);
s32 func_002bc420(u32);
s32 func_0019ba60(u32);
void func_002bc398(u32, u32);
void func_001b0250(Obj* o)
{
    s32 id = o->id;
    if (id >= 0) {
        func_001b0330(o);
        o->h16 = ((MkFn)o->vt[2])(o, id, func_0016c028(o->h24));
        return;
    }
    if (!func_001b0320(o)) return;
    if (func_002bc420(o->h16)) {
        if (o->h24 && func_0019ba60(o->h24)) {
            func_002bc398(o->h16, func_0016c028(o->h24));
            return;
        }
        o->h24 = 0;
    } else {
        o->h16 = 0;
        o->h24 = 0;
    }
}
}
}

// ---- 001b2618
namespace n001b2618 {
extern "C" {
struct Pt { f32 x, y, z; };
struct Src { u16 f0; u16 n; u8 pad[4]; Pt p[1]; };
Src* func_00182e08(void);
u8* func_001050d8(s32);
void func_001b2380(u8*, u16);
void func_001b2520(u8*, f32*);
u8* func_001b2618(void)
{
    s32 i = 0;
    Src* s = func_00182e08();
    u8* o = func_001050d8(28);
    func_001b2380(o, s->n);
    for (; i < s->n; i++) {
        f32 v[4];
        v[0] = s->p[i].x;
        v[1] = s->p[i].y;
        v[2] = s->p[i].z;
        v[3] = 1.0f;
        func_001b2520(o, v);
    }
    return o;
}
}
}

// ---- 001bec68
namespace n001bec68 {
extern "C" {
void func_001bc778(u8*);
u8* func_00176b20(s32);
s32 func_0019ba60(u8*);
u32 func_0016a070(u8*);
u32 func_001b77e8(u32);
void func_001bc780(u8*, u32, s32, s32);
void func_001bec68(u8* p)
{
    u8* q = p + 500;
    func_001bc778(q);
    for (s32 i = 0; i < 3; i++) {
        u8* e = func_00176b20(i);
        if (!func_0019ba60(e)) continue;
        if (*(u32*)(e + 1416) & 0x400000) continue;
        if (!*(u32*)(e + 1164)) continue;
        *(u8**)(p + *(s32*)(q + 8) * 4 + 2652) = e;
        func_001bc780(q, func_001b77e8(func_0016a070(e)), 0, 1);
    }
}
}
}

// ---- 001c1fe0
namespace n001c1fe0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Scale(const QWord& a, f32 k)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline void ScaleIn(QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "f"(k) : "$8", "memory");
}
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct VObj { void** vt; };
typedef QWord (*PosFn)(VObj*);
extern "C" {
QWord func_0016be98(u8*);
void func_0016aef0(u8*, QWord*);
void func_001c1fe0(u8* p)
{
    QWord n;
    VObj* o = *(VObj**)(p + 2732);
    n = Sub(((PosFn)o->vt[2])(o), func_0016be98(p));
    Normalize(&n);
    f32 k = -1.0f;
    if (*(s32*)(p + 2744) == 21) ScaleIn(&n, k);
    func_0016aef0(p, &n);
}
}
}

// ---- 001d4ae0
namespace n001d4ae0 {
extern "C" {
extern char D_0036e4a0[];
extern char D_0036e4b0[];
extern char D_0036e4c0[];
void func_00190878(u8*, u32, s32);
void func_001bce90(u32, const char*, s32, u8*);
s32 func_001d4ae0(u8* a, u8* b, u32 c)
{
    if (!(*(u32*)(b + 352) & 0x4000) || !*(s32*)(b + 2928)) return 0;
    func_00190878(a + 12, *(u32*)(a + 4), 0);
    switch (*(s32*)(b + 2928)) {
    case 1: func_001bce90(c, D_0036e4a0, 3, a + 12); break;
    case 2: func_001bce90(c, D_0036e4b0, 3, a + 12); break;
    case 3: func_001bce90(c, D_0036e4c0, 3, a + 12); break;
    }
    return 1;
}
}
}

// ---- 001fbb98
namespace n001fbb98 {
extern "C" {
extern u8* D_01d9e6e0;
extern u8 D_00354be0;
void func_002f3f88(u8*, void*);
void func_001fbab8(u8*, s32, s32);
void func_001fbb98(u8* a, u8* col, u8* c)
{
    u8* d = a + **(u32**)(c + 12);
    u8* s = d + 160;
    s[36] = (s32)(col[8] * *(f32*)(D_01d9e6e0 + 48));
    s[37] = (s32)(col[9] * *(f32*)(D_01d9e6e0 + 52));
    s[38] = (s32)(col[10] * *(f32*)(D_01d9e6e0 + 56));
    s[39] = (s32)(col[11] * *(f32*)(D_01d9e6e0 + 60));
    func_002f3f88(d + 176, &D_00354be0);
    func_001fbab8(s, 0, 0);
}
}
}

// ---- 00201bb0
namespace n00201bb0 {
extern "C" {
extern u8* D_01d9e6e8;
extern u8 D_01d9e6f0;
void func_002f3cd8(f32*, void*, f32*);
void func_00201bb0(u8* p, f32* v1, f32* v2)
{
    f32 t[4];
    f32 a = *(f32*)(p + 16);
    f32 k = 0.5f;
    t[0] = 0;
    t[1] = a * k;
    t[2] = 0;
    t[3] = 1.0f;
    func_002f3cd8(v1, D_01d9e6e8 + 16, t);
    t[1] = -a * k;
    func_002f3cd8(v2, D_01d9e6e8 + 16, t);
    if (p[21]) {
        func_002f3cd8(v1, &D_01d9e6f0, v1);
        func_002f3cd8(v2, &D_01d9e6f0, v2);
    }
}
}
}

// ---- 00202c20
namespace n00202c20 {
extern "C" {
void func_00202c20(u8* p, s32* x, s32* w, s32* y, s32* h)
{
    s32 x0 = 0;
    s32 ww = 4096;
    s32 hh = 4096;
    switch (p[16]) {
    case 1: ww = 2048; break;
    case 2: ww = 1024; break;
    }
    switch (p[17]) {
    case 1: hh = 2048; break;
    case 2: hh = 1024; break;
    }
    switch (p[18]) {
    case 1: x0 = 1024; ww += 1024; break;
    case 2: x0 = 2048; ww += 2048; break;
    case 3: x0 = 3072; ww += 3072; break;
    }
    *x = x0 + 16;
    *w = ww - 16;
    *y = 16;
    *h = hh - 16;
}
}
}

// ---- 00226978
namespace n00226978 {
extern "C" {
extern u8 D_0035de14;
extern u8 D_0035de15;
extern u32 D_0035de80;
extern u32 D_0035de84;
extern u32 D_0035de88;
extern u8 D_0035de0c;
extern u32 D_0035db10;
extern u32 D_0035db14;
extern u32 D_0035db18;
extern u32 D_0035de30;
extern u32 D_0035de34;
extern u32 D_0035de38;
extern u32 D_0035de3c;
struct St { u32 a, b, c, d, e, f; f32 g; u32 h, i, j; };
extern St D_0035db20;
extern u8 D_0035de44;
extern f32 D_0035de48;
extern u32 D_0035de40;
void func_00227108(s32);
void func_00226968(void);
void func_00226ee8(s32);
void func_00226f90(void);
void func_00226fa8(void);
void func_00226fc8(void);
void func_00226978(void)
{
    func_00227108(0);
    func_00226968();
    D_0035de14 = 0;
    D_0035de15 = 0;
    D_0035de80 = 0;
    D_0035de84 = 0;
    D_0035de88 = 0;
    D_0035de0c = 0;
    D_0035db10 = 0;
    D_0035db14 = 0;
    D_0035db18 = 0;
    D_0035de30 = 0;
    D_0035de34 = 0;
    D_0035de38 = 0;
    D_0035de3c = 0;
    func_00226ee8(0);
    D_0035db20.a = 0;
    D_0035db20.b = 0;
    D_0035db20.c = 0;
    D_0035db20.d = 0;
    D_0035db20.e = 0;
    D_0035db20.f = 0;
    D_0035db20.g = 1.0f;
    D_0035db20.h = 0;
    D_0035db20.i = 0;
    D_0035db20.j = 0;
    D_0035de40 = 0;
    D_0035de44 = 0;
    D_0035de48 = 1.0f;
    func_00226f90();
    func_00226fa8();
    func_00226fc8();
}
}
}

// ---- 00227b00
namespace n00227b00 {
extern "C" {
struct Ent { u32 type; s32 state; u8 pad[24]; char name[16]; char sub[16]; u8 pad2[20]; };
extern Ent* D_0035dcf0;
s32 func_002ff1a4(const char*, const char*);
Ent* func_00227b00(const char* name, u32 type, const char* sub)
{
    for (s32 i = 0; i < 128; i++) {
        if (D_0035dcf0[i].type != type) continue;
        if (D_0035dcf0[i].state != 3) continue;
        if (func_002ff1a4(D_0035dcf0[i].name, name)) continue;
        if (func_002ff1a4(D_0035dcf0[i].sub, sub)) continue;
        return &D_0035dcf0[i];
    }
    return 0;
}
}
}

// ---- 0024d6c8
namespace n0024d6c8 {
extern "C" {
extern u32 D_0035edcc;
extern u32 D_0035edd0;
extern u32 D_0035edd4;
extern u32 D_0035edd8;
extern u32 D_0035eddc;
s32 func_00287bc0(void);
void func_00287d68(void);
s32 func_00287db0(void);
s32 func_0028acc8(u32);
s32 func_00139d78(u32);
void func_001039f8(void);
void func_0024d910(void);
void func_0024d7a0(void);
s32 func_0024d6c8(void)
{
    s32 st = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (func_0028acc8(D_0035edcc) || func_0028acc8(D_0035edd0) || func_00139d78(D_0035edd4) || func_00139d78(D_0035edd8) || func_00139d78(D_0035eddc)) return 0;
        func_001039f8();
        return 1;
    }
    switch (st) {
    case 0: func_0024d7a0(); break;
    case 1: func_0024d910(); break;
    }
    return 0;
}
}
}

// ---- 0028b520
namespace n0028b520 {
extern "C" {
void func_0028d980(u8*, u32, u32, u32, u32, u32, s32, u32, s32);
void func_0028b6f0(u8*, u32);
void func_0028b720(u8*, u32);
u8* func_0023f1b0(u32);
u32 func_0023c3e0(u8*, s32, s32);
void func_0028dd28(u8*, u32);
void func_0028b520(u8* p, u32 a, u32 b, u32 c, u32 id, u32 x, u32 y, u32 z, u32 w)
{
    *(u32*)(p + 436) = id;
    func_0028d980(p, a, b, c, id, z, -1, w, 0);
    func_0028b6f0(p, x);
    func_0028b720(p, y);
    s32 v = *(s32*)(func_0023f1b0(*(u32*)(p + 436)) + 76);
    for (s32 i = 0; i < 3; i++) {
        if (v == ((s16*)(p + 444))[i]) {
            func_0028dd28(p, func_0023c3e0(func_0023f1b0(*(u32*)(p + 436)), ((s16*)(p + 450))[i], 0));
            break;
        }
    }
    *(s16*)(p + 456) = v;
}
}
}

// ---- 00293cb8
namespace n00293cb8 {
extern "C" {
extern const char* D_0035f508[];
extern const char* D_0035f500;
extern const char* D_0035f504;
void func_00253b30(char*, const char*);
void func_002feee8(char*, const char*);
void func_00293cb8(char* buf, s32 k, const char* s)
{
    func_00253b30(buf, D_0035f508[k]);
    if (k == 2 && s) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f500);
    } else if (k == 3) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f504);
    } else if (k == 4) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f500);
    } else if (k == 5) {
        func_002feee8(buf, s);
        func_002feee8(buf, D_0035f504);
    }
}
}
}

// ---- 002969e0
namespace n002969e0 {
extern "C" {
extern u32 D_0035f58c;
extern u8 D_0035f590;
void func_0023f900(u32);
s32 func_00292630(void);
s8* func_00276568(void);
s32 func_00287bc0(void);
u32 func_002953c8(s32);
s32 func_002941d8(u32);
u32 func_00296f90(void);
u32 func_00296f80(void);
u32 func_00293db8(s32, u32);
void func_0023fa08(u32, u32);
void func_002969e0(void)
{
    func_0023f900(D_0035f58c);
    if (!func_00292630()) {
        s8 c = *func_00276568();
        u32 v;
        if (func_00287bc0() == 2) {
            if (c == 1 && func_002941d8(func_002953c8(1))) v = func_00296f90();
            else v = func_002953c8(c) + 1;
        } else {
            v = func_00296f80();
        }
        func_0023fa08(D_0035f58c, func_00293db8(2, v));
        D_0035f590 = 1;
    } else {
        D_0035f590 = 0;
    }
}
}
}

// ---- 0029daa0
namespace n0029daa0 {
extern "C" {
extern u8* D_0035f5b0;
extern u32 D_0035f200;
s32 func_00139d78(u8*);
s32 func_0028b040(u32);
s32 func_0028afa8(u32);
void func_00139570(u8*);
void func_00139580(u8*);
void func_0029daa0(void)
{
    if (!func_00139d78(D_0035f5b0 + 6104)) return;
    if (!func_00139d78(D_0035f5b0 + 6512)) return;
    s32 cur = func_0028b040(D_0035f200);
    s32 n = func_0028afa8(D_0035f200);
    if (n < 2) {
        func_00139570(D_0035f5b0 + 6104);
        func_00139570(D_0035f5b0 + 6512);
    } else if (cur == 0) {
        func_00139570(D_0035f5b0 + 6104);
        func_00139580(D_0035f5b0 + 6512);
    } else if (cur >= n - 1) {
        func_00139580(D_0035f5b0 + 6104);
        func_00139570(D_0035f5b0 + 6512);
    } else {
        func_00139580(D_0035f5b0 + 6104);
        func_00139580(D_0035f5b0 + 6512);
    }
}
}
}

// ---- 002aad58
namespace n002aad58 {
extern "C" {
struct Flags { u8 pad[148]; u32 bits[8]; };
extern Flags* D_0035f610;
Flags* func_002a9d68(void);
static inline s32 TestBit(u32* bits, u32 i)
{
    return bits[i >> 5] & (1 << (i & 31));
}
s32 func_002aad58(s32 n)
{
    Flags* a = func_002a9d68();
    s32 r = 1;
    if (n < 0) {
        for (s32 i = 0; i < 192; i++) {
            if (TestBit(D_0035f610->bits, i)) {
                r = TestBit(a->bits, i) != 0;
                if (!r) break;
            }
        }
    } else {
        r = TestBit(D_0035f610->bits, n) && TestBit(a->bits, n);
    }
    return r;
}
}
}

// ---- 002b1af0
namespace n002b1af0 {
extern "C" {
extern u8* D_0035f634;
extern s32 D_0035f3d4;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
extern u8* D_0035f638;
u32 func_002766d0(void);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_0028dcc0(u8*, u32);
u32 func_00192048(s32);
u16* func_002b23e0(s32);
u32 func_001a37e8(u16, s32);
void func_00192e50(u32, u8*, s32, u32);
void func_002b1af0(void)
{
    u32 r = func_002766d0();
    s32 k = D_0035f3d4 + 2;
    u8* o = D_0035f634 + 24212;
    func_0028d980(o, k, D_0035f14c, D_0035f148, D_0035f210, 131, -1, -1, 0);
    func_00139620(o);
    func_0028dcc0(o, r);
    *(u32*)(o + 432) = 2;
    u32 x = func_00192048(20688);
    func_00192e50(x, D_0035f638 + 88, 64, func_001a37e8(*func_002b23e0(-1), -1));
    *(u8**)(o + 408) = D_0035f638 + 88;
}
}
}

// ---- 002bed48
namespace n002bed48 {
extern "C" {
extern u8 D_00361980[];
void func_002edf28(u8*);
u8* func_001050d8(s32);
void func_001ad0f8(u8*, u32, s32);
void func_001ad330(u8*, u32);
void func_002bed48(u8* p, s32 kind, u32 c)
{
    func_002edf28(p);
    *(u32*)(p + 40) = 0;
    *(u32*)p = (u32)D_00361980;
    switch (kind) {
    case 0: {
        u8* o = func_001050d8(2924);
        func_001ad0f8(o, c, 0);
        *(u32*)(p + 36) = (u32)o;
        *(u32*)(o + 100) = 2;
        u8* q = (u8*)*(u32*)(p + 36);
        *(u32*)(q + 4) = 256;
        *(u32*)(q + 8) = 48;
        break;
    }
    case 1: {
        u8* o = func_001050d8(4656);
        func_001ad330(o, c);
        *(u32*)(p + 36) = (u32)o;
        break;
    }
    }
}
}
}

// ---- 002bf098
namespace n002bf098 {
extern "C" {
extern u8 D_00363880[];
extern u8 D_003619a8[];
extern u8* D_00361998;
extern u8 D_002bf308;
u32 func_001050c8(void);
void func_002edf28(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
u32 func_002beb90(void);
u32 func_001708f8(u32, s32);
u8* func_00168b38(u32, s32, s32);
void func_002ef1f8(u8*, u32, u32);
void func_00102c18(s32, s32, void*);
void func_002bf098(u8* p)
{
    u32 m = func_001050c8();
    func_002edf28(p);
    *(u32*)(p + 36) = m;
    *(u32*)p = (u32)D_00363880;
    func_002369a0(p + 40);
    func_0023c008(p + 64);
    *(u8**)p = D_003619a8;
    D_00361998 = p;
    *(u32*)(p + 156) = func_001708f8(func_002beb90(), -1);
    u8* a = func_00168b38(*(u32*)(p + 156), 28, 0);
    u8* b = func_00168b38(*(u32*)(p + 156), 29, 0);
    func_002ef1f8(p, *(u32*)(a + 8), *(u32*)(b + 8));
    *(u32*)(p + 4) |= 1;
    func_00102c18(1, 0x19258, &D_002bf308);
}
}
}

// ---- 002c3280
namespace n002c3280 {
extern "C" void func_00288b00(void*);
struct Obj {
    ~Obj() { func_00288b00(this); }
    static void operator delete(void*) asm("func_00288c20");
};
struct Self;
typedef void (*DelFn)(Self*);
struct Self { void** vt; };
extern "C" {
void func_00170950(u32);
void func_002c5f60(void);
u32 func_002c6218(void);
void func_002c6280(u32, s32);
void func_002c5460(u8*);
void func_00167f38(s32);
s32 func_002c5120(u8*);
void func_001384a0(s32);
void func_0014f2b0(void);
void func_002c3280(u8* p)
{
    func_00170950(*(u32*)(p + 8232));
    func_002c5f60();
    func_002c6280(func_002c6218(), 2);
    switch (*(s32*)(p + 8240)) {
    case 0: break;
    case 1: func_002c5460(p + 13608); break;
    }
    func_00167f38(1);
    if (func_002c5120(p) && *(u32*)(p + 12368)) delete *(Obj**)(p + 12360);
    delete *(Obj**)(p + 872);
    if (p) ((DelFn)((Self*)p)->vt[4])((Self*)p);
    func_001384a0(0);
    func_0014f2b0();
}
}
}
