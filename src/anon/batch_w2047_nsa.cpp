#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QV ScaleQ(const QV& a, f32 k) {
    QV r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct CDE58Ent { s32 f0; u8 f4; u8 f5; u8 pad[62]; };
typedef CDE58Ent CDE58Tab;
struct CDE58Sub8 { s32 f0; s32 f4; s32 f8; };
struct CDE58Sub130 { u8 pad[0x2c]; f32 f2c; };
struct CDE58A {
    u8 pad0[0xc];
    CDE58Sub8* f0c;
    u8 pad10[0x120];
    CDE58Sub130* f130;
    u8 pad134[0x2c];
    s32 f160;
    u8 pad164[0x44c];
    f32 f5b0;
    u8 pad5b4[0x25c];
    s32 f810;
};
struct CDE58O {
    s32 f0;
    u8 pad4[0xc];
    u8 f10[0x20];
    QV v30;
    CDE58A* f40;
    CDE58Tab* f44;
    u8 pad48[0x18];
    u32 bits[4];
};
extern "C" {
void func_001cddb8(CDE58O*);
void func_001cdbc8(CDE58O*, void*, s32);
s32 func_001a0920(CDE58Ent*, CDE58A*);
s32 func_0019c090(CDE58A*);
QV func_001840c0(CDE58A*, QV);
s32 func_0019bf50(CDE58A*, QV*);
u32 func_001d7f40(CDE58Tab*, s32);
s32 func_001ce0a8(CDE58O*);
}
static inline __attribute__((always_inline)) bool cde58_chk(CDE58A* a) {
    bool r = false;
    if ((a->f0c->f8 & 2) || (a->f160 & 0x40)) r = true;
    return r;
}
static inline __attribute__((always_inline)) void cde58_put(u32* w, u32 i, s32 v) {
    u32* q = &w[i >> 5];
    u32 m = 1 << (i & 31);
    if (v) *q |= m;
}
static inline __attribute__((always_inline)) void cde58_set(u32* w, u32 i) {
    u32* q = &w[i >> 5];
    *q |= 1 << (i & 31);
}
static inline __attribute__((always_inline)) void cde58_scan(CDE58O* o) {
    CDE58Tab* t = o->f44;
    for (s32 i = 0; i < t->f0; i++, t = o->f44) {
        CDE58Ent* e = (CDE58Ent*)(i * 68 + (u32)t);
        if (e->f5 == 3) {
            cde58_put(o->bits, i, func_001a0920((CDE58Ent*)&e->f4, o->f40));
        }
    }
}
extern "C" {
void func_001cde58(CDE58O* o) {
    func_001cddb8(o);
    if (o->f0) func_001cdbc8(o, o->f10, 1);
    cde58_scan(o);
    QV v;
    v = ScaleQ(o->v30, o->f40->f5b0 + o->f40->f130->f2c);
    CDE58A* a = o->f40;
    bool hit = func_0019c090(a) || cde58_chk(a);
    bool ok = !hit;
    if (ok && o->f40->f810 == 0) {
        QV r = func_001840c0(o->f40, v);
        if (func_0019bf50(o->f40, &r)) {
            cde58_set(o->bits, func_001d7f40(o->f44, 1));
        }
    }
    if (!func_001ce0a8(o)) {
        if (func_0019c090(o->f40)) cde58_set(o->bits, func_001d7f40(o->f44, 9));
        else cde58_set(o->bits, func_001d7f40(o->f44, 5));
        func_001ce0a8(o);
    }
}
}
