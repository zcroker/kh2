// sa::MUSICAL_TARGET: the target sprite object of the musical (Atlantica) minigame.
// Linked unit 0x22b558-0x22b7f0.
#include "musical_target.hpp"

extern "C" {
u32 func_0022b9e0(void);  // sa::MUSICAL_2D::getSqd (musical_2d.cpp)
u32 func_0022b9b8(void);  // sa::MUSICAL_2D::getImd (musical_2d.cpp)
}

void func_001386e0(u8*, u32, u32, u32, u32, u32) asm("func_001386e0");
void func_001390f0(void) asm("func_001390f0");
void func_00138840(u8*) asm("func_00138840");
u32 func_00139d78(u8*, u32) asm("func_00139d78");
void func_00138c10(u8*, u32) asm("func_00138c10");
void func_00239700(u8*) asm("func_00239700");
void func_002361a0(u8*) asm("func_002361a0");
u32 func_00138650(u8*, u32, u32, u32) asm("func_00138650");

typedef u8* (*AllocFn)(u8*, u32, u32);
extern u8 D_00340000[] asm("D_00340000");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e80[] asm("D_00347e80");
extern u8 D_0035e2a8[] asm("D_0035e2a8");

u8* D_0035e298 asm("D_0035e298");

void func_0022b558(u8* p, u32 a, u32 b) {
    func_001386e0(p, 2500, func_0022b9e0(), b, a, 11);
    *(f32*)(p + 384) = 1.0f;
}

void func_0022b5c0(u8* p) {
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 16))(p);
    }
}

void func_0022b5f0(u8* p) {
    if (p[436] == 0) {
        func_001390f0();
        p[436] = 1;
        return;
    }
    func_00138840(p);
}

void func_0022b638(u8* p, u32 a) {
    if (func_00139d78(p, a) != 0) {
        func_00138c10(p, a);
    }
}

u8* func_0022b688(u32 a) {
    u8* h = *(u8**)(*(u8**)(D_00340000 + 32640) + 20);
    u8* o = (**(AllocFn**)h)(h, 448, 0);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_00347e60;
    func_00239700(o + 24);
    *(u32*)(o + 432) = 0;
    o[436] = 0;
    *(u8**)o = D_0035e2a8;
    func_0022b558(o, a, (u32)(D_0035e298 + 32));
    return o;
}

namespace sa {

void* MUSICAL_TARGET::getImage() { return D_0035e298 + 32; }

u32 MUSICAL_TARGET::init() {
    u8* h = *(u8**)(*(u8**)(D_00340000 + 32640) + 20);
    u8* o = (**(AllocFn**)h)(h, 448, 0);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_00347e80;
    func_002361a0(o + 32);
    D_0035e298 = o;
    u32 imd = func_0022b9b8();
    return func_00138650(D_0035e298, 2000, imd, 11);
}

void MUSICAL_TARGET::free() {
    u8* p = D_0035e298;
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 16))(p);
        D_0035e298 = 0;
    }
}

}  // namespace sa
