// 0014e2c0 GS copy packet (draw env + TEX0 + strip sprites), built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"
#define GS_ZBUF(zbp, psm, zmsk) ((u64)(zbp) | ((u64)(psm) << 24) | ((u64)(zmsk) << 32))
#define GS_FRAME(fbp, fbw, psm, fbmsk) \
    ((u64)(fbp) | ((u64)(fbw) << 16) | ((u64)(psm) << 24) | ((u64)(fbmsk) << 32))
#define GS_SCISSOR(x0, x1, y0, y1) \
    ((u64)(x0) | ((u64)(x1) << 16) | ((u64)(y0) << 32) | ((u64)(y1) << 48))
#define GS_XYOFFSET(ofx, ofy) ((u64)(ofx) | ((u64)(ofy) << 32))
#define GS_RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define GS_UV(u, v) ((u64)(u) | ((u64)(v) << 16))
#define GS_XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
#define GS_CLAMP(wms, wmt, minu, maxu, minv, maxv) ((u64)(wms) | ((u64)(wmt) << 2))
#define GIF_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u64)(nloop) | ((u64)(eop) << 15) | ((u64)(pre) << 46) | ((u64)(prim) << 47) | ((u64)(flg) << 58) | ((u64)(nreg) << 60))

struct DmaTag {
    u16 qwc; u8 pad; u8 id; void* next;
    void Set(u16 q, void* n) { qwc = q; id = 0; next = n; }
};
struct Env { u32 fbp; u16 w; u16 h; u16 psm; u8 pad[6]; };
struct TexInfo { u32 w0; u16 w; u16 h; u16 h8; u8 pad[6]; };
struct Strip { u64 uv0, xyz0, uv1, xyz1; };
struct Pkt {
    u64 giftag[2];
    u64 zbuf, zbufReg;
    u64 frame, frameReg;
    u64 tex0, tex0Reg;
    u64 tex1, tex1Reg;
    u64 test, testReg;
    u64 alpha, alphaReg;
    u64 scissor, scissorReg;
    u64 xyoffset, xyoffsetReg;
    u64 clamp, clampReg;
    u64 giftag2[2];
    u64 prim, rgbaq;
    u64 giftag3[2];
    Strip strip[16];
};
struct CopyPkt {
    DmaTag tag; u8 pad0[8];
    Pkt pkt;
    Env env;
    TexInfo tex;
    u8 pad1[0x4d0 - 0x300];
    u8 bright;
};
extern "C" {
u64 func_00166730(TexInfo*);

void func_0014e2c0(CopyPkt* p)
{
    Env* env = &p->env;
    TexInfo* tex = &p->tex;
    Pkt* g = &p->pkt;
    s32 n = env->w >> 5;
    g->giftag[1] = 0xeeeeeeeeeULL;
    g->zbuf = GS_ZBUF(0x70, 0x31, 1);
    g->zbufReg = 0x4e;
    g->giftag[0] = GIF_TAG(1, 0, 0, 0, 0, 9);
    g->frame = GS_FRAME(env->fbp, (u16)(env->w >> 6), env->psm, 0);
    g->frameReg = 0x4c;
    g->tex0 = func_00166730(tex);
    g->tex0Reg = 6;
    g->tex1 = 0x60;
    g->tex1Reg = 0x14;
    g->test = 0x30000;
    g->testReg = 0x47;
    g->alpha = 0x44;
    g->alphaReg = 0x42;
    g->scissor = GS_SCISSOR(0, env->w - 1, 0, env->h - 1);
    g->scissorReg = 0x40;
    g->xyoffset = GS_XYOFFSET((2048 - (env->w >> 1)) << 4, (2048 - (env->h >> 1)) << 4);
    g->xyoffsetReg = 0x18;
    g->clamp = 5;
    g->clampReg = 8;
    g->giftag2[0] = GIF_TAG(1, 0, 0, 0, 1, 2) | 1;
    g->giftag2[1] = 0x10;
    g->prim = 0x116;
    g->rgbaq = GS_RGBAQ(p->bright, p->bright, p->bright, 0x80, 1);
    g->giftag3[0] = GIF_TAG(n, 1, 0, 0, 1, 4);
    g->giftag3[1] = 0x5353;
    s32 q = tex->w / n;
    s32 h = env->h;
    u64 tx = (u64)(2048 - (env->w >> 1)) << 4;
    s32 ofx = tx;
    u64 ty = (u64)(2048 - (env->h >> 1)) << 4;
    s32 ofy = ty; u16 hh = h;
    u16 th = tex->h;
    for (s32 i = 0; i < n; i++) {
        Strip* s = &g->strip[i];
        s->uv0 = GS_UV(((i * q) << 4) + 8, 8);
        s->xyz0 = GS_XYZ((u32)(ofx + (i << 9)), (u32)ofy, 0);
        s->uv1 = GS_UV((((i + 1) * q) << 4) + 8, (th << 4) + 8);
        s->xyz1 = GS_XYZ((u32)(ofx + ((i + 1) << 9)), (u32)(ofy + (hh << 4)), 0);
    }
    p->tag.Set((n * 32 + 208) >> 4, g->giftag);
}
}
