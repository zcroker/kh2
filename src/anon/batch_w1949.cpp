#include "../common/types.h"
extern "C" {
struct W1949Vec {
    f32 x, y, z, w;
    W1949Vec() {}
    W1949Vec(const W1949Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1949Hit { s32 a; f32 b; s32 x8; s32 c; W1949Vec v; W1949Hit() { c = 0; } };
struct W1949Obj { u8 pad[0x850]; W1949Vec p; };
static inline void w1949_scalew(W1949Vec* v) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
        : : "r"(v), "f"(v->w) : "$8", "memory");
}
static inline void w1949_add(W1949Vec* d, W1949Vec* s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(s) : "memory");
}
void* func_0016bc20(W1949Obj*, s32, s32);
void YS__COLLISION__set(W1949Hit*, W1949Obj*, void*);
W1949Obj* YS__OBJ__Each(W1949Obj*);
s32 func_0016bff0(W1949Obj*);
s32 func_0018a550(W1949Hit*, W1949Hit*);
void func_0018bfa0(W1949Obj*, W1949Obj*, f32);
W1949Obj* func_0018be00(W1949Obj* o, s32 k);  // 0x0018be00: definition moved into src/yasui/libys/npc.cpp
}
