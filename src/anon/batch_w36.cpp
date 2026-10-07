#include "../common/types.h"
#include <stdarg.h>

struct Obj { struct VT { void* f[16]; }* vt; };
typedef void (*VFn)(void*);
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
struct Blk64 { u32 w[16]; };

extern "C" {
u32 wtarget_00142208(u32, u32, u32, u32) asm("_Z16wtarget_00142208jjjj");
void ctarget_00185b00(u32, u32, u32, u32) asm("_Z16ctarget_00185b00jjjj");
u32 ctarget_0018bbf8(u32, u32, u32, u32) asm("_Z16ctarget_0018bbf8jjjj");

s32 func_0013ba50(u8*, s32);
extern s8 D_00457458;
extern u8 D_00457460[];
void func_002fd188(void*);
void func_00142c88(void);
void func_00141988(u8*, u32, u8*);
extern u8 D_00348d68[];
void func_00149448(u8*);
u32 func_001492c8(u8*);
void func_0015c228(u32);
u32 func_001050c8(void);
void func_0015eba8(u8*, u32, u32, u32);
extern f32 D_0034a780;
extern f32 D_0034a784;
extern f32 D_0034a788;
s32 func_001541d8(u8*, u32*, u32);
u32 func_00154288(u8*, u32);
void func_001387f8(u8*, u32, u8*, u32);
s32 func_00197920(u8*);
extern f32 D_00349e14;
s32 func_001ad938(void);
struct Flags34f240 { u32 b0 : 1; };
extern Flags34f240 D_0034f240;
void func_00138840(u8*);
s32 func_0017e310(u32);
u32 func_001a8bd0(s32);
u32 func_0016a070(u32);
s32 func_001a90a8(u32, u32);
void func_001d7cd0(u8*);
extern u8 D_0034ed78[];
s32 func_0016a090(u8*);
u32 func_0016c028(void);
u32 func_0018c490(u8*, u32);
void func_0018c480(u8*, u32);
u8* func_001b58f0(u32, u32, u32, u32);
Q16* func_001dc5f8(u8*);
struct S1c620c8 { u8 pad[96]; s32 a[4]; };
extern S1c620c8 D_01c620c8;
extern s32 D_01c62138;
struct Pair { s32 a, b; };
static inline void pair_clear(Pair* p) { p->a = 0; p->b = 0; }
extern Pair D_01c62140;
void func_00199280(void);
void func_00102c18(u32, u32, void*);
s32 func_00194878(u32, s32);
extern u32 D_0032de28[][2];
static inline s32 bit_test(const u32* bits, u32 n) { return (bits[n >> 5] & (1 << (n & 31))) != 0; }
extern u32 D_00350790;
extern u8 D_0036d4e8[];
void func_001a5420(u32, u8*, u32);
void func_00239700(u8*);
void func_001abb28(u8*);
u32 func_001ab810(void);
u32 func_001ab800(void);
void func_00239988(u8*, u32, u32);
u8* func_001c10f8(void);
extern Blk64 D_01d49388[];

s32 func_0013b9e0(u8* p, s32 b) {
    if (func_0013ba50(p, b)) return 0;
    if (b == 0 && *(s32*)(p + 236) == 6) return 1;
    if (b == 6 && *(s32*)(p + 236) == 0) return 1;
    return 0;
}

// Function-local static: guard byte, destructor registered once.
u32 wtarget_00142208(u32 a0, u32 a1, u32, u32) {
    u8* p = (u8*)a0;
    u16 i = a1;
    if (!D_00457458) {
        D_00457458 = 1;
        func_002fd188((void*)func_00142c88);
    }
    func_00141988(p, *(u32*)(p + 12) + i * 16, D_00457460);
    return (u32)D_00457460;
}

void func_00149c40(u32 a) {
    func_00149448(D_00348d68);
    func_0015c228(func_001492c8(D_00348d68));
    func_0015eba8(D_00348d68, func_001050c8(), 1, a);
}

f32 func_00153610(f32 x) {
    f32 r = 1.0f / (D_0034a780 + D_0034a784 * x + D_0034a788 * x * x);
    if (1.0f < r) r = 1.0f;
    if (r < 0.0f) r = 0.0f;
    return r;
}

void func_001542c8(u8* p, u32 a, u32 b) {
    u32 v = 0;
    if (func_001541d8(p, &v, a) == 1) {
        func_001387f8(p, v, p + 416, func_00154288(p, b));
    }
}

void func_0015aaf8(u8* p) {
    if (func_00197920(p)) {
        ((VFn)(*(void***)p)[5])(p);
        return;
    }
    if (*(f32*)(p + 28) <= 0.0f) ((VFn)(*(void***)p)[5])(p);
    *(f32*)(p + 28) = *(f32*)(p + 28) - D_00349e14;
}

void func_0015ac68(u8* p) {
    if (func_00197920(p) || func_001ad938() || (u8)D_0034f240.b0) {
        ((VFn)(*(void***)p)[5])(p);
        return;
    }
    func_00138840(p);
}

// Which side of a plane: (b - a) . n
s32 func_00163828(const f32* a, const f32* b, const f32* n) {
    Q16 d;
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%0)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(&d) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(r) : "r"(&d), "r"(n) : "$8", "memory");
    if (r < -0.001f) return 1;
    if (0.001f < r) return 0;
    return 2;
}

s32 func_0017e358(u32 a) {
    s32 r = 0;
    if (func_0017e310(a)) {
        u32 x = func_001a8bd0(-1);
        r = func_001a90a8(x, func_0016a070(a)) == 0;
    }
    return r;
}

void ctarget_00185b00(u32 a0, u32, u32, u32) {
    u8* p = (u8*)a0;
    func_001d7cd0(p);
    *(u32*)(p + 2800) = 0;
    *(void**)p = D_0034ed78;
    *(u32*)(p + 1416) |= 0x10;
    *(f32*)(p + 2804) = 100.0f;
    if (func_0016a090(p) == 2) *(u32*)(p + 2748) |= 0x8000;
}

u32 ctarget_0018bbf8(u32 a0, u32, u32, u32) {
    u8* q = (u8*)a0 + 2624;
    if (q[48]) return 0;
    u32 r = func_0018c490(q, func_0016c028());
    if (r) func_0018c480(q, 1);
    return r;
}

void func_0018fe80(u32* p) {
    u8* v = func_001b58f0(p[0], p[1], p[3], 0);
    if (v) {
        Q16* d = func_001dc5f8(v);
        Q16* s = (Q16*)p[2];
        if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
    p[0] = (u32)v;
}

void func_00199548(void) {
    s32 i;
    for (i = 0; i < 4; i++) D_01c620c8.a[i] = i;
    D_01c62138 = 4;
    pair_clear(&D_01c62140);
    func_00102c18(1, 14500, (void*)func_00199280);
}

s32 func_0019eeb8(s32 a, u32 b) {
    if (func_00194878(b, a)) return 1;
    return bit_test(D_0032de28[a], b);
}

void func_001a5880(u32 a, s32 k, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) func_001a5420(D_00350790, D_0036d4e8 + k * 16, a);
}

void func_001abd90(u8* p) {
    *(u32*)p = 0;
    func_00239700(p + 4);
    func_001abb28(p + 348);
    u32 x = func_001ab810();
    func_00239988(p + 4, x, func_001ab800());
}

Blk64* func_001c1130(void) {
    u8* p = func_001c10f8();
    D_01d49388[p[36]] = *(Blk64*)p;
    return &D_01d49388[p[36]];
}
}



extern "C" {
void func_0016bd60(u8*, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_001c1fe0(u8*);
void func_001c9c00(void);
void func_001c9c78(u32);
extern s32 D_00351f30;
extern u32 D_01d49980[];
void func_001980d0(u8*, u32, u32);
extern u8 D_00352140[];
extern u8 D_01d5b9e0[];
void func_001dba88(u32);
u8* func_001d6cc8(u8*);
s32 func_001a3570(u16);
s32 func_002283e0(void);
u32 func_00227120(void);
s32 func_002ff538(u32, const char*, u32);
extern const char D_003712f0[];
extern u8 D_0035e359;
extern s32 D_0035e360;
extern s32 D_0035e368;
struct Ev32 { s32 type, id, a, b, c, d, e, f; };
extern Ev32 D_01dadc00[];

struct Fn18 { u8 pad[16]; s32 (*f)(Fn18*); u8 pad2[3]; u8 b23; u32 pad3; u32* f28; u8* f32; };

s32 func_001c18d0(Fn18* p) {
    if (!p->f(p)) return 0;
    if (!p->f32) return 1;
    u8 v;
    switch (p->f28[1]) {
    case 0: v = p->f32[15]; break;
    case 1: v = p->f32[13]; break;
    default: v = 0; break;
    }
    p->b23 = v;
    return 1;
}

void func_001c1d90(u32, u8* p) {
    if (*(u32*)(p + 2732) == 0) {
        func_0016bd60(p, 5);
        func_0017f488(p + 320, 0, 8.0f, 0.0f);
        return;
    }
    func_001c1fe0(p);
}

void func_001c9b90(void) {
    s32 i;
    func_001c9c00();
    for (i = 0; i < D_00351f30; i++) func_001c9c78(D_01d49980[i]);
    D_00351f30 = 0;
}

void func_001ce378(u8* p, u32 a, u32 b) {
    func_001980d0(p, b, 4);
    *(u32*)(p + 2548) = a;
    *(void**)p = D_00352140;
    func_001dba88(a);
    *(u32*)(p + 1416) |= 0x800000;
    *(void**)(p + 2552) = D_01d5b9e0;
}

s32 func_001d6ec8(void) {
    s32 n = 2;
    u8* p = 0;
    while ((p = func_001d6cc8(p)) != 0) n += func_001a3570(*(u16*)(p + 2)) > 0;
    if (n == 6) n++;
    return n;
}

struct Comp { u8 pad[20]; VFn f; };
struct Mgr { u8 pad[100]; s32 n; u8 pad2[16]; Comp** c; };
// Runs every component's optional update hook.
void func_001e7878(Mgr* p) {
    s32 i;
    for (i = 0; i < p->n; i++) {
        if (p->c[i]->f) p->c[i]->f(p);
    }
}

void func_00232590(void) {
    D_0035e359 = 0;
    if (func_002283e0()) {
        if (func_002ff538(func_00227120(), D_003712f0, 12) == 0) D_0035e359 = 1;
    }
}

// Queues an event record in a 64-entry ring; returns its serial number.
s32 func_00234348(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 idx = D_0035e360;
    s32 id = D_0035e368;
    Ev32* ev = &D_01dadc00[idx];
    ev->type = 8;
    ev->id = id;
    ev->a = a;
    ev->b = b;
    ev->c = c;
    ev->d = d;
    ev->e = e;
    ev->f = f;
    D_0035e360 = (idx + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

struct Key44 { u8 pad[20]; f32 x, y; u8 pad2[16]; };
struct Ref20 { u8 pad[16]; s32 idx; };
struct Tbl { u32 pad; Key44* keys; Ref20* refs; u16* ranges; };

s32 func_002384f8(Tbl* t, s32 i) {
    u16* r = &t->ranges[i * 2];
    Ref20* e = &t->refs[r[0]];
    s32 n = r[1];
    for (; n > 0; n--, e++) {
        Key44* k = &t->keys[e->idx];
        if (k->x != 0.0f || k->y != 0.0f) return 1;
    }
    return 0;
}

struct Ent144 { u32 flags; u32 pad[2]; s32 v; u8 pad2[128]; };
struct Rng36 { u16 first, count; u8 pad[32]; };

s32 func_00239b50(u8* p, s32 i) {
    Rng36* r = &(*(Rng36**)(p + 180))[i];
    Ent144* e = &(*(Ent144**)(p + 176))[r->first];
    s32 n = r->count;
    s32 m = 0;
    for (; n > 0; n--, e++) {
        s32 v = e->v;
        if (m < v) {
            if (e->flags & 0x8000) m = v - 1;
            else m = v;
        }
    }
    return m + 1;
}
}



extern "C" {
s32 wtarget_002fee78(u8*, const char*, ...) asm("_Z16wtarget_002fee78jjjj");
s32 func_002ffd00(u8*, const char*, va_list);

extern u32 D_0035ee64;
s32 func_00139d78(u32);
extern u32 D_00372668[];
void func_0023f5b8(u32, u32, u32);
u32 func_00256b68(u32);
extern u32 D_0035f01c;
extern u32 D_0035f04c;
s32 func_0028acc8(u32);
s32 func_0028be58(u32);
u32 func_002570a0(u32);
s32 func_002635d8(u32);
s32 func_00263660(u32);
u8* func_001058e8(void);
extern s8 D_00374188[];
void func_00281f70(u8*, u32, u32);
void func_00282858(u8*, u32, u32);
void func_00282b00(u8*, u32, u32);
u32 func_00103570(void);
u32 func_001063c0(u32, u32);
void func_00324448(u32);
extern u32 D_0035f600;
extern u32 D_0035f604;
u32* func_002a9d68(void);
extern u8* D_0035f634;
u8 func_00281be0(void);
u32 func_00192048(u32);
void func_00192e50(u32, u32, u32, u32);
struct Ent32 { u32 w[8]; };
struct Stack1e2a5f8 { Ent32 e[32]; s32 free[32]; s32 n; };
extern Stack1e2a5f8 D_01e2a5f8;
void func_002bac78(Ent32*, u32, u32, u32, u32, u32, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_002c5f78(u8*);
u8* func_001c3748(u32, u8*);
extern s32 D_01e2bfa4;
extern u8* D_01e2bfa0;
void func_002e93a0(u8*);
extern f32 D_01e2c048;
void func_001d14b0(u8*, u32);
void func_0017c578(u32, u8*);
u32 func_002f3588(u32);
void func_002f3490(u32*);
s32 func_0030edb0(void);
void func_0030ee00(void);
void func_003086b8(u32, void*, u32);
void func_002f6bd0(void);
extern s32 D_00363da4;
extern s32 D_00363dc8;
extern u8* D_00365c48;
s32 func_002ffd78(u8*, u8*, const char*, va_list);
void func_00302e10(u8*);
union FLO;
struct FPN;
void func_003147a0(FLO*, FPN*);
FPN* func_00313c58(FPN*, FPN*, FPN*);
double func_003146c8(FPN*);

void func_00251ec8(s32 i) {
    if (D_0035ee64 && func_00139d78(D_0035ee64)) {
        u32 v = D_00372668[i];
        func_0023f5b8(D_0035ee64, v, 0);
    }
}

s32 func_00262290(void) {
    s32 r = func_00139d78(func_00256b68(1));
    if (r) return r;
    if (D_0035f01c) r = func_0028acc8(D_0035f01c) != 0;
    if (r) return r;
    if (D_0035f04c) r = func_0028be58(D_0035f04c) != 0;
    return r;
}

s32 func_002637e8(s32 a) {
    u32 h = func_002570a0(10);
    if (!a) a = func_002635d8(h) == 0;
    else a = 1;
    if (a == 1) {
        if (!func_00263660(h)) a = -1;
    }
    return a;
}

// Is the current id in the -1-terminated table?
s32 func_002812e0(void) {
    s32 r = 0;
    u8 c = func_001058e8()[12];
    s32 i;
    for (i = 0; D_00374188[i] >= 0; i++) {
        if (D_00374188[i] == c) {
            r = 1;
            break;
        }
    }
    return r;
}

void func_002abdc8(void) {
    u32* bits = (u32*)((u8*)func_002a9d68() + 320);
    s32 i;
    for (i = 0; i < 4; i++) {
        u32* w = (u32*)(((u32)i >> 5) * 4 + (u32)bits);
        u32 m = 1 << (i & 31);
        if (!(*w & m)) *w |= m;
    }
}

// The empty-destructor local keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };

void func_002b1660(void) {
    NoTail g;
    if (func_00139d78((u32)(D_0035f634 + 21624))) return;
    if (func_00139d78((u32)(D_0035f634 + 22904))) return;
    if (func_00139d78((u32)(D_0035f634 + 23340))) return;
    if (func_00139d78((u32)(D_0035f634 + 23776))) return;
    func_00281be0();
}

void func_002b6338(u32 a, u32 b, u32 c, u32 d) {
    u32 id = !d ? 0xb7d4 : 0xb7d5;
    u32 x = func_00192048(c);
    func_00192e50(x, a, b, func_00192048(id));
}

void func_002baf48(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    s32 n = --D_01e2a5f8.n;
    func_002bac78(&D_01e2a5f8.e[D_01e2a5f8.free[n]], a, b, c, d, e, f);
}

// dst = src * s (VU0), then kick a motion.
void func_002c18e0(u32, u8* p) {
    Q16 tmp;
    Q16* d = (Q16*)(p + 32);
    f32 s = *(f32*)(*(u8**)(p + 300) + 36);
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&tmp), "r"(p + 16), "f"(s) : "$8", "memory");
    if (d != &tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&tmp) : "$8", "memory");
    func_0017f488(p + 320, 154, 0.0f, 0.0f);
    func_002c5f78(p);
}

u32 func_002c2598(u32 a, s32 n) {
    s32 i = 0;
    u8* v = 0;
    while ((v = func_001c3748(a, v)) != 0) {
        if (i == n) return func_00192048(*(u16*)(v + 4));
        i++;
    }
    return 0;
}

void func_002ec088(u32 a, u8* p) {
    *(f32*)(p + 276) = *(f32*)(p + 272) = 20.0f;
    *(f32*)(p + 284) = D_01e2c048;
    *(f32*)(p + 284) = *(f32*)(*(u8**)(p + 300) + 12);
    func_001d14b0(p, 2);
    func_0017c578(a, p);
}

struct SFile { u8* p; s32 r; s32 w; s16 flags; s16 file; u8* base; s32 size; u8 pad[60]; u8* data; u8 pad2[8]; };

// sprintf: formats into a string-backed stream.
s32 wtarget_002fee78(u8* buf, const char* fmt, ...) {
    SFile f;
    va_list ap;
    f.flags = 520;
    f.base = f.p = buf;
    f.size = f.w = 0x7fffffff;
    f.data = D_00365c48;
    va_start(ap, fmt);
    s32 r = func_002ffd00((u8*)&f, fmt, ap);
    va_end(ap);
    *f.p = 0;
    return r;
}

// vfprintf: makes sure the stream has an initialised reentrancy struct.
s32 func_002ffd00(u8* fp, const char* fmt, va_list ap) {
    if (*(u8**)(fp + 84) == 0) *(u8**)(fp + 84) = D_00365c48;
    if (*(u32*)(*(u8**)(fp + 84) + 56) == 0) func_00302e10(*(u8**)(fp + 84));
    return func_002ffd78(*(u8**)(fp + 84), fp, fmt, ap);
}

struct FPN { s32 cls; s32 sign; s32 exp; u64 frac; };
union FLO { double v; u64 u; };

// Soft-float double subtract: a + (-b).
double func_00313ed8(double a, double b) {
    FPN x, y, t;
    FLO au, bu;
    au.v = a;
    bu.v = b;
    func_003147a0(&au, &x);
    func_003147a0(&bu, &y);
    y.sign ^= 1;
    return func_003146c8(func_00313c58(&x, &y, &t));
}
}
