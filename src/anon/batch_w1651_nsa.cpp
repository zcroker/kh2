#include "../common/types.h"
inline void* operator new(unsigned int, void* p) { return p; }
struct W1651Vec {
    f32 x, y, z, w;
    W1651Vec() {}
    W1651Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1651Vec& operator=(const W1651Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1651Vec operator-(const W1651Vec& o) const {
        W1651Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1651Mtx {
    W1651Vec r[4];
    W1651Mtx() {}
    W1651Mtx& operator=(const W1651Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    void inverse(const W1651Mtx& src) {
        *this = src;
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    W1651Vec operator*(const W1651Vec& v) const {
        W1651Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
// Double-buffered transform entry (144 bytes); the owner picks the current buffer.
struct W1651Entry { W1651Mtx m[2]; s32 pad80[4]; };
struct W1651Owner { u8 pad[0x808]; s32 cur; };
struct W1651Ref { W1651Owner* owner; W1651Entry* entry; };
struct W1651Actor;
extern "C" {
extern s8 D_01d48c98;
extern W1651Vec D_01d48ca0;
void func_001b3740(void);
void func_002fd188(void (*)(void));
W1651Vec* func_0016c028(W1651Actor*);
f32 func_002f8ad0(f32, f32);
void func_001835a0(W1651Actor*, f32);
W1651Vec func_001b3428(W1651Ref* ref, W1651Actor* act)
{
    if (!D_01d48c98) {
        new (&D_01d48ca0) W1651Vec(0.0f, 0.0f, 1.0f, 0.0f);
        D_01d48c98 = 1;
        func_002fd188(func_001b3740);
    }
    W1651Vec pos;
    W1651Vec dir;
    W1651Mtx m;
    W1651Vec* pd = &dir;
    W1651Mtx* pm = &m;
    pos = *func_0016c028(act);
    pos.w = 1.0f;
    pm->inverse(ref->entry->m[ref->owner->cur]);
    W1651Vec ret;
    ret = m * pos;
    ret.w = 1.0f;
    *pd = m * D_01d48ca0;
    m = ref->entry->m[ref->owner->cur ^ 1];
    ret = m * ret - pos;
    *pd = m * *pd;
    func_001835a0(act, func_002f8ad0(pd->x, pd->z));
    return ret;
}
}
