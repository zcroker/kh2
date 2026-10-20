#include "../common/types.h"

extern "C" {
void func_0013d798(void);
void func_002f8b48(void);
void wtarget_00239bf8(u8*) asm("_Z16wtarget_00239bf8jjjj");
void func_00303698(u32, void*);
void func_00302b18(void);
void func_001cd690(void*, u32, u32);
extern u32 D_00352bd0;
extern u32 D_0034dbf8[];
extern u8* D_00350df8;
extern u32 D_00352b50;
extern u32 D_00352b54;
extern u8 D_004f4240;
extern u8 D_01c60d10;

void func_00198a90(void) { func_0013d798(); }

void func_001e2ac0(void) { *(s32*)(D_00352bd0 + 0xdc0) = 7; }

void func_002f8a88(void) { func_002f8b48(); }

void func_00113438(u8* p) { *(u32*)(p + 0xb7c) &= ~0x20000; }

void wtarget_0016d0d8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_0016d0d8jjjj");
void wtarget_0016d0d8(u32 a, u32 b, u32 c, u32 d) { D_0034dbf8[a] = b; }

u8 func_0019c158(u8* p) { return (*(u16*)(*(u8**)(p + 8) + 0x48) >> 3) & 1; }

void func_001afe18(void) {
    u8* p = D_00350df8;
    if (p) *(u32*)(p + 4) = 0;
}

void func_001e0310(u32 a) {
    D_00352b54 = D_00352b50;
    D_00352b50 = a;
}

void func_002ef5c8(u8* p) { wtarget_00239bf8(p + 468); }

void func_0014dd80(u8* p, u8* a, u8* b, u8* c) {
    *a = p[470];
    *b = p[471];
    *c = p[472];
}

void func_001e2aa0(void) {
    *(s32*)(D_00352bd0 + 0xdc0) = 3;
    *(s32*)(D_00352bd0 + 0xde4) = 0;
}

void func_002f4820(f32* d, f32* s) {
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
}

void func_00302dd0(u32 a) { func_00303698(a, (void*)func_00302b18); }

void wtarget_00167268(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00167268jjjj");
void wtarget_00167268(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff && a == 1) D_004f4240 = 0;
}

void func_00191398(u32 a, u32 b) { func_001cd690(&D_01c60d10, b, a); }
}
