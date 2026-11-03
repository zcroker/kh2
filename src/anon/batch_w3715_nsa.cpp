#include "../common/types.h"
typedef u8* (*AllocFn)(...);
struct Alloc { AllocFn* vt; };
extern "C" {
void func_002427c0(void);
void func_00253818(s32);
void func_00259350(s32);
void func_00287b18(s32, s32);
void func_00242618(s32, s32);
void func_0028d068(s32, s32);
u8* func_00288be8(s32);
void func_002889f0(u8*, s32, s32);
u8* func_0023ee30(u32);
void func_0031a838(u8*);
void func_002369a0(u8*);
void func_0023c008(u8*);
void func_00239700(u8*);
u8* func_00103eb0(void);
void func_002809d8(u32);
void func_00102818(u32, u32, u32, void (*)(u32), u32);
extern u8* D_00347f80;
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern u8 D_0035eb98[];
extern u8* D_0035f250;
extern u8* D_0035f254;
extern u8* D_0035f258;
extern u8* D_0035f25c;
// Startup: builds the global managers (D_0035f250..5c) and starts a thread.
void func_00280720(void) {
    func_002427c0();
    func_00253818(5);
    func_00259350(5);
    func_00287b18(1, 3);
    func_00242618(11, 1);
    func_0028d068(30026, -1);
    u8* p0 = func_00288be8(56);
    func_002889f0(p0, 3, 0);
    D_0035f254 = p0;
    u8* p1 = func_0023ee30(160);
    *(u32*)p1 = (u32)D_00347f98;
    func_0031a838(p1 + 12);
    *(u32*)p1 = (u32)D_0035eb98;
    func_002369a0(p1 + 24);
    func_0023c008(p1 + 48);
    // The original stores D_0035f250 before it loads D_00347f80 (as if the two could alias):
    // the store goes through a hidden high half pinned to t7, the register the original uses.
    register u32 hs asm("$15") = 0x360000; asm("" : "+r"(hs));
    *(u8**)(hs - 3504) = p1;
    Alloc* al = *(Alloc**)(D_00347f80 + 20);
    u8* p2 = al->vt[0](al, 408, 0);
    *(u32*)(p2 + 12) = 0;
    *(u32*)p2 = (u32)D_00347e60;
    func_00239700(p2 + 24);
    D_0035f258 = p2;
    Alloc* al2 = *(Alloc**)(D_00347f80 + 20);
    u8* p3 = al2->vt[0](al2, 1312, 0);
    *(u32*)p3 = 3;
    u8* a = p3 + 4;
    u8* q = a;
    for (s32 i = 2; i != -1; i--, q += 436) {
        *(u32*)q = (u32)D_00347f98;
        func_0031a838(q + 12);
        *(u32*)q = (u32)D_00347e60;
        func_00239700(q + 24);
        *(u32*)q = (u32)D_00347e40;
        *(u32*)(q + 408) = 0;
    }
    D_0035f25c = a;
    func_00102818(*(u32*)(func_00103eb0() + 4), 0, 2000, func_002809d8, 4096);
}
}
