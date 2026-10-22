#include "../common/types.h"

/* w2046: built with -fno-strict-aliasing (_nsa). Uses the lq/sq copy idiom
   and a VU0 outer-product macro (Cross), both as small inline asm. */
namespace w2046_nsa {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator=(const V& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

static inline V Cross(const V& a, const V& b)
{
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

struct Mot { u8 pad[0x14]; s32 id; };
struct Info { u8 pad[0x2b]; u8 kind; };
struct Tgt { V v; u8 pad[0x10]; Info* info; };
struct Self {
    u8 pad[0x140];
    Mot mot;                 /* 0x140 */
    u8 pad2[0x58c - 0x158];
    u32 flags;               /* 0x58c */
    u8 pad3[0xb6c - 0x590];
    s32 party;               /* 0xb6c */
};

void mo488_w2046(Mot*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void mopush_w2046(Mot*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void ct186a90_w2046(Self*, V*, f32) asm("_Z16ctarget_00186a90jjjj");
s32 ct19ba60_w2046(s32) asm("_Z16ctarget_0019ba60jjjj");
void f16ac38_w2046(s32, s32, s32, s32, s32) asm("_Z13func_0016ac38jjjjjjjj");

extern "C" s32 D_0036e318;
extern "C" s32 D_0036e31c;
static inline __attribute__((always_inline)) s32 motIdB(Mot* m) { if (m->id == 189) return D_0036e318; return D_0036e31c; }

extern "C" {
V func_0016af58(Self*);
V func_0017d538(const V&, f32);
f32 func_0018cb30(Tgt*);

void func_001cf0d8(Self* self, Tgt* t)
{
    V n;
    V d;
    n = Cross(func_0016af58(self), t->v);
    switch (t->info->kind) {
    case 0:
        mo488_w2046(&self->mot, 30, 0.0f, 0.0f);
        mopush_w2046(&self->mot, 0, 0.0f, 0.0f, 0);
        break;
    case 1: {
        s32 id = motIdB(&self->mot);
        Mot* m = &self->mot;
        f32 k;
        if (0.0f < n.y) {
            k = 1.5707964f;
            mo488_w2046(m, 32, 0.0f, 0.0f);
            id++;
        } else {
            k = -1.5707964f;
            mo488_w2046(m, 31, 0.0f, 0.0f);
        }
        d = func_0017d538(func_0016af58(self), k);
        ct186a90_w2046(self, &d, func_0018cb30(t));
        if (self->flags & 4) {
            if (ct19ba60_w2046(self->party)) {
                f16ac38_w2046(self->party, id, 1, 0, 0);
            }
        }
        mopush_w2046(m, 0, 0.0f, 0.0f, 0);
        break;
    }
    case 2:
        mo488_w2046(&self->mot, 16, 0.0f, 0.0f);
        mopush_w2046(&self->mot, 0, 0.0f, 0.0f, 0);
        break;
    case 3:
        if (0.0f < n.y) mo488_w2046(&self->mot, 33, 0.0f, 0.0f);
        else mo488_w2046(&self->mot, 34, 0.0f, 0.0f);
        mopush_w2046(&self->mot, 0, 0.0f, 0.0f, 0);
        break;
    }
}
}
}
