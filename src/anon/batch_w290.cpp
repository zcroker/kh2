#include "../common/types.h"
struct W290V {
    f32 x, y, z, w;
    W290V() {}
    W290V(const W290V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W290V& operator=(const W290V& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    f32 Length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 Normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 LengthSq() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W290M { W290V r[4]; };
static inline W290V operator*(const W290M& m, const W290V& v) {
    W290V r;
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline W290V operator-(const W290V& a, const W290V& b) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W290V operator+(const W290V& a, const W290V& b) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline W290V Lerp(const W290V& a, const W290V& b, f32 t) {
    W290V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct W290Fx { W290V pos; u8 p16[5]; s8 f21; u8 p22[26]; W290V v48; u8 p64[16]; u8 cnt; u8 idx; };
extern "C" {
void* func_001050d8(u32);
void func_002cb5d8(void*, f32);
s32 func_0018ac80(void*, s32);
void func_002cb828(void*, f32*);
void func_002cc7d0(void*);
void func_002ce870(void*, void*);
void func_002ce598(void*, void*);
struct W290Ent { f32 a; f32 b; f32 c; };
struct W290Dat { u16 h0; u16 n; u8 b4; u8 p5[3]; W290Ent e[1]; };
struct W290Cd {  u8 p0[12]; u32 n; u8 b16; u8 p17[15]; f32 f32_; u8 p36[92]; u32 buf; u8 p132; u8 b133; u8 b134; u8 p135[9]; W290Dat* dat; };
W290Cd* func_002cd018(u8* act, W290Dat* d, void* a2, f32 f) {
    s32 s4 = 0;
    W290Cd* p = (W290Cd*)func_001050d8(160);
    func_002cb5d8(p, f);
    p->n = d->n;
    p->buf = (u32)func_001050d8(d->n << 5);
    if (*(u32*)(act + 1416) & 8) s4 = func_0018ac80(act, 3) != 0;
    for (s32 i = 0; i < d->n; i++) {
        f32 t[4];
        t[0] = d->e[i].a;
        t[1] = d->e[i].b;
        if (s4) t[1] = d->e[0].b;
        t[2] = d->e[i].c;
        t[3] = 1.0f;
        func_002cb828(p, t);
    }
    p->b16 = d->b4 & 1;
    f32 z = 0.0f;
    if (!(d->b4 & 2)) z = 0.5f;
    p->f32_ = z;
    func_002cc7d0(p);
    if (*(u32*)(act + 1416) & 8) {
        p->b134 = func_0018ac80(act, 2);
        if (func_0018ac80(act, 1)) func_002ce598(p, a2);
        else func_002ce870(p, act);
    } else {
        p->b134 = 0;
        func_002ce598(p, a2);
    }
    p->dat = d;
    p->b133 = p->b134 == 0;
    return p;
}

extern void* D_00361de8[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u32 D_00361dd8;
void func_00170950(u32);
void func_00239870(void*);
void func_0023c098(void*);
void func_002369f0(void*);
void func_00105110(void*);
struct W290VE { virtual void f0(); virtual void f1(); virtual void f2(); virtual ~W290VE(); u8 pad[404]; };
struct W290B0 { u32 vt; ~W290B0() { vt = (u32)D_00347f98; } };
struct W290S24 { u8 d[384]; ~W290S24() { func_00239870(this); } };
struct W290E1 : W290B0 { u8 p[20]; W290S24 s; ~W290E1() { vt = (u32)D_00347e60; } };
struct W290S52 { u8 d[24]; ~W290S52() { func_002369f0(this); } };
struct W290S76 { u8 d[120]; ~W290S76() { func_0023c098(this); } };
struct W290M28 : W290B0 { u8 p[20]; W290S52 a; W290S76 b; ~W290M28() { vt = (u32)D_0035eb98; } };
struct W290Big : W290B0 {
    u8 p4[24];
    W290M28 m28;
    W290E1 m196;
    u8 p604[28];
    W290VE a632[3];
    W290E1 m1856;
    W290E1 m2264;
    W290VE a2672[2];
    W290VE a3488[3];
    W290E1 m4712;
    W290VE a5120[2];
    ~W290Big() __attribute__((always_inline));
};
inline W290Big::~W290Big() {
        *(void***)this = D_00361de8;
        func_00170950(*(u32*)((u8*)this + 188));
        u32 t = D_00361dd8;
        if (t == (u32)this) t = 0;
        D_00361dd8 = t;
}

void func_002c81e8(W290Big* p) {
    p->~W290Big();
    func_00105110(p);
}

struct W290Q { f32 x, y, z, w; } __attribute__((aligned(16)));
extern W290Q* D_0034a3f4;
extern u32 D_0034a3f0;
extern f32 D_0034a3f8;
extern f32 D_004f3584;
extern f32 D_004f3580;
W290Q* func_0016c028(u32);
f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
void* func_00106a18(s32);
f32 func_00106f30(void*, s32);
struct W290Cam { u8 p[192]; f32 yaw; f32 pitch; };
void func_0014e6f8(W290Cam* c) {
    W290Q* a = D_0034a3f4;
    W290Q* b = func_0016c028(D_0034a3f0);
    W290Q d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(a), "r"(b) : "memory");
    d.y += D_0034a3f8;
    f32 t = func_002f8ad0(d.x, d.z);
    f32 r = func_0017ce10(c->yaw - t);
    f32 lim = func_00106f30(func_00106a18(1), 0) * 0.5f - 0.17453292f;
    if (r < -lim) c->yaw = func_0017ce10(t - lim);
    else if (lim < r) c->yaw = func_0017ce10(t + lim);
    t = -func_002f8ad0(d.y, __builtin_sqrtf(d.x * d.x + d.z * d.z));
    r = func_0017ce10(c->pitch - t);
    lim = func_00106f30(func_00106a18(1), 1) * 0.5f - 0.17453292f;
    if (r < -lim) c->pitch = func_0017ce10(t - lim);
    else if (lim < r) c->pitch = func_0017ce10(t + lim);
    if (D_004f3584 < c->pitch) c->pitch = D_004f3584;
    else if (c->pitch < D_004f3580) c->pitch = D_004f3580;
}

extern W290V D_01d49590[];
extern W290M D_01d49610;
extern W290V D_00352a60;
s32 func_001c4160(W290Fx*);
void func_001c4188(W290Fx*, f32);
void func_001c4e30(W290Fx* o) {
    W290V l;
    o->pos = o->v48 + D_01d49590[o->idx];
    l = D_01d49610 * o->v48;
    if (func_001c4160(o)) func_001c4188(o, (o->pos - D_00352a60).LengthSq());
    if (o->cnt) { o->cnt--; return; }
    if (l.z < 300.0f) { o->f21 = 0; return; }
    l = o->pos - D_00352a60;
    o->f21 = -128;
    f32 len = l.Normalize();
    if (len < 1200.0f) o->pos.y -= (1200.0f - len) * 0.5f;
}
}
