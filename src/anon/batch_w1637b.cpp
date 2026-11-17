#include "../common/types.h"

#define W1637B_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")

struct W1637BVec {
    f32 x, y, z, w;
    W1637BVec() {}
    W1637BVec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1637BVec(const W1637BVec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1637BVec& operator=(const W1637BVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W1637BMtx {
    W1637BVec r[4];
    W1637BMtx() {}
    W1637BMtx(const W1637BMtx& o) { W1637B_QCOPY4(this, &o); }
    W1637BMtx& operator=(const W1637BMtx& o) { if (this != &o) W1637B_QCOPY4(this, &o); return *this; }
    W1637BVec operator*(const W1637BVec& v) const {
        W1637BVec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1637BMtx operator*(const W1637BMtx& b) const {
        W1637BMtx o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));

struct W1637BMdl3;
typedef s32 (*W1637BMdl3Fn)(W1637BMdl3*, u32);
struct W1637BMdl3 { W1637BMdl3Fn* vt; };
struct W1637BModel { u8 p0[0x8b0]; W1637BMdl3* mdl; };
struct W1637BObj3 {
    u8 p0[0x40];
    W1637BMtx m040;          // 0x040
    u8 p080[0x5f0];
    W1637BModel* model;      // 0x670
    u8 p674[0x3c];
    W1637BMtx m6b0;          // 0x6b0
    u8 p6f0[0x1c0];
    W1637BMdl3* mdl;         // 0x8b0
};
struct W1637BInfo { u8 p0[0xc]; s32 f0c; W1637BVec pos; W1637BInfo() : f0c(0) {} };

extern "C" {
W1637BVec* func_0016c028(W1637BObj3*);
W1637BVec func_0016be98(W1637BObj3*);
f32 func_0016b518(W1637BObj3*, s32);
void* func_0016bc20(W1637BObj3*, s32, s32);
void func_0018a818(W1637BInfo*, W1637BObj3*, void*);
f32 func_0011d6c0(W1637BModel*, u32, W1637BMtx*);

f32 func_0016b0e0(W1637BObj3* o, u32 id, W1637BMtx* out);  // 0x0016b0e0: definition moved into src/anon/unit_00169f98.cpp
}
