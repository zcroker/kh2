#include "../common/types.h"
extern "C" {

void func_00177dc8(void*, s32, s32);
s32 func_00181978();
s32 func_00192048(s32);
void func_001a1c90(void*, s32, s32);
u8* func_001c1130(s32);
void func_001c11a8(s32);
s32 func_001d6d88();
extern u32 D_0034f240;
extern void* D_00352400;
extern u8 D_00352410[];
void func_001d0980(u8* p, s32 a1, s32 a2) {
    func_00177dc8(p, a1, a2);
    *(void**)(p + 0) = D_00352410;
    *(s32*)(p + 0xB68) = 0;
    *(s32*)(p + 0xB6C) = 0;
    *(s32*)(p + 0xB70) = 0;
    *(u32*)(p + 0x588) |= 0x01000000;
    D_00352400 = p;
    if (func_00181978() != 0) {
        if (D_0034f240 & 0x40000) {
            (*(u8**)(p + 0x48C))[0x1AF] = 4;
        } else if (*(s32*)(p + 0xB50) == 0xC) {
            func_001a1c90(*(void**)(p + 0x48C), 2, -1);
        } else if (func_001d6d88() != 0) {
            (*(u8**)(p + 0x48C))[0x1AF] = 3;
        } else {
            (*(u8**)(p + 0x48C))[0x1AF] = 1;
        }
    }
    if (a2 == 6) {
        u8* q = func_001c1130(0x1D);
        *(s32*)(q + 0x18) = func_00192048(0xC44F);
        return;
    }
    func_001c11a8(0x1D);
}
}
