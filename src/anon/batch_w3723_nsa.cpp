// w3723 2026-11-04: 00243298 matched with -fno-strict-aliasing (_nsa). Partial asm: the four global high halves
// (lui) are hand-written into pinned t6/t7 so the byte stores to D_0035ed0c/D_0035ed14 keep the original lui placement;
// the loop invariants (e60 vtable copy, -1 bound) are pinned to s5/s6. Based on zl90 best/00243298.cpp.
#include "../common/types.h"
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
extern "C" {
extern Holder* D_00347f80;
extern u8 D_00347e60;
extern u8 D_00347e40;
extern u8 D_00347f98;
extern s32 D_0035ece8; extern s32 D_0035ecec; extern s32 D_0035ecf0; extern s32 D_0035ecf4;
extern s32 D_0035ecf8; extern void* D_0035ecfc; extern void* D_0035ed00; extern void* D_0035ed04;
extern s32 D_0035ed08; extern s8 D_0035ed0c; extern s32 D_0035ed10; extern s8 D_0035ed14;
void func_00287b18(s32, s32);
s32 func_00288be8(s32);
void func_002889f0(s32, s32, s32);
void func_00288f48(s32, s32, s32, s32, s32);
void func_002b3df8(s32);
s32 func_00103570(void);
s32 func_001063f0(s32, s32);
void func_002fde18(s32, s32, s32);
void func_00239700(void*);
void func_0031a838(void*);
void func_0028d068(s32, s32);
s32* func_00103eb0(void);
void func_00102818(s32, s32, s32, void*, s32);
void PauseThread_243(void*) asm("_ZN2Tz4HEFT11PauseThreadEP4TASK");

typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
void func_00243298(void) {
    s32 v;
    u8* o;
    void* e60 = &D_00347e60;
    void* e40 = &D_00347e40;
    func_00287b18(2, 3);
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 1);
    D_0035ece8 = v;
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 0);
    D_0035ecec = v;
    func_00288f48(v, 0x40, 0x80, 0, 0);
    D_0035ecf0 = 0;
    D_0035ecf4 = 0;
    D_0035ecf8 = 0;
    v = (s32)Al(12);
    func_002b3df8(v);
    {
        register u32 h1 asm("$15");
        register u32 h asm("$14");
        asm("lui %0,%%hi(D_0035ed08)" : "=r"(h1));
        asm("lui %0,%%hi(D_0035ed0c)" : "=r"(h) : "r"(h1));
        asm("" : "+r"(v) : "r"(h));
        *(s32*)(h1 - 4856) = v;
        *(s8*)(h - 4852) = 0;
    }
    {
        Alloc* al = D_00347f80->al;
        o = (u8*)(*al->vt)(al, 436, 0);
        *(void**)o = e60;
        *(s32*)(o + 12) = 0;
        func_00239700(o + 24);
        *(s32*)(o + 408) = 0;
        *(void**)o = e40;
        D_0035ecfc = o;
    }
    {
        Alloc* al = D_00347f80->al;
        o = (u8*)(*al->vt)(al, 436, 0);
        *(void**)o = &D_00347f98;
        func_0031a838(o + 12);
        *(void**)o = e60;
        func_00239700(o + 24);
        *(void**)o = e40;
        *(s32*)(o + 408) = 0;
        D_0035ed00 = o;
    }
    v = func_001063f0(0x20, func_00103570());
    D_0035ed10 = v;
    func_002fde18(v, 0, 0x20);
    {
        register Holder* hh asm("$15") = D_00347f80;
        Alloc* al = hh->al;
        s32* p = (s32*)(*al->vt)(al, 820, 0);
        u8* base = (u8*)(p + 1);
        u8* q = base;
        register s32 i asm("$20") = 1;
        register void* vt asm("$21") = e60;
        register s32 m1 asm("$22") = -1;
        *p = 2;
        do {
            *(s32*)(q + 12) = 0;
            *(void**)q = vt;
            i--;
            func_00239700(q + 0x18);
            q += 0x198;
        } while (i != m1);
        register u32 h3 asm("$15");
        register u32 h2 asm("$14");
        asm("lui %0,%%hi(D_0035ed04)" : "=r"(h3));
        asm("lui %0,%%hi(D_0035ed14)" : "=r"(h2) : "r"(h3));
        asm("" : "+r"(base) : "r"(h2));
        *(u8**)(h3 - 4860) = base;
        register s32 r4 asm("$4") = 30026;
        asm("" : "+r"(h2) : "r"(r4));
        *(s8*)(h2 - 4844) = 0;
        func_0028d068(r4, -1);
    }
    func_00102818(func_00103eb0()[1], 0, 2000, (void*)PauseThread_243, 0x1000);
}
}
