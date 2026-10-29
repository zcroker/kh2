#include "../common/types.h"
// Sony-style GIF/GS packing macros (sprite strip packet builder, 0014da40). Built with -fno-strict-aliasing.
typedef u64 u_long;
#define GIF_TAG(nloop, eop, pre, prim, flg, nreg) \
    ((u_long)(nloop) | ((u_long)(eop)<<15) | ((u_long)(pre) << 46) | \
    ((u_long)(prim)<<47) | ((u_long)(flg)<<58) | ((u_long)(nreg)<<60))
#define GS_RGBAQ(r, g, b, a, q) \
    ((u_long)(r) | ((u_long)(g) << 8) | ((u_long)(b) << 16) | \
    ((u_long)(a) << 24) | ((u_long)(q) << 32))
#define GS_XYZ(x, y, z) ((u_long)(x) | ((u_long)(y) << 16) | ((u_long)(z) << 32))
struct Pk14da40 { u16 qwc; u8 pad2; u8 id; void* addr; u8 pad8[8]; };
struct XY14da40 { u64 a; u64 b; };
struct S14da40 {
    u8 pad0[4]; u16 w; u16 h; u8 pad8[0x88];
    Pk14da40 pk; u64 tag[2]; u64 prim[2]; u64 tag2[2]; XY14da40 xy[0x10]; u8 pad1d0[6]; u8 r, g, b;
};
extern "C" {
void func_0014da40(S14da40* s) {
    int n = s->w >> 5;
    s->tag[0] = GIF_TAG(1, 0, 0, 0, 1, 2);
    s->tag[1] = 0x10;
    s->prim[0] = 6;
    s->prim[1] = GS_RGBAQ(s->r, s->g, s->b, 0x80, 1);
    s->tag2[0] = GIF_TAG(n, 1, 0, 0, 1, 2);
    s->tag2[1] = 0x55;
    u32 x = (s64)(0x800 - (s->w >> 1)) * 16;
    u32 y = (s64)(0x800 - (s->h >> 1)) * 16;
    if (n) {
        u32 xb = x + 512;
        u32 xa = x;
        S14da40* q = s;
        int c = n;
        do {
            q->xy[0].a = GS_XYZ(xa, y, 0);
            q->xy[0].b = GS_XYZ(xb, y + s->h * 16, 0);
            q = (S14da40*)((u8*)q + 16); xb += 512; xa += 512;
        } while (--c);
    }
    Pk14da40* p = &s->pk;
    p->id = 0;
    p->addr = s->tag;
    s->pk.qwc = (n * sizeof(XY14da40) + 0x30) >> 4;
}
}
