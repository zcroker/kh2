#include "../common/types.h"

// Built with -g (see BRIEF_G.md): the s-register save stays before the first jal.
extern "C" {
u32 func_00257770();
u32 func_00257130();
u32 func_00139d78(u32);
void func_0028da70(u32, s32);
u32 func_00281f20(u32);
s32 func_0028b040(u32);
s32 func_00285d58(u32);
s32 func_00285e30(u32);
void func_00285f50(u32);
s32 func_002891e8(u32);
void func_00138c10(u32, s32);
extern u32 D_0035f01c;
extern s32 D_00373278;
extern s32 D_0037327c;

u32 func_00262650(void) {
    u32 base = func_00257770();
    u32 r = func_00139d78(base + 0x9C8);
    if (r == 0) {
        s32 i;
        for (i = 0; i < 5; i++) {
            if (func_00139d78(base + 0xD30 + i * 0x1B4) != 0) { r = 1; break; }
        }
        if (r == 0) r = func_00139d78(base + 0x330);
    }
    return r;
}

void func_00262730(void) {
    u32 p = func_00257770() + 0x9C8;
    func_00139d78(p);
    func_0028da70(p, 0xF2);
}

void func_00262a30(void) {
    u32 base = func_00257770();
    u32 info = func_00281f20(func_00257130());
    u16* e = (u16*)(func_0028b040(D_0035f01c) * 6 + info);
    s32 n;
    if (func_00285d58(*e) == 0) return;
    func_00285f50(*e);
    if (func_00285e30(*e) != 0) n = D_0037327c;
    else n = D_00373278;
    func_00138c10(base + func_002891e8(D_0035f01c) * 0x198 + 0x87D0, n);
}

void func_00262f58(void) {
    u32 p = func_00257770();
    func_0028da70(p, 0x129);
    func_0028da70(p + 0xB350, 0x132);
}

s32 func_00265740(void) {
    u32 p = func_00257770();
    func_00139d78(p);
    return *(s32*)(p + 0x184) == 0x8D;
}

s32 func_00265c10(void) {
    u32 p = func_00257770();
    func_00139d78(p);
    return *(s32*)(p + 0x184) == 0x141;
}
}
