#include "../../src/common/types.h"
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V10e810 {
    f32 x, y, z, w;
    V10e810() {}
    V10e810& operator=(const V10e810& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V10e810 operator-(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e810 operator*(f32 k) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V10e810& operator+=(const V10e810& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    V10e810& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
    V10e810 operator+(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V10e810 cross(const V10e810& b) const
    {
        V10e810 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 dot(const V10e810& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct VecSet10e810 { f32 x; u8 pad[28]; V10e810 dir; };
struct Seg10e810 { V10e810 p, q; };
struct Fr10e810;
struct Fr10e810Vt { void* f[38]; s32 (*kind)(Fr10e810*); };
struct Who10e810;
struct Fr10e810 {
    Fr10e810Vt* vt;
    u8 pad0[280 - 4];
    f32 reach;
    u8 pad1[1360 - 284];
    V10e810 fwd;
    u8 pad2[1456 - 1376];
    f32 f1456;
    u8 pad3[1520 - 1460];
    u16 h1520;
    u8 pad4[1532 - 1522];
    f32 f1532;
    u64 bits;
    s32 f1544;
    u8 pad5[1584 - 1548];
    V10e810 up;
    u8 pad6[2064 - 1600];
    s32 f2064;
    u8 pad7[2912 - 2068];
    Who10e810* who;
    u8 pad8[2928 - 2916];
    s32 point;
    u8 pad9[4];
    s32 level;
    u32 flags;
    VecSet10e810 own;
    u8 pad10[3072 - 2992];
    V10e810 dir;
    u8 pad11[3288 - 3088];
    s32 f3288;
};
extern V10e810 D_00341720[];
extern Fr10e810* D_00341708;
extern u8 D_003a9040;
s32 f10e810_update(Fr10e810*, const VecSet10e810*) asm("func_0010e368");
s32 func_001917c0(void);
V10e810* f10e810_attach(Fr10e810*) asm("func_0016c028");
f32 f10e810_hi(Who10e810*, s32, s32, s32) asm("func_00114328");
f32 f10e810_lo(Who10e810*, s32, s32, s32) asm("func_001142e0");
f32 f10e810_dist(Fr10e810*, s32) asm("func_0010e7e0");
s32 func_0010e6e0(Fr10e810*, V10e810*, f32, f32, f32);
s32 func_00143f28(u16, s32);
s32 func_00143ae0(Seg10e810*, V10e810*, V10e810*, s32);
void f10e810_warp(Fr10e810*, s32, f32) asm("func_0010cac8");
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs) asm("_ZN2kn6Friend10followMoveEPKNS_6VecSetE");
void f10e810_followMove(Fr10e810* o, const VecSet10e810* vs)
{
    if (o->flags & 0x10000000) return;
    if (f10e810_update(o, vs)) return;
    s32 mode = func_001917c0();
    bool self = vs == &o->own;
    if (self && !(o->flags & 0x10)) {
        o->dir = D_00341720[o->point] - *f10e810_attach(o);
        o->dir.y = 0.0f;
        o->dir.normalize();
    } else {
        o->dir = vs->dir;
    }
    const V10e810* d = &vs->dir;
    if (o->level != 3) {
        f32 hi = f10e810_hi(o->who, o->level, mode, self);
        f32 lo = f10e810_lo(o->who, o->level, mode, self);
        if (mode && self && o->vt->kind(o) == 3) {
            hi += hi;
            lo += lo;
        }
        if (hi < d->w) {
            if (o->level < 2) o->level++;
        } else if (d->w < lo) {
            if (o->level > 0) o->level--;
        }
    }
    f32 f = f10e810_dist(o, o->level);
    o->dir.w = f;
    if (self && f == 0.0f) {
        if (o->flags & 0x10) {
            o->dir += o->fwd * 0.4f;
            o->dir.normalize();
            o->dir.w = f10e810_dist(o, 1);
            if (0.97f < o->fwd.dot(*d)) o->flags &= ~0x10;
        } else {
            if (D_003a9040 && o->fwd.dot(*d) < 0.5f) o->flags |= 0x10;
        }
        o->flags &= ~0x40;
    } else {
        o->flags &= ~0x10;
    }
    f32 reach = o->reach;
    f32 limit = reach;
    if (self && 0.0f < vs->x) limit = reach + vs->x;
    switch (func_0010e6e0(o, &o->dir, o->dir.w, reach, limit)) {
    case 0:
    case 2:
        break;
    case 1: {
        if (!o->f1544 && o->h1520 != 0xffff && func_00143f28(o->h1520, 0) == 4) break;
        V10e810 p, a, b;
        Seg10e810 s;
        V10e810 out;
        p = *f10e810_attach(o);
        p.y -= o->f1532 * 0.4f;
        { register f32 w asm("$f1") = *(volatile f32*)&o->dir.w; f32 f = *(volatile f32*)&o->f1456; a = o->dir * (f + w); }
        a.w = 1.0f;
        f32 len = a.normalize();
        b = o->up.cross(a);
        b.normalize();
        a = b.cross(o->up);
        a.normalize();
        a *= len;
        a = p + a;
        a.w = 1.0f;
        s.p = p;
        s.q = a;
        if (func_00143ae0(&s, &b, &out, (s32)(o->bits >> 3) & 0xf)) {
            p = *f10e810_attach(o);
            f10e810_warp(o, 3, reach);
        }
        break;
    }
    default:
        o->dir.w = 0.0f;
        o->f3288++;
        break;
    }
    if (d->w < 8.0f && vs->x < -250.0f) {
        o->dir.w = 0.0f;
        o->f3288++;
    }
    if (!(o->flags & 0x20000) && o->f2064 && D_00341708 && !D_00341708->f2064 && 80.0f < o->own.x) {
        f10e810_warp(o, 3, reach);
    }
}
}
