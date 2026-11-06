#include "../common/types.h"
struct V124 {
    f32 x, y, z, w;
    V124() {}
    V124(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V124& operator=(const V124& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V124 operator-(const V124& b) const
    {
        V124 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V124 operator^(const V124& b) const
    {
        V124 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct M124 {
    V124 r[4];
    M124() {}
    void set(const V124& a, const V124& b, const V124& c) { r[0] = a; r[1] = b; r[2] = c; r[3].unit(); }
    M124& operator=(const M124& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    M124 operator*(const M124& b) const {
        M124 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
extern "C" {
void func_0011b6a8(M124*);
M124* func_0011b6d8(M124*, f32);
// 00124ca8: look-at view matrix (eye, target, optional up, roll); with proj, also a 2D correction from the triangle a, b, |target-eye|
void func_00124ca8(V124* eye, V124* tgt, s32 flip, M124* out, M124* proj, V124* upv, f32 a, f32 b, f32 roll, f32 roll2)
{
    V124 fwd(0.0f, 0.0f, 0.0f, 0.0f), up(0.0f, 0.0f, 0.0f, 0.0f), side(0.0f, 0.0f, 0.0f, 0.0f);
    M124 view, rot, m2;
    V124* pu = &up;
    V124* ps = &side;
    fwd = *tgt - *eye;
    f32 len = fwd.normalize();
    if (upv) {
        (*pu) = *upv - *eye;
        pu->normalize();
        (*ps) = fwd ^ (*pu);
        ps->normalize();
        (*pu) = (*ps) ^ fwd;
        pu->normalize();
    } else {
        pu->x = -fwd.y;
        pu->y = fwd.x;
        pu->z = 0.0f;
        pu->normalize();
        (*ps) = fwd ^ (*pu);
        ps->normalize();
    }
    view.set(fwd, (*pu), (*ps));
    if (roll != 0.0f) {
        func_0011b6a8(&rot);
        func_0011b6d8(&rot, roll);
        view = view * rot;
    }
    if (!proj) {
        *out = view;
        return;
    }
    f32 c = (len * len - a * a - b * b) / (2.0f * a * b);
    if (c > 1.0f) c = 1.0f;
    else if (c < -1.0f) c = -1.0f;
    f32 s = 1.0f - c * c;
    if (s < 0.0f) s = 0.0f;
    if (flip) s = -__builtin_sqrtf(s);
    else s = __builtin_sqrtf(s);
    proj->r[0].x = c;
    proj->r[0].y = s;
    proj->r[0].z = 0.0f;
    proj->r[0].w = 0.0f;
    proj->r[1].x = -s;
    proj->r[1].y = c;
    proj->r[1].z = 0.0f;
    proj->r[1].w = 0.0f;
    proj->r[2].x = 0.0f;
    proj->r[2].y = 0.0f;
    proj->r[2].z = 1.0f;
    proj->r[2].w = 0.0f;
    proj->r[3].x = 0.0f;
    proj->r[3].y = 0.0f;
    proj->r[3].z = 0.0f;
    proj->r[3].w = 1.0f;
    if (roll2 != 0.0f) {
        func_0011b6a8(&rot);
        func_0011b6d8(&rot, roll2);
        *proj = *proj * rot;
    }
    f32 x = (a + b * c) * len;
    f32 y = -(b * s) * len;
    f32 n = __builtin_sqrtf(x * x + y * y);
    x /= n;
    y /= n;
    m2.r[0].x = x;
    m2.r[0].y = y;
    m2.r[0].z = 0.0f;
    m2.r[0].w = 0.0f;
    m2.r[1].x = -y;
    m2.r[1].y = x;
    m2.r[1].z = 0.0f;
    m2.r[1].w = 0.0f;
    m2.r[2].x = 0.0f;
    m2.r[2].y = 0.0f;
    m2.r[2].z = 1.0f;
    m2.r[2].w = 0.0f;
    m2.r[3].x = 0.0f;
    m2.r[3].y = 0.0f;
    m2.r[3].z = 0.0f;
    m2.r[3].w = 1.0f;
    *out = view * m2;
}


}
