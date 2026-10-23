#include "../common/types.h"
extern "C" {
struct V129960 {
    f32 x, y, z, w;
    V129960() {}
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V129960(const V129960& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V129960& operator=(const V129960& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    void cross(const V129960& a, const V129960& b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
    V129960& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M129960 {
    V129960 r[4];
    M129960& operator=(const M129960& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0011b6a8(M129960*);
/* Re-orthonormalize a matrix's rotation rows, keeping each row's length;
   when the x row is nearly vertical, rebuild the basis around an up axis. */
void func_00129960(const M129960* src, M129960* dst)
{
    V129960 x(src->r[0]);
    V129960 y(src->r[1]);
    V129960 z(src->r[2]);
    f32 lx = x.normalize();
    f32 ly = y.normalize();
    f32 lz = z.normalize();
    f32 xy = x.y;
    if (0.6499999761581421f <= xy || xy <= -0.6499999761581421f) {
        func_0011b6a8(dst);
        V129960 up;
        if (xy < 0.0f) { up.set(0.0f, -1.0f, 0.0f, 0.0f); dst->r[0] = up; }
        else { up.set(0.0f, 1.0f, 0.0f, 0.0f); dst->r[0] = up; }
        dst->r[2].cross(dst->r[0], y);
        dst->r[2].normalize();
        dst->r[1].cross(dst->r[2], dst->r[0]);
        dst->r[1].normalize();
        dst->r[0] *= lx;
        dst->r[1] *= ly;
        dst->r[2] *= lz;
        dst->r[3] = src->r[3];
    } else {
        *dst = *src;
    }
}
}
