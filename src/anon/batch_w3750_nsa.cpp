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

// 0014e2c0: moved to src/harata/libdk/fpscamera.cpp
}
