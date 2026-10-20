#include "../common/types.h"
#define W1719_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1719Vec {
    f32 x, y, z, w;
    W1719Vec() {}
    W1719Vec(const W1719Vec& o) { W1719_QCOPY(this, &o); }
    W1719Vec& operator=(const W1719Vec& o) {
        if (this != &o) W1719_QCOPY(this, &o);
        return *this;
    }
    W1719Vec operator*(f32 k) const {
        W1719Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    W1719Vec operator+(const W1719Vec& o) const {
        W1719Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    W1719Vec operator-(const W1719Vec& o) const {
        W1719Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1719Zero : W1719Vec {
    W1719Zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
};
static inline W1719Vec w1719_cross(const W1719Vec& a, const W1719Vec& b) {
    W1719Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void w1719_add(W1719Vec* r, const W1719Vec* a, const W1719Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline void w1719_scale(W1719Vec* r, const W1719Vec* a, f32 k) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "f"(k) : "$8", "memory");
}
struct W1719Obj;
struct W1719Cfg { f32 f0; f32 reach; };
extern "C" {
extern W1719Cfg* D_00351f34;
extern f32 D_00349e10;
W1719Vec func_0016af58(W1719Obj*);
W1719Vec* func_0016c028(W1719Obj*);
W1719Vec func_0017d538(f32, const W1719Vec&);

// Compares object b's position with object a's facing direction.
// Returns { x: side sign (+1/-1), y: 0, z: width-test sign (+1/-1/0), w: distance }.
W1719Vec func_001ca148(f32 width, W1719Obj* a, W1719Obj* b) {
    W1719Vec dirA = func_0016af58(a);
    W1719Vec aimA, axis, toB;
    W1719Vec* posA = func_0016c028(a);
    w1719_scale(&toB, &dirA, D_00351f34->reach);
    w1719_scale(&axis, &toB, D_00349e10);
    w1719_add(&aimA, posA, &axis);
    W1719Vec dirB = func_0016af58(b);
    W1719Vec posB = *func_0016c028(b);
    W1719Vec side;
    W1719Vec r;
    r.zero();
    axis = func_0017d538(1.57079625f, dirB);
    toB = posB - dirB * width - aimA;
    side = w1719_cross(axis, toB);
    if (side.y < 0.0f) {
        r.z = 1.0f;
    } else {
        toB = posB + dirB * width - aimA;
        side = w1719_cross(axis, toB);
        if (side.y > 0.0f) r.z = -1.0f;
    }
    axis = posB - aimA;
    r.w = axis.normalize();
    side = w1719_cross(axis, dirA);
    if (side.y < 0.0f) r.x = 1.0f;
    else r.x = -1.0f;
    return r;
}
}
