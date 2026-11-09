// func_00294f78: builds menu entries from the item table (one per usable slot), sets them up and marks D_0035f581.
// Built with -fno-strict-aliasing -fmove-all-movables (_nsamam). The explicit down-counting do-while with the
// obj/menu pointer locals gives the original preheader order (move s3,t5 before move s4,s0).
#include "../common/types.h"
extern "C" {
extern u8 D_0035f580;
extern u8 D_0035f581;
extern s32 D_0035f3d4;
extern s32 D_0035f210;
extern s32 D_0035f57c;
extern s32 D_0035f200;
u8* func_002766d0();
u8* func_00294000(u32);
s32 func_002941a8(u8*);
s32 func_00276c18();
s32 func_0023f1b0(s32);
s32 func_0023c4b8(s32, s32);
s32 func_0023f988(s32, s32);
void func_002362b0(u8*, s32);
void func_001386e0(u8*, s32, s32, u8*, s32, s32);
void func_00139620(u8*);
u8* func_002891b8(s32, s32);
void func_0028dcc0(u8*, u8*);

void func_00294f78(u8 flag) {
    u8* w = func_002766d0();
    if (!D_0035f580) return;
    if (D_0035f581) return;
    s32 v;
    s32 cnt = 0;
    u8* t = func_00294000(0);
    s32 n = *(s32*)(t + 8);
    v = D_0035f3d4 + 1;
    u8* base = t + 16;
    if (n > 0) {
    u8* e = base;
    u8* a = w + 0xDCA0;
    s32 c = n;
    u8* o = w;
    u8* a2 = a;
    do {
        if (*(s8*)e < 16) {
            s32 r = func_002941a8(e);
            if (r || func_00276c18()) {
                s32 k = *(s8*)e;
                if (r == 0) k = 16;
                s32 x = func_0023c4b8(func_0023f1b0(D_0035f210), 2);
                func_002362b0(a, func_0023f988(D_0035f57c, k));
                a[400] = 1;
                s32 q, m;
                if (flag) { q = 1; m = 2; } else { q = 2; m = -1; }
                u8* p = o + 0x4398;
                func_001386e0(p, v, x, a2, q, 0);
                a += 416;
                *(s32*)(o + 0x4520) = m;
                func_00139620(p);
                a2 += 416;
                o[0x452d] = 1;
                *(u32*)(o + 0x4468) |= 8;
                s32 cc = cnt++;
                o += 408;
                func_0028dcc0(p, func_002891b8(D_0035f200, cc));
            }
        }
        e += 16;
    } while (--c);
    }
    D_0035f581 = 1;
}

}
