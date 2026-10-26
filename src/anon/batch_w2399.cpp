#include "../common/types.h"

// 00107888: copy current slot of the A/B state arrays to their second copies, then update both.
// Same types as the matched twins func_001065d8/func_001067b8 (batch_w1966.cpp).
#define W2399_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
#define W2399_QCOPY1(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct W2399Mat {
    f32 m[4][4];
    W2399Mat& operator=(const W2399Mat& o) { if (this != &o) W2399_QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));

struct W2399Vec {
    f32 v[4];
    W2399Vec& operator=(const W2399Vec& o) { if (this != &o) W2399_QCOPY1(this, &o); return *this; }
} __attribute__((aligned(16)));

struct W2399Pad {
    u8 b[16];
    W2399Pad& operator=(const W2399Pad&) { return *this; }
} __attribute__((aligned(16)));

struct W2399I3 { s32 a, b, c; };
struct W2399Pair { void* a; void* b; } __attribute__((aligned(8)));

struct W2399A {
    W2399Mat m0;
    f32 f40;
    s32 i44, i48;
    W2399I3 t4c;
    W2399Pair p58;
    void* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    W2399Mat m80;
    W2399Mat mc0;
};

struct W2399B {
    W2399Pad e0;
    W2399Mat m10;
    W2399Vec v50, v60, v70;
    f32 f80;
};


extern W2399A D_003a7b70[2];
extern W2399B D_003a7f70[2];
extern W2399A D_003a7d70[2];
extern W2399B D_003a8090[2];
extern "C" {
extern s32 D_0033cc40;
void func_00106c08(W2399A*);
void func_00107118(W2399B*);
void func_00107888(void)
{
    D_003a7d70[D_0033cc40] = D_003a7b70[D_0033cc40];
    D_003a8090[D_0033cc40] = D_003a7f70[D_0033cc40];
    func_00106c08(&D_003a7b70[D_0033cc40]);
    func_00107118(&D_003a7f70[D_0033cc40]);
}

}
