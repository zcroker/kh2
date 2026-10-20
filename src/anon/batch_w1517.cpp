#include "../common/types.h"

struct QW_w1517 { f32 v[4]; } __attribute__((aligned(16)));

// VU0 macro-mode normalize (hand-written asm sequence)
static inline f32 Normalize_w1517(QW_w1517* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}

extern "C" {

char* GetImage_w1517(void* t, s32 i) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
struct ImgSub_w1517 { u8 pad[0x28]; void* img; char* Get(s32 i) { return GetImage_w1517(img, i); } };
struct T_0023ef50 { u8 pad[0x28]; s32 n; u8 p2[4]; ImgSub_w1517 sub; };
void func_0023ef50(T_0023ef50* a0) {  // list_enable_all
    s32 n = a0->n;
    for (s32 i = 0; i < n; i++) {
        a0->sub.Get(i)[400] = 1;
    }
}

void func_002cdb00(QW_w1517*, f32);
struct T_002cbf08 { u8 pad[0x18]; f32 f18; };
QW_w1517* func_002cbf08(QW_w1517* a0, T_002cbf08* a1) {
    asm volatile("");
    func_002cdb00(a0, a1->f18);
    Normalize_w1517(a0);
    return a0;
}

}
