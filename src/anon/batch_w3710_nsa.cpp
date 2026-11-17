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
void func_0014f300(void* a0);  // 0x0014f300: definition moved into src/anon/unit_0014ecb8.cpp

// 0013e688: builds the 9-entry table (896-byte records, three sub-objects each), stores it in D_003486a4, then
// allocates the 448-byte object kept in D_003486a0 and registers it.
// Partial asm: the same hidden 0x340000 high half as in 0014f300 keeps the heap-pointer load after the D_003486a4
// store; the store's own high half (lui 0x35) is one volatile asm instruction, and a1/a2 are pinned before it, so the
// original order (li a1; move a2; lui; sw; lw) is kept. Built with -fno-strict-aliasing (_nsa).
void u_call0_0013e688(void);  // 0x0013e688: definition moved into src/anon/unit_0013dfb8.cpp
