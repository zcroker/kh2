#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {
void* func_00170b30(u32);
void* func_00106178(void*, u32);
void func_001091c8(void*, u32, u32);
extern void* D_0032bb1c;

// Allocates a heap of `size` bytes and installs it.
void func_00105370(u32 size, u32 a1) {
    void* h = func_00106178(func_00170b30(size), size);
    D_0032bb1c = h;
    func_001091c8(h, 256, a1);
}

f32 func_001142e0(u8* p, s32 i, u8 a, u8 b) {
    if (a) {
        if (b) return *(f32*)(*(u8**)(p + 8) + i * 8 + 32);
        return *(f32*)(*(u8**)(p + 8) + i * 8 + 64);
    }
    return *(f32*)(*(u8**)(p + 8) + i * 8);
}

extern u32 D_00348804;
u8 func_001652c8(u32, u32, u32, u32, u32, u32, u32, u32);
u32 func_00143470(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    return func_001652c8(D_00348804, a, b, c, d, e, f, g);
}

extern u8 D_00349f00[];
void* func_0014e648(void*);
void func_0014dd60(void*, u8, u8, u8);
void func_0014e140(u8 a, u8 b, u8 c) {
    func_0014dd60(func_0014e648(D_00349f00), a, b, c);
}

extern Q16 D_0034aa50[2];
Q16* func_0016c028(u32);
void func_00159ef8(u8* p) {
    Q16* src = (Q16*)(p + 128);
    Q16* v = func_0016c028(*(u32*)(p + 68));
    Q16* d = D_0034aa50;
    if (d != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(src) : "$8", "memory");
    d++;
    if (v != d) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(v) : "$8", "memory");
}

// Scales the base colour at +420 by (r, g, b)/128 into +680.
void func_00160488(u8* p, u8 r, u8 g, u8 b) {
    u8 out[3];
    u8* c = p + 420;
    out[0] = (r * c[0]) >> 7;
    out[1] = (g * c[1]) >> 7;
    out[2] = (b * c[2]) >> 7;
    p[680] = out[0];
    p[681] = out[1];
    p[682] = out[2];
}

// Plane test: d = dot(a.xyz, b.xyz) + b.w -> *out; 1 when 0 <= d <= a[4].
s32 func_00162b18(f32* a, f32* b, f32* out) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    d += b[3];
    *out = d;
    if (a[4] < d) return 0;
    if (d < 0.0f) return 0;
    return 1;
}

void func_0017d050(void*, u32);
extern u8 D_004f62a0[];
void func_0016dad8(u8* p) {
    u8 tmp[16] __attribute__((aligned(16)));
    func_0017d050(tmp, *(u32*)p);
    u8* d = D_004f62a0;
    if (d != tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(tmp) : "$8", "memory");
    *(u8**)p = d;
}

u32 func_00180378(u32, u32, u32, f32);
void func_00172440(u8* p) {
    *(u32*)p = func_00180378(*(u32*)(*(u8**)p + 4) + 320, *(u32*)(*(u8**)(p + 4) + 4), *(u32*)(p + 8), *(f32*)(p + 12));
}

s32 func_00181500(s32);
s32 func_001819c0(void) {
    s32 r = 0;
    if (func_00181500(2071) == 0 || func_00181500(5163) != 0 || func_00181500(8193) != 0) r = 1;
    return r;
}

void func_0016af58(void*, u32);
s32 func_001860b0(u32 a, f32* b) {
    f32 tmp[4] __attribute__((aligned(16)));
    f32 d;
    func_0016af58(tmp, a);
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(tmp), "r"(b) : "$8", "memory");
    return d < 0.0f;
}

// Puts an ability (15-bit id + enabled bit) into the first free slot of the 80-entry list.
struct AbilitySlot { u16 id : 15; u16 on : 1; };
void partram_add_ability(u8* self, s32 id, u8 on) asm("_ZN2YS7PARTRAM11add_abilityEib");
void partram_add_ability(u8* self, s32 id, u8 on) {
    AbilitySlot* a = (AbilitySlot*)(self + 80);
    for (s32 i = 0; i < 80; i++) {
        if (a[i + 2].id == 0) {
            AbilitySlot x;
            x.id = id;
            x.on = on != 0;
            a[i + 2] = x;
            return;
        }
    }
}

struct S24 { u32 w[6]; };
void func_00192868(u32, u32, S24);
void func_00192940(u32 a, u32 b, S24 s) {
    func_00192868(a, b, s);
}

struct E56 { u32 a, b; u16* p; u8 pad[44]; };
extern s32 D_00350440;
extern E56 D_01c62198[];
u32 ctarget_0019b260(u32 id, u32, u32, u32) asm("_Z16ctarget_0019b260jjjj");
u32 ctarget_0019b260(u32 id, u32, u32, u32) {
    for (s32 i = 0; i < D_00350440; i++) {
        E56* e = &D_01c62198[i];
        if (e->p[1] == id) return (u32)e;
    }
    return 0;
}

// Adds n to a counter capped at 100, and to two halfword totals.
void func_001a2668(u8* p, s32 n) {
    u8* q = *(u8**)(p + 580);
    if (q) {
        if (q[8] + n > 100) n = 100 - q[8];
        q[8] += n;
    }
    *(u16*)(p + 398) += n;
    *(u16*)(p + 406) += n;
}

s32 func_001a8f10(s32 x) {
    switch (x) {
    case 1: case 14: return 0;
    case 2: return 1;
    case 3: return 2;
    }
    return 3;
}

void func_001ac378(void*, u32, u32, u32, u32, u32, u32);
void func_001aa668(void*, void*);
extern u8 D_00350bf0[];
void func_001ac8b0(u8* p, u32 a1) {
    func_001ac378(p, 4, 3, a1, 0, 256, 365);
    *(u32*)(p + 100) = 4;
    *(void**)p = D_00350bf0;
    func_001aa668(p + 12, p);
}

u32 func_001b1400(void*);
void func_00168328(void*, u32);
u32 func_001b1490(void* p) {
    u32 v = func_001b1400(p);
    if (v) func_00168328(p, v);
    return v;
}

void func_001bc720(u8*);
void func_001bc730(u8* p, s32 i) {
    if (i < *(s32*)(p + 8)) {
        *(s32*)(p + 108) = i;
        *(u32*)(p + 112) = *(u16*)(i * 12 + (u32)p + 14);
    } else {
        func_001bc720(p);
    }
}

// Pops the stack pointer at +2240 (clearing the top slot).
void func_002ba2e8(u32, u32);
void func_001bd618(u8* p, u8 flag) {
    void** sp = (void**)(p + 2240);
    *(void**)*sp = 0;
    if (*sp == (void*)(p + 2536)) *sp = 0;
    else *sp = (u8*)*sp - 4;
    if (flag) func_002ba2e8(4, 0);
}

void func_00177dc8(void*, u32, u32, u32, u32);
void func_001d56f0(void*);
extern u8 D_003521e0[];
void func_001ced68(u8* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 0, a2, a3);
    *(u32*)(p + 2920) = 0;
    *(u32*)(p + 2928) = 0;
    *(void**)p = D_003521e0;
    func_001d56f0(p + 2932);
    *(u32*)(p + 1420) |= 4;
}

void func_001d2110(void*, s32);
void func_001d2248(void*, s32);
void func_001d2130(u8* p, s32 n, f32 f) {
    func_001d2110(p, *(s32*)(p + 44) + n);
    func_001d2248(p, *(s32*)(p + 44));
    *(f32*)(p + 60) = f;
}

// "Assertion failed: %s\n" / "   File %s, Line %u\n" then break.
extern char D_0036e978[];
extern char D_0036e9c0[];
extern char D_0036e9d0[];
extern char D_0036e998[];
u32 func_002fdfc8(const char*, ...);
static inline void assert_fail_1e2c00(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break");
}
u8 func_001e7cc0(void*);
u8 func_001e2c00(void* pMng) {
    if (!pMng) assert_fail_1e2c00(D_0036e9c0, D_0036e9d0, 357);
    return func_001e7cc0(pMng);
}

u8 func_00209178(void*, void*);
void func_002092e0(u8* a, u32* b, u8* c) {
    u8* t = a + *(s32*)(*(u8**)(c + 12) + 8) + 160;
    if (*b == *(u32*)(a + 12)) {
        struct NoTail { ~NoTail() {} } g; // keeps the call a jal
        func_00209178(b, t);
    }
}

extern u32 D_0035dae4;
u32 func_00227818(u32);
u32 func_00225eb8(u32, u32, u32);
u32 func_00227858(u32, u32, u32);
u32 func_00225640(u32 a, u32 b, u32 c) {
    return func_00227858(func_00225eb8(D_0035dae4, func_00227818(a), c), b, c);
}

extern char D_01dad938[];
extern char D_00371138[];
extern u32 D_0033caf4;
void func_002fee78(char*, const char*, ...);
void func_002ff3fc(char*);
char* func_0022b7f0(void) {
    func_002fee78(D_01dad938, D_00371138, D_0033caf4);
    func_002ff3fc(D_01dad938);
    return D_01dad938;
}

// Appends a type-9 record to the 64-entry ring buffer; returns its serial.
struct REnt { u32 type, id, a, b, c, d; u32 pad[2]; };
extern s32 D_0035e360;
extern u32 D_0035e368;
extern REnt D_01dadc00[];
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002343a8jjjj");
u32 wtarget_002343a8(u32 a, u32 b, u32 c, u32 d) {
    s32 i = D_0035e360;
    u32 id = D_0035e368;
    REnt* e = &D_01dadc00[i];
    e->type = 9;
    e->a = a;
    e->b = b;
    e->c = c;
    e->id = id;
    e->d = d;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

extern u8* D_0035ec90;
void func_00242408(void);
void func_00242418(void*, u32);
void func_002409b8(u8* p) {
    if (!p) p = D_0035ec90;
    func_00242408();
    func_00242418(p, 8);
    func_00242418(p + 12, 0x10fb4);
}

struct BF242 { u32 lo : 8; u32 f : 1; u32 hi : 23; };
struct X242 { u32 a; BF242 b; };
u8* func_001058e8(void);
void func_00242d80(u8 f) {
    X242* x = (X242*)(func_001058e8() + 16800);
    x->b.f = f != 0;
}

extern char D_01e2bba0[];
extern char D_00374fa8[];
char* func_002bd260(u32 a) {
    func_002fee78(D_01e2bba0, D_00374fa8, a);
    func_002ff3fc(D_01e2bba0);
    return D_01e2bba0;
}

extern u8 D_00361980[];
extern u8 D_003637e0[];
typedef void (*VFn)(void*);
void func_002bee58(u8* p) {
    *(u8**)p = D_00361980;
    u8* o = *(u8**)(p + 36);
    (*(VFn*)((*(u8**)o) + 12))(o);
    *(u8**)p = D_003637e0;
}

void func_00143e50(void*, u16, u32);
void func_00186a90(void*, void*, f32);
void func_002c5ff8(u8* p, u32 a) {
    f32 tmp[4] __attribute__((aligned(16)));
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 32) : "memory");
    func_00143e50(tmp, a, 0);
    func_00186a90(p, tmp, 1000.0f);
}

extern u8 D_003629e8[];
void func_002e4a90(void*);
void func_002cea28(void*);
void func_00105110(void*);
void func_002dc788(u8* p) {
    *(void**)p = D_003629e8;
    func_002e4a90(p + 256);
    func_002cea28(p);
    func_00105110(p);
}

void func_00108398(void*);
void func_002e5f70(u8* p) {
    func_00108398(p + 16);
    func_00108398(p + 288);
    *(u32*)(p + 544) = 0;
    *(u32*)(p + 548) = 0;
    *(u32*)(p + 552) = 0;
    *(u32*)(p + 556) = 0;
    *(u64*)(p + 560) = 0;
}

void func_001c1748(void*, u32, u32, u32);
void func_00190128(void*);
void func_002ed558(u8* p, u8* q, u32 a2, u32 a3, u32 a4) {
    func_001c1748(p, *(u32*)(q + 2548), a3, a4);
    *(u32*)(p + 80) = a2;
    func_00190128(p + 100);
    *(u32*)(p + 120) = 0;
}

void func_00103bb0(u32);
void func_00103590(u32, void*);
extern void* D_003638c4;
extern u8 D_003638c0;
extern u8 D_003638c8;
void func_002ef6b0(void) {
    func_00103bb0(5);
    void* h = func_00106178(func_00170b30(0xa0000), 0xa0000);
    D_003638c4 = h;
    func_00103590(1, h);
    D_003638c0 = 0;
    D_003638c8 = 0;
}

extern u32 D_00363c20;
extern u32 D_00363c24;
extern u32 D_01e2c0d0;
u32 func_001708f8(u32, s32);
u8* func_00168b38(u32, u32, u32);
void func_002f1808(void) {
    u32 v = func_001708f8(D_00363c20, -1);
    D_01e2c0d0 = v;
    D_00363c24 = *(u32*)(func_00168b38(v, 2, 0) + 8);
}

extern u8 D_0034a800[];
extern u8 D_00347e60[];
extern void* D_00347f98[];
void func_002361d0(void*);
void func_00239870(void*);
void func_0031cec0(u8* p) {
    *(void**)p = D_0034a800;
    func_002361d0(p + 416);
    *(void**)p = D_00347e60;
    func_00239870(p + 24);
    *(void***)p = D_00347f98;
}

extern void*** D_00347f80;
typedef void (*VFn2)(void*, void*);
void func_00322e18(u8* p) {
    *(void***)p = D_00347f98;
    void** o = (void**)D_00347f80[5];
    ((VFn2)((void**)*o)[1])(o, p);
}

extern u8 D_00363880[];
void func_0023c098(void*);
void func_002369f0(void*);
void func_00325aa0(u8* p) {
    *(void**)p = D_00363880;
    func_0023c098(p + 64);
    func_002369f0(p + 40);
    *(void**)p = D_003637e0;
}
}

// Sets bit `i` in the bitset returned by func_002859a0 (if not already set).
extern "C" u32* func_002859a0(void);
void func_00285f50(void* a) {
    u32 i = (u32)a;
    u32* bits = func_002859a0();
    u32* w = (u32*)((i >> 5) * 4 + (u32)bits);
    u32 m = 1 << (i & 31);
    if (!(*w & m)) *w |= m;
}
