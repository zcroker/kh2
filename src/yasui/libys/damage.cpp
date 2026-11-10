#include "damage.hpp"

// YS::DAMAGE (0x18c8b8-0x18d050): one hit's damage record (direction, attacker, target, attack
// parameters), allocated from a static pool of four.

#define DMG_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct DmgVec {
    f32 x, y, z, w;
    DmgVec() {}
    DmgVec& operator=(const DmgVec& o) { if (this != &o) DMG_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));

static inline DmgVec operator-(const DmgVec& a, const DmgVec& b) {
    DmgVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

// VU0: xyz length
static inline f32 DmgLength(const DmgVec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// VU0: normalize xyz in place, return the old length
static inline f32 DmgNormalize(DmgVec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// The attack source: an object that gives the hit direction.
struct DmgSrc {
    virtual void v0();
    virtual void v1();
    virtual DmgVec get(void);
    virtual DmgVec get(int);
};
struct DmgRange { u8 pad[12]; s16 lo; s16 hi; };
struct DmgPrm { u8 pad[44]; f32 f2c; f32 f30; f32 f34; f32 f38; f32 f3c; };

extern "C" void func_0031e2b8(void*);  // DAMAGE flags constructor

struct DamageRec {
    DmgVec dir;      // 0
    u32 owner;       // 16
    u32 target;      // 20
    u32 flags;       // 24
    DmgSrc* src;     // 28
    u8* prm;         // 32 (DmgRange at +12, flags byte at +18, reaction at +10)
    u8 f36;
    u8 attr;         // 37
    u8 kind;         // 38
    u8 type;         // 39
    u32 combo;       // 40
    u8 pad44[4];
    DamageRec() { func_0031e2b8(&flags); }
    ~DamageRec() {}
};

struct DamageFree {
    s32 free[4];
    s32 n;
};

struct DamagePool {
    DamageRec e[4];
    DamageFree list;   // 192
    DamagePool() {
        DamagePool* p = this;
        s32 i;
        for (i = 0; i < 4; i++) p->list.free[i] = i;
        p->list.n = 4;
    }
};

static DamagePool D_01c60bf0;

extern "C" {
extern DmgPrm* D_00352130;
extern u32 D_003638d0;  // random seed
DmgVec* func_0016c028(u32);  // obj_get_attach_or_alt
u32 func_001a1e20(u32, DmgSrc*, u8*, u8);

DamageRec* func_0018c8b8(void) {
    DamagePool* p = &D_01c60bf0;
    DamageRec* d = &p->e[p->list.free[--p->list.n]];
    d->flags = 0;
    return d;
}

void func_0018c960(DamageRec* d, DmgSrc* src, u8* prm, u32 target, u32 attr);

DamageRec* func_0018c8f0(DmgSrc* src, u8* prm, u32 target, u32 attr) {
    DamageRec* d = func_0018c8b8();
    func_0018c960(d, src, prm, target, attr);
    return d;
}

void func_0018ce08(DamageRec* o);

void func_0018c960(DamageRec* d, DmgSrc* src, u8* prm, u32 target, u32 attr) {
    d->src = src;
    d->prm = prm;
    u32 t = *(u32*)((u8*)src + 8);
    d->target = target;
    d->owner = t;
    d->attr = attr;
    u8 v = prm[10];
    d->type = v;
    d->kind = v;
    func_0018ce08(d);
    u32 s1 = *(u32*)(d->target + 1164);
    if (s1 != 0) {
        d->combo = func_001a1e20(s1, d->src, d->prm, d->attr);
        u32 t2 = *(u8*)(s1 + 430);
        u32 t4 = *(u8*)(*(u8*)(d->prm + 9) + s1 + 424);
        if (t4 * t2 == 0) {
            d->kind = 0;
            d->flags |= 4;
        }
    } else {
        d->combo = 0;
    }
}

void func_0018ca10(DamageRec* d) {
    s32 n = D_01c60bf0.list.n;
    D_01c60bf0.list.n = n + 1;
    D_01c60bf0.list.free[n] = d - D_01c60bf0.e;
}

}

namespace YS {

s32 DAMAGE::GetReactionType(s32 a) {
    switch (a) {
    case 1: case 12: return 1;
    default: return a;
    case 4: case 7: case 9: case 11: case 15: case 17: return 4;
    case 3: case 6: case 8: case 10: case 13: case 16: case 18: return 3;
    }
}

}  // namespace YS

extern "C" bool func_0018ca90(s32 a) {
    switch (a) {
    case 6: case 7: case 10: case 11:
        return true;
    }
    return false;
}

namespace YS {

u32 DAMAGE::is_finish() const {
    return func_0018ca90(((const DamageRec*)this)->type);
}

}  // namespace YS

extern "C" u8 func_0018cae0(DamageRec* d) {
    return (d->prm[18] >> 5) & 1;
}

namespace YS {

s32 DAMAGE::is_normal() const {
    switch (((const DamageRec*)this)->type) {
    case 0: case 1: case 3: case 4: case 6: case 7: case 15: case 16:
        return 1;
    case 2: case 5: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
        return 0;
    }
    return 0;
}

}  // namespace YS

extern "C" {

void func_0018cd28(DamageRec* d, f32* x, f32* y);

// Knock-back distance of the hit.
f32 func_0018cb30(DamageRec* self) {
    DmgVec v;
    DmgVec* pv = &v;
    f32 r = D_00352130->f30;
    switch (YS::DAMAGE::GetReactionType(self->type)) {
    case 4:
        func_0018cd28(self, &pv->y, &pv->z);
        pv->x = 0.0f;
        r = DmgLength(pv) * D_00352130->f2c;
        break;
    case 5: {
        f32 len;
        f32 lo, hi;
        *pv = self->src->get() - *func_0016c028(self->target);
        pv->y = 0.0f;
        len = DmgLength(pv);
        lo = (f32)((DmgRange*)self->prm)->lo;
        hi = (f32)((DmgRange*)self->prm)->hi;
        D_003638d0 *= 0x10dcd;
        r = -(len - (lo + (f32)D_003638d0 * 2.3283064365386963e-10f * (hi - lo)));
        break;
    }
    case 3:
        r = D_00352130->f34;
    default:
        if (self->prm && ((DmgRange*)self->prm)->lo != 0x7fff) r = (f32)((DmgRange*)self->prm)->lo;
        break;
    }
    if (self->kind == 12 || self->kind == 13) r *= 0.5f;
    return r;
}

void func_0018cd28(DamageRec* d, f32* x, f32* y) {
    *x = *(f32*)((u8*)D_00352130 + 36);
    *y = *(f32*)((u8*)D_00352130 + 40);
    if (YS::DAMAGE::GetReactionType(d->type) != 4) return;
    if (!d->prm) return;
    if (!*(u32*)(d->prm + 12)) return;
    *x = (f32)*(s16*)(d->prm + 12);
    *y = (f32)*(s16*)(d->prm + 14);
}

}

namespace YS {

u32 DAMAGE::is_count_combo() const {
    u32 v0 = 0u;
    u32 t7 = *(u32*)((u32)this + (s32)(24));
    t7 = (u32)(t7 & 0x4u);
    if (t7 != 0u) goto Lret;
    if (*(u8*)((u32)this + (s32)(38)) != (u8)5u) goto Lset;
    if (*(u32*)((u32)this + (s32)(40)) != 0u) goto Lset;
    goto Lret;
Lset:
    v0 = 1u;
Lret:
    return v0;
}

}  // namespace YS

extern "C" void func_0018ce08(DamageRec* o) {
    if (o->kind == 5) {
        DmgVec* p = func_0016c028(o->target);
        o->dir = *p - o->src->get();
        o->dir.y = 0;
        DmgNormalize(&o->dir);
    } else {
        o->dir = o->src->get(o->target);
    }
}

namespace YS {

u32 DAMAGE::is_player_attack() const {
    u32 o = ((const DamageRec*)this)->owner;
    u32 r = 0;
    if (o) {
        u32 f = *(u32*)(o + 1416) & 0x80;
        r = f != 0;
    }
    return r;
}

}  // namespace YS
