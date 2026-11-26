#include "../common/types.h"
extern "C" {
struct W1898Seq { u8 pad[344]; };
struct W1898Sprite {
    u8 pad0[24];
    W1898Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1898Menu2 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W1898Sprite root;       // 48
    u8 pad2[40];
    W1898Sprite title;      // 496
    W1898Sprite base;       // 904
    W1898Sprite items[6];   // 1312
    W1898Sprite extra;      // 3760
    W1898Sprite extra2;     // 4168
    W1898Sprite icons[4];   // 4576
    W1898Seq seq;           // 6208
    u32 flags;              // 6552
    u32 f6556;
    s32 time;               // 6560
    s32 shown;              // 6564
    s32 f6568;
};
void dk__INFO_BASE__update(W1898Menu2*);
u32 func_00139d78(void*);
void func_001515b0(W1898Menu2*);
void func_00138c40(W1898Sprite*, s32, s32);
s32 func_0014ca38(void);
void dk__Clock__vCountToHMSMS(s32, s32*, s32*, s32*, s32*);
s32 func_00151100(W1898Menu2*, s32);
void func_00150260(void*, s32, s32, s32*);
void func_00138c10(W1898Sprite*, s32);
s32 func_0014c9a0(void);
void dk__Sprite__create(W1898Sprite*, u32, u32, void*, u32, u32);
void func_002ba2e8(s32, s32);
extern u8 D_0034a580[];

void dk__TIMER__update(W1898Menu2* self);  // 0x00151138: definition moved into src/anon/unit_0014ecb8.cpp
}
