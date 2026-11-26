// Linked unit 0x00105550-0x001056e8.
#include "../common/types.h"
#include <stdarg.h>

// 00105550 (was src/anon/batch_w39.cpp)
namespace n00105550 {
/*TARGET 00105550*/
// --- 00105550
// setjmp: saves gp/sp/fp/ra/s0-s7 (128-bit) and f20-f31. Hand-written assembly.
int func_00105550(void* jb) asm("func_00105550");
// --- 00105550
// setjmp: saves gp/sp/fp/ra/s0-s7 (128-bit) and f20-f31. Hand-written assembly.
int func_00105550(void* jb) {
    asm volatile(
        "sq $28, 0(%0)\n\t"
        "sq $29, 16(%0)\n\t"
        "sq $30, 32(%0)\n\t"
        "sq $31, 48(%0)\n\t"
        "sq $16, 64(%0)\n\t"
        "sq $17, 80(%0)\n\t"
        "sq $18, 96(%0)\n\t"
        "sq $19, 112(%0)\n\t"
        "sq $20, 128(%0)\n\t"
        "sq $21, 144(%0)\n\t"
        "sq $22, 160(%0)\n\t"
        "sq $23, 176(%0)\n\t"
        "swc1 $f20, 192(%0)\n\t"
        "swc1 $f21, 196(%0)\n\t"
        "swc1 $f22, 200(%0)\n\t"
        "swc1 $f23, 204(%0)\n\t"
        "swc1 $f24, 208(%0)\n\t"
        "swc1 $f25, 212(%0)\n\t"
        "swc1 $f26, 216(%0)\n\t"
        "swc1 $f27, 220(%0)\n\t"
        "swc1 $f28, 224(%0)\n\t"
        "swc1 $f29, 228(%0)\n\t"
        "swc1 $f30, 232(%0)\n\t"
        "swc1 $f31, 236(%0)"
        : : "r"(jb) : "memory");
    return 0;
}
}  // namespace n00105550

// 001055b8 (was src/anon/batch_wcx2.cpp)
namespace n001055b8 {
/*TARGET 001055b8*/
// ---- 001055b8
s32 func_001055b8(void* a0) asm("func_001055b8");
// ---- 001055b8
s32 func_001055b8(void* a0) {
    // Hand-written longjmp in the original.
    asm volatile(
        "lq $28, 0(%0)\n\tlq $29, 16(%0)\n\tlq $30, 32(%0)\n\tlq $31, 48(%0)\n\t"
        "lq $16, 64(%0)\n\tlq $17, 80(%0)\n\tlq $18, 96(%0)\n\tlq $19, 112(%0)\n\t"
        "lq $20, 128(%0)\n\tlq $21, 144(%0)\n\tlq $22, 160(%0)\n\tlq $23, 176(%0)\n\t"
        "lwc1 $f20, 192(%0)\n\tlwc1 $f21, 196(%0)\n\tlwc1 $f22, 200(%0)\n\tlwc1 $f23, 204(%0)\n\t"
        "lwc1 $f24, 208(%0)\n\tlwc1 $f25, 212(%0)\n\tlwc1 $f26, 216(%0)\n\tlwc1 $f27, 220(%0)\n\t"
        "lwc1 $f28, 224(%0)\n\tlwc1 $f29, 228(%0)\n\tlwc1 $f30, 232(%0)\n\tlwc1 $f31, 236(%0)"
        : : "r"(a0));
    return 1;
}
}  // namespace n001055b8

// 00105620 (was src/anon/batch_w88.cpp)
namespace n00105620 {
u32 wtarget_00105620(u32, u32, u32, u32) asm("_Z16wtarget_00105620jjjj");
/*TARGET 00105620*/
// extern "C"

u32 wtarget_00105620(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00105620jjjj");
// extern "C"

u32 wtarget_00105620(u32 a, u32 b, u32, u32) {
    u32 save = a;
    u32 load = b;
    asm volatile(
        "sq $28, 0(%0)\n\tsq $29, 16(%0)\n\tsq $30, 32(%0)\n\tsq $31, 48(%0)\n\t"
        "sq $16, 64(%0)\n\tsq $17, 80(%0)\n\tsq $18, 96(%0)\n\tsq $19, 112(%0)\n\t"
        "sq $20, 128(%0)\n\tsq $21, 144(%0)\n\tsq $22, 160(%0)\n\tsq $23, 176(%0)\n\t"
        "swc1 $f20, 192(%0)\n\tswc1 $f21, 196(%0)\n\tswc1 $f22, 200(%0)\n\tswc1 $f23, 204(%0)\n\t"
        "swc1 $f24, 208(%0)\n\tswc1 $f25, 212(%0)\n\tswc1 $f26, 216(%0)\n\tswc1 $f27, 220(%0)\n\t"
        "swc1 $f28, 224(%0)\n\tswc1 $f29, 228(%0)\n\tswc1 $f30, 232(%0)\n\tswc1 $f31, 236(%0)\n\t"
        "lq $28, 0(%1)\n\tlq $29, 16(%1)\n\tlq $30, 32(%1)\n\tlq $31, 48(%1)\n\t"
        "lq $16, 64(%1)\n\tlq $17, 80(%1)\n\tlq $18, 96(%1)\n\tlq $19, 112(%1)\n\t"
        "lq $20, 128(%1)\n\tlq $21, 144(%1)\n\tlq $22, 160(%1)\n\tlq $23, 176(%1)\n\t"
        "lwc1 $f20, 192(%1)\n\tlwc1 $f21, 196(%1)\n\tlwc1 $f22, 200(%1)\n\tlwc1 $f23, 204(%1)\n\t"
        "lwc1 $f24, 208(%1)\n\tlwc1 $f25, 212(%1)\n\tlwc1 $f26, 216(%1)\n\tlwc1 $f27, 220(%1)\n\t"
        "lwc1 $f28, 224(%1)\n\tlwc1 $f29, 228(%1)\n\tlwc1 $f30, 232(%1)\n\tlwc1 $f31, 236(%1)"
        : : "r"(save), "r"(load) : "memory");
    return 2;
}
}  // namespace n00105620

