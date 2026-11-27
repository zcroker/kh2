// Linked unit 0x0020efe8-0x0020f118: relocation wrappers, header table lookup and two VU0 random helpers.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0020efe8 (was src/anon/tiny_wrappers_more.cpp)
namespace n0020efe8 {
u32 func_0020edd0(u32, u32, u32, u32) asm("_Z13func_0020edd0jjjj");
/*TARGET 0020efe8*/
u32 func_0020efe8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0020efe8jjjj");
u32 func_0020efe8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0020edd0(a0, ((u32)(a0) + (u32)(((u32)(*(u32*)((u32)(a0) + 60u))))), a2, a3);
}
}  // namespace n0020efe8

// 0020f008 (was gap)
namespace n0020f008 {
u32 func_0020edd0(u32, u32, u32, u32) asm("_Z13func_0020edd0jjjj");
u32 func_0020f008(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0020f008");
u32 func_0020f008(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = a0 + 16;
    return func_0020edd0(b, b + *(u32*)(b + 60), a2, a3);
}
}  // namespace n0020f008

// 0020f030 (was gap)
namespace n0020f030 {
// Entry idx of table kind in a block whose header holds the table offsets.
u32 func_0020f030(u32* h, s32 kind, s32 idx) asm("func_0020f030");
u32 func_0020f030(u32* h, s32 kind, s32 idx) {
    u32 b = (u32)h;
    switch (kind) {
    case 2: return h[2] + b + (idx << 5);
    case 3: return h[3] + b + (idx << 4);
    default: {
        u32 o = b + (kind << 2);
        o = *(u32*)o;
        o += b;
        return ((u32*)o)[idx];
    }
    }
}
}  // namespace n0020f030

// 0020f088 (was gap)
namespace n0020f088 {
// VU0 random in [-x, x): R in [1,2) * 2 - 3, times x; the R seed is advanced with the result's w.
f32 func_0020f088(f32 x) asm("func_0020f088");
f32 func_0020f088(f32 x) {
    register f32 xi asm("$2");
    register u32 two asm("$3");
    register u32 three asm("$4");
    register u32 k asm("$5");
    // Empty barriers keep the operand set-up in source order (mfc1 first, as in the original).
    xi = x; asm volatile(""); two = 0x40000000;  three = 0x40400000; asm volatile(""); k = 0x3ff19120;
    register u32 r asm("$2");
    asm volatile("vrnext.wxyz $vf31, R\n\tqmtc2 %1, $vf30\n\tqmtc2 %2, $vf29\n\tqmtc2 %3, $vf28\n\tqmtc2 %4, $vf27\n\t"
                 "vmul.x $vf31, $vf31, $vf29\n\tvsubx.w $vf25, $vf31, $vf27x\n\tvsub.x $vf31, $vf31, $vf28\n\t"
                 "vmul.x $vf31, $vf31, $vf30\n\tqmfc2 %0, $vf31"
                 : "=r"(r) : "r"(xi), "r"(two), "r"(three), "r"(k));
    union { u32 u; f32 f; } v; v.u = r;
    f32 out = v.f;
    asm volatile("vrinit R, $vf25w");
    return out;
}
}  // namespace n0020f088

// 0020f0d8 (was gap)
namespace n0020f0d8 {
// VU0 random in [0, x): (R in [1,2) - 1) * x; the R seed is advanced with the result's w.
f32 func_0020f0d8(f32 x) asm("func_0020f0d8");
f32 func_0020f0d8(f32 x) {
    register f32 xi asm("$2");
    register u32 one asm("$3");
    register u32 k asm("$5");
    xi = x; asm volatile(""); one = 0x3f800000; asm volatile(""); k = 0x3ff19120;
    register u32 r asm("$2");
    asm volatile("vrnext.wxyz $vf31, R\n\tqmtc2 %1, $vf30\n\tqmtc2 %2, $vf29\n\tqmtc2 %3, $vf27\n\t"
                 "vsub.wxyz $vf31, $vf31, $vf29\n\tvsubx.w $vf25, $vf31, $vf27x\n\t"
                 "vmul.x $vf31, $vf31, $vf30\n\tqmfc2 %0, $vf31"
                 : "=r"(r) : "r"(xi), "r"(one), "r"(k));
    union { u32 u; f32 f; } v; v.u = r;
    f32 out = v.f;
    asm volatile("vrinit R, $vf25w");
    return out;
}
}  // namespace n0020f0d8

