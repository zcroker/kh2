#include "../common/types.h"
extern "C" {

// VU0 macro sequence (hand-written original): length of the vector at +0x20 scaled by a global factor.
void func_0019fb70(u32 a0, u8* a1) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile(
        "addiu $15,%1,32\n\t"
        "lq $8,0($15)\n\t"
        "sq $8,%0\n\t"
        "sw $0,4(%2)\n\t"
        "lqc2 vf1,%0\n\t"
        "vmul.xyz vf1,vf1,vf1\n\t"
        "vaddy.x vf1,vf1,vf1y\n\t"
        "vaddz.x vf1,vf1,vf1z\n\t"
        "vsqrt Q,vf1x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8,$22\n\t"
        "mtc1 $8,$f1\n\t"
        "lui $15,%%hi(D_00352130)\n\t"
        "lw $14,%%lo(D_00352130)($15)\n\t"
        "lwc1 $f0,28($14)\n\t"
        "mul.s $f1,$f1,$f0\n\t"
        "sw $0,248(%1)\n\t"
        "swc1 $f1,244(%1)\n\t"
        : "=m"(tmp) : "r"(a1), "r"(tmp) : "$8", "$14", "$15", "$f0", "$f1", "memory");
}

extern f32 func_001065a8();
struct W214O { u8 pad[24]; f32 f; };
void func_002deac0(W214O* o, f32 a, f32 b) {
    if (a == b) { asm("" : "+r"(o)); o->f = a; }
    else o->f = func_001065a8();
    o->f = o->f * 0.01f;
}

s32 func_002e64e8(u32 a0, u32 a1, u8* a2) {
    s32 n = *(s32*)(a2 + 12);
    a0 &= 0xff; a1 &= 0xff;
    s32 i = 0;
    u8* p = a2 + 16;
    if (n > 0) {
        s32 m = n; asm("" : "+r"(m));
        do {
            if (p[0] == a0) { if (p[1] == a1) return i; }
            i++;
            p += *(s32*)(p + 12);
        } while (i < m);
    }
    return -1;
}
}
