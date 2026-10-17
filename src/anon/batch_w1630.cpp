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
void func_00138650(W1630Sprite*, u32, u32, u32);
s32 func_0013a9d0(void);
void func_002368e8(void*, f32);
void func_002367c8(void*);
s32 func_00139538(W1630Sprite*);
void func_00139520(W1630Sprite*);
void func_001386e0(W1630Sprite*, u32, u32, void*, u32, u32);
void func_00239988(W1630Seq*, u32, void*);
void func_00239c38(W1630Seq*, s32);
void func_0023acd8(W1630Seq*);
s32 func_0023a950(W1630Seq*);
s32 func_0023aa78(W1630Seq*);
void func_0014fc40(W1630Menu2*, u32, s32, u32, u32, s32);
void func_00150be8(W1630Menu2*);

void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4) asm("_Z16wtarget_00150e00jjjj");
// (Re)builds the menu panel: root sprite, title sequence, base/item sprites, then the shared init.
void wtarget_00150e00(W1630Menu2* self, u32 a1, u32 a2, s32 mode, u32 a4) {
    void* s5;
    s32 num;
    s32 i;
    W1630Sprite* p;
    s32 cr;
    if (func_00151590(self)) {
        func_001514e8(self);
        return;
    }
    if (!func_00139d78(&self->root)) {
        func_00138650(&self->root, 3600, a1, 9);
        if (func_0013a9d0()) {
            func_002368e8((u8*)&self->root + 32, 0.8f);
            func_002367c8((u8*)&self->root + 32);
        }
    } else if (func_00139538(&self->root)) {
        func_00139520(&self->root);
    }
    s5 = (u8*)&self->root + 32;
    self->f6552 = 0;
    self->f6556 = a2;
    num = 0;
    switch (mode) {
    case 0: num = 26; break;
    case 2: num = 25; break;
    case 1: num = 27; break;
    }
    func_00239988(&self->seq, a2, s5);
    func_00239c38(&self->seq, num);
    func_0023acd8(&self->seq);
    self->x = func_0023a950(&self->seq);
    func_001386e0(&self->title, 3600, a2, s5, 3, 9);
    if (!func_00139d78(&self->base)) {
        func_001386e0(&self->base, 3600, a2, s5, 9, 9);
    }
    for (i = 0; i < 6; i++) {
        if (!func_00139d78(&self->items[i])) {
            func_001386e0(&self->items[i], 3600, a2, s5, 12, 9);
        }
    }
    if (!func_00139d78(&self->extra)) {
        func_001386e0(&self->extra, 3600, a2, s5, 23, 9);
    }
    if (!func_00139d78(&self->extra2)) {
        func_001386e0(&self->extra2, 3600, a2, s5, 24, 9);
    }
    cr = func_0023aa78(&self->title.seq);
    if (!func_00139d78(self)) {
        func_0014fc40(self, a4, cr, 3600, 9, mode);
    }
    func_00150be8(self);
}
}
