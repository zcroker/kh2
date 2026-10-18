#include "../common/types.h"
typedef struct Alloc Alloc; typedef struct AllocVt AllocVt; typedef struct Heap Heap;
struct Alloc;
struct AllocVt { void* (*alloc)(Alloc*, u32, u32); };
struct Alloc { AllocVt* vt; };
struct Heap { u8 pad[0x14]; Alloc* a; };

extern Heap* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u8 D_003485b0[];
extern u8 D_003485d0[];
extern void* D_00348050;
extern void* D_00348054;
extern void* D_00348058;
u32 func_001050c8(void);
u8* func_001063c0(u32, u32);
void func_0031a838(void*);
void func_00239700(void*);
void func_002361a0(void*);
void func_0013ad20(void) {
    u32 h = func_001050c8();
    u8* m = func_001063c0(0x6ed4, h);
    u8* p;
    s32 n = 35;
    p = m;
    do {
        *(u32*)(p + 12) = 0;
        *(u32*)p = (u32)D_00347e60;
        func_00239700(p + 24);
        *(u32*)(p + 0x198) = 0;
        *(u32*)p = (u32)D_003485b0;
        func_00239700(p + 0x1b4);
        p += 0x310;
    } while (--n != -1);
    s32 i = 0;
    s32* q = (s32*)(m + 0x6e40);
    do { *q++ = i; i++; } while (i < 36);
    *(s32*)(m + 0x6ed0) = 36;
    *(u32*)&D_00348058 = (u32)m;
    u8* m2 = func_001063c0(0x3384, h);
    p = m2;
    n = 31;
    do {
        *(u32*)p = (u32)D_00347f98;
        func_0031a838(p + 12);
        *(u32*)p = (u32)D_00347e60;
        func_00239700(p + 24);
        *(u32*)p = (u32)D_003485d0;
        p += 0x198;
    } while (--n != -1);
    s32 j = 0;
    s32* r = (s32*)(m2 + 0x3300);
    do { *r++ = j; j++; } while (j < 32);
    *(s32*)(m2 + 0x3380) = 32;
    D_00348054 = m2;
    Alloc* al = ((Heap*)*(u32*)&D_00347f80)->a;
    u32* o = (u32*)al->vt->alloc(al, 0x1c0, 0);
    o[3] = 0;
    o[0] = (u32)D_00347e80;
    func_002361a0(o + 8);
    D_00348050 = o;
}
