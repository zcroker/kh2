#include "../common/types.h"
extern "C" {
extern s32 D_00348060[];
extern s32 D_00348420[];
u32 func_0013b988(void*, void*, u8, s32, s32, s32);
void func_0013c080(void*, void*, s32, s32, u8*, s32, s32*, s32*);
u32 func_0013bc40(void*, s32);
u32 func_0013b9e0(void*, s32);
u8* func_001b8e88(u16);
u32 func_00192048(u32);
u8* func_0013b5d0(void*, s32, s32, void*, u8, s32, s32, u32, f32, u32, s32);
void func_0013bc50(void*, void*, s32, s32, u8, u32, u8*, u8*);

void func_0013c190(u8* p, u8* a1, s32 a2, s32 a3, u8 t0, s32 t1, s32 t2, s32 t3, u8* s6) {
    u8 flag;
    s32 w20;
    s32 w24;
    s32 s4 = *(s32*)(a1 + 108);
    u32 s8 = func_0013b988(p, a1, s6[5], s4, 1, 0);
    u8* v;
    u8* r;
    flag = 0;
    { u32 x = *(u32*)(a1 + 8); if (*(u32*)(p + a2 * 4 + 220) != x) flag = 1; }
    if (*(s32*)(p + a2 * 4 + 204) != s4) flag = 1;
    w24 = -1;
    w20 = D_00348060[t1 * 12 + a3 + 3];
    if (t0 == 1) {
        flag = t0;
        if (*(s32*)a1 == 0 || *(s32*)a1 == 6) w20 = D_00348420[a3];
    }
    func_0013c080(p, s6, a2, a3, &flag, 1, &w20, &w24);
    if (func_0013bc40(p, a2) && func_0013b9e0(p, t1)) flag = 1;
    v = func_001b8e88(*(u16*)(a1 + s4 * 12 + 14));
    r = func_0013b5d0(p, a2, w20, s6, flag, t2 + 8, t3, func_00192048(*(u32*)(v + 8)), 1.0f, s8, 2);
    if (w24 != -1) *(s32*)(r + 392) = w24;
    func_0013bc50(p, a1, a2, a3, flag, s8, v, r);
    *(s32*)(p + a2 * 4 + 204) = s4;
}

s32 func_002384f8(...);

union W319U { u32 w; u16 h[2]; u8* p; };
struct W319BF { u32 b0:4; u32 b4:1; u32 b5:1; u32 b6:1; u32 b7:1; u32 b8:1; u32 b9:1; u32 b10:1; u32 rest:21; };
void func_0023aab8(u8* p) {
    if (*(u8*)(p + 188) == 0) {
        s32 idx = *(s32*)(p + 276);
        u16* e;
        u8* s1;
        s32 n;
        u32 s0;
        ((W319U*)(p + 192))->w = idx;
        *(u8*)(p + 188) = 1;
        e = (u16*)(*(u8**)(p + 180) + idx * 36);
        s0 = 0;
        ((W319U*)(p + 196))->p = *(u8**)(p + 176) + e[0] * 144;
        ((W319U*)(p + 200))->w = e[1];
        n = e[1];
        s1 = *(u8**)(p + 176) + e[0] * 144;
        if (n > 0) {
            do {
                u32 f = *(u32*)s1;
                if (f & 4) s0 |= 1;
                if (*(u32*)(s1 + 132)) s0 |= 2;
                if (!(f & 0x20)) s0 |= 4;
                if (!(f & 0x40)) s0 |= 8;
                if (!(f & 0x400)) s0 |= 0x10;
                if (func_002384f8(p, *(u32*)(s1 + 4))) s0 |= 0x20;
                if ((*(u32*)s1 & 0x1010) != 0x1010) s0 |= 0x40;
                s1 += 144;
                if (s0 == 127) break;
            } while (--n > 0);
        }
        { W319BF* b = (W319BF*)(p + 184);
        b->b4 = 0; b->b5 = 0; b->b6 = 0; b->b7 = 0; b->b8 = 0; b->b9 = 0; b->b10 = 0;
        if (!(s0 & 1)) b->b4 = 1;
        if (!(s0 & 2)) b->b5 = 1;
        if (!(s0 & 4)) b->b6 = 1;
        if (!(s0 & 8)) b->b7 = 1;
        if (!(s0 & 0x10)) b->b8 = 1;
        if (!(s0 & 0x20)) b->b9 = 1;
        if (!(s0 & 0x40)) b->b10 = 1; }
    }
    *(f32*)(p + 204) = (f32)(s32)*(f32*)(p + 260);
}

extern s32 D_0035f3d4;
extern u16 D_00375850[];
extern u8 D_00375840[];
extern u8 D_00375848[];
extern u8 D_00375838[];
u32 func_00288be8(...);
u8* func_0023f1b0(...);
u32 func_0023c4b8(...);
u32 func_00236ca8(...);
u8* func_0028c2c8(...);
s32 func_0023aa98(...);
u32 func_00138c68(...);
u32 func_00324bc0(...);
s32 func_0023aa18(...);
s32 func_0023aa38(...);
u32 func_00288ce0(...);
u32 func_00239870(...);
u32 func_002891f0(...);
u32 func_0028b078(...);
u32 func_0028af90(...);
u32 func_00288f48(...);
u32 func_0028d068(...);
u32 func_0028d1c0(...);
u32 func_002891d0(...);
u32 func_0028d660(...);
u32 func_001396b0(...);

struct W319C { void f(s32, s32) asm("func_002889f0"); };
void func_002ca828(u8* p) {
    u8 buf[352];
    s32 i;
    u32 s2;
    u32 s7;
    u32 s6;
    D_0035f3d4 = 30020;
    s2 = func_00288be8(56);
    ((W319C*)s2)->f(2, 1);
    *(u32*)(p + 188) = s2;
    s7 = func_0023c4b8(func_0023f1b0(p + 28), 1);
    s6 = func_00236ca8(*(u32*)(func_0023f1b0(p + 28) + 40), 1);
    for (i = 0; i < 2; i++) {
        u8* v;
        u8* o;
        s32 a, b;
        v = func_0028c2c8(s7, s6, 58, i ? 18564 : D_00375850[*(s32*)(p + 640) - 1], 0);
        *(s32*)(v + 392) = 59;
        o = v + 24;
        func_00138c68(v, 0, func_0023aa98(o) * i);
        *(s32*)(v + 432) = 2;
        func_00324bc0(buf, o);
        a = -func_0023aa18(buf);
        b = -func_0023aa38(buf);
        *(s32*)(v + 412) = a;
        *(s32*)(v + 416) = b;
        func_00288ce0(s2, v, i, D_00375840, D_00375848);
        func_00239870(buf);
    }
    func_002891f0(s2, 0, 1, 0, 2);
    func_0028b078(s2, 1, 2);
    func_0028af90(s2, 2);
    func_00288f48(s2, 16, 32, 64, 128);
    func_0028d068(30040, -1);
    func_0028d1c0(p + 192, 30050, 1, 1, p + 28, D_00375838, 0);
    func_0028d660(p + 192, func_002891d0(s2));
    func_001396b0(p + 192);
}
}
