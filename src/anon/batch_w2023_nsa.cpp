#include "../common/types.h"
void func_0011b6a8(void*);  // C++ linkage, see functions.tsv
extern "C" {
struct W2023V {
    f32 x, y, z, w;
    W2023V() {}
    W2023V(const W2023V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2023V& operator=(const W2023V& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void operator*=(f32 k)
    {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(this), "f"(k) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct W2023M {
    f32 m[4][4];
    W2023M() {}
    W2023M& operator=(const W2023M& o)
    {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W2023M W2023Mul(const W2023M& l, const W2023M& r)
{
    W2023M d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&d), "r"(&l), "r"(&r) : "memory");
    return d;
}
static inline W2023V W2023MulV(const W2023M& m, const W2023V& v)
{
    W2023V d;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)"
                 : : "r"(&d), "r"(&m), "r"(&v) : "memory");
    return d;
}
struct W2023Ob {
    W2023V pos;       // 0
    u8 pad10[6];
    u8 b16;         // 22
    u8 pad17[0x19];
    W2023V vel;       // 48
    f32 timer;      // 64
    u8 pad44[0x74];
    s32 dir;        // 184
};
struct W2023Pl;
typedef W2023M* (*W2023PlFn)(W2023Pl*);
struct W2023Pl { W2023PlFn* vt; };
extern f32 D_00349e10;
extern f32 D_00351fd8;
extern f32 D_00351fe0;
W2023Pl* W2023_current(void) asm("_ZN2Ti8MGPlayer7currentEv");
s32 W2023_ctarget(W2023Pl*) asm("_Z16ctarget_0019ba60jjjj");
void W2023_rotateY(W2023M*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
f32 func_001cbf50(f32);

s32 func_001cab28(W2023Ob* o)
{
    W2023Pl* pl = W2023_current();
    f32 t;
    o->timer -= D_00349e10;
    if (o->timer <= 0.0f || !W2023_ctarget(pl)) return 0;
    t = o->timer / D_00351fd8;
    W2023V v = o->vel;
    v *= o->vel.w * t;
    f32 one = 1.0f;
    v.w = one;
    W2023M m;
    func_0011b6a8(&m);
    if (o->dir) W2023_rotateY(&m, func_001cbf50(D_00351fe0 * (one - t)));
    else W2023_rotateY(&m, func_001cbf50(-D_00351fe0 * (one - t)));
    m = W2023Mul(*pl->vt[40](pl), m);
    o->pos = W2023MulV(m, v);
    o->b16 = t * 255.0f;
    return 1;
}

s32 func_0022a3d0(s32 n, f32 x, s32* a, s32* b, s32* c, s32* d, s32* e, s32* f, s32* g, s32* h, f32* out);
void W2023_hide(void*) asm("_ZN2dk5Obj2D9localHideEv");
void W2023_show(void*) asm("_ZN2dk5Obj2D9localShowEv");
void W2023_call4(void*) asm("_Z16u_call4_00139d78jjjj");
void W2023_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
void W2023_setXY(void*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void W2023_setZ(void*, u32) asm("_ZN2dk13RectParamBase4setZEj");
void W2023_setWH(void*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
struct W2023Ent {
    u8 obj[32];     // dk::Obj2D (0)
    u8 ft4[288];    // dk::Ft4Base (32)
    u8 r1[256];     // dk::RectParamBase (320)
    u8 r2[272];     // dk::RectParamBase (576)
    void setZ(u32 z)
    {
        W2023_call4(obj);
        W2023_setZ(r1, z);
        W2023_setZ(r2, z);
    }
    void setRot(f32 a)
    {
        W2023_call4(obj);
        W2023_setRot(ft4, a);
    }
    static void rect(void* o, void* r, s32 x, s32 y, s32 w, s32 h)
    {
        W2023_call4(o);
        W2023_setXY(r, x, y);
        W2023_setWH(r, w, h);
    }
};
struct W2023Self {
    u8 pad[864];
    W2023Ent e[2];
    u8 pad2[2968 - 864 - 2 * 848];
    s32 b98;
};
struct W2023SelfB {
    u8 pad[1680];
    W2023Ent e[4];
    u8 pad2[5480 - 1680 - 4 * 848];
    s32 b98;
};

void func_00229b28(W2023Self* s, s32 i, u32 z1, u32 z2, f32 x)
{
    s32 h;
    f32 rot;
    s32 a, b, c, d, e, f, g;
    W2023_hide(s->e[i].obj);
    switch (func_0022a3d0(s->b98, x, &a, &b, &c, &d, &e, &f, &g, &h, &rot)) {
    case 0:
        break;
    case 1:
        s->e[i].setZ(z1);
        break;
    case 2:
        s->e[i].setZ(z1);
        break;
    case 3:
        s->e[i].setZ(z1);
        break;
    case 4:
        s->e[i].setZ(z2);
        break;
    }
    W2023Ent* p = &s->e[i];
    p->setRot(rot);
    W2023Ent::rect(p->obj, p->r1, a, b, c, d);
    W2023Ent::rect(p->obj, p->r2, e, f, g, h);
    W2023_show(p->obj);
}

void func_0022a5c8(W2023SelfB* s, s32 i, u32 z1, u32 z2, f32 x)
{
    s32 h;
    f32 rot;
    s32 a, b, c, d, e, f, g;
    W2023_hide(s->e[i].obj);
    switch (func_0022a3d0(s->b98, x, &a, &b, &c, &d, &e, &f, &g, &h, &rot)) {
    case 0:
        break;
    case 1:
        s->e[i].setZ(z1);
        break;
    case 2:
        s->e[i].setZ(z1);
        break;
    case 3:
        s->e[i].setZ(z1);
        break;
    case 4:
        s->e[i].setZ(z2);
        break;
    }
    W2023Ent* p = &s->e[i];
    p->setRot(rot);
    W2023Ent::rect(p->obj, p->r1, a, b, c, d);
    W2023Ent::rect(p->obj, p->r2, e, f, g, h);
    W2023_show(p->obj);
}

struct W2023Q {
    f32 x, y, z, w;
    W2023Q() {}
    W2023Q(const W2023Q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2023Q& operator=(const W2023Q& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W2023Q operator-(const W2023Q& b) const
    {
        W2023Q r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W2023Q operator+(const W2023Q& b) const
    {
        W2023Q r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W2023Q operator*(f32 k) const
    {
        W2023Q r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 normalize()
    {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
s32 func_002cbf70(void* a, W2023Q* out, W2023Q* p, f32 t);

W2023Q func_002cba88(void* a, const W2023Q& from, const W2023Q& other, f32 t, f32 k)
{
    W2023Q o;
    W2023Q p = from;
    if (t > 50.0f) t = 50.0f;
    if (!func_002cbf70(a, &o, &p, t)) {
        W2023Q r = other;
        r.w = 0.0f;
        return r;
    }
    W2023Q d1 = o - from;
    W2023Q d2 = o - p;
    f32 l1 = d1.normalize();
    d2.normalize();
    if (t * 10.0f < l1) {
        d1.w = 1.0f;
        return d1;
    }
    W2023Q m = d1 * (1.0f - k) + d2 * k;
    m.normalize();
    m.w = 1.0f;
    return m;
}
}
