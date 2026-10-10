#include "../common/types.h"
struct W322Ent { s8 c0; s8 c1; s8 c2; s8 c3; };
struct W322Sav { u8 pad[488]; W322Ent e[1][48]; };
struct W322G { u8 pad[28]; s16 h28; s16 h30; s16 h32; s16 h34; u8 pad2[44-36]; u32 bits[2];
    u32 :11; u32 b11:1; u32 b12:2; };
struct W322S3 { u8 b0; u8 b1; u8 b2; };
union W322GU { W322G* p; u8 c; };
struct W322Pr { s8 a; s8 b; };
extern "C" {

extern W322GU D_0035f638;
W322Sav* func_002a9d68(void);
W322S3* func_002b23e0(s32);
u32 func_002b2380(s32, s32);
void func_002b2da8(s32);
void func_002b3050(s32);
void func_002b1bd0(s32);
void func_002b2f28(s32);
extern W322Pr D_003741b0[];
s32 func_002811f8(u32, s32);
s32 func_002811b0(u32, s32);
u32 func_00281fe0(u8* o, s32 a1, s32 m) {
    u32 r = 0; s32 i;
    if (m == 1 || m == 11 || m == 0) {
        if (a1 == 0) {
            for (i = 0; D_003741b0[i].a >= 0; i++) r |= 1 << D_003741b0[i].b;
        } else {
            s32 v = func_002811f8(*(u32*)(o + 4100), a1 < 5 ? a1 - 1 : a1 - 5);
            v = func_002811b0(*(u32*)(o + 4100), v);
            for (i = 0; D_003741b0[i].a >= 0; i++) {
                if (D_003741b0[i].a == v) { r = 1 << D_003741b0[i].b; break; }
            }
        }
    }
    if (m == 2 || m == 0) r |= 0x4000;
    if (m == 3 || m == 0) r |= 0x8000;
    if (m == 4 || m == 0 || m == 10) r |= 1;
    if (m == 5 || m == 0) r |= 2;
    if (m == 6 || m == 0) r |= 0x10000;
    if (m == 7 || m == 0) r |= 0x20000;
    if (m == 8 || m == 0) r |= 0x100000;
    if (m == 9 || m == 10) r |= 0x40000;
    if (m == 12 || m == 0) r |= 0xc000;
    if (m == 13 || m == 0) r |= 3;
    if (m == 14 || m == 0) { r |= 0x20000; r |= 0x10000; r |= 0x100000; }
    return r;
}
static inline void w322_setbit(u32* p, u32 n) { p += n >> 5; *p |= 1 << (n & 31); }
void func_002b0fc8(u32 fl) {
    W322Sav* sv = func_002a9d68();
    W322S3* s3 = func_002b23e0(-1);
    u32 a = func_002b2380(D_0035f638.p->h28, D_0035f638.p->h32);
    if (!D_0035f638.p->b11) {
        D_0035f638.p->h30 = D_0035f638.p->h28;
        D_0035f638.p->h34 = D_0035f638.p->h32;
        D_0035f638.p->b12 = sv->e[s3->b2][a].c1;
        func_002b2da8(1);
    } else {
        if (fl & 4) {
            u32 b = func_002b2380(D_0035f638.p->h30, D_0035f638.p->h34);
            sv->e[s3->b2][a].c1 = D_0035f638.p->b12;
            W322Ent t = sv->e[s3->b2][b];
            sv->e[s3->b2][b] = sv->e[s3->b2][a];
            sv->e[s3->b2][a] = t;
            D_0035f638.p->h28 = D_0035f638.p->h30;
            D_0035f638.p->h32 = D_0035f638.p->h34;
            w322_setbit(D_0035f638.p->bits, a);
            w322_setbit(D_0035f638.p->bits, b);
            func_002b1bd0(0);
        }
        func_002b2f28(1);
    }
    D_0035f638.p->b11 ^= 1;
    func_002b3050(1);
}
}
