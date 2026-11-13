// sa::MUSICAL_COMBO: the combo counter of the musical (Atlantica) minigame (vtable 0x35e1b8).
// Linked unit 0x229840-0x229e58.
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

typedef u8* (*AllocFn)(u8*, u32, u32);
extern u8 D_00340000[];
void func_00322418(void*);
void func_001390f0(void*);
void dk_Obj2D_leave(void*) asm("_ZN2dk5Obj2D5leaveEv");
void dk_Obj2D_show(void*) asm("_ZN2dk5Obj2D4showEv");

void func_002298a8(W1635Combo* c, s32 mode);

namespace sa { struct MUSICAL_COMBO { static void* start(int); void showFace(); void hideFace(); }; }

void* sa::MUSICAL_COMBO::start(int mode) {
    u8* h = *(u8**)(*(u8**)(D_00340000 + 32640) + 20);
    u8* o = (**(AllocFn**)h)(h, 2992, 0);
    func_00322418(o);
    func_002298a8((W1635Combo*)o, mode);
    return o;
}

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

s32 func_0022a3d0(s32 n, f32 x, s32* a, s32* b, s32* c, s32* d, s32* e, s32* f, s32* g, s32* h, f32* out);
void W2023_hide(void*) asm("_ZN2dk5Obj2D9localHideEv");
void W2023_show(void*) asm("_ZN2dk5Obj2D9localShowEv");
void W2023_call4(void*) asm("_Z16u_call4_00139d78jjjj");
void W2023_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
void W2023_setXY(void*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void W2023_setZ(void*, u32) asm("_ZN2dk13RectParamBase4setZEj");
void W2023_setWH(void*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
struct W2023Ent {
    u8 obj[32];     // dk::Obj2D (0)
    u8 ft4[288];    // dk::Ft4Base (32)
    u8 r1[256];     // dk::RectParamBase (320)
    u8 r2[272];     // dk::RectParamBase (576)
    void setZ(u32 z)
    {
        W2023_call4(obj);
        W2023_setZ(r1, z);
        W2023_setZ(r2, z);
    }
    void setRot(f32 a)
    {
        W2023_call4(obj);
        W2023_setRot(ft4, a);
    }
    static void rect(void* o, void* r, s32 x, s32 y, s32 w, s32 h)
    {
        W2023_call4(o);
        W2023_setXY(r, x, y);
        W2023_setWH(r, w, h);
    }
};
struct W2023Self {
    u8 pad[864];
    W2023Ent e[2];
    u8 pad2[2968 - 864 - 2 * 848];
    s32 b98;
};

void func_00229b28(W2023Self* s, s32 i, u32 z1, u32 z2, f32 x)
{
    s32 h;
    f32 rot;
    s32 a, b, c, d, e, f, g;
    W2023_hide(s->e[i].obj);
    switch (func_0022a3d0(s->b98, x, &a, &b, &c, &d, &e, &f, &g, &h, &rot)) {
    case 0:
        break;
    case 1:
        s->e[i].setZ(z1);
        break;
    case 2:
        s->e[i].setZ(z1);
        break;
    case 3:
        s->e[i].setZ(z1);
        break;
    case 4:
        s->e[i].setZ(z2);
        break;
    }
    W2023Ent* p = &s->e[i];
    p->setRot(rot);
    W2023Ent::rect(p->obj, p->r1, a, b, c, d);
    W2023Ent::rect(p->obj, p->r2, e, f, g, h);
    W2023_show(p->obj);
}

void func_00229d40(u8* a0) {
    func_00229b28((W2023Self*)a0, 1, 200, 0, (f32)*(s32*)(a0 + 2972));
}

void func_00229d68(void* p) {
    func_00229d40((u8*)p);
    func_001390f0(p);
}

static inline void call20(u8* a0) {
    (*(void (**)(u8*))(*(u8**)a0 + 20))(a0);
}

void func_00229d90(u8* a0) {
    u8* s = a0;
    call20(a0);
    call20(a0 + 440);
    s32 i = 1;
    do {
        call20(s + 864);
        i--;
        s += 848;
    } while (i >= 0);
    dk_Obj2D_leave(a0 + 2560);
}

void func_00229e08(u8* a0, s32 v) { *(s32*)(a0 + 2968) = v; }

void func_00229e10(u8* a0, s32 v) {
    s32 d = *(s32*)(a0 + 2968) - v;
    if (d < 0) d = 0;
    *(s32*)(a0 + 2972) = d;
}

}  // extern "C"

void sa::MUSICAL_COMBO::showFace() { dk_Obj2D_show((u8*)this + 2560); }
void dk_Obj2D_hide2(void*) asm("_ZN2dk5Obj2D4hideEv");
void sa::MUSICAL_COMBO::hideFace() { dk_Obj2D_hide2((u8*)this + 2560); }
