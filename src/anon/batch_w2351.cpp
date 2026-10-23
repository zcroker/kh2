#include "../common/types.h"

#define TEX0_W2351(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | \
    ((u64)(th) << 30) | ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | \
    ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | ((u64)(csa) << 56) | ((u64)(cld) << 61))

extern "C" {
void func_002f28b8(void*, s16, s16, s16, s16, s16, s16, s16);
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
void u_tail0_00236560(TexUpload2351* p) {
    s32 cbp = p->cbp;
    s32 tbp = p->tbp;
    s32 tbw, psm, w, h;
    func_002f28b8(p->clutXfer, cbp, p->clutW, p->u.s.cpsm, 0, 0, p->clutX, p->clutY);
    tbw = p->tbw; psm = p->psm; w = p->w; h = p->h;
    if (p->u.q & (1ULL << 34)) {
        // 8/4-bit textures are uploaded as PSMCT32
        switch (psm) {
        case 19: tbw /= 2; w /= 2; h /= 2; psm = 0; break;
        case 20: tbw /= 2; w /= 2; h /= 4; psm = 0; break;
        }
    }
    func_002f28b8(p->texXfer, tbp, tbw, psm, 0, 0, w, h);
    p->g[0] = 0x70000008;
    p->g[2] = (7ULL << 60) | 0x8001;
    p->g[3] = 0xeeeeeee;
    p->g[4] = 5;
    p->g[5] = 8;
    p->g[6] = 0;
    p->g[7] = 0x3f;
    p->g[8] = TEX0_W2351(tbp, p->tbw, p->psm, p->tw, p->th, 1, 0, cbp, p->u.s.cpsm, 0, 0, 1);
    p->g[9] = 6;
    p->g[10] = 0x60;
    p->g[11] = 0x14;
    {
        u64 lo = (u64)cbp << 37 | 1ULL << 62;
        u64 hi = (u64)p->u.s.cpsm << 51 | 0x1300000;
        p->g[12] = lo | hi;
    }
    p->g[13] = 0x16;
    p->g[14] = (u64)p->psm << 20 | ((u64)p->u.s.cpsm << 51 | (u64)cbp << 37);
    p->g[15] = 0x16;
    p->g[16] = 0x44;
    p->g[17] = 0x42;
    func_003058a0(0);
}
}
