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
void func_0028b078(void*, s32, s32);  // obj_setup_from_args
void func_0028af90(void*, s32);  // obj_set_field22_from_arg
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028d068(s32, s32);
void func_0028d1c0(void*, s32, s32, s32, void*, void*, s32);
s32 func_002891d0(void*);
void func_0028d660(void*, s32);  // record_set_value_refresh
void func_001396b0(void*);
void func_002c4ca8(u8* p);  // 0x002c4ca8: definition moved into src/anon/unit_002c4ca8.cpp
}
