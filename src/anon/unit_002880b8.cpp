// Linked unit 0x002880b8-0x00288b00 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
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
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/cmenu_newflg.hpp"
#include "../tozawa/cmenu_slbase.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tz/ui_accessors.hpp"
#include "../tozawa/cmenu_item.hpp"

// 002880b8 (was src/anon/batch_w3715_g.cpp)
namespace n002880b8 {
s32 func_00103570(void) asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
void func_0023f800(s32) asm("func_0023f800");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(s32) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void func_00239700(void*) asm("func_00239700");
void YI__LAYOUT__LAYOUT(s32) asm("YI__LAYOUT__LAYOUT");
u8* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(s32, s32, s32, void*, s32) asm("TASK_MANAGER__create_thread");
struct Alloc;
struct AllocVt { void* (*alloc)(Alloc*, s32, s32); };
struct Alloc { AllocVt* vt; };
struct Holder { u8 pad[0x14]; s32 a; };
extern Holder* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00288308[] asm("D_00288308");
extern s16 D_0035f32c asm("D_0035f32c");
extern s16 D_0035f32e asm("D_0035f32e");
extern u8 D_0035f328 asm("D_0035f328");
extern void* D_0035f338 asm("D_0035f338");
extern s32 D_0035f33c asm("D_0035f33c");
extern s32 D_0035f340 asm("D_0035f340");
/*TARGET 002880b8*/
// Startup: creates the managers kept in D_0035f334..D_0035f340 and starts a thread.
void Tz__MenuBasic__Init(void) asm("Tz__MenuBasic__Init");
// Startup: creates the managers kept in D_0035f334..D_0035f340 and starts a thread.
void Tz__MenuBasic__Init(void) {
    D_0035f32c = -1;
    D_0035f32e = -1;
    s32 r = func_001063c0(0x1C, func_00103570());
    func_0023f800(r);
    Holder* h = D_00347f80;
    // The original loads D_00347f80 before this store and its field after it: the store
    // goes through a hidden high half pinned to t7, the register the original uses.
    register u32 hs asm("$15") = 0x360000; asm("" : "+r"(hs));
    *(s32*)(hs - 3276) = r;
    Alloc* a = (Alloc*)h->a;
    u8* p = (u8*)a->vt->alloc(a, 0x198, 0);
    *(s32*)(p + 0xC) = 0;
    *(void**)p = D_00347e60;
    func_00239700(p + 0x18);
    D_0035f338 = p;
    r = func_001063c0(0x18, func_00103570());
    YI__IMAGE_FREEZE__IMAGE_FREEZE(r);
    D_0035f33c = r;
    r = func_001063c0(0x5C, func_00103570());
    YI__LAYOUT__LAYOUT(r);
    D_0035f340 = r;
    D_0035f328 = 0;
    TASK_MANAGER__create_thread(*(s32*)(func_00103eb0() + 4), 0, 0x7CE, D_00288308, 0x1000);
}
}  // namespace n002880b8

// 002881c0 (was src/anon/batch_w268.cpp)
namespace n002881c0 {
struct W268VObj { void (**vt)(W268VObj*); };
struct W268FnHolder { u8 pad[8]; void (*fn)(void); };
extern u8 D_0035f328 asm("D_0035f328");
extern s16 D_0035f32a asm("D_0035f32a");
extern s16 D_0035f32c asm("D_0035f32c");
extern s16 D_0035f32e asm("D_0035f32e");
extern W268VObj* D_0035f334 asm("D_0035f334");
extern W268VObj* D_0035f338 asm("D_0035f338");
extern W268VObj* D_0035f33c asm("D_0035f33c");
extern W268VObj* D_0035f340 asm("D_0035f340");
extern s32 D_0035f344 asm("D_0035f344");
extern u8 D_0035f3a8[] asm("D_0035f3a8");
extern s32 func_00103398(s32) asm("func_00103398");
extern s32 func_001033b0(s32) asm("func_001033b0");
extern W268FnHolder* func_00253330(s32) asm("func_00253330");
extern W268FnHolder* func_00243150(s32) asm("func_00243150");
extern void func_0023fad0(void*) asm("func_0023fad0");
/*TARGET 002881c0*/
void func_002881c0(void) asm("func_002881c0");
void func_002881c0(void)
{
    if (D_0035f328) {
        s32 id = func_00103398(D_0035f32a);
        if (func_001033b0(D_0035f32a) != 1) {
            func_00253330(id)->fn();
        } else {
            func_00243150(id)->fn();
            func_0023fad0(D_0035f3a8);
        }
    }
    if (D_0035f334) { D_0035f334->vt[1](D_0035f334); D_0035f334 = 0; }
    if (D_0035f338) { D_0035f338->vt[4](D_0035f338); D_0035f338 = 0; }
    if (D_0035f33c) { D_0035f33c->vt[1](D_0035f33c); D_0035f33c = 0; }
    if (D_0035f340) { D_0035f340->vt[1](D_0035f340); D_0035f340 = 0; }
    D_0035f32a = -1;
    D_0035f344 = 0;
    D_0035f32c = -1;
    D_0035f328 = 0;
    D_0035f32e = -1;
}
}  // namespace n002881c0

// 00288308 (was gap, written for the unit)
namespace n00288308 {
void func_00288610(void) asm("func_00288610");
void func_00102448(void*, s32) asm("func_00102448");
void func_00288370(void) asm("_ZN2Tz9MenuBasic5SetupEv");
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
s32 func_00288400(void*) asm("func_00288400");
void func_002885d0(void*, s32) asm("func_002885d0");
void func_00288308(void* t) asm("func_00288308");
void func_00288308(void* t) {
    func_00288610();
    func_00102448(t, 1);
    func_00288370();
    for (;;) {
        YI__IMAGE_CACHE__Clear();
        if (func_00288400(t)) { func_002885d0(t, 0); return; }
        func_00102448(t, 0);
    }
}
}  // namespace n00288308

// 00288370 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00288370
extern u32 D_0035f334 asm("D_0035f334");
extern u32 D_0035f33c asm("D_0035f33c");
extern u32 D_0035f340 asm("D_0035f340");
u32 func_0023f948(...) asm("func_0023f948");
u32 func_0023f908(...) asm("func_0023f908");
u32 func_00103570(...) asm("func_00103570");
void func_00236a58(...) asm("func_00236a58");
void func_0023c100(...) asm("func_0023c100");
/*TARGET 00288370*/
void MenuBasic::Setup() {
    u32 s2 = func_0023f948(D_0035f334, 0);
    u32 s0 = func_0023f908(D_0035f334, 0);
    u32 t = func_00103570();

    func_00236a58(D_0035f33c, s0, t);
    t = func_00103570();

    func_0023c100(D_0035f340, s2, D_0035f33c, t);
}
}  // Tz

// 002883f8 (was src/anon/misc_2.cpp)
namespace n002883f8 {
/*TARGET 002883f8*/
void func_002883f8(void* self) asm("_Z13func_002883f8Pv");
void func_002883f8(void* self) {}
}  // namespace n002883f8

// 00288400 (was src/anon/auto80_199_queue.cpp)
namespace n00288400 {
/*TARGET 00288400*/
u32 func_00288400(u32 a0) asm("_Z13func_00288400j");
u32 func_00288400(u32 a0) {
    if (D_0035f32a < 0) {
        func_001039f8();
        return 1;
    }

    if (func_00287db0() != 0) {
        func_00287ad0();
    }

    D_0035f328 = 1;
    func_00288478(a0);
    D_0035f328 = 0;
    return 0;
}
}  // namespace n00288400

// 00288478 (was src/anon/batch_w92.cpp)
namespace n00288478 {
struct VT288 { void (*f0)(void); void (*f4)(void); void (*f8)(void); };
void func_002883f8(void*) asm("func_002883f8");
void func_00102448(void*, s32) asm("func_00102448");
s32 func_00103398(s16) asm("func_00103398");
s32 func_001033b0(s16) asm("func_001033b0");
void func_00242fa0(void) asm("func_00242fa0");
VT288* func_00243150(s32) asm("func_00243150");
void func_002530c8(void) asm("func_002530c8");
// set_state_30012
VT288* func_00253330(s32) asm("func_00253330");
void func_00103ea0(void (*)(void)) asm("func_00103ea0");
// set_hook_ptr
void func_00288638(void) asm("func_00288638");
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
void func_00288870(void) asm("func_00288870");
void func_0023fad0(void*) asm("func_0023fad0");
extern s16 D_0035f32a asm("D_0035f32a");
extern s16 D_0035f32c asm("D_0035f32c");
extern s16 D_0035f32e asm("D_0035f32e");
extern u8 D_0035f330 asm("D_0035f330");
extern u8 D_0035f3a8 asm("D_0035f3a8");
/*TARGET 00288478*/
void func_00288478(void* ctx) asm("func_00288478");
void func_00288478(void* ctx) {
    func_002883f8(ctx);
    func_00102448(ctx, 1);
    s32 id = func_00103398(D_0035f32a);
    s32 kind = func_001033b0(D_0035f32a);
    if (kind != 1) {
        func_002530c8();  // set_state_30012
        func_00253330(id)->f4();
    } else {
        func_00242fa0();
        func_00243150(id)->f4();
    }
    D_0035f330 = 0;
    func_00103ea0(func_00288638);  // set_hook_ptr
    for (;;) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        func_00288870();
        if (D_0035f330) break;
        func_00102448(ctx, 0);
    }
    if (kind != 1) {
        func_00253330(id)->f8();
    } else {
        func_00243150(id)->f8();
        func_0023fad0(&D_0035f3a8);
    }
    D_0035f32a = D_0035f32c;
    D_0035f32c = D_0035f32e;
    D_0035f32e = -1;
}
}  // namespace n00288478

// 002885d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002885d0 {
extern void* D_0035f338 asm("D_0035f338");
u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 002885d0*/
void func_002885d0() asm("_Z13func_002885d0v");
void func_002885d0() {
    if (func_00139d78(D_0035f338) != 0u) {
        void* p = D_0035f338;
        ((void (*)(void*))(*(u32*)(*(u32*)p + 20u)))(p);
    }
}
}  // namespace n002885d0

// 00288610 (was src/anon/batch_w7.cpp)
namespace n00288610 {
u32 func_002537c8(u32) asm("func_002537c8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
extern u32 D_0035f334 asm("D_0035f334");
/*TARGET 00288610*/
void func_00288610(void) asm("func_00288610");
void func_00288610(void) {
    func_0023fa08(D_0035f334, func_002537c8(0));
}
}  // namespace n00288610

// 00288638 (was gap, written for the unit)
namespace n00288638 {
extern u8 D_0035f330 asm("D_0035f330");
void func_00288638(void) asm("func_00288638");
void func_00288638(void) {
    D_0035f330 = 1;
}
}  // namespace n00288638

// 00288648 (was src/anon/tiny.cpp)
namespace n00288648 {
/*TARGET 00288648*/
void func_00288648(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00288648jjjj");
void func_00288648(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u16*)((u32)b + (-3286)) = (u16)a0;
}
}  // namespace n00288648

// 00288658 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00288658
extern u32 D_0035f32c asm("D_0035f32c");
extern u32 D_0035f32e asm("D_0035f32e");
/*TARGET 00288658*/
void MenuBasic::SetNextMenu(s32 nextMenu, s32 nextMenu2) {
    *(u16*)&D_0035f32c = (u16)nextMenu;
    *(u16*)&D_0035f32e = (u16)nextMenu2;
}
}  // Tz

// 00288670 (was src/anon/batch_w246.cpp)
namespace n00288670 {
struct W246Sub { u8 pad[184]; u32 flags; inline void set(u32 f) { flags |= f; } };
struct W246Obj { u8 pad[24]; W246Sub sub; };
union W246UP { u8* c; W246Obj* o; s32* i; };
s32 isPause(void) asm("_ZN2Tz5Pause7isPauseEv");
void StartFade(void (*)()) asm("_ZN2Tz5Pause9StartFadeEPFvvE");
void u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void* GetSequenceUnit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
u8* GetImage(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void dk__Sprite__create(void*, s32, void*, void*, s32, s32) asm("dk__Sprite__create");
extern W246UP D_0035f338 asm("D_0035f338");
extern void* D_0035f33c asm("D_0035f33c");
extern void* D_0035f340 asm("D_0035f340");
extern void (*D_0035f344)() asm("D_0035f344");
/*TARGET 00288670*/
void func_00288670(void (*cb)()) asm("func_00288670");
void func_00288670(void (*cb)()) {
    if (isPause()) {
        StartFade(cb);
        return;
    }
    s32 on = 1;
    u_call4_00139d78(D_0035f338.c);
    void* seq = GetSequenceUnit(D_0035f340, 0);
    u8* img = GetImage(D_0035f33c, 0);
    img[400] = on;
    dk__Sprite__create(D_0035f338.c, 30036, seq, img, 5, 0);
    *(s32*)(D_0035f338.c + 392) = on;
    D_0035f338.o->sub.set(8);
    D_0035f338.c[405] = on;
    D_0035f344 = cb;
}
}  // namespace n00288670

// 00288750 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00288750
extern u32 D_0035f338 asm("D_0035f338");
extern u32 D_0035f344 asm("D_0035f344");
u32 func_00139d78(u32) asm("func_00139d78");
void func_00138c10(u32, u32) asm("func_00138c10");
u32 func_00258cd8(...) asm("func_00258cd8");
void func_00258bc0(u32) asm("func_00258bc0");
/*TARGET 00288750*/
void MenuBasic::EndFade(void (*cb)()) {
    u32 s1 = (u32)cb;
    if (func_00258cd8(s1) != 0) {
        func_00258bc0(s1);
        return;
    }

    func_00139d78(D_0035f338);
    func_00138c10(D_0035f338, 4);
    *(u32*)(D_0035f338 + 392) = 0xFFFFFFFFu;
    D_0035f344 = s1;
}
}  // Tz

// 002887c8 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 002887c8
extern u32 D_0035f338 asm("D_0035f338");
u32 func_00139d78(u32) asm("func_00139d78");
u32 func_00258cd8(...) asm("func_00258cd8");
u32 func_00258c18(...) asm("func_00258c18");
/*TARGET 002887c8*/
u32 MenuBasic::isExistFade() {
    u32 t5 = 0;

    if (func_00258cd8() != 0) {
        t5 = func_00258c18();
        goto ret;
    }

    {
        u32 t7 = D_0035f338;
        if (t7 != 0) {
            t5 = func_00139d78(t7);
        }
    }

ret:
    return t5;
}
}  // Tz

// 00288820 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 00288820
u32 func_00139d78(u32) asm("func_00139d78");
u32 func_00258cd8(...) asm("func_00258cd8");
u32 func_00258c48(...) asm("func_00258c48");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 00288820*/
u32 MenuBasic::CheckFade() {
    u32 v0;
    if (func_00258cd8() != 0u) {
        v0 = func_00258c48();
    } else {
        func_00139d78(*(u32*)((u8*)&D_00360000 - 3272u));
        u32 t6 = *(u32*)((u8*)&D_00360000 - 3272u);
        v0 = (*(u32*)(t6 + 388u)) == 1u;
    }
    return v0;
}
}  // Tz

// 00288870 (was src/anon/auto80_199_queue.cpp)
namespace n00288870 {
/*TARGET 00288870*/
void func_00288870(void) asm("_Z13func_00288870v");
void func_00288870(void) {
    if (D_0035f344 == 0) {
        return;
    }

    if (func_00139d78(D_0035f338) != 0) {
        if (func_00288820() == 0) {
            return;
        }
    }

    ((void(*)(void))D_0035f344)();
    D_0035f344 = 0;
}
}  // namespace n00288870

// 002888c8 (was src/tozawa/cmenu_slbase.cpp)
namespace Tz { // method 002888c8
extern u16 D_0035f32a asm("D_0035f32a");
s32 func_00103398(u32) asm("func_00103398");
/*TARGET 002888c8*/
s32 MenuBasic::GetMenuId() {
    s32 a0 = (s16)D_0035f32a;
    s32 v0 = -1;
    if (a0 >= 0) {
        v0 = (s32)func_00103398((u32)a0);
    }
    return v0;
}
}  // Tz

// 002888f8 (was src/anon/batch_w83.cpp)
namespace n002888f8 {
void func_00288c58(void*, s16) asm("func_00288c58");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_0028af18(void*, s32) asm("func_0028af18");
void func_0028b1b0(void*, s32) asm("func_0028b1b0");
union S16Ptr { s16* p; s16 h; };
struct Grid { s16 h0, h2, h4, pad6, pad8, pad10, pad12, h14, h16, h18, h20, h22, h24, h26, h28, pad30, pad32, pad34; u8 b36, b37, b38, b39; u32 pad40; S16Ptr f44; S16Ptr f48; };
/*TARGET 002888f8*/
void func_002888f8(Grid* g, s32 n, u8 kind) asm("func_002888f8");
void func_002888f8(Grid* g, s32 n, u8 kind) {
    g->h0 = 0;
    g->h16 = n;
    g->h2 = -1;
    g->h28 = 1;
    g->b36 = kind;
    g->h20 = -1;
    g->h4 = 0;
    g->h18 = 0;
    g->h22 = 0;
    g->h24 = 0;
    g->h26 = 0;
    g->b37 = 0;
    g->b38 = 0;
    g->b39 = 0;
    func_00288c58(g, n);
    func_00288f48(g, 16, 32, 0, 0);
    for (s32 i = 0; i < g->h16; i++) {
        for (s32 j = 0; j < 4; j++) {
            g->f44.p[i * 4 + j] = -1;
            g->f48.p[i * 4 + j] = -1;
        }
    }
    g->h14 = 0;
    func_0028af18(g, 115);
    func_0028b1b0(g, 0);
}
}  // namespace n002888f8

// 002889f0 (was src/anon/batch_w84.cpp)
namespace n002889f0 {
void func_00288c58(void*, s16) asm("func_00288c58");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_0028af18(void*, s32) asm("func_0028af18");
void func_0028b1b0(void*, s32) asm("func_0028b1b0");
union PU { s16 (*p)[4]; s16 s; };
struct Tbl {
    s16 f0, f2, f4, f6_, f8_, f10_, f12_, f14;
    s16 n, f18, f20, f22, f24, f26, f28, f30;
    u32 f32_;
    u8 c36, c37, c38, c39;
    u32 f40;
    PU a;
    PU b;
};
/*TARGET 002889f0*/
void func_002889f0(Tbl* p, s32 n, u8 c) asm("func_002889f0");
void func_002889f0(Tbl* p, s32 n, u8 c) {
    p->f0 = 0;
    p->n = n;
    p->f2 = -1;
    p->f28 = 1;
    p->c36 = c;
    p->f20 = -1;
    p->f4 = 0;
    p->f18 = 0;
    p->f22 = 0;
    p->f24 = 0;
    p->f26 = 0;
    p->c37 = 0;
    p->c38 = 0;
    p->c39 = 0;
    func_00288c58(p, n);
    func_00288f48(p, 16, 32, 0, 0);
    for (s32 i = 0; i < p->n; i++) {
        for (s32 j = 0; j < 4; j++) {
            p->a.p[i][j] = -1;
            p->b.p[i][j] = -1;
        }
    }
    p->f14 = 0;
    func_0028af18(p, 115);
    func_0028b1b0(p, 0);
}
}  // namespace n002889f0

// 00288ae8 (was gap, written for the unit)
namespace n00288ae8 {
u32 func_00288ca8(u32, u32, u32, u32) asm("func_00288ca8");
u32 func_00288ae8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00288ae8");
u32 func_00288ae8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00288ca8(a0, a1, a2, a3);
}
}  // namespace n00288ae8

