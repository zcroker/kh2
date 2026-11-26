// Linked unit 0x1ca148-0x1ca638: rest of the file that unit_001c9ea0.cpp starts ("dead_crash").
// .rodata at 0x36e0d0. Built with -fno-strict-aliasing (old copy from a _nsa file).

#include "../common/types.h"

// ---- 001ca148 from src/anon/batch_w1719_nsa.cpp
namespace n001ca148 {
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
extern W1719Cfg* D_00351f34 asm("D_00351f34");
extern f32 D_00349e10 asm("D_00349e10");
W1719Vec YS__OBJ__get_dir(W1719Obj*) asm("YS__OBJ__get_dir");
W1719Vec* YS__OBJ__get_pos(W1719Obj*) asm("YS__OBJ__get_pos");
W1719Vec YS__MATH__VectorRotY(f32, const W1719Vec&) asm("YS__MATH__VectorRotY");
W1719Vec YS__OBJ__get_lightcycle_movement(f32 width, W1719Obj* a, W1719Obj* b) asm("YS__OBJ__get_lightcycle_movement");
W1719Vec YS__OBJ__get_lightcycle_movement(f32 width, W1719Obj* a, W1719Obj* b) {
    W1719Vec dirA = YS__OBJ__get_dir(a);
    W1719Vec aimA, axis, toB;
    W1719Vec* posA = YS__OBJ__get_pos(a);
    w1719_scale(&toB, &dirA, D_00351f34->reach);
    w1719_scale(&axis, &toB, D_00349e10);
    w1719_add(&aimA, posA, &axis);
    W1719Vec dirB = YS__OBJ__get_dir(b);
    W1719Vec posB = *YS__OBJ__get_pos(b);
    W1719Vec side;
    W1719Vec r;
    r.zero();
    axis = YS__MATH__VectorRotY(1.57079625f, dirB);
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
}  // namespace n001ca148

// ---- 001ca448 from src/anon/batch_w31.cpp
namespace n001ca448 {
int func_001ca448(u8* p) asm("func_001ca448");
int func_001ca448(u8* p) {                      
    switch (*(s32*)(p + 340)) {
    case 16:
    case 44:
        return 0;
    case 161: {
        u32 m = *(u32*)(p + 1416) & 0x80;
        return m == 0;
    }
    default:
        return 1;
    }
}
}  // namespace n001ca448

// ---- 001ca498 from src/anon/tiny_more.cpp
namespace n001ca498 {
u32 func_001ca498(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_001ca498jjjj");
u32 func_001ca498(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v = (u32)((s32)(*(u32*)((u32)a0 + (340))) + (-31)); return (v < (u32)2); }
}  // namespace n001ca498

// ---- 001ca4a8 from src/anon/batch_w1568.cpp
namespace n001ca4a8 {
#define QCOPY_w1568(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_w1568_ca {
    f32 x, y, z, w;
    QV_w1568_ca() {}
    QV_w1568_ca(const QV_w1568_ca& o) { QCOPY_w1568(this, &o); }
    f32 dot(const QV_w1568_ca& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct E_w1568_ca { u8 pad[0x1c]; s32 x1c; u8 pad2[8]; f32 x28; u8 pad3[0x2d4]; u8 x300[0x288]; u32 flags; u8 pad4[0x314]; QV_w1568_ca vel; };
void YS__OBJ__get_dir(QV_w1568_ca*, E_w1568_ca*) asm("YS__OBJ__get_dir");
s32 func_0018ee60(s32, s32, E_w1568_ca*, QV_w1568_ca*, s32) asm("func_0018ee60");
void func_001880b0(void*, const char*) asm("func_001880b0");
s32 func_001ca498(E_w1568_ca*) asm("func_001ca498");
s32 func_00186d18(E_w1568_ca*) asm("func_00186d18");
void func_00187818(E_w1568_ca*) asm("func_00187818");
void YS__ACTION_LIGHTCYCLE__CheckCrash(E_w1568_ca* e) asm("YS__ACTION_LIGHTCYCLE__CheckCrash");
void YS__ACTION_LIGHTCYCLE__CheckCrash(E_w1568_ca* e)
{
    QV_w1568_ca v(e->vel);
    f32 len = v.normalize();
    v.w = len;
    if (len < 1.0f) return;
    QV_w1568_ca d;
    YS__OBJ__get_dir(&d, e);
    if (v.dot(d) < -0.866f) {
        if (e->flags & 0x80) {
            QV_w1568_ca t;
            YS__OBJ__get_dir(&t, e);
            func_0018ee60(0, 992, e, &t, 1);
        } else {
            func_001880b0(e->x300, "dead_crash");
        }
    } else if (func_001ca498(e) || func_00186d18(e)) {
        if (e->flags & 0x80) {
            if (func_0018ee60(0, 993, e, &v, 1)) e->x28 *= 0.5f;
        } else {
            func_00187818(e);
        }
    }
    e->x1c = 0;
}
}  // namespace n001ca4a8

