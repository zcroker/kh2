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
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
f32 func_002f8a18(f32);
f32 func_002f8ab8(f32);
f32 acos_2f8aa0(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
f32 func_002f8420(f32);
f32 func_002f8b18(f32);
f32 func_002f8ae8(f32);
f32 func_002f8870(f32);
f32 f_powf(f32, f32);
f32 func_002f8b00(f32, f32);
void func_0011bac8(MotMtx*, MotVec*);
void func_001285f8(MotCtx*, f32, s32*, s32*);
f32 func_00128750(MotCtx*, MotKey*, s32, s32, f32);

f32 func_00129060(MotCtx* ctx, MotPose* pose, u16 idx) {
    MotHeader* hdr = ctx->mot;
    f32 r;
    if (idx >= hdr->nodeCount) return 0.0f;
    {
        MotNode* nodes = (MotNode*)((u8*)hdr + hdr->nodeOff);
        MotNode* n = &nodes[idx];
        switch (n->op) {
        case 0: return func_002f8960(func_00129060(ctx, pose, n->a) * 0.017453292f);
        case 1: return func_002f87c0(func_00129060(ctx, pose, n->a) * 0.017453292f);
        case 2: return func_002f8a18(func_00129060(ctx, pose, n->a) * 0.017453292f);
        case 3: return func_002f8ab8(func_00129060(ctx, pose, n->a)) * 57.295776f;
        case 4: return acos_2f8aa0(func_00129060(ctx, pose, n->a)) * 57.295776f;
        case 5: return func_002f8420(func_00129060(ctx, pose, n->a)) * 57.295776f;
        case 6: return func_002f8b18(func_00129060(ctx, pose, n->a));
        case 7: return func_002f8ae8(func_00129060(ctx, pose, n->a));
        case 8: return func_002f8870(func_00129060(ctx, pose, n->a));
        case 9: {
            f32 a = func_00129060(ctx, pose, n->a);
            return f_powf(a, func_00129060(ctx, pose, n->b));
        }
        case 10: return __builtin_sqrtf(func_00129060(ctx, pose, n->a));
        case 11: {
            f32 a = func_00129060(ctx, pose, n->a);
            r = func_00129060(ctx, pose, n->b);
            if (a < r) return a;
            return r;
        }
        case 12: {
            f32 a = func_00129060(ctx, pose, n->a);
            f32 b = func_00129060(ctx, pose, n->b);
            if (b < a) return a;
            return b;
        }
        case 13: {
            MotNode* p = &nodes[n->a];
            f32 sum = 0.0f;
            s32 cnt = 0;
            while (p->a < hdr->nodeCount) {
                sum += func_00129060(ctx, pose, p->a);
                cnt++;
                p = &nodes[p->b];
            }
            return sum / cnt;
        }
        case 14:
            if (func_00129060(ctx, pose, nodes[n->a].a) != 0.0f)
                return func_00129060(ctx, pose, nodes[nodes[n->a].b].a);
            return func_00129060(ctx, pose, nodes[nodes[nodes[n->a].b].b].a);
        case 16:
            return (motWorld(ctx, pose, n->a)->r[3] - motWorld(ctx, pose, n->b)->r[3]).length();
        case 17: {
            f32 a = func_00129060(ctx, pose, n->a);
            return func_002f8b00(a, func_00129060(ctx, pose, n->b));
        }
        case 18: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a + func_00129060(ctx, pose, n->b);
        }
        case 19: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a - func_00129060(ctx, pose, n->b);
        }
        case 20: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a * func_00129060(ctx, pose, n->b);
        }
        case 21: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a / func_00129060(ctx, pose, n->b);
        }
        case 22: {
            s32 a = (s32)func_00129060(ctx, pose, n->a);
            return (f32)(a % (s32)func_00129060(ctx, pose, n->b));
        }
        case 23: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a == func_00129060(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 24: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a > func_00129060(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 25: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a >= func_00129060(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 26: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a < func_00129060(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 27: {
            f32 a = func_00129060(ctx, pose, n->a);
            return a <= func_00129060(ctx, pose, n->b) ? 1.0f : 0.0f;
        }
        case 28:
            return (func_00129060(ctx, pose, n->a) != 0.0f && func_00129060(ctx, pose, n->b) != 0.0f) ? 1.0f : 0.0f;
        case 29:
            r = (func_00129060(ctx, pose, n->a) != 0.0f || func_00129060(ctx, pose, n->b) != 0.0f) ? 1.0f : 0.0f;
            return r;
        case 30: return D_00347b70;
        case 31: return n->value;
        case 32: case 33: case 34: {
            MotMtx* m = n->world ? motWorld(ctx, pose, n->joint) : motLocal(ctx, pose, n->joint);
            return m->r[3][n->op - 32];
        }
        case 35: case 36: case 37:
            if (n->world) {
                MotVec v(*motRot(ctx, pose, n->joint));
                func_0011bac8(&ctx->work[n->joint], &v);
                return v[n->op - 35] * 57.295776f;
            }
            return (*motRot(ctx, pose, n->joint))[n->op - 35] * 57.295776f;
        case 38: case 39: case 40:
            if (n->world) return ctx->workScale[n->joint][n->op - 38];
            return (*motScale(ctx, pose, n->joint))[n->op - 38];
        case 41: case 42:
            return 0.0f;
        case 15: case 43: {
            s32 lo, hi;
            f32 t = func_00129060(ctx, pose, n->a) * 60.0f / hdr->frameRate;
            func_001285f8(ctx, t, &lo, &hi);
            MotKey* k;
            if (n->b >= hdr->keyCountA) k = (MotKey*)((u8*)hdr + hdr->keyOffB) + (n->b - hdr->keyCountA);
            else k = (MotKey*)((u8*)hdr + hdr->keyOffA) + n->b;
            r = func_00128750(ctx, k, lo, hi, t);
            if (n->op == 43) r *= 57.295776f;
            return r;
        }
        }
    }
    return 0.0f;
}

}
