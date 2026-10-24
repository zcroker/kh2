#include "../common/types.h"
// Built with -g and -fno-strict-aliasing (_gnsa).

// 002e6930: path direction at time t: normalized (key[i+1] - key[i]) with y/z flipped, w = 0.
// The key positions are their own vector type (KV), which lets their loads move above the QV stack stores.
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV& operator=(const QV& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    QV operator-(const QV& b) const {
        QV r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QV* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct KV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct PathKey { KV pos; KV pad; };
struct Path { u32 pad0; s32 count; f32 start; u32 padc; PathKey key[1]; };
static inline QV conv(const KV& p) { return QV(p.x, -p.y, -p.z, 0.0f); }
extern "C" {
void func_002e6930(Path* p, QV* out, f32 t)
{
    s32 n = p->count - 1;
    s32 i = (s32)(t - p->start);
    if (i < 0) i = 0;
    if (i >= n) {
        QV a = conv(p->key[n - 1].pos);
        QV b = conv(p->key[n].pos);
        QV d = b - a;
        *out = d;
    } else {
        QV a = conv(p->key[i].pos);
        QV b = conv(p->key[i + 1].pos);
        QV d = b - a;
        *out = d;
    }
    Normalize(out);
}
}
