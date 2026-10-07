#include "../common/types.h"

extern "C" {

// Clears two quadwords.
void func_0011c138(void* p) {
    asm volatile(".set noreorder\n\tsq $0, 0(%0)\n\tsq $0, 16(%0)\n\t.set reorder" : : "r"(p) : "memory");
}

struct Pair8 { u8 a; u8 b; u8 pad[2]; s32 c; };
void func_0010b550(Pair8* p) {
    p->a = 0;
    p->b = 0;
    p->c = -1;
}

extern u32 D_0033cc38;
extern u32 D_0033cc3c;
// Sets the current value, keeping the previous one.
void func_001069b8(u32 v) {
    D_0033cc3c = D_0033cc38;
    D_0033cc38 = v;
}

// Quadword copy unless source and destination are the same.
void func_00134d60(void* dst, void* src) {
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}

}
