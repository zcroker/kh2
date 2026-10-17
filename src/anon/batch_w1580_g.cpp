#include "../common/types.h"

extern "C" {

extern s32 D_0035f010;
void func_00138c10(u8*, s32);
s32 func_00139d78(void*);
s32 func_00192048(s32);
void func_00192e50(s32, s32, s32, s32, s32);
s32 func_00103550(void);
s32 func_00103b38(void);
void func_00253180(s32, s32);
s32 func_002570a0(s32);
s32 func_00257130(void);
s32 func_00257140(s32);
void func_002571e0(s32);
void func_00257458(s32, s32);
u8* func_00257770(void);
u16 func_002594b8(u8);
u8* func_002632d0(s32);
void func_002634d8(s32);
void func_0027dc08(void);
s32 func_00281198(s32, s32);
s32 func_00281f18(s32);
s32 func_00281f30(s32);
void func_00282240(s32, s32, s32);
void func_002827f0(s32, s32, s32);
void func_00287cc0(s32);
extern u8 D_00372ea0[];
void func_00234570(s32, s32);
s32 func_002408d0(s32);
s32 func_00240ba0(void);
void func_002417a0(void);
s32 func_00241a00(void);
s32 func_00241a48(void);
s16* func_00241f10(void);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_00287c00(s32);
void func_00287c30(void);
s32 func_00287cd0(void);
void func_00287d20(s32);
void func_002b4c88(s32);
void func_002b4ee0(void);
s32 func_002b4fb8(void);
void func_002b5108(s32, s32);
void func_002b5188(void*, s32);
struct VObj { void (**vt)(VObj*); };
extern void* D_0035ee58;
extern void* D_0035ee5c;
extern void* D_0035ee60;
extern VObj* D_0035ee64;
extern VObj* D_0035ee68;
void func_0023f070(void*, s32, s32);
s32 func_0023f0c0(void*);
void func_002519b0(void);
void func_00251d80(void*, s32, s32);
s32 func_00251e90(s32);
void func_00251fe0(void);
void func_00252020(void);
s32 func_00252110(s32);
s32 func_00287c50(void);
s32 func_00287db0(void);
void func_00288018(void);
s32 func_002891d0(void*);
s32 func_002891e8(void*);
void func_0028aa40(void*);
s32 func_0028acb8(void*);
s32 func_0028acc8(void*);
void func_0028cc78(s32, s32, s32, void*, s32, s32);
void func_0028cdb8(s32);
void func_0028ce38(void);
void func_0028ce98(s32, s32);
void func_0028cf28(s32, s32);
void func_0028cf98(s32, s32);
s32 func_0028d008(s32);
struct W1580Word4 { u8 b[4]; };
extern void* D_0035f03c;
extern void* D_0035f048;
extern W1580Word4 D_0035f060;
void func_001039f8(void);
void func_0013a368(void);
s32 func_0013a4b8(void);
s32 func_001688b8(void);
W1580Word4* func_001a8bd0(s32);
void func_00254f80(void);
void func_00256aa0(void);
void func_00256f18(void);
void func_00287d68(void);
void* func_00287dc0(void);
s32 func_00288088(void);
void func_00290420(void*);
s32 func_00290580(void*);
s32 func_00293668(void);
void func_002936e8(void);
s32 func_002936f8(void);
s32 func_002938e0(void);
s32 func_002938f0(void);
s32 func_00293948(void);
s32 func_00293b70(void);
void func_00255900(void); void func_0025fb48(void); void func_00267e00(void); void func_002691f8(void);
void func_002693a8(void); void func_00268db8(void); void func_00260418(void); void func_00260ce0(void);
void func_002612c8(void); void func_00261668(void); void func_002618d8(void); void func_00277938(void);
void func_00278318(void); void func_00278dd0(void); void func_0026c470(void); void func_0026c9f0(void);
void func_0026c818(void); void func_002648b8(void); void func_00265018(void); void func_0026f0a0(void);
void func_0026f920(void); void func_0026ff78(void); void func_002708c0(void); void func_0027c700(void);
void func_00283230(void);

void func_002534e0(void) {
    s32 s;
    func_0027dc08();
    s = func_00103550();
    if (func_00103b38() == 0 || s != 50) {
        func_00253180(14, -1);
    }
}

void func_002615b0(void) {
    s32 base = (s32)func_00257770();
    u8* p = func_002632d0(func_002570a0(10));
    s32 a = func_00192048(0xBB90);
    s32 b = func_00192048(func_002594b8(p[2]));
    s32 c = func_00192048(*(u16*)(p + 8));
    base += 0xB290;
    func_00192e50(a, base, 0xC0, b, c);
    func_00257458(base, 0);
    func_002571e0(0);
    func_00287cc0(0);
}

void func_00261820(void) {
    s32 base = (s32)func_00257770();
    u8* p = func_002632d0(func_002570a0(10));
    s32 a = func_00192048(0xB94F);
    s32 b = func_00192048(func_002594b8(p[2]));
    s32 c = func_00192048(*(u16*)(p + 8));
    base += 0xB290;
    func_00192e50(a, base, 0xC0, b, c);
    func_00257458(base, 0);
    func_002571e0(1);
    func_00287cc0(0);
}

void func_00261ce8(s32 a) {
    s32 n = func_00281198(D_0035f010, a) + 5;
    func_00282240(func_00257130(), n, 0);
    func_002827f0(func_00257130(), 0, 0);
}

void func_00261fb8(void) {
    u8* p = func_00257770();
    func_00139d78(p);
    func_002634d8(0);
    s32 k = func_00257140(0);
    s32 q = func_00281f30(func_00257130());
    s32 n = func_00281f18(func_00257130()) < 20 ? func_00281f18(func_00257130()) : 20;
    func_002827f0(func_00257130(), 0, n);
    for (s32 i = 0; i < n; i++) {
        u8* e = p + i * 0x1B4;
        func_00138c10(e + 0x3610, 0x8F);
        func_00138c10(e + 0x5EF0, k);
        *(s32*)(e + 0x6088) = q + 16 + i * 0x50;
    }
}

void func_0025b5e0(void) {
    s32 x = func_00240ba0();
    s32 m = func_00287cd0();
    if (m == 2) {
        if (func_002b4fb8() == 0) {
            func_00287c30();
            func_00287d20(0);
            s32 k = func_00287bc0();
            func_00287cc0(0);
            if (k == 12) {
                func_002417a0();
                func_002b5188(D_00372ea0, 0);
            }
        }
        return;
    }
    if (m == 0) {
        func_00287cc0(1);
    }
    s32 lt = func_00241f10()[1] < func_002408d0(0);
    s32 ok = lt == 0;
    if ((func_00241a00() && func_00241a48()) ||
        (func_00241a00() && !(func_00241f10()[1] < func_002408d0(2)))) {
        ok = 1;
    } else if (func_00241a48()) {
        if (!(func_00241f10()[1] < func_002408d0(1))) ok = 1;
    }
    if (ok) {
        func_002b4ee0();
        func_00287c00(12);
        func_00287cc0(2);
    } else {
        func_00234570(x, 0);
        func_002b5108(0xC6C8, x);
        func_00287bd0(7, 0);
        func_002b4c88(0);
    }
}

void func_00251a70(void) {
    s32 mode = func_00287bc0();
    s32 st = func_00287cd0();
    if (func_00287db0()) {
        if (!func_00139d78(D_0035ee60)) return;
        if (func_0023f0c0(D_0035ee60) == 2) return;
        if (func_00139d78(D_0035ee60) && func_0023f0c0(D_0035ee60) != 2) {
            func_0023f070(D_0035ee60, 2, -1);
        }
        if (func_0028acc8(D_0035ee58) && !func_0028acb8(D_0035ee58)) {
            func_0028aa40(D_0035ee58);
        }
        if (func_0028acc8(D_0035ee5c) && !func_0028acb8(D_0035ee5c)) {
            func_0028aa40(D_0035ee5c);
        }
        if (D_0035ee64 && func_00139d78(D_0035ee64)) {
            D_0035ee64->vt[5](D_0035ee64);
        }
        if (D_0035ee68 && func_00139d78(D_0035ee68)) {
            D_0035ee68->vt[5](D_0035ee68);
        }
        func_00251fe0();
        func_002519b0();
        func_0028ce38();
        func_00288018();
        return;
    }
    func_00252020();
    s32 h = func_00252110(func_002891e8(D_0035ee58));
    void* obj = mode == 0 ? D_0035ee58 : D_0035ee5c;
    s32 idx = mode != 0;
    if (func_00139d78(D_0035ee60) && func_0023f0c0(D_0035ee60) == 1) {
        if (idx == 0) {
            if (!func_0028d008(idx)) {
                func_0028cc78(idx, 2, 2, D_0035ee60, 4, 6);
                func_0028cf98(idx, func_00251e90(h));
            }
        } else {
            if (!func_0028d008(idx)) {
                func_0028cc78(idx, 2, 2, D_0035ee60, 12, 12);
                func_0028cf28(idx, func_002891d0(obj));
            }
        }
    } else if (st == 2 && func_0028d008(idx)) {
        func_0028cdb8(idx);
    }
    if (func_00287c50()) {
        if (func_0028d008(0)) func_0028ce98(0, idx);
    }
    func_00251d80(obj, mode, h);
}

s32 func_00255588(void) {
    func_00287d68();
    func_00256f18();
    if (func_00287db0()) {
        if (!func_002938f0()) return 0;
        if (func_00139d78(func_00287dc0())) return 0;
        if (func_00293948() && !func_00293b70() && func_002936f8()) {
            func_002936e8();
            return 0;
        }
        if (func_002938e0() && !func_002938f0()) return 0;
        if (func_00293b70()) return 0;
        if (func_001688b8()) return 0;
        if (func_00293668()) return 0;
        if (func_00139d78(D_0035f03c)) return 0;
        if (func_0013a4b8()) func_0013a368();
        func_00256aa0();
        func_00254f80();
        D_0035f060 = *func_001a8bd0(-1);
        func_001039f8();
        return 1;
    }
    if (func_00290580(D_0035f048)) func_00290420(D_0035f048);
    if (func_00139d78(D_0035f03c) && func_0023f0c0(D_0035f03c) != 1) {
        if (func_00288088()) func_0023f070(D_0035f03c, 1, -1);
        else return 0;
    }
    switch (func_00287bc0()) {
    case 0: func_00255900(); break;
    case 1: func_0025fb48(); break;
    case 2: func_00267e00(); break;
    case 3: func_002691f8(); break;
    case 4: func_002693a8(); break;
    case 5: case 6: case 7: case 8: case 9: func_00268db8(); break;
    case 10: func_00260418(); break;
    case 11: func_00260ce0(); break;
    case 12: func_002612c8(); break;
    case 13: func_00261668(); break;
    case 14: func_002618d8(); break;
    case 15: func_00277938(); break;
    case 16: func_00278318(); break;
    case 17: case 18: case 19: func_00278dd0(); break;
    case 20: func_0026c470(); break;
    case 21: func_0026c9f0(); break;
    case 22: func_0026c818(); break;
    case 23: func_002648b8(); break;
    case 24: func_00265018(); break;
    case 25: func_0026f0a0(); break;
    case 26: case 27: func_0026f920(); break;
    case 28: func_0026ff78(); break;
    case 29: case 30: case 31: case 32: case 33: func_002708c0(); break;
    case 36: func_0027c700(); break;
    case 37: func_00283230(); break;
    }
    return 0;
}

}
