#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fmatrix.hpp"

// ---- 0011a260 gap: C2 copy of the ctor after it
namespace n0011a260 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_003477d8 asm("D_003477d8");
extern u8 D_00347808 asm("D_00347808");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
u32 func_0011a260(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_0011a260");
u32 func_0011a260(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_003477d8;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347808;
    *(u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 1;
    return r2;
}
}  // namespace n0011a260

// ---- 0011a2a8 from src/anon/tiny_auto80_solver.cpp
namespace n0011a2a8 {
extern u8 D_00340000 asm("D_00340000");
extern u8 D_003477d8 asm("D_003477d8");
extern u8 D_00347808 asm("D_00347808");
void func_00113628(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00113628jjjjjjjj");
u32 func_0011a2a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0011a2a8jjjjjjjj");
u32 func_0011a2a8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r16 = a0;
    u32 r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00113628)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 r15 = (u32)&D_003477d8;
    u32 r14 = (u32)&D_00340000;
    *(volatile u32*)(r16 + 16) = r15;
    r14 = (u32)&D_00347808;
    *(u32*)r16 = r14;
    *(volatile u32*)(r16 + 12) = 1;
    return r2;
}
}  // namespace n0011a2a8

// ---- 0011a2f0 from src/anon/tiny_auto80_fptr4.cpp
namespace n0011a2f0 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347808 asm("D_00347808");
u32 func_0011a2f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011a2f0jjjj");
u32 func_0011a2f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347808;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011a2f0

// ---- 0011a318 from src/anon/tiny_auto80_fptr4.cpp
namespace n0011a318 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347808 asm("D_00347808");
u32 func_0011a318(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011a318jjjj");
u32 func_0011a318(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347808;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011a318

// ---- 0011a340 from src/anon/batch_w23.cpp
namespace n0011a340 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
extern u32 D_00347808 asm("D_00347808");
void func_0011a340(void** p) asm("func_0011a340");
void func_0011a340(void** p) {
    *p = &D_00347808;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n0011a340

// ---- 0011a378 gap: script callback (table 0x3477d8), same body as 0x11a7f0
namespace n0011a378 {
void func_00188170(u32, u32) asm("func_00188170");
u32 func_0011a378(u8* a0, u8* a1, u32* a2, u32* a3, u32 a4) asm("func_0011a378");
u32 func_0011a378(u8* a0, u8* a1, u32* a2, u32* a3, u32 a4) {
    if ((a4 & 0xff) != 0) {
        *a3 = 0;
        u8* t5 = *(u8**)(a0 + 4);
        a2[0] = *(u32*)(t5 + 0x9f4);
        a2[1] = *(u32*)(t5 + 0x9f8);
        a2[2] = *(u32*)(t5 + 0x9fc);
        a2[3] = *(u32*)(t5 + 0xa00);
        a2[4] = *(u32*)(t5 + 0xa04);
        return 1;
    }

    u32 p = *(u32*)(a0 + 4);
    func_00188170(p + 0x300, *(u32*)(a1 + 0x20));
    return 1;
}
}  // namespace n0011a378

// ---- 0011a3e0 gap: vtable slot (0x347838)
namespace n0011a3e0 {
u32 func_0016ac38(u32, u32, u32, u32, u32) asm("func_0016ac38");
u32 func_0011a3e0(u32* a0) asm("func_0011a3e0");
u32 func_0011a3e0(u32* a0) {
    return func_0016ac38(a0[1], 10, 1, 0, 0);
}
}  // namespace n0011a3e0

// ---- 0011a408 from src/anon/tiny_auto80_solver.cpp
namespace n0011a408 {
u32 kn__Friend__getFlag(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z19kn__Friend__getFlagjjjjjjjj");
u32 func_00119f48(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00119f48jjjjjjjj");
u32 func_0011a408(u32) asm("_Z13func_0011a408j");
u32 func_0011a408(u32 a0) asm("_Z13func_0011a408j");
u32 func_0011a408(u32 a0) {
    u32 v0 = ((u32(*)(u32))kn__Friend__getFlag)(*(u32*)(a0 + 4));
    u32 ret = ((u32(*)(u32))func_00119f48)(v0);
    if (ret != 0) {
        return ret;
    }
    return ret;
}
}  // namespace n0011a408

// ---- 0011a430 from src/anon/batch_w10.cpp
namespace n0011a430 {
u32 kn__Friend__getFlag(void*) asm("kn__Friend__getFlag");
void func_00112730(void*, u32) asm("func_00112730");
void Peterpan_acceptNotifyPlayerTarget(void*) asm("_ZN2kn8Peterpan24acceptNotifyPlayerTargetEv");
void Peterpan_acceptNotifyPlayerTarget(void* s) {
    func_00112730(*(void**)((u8*)s + 4), kn__Friend__getFlag(*(void**)((u8*)s + 4)) | 0x200);
}
}  // namespace n0011a430

// ---- 0011a460 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n0011a460 {
u32 func_00113628(u32, u32, u32, u32) asm("_Z13func_00113628jjjj");
extern u8 D_00347848 asm("D_00347848");
u32 func_0011a460(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011a460jjjj");
u32 func_0011a460(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00113628(r4, r5, r6, r7);
    r15 = (u32)&D_00347848;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0011a460

// ---- 0011a490 from src/anon/tiny_jal_wrappers_reloc.cpp
namespace n0011a490 {
u32 func_00113628(u32, u32, u32, u32) asm("_Z13func_00113628jjjj");
extern u8 D_00347848 asm("D_00347848");
u32 func_0011a490(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011a490jjjj");
u32 func_0011a490(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00113628(r4, r5, r6, r7);
    r15 = (u32)&D_00347848;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n0011a490

// ---- 0011a4c0 from src/anon/tiny_auto80_fptr4.cpp
namespace n0011a4c0 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347848 asm("D_00347848");
u32 func_0011a4c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011a4c0jjjj");
u32 func_0011a4c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347848;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011a4c0

// ---- 0011a4e8 from src/anon/tiny_auto80_fptr4.cpp
namespace n0011a4e8 {
u32 func_00113668(u32, u32, u32, u32) asm("_Z13func_00113668jjjj");
extern u8 D_00347848 asm("D_00347848");
u32 func_0011a4e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011a4e8jjjj");
u32 func_0011a4e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347848;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00113668)(u32, u32, u32, u32) = func_00113668;
    r2 = fp_call4_00113668(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011a4e8

// ---- 0011a510 from src/anon/batch_w11.cpp
namespace n0011a510 {
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
extern u32 D_00347848 asm("D_00347848");
void func_0011a510(void** p) asm("func_0011a510");
void func_0011a510(void** p) {
    *p = &D_00347848;
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n0011a510

// ---- 0011a548 gap: follow the player target, or the attach point plus front * 200
namespace n0011a548 {
struct V {
    f32 x, y, z, w;
    V() {}
    V& operator=(const V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V operator*(const V& a, f32 k) {
    V r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline V operator+(const V& a, const V& b) {
    V r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Tgt { s32 a, b, c, d, e; };
struct Owner { u8 p0[32]; u32 flags; u8 p24[28]; V pos; };
struct Self { u8 p0[2548]; Tgt tgt; u8 pa08[344]; Owner* owner; };
void func_0011b038(Owner*) asm("func_0011b038");
void func_001112a8(Self*) asm("func_001112a8");
s32 func_00190140(Tgt*) asm("func_00190140");
V func_00190388(Tgt*) asm("func_00190388");
V* YS__OBJ__get_pos(Self*) asm("YS__OBJ__get_pos");
V YS__OBJ__get_dir(Self*) asm("YS__OBJ__get_dir");

static inline u8 valid(Tgt* t) {
    u8 ok = 0;
    if (func_00190140(t)) ok = t->a != 0;
    return ok;
}
void func_0011a548(Self* self) asm("func_0011a548");
void func_0011a548(Self* self) {
    Tgt* t = &self->tgt;
    u32 flags = self->owner->flags; if (flags & 1) {
        func_0011b038(self->owner);
        return;
    }
    func_001112a8(self);
    if (valid(t)) {
        self->owner->pos = func_00190388(t);
    } else {
        self->owner->pos = *YS__OBJ__get_pos(self) + YS__OBJ__get_dir(self) * 200.0f;
    }
}
}  // namespace n0011a548

