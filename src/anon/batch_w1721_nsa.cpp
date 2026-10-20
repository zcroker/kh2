#include "../common/types.h"
struct W1721V4 {
    f32 x, y, z, w;
    W1721V4() {}
    W1721V4& operator=(const W1721V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1721V4 operator-(const W1721V4& o) const {
        W1721V4 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    f32 dot(const W1721V4& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct W1721Target;
struct W1721Obj { u8 pad0[0x588]; s32 flags; u8 pad58c[0xb40 - 0x58c]; u8* b40; };
struct W1721Owner { u8 pad0[0x9e0]; W1721Obj* obj; };
struct W1721Head { W1721Owner* owner; };
struct W1721Self { W1721Head* head; u8 pad4[0x3c]; W1721V4 pos; };
struct W1721Param { u8 pad0[0xc]; s32 flags; f32 angle; f32 cone; f32 range; };

static inline bool W1721_lt(f32 a, f32 b) { return a < b; }
extern "C" {
s32 func_00190680(W1721Target*, void*) asm("_ZNK2YS6TARGET7is_sameERKS0_");
W1721V4 func_00190388(W1721Target*);
void func_0016af58(W1721V4*, W1721Obj*);
W1721V4 func_0017d538(f32, s32);
s32 func_0019c090(W1721Obj*);

/* 0019df08: scales damage when the attack target matches the owner (0.5) or the lock target (0.8),
   then sets bit 30 (0x40000000) when the hit falls inside the facing cone, the arc cone or the extra obj test. */
s32 func_0019df08(W1721Self* self, W1721Param* prm, W1721Target* tgt, s32 a3, s32 dmg)
{
    W1721Obj* o = self->head->owner->obj;
    if ((o->flags & 0x80) && func_00190680(tgt, o->b40 + 4)) {
        dmg = (s32)(dmg * 0.5f);
    } else if (func_00190680(tgt, (u8*)self->head + 12)) {
        dmg = (s32)(dmg * 0.8f);
    }
    if (dmg > 0x3fffffff) dmg = 0x3fffffff;
    W1721V4 d;
    W1721V4 t2;
    d = func_00190388(tgt) - self->pos;
    d.normalize();
    if (-1.0f < prm->angle) {
        W1721V4 t;
        func_0016af58(&t, o);
        if (W1721_lt(d.dot(t), prm->angle)) dmg |= 0x40000000;
    }
    if (-1.0f < prm->range) {
        t2 = func_0017d538(prm->cone + 3.1415927f, a3);
        if (d.dot(t2) < prm->range) dmg |= 0x40000000;
    }
    if ((prm->flags >> 1) & 1) {
        if (func_0019c090(o)) dmg |= 0x40000000;
    }
    return dmg;
}
}
