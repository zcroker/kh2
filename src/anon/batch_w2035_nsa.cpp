#include "../common/types.h"

struct V1dbd68 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Box1dbd68 { V1dbd68 lo, hi; };
static inline void VAdd1dbd68(V1dbd68* d, const V1dbd68* a, const V1dbd68* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
extern "C" {
extern s8 D_01d5bac0;
extern s8 D_01d5bac8;
extern V1dbd68 D_01d5bad0;
extern V1dbd68 D_01d5bae0;
void func_001dbf80(void);
void func_001dbf88(void);
s32 func_002fd188(void (*)(void));
void func_001a7790(Box1dbd68*);
void Aabbox_1dbd68(Box1dbd68*, const V1dbd68*, const V1dbd68*) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");
/* Two function-local statics (guard byte + vector, destructor thunk registered
   with atexit), written out by hand so the thunks keep their own addresses. */
// 001dbd68: moved to src/anon/unit_001dbbe0.cpp
}

/* 001f1728 left out: its VU0 copies need tag comments that only stop gcc cross-jumping (owner rule). */

struct M2efe18 { u8 pad0[48]; f32 time; };
struct O2efe18 { u8 pad0[320]; M2efe18 mot; };
extern "C" {
extern f32 D_00349e10;
f32 func_001806f8(M2efe18*, s32);
f32 func_00180770(M2efe18*, s32);
f32 func_002f8b00(f32, f32);
f32 func_002efe18(O2efe18* o, s32 id, f32 dt) {
    M2efe18* m = &o->mot;
    f32 t = m->time + D_00349e10 + dt;
    f32 s0 = func_001806f8(m, -1);
    f32 e0 = func_00180770(m, -1);
    f32 s1 = func_001806f8(m, id);
    f32 e1 = func_00180770(m, id);
    f32 r;
    if (e0 < s0 && e1 < s1) {
        if (e0 < t) {
            f32 d = s1 - e1;
            r = (t - e0) / (s0 - e0);
            return e1 + func_002f8b00(d * r, d);
        }
        r = t / e0;
        return func_002f8b00(e1 * r, e1);
    }
    r = t / s0;
    return func_002f8b00(s1 * r, s1);
}
}
