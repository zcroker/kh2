#include "../common/types.h"

/* 001cbe30 */
u8* func_001cbc50(s32, void*, s32, s32);
u32 func_001cb6e0(u32, u32, u32, u32);
u32 func_001cb700(u32, u32, u32, u32);
extern s32 D_00351fe4;
extern u8 D_0036e180[];
typedef struct W2433_O { u8 pad[0x10]; void* fn; u8 pad2[0x28 - 0x14]; u32 fl; } W2433_O;

W2433_O* func_001cbe30(s32 a0, s32 a1, s32 a2);  // 0x001cbe30: definition moved into src/anon/unit_001ca8e0.cpp

/* 00152b50: three sub-inits; volatile fields keep the store order, the c rmw goes through a cast */
s32 func_001391c8(void*, s32, s32);
typedef struct W2433_S { u32 a; volatile u32 b; volatile u32 c; volatile u32 d; volatile u32 e; } W2433_S;
typedef struct W2433_B {
    u8 pad[24]; W2433_S s1; u8 pad2[9644 - 24 - 20]; W2433_S s2; u8 pad3[12064 - 9644 - 20]; W2433_S s3;
} W2433_B;

void func_00152b50(W2433_B* p);  // 0x00152b50: definition moved into src/anon/unit_0014ecb8.cpp
