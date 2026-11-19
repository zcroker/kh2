// 0x1c6a28-0x1c6c60: spawner file, "drop at a random ground point" (state set by 0x1c6c60). Written from
// the retail disassembly; the V/M helpers are the file's usual VU asm idiom (see unit_001c5b90.cpp).
// `f32 one = 1.0f` declared first is what gives gcc the retail register/schedule order.
#include "../common/types.h"
// gap (state set by 0x1c6c60): drop at a random ground point
namespace n001c6a28 {
struct V {
    f32 x, y, z, w;
    V() {}
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V operator-(const V& b) const
    {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V operator*(f32 k) const
    {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    V operator*(const V& v) const {
        V o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct N { V pos; u8 pad0[5]; u8 alpha; u8 pad1[60]; u8 slot; };
struct HIT { V pos; u8 rest[16]; } __attribute__((aligned(16)));
s32 func_001d35e0(HIT*, const V&, const V&, u32) asm("func_001d35e0");
s32 func_001d36e8(HIT*) asm("func_001d36e8");
s32 func_001c5f90(N*) asm("func_001c5f90");
extern u32 D_003638d0 asm("D_003638d0");
extern M D_01d49830 asm("D_01d49830");
extern s32 D_01d498a8 asm("D_01d498a8");
extern s32 D_01d498b0 asm("D_01d498b0");
static inline f32 frand() { D_003638d0 *= 0x10dcd; return (f32)D_003638d0 * 2.3283064e-10f; }
static inline f32 frange(f32 lo, f32 hi) { return lo + frand() * (hi - lo); }
static inline void rnd(V& o) { f32 one = 1.0f; f32 x = frange(-400.0f, 400.0f); f32 z = -(frand() * 400.0f); o.x = x; o.y = 0.0f; o.w = one; o.z = z; }
static inline s32 ground(V* v, V* b, HIT* h) { *v = D_01d49830 * *v; *b = *v; v->y = -10000.0f; b->y = 10000.0f; return func_001d35e0(h, *v, *b, 1); }
void func_001c6a28(N* o) asm("func_001c6a28");
void func_001c6a28(N* o) {
    V v, b;
    HIT h;
    rnd(v);
    if (!ground(&v, &b, &h)) return;
    if (func_001d36e8(&h) != 1) return;
    v = h.pos;
    v.y -= 115.2f;
    o->pos = v;
    if (D_01d498a8 < 1000 - D_01d498b0) {
        if (func_001c5f90(o)) D_01d498a8++;
    }
}
}  // namespace n001c6a28
