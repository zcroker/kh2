#include "../common/types.h"
extern "C" {
s32 func_00287cd0(s32);
s32 func_002891d0(s32);
void func_002891e8(s32);
s32 func_00289310(s32);
s32 func_00289358(s32);
void func_0028cf28(s32, s32);
s32 func_0028d008(s32);
void func_0028d660(s32, s32);
s32 func_0028d6e8(s32);
void func_00295668(s32, u32, s32);
void func_00296ea8(s32, u32, s32);
void func_00297878(s32, u32, s32);
void func_00298e20(s32, u32, s32);
void func_0029a718(s32, u32, s32);
void func_0029cd70(s32, u32, s32);
void func_002a0168(s32, u32, s32);
void func_002a6308(s32, u32, s32);
void func_002a82f8(s32, u32, s32);
void func_002a9570(s32, u32, s32);
extern s32 D_0035f218;

void func_002756f8(s32 a0, u32 a1, s32 a2) {
    if (func_00287cd0(a0) != 1) return;
    if (func_00289310(a0)) {
        func_002891e8(a0);
        if (func_0028d008(a2)) func_0028cf28(a2, func_002891d0(a0));
        if (func_0028d6e8(D_0035f218)) func_0028d660(D_0035f218, func_002891d0(a0));
    }
    if (func_00289310(a0) || func_00289358(a0)) {
        switch (a1) {
        case 0: func_00295668(a0, a1, a2); return;
        case 1: case 2: func_00296ea8(a0, a1, a2); return;
        case 3: func_00297878(a0, a1, a2); return;
        case 4: case 5: func_00298e20(a0, a1, a2); return;
        case 13: func_0029a718(a0, a1, a2); return;
        case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23:
            func_0029cd70(a0, a1, a2); return;
        case 24: case 25: func_002a0168(a0, a1, a2); return;
        default: return;
        case 10: case 35: func_002a9570(a0, a1, a2); return;
        case 11: case 36: func_002a82f8(a0, a1, a2); return;
        case 37: case 38: func_002a6308(a0, a1, a2); return;
        }
    }
}

void func_00138c10(u8*, s32);
void func_00138c68(u8*, s32, s32);
void func_00192cc0(u8*, u32*, s32);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
void func_0028dcc0(u8*, u8*);
s32 func_00291370(u8*, s32);
u8* func_002924d0(u8*, s32);
extern u32 D_00374498;
extern u32 D_003744a0;

void func_00291918(u8* obj, s32 mode, s32 id1, s32 id2, s32 mask);  // 00291918: moved to src/anon/unit_00290f78.cpp

struct Info { u8 pad[0x18]; s32 mask; u8 pad2[2]; s8 b1e; s8 b1f; };
s32 func_00266c70(void);
union InfoP { Info* p; s32 i; };
extern InfoP D_0035f0e4;

void func_00266df8(u32 arg0) {
    s32 i;
    s32 b;
    D_0035f0e4.p->mask = 0;
    switch (arg0) {
    case 0: case 7: case 8: case 9:
        for (i = 0; i < 6; i++) D_0035f0e4.p->mask |= 1 << i;
        for (i = 10; i < 17; i++) D_0035f0e4.p->mask |= 1 << i;
        if (arg0 == 0) {
            if (func_00266c70()) D_0035f0e4.p->mask |= 0x40;
            D_0035f0e4.p->mask |= 0x80;
            for (i = 0; i < 7; i++) {
                if (((D_0035f0e4.p->b1f >> i) ^ 1) & 1) continue;
                b = 0;
                switch (i) {
                case 1: b = 17; break;
                case 2: b = 8; break;
                case 3: b = 18; break;
                case 4: b = 9; break;
                case 5: b = 19; break;
                }
                D_0035f0e4.p->mask |= 1 << b;
            }
        }
        break;
    case 1: case 2: case 3: case 4: case 5:
        for (i = 0; i < 4; i++) D_0035f0e4.p->mask |= 1 << i;
        for (i = 10; i < 17; i++) D_0035f0e4.p->mask |= 1 << i;
        break;
    case 6:
        for (i = 0; i < 4; i++) D_0035f0e4.p->mask |= 1 << i;
        for (i = 0; i < 4; i++) {
            if ((D_0035f0e4.p->b1e >> i) & 1) {
                b = 0;
                switch (i) {
                case 0: b = 10; break;
                case 1: b = 11; break;
                case 2: b = 12; break;
                case 3: b = 13; break;
                }
                D_0035f0e4.p->mask |= 1 << b;
            }
        }
        break;
    }
}
}
