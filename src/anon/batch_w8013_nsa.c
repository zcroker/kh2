#include "../common/types.h"

/* 002eee68: the two by-value structs are spilled to the stack (sd a1 / sw a2). */
typedef struct W8013X { u32 a; u16 b; } W8013X;
typedef struct W8013Y { u16 a; u8 b; } W8013Y;
void func_0011cdf0(s32, void*, void*, void*, s32);
void sceGsSyncPath(s32, s32);

// 002eee68: moved to src/anon/unit_002ee8a8.cpp
