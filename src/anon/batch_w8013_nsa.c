#include "../common/types.h"

/* 002eee68: the two by-value structs are spilled to the stack (sd a1 / sw a2). */
typedef struct W8013X { u32 a; u16 b; } W8013X;
typedef struct W8013Y { u16 a; u8 b; } W8013Y;
void func_0011cdf0(s32, void*, void*, void*, s32);
void func_002f25a0(s32, s32);

void func_002eee68(u8* p, W8013X x, W8013Y y) {
    func_0011cdf0(*(s32*)(p + 0x44), p + 0x50, p + 0x150, p + 0x190, 0);
    func_002f25a0(0, 0);
}
