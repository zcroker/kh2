#include "../common/types.h"

// ---- 001a49f8: direction vector (normalised, y flattened)
namespace n001a49f8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Scale(const QWord& a, const f32& k)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Obj1a4 {
    u32 pad0;
    u32 flags;
    u8 pad8[0xe0 - 8];
    QWord pos;
    QWord prev;
};
extern "C" {
void func_0016af58(QWord*, u32);
QWord* func_0016c028(u32);

static inline QWord Back(u32 id)
{
    QWord t;
    func_0016af58(&t, id);
    return Scale(t, -1.0f);
}
static inline QWord Dir(Obj1a4* o, u32 id)
{
    if (o->flags & 0x20) return Back(id);
    if (o->flags & 4) return Sub(o->pos, o->prev);
    return Sub(*func_0016c028(id), o->pos);
}
QWord func_001a49f8(Obj1a4* o, u32 id)
{
    QWord r;
    r = Dir(o, id);
    if (r.v[0] == 0.0f && r.v[2] == 0.0f) {
        QWord t;
        func_0016af58(&t, id);
        r = Scale(t, -1.0f);
    }
    r.v[1] = 0.0f;
    Normalize(&r);
    r.v[3] = 1.0f;
    return r;
}
}
}
