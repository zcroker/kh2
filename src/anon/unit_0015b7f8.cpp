// Linked unit: 0x0015b7f8 (was whole asm). dk::Radar window set-up: back panel, four edges, four corners,
// body sized from the texture, icon. Plain member function; the edges are indexed directly in every call
// (no pointer or reference locals: where an address is first computed decides the argument order of the calls).
// The UV words are SCE_GS_SET_UV pairs ((v * 16 + 8) << 16 | (u * 16 + 8)); setUV is dk::RectBase::setGsUV(u64, u64).
// Own row: its 64-bit colour constant sits at .rodata 0x36b3c8, after data the previous unit does not define.
#include "../common/types.h"

namespace n0015b7f8 {
void func_001665d8(u32 id, u32 *w, u32 *h, u32 *a, u32 *b, u32 *c, u32 *d) asm("func_001665d8");
struct Spr {
    u8 b[256];
    void setTex(s32 tex) asm("func_0014b5e0");
    void setSize(u16 w, u16 h) asm("func_0014b208");
    void setRgba(u64 rgba) asm("func_0014b608");
    void setUV(u64 uv0, u64 uv1) asm("_ZN2dk8RectBase7setGsUVEyy");
    void setFlip(s32 f) asm("func_0014b518");
    void set630(s32 a) asm("func_0014b630");
    void set620(s32 a) asm("func_0014b620");
    void setScale(u16 w, u16 h) asm("func_0014b468");
};
struct Ft4 {
    u8 b[288];
    void setTex(s32 tex) asm("func_0013ee38");
    void setUV(u64 a, u64 b, u64 c, u64 d) asm("_ZN2dk7Ft4Base7setGsUVEyyyy");
    void setSize(u16 w, u16 h) asm("func_0014b208");
};
struct RadarWin {
    Spr body; u8 pad256[80];
    Ft4 icon;
    Spr back;
    Spr edge[4];
    Spr corner[4];
    u32 id;
    void init() asm("func_0015b7f8");
};
void RadarWin::init() {
    u32 w, h, a, b, c, d;
    back.setTex(262);
    back.setSize(80, 80);
    back.setRgba(0x00ffffff000800d8ULL);
    for (s32 i = 0; i < 4; i++) {
        edge[i].setTex(278);
        edge[i].setRgba(0x00ffffff000800d8ULL);
        corner[i].setTex(278);
        corner[i].setRgba(0x00ffffff000800d8ULL);
        corner[i].setSize(8, 8);
    }
    edge[0].setUV(0x80188, 0x7801f8);
    edge[1].setUV(0x80188, 0x7801f8);
    edge[2].setUV(0x80008, 0x780078);
    edge[3].setUV(0x80008, 0x780078);
    edge[0].setSize(80, 8);
    edge[1].setSize(80, 8);
    edge[2].setSize(8, 80);
    edge[3].setSize(8, 80);
    edge[1].setFlip(2);
    edge[2].setFlip(1);
    for (s32 i = 0; i < 4; i++) corner[i].setUV(0x880008, 0xf80078);
    corner[0].setFlip(3);
    corner[1].setFlip(2);
    corner[2].setFlip(1);
    func_001665d8(id, &w, &h, &a, &b, &c, &d);
    body.setSize(w, h);
    body.setTex(342);
    body.set630(0);
    body.set620(84);
    body.setScale(w - 1, h - 1);
    icon.setTex(340);
    icon.setSize(16, 16);
    icon.setUV(0x80088, 0x80178, 0xf80088, 0xf80178);
}
}  // namespace n0015b7f8
