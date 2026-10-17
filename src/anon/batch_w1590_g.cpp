#include "../common/types.h"
extern "C" {
struct W1590C4 { u8 b[4]; };
u32 func_00103570(void);
void* func_001063c0(s32, u32);
void func_001a8bb8(void*);
W1590C4* func_001a8bd0(s32);
void func_0023f800(void*);
extern W1590C4* D_0035f4f4;
extern u8 D_0035f4f8;
extern u8 D_0035f4f9;
extern u8 D_0035f4fa;
extern void* D_0035f598;
extern void* D_0035f59c;
extern s8 D_0035f5a0;
extern s8 D_0035f5a1;
extern s8 D_0035f5a2;
extern s8 D_0035f5a3;

void func_00293708(void) {
    W1590C4* p;
    D_0035f4fa = 1;
    D_0035f4f8 = 0;
    D_0035f4f9 = 0;
    p = (W1590C4*)func_001063c0(4, func_00103570());
    func_001a8bb8(p);
    D_0035f4f4 = p;
    *p = *func_001a8bd0(-1);
}

void func_00297cf8(void) {
    void* p;
    D_0035f598 = func_001063c0(0x14, func_00103570());
    p = func_001063c0(0x1c, func_00103570());
    func_0023f800(p);
    D_0035f59c = p;
    D_0035f5a0 = -1;
    D_0035f5a1 = -1;
    D_0035f5a3 = 0;
    D_0035f5a2 = 0;
}
}
