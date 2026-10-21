#include "../common/types.h"
// 001cf320
#define W1965aQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965aV {
    f32 x, y, z, w;
    W1965aV() {}
    W1965aV(const W1965aV& o) { W1965aQCOPY(this, &o); }
    W1965aV& operator=(const W1965aV& o) { if (this != &o) W1965aQCOPY(this, &o); return *this; }
    W1965aV operator-(const W1965aV& b) const {
        W1965aV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline W1965aV W1965aCross(const W1965aV& a, const W1965aV& b)
{
    W1965aV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W1965aNormalize(W1965aV* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct W1965aTgt { u8 pad[12]; u8* obj; };
extern "C" {
W1965aV* func_0016c028(u8*);
W1965aV func_0016af58(u8*);
W1965aV func_0017d538(const W1965aV&, f32);
s32 func_0018f010(W1965aTgt*);
void func_00186a90(u8*, W1965aV*, f32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
void func_001cf320(u8* o, s32 a1, W1965aTgt* t)
{
    f32 spd = 100.0f;
    W1965aV c;
    W1965aV n;
    n = *func_0016c028(t->obj) - *func_0016c028(o);
    W1965aNormalize(&n);
    c = W1965aCross(func_0016af58(o), n);
    s32 id;
    f32 ang;
    if (c.y < 0.0f) { id = 140; ang = 1.5707964f; }
    else { id = 141; ang = -1.5707964f; }
    { W1965aV t = func_0016af58(o); n = func_0017d538(t, ang); }
    if (func_0018f010(t)) spd = 2000.0f;
    func_00186a90(o, &n, spd);
    func_0017f488(o + 320, id, 0.0f, 0.0f);
    func_0017f5e0(o + 320, 0, 0, 0.0f, 0.0f);
}
}

// 002df500
#define W1965bQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965bV {
    f32 x, y, z, w;
    W1965bV() {}
    W1965bV(const W1965bV& o) { W1965bQCOPY(this, &o); }
    W1965bV& operator=(const W1965bV& o) { if (this != &o) W1965bQCOPY(this, &o); return *this; }
    W1965bV operator-(const W1965bV& b) const {
        W1965bV r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1965bV& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1965bPrm { u8 pad[216]; f32 f216; u8 pad2[16]; f32 f236; };
struct W1965bCtl { u8 pad[52]; s32 i52; s32 i56; };
struct W1965bBod { u8 pad[16]; W1965bV vel; };
struct W1965bBodV { u8 pad[16]; f32 vx; u8 pad2[8]; f32 spd; };
extern "C" {
extern s32 D_00361f60;
extern u8* D_0034e948;
W1965bV* w1965_pos(void*) asm("func_0016c028");
void func_002df040(void);
W1965bPrm* func_002dc7c8(s32);
void func_002dd2d8(s32, f32*, f32*);
void func_002df500(W1965bCtl* a, W1965bBod* b)
{
    func_002df040();
    s32 id = D_00361f60;
    W1965bV p = *w1965_pos(b);
    W1965bV* vel = &b->vel;
    p.x += func_002dc7c8(id)->f216 * (f32)a->i52;
    f32 lo, hi;
    func_002dd2d8(id, &lo, &hi);
    hi *= 0.95f;
    lo *= 0.95f;
    if (hi < p.x) p.x = hi;
    if (p.x < lo) p.x = lo;
    *vel *= ((W1965bBodV*)b)->spd;
    ((W1965bBodV*)b)->vx = p.x - w1965_pos(b)->x;
    f32 len = vel->length();
    vel->normalize();
    ((W1965bBodV*)b)->spd = len;
    if (a->i56 == 0) {
        W1965bV d = *w1965_pos(D_0034e948) - p;
        f32 dl = d.length();
        if (dl <= func_002dc7c8(id)->f236) a->i56 = 1;
    }
}
}
