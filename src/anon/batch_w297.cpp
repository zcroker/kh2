#include "../common/types.h"
struct Sub297 { u8 pad[184]; u32 f; void Set8() { f |= 8; } };
extern "C" {
union UP297 { u8* p; u32 u; u8 c; };
extern UP297 D_0035f2d8;
extern UP297 D_0035f2dc;
extern s32 D_0035f2c8;
extern u8 D_00374378[];
void func_00139d78(void*);
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00139620(void*);
s32 func_00192048(void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
s32 func_0023aa78(void*);
void func_00259108(void*, s32, s32, s32, s32, s32, void*);
u8* func_002891b8(void*, s32);
void func_0028dcc0(void*, void*);
void func_00138c68(void*, s32, s32);
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028af28(void*, s32);
void func_002854d8(void* p, u8 flag) {
    func_00139d78(D_0035f2d8.p);
    func_0028d980(D_0035f2d8.p, 30013, 0, 0, D_0035f2c8, 4, 5, -1, 0);
    func_00139620(D_0035f2d8.p);
    *(s32*)(D_0035f2d8.p + 432) = 2;
    D_0035f2d8.p[405] = 1;
    ((Sub297*)(D_0035f2d8.p + 24))->Set8();
    u8* q = D_0035f2d8.p;
    *(s32*)(q + 408) = func_00192048(p);
    s32 x = func_0023aa18(D_0035f2d8.p + 24);
    s32 y = func_0023aa38(D_0035f2d8.p + 24);
    s32 n, m;
    if (flag) { m = 1; n = 2; }
    else { m = 0; n = 1; }
    func_00259108(D_0035f2dc.p, 30013, 0, 0, D_0035f2c8, m, D_00374378);
    for (s32 i = 0; i < n; i++) {
        func_0028dcc0(func_002891b8(D_0035f2dc.p, i), D_0035f2d8.p);
        s32 w = func_0023aa78(func_002891b8(D_0035f2dc.p, i) + 24);
        func_00138c68(func_002891b8(D_0035f2dc.p, i), x + w * i, y);
        ((Sub297*)(func_002891b8(D_0035f2dc.p, i) + 24))->Set8();
    }
    func_00288f48(D_0035f2dc.p, 128, 64, 0, 0);
    func_0028af28(D_0035f2dc.p, flag ? 64 : 96);
}
extern s32 D_0035f3d4;
extern u16 D_00375608[];
extern u16 D_003755d0[];
extern u16 D_003755d8[];
extern u16 D_00375598[];
void* func_00288be8(s32);
void func_002889f0(void*, s32, s32);
u8* func_0028c2c8(s32, s32, s32, s32, s32);
s32 func_0023aa98(void*);
void func_00138c68(void*, s32, s32);
void func_00324bc0(void*, void*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_00288ce0(void*, void*, s32, void*, void*);
void func_00239870(void*);
void func_002891f0(void*, s32, s32, s32, s32);
void func_0028b078(void*, s32, s32);
void func_0028af90(void*, s32);
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028d068(s32, s32);
void func_0028d1c0(void*, s32, s32, s32, void*, void*, s32);
s32 func_002891d0(void*);
void func_0028d660(void*, s32);
void func_001396b0(void*);
void func_002c4ca8(u8* p) {
    D_0035f3d4 = 30020;
    void* g = func_00288be8(56);
    func_002889f0(g, 2, 1);
    *(void**)(p + 872) = g;
    for (s32 i = 0; i < 2; i++) {
        s32 id = 18564;
        if (i == 0) id = D_00375608[*(s32*)(p + 8236)];
        u8* o = func_0028c2c8(*(s32*)(p + 13640), *(s32*)(p + 13644), 58, id, 0);
        *(s32*)(o + 392) = 59;
        func_00138c68(o, 0, func_0023aa98(o + 24) * i);
        *(s32*)(o + 432) = 2;
        u8 buf[352] __attribute__((aligned(16)));
        func_00324bc0(buf, o + 24);
        s32 w = -func_0023aa18(buf);
        s32 h = -func_0023aa38(buf);
        *(s32*)(o + 412) = w;
        *(s32*)(o + 416) = h;
        func_00288ce0(g, o, i, D_003755d0, D_003755d8);
        func_00239870(buf);
    }
    func_002891f0(g, 0, 1, 0, 2);
    { s32 b = 2; func_0028b078(g, 1, b); }
    func_0028af90(g, 2);
    func_00288f48(g, 16, 32, 64, 128);
    func_0028d068(30040, -1);
    func_0028d1c0(p + 876, 30050, 1, 1, p + 28, D_00375598, 0);
    func_0028d660(p + 876, func_002891d0(g));
    func_001396b0(p + 876);
}
}
