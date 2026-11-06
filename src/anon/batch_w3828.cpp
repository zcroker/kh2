// 002eb1e8: vector distance check (C++ with VU0/lq inline asm helpers and register pins inherited from w3767; w3828 fixed the last delay slot with a tie on tb after func_002cbed8 and an empty tie on m)
#include "../common/types.h"
extern "C" {
struct V3 {
    f32 x, y, z, w;
    V3() {}
    V3& operator=(const V3& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct B3 { f32 v[8]; };
#define F3(o, off, T) (*(T*)((u8*)(o) + (off)))
extern u8* D_0034e948;
s32 func_002eb068(u8*);
void* func_0019b260(s32);
s32 func_00184eb8(u8*, s32, void*);
V3* func_0016c028(u8*);
void func_002cbec0(void*, V3*);
V3 func_002cbed8(void*);
V3 func_002eaf48(u8*, s32);
s32 func_002eaf40(u8*);
void func_00190128(B3*);
void func_00190878(B3*, s32, s32);
s32 func_001bd3e0(s32, s32, s32, B3*, s32, s32);
double func_00313b80(f32) __attribute__((const));
s32 func_003142e0(double, double) __attribute__((const));

static inline __attribute__((always_inline)) void vsub(const V3* a, const V3* b, V3* d) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
        : : "r"(a), "r"(b), "r"(d) : "memory");
}
static inline __attribute__((always_inline)) V3 operator-(const V3& a, const V3& b) {
    V3 r; vsub(&a, &b, &r); return r;
}
static inline __attribute__((always_inline)) f32 vlen(const V3* v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}

V3* func_002cbed8r(V3*, void*) asm("func_002cbed8");
V3* func_002eaf48r(V3*, u8*, s32) asm("func_002eaf48");
void func_002eb1e8(u8* self) {
    
    if (func_002eb068(self)) return;
    void* t = func_0019b260(F3(self, 0xb4c, s32));
    if (!t) return;
    if (!func_00184eb8(self, -1, t)) return;
    register void* m asm("$17") = F3(self, 0x508, void*);
    V3 d, B, A;
    register V3* ta asm("$20") = &A; asm("" : "+r"(ta));
    register V3* tb asm("$19") = &B;
    func_002cbec0(m, func_0016c028(self));
    { void* mm = m; asm("" : "+r"(mm)); func_002cbed8r(ta, mm); }
    asm volatile("" : "+r"(tb));
    vsub(ta, func_0016c028(self), tb);
    d = *tb;
    f32 len = vlen(&d);
    asm("" : "+r"(ta));
    func_002eaf48r(ta, self, 0);
    vsub(ta, func_0016c028(self), tb);
    d = *tb;
    if (func_003142e0(func_00313b80(len), 300.0) >= 0) return;
    if (!(300.0f < vlen(&d))) return;
    {
    register s32 o asm("$18") = F3(D_0034e948, 0xb44, s32);
    register s32 e asm("$17") = func_002eaf40(self);
    B3 b;
    register void* tc asm("$16") = &b;
    func_00190128((B3*)tc);
    func_00190878((B3*)tc, e, 0);
    func_001bd3e0(o, 1, 523, (B3*)tc, 1, 100);
    register int ph asm("$21"); asm volatile("" : "=r"(ph));
    }
}
}
