#include "../common/types.h"

// Curve evaluation for a looping key list (0x0022fe08). VU0 vector ops are inline asm.
struct SplV3 { f32 x, y, z; };

struct SplVec {
    f32 x, y, z, w;
    SplVec() {}
    SplVec(f32 x_, f32 y_, f32 z_, f32 w_) { x = x_; y = y_; z = z_; w = w_; }
    SplVec& operator=(const SplVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

static inline SplVec operator*(const SplVec& v, f32 k) {
    SplVec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(k) : "$8", "memory");
    return r;
}
static inline SplVec operator-(const SplVec& a, const SplVec& b) {
    SplVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline SplVec operator+(const SplVec& a, const SplVec& b) {
    SplVec r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

// One key: position plus outgoing and incoming Bezier control points.
struct SplKey { SplV3 pos; SplV3 out; SplV3 in; f32 pad; };
struct Spline { u8 pad0[6]; s16 num; s16 type; u8 pad1[6]; SplKey key[1]; };

#define SPL_VEC(v) (v).x, (v).y, (v).z, 0.0f

extern "C" {
void func_0022f928(SplVec* out, const SplVec* p0, const SplVec* p1, const SplVec* m0, const SplVec* m1, f32 t);
void func_0022fb98(SplVec* out, const SplVec* a, const SplVec* b, const SplVec* c, const SplVec* d, f32 t);

void func_0022fe08(SplVec* out, f32 t, Spline* s, s32 idx) {
    s32 n = s->num;
    s32 i = idx % n;
    s32 ip = (i + n - 1) % n;
    s32 i1 = (i + 1) % n;
    s32 i2 = (i + 2) % n;
    SplVec m0, m1;
    SplKey* k = s->key;

    switch (s->type) {
    case 0: { // linear
        SplVec a(SPL_VEC(k[i].pos));
        SplVec b(SPL_VEC(k[i1].pos));
        *out = a * (1.0f - t) + b * t;
        break;
    }
    case 1: { // Bezier, converted to Hermite tangents
        SplVec a(SPL_VEC(k[i].out));
        SplVec b(SPL_VEC(k[i].pos));
        SplVec c(SPL_VEC(k[i1].pos));
        SplVec d(SPL_VEC(k[i1].in));
        m0 = (a - b) * 3.0f;
        m1 = (c - d) * 3.0f;
        func_0022f928(out, &b, &c, &m0, &m1, t);
        break;
    }
    case 2: { // uniform B-spline
        SplVec a(SPL_VEC(k[ip].pos));
        SplVec b(SPL_VEC(k[i].pos));
        SplVec c(SPL_VEC(k[i1].pos));
        SplVec d(SPL_VEC(k[i2].pos));
        func_0022fb98(out, &a, &b, &c, &d, t);
        break;
    }
    case 3: { // Catmull-Rom
        SplVec a(SPL_VEC(k[i1].pos));
        SplVec b(SPL_VEC(k[ip].pos));
        SplVec c(SPL_VEC(k[i2].pos));
        SplVec d(SPL_VEC(k[i].pos));
        m0 = (a - b) * 0.5f;
        m1 = (c - d) * 0.5f;
        func_0022f928(out, &d, &a, &m0, &m1, t);
        break;
    }
    }
}
}
