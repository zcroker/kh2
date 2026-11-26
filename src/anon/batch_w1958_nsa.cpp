#include "../common/types.h"

struct V58a {
    f32 x, y, z, w;
    V58a() {}
    V58a& operator=(const V58a& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct O58a { u8 pad[0x60]; void* x60; u8 x64[0x10]; };
struct A58b { u8 pad[0x588]; u32 x588; };
struct O58b { u8 pad[0x34]; s32 x34; s32 x38; };
struct V58e {
    f32 x, y, z, w;
    V58e() {}
    V58e& operator=(const V58e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    void normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
    }
} __attribute__((aligned(16)));
static inline V58e operator-(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
static inline V58e operator+(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct S58e { u8 pad[0x9f4]; u8 x9f4[0x10]; };
struct O58e { u8 pad[0xc]; s32 xc; u8 pad2[0x84 - 0x10]; S58e* x84; u8 pad3[0xe0 - 0x88]; V58e xe0; };
static inline void w1958_lerp(V58a* r, const V58a* a, const V58a* b, f32 t) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline void w1958a_vsub(V58a* r, const V58a* a, const V58a* b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline void w1958a_vadd(V58a* r, const V58a* a, const V58a* b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline f32 w1958a_vlen(const V58a* a) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(a) : "$8", "memory");
    return len;
}
extern "C" {
void* YS__OBJ__get_pos(void*);
void func_001904a8(V58a*, void*);
extern V58a D_01e2bc70;
extern V58a D_01e2bc80;
extern V58a D_01e2bc90;
void func_002dd2d8(s32, f32*, f32*);
f32 func_00106558(f32);
extern s32 D_00361f60;
extern void* D_0034e948;
s32 YS__OBJ__is_exist(s32);
V58e YS__OBJ__get_target_pos(s32);
V58e YS__OBJ__get_dir(S58e*);
s32 func_00190140(void*);
V58e func_00190388(void*);


void worldmap__LockOnCamera__getEyeAt(O58a* o, V58a* out1, V58a* out2);  // 0x002c04c8: definition moved into src/anon/unit_002bebd0.cpp

void Ti__ACTION_PO_JUMP__decide_way(O58b* o, A58b* act, f32 a, f32 b);  // 0x002deba0: definition moved into src/anon/unit_002de3c8.cpp

// 001a4b78: moved to src/anon/unit_001a3e70.cpp
}
