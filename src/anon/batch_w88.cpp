#include "../common/types.h"

// 16-byte aligned vector / matrix used with VU0 macro code.
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
// A local of this type disables sibling calls (keeps jal + epilogue).
struct NoTail { ~NoTail() {} };

static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VAssign(V4* d, V4* s) {
    if (d != s) QCOPY(d, s);
}
static inline void ApplyM(V4* d, M4* m, V4* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void ApplyTo(V4* d, M4* m, V4* v) {
    V4 t;
    ApplyM(&t, m, v);
    VAssign(d, &t);
}

u32 wtarget_00105620(u32, u32, u32, u32) asm("_Z16wtarget_00105620jjjj");
void wtarget_0017a7e0(u32, u32, u32, u32) asm("_Z16wtarget_0017a7e0jjjj");
void u_tail0_001917d0(void) asm("_Z16u_tail0_001917d0v");

extern "C" {
// --- callees
void func_00190128(void*);
s32 func_00168aa0(u32, u32);
u8* func_00168b38(u32, u32, s32);
void func_0031ae58(void*, void*);
u32 func_001050c8(void);
u8* func_001063c0(u32, u32);
void func_00239700(u8*);
u32 func_0013e678(void);
void func_0015b368(u8*, u32, u32, u32);
void func_001391a8(u8*, V4*);
void func_0014f648(u32);
void func_001bcf80(u8*);
void func_0019c920(u8*);
void func_0031e2b8(u8*);
void func_0019c9a8(u8*);
void func_001d48b0(u8*);
s32 func_00132f98(void*, u32, u32*, u32, u32);
s32 func_001d7ba8(u8*);
s32 func_00105300(void);
s32 func_001c8db8(u8*, u32);
void func_00191cd8(void);
s32 func_001918c8(void);
void func_00191938(s32);
void func_001a3710(void);
void func_0019ba60(u32);
s32 func_001a1c30(u8*);
void func_001d6f28(s32);
void func_001c11a8(u32);
void func_0014c9f0(u32);
void func_00239870(u8*);
void func_0031e668(u8*);
void func_001ac5b8(u8*);
void func_001bd988(u32);
u32 func_0016ac38(u8*, u32, u32, u32, u32);
void func_001dc840(u32);
void func_001940f0(u8*, u32);
void func_00194108(u8*, u32);
s32 func_002282f0(u16);
u8* func_00227d10(s16);
f32 func_00227c78(u8*);
u32 func_00227ca8(u8*);
u32 func_0016f000(u32, V4*, f32);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
s32 func_00240440(u32);
u32 func_001058e8(void);
void func_002fdd68(void*, u32, u32);
u8 func_00241e18(void);
u32 func_00241ed8(u8);
u32 func_002409b8(u8*);
s32 func_00139d78(u32);
s32 func_0023f0c0(u32);
void func_0023f070(u32, s32, s32);
s32 func_0028acc8(u32);
void func_0028ab20(u32);
u32 func_002891e8(u32);
u8* func_0024e008(u32);
void func_0028da70(u32, u32);
s32 func_001a6d08(u32);
void func_0028d980(u32, u32, u32, u32, u32, u32, u32, s32, u32);
void func_00139620(u32);
void func_001395f8(u32);
void func_002fde18(u32, u32, u32);
void func_0024e228(void);
void func_00106420(void*);
void func_0031abd8(u8*);
void func_0031acc0(u8*);
void func_0031a840(u8*);
void func_002361d0(u8*);
s32 func_001396c0(u8*);
s32 func_0028acc8p(u8*) asm("func_0028acc8");
s32 func_00239d30i(u8*, u32) asm("func_00239d30");
void func_00290d68(u32, u32);
void func_00290f78(u32);
u32 func_00291380(u32, u32);
void func_00291510(u32, u32, u32, u32);
void func_00291918(u32, u32, u32, u32, u32);
void func_00291de0(u32, u32, u32, u32, u32, u32, u32);
s32 func_00287cd0(void);
s32 func_00289310(u32);
void func_002890e0(u32, u32, u32, u32, s32);
void func_00289038(u32, u32, u32, u32, u32, u32, s32);
s32 func_00289358(u32);
void func_002b5c30(u32);
s32 func_0028d008(u32);
u32 func_002891d0(u32);
void func_0028cf28(u32, u32);
u32 func_001708f8(u32, s32);
u32 func_002ca3d0(u8*, u32);
void func_0023eea0(u8*, u32, u32, u32, u32, u32);
void func_0023ef50(u8*);
void func_0023f0c8(u8*, u32);
void func_002ca828(u8*);
void func_001391c8(u8*, u32, u32);
void func_0031c9f8(u8*);
void func_0031c980(u8*);
void func_0031c8e8(u8*);
void func_0031cec0(u8*);

// --- data
struct E13a6f8 { u32 x, y; };
struct T13a6f8 { u32 data; s32 count; E13a6f8 e[1]; };
extern T13a6f8 D_00347fb0;
extern u8 D_003b8bc0[];
extern u8 D_00347fd8[];
extern u8 D_004193c0[];
extern u8* D_004f35a0;
extern u8 D_00347e60[];
extern u8 D_0034ab80[];
extern u8 D_01c5f530[];
extern u8 D_00351260[];
extern u8 D_00351228[];
extern u8 D_00351ec8[];
extern s32 D_01c61958;
extern f32 D_01c6195c;
extern f32 D_01c61960;
extern f32 D_00349e10;
extern u8 D_00350a70[];
extern u8 D_00350ab0[];
extern u8 D_00350bb0[];
extern u8 D_00350a56;
extern u64 D_0036dc48[];
struct S84 { u32 w[21]; };
struct B240 { u64 lo : 32; u64 b : 8; u64 f : 1; u64 rest : 23; };
extern u8* D_0035ec90;
extern S84 D_0035ec30;
extern u32 D_0035edd4;
extern u32 D_0035edcc;
extern u32 D_0035eddc;
extern u32 D_0035edd8;
extern u32 D_0035ede0;
extern u32 D_0035ede4;
extern u32 D_0035edf8;
extern u8* D_0035f2b0;
extern u8* D_0035f2b4;
extern u8* D_0035f2b8;
extern u32 D_0035f64c;
extern u8 D_0034a700[];
extern u8 D_00347f98[];
extern u8 D_0034a848[];
extern u8 D_00348608[];
extern u32 D_00347f80;

typedef void (*Dtor)(u8*);

s32 func_00133078(void* a, u32* tab, u32, u32 n, u32 x) {
    u32* out = tab + n * 2;
    s32 total = 0;
    for (u32 i = 0; i < n; i++) {
        u32 buf[8];
        s32 c = func_00132f98(a, i, buf, 8, x);
        u32* t = &tab[i * 2];
        t[0] = c;
        t[1] = (n * 2 + total) * 4;
        total += c;
        for (s32 k = 0; k < c; k++) *out++ = buf[k];
    }
    return total;
}

void func_0013a6f8(void) {
    D_00347fb0.data = (u32)D_003b8bc0;
    D_00347fb0.count = func_00168aa0((u32)D_003b8bc0, 25);
    for (s32 i = 0; i < D_00347fb0.count; i++) {
        D_00347fb0.e[i].y = *(u32*)(func_00168b38(D_00347fb0.data, 25, i) + 8);
        if (func_00168b38(D_00347fb0.data, 24, 0))
            D_00347fb0.e[i].x = *(u32*)(func_00168b38(D_00347fb0.data, 24, i) + 8);
        else
            D_00347fb0.e[i].x = 0;
    }
    func_0031ae58(D_00347fd8, D_004193c0);
}

void func_001589d0(u8* p) {
    M4* m = (M4*)(D_004f35a0 + 64);
    ApplyTo((V4*)(p + 96), m, (V4*)(D_004f35a0 + 2928));
    ApplyTo((V4*)(p + 128), m, (V4*)(D_004f35a0 + 2944));
    VAssign((V4*)(p + 16), (V4*)(p + 96));
    VAssign((V4*)p, (V4*)(p + 128));
}

void func_0015b680(V4* pos, u32 a, u32 b) {
    u8* o = func_001063c0(2880, func_001050c8());
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e60;
    func_00239700(o + 24);
    *(u32*)(o + 432) = 0;
    *(u32*)o = (u32)D_0034ab80;
    u8* q = o + 440;
    for (s32 i = 6; i != -1; i--, q += 344) func_00239700(q);
    func_0015b368(o, 16, func_0013e678(), a);
    V4 t;
    QCOPY(&t, pos);
    func_001391a8(o, &t);
    func_0014f648(b);
}

static inline bool Bit187920(u32 x, u32 m) { return (x & m) != 0; }
// Nonzero when any blocking flag/condition is set.
s32 func_00187920(u8* p) {
    s32 r = 0;
    if (Bit187920(*(u32*)(p + 264), 0x100) || Bit187920(*(u32*)(p + 352), 0x400000) || func_001d7ba8(p + 1304) ||
        Bit187920(*(u32*)(p + 264), 0x10000000) || Bit187920(*(u32*)(p + 264), 0x80000) || Bit187920(*(u32*)(p + 2040), 0x10) ||
        Bit187920(*(u32*)(p + 2040), 0x200) || func_00105300() || func_001c8db8(D_00351ec8, 0))
        r = 1;
    return r;
}

void func_001a1b68(u8* p, f32 d) {
    func_0019ba60(*(u32*)(p + 604));
    s32 m = *(s32*)(*(u8**)(p + 604) + 2896);
    bool neg = m == 6;
    if (neg) {
        if (0.0f < d) d = -d;
    }
    s32 a = func_001a1c30(p);
    f32 v = *(f32*)(p + 436) + d;
    f32 r;
    if (v < 0.0f) r = 0.0f;
    else if (*(f32*)(p + 440) < v) r = *(f32*)(p + 440);
    else r = v;
    *(f32*)(p + 436) = r;
    if (p[431] == 3) func_001d6f28(a - func_001a1c30(p));
}

void func_001ad738(u8* o) {
    NoTail g;
    *(u32*)o = (u32)D_00350a70;
    D_00350a56 = 0;
    func_001c11a8(12);
    func_0014c9f0(8);
    *(u32*)o = (u32)D_00350ab0;
    if (o + 3280 != 0) {
        u8* e = o + 4656;
    l1:
        if (o + 3280 != e) { e -= 344; (**(Dtor**)e)(e); goto l1; }
    }
    func_00239870(o + 2936);
    *(u32*)o = (u32)D_00350bb0;
    if (o + 1544 != 0) {
        u8* e = o + 2920;
    l2:
        if (o + 1544 != e) { e -= 344; (**(Dtor**)e)(e); goto l2; }
    }
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    func_0031e668(o + 132);
    func_001ac5b8(o);
}

struct E1bcc28 { u16 pad; u16 id; u8 pad2[2]; u8 kind; u8 pad3[5]; };
struct T1bcc28 { u32 pad; u32 owner; s32 n; E1bcc28 e[8]; s32 sel; };
void func_001bcc28(T1bcc28* p) {
    u32 t1 = p->owner;
    s32 n = p->n;
    u32 a3 = *(u32*)(t1 + 2532);
    p->sel = -1;
    for (s32 i = 0; i < n; i++) {
        if (*(u64*)(a3 + 8) & D_0036dc48[p->e[i].kind - 1]) { p->sel = i; break; }
    }
    s32 idx = p->sel;
    if (idx >= 0) {
        E1bcc28* e = p->e;
        u16 v = e[idx].id;
        if (v != 0) {
            if (v == 454) { *(u32*)(t1 + 8) |= 2; return; }
            func_001bd988(p->owner);
            return;
        }
    }
    u64 fl = *(u64*)(a3 + 8);
    if (fl & 0x100) *(u32*)(t1 + 8) |= 2;
    else if (fl & 0x200) *(u32*)(t1 + 8) |= 8;
}

union U1c1a30 { f32 f; u8* p; u8 b; };
void func_001c1a30(u8* p, U1c1a30** out) {
    *(U1c1a30**)(p + 32) = *out;
    switch (*(s32*)(*(u8**)(p + 28) + 4)) {
    case 0:
        (*out)[0].f = *(f32*)(p + 0);
        (*out)[1].f = *(f32*)(p + 4);
        (*out)[2].f = *(f32*)(p + 8);
        ((u8*)*out)[12] = p[20];
        ((u8*)*out)[13] = p[21];
        ((u8*)*out)[14] = p[22];
        ((u8*)*out)[15] = p[23];
        *out += 4;
        break;
    case 1:
        (*out)[0].f = *(f32*)(p + 0);
        (*out)[1].f = *(f32*)(p + 4);
        (*out)[2].f = *(f32*)(p + 8);
        ((u8*)*out)[12] = p[21];
        ((u8*)*out)[13] = p[23];
        ((u8*)*out)[14] = p[24];
        ((u8*)*out)[15] = p[22];
        *out += 4;
        break;
    }
}

void func_001cf9e0(u8* p, s32 mode) {
    switch (mode) {
    case 0:
        if (!*(u32*)(p + 2976)) *(u32*)(p + 2976) = func_0016ac38(p, 12, 1, 0, 0);
        if (*(u32*)(p + 2980)) { func_001dc840(*(u32*)(p + 2980)); *(u32*)(p + 2980) = 0; }
        func_001940f0(p, 2);
        func_00194108(p, 1);
        break;
    case 1:
        if (!*(u32*)(p + 2980)) *(u32*)(p + 2980) = func_0016ac38(p, 13, 1, 0, 0);
        if (*(u32*)(p + 2976)) { func_001dc840(*(u32*)(p + 2976)); *(u32*)(p + 2976) = 0; }
        func_001940f0(p, 1);
        func_00194108(p, 2);
        break;
    }
}

typedef void (*VF233490)(u8*, V4*, u32);
void func_00233490(u8* p) {
    if (func_002282f0(*(u16*)(p + 4))) return;
    u8* o = func_00227d10(*(s16*)(p + 6));
    if (*(u32*)(o + 8)) return;
    V4 a, b;
    a.x = func_00227c78(p + 8);
    a.y = func_00227c78(p + 12);
    a.z = func_00227c78(p + 16);
    *(u32*)(o + 8) = func_0016f000(*(u32*)o | 0x40000000, &a, func_00227c78(p + 36) * 0.017453292f);
    b.x = func_00227c78(p + 24);
    b.y = func_00227c78(p + 28);
    b.z = func_00227c78(p + 32);
    u32 r = func_00227ca8(p + 20);
    u8* q = *(u8**)(o + 8);
    (*(VF233490*)(*(u8**)q + 88))(q, &b, r);
}

void func_00237988(u8* p, f32 z) {
    *(f32*)(p + 120) = z;
    f32 a = func_002f8960(*(f32*)(p + 112));
    f32 b = func_002f87c0(*(f32*)(p + 112));
    f32 c = func_002f8960(*(f32*)(p + 116));
    f32 d = func_002f87c0(*(f32*)(p + 116));
    f32 e = func_002f8960(*(f32*)(p + 120));
    f32 f = func_002f87c0(*(f32*)(p + 120));
    f32 ac = a * c;
    *(f32*)(p + 28) = d * f;
    *(f32*)(p + 32) = d * -e;
    *(f32*)(p + 36) = ac * f + b * e;
    *(f32*)(p + 40) = ac * -e + b * f;
}

s32 func_002408d0(u32 mode) {
    s32 b = 0;
    s32 a = 0;
    if (mode < 2) {
        a = func_00240440(964);
        a += func_00240440(0x8a58);
        a += func_00240440(0x10fc0);
        a = (a + 8) / 5 * 5;
    }
    if (mode == 0 || mode == 2) {
        b = func_00240440(964);
        b += func_00240440(0x8a58);
        b += func_00240440(1024);
        b = (b + 8) / 5 * 5;
    }
    a += b;
    return a;
}

void func_00240a70(u8* p) {
    if (!p) p = D_0035ec90;
    func_002fdd68(p, func_001058e8(), 0x10fc0);
    p[16796] = func_00241e18();
    ((B240*)(p + 16792))->f = func_00241ed8(p[12]) != 0;
    *(S84*)(p + 9284) = D_0035ec30;
    *(u32*)(p + 8) = func_002409b8(p);
}

#define SETANIM(o, id) if (func_00139d78(o)) { if (func_0023f0c0(o) != (id)) func_0023f070(o, id, -1); }
void func_0024d4a0(void) {
    SETANIM(D_0035edd4, 32);
    if (func_0028acc8(D_0035edcc)) {
        func_0028ab20(D_0035edcc);
        u8* s = func_0024e008(func_002891e8(D_0035edcc));
        SETANIM(D_0035eddc, *(s16*)(s + 4));
    }
    SETANIM(D_0035edd8, 35);
    func_0028da70(D_0035ede0, 33);
    func_0028da70(D_0035ede4, 41);
}

static inline void Or8(u8* o) { *(u32*)(o + 184) |= 8; }
void func_0024e158(void) {
    if (!func_001a6d08(7)) return;
    func_0028d980(D_0035ede4, 30011, 0, 0, D_0035edd4, 39, 41, -1, 0);
    func_00139620(D_0035ede4);
    func_001395f8(D_0035ede4);
    *(u32*)(D_0035ede4 + 432) = 2;
    *(u8*)(D_0035ede4 + 405) = 1;
    Or8((u8*)(D_0035ede4 + 24));
    func_002fde18(D_0035edf8, 0, 32);
    *(u32*)(D_0035ede4 + 408) = D_0035edf8;
    func_0024e228();
}

typedef void (*VF2830b8)(u8*);
void func_002830b8(void) {
    if (D_0035f2b0) {
        (*(VF2830b8*)(*(u8**)D_0035f2b0 + 4))(D_0035f2b0);
        D_0035f2b0 = 0;
    }
    if (D_0035f2b4) {
        func_00106420(D_0035f2b4);
        D_0035f2b4 = 0;
    }
    u8* s = D_0035f2b8;
    u8* sub = s + 416;
    if (s) {
        func_0031abd8(s + 1696);
        func_0031abd8(s + 1288);
        func_0031acc0(s + 852);
        *(u32*)sub = (u32)D_00347e60;
        func_00239870(s + 440);
        func_0031a840(sub);
        func_002361d0(s);
        func_00106420(s);
        D_0035f2b8 = 0;
    }
}

s32 func_0028ad50(u8* p) {
    if (!func_0028acc8p(p)) return 0;
    for (s32 i = 0; i < (s16)*(u16*)(p + 4); i++) {
        u8* o = (*(u8***)(p + 40))[i];
        if (!o) continue;
        if (func_001396c0(o)) continue;
        u8* q = (*(u8***)(p + 40))[i] + 24;
        if ((u8)func_00239d30i(q, *(u32*)(q + 276))) continue;
        if (!(*(u8***)(p + 40))[i][404]) return 0;
    }
    return 1;
}

void func_00291110(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    func_00290d68(a, e);
    func_00290f78(a);
    u32 m = (func_00291380(a, c) | func_00291380(a, d)) & ~0x100;
    func_00291510(a, b, c, m);
    func_00291918(a, b, c, d, m);
    func_00291de0(a, b, c, d, f, g, m);
}

void func_002b5b38(u32 a, s32 b, u32 c) {
    if (func_00287cd0() != 1) return;
    if (!func_00289310(a)) return;
    func_002890e0(a, 1, 2, 0, -1);
    func_00289038(a, func_002891e8(a), 1, 1, 2, 0, -1);
    if (b == 12 && func_00289358(D_0035f64c)) func_002b5c30(0);
    if (func_0028d008(c)) func_0028cf28(c, func_002891d0(a));
}

struct T2caa50 { u8 d[32]; };
void func_0023f800(T2caa50*);
void func_0023fa08(T2caa50*, u32);
u32 func_0023f948(T2caa50*, u32);
u32 func_0023f908(T2caa50*, u32);
void func_0023f848(T2caa50*);
void func_002caa50(u8* p, u32 a, u32 b) {
    *(u32*)(p + 640) = b;
    *(u32*)(p + 648) = 0;
    T2caa50 t;
    func_0023f800(&t);
    u32 r = func_001708f8(a, -1);
    *(u32*)(p + 636) = r;
    func_0023fa08(&t, r);
    u32 x = func_0023f948(&t, 0);
    u32 y = func_0023f908(&t, 0);
    func_0023eea0(p + 28, 30001, x, y, func_002ca3d0(p, 0), 0);
    func_0023ef50(p + 28);
    func_0023f0c8(p + 28, func_002ca3d0(p, 2));
    func_002ca828(p);
    func_001391c8(p, 30002, 0);
    func_0023f848(&t);
}

// Class with a vtable: implicit assignment copies every field but the vptr.
struct C2ef258 { virtual void f(); u32 a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14; f32 b, c, d, e; u32 g; u8 h; u32 i, j; };
void func_002ef258(u8* d, C2ef258* s) {
    *(C2ef258*)(d + 64) = *s;
}

static inline void Dtor1cb58a(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 2408;
    l:
        if (self + 8 != e) { e -= 600; func_0031c9f8(e); goto l; }
    }
}
static inline void Dtor1cb58b(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 2408;
    l:
        if (self + 8 != e) { e -= 600; func_0031c980(e); goto l; }
    }
}
static inline void Dtor1cb58c(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 9608;
    l:
        if (self + 8 != e) { e -= 600; func_0031c8e8(e); goto l; }
    }
}
void func_0031cb58(u8* o) {
    *(u32*)o = (u32)D_0034a700;
    Dtor1cb58a(o + 12076);
    Dtor1cb58b(o + 9656);
    Dtor1cb58c(o + 36);
    *(u32*)o = (u32)D_00347f98;
}

typedef void (*VF31d1b8)(u8*, u8*);
void func_0031d1b8(u8* o) {
    *(u32*)o = (u32)D_0034a848;
    if (o + 2576 != 0) {
        u8* e = o + 5536;
    l1:
        if (o + 2576 != e) { e -= 592; (*(Dtor*)(*(u8**)e + 12))(e); goto l1; }
    }
    if (o + 916 != 0) {
        u8* e = o + 2564;
    l2:
        if (o + 916 != e) { e -= 412; (*(Dtor*)(*(u8**)e + 12))(e); goto l2; }
    }
    *(u32*)o = (u32)D_00348608;
    func_0031cec0(o + 64);
    *(u32*)o = (u32)D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VF31d1b8*)(*(u8**)m + 4))(m, o);
}

struct E19ad58 { u8 pad[12]; u32 obj; u8 pad2[24]; u8 kind; u8 pad3; u16 id; u8 pad4[16]; u8 lv; u8 pad5[3]; };
struct T19ad58 { u8 pad[4]; u16 n; u8 pad2[26]; E19ad58 e[1]; };
s32 func_0019ac30(u8*, u16);
u8* func_0016e920(u32);
// The table pointer is re-read from p+8 on every access.
#define TAB19ad58 (*(T19ad58**)(p + 8))
s32 func_0019ad58(u8* p) {
    s32 sum = 0;
    for (s32 i = 0; i < TAB19ad58->n; i++) {
        switch (TAB19ad58->e[i].kind) {
        case 2:
            if (p[32] < TAB19ad58->e[i].lv) continue;
            break;
        case 0:
        case 3:
            break;
        default:
            continue;
        }
        if (!func_0019ac30(p, TAB19ad58->e[i].id)) sum += *(u8*)(func_0016e920(TAB19ad58->e[i].obj) + 84);
    }
    return sum;
}

struct E1ce0a8 { u8 a; u8 b; s8 link; u8 c; u8 pad[4]; u16 id; u8 rest[58]; };
struct T1ce0a8 { s32 n; E1ce0a8 e[1]; };
s32 func_001d7f40(T1ce0a8*, s32);
static inline u32 Bit1ce0a8(u32* b, u32 i) { return b[i >> 5] & (1 << (i & 31)); }
#define TAB1ce0a8 (*(T1ce0a8**)(p + 68))
E1ce0a8* func_001ce0a8(u8* p) {
    E1ce0a8* r = 0;
    for (s32 i = 0; i < TAB1ce0a8->n; i++) {
        if (Bit1ce0a8((u32*)(p + 96), i)) {
            if (TAB1ce0a8->e[i].link == TAB1ce0a8->e[i].a || TAB1ce0a8->e[i].id != *(u32*)(*(u8**)(p + 64) + 340)) return &TAB1ce0a8->e[i];
            if (!r && TAB1ce0a8->e[i].link >= 0) r = &TAB1ce0a8->e[func_001d7f40(TAB1ce0a8, TAB1ce0a8->e[i].link)];
        }
    }
    return r;
}

extern char D_00374470[];
u8* func_00192cc0(u8*, const char*);
s32 func_00192b30(u8*);
s32 func_00105c30(void);
// Fill dst with n copies of a formatted string (5 unless mode 1/8); the last copy keeps its NUL.
u8* func_0028def0(u8* dst, s32 n) {
    u8 buf[16];
    u8* q = dst;
    s32 ok = 0;
    s32 len = func_00192b30(func_00192cc0(buf, D_00374470));
    if (func_00105c30() == 1 || func_00105c30() == 8) ok = 1;
    if (!ok) n = 5;
    for (s32 i = 0; i < n; i++) {
        if (i + 1 >= n) len++;
        func_002fdd68(q, (u32)buf, len);
        q += len;
    }
    return dst;
}

// Relocate a node tree in place: type -1 = group of child offsets (recursed),
// type 0 = table whose entry pointers (+116) are rebased from base to p.
u8* func_00131f48(u8* p, u32 base) {
    s16 t = *(s16*)p;
    if (t != -1) {
        if (t == 0) {
            u8* e = p + *(s32*)(p + 20);
            for (s32 i = 0; i <= *(s32*)(p + 8); i++, e += 144)
                *(u32*)(e + 116) = (u32)p + (*(u32*)(e + 116) - base);
        }
    } else {
        u32* q = (u32*)(p + 8);
        for (u32 i = 0; i < *(u32*)(p + 4); i++) {
            u32 off = *q++;
            u32 nb = base + off;
            func_00131f48(p + off, nb);
        }
    }
    return p;
}

struct F1213c0 { u8 st : 2; u8 rest : 6; };
struct EA1213c0 { u32 lo : 6; u32 kind : 5; u32 hi : 21; u8 pad[28]; };
struct EB1213c0 { u32 kind : 5; u32 hi : 27; u8 pad[28]; };
struct TA1213c0 { u8 pad[28]; s32 n; EA1213c0 e[1]; };
struct TB1213c0 { u8 pad[28]; s32 n; EB1213c0 e[1]; };
TB1213c0* func_00120800(u8*);
// Mark every entry of the given kind (-1 = all) in both tables as state 1.
void func_001213c0(u8* p, F1213c0* fl, s32 kind) {
    TA1213c0* t = *(TA1213c0**)(p + 4);
    TB1213c0* b = func_00120800(p);
    for (s32 i = 0; i < t->n; i++) {
        if (kind == -1 || t->e[i].kind == kind) fl[i].st = 1;
    }
    if (b) {
        for (s32 i = 0; i < b->n; i++) {
            if (kind == -1 || b->e[i].kind == kind) fl[t->n + i].st = 1;
        }
    }
}

} // extern "C"

u32 wtarget_00105620(u32 a, u32 b, u32, u32) {
    register u32 save asm("$4") = a;
    register u32 load asm("$5") = b;
    asm volatile(
        "sq $28, 0(%0)\n\tsq $29, 16(%0)\n\tsq $30, 32(%0)\n\tsq $31, 48(%0)\n\t"
        "sq $16, 64(%0)\n\tsq $17, 80(%0)\n\tsq $18, 96(%0)\n\tsq $19, 112(%0)\n\t"
        "sq $20, 128(%0)\n\tsq $21, 144(%0)\n\tsq $22, 160(%0)\n\tsq $23, 176(%0)\n\t"
        "swc1 $f20, 192(%0)\n\tswc1 $f21, 196(%0)\n\tswc1 $f22, 200(%0)\n\tswc1 $f23, 204(%0)\n\t"
        "swc1 $f24, 208(%0)\n\tswc1 $f25, 212(%0)\n\tswc1 $f26, 216(%0)\n\tswc1 $f27, 220(%0)\n\t"
        "swc1 $f28, 224(%0)\n\tswc1 $f29, 228(%0)\n\tswc1 $f30, 232(%0)\n\tswc1 $f31, 236(%0)\n\t"
        "lq $28, 0(%1)\n\tlq $29, 16(%1)\n\tlq $30, 32(%1)\n\tlq $31, 48(%1)\n\t"
        "lq $16, 64(%1)\n\tlq $17, 80(%1)\n\tlq $18, 96(%1)\n\tlq $19, 112(%1)\n\t"
        "lq $20, 128(%1)\n\tlq $21, 144(%1)\n\tlq $22, 160(%1)\n\tlq $23, 176(%1)\n\t"
        "lwc1 $f20, 192(%1)\n\tlwc1 $f21, 196(%1)\n\tlwc1 $f22, 200(%1)\n\tlwc1 $f23, 204(%1)\n\t"
        "lwc1 $f24, 208(%1)\n\tlwc1 $f25, 212(%1)\n\tlwc1 $f26, 216(%1)\n\tlwc1 $f27, 220(%1)\n\t"
        "lwc1 $f28, 224(%1)\n\tlwc1 $f29, 228(%1)\n\tlwc1 $f30, 232(%1)\n\tlwc1 $f31, 236(%1)"
        : : "r"(save), "r"(load) : "memory");
    return 2;
}

void wtarget_0017a7e0(u32 init, u32 prio, u32, u32) {
    NoTail g;
    if (prio == 0xffff && init == 1) {
        func_001bcf80(D_01c5f530);
        *(u32*)D_01c5f530 = (u32)D_00351260;
        func_00190128(D_01c5f530 + 2664);
        func_00190128(D_01c5f530 + 2684);
        func_00190128(D_01c5f530 + 2704);
        func_0019c920(D_01c5f530 + 2752);
        func_0031e2b8(D_01c5f530 + 2800);
    }
    if (prio == 0xffff && init == 0) {
        u8* o = D_01c5f530;
        func_0019c9a8(o + 2752);
        *(u32*)D_01c5f530 = (u32)D_00351228;
        func_001d48b0(o + 2496);
    }
}

void u_tail0_001917d0(void) {
    func_00191cd8();
    if (D_01c61958 == 2) return;
    s32 n = func_001918c8();
    if (0.0f < D_01c6195c) D_01c6195c -= D_00349e10;
    if (D_01c61958 != n) {
        if (0.0f < D_01c6195c || (D_01c61960 -= D_00349e10) <= 0.0f) func_00191938(n);
    }
    if (D_01c61958 == n) {
        if (n == 1) D_01c61960 = 120.0f;
        else D_01c61960 = 45.0f;
    }
    if (D_01c61958 == 0) func_001a3710();
}

