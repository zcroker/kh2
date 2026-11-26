// Linked unit 0x2ca0e0-0x2cac58: world map gummi route landing menu (dk::WM_GLANDING): C2/C1, D2/D1/D0,
// the menu methods, dk::SE::Play (emitted at the end of this file) and the .rodata tables at 0x375818.
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

namespace Tz { class Select { public: u32 isCursorMove(); u32 isSelectTopMove(); }; }

// .rodata 0x375818-0x375868: menu tables of this file. The functions keep the old extern
// declarations (asm-label aliases), so gcc does not fold the reads.
extern "C" const s16 D_00375818[16] = { 0, 2, 1, -1, 3, 5, 4, -1, 6, 9, 8, -1, 10, 5, 4, -1 };
extern "C" const s16 D_00375838[4] = { 14, 16, 15, 0 };
extern "C" const s16 D_00375840[4] = { 0x3a, 0x3c, 0x3b, -1 };
extern "C" const s16 D_00375848[4] = { 0x3a, 0x3c, 0x39, -1 };
extern "C" const u16 D_00375850[12] = { 0x4a4d, 0x4a4e, 0x4a4f, 0x4a50, 0x4a51, 0x4a52, 0x4a53, 0x4a54, 0x4a55, 0, 0, 0 };

// ---- 002ca0e0 (from batch_w64.cpp)
namespace n002ca0e0 {
// ---------------------------------------------------------------------------
extern char D_00361e38[] asm("D_00361e38");
extern char D_00347f98[] asm("D_00347f98");
extern char D_0035eb98[] asm("D_0035eb98");
extern u8* D_00361e28 asm("D_00361e28");
void func_0031a838(u8*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(u8*) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
void func_0028d140(u8*) asm("func_0028d140");
void func_00167f38(s32) asm("func_00167f38");
void func_002c5f48(void) asm("func_002c5f48");


// Constructor; registers itself as the global instance.
void func_002ca0e0(u8* p) asm("func_002ca0e0");
// Constructor; registers itself as the global instance.
void func_002ca0e0(u8* p) {
    *(u32*)(p + 28) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00361e38;
    *(u32*)(p + 12) = 0;
    *(u32*)(p + 24) = 0;
    func_0031a838(p + 40);
    *(void**)(p + 28) = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(p + 52);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(p + 76);  // obj_ctor_36eae8
    *(u32*)(p + 188) = 0;
    func_0028d140(p + 192);
    *(u32*)(p + 636) = 0;
    *(u32*)(p + 640) = 0;
    *(u32*)(p + 644) = 0;
    *(u32*)(p + 648) = 0;
    *(u32*)&D_00361e28 = (u32)p;
    func_00167f38(3);
    func_002c5f48();
}
}  // namespace n002ca0e0

// ---- 002ca170 (from batch_w65.cpp)
namespace n002ca170 {
void func_0031a838(void*) asm("func_0031a838");
// 002e9610: moved to src/sugi/flare.cpp

// 002ee730: moved to src/menu/tutorial_widget.cpp

extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00361e38[] asm("D_00361e38");
extern u8 D_0035eb98[] asm("D_0035eb98");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(void*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(void*) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
void func_0028d140(void*) asm("func_0028d140");
void func_00167f38(s32) asm("func_00167f38");
void func_002c5f48(void) asm("func_002c5f48");

extern union { u32* v; u8 c; } D_00361e28 asm("D_00361e28");
void dk__WM_GLANDING__WM_GLANDING(u32* p) asm("dk__WM_GLANDING__WM_GLANDING");
void dk__WM_GLANDING__WM_GLANDING(u32* p) {
    p[7] = (u32)D_00347f98;
    p[0] = (u32)D_00361e38;
    p[3] = 0;
    p[6] = 0;
    func_0031a838(p + 10);
    p[7] = (u32)D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(p + 13);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(p + 19);  // obj_ctor_36eae8
    p[47] = 0;
    func_0028d140(p + 48);
    p[159] = 0;
    p[160] = 0;
    p[161] = 0;
    p[162] = 0;
    D_00361e28.v = p;
    func_00167f38(3);
    func_002c5f48();
}
}  // namespace n002ca170

// ---- 002ca200: D2 dtor (never written before; the D0 at 0x2ca320 without the free)
namespace n002ca200 {
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00361e38[] asm("D_00361e38");
extern u8* D_00361e28 asm("D_00361e28");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
void func_002c1750(u8*) asm("func_002c1750");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
void func_002ca200(u8* o) asm("func_002ca200");
void func_002ca200(u8* o)
{
    *(u8**)o = D_00361e38;
    D_00361e28 = D_00361e28 == o ? 0 : D_00361e28;
    func_002c1750(o);
    *(u8**)(o + 192) = D_00347e60;
    func_00239870(o + 216);
    *(u8**)(o + 192) = D_00347f98;
    *(u8**)(o + 28) = D_0035eb98;
    func_0023c098(o + 76);
    func_002369f0(o + 52);
    *(u8**)(o + 28) = D_00347f98;
    *(u8**)o = D_00347f98;
}
}  // namespace n002ca200

// ---- 002ca290: D1 dtor (never written before; same body as D2)
namespace n002ca290 {
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00361e38[] asm("D_00361e38");
extern u8* D_00361e28 asm("D_00361e28");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
void func_002c1750(u8*) asm("func_002c1750");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
void func_002369f0(u8*) asm("func_002369f0");
void func_002ca290(u8* o) asm("func_002ca290");
void func_002ca290(u8* o)
{
    *(u8**)o = D_00361e38;
    D_00361e28 = D_00361e28 == o ? 0 : D_00361e28;
    func_002c1750(o);
    *(u8**)(o + 192) = D_00347e60;
    func_00239870(o + 216);
    *(u8**)(o + 192) = D_00347f98;
    *(u8**)(o + 28) = D_0035eb98;
    func_0023c098(o + 76);
    func_002369f0(o + 52);
    *(u8**)(o + 28) = D_00347f98;
    *(u8**)o = D_00347f98;
}
}  // namespace n002ca290

// ---- 002ca320 (from batch_w67.cpp)
namespace n002ca320 {
extern u8 D_00347e60[] asm("D_00347e60");
typedef void (*VFn2)(void*, void*);
extern u8 D_00361e38[] asm("D_00361e38");
extern u8* D_00361e28 asm("D_00361e28");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8* D_00347f80 asm("D_00347f80");
void func_002c1750(u8*) asm("func_002c1750");
void func_00239870(u8*) asm("func_00239870");
void func_0023c098(u8*) asm("func_0023c098");
// set_vtbl_36eae8_then_call
void func_002369f0(u8*) asm("func_002369f0");
  // set_vtbl_36eac8_then_call

// 002ca320: destructor
void func_002ca320(u8* o) asm("func_002ca320");
// set_vtbl_36eac8_then_call

// 002ca320: destructor
void func_002ca320(u8* o)
{
    *(u8**)o = D_00361e38;
    D_00361e28 = D_00361e28 == o ? 0 : D_00361e28;
    func_002c1750(o);
    *(u8**)(o + 192) = D_00347e60;
    func_00239870(o + 216);
    *(u8**)(o + 192) = D_00347f98;
    *(u8**)(o + 28) = D_0035eb98;
    func_0023c098(o + 76);  // set_vtbl_36eae8_then_call
    func_002369f0(o + 52);  // set_vtbl_36eac8_then_call
    *(u8**)(o + 28) = D_00347f98;
    *(u8**)o = D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VFn2*)(*(u8**)m + 4))(m, o);
}
}  // namespace n002ca320

// ---- 002ca3d0 (from tiny_auto80_fptr4.cpp)
namespace n002ca3d0 {
extern u8 D_00375818 asm("D_00375818");


u32 func_002ca3d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002ca3d0");
u32 func_002ca3d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = *(u32*)((u32)r4 + (s32)(648));
    r14 = (u32)&D_00375818;
    r15 = (u32)(r15 << 2);
    r15 = (u32)(r15 + r5);
    r15 = (u32)(r15 << 1);
    r15 = (u32)(r15 + r14);
    r2 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(0)));
    return r2;
}
}  // namespace n002ca3d0

// ---- 002ca3f8: row of the base number table for the current mode (never written before)
namespace n002ca3f8 {
extern s16 D_00375818[] asm("D_00375818");
s16* func_002ca3f8(u8* p) asm("func_002ca3f8");
s16* func_002ca3f8(u8* p) { return &D_00375818[*(s32*)(p + 648) * 4]; }
}  // namespace n002ca3f8

// ---- 002ca410 (from auto80_199_queue.cpp)
namespace n002ca410 {


void func_002ca410(u8* a0) asm("func_002ca410");
void func_002ca410(u8* a0) {
    u8* s1 = a0;

    func_00170950(*(u32*)(a0 + 636));
    func_002c5f60();

    u32 v0 = func_002c6218();
    func_002c6280(v0, 2);

    u32 t6 = *(u32*)(s1 + 644);
    if (t6 != 0) {
        if (t6 == 1) {
            u32 a = *(u32*)(s1 + 640);
            func_002c5418(a - 1);
        }
    }

    func_00167f38(1);

    u32 s0 = *(u32*)(s1 + 188);
    if (s0 != 0) {
        func_00288b00(s0);
        func_00288c20(s0);
    }

    if (s1 != 0) {
        u32* vt = *(u32**)s1;
        ((VCall16)vt[4])(s1);
    }

    func_001384a0(0);
    func_0014f2b0();
}
}  // namespace n002ca410

// ---- 002ca4c0 (from batch_w87.cpp)
namespace n002ca4c0 {
s32 func_002891e8(void*) asm("func_002891e8");
// ---- 0x2ca4c0 ----
s32 func_00289380(void*) asm("func_00289380");
s32 func_00289310(void*) asm("func_00289310");
void func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_002cac40(s32) asm("func_002cac40");
void func_002ca5b8(void*) asm("func_002ca5b8");
void func_002ca0a8(void) asm("func_002ca0a8");

void dk__WM_GLANDING__select(u8* p) asm("dk__WM_GLANDING__select");
void dk__WM_GLANDING__select(u8* p) {
    s32 a = func_00289380(*(void**)(p + 188));
    func_00287df0(a, func_00289310(*(void**)(p + 188)), 0, 0, 1);
    switch (a) {
    case -2:
        func_002cac40(4);
        *(s32*)(p + 644) = 0;
        func_002ca5b8(p);
        break;
    case -4:
    case -1:
        break;
    default:
        if (func_002891e8(*(void**)(p + 188)) == 0) {
            func_002cac40(2);
            *(s32*)(p + 644) = 1;
            *(u32*)(p + 24) |= 1;
            func_002ca5b8(p);
            func_002ca0a8();
        } else {
            func_002cac40(2);
            *(s32*)(p + 644) = 0;
            func_002ca5b8(p);
        }
        break;
    }
}
}  // namespace n002ca4c0

// ---- 002ca5b8 (from auto80_199_queue.cpp)
namespace n002ca5b8 {


void func_002ca5b8(u8* a0) asm("func_002ca5b8");
void func_002ca5b8(u8* a0) {
    u8* s0 = a0;

    u32 v0 = func_002ca3d0((u32)a0, 1);
    u8* s1 = s0 + 192;

    func_0023f070(s0 + 28, v0, -1);
    func_0028aa40(*(u32*)(s0 + 188));
    func_0028ce38();

    if (func_0028d6e8(s1) != 0) {
        func_00139510(s1);
    }
}
}  // namespace n002ca5b8

// ---- 002ca630 (from auto80_199_queue.cpp)
namespace n002ca630 {


void func_002ca630(u8* a0) asm("func_002ca630");
void func_002ca630(u8* a0) {
    u8* s0 = a0;
    YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
    u8* s1 = s0 + 28;

    if (func_00139d78(s1) != 0) {
        if (func_00139538(s1) != 0) {
            if (func_0028acc8(*(u32*)(s0 + 188)) != 0) {
                func_0028abe0(*(u32*)(s0 + 188));
            }
        }
    }

    if (func_00139d78(s1) == 0) {
        u32* vt = *(u32**)s0;
        ((VCall20)vt[5])(s0);
        return;
    }

    dk__WM_GLANDING_INFO__start(*(u32*)(s0 + 640));
    u32 s2 = func_0023f0c0(s1);
    u32 v0 = func_002ca3d0((u32)s0, 2);
    if (s2 != v0) {
        return;
    }

    dk__WM_GLANDING__select((u32)s0);
}
}  // namespace n002ca630

// ---- 002ca6f8 (from auto80_199_queue.cpp)
namespace n002ca6f8 {
class Select { public: u32 isCursorMove(); u32 isSelectTopMove(); };


void func_002890e0(Obj_002890e0* self, u32 a1, s32 a2, u32 a3, s32 a4) asm("func_002890e0");


void dk__WM_GLANDING__drawSelectDeparture(u8* a0) asm("dk__WM_GLANDING__drawSelectDeparture");
void dk__WM_GLANDING__drawSelectDeparture(u8* a0) {
    u8* s2 = a0 + 192;
    u32 s1 = *(u32*)(a0 + 188);

    if (((Tz::Select*)s1)->isCursorMove() == 0) {
        return;
    }

    u32 s0 = func_002891e8(s1);
    func_002890e0(s1, 1, 2, 0, -1);
    func_00289038(s1, s0, 1, 1, 2, 0, -1);

    u32 v0 = func_002891d0(s1);
    func_0028d660(s2, v0);  // record_set_value_refresh
    func_001396b0(s2);
}
}  // namespace n002ca6f8

// ---- 002ca7b0 (from auto80_199_queue.cpp)
namespace n002ca7b0 {


void dk__WM_GLANDING__drawSelectDeparture(u8* a0) asm("dk__WM_GLANDING__drawSelectDeparture");


void func_002ca7b0(u8* a0) asm("func_002ca7b0");
void func_002ca7b0(u8* a0) {
    u8* s0 = a0 + 28;
    u8* s1 = a0;

    if (func_00139538(s0) == 0) {
        u32 v1 = func_0023f0c0(s0);
        u32 v0 = func_002ca3d0((u32)s1, 2);
        if (v1 == v0) {
            dk__WM_GLANDING__drawSelectDeparture((u32)s1);
            return;
        }
    }
}
}  // namespace n002ca7b0

// ---- 002ca828 (from batch_w319.cpp)
namespace n002ca828 {
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u16 D_00375850[] asm("D_00375850");
extern u8 D_00375840[] asm("D_00375840");
extern u8 D_00375848[] asm("D_00375848");
extern u8 D_00375838[] asm("D_00375838");
u32 func_00288be8(...) asm("func_00288be8");
u8* func_0023f1b0(...) asm("func_0023f1b0");
u32 func_0023c4b8(...) asm("func_0023c4b8");
u32 func_00236ca8(...) asm("func_00236ca8");
u8* func_0028c2c8(...) asm("func_0028c2c8");
s32 func_0023aa98(...) asm("func_0023aa98");
u32 func_00138c68(...) asm("func_00138c68");
u32 func_00324bc0(...) asm("func_00324bc0");
s32 func_0023aa18(...) asm("func_0023aa18");
s32 func_0023aa38(...) asm("func_0023aa38");
u32 func_00288ce0(...) asm("func_00288ce0");
u32 func_00239870(...) asm("func_00239870");
u32 Tz__Select__SetCurrent(...) asm("Tz__Select__SetCurrent");
u32 func_0028b078(...) asm("func_0028b078");
// obj_setup_from_args
u32 Tz__Select__SetSelectMax(...) asm("Tz__Select__SetSelectMax");
// obj_set_field22_from_arg
u32 func_00288f48(...) asm("func_00288f48");
u32 func_0028d068(...) asm("func_0028d068");
u32 Tz__LightCur__Create(...) asm("Tz__LightCur__Create");
u32 func_002891d0(...) asm("func_002891d0");
u32 func_0028d660(...) asm("func_0028d660");
// record_set_value_refresh
u32 func_001396b0(...) asm("func_001396b0");
struct W319C { void f(s32, s32) asm("func_002889f0"); };

void func_002ca828(u8* p) asm("func_002ca828");
void func_002ca828(u8* p) {
    u8 buf[352];
    s32 i;
    u32 s2;
    u32 s7;
    u32 s6;
    D_0035f3d4 = 30020;
    s2 = func_00288be8(56);
    ((W319C*)s2)->f(2, 1);
    *(u32*)(p + 188) = s2;
    s7 = func_0023c4b8(func_0023f1b0(p + 28), 1);
    s6 = func_00236ca8(*(u32*)(func_0023f1b0(p + 28) + 40), 1);
    for (i = 0; i < 2; i++) {
        u8* v;
        u8* o;
        s32 a, b;
        v = func_0028c2c8(s7, s6, 58, i ? 18564 : D_00375850[*(s32*)(p + 640) - 1], 0);
        *(s32*)(v + 392) = 59;
        o = v + 24;
        func_00138c68(v, 0, func_0023aa98(o) * i);
        *(s32*)(v + 432) = 2;
        func_00324bc0(buf, o);
        a = -func_0023aa18(buf);
        b = -func_0023aa38(buf);
        *(s32*)(v + 412) = a;
        *(s32*)(v + 416) = b;
        func_00288ce0(s2, v, i, D_00375840, D_00375848);
        func_00239870(buf);
    }
    Tz__Select__SetCurrent(s2, 0, 1, 0, 2);
    func_0028b078(s2, 1, 2);  // obj_setup_from_args
    Tz__Select__SetSelectMax(s2, 2);  // obj_set_field22_from_arg
    func_00288f48(s2, 16, 32, 64, 128);
    func_0028d068(30040, -1);
    Tz__LightCur__Create(p + 192, 30050, 1, 1, p + 28, D_00375838, 0);
    func_0028d660(p + 192, func_002891d0(s2));  // record_set_value_refresh
    func_001396b0(p + 192);
}
}  // namespace n002ca828

// ---- 002caa50 (from batch_w88.cpp)
namespace n002caa50 {
// record408_set_and_refresh
u32 func_001708f8(u32, s32) asm("func_001708f8");
u32 func_002ca3d0(u8*, u32) asm("func_002ca3d0");
void Tz__Layout__create(u8*, u32, u32, u32, u32, u32) asm("Tz__Layout__create");
void Tz__Layout__SetImageCache(u8*) asm("Tz__Layout__SetImageCache");
void func_0023f0c8(u8*, u32) asm("func_0023f0c8");
void func_002ca828(u8*) asm("func_002ca828");
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
struct T2caa50 { u8 d[32]; };
void func_0023f800(T2caa50*) asm("func_0023f800");
void func_0023fa08(T2caa50*, u32) asm("func_0023fa08");
u32 func_0023f948(T2caa50*, u32) asm("func_0023f948");
u32 func_0023f908(T2caa50*, u32) asm("func_0023f908");
void func_0023f848(T2caa50*) asm("func_0023f848");

void dk__WM_GLANDING__create(u8* p, u32 a, u32 b) asm("dk__WM_GLANDING__create");
void dk__WM_GLANDING__create(u8* p, u32 a, u32 b) {
    *(u32*)(p + 640) = b;
    *(u32*)(p + 648) = 0;
    T2caa50 t;
    func_0023f800(&t);
    u32 r = func_001708f8(a, -1);
    *(u32*)(p + 636) = r;
    func_0023fa08(&t, r);
    u32 x = func_0023f948(&t, 0);
    u32 y = func_0023f908(&t, 0);
    Tz__Layout__create(p + 28, 30001, x, y, func_002ca3d0(p, 0), 0);
    Tz__Layout__SetImageCache(p + 28);
    func_0023f0c8(p + 28, func_002ca3d0(p, 2));
    func_002ca828(p);
    func_001391c8(p, 30002, 0);
    func_0023f848(&t);
}
}  // namespace n002caa50

// ---- 002cab48: dk::WM_GLANDING::get_jump_flag (from src/worldmap/wm_glanding.cpp)
namespace n002cab48 {
u32 WM_GLANDING_get_jump_flag(u8* p) asm("_ZN2dk11WM_GLANDING13get_jump_flagEv");
u32 WM_GLANDING_get_jump_flag(u8* p) {
    u32 v = *(u32*)(p + 24);
    return v & 0x1u;
}
}  // namespace n002cab48

// ---- 002cab58 (from tiny_auto80_queue.cpp)
namespace n002cab58 {
extern "C" u32 func_002cab48(...) asm("func_002cab48");


u32 func_002cab58() asm("func_002cab58");
u32 func_002cab58() {
    u32* base = (u32*)0x00360000;
    u32 v = *(u32*)((u8*)base + 0x1e28);
    if (v != 0) {
        if (func_002cab48(v) != 0) {
            return 1;
        }
    }
    return 0;
}
}  // namespace n002cab58

// ---- 002cab98 (from auto80_199_queue.cpp)
namespace n002cab98 {


void func_002cab98(u32 a0) asm("func_002cab98");
void func_002cab98(u32 a0) {
    u32 s1 = a0;

    if (D_00361e28 != 0) {
        return;
    }

    func_00138480(0);
    func_0014f2d8();

    u32 t6 = D_00347f80;
    u32 obj = *(u32*)(t6 + 20);
    u32* vt = *(u32**)obj;
    u32 s0 = ((FnAlloc)vt[0])(obj, 652, 0);

    dk__WM_GLANDING__WM_GLANDING(s0);
    u32 v0 = worldmap__Manager__get2ldFile();
    dk__WM_GLANDING__create(s0, v0, s1);

    func_002cac40(3);
}
}  // namespace n002cab98

// ---- 002cac40 (from tiny_wrappers_more.cpp)
namespace n002cac40 {
u32 func_002bc1e8(u32, u32, u32, u32) asm("func_002bc1e8");


u32 func_002cac40(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002cac40");
u32 func_002cac40(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002bc1e8(a0, a1, a2, a3);
}
}  // namespace n002cac40

