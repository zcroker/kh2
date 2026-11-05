// w2492: unchanged best (cmp2 24). Tried pos=&local (const and non-const pos), lp/dp pointer locals at top (103+ diffs).
// near-miss: 25 diff lines (m.sh), 34 by the coord count, flags -O2 (nsa/-g/nogcse no help). Coord draft unchanged.
// w2397: tried cam accessor forms, pointer locals for &d/&local, pos=&local reuse, operator-/static sub forms,
// __builtin_expect on all 6 tests (pairs): all keep &local's in-loop range copy in s4 (orig s1 shared with pos).
#include "../common/types.h"
// VU0 vector/matrix helpers (inline asm: the original uses the VU0 macro library).
#define QCOPY16b(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_16b(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV16b {
    f32 x, y, z, w;
    QV16b() {}
    QV16b(const QV16b& o) { QCOPY16b(this, &o); }
    QV16b& operator=(const QV16b& o) { if (this != &o) QCOPY16b(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM16b {
    QV16b r[4];
    QM16b() {}
    QM16b(const QM16b& o) { QCOPY4_16b(this, &o); }
    QM16b& operator=(const QM16b& o) { QCOPY4_16b(this, &o); return *this; }
    void apply(QV16b* o, const QV16b* v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(o), "r"(this), "r"(v) : "memory");
    }
    QV16b operator*(const QV16b& v) const {
        QV16b o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Obj16b { u8 pad0[0x10c]; u32 flags; };
static inline void vsub16b(QV16b* o, const QV16b* a, const QV16b* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline f32 normalize16b(QV16b* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
extern "C" {
u8* func_00106a60(s32);
Obj16b* func_001b9bc8(Obj16b*);
s32 func_0016a020(Obj16b*);
QV16b* func_0016c028(Obj16b*);

}
// partial asm: register pins and empty ties steer allocation only (closest plain C: 24 lines, regalloc only).
extern "C" {
Obj16b* func_0016b8b8(s32 kind0, const QV16b* pos0) {
    s32 kind = kind0;
    register const QV16b* pos asm("$17") = pos0;
    QM16b m;
    QV16b local;
    QV16b d;
    Obj16b* o = 0;
    Obj16b* best = 0;
    u8* cam = func_00106a60(1);
    f32 bestDist = 0.0f;
    m = *(QM16b*)(cam ? cam + 16 : 0);
    m.invOrtho(); asm("" : "+r"(pos));
    register QV16b* q asm("$7") = &local; asm("" : "+r"(q)); m.apply(q, pos); pos = q; asm("" : "+r"(pos));register QV16b* dp asm("$16") = &d; asm("" : "+r"(dp));
    while ((o = func_001b9bc8(o)) != 0) {
        if (func_0016a020(o) != kind) continue;
        if (o->flags & 0x2000) continue;
        vsub16b(dp, func_0016c028(o), pos);
 f32 len = normalize16b(dp);
        Obj16b* other = best;
        if (!best || len < bestDist) {
            bestDist = len;
            best = o;
        } else {
            other = o;
        }
        if (other && (other->flags & 0x1000)) other->flags |= 0x2000;
    }
    if (best) best->flags |= 0x1000;
    return best;
}
}
