#include "../common/types.h"

// Game file 0x2f17e0-0x2f1a68: the "70landing.bar" archive (loaded by name, entries looked up by
// kind) and small helpers that start, check and stop ryj effects held in a handle slot.

extern "C" {
u32 func_00170518(const char*, u32, u32);
u32 func_001708f8(const char*, s32);
u8* func_00168b38(u32, u32, u32);
void func_00170950(u32);
u32 func_0016ac38(u32, u32, u32, u32, u32);
void func_001dc920(u32);
void func_001dc840(u32);
void func_001dc978(u32);
void func_001dc818(u32);
}
u32 ryj_EFFECT_is_alive(u32) asm("_ZN3ryj6EFFECT8is_aliveEv");

const char* D_00363c20 = "70landing.bar";
u32 D_00363c24;
static u32 D_01e2c0d0;

extern "C" {

u32 func_002f17e0(void) {
    return func_00170518(D_00363c20, 950, 0);
}

void func_002f1808(void) {
    u32 v = func_001708f8(D_00363c20, -1);
    D_01e2c0d0 = v;
    D_00363c24 = *(u32*)(func_00168b38(v, 2, 0) + 8);
}

void func_002f1850(void) {
    if (D_01e2c0d0) {
        func_00170950(D_01e2c0d0);
        D_01e2c0d0 = 0;
    }
}

u32 func_002f1888(void) {
    return D_00363c24;
}

u32 func_002f1898(void) {
    return *(u32*)(func_00168b38(D_01e2c0d0, 25, 0) + 8);
}

u32 func_002f18c8(u8* a0) {
    u8* e = func_00168b38(D_01e2c0d0, 24, a0[3]);
    u32 r = 0;
    if (e) r = *(u32*)(e + 8);
    return r;
}

void func_002f1900(u32* slot, u32 a1, u32 a2) {
    if (*slot == 0) *slot = func_0016ac38(a2, a1, 1, 0, 0);
}

void func_002f1990(u32* slot);

void func_002f1940(u32* slot) {
    if (*slot && !ryj_EFFECT_is_alive(*slot)) func_002f1990(slot);
}

void func_002f1990(u32* slot) {
    if (*slot) {
        func_001dc920(*slot);
        *slot = 0;
    }
}

void func_002f19c8(u32* slot) {
    if (*slot) {
        func_001dc840(*slot);
        *slot = 0;
    }
}

void func_002f1a00(u32* slot) {
    if (*slot) {
        func_001dc978(*slot);
        *slot = 0;
    }
}

void func_002f1a38(u32* slot) {
    if (*slot) func_001dc818(*slot);
}

}
