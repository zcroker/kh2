// Linked unit 0x002029a0-0x00202ce0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002029a0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002029a0 {
extern u8  D_01da0000 asm("D_01da0000");
// alloc_aligned16
extern "C" void func_001e7798(...) asm("func_001e7798");
/*TARGET 002029a0*/
void func_002029a0(u32 a0, u8* a1) asm("_Z13func_002029a0jPh");
void func_002029a0(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 8) + 160);
    u32 v = *(u32*)(s0 + 8);
    if (v != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), v);
        *(u32*)(s0 + 8) = 0;
    }
}
}  // namespace n002029a0

// 002029e8 (was src/anon/spline_vu0_owner1025.c)
namespace n002029e8 {
#define SPLINE_SOLVE(in, n, out, tab, work) \
    asm volatile( \
        ".set noreorder\n\t" \
        "addi $9,%1,-1\n\t" \
        "addi $10,%1,-2\n\t" \
        "lqc2 $vf1,0(%3)\n\t" \
        "sqc2 $vf0,0(%2)\n\t" \
        "sll $11,$9,0x4\n\t" \
        "add $11,$11,%2\n\t" \
        "sqc2 $vf0,0($11)\n\t" \
        "move $8,$9\n\t" \
        "move $11,$0\n\t" \
        ".Lspl%=_delta_loop:\n\t" \
        "blez $8,.Lspl%=_delta_done\n\t" \
        "addi $8,$8,-1\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "add $14,$12,%0\n\t" \
        "add $15,$13,%0\n\t" \
        "add $16,$13,%4\n\t" \
        "lqc2 $vf10,0($14)\n\t" \
        "lqc2 $vf11,0($15)\n\t" \
        "vsub.xyzw $vf10,$vf11,$vf10\n\t" \
        "sqc2 $vf10,0($16)\n\t" \
        "b .Lspl%=_delta_loop\n\t" \
        "addi $11,$11,1\n\t" \
        ".Lspl%=_delta_done:\n\t" \
        "lqc2 $vf10,32(%4)\n\t" \
        "lqc2 $vf11,16(%4)\n\t" \
        "lqc2 $vf12,0(%2)\n\t" \
        "vsub.xyzw $vf10,$vf10,$vf11\n\t" \
        "vsub.xyzw $vf10,$vf10,$vf12\n\t" \
        "sqc2 $vf10,16(%2)\n\t" \
        "vaddx.xyzw $vf11,$vf0,$vf1x\n\t" \
        "sqc2 $vf11,16(%4)\n\t" \
        "move $8,$10\n\t" \
        "addi $8,$8,-1\n\t" \
        "addi $11,$0,1\n\t" \
        ".Lspl%=_fwd_loop:\n\t" \
        "blez $8,.Lspl%=_fwd_done\n\t" \
        "addi $8,$8,-1\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "addi $14,$13,16\n\t" \
        "add $15,$12,%4\n\t" \
        "add $16,$13,%4\n\t" \
        "add $17,$14,%4\n\t" \
        "add $18,$13,%2\n\t" \
        "add $19,$12,%2\n\t" \
        "lqc2 $vf10,0($15)\n\t" \
        "lqc2 $vf11,0($16)\n\t" \
        "lqc2 $vf12,0($17)\n\t" \
        "lqc2 $vf13,0($19)\n\t" \
        "vdiv Q,$vf0w,$vf10x\n\t" \
        "vwaitq\n\t" \
        "vaddq.x $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf0w,$vf10y\n\t" \
        "vwaitq\n\t" \
        "vaddq.y $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf0w,$vf10z\n\t" \
        "vwaitq\n\t" \
        "vaddq.z $vf15,$vf0,Q\n\t" \
        "vsub.xyzw $vf16,$vf12,$vf11\n\t" \
        "vmul.xyzw $vf17,$vf13,$vf15\n\t" \
        "vsub.xyzw $vf17,$vf16,$vf17\n\t" \
        "sqc2 $vf17,0($18)\n\t" \
        "vmuly.xyzw $vf18,$vf15,$vf1y\n\t" \
        "vaddx.xyzw $vf18,$vf18,$vf1x\n\t" \
        "sqc2 $vf18,0($16)\n\t" \
        "b .Lspl%=_fwd_loop\n\t" \
        "addi $11,$11,1\n\t" \
        ".Lspl%=_fwd_done:\n\t" \
        "sll $11,$9,0x4\n\t" \
        "add $11,$11,%2\n\t" \
        "sll $12,$10,0x4\n\t" \
        "add $12,$12,%2\n\t" \
        "lqc2 $vf10,0($11)\n\t" \
        "lqc2 $vf11,0($12)\n\t" \
        "vsub.xyzw $vf11,$vf11,$vf10\n\t" \
        "sqc2 $vf11,0($12)\n\t" \
        "move $11,$10\n\t" \
        ".Lspl%=_back_loop:\n\t" \
        "blezl $11,.Lspl%=_done\n\t" \
        "nop\n\t" \
        "sll $12,$11,0x4\n\t" \
        "addi $13,$12,16\n\t" \
        "add $15,$12,%4\n\t" \
        "add $16,$12,%2\n\t" \
        "add $17,$13,%2\n\t" \
        "lqc2 $vf10,0($15)\n\t" \
        "lqc2 $vf11,0($16)\n\t" \
        "lqc2 $vf12,0($17)\n\t" \
        "vsub.xyzw $vf11,$vf11,$vf12\n\t" \
        "vdiv Q,$vf11x,$vf10x\n\t" \
        "vwaitq\n\t" \
        "vaddq.x $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf11y,$vf10y\n\t" \
        "vwaitq\n\t" \
        "vaddq.y $vf15,$vf0,Q\n\t" \
        "vdiv Q,$vf11z,$vf10z\n\t" \
        "vwaitq\n\t" \
        "vaddq.z $vf15,$vf0,Q\n\t" \
        "sqc2 $vf15,0($16)\n\t" \
        "b .Lspl%=_back_loop\n\t" \
        "addi $11,$11,-1\n\t" \
        ".Lspl%=_done:\n\t" \
        ".set reorder" \
        : : "r"(in), "r"(n), "r"(out), "r"(tab), "r"(work) \
        : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$17", "$18", "$19", "memory")
extern u8 D_003590e0[] asm("D_003590e0");
/*TARGET 002029e8*/
// 0x00201978: definition moved into src/anon/unit_00200578.cpp

void func_002029e8(void* in, s32 n, void* out) asm("func_002029e8");
// 0x00201978: definition moved into src/anon/unit_00200578.cpp

void func_002029e8(void* in, s32 n, void* out)
{
    u128 work[128];
    SPLINE_SOLVE(in, n, out, D_003590e0, work);
}
}  // namespace n002029e8

// 00202ba0 (was src/anon/batch_w50.cpp)
namespace n00202ba0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector: copies are one quadword; assignment skips self-copies.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct F8 { f32 a, b, t, d; };
extern F8 D_003590f0 asm("D_003590f0");
/*TARGET 00202ba0*/
// 0x001d7d68: definition moved into src/anon/unit_001d7458.cpp

// Cubic interpolation between key pairs a[i], b[i] at fraction t (VU0).
void func_00202ba0(Vec4* out, Vec4* a, Vec4* b, f32 t) asm("func_00202ba0");
// 0x001d7d68: definition moved into src/anon/unit_001d7458.cpp

// Cubic interpolation between key pairs a[i], b[i] at fraction t (VU0).
void func_00202ba0(Vec4* out, Vec4* a, Vec4* b, f32 t) {
    s32 i = (s32)t;
    a += i;
    b += i;
    D_003590f0.t = t - (f32)i;
    asm volatile(".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 0(%2)\n\tlqc2 $vf4, 16(%2)\n\tlqc2 $vf5, 0(%3)\n\t"
        "vsub.xyzw $vf10, $vf4, $vf3\n\tvmuly.xyzw $vf11, $vf3, $vf5y\n\tvmulx.xyzw $vf12, $vf3, $vf5x\n\t"
        "vsub.xyzw $vf13, $vf2, $vf1\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf11, $vf11, $vf4\n\t"
        "vadd.xyzw $vf10, $vf10, $vf12\n\tvsub.xyzw $vf13, $vf13, $vf11\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\t"
        "vadd.xyzw $vf10, $vf10, $vf13\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf10, $vf10, $vf1\n\t"
        "sqc2 $vf10, 0(%0)\n\t.set reorder"
        : : "r"(out), "r"(a), "r"(b), "r"(&D_003590f0) : "memory");
}
}  // namespace n00202ba0

// 00202c20 (was src/anon/batch_w77.cpp)
namespace n00202c20 {
/*TARGET 00202c20*/
void func_00202c20(u8* p, s32* x, s32* w, s32* y, s32* h) asm("func_00202c20");
void func_00202c20(u8* p, s32* x, s32* w, s32* y, s32* h)
{
    s32 x0 = 0;
    s32 ww = 4096;
    s32 hh = 4096;
    switch (p[16]) {
    case 1: ww = 2048; break;
    case 2: ww = 1024; break;
    }
    switch (p[17]) {
    case 1: hh = 2048; break;
    case 2: hh = 1024; break;
    }
    switch (p[18]) {
    case 1: x0 = 1024; ww += 1024; break;
    case 2: x0 = 2048; ww += 2048; break;
    case 3: x0 = 3072; ww += 3072; break;
    }
    *x = x0 + 16;
    *w = ww - 16;
    *y = 16;
    *h = hh - 16;
}
}  // namespace n00202c20

