#include "../common/types.h"
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct S20 { s32 v[5]; };
/* VU0 vector subtract (lqc2/vsub/sqc2 macro sequence). */
static inline __attribute__((always_inline)) QV vsub_w1883(const QV& p, const QV* q) {
    QV d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(&p), "r"(q) : "memory");
    return d;
}
extern "C" {
void func_001bc6a8(u8*, u8*, u8*, u8*, s32);
QV func_00190388(u8*);
QV* func_0016c028(u8*);
void func_0019da68(u8* a0, u8* a1, u8* a2, s32 a3, s32 a4) {
    u8* o = (u8*)*(s32*)(*(s32*)*(s32*)a0 + 0x9e0);
    *(S20*)(a0 + 0x10) = *(S20*)a2;
    func_001bc6a8(a0 + 4, a1, o, a0 + 0x10, 1);
    *(s32*)(a0 + 0x24) = a4;
    *(s32*)(a0 + 0x50) = a3;
    if (a3 != 0xc9 && (*(s32*)(o + 0x588) & 0x80)) {
        *(s32*)(o + 0xb48) = 0;
    }
    if (*(u16*)(a1 + 0x28) != 0 && *(s32*)(a0 + 0x24) <= 0x3fffffff) {
        QV d = vsub_w1883(func_00190388(a2), func_0016c028(o));
        f32 len;
        d.y = 0;
        /* VU0 xyz length: vmul/vaddy/vaddz/vsqrt, Q read via cfc2. */
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        if ((f32)*(u16*)(a1 + 0x28) < len) {
            *(s32*)(a0 + 0x24) |= 0x40000000;
        }
    }
}
}
