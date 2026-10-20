#include "../common/types.h"
struct W1669NoTail { ~W1669NoTail() {} };
struct W1669Pair { u32 a, b; };
struct W1669Tri { u32 a, b; f32 c; };
extern "C" {
extern W1669Pair D_01e2be18;
extern W1669Pair D_01e2bf00;
extern W1669Pair D_01e2c080;
extern f32 D_00351fe0;
extern W1669Tri D_004574b8;
extern u32 D_0032df30[];
extern u8 D_00348d68[];
void func_001491c0(void*);
void func_001a1460(u32) asm("_ZN2YS5SHEET6reloadEv");
f32 func_00166d70(u32);
void func_00154de8(u8*, f32);
void func_001bc688(void*) asm("_ZN2YS12COMMAND_SLOT5clearEv");
void func_00190128(void*);
f32 func_001065a8(f32, f32) asm("_Z13func_001065a8jjjjjjjj");

void wtarget_002ce910(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ce910jjjj");
void wtarget_002ce910(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2be18.b = 0; D_01e2be18.a = 0; }
}
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002e7610jjjj");
void wtarget_002e7610(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2bf00.b = 0; D_01e2bf00.a = 0; }
}
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_002ee540jjjj");
void wtarget_002ee540(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_01e2c080.b = 0; D_01e2c080.a = 0; }
}
void func_001cbf20(u32 a0, u32 a1) {
    if (a1 == 0xffff && a0 == 1) { D_00351fe0 = 4.7123885f; }
}
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0014d240jjjj");
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_004574b8.a = 0; D_004574b8.b = 0; D_004574b8.c = 1.0f; }
}
void func_00149f30(int a0, int a1) asm("_Z13func_00149f30ii");
void func_00149f30(int a0, int a1) {
    W1669NoTail nt;
    if (a1 == 0xffff && a0 == 1) func_001491c0(D_00348d68);
}
void func_00323ad0(u32* p) {
    s32 i = 19;
    do { *p = 0; i--; __asm__ volatile("nop\n\tnop\n\tnop"); p++; } while (i >= 0);
}
void func_001e7440(void) {
    u32 x;
    do { x = *(volatile u32*)0x1000a000 & 0x100; __asm__ volatile("nop\n\tnop\n\tnop"); } while (x);
}
struct W1669VObj { void** vt; };
void func_00153c98(W1669VObj* p) {
    if (p) ((void (*)(W1669VObj*))p->vt[4])(p);
}
void func_00177678(u8* p) {
    u32 x = *(u32*)(p + 0x48c);
    if (x) func_001a1460(x);
}
void func_001556c0(u8* p) {
    func_00154de8(p, func_00166d70(*(u32*)(p + 0x34)));
}
void func_0019d518(u8* p) {
    func_001bc688(p + 36);
    func_00190128(p + 12);
}
void func_001a9160(u32 n) {
    D_0032df30[n >> 5] |= 1 << (n & 31);
}
void func_002e73a8(u8* p) {
    *(f32*)(p + 0x1c) = func_001065a8(*(f32*)(p + 0x10), *(f32*)(p + 0x14));
}
}
