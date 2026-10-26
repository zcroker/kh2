#include "../common/types.h"
extern "C" {
extern s32 D_0035f650;
extern s32 D_0035f664;
void func_001039f8(void);
s32 func_00139d78(s32);
s32 func_00233e60(void);
void func_00233e70(s32);
s32 func_0023f0c0(s32);
void func_0025dbd8(void); void func_0025dde8(void); void func_0025dfb0(void); void func_0025e370(void);
void func_0025e450(void); void func_0025e8a0(void); void func_0025ebb0(void); void func_0025ee88(void);
void func_0025f550(void);
u32 func_00287bc0(void);
void func_00287d68(void);
s32 func_00287db0(void);
s32 func_0028acc8(s32);
s32 func_002b55e0(void);
void func_002b5af0(void);
void func_002b6418(void);
s32 func_0025da20(void) {
    func_00287d68();
    func_002b6418();
    if (func_00287db0()) {
        func_00233e70(0);
        if (!func_00233e60()) return 0;
        if (func_00139d78(D_0035f664) || func_002b55e0() || func_0028acc8(D_0035f650)) return 0;
        func_002b5af0();
        func_0025f550();
        func_001039f8();
        return 1;
    } else {
        if (func_00139d78(D_0035f664) == 0 || func_0023f0c0(D_0035f664) == 1) {
            switch (func_00287bc0()) {
            case 1: func_0025dbd8(); break;
            case 2: func_0025dde8(); break;
            case 4: func_0025e450(); break;
            case 5: case 7: func_0025dfb0(); break;
            case 11: func_0025e370(); break;
            case 12: func_0025e8a0(); break;
            case 18: func_0025ebb0(); break;
            case 23: func_0025ee88(); break;
            }
        }
    }
    return 0;
}
}
