#include "../common/types.h"
extern "C" {
struct V15d058 {
    f32 x, y, z, w;
    V15d058() {}
    V15d058(const V15d058& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V15d058& operator=(const V15d058& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern V15d058 D_004f3760, D_004f3770, D_004f3780, D_004f3790, D_004f37a0, D_004f37b0;
V15d058 s15d058_spring(V15d058, V15d058, V15d058, f32, f32, f32, f32) asm("func_0013f6e8");
static inline void U15d058(V15d058& cur, V15d058& goal, V15d058& vel, f32 dt) { cur = s15d058_spring(cur, goal, vel, dt, 2.5f, 0.5f, 1.0f); }

// 0015d058: moved to src/anon/unit_0015cdb0.cpp
}
extern "C" {
struct V158dc0 {
    f32 x, y, z, w;
    V158dc0& operator=(const V158dc0& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Seg158dc0 { V158dc0 a, b; };
struct Tgt158dc0;
struct Tgt158dc0Vt { void* f[16]; s32 (*IsValid)(Tgt158dc0*); };
struct Tgt158dc0 { Tgt158dc0Vt* vt; };
struct C158dc0 { u8 pad[68]; Tgt158dc0* target; u8 pad2[8]; f32 dist; u8 pad3[12]; V158dc0 v96, v112, v128; };
extern V158dc0 D_0034a9b0;
extern u8 D_0034a9e8;
s32 func_00167f18(s32);
void func_00158ac8(C158dc0*);
void func_00158b78(s32, C158dc0*);
void func_00158b20(C158dc0*);
void func_00158c88(C158dc0*);
s32 func_0013f9e0(V158dc0*, V158dc0*, V158dc0*, s32, s32);
V158dc0 func_0016c2b0(Tgt158dc0*);
V158dc0* func_0016c028(Tgt158dc0*);
s32 func_00143d10(Seg158dc0*, V158dc0*, f32*, s32*);
f32 func_0013fd10(C158dc0*);
// 00158dc0: moved to src/harata/libdk/bookcamera.cpp
}
