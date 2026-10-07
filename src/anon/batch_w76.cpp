#include "../common/types.h"
extern "C" {
f32* func_0016c028(u8*);
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
s32 func_00114620(u32);
u32 func_0016a070(u32);
s32 func_001a35f8(s32, u32);
u8* func_001058e8(void);
u8* func_00188fe0(u8*, u32);
struct Entry { u16 id : 15; u16 on : 1; };
u32 ctarget_0010f7b0(u32, u32, s32, u32) asm("_Z16ctarget_0010f7b0jjjj");

u32 ctarget_0010f7b0(u32 a, u32 b, s32 id, u32 d)
{
    if (id < 0) id = func_00114620(b);
    if (id == 0) return 0;
    if (func_001a35f8(id, func_0016a070(a)) <= 0) return 0;
    u8* base = func_001058e8() + 9456;
    u8* r = func_00188fe0(base, func_0016a070(a));
    u16 key = id;
    Entry* p = (Entry*)(r + 84);
    for (s32 i = 0; i < 80; i++) {
        Entry e = *p++;
        u32 on = e.on;
        if (e.id == key && on) return 1;
    }
    return 0;
}

extern u32 D_00341708[3];
extern u32 D_0034e948;
u8* func_0017df58(s32);
void func_001136b0(u32, u8*);
void func_00135818(u32, u32);
void func_001357d8(void);

void func_00111e50(void)
{
    u32 old[3];
    s32 i, k;
    for (i = 0; i < 3; i++) old[i] = D_00341708[i];
    D_00341708[2] = 0;
    D_00341708[0] = D_0034e948;
    D_00341708[1] = 0;
    for (k = 1; k < 3; k++) {
        u8* o = func_0017df58(k - 1);
        if (o) {
            D_00341708[k] = (u32)o;
            func_001136b0(*(u32*)(o + 2912), o);
            *(s32*)(o + 2928) = k;
        }
    }
    for (i = 0; i < 3; i++) {
        if (old[i] != D_00341708[i]) func_00135818(old[i], D_00341708[i]);
    }
    func_001357d8();
}

s32 func_001384c0(void);
extern u8 D_0032bad8;
s32 func_00103b38(void);
u8* func_0014aba8(void);
s32 func_002ee530(void);
u8* func_00167f18(u32);
u32 func_001c1218(void);
s32 func_001688b8(void);
void func_00253180(u32, s32);
void func_00253410(u32, u32);
void func_00102448(u32, u32);
void* func_001050c8(void);
typedef void (*VFn)(void*);

void func_001384d0(u32 a)
{
    for (;;) {
        if (!func_001384c0() && D_0032bad8 && !func_00103b38()
            && *(u32*)(func_0014aba8() + 252) == 0 && !func_002ee530()
            && (*(u64*)(func_00167f18(0) + 8) & 2)) {
            u32 v = func_001c1218();
            if (!v) { if (!func_001688b8()) func_00253180(0, -1); }
            else func_00253410(v, 0);
        }
        func_00102448(a, 0);
        void* o = func_001050c8();
        if (o) (*(VFn*)(*(u8**)o + 16))(o);
    }
}

extern void* D_00348050;
extern u8* D_00348058;
extern u8* D_00348054;
void func_00106420(void*);

void func_0013aed8(void)
{
    if (D_00348050) {
        (*(VFn*)(*(u8**)D_00348050 + 16))(D_00348050);
        D_00348050 = 0;
    }
    u8* p = D_00348058;
    if (p) {
        u8* q = p + 28224;
    l1: if (p == q) goto d1; q -= 784; (*(VFn*)(*(u8**)q + 12))(q); goto l1;
    d1:
        func_00106420(p);
        D_00348058 = 0;
    }
    p = D_00348054;
    if (p) {
        u8* q = p + 13056;
    l2: if (p == q) goto d2; q -= 408; (*(VFn*)(*(u8**)q + 12))(q); goto l2;
    d2:
        func_00106420(p);
        D_00348054 = 0;
    }
}

extern f32 D_00348d30[];
union HalfOrFloat6 { s16 h[6]; f32 f[6]; };
/* six s16 values to floats, optionally scaled by a table entry */
void func_001450e8(HalfOrFloat6* src, s32 idx, HalfOrFloat6* out)
{
    if (idx == 0) {
        out->f[0] = src->h[0];
        out->f[1] = src->h[1];
        out->f[2] = src->h[2];
        out->f[3] = src->h[3];
        out->f[4] = src->h[4];
        out->f[5] = src->h[5];
    } else {
        f32 s = D_00348d30[idx];
        out->f[0] = src->h[0] * s;
        out->f[1] = src->h[1] * s;
        out->f[2] = src->h[2] * s;
        out->f[3] = src->h[3] * s;
        out->f[4] = src->h[4] * s;
        out->f[5] = src->h[5] * s;
    }
}

void func_00239f18(u8*, f32);
void func_00138c68(u8*, s32, s32);
void func_001547e0(u8* a, s32 b, s32 c)
{
    f32 v = b;
    func_00239f18(a + c * 408 + 72, v / 100.0f);
    s32 n = (s32)-v;
    func_00138c68(a + c * 408 + 48, n, 0);
    if (c == 2) func_00138c68(a + 1272, n, 0);
}

struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern V4 D_004f37c0;
extern V4 D_004f37d0;
extern V4 D_004f37e0;
V4 func_0013f6e8(V4, V4, V4, f32, f32, f32, f32);
void func_0015d208(f32* a, f32* b)
{
    D_004f37d0.x = *a;
    D_004f37d0.y = *b;
    D_004f37c0 = func_0013f6e8(D_004f37c0, D_004f37d0, D_004f37e0, 0.07f, 2.5f, 0.5f, 0.001f);
    *a = D_004f37c0.x;
    *b = D_004f37c0.y;
}

void func_001da458(u8*, u32, u32, u32);
void func_001da558(u8*, void*, u32, u32);
extern u8 D_0034dbf8;
void func_0016cab8(u8*);
void func_0016c7d8(u8*);
typedef void (*VFn2)(void*, u32);
extern void* D_004f6288;
void func_0016d1f0(u32);
void func_0016ce90(u8*);
static inline void Kill(u8* n) { if (n) { func_0016cab8(n); func_0016c7d8(n); } }
void func_0016c9e8(u8* o)
{
    if (*(u32*)(o + 36)) {
        func_001da458(o, *(u32*)(o + 36), 0, 0);
        func_001da558(o, &D_0034dbf8, 0, 0);
    }
    u8* n = *(u8**)(o + 44);
    while (n) {
        u8* next = *(u8**)(n + 40);
        Kill(n);
        n = next;
    }
    (*(VFn2*)(*(u8**)D_004f6288 + 4))(D_004f6288, *(u32*)(o + 20));
    (*(VFn2*)(*(u8**)D_004f6288 + 4))(D_004f6288, *(u32*)(o + 24));
    if (*(u32*)(o + 52)) func_0016d1f0(*(u32*)(o + 52));
    func_0016ce90(o);
}

s32 func_001b58a8(u8*, u32, u32, u32);
void func_001b59c0(u8*, u32, u32, u32);
s32 func_0019ba60(u8*);
void func_0016cce8(u32, s32, u32*, s32, s32);
typedef void (*VFn4)(void*, u32, u32, u32);
void func_00177760(u8* o, u32 a, u32 b, u32 c)
{
    s32 r = func_001b58a8(o, a, b, c);
    u8* sub = o + 320;
    if (r) {
        func_001b59c0(o, a, b, c);
    } else if (*(u32*)(o + 352) & 0x4000) {
        u8* t = *(u8**)(sub + 252);
        if (func_0019ba60(t) && (*(u32*)(t + 1416) & 2))
            (*(VFn4*)(*(u8**)t + 116))(t, a, b, c);
    }
    if (*(u32*)(o + 1156)) {
        u32 buf[2];
        buf[0] = a;
        buf[1] = b;
        func_0016cce8(*(u32*)(o + 1156), 15, buf, 2, 0);
    }
}

struct Bits8 { u32 b0 : 1; u32 hi : 31; };
static inline bool InfoFlag(u8* info) { return ((Bits8*)(info + 8))->b0; }
void flagupd_0017c578(void*, u8* o) asm("_Z13func_0017c578Pv");
void flagupd_0017c578(void*, u8* o)
{
    u32 fl = *(u32*)(o + 264);
    if (fl & 0x10000) *(u32*)(o + 264) = fl | 0x20000;
    else *(u32*)(o + 264) = fl & ~0x20000;
    *(u32*)(o + 264) &= ~0x10000;
    f32* v = func_0016c028(o);
    *(f32*)(o + 216) += v[1];
    if (0.0f < *(f32*)(o + 204)) {
        Q16* d = (Q16*)(o + 32);
        Q16* s = (Q16*)(o + 192);
        if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
    *(u32*)(o + 264) &= ~0x800000;
    *(u32*)(o + 268) |= 1;
    *(u32*)(o + 264) &= ~0x1000000;
    if (!InfoFlag(*(u8**)(o + 12))) *(u32*)(o + 268) |= 2;
}

u8 func_0019f6f0(u8*, u32, u32);
u8 func_0019f740(u8*, u32, u32);
u8 func_0019bd08(u8*, u32);
u8 func_0019bdc8(u8* o, u32 a, u32 b)
{
    u8* s = o + 1044;
    if (func_0019f6f0(s, a, b)) return 1;
    if (func_0019f740(s, a, b)) return 0;
    s = o + 948;
    if (func_0019f6f0(s, a, b)) return 1;
    if (func_0019f740(s, a, b)) return 0;
    return func_0019bd08(o, b);
}

struct FV {
    f32 x, y, z, w;
    FV() {}
    FV& operator=(const FV& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void Normalize(FV* v)
{
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, $f1\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(v) : "$8", "$f1", "memory");
}
static inline void Scale(FV* d, const FV* s, f32 k)
{
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "mfc1 $8, %2\n\t"
        "qmtc2 $8, $vf2\n\t"
        "vmulx.wxyz $vf1, $vf1, $vf2x\n\t"
        "sqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
void func_0017a9e8(u32, u8*);
void btl_blow(u8* self, const FV& v) asm("_ZN2YS6BTLOBJ4blowERKN2kn7FVectorE");
/* knock-back: horizontal unit direction scaled by v.w */
void btl_blow(u8* self, const FV& v)
{
    *(u32*)(self + 268) &= ~0x20000;
    FV t;
    t = v;
    t.y = 0.0f;
    Normalize(&t);
    FV* dir = (FV*)(self + 32);
    FV r;
    Scale(&r, &t, v.w);
    *dir = r;
    *(f32*)(self + 36) = -v.y;
    func_0017a9e8(*(u32*)(self + 12), self);
}

extern struct { u32 a, b; } D_01d44100;
extern u8 D_01d44108[];
void func_0031a830(void*) asm("_Z13func_0031a830Pv");
void func_003200c0(void*);
void wtarget_001b1c38(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_001b1c38jjjj");
void wtarget_001b1c38(u32 a, u32 b, u32 c, u32 d)
{
    if (b == 0xffff && a == 1) {
        D_01d44100.a = 0;
        D_01d44100.b = 0;
    }
    if (b == 0xffff && a == 1) {
        u8* p = D_01d44108;
        for (s32 i = 15; i != -1; i--) {
            *(f32*)(p + 12) = *(f32*)(p + 8) = 0.0f;
            func_0031a830(p + 16);
            p += 40;
        }
        func_003200c0(D_01d44108);
    }
}
struct M44 { FV r[4]; };
static inline FV MulMV(const M44* m, const FV* v)
{
    FV out;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\t"
        "vmadday.wxyz ACC, $vf2, $vf5y\n\t"
        "vmaddaz.wxyz ACC, $vf3, $vf5z\n\t"
        "vmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&out), "r"(v), "r"(m) : "memory");
    return out;
}
struct ZNode { f32 key; FV* pos; ZNode* next; };
struct ZList { ZNode* head; ZNode* tail; };
static inline ZNode* NextZ(ZList* l, ZNode* n)
{
    if (!n) return l->head;
    return n->next;
}
/* project v by m and insert n into list sorted by depth z/w */
void func_001c1938(FV* v, ZList* list, ZNode* n, M44* m)
{
    v->w = 1.0f;
    FV t;
    t = MulMV(m, v);
    n->pos = v;
    n->key = t.z / t.w;
    ZNode* cur = 0;
    ZNode* prev = 0;
    while ((cur = NextZ(list, cur))) {
        if (cur->key >= n->key) break;
        prev = cur;
    }
    if (!prev) {
        if (!list->head) {
            list->tail = n;
            list->head = n;
            n->next = 0;
        } else {
            n->next = list->head;
            list->head = n;
        }
    } else if (prev == list->tail) {
        prev->next = n;
        n->next = 0;
        list->tail = n;
    } else {
        n->next = prev->next;
        prev->next = n;
    }
}

f32 func_00191b70(void);
extern u32 D_00351d98;
extern u8 D_0036dfe0[];
struct E16 { u32 w[4]; };
extern E16 D_0036e000[];
s32 func_001a5bd0(u32, s32, f32);
void func_001a5420(u32, E16*, u32);
void func_001c7ca8(u32 a, u32 b)
{
    f32 k = func_00191b70();
    if (D_00351d98) {
        for (s32 i = 0; i < 9; i++) {
            for (s32 j = 0; j < func_001a5bd0(b, i, k); j++)
                func_001a5420(D_00351d98, &D_0036e000[D_0036dfe0[i]], a);
        }
    }
}

void func_00177dc8(u8*, u32, s32);
extern u8 D_00352410[];
extern u32 D_00352400;
s32 func_00181978(void);
extern u32 D_0034f240;
void func_001a1c90(u8*, s32, s32);
s32 func_001d6d88(void);
u8* func_001c1130(s32);
u32 func_00192048(s32);
void func_001c11a8(s32);
void func_001d0878(u8* o, u32 a, s32 kind)
{
    func_00177dc8(o, a, kind);
    *(u32*)(o + 2920) = 0;
    *(u32*)o = (u32)D_00352410;
    *(u32*)(o + 2924) = 0;
    *(u32*)(o + 1416) |= 0x1000000;
    *(u32*)(o + 2928) = 0;
    D_00352400 = (u32)o;
    if (func_00181978()) {
        if (D_0034f240 & 0x40000) *(*(u8**)(o + 1164) + 431) = 4;
        else if (*(s32*)(o + 2896) == 12) func_001a1c90(*(u8**)(o + 1164), 2, -1);
        else if (func_001d6d88()) *(*(u8**)(o + 1164) + 431) = 3;
        else *(*(u8**)(o + 1164) + 431) = 1;
    }
    if (kind == 6) {
        u8* r = func_001c1130(29);
        *(u32*)(r + 24) = func_00192048(0xc44f);
    } else {
        func_001c11a8(29);
    }
}

extern u8 D_0032bb30[];
extern u8 D_0033bc10[];
s32 func_00105868(void*);
s32 func_00276fd0(void);
s32 func_001e0a90(void*);
static inline bool Is100() { return func_00276fd0() == 100; }
bool IsFMSecretMovie(void) asm("_ZN2YS13BATTLE_REPORT15IsFMSecretMovieEv");
bool IsFMSecretMovie(void)
{
    switch (func_00105868(D_0032bb30)) {
    case 0:
        return false;
    case 1:
        if (!Is100()) return false;
        return func_001e0a90(D_0033bc10) != 0;
    case 2:
        return Is100();
    case 3:
        return func_001a35f8(593, 100) > 0 && func_001a35f8(594, 100) > 0 && func_001a35f8(595, 100) > 0;
    }
    return false;
}

f32 func_002f8ad0(f32, f32);
u8* func_0016f000(u32, FV*, f32);
void func_0016c018(u8*, s32, u32);
extern u32 D_003638d0;
extern f32 D_00352ad0;
static inline u32 Rand() { D_003638d0 *= 0x10dcd; return D_003638d0; }
static inline f32 Rand1() { return (f32)Rand() * 2.3283064365386963e-10f; }
static inline f32 RandR(f32 lo, f32 w) { return lo + Rand1() * w; }
u8* func_001dbe78(u8* o, FV* dir)
{
    FV t;
    t = *(FV*)o;
    t.y += *(f32*)(*(u8**)(o + 92) + 8);
    f32 h = func_002f8ad0(dir->x, dir->z);
    u8* r = func_0016f000(*(u32*)(*(u8**)(o + 92) + 4), &t, h);
    if (r) {
        func_0016c018(r, 1, *(u32*)(o + 88));
        D_00352ad0 = RandR(8.0f, 22.0f);
    }
    return r;
}

union PtrF { u8* p; f32 f; };
extern PtrF D_01d9e6e8;
void func_0021edb0(u8*, u8*);
static inline void ScaleRow(u8* row, f32 k)
{
    asm volatile(
        "qmtc2 %1, $vf9\n\t"
        "lqc2 $vf10, 0(%0)\n\t"
        "vmulx.xyz $vf10, $vf10, $vf9x\n\t"
        "sqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(k) : "memory");
}
void func_001eadf8(u8* base, u32 unused, u8* desc)
{
    u32* d = *(u32**)(desc + 12);
    u8* p0 = base + d[0];
    u8* p1 = base + d[1];
    u8* p2 = base + d[2];
    f32* t = (f32*)(p0 + 160);
    f32* s = (f32*)(p2 + 160);
    func_0021edb0(D_01d9e6e8.p + 16, p1 + 160);
    ScaleRow(D_01d9e6e8.p + 16, s[0]);
    ScaleRow(D_01d9e6e8.p + 32, s[1]);
    ScaleRow(D_01d9e6e8.p + 48, s[2]);
    *(f32*)(D_01d9e6e8.p + 64) = t[0];
    *(f32*)(D_01d9e6e8.p + 68) = t[1];
    *(f32*)(D_01d9e6e8.p + 72) = t[2];
}

extern u32 D_01d9ea9c;
extern u32 D_01d9eab4;
extern u8* D_01d9e6e0;
void func_001f69c0(void);
void func_0021ee48(u8*, u8*, void*, u8*, s16, u8, u8);
void func_001f6b68(u8* base, u8* in, u8* desc)
{
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (in[7] == 0) return;
    u8* q = base + **(u32**)(desc + 12) + 160;
    if (q[2] == 0) {
        q[2] = in[7];
        if (*(s32*)(in + 12) == -1) return;
        if (*(s32*)(in + 20) == -1) return;
        func_0021ee48(base, in, (void*)func_001f69c0, q, *(s16*)(in + 4), in[8], in[6]);
    }
    q[2]--;
}

extern u8 D_00354be0[];
void func_002f3f88(u8*, void*);
void func_001fb8b8(u8*, s32, s32);
void func_001fb9a8(u8* base, u8* in, u8* desc)
{
    u8* p = base + **(u32**)(desc + 12);
    u8* q = p + 160;
    q[36] = (s32)(in[8] * *(f32*)(D_01d9e6e0 + 48));
    q[37] = (s32)(in[9] * *(f32*)(D_01d9e6e0 + 52));
    q[38] = (s32)(in[10] * *(f32*)(D_01d9e6e0 + 56));
    q[39] = (s32)(in[11] * *(f32*)(D_01d9e6e0 + 60));
    func_002f3f88(p + 176, D_00354be0);
    func_001fb8b8(q, 0, 0);
}

void func_00201ca0(u8* p, s32* x, s32* w, s32* y, s32* h)
{
    s32 ox = 0;
    s32 wv = 4096;
    s32 hv = 4096;
    switch (p[22]) {
    case 1: wv = 2048; break;
    case 2: wv = 1024; break;
    }
    switch (p[23]) {
    case 1: hv = 2048; break;
    case 2: hv = 1024; break;
    }
    switch (p[24]) {
    case 1: ox = 1024; wv += 1024; break;
    case 2: ox = 2048; wv += 2048; break;
    case 3: ox = 3072; wv += 3072; break;
    }
    *x = ox + 16;
    *w = wv - 16;
    *y = 16;
    *h = hv - 16;
}
s32 func_00287bc0(void);
void func_00287d68(void);
s32 func_00287db0(void);
s32 func_0028acc8(u32);
s32 func_00139d78(void*);
void func_001039f8(void);
void func_0024be68(void);
void func_0024bfb8(void);
extern u32 D_0035eda8;
extern u32 D_0035edac;
extern void* D_0035edb0;
extern void* D_0035edb4;
extern void* D_0035edb8;
s32 func_0024bd90(void)
{
    s32 mode = func_00287bc0();
    func_00287d68();
    if (func_00287db0()) {
        if (func_0028acc8(D_0035eda8) || func_0028acc8(D_0035edac) || func_00139d78(D_0035edb0)
            || func_00139d78(D_0035edb4) || func_00139d78(D_0035edb8))
            return 0;
        func_001039f8();
        return 1;
    } else {
        switch (mode) {
        case 0: func_0024be68(); break;
        case 1: func_0024bfb8(); break;
        }
    }
    return 0;
}
union PtrI { u8* p; s32 i; };
extern PtrI D_0035f20c;
extern u32 D_0035f14c;
extern u32 D_0035f148;
extern u32 D_0035f210;
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00275d10(void)
{
    if (!func_00139d78(D_0035f20c.p)) {
        func_0028d980(D_0035f20c.p, 30040, D_0035f14c, D_0035f148, D_0035f210, 47, 48, -1, 0);
        *(s32*)(D_0035f20c.p + 432) = 2;
    }
    if (!func_00139d78(D_0035f20c.p + 436)) {
        func_0028d980(D_0035f20c.p + 436, 30040, D_0035f14c, D_0035f148, D_0035f210, 50, 51, -1, 0);
        *(s32*)(D_0035f20c.p + 868) = 2;
    }
}

void func_00276088(u32, s32*, s32*);
extern u16 D_00373d70[3];
void func_00276150(u32 a, s32* out0, s32* out1)
{
    s32 v0, v1;
    func_00276088(a, &v0, &v1);
    for (s32 k = 0; k < 2; k++) {
        s32 x;
        if (k == 0) x = v0; else x = v1;
        for (s32 j = 0; j < 3; j++) {
            if (D_00373d70[j] == x) { x = j; break; }
        }
        s32 r = -1;
        switch (x) {
        case 0: r = 0; break;
        case 1: r = 2; break;
        case 2: r = 13; break;
        }
        if (k == 0) *out0 = r; else *out1 = r;
    }
}
u8* func_0023f1b0(void*);
u32 func_0023c3e0(u8*, s32, s32);
u32 func_0028dbf8(void* a, s16* keys, s16* vals)
{
    if (!func_00139d78(a)) return 0;
    s32 idx = -1;
    s32 cur = *(s32*)(func_0023f1b0(a) + 76);
    for (s32 i = 0; i < 3; i++) {
        if (cur == keys[i]) { idx = vals[i]; break; }
    }
    if (idx < 0) return 0;
    return func_0023c3e0(func_0023f1b0(a), idx, 0);
}

s32 func_00192a80(u32);
s32 func_00105c30(void);
extern char D_00374470[];
u32 func_00192cc0(char*, const char*);
s32 func_00192b30(u32);
void func_002fdd68(u8*, char*, s32);
u8* func_0028de08(u32 id, u8* buf)
{
    char tmp[32];
    s32 flag = 0;
    u8* p = buf;
    s32 n = func_00192a80(func_00192048(id));
    if (func_00105c30() == 1 || func_00105c30() == 8) flag = 1;
    if (!flag) n = 5;
    s32 len = func_00192b30(func_00192cc0(tmp, D_00374470));
    for (s32 i = 0; i < n; i++) {
        if (i + 1 >= n) len++;
        func_002fdd68(p, tmp, len);
        p += len;
    }
    return buf;
}

s8* func_00276568(void);
s32 func_002a4380(s8);
s32 func_002b3ae8(void);
s32 func_002a9b88(s8);
s32 func_002a8870(s8);
s32 JmReport_GetIndex(u32 idx) asm("_ZN2Tz8JmReport8GetIndexEj");
s32 JmReport_GetIndex(u32 idx)
{
    s32 list[9];
    s32* p = list;
    for (s32 i = 0; i < 9; i++) {
        if (i == 3 && func_002a4380(*func_00276568())) continue;
        if (i == 4 && !func_002b3ae8()) continue;
        if (i == 6 && !func_002a9b88(*func_00276568())) continue;
        if (i == 7 && !func_002a8870(*func_00276568())) continue;
        *p++ = i;
    }
    return list[idx];
}
union GP { u8* p; s32 i; };
extern GP D_0035f5e4;
s8* func_00276568(void);
void func_002a4b78(void)
{
    s32 m = func_00287bc0();
    if (m == 26 || m == 34 || m == 33) {
        *(s32*)(D_0035f5e4.p + 4228) = 0;
        *(s32*)(D_0035f5e4.p + 4232) = 0;
        return;
    }
    s32 lim = *(s32*)(D_0035f5e4.p + 4224);
    if (lim >= 10) lim = 9;
    s32 n = *func_00276568();
    s32 sum = 0;
    for (s32 i = 0; i < n; i++) sum += *(D_0035f5e4.p + 4097 + i * 8);
    s32 d = *(s32*)(D_0035f5e4.p + 4224) - lim;
    if (d >= sum) {
        *(s32*)(D_0035f5e4.p + 4228) = sum;
        *(s32*)(D_0035f5e4.p + 4232) = 0;
    } else {
        *(s32*)(D_0035f5e4.p + 4228) = d;
        *(s32*)(D_0035f5e4.p + 4232) = (sum - *(s32*)(D_0035f5e4.p + 4228)) * 8;
    }
}

static inline bool TestBit(u32* bits, u32 i) { return (bits[i >> 5] & (1 << (i & 31))) != 0; }
extern u8* D_0035f610;
extern u8* D_0035f620;
u8* func_001a82b0(u8*);
s32 func_002764b0(u8);
bool func_002adaf0(s32 who)
{
    u8* e = 0;
    u32 idx = 0;
    bool r = true;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (e[4] == 0) {
            u16 k = *(u16*)(e + 8);
            if (k != 0 && k != 2048) {
                if (who < 0 || func_002764b0(e[5]) == who) {
                    if (!TestBit((u32*)(D_0035f620 + 236), idx)) { r = false; break; }
                }
            }
        }
        idx++;
    }
    return r;
}
void func_002edf28(u8*);
u8* func_001050d8(u32);
void func_001ad0f8(u8*, u32, s32);
void func_001ad330(u8*, u32);
extern u8 D_00361980[];
union PtrS { u8* p; s32 i; };
void func_002bec88(u8* o, s32 kind, u32 arg)
{
    func_002edf28(o);
    *(u32*)(o + 40) = 0;
    *(u32*)o = (u32)D_00361980;
    switch (kind) {
    case 0: {
        u8* p = func_001050d8(2924);
        func_001ad0f8(p, arg, 0);
        ((PtrS*)(o + 36))->p = p;
        *(s32*)(p + 100) = 2;
        u8* q = ((PtrS*)(o + 36))->p;
        *(s32*)(q + 4) = 256;
        *(s32*)(q + 8) = 48;
        break;
    }
    case 1: {
        u8* p = func_001050d8(4656);
        func_001ad330(p, arg);
        *(u8**)(o + 36) = p;
        break;
    }
    }
}

void func_002369a0(u8*);
void func_0023c008(u8*);
extern u8 D_00363880[];
extern u8 D_003619a8[];
extern u32 D_00361998;
u8* func_002beb90(void);
u32 func_001708f8(u8*, s32);
u8* func_00168b38(u32, s32, s32);
void func_002ef1f8(u8*, u32, u32);
void func_002bf308(void);
void func_00102c18(s32, u32, void*);
void func_002befc0(u8* o)
{
    u32 v = (u32)func_001050c8();
    func_002edf28(o);
    *(u32*)(o + 36) = v;
    *(u32*)o = (u32)D_00363880;
    func_002369a0(o + 40);
    func_0023c008(o + 64);
    *(u32*)o = (u32)D_003619a8;
    D_00361998 = (u32)o;
    *(u32*)(o + 156) = func_001708f8(func_002beb90(), -1);
    u8* x = func_00168b38(*(u32*)(o + 156), 28, 0);
    u8* y = func_00168b38(*(u32*)(o + 156), 29, 0);
    func_002ef1f8(o, *(u32*)(x + 8), *(u32*)(y + 8));
    *(u32*)(o + 4) |= 1;
    func_00102c18(1, 0x19258, (void*)func_002bf308);
}

struct V4f { f32 x, y, z, w; };
extern V4f D_01e2bc70;
extern V4f D_01e2bc80;
extern V4f D_01e2bc90;
static inline void Set4(V4f* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void wtarget_002c0738(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002c0738jjjj");
void wtarget_002c0738(u32 a, u32 b, u32 c, u32 d)
{
    if (b == 0xffff && a == 1) Set4(&D_01e2bc70, 0.0f, -500.0f, 0.0f, 1.0f);
    if (b == 0xffff && a == 1) Set4(&D_01e2bc80, 0.0f, -1840.0f, -2400.0f, 0.0f);
    if (b == 0xffff && a == 1) Set4(&D_01e2bc90, 0.0f, -3450.0f, -3000.0f, 0.0f);
}
/* sign + decimal digits of v after prefix char c; returns length */
s32 func_00301480(char* buf, s32 v, s32 c)
{
    char tmp[40];
    char* p = buf;
    *p++ = c;
    if (v < 0) {
        v = -v;
        *p++ = '-';
    } else {
        *p++ = '+';
    }
    char* q = tmp + 40;
    char* end = q;
    if (v >= 10) {
        do {
            *--q = v % 10 + '0';
            v /= 10;
        } while (v >= 10);
        *--q = v + '0';
        while (q < end) *p++ = *q++;
    } else {
        *p++ = '0';
        *p++ = v + '0';
    }
    return p - buf;
}
void func_001af638(void);
void func_001af6f0(void);
void func_001bb468(u8*);
u32 func_001c10f8(s32);
s32 func_0017a538(u8*);
u32 func_001d1438(s32);
u32 func_0016a020(u8*);
static inline bool Is12(u8* p) { return *(s32*)(p + 2896) == 12; }
void func_001af0c0(u8* o)
{
    if (*(u8*)(o + 12) == 0) func_001bb468(o);
    else *(void**)(o + 44) = (void*)func_001af638;
    if (*(s32*)o == 3) {
        *(u32*)(o + 16) = func_001c10f8(33);
    } else {
        *(u32*)(o + 16) = func_001c10f8(1);
        *(void**)(o + 72) = (void*)func_001af6f0;
    }
    u8* p = (u8*)D_0034e948;
    if (p) {
        u32 v;
        if (func_0017a538(p) || Is12(p)) v = func_001d1438(0);
        else v = func_0016a020(p) | 0x20000000;
        *(u32*)(o + 48) = v;
    } else {
        *(u32*)(o + 48) = 0;
    }
}
extern char D_0036ef58[];
extern char D_0036efb8[];
extern char D_0036ef98[];
extern char D_0036ef88[];
void func_002fdfc8(const char*, ...);
u8* func_001e7a98(u8*, u8*);
static inline void AssertFail(const char* expr, const char* file, u32 line)
{
    func_002fdfc8(D_0036ef58, expr);
    func_002fdfc8(D_0036ef98, file, line);
    asm volatile("break");
}
void func_001e8ac8(u8* o)
{
    for (s32 i = 0; i < *(s32*)(o + 104); i++) {
        u8* e = *(u8**)(o + 128) + i * 16;
        if (!e) AssertFail(D_0036efb8, D_0036ef88, 964);
        if (*(s32*)(o + 88) < *(s32*)(e + 8)) continue;
        *(s32*)(e + 8) = 0x7fffffff;
        u8* r = func_001e7a98(o, e);
        *(u8**)(e + 4) = r;
        *(r + 156) = 0;
    }
}

u8* func_001a80c8(u16);
bool func_002ab8e8(s32 who)
{
    u8* e = 0;
    u32 idx = 0;
    bool r = false;
    for (;;) {
        e = func_001a82b0(e);
        if (!e) break;
        if (func_001a80c8(*(u16*)(e + 2))[2] != 22) continue;
        if (who >= 0 && func_002764b0(e[5]) != who) { idx++; continue; }
        if (TestBit((u32*)(D_0035f610 + 300), idx)) { r = true; break; }
        idx++;
    }
    return r;
}
u8* func_002a9d68(s32);
bool func_002aaab8(s32 id)
{
    u8* a = func_002a9d68(id);
    bool r = true;
    if (id < 0) {
        for (s32 i = 0; i < 32; i++) {
            if (TestBit((u32*)(D_0035f610 + 132), i)) {
                r = TestBit((u32*)(a + 132), i);
                if (!r) break;
            }
        }
    } else {
        r = TestBit((u32*)(D_0035f610 + 132), id) && TestBit((u32*)(a + 132), id);
    }
    return r;
}
}
