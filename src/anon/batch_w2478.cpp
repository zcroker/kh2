// 00129060: motion expression evaluator (recursive). Matched w2478: a function-level result r shared by cases 11/29/43.
#include "../common/types.h"

// Motion expression evaluator (expression nodes of the motion data; joints, math, logic, curves).

struct MotVec {
    f32 x, y, z, w;
    MotVec() {}
    MotVec(const MotVec& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    f32& operator[](s32 i) { return (&x)[i]; }
    f32 length() const {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
                     : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

static inline MotVec operator-(const MotVec& a, const MotVec& b) {
    MotVec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

struct MotMtx {
    MotVec r[4];
} __attribute__((aligned(16)));

struct MotBone {            // 64 bytes: rest pose entry
    u8 pad0[0x10];
    MotVec scale;           // 0x10
    MotVec rot;             // 0x20
    MotVec trans;           // 0x30
};

struct MotNode {            // 12 bytes: expression node
    s8 op;
    u8 world : 1;
    u16 joint;              // 0x02
    f32 value;              // 0x04
    u16 a;                  // 0x08
    u16 b;                  // 0x0a
};

struct MotKey { u8 pad[6]; };

struct MotHeader {
    u8 pad0[0x10];
    u16 boneCount;          // 0x10
    u16 jointCount;         // 0x12
    u8 pad14[4];
    s32 restOff;            // 0x18
    u8 pad1c[0x14];
    s32 keyOffA;            // 0x30
    u32 keyCountA;          // 0x34
    s32 keyOffB;            // 0x38
    u8 pad3c[0x2c];
    s32 nodeOff;            // 0x68
    u32 nodeCount;          // 0x6c
    u8 pad70[0x28];
    f32 frameRate;          // 0x98
};

struct MotPose {
    u8 pad0[0x1c];
    MotVec* scale;          // 0x1c
    MotVec* rot;            // 0x20
    MotVec* trans;          // 0x24
    MotMtx* local;          // 0x28
    MotMtx* world;          // 0x2c
};

struct MotCtx {
    u8 pad0[4];
    MotHeader* mot;         // 0x04
    MotMtx* work;           // 0x08
    MotMtx* localX;         // 0x0c
    MotMtx* worldX;         // 0x10
    MotVec* workScale;      // 0x14
};

static inline MotBone* motRest(MotHeader* m, s32 i) {
    return (MotBone*)((u8*)m + m->restOff) + (i - m->boneCount);
}
static inline MotVec* motRot(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->rot[i];
    return &motRest(m, i)->rot;
}
static inline MotVec* motScale(MotCtx* ctx, MotPose* pose, s32 i) {
    MotHeader* m = ctx->mot;
    if (i < m->boneCount) return &pose->scale[i];
    return &motRest(m, i)->scale;
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

extern "C" {

extern f32 D_00347b70;
f32 sinf(f32);
f32 cosf(f32);
f32 func_002f8a18(f32);
f32 func_002f8ab8(f32);
f32 acos_2f8aa0(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
f32 atanf(f32);
f32 func_002f8b18(f32);
f32 func_002f8ae8(f32);
f32 fabsf(f32);
f32 f_powf(f32, f32);
f32 func_002f8b00(f32, f32);
void func_0011bac8(MotMtx*, MotVec*);
void func_001285f8(MotCtx*, f32, s32*, s32*);
f32 func_00128750(MotCtx*, MotKey*, s32, s32, f32);

f32 kn__MotionPrototype0__evalExpression(MotCtx* ctx, MotPose* pose, u16 idx);  // 0x00129060: definition moved into src/anon/unit_00128480.cpp

}
