// Linked unit 0x001149a0-0x00117588 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../naka/libkn/friend_personality.hpp"
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
#include "../naka/libkn/ability_info.hpp"

// 001149a0 (gap function, not written before): mode test / follow update of a friend controller
namespace g001149a0 {
struct V4 { f32 x, y, z, w;
    V4& operator=(const V4& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct Obj { u8 pad[112]; f32 a, b; };
struct In;
struct O { void* vt; In* in; Obj* obj; u8 pad[20]; V4 v; };
u32 func_0010f8c0(In*) asm("func_0010f8c0");
u32 func_0010f8e0(In*) asm("func_0010f8e0");
f32 func_0010f8a8(In*) asm("func_0010f8a8");
u32 func_0010cc80(In*) asm("func_0010cc80");
void func_0010f880(f32, f32, In*) asm("func_0010f880");
void func_00110630(In*) asm("func_00110630");
V4* func_0010fa28(In*) asm("func_0010fa28");
f32 func_0010e7e0(In*, s32) asm("func_0010e7e0");
void func_0010f9f0(In*, V4*, s32) asm("func_0010f9f0");
u8 func_001149a0(O* o, u32 a1, u32 a2, u32 a3, u8 mode) asm("func_001149a0");
u8 func_001149a0(O* o, u32 a1, u32 a2, u32 a3, u8 mode) {
    if (mode) {
        if (func_0010f8c0(o->in)) {
            if (func_0010f8e0(o->in)) return 0;
            if (func_0010f8a8(o->in) <= 0.0f) return 0;
        }
        if (!func_0010cc80(o->in)) return 0;
    } else if (func_0010f8c0(o->in) == 0) {
        func_0010f880(o->obj->a, o->obj->b, o->in);
        func_00110630(o->in);
        o->v = *func_0010fa28(o->in);
        o->v.w = func_0010e7e0(o->in, 2);
    } else {
        func_0010f9f0(o->in, &o->v, 0);
    }
    return 1;
}
}  // namespace g001149a0

// 00114a90 (gap function, not written before)
namespace g00114a90 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00114a90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00114a90");
u32 func_00114a90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00114a90

// 00114ab0 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114ab0 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_003464e8 asm("D_003464e8");
extern u8 D_00346658 asm("D_00346658");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114ab0*/
u32 func_00114ab0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114ab0jjjjjjjj");
u32 func_00114ab0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_003464e8;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346658;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n00114ab0

// 00114af8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114af8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_003464e8 asm("D_003464e8");
extern u8 D_00346658 asm("D_00346658");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114af8*/
u32 func_00114af8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114af8jjjjjjjj");
u32 func_00114af8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_003464e8;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346658;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n00114af8

// 00114b40 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114b40 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346658 asm("D_00346658");
/*TARGET 00114b40*/
u32 func_00114b40(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114b40jjjj");
u32 func_00114b40(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346658;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114b40

// 00114b68 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114b68 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346658 asm("D_00346658");
/*TARGET 00114b68*/
u32 func_00114b68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114b68jjjj");
u32 func_00114b68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346658;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114b68

// 00114b90 (was src/anon/batch_w12.cpp)
namespace n00114b90 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
// set_vtbl_362d20

extern u8 D_00346658 asm("D_00346658");
/*TARGET 00114b90*/
// Deleting destructor: reset vtable, run base dtor, free.
void func_00114b90(void** p) asm("func_00114b90");
// Deleting destructor: reset vtable, run base dtor, free.
void func_00114b90(void** p) {
    *p = &D_00346658;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00114b90

// 00114bc8 (gap function, not written before)
namespace g00114bc8 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00114bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00114bc8");
u32 func_00114bc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00114bc8

// 00114be8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114be8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346690 asm("D_00346690");
extern u8 D_003467b8 asm("D_003467b8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114be8*/
u32 func_00114be8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114be8jjjjjjjj");
u32 func_00114be8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346690;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003467b8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 8;
    return r2;
}
}  // namespace n00114be8

// 00114c30 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114c30 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346690 asm("D_00346690");
extern u8 D_003467b8 asm("D_003467b8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114c30*/
u32 func_00114c30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114c30jjjjjjjj");
u32 func_00114c30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346690;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003467b8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 8;
    return r2;
}
}  // namespace n00114c30

// 00114c78 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114c78 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003467b8 asm("D_003467b8");
/*TARGET 00114c78*/
u32 func_00114c78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114c78jjjj");
u32 func_00114c78(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003467b8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114c78

// 00114ca0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114ca0 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003467b8 asm("D_003467b8");
/*TARGET 00114ca0*/
u32 func_00114ca0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114ca0jjjj");
u32 func_00114ca0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003467b8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114ca0

// 00114cc8 (was src/anon/batch_w13.cpp)
namespace n00114cc8 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
// set_vtbl_362d20

extern u8 D_003467b8 asm("D_003467b8");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 00114cc8*/
void func_00114cc8(void** p) asm("func_00114cc8");
void func_00114cc8(void** p) {
    *p = &D_003467b8;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00114cc8

// 00114d00 (gap function, not written before)
namespace g00114d00 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_003467f0 asm("D_003467f0");
extern u8 D_00346960 asm("D_00346960");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114d48*/
u32 func_00114d00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00114d00");
u32 func_00114d00(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_003467f0;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346960;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace g00114d00

// 00114d48 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114d48 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_003467f0 asm("D_003467f0");
extern u8 D_00346960 asm("D_00346960");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114d48*/
u32 func_00114d48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114d48jjjjjjjj");
u32 func_00114d48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_003467f0;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346960;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n00114d48

// 00114d90 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114d90 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346960 asm("D_00346960");
/*TARGET 00114d90*/
u32 func_00114d90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114d90jjjj");
u32 func_00114d90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346960;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114d90

// 00114db8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114db8 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346960 asm("D_00346960");
/*TARGET 00114db8*/
u32 func_00114db8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114db8jjjj");
u32 func_00114db8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346960;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114db8

// 00114de0 (was src/anon/batch_w14.cpp)
namespace n00114de0 {
// list_nth_node_rel
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
extern u8 D_00346960[] asm("D_00346960");
/*TARGET 00114de0*/
// 00102a08: moved to src/global/unit_001022c0.cpp

void func_00114de0(u8* p) asm("func_00114de0");
// 00102a08: moved to src/global/unit_001022c0.cpp

void func_00114de0(u8* p) {
    *(u8**)p = D_00346960;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00114de0

// 00114e18 (gap function, not written before)
namespace g00114e18 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00114e18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00114e18");
u32 func_00114e18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00114e18

// 00114e38 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114e38 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00114e38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114e38jjjjjjjj");
u32 func_00114e38(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00114e38

// 00114e58 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114e58 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346998 asm("D_00346998");
extern u8 D_00346b08 asm("D_00346b08");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114e58*/
u32 func_00114e58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114e58jjjjjjjj");
u32 func_00114e58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346998;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346b08;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n00114e58

// 00114ea0 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114ea0 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346998 asm("D_00346998");
extern u8 D_00346b08 asm("D_00346b08");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114ea0*/
u32 func_00114ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114ea0jjjjjjjj");
u32 func_00114ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346998;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346b08;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n00114ea0

// 00114ee8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114ee8 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346b08 asm("D_00346b08");
/*TARGET 00114ee8*/
u32 func_00114ee8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114ee8jjjj");
u32 func_00114ee8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346b08;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114ee8

// 00114f10 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00114f10 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346b08 asm("D_00346b08");
/*TARGET 00114f10*/
u32 func_00114f10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00114f10jjjj");
u32 func_00114f10(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346b08;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00114f10

// 00114f38 (was src/anon/batch_w15.cpp)
namespace n00114f38 {
// 00102a38: moved to src/global/unit_001022c0.cpp

extern u8 D_00346b08 asm("D_00346b08");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
/*TARGET 00114f38*/
void func_00114f38(void** self) asm("func_00114f38");
void func_00114f38(void** self) {
    *self = &D_00346b08;
    func_00113668(self);
    func_00105110(self);
}
}  // namespace n00114f38

// 00114f70 (gap function, not written before)
namespace g00114f70 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00114f70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00114f70");
u32 func_00114f70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00114f70

// 00114f90 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114f90 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114f90*/
u32 func_00114f90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114f90jjjjjjjj");
u32 func_00114f90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00114f90

// 00114fb0 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114fb0 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346b40 asm("D_00346b40");
extern u8 D_00346cd8 asm("D_00346cd8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114fb0*/
u32 func_00114fb0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114fb0jjjjjjjj");
u32 func_00114fb0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346b40;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346cd8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 11;
    return r2;
}
}  // namespace n00114fb0

// 00114ff8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00114ff8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346b40 asm("D_00346b40");
extern u8 D_00346cd8 asm("D_00346cd8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00114ff8*/
u32 func_00114ff8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00114ff8jjjjjjjj");
u32 func_00114ff8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346b40;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346cd8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 11;
    return r2;
}
}  // namespace n00114ff8

// 00115040 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115040 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346cd8 asm("D_00346cd8");
/*TARGET 00115040*/
u32 func_00115040(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115040jjjj");
u32 func_00115040(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346cd8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115040

// 00115068 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115068 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346cd8 asm("D_00346cd8");
/*TARGET 00115068*/
u32 func_00115068(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115068jjjj");
u32 func_00115068(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346cd8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115068

// 00115090 (was src/anon/batch_w16.cpp)
namespace n00115090 {
void func_00105110(void*) asm("func_00105110");
void func_00113668(void*) asm("func_00113668");
extern u8 D_00346cd8 asm("D_00346cd8");
/*TARGET 00115090*/
// 00102c48: moved to src/common/unit_00102a70.cpp

// Destructor body: set vtable, destroy members, chain to the base.
void func_00115090(void* p) asm("func_00115090");
// 00102c48: moved to src/common/unit_00102a70.cpp

// Destructor body: set vtable, destroy members, chain to the base.
void func_00115090(void* p) {
    *(void**)p = &D_00346cd8;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00115090

// 001150c8 (gap function, not written before)
namespace g001150c8 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_001150c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001150c8");
u32 func_001150c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g001150c8

// 001150e8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001150e8 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 001150e8*/
u32 func_001150e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001150e8jjjjjjjj");
u32 func_001150e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n001150e8

// 00115108 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115108 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00115108*/
u32 func_00115108(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115108jjjjjjjj");
u32 func_00115108(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00115108

// 00115128 (was src/anon/auto80_199_queue.cpp)
namespace n00115128 {
/*TARGET 00115128*/
void func_00115128(u32 param_1, u32 param_2) asm("_Z13func_00115128jj");
void func_00115128(u32 param_1, u32 param_2) {
    u32 s1 = param_1;
    if (param_2 != 0) {
        u32 a1 = *(u32*)(param_2 + 0x20);
        if (a1 != 0) {
            if (((u16)*(u16*)(a1 + 2) - 0x2dcu) < 2u) {
                u32 s0 = (u32)&D_0036a698;
                u32 a0 = *(u32*)(param_1 + 4);
                if (func_001883d8(a0 + 0x300, s0) != 0) {
                    func_00188170(*(u32*)(s1 + 4) + 0x300, s0);
                    return;
                }
            }
        }
    }
}
}  // namespace n00115128

// 001151b0 (was src/anon/tiny_auto80_solver.cpp)
namespace n001151b0 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346d10 asm("D_00346d10");
extern u8 D_00346e80 asm("D_00346e80");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001151b0*/
u32 func_001151b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001151b0jjjjjjjj");
u32 func_001151b0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346d10;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346e80;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n001151b0

// 001151f8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001151f8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346d10 asm("D_00346d10");
extern u8 D_00346e80 asm("D_00346e80");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001151f8*/
u32 func_001151f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001151f8jjjjjjjj");
u32 func_001151f8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346d10;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00346e80;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n001151f8

// 00115240 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115240 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346e80 asm("D_00346e80");
/*TARGET 00115240*/
u32 func_00115240(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115240jjjj");
u32 func_00115240(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346e80;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115240

// 00115268 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115268 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00346e80 asm("D_00346e80");
/*TARGET 00115268*/
u32 func_00115268(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115268jjjj");
u32 func_00115268(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00346e80;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115268

// 00115290 (was src/anon/batch_w17.cpp)
namespace n00115290 {
// 001037b8: moved to src/common/unit_001031b0.cpp

extern u32 D_00346e80 asm("D_00346e80");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
/*TARGET 00115290*/
void func_00115290(void** p) asm("func_00115290");
void func_00115290(void** p) {
    *p = &D_00346e80;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00115290

// 001152c8 (gap function, not written before)
namespace g001152c8 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_001152c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001152c8");
u32 func_001152c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g001152c8

// 001152e8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001152e8 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 001152e8*/
u32 func_001152e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001152e8jjjjjjjj");
u32 func_001152e8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n001152e8

// 00115308 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115308 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346eb8 asm("D_00346eb8");
extern u8 D_00347050 asm("D_00347050");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00115308*/
u32 func_00115308(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115308jjjjjjjj");
u32 func_00115308(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346eb8;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347050;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 11;
    return r2;
}
}  // namespace n00115308

// 00115350 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115350 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00346eb8 asm("D_00346eb8");
extern u8 D_00347050 asm("D_00347050");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00115350*/
u32 func_00115350(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115350jjjjjjjj");
u32 func_00115350(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00346eb8;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347050;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 11;
    return r2;
}
}  // namespace n00115350

// 00115398 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115398 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347050 asm("D_00347050");
/*TARGET 00115398*/
u32 func_00115398(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115398jjjj");
u32 func_00115398(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347050;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115398

// 001153c0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001153c0 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347050 asm("D_00347050");
/*TARGET 001153c0*/
u32 func_001153c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001153c0jjjj");
u32 func_001153c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347050;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001153c0

// 001153e8 (was src/anon/batch_w18.cpp)
namespace n001153e8 {
// 00109cc0: moved to src/anon/unit_00109c30.cpp

extern u32 D_00347050 asm("D_00347050");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
/*TARGET 001153e8*/
void func_001153e8(void** p) asm("func_001153e8");
void func_001153e8(void** p) {
    *p = &D_00347050;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n001153e8

// 00115420 (gap function, not written before)
namespace g00115420 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00115420(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00115420");
u32 func_00115420(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00115420

// 00115440 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115440 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00115440*/
u32 func_00115440(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115440jjjjjjjj");
u32 func_00115440(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00115440

// 00115460 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115460 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00115460*/
u32 func_00115460(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115460jjjjjjjj");
u32 func_00115460(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00115460

// 00115480 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115480 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347088 asm("D_00347088");
extern u8 D_00347220 asm("D_00347220");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00115480*/
u32 func_00115480(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115480jjjjjjjj");
u32 func_00115480(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347088;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347220;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 11;
    return r2;
}
}  // namespace n00115480

// 001154c8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001154c8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347088 asm("D_00347088");
extern u8 D_00347220 asm("D_00347220");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001154c8*/
u32 func_001154c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001154c8jjjjjjjj");
u32 func_001154c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347088;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347220;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 11;
    return r2;
}
}  // namespace n001154c8

// 00115510 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115510 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347220 asm("D_00347220");
/*TARGET 00115510*/
u32 func_00115510(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115510jjjj");
u32 func_00115510(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347220;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115510

// 00115538 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115538 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347220 asm("D_00347220");
/*TARGET 00115538*/
u32 func_00115538(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115538jjjj");
u32 func_00115538(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347220;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115538

// 00115560 (was src/anon/batch_w19.cpp)
namespace n00115560 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
extern u8 D_00347220[] asm("D_00347220");
/*TARGET 00115560*/
// 0x0010f960: definition moved into src/anon/unit_0010f338.cpp

void func_00115560(void** p) asm("func_00115560");
// 0x0010f960: definition moved into src/anon/unit_0010f338.cpp

void func_00115560(void** p) {
    *p = D_00347220;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00115560

// 00115598 (gap function, not written before)
namespace g00115598 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 00114e38*/
u32 func_00115598(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00115598");
u32 func_00115598(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00115598

// 001155b8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001155b8 {
u32 func_00113fb0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113fb0jjjjjjjj");
/*TARGET 001155b8*/
u32 func_001155b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001155b8jjjjjjjj");
u32 func_001155b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113fb0)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n001155b8

// 001155d8 (was src/anon/tiny_auto80_solver.cpp)
namespace n001155d8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347258 asm("D_00347258");
extern u8 D_003473c8 asm("D_003473c8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 001155d8*/
u32 func_001155d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001155d8jjjjjjjj");
u32 func_001155d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347258;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003473c8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n001155d8

// 00115620 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115620 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347258 asm("D_00347258");
extern u8 D_003473c8 asm("D_003473c8");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00115620*/
u32 func_00115620(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115620jjjjjjjj");
u32 func_00115620(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347258;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_003473c8;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 10;
    return r2;
}
}  // namespace n00115620

// 00115668 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115668 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003473c8 asm("D_003473c8");
/*TARGET 00115668*/
u32 func_00115668(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115668jjjj");
u32 func_00115668(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003473c8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115668

// 00115690 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115690 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_003473c8 asm("D_003473c8");
/*TARGET 00115690*/
u32 func_00115690(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115690jjjj");
u32 func_00115690(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003473c8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115690

// 001156b8 (was src/anon/batch_w20.cpp)
namespace n001156b8 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
extern void* D_003473c8[] asm("D_003473c8");
/*TARGET 001156b8*/
void func_001156b8(void** p) asm("func_001156b8");
void func_001156b8(void** p) {
    *p = D_003473c8;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n001156b8

// 001156f0 (gap function, not written before)
namespace g001156f0 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347400 asm("D_00347400");
extern u8 D_00347550 asm("D_00347550");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00115738*/
u32 func_001156f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001156f0");
u32 func_001156f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347400;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347550;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 9;
    return r2;
}
}  // namespace g001156f0

// 00115738 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115738 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_00347400 asm("D_00347400");
extern u8 D_00347550 asm("D_00347550");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
/*TARGET 00115738*/
u32 func_00115738(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115738jjjjjjjj");
u32 func_00115738(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_00347400;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347550;
    *(volatile u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 9;
    return r2;
}
}  // namespace n00115738

// 00115780 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00115780 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347550 asm("D_00347550");
/*TARGET 00115780*/
u32 func_00115780(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00115780jjjj");
u32 func_00115780(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347550;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00115780

// 001157a8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001157a8 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347550 asm("D_00347550");
/*TARGET 001157a8*/
u32 func_001157a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001157a8jjjj");
u32 func_001157a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347550;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001157a8

// 001157d0 (was src/anon/batch_w21.cpp)
namespace n001157d0 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
extern u32 D_00347550 asm("D_00347550");
/*TARGET 001157d0*/
// 0x0010c7b0: definition moved into src/anon/unit_0010b978.cpp

void func_001157d0(void** p) asm("func_001157d0");
// 0x0010c7b0: definition moved into src/anon/unit_0010b978.cpp

void func_001157d0(void** p) {
    *p = &D_00347550;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n001157d0

// 00115808 (gap function, not written before)
namespace g00115808 {
u32 func_00113848(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00113848");
/*TARGET 00114e38*/
u32 func_00115808(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00115808");
u32 func_00115808(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113848)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace g00115808

// 00115828 (was src/anon/tiny_auto80_solver.cpp)
namespace n00115828 {
u32 func_00113990(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00113990jjjjjjjj");
/*TARGET 00115828*/
u32 func_00115828(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00115828jjjjjjjj");
u32 func_00115828(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r8 = (u32)(r8 & 0x00ffu);
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113990)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2) return r2;
    return r2;
}
}  // namespace n00115828

// 00115848 (was src/anon/batch_w2427_nsa.cpp)
namespace n00115848 {
struct Tgt115848;
struct Ent115848;
struct Who115848;
struct V115848 {
    f32 x, y, z, w;
    V115848 operator*(f32 k) const
    {
        V115848 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
    V115848& operator+=(const V115848& b)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&b) : "memory");
        return *this;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
};
void func_00190128(Tgt115848*) asm("func_00190128");
struct Tgt115848 {
    s32 f0, f4, f8, f12, f16;
    Tgt115848() { func_00190128(this); }
};
struct Parm115848 { u8 pad[4]; f32 f4; u8 pad2[8]; f32 f16; f32 f20; };
struct Ent115848;
struct Who115848;
typedef s32 (Who115848::*Pick115848)(Ent115848*, Tgt115848*, s32*, s32);
struct Ent115848 { u32 flags; Pick115848 pick; };
struct Who115848 {
    u8 pad0[20];
    Parm115848* parm;
    u8 pad1[1580 - 24];
    f32 f1580;
    union { u32 f1584; struct { s32 init : 1; s32 rest : 31; } fb; };
    u8 pad2[1600 - 1588];
    V115848 v1600;
    V115848 v1616;
    V115848 v1632;
    f32 f1648;
    f32 f1652;
    u8 pad4[1928 - 1656];
    s32 count;
};
struct Stats115848 { s32 f0, f4; u8 pad[376]; s32 f384, f388; bool full() { return f0 >= f4; } };
struct Lead115848 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual s32 act(s32, s32, s32);
    u8 pad[1160];
    Stats115848* stats;
};
struct Fr115848 {
    u8 pad0[352];
    u32 f352;
    u8 pad1[2912 - 356];
    Who115848* who;
    u8 pad2[2940 - 2916];
    u32 flags;
    u8 pad3[3168 - 2944];
    Ent115848* cur;
    bool isA() { if (f352 & 4) return true; return false; }
    bool isB() { if (f352 & 8) return true; return false; }
    bool isC() { if (f352 & 0x10) return true; return false; }
    bool busy() { return isA() || isB() || isC(); }
};
extern Lead115848* D_00341708 asm("D_00341708");
extern f32 D_00349e10 asm("D_00349e10");
extern const Pick115848 D_0036a760 asm("D_0036a760");
extern const Pick115848 D_0036a768 asm("D_0036a768");
void func_0016bd60(Fr115848*, s32) asm("func_0016bd60");
void func_00117808(Who115848*, V115848*) asm("func_00117808");
void func_00116798(Who115848*) asm("func_00116798");
s32 func_001917c0(void) asm("func_001917c0");
s32 func_001b58a8(void) asm("func_001b58a8");
f32 func_0010f660(void) asm("func_0010f660");
Ent115848* func_001144e8(Who115848*, Pick115848) asm("func_001144e8");
void func_0010eed8(Fr115848*, Ent115848*, s32) asm("func_0010eed8");
void func_0010ff08(Fr115848*) asm("func_0010ff08");
f32 func_0017ce80(f32, f32, f32) asm("func_0017ce80");
/*TARGET 00115848*/
void func_00115848(Fr115848* o) asm("func_00115848");
void func_00115848(Fr115848* o)
{
    Lead115848* lead = D_00341708;
    func_0016bd60(o, 3);
    if (!o->busy() && !(o->f352 & 0x40000000)) goto tail;
    {
        if (o->busy()) {
            if (!(o->flags & 0x80000000)) o->flags |= 0x80000000;
            if (!o->who->fb.init) {
                V115848 z;
                z.w = z.z = z.y = z.x = 0.0f;
                func_00117808(o->who, &z);
                o->who->f1584 |= 1;
            }
        }
        func_00116798(o->who);
        o->who->v1632.zero();
        s32 pick = 0;
        if (func_001917c0() && !func_001b58a8() && o->who->parm->f16 < (f32)o->who->count) {
            if (func_0010f660() < o->who->parm->f20) pick = 1;
            o->who->count = 0;
        }
        if (pick) {
            Stats115848* st = lead->stats;
            Ent115848* e;
            s32 h0=st->f0, m=st->f388, m0=st->f4, h=st->f384; if (h*m0 < h0*m) e = func_001144e8(o->who, D_0036a760);
            else e = func_001144e8(o->who, D_0036a768);
            Tgt115848 t;
            s32 score = 0;
            func_00190128(&t);
            func_0010eed8(o, 0, 0);
            o->flags &= ~4;
            (o->who->*e->pick)(e, &t, &score, 0);
            func_0010eed8(o, e, 0);
        } else {
            Ent115848* prev = o->cur;
            func_0010ff08(o);
            if (prev != o->cur || !(o->flags & 4)) o->who->count++;
        }
        Who115848* w = o->who;
        f32 r = func_0017ce80(w->v1600.w, w->v1616.w, w->f1580 * D_00349e10);
        o->who->v1600 += o->who->v1632 * o->who->v1632.w * D_00349e10;
        o->who->v1600.w = r;
    }
tail:
    if (lead->stats->full()) return;
    o->who->f1652 -= D_00349e10;
    if (o->who->f1652 <= 0.0f) {
        lead->act(1, 0, 0);
        o->who->f1652 = o->who->parm->f4;
    }
}
}  // namespace n00115848

// 00115c08 (was src/anon/batch_wcx2.cpp)
namespace n00115c08 {
struct VA14;
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
#define W115c08_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W115c08Vec {
    f32 x, y, z, w;
    W115c08Vec() {}
    W115c08Vec(const W115c08Vec& o) { W115c08_QCOPY(this, &o); }
    W115c08Vec& operator=(const W115c08Vec& o) { if (this != &o) W115c08_QCOPY(this, &o); return *this; }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W115c08Mtx {
    W115c08Vec r0, r1, r2, r3;
    W115c08Mtx() {}
    W115c08Mtx(const W115c08Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W115c08Mtx& operator=(const W115c08Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    W115c08Mtx operator*(const W115c08Mtx& b) const {
        W115c08Mtx o;
        const W115c08Mtx& a = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
        return o;
    }
    // general 4x4 inverse in place (affine: cofactors via outer products, 1/det in Q)
    void inverse() {
        asm volatile(".set noreorder\n\t"
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W115c08Vec operator*(const W115c08Vec& v) const {
        W115c08Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct O115c08 { u8 pad0[4]; void* model; u8 pad1[1656]; W115c08Mtx view; };
void f115c08_node(void*, s32, W115c08Mtx*) asm("func_0016b0e0");
s32 func_00106a18(u8) asm("func_00106a18");
f32 func_001070a0(s32) asm("func_001070a0");
u8* func_00106a60(u8) asm("func_00106a60");
void f115c08_euler(W115c08Mtx*, W115c08Vec*) asm("func_0011bac8");
f32 func_0017ce10(f32) asm("func_0017ce10");
/*TARGET 00115c08*/
void func_00115c08(O115c08* o, W115c08Mtx* m, W115c08Vec* scaleOut, W115c08Vec* rotOut, W115c08Vec* posOut, u8 cam) asm("func_00115c08");
void func_00115c08(O115c08* o, W115c08Mtx* m, W115c08Vec* scaleOut, W115c08Vec* rotOut, W115c08Vec* posOut, u8 cam)
{
    W115c08Vec scale, rot, pos;
    W115c08Mtx a, b;
    f115c08_node(o->model, 0x4002, &a);
    a.inverse();
    a = a * *m;
    a = o->view * a;
    a.r3.x = a.r3.x * 1024.0f / a.r3.z;
    a.r3.y = a.r3.y * 1024.0f / a.r3.z;
    a.r3.z = func_001070a0(func_00106a18(cam));
    u8* p = func_00106a60(cam);
    b = *(W115c08Mtx*)(p ? p + 16 : 0);
    b.inverse();
    a = b * a;
    scale.x = a.r0.normalize();
    scale.y = a.r1.normalize();
    scale.z = a.r2.normalize();
    rot.zero();
    f115c08_euler(&a, &rot);
    rot.x = func_0017ce10(rot.x);
    rot.y = func_0017ce10(rot.y);
    rot.z = func_0017ce10(rot.z);
    pos = a.r3;
    if (scaleOut) {
        scale.w = scaleOut->w;
        *scaleOut = scale;
    }
    if (rotOut) {
        rot.w = rotOut->w;
        *rotOut = rot;
    }
    if (posOut) {
        pos.w = posOut->w;
        *posOut = pos;
    }
}
}  // namespace n00115c08

// 001161c8 (was src/anon/batch_wcx2.cpp)
namespace n001161c8 {
struct VA14;
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
f32 func_0017ce10(f32) asm("func_0017ce10");
#define W1161c8_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1161c8Vec {
    f32 x, y, z, w;
    W1161c8Vec() {}
    W1161c8Vec(const W1161c8Vec& o) { W1161c8_QCOPY(this, &o); }
    W1161c8Vec& operator=(const W1161c8Vec& o) { if (this != &o) W1161c8_QCOPY(this, &o); return *this; }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1161c8Mtx {
    W1161c8Vec r0, r1, r2, r3;
    W1161c8Mtx() {}
    W1161c8Mtx(const W1161c8Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    W1161c8Mtx& operator=(const W1161c8Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    W1161c8Mtx operator*(const W1161c8Mtx& b) const {
        W1161c8Mtx o;
        const W1161c8Mtx& a = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
        return o;
    }
    // general 4x4 inverse in place (affine: cofactors via outer products, 1/det in Q)
    void inverse() {
        asm volatile(".set noreorder\n\t"
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    W1161c8Vec operator*(const W1161c8Vec& v) const {
        W1161c8Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
s32 f1161c8_cam(u8) asm("func_00106a18");
f32 f1161c8_fov(s32) asm("func_001070a0");
u8* f1161c8_camm(u8) asm("func_00106a60");
struct O1161c8 { u8 pad0[1792]; W1161c8Mtx view; };
void* func_00111e38(s32) asm("func_00111e38");
void f1161c8_node(void*, s32, W1161c8Mtx*) asm("func_0016b0e0");
void f1161c8_euler(W1161c8Mtx*, W1161c8Vec*) asm("func_0011bac8");
/*TARGET 001161c8*/
void func_001161c8(O1161c8* o, W1161c8Mtx* m, W1161c8Vec* scaleOut, W1161c8Vec* rotOut, W1161c8Vec* posOut, u8 cam) asm("func_001161c8");
void func_001161c8(O1161c8* o, W1161c8Mtx* m, W1161c8Vec* scaleOut, W1161c8Vec* rotOut, W1161c8Vec* posOut, u8 cam)
{
    W1161c8Vec scale, rot, pos;
    W1161c8Mtx work, a, b;
    f1161c8_node(func_00111e38(0), 0x4002, &a);
    a.inverse();
    a = a * *m;
    a = o->view * a;
    a.r3.x = a.r3.x * 1024.0f / a.r3.z;
    a.r3.y = a.r3.y * 1024.0f / a.r3.z;
    a.r3.z = f1161c8_fov(f1161c8_cam(cam));
    scale.x = a.r0.normalize();
    scale.y = a.r1.normalize();
    scale.z = a.r2.normalize();
    u8* p = f1161c8_camm(cam);
    b = *(W1161c8Mtx*)(p ? p + 16 : 0);
    b.inverse();
    a = b * a;
    rot.zero();
    f1161c8_euler(&a, &rot);
    rot.x = func_0017ce10(rot.x);
    rot.y = func_0017ce10(rot.y);
    rot.z = func_0017ce10(rot.z);
    pos = a.r3;
    if (scaleOut) {
        scale.w = scaleOut->w;
        *scaleOut = scale;
    }
    if (rotOut) {
        rot.w = rotOut->w;
        *rotOut = rot;
    }
    if (posOut) {
        pos.w = posOut->w;
        *posOut = pos;
    }
}
}  // namespace n001161c8

// 00116798 (was src/anon/batch_wcx2.cpp)
namespace n00116798 {
struct Cam1 {
    u8 pad[1584];
    u32 on : 1;
    u32 rest : 31;
    u8 pad2[12];
    f32 ax, ay, pad3[2];
    f32 bx, by;
    bool On() { return on; }
};
/*TARGET 00116798*/
// 00116798: keep the two (x, y) pairs inside their wrap ranges
void func_00116798(Cam1* p) asm("func_00116798");
// 00116798: keep the two (x, y) pairs inside their wrap ranges
void func_00116798(Cam1* p)
{
    if (!p->On()) return;
    if (p->ax < -400.0f && p->bx < -400.0f) {
        p->ax += 800.0f;
        p->bx += 800.0f;
    }
    if (400.0f < p->ax && 400.0f < p->bx) {
        p->ax -= 800.0f;
        p->bx -= 800.0f;
    }
    if (p->ay < -320.0f && p->by < -320.0f) {
        p->ay += 640.0f;
        p->by += 640.0f;
    }
    if (320.0f < p->ay && 320.0f < p->by) {
        p->ay -= 640.0f;
        p->by -= 640.0f;
    }
}
}  // namespace n00116798

// 001168c0 (was src/anon/batch_w41.cpp)
namespace n001168c0 {
// forward_sub24_to_1337f0
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
// 00109690: moved to src/anon/unit_001085a8.cpp

// soft-double helpers linked in the game image (float->double, double !=)
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
s32 func_003142e0(double, double) asm("func_003142e0");
/*TARGET 001168c0*/
// double_compare
void func_001168c0(u8* p) asm("func_001168c0");
// double_compare
void func_001168c0(u8* p) {
    if (func_003142e0(func_00313b80(*(f32*)(p + 0x660)), 0.0) != 0 || func_003142e0(func_00313b80(*(f32*)(p + 0x664)), 0.0) != 0)
        *(f32*)(p + 0x65c) = func_002f8ad0(*(f32*)(p + 0x660), -*(f32*)(p + 0x664));
}
}  // namespace n001168c0

// 00116938 (was src/anon/auto80_199_queue.cpp)
namespace n00116938 {
/*TARGET 00116938*/
void func_00116938(u32 param_1, f32* param_2, f32* param_3) asm("_Z13func_00116938jPfS_");
void func_00116938(u32 param_1, f32* param_2, f32* param_3) {  // float_table_lookup_b
    (void)param_1;
    s32 iVar1 = (s32)func_0010f648(6);
    Pair00116938* p = &D_00347688[iVar1];
    *param_2 = p->x;
    *param_3 = p->y;
}
}  // namespace n00116938

// 00116990 (was src/anon/auto80_199_queue.cpp)
namespace n00116990 {
/*TARGET 00116990*/
void func_00116990(u32 param_1, f32* param_2, f32* param_3) asm("_Z13func_00116990jPfS_");
void func_00116990(u32 param_1, f32* param_2, f32* param_3) {  // float_table_lookup_a
    (void)param_1;
    s32 iVar1 = (s32)func_0010f648(6);
    Pair00116990* p = &D_003476b8[iVar1];
    *param_2 = p->x;
    *param_3 = p->y;
}
}  // namespace n00116990

// 001169e8 (was src/anon/batch_wcx2.cpp)
namespace n001169e8 {
// 00292b40: moved to src/anon/unit_00292998.cpp

// --------------------
// Pick the offset position for the given mode (random for unknown modes).
struct Obj1169e8 { u8 pad[1600]; f32 dir; u8 pad2[12]; f32 x; f32 y; f32 z; };
void func_00116938(Obj1169e8* p, f32* px, f32* py) asm("func_00116938");
void func_00116990(Obj1169e8* p, f32* px, f32* py) asm("func_00116990");
f32 func_0010f660(void) asm("func_0010f660");
u32 func_0010f648(s32 n) asm("func_0010f648");
/*TARGET 001169e8*/
void func_001169e8(Obj1169e8* p, s32 mode) asm("func_001169e8");
void func_001169e8(Obj1169e8* p, s32 mode)
{
    f32 r;
    f32* px = &p->x;
    p->z = 1024.0f;
    switch (mode) {
    case 0:
        p->x = -135.0f;
        p->y = 110.0f;
    case 1:
        p->x = -260.0f;
        p->y = -180.0f;
        break;
    case 2:
        p->x = 260.0f;
        p->y = -180.0f;
        break;
    case 3:
        p->x = 260.0f;
        p->y = 180.0f;
        break;
    case 4:
        p->x = -260.0f;
        p->y = 180.0f;
        break;
    case 5:
        p->x = 0.0f;
        p->y = 0.0f;
        break;
    case 6:
        p->x = -230.0f;
        p->y = 90.0f;
        break;
    case 7:
        p->x = 138.0f;
        p->y = 106.0f;
        break;
    default:
        if (func_0010f660() < 0.5f) {
            if (p->dir < 0.0f) func_00116938(p, px, &p->y);
            else func_00116990(p, px, &p->y);
            break;
        }
        r = (func_0010f660() * 0.5f + 0.5f) * 60.0f;
        switch (func_0010f648(4)) {
        case 0:
            if (p->dir < 0.0f) {
                func_00116990(p, px, &p->y);
                p->x -= r;
            } else {
                func_00116938(p, px, &p->y);
                p->x += r;
            }
            break;
        case 1:
            if (p->dir < 0.0f) {
                func_00116990(p, px, &p->y);
                p->x -= 800.0f;
            } else {
                func_00116938(p, px, &p->y);
                p->x += 800.0f;
            }
            break;
        case 3:
            if (p->dir < 0.0f) func_00116938(p, px, &p->y);
            else func_00116990(p, px, &p->y);
            p->y -= 640.0f;
            break;
        case 2:
            if (p->dir < 0.0f) func_00116938(p, px, &p->y);
            else func_00116990(p, px, &p->y);
            p->y += 640.0f - r;
            break;
        }
        break;
    }
}
}  // namespace n001169e8

// 00116d08 (was src/anon/batch_wcx.cpp)
namespace n00116d08 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 0x001244b8: definition moved into src/anon/unit_00123990.cpp
extern f32 D_00349e10 asm("D_00349e10");
f32 func_0017ce10(f32) asm("func_0017ce10");
f32 fabsf(f32) asm("fabsf");
/*TARGET 00116d08*/
// fabsf
s32 func_00116d08(u8* p) asm("func_00116d08");
// fabsf
s32 func_00116d08(u8* p)
{
    V4 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&d), "r"(p + 1600), "r"(p + 1616) : "memory");
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
    if (!(len < *(f32*)(p + 1576) * D_00349e10)) return 0;
    f32 a = fabsf(func_0017ce10(d.w));  // fabsf
    f32 k = D_00349e10;
    if (a < *(f32*)(p + 1580) * k) return 1;
    return 0;
}
}  // namespace n00116d08

// 00116db0 (was src/anon/batch_w3804.cpp)
namespace n00116db0 {
#define E116_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct E116Vec {
    f32 x, y, z, w;
    E116Vec() {}
    E116Vec(const E116Vec& o) { E116_QCOPY(this, &o); }
    E116Vec& operator=(const E116Vec& o) { if (this != &o) E116_QCOPY(this, &o); return *this; }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct E116Mtx {
    E116Vec r0, r1, r2, r3;
    E116Mtx() {}
    E116Mtx(const E116Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    E116Mtx& operator=(const E116Mtx& o) {
        if (this != &o) {
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        }
        return *this;
    }
    // inverse of a rigid (orthonormal) transform in place: transpose + negated translation
    void invOrtho() {
        asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * matrix (each column of b transformed by this).
    E116Mtx operator*(const E116Mtx& b) const {
        E116Mtx o;
        const E116Mtx& a = *this;
        asm volatile(".set noreorder\n\t"
                     "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(&a), "r"(&b) : "memory");
        return o;
    }
    // general 4x4 inverse in place (affine: cofactors via outer products, 1/det in Q)
    void inverse() {
        asm volatile(".set noreorder\n\t"
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.wxyz $vf1, $vf1, Q\n\tvmulq.wxyz $vf2, $vf2, Q\n\tvmulq.wxyz $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    // VU0 matrix * column vector.
    E116Vec operator*(const E116Vec& v) const {
        E116Vec o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
// transform a point (w = 1) by a VU0 matrix
static inline void E116_xformPt(E116Vec* out, const E116Mtx* m, const E116Vec* v)
{
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                 : : "r"(out), "r"(m), "r"(v) : "memory");
}
struct E116Model { u8 pad[340]; s32 f340; u8 pad1[8]; u32 f352; };
struct E116Sub { u8 pad[24]; s32 f24; };
struct E116Cam { u8 pad[320]; E116Sub sub; u8 pad1[4]; u32 f352; };
struct E116Slot {
    s32 flags;
    s32 res;
    s32 handle;
    u32 f12;
    s32 f16;
    s32 f20;
    s32 node;
    s32 pad28;
    E116Vec rot;
    E116Vec pos;
};
struct E116Obj {
    u8 pad0[4];
    E116Model* model;
    u8 pad8[24];
    E116Slot slots[24];
    s32 f1568;
    s32 f1572;
};
E116Cam* func_00111e38(s32) asm("func_00111e38");
s32 func_0019ba60(E116Model*) asm("func_0019ba60");
void func_001dc920(s32) asm("func_001dc920");
void func_00117910(E116Obj*, s32) asm("func_00117910");
void func_00117aa8(E116Obj*, s32) asm("func_00117aa8");
s32 func_001dc9d0(s32) asm("func_001dc9d0");
s32 func_001dc9e0(s32) asm("func_001dc9e0");
s32 func_0016abf8(E116Model*, s32, u32, s32) asm("func_0016abf8");
u8* func_00106a60(s32) asm("func_00106a60");
E116Vec* func_001dc5f8(s32) asm("func_001dc5f8");
E116Vec* func_001dc620(s32) asm("func_001dc620");
E116Vec* func_001dc648(s32) asm("func_001dc648");
f32* func_001dc670(s32) asm("func_001dc670");
void func_0016b0e0(void*, s32, E116Mtx*) asm("func_0016b0e0");
void func_0011b6a8(E116Mtx*) asm("func_0011b6a8");
void func_0011b7b0(E116Mtx*, E116Vec*) asm("func_0011b7b0");
void func_00115c08(E116Obj*, E116Mtx*, E116Vec*, E116Vec*, E116Vec*, u8) asm("func_00115c08");
void func_001161c8(E116Obj*, E116Mtx*, E116Vec*, E116Vec*, E116Vec*, u8) asm("func_001161c8");
f32 func_00194690(E116Model*) asm("func_00194690");
void func_0018f028(s32) asm("func_0018f028");
/*TARGET 00116db0*/
void func_00116db0(E116Obj* o) asm("func_00116db0");
void func_00116db0(E116Obj* o)
{
    E116Mtx M;
    E116Mtx mtx;
    E116Mtx M2;
    E116Vec scale, rot, pos;
    E116Cam* cam = func_00111e38(0);
    for (s32 i = 0; i < 24; i++) {
        if (o->slots[i].handle) {
            if (!func_0019ba60(o->model) || (o->slots[i].flags & 0x40000000)) {
                func_001dc920(o->slots[i].handle);
                func_00117910(o, i);
                continue;
            }
            if (func_001dc9d0(o->slots[i].handle)) {
                if (o->slots[i].f20 >= 0) {
                    s32 chg = 0;
                    switch (o->slots[i].flags & 3) {
                    case 0:
                    case 1:
                        if (o->slots[i].f20 != o->model->f340) chg = 1;
                        break;
                    case 2:
                        {
                    E116Sub* sb = &cam->sub;
                    if (!(cam->f352 & 0x4000) || o->slots[i].f20 != -sb->f24) chg = 1;
                }
                        break;
                    }
                    if (chg) func_00117aa8(o, i);
                }
            } else {
                bool lp = o->slots[i].f12 & 1;
                if (lp) o->slots[i].flags |= 0x40000000;
            }
        } else if (o->slots[i].res >= 0) {
            o->slots[i].handle = func_0016abf8(o->model, o->slots[i].res, o->slots[i].f12 & ~1, o->slots[i].f16);
            if (o->slots[i].handle) o->slots[i].res = -1;
        }
        if (!o->slots[i].handle || !func_001dc9e0(o->slots[i].handle)) continue;
        if (o->slots[i].node < 0) continue;
        switch (o->slots[i].flags & 3) {
        case 0:
            break;
        case 1: {
            func_0016b0e0(o->model, o->slots[i].node, &mtx);
            pos = mtx.r3;
            if (!(o->slots[i].flags & 8) && o->slots[i].node != 0x4000) func_0016b0e0(o->model, 0x4000, &mtx);
            mtx.r3 = pos;
            func_0011b6a8(&M2);
            func_0011b7b0(&M2, &o->slots[i].rot);
            M2.r3 = o->slots[i].pos;
            M = mtx * M2;
            func_00115c08(o, &M, &scale, &rot, &pos, 1);
            *func_001dc620(o->slots[i].handle) = scale;
            *func_001dc648(o->slots[i].handle) = rot;
            *func_001dc5f8(o->slots[i].handle) = pos;
            if (o->slots[i].flags & 0x20) {
                f32* q = func_001dc670(o->slots[i].handle);
                q[3] = func_00194690(o->model);
            }
            if (o->slots[i].flags & 0x10) {
                o->slots[i].flags |= 3;
                register E116Vec* qp asm("$16");
                register s32 one asm("$4") = 1;
                asm volatile("" : "+r"(one));
                qp = &o->slots[i].pos;
                asm("" : "+r"(qp));
                u8* c = func_00106a60(one);
                E116_xformPt(qp, (E116Mtx*)(c ? c + 16 : 0), &pos);
            }
            break;
        }
        case 2: {
            register E116Vec* pp asm("$16");
            func_0016b0e0(cam, o->slots[i].node, &mtx);
            pos = mtx.r3;
            if (!(o->slots[i].flags & 8) && o->slots[i].node != 0x4000) func_0016b0e0(cam, 0x4000, &mtx);
            mtx.r3 = pos;
            pp = &o->slots[i].pos;
            asm("" : "+r"(pp));
            func_0011b6a8(&M2);
            func_0011b7b0(&M2, &o->slots[i].rot);
            M2.r3 = *pp;
            M = mtx * M2;
            func_001161c8(o, &M, &scale, &rot, &pos, 1);
            *func_001dc620(o->slots[i].handle) = scale;
            *func_001dc648(o->slots[i].handle) = rot;
            *func_001dc5f8(o->slots[i].handle) = pos;
            if (o->slots[i].flags & 0x10) {
                o->slots[i].flags |= 3;
                u8* c = func_00106a60(1);
                E116_xformPt(pp, (E116Mtx*)(c ? c + 16 : 0), &pos);
            }
            break;
        }
        case 3: {
            u8* c = func_00106a60(1);
            E116Mtx m = *(E116Mtx*)(c ? c + 16 : 0);
            m.inverse();
            E116_xformPt(&pos, &m, &o->slots[i].pos);
            *func_001dc5f8(o->slots[i].handle) = pos;
            break;
        }
        }
    }
    if (o->f1568) {
        if (!func_0019ba60(o->model) || (o->f1572 >= 0 && (o->f1572 != o->model->f340 || (o->model->f352 & 2)))) {
            func_0018f028(o->f1568);
            o->f1568 = 0;
        }
    }
}
}  // namespace n00116db0

