#include "../common/types.h"

struct W1639Sprite {
    u8 pad0[0x188];
    s32 on188;
    s32 on18c;
    s32 on190;
};

struct W1639Cmd {
    u8 pad0[0xcc];
    s32 cursor[4];     // 0xcc
    s32 count[4];      // 0xdc
};

struct W1639Entry {
    u8 pad0[2];
    u16 id;            // +2
    u8 pad4;
    u8 kind;           // +5
    u8 pad6[6];
};

struct W1639Menu {
    s32 type;          // 0x00
    u8 pad4[4];
    s32 count;         // 0x08
    W1639Entry ent[8]; // 0x0c
    s32 sel;           // 0x6c
};

extern "C" {
extern s32 D_00348060[];
u8* func_0013bb58(W1639Cmd*, W1639Menu*, s32, s32, u8, s32, s32);
u8* func_001b8e88(u16);
void func_0013c080(W1639Cmd*, W1639Entry*, s32, s32, u8*, s32, s32*, s32*);
s32 func_00192048(s32);
s32 func_0013b988(W1639Cmd*, W1639Menu*, s32, s32, s32, s32);
W1639Sprite* func_0013b5d0(f32, W1639Cmd*, s32, s32, void*, u8, s32, s32, s32, s32, s32);
void func_0013c190(W1639Cmd*, W1639Menu*, s32, s32, u8, s32, s32, s32, W1639Entry*);
s32 func_0013bc40(W1639Cmd*, s32);
void func_0013ce08(W1639Cmd*, s32);

// Draws one column of a menu: one sprite per entry, the selected entry is passed to func_0013c190.
void func_0013c3b8(W1639Cmd* self, W1639Menu* m, s32 slot, s32 col, u8 force)
{
    u8 flag;
    s32 v;
    s32 extra;
    s32 i = 0;
    u8* item;
    s32 selX;
    s32 selY;
    s32 type = m->type;
    s32 sx = slot * 16;
    v = 0;
    func_0013bb58(self, m, slot, col, force, sx, type);
    s32 y;
    selY = -64;
    asm("" : "+m"(m->count) : "g"(selY));
    selX = 0;
    y = 410 - m->count * 22;
    if (i < m->count) {
    u16* pid = &m->ent[0].id;
    asm("" : "+r"(pid));
    do {
        item = func_001b8e88(*pid);
        flag = 0;
        extra = -1;
        if (self->cursor[slot] == i) flag = 1;
        if (force == 1) flag = force;
        if (self->count[slot] != m->count) flag = 1;
        if (m->sel == i) {
            selY = y;
            selX = sx + 28;
        } else {
            if (i == m->count - 1) v = D_00348060[type * 12 + col + 9];
            else v = D_00348060[type * 12 + col + 6];
            register s32 k asm("$18");
            asm("" : "=r"(k) : "0"((s32)m->ent[i].kind), "m"(flag));
            W1639Entry* e = &m->ent[i];

            func_0013c080(self, e, slot, col, &flag, 2, &v, &extra);
            s32 r = func_00192048(*(s32*)(item + 8));
            s32 q = func_0013b988(self, m, k, i, 0, 0);
            W1639Sprite* p = func_0013b5d0(1.0f, self, slot, v, e, flag, sx + 28, y, r, q, 2);
            s32 c = -1;
            asm("" : "+r"(c) : "r"(p));
            if (extra != c) p->on188 = extra;
        }
        y += 22; pid += 6; i++;
    } while (i < m->count);
    }
    func_0013c190(self, m, slot, col, force, type, selX, selY, &m->ent[m->sel]);
    self->count[slot] = m->count;
    if (func_0013bc40(self, slot)) func_0013ce08(self, m->count);
}
}
