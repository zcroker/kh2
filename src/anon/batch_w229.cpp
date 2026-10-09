#include "../common/types.h"
extern "C" {
void func_002361a0(void*);
void func_00239700(void*);
extern u8 D_0034a548, D_00347e80, D_00347e60;
struct E { void* vt; u8 p[8]; u32 w0c; u8 q[0x0c]; };
void func_0031bc58(u32* t) {
    t[0] = (u32)&D_0034a548;
    t[0x30/4] = (u32)&D_00347e80;
    t[3] = 0;
    t[0x3c/4] = 0;
    func_002361a0((u8*)t + 0x50);
    func_00239700((u8*)t + 0x1f0);
    u8* e = (u8*)t + 0x348;
    int i = 12;
    do {
        *(u32*)(e + 12) = 0;
        *(u32*)e = (u32)&D_00347e60;
        func_00239700(e + 0x18);
        e += 0x198;
    } while (--i != -1);
}
}
