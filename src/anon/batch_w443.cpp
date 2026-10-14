#include "../common/types.h"
extern "C" {
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_0035e238[];
extern u8 D_0034a958[];
extern u8 D_0035e280[];
void func_0031a838(void*);
void func_00239700(void*);
void func_0013ee88(void*);
void func_0014b668(void*);
void func_00322790(u8* t) {
    u8* p;
    s32 i;
    *(u8**)t = D_00347f98;
    func_0031a838(t + 12);
    *(u8**)t = D_00347e60;
    func_00239700(t + 24);
    *(s32*)(t + 0x1b0) = 0;
    t[0x1b4] = 0;
    *(u8**)t = D_0035e238;
    p = t + 440;
    i = 2;
    do {
        *(u8**)p = D_00347f98;
        func_0031a838(p + 12);
        *(u8**)p = D_00347e60;
        func_00239700(p + 24);
        *(u8**)p = D_0034a958;
        i--;
        p += 412;
    } while (i != -1);
    p = t + 1680;
    i = 3;
    do {
        *(u8**)p = D_00347f98;
        func_0031a838(p + 12);
        *(u8**)p = D_0035e280;
        func_0013ee88(p + 32);
        func_0014b668(p + 320);
        func_0014b668(p + 576);
        i--;
        p += 848;
    } while (i != -1);
    *(s32*)(t + 0x13dc) = 0;
    *(u8**)(t + 0x13d0) = D_00347e60;
    func_00239700(t + 0x13e8);
}
}
