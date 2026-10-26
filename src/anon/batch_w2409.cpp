#include "../common/types.h"
extern "C" {
#define GS_SET_TEX0(tbp, tbw, psm, tw, th, tcc, tfx, cbp, cpsm, csm, csa, cld) \
    ((u64)(tbp) | ((u64)(tbw) << 14) | ((u64)(psm) << 20) | ((u64)(tw) << 26) | ((u64)(th) << 30) | \
     ((u64)(tcc) << 34) | ((u64)(tfx) << 35) | ((u64)(cbp) << 37) | ((u64)(cpsm) << 51) | ((u64)(csm) << 55) | \
     ((u64)(csa) << 56) | ((u64)(cld) << 61))
struct Img2e6210 { u8 pad0[8]; s32 size; u8 pad1[7]; u8 format; u16 w; u16 h; };
struct Tex2e6210 {
    u8 pad0[272];
    u8 clutObj[548 - 272];
    Img2e6210* img;
    void* pixels;
    void* clut;
    u64 tex0 __attribute__((aligned(4)));
};
void func_001097e8(void*, s32, s32, s32, s32, s32, s32, s32, void*);
void func_00133c60(void*, void*, s32, s32, s32);

struct Clut2e6210 { u8 b[276]; };
static inline void ld1(void* co, void* pkt, s32 cbp, s32 h, void* data) { func_001097e8(co, cbp, 64, 0, 0, 16, h, 0, data); func_00133c60(pkt, co, 0, 0, 0); }
static inline void ld2(void* co, s32 cbp, s32 h, void* data) { func_001097e8(co, cbp, 64, 0, 0, 16, h, 0, data); }
static inline void ld3(void* pkt, void* co) { func_00133c60(pkt, co, 0, 0, 0); }
void func_002e6210(Tex2e6210* t, void* pkt, s32 tbp)
{
    s16 psm = 0;
    switch (t->img->format) {
    case 0:
        break;
    case 1:
        psm = 2;
        break;
    case 2:
        psm = 1;
        break;
    case 3:
        psm = 0;
        break;
    case 4:
        psm = 20;
        break;
    case 5:
        psm = 19;
        break;
    }
    func_001097e8(t, tbp, t->img->w >> 6, 0, 0, t->img->w, t->img->h, psm, t->pixels);
    func_00133c60(pkt, t, 0, 0, 0);
    s32 cbp = tbp + t->img->size / 256;
    s32 tw = 0;
    while ((1 << tw) < t->img->w) tw++;
    s32 th = 0;
    while ((1 << th) < t->img->h) th++;
    if (t->clut) {
        if (psm == 20) ld1(t->clutObj, pkt, cbp, 2, t->clut);
        else ld1(t->clutObj, pkt, cbp, 16, t->clut);
        t->tex0 = GS_SET_TEX0(tbp, (u16)(t->img->w >> 6), psm, tw, th, 1, 0, cbp, 0, 0, 0, 1);
    } else { t->tex0 = GS_SET_TEX0(tbp, (u16)(t->img->w >> 6), psm, tw, th, 1, 0, 0, 0, 0, 0, 0); }
}
}
