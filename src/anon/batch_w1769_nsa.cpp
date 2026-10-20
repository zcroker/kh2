#include "../common/types.h"
extern "C" {
void* func_001050d8(u32);
void func_001ad0f8(void*, s32, s32);
void func_001ac7c8(void*, void*);

void func_001ad520(u8* p, s32 a1, s32 a2, s32 a3) {
    u8* o = (u8*)func_001050d8(0xB6C);
    func_001ad0f8(o, a3, 0);
    func_001ac7c8(func_001050d8(0x1C), o);
    *(u8**)(p + 0x4A8) = o;
    *(s32*)(o + 4) = a1;
    *(s32*)(o + 8) = a2;
}
}
