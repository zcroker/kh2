#include "../common/types.h"

#define TEX0_W2351(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
    ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
    ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))

extern "C" {
void sceGsSetDefLoadImage(void*, s16, s16, s16, s16, s16, s16, s16);
void func_003058a0(s32);

// Texture + CLUT upload descriptor followed by a GIF packet that sets TEX0/TEX1/TEX2.
struct TexUpload2351 {
    s32 x0, tbp, w, h, tw, th, tbw, psm, cbp, clutX, clutY, clutW;
    union { struct { s32 cpsm; s32 x34; } s; u64 q; } u;
    u8 pad38[0x40 - 0x38];
    u8 texXfer[0x60];
    u8 clutXfer[0x60];
    u64 g[0x20];
};

void u_tail0_00236560(TexUpload2351* p) asm("_Z16u_tail0_00236560v");
void u_tail0_00236560(TexUpload2351* p);  // 0x00236560: definition moved into src/anon/unit_00236180.cpp
}
