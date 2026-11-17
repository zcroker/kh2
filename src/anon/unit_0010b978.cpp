// Linked unit 0x0010b978-0x0010cdc8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include <stdarg.h>
#include "../naka/libkn/friend.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../../src/common/types.h"
extern "C" float fabsf(float);
#include "tiny_auto80_solver_structs.hpp"

// 0010b978 (was src/anon/batch_wcx2.cpp)
namespace n0010b978 {
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
// 0x00194a30: definition moved into src/anon/unit_00194790.cpp

// --------------------
// Player constructor body: sets up state, then creates the per-character controller.
struct Pair10b978 { u32 a; u32 b; };
struct Mdl10b978 { u8 pad[78]; u16 id; };
struct Pl10b978 {
    u32 vt; u32 f4; Mdl10b978* mdl; u8 pad0[2748 - 12]; u32 flags2; u8 pad1[2896 - 2752];
    s32 f2896; u32 f2900; u32 f2904; u32 f2908; void* ctl; Pair10b978 pair; s32 kind; s32 pad; u32 f2932;
    u32 f2936; u32 flags; u8 pad2[3120 - 2944]; u8 m3120[8]; u8 m3128[40]; u32 f3168; u32 f3172;
    u8 pad3[3280 - 3176]; s32 f3280; u32 f3284[7]; u8 pad4[3324 - 3312]; u32 f3324;
};
extern u8 D_00345c08[] asm("D_00345c08");
extern const Pair10b978 D_0036a440 asm("D_0036a440");
extern const Pair10b978 D_0036a448 asm("D_0036a448");
extern const Pair10b978 D_0036a450 asm("D_0036a450");
void func_0017d968__10b978(Pl10b978*) asm("func_0017d968");
void func_00190128__10b978(void*) asm("func_00190128");
void func_0017bf40__10b978(void*) asm("func_0017bf40");
void func_0010eee8__10b978(Pl10b978*) asm("func_0010eee8");
Pl10b978* func_0017df58__10b978(s32) asm("func_0017df58");
s32 func_0016a070__10b978(Pl10b978*) asm("func_0016a070");
void* func_001050d8__10b978(u32) asm("func_001050d8");
s32 func_00112720__10b978(Pl10b978*) asm("func_00112720");
void func_001136b8__10b978(void*) asm("func_001136b8");
void func_001133f8__10b978(Pl10b978*) asm("func_001133f8");
extern s32 D_00341800[] asm("D_00341800");
#define CTL10b978(fn) void fn##__10b978(void*, Pl10b978*, void*) asm(#fn);
CTL10b978(func_00113648) CTL10b978(func_001148d0) CTL10b978(func_001147b8) CTL10b978(func_001151f8)
CTL10b978(func_00114ff8) CTL10b978(func_00114d48) CTL10b978(func_00114ea0) CTL10b978(func_00114af8)
CTL10b978(func_00115738) CTL10b978(func_001154c8) CTL10b978(func_00115620) CTL10b978(func_00119c40)
CTL10b978(func_00117c28) CTL10b978(func_0011a6b0) CTL10b978(func_0011a490) CTL10b978(func_0011a2a8)
CTL10b978(func_00114c30) CTL10b978(func_00115350)
static inline void* Tab10b978(s32 k) { return (u8*)D_00341800 + D_00341800[k]; }
#define NEW10b978(sz, fn) { void* c = func_001050d8__10b978(sz); fn##__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; }
#define NEW10b978(sz, fn) { void* c = func_001050d8__10b978(sz); fn##__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; }
static inline void CtorM10b978(u8* m) { func_00190128__10b978(m + 8); func_0017bf40__10b978(m); }
/*TARGET 0010b978*/
void func_0010b978(Pl10b978* p) asm("func_0010b978");
void func_0010b978(Pl10b978* p)
{
    func_0017d968__10b978(p);
    p->vt = (u32)D_00345c08;
    CtorM10b978(p->m3120);
    p->f2896 = 0;
    p->pair.a = D_0036a440.a;
    p->pair.b = D_0036a440.b;
    p->flags = 0x10000000;
    p->f3280 = -1;
    p->f2900 = 0;
    p->f2904 = 0;
    p->f2908 = 0;
    p->f2936 = 0;
    p->f3168 = 0;
    p->f3172 = 0;
    func_0010eee8__10b978(p);
    p->f3284[0] = 0; p->f3284[1] = 0; p->f3284[2] = 0; p->f3284[3] = 0;
    p->f3284[4] = 0; p->f3284[5] = 0; p->f3284[6] = 0;
    p->kind = 0;
    p->f3324 = 0;
    if (func_0017df58__10b978(0) == p) p->pad = 1;
    else if (func_0017df58__10b978(1) == p) p->pad = 2;
    s32 id = func_0016a070__10b978(p);
    p->ctl = 0;
    switch (id) {
    case 1: case 4: case 14:
        break;
    case 2:
        if (p->mdl->id == 18) p->kind = 12;
        else p->kind = 0;
        NEW10b978(20, func_001147b8)
        break;
    case 3:
        if (p->mdl->id == 21) p->kind = 13;
        else p->kind = 1;
        NEW10b978(48, func_001148d0)
        break;
    case 5: p->kind = 2; NEW10b978(20, func_00114af8) break;
    case 6: p->kind = 4; NEW10b978(20, func_00114d48) break;
    case 7: p->kind = 5; NEW10b978(20, func_00114ea0) break;
    case 8: p->kind = 6; NEW10b978(20, func_00114ff8) break;
    case 9: p->kind = 7; NEW10b978(20, func_001151f8) break;
    case 10: p->kind = 8; NEW10b978(20, func_00115350) break;
    case 11: p->kind = 9; NEW10b978(20, func_001154c8) break;
    case 12: p->kind = 10; NEW10b978(20, func_00115620) break;
    case 13: p->kind = 11; NEW10b978(20, func_00115738) break;
    case 15: p->kind = 3; NEW10b978(20, func_00114c30) break;
    case 200: {
        p->kind = 14;
        void* c = func_001050d8__10b978(1936);
        func_00117c28__10b978(c, p, Tab10b978(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a448.a;
        p->pair.b = D_0036a448.b;
        p->flags |= 2;
        break;
    }
    case 201: p->kind = 15; { void* c = func_001050d8__10b978(24); func_00119c40__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 202: p->kind = 16; { void* c = func_001050d8__10b978(20); func_0011a2a8__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 203: p->kind = 17; { void* c = func_001050d8__10b978(20); func_0011a490__10b978(c, p, Tab10b978(p->kind)); p->ctl = c; p->flags |= 0x802; } break;
    case 204: {
        p->kind = 18;
        void* c = func_001050d8__10b978(80);
        func_0011a6b0__10b978(c, p, Tab10b978(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a450.a;
        p->pair.b = D_0036a450.b;
        func_001133f8__10b978(p);
        break;
    }
    default: {
        void* c = func_001050d8__10b978(20);
        func_00113648__10b978(c, p, Tab10b978(0));
        p->ctl = c;
        break;
    }
    }
    if (func_00112720__10b978(p)) p->flags2 |= 2;
    func_001136b8__10b978(p->ctl);
}
}  // namespace n0010b978

// 0010c078 (was src/anon/batch_wcx2.cpp)
namespace n0010c078 {
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
// --------------------
// Player constructor body: sets up state, then creates the per-character controller.
struct Pair10c078 { u32 a; u32 b; };
struct Mdl10c078 { u8 pad[78]; u16 id; };
struct Pl10c078 {
    u32 vt; u32 f4; Mdl10c078* mdl; u8 pad0[2748 - 12]; u32 flags2; u8 pad1[2896 - 2752];
    s32 f2896; u32 f2900; u32 f2904; u32 f2908; void* ctl; Pair10c078 pair; s32 kind; s32 pad; u32 f2932;
    u32 f2936; u32 flags; u8 pad2[3120 - 2944]; u8 m3120[8]; u8 m3128[40]; u32 f3168; u32 f3172;
    u8 pad3[3280 - 3176]; s32 f3280; u32 f3284[7]; u8 pad4[3324 - 3312]; u32 f3324;
};
extern u8 D_00345c08[] asm("D_00345c08");
extern const Pair10c078 D_0036a440_x11763 asm("D_0036a440");
extern const Pair10c078 D_0036a448_x11764 asm("D_0036a448");
extern const Pair10c078 D_0036a450_x11765 asm("D_0036a450");
void func_0017d968__10c078(Pl10c078*) asm("func_0017d968");
void func_00190128__10c078(void*) asm("func_00190128");
void func_0017bf40__10c078(void*) asm("func_0017bf40");
void func_0010eee8__10c078(Pl10c078*) asm("func_0010eee8");
Pl10c078* func_0017df58__10c078(s32) asm("func_0017df58");
s32 func_0016a070__10c078(Pl10c078*) asm("func_0016a070");
void* func_001050d8__10c078(u32) asm("func_001050d8");
s32 func_00112720__10c078(Pl10c078*) asm("func_00112720");
void func_001136b8__10c078(void*) asm("func_001136b8");
void func_001133f8__10c078(Pl10c078*) asm("func_001133f8");
extern s32 D_00341800[] asm("D_00341800");
#define CTL10c078(fn) void fn##__10c078(void*, Pl10c078*, void*) asm(#fn);
CTL10c078(func_00113648) CTL10c078(func_001148d0) CTL10c078(func_001147b8) CTL10c078(func_001151f8)
CTL10c078(func_00114ff8) CTL10c078(func_00114d48) CTL10c078(func_00114ea0) CTL10c078(func_00114af8)
CTL10c078(func_00115738) CTL10c078(func_001154c8) CTL10c078(func_00115620) CTL10c078(func_00119c40)
CTL10c078(func_00117c28) CTL10c078(func_0011a6b0) CTL10c078(func_0011a490) CTL10c078(func_0011a2a8)
CTL10c078(func_00114c30) CTL10c078(func_00115350)
static inline void* Tab10c078(s32 k) { return (u8*)D_00341800 + D_00341800[k]; }
#define NEW10c078(sz, fn) { void* c = func_001050d8__10c078(sz); fn##__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; }
static inline void CtorM10c078(u8* m) { func_00190128__10c078(m + 8); func_0017bf40__10c078(m); }
/*TARGET 0010c078*/
void func_0010c078(Pl10c078* p) asm("func_0010c078");
void func_0010c078(Pl10c078* p)
{
    func_0017d968__10c078(p);
    p->vt = (u32)D_00345c08;
    CtorM10c078(p->m3120);
    p->f2896 = 0;
    p->pair.a = D_0036a440_x11763.a;
    p->pair.b = D_0036a440_x11763.b;
    p->flags = 0x10000000;
    p->f3280 = -1;
    p->f2900 = 0;
    p->f2904 = 0;
    p->f2908 = 0;
    p->f2936 = 0;
    p->f3168 = 0;
    p->f3172 = 0;
    func_0010eee8__10c078(p);
    p->f3284[0] = 0; p->f3284[1] = 0; p->f3284[2] = 0; p->f3284[3] = 0;
    p->f3284[4] = 0; p->f3284[5] = 0; p->f3284[6] = 0;
    p->kind = 0;
    p->f3324 = 0;
    if (func_0017df58__10c078(0) == p) p->pad = 1;
    else if (func_0017df58__10c078(1) == p) p->pad = 2;
    s32 id = func_0016a070__10c078(p);
    p->ctl = 0;
    switch (id) {
    case 1: case 4: case 14:
        break;
    case 2:
        if (p->mdl->id == 18) p->kind = 12;
        else p->kind = 0;
        NEW10c078(20, func_001147b8)
        break;
    case 3:
        if (p->mdl->id == 21) p->kind = 13;
        else p->kind = 1;
        NEW10c078(48, func_001148d0)
        break;
    case 5: p->kind = 2; NEW10c078(20, func_00114af8) break;
    case 6: p->kind = 4; NEW10c078(20, func_00114d48) break;
    case 7: p->kind = 5; NEW10c078(20, func_00114ea0) break;
    case 8: p->kind = 6; NEW10c078(20, func_00114ff8) break;
    case 9: p->kind = 7; NEW10c078(20, func_001151f8) break;
    case 10: p->kind = 8; NEW10c078(20, func_00115350) break;
    case 11: p->kind = 9; NEW10c078(20, func_001154c8) break;
    case 12: p->kind = 10; NEW10c078(20, func_00115620) break;
    case 13: p->kind = 11; NEW10c078(20, func_00115738) break;
    case 15: p->kind = 3; NEW10c078(20, func_00114c30) break;
    case 200: {
        p->kind = 14;
        void* c = func_001050d8__10c078(1936);
        func_00117c28__10c078(c, p, Tab10c078(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a448_x11764.a;
        p->pair.b = D_0036a448_x11764.b;
        p->flags |= 2;
        break;
    }
    case 201: p->kind = 15; { void* c = func_001050d8__10c078(24); func_00119c40__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 202: p->kind = 16; { void* c = func_001050d8__10c078(20); func_0011a2a8__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; p->flags |= 0x800; } break;
    case 203: p->kind = 17; { void* c = func_001050d8__10c078(20); func_0011a490__10c078(c, p, Tab10c078(p->kind)); p->ctl = c; p->flags |= 0x802; } break;
    case 204: {
        p->kind = 18;
        void* c = func_001050d8__10c078(80);
        func_0011a6b0__10c078(c, p, Tab10c078(p->kind));
        p->ctl = c;
        p->pair.a = D_0036a450_x11765.a;
        p->pair.b = D_0036a450_x11765.b;
        func_001133f8__10c078(p);
        break;
    }
    default: {
        void* c = func_001050d8__10c078(20);
        func_00113648__10c078(c, p, Tab10c078(0));
        p->ctl = c;
        break;
    }
    }
    if (func_00112720__10c078(p)) p->flags2 |= 2;
    func_001136b8__10c078(p->ctl);
}
}  // namespace n0010c078

// 0010c778 (was src/naka/libkn/friend.cpp)
namespace kn { // method 0010c778
extern void ObjObserver_Create(void*) asm("_ZN2kn11ObjObserver6CreateEPPS0_");
class Friend;
/*TARGET 0010c778*/
u32 Friend::getObjObserver() {
    u32 r2 = *(volatile u32*)((u32)this + 2904);
    if (r2 == 0u) {
        ObjObserver_Create((void*)((u32)this + 2904));
        r2 = *(volatile u32*)((u32)this + 2904);
    }
    return r2;
}
}  // kn

// 0010c7b0 (was src/anon/batch_w21.cpp)
namespace n0010c7b0 {
void func_00135dc8(void*) asm("func_00135dc8");
/*TARGET 0010c7b0*/
// 001050d8: moved to src/common/area.cpp

u32 func_0010c7b0(u8* p) asm("func_0010c7b0");
// 001050d8: moved to src/common/area.cpp

u32 func_0010c7b0(u8* p) {  // obj_get_sub_lazy
    if (*(u32*)(p + 2908) == 0) func_00135dc8(p + 2908);
    return *(u32*)(p + 2908);
}
}  // namespace n0010c7b0

// 0010c7e8 (was src/naka/libkn/friend.cpp)
namespace kn { // method 0010c7e8
class Friend;
/*TARGET 0010c7e8*/
s32 Friend::getPersonality() { return reinterpret_cast<FriendLayout*>(this)->personality; }
}  // kn

// 0010c7f0 (was src/anon/batch_w22.cpp)
namespace n0010c7f0 {
// 00104da0: moved to src/common/area.cpp

// --- 0010c7f0
void func_0017dbb8(void*) asm("func_0017dbb8");
typedef void (*VFn)(void*);
/*TARGET 0010c7f0*/
void func_0010c7f0(u8* p) asm("func_0010c7f0");
void func_0010c7f0(u8* p) {
    func_0017dbb8(p);
    void* o = *(void**)(p + 2912);
    (*(VFn*)((*(u8**)o) + 20))(o);
}
}  // namespace n0010c7f0

// 0010c828 (was src/anon/batch_w1.cpp)
namespace n0010c828 {
/*TARGET 0010c828*/
// Virtual call: slot 6 of the object held at +0xb60.
void func_0010c828(u8* p) asm("func_0010c828");
// Virtual call: slot 6 of the object held at +0xb60.
void func_0010c828(u8* p) {
    void* o = *(void**)(p + 0xb60);
    (*(void (**)(void*))(*(u8**)o + 24))(o);
}
}  // namespace n0010c828

// 0010c850 (was src/anon/auto80_199_queue.cpp)
namespace n0010c850 {
/*TARGET 0010c850*/
// 0010a580: moved to src/anon/unit_00109c30.cpp

void func_0010c850(u8* a0) asm("_Z13func_0010c850Ph");
// 0010a580: moved to src/anon/unit_00109c30.cpp

void func_0010c850(u8* a0) {
    u8* s0 = a0;

    u32 p = *(u32*)(s0 + 2904);
    if (p != 0) {
        u32 vtbl = *(u32*)p;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(u32))fn)(p);
        *(u32*)(s0 + 2904) = 0;
    }

    p = *(u32*)(s0 + 2908);
    if (p != 0) {
        u32 vtbl = *(u32*)p;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(u32))fn)(p);
        *(u32*)(s0 + 2908) = 0;
    }

    p = *(u32*)(s0 + 2912);
    if (p != 0) {
        u32 vtbl = *(u32*)p;
        u32 fn = *(u32*)(vtbl + 4);
        ((void (*)(u32))fn)(p);
        *(u32*)(s0 + 2912) = 0;
    }

    func_0017dc08(s0);
}
}  // namespace n0010c850

// 0010c8d8 (was gap, never written)
namespace n0010c8d8 {
struct C; struct CVt { void* f0; void* f4; void (*f8)(C*); void (*f12)(C*, u8*); };
struct C { CVt* vt; };
void func_001a67e0(u32) asm("func_001a67e0");
void area_free(u32) asm("_ZN4AREA4FreeEPv");
void func_0017e210(u8*) asm("func_0017e210");
void func_0010c8d8(u8* p) asm("func_0010c8d8");
void func_0010c8d8(u8* p) {
    C* c = *(C**)(p + 2912);
    c->vt->f8(c);
    if (*(u32*)(p + 2896)) { func_001a67e0(*(u32*)(p + 2896)); *(u32*)(p + 2896) = 0; }
    if (*(u32*)(p + 2900)) { area_free(*(u32*)(p + 2900)); *(u32*)(p + 2900) = 0; }
    func_0017e210(p);
}
}

// 0010c940 (was src/anon/batch_w67.cpp)
namespace n0010c940 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector: copy-construct = quadword copy, assignment skips self.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
void func_0017c4c8(void*, Vec4) asm("func_0017c4c8");
void func_0017f488(void*, s32, f32, f32) asm("func_0017f488");
static inline bool stateIsOne(u8* c) { return *(s32*)(c + 4) == 1; }
/*TARGET 0010c940*/
// 0010c940
void func_0010c940(u8* p, s32 n, f32 t) asm("func_0010c940");
// 0010c940
void func_0010c940(u8* p, s32 n, f32 t)
{
    u8* c = *(u8**)(p + 12);
    if (c && stateIsOne(c)) return;
    f32 m = *(f32*)(p + 280);
    if (m < t) t = m;
    Vec4 v;
    v = *(Vec4*)(p + 16);
    v.y = t;
    func_0017c4c8(p, v);
    func_0017f488(p + 320, n, 0.0f, 0.0f);
    *(s32*)(p + 256) = n + 1;
    *(s32*)(p + 260) = n + 2;
    *(u32*)(p + 264) |= 0x10000;
}
}  // namespace n0010c940

// 0010c9f8 (was src/anon/batch_w91.cpp)
namespace n0010c9f8 {
// 16-byte vector whose copy constructor is a 128-bit lq/sq (used for by-value passing).
struct Vc {
    f32 x, y, z, w;
    Vc() {}
    Vc(const Vc& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
// --- 0010c9f8
// Sets a direction vector from a yaw (degrees, relative to the current one) and resets motion.
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");
void func_001b2210(u8*, Vc, f32, f32) asm("func_001b2210");
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
/*TARGET 0010c9f8*/
void func_0010c9f8(u8* p, f32 a, f32 b, f32 c, f32 d, f32 e) asm("func_0010c9f8");
void func_0010c9f8(u8* p, f32 a, f32 b, f32 c, f32 d, f32 e) {
    a = *(f32*)(p + 1372) + a * 0.017453292f;
    Vc v;
    v.x = sinf(a);
    v.z = cosf(a);
    v.y = b;
    v.w = c;
    func_001b2210(p, v, e, d);
    func_0017f488(p + 320, 3, 0.0f, 0.0f);
    *(s32*)(p + 256) = 4;
    *(s32*)(p + 260) = 5;
}
}  // namespace n0010c9f8

// 0010cac8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0010cac8 {
/*TARGET 0010cac8*/
void func_0010cac8(u8* a0, u32 a1, f32 f12) asm("_Z13func_0010cac8Phjf");
void func_0010cac8(u8* a0, u32 a1, f32 f12) {  // set_bit_and_fields
    u64 t6 = *(u64*)(a0 + 0xc30);
    u64 t7 = ((u64)1) << 33;
    *(u32*)(a0 + 0xc50) = a1;
    t6 |= t7;
    *(f32*)(a0 + 0xc4c) = f12;
    *(u64*)(a0 + 0xc30) = t6;
}
}  // namespace n0010cac8

// 0010cae8 (was src/anon/batch_w2031_nsa.cpp)
namespace n0010cae8 {
struct W2031_V5 { s32 v[5]; };
/*TARGET 0010cae8*/
void func_0010cae8(u8* a0, u8* a1) asm("func_0010cae8");
void func_0010cae8(u8* a0, u8* a1) {
    *(u16*)(a0 + 0xc30) = 1;
    *(W2031_V5*)(a0 + 0xc38) = *(W2031_V5*)(a0 + 0x9f4);
    *(s32*)(a0 + 0xb78) = 0;
    *(u8**)(a0 + 0xc68) = a1;
    if (*(s32*)(a0 + 0x48c) != 0 && *(s32*)(a1 + 8) != 0) a0[0xc35] = a1[8];
    else a0[0xc35] = 0;
}
}  // namespace n0010cae8

// 0010cb50 (was src/anon/auto80_199_queue.cpp)
namespace n0010cb50 {
/*TARGET 0010cb50*/
void func_0010cb50(u8* a0, s32 a1, u32 a2) asm("_Z13func_0010cb50Phij");
void func_0010cb50(u8* a0, s32 a1, u32 a2) {
    u8* s0 = a0;
    u8* p = s0 + 2548;
    u32 v;
    u32 eq;

    if (a2 == 0) {
        return;
    }
    *(s16*)(s0 + 3122) = (s16)a1;
    *(u32*)(s0 + 2936) = 0;
    *(u8*)(s0 + 3125) = 0;
    *(s16*)(s0 + 3120) = 2;

    v = *(u32*)(p + 0);
    eq = (v == a2);
    if (!eq) {
        func_00190878(p, a2, 0);
        v = *(u32*)(p + 0);
    }

    u32 e = *(volatile u32*)(s0 + 2552);
    u32 d = *(volatile u32*)(s0 + 2556);
    u32 c = *(volatile u32*)(s0 + 2560);
    u32 f = *(volatile u32*)(s0 + 2564);
    volatile u32* dst = (volatile u32*)s0;
    dst[782] = v;   // +3128
    dst[786] = f;   // +3144
    dst[783] = e;   // +3132
    dst[784] = d;   // +3136
    dst[785] = c;   // +3140
}
}  // namespace n0010cb50

// 0010cbc8 (was src/anon/batch_w1773.cpp)
namespace n0010cbc8 {
/* 0010cbc8 */
void YS_TARGET_set_obj(void* t, void* o, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void* YS_ITEM_GetCommandElem(s32) asm("_ZN2YS4ITEM14GetCommandElemEi");
void func_00176dd8(void*, void*, void*, s32) asm("func_00176dd8");
/*TARGET 0010cbc8*/
void func_0010cbc8(u8* p, s32 item, void* obj, s32 d) asm("func_0010cbc8");
void func_0010cbc8(u8* p, s32 item, void* obj, s32 d) {
    void* t = p + 0x9f4;
    if (obj == 0) return;
    *(s32*)(p + 0xb78) = 0;
    if (*(void**)(p + 0x9f4) != obj) YS_TARGET_set_obj(t, obj, 0);
    func_00176dd8(p, YS_ITEM_GetCommandElem(item), t, d);
}
}  // namespace n0010cbc8

// 0010cc60 (was gap, never written)
namespace n0010cc60 {
u8* func_0010cc60(u8* p) asm("func_0010cc60");
u8* func_0010cc60(u8* p) { return p + 2944; }
}

// 0010cc70 (was src/anon/tiny.cpp)
namespace n0010cc70 {
/*TARGET 0010cc70*/
// 0010ae90: moved to src/anon/unit_0010a918.cpp

u32 func_0010cc70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0010cc70jjjj");
// 0010ae90: moved to src/anon/unit_0010a918.cpp

u32 func_0010cc70(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)((s32)a0 + (2992));
}
}  // namespace n0010cc70

// 0010cc80 (was src/anon/auto80_199_queue.cpp)
namespace n0010cc80 {
/*TARGET 0010cc80*/
u32 func_0010cc80(u8* a0) asm("_Z13func_0010cc80Ph");
u32 func_0010cc80(u8* a0) {
    u8* s0 = a0 + 2548;
    u32 s1 = 0;

    if ((*(u32*)(a0 + 2940) & 0x40) == 0) {
        if (func_00112d90(s0) != 0) {
            u32 v0 = func_001901c0(s0);
            s1 = (v0 != 0);
        }
    }

    return s1;
}
}  // namespace n0010cc80

// 0010cce0 (was src/anon/batch_w59.cpp)
namespace n0010cce0 {
// 00109140: moved to src/anon/unit_001085a8.cpp

// --- 0010cce0
// Advance the object iterator until an object passing the check is found.
void* func_001b9bc8p(void*) asm("func_001b9bc8");
bool func_00112d28(void*) asm("func_00112d28");
/*TARGET 0010cce0*/
void* func_0010cce0(void* p) asm("func_0010cce0");
void* func_0010cce0(void* p) {
    while ((p = func_001b9bc8p(p)) != 0) {
        if (func_00112d28(p)) break;
    }
    return p;
}
}  // namespace n0010cce0

// 0010cd30 (was gap, never written)
namespace n0010cd30 {
typedef s32 (*FA)(u32*, u32);
typedef void (*FB)(s32, u32, u32);
typedef s32 (*FC)(s32, u32);
u32 func_001b9bc8(u32) asm("_Z16ctarget_001b9bc8jjjj");
s32 func_0010cd30(FA a, FB b, FC c, u32 x) asm("func_0010cd30");
s32 func_0010cd30(FA a, FB b, FC c, u32 x) {
    u32 h = 0;
    s32 r = 0;
    if (a) r = a(&h, x);
    while ((h = func_001b9bc8(h)) != 0) b(r, h, x);
    if (c) r = c(r, x);
    return r;
}
}

