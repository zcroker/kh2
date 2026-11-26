// Joint limit clamp 0x128040 (own unit: it needs -fno-rerun-loop-opt, which its neighbours do not take).
// With a signed loop counter the soft-edge loop counts up as in retail only when loop.c does not run its
// second pass (the second pass reverses it: li s0,2 / bgez). VU0 vector helpers are inline asm as in
// the other kn vector code; the soft path pins base in $f2 and the two hoisted 0.0f in $f21/$f22.
#include "../common/types.h"

struct LVec {
    f32 x, y, z, w;
    LVec() {}
    LVec& operator=(const LVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32& operator[](s32 i) { return (&x)[i]; }
    f32 length() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                     : : "r"(this), "f"(s) : "$8", "memory");
    }
    void zero() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));

static inline LVec operator-(const LVec& a, const LVec& b) {
    LVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline LVec operator+(const LVec& a, const LVec& b) {
    LVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

// Joint limit shape: kind 1 = sphere (radius lo[0]), else box lo..hi with
// per-axis enables; soft > 0 gives an exponential soft edge of width margin.
struct Limit {
    u64 kind : 3;
    u64 noOrigin : 1;
    u8 en0 : 1; u8 en1 : 1; u8 en2 : 1; u8 en3 : 1; u8 en4 : 1; u8 en5 : 1;
    u64 rest : 54;
    f32 margin;     // 0x08
    f32 soft;       // 0x0c
    LVec lo;        // 0x10
    LVec hi;        // 0x20
};

extern "C" {
f32 func_002f8ae8(f32);


}

// Clamps *io (relative to origin *org) into the limit shape; returns whether it moved.
extern "C" bool func_00128040(void* ctx, Limit* lim, LVec* org, LVec* io) {
    bool hit = false;
    s32 i;
    LVec c;
    if (lim->kind != 0 && !lim->noOrigin) c = *org;
    else c.zero();
    LVec d;
    d = *io - c;
    if (lim->kind == 1) {
        f32 r = lim->lo.x;
        f32 len = d.length();
        f32 nl = len; if (lim->soft == 0.0f) { if (r < len) { apply: d.normalize(); d.scale(nl); *io = c + d; hit = true; } } else { f32 over = len - (r - lim->margin); if (0.0f < over) { f32 e = func_002f8ae8((lim->soft - 1.0f) * (over / lim->margin)); f32 t = lim->margin * (1.0f - e); nl = (r - lim->margin) + t; goto apply; } }
    } else {
        u8 en[6];
        en[0] = lim->en0; en[1] = lim->en1; en[2] = lim->en2;
        en[3] = lim->en3; en[4] = lim->en4; en[5] = lim->en5;
        if (lim->soft == 0.0f) {
            for (i = 0; i < 3; i++) {
                if (en[i * 2] && d[i] < lim->lo[i]) {
                    (*io)[i] = c[i] + lim->lo[i];
                    hit = true;
                } else if (en[i * 2 + 1] && d[i] > lim->hi[i]) {
                    (*io)[i] = c[i] + lim->hi[i];
                    hit = true;
                }
            }
        } else {
register f32 z1 asm("$f21") = 0.0f; f32 z2 = z1; { f32* pc; f32* pio; i = 0; pio=&io->x; pc=&c.x;
for (; i < 3; pio++, pc++, i++) {
                register f32 base asm("$f2"); f32 k, m, ov, x;
                if (en[i * 2] && (m = lim->margin, x = d[i], z1 < (ov = lim->lo[i] + m - x))) { ov = ov / m; m = lim->soft; m = m - 1.0f; m = m * ov;
                    f32 e = func_002f8ae8(m);
                    hit = true;
                    base = lim->lo[i];
                    base += lim->margin;
                    k = 1.0f - e;
                 } else if (en[i * 2 + 1] && (m = lim->margin, z2 < (ov = d[i] - (lim->hi[i] - m)))) { ov = ov / m; m = lim->soft; m = m - 1.0f; m = m * ov;
                    f32 e = func_002f8ae8(m);
                    hit = true;
                    base = lim->hi[i];
                    base -= lim->margin;
                    k = 1.0f - e;
                } else  continue;
                { f32 t = lim->margin * k; x = *pc; x += base; x += t; *pio = x; }
            }
        }
}
}
done:
    io->w = 1.0f;
    return hit;
}


