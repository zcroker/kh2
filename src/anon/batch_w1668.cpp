#include "../common/types.h"

extern "C" {

extern u32 D_0034f240;
void w191ee0(u32, u32, u32, u32) asm("_Z16wtarget_00191ee0jjjj");
void w191ee0(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_0034f240 = 0; }

extern u32 D_01d49970;
void w1c8d40(u32, u32, u32, u32) asm("_Z16wtarget_001c8d40jjjj");
void w1c8d40(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_01d49970 = 0; }

extern u32 D_003638d0;
void w2ef890(u32, u32, u32, u32) asm("_Z16wtarget_002ef890jjjj");
void w2ef890(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_003638d0 = a; }

struct W2 { u32 a; u32 b; };

extern W2 D_01c6cba0;
void w1a8570(u32, u32, u32, u32) asm("_Z16wtarget_001a8570jjjj");
void w1a8570(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) { D_01c6cba0.a = 0; D_01c6cba0.b = 0; } }

extern W2 D_01d48de0;
void w1ba798(u32, u32, u32, u32) asm("_Z16wtarget_001ba798jjjj");
void w1ba798(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) { D_01d48de0.b = 0; D_01d48de0.a = 0; } }

extern W2 D_01d5ba20;
void w1d3bc0(u32, u32, u32, u32) asm("_Z16wtarget_001d3bc0jjjj");
void w1d3bc0(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) { D_01d5ba20.b = 0; D_01d5ba20.a = 0; } }

extern u32 D_003511b8;
extern u32 D_01d48cb8;
void w1b8290(u32, u32, u32, u32) asm("_Z16wtarget_001b8290jjjj");
void w1b8290(u32 a, u32 b, u32, u32) { if (b == 0xffff && a == 1) D_01d48cb8 = D_003511b8; }

extern f32 D_00349e14;
void func_00239230(u8* p) { *(f32*)(p + 0x48) += D_00349e14 * *(f32*)(p + 0x44); }

void dkMap_setVisibleGroup(u32) asm("_ZN2dk3Map15setVisibleGroupEj");
void func_0015f6e8(void);
void func_0015e018(void);
void func_001e2a78(void) { dkMap_setVisibleGroup(0); func_0015f6e8(); func_0015e018(); }

extern u32 D_00363540;
void func_002eb778(void*, u32, u32);
void func_002eb868(void* p) { D_00363540 = 0; func_002eb778(p, 252, 0); }

struct S8 { u32 a, b; void (*fn)(u32, void*); };
void func_00319190(S8* p) { p->fn(1, p); }

// 00102ff0: moved to src/common/title.cpp

/* the original has three nops in the loop body (hand-placed delay padding) */
void func_001879f0(u32* p) {
    s32 i = 127;
    do { *p = 0; i--; asm volatile("nop\n\tnop\n\tnop"); p += 8; } while (i >= 0);
}

void func_001bf118(u8* p, s32 b) {
    if (b == 0) { *(u32*)(p + 0xab0) = 0; return; }
    *(u32*)(p + 0xab0) &= ~(1 << b);
}

void func_001e0dc8(void*);
void func_001e1698(u8* p) { func_001e0dc8(p); *(u32*)(p + 0x24) = 0; }

}
