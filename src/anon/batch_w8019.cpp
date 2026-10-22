// w8019 (zl90 retry): matched near-misses.
#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
extern "C" {
extern f32 D_004f5268;
u32 func_00167778(u8* self, u8* in) {
    QWord* out = (QWord*)(self + 0x20);
    u32 mask = 0;
    for (s32 i = 0; i < 2; i++) {
        QWord v;
        for (s32 j = 0; j < 2; j++) {
            *(f32*)((u8*)&v + (j << 2)) = in[i * 2 + j + 2] - 127.5f;
            if (*(f32*)((u8*)&v + (j << 2)) > 0.0f) {
                *(f32*)((u8*)&v + (j << 2)) -= D_004f5268;
                if (*(f32*)((u8*)&v + (j << 2)) < 0.0f) *(f32*)((u8*)&v + (j << 2)) = 0.0f;
                else { u32 nm = ((j + 1) << (i * 4 + 16)) | mask; mask = nm; }
            } else {
                *(f32*)((u8*)&v + (j << 2)) += D_004f5268;
                if (*(f32*)((u8*)&v + (j << 2)) > 0.0f) *(u32*)((u8*)&v + (j << 2)) = 0;
                else { u32 nm = ((j + 1) << (i * 4 + 18)) | mask; mask = nm; }
            }
            *(f32*)((u8*)&v + (j << 2)) /= 127.5f - D_004f5268;
        }
        v.v[2] = 0;
        f32 len = Normalize(&v);
        if (len > 1.0f) len = 1.0f;
        v.f[3] = len;
        *out = v;
        out++;
    }
    return mask;
}
}
