// Linked unit 0x002dd650-0x002ddbf0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 002dd650 (was src/anon/batch_w1530.cpp)
namespace n002dd650 {
struct W1530_E { s16 h; u8 pad[30]; };
struct W1530_T { u8 pad[8]; s32 n; u8 pad2[4]; W1530_E e[1]; };
struct W1530_B { u8 pad[0x74]; W1530_T* t[3]; u8 pad2[0x8000 - 0x80]; u8 p6c[0x6c]; u8 c6c; u8 pad3[7]; s32 v74; u8 pad4[0x18]; u8 c90; };
/*TARGET 002dd650*/
W1530_E* func_002dd650(W1530_B* b) asm("func_002dd650");
W1530_E* func_002dd650(W1530_B* b) {
    s32 idx;
    if (b->c90) idx = 2;
    else idx = b->c6c != 0;
    W1530_T* t = b->t[idx];
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (t->e[i].h >= b->v74) return &t->e[i];
    }
    return &t->e[t->n - 1];
}
}  // namespace n002dd650

// 002dd6d0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002dd6d0 {
// obj_init_field1416_bit800
u32 func_002d0ea8(u32, u32, u32, u32) asm("_Z13func_002d0ea8jjjj");
extern u8 D_00362a20 asm("D_00362a20");
/*TARGET 002dd6d0*/
// 0x002db6b0: definition moved into src/anon/unit_002da040.cpp

u32 func_002dd6d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dd6d0jjjj");
// 0x002db6b0: definition moved into src/anon/unit_002da040.cpp

u32 func_002dd6d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002d0ea8(r4, r5, r6, r7);
    r15 = (u32)&D_00362a20;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002dd6d0

// 002dd700 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n002dd700 {
// obj_init_field1416_bit800
u32 func_002d0ea8(u32, u32, u32, u32) asm("_Z13func_002d0ea8jjjj");
extern u8 D_00362a20 asm("D_00362a20");
/*TARGET 002dd700*/
u32 func_002dd700(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002dd700jjjj");
u32 func_002dd700(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_002d0ea8(r4, r5, r6, r7);
    r15 = (u32)&D_00362a20;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n002dd700

// 002dd730 (was src/anon/batch_w46.cpp)
namespace n002dd730 {
// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// 002ceb48: moved to src/taito/minigame_base.cpp (linked unit)

// ---- 002dd730
void func_001780d8(u8*) asm("func_001780d8");
void func_00198860(u8*, u32) asm("func_00198860");
void func_0017a7d8(u8*) asm("func_0017a7d8");
/*TARGET 002dd730*/
void func_002dd730(u8* p) asm("func_002dd730");
void func_002dd730(u8* p) {
    func_001780d8(p);
    func_00198860(p, 8);
    *(Vq*)(p + 3056) = *(Vq*)(p + 1344);
    func_0017a7d8(p);
    *(f32*)(p + 3072) = 1.0f;
}
}  // namespace n002dd730

// 002dd790 (was src/anon/batch_w11.cpp)
namespace n002dd790 {
// 0x002db730: definition moved into src/anon/unit_002da040.cpp

void func_002d10a0(void*) asm("func_002d10a0");
/*TARGET 002dd790*/
void func_002dd790(u8* p) asm("func_002dd790");
void func_002dd790(u8* p) {
    func_002d10a0(p);
    u8* d = p + 3056;
    u8* s = p + 1344;
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}
}  // namespace n002dd790

// 002dd7d0 (was src/anon/batch_w2484.cpp)
namespace n002dd7d0 {
typedef struct V4 { f32 x, y, z, w; } V4;
void func_001788b8(void*) asm("func_001788b8");
void func_00183768(f32, void*, void*) asm("func_00183768");
u8* func_002dc7c8(s32) asm("func_002dc7c8");
f32 func_002dc808(s32) asm("func_002dc808");
f32 fabsf(f32) asm("fabsf");
extern s32 D_00361f60 asm("D_00361f60");
/*TARGET 002dd7d0*/
// Applies a push along the owner's direction vector, then eases the value at +0xc00 within the param range.
void func_002dd7d0(u8* p) asm("func_002dd7d0");
// Applies a push along the owner's direction vector, then eases the value at +0xc00 within the param range.
void func_002dd7d0(u8* p) {
    func_001788b8(p);
    s32 id = D_00361f60;
    V4 v;
    f32 s = func_002dc808(id) * 10.0f;
    V4* dir = (V4*)(*(u8**)(p + 0xb44) + 0xa30);
    v.w = v.z = v.y = 0.0f;
    v.x = dir->x;
    func_00183768(s, p, &v);
    if (*(u32*)(*(u8**)(p + 0xb44) + 8) & 2) {
        *(u32*)(p + 0x108) |= 0x10000;
    }
    u8* prm = func_002dc7c8(id);
    f32* lo = (f32*)(func_002dc7c8(id) + 0x98);
    f32* hi = (f32*)(func_002dc7c8(id) + 0x9c);
    if (fabsf(*(f32*)(*(u8**)(p + 0xb44) + 0xa34)) < 0.1f) {
        f32 d = 1.0f - *(f32*)(p + 0xc00);
        f32 m = (fabsf(d) < *(f32*)(prm + 0x94)) ? fabsf(d) : *(f32*)(prm + 0x94);
        if (d < 0.0f) *(f32*)(p + 0xc00) = *(f32*)(p + 0xc00) - m;
        else *(f32*)(p + 0xc00) = *(f32*)(p + 0xc00) + m;
    } else {
        *(f32*)(p + 0xc00) = *(f32*)(p + 0xc00) + *(f32*)(*(u8**)(p + 0xb44) + 0xa34) * *(f32*)(prm + 0x94);
    }
    f32 c = *(f32*)(p + 0xc00);
    if (c < *lo) *(f32*)(p + 0xc00) = *lo;
    else if (*hi < c) *(f32*)(p + 0xc00) = *hi;
}
}  // namespace n002dd7d0

// 002dd968 (was src/anon/auto80_199_queue.cpp)
namespace n002dd968 {
/*TARGET 002dd968*/
// 0x002da8f0: definition moved into src/anon/unit_002da040.cpp

void func_002dd968(u32 a0) asm("_Z13func_002dd968j");
// 0x002da8f0: definition moved into src/anon/unit_002da040.cpp

void func_002dd968(u32 a0) {
    u32 scratch[8];
    func_00190128(scratch);
    func_00190878(scratch, a0, 0);
    func_001bd3e0(*(u32*)(a0 + 0xb44), 1, 565, scratch, 1, 100);
}
}  // namespace n002dd968

// 002dd9c0 (was never written: gap function)
namespace n002dd9c0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

void func_002dd9c0(u8* p) asm("func_002dd9c0");
void func_002dd9c0(u8* p) { *(u32*)(p + 264) |= 0x10000; }
}  // namespace n002dd9c0

// 002dd9d8 (was never written: gap function)
namespace n002dd9d8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

s32 func_002dd9d8(void) asm("func_002dd9d8");
s32 func_002dd9d8(void) { return 1; }
}  // namespace n002dd9d8

// 002dd9e0 (was src/anon/batch_w67.cpp)
namespace n002dd9e0 {
// Word accessed through a union: aliases everything, as the original assumes.
union Word { f32 f; u32 u; };
// 001c7f10: constructor; registers itself in a two-slot table
// 0x1c7f10: moved to src/yasui/libys/summon.cpp

void func_002cfeb0(u8*, void*, s32, s32) asm("func_002cfeb0");
// obj_init_field1416_bit800
extern u8 D_00362b68[] asm("D_00362b68");
/*TARGET 002dd9e0*/
// 002dd9e0: constructor
void func_002dd9e0(u8* o, Word* p, s32 c) asm("func_002dd9e0");
// 002dd9e0: constructor
void func_002dd9e0(u8* o, Word* p, s32 c)
{
    func_002cfeb0(o, p, 3, c);  // obj_init_field1416_bit800
    *(u8**)o = D_00362b68;
    *(f32*)(o + 2840) = 300.0f;
    switch (p->u) {
    case 1637: *(s32*)(o + 2836) = 1; break;
    case 1636: *(s32*)(o + 2836) = 2; break;
    case 1638: *(s32*)(o + 2836) = 0; break;
    case 1639: *(s32*)(o + 2836) = 3; break;
    }
}
}  // namespace n002dd9e0

// 002dda88 (was src/anon/batch_w68.cpp)
namespace n002dda88 {
/* ---- 002dda88 ---- */
void func_002cfeb0(void*, void*, u32, u32) asm("func_002cfeb0");
// obj_init_field1416_bit800
extern void* D_00362b68 asm("D_00362b68");
union U20 { u32 id; f32 f; };
/*TARGET 002dda88*/
void func_002dda88(u8* o, U20* a1, u32 a2) asm("func_002dda88");
void func_002dda88(u8* o, U20* a1, u32 a2) {
    func_002cfeb0(o, a1, 3, a2);  // obj_init_field1416_bit800
    *(u32*)o = (u32)&D_00362b68;
    *(f32*)(o + 2840) = 300.0f;
    switch (a1->id) {
    case 1636: *(s32*)(o + 2836) = 2; break;
    case 1637: *(s32*)(o + 2836) = 1; break;
    case 1638: *(s32*)(o + 2836) = 0; break;
    case 1639: *(s32*)(o + 2836) = 3; break;
    }
}
}  // namespace n002dda88

// 002ddb30 (was never written: gap function)
namespace n002ddb30 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator*=(f32 k)
    {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern u8 D_00362b68 asm("D_00362b68");
extern u8 D_00362d20[] asm("D_00362d20");
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362bf0[] asm("D_00362bf0");
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
void func_002d00a0(u8*) asm("func_002d00a0");
void func_0016bd60(u8*, s32) asm("func_0016bd60");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
u8* func_002df140(u8*) asm("func_002df140");
void func_002e5010(u8*, f32, f32) asm("func_002e5010");
void func_002e0858(u8*) asm("_ZN2Ti12MGJumpPlayer19ready_jump_reactionEv");
u8* config(u8*) asm("_ZN2Ti6MGJump6configEv");
void* func_0016b740(s32) asm("func_0016b740");
void func_002e7568(void*, s32, void*, f32) asm("func_002e7568");
void func_002cebc0(u8*) asm("func_002cebc0");
void func_00199718(u8*, s32, s32) asm("func_00199718");
void func_00195750(void) asm("func_00195750");
void func_00104f58(u8*, s32, s32, s32, s32) asm("func_00104f58");
u32 init(u32, u32, u32, u32) asm("_Z16wtarget_002e1878jjjj");

struct C { void* vt; s32 f4; s32 f8; f32 f12; f32 f16; f32 f20; u8 pad[32]; s32 f56; };
struct J { u8 pad[49]; u8 b49; u8 pad2[10]; f32 f60; f32 f64; f32 f68; };
struct K { void** vt; u8 pad[80]; u8 b84; u8 pad2[7]; f32 f92; };
void func_002d0070(u8*) asm("func_002d0070");

u32 func_002ddb30(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002ddb30");
u32 func_002ddb30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362b68;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002ddb30

// 002ddb58 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002ddb58 {
u32 func_002cff98(u32, u32, u32, u32) asm("_Z13func_002cff98jjjj");
extern u8 D_00362b68 asm("D_00362b68");
/*TARGET 002ddb58*/
// 0x002db708: definition moved into src/anon/unit_002da040.cpp

u32 func_002ddb58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ddb58jjjj");
// 0x002db708: definition moved into src/anon/unit_002da040.cpp

u32 func_002ddb58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00362b68;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_002cff98)(u32, u32, u32, u32) = func_002cff98;
    r2 = fp_call4_002cff98(r4, r5, r6, r7);
    return r2;
}
}  // namespace n002ddb58

// 002ddb80 (was src/anon/batch_w12.cpp)
namespace n002ddb80 {
void func_00105110(void*) asm("func_00105110");
void func_002cff98(void*) asm("func_002cff98");
extern u8 D_00362b68 asm("D_00362b68");
/*TARGET 002ddb80*/
// 0x002cb708: definition moved into src/taito/path.cpp

// Deleting destructor: reset vtable, run base dtor, free.
void func_002ddb80(void** p) asm("func_002ddb80");
// 0x002cb708: definition moved into src/taito/path.cpp

// Deleting destructor: reset vtable, run base dtor, free.
void func_002ddb80(void** p) {
    *p = &D_00362b68;
    func_002cff98(p);
    func_00105110(p);
}
}  // namespace n002ddb80

// 002ddbb8 (was src/anon/batch_w5.cpp)
namespace n002ddbb8 {
// 0x0029e148: definition moved into src/anon/unit_0029d008.cpp

struct S2dd { u8 pad[0x12]; u16 flags; };
/*TARGET 002ddbb8*/
u32 func_002ddbb8(u8* p) asm("func_002ddbb8");
u32 func_002ddbb8(u8* p) {  // get_bit0_of_field2808
    S2dd* s = *(S2dd**)(p + 0xaf8);
    if (s) return (s->flags & 1) != 0;
    return 0;
}
}  // namespace n002ddbb8

// 002ddbd8 (was src/anon/tiny_wrappers_more.cpp)
namespace n002ddbd8 {
u32 Ti_MGObj_OVR_initialize(u32, u32, u32, u32) asm("_ZN2Ti5MGObj15_OVR_initializeEv");
/*TARGET 002ddbd8*/
// 0x002dd1d0: definition moved into src/anon/unit_002da040.cpp

u32 func_002ddbd8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002ddbd8jjjj");
// 0x002dd1d0: definition moved into src/anon/unit_002da040.cpp

u32 func_002ddbd8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return Ti_MGObj_OVR_initialize(a0, a1, a2, a3);
}
}  // namespace n002ddbd8

