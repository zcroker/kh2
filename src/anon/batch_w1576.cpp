#include "../common/types.h"
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCP4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCP(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCP(this, &o); return *this; }
    QV operator+(const QV& b) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QM() {}
    QM(const QM& o) { QCP4(this, &o); }
    QV operator*(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
extern Alloc* D_0032ba14;
extern Holder* D_00347f80;
extern u8 D_00347e60;
extern s32 D_0035ed20; extern s32 D_0035ed24; extern s32 D_0035ed28; extern s32 D_0035ed2c;
extern s32 D_0035ed30; extern void* D_0035ed34; extern s32 D_0035ed38; extern s8 D_0035ed3c;
extern s32 D_0035ed40; extern s8 D_0035ed44;
void func_00287b18(s32, s32);
s32 func_00288be8(s32);
void func_002889f0(s32, s32, s32);
void func_00288f48(s32, s32, s32, s32, s32);
void func_002b3df8(s32);
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_00322e58(s32);
void func_002fde18(s32, s32, s32);
void func_00239700(void*);
s32* func_00103eb0(void);
void func_00102818(s32, s32, s32, void*, s32);
void PauseThread_(void*) asm("_ZN2Tz4HECO11PauseThreadEP4TASK");

typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
void func_00244f10(void) {
    s32 v;
    func_00287b18(4, 3);
    v = func_00288be8(0x38);
    func_002889f0(v, 4, 1);
    D_0035ed20 = v;
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 0);
    D_0035ed24 = v;
    func_00288f48(v, 0x40, 0x80, 0, 0);
    D_0035ed28 = 0;
    D_0035ed2c = 0;
    D_0035ed30 = 0;
    v = (s32)Al(12);
    func_002b3df8(v);
    D_0035ed38 = v;
    D_0035ed3c = 0;
    v = func_001063c0(0x394c, func_00103570());
    func_00322e58(v);
    D_0035ed40 = v;
    v += 0x3948;
    func_002fde18(v, 0, 4);
    {
        Alloc* al = D_00347f80->al;
        s32* p = (s32*)(*al->vt)(al, 0x664, 0);
        u8* base = (u8*)(p + 1);
        u8* q = base;
        s32 i = 3;
        *p = 4;
        do {
            *(s32*)(q + 12) = 0;
            *(void**)q = &D_00347e60;
            i--;
            func_00239700(q + 0x18);
            q += 0x198;
        } while (i != -1);
        D_0035ed34 = base;
    }
    D_0035ed44 = 0;
    func_00102818(func_00103eb0()[1], 0, 2000, (void*)PauseThread_, 0x1000);
}

extern u8 D_0035f0b0;
s32 func_00240ba0(void);
s32 func_00287cd0(void);
s32 func_002b4ff8(void);
void func_00287cc0(s32);
s32 func_00287d30(void);
s32 func_00233e70(s32);
s32 func_00234798(void);
s32 func_00234758(void);
void func_00241450(s32);
void func_00287d20(s32);
s32 func_00241c40(s32);
void func_00287bd0(s32, s32);
void func_002400f8(s32);
void func_002b5108(s32, s32);
void func_002b4c88(s32);
void func_00240e10(s32);
void func_00234570(s32, s32);

void func_0025bbe0(void) {
    s32 fail = 0;
    s32 id = func_00240ba0();
    s32 st = func_00287cd0();
    if (st == 2) return;
    if (func_002b4ff8() == 0) return;
    if (st == 0) func_00287cc0(1);
    switch (func_00287d30()) {
    case 0x3c:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00241450(0);
                func_00287d20(0x3d);
            }
        }
        break;
    case 0x3e:
        if (func_00233e70(0) == 0) {
            if (func_00234758() != 0) {
                fail = 1;
            } else if (func_00241c40(0) != 0) {
                func_00287bd0(0xe, 0);
                func_00287d20(0x46);
                func_002400f8(1);
            } else {
                func_002b5108(0xc6c8, id);
                func_00287bd0(0x16, 0);
                func_002b4c88(0);
            }
        }
        break;
    case 0x3d:
        if (func_00233e70(0) == 0) {
            if (func_00234798() != 0) {
                fail = 1;
            } else {
                func_00240e10(-4);
                func_00287d20(0x3e);
            }
        }
        break;
    }
    if (fail) {
        func_002b4c88(0);
        func_002b5108(0x8a8b, id);
        func_00287bd0(7, 0);
        func_00234570(id, 0);
        D_0035f0b0 = 0;
    }
}

extern u8* D_00361f60;
void func_0016a9a0(void);
QM* func_002d8110(u8*);
void func_002d0bd8(u8*, QM*);
void func_0011b6a8(QM*);
void func_0011b7b0(QM*, u8*);
void func_0016ace0(u8*, QV*);
void func_0016b070(u8*, u8*);
void func_002d8120(f32, QM*, u8*, u8*);
void func_002d0b88(u8*, QM*);

void func_002dafd0(u8* o) {
    func_0016a9a0();
    if (*(u8*)(o + 0xb18) == 0) return;
    u8* g = D_00361f60;
    if (*(s32*)(o + 0xb1c) == 0) {
        QM m;
        QM* src = func_002d8110(g);
        QV* tp = &m.r[3];
        QCP4(&m, src);
        QV v;
        v.x = *(f32*)(o + 0xb40) + *(f32*)(o + 0xb30);
        v.y = *(f32*)(o + 0xb44) - *(f32*)(o + 0xb34);
        v.z = *(f32*)(o + 0xb48);
        v.w = 1.0f;
        QV t = m * v;
        t.w = 1.0f;
        *tp = t;
        func_002d0bd8(o, &m);
    } else {
        QM m;
        func_0011b6a8(&m);
        func_0011b7b0(&m, o + 0xb50);
        *(s32*)(o + 0xb3c) = 0;
        QV t = m * *(QV*)(o + 0xb30);
        QV v = t + *(QV*)(o + 0xb40);
        func_0016ace0(o, &v);
        func_0016b070(o, o + 0xb50);
        QM x;
        func_002d8120(-*(f32*)(o + 0xb34), &x, g, o + 0xb30);
        func_002d0b88(o, &x);
    }
}
}
