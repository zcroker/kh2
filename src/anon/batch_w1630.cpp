#include "../common/types.h"
extern "C" {
struct W1630Seq { u8 pad[344]; };
struct W1630Sprite {
    u8 pad0[24];
    W1630Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1630Menu2 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W1630Sprite root;       // 48
    u8 pad2[40];
    W1630Sprite title;      // 496
    W1630Sprite base;       // 904
    W1630Sprite items[6];   // 1312
    W1630Sprite extra;      // 3760
    W1630Sprite extra2;     // 4168
    u8 pad3[1632];
    W1630Seq seq;           // 6208
    s32 f6552;
    u32 f6556;
};
s32 func_00151590(W1630Menu2*);
void func_001514e8(W1630Menu2*);
u32 func_00139d78(void*);
void dk__SpriteImage__create(W1630Sprite*, u32, u32, u32);
s32 func_0013a9d0(void);
void YI__IMAGE__ClutGray(void*, f32);
void func_002367c8(void*);
s32 func_00139538(W1630Sprite*);
void func_00139520(W1630Sprite*);
void dk__Sprite__create(W1630Sprite*, u32, u32, void*, u32, u32);
void YI__SEQUENCE__Init(W1630Seq*, u32, void*);
void func_00239c38(W1630Seq*, s32);
void func_0023acd8(W1630Seq*);
s32 func_0023a950(W1630Seq*);
s32 func_0023aa78(W1630Seq*);
void func_0014fc40(W1630Menu2*, u32, s32, u32, u32, s32);
void dk__TIMER__init(W1630Menu2*);

void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4) asm("_Z16wtarget_00150e00jjjj");
// (Re)builds the menu panel: root sprite, title sequence, base/item sprites, then the shared init.
void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4);  // 0x00150e00: definition moved into src/anon/unit_0014ecb8.cpp
}
