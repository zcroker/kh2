// 0014f300: allocates the four global subsystems (heap alloc through the system heap's vtable, then constructors).
// Partial asm: the high half of the system-object address (0x340000) goes through an empty asm so gcc cannot see
// that the heap-pointer load (0x347f80) and the D_0034a428/D_0034a430 stores hit different globals; that keeps the
// load after the store like the original. One register pin ($14) on the first load keeps the original t6/t7 choice.
// Built with -fno-strict-aliasing (_nsa).
#include "../common/types.h"
struct Heap;
struct HeapVT { void* (*alloc)(Heap*, u32, s32); };
struct Heap { HeapVT* vt; };
struct Sys { u8 pad[0x14]; Heap* heap; };
extern "C" {
extern Sys* D_00347f80;
extern void* D_0034a428;
extern void* D_0034a42c;
extern void* D_0034a430;
extern void* D_0034a434;
extern u8 D_0034a568[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
void func_0014fba0(void*);
void func_0031bd98(void*);
void func_0031be70(void*);
void func_0031a838(void*);
void func_00239700(void*);
void func_0031bed8(void*);
void func_0031bf50(void*);
void* func_001050c8(void);
u8* func_001063c0(u32, void*);
void func_002361a0(void*);
s32 func_0013a7d0(s32);
void func_00138650(void*, s32, s32, s32);
void func_0013e890(void);
extern u32 D_00347e18[];
extern u32 D_003486b0[];
extern u32 D_00347e80[];
extern u8* D_003486a0;
}
// System heap: Sys at 0x347f80 (= hi 0x340000 + 0x7f80), heap->vt->alloc(heap, size, 0).
static inline void* halloc1(u8* b, u32 n) { register Sys* s asm("$14") = *(Sys**)(b + 0x7f80); return s->heap->vt->alloc(s->heap, n, 0); }
static inline void* halloc(u8* b, u32 n) { Sys* s = *(Sys**)(b + 0x7f80); return s->heap->vt->alloc(s->heap, n, 0); }
void func_0014f300(void* a0) {
    func_0014fba0(a0);
    u8* b = (u8*)0x340000;
    asm("" : "+r"(b));
    void* p = halloc1(b, 0x19b0);
    func_0031bd98(p);
    D_0034a428 = p;
    u8* q = (u8*)halloc(b, 0x3e0);
    *(s32*)(q + 0xc) = 0;
    *(void**)q = D_0034a568;
    func_0031be70(q + 0x30);
    *(void**)(q + 0x230) = D_00347f98;
    func_0031a838(q + 0x23c);
    *(void**)(q + 0x230) = D_00347e60;
    func_00239700(q + 0x248);
    *(s32*)(q + 0x3cc) = 0;
    D_0034a42c = q;
    p = halloc(b, 0xb54);
    func_0031bed8(p);
    D_0034a430 = p;
    p = halloc(b, 0xb54);
    func_0031bf50(p);
    D_0034a434 = p;
}

// 0013e688: builds the 9-entry table (896-byte records, three sub-objects each), stores it in D_003486a4, then
// allocates the 448-byte object kept in D_003486a0 and registers it.
// Partial asm: the same hidden 0x340000 high half as in 0014f300 keeps the heap-pointer load after the D_003486a4
// store; the store's own high half (lui 0x35) is one volatile asm instruction, and a1/a2 are pinned before it, so the
// original order (li a1; move a2; lui; sw; lw) is kept. Built with -fno-strict-aliasing (_nsa).
void u_call0_0013e688(void) {
    u8* p = func_001063c0(8112, func_001050c8());
    u8* q = p;
    u32* r = (u32*)(p + 12);
    for (s32 i = 8; i != -1; i--) {
        u32 ve60 = (u32)D_00347e60;
        u32 ve18 = (u32)D_00347e18;
        u32 vb0 = (u32)D_003486b0;
        u32 vf98 = (u32)D_00347f98;
        r[0] = 0;
        r[-3] = ve60;
        func_00239700(q + 24);
        r[105] = 0;
        r[-3] = vb0;
        r[109] = vf98;
        func_0031a838(q + 460);
        r[109] = ve60;
        func_00239700(q + 472);
        r[109] = ve18;
        r[217] = 0;
        q += 896;
        r += 224;
    }
    for (s32 j = 0; j < 9; j++) ((s32*)(p + 8064))[j] = j;
    u8* b = (u8*)0x340000;
    asm("" : "+r"(b));
    *(u32*)(p + 8100) = 9;
    register u32 n asm("$5") = 448;
    register s32 z asm("$6") = 0;
    u8* c;
    asm volatile("lui %0,0x35" : "=r"(c));
    *(u8**)(c - 31068) = p; // D_003486a4 = p
    Heap* hp = (*(Sys**)(b + 0x7f80))->heap;
    u8* o = (u8*)hp->vt->alloc(hp, n, z);
    *(u32*)(o + 12) = 0;
    *(u32**)o = D_00347e80;
    func_002361a0(o + 32);
    D_003486a0 = o;
    func_00138650(D_003486a0, 3700, func_0013a7d0(0), 0);
    func_0013e890();
}
