#include "../common/types.h"

extern "C" {
void func_00161598(void*);
void func_00161668(void*, f32);
void func_0011ea40(f32, u32);
extern f32 D_00349e10;

// 00160430: moved to src/harata/libdk/bgobj.cpp

struct W1752Tbl { u8 pad[0xa00]; s32 arr[128]; };
extern W1752Tbl D_01c60d50;
extern s32 D_01c61950;
extern u8 D_01c60d10[];
void w1752_wt_001cd660(void*) asm("_Z16wtarget_001cd660jjjj");

void func_001900d0(void) {
    s32 i;
    for (i = 0; i < 128; i++) D_01c60d50.arr[i] = i;
    D_01c61950 = 128;
    w1752_wt_001cd660(D_01c60d10);
}
}
