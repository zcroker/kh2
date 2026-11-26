#include "../common/types.h"

// dk::SpriteMessage message drawing (00138de0). W1622Sprite mirrors dk::Sprite/SpriteMessage
// (+24 YI::SEQUENCE, +368 pos, +376 offset, +396 parent sprite, +400 parent sequence, +408 message).

struct W1622Seq {
    u8 pad0[280];
    f32 r, g, b, a;
    u8 pad128[32];
    s32 x, y;
    void setPos(s32 nx, s32 ny) { x = nx; y = ny; }
};
struct W1622Sprite {
    u32 vt;
    u8 pad4[8];
    u32 flags;
    u8 pad10[8];
    W1622Seq seq;
    u8 pad168[8];
    s32 posX, posY;
    s32 offX, offY;
    u8 pad180[12];
    W1622Sprite* parent;
    W1622Seq* parentSeq;
    u8 pad194;
    u8 clear;
    u8 pad196[2];
    const void* msg;
    s32 msgX, msgY;
    u32 color;
    s32 msgSize;
    s32 msgA;
    s32 msgB;
    void setPos(s32 x, s32 y) { posX = x; posY = y; }
};

s32 W1622_isActive(W1622Sprite*) asm("_Z16u_call4_00139d78jjjj");
s32 W1622_getPlayMode(W1622Seq*) asm("_ZN2YI8SEQUENCE11GetPlayModeEv");
void W1622_getXYAddOff(W1622Sprite*, s32*, s32*) asm("_ZN2dk6Sprite23getSeqActiveXYAddOffsetERiS1_");
s32 W1622_getParamX(W1622Seq*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 W1622_getParamY(W1622Seq*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
s32 W1622_getParamCr(W1622Seq*) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
u32 W1622_getActiveRGBA(W1622Seq*) asm("_ZN2YI8SEQUENCE13GetActiveRGBAEv");
struct W1622Printer { u8 b[96]; };
void W1622_print(W1622Printer*, s32, s32, u32) asm("_Z21YS__MESSAGEDRAW__drawjjjj");

extern "C" {
void YS__MESSAGEDRAW__MESSAGEDRAW(W1622Printer*, s32, const void*, s32, s32);
void YS__MESSAGEDRAW__set_line_space(W1622Printer*, s32);

u32 dk__SpriteMessage__drawMessage(W1622Sprite* s);  // 0x00138de0: definition moved into src/anon/unit_00138480.cpp
}
