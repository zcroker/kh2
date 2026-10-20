#include "../common/types.h"

/* Built with -fno-strict-aliasing (the _nsa rule in the Makefile). */

void func_0017f488(int, int, float, float);

struct W1810Vec {
    f32 x, y, z, w;
    W1810Vec() {}
    W1810Vec& operator=(const W1810Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// VU0 vector subtract into a returned temporary
static inline W1810Vec operator-(const W1810Vec& a, const W1810Vec& b) {
    W1810Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

// VU0: normalize xyz in place, return the old length
static inline f32 w1810_norm(W1810Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// VU0: xyz length
static inline f32 w1810_len(const W1810Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

struct W1810Ray { W1810Vec o; W1810Vec d; };
struct W1810Seg2 { W1810Vec a; W1810Vec b; };

struct W1810Src {
    virtual void v0();
    virtual void v1();
    virtual W1810Vec get(void);
    virtual W1810Vec get(int);
};

extern "C" {
void* w1810_area_alloc(u32) asm("_ZN4AREA5AllocEj");
int w1810_getcharadata(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
void w1810_set_mode(void*, int) asm("_ZN2YS6MOTION8set_modeEi");
W1810Vec* func_0016c028(int);

f32 func_00164c70(void* self, const W1810Vec& a, const W1810Vec& b, const W1810Vec& c)
{
    W1810Seg2 s;
    s.a = a;
    s.b = c;
    W1810Ray r;
    r.o = s.a;
    r.d = s.b - s.a;
    r.d.w = 1.0f;
    r.o.w = 1.0f;
    w1810_norm(&r.d);
    return w1810_len(&(r.d - b)) * 10.0f;
}

int func_0017a538(void*);
void func_00185468(void*, int, void*, u32, int, int);
struct W1810S8 { u8 pad[0x4e]; u16 h; };
struct W1810Sub { u8 pad[0x14]; int a; u8 p2[4]; int b; u8 p3[0x10]; float f; };
struct W1810Obj;
struct W1810VT { void* p[15]; int (*f3c)(W1810Obj*); };
struct W1810Obj { W1810VT* vt; u8 pad[4]; W1810S8* s8; };
void func_00176168(W1810Obj* o, u32 id, int n)
{
    W1810Sub* s = (W1810Sub*)((u8*)o + 0x140);
    int k;
    if ((*(u32*)((u8*)o + 0x588) & 0x80) && func_0017a538(o) != 0 && n == 0) {
        k = 2301;
    } else {
        k = o->vt->f3c(o);
        k += n + 1;
    }
    u8* p = (u8*)w1810_area_alloc(0xa10);
    func_00185468(p, w1810_getcharadata(id), o, o->s8->h, n, k);
    ((u8**)((u8*)o + 0xaf8))[n] = p;
    w1810_set_mode(p + 0x140, s->b);
    func_0017f488((int)(p + 0x140), s->a, 0.0f, s->f);
}

struct W1810Item { W1810Vec v; int m10; int m14; int m18; W1810Src* src; u8 p20[6]; u8 kind; };
void func_0018ce08(W1810Item* o)
{
    if (o->kind == 5) {
        W1810Vec* p = func_0016c028(o->m14);
        o->v = *p - o->src->get();
        o->v.y = 0;
        w1810_norm(&o->v);
    } else {
        o->v = o->src->get(o->m14);
    }
}
}
