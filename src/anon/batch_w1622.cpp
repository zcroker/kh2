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
void W1622_print(W1622Printer*, s32, s32, u32) asm("_Z16wtarget_001a9ae8jjjj");

extern "C" {
void func_001a98e8(W1622Printer*, s32, const void*, s32, s32);
void func_001aa6d0(W1622Printer*, s32);

u32 func_00138de0(W1622Sprite* s) {
    if ((s->parent && !W1622_isActive(s->parent)) || (s->parentSeq && !W1622_getPlayMode(s->parentSeq))) return 0;
    s32 x = 0, y = 0;
    W1622_getXYAddOff(s, &x, &y);
    if (s->flags & 0x10) {
        x += W1622_getParamX(&s->seq);
        y += W1622_getParamY(&s->seq);
    }
    u32 color = s->color;
    if (s->flags & 4) {
        u32 c = W1622_getActiveRGBA(&s->seq);
        if (s->flags & 8) {
            c &= 0xff000000;
            color &= 0x00ffffff;
            color |= c;
        }
        else color = c;
        W1622Seq* q = &s->seq;
        f32 fr = q->r, fg = q->g, fb = q->b, fa = q->a;
        s32 a = (s32)((f32)(color >> 24) * fa);
        if (a >= 255) a = 255;
        s32 r = (s32)((f32)(color & 0xff) * fr);
        if (r >= 255) r = 255;
        s32 g = (s32)((f32)((color & 0xff00) >> 8) * fg);
        if (g >= 255) g = 255;
        s32 b = (s32)((f32)((color & 0xff0000) >> 16) * fb);
        if (b >= 255) b = 255;
        color = (a << 24) | (b << 16) | (g << 8) | r;
    }
    if (s->msg == 0) return color;
    {
        s32 px = x + s->posX + s->msgX;
        s32 py = y + s->posY + s->msgY;
        W1622Printer pr;
        func_001a98e8(&pr, s->msgA, s->msg, s->msgSize, s->msgB);
        func_001aa6d0(&pr, W1622_getParamCr(&s->seq));
        W1622_print(&pr, px, py, color);
    }
    return color;
}
}
