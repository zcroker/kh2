// Linked unit 0x2c9998-0x2ca0e0: dk::WM_GLANDING_INFO, second part: D2/D1/D0 and the update/fade/exit
// methods. The first part (ctors and .rodata tables) is unit_002c87f8.cpp.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 002c9998 (from batch_w284.cpp)
namespace n002c9998 {
// ---- 002c9998 / 002c9b38: destructor (two identical ABI copies)
struct E284 { void (**vt)(E284*); u8 pad[404]; };
extern u8 D_00361e10[] asm("D_00361e10");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_00361e00 asm("D_00361e00");
void func_00170950(u32) asm("func_00170950");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
#define ARR(b, e) if (p + (b)) { E284* q = (E284*)(p + (e)); top##b: if ((E284*)(p + (b)) == q) goto out##b; q--; q->vt[3](q); goto top##b; } out##b:

void func_002c9998(u8* p) asm("func_002c9998");
void func_002c9998(u8* p) {
    *(void**)p = D_00361e10;
    u32 x = *(u32*)(p + 9604); asm volatile("" ::: "memory");
    func_00170950(x);
    D_00361e00 = (D_00361e00 == p) ? 0 : D_00361e00;
    ARR(8376, 9600)
    ARR(4704, 8376)
    ARR(3480, 4704)
    ARR(2256, 3480)
    ARR(1032, 2256)
    *(u32*)(p + 624) = (u32)D_00347e60;
    func_00239870(p + 648);
    *(u32*)(p + 624) = (u32)D_00347f98;
    *(u32*)(p + 188) = (u32)D_00347e60;
    func_00239870(p + 212);
    *(u32*)(p + 188) = (u32)D_00347f98;
    *(u32*)(p + 28) = (u32)D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(u32*)(p + 28) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
}
#undef ARR
}  // namespace n002c9998

// ---- 002c9b38 (from batch_w284.cpp)
namespace n002c9b38 {
// ---- 002c9998 / 002c9b38: destructor (two identical ABI copies)
struct E284 { void (**vt)(E284*); u8 pad[404]; };
extern u8 D_00361e10[] asm("D_00361e10");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_00361e00 asm("D_00361e00");
void func_00170950(u32) asm("func_00170950");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
#define ARR(b, e) if (p + (b)) { E284* q = (E284*)(p + (e)); top##b: if ((E284*)(p + (b)) == q) goto out##b; q--; q->vt[3](q); goto top##b; } out##b:


void func_002c9b38(u8* p) asm("func_002c9b38");
void func_002c9b38(u8* p) {
    *(void**)p = D_00361e10;
    u32 x = *(u32*)(p + 9604); asm volatile("" ::: "memory");
    func_00170950(x);
    D_00361e00 = (D_00361e00 == p) ? 0 : D_00361e00;
    ARR(8376, 9600)
    ARR(4704, 8376)
    ARR(3480, 4704)
    ARR(2256, 3480)
    ARR(1032, 2256)
    *(u32*)(p + 624) = (u32)D_00347e60;
    func_00239870(p + 648);
    *(u32*)(p + 624) = (u32)D_00347f98;
    *(u32*)(p + 188) = (u32)D_00347e60;
    func_00239870(p + 212);
    *(u32*)(p + 188) = (u32)D_00347f98;
    *(u32*)(p + 28) = (u32)D_0035eb98;
    func_0023c098(p + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 52);  // set_vtbl_36eac8_then_call
    *(u32*)(p + 28) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
}
#undef ARR
}  // namespace n002c9b38

// ---- 002c9cd8 (from batch_w8012.cpp)
namespace n002c9cd8 {
struct Alloc { void (**vt)(Alloc*, ...); };
struct Holder { u8 pad[0x14]; Alloc* al; };
typedef void (*DtorFn)(u8*);
extern void* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
extern u8 D_0035eb98 asm("D_0035eb98");
extern u8 D_00361e10 asm("D_00361e10");
extern u8* D_00361e00 asm("D_00361e00");
void func_00170950(s32) asm("func_00170950");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
static inline void Free(void* p) { Alloc* al = ((Holder*)D_00347f80)->al; al->vt[1](al, p); }

void func_002c9cd8(u8* self) asm("func_002c9cd8");
void func_002c9cd8(u8* self) {
    *(void**)self = &D_00361e10;
    func_00170950(*(s32*)(self + 0x2584));
    D_00361e00 = (D_00361e00 == self) ? 0 : D_00361e00;
    if (self + 0x20b8) {
        u8* p = self + 0x2580;
    top0x20b8:
        if (self + 0x20b8 == p) goto out0x20b8;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x20b8;
    }
out0x20b8:;
    if (self + 0x1260) {
        u8* p = self + 0x20b8;
    top0x1260:
        if (self + 0x1260 == p) goto out0x1260;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x1260;
    }
out0x1260:;
    if (self + 0xd98) {
        u8* p = self + 0x1260;
    top0xd98:
        if (self + 0xd98 == p) goto out0xd98;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0xd98;
    }
out0xd98:;
    if (self + 0x8d0) {
        u8* p = self + 0xd98;
    top0x8d0:
        if (self + 0x8d0 == p) goto out0x8d0;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x8d0;
    }
out0x8d0:;
    if (self + 0x408) {
        u8* p = self + 0x8d0;
    top0x408:
        if (self + 0x408 == p) goto out0x408;
        p -= 0x198;
        (*(DtorFn*)(*(u8**)p + 12))(p);
        goto top0x408;
    }
out0x408:;
    *(void**)(self + 0x270) = &D_00347e60;
    func_00239870(self + 0x288);
    *(void**)(self + 0x270) = &D_00347f98;
    *(void**)(self + 0xbc) = &D_00347e60;
    func_00239870(self + 0xd4);
    *(void**)(self + 0xbc) = &D_00347f98;
    *(void**)(self + 0x1c) = &D_0035eb98;
    func_0023c098(self + 0x4c);
    func_002369f0(self + 0x34);
    *(void**)(self + 0x1c) = &D_00347f98;
    *(void**)self = &D_00347f98;
    Free(self);
}
}  // namespace n002c9cd8

// ---- 002c9e90 (from tiny.cpp)
namespace n002c9e90 {
extern u32 D_00375540 asm("D_00375540");


u32 func_002c9e90(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c9e90");
u32 func_002c9e90(u32 a0, u32 a1, u32 a2, u32 a3) {  // halfword_375540
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)(s32)(*(s16*)((u32)&D_00375540 + ((u32)a1 << 1) + (0)));
}
}  // namespace n002c9e90

// ---- 002c9ea8 (from tiny_auto80.cpp)
namespace n002c9ea8 {


void func_002c9ea8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c9ea8");
void func_002c9ea8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    if (r4 != 0u) {
        r15 = *(volatile u32*)((u32)r4 + (s32)(0));
        r14 = *(volatile u32*)((u32)r15 + (s32)(16));
        ((void(*)(u32,u32,u32,u32))(u32)r14)(r4, r5, r6, r7);
    }
}
}  // namespace n002c9ea8

// ---- 002c9ed8 (from tiny_jal_wrappers_reloc.cpp)
namespace n002c9ed8 {
// obj_ctor_347b88
u32 func_00138c10(u32, u32, u32, u32) asm("func_00138c10");
extern u8 D_003757e0 asm("D_003757e0");


u32 func_002c9ed8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c9ed8");
u32 func_002c9ed8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_003757e0;
    r16 = (u32)((s32)r4 + (188));
    r14 = *(u32*)((u32)r4 + (s32)(9612));
    r14 = (u32)(r14 << 1);
    r4 = r16;
    r14 = (u32)(r14 + r15);
    r5 = (u32)(s32)(*(s16*)((u32)r14 + (s32)(0)));
    r2 = func_00138c10(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (-1));
    *(u32*)((u32)r16 + (s32)(392)) = r15;
    return r2;
}
}  // namespace n002c9ed8

// ---- 002c9f20 (from tiny_auto80_queue.cpp)
namespace n002c9f20 {
extern "C" u32 func_00139510(...) asm("func_00139510");
extern "C" u32 func_00139d78(...) asm("func_00139d78");


void func_002c9f20(u32 a0) asm("func_002c9f20");
void func_002c9f20(u32 a0) {
    u32 p = a0 + 188;
    if (func_00139d78(p) != 0) {
        func_00139510(p);
    }
}
}  // namespace n002c9f20

// ---- 002c9f60 (from auto80_199_queue.cpp)
namespace n002c9f60 {


void func_002c9f60(u8* a0) asm("func_002c9f60");
void func_002c9f60(u8* a0) {
    u8* s1 = a0;
    u8* t6 = a0 + 188;
    u8* s0;

    u32 t7 = *(u32*)(a0 + 24);
    t7 = t7 & 1;
    if (t7 != 0) {
        u32* vt = *(u32**)a0;
        ((VCall20)vt[5])(a0);
        return;
    }

    if (func_00139538(t6) == 0) {
        goto L_fail;
    }

    s0 = s1 + 28;
    if (func_00139d78(s0) != 0) {
        func_00139510(s0);
    }

    t7 = *(u32*)(s1 + 24);
    t7 = t7 | 1;
    *(u32*)(s1 + 24) = t7;
    return;

L_fail:
    func_00236d60();  // clear_64_entries_24
}
}  // namespace n002c9f60

// ---- 002c9ff8: forwards the object's handle at +9600 (never written before)
namespace n002c9ff8 {
void func_00236788(u32) asm("func_00236788");
void func_002c9ff8(u8* p) asm("func_002c9ff8");
void func_002c9ff8(u8* p) { func_00236788(*(u32*)(p + 9600)); }
}  // namespace n002c9ff8

// ---- 002ca010 (from batch_w53.cpp)
namespace n002ca010 {
typedef void* (*AllocFn)(void*, u32, u32);
extern u8* D_00361e00 asm("D_00361e00");
extern u8* D_00347f80 asm("D_00347f80");
u32 func_002cab58(u32) asm("func_002cab58");
void func_002c9f20(u8*) asm("func_002c9f20");
void func_002c90c8(void*, u32) asm("func_002c90c8");


void func_002ca010(u32 a) asm("func_002ca010");
void func_002ca010(u32 a) {
    if (func_002cab58(a)) return;
    u8* c = D_00361e00;
    if (c) {
        if (*(u32*)(c + 9608) == a) return;
        func_002c9f20(c);
        D_00361e00 = 0;
    }
    u8* al = *(u8**)(D_00347f80 + 20);
    void* m = (**(AllocFn**)al)(al, 9616, 0);
    func_002c90c8(m, a);
}
}  // namespace n002ca010

// ---- 002ca0a8: dk::WM_GLANDING_INFO::exit (from src/worldmap/wm_glanding_info.cpp)
namespace n002ca0a8 {
extern u32 D_00361e00 asm("D_00361e00");
void WM_GLANDING_INFO_fadeout(u32) asm("func_002c9ed8");
void WM_GLANDING_INFO_exit() asm("_ZN2dk16WM_GLANDING_INFO4exitEv");
void WM_GLANDING_INFO_exit() {
    u32 ptr = D_00361e00;
    if (ptr) {
        WM_GLANDING_INFO_fadeout(ptr);
        D_00361e00 = 0;
    }
}
}  // namespace n002ca0a8

