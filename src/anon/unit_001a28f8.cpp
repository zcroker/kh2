#include "../common/types.h"

// Object movement helpers (0x1a28f8-0x1a2a50), the end of the file before YS::ITEM: a forwarder,
// a velocity damping step that stops the object below a minimum speed, the velocity scaled
// by the frame time, and the stop itself.
// Each function keeps the declarations of the source it was matched in (namespace jN).

// 001a28f8
namespace j0 {
u32 func_001878e8(u32, u32, u32, u32) asm("func_001878e8");
u32 func_001a28f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001a28f8");
u32 func_001a28f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001878e8(a1, a1, a2, a3);
}
}  // namespace j0

// 001a2910
namespace j1 {
static inline void vu_scale(void* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(s) : "$8", "memory");
}
static inline f32 vu_len(void* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
extern u8* D_00352130 asm("D_00352130");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
u32 func_0019fdb0(u8*) asm("func_0019fdb0");
void func_001a2a18(u8*) asm("func_001a2a18");
void func_001a2910(u32, u8* o) asm("func_001a2910");
void func_001a2910(u32, u8* o) {
    u8* v = o + 32;
    vu_scale(v, *(f32*)(D_00352130 + 60));
    if (vu_len(v) < *(f32*)(o + 244)) {
        f32 z = 0.0f;
        func_0017f488(o + 320, func_0019fdb0(o), z, z);
        func_0017f5e0(o + 320, 0, 0, z, z);
        func_001a2a18(o);
    }
}
}  // namespace j1

// 001a29f0 (never written before): the object's velocity scaled by the frame time
namespace j3 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void vu_scale_to(V4* d, const void* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
extern f32 D_00349e10 asm("D_00349e10");  // frame time
V4 func_001a29f0(u32, u8* o) asm("func_001a29f0");
V4 func_001a29f0(u32, u8* o) {
    V4 r;
    vu_scale_to(&r, o + 32, D_00349e10);
    return r;
}
}  // namespace j3

// 001a2a18
namespace j2 {
void func_0016bd60(void*, u32) asm("func_0016bd60");
void func_001a2a18(u8* p) asm("func_001a2a18");
void func_001a2a18(u8* p) {
    register u8* vec asm("$14") = p + 32;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(vec) : "memory");
    register u32 flags asm("$13") = *(u32*)(p + 352);
    if (flags & 0x40) func_0016bd60(p, 0);
    else func_0016bd60(p, 5);
}
}  // namespace j2
