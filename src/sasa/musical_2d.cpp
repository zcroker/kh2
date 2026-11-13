// sa::MUSICAL_2D: the 2D layout of the musical (Atlantica) minigame. Linked unit 0x22b7f0-0x22ba08.
#include "musical_2d.hpp"

struct BD_VALUE;

extern "C" {
void func_002fee78(char*, const char*, ...);  // sprintf
void func_002ff3fc(char*);
}

u32 func_001050d8(u32) asm("_ZN4AREA5AllocEj");
void func_0023f800(u8*) asm("_ZN2Tz7LayFileC1Ev");
u32 func_0023fa70(u8*, char*, s32) asm("_ZN2Tz7LayFile11readRequestEPKci");
void func_0023c008(u8*);
void func_002369a0(u8*);
void func_0023fa90(u8*, char*);
u32 func_0023f908(u8*, u32);
u32 func_0023f948(u8*, u32);
u32 func_001050c8(void);
void func_00236a58(u8*, u32, u32);
u32 func_0023c100(u8*, u32, u8*, u32) asm("func_0023c100");
void func_001397d8(s32);
u32 func_0023fad0(u8*);
void func_002369f0(u8*);
void func_0023c098(u8*);
void func_0023f848(u8*);
void func_00105110(u8*);
u32 func_00236cc0(u8*, u32);
u32 func_0023c4b8(u8*, u32);

static char D_01dad938[40] asm("D_01dad938");

extern u32 D_0033caf4;
u8* D_0035e2e8;

char* func_0022b7f0(void) {
    func_002fee78(D_01dad938, "file/%s/mg_lm_mu.2ld", D_0033caf4);
    func_002ff3fc(D_01dad938);
    return D_01dad938;
}

u32 func_0022b838() {
    u8* p = (u8*)func_001050d8(144);
    func_0023f800(p);
    func_0023c008(p + 28);
    func_002369a0(p + 120);
    D_0035e2e8 = p;
    return func_0023fa70(D_0035e2e8, func_0022b7f0(), -200);
}

void func_0022b898(void) {
    func_0023fa90(D_0035e2e8, func_0022b7f0());
    u32 a = func_0023f908(D_0035e2e8, 0);
    u32 b = func_0023f948(D_0035e2e8, 0);
    u32 c = func_001050c8();
    func_00236a58(D_0035e2e8 + 120, a, c);
    func_0023c100(D_0035e2e8 + 28, b, D_0035e2e8 + 120, c);
}

void func_0022b930(BD_VALUE* bd) { func_001397d8(11); }

u32 func_0022b948(void) { return func_0023fad0(D_0035e2e8); }

void func_0022b968(void) {
    u8* p = D_0035e2e8;
    if (p != 0) {
        func_002369f0(p + 120);
        func_0023c098(p + 28);
        func_0023f848(p);
        void (*f)(u8*) = func_00105110;
        f(p);
    }
}

u32 func_0022b9b8(void) { return func_00236cc0(D_0035e2e8 + 120, 0); }

u32 func_0022b9e0(void) { return func_0023c4b8(D_0035e2e8 + 28, 0); }
