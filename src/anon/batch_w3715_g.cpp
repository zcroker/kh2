#include "../common/types.h"
extern "C" {
s32 func_00103570(void);
s32 func_001063c0(s32, s32);
void func_0023f800(s32);
void func_002369a0(s32);
void func_00239700(void*);
void func_0023c008(s32);
u8* func_00103eb0(void);
void func_00102818(s32, s32, s32, void*, s32);
struct Alloc;
struct AllocVt { void* (*alloc)(Alloc*, s32, s32); };
struct Alloc { AllocVt* vt; };
struct Holder { u8 pad[0x14]; s32 a; };
extern Holder* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00288308[];
extern s16 D_0035f32c;
extern s16 D_0035f32e;
extern u8 D_0035f328;
extern s32 D_0035f334;
extern void* D_0035f338;
extern s32 D_0035f33c;
extern s32 D_0035f340;

// Startup: creates the managers kept in D_0035f334..D_0035f340 and starts a thread.
void func_002880b8(void) {
    D_0035f32c = -1;
    D_0035f32e = -1;
    s32 r = func_001063c0(0x1C, func_00103570());
    func_0023f800(r);
    Holder* h = D_00347f80;
    // The original loads D_00347f80 before this store and its field after it: the store
    // goes through a hidden high half pinned to t7, the register the original uses.
    register u32 hs asm("$15") = 0x360000; asm("" : "+r"(hs));
    *(s32*)(hs - 3276) = r;
    Alloc* a = (Alloc*)h->a;
    u8* p = (u8*)a->vt->alloc(a, 0x198, 0);
    *(s32*)(p + 0xC) = 0;
    *(void**)p = D_00347e60;
    func_00239700(p + 0x18);
    D_0035f338 = p;
    r = func_001063c0(0x18, func_00103570());
    func_002369a0(r);
    D_0035f33c = r;
    r = func_001063c0(0x5C, func_00103570());
    func_0023c008(r);
    D_0035f340 = r;
    D_0035f328 = 0;
    func_00102818(*(s32*)(func_00103eb0() + 4), 0, 0x7CE, D_00288308, 0x1000);
}

}
