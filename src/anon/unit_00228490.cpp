// A musical (Atlantica) minigame object with vtable 0x35df98. Linked unit 0x228490-0x228618.
#include "../common/types.h"

typedef u8* (*AllocFn)(u8*, u32, u32);

extern "C" {
u32 func_0022b9e0(void);  // sa::MUSICAL_2D::getSqd
u32 func_0022b720(void);  // sa::MUSICAL_TARGET::getImage
void func_001386e0(u8*, s32, u32, u32, u32, s32);
void func_00239700(u8*);
void func_0031a838(u8*);
void func_002251c8(s32);
}

extern u8 D_00340000[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8 D_0035df98[];

void func_00228490(u8* p, u32 a) {
    u32 sqd = func_0022b9e0();
    func_001386e0(p, 3000, sqd, func_0022b720(), a, 11);
}

void func_002284e8(u8* p) {
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 16))(p);
    }
}

void func_00228518(void) {
    u8* h = *(u8**)(*(u8**)(D_00340000 + 32640) + 20);
    u8* o = (**(AllocFn**)h)(h, 408, 0);
    *(u32*)(o + 12) = 0;
    *(u8**)o = D_00347e60;
    func_00239700(o + 24);
    *(u8**)o = D_0035df98;
    func_00228490(o, 143);
    func_002251c8(12020);
}

void func_00228590(void) {
    u8* h = *(u8**)(*(u8**)(D_00340000 + 32640) + 20);
    u8* o = (**(AllocFn**)h)(h, 408, 0);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_00347e60;
    func_00239700(o + 24);
    *(u8**)o = D_0035df98;
    func_00228490(o, 144);
    func_002251c8(12021);
}
