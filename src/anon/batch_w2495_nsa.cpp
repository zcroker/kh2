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
// 0014da40: moved to src/anon/unit_0014d680.cpp
}
