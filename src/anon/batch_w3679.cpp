// 00178330: camera-relative direction from a stick vector (copy camera matrix, transpose, multiply, normalize).
#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Mtx {
    QWord r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    void transpose() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tlq $11, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tpcpyud $11, $13, $15\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    QWord operator*(const QWord& v) const {
        QWord o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct CamBase { u8 pad[16]; };
struct Cam : CamBase, Mtx {};
extern "C" {
Cam* func_00106a60(s32);
QWord* ctarget_00178330(QWord* out, const QWord* in) asm("_Z16ctarget_00178330jjjj");
QWord* ctarget_00178330(QWord* out, const QWord* in) {
    if (in->f[3] > 0.0f) {
        Mtx m;
        QWord v;
        v.f[0] = in->f[0];
        v.f[1] = 0.0f;
        v.f[2] = -in->f[1];
        v.f[3] = 0.0f;
        Cam* c = func_00106a60(1);
        // Partial asm (no instructions): the original saves s2 without using it (a pseudo dropped after
        // reload); an empty asm writing $18 reproduces the save.
        { register u32 r18 asm("$18"); asm volatile("" : "=r"(r18)); }
        m = *static_cast<Mtx*>(c);
        m.transpose();
        *out = m * v;
        out->f[1] = 0.0f;
        Normalize(out);
        out->f[3] = in->f[3];
    } else {
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(out) : "memory");
    }
    return out;
}

}

extern "C" {
extern void* D_00361f60;
// The minigame type() method, declared without its argument: a0 already holds the object from the
// branch delay slot. Partial asm: the empty asm keeps the then-block from starting with the
// argument move, so reorg fills the beqz slot from the join's move a0,s0 and branches past it,
// leaving the jal slot empty as in the original (passing p gives a second move a0,s0).
int minigame_type_a0(void) asm("_ZN2Ti8MiniGame4typeEv");
void func_002e2660(void*);
// Runs the current minigame's type() (when one exists), then func_002e2660 on it.
void func_002e2d50(void) {
    void* p = D_00361f60;
    if (p != 0) {
        asm volatile("");
        minigame_type_a0();
    }
    func_002e2660(p);
}
}
