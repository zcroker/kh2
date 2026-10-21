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
void func_0014fcd8(W1898Menu2*);
u32 func_00139d78(void*);
void func_001515b0(W1898Menu2*);
void func_00138c40(W1898Sprite*, s32, s32);
s32 func_0014ca38(void);
void func_0014ca80(s32, s32*, s32*, s32*, s32*);
s32 func_00151100(W1898Menu2*, s32);
void func_00150260(void*, s32, s32, s32*);
void func_00138c10(W1898Sprite*, s32);
s32 func_0014c9a0(void);
void func_001386e0(W1898Sprite*, u32, u32, void*, u32, u32);
void func_002ba2e8(s32, s32);
extern u8 D_0034a580[];

void func_00151138(W1898Menu2* self) {
    s32 buf[2];
    s32 a, b, c, d;
    s32 v;
    u32 s3;
    void* s4;
    func_0014fcd8(self);
    if (self->f6568 == 1) {
        if (!func_00139d78(&self->title)) {
            func_001515b0(self);
        }
        return;
    }
    func_00138c40(&self->title, self->x, self->y);
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    if (self->time == -1) {
        v = func_0014ca38();
    } else {
        v = self->time;
    }
    func_0014ca80(v, &a, &b, &c, &d);
    if (a != 0) {
        return;
    }
    if (self->shown != v) {
        if (func_00151100(self, v)) {
            v += 60;
            func_0014ca80(v, &a, &b, &c, &d);
        }
        func_00150260(D_0034a580, b, 2, buf);
        func_00138c10(&self->items[0], buf[1]);
        func_00138c10(&self->items[1], buf[0]);
        func_00150260(D_0034a580, c, 2, buf);
        func_00138c10(&self->items[2], buf[1]);
        func_00138c10(&self->items[3], buf[0]);
        func_00150260(D_0034a580, d, 2, buf);
        func_00138c10(&self->items[4], buf[1]);
        func_00138c10(&self->items[5], buf[0]);
        func_00138c10(&self->extra, 23);
        func_00138c10(&self->extra2, 24);
        if (func_00151100(self, v)) {
            v -= 60;
            func_0014ca80(v, &a, &b, &c, &d);
        }
    }
    if (self->time == -1 && func_0014c9a0() && a == 0 && b == 0) {
        s3 = self->f6556;
        s4 = (u8*)&self->root + 32;
        if (c == 2 && !func_00139d78(&self->icons[0]) && (self->flags & 1) == 0) {
            func_001386e0(&self->icons[0], 3600, s3, s4, 31, 7);
            self->flags |= 1;
            func_002ba2e8(43, 0);
        } else if (c == 1 && !func_00139d78(&self->icons[1]) && !(self->flags & 2)) {
            func_001386e0(&self->icons[1], 3600, s3, s4, 30, 7);
            self->flags |= 2;
            func_002ba2e8(43, 0);
        } else if (c == 0 && !func_00139d78(&self->icons[2]) && !(self->flags & 4)) {
            func_001386e0(&self->icons[2], 3600, s3, s4, 29, 7);
            self->flags |= 4;
            func_002ba2e8(43, 0);
        } else if (v == 0 && !func_00139d78(&self->icons[3]) && !(self->flags & 8)) {
            func_001386e0(&self->icons[3], 3600, s3, s4, 28, 7);
            self->flags |= 8;
        }
    }
    self->shown = v;
}
}
