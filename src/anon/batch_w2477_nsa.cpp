// 001b0940: aim a direction toward a target with per-frame and absolute yaw/pitch limits (VU0 vector helpers).
#include "../common/types.h"
struct V09 {
    f32 x, y, z, w;
    V09() {}
    V09(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V09(const V09& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V09& operator=(const V09& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V09 operator-(const V09& b) const
    {
        V09 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V09 operator+(const V09& b) const
    {
        V09 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V09 operator*(f32 k) const
    {
        V09 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V09 operator^(const V09& b) const
    {
        V09 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct M09 {
    V09 r[4];
    M09() {}
    V09 operator*(const V09& v) const
    {
        V09 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Pair09 { V09 a, b; };
struct Tgt09 { u8 pad[16]; s16 yaw; s16 pitch; };
struct Obj09 { u32 actor; u8 pad[28]; V09 pos; V09 x30; V09 dir; f32 angle; };
extern "C" {
s32 func_0019ba60(u32);
Tgt09* func_0016bc20(u32, s32, s32);
Pair09 func_0018a818(u32, Tgt09*);
V09 func_0016af58(u32);
void func_0011b6a8(M09*);
void func_0011b6d8(M09*, f32);
void func_0011b720(M09*, f32);
void func_0011b768(M09*, f32);
f32 func_0017d160(V09, V09);
f32 func_002f8870(f32);
f32 func_002f8ad0(f32, f32);

f32 dotr(const V09&, const V09&) asm("func_0017d160");
static inline f32 func_002f8870x(f32 x){return x;}
void func_001b0940(Obj09* o, V09* target)
{
    f32 a = 0.017453292f;
    f32 lim = 0.08726646f;
    f32 lim3 = 0.0523598753f;
    f32 f;
    if (!func_0019ba60(o->actor)) return;
    Tgt09* t = func_0016bc20(o->actor, 20, -1);
    if (!t) return;
    Pair09 p = func_0018a818(o->actor, t);
    f32 maxYaw = t->yaw * a;
    f32 maxPitch = t->pitch * a;
    V09 d = *target - p.b;
    f32 dist = d.normalize();
    V09 dh(d.x, 0.0f, d.z, 0.0f);
    f32 lh = dh.normalize();
    V09 dv(lh, d.y, 0.0f, 0.0f);
    dv.normalize();
    V09 cur = o->dir;
    V09 ch(cur.x, 0.0f, cur.z, 0.0f);
    f32 lc = ch.normalize();
    V09 cv(lc, cur.y, 0.0f, 0.0f);
    cv.normalize();
    V09 base = func_0016af58(o->actor);
    V09 bh(base.x, 0.0f, base.z, 0.0f);
    f32 lb = bh.normalize();
    V09 bv(lb, base.y, 0.0f, 0.0f);
    bv.normalize();
    {
        M09 m;
        func_0011b6a8(&m);
        func_0011b720(&m, o->angle);
        ch = m * bh;
    }
    f = func_002f8870(func_0017d160(ch, dh));
    if (lim < f) {
        a = lim;
        V09 c = ch ^ dh;
        if (c.y < 0.0f) a = -0.08726646f;
        M09 m;
        func_0011b6a8(&m);
        func_0011b720(&m, a);
        dh = m * ch;
    }
    f = func_002f8870(func_0017d160(bh, dh));
    if (maxYaw < f) {
        a = maxYaw;
        V09 c = bh ^ dh;
        if (c.y < 0.0f) a = -maxYaw;
        M09 m;
        func_0011b6a8(&m);
        func_0011b720(&m, a);
        dh = m * bh;
    }
    f32 f3 = func_002f8870(func_0017d160(cv, dv));
    if (lim3 < f3) {
        a = lim3;
        V09 c = cv ^ dv;
        if (c.z < 0.0f) a = -0.0523598753f;
        M09 m;
        func_0011b6a8(&m);
        func_0011b768(&m, a);
        dv = m * cv;
    } else {
        dv = cv;
    }
    f = func_002f8870(func_0017d160(bv, dv));
    if (maxPitch < f) {
        a = maxPitch;
        V09 c = bv ^ dv;
        if (c.z < 0.0f) a = -maxPitch;
        M09 m;
        func_0011b6a8(&m);
        func_0011b768(&m, a);
        dv = m * bv;
    }
    f32 yaw = func_002f8ad0(dh.x, dh.z);
    f32 pitch = func_002f8ad0(dv.y, dv.x);
    {
        M09 m;
        func_0011b6a8(&m);
        func_0011b6d8(&m, -pitch);
        func_0011b720(&m, yaw);
        o->dir = m.r[2];
        { V09 t1(bh); V09 t2(dh); o->angle = dotr(t1, t2); }
        if ((bh ^ dh).y < 0.0f) o->angle = -o->angle;
        o->pos = o->dir * dist + p.b;
        o->pos.w = 1.0f;
    }
}



}
