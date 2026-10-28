#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
extern "C" {
// VU0 macro-mode vector/matrix helpers (hand-written asm in the original math library)
struct V1118a8 {
    f32 x, y, z, w;
    V1118a8() {}
    void set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1118a8(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V1118a8& operator=(const V1118a8& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1118a8 operator-(const V1118a8& b) const
    {
        V1118a8 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1118a8 operator*(f32 k) const
    {
        V1118a8 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    f32 dot(const V1118a8& o) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&o) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline V1118a8 operator*(f32 k, const V1118a8& v) { return v * k; }
struct M1118a8 {
    V1118a8 r[4];
    M1118a8() {}
    M1118a8& operator=(const M1118a8& o)
    {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // out = this * (v.xyz, 1), w = 1
    void xfpt(V1118a8* out, const V1118a8& v) const
    {
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                     "vmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                     : : "r"(out), "r"(this), "r"(&v) : "memory");
    }
} __attribute__((aligned(16)));
struct Fr1118a8 {
    u8 pad0[112];
    V1118a8 v112;
    u8 pad1[1712 - 128];
    M1118a8 mtx;
};
extern s8 D_003a99a0;
extern V1118a8 D_003a99b0[2];
extern Fr1118a8* D_00341708[3];
extern V1118a8 D_00341720[3];
extern V1118a8 D_00341750[3];
void func_002fd188(void (*)(void));
void func_001135b0(void);
V1118a8* f1118a8_attach(Fr1118a8*) asm("func_0016c028");
f32 func_00111808(Fr1118a8*);
void func_001118a8(void)
{
    if (!D_003a99a0) {
        new (&D_003a99b0[0]) V1118a8(0.86f, 0.0f, 0.51f, 1.0f);
        new (&D_003a99b0[1]) V1118a8(-0.86f, 0.0f, 0.51f, 1.0f);
        D_003a99a0 = 1;
        func_002fd188(func_001135b0);
    }
    s32 i;
    for (i = 0; i < 3; i++) D_00341750[i] = D_00341720[i];
    Fr1118a8* leader = D_00341708[0];
    D_00341720[0] = *f1118a8_attach(leader);
    V1118a8 p, t, d;
    d = D_00341720[0] - D_00341750[0];
    s32 best[2];
    M1118a8 m;
    m = leader->mtx;
    m.r[3] = leader->v112;
    f32 bestDist[2];
    for (s32 k = 0; k < 2; k++) {
        best[k] = -1;
        bestDist[k] = 0.0f;
        Fr1118a8* f = D_00341708[k + 1];
        if (!f) continue;
        for (i = 0; i < 2; i++) {
            t = func_00111808(f) * D_003a99b0[i];
            m.xfpt(&p, t);
            d = p - *f1118a8_attach(f);
            f32 dist = d.dot(d);
            if (best[k] < 0 || dist < bestDist[k]) {
                bestDist[k] = dist;
                best[k] = i;
                D_00341720[k + 1] = p;
            }
        }
    }
    if (!D_00341708[1] || !D_00341708[2]) return;
    if (bestDist[1] < bestDist[0]) {
        if (best[0] != best[1]) return;
        best[0] ^= 1;
        f32 sc = func_00111808(D_00341708[1]);
        t = sc * D_003a99b0[best[0]];
        m.xfpt(&D_00341720[1], t);
    } else {
        if (best[1] != best[0]) return;
        best[1] ^= 1;
        f32 sc = func_00111808(D_00341708[2]);
        t = sc * D_003a99b0[best[1]];
        m.xfpt(&D_00341720[2], t);
    }
}
}
