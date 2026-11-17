// Linked unit 0x0023e5d0-0x0023f340: Tz::MenuObj, Tz::Layout (gap functions written here).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 0023e5d0 (was src/anon/auto80_199_queue.cpp)
namespace n0023e5d0 {
// 0x0011ea98: definition moved into src/anon/unit_0011c128.cpp

void func_0011eb08(u32 a0, u32 a1) asm("_Z13func_0011eb08jj");
/*TARGET 0023e5d0*/
void func_0023e5d0(void* a0, u32 a1, void* a2) asm("_Z13func_0023e5d0PvjS_");
void func_0023e5d0(void* a0, u32 a1, void* a2) {
    u8* s1;
    u8* s0;
    u8 idx;

    s1 = (u8*)a0;
    a1 += (u32)a0;
    idx = *(u8*)(a1 + 0xb64);
    s0 = s1 + ((u32)idx * 0x140) + 0x660;

    *(u32*)(s0 + 0x74) = (u32)a2;
    {
        f32 (*vf)(void*);
        vf = *(f32 (**)(void*))(*(u32*)a2 + 0x1c);
        *(volatile f32*)(s0 + 0x12c) = vf(a2);
    }
    {
        void* obj;
        f32 (*vf)(void*);
        obj = (void*)*(volatile u32*)(s0 + 0x74);
        vf = *(f32 (**)(void*))(*(u32*)obj + 0x1c);
        *(f32*)(s0 + 0x130) = vf(obj);
    }

    *(f32*)(s0 + 0x134) = func_0023e700(s1);
    *(u8*)(s0 + 0x13c) = 1;
    *(u32*)(s0 + 0x128) = 0;

    return func_0011eb08(*(u32*)(s0 + 0x30), 10);
}
}  // namespace n0023e5d0

// 0023e660 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023e660 {
u32 func_0011eb08(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0011eb08jjjjjjjj");
/*TARGET 0023e660*/
u32 func_0023e660(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023e660jjjjjjjj");
u32 func_0023e660(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 += a0;
    u32 stride = 320;
    u32 idx = *(u8*)(a1 + 2916);
    idx *= stride;
    a1 = a2;
    a0 += idx;
    a0 = *(u32*)(a0 + 1680);
    return func_0011eb08(a0, a1, a2, a3, a4, a5, a6, a7);
}
}  // namespace n0023e660

// 0023e690 (was src/tozawa/menu_obj.cpp)
namespace Tz { // method 0023e690
u32 func_001a9458(...) asm("func_001a9458");
/*TARGET 0023e690*/
void MenuObj::SetAction(s32 a1, s32 a2, s32 a3) {
    u8* s1;
    u8 idx;

    a1 += (s32)(u32)this;
    idx = *(u8*)((u32)a1 + 0xb64);
    s1 = (u8*)this + ((u32)idx * 0x140) + 0x660;

    *(u32*)(s1 + 0x78) = func_001a9458(*(u32*)(s1 + 0x70), (u32)a2, *(u32*)(s1 + 0x124));
    if (a3 >= 0) {
        *(u32*)(s1 + 0x7c) = func_001a9458(*(u32*)(s1 + 0x70), (u32)a3, *(u32*)(s1 + 0x124));
    }
}
}  // Tz

// 0023e700 (was src/anon/batch_w204.cpp)
namespace n0023e700 {
// 0x0014f030: definition moved into src/anon/unit_0014ecb8.cpp
extern int func_001064a8(int) asm("func_001064a8");
/*TARGET 0023e700*/
// int_to_float_scaled
float func_0023e700(void) asm("func_0023e700");
// int_to_float_scaled
float func_0023e700(void) {
    return (float)(func_001064a8(20) + 10) * 60.0f;
}
}  // namespace n0023e700

// 0023e738 (was src/anon/batch_w8.cpp)
namespace n0023e738 {
// 0x002345c0: definition moved into src/anon/unit_002335e8.cpp

struct P23 { s16 a; s16 pad[3]; s16 b; };
/*TARGET 0023e738*/
void func_0023e738(u8* p, u32 i, s16 a, s16 b) asm("func_0023e738");
void func_0023e738(u8* p, u32 i, s16 a, s16 b) {  // store_2halfwords_2928
    u8* q = (u8*)(i * 2) + (u32)p;
    P23* r = (P23*)(q + 2928);
    r->a = a;
    r->b = b;
}
}  // namespace n0023e738

// 0023e760 (was gap)
namespace n0023e760 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
u8* func_0023e760(u8* d, u8* p, s32 i) asm("func_0023e760");
u8* func_0023e760(u8* d, u8* p, s32 i) {
    u8* s = p + *(u8*)(i + (u32)p + 2916) * 320 + 1648;
    QCOPY(d, s);
    return d;
}
}  // namespace n0023e760

// 0023e788 (was src/anon/batch_w9.cpp)
namespace n0023e788 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
/*TARGET 0023e788*/
// 0x00234670: definition moved into src/anon/unit_002335e8.cpp

u8* func_0023e788(u8* d, u8* p, s32 i) asm("func_0023e788");
// 0x00234670: definition moved into src/anon/unit_002335e8.cpp

u8* func_0023e788(u8* d, u8* p, s32 i) {
    u8* s = p + *(u8*)(i + (u32)p + 2916) * 320 + 1632;
    QCOPY(d, s);
    return d;
}
}  // namespace n0023e788

// 0023e7b0 (was gap)
namespace n0023e7b0 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
u8* func_0023e7b0(u8* d, u8* p, s32 i) asm("func_0023e7b0");
u8* func_0023e7b0(u8* d, u8* p, s32 i) {
    u8* s = p + *(u8*)(i + (u32)p + 2916) * 320 + 1664;
    QCOPY(d, s);
    return d;
}
struct __attribute__((aligned(16))) FV { f32 x, y, z; u32 w;
    inline FV& operator=(const FV& rhs) {
        if (this == &rhs) return *this;
        asm("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(this), "r"(&rhs) : "t0");
        return *this;
    }
};
void func_0023e7d8(u8* p, s32 i, f32 x, f32 y, f32 z) asm("func_0023e7d8");
void func_0023e7d8(u8* p, s32 i, f32 x, f32 y, f32 z) {
    FV* d = (FV*)(p + *(u8*)(i + (u32)p + 2916) * 320 + 1648);
    FV v;
    v.x = x; v.y = y; v.z = z; v.w = 0;
    *d = v;
}
void func_0023e818(u8* p, s32 a1, f32 a2) asm("func_0023e818");
void func_0023e818(u8* p, s32 a1, f32 a2) {
    u32 a0 = (u32)p;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1648) = a2;
}
void func_0023e838(u8* p, s32 a1, f32 a2) asm("func_0023e838");
void func_0023e838(u8* p, s32 a1, f32 a2) {
    u32 a0 = (u32)p;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1652) = a2;
}
}  // namespace n0023e7b0

// 0023e858 (was src/tozawa/menu_obj.cpp)
namespace Tz { // method 0023e858
/*TARGET 0023e858*/
void MenuObj::SetTransZ(s32 a1, f32 a2) {
    u32 a0 = (u32)this;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1656) = a2;
}
}  // Tz

// 0023e878 (was gap)
namespace n0023e878 {
struct __attribute__((aligned(16))) FV { f32 x, y, z; u32 w;
    inline FV& operator=(const FV& rhs) {
        if (this == &rhs) return *this;
        asm("lq $8, 0(%1);" "sq $8, 0(%0);" : : "r"(this), "r"(&rhs) : "t0");
        return *this;
    }
};
void func_0023e878(u8* p, s32 i, f32 x, f32 y, f32 z) asm("func_0023e878");
void func_0023e878(u8* p, s32 i, f32 x, f32 y, f32 z) {
    FV* d = (FV*)(p + *(u8*)(i + (u32)p + 2916) * 320 + 1632);
    FV v;
    v.x = x; v.y = y; v.z = z; v.w = 0;
    *d = v;
}
}  // namespace n0023e878

// 0023e8b8 (was src/tozawa/menu_obj.cpp)
namespace Tz { // method 0023e8b8
/*TARGET 0023e8b8*/
void MenuObj::SetRotX(s32 a1, f32 a2) {
    u32 a0 = (u32)this;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1632) = a2;
}
}  // Tz

// 0023e8d8 (was src/tozawa/menu_obj.cpp)
namespace Tz { // method 0023e8d8
/*TARGET 0023e8d8*/
void MenuObj::SetRotY(s32 a1, f32 a2) {
    u32 a0 = (u32)this;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1636) = a2;
}
}  // Tz

// 0023e8f8 (was gap)
namespace n0023e8f8 {
void func_0023e8f8(u8* p, s32 a1, f32 a2) asm("func_0023e8f8");
void func_0023e8f8(u8* p, s32 a1, f32 a2) {
    u32 a0 = (u32)p;
    a1 += (s32)a0;
    u32 t7 = *(u8*)((u32)a1 + 2916);
    t7 = t7 * 320;
    t7 += a0;
    *(f32*)(t7 + 1640) = a2;
}
}  // namespace n0023e8f8

// 0023e918 (was src/anon/batch_w17.cpp)
namespace n0023e918 {
/*TARGET 0023e918*/
// 0x00225690: definition moved into src/anon/unit_00224780.cpp

// Store the vector (x, y, z, 0) into slot p[2916 + i] of the 320-byte table at p + 1664.
void func_0023e918(u8* p, s32 i, f32 x, f32 y, f32 z) asm("func_0023e918");
// 0x00225690: definition moved into src/anon/unit_00224780.cpp

// Store the vector (x, y, z, 0) into slot p[2916 + i] of the 320-byte table at p + 1664.
void func_0023e918(u8* p, s32 i, f32 x, f32 y, f32 z) {
    u8* d = p + *(u8*)(i + (u32)p + 2916) * 320 + 1664;
    struct { f32 f[3]; u32 w; } __attribute__((aligned(16))) v;
    v.f[0] = x; v.f[1] = y; v.f[2] = z; v.w = 0;
    if (d != (u8*)&v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(&v) : "$8", "memory");
}
}  // namespace n0023e918

// 0023e958 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023e958 {
/*TARGET 0023e958*/
void func_0023e958(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023e958jjjjjjjj");
void func_0023e958(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 += a0;
    u32 stride = 320;
    u32 idx = *(u8*)(a1 + 2916);
    idx *= stride;
    a0 += idx;
    a0 += 1632;
    *(u8*)(a0 + 312) = a2;
    *(u8*)(a0 + 313) = a3;
    *(u8*)(a0 + 314) = a4;
    if ((s32)a5 >= 0) {
        *(u8*)(a0 + 315) = a5;
    }
}
}  // namespace n0023e958

// 0023e990 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023e990 {
/*TARGET 0023e990*/
void func_0023e990(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023e990jjjjjjjj");
void func_0023e990(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 += a0;
    u32 stride = 320;
    u32 idx = *(u8*)(a1 + 2916);
    idx *= stride;
    idx += a0;
    idx += 1632;
    *(u8*)(idx + 315) = a2;
}
}  // namespace n0023e990

// 0023e9b0 (was src/tozawa/menu_obj.cpp)
namespace Tz { // method 0023e9b0
/*TARGET 0023e9b0*/
void MenuObj::SetSyncLayMsg(s32 a1, LayMsg* a2) {
    u32 a0 = (u32)this;
    a1 = (s32)((u32)a1 << 2);
    a1 = (s32)((u32)a1 + a0);
    *(u32*)((u32)a1 + 5296) = (u32)a2;
    *(u32*)((u32)a1 + 5312) = 0u;
}
}  // Tz

// 0023e9c8 (was src/tozawa/menu_obj.cpp)
namespace Tz { // method 0023e9c8
/*TARGET 0023e9c8*/
void MenuObj::SetSyncSprite(s32 a1, dk::Sprite* a2) {
    u32 a0 = (u32)this;
    a1 = (s32)((u32)a1 << 2);
    a1 = (s32)((u32)a1 + a0);
    *(u32*)((u32)a1 + 5312) = (u32)a2;
    *(u32*)((u32)a1 + 5296) = 0u;
}
}  // Tz

// 0023e9e0 (was src/anon/tiny_leaf.cpp)
namespace n0023e9e0 {
/*TARGET 0023e9e0*/
void func_0023e9e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023e9e0jjjj");
void func_0023e9e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r4);
    *(u32*)((u32)r5 + (s32)(5328)) = r6;
}
}  // namespace n0023e9e0

// 0023e9f0 (was src/anon/batch_w86.cpp)
namespace n0023e9f0 {
struct Obj { u8 p0[2924]; s32 n; u8 p2928[2368]; u8* a[4]; u8* b[4]; u8* c[4]; };
u32 func_0023f6f8(u8*) asm("func_0023f6f8");
s32 func_00139d78(u8*) asm("func_00139d78");
u32 func_0023a918(u8*) asm("func_0023a918");
void func_0023e990(Obj*, s32, u32) asm("func_0023e990");
/*TARGET 0023e9f0*/
void func_0023e9f0(Obj* o) asm("func_0023e9f0");
void func_0023e9f0(Obj* o)
{
    for (s32 i = 0; i < o->n; i++) {
        u32 v;
        if (!o->a[i]) {
            if (!o->b[i]) continue;
            if (o->c[i] && func_00139d78(o->c[i])) v = func_0023a918(o->c[i] + 24) >> 24;
            else if (func_00139d78(o->b[i])) v = func_0023a918(o->b[i] + 24) >> 24;
            else v = 0;
        } else v = func_0023f6f8(o->a[i]);
        func_0023e990(o, i, v);
    }
}
}  // namespace n0023e9f0

// 0023eac0 (was src/anon/tiny_more2.cpp)
namespace n0023eac0 {
/*TARGET 0023eac0*/
void func_0023eac0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0023eac0jjjj");
void func_0023eac0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 p=a1+a0; *(u8*)((u32)p + (2912))=(u8)a2; }
}  // namespace n0023eac0

// 0023ead0 (was gap)
namespace n0023ead0 {
u8 func_0023ead0(u8* p, s32 i) asm("func_0023ead0");
u8 func_0023ead0(u8* p, s32 i) { return *(u8*)(i + (u32)p + 2912); }
}  // namespace n0023ead0

// 0023eae0 (was src/anon/auto80_199_queue.cpp)
namespace n0023eae0 {
/*TARGET 0023eae0*/
void func_0023eae0(void* a0, u32 a1, s32 a2, s32 a3) asm("_Z13func_0023eae0Pvjii");
void func_0023eae0(void* a0, u32 a1, s32 a2, s32 a3) {
    u8* s1;
    u8 idx;
    s32 s0;
    s32 s2;

    a1 += (u32)a0;
    s0 = a2;
    s2 = a3;

    idx = *(u8*)(a1 + 0xb64);
    s1 = (u8*)a0 + ((u32)idx * 0x140) + 0x660;

    if (a2 < a3) {
        do {
            func_0011c7f8(*(u32*)(s1 + 0x30), s0);
            s0 += 1;
        } while (s0 < s2);
    }
}
}  // namespace n0023eae0

// 0023eb50 (was src/anon/auto80_199_queue.cpp)
namespace n0023eb50 {
/*TARGET 0023eb50*/
void func_0023eb50(void* a0, u32 a1, s32 a2) asm("_Z13func_0023eb50Pvji");
void func_0023eb50(void* a0, u32 a1, s32 a2) {
    u8* s2;
    s32 s0;
    s32 s1;
    u32 t7;

    a1 += (u32)a0;
    s1 = a2;

    s2 = (u8*)a0 + ((u32)*(u8*)(a1 + 0xb64) * 0x140) + 0x660;
    if (a2 != 0) {
        s0 = 0;
        do {
            t7 = (u32)(s1 >> s0);
            t7 &= 1u;
            if ((u8)t7 != 0) {
                func_0011c7f8(*(u32*)(s2 + 0x30), s0);
            }
            s0 += 1;
        } while (s0 < 32);
    }
}
}  // namespace n0023eb50

// 0023ebd0 (was src/anon/tiny.cpp)
namespace n0023ebd0 {
/*TARGET 0023ebd0*/
void func_0023ebd0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023ebd0jjjj");
void func_0023ebd0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a2;
    (void)a3;
    u32 v = a1 & 0x00ffu;
    *(u8*)((u32)a0 + (5345)) = (u8)v;
}
}  // namespace n0023ebd0

// 0023ebe0 (was src/anon/tiny_leaf.cpp)
namespace n0023ebe0 {
/*TARGET 0023ebe0*/
void func_0023ebe0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023ebe0jjjj");
void func_0023ebe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r11 = 0u, r12 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r5 = (u32)(r5 + r4);
    r6 = (u32)(r6 + r4);
    r14 = (u32)((s32)r5 + (2912));
    r12 = (u32)(*(u8*)((u32)r6 + (s32)(2912)));
    r13 = (u32)((s32)r6 + (2912));
    r11 = (u32)(*(u8*)((u32)r14 + (s32)(4)));
    r15 = (u32)(*(u8*)((u32)r13 + (s32)(4)));
    *(u8*)((u32)r14 + (s32)(4)) = (u8)r15;
    *(u8*)((u32)r13 + (s32)(4)) = (u8)r11;
    r11 = (u32)(*(u8*)((u32)r5 + (s32)(2912)));
    *(u8*)((u32)r5 + (s32)(2912)) = (u8)r12;
    *(u8*)((u32)r6 + (s32)(2912)) = (u8)r11;
}
}  // namespace n0023ebe0

// 0023ec18 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023ec18 {
/*TARGET 0023ec18*/
u32 func_0023ec18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023ec18jjjjjjjj");
u32 func_0023ec18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    a1 = (u32)(a1 + a0);
    u32 stride = 320u;
    u32 idx = *(u8*)((u32)a1 + 2916);
    idx = (u32)(idx * stride);
    a0 = (u32)(a0 + idx);
    return *(u8*)((u32)a0 + 1948);
}
}  // namespace n0023ec18

// 0023ec38 (was src/anon/tiny_leaf.cpp)
namespace n0023ec38 {
/*TARGET 0023ec38*/
void func_0023ec38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023ec38jjjj");
void func_0023ec38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3;
    r5 = ((u32)0u < (u32)r5);
    *(u8*)((u32)r4 + (s32)(5346)) = (u8)r5;
}
}  // namespace n0023ec38

// 0023ec48 (was src/anon/batch_w68.cpp)
namespace n0023ec48 {
// 0x0022e288: definition moved into src/anon/unit_0022d358.cpp

/* ---- 0023ec48: out = obj->mtx(+128) * m (VU0) ---- */
void func_0011d6c0(u32, u32, f32*) asm("func_0011d6c0");
/*TARGET 0023ec48*/
f32* func_0023ec48(f32* out, u8* obj, u32 a2) asm("func_0023ec48");
f32* func_0023ec48(f32* out, u8* obj, u32 a2) {
    f32 m[16] __attribute__((aligned(16)));
    u8* w = obj + 128;
    func_0011d6c0(*(u32*)(obj + 48), a2, m);
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(out), "r"(w), "r"(m) : "memory");
    return out;
}
}  // namespace n0023ec48

// 0023ed00 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023ed00 {
extern u8  D_0035eb80 asm("D_0035eb80");
extern u8  D_0035eb81 asm("D_0035eb81");
void func_00167fc8(...) asm("func_00167fc8");
/*TARGET 0023ed00*/
void func_0023ed00() asm("_Z13func_0023ed00v");
void func_0023ed00() {
    if (D_0035eb81 != 0) {
        func_00167fc8();
        D_0035eb80 = 1;
    }
}
}  // namespace n0023ed00

// 0023ed38 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023ed38 {
extern u8  D_0035eb80 asm("D_0035eb80");
extern u8  D_0035eb81 asm("D_0035eb81");
void func_00168008(...) asm("func_00168008");
void func_0023ed90(...) asm("func_0023ed90");
/*TARGET 0023ed38*/
void func_0023ed38() asm("_Z13func_0023ed38v");
void func_0023ed38() {
    if (D_0035eb81 == 0) {
        func_0023ed90();  // set_global_byte1
    }
    func_00168008();
    D_0035eb80 = 0;
}
}  // namespace n0023ed38

// 0023ed78 (was gap)
namespace n0023ed78 {
extern u8 D_0035eb80 asm("D_0035eb80");
extern u8 D_0035eb81 asm("D_0035eb81");
void func_0023ed78(void) asm("func_0023ed78");
void func_0023ed78(void) { D_0035eb80 = 0; D_0035eb81 = 1; }
}  // namespace n0023ed78

// 0023ed90 (was src/anon/tiny.cpp)
namespace n0023ed90 {
extern u32 D_0035eb81 asm("D_0035eb81");
/*TARGET 0023ed90*/
void func_0023ed90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023ed90jjjj");
void func_0023ed90(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_global_byte1
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035eb81 = (u8)v;
}
}  // namespace n0023ed90

// 0023eda0 (was gap)
namespace n0023eda0 {
extern u8 D_0035eb81 asm("D_0035eb81");
void func_0023eda0(void) asm("func_0023eda0");
void func_0023eda0(void) { D_0035eb81 = 0; }
}  // namespace n0023eda0

// 0023edb0 (was src/anon/batch_w15.cpp)
namespace n0023edb0 {
// 0x002374c8: definition moved into src/anon/unit_00237068.cpp

extern u32 D_0035eb88 asm("D_0035eb88");
extern u32 D_0035eb8c asm("D_0035eb8c");
extern u8 D_0035eb84 asm("D_0035eb84");
/*TARGET 0023edb0*/
void func_0023edb0(u32 x) asm("func_0023edb0");
void func_0023edb0(u32 x) {
    u32 cur = D_0035eb88;
    if (cur != x) {
        if (cur) D_0035eb8c = cur;
        D_0035eb88 = x;
        return;
    }
    D_0035eb84++;
}
}  // namespace n0023edb0

// 0023ede8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023ede8 {
extern u8  D_0035eb84 asm("D_0035eb84");
extern u32 D_0035eb88 asm("D_0035eb88");
extern u32 D_0035eb8c asm("D_0035eb8c");
/*TARGET 0023ede8*/
void func_0023ede8() asm("_Z13func_0023ede8v");
void func_0023ede8() {
    u32 t7 = D_0035eb84;
    u32 t6 = t7 - 1;
    t7 = (u32)((s32)(t7 << 24) >> 24);
    if (t7 != 0) {
        D_0035eb84 = (u8)t6;
        return;
    }

    u32 v = D_0035eb8c;
    if (v != 0) {
        D_0035eb88 = v;
    } else {
        D_0035eb88 = 0;
    }
    D_0035eb8c = 0;
}
}  // namespace n0023ede8

// 0023ee30 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023ee30 {
extern u32 D_0035eb88 asm("D_0035eb88");
/*TARGET 0023ee30*/
u32 func_0023ee30(u32 a0) asm("_Z13func_0023ee30j");
u32 func_0023ee30(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    a0 = D_0035eb88;
    u32 t7 = *(u32*)a0;
    u32 v0 = *(u32*)t7;
    return ((u32(*)(u32, u32, u32))v0)(a0, a1, a2);
}
}  // namespace n0023ee30

// 0023ee68 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023ee68 {
void func_0023ee68(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0023ee68jjjjjjjj");
/*TARGET 0023ee68*/
void func_0023ee68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023ee68jjjjjjjj");
void func_0023ee68(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    if (a0 != 0) {
        u32 base = 0x0036u << 16;
        u32 obj = *(u32*)((u32)base + (s32)-5240);
        void (**vt)() = *(void (***)())obj;
        ((void (*)(u32, u32, u32, u32, u32, u32, u32, u32))vt[1])(obj, a0, a2, a3, a4, a5, a6, a7);
    }
}
}  // namespace n0023ee68

// 0023eea0 (was src/anon/batch_wcx.cpp)
namespace n0023eea0 {
// 0x0022f308: definition moved into src/anon/unit_0022d358.cpp
extern u32 D_0035eb88 asm("D_0035eb88");
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
void func_00236a58(u8*, u32, u32) asm("func_00236a58");
void func_0023c100(u8*, u32, u8*, u32) asm("func_0023c100");
void func_0023f070(u8*, u32, s32) asm("func_0023f070");
void func_0023f168(u8*) asm("func_0023f168");
/*TARGET 0023eea0*/
void func_0023eea0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_0023eea0");
void func_0023eea0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    func_001391c8(p, a, e);
    u8* q = p + 24;
    func_00236a58(q, c, D_0035eb88);
    func_0023c100(p + 48, b, q, D_0035eb88);
    *(s32*)(p + 152) = -10;
    *(s32*)(p + 156) = -10;
    func_0023f070(p, d, -1);
    p[148] = 0;
    func_0023f168(p);
}
}  // namespace n0023eea0

// 0023ef50 (was src/anon/batch_w1517.cpp)
namespace n0023ef50 {
char* GetImage_w1517(void* t, s32 i) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
struct ImgSub_w1517 { u8 pad[0x28]; void* img; char* Get(s32 i) { return GetImage_w1517(img, i); } };
struct T_0023ef50 { u8 pad[0x28]; s32 n; u8 p2[4]; ImgSub_w1517 sub; };
/*TARGET 0023ef50*/
void func_0023ef50(T_0023ef50* a0) asm("func_0023ef50");
void func_0023ef50(T_0023ef50* a0) {  // list_enable_all
    s32 n = a0->n;
    for (s32 i = 0; i < n; i++) {
        a0->sub.Get(i)[400] = 1;
    }
}
}  // namespace n0023ef50

// 0023efb8 (was src/anon/batch_wcx.cpp)
namespace n0023efb8 {
void func_0023f168(u8*) asm("func_0023f168");
void func_0023ca80(u8*) asm("func_0023ca80");
s32 func_0023c900(u8*) asm("func_0023c900");
void func_0023f108(u8*) asm("func_0023f108");
typedef void (*VFn)(u8*);
/*TARGET 0023efb8*/
void func_0023efb8(u8* p) asm("func_0023efb8");
void func_0023efb8(u8* p)
{
    func_0023f168(p);
    u8* q = p + 48;
    func_0023ca80(q);
    if (p[148]) p[148] = 0;
    if (func_0023c900(q)) return;
    if (*(s32*)(p + 144) != -1) {
        func_0023f108(p);
        func_0023f168(p);
        func_0023ca80(q);
        p[148] = 1;
    } else {
        (*(VFn*)(*(u8**)p + 20))(p);
    }
}
}  // namespace n0023efb8

// 0023f058 (was gap)
namespace n0023f058 {
void func_0023cc18(u8* p) asm("func_0023cc18");
void func_0023f058(u8* p) asm("func_0023f058");
void func_0023f058(u8* p) { func_0023cc18(p + 48); }
}  // namespace n0023f058

// 0023f070 (was src/anon/batch_w34.cpp)
namespace n0023f070 {
void Layout_setNum(void*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
// vu_store_w_splat
s32 func_00139d78(void*) asm("func_00139d78");
void func_0023f0c8(void*, s32) asm("func_0023f0c8");
/*TARGET 0023f070*/
// 0x002342f0: definition moved into src/anon/unit_002335e8.cpp

void Layout_setNum(void* l, s32 n, s32 m) asm("_ZN2Tz6Layout6setNumEii");
// 0x002342f0: definition moved into src/anon/unit_002335e8.cpp

void Layout_setNum(void* l, s32 n, s32 m) {
    func_00139d78(l);
    *(s32*)((u8*)l + 140) = n;
    *(s32*)((u8*)l + 152) = n;
    func_0023f0c8(l, m);
}
}  // namespace n0023f070

// 0023f0c0 (was src/tozawa/layout.cpp)
namespace Tz { // method 0023f0c0
/*TARGET 0023f0c0*/
s32 Layout::getNum() { return reinterpret_cast<LayoutLayout*>(this)->num; }
}  // Tz

// 0023f0c8 (was src/anon/batch_w16.cpp)
namespace n0023f0c8 {
u32 func_00139d78(void*) asm("func_00139d78");
/*TARGET 0023f0c8*/
// 0x00237640: definition moved into src/anon/unit_00237068.cpp

void func_0023f0c8(u8* p, u32 v) asm("func_0023f0c8");
// 0x00237640: definition moved into src/anon/unit_00237068.cpp

void func_0023f0c8(u8* p, u32 v) {
    func_00139d78(p);
    *(u32*)(p + 144) = v;
}
}  // namespace n0023f0c8

// 0023f100 (was src/tozawa/layout.cpp)
namespace Tz { // method 0023f100
/*TARGET 0023f100*/
s32 Layout::getNextNum() { return reinterpret_cast<LayoutLayout*>(this)->nextNum; }
}  // Tz

// 0023f108 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0023f108 {
u32 Tz_Layout_setNum(u32, u32, u32, u32) asm("_ZN2Tz6Layout6setNumEii");
/*TARGET 0023f108*/
u32 func_0023f108(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f108jjjj");
u32 func_0023f108(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (-1));
    r16 = r4;
    r5 = *(u32*)((u32)r4 + (s32)(144));
    r2 = Tz_Layout_setNum(r4, r5, r6, r7);
    r15 = (u32)((s32)0u + (1));
    *(u8*)((u32)r16 + (s32)(148)) = (u8)r15;
    return r2;
}
}  // namespace n0023f108

// 0023f140 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0023f140 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0023f140*/
u32 func_0023f140(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f140jjjj");
u32 func_0023f140(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00139d78(r4, r5, r6, r7);
    r2 = (u32)(*(u8*)((u32)r16 + (s32)(148)));
    return r2;
}
}  // namespace n0023f140

// 0023f168 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023f168 {
u32 func_0023c6f8(...) asm("func_0023c6f8");
/*TARGET 0023f168*/
void func_0023f168(u32 a0) asm("_Z13func_0023f168j");
void func_0023f168(u32 a0) {
    s32 s1 = -10;
    if (*(s32*)(a0 + 152) != s1) {
        func_0023c6f8(a0 + 48, *(u32*)(a0 + 140));
        *(s32*)(a0 + 152) = s1;
        *(u8*)(a0 + 148) = 0;
    }
}
}  // namespace n0023f168

// 0023f1b0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0023f1b0 {
u32 func_00139d78(u32, u32, u32, u32) asm("_Z13func_00139d78jjjj");
/*TARGET 0023f1b0*/
u32 func_0023f1b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023f1b0jjjj");
u32 func_0023f1b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00139d78(r4, r5, r6, r7);
    r16 = (u32)((s32)r16 + (48));
    r2 = r16;
    return r2;
}
}  // namespace n0023f1b0

// 0023f1e0 (was src/anon/batch_wcx2.cpp)
namespace n0023f1e0 {
u32 func_0023aa78(u8*) asm("func_0023aa78");
// 0x002395b8: definition moved into src/anon/unit_002384f8.cpp

struct Snd23 {
    u8 pad[24];
    u32 bank;
    u32 voice;
    u32 f32_;
    s32 f36;
    u8 pad2[4];
    s16 ids[3];
    s16 sel[3];
    s16 cur;
    u8 pad3[2];
    u32 color;
    s32 len;
    u32 f68;
};
void func_001391c8(Snd23*, u32, u32) asm("func_001391c8");
void func_0023f778(Snd23*, u32) asm("func_0023f778");
// copy_3halfwords_44
void func_0023f7a8(Snd23*, u32) asm("func_0023f7a8");
// copy_3halfwords_50
u8* func_0023f1b0(u32) asm("func_0023f1b0");
u32 func_0023c3e0(u8*, s16, s32) asm("func_0023c3e0");
void func_0023f5b8(Snd23*, u32, u32) asm("func_0023f5b8");
s32 func_0023aa58(u32) asm("func_0023aa58");
void func_0023f6c0(Snd23*, s32) asm("func_0023f6c0");
void func_0023f688(Snd23*, s32) asm("func_0023f688");
void func_0023f740(Snd23*, u32) asm("func_0023f740");
void func_001395e8(Snd23*) asm("func_001395e8");
void func_00139610(Snd23*) asm("func_00139610");
void func_00139638(Snd23*) asm("func_00139638");
/*TARGET 0023f1e0*/
void func_0023f1e0(Snd23* p, u32 a1, u32 bank, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3) asm("func_0023f1e0");
void func_0023f1e0(Snd23* p, u32 a1, u32 bank, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3)
{
    func_001391c8(p, a1, t3);
    p->bank = bank;
    func_0023f778(p, a3);  // copy_3halfwords_44
    func_0023f7a8(p, t0);  // copy_3halfwords_50
    s32 id = *(s32*)(func_0023f1b0(p->bank) + 76);
    p->voice = 0;
    for (s32 i = 0; i < 3; i++) {
        if (id == p->ids[i]) p->voice = func_0023c3e0(func_0023f1b0(p->bank), p->sel[i], 0);
    }
    p->cur = id;
    p->f36 = -1;
    p->f32_ = 0;
    func_0023f5b8(p, t1, t2);
    p->color = 0x80e5e5e5;
    s32 n = func_0023aa58(p->voice);
    p->len = n > 0 ? n : 15;
    func_0023f6c0(p, 0);
    func_0023f688(p, 1);
    p->f68 = 0;
    func_0023f740(p, func_0023aa78((u8*)p->voice));
    func_001395e8(p);
    func_00139610(p);
    func_00139638(p);
}
}  // namespace n0023f1e0

