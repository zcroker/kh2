#include "../common/types.h"
struct Heap1956;
struct HeapVt1956 { void* (*alloc)(Heap1956*, u32, u32); };
struct Heap1956 { HeapVt1956* vt; };
struct Sys1956 { u8 pad[20]; Heap1956* heap; };
struct Obj13d820w1956 { u32 vt; u32 f4; u32 f8; u32 f12; u8 pad[16]; u8 sub[1]; };
extern "C" {
extern Sys1956* D_00347f80;
extern u8 D_00347e80[];
extern u8 D_003485fc;
extern Obj13d820w1956* D_003485e8;
extern void* D_003485ec;
extern void* D_003485f0;
extern void* D_003485f4;
extern void* D_003485f8;
void func_002361a0(void*);
void func_0031b130(void*);
void func_0031b3b8(void*);
void func_0031b4f0(void*);
s32 func_0013a7d0(s32);
void func_00138650(void*, s32, s32, s32);
s32 func_0013dda0(s32);
void func_00154f30(void*, s32, s32);
void func_001569d8(void*, s32);
void func_00154558(void*);
void func_0013db60(void);

void ttarget0_0013d820(void) asm("_Z17ttarget0_0013d820v");
void ttarget0_0013d820(void) {
    Heap1956* h;
    void* p;
    D_003485fc = 0;
    h = D_00347f80->heap;
    Obj13d820w1956* o = (Obj13d820w1956*)h->vt->alloc(h, 448, 0);
    o->f12 = 0;
    o->vt = (u32)D_00347e80;
    func_002361a0(o->sub + 0);
    D_003485e8 = o;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 15616, 0);
    func_0031b130(p);
    D_003485ec = p;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 5552, 0);
    func_0031b3b8(p);
    D_003485f0 = p;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 5552, 0);
    func_0031b3b8(p);
    D_003485f4 = p;
    h = D_00347f80->heap;
    p = h->vt->alloc(h, 15588, 0);
    func_0031b4f0(p);
    D_003485f8 = p;
    func_00138650(D_003485e8, 6000, func_0013a7d0(1), 0);
    func_00154f30(D_003485f4, func_0013dda0(2), 1);
    func_00154f30(D_003485f0, func_0013dda0(1), 0);
    func_001569d8(D_003485ec, func_0013dda0(0));
    func_00154558(D_003485f8);
    func_0013db60();
}
}
