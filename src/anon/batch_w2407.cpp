#include "../common/types.h"
// zl90 w2407 2026-10-26: 00154558 matched (separate inner-loop counter j lets the range pass split root into s7).
extern "C" {
struct W1632Seq { u8 pad[344]; };
struct W1632Sprite {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1632Menu {
    u8 pad0[32];
    s32 x;                      // 32
    u8 pad1[12];
    W1632Sprite parts[6];       // 48
    W1632Sprite grid[16][2];    // 2496
};
void func_00154b18(W1632Menu*);
void func_0014fc40(W1632Menu*, u32, s32, u32, u32, s32);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
void func_001386e0(W1632Sprite*, u32, u32, u32, u32, u32);
void func_001396b0(W1632Sprite*);
void func_0031a260(W1632Sprite*, u32);
void func_00138c68(W1632Sprite*, s32, s32);
s32 func_0023aa98(W1632Seq*);
void func_001399c0(s32);

static inline void W1632_setParent(W1632Sprite* obj, W1632Sprite* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}
void func_00154558(W1632Menu* self) {
    u32 tex, img;
    s32 i, row, pos;
    func_00154b18(self);
    func_0014fc40(self, 18, 0, 7000, 6, 1);
    self->x = 0;
    tex = func_0013a7e8(1);
    img = func_0013d7e0();
    func_001386e0(&self->parts[0], 7000, tex, img, 38, 6);
    func_001386e0(&self->parts[1], 7000, tex, img, 42, 6);
    func_001386e0(&self->parts[2], 7000, tex, img, 39, 6);
    func_001386e0(&self->parts[3], 7000, tex, img, 40, 6);
    func_001386e0(&self->parts[4], 7000, tex, img, 41, 6);
    func_001386e0(&self->parts[5], 7000, tex, img, 43, 6);
    for (i = 0; i < 6; i++) {
        W1632_setParent(&self->parts[i], &self->parts[0]);
    }
    W1632_setParent(&self->parts[0], 0);
    pos = 0;
    for (row = 0; row < 16; row++) {
        for (s32 j = 0; j < 2; j++) {
            W1632Sprite* p = &self->grid[row][j];
            func_001386e0(p, 7000, tex, img, j == 0 ? 45 : 44, 6);
            W1632_setParent(p, &self->parts[0]);
            func_00138c68(p, pos, 0);
        }
        pos -= func_0023aa98(&self->grid[row][0].seq);
    }
    func_001399c0(6);
}
}
