#include "../common/types.h"

// Motion joint solver, second variant (sibling of func_00129c38).
// Per joint: expression channels, constraint scan, then one of
//   - 0x200000: plain local rotation (optional rebuild from rot)
//   - mode 1: one-bone IK, mode 2/3: two-bone IK (with optional ground entities)
//   - mode 0: constraint driven (copy/aim) or plain FK
// and finally an optional look-at target.

struct MotVec {
    f32 x, y, z, w;
    MotVec() {}
    MotVec(const MotVec& o) {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    MotVec& operator=(const MotVec& o) {
        if (this != &o) asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32& operator[](s32 i) { return (&x)[i]; }
    f32 normalize() {
        f32 len;
        asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void cross(const MotVec& a, const MotVec& b) {
        asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&a), "r"(&b) : "memory");
    }
} __attribute__((aligned(16)));

static inline MotVec operator-(const MotVec& a, const MotVec& b) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline MotVec motLerp(const MotVec& a, const MotVec& b, f32 t) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}

struct MotMtx {
    MotVec r[4];
    MotMtx() {}
    MotMtx(const MotMtx& o) {
        asm volatile(".set noreorder\n\t"
                     "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    MotMtx& operator=(const MotMtx& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // general 4x4 (affine) inverse in place
    void inverse() {
        asm volatile(".set noreorder\n\t"
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
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));

static inline MotMtx operator*(const MotMtx& a, const MotMtx& b) {
    MotMtx r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline MotVec operator*(const MotMtx& m, const MotVec& v) {
    MotVec r;
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}

// out = this * (v.xyz, 1), w = 1
static inline void motXfpt(MotVec* out, const MotMtx* m, const MotVec* v) {
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "vmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
// out.xyz = this * (v.xyz, 1), w kept
static inline void motXfp(MotVec* out, const MotMtx* m, const MotVec* v) {
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "sqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
// out.xyz = rotation part * v.xyz
static inline void motRot3(MotVec* out, const MotMtx& mr, const MotVec* v) {
    const MotMtx* m = &mr;
    asm volatile(".set noreorder\n\t"
             "lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
                 "sqc2 $vf4, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}

struct MotBone {            // 64 bytes: rest pose entry
    s16 index;
    s16 pad2;
    s16 parent;             // 0x04
    s16 pad6;
    u8 pad8[0x14];
    f32 len;                // 0x1c
    MotVec rot;             // 0x20
    MotVec trans;           // 0x30
};

struct MotExpr {            // 8 bytes
    u16 joint;
    u16 channel;
    u16 pad4;
    u16 node;
};

struct MotConstraint {      // 12 bytes
    u8 type;
    u8 active;
    u16 joint;
    u16 source;
    u16 limiter;
    u16 pad8;
    u16 padA;
};

struct MotLimiter { u8 pad[0x30]; };

struct MotHeader {
    u8 pad0[0x10];
    u16 boneCount;          // 0x10
    u16 jointCount;         // 0x12
    u8 pad14[4];
    s32 restOff;            // 0x18
    s32 jointOff;           // 0x1c
    u8 pad20[0x30];
    s32 constraintOff;      // 0x50
    s32 constraintCount;    // 0x54
    u8 pad58[4];
    s32 limiterOff;         // 0x5c
    s32 exprOff;            // 0x60
    s32 exprCount;          // 0x64
    u8 pad68[0x38];
    s32 tableA0Off;         // 0xa0
};

struct MotSkel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual f32 slotValue(s32);     // vtable + 0x14
    virtual s32 slotJoint(s32);     // vtable + 0x18
    virtual void v7();
    virtual MotBone* getBones();    // vtable + 0x20
};

struct MotPose {
    u8 pad0[0x14];
    MotSkel* skel;          // 0x14
    u8 pad18[4];
    MotVec* scale;          // 0x1c
    MotVec* rot;            // 0x20
    MotVec* trans;          // 0x24
    MotMtx* local;          // 0x28
    MotMtx* world;          // 0x2c
};

struct MotCtx {
    u8 pad0[4];
    MotHeader* mot;         // 0x04
    MotMtx* work;           // 0x08 world matrices, all joints
    MotMtx* localX;         // 0x0c local matrices of the extra (non-skeleton) joints
    MotMtx* worldX;         // 0x10 world matrices of the extra joints
};

struct MotTarget {          // look-at target
    MotVec pos;             // w = blend
    union {
        u64 flags;          // 0x10000: pos is a direction
        u16 joint;
    } u;
};

struct MotEnt {             // 0x20: ground/contact entity list, ends with flag bit 53
    MotVec pos;
    union {
        u64 flags;
        u32 lo;
    } u;                    // 0x10
    f32 yofs;               // 0x18
    u16 joint;              // 0x1c
    u16 pad1e;
};

extern "C" {

void func_0011b6a8(MotMtx*);
u32 FMatrix_rotateX(MotMtx*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
void FMatrix_rotateXYZ(MotMtx*, MotVec*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
void func_0011bac8(MotMtx*, MotVec*);
void gm__GRID__draw(MotVec*, MotVec*, s32, f32, f32, MotMtx*, MotMtx*, f32, f32, MotVec*);
void func_00128040(MotCtx*, void*, MotVec*, MotVec*);
void func_00128d40(MotVec*, MotVec*, MotMtx*);
void func_00128e98(MotCtx*, MotPose*, u32, u32, MotVec*, MotMtx*, MotVec*);
void func_00129008(MotCtx*, MotPose*, MotConstraint*, MotVec*, MotMtx*, MotVec*);
f32 kn__MotionPrototype0__evalExpression(MotCtx*, MotPose*, u16);
void func_00129960(MotMtx*, MotMtx*);
s32 func_00143c68(MotVec*, MotVec*);

static inline MotBone* motRest(MotHeader* m, s32 i) {
    return (MotBone*)((u8*)m + m->restOff) + (i - m->boneCount);
}
static inline MotBone* motBone(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return pose->skel->getBones() + i;
    return motRest(m, i);
}
static inline MotVec* motRot(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->rot[i];
    return &motRest(m, i)->rot;
}
static inline MotVec* motTrans(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->trans[i];
    return &motRest(m, i)->trans;
}
static inline MotMtx* motLocal(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->local[i];
    return &ctx->localX[i - m->boneCount];
}
static inline MotMtx* motWorld(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->world[i];
    return &ctx->worldX[i - m->boneCount];
}
static inline void motSetRot(MotMtx* m, MotVec* r) { func_0011bac8(m, r); }
static inline void motRotXYZ(MotMtx* m, MotVec* r) { FMatrix_rotateXYZ(m, r); }
static inline void motIK2(MotVec* a, MotVec* b, f32& l1, f32& l2, MotMtx* m1, MotMtx* m2, f32& r1, f32& r2, s32 type, MotVec* pole) {
    gm__GRID__draw(a, b, type, l1, l2, m1, m2, r1, r2, pole);
}
static inline void motIK1(MotVec* a, MotVec* b, f32& l1, MotMtx* m1, f32& r1, MotVec* pole) {
    gm__GRID__draw(a, b, 0, l1, 0.0f, m1, 0, r1, 0.0f, pole);
}
static inline void motLimit(MotCtx* ctx, void* lim, MotVec v, MotVec* io) { func_00128040(ctx, lim, &v, io); }
static inline bool motIsEndType(s32 t) {
    switch (t) {
    case 0: case 1: case 5:
        return true;
    }
    return false;
}

void func_0012d728(MotCtx* ctx, MotPose* pose, MotMtx* base, MotTarget* tgt, MotEnt* ents);  // 0x0012d728: definition moved into src/anon/unit_00128480.cpp

}
