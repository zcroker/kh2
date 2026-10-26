#include "../common/types.h"
extern "C" {
extern s32 D_0035f650;
extern s32 D_0035f664;
extern s32 D_0035f670;
void func_001039f8(void);
s32 func_00139d78(s32);
s32 func_00233e60(void);
void func_00233e70(s32);
s32 func_0023f0c0(s32);
void func_00259fb8(void); void func_0025a200(void); void func_0025a468(void); void func_0025a660(void);
void func_0025aa10(void); void func_0025adf0(void); void func_0025af70(void); void func_0025b050(void);
void func_0025b218(void); void func_0025b5e0(void); void func_0025b7b8(void); void func_0025bbe0(void);
void func_0025bd98(void); void func_0025c3c0(void); void func_0025caf0(void); void func_0025ccf0(void);
void func_0025cd78(void); void func_0025d4e8(void);
u32 func_00287bc0(void);
void func_00287d68(void);
s32 func_00287db0(void);
s32 func_0028acc8(s32);
void func_00290420(s32);
s32 func_00290580(s32);
s32 func_002b55e0(void);
void func_002b5af0(void);
void func_002b6418(void);
s32 func_00259c60(void) {
    func_00287d68();
    func_002b6418();
    if (func_00287db0()) {
        func_00233e70(0);
        if (!func_00233e60()) return 0;
        if (func_00139d78(D_0035f664) || func_002b55e0() || func_0028acc8(D_0035f650)) return 0;
        func_002b5af0();
        func_0025d4e8();
        func_001039f8();
        return 1;
    } else {
        if (func_00290580(D_0035f670)) func_00290420(D_0035f670);
        if (func_00139d78(D_0035f664) == 0 || func_0023f0c0(D_0035f664) == 1) {
            switch (func_00287bc0()) {
            case 0: func_00259fb8(); break;
            case 1: func_0025a200(); break;
            case 2: func_0025a468(); break;
            case 3: func_0025b050(); break;
            case 4: func_0025b218(); break;
            case 9: func_0025adf0(); break;
            case 11: func_0025af70(); break;
            case 12: func_0025b7b8(); break;
            case 8: case 13: func_0025aa10(); break;
            case 14: func_0025c3c0(); break;
            case 15: func_0025bd98(); break;
            case 19: func_0025caf0(); break;
            case 20: func_0025bbe0(); break;
            case 21: func_0025b5e0(); break;
            case 5: case 7: case 10: case 22: func_0025a660(); break;
            case 23: func_0025ccf0(); break;
            case 24: func_0025cd78(); break;
            }
        }
    }
    return 0;
}
}
