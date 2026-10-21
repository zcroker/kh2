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

void func_00138988(W1622Sprite* s) {
    if (s->flags & 0x800) {
        if (s->parent && !W1622_isActive(s->parent)) return;
        if (s->parentSeq && !W1622_getDrawMode(s->parentSeq)) return;
    }
    s32 x, y;
    if (s->parent) {
        W1622_getXYAddOff(s->parent, &x, &y);
        s->setPos(s->parent->posX + x, s->parent->posY + y);
    } else if (s->parentSeq) {
        W1622_getActiveXY(s->parentSeq, &x, &y);
        s->setPos(x + s->parentSeq->x, y + s->parentSeq->y);
    }
    if ((s->parent || s->parentSeq) && (s->flags & 0x200)) {
        u32 c;
        if (s->parent) c = W1622_getActiveRGBA(&s->parent->seq);
        else c = W1622_getActiveRGBA(s->parentSeq);
        W1622Seq* q = &s->seq;
        f32 r = q->r;
        f32 g = q->g;
        f32 b = q->b;
        f32 a = (f32)(c >> 24) * 0.0078125f;
        if (!(s->flags & 0x400)) {
            r = (f32)(c & 0xff) * 0.0078125f;
            g = (f32)((c & 0xff00) >> 8) * 0.0078125f;
            b = (f32)((c & 0xff0000) >> 16) * 0.0078125f;
        }
        W1622_setRGBA(q, r, g, b, a);
    }
    if (!(s->flags & 0x1000)) {
        W1622Seq* q = &s->seq;
        q->setPos(s->posX + s->offX, s->posY + s->offY);
        func_0023ade0(q);
    }
    if (s->clear) func_00236d60();
}
}
