#include "../common/types.h"

// 0021efc0: sprite animation frame table (header with frame count, then 8-byte frames).
struct W2368AnimFrame { u16 a; s16 dur; s8 flags; u8 pad[3]; };
struct W2368AnimHdr { u8 pad[6]; s16 count; u8 pad8[8]; W2368AnimFrame frm[1]; };
struct W2368AnimState { s16 time; u8 frame; };
struct W2368AnimObj { W2368AnimHdr** hdr; W2368AnimState* st; };

// 001a38b8
struct W2368Ent { u16 v; u16 pad; s32 f4; };
struct W2368Info { u8 pad[4]; s16 kind; };
struct W2368Arg { u8 pad[0x10]; u16 id; };

extern "C" {
extern u8 D_0032e020;
W2368Ent* func_00189200(void*, s32);
W2368Info* func_001b8e88(u16);
u16 func_001a3958(s32);

// Advances the animation clock by 0x200; on reaching the frame's duration steps to the next
// frame, and at the end of the table either rewinds (flag 0x80) or holds the last frame.
void func_0021efc0(W2368AnimObj* o) {
    W2368AnimState* st = o->st;
    W2368AnimFrame* f = &(*o->hdr)->frm[st->frame];
    st->time += 0x200;
    if (st->time >= f->dur) {
        st->time -= f->dur;
        st->frame++;
        if (st->frame >= (*o->hdr)->count) {
            if (f->flags & 0x80) {
                st->frame = 0;
                st->time = 0;
            } else {
                st->frame--;
                st->time = 0;
            }
        }
    }
}

// Clears entry 6's field, then for item kinds 1, 4 and 5 makes sure that kind's entry has a value.
void func_001a38b8(W2368Arg* a) {
    W2368Ent* e = func_00189200(&D_0032e020, 6);
    e->f4 = 0;
    s16 k = func_001b8e88(a->id)->kind;
    switch (k) {
    case 1: case 4: case 5:
        e = func_00189200(&D_0032e020, k);
        if (e->v == 0) e->v = func_001a3958(2);
        break;
    }
}
}
