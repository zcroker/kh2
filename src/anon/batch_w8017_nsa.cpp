#include "../common/types.h"
struct QW {
    f32 x, y, z, w;
    QW() {}
    QW(const QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW& operator=(const QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline QW vscale(const QW& a, f32 k) {
    QW r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct Act { u8 p0[0x40]; QW vel; u8 p50; u8 p51[3]; void (*fn)(Act*); };
extern "C" {
s32 func_001c5f78(Act*, QW*);
s32 func_001db5a8(s32);
void func_001b4198(s32, s32, Act*);
void func_001890a8(void*, s32);
void addcount_w8017(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void func_001c6850(Act*);
extern u8 D_0032e020[];
extern s32 D_0034e948;
extern s32 D_00351670;
extern s32 D_00351674;
extern s32 D_0036df78[];
extern s32 D_01d498b0;


void func_001c6900(Act* a, QW* v) {
    s32 id;
    s32 r = 0;
    if (func_001c5f78(a, v) != 0) {
        id = 0x405;
        if (D_00351674 > 0) r = func_001db5a8(D_0036df78[D_00351674 - 1]);
    } else {
        id = 0x404;
        if (D_00351670 > 0) r = func_001db5a8(D_0036df78[D_00351670 - 1]);
    }
    if (r != 0) {
        func_001b4198(r, D_0034e948, a);
    }
    func_001890a8(D_0032e020, id);
    addcount_w8017(1, 0);
    D_01d498b0++;
    a->fn = func_001c6850;
    a->vel = vscale(*v, 60.0f);
    a->vel.y = -30.0f;
    a->vel.w = 14.0f;
    a->p50 = 20;
}
}
