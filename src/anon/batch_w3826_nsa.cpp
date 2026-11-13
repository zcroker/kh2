// w3826: built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"
extern "C" {
struct V1d35e0 {
    f32 x, y, z, w;
    V1d35e0& operator=(const V1d35e0& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct L1d35e0 { V1d35e0 a, b; };
struct O1d35e0 { u8 pad[16]; s32 hit; s32 id; };
s32 func_00143b88(L1d35e0*, O1d35e0*, u16*, s32*, u32);
s32 func_00143ae0(L1d35e0*, O1d35e0*, u16*);

// Line test from a to b (w forced to 1); fills o->hit / o->id. Returns whether something was hit.
// 001d35e0: moved to src/anon/unit_001d35e0.cpp
}
