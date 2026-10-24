/* batch w2387 (C): VU0 vector*matrix helper. */
#include "../common/types.h"
typedef unsigned int u128_1f1728 __attribute__((mode(TI)));
struct A1f1728 { u8 pad[0x11]; u8 mode; };
struct B1f1728 { u8 pad[0x60]; u128_1f1728 v; };
extern u8 D_01d9e6f0[];
extern u8 D_01d9e7b0[];
extern u8* D_00354688;
/* VU0 vector * matrix macro (out = m * out), hand-written VU0 asm. */
#define MULMAT(v, m) asm volatile( \
        ".set noreorder\n" \
        "lqc2 $vf27,0(%0)\n" \
        "lqc2 $vf28,0(%1)\n" \
        "lqc2 $vf29,16(%1)\n" \
        "lqc2 $vf30,32(%1)\n" \
        "lqc2 $vf31,48(%1)\n" \
        "vmulax.wxyz ACC,$vf28,$vf27x\n" \
        "vmadday.wxyz ACC,$vf29,$vf27y\n" \
        "vmaddaz.wxyz ACC,$vf30,$vf27z\n" \
        "vmaddw.wxyz $vf26,$vf31,$vf0w\n" \
        "sqc2 $vf26,0(%0)\n" \
        ".set reorder\n" : : "r"(v), "r"(m) : "memory")
/* Copy the vector at b+0x60 to out, then transform it by the matrices that a->mode selects. */
void func_001f1728(struct A1f1728* a, struct B1f1728* b, u128_1f1728* out) {
    *out = b->v;
    switch (a->mode) {
    case 0:
        break;
    case 1:
        MULMAT(out, D_01d9e6f0);
        break;
    case 2:
        if (D_00354688) {
            MULMAT(out, D_01d9e6f0);
            MULMAT(out, D_00354688 + 64);
        }
        break;
    case 3:
        MULMAT(out, D_01d9e6f0);
        MULMAT(out, D_01d9e7b0);
        break;
    }
}
