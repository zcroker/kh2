#include "../common/types.h"

struct W1622Seq {
    u8 pad0[280];
    f32 r, g, b;
    u8 pad124[36];
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
    void setPos(s32 x, s32 y) { posX = x; posY = y; }
};

s32 W1622_isActive(W1622Sprite*) asm("_Z16u_call4_00139d78jjjj");
s32 W1622_getDrawMode(W1622Seq*) asm("_ZN2YI8SEQUENCE11GetDrawModeEv");
void W1622_getXYAddOff(W1622Sprite*, s32*, s32*) asm("_ZN2dk6Sprite23getSeqActiveXYAddOffsetERiS1_");
void W1622_getActiveXY(W1622Seq*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
u32 W1622_getActiveRGBA(W1622Seq*) asm("_ZN2YI8SEQUENCE13GetActiveRGBAEv");
void W1622_setRGBA(W1622Seq*, f32, f32, f32, f32) asm("_Z16wtarget_00239fd0jjjj");

extern "C" {
void func_0023ade0(W1622Seq*);
void func_00236d60(void);

void func_00138988(W1622Sprite* s);  // 0x00138988: definition moved into src/anon/unit_00138480.cpp
}
