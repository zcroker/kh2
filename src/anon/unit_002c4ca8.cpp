// Linked unit 0x2c4ca8-0x2c53c8: end of the worldmap landing file, up to the _GLOBAL__D_ stub
// 0x2c53a8. Holds the static init (three .bss vectors, .rodata 0x375574) as a plain function,
// the two empty atexit thunks of 0x2c3638's local statics and the I/D stubs.
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

// ---- 002c4ca8 from src/anon/batch_w297.cpp
namespace n002c4ca8 {
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u16 D_00375608[] asm("D_00375608");
extern u16 D_003755d0[] asm("D_003755d0");
extern u16 D_003755d8[] asm("D_003755d8");
extern u16 D_00375598[] asm("D_00375598");
void* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
u8* func_0028c2c8(s32, s32, s32, s32, s32) asm("func_0028c2c8");
s32 func_0023aa98(void*) asm("func_0023aa98");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_00324bc0(void*, void*) asm("func_00324bc0");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_00288ce0(void*, void*, s32, void*, void*) asm("func_00288ce0");
void func_00239870(void*) asm("func_00239870");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028b078(void*, s32, s32) asm("func_0028b078");
void Tz__Select__SetSelectMax(void*, s32) asm("Tz__Select__SetSelectMax");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_0028d068(s32, s32) asm("func_0028d068");
void Tz__LightCur__Create(void*, s32, s32, s32, void*, void*, s32) asm("Tz__LightCur__Create");
s32 func_002891d0(void*) asm("func_002891d0");
void func_0028d660(void*, s32) asm("func_0028d660");
void func_001396b0(void*) asm("func_001396b0");
void func_002c4ca8(u8* p) asm("func_002c4ca8");
void func_002c4ca8(u8* p) {
    D_0035f3d4 = 30020;
    void* g = func_00288be8(56);
    func_002889f0(g, 2, 1);
    *(void**)(p + 872) = g;
    for (s32 i = 0; i < 2; i++) {
        s32 id = 18564;
        if (i == 0) id = D_00375608[*(s32*)(p + 8236)];
        u8* o = func_0028c2c8(*(s32*)(p + 13640), *(s32*)(p + 13644), 58, id, 0);
        *(s32*)(o + 392) = 59;
        func_00138c68(o, 0, func_0023aa98(o + 24) * i);
        *(s32*)(o + 432) = 2;
        u8 buf[352] __attribute__((aligned(16)));
        func_00324bc0(buf, o + 24);
        s32 w = -func_0023aa18(buf);
        s32 h = -func_0023aa38(buf);
        *(s32*)(o + 412) = w;
        *(s32*)(o + 416) = h;
        func_00288ce0(g, o, i, D_003755d0, D_003755d8);
        func_00239870(buf);
    }
    Tz__Select__SetCurrent(g, 0, 1, 0, 2);
    { s32 b = 2; func_0028b078(g, 1, b); }
    Tz__Select__SetSelectMax(g, 2);                             
    func_00288f48(g, 16, 32, 64, 128);
    func_0028d068(30040, -1);
    Tz__LightCur__Create(p + 876, 30050, 1, 1, p + 28, D_00375598, 0);
    func_0028d660(p + 876, func_002891d0(g));                             
    func_001396b0(p + 876);
}
}  // namespace n002c4ca8

// ---- 002c4e98 from src/anon/batch_wcx2.cpp
namespace n002c4e98 {
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
struct Init5_98 { u8* obj; u32 w[4]; };
struct La98 { u8 d[32]; };
struct Ent98 { u8 pad[24]; u32 a; u32 b; };
extern u8 D_01e2bd30[] asm("D_01e2bd30");
extern u8 D_01e2bd20[] asm("D_01e2bd20");
extern Ent98 D_00375630[] asm("D_00375630");
s32 func_002cb200(u8*, u8, u8*) asm("func_002cb200");
void func_0023f800(La98*) asm("func_0023f800");
u32 func_001708f8_4e98(u32, s32) asm("func_001708f8");
void func_0023fa08(La98*, u32) asm("func_0023fa08");
u32 func_0023f948(La98*, s32) asm("func_0023f948");
u32 func_0023f908(La98*, s32) asm("func_0023f908");
u32 func_002c3240_4e98(u8*, s32) asm("func_002c3240");
void Tz__Layout__create(u8*, s32, u32, u32, u32, s32) asm("Tz__Layout__create");
void Tz__Layout__SetImageCache(u8*) asm("Tz__Layout__SetImageCache");
void func_0023f0c8(u8*, u32) asm("func_0023f0c8");
u8* func_0023f1b0_4e98(u8*) asm("func_0023f1b0");
u32 func_0023c4b8_4e98(u8*, s32) asm("func_0023c4b8");
u32 func_00236ca8_4e98(u32, s32) asm("func_00236ca8");
s32 func_002c5120(u8*) asm("func_002c5120");
void func_002cb0e8_4e98(Init5_98*, u8*, f32) asm("func_002cb0e8");
void func_002c44b8(u8*) asm("func_002c44b8");
void func_002c4ca8(u8*) asm("func_002c4ca8");
u32 func_002c3268_4e98(u8*) asm("func_002c3268");
void func_0023f1e0_4e98(u8*, s32, u8*, u32, Ent98*, u32, s32, s32) asm("Tz__LayMsg__create");
void func_00139620(u8*) asm("func_00139620");
void func_001395e8_4e98(u8*) asm("func_001395e8");
void func_001395f8(u8*) asm("func_001395f8");
void func_0023f6c0_4e98(u8*, u32) asm("func_0023f6c0");
u32 func_002c24e0(u32) asm("func_002c24e0");
u32 func_002c2518(u32) asm("func_002c2518");
void func_0023f618(u8*, u32) asm("func_0023f618");
void func_00139638_4e98(u8*) asm("func_00139638");
void func_001391c8_4e98(u8*, s32, s32) asm("func_001391c8");
void func_0023f848(La98*) asm("func_0023f848");
void dk__WM_LANDING__create(u8* p, u32 res, Init5_98* arg) asm("dk__WM_LANDING__create");
void dk__WM_LANDING__create(u8* p, u32 res, Init5_98* arg)
{
    La98 la;
    *(Init5_98*)(p + 13620) = *arg;
    u8 kind = (*(u8**)(arg->obj + 2808))[4];
    *(u32*)(p + 8236) = kind;
    if (func_002cb200(p + 8272, kind, p + 8248)) *(s32*)(p + 8244) = 1;
    else *(s32*)(p + 8244) = 0;
    func_0023f800(&la);
    u8* lay = p + 28;
    *(u32*)(p + 8232) = func_001708f8_4e98(res, -1);
    func_0023fa08(&la, *(u32*)(p + 8232));
    u32 w = func_0023f948(&la, 0);
    u32 h = func_0023f908(&la, 0);
    Tz__Layout__create(lay, 30001, w, h, func_002c3240_4e98(p, 0), 0);
    Tz__Layout__SetImageCache(lay);
    func_0023f0c8(lay, func_002c3240_4e98(p, 2));
    *(u32*)(p + 13640) = func_0023c4b8_4e98(func_0023f1b0_4e98(lay), 1);
    *(u32*)(p + 13644) = func_00236ca8_4e98(*(u32*)(func_0023f1b0_4e98(lay) + 40), 1);
    if (func_002c5120(p)) {
        func_002cb0e8_4e98(arg, D_01e2bd30, 0.0f);
        func_002c44b8(p);
    } else {
        func_002cb0e8_4e98(arg, D_01e2bd20, 0.0f);
        func_002c4ca8(p);
    }
    if (func_002c5120(p)) {
        u8* o = p + 188;
        Ent98* e = D_00375630;
        s32 i;
        for (i = 0; i < 9; i++) {
            func_0023f1e0_4e98(o, 30005, lay, func_002c3268_4e98(p), e, e->a, 0, 0);
            func_00139620(o);
            func_001395e8_4e98(o);
            func_001395f8(o);
            func_0023f6c0_4e98(o, e->b);
            o += 76;
            e++;
        }
        func_0023f618(p + 720, func_002c24e0(*(u32*)(p + 8236)));
        func_00139638_4e98(p + 720);
        func_0023f618(p + 796, func_002c2518(*(u32*)(p + 8236)));
        func_00139638_4e98(p + 796);
    }
    func_001391c8_4e98(p, 30002, 0);
    func_0023f848(&la);
}
}  // namespace n002c4e98

// ---- 002c5120 from src/worldmap/wm_landing_info.cpp
namespace n002c5120 {
bool WM_LANDING_isListType(u8* t) asm("_ZN2dk10WM_LANDING10isListTypeEv");
bool WM_LANDING_isListType(u8* t) { return *(u32*)((u32)t + 8244) != 0; }
}  // namespace n002c5120

// ---- 002c5130 from src/worldmap/wm_landing_info.cpp
namespace n002c5130 {
bool WM_LANDING_isEpisodeType(u8* t) asm("_ZN2dk10WM_LANDING13isEpisodeTypeEv");
bool WM_LANDING_isEpisodeType(u8* t) { return ((*(u32*)((u32)t + 8244) ^ 2u) == 0); }
}  // namespace n002c5130

// ---- 002c5140 from src/anon/tiny.cpp
namespace n002c5140 {
u32 func_002c5140(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c5140jjjj");
u32 func_002c5140(u32 a0, u32 a1, u32 a2, u32 a3) {                  
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = *(u32*)((u32)a0 + (24));
    v &= 0x0002u;
    return (v != 0);
}
}  // namespace n002c5140

// ---- 002c5150 from src/anon/tiny_auto80_queue.cpp
namespace n002c5150 {
u32 func_002c5140(...) asm("func_002c5140");
u32 func_002c5150() asm("_Z13func_002c5150v");
u32 func_002c5150() {
    u32* base = (u32*)0x00360000;
    u32 v = *(u32*)((u8*)base + 0x1c10);
    if (v != 0) {
        if (func_002c5140(v) != 0) {
            return 1;
        }
    }
    return 0;
}
}  // namespace n002c5150

// ---- 002c5190 from src/anon/auto80_199_queue.cpp
namespace n002c5190 {
void func_002c5190(u32 a0) asm("_Z13func_002c5190j");
void func_002c5190(u32 a0) {
    if (D_00361c10 != 0) {
        return;
    }

    func_00138480(0);
    func_0014f2d8();

    u32 t6 = D_00347f80;
    u32 obj = *(u32*)(t6 + 20);
    u32 vt = *(u32*)obj;
    u32 s0 = ((u32 (*)(u32, u32, u32))*(u32*)(vt + 0))(obj, 14096, 0);
    dk__WM_LANDING__WM_LANDING(s0);
    u32 v0 = worldmap__Manager__get2ldFile();
    dk__WM_LANDING__create(s0, v0, a0);
    func_002cac40(3);
}
}  // namespace n002c5190

// ---- 002c5238 from src/anon/batch_w40.cpp
namespace n002c5238 {
s32 func_002c5238(s32 n, s32 count, s32* out) asm("func_002c5238");
s32 func_002c5238(s32 n, s32 count, s32* out) {
    s32 nz = 0;
    s32 i = count - 1;
    do {
        if (n == 0) out[i] = 0;
        else { nz++; out[i] = n % 10; n /= 10; }
    } while (--i >= 0);
    return nz ? nz : 1;
}
}  // namespace n002c5238

// ---- 002c5298 from src/anon/batch_w245.cpp
namespace n002c5298 {
inline void* operator new(unsigned int, void* p) { return p; }
struct V4 { f32 x, y, z, w; V4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
extern V4 D_01e2bd20 asm("D_01e2bd20");
extern V4 D_01e2bd30 asm("D_01e2bd30");
extern V4 D_01e2bd40 asm("D_01e2bd40");
void wtarget_002c5298(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002c5298jjjj");
void wtarget_002c5298(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (a1 == 0xffff && a0 == 1) new (&D_01e2bd20) V4(0.0f, 0.0f, 1.0f, 0.0f);
    if (a1 == 0xffff && a0 == 1) new (&D_01e2bd30) V4(-120.0f, 40.0f, 1.3f, 0.0f);
    if (a1 == 0xffff && a0 == 1) new (&D_01e2bd40) V4(200.0f, 0.0f, 1.2f, 0.0f);
}
}  // namespace n002c5298

// 002c5378 / 002c5380 (gap, never written): the two empty atexit thunks (__tcf_0, __tcf_1) of the
// function-local static vectors in 002c3638 (whole-asm, src/anon/batch_w3953.s, which calls them by
// address). gcc places such thunks after the static initialiser.
namespace n002c5378 {
void func_002c5378() asm("func_002c5378");
void func_002c5378() {}
void func_002c5380() asm("func_002c5380");
void func_002c5380() {}
}  // namespace n002c5378

// ---- 002c5388 from src/anon/tiny_wrappers_more.cpp (_GLOBAL__I_ stub)
namespace n002c5388 {
u32 func_002c5298(u32, u32, u32, u32) asm("_Z16wtarget_002c5298jjjj");
u32 func_002c5388(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c5388jjjj");
u32 func_002c5388(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002c5298(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002c5388

// 002c53a8 (gap, never written): the _GLOBAL__D_ stub.
namespace n002c53a8 {
u32 func_002c5298(u32, u32, u32, u32) asm("_Z16wtarget_002c5298jjjj");
u32 func_002c53a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c53a8");
u32 func_002c53a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002c5298(0, 0x0000ffffu, a2, a3);
}
}  // namespace n002c53a8

