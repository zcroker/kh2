#include "../common/types.h"
extern "C" {
struct W1769Vec {
    f32 x, y, z, w;
    W1769Vec& operator=(const W1769Vec& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
} __attribute__((aligned(16)));
struct W1769Obj { W1769Vec* v; f32 s; };
extern s8 D_004f6310;            // guard of the function-local static below
extern W1769Vec D_004f6320;      // function-local static vector
void func_0016e890(void);        // its destructor (empty)
void func_002fd188(void (*)(void)); // atexit-style registration

static inline W1769Vec w1769_div(const W1769Vec* v, f32 s) {
    W1769Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(v), "f"(s) : "$8", "memory");
    return r;
}

// o->v = o->v / o->s, through a function-local static.
void func_0016d4d0(W1769Obj* o) {
    W1769Vec* v = o->v;
    if (!D_004f6310) {
        D_004f6310 = 1;
        func_002fd188(func_0016e890);
    }
    D_004f6320 = w1769_div(v, o->s);
    o->v = &D_004f6320;
}
}
