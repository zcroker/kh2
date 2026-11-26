// Linked unit 0x2c3c90-0x2c44b8: worldmap landing file, after the whole-asm 0x2c3638 and before
// the C function 0x2c44b8 (its own unit, src/anon/unit_002c44b8.c).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_top.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../worldmap/menu.hpp"
#include "../worldmap/wm_landing_info.hpp"

namespace Tz { class Select { public: u32 isCursorMove(); u32 isSelectTopMove(); }; }

// ---- 002c3c90 from src/anon/batch_w254.cpp
namespace n002c3c90 {
s32 func_00289380(void*) asm("func_00289380");
s32 func_00289310(void*) asm("func_00289310");
s32 func_002891e8(void*) asm("func_002891e8");
void func_002cac40(s32) asm("func_002cac40");
u8* func_001c3f58(s32) asm("func_001c3f58");
void func_002c3da0(u8*) asm("func_002c3da0");
void func_002c8648(void) asm("func_002c8648");
struct W254S10 { s16 h[5]; };
void func_002c3c90(u8* a0) asm("func_002c3c90");
void func_002c3c90(u8* a0) {
    s32 r = func_00289380(*(void**)(a0 + 872));
    if (func_00289310(*(void**)(a0 + 872))) func_002cac40(1);
    switch (r) {
    case -2:
        func_002cac40(4);
        *(s32*)(a0 + 8240) = 0;
        func_002c3da0(a0);
        return;
    case -1:
    case -4:
        return;
    }
    if (func_002891e8(*(void**)(a0 + 872)) == 0) {
        func_002cac40(2);
        *(s32*)(a0 + 8240) = 1;
        *(u32*)(a0 + 24) |= 2;
        *(W254S10*)(a0 + 13608) = *(W254S10*)func_001c3f58(*(s32*)(a0 + 8236));
        func_002c3da0(a0);
        func_002c8648();
    } else {
        func_002cac40(2);
        *(s32*)(a0 + 8240) = 0;
        func_002c3da0(a0);
        asm volatile("");
    }
}
}  // namespace n002c3c90

// ---- 002c3da0 from src/anon/auto80_199_queue.cpp
namespace n002c3da0 {
void func_002c3da0(u8* self) asm("_Z13func_002c3da0Ph");
void func_002c3da0(u8* self) {
    u32 v0 = func_002c3240((u32)self, 1);
    u8* s0 = self + 876;
    func_0023f070(self + 28, v0, -1);
    func_0028aa40(*(u32*)(self + 872));
    func_0028ce38();
    if (func_0028d6e8(s0) != 0) {
        func_00139510(s0);
    }

    if (func_002c5120(self) == 0) {
        return;
    }
    if (func_002c5130(self) == 0) {
        func_00139510(self + 11872);
        return;
    }
    func_00138c10(self + 11872, 96);
}
}  // namespace n002c3da0

// ---- 002c3e58 from src/anon/batch_wcx2.cpp
namespace n002c3e58 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
void func_00134668(void* p) asm("func_00134668");
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
typedef void (*VFn58)(void*);
#define VCALL5_e58(o) ((VFn58)(*(void***)(o))[5])(o)
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
void func_002c3368_3e58(u8*) asm("func_002c3368");
void func_002c34d0_3e58(u8*) asm("func_002c34d0");
s32 func_00139d78_3e58(u8*) asm("func_00139d78");
s32 func_00139538(u8*) asm("func_00139538");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
s32 func_002c5120(u8*) asm("func_002c5120");
void func_00139510(u8*) asm("func_00139510");
void func_002c85c8(u32) asm("func_002c85c8");
s32 func_0023f0c0_3e58(u8*) asm("func_0023f0c0");
s32 func_002c3240(u8*, s32) asm("func_002c3240");
void func_002c3638(u8*) asm("func_002c3638");
void func_002c3c90(u8*) asm("func_002c3c90");
void dk__WM_LANDING__update(u8* p) asm("dk__WM_LANDING__update");
void dk__WM_LANDING__update(u8* p)
{
    YI__IMAGE_CACHE__Clear();                        
    switch (*(s32*)(p + 8260)) {
    case 1:
        func_002c3368_3e58(p);
        *(s32*)(p + 8260) = 0;
        break;
    case 2:
        func_002c34d0_3e58(p);
        *(s32*)(p + 8260) = 0;
        break;
    case 0:
        break;
    }
    u8* lay = p + 28;
    if (func_00139d78_3e58(lay) && func_00139538(lay)) {
        if (func_0028acc8(*(u32*)(p + 872))) func_0028abe0(*(u32*)(p + 872));
        if (func_002c5120(p)) {
            for (s32 i = 0; i < 9; i++) VCALL5_e58(p + 188 + i * 76);
            for (s32 i = 0; i < *(s32*)(p + 8252); i++) {
                u8* o = p + 1320 + i * 432;
                if (func_00139d78_3e58(o)) VCALL5_e58(o);
            }
            for (s32 i = 0; i < *(s32*)(p + 8256); i++) {
                u8* o = p + 4776 + i * 432;
                if (func_00139d78_3e58(o)) VCALL5_e58(o);
            }
            if (*(s32*)(p + 12368) && func_0028acc8(*(u32*)(p + 12360))) func_0028abe0(*(u32*)(p + 12360));
            if (func_00139d78_3e58(p + 13648)) func_00139510(p + 13648);
        }
    }
    if (!func_00139d78_3e58(p + 11872) && !func_00139d78_3e58(lay)) {
        VCALL5_e58(p);
        return;
    }
    func_002c85c8(*(u32*)(p + 8236));
    if (func_0023f0c0_3e58(lay) != func_002c3240(p, 2)) return;
    if (func_002c5120(p)) func_002c3638(p);
    else func_002c3c90(p);
}
}  // namespace n002c3e58

// ---- 002c40d8 from src/anon/batch_wcx2.cpp
namespace n002c40d8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14;
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
struct V86 {
    f32 x, y, z, w;
    V86() {}
    V86& operator=(const V86& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Obj98 { u8 pad[28]; u8 pos[844]; u32 lst; u8 m[4]; };
s32 func_0028d008_116312(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, u8*, s32, s32) asm("Tz__MenuCursor__Create");
u32 func_002891d0(u32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, u32) asm("Tz__MenuCursor__SetParent");
s32 func_00289310(u32) asm("func_00289310");
s32 func_002891e8(u32) asm("func_002891e8");
void func_002890e0(u32, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(u32, s32, s32, s32, s32, s32, s32) asm("func_00289038");
void func_0028d660(u8*, u32) asm("func_0028d660");
void func_001396b0_116312(u8*) asm("func_001396b0");
void dk__WM_LANDING__drawList(Obj98* o) asm("dk__WM_LANDING__drawList");
void dk__WM_LANDING__drawList(Obj98* o)
{
    u32 lst = o->lst;
    if (!func_0028d008_116312(0)) {
        Tz__MenuCursor__Create(0, 1, 1, o->pos, 54, 54);
        Tz__MenuCursor__SetParent(0, func_002891d0(lst));                              
    }
    if (!func_0028d008_116312(1)) {
        Tz__MenuCursor__Create(1, 1, 1, o->pos, 13, 13);
        Tz__MenuCursor__SetParent(1, func_002891d0(lst));                              
    }
    if (!func_00289310(lst)) return;
    s32 k = func_002891e8(lst);
    func_002890e0(lst, 1, 2, 0, -1);
    func_00289038(lst, k, 1, 1, 2, 0, -1);
    Tz__MenuCursor__SetParent(0, func_002891d0(lst));                              
    Tz__MenuCursor__SetParent(1, func_002891d0(lst));                              
    func_0028d660(o->m, func_002891d0(lst));                             
    func_001396b0_116312(o->m);
}
}  // namespace n002c40d8

// ---- 002c4240 from src/anon/auto80_199_queue.cpp
namespace n002c4240 {
void func_002c4240(u8* self) asm("_Z13func_002c4240Ph");
void func_002c4240(u8* self) {
    u8* s2 = self + 876;
    u32 s1 = *(u32*)(self + 872);
    if (((Tz::Select*)s1)->isCursorMove() == 0) {
        return;
    }

    u32 s0 = func_002891e8(s1);
    func_002890e0(s1, 1, 2, 0, -1);
    func_00289038(s1, s0, 1, 1, 2, 0, -1);
    u32 v0 = func_002891d0(s1);
    func_0028d660(s2, v0);                             
    func_001396b0(s2);
}
}  // namespace n002c4240

// ---- 002c42f8 from src/anon/auto80_199_queue.cpp
namespace n002c42f8 {
void func_002c4240(u8* self) asm("_Z13func_002c4240Ph");
void func_002c42f8(u8* self) asm("_Z13func_002c42f8Ph");
void func_002c42f8(u8* self) {
    u8* s0 = self + 28;
    if (func_00139538(s0) != 0) {
        return;
    }
    u32 v = func_0023f0c0(s0);
    if (v != func_002c3240((u32)self, 2)) {
        return;
    }
    if (func_002c5120(self) != 0) {
        dk__WM_LANDING__drawList(self);
        return;
    }
    func_002c4240(self);
}
}  // namespace n002c42f8

// ---- 002c4390 from src/anon/batch_w1832.cpp
namespace n002c4390 {
struct Obj2c1832 { u8 pad[0x18]; u8 sub[0x174]; void* f18c; };
void func_00138cb8(void*, s32*, s32*) asm("func_00138cb8");
void YS__MESSAGEDRAW__Draw(s32, s32, s32, s32, s32, s32, s32) asm("YS__MESSAGEDRAW__Draw");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
s32 func_0023aa58(void*) asm("func_0023aa58");
s32 func_0023aa98(void*) asm("func_0023aa98");
s32 func_0028b040(s32) asm("func_0028b040");
s32 Tz__Select__GetPtr2Idx(s32, Obj2c1832*) asm("Tz__Select__GetPtr2Idx");
s32 func_002c2610(s32, s32) asm("func_002c2610");
extern s32 D_00361c0c asm("D_00361c0c");
extern s32 D_01e2bd10 asm("D_01e2bd10");
void func_002c4390(s32 en, s32 a1, s32 a2, s32 a3, Obj2c1832* o) asm("func_002c4390");
void func_002c4390(s32 en, s32 a1, s32 a2, s32 a3, Obj2c1832* o) {
    s32 px, py, qx, qy;
    s32 m, n;
    void* sub = o->sub;
    if (en) {
        func_00138cb8(o->f18c, &px, &py);
        func_00138cb8(o, &qx, &qy);
        qx = qx + px + func_0023aa18(sub);
        qy = qy + ((Tz__Select__GetPtr2Idx(D_00361c0c, o) * func_0023aa98(sub)) + (func_0023aa38(sub) + py));
        m = func_0023aa58(sub);
        n = Tz__Select__GetPtr2Idx(D_00361c0c, o);
        n = n + func_0028b040(D_00361c0c);
        YS__MESSAGEDRAW__Draw(0, func_002c2610(D_01e2bd10, n), qx, qy, a2, m, 0);
    }
}
}  // namespace n002c4390

