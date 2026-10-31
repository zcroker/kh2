#include "../common/types.h"
extern "C" void func_00190128(void*);
struct W1680QW {
    f32 x, y, z, w;
    W1680QW() {}
    W1680QW& operator=(const W1680QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1680Mtx {
    W1680QW r[4];
    W1680Mtx(const W1680Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
};
struct W1680Tgt {
    s32 a, b, c, d, e;
    W1680Tgt() { func_00190128(this); }
    void clear() { func_00190128(this); }
};
struct W1680Hit { s32 p0; f32 r; s32 p8; s32 z; W1680QW v; W1680Hit() { z = 0; } };
struct W1680Cam { u8 p0[16]; W1680Mtx m; };
struct W1680Self2 { u8 p0[64]; W1680QW pos; };
static inline void W1680_apply(W1680QW* out, const W1680Mtx* m, const W1680QW* v) {
    asm volatile("lqc2 $vf5,0(%1)\n\tlqc2 $vf1,0(%2)\n\tlqc2 $vf2,16(%2)\n\tlqc2 $vf3,32(%2)\n\tlqc2 $vf4,48(%2)\n\t"
                 "vmulax.xyz ACC,$vf1,$vf5x\n\tvmadday.xyz ACC,$vf2,$vf5y\n\tvmaddaz.xyz ACC,$vf3,$vf5z\n\t"
                 "vmaddw.xyz $vf5,$vf4,$vf0w\n\tvmove.w $vf5,$vf0\n\tsqc2 $vf5,0(%0)"
                 : : "r"(out), "r"(v), "r"(m) : "memory");
}
static inline void W1680_scale(W1680QW* r, const W1680QW* a, f32 k) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "f"(k) : "$8", "memory");
}
static inline void W1680_sub(W1680QW* r, const W1680QW* a, const W1680QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline void W1680_zw(W1680QW* v, f32 z) { v->w = z; v->z = z; }
static inline W1680QW operator*(const W1680Mtx& m, const W1680QW& v) { W1680QW r; W1680_apply(&r, &m, &v); return r; }
static inline W1680QW operator*(const W1680QW& v, f32 k) { W1680QW r; W1680_scale(&r, &v, k); return r; }
static inline W1680QW operator-(const W1680QW& a, const W1680QW& b) { W1680QW r; W1680_sub(&r, &a, &b); return r; }
static inline void W1680_mul(W1680QW& r, const W1680Mtx& m, const W1680QW& v) { W1680_apply(&r, &m, &v); }
extern "C" {
s32 W1680_is_exist(W1680Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 W1680_can_attack(W1680Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 W1680_is_culling(s32) asm("_ZN2YS3OBJ10is_cullingEv");
f32 W1680_getScreenZ(void*) asm("_ZNK2kn10Projection10getScreenZEv");
s32 func_00190730(W1680Tgt*, s32);
s32 func_00112d90(W1680Tgt*);
void* func_00106a18(s32);
W1680Cam* func_00106a60(s32);
W1680QW func_00190388(W1680Tgt*);
f32 func_002f8870(f32);
void func_0011a938(W1680Self2* self, W1680Tgt* out, f32 fx, f32 fy) {
    out->clear();
    f32 sz = W1680_getScreenZ(func_00106a18(0));
    W1680Cam* c = func_00106a60(0);
    W1680Mtx m(c ? c->m : *(W1680Mtx*)0);
    // Steers allocation only (emits nothing): the original keeps self out of s0 here.
    register u32 s0_busy asm("$16");
    asm volatile("" : "=r"(s0_busy));
    W1680Tgt it;
    W1680Hit hit;
    W1680QW p = m * self->pos;
    W1680QW center;
    center = p * (sz / p.z);
    it.clear();
    f32 best = fx * fx + fy * fy;
    s32 k = 0;
    W1680Mtx* pm = &m;
    while ((k = func_00190730(&it, k)) != 0) {
        if (!func_00112d90(&it)) continue;
        if (!W1680_can_attack(&it)) continue;
        if (W1680_is_culling(it.a)) continue;
        W1680QW p2;
        W1680QW s;
        W1680_mul(p2, *pm, func_00190388(&it));
        s = p2 * (sz / p2.z);
        W1680QW d = s - center;
        if (!(func_002f8870(d.x) <= fx)) continue;
        if (!(func_002f8870(d.y) <= fy)) continue;
        W1680_zw(&d, 0.0f);
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        if (!W1680_is_exist(out) || len < best) { best = len; *out = it; }
    }
}
}
