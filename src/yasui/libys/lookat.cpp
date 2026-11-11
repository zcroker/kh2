#include "../../common/types.h"

// YS::LOOKAT (0x1b0448-0x1b13d8): head/eye look-at control (aim with yaw/pitch limits, facing
// cone test). Assembled from the matched per-function sources; each source's declarations stay
// in their own namespace (srcN) and every external symbol is bound by asm label. The VU0 and
// lq/sq code is hand-written inline asm, as in the original.

// ==== from src/anon/batch_w213.cpp
namespace src0 {


struct S1b0 { u32 a; u32 pad[2]; u32 b; };

struct R16 { u8 pad[6]; u16 h; };
extern R16* func_0016bc20(u32, u32, s32) asm("func_0016bc20");

}

// 1b0448
namespace src0 {
void func_001b0448(S1b0* a0, u32 a1) asm("func_001b0448");
void func_001b0448(S1b0* a0, u32 a1) {
    R16* v = func_0016bc20(a1, 12, -1);
    if (v) { a0->a = a1; asm volatile("" ::: "memory"); a0->b = v->h; }
}
}

// ==== from src/anon/batch_w19.cpp
namespace src1 {


struct Ref0498 { u8* o; u32 x; bool f; };

}

// 1b0498
namespace src1 {
bool func_001b0498(Ref0498* p) asm("func_001b0498");
bool func_001b0498(Ref0498* p) {  // obj_check_ready_flags
    u8* o = p->o;
    if (!o) return false;
    return (u8)(!p->f & 1) || (*(u32*)(o + 352) & 0x4000000) != 0;
}
}

// ==== from src/anon/auto80_199_queue.cpp
namespace src2 {
u32 func_0019ba60(...) asm("func_0019ba60");
u32 func_001ad9c8(...) asm("func_001ad9c8");
u32 func_001b0498(u32 a0) asm("func_001b0498");
void func_0016c2b0(void* a0, u32 a1) asm("func_0016c2b0");
void func_001b0940(u32 a0, void* a1) asm("func_001b0940");

}

// 1b04d8
namespace src2 {
void func_001b04d8(u32 a0) asm("func_001b04d8");
void func_001b04d8(u32 a0) {
    u32 s0 = a0;

    if (func_001b0498(s0) == 0) {  // obj_check_ready_flags
        const f32 z = 0.0f;
        u32 t7 = 1;
        if (*(f32*)(s0 + 20) == z) {
            t7 = 0;
        }
        u32 t6 = t7 & 0xff;
        if (t6 != 0) {
            *(f32*)(s0 + 16) = z;
        }
        return;
    }

    func_001ad9c8(s0 + 16);  // float_accumulate_clamped

    if (*(f32*)(s0 + 16) == 0.0f) {
        *(u32*)(s0 + 4) = 0;
    }

    if (*(u32*)(s0 + 4) != 2) {
        return;
    }

    u32 v0 = func_0019ba60(*(u32*)(s0 + 48));
    if (v0 != 0) {
        u8 tmp[16];
        func_0016c2b0(tmp, *(u32*)(s0 + 48));
        func_001b0940(s0, tmp);
    } else {
        *(u32*)(s0 + 4) = 0;
    }
}
}

// ==== from src/anon/batch_w278.cpp
namespace src3 {

struct Vq278 {
    f32 x, y, z, w;
    Vq278& operator=(const Vq278& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Res278 { Vq278 v; u64 id:16; u64 flag:1; u64 rest:47; };

struct Src278 { u8 pad[4]; s32 type; u8 pad2[4]; u16 id; u8 pad3[2]; f32 t; u8 pad4[12]; Vq278 v; };
extern s8 D_01c940c0 asm("D_01c940c0");
extern Res278 D_01c940d0 asm("D_01c940d0");
void func_001b13d0() asm("func_001b13d0");
void func_002fd188(void (*)()) asm("func_002fd188");
s32 func_001b0498(Src278*) asm("func_001b0498");
f32 cosf(f32) asm("cosf");

}

// 1b0580
namespace src3 {
Res278* func_001b0580(Src278* s) asm("func_001b0580");
Res278* func_001b0580(Src278* s) {
    if (!D_01c940c0) {
        D_01c940c0 = 1;
        func_002fd188(func_001b13d0); /* static local dtor registration */
    }
    if (!func_001b0498(s)) return 0;
    switch (s->type) {
    case 0:
        return 0;
    case 1:
    case 2:
        D_01c940d0.v = s->v;
        D_01c940d0.v.w = (1.0f - cosf(s->t * 3.1415927f)) * 0.5f;
        asm volatile("" ::: "memory");
        D_01c940d0.id = s->id;
        D_01c940d0.flag = 0;
        break;
    case 3:
        D_01c940d0.v = s->v;
        D_01c940d0.v.w = (1.0f - cosf(s->t * 3.1415927f)) * 0.5f;
        asm volatile("" ::: "memory");
        D_01c940d0.id = s->id;
        D_01c940d0.flag = 1;
        break;
    }
    return &D_01c940d0;
}
}

// ==== from src/anon/tiny_auto80_queue.cpp
namespace src4 {
void func_001ad990(u32, f32, f32, f32) asm("func_001ad990");
void func_001ad990(u32, f32, f32, f32) asm("func_001ad990");
void func_001ad990(u32, f32, f32, f32) asm("func_001ad990");

}

// 1b0700
namespace src4 {
void func_001b0700(u8* a0, f32 a1) asm("func_001b0700");
void func_001b0700(u8* a0, f32 a1) {
    func_001ad990((u32)(a0 + 16), *(f32*)(a0 + 16), 0.0f, a1);
}
}

// ==== from src/anon/batch_w44.cpp
namespace src5 {


struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_001ad990(void*, f32, f32, f32) asm("func_001ad990");

}

// 1b0728
namespace src5 {
void func_001b0728(u8* o, Q16* q, u32 c, f32 f) asm("func_001b0728");
void func_001b0728(u8* o, Q16* q, u32 c, f32 f) {
    if (*(s32*)(o + 12) >= 0) {
        *(u32*)(o + 4) = 1;
        Q16* d = (Q16*)(o + 32);
        if (d != q) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(q) : "$8", "memory");
        func_001ad990(o + 16, 0.0f, 1.0f, f);
        *(u32*)(o + 8) = c;
    }
}
}

// ==== from src/anon/batch_w79.cpp
namespace src6 {

typedef unsigned int u128 __attribute__((mode(TI)));


struct Q16 {
    u128 v;
    Q16() {}
    Q16(const Q16& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};


struct OBv { u32 f0; volatile s32 f4; s32 f8; volatile s32 f12; u8 pad16[32]; volatile s32 f48; u8 pad52[12]; Q16 v64; s32 f80; };


struct VB { u16 a, b, c, d; };
void func_0016af58(Q16*, void*) asm("func_0016af58");
void* func_0016bc20(u32, s32, s32) asm("func_0016bc20");
void func_001ad990(void*, f32, f32, f32) asm("func_001ad990");

}

// 1b0798
namespace src6 {
void func_001b0798(OBv* o, s32 a, s32 b, f32 t) asm("func_001b0798");
void func_001b0798(OBv* o, s32 a, s32 b, f32 t) {
    VB* v;
    Q16 tmp;
    if (*(s32*)((u8*)o + 12) < 0) return;
    v = (VB*)func_0016bc20(o->f0, 20, -1);
    if (v == 0) return;
    {
    Q16* d = &o->v64;
    o->f12 = v->d;
    o->f4 = 2;
    o->f48 = a;
    func_0016af58(&tmp, (void*)a);
    *d = tmp;
    }
    *(f32*)&o->f80 = 0.0f;
    func_001ad990(&o->f8 + 2, *(f32*)&o->f80, 1.0f, t);
    o->f8 = b;
}
}

// ==== from src/anon/batch_w45.cpp
namespace src7 {
void func_001b08e8(u8*, u32) asm("func_001b08e8");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");

}

// 1b0858
namespace src7 {
void func_001b0858(u8* a0, f32 f, u32 a1, u32 a2) asm("func_001b0858");
void func_001b0858(u8* a0, f32 f, u32 a1, u32 a2) {
    if (*(s32*)(a0 + 12) >= 0) {
        *(u32*)(a0 + 4) = 3;
        func_001b08e8(a0, a1);
        func_001ad990(a0 + 16, 0.0f, 1.0f, f);
        *(u32*)(a0 + 8) = a2;
    }
}
}

// ==== from src/anon/batch_w54.cpp
namespace src8 {

typedef unsigned int u128 __attribute__((mode(TI)));


// 128-bit value with a self-checking lq/sq copy
struct Q16 {
    u128 v;
    Q16& operator=(const Q16& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

// same, but the original leaves the jr ra delay slot empty
static inline f32 vu0_normalize_nr(Q16& v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
}

// 1b08c8
namespace lookat {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
void func_001b08c8(u8* p, const Q16* v) asm("func_001b08c8");
void func_001b08c8(u8* p, const Q16* v) {
    Q16* d = (Q16*)(p + 32);
    if (d != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(v) : "$8", "memory");
}
}

// 1b08e8
namespace src8 {
void func_001b08e8(u8* p, const Q16* v) asm("func_001b08e8");
void func_001b08e8(u8* p, const Q16* v) {
    Q16* d = (Q16*)(p + 32);
    *d = *v;
    vu0_normalize_nr(*d);
}
}

// ==== from src/anon/batch_w2477_nsa.cpp
namespace src9 {
// 001b0940: aim a direction toward a target with per-frame and absolute yaw/pitch limits (VU0 vector helpers).
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
s32 func_0019ba60(u32) asm("func_0019ba60");
Tgt09* func_0016bc20(u32, s32, s32) asm("func_0016bc20");
Pair09 func_0018a818(u32, Tgt09*) asm("func_0018a818");
V09 func_0016af58(u32) asm("func_0016af58");
void func_0011b6a8(M09*) asm("func_0011b6a8");
void func_0011b6d8(M09*, f32) asm("func_0011b6d8");
void func_0011b720(M09*, f32) asm("func_0011b720");
void func_0011b768(M09*, f32) asm("func_0011b768");
f32 func_0017d160(V09, V09) asm("func_0017d160");
f32 fabsf(f32) asm("fabsf");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");


f32 dotr(const V09&, const V09&) asm("func_0017d160");
}

// 1b0940
namespace src9 {
void func_001b0940(Obj09* o, V09* target) asm("func_001b0940");
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
    f = fabsf(func_0017d160(ch, dh));
    if (lim < f) {
        a = lim;
        V09 c = ch ^ dh;
        if (c.y < 0.0f) a = -0.08726646f;
        M09 m;
        func_0011b6a8(&m);
        func_0011b720(&m, a);
        dh = m * ch;
    }
    f = fabsf(func_0017d160(bh, dh));
    if (maxYaw < f) {
        a = maxYaw;
        V09 c = bh ^ dh;
        if (c.y < 0.0f) a = -maxYaw;
        M09 m;
        func_0011b6a8(&m);
        func_0011b720(&m, a);
        dh = m * bh;
    }
    f32 f3 = fabsf(func_0017d160(cv, dv));
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
    f = fabsf(func_0017d160(bv, dv));
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

// ==== from src/anon/batch_wcx2_nsa.cpp
namespace src10 {

// Functions that only match with -fno-strict-aliasing (gcc 3.2 combines freed
// stack temporaries only without strict aliasing).

// --------------------
// 001b1100: is the target point inside the facing cone? (flattened direction vs dir,
// cone 15 degrees, or the lock-on target's own range in degrees)
struct V1b1100 {
    f32 x, y, z, w;
    V1b1100() {}
    V1b1100(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1b1100(const V1b1100& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V1b1100& operator=(const V1b1100& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1b1100 operator-(const V1b1100& b) const
    {
        V1b1100 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1b1100& normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct Pair1b1100 { V1b1100 a, b; };

struct Obj1b1100 { u8 pad[1344]; V1b1100 pos; V1b1100 dir; };

struct Tgt1b1100 { u8 pad[16]; s16 range; };
Tgt1b1100* func_0016bc20(Obj1b1100*, s32, s32) asm("func_0016bc20");
f32 func_0017d160(V1b1100, V1b1100) asm("func_0017d160");
Pair1b1100 func_0018a818(Obj1b1100*, Tgt1b1100*) asm("func_0018a818");
f32 fabsf(f32) asm("fabsf");

bool t1b1100(Obj1b1100*, V1b1100*) asm("_Z16ctarget_001b1100jjjj");
}

// 1b1100
namespace src10 {
bool t1b1100(Obj1b1100* o, V1b1100* target)
{
    V1b1100 d;
    Tgt1b1100* t = func_0016bc20(o, 20, -1);
    if (!t) {
        d = *target - o->pos;
        V1b1100 v;
        v.x = d.x; v.z = d.z; v.w = v.y = 0.0f;
        v.normalize();
        return fabsf(func_0017d160(v, o->dir)) < 0.26179937f;
    } else {
        Pair1b1100 p = func_0018a818(o, t);
        d = *target - p.b;
        d.normalize();
        V1b1100 v;
        v.x = d.x; v.z = d.z; v.w = v.y = 0.0f;
        v.normalize();
        return fabsf(func_0017d160(v, o->dir)) <= t->range * 0.017453292f;
    }
}
}

// ==== from src/anon/batch_w12.cpp
namespace src11 {
void func_0016c2b0(void*) asm("func_0016c2b0");
void func_001b1100(u32, void*) asm("func_001b1100");

void ctarget_001b1328(u32, u32, u32, u32) asm("_Z16ctarget_001b1328jjjj");
}

// 1b1328
namespace src11 {
void ctarget_001b1328(u32 a, u32 b, u32 c, u32 d) {
    u8 buf[16];
    func_0016c2b0(buf);
    func_001b1100(a, buf);
}
}

// ==== from src/anon/batch_w46.cpp
namespace src12 {
u8* func_001b9bc8(u8*) asm("func_001b9bc8");

}

// 1b1360
namespace src12 {
void func_001b1360(s32 from, s32 to) asm("func_001b1360");
void func_001b1360(s32 from, s32 to) {
    u8* o = 0;
    while ((o = func_001b9bc8(o))) {
        if (*(s32*)(o + 1188) == 2 && *(s32*)(o + 1232) == from) *(s32*)(o + 1232) = to;
    }
}
}


// 1b13d0: the destructor of func_001b0580's static result (empty), registered with atexit there.
namespace lookat {
void func_001b13d0(void) asm("func_001b13d0");
void func_001b13d0(void) {}
}
