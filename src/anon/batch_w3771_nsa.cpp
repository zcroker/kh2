#include "../common/types.h"

struct W1635Sel {            // dk::Obj2D-like selectable sprite
    u8 pad0[0x18c];
    void* parent;            // 0x18c
    s32 flag;                // 0x190
};

struct W1635ComboPart {      // 0x350 bytes
    u8 pad0[0x20];
    u8 rect0[0x120];         // 0x20
    u8 rect1[0x100];         // 0x140
    u8 rect2[0x100];         // 0x240
    void* owner;             // 0x340
    u8 pad344[0xc];
};

struct W1635Combo {
    W1635Sel face;           // 0x000
    u8 pad194[0x1b8 - 0x194];
    W1635Sel ring;           // 0x1b8
    u8 pad34c[0x360 - 0x34c];
    W1635ComboPart part[2];  // 0x360
    W1635Sel gauge;          // 0xa00
    u8 padb94[0xba0 - 0xb94];
    s32 mode;                // 0xba0
};

extern "C" {
void* W1635_getImage(void) asm("_ZN2sa14MUSICAL_TARGET8getImageEv");
void* W1635_getSqd(void) asm("_ZN2sa10MUSICAL_2D6getSqdEv");
void func_0022a0f8(W1635ComboPart*, s32, s32, s32);
void func_00158050(W1635Sel*, s32, void*, void*, s32, s32, s32);
void func_001386e0(W1635Sel*, s32, void*, void*, s32, s32);
void W1635_hide(W1635Sel*) asm("_ZN2dk5Obj2D4hideEv");
u8 W1635_call139d78(W1635ComboPart*) asm("_Z16u_call4_00139d78jjjj");
void W1635_setZ(void*, u32) asm("_ZN2dk13RectParamBase4setZEj");
void func_001396b0(W1635Sel*);
void func_0031a260(W1635Sel*, s32);

static inline void W1635_setParent(W1635Sel* p, void* parent) {
    p->parent = parent;
    func_001396b0(p);
    if (p->parent) {
        p->flag = 0;
        func_001396b0(p);
        if (p->flag) func_0031a260(p, 0);
    }
}

#define SETPARENT(P, PAR) do { (P)->parent = (PAR); func_001396b0(P); if ((P)->parent) { (P)->flag = 0; func_001396b0(P); if ((P)->flag) func_0031a260(P, 0); } } while (0)
// sa::MUSICAL_COMBO set-up: builds the two parts, ring, gauge and face sprites and parents them.
// ring is pinned to s0 (one register asm + empty tie): without it gcc rotates the saved registers.
void func_002298a8(W1635Combo* c, s32 mode) {
    s32 faceNo = 111;
    s32 ringNo = 96;
    s32 gaugeNo = 137;
    c->mode = mode;
    void* img = W1635_getImage();
    void* sqd = W1635_getSqd();
    if (mode == 1) {
        faceNo = 110;
        ringNo = 95;
        gaugeNo = 135;
    }
    W1635ComboPart* p0 = &c->part[0];
    func_0022a0f8(p0, 2500, 0, 11);
    W1635ComboPart* p1 = &c->part[1];
    register W1635Sel* ring asm("$16") = &c->ring;
    func_0022a0f8(p1, 2500, 1, 11);
    asm("" : "+r"(ring));
    func_00158050(ring, 2500, sqd, img, ringNo, 100, 11);
    W1635Sel* gauge = &c->gauge;
    func_001386e0(gauge, 2500, sqd, img, gaugeNo, 11);
    func_001386e0(&c->face, 2499, sqd, img, faceNo, 11);
    W1635_hide(gauge);
    W1635_call139d78(p0);
    W1635_setZ(c->part[0].rect0, 0);
    W1635_setZ(c->part[0].rect1, 0);
    W1635_setZ(c->part[0].rect2, 0);
    W1635_call139d78(p1);
    W1635_setZ(c->part[1].rect0, 200);
    W1635_setZ(c->part[1].rect1, 200);
    W1635_setZ(c->part[1].rect2, 200);
    SETPARENT(ring, c);
    for (s32 i = 0; i < 2; i++) {
        W1635ComboPart* p = &c->part[i];
        W1635_call139d78(p);
        p->owner = c;
    }
    W1635_setParent(gauge, c);
    W1635_setParent(&c->face, 0);
}
}
