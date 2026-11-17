#include "../common/types.h"
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
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../worldmap/libretto.hpp"
#include "../worldmap/rootwindow.hpp"
#include "../worldmap/messagewidget.hpp"
#include "../ohori/sebank.hpp"

// ---- 002bebd0 from src/anon/batch_w44.cpp
namespace n002bebd0 {
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
void func_002bebd0(void*, u8* o) asm("func_002bebd0");
void func_002bebd0(void*, u8* o) {
    s32 c = 0;
    f32 f = *(f32*)(o + 28);
    if (0.0f < f && !(f < (*(f32*)(o + 272) + *(f32*)(o + 276)) * 0.5f)) c = 153;
    func_0017f540(o + 320, c, 8.0f, 0.0f);
}
}  // namespace n002bebd0

// ---- 002bec38 from src/anon/batch_w23.cpp
namespace n002bec38 {
void func_00184540(void*, void*, f32, f32) asm("func_00184540");
void* func_002bec38(void* a, void*, u8* c) asm("func_002bec38");
void* func_002bec38(void* a, void*, u8* c) {
    u8* t = *(u8**)(c + 300);
    func_00184540(a, c, *(f32*)(t + 40), *(f32*)(t + 44));
    return a;
}
}  // namespace n002bec38

// ---- 002bec70 gap
namespace n002bec70 {
void func_002bec70(void*, u8* o) asm("func_002bec70");
void func_002bec70(void*, u8* o) {
    *(u32*)(o + 264) |= 0x4000000;
}
}  // namespace n002bec70

// ---- 002bec88 from src/anon/batch_w76.cpp
namespace n002bec88 {
void func_002edf28(u8*) asm("func_002edf28");
u8* func_001050d8(u32) asm("func_001050d8");
void func_001ad0f8(u8*, u32, s32) asm("func_001ad0f8");
void func_001ad330(u8*, u32) asm("func_001ad330");
extern u8 D_00361980[] asm("D_00361980");
union PtrS { u8* p; s32 i; };
void func_002bec88(u8* o, s32 kind, u32 arg) asm("func_002bec88");
void func_002bec88(u8* o, s32 kind, u32 arg)
{
    func_002edf28(o);                    
    *(u32*)(o + 40) = 0;
    *(u32*)o = (u32)D_00361980;
    switch (kind) {
    case 0: {
        u8* p = func_001050d8(2924);
        func_001ad0f8(p, arg, 0);
        ((PtrS*)(o + 36))->p = p;
        *(s32*)(p + 100) = 2;
        u8* q = ((PtrS*)(o + 36))->p;
        *(s32*)(q + 4) = 256;
        *(s32*)(q + 8) = 48;
        break;
    }
    case 1: {
        u8* p = func_001050d8(4656);
        func_001ad330(p, arg);
        *(u8**)(o + 36) = p;
        break;
    }
    }
}
}  // namespace n002bec88

// ---- 002bed48 from src/anon/batch_w77.cpp
namespace n002bed48 {
extern u8 D_00361980[] asm("D_00361980");
void func_002edf28(u8*) asm("func_002edf28");
u8* func_001050d8(s32) asm("func_001050d8");
void func_001ad0f8(u8*, u32, s32) asm("func_001ad0f8");
void func_001ad330(u8*, u32) asm("func_001ad330");
void func_002bed48(u8* p, s32 kind, u32 c) asm("func_002bed48");
void func_002bed48(u8* p, s32 kind, u32 c)
{
    func_002edf28(p);                    
    *(u32*)(p + 40) = 0;
    *(u32*)p = (u32)D_00361980;
    switch (kind) {
    case 0: {
        u8* o = func_001050d8(2924);
        func_001ad0f8(o, c, 0);
        *(u32*)(p + 36) = (u32)o;
        *(u32*)(o + 100) = 2;
        u8* q = (u8*)*(u32*)(p + 36);
        *(u32*)(q + 4) = 256;
        *(u32*)(q + 8) = 48;
        break;
    }
    case 1: {
        u8* o = func_001050d8(4656);
        func_001ad330(o, c);
        *(u32*)(p + 36) = (u32)o;
        break;
    }
    }
}
}  // namespace n002bed48

// ---- 002bee08 gap
namespace n002bee08 {
extern u8 D_00361980[] asm("D_00361980");
extern u8 D_003637e0[] asm("D_003637e0");
typedef void (*VFn)(void*);
void func_002bee08(u8* p) asm("func_002bee08");
void func_002bee08(u8* p) {
    *(u8**)p = D_00361980;
    u8* o = *(u8**)(p + 36);
    (*(VFn*)((*(u8**)o) + 12))(o);
    *(u8**)p = D_003637e0;
}
}  // namespace n002bee08

// ---- 002bee58 from src/anon/batch_w35.cpp
namespace n002bee58 {
extern u8 D_00361980[] asm("D_00361980");
extern u8 D_003637e0[] asm("D_003637e0");
typedef void (*VFn)(void*);
void func_002bee58(u8* p) asm("func_002bee58");
void func_002bee58(u8* p) {
    *(u8**)p = D_00361980;
    u8* o = *(u8**)(p + 36);
    (*(VFn*)((*(u8**)o) + 12))(o);
    *(u8**)p = D_003637e0;
}
}  // namespace n002bee58

// ---- 002beea8 from src/anon/batch_w26.cpp
namespace n002beea8 {
inline void* operator new(unsigned int, void* p) { return p; }
void area_free(void*) asm("_ZN4AREA4FreeEPv");
extern u8 D_00361980[] asm("D_00361980");
extern u8 D_003637e0[] asm("D_003637e0");
struct Obj { void (**vt)(Obj*); };
void func_002beea8(u8* o) asm("func_002beea8");
void func_002beea8(u8* o) {
    *(u8**)o = D_00361980;
    Obj* c = *(Obj**)(o + 36);
    (*(void (**)(Obj*))((*(u8**)c) + 12))(c);
    *(u8**)o = D_003637e0;
    area_free(o);
}
}  // namespace n002beea8

// ---- 002beef8 from src/anon/auto80_199_queue.cpp
namespace n002beef8 {
u32 func_002beef8(u8* self) asm("_Z13func_002beef8Ph");
u32 func_002beef8(u8* self) {
    u32 a0 = *(u32*)(self + 36);
    u32 t7 = *(u32*)a0;
    ((void (*)(u32))*(u32*)(t7 + 20))(a0);

    u32 t = *(u32*)(self + 40);
    t = t & 1u;
    if (t) {
        return 1;
    }

    u32 t6 = *(u32*)(self + 36);
    if ((*(u32*)(t6 + 112) ^ 3u) != 0) {
        return 1;
    }

    u32 vt = *(u32*)t6;
    u32 fn = *(u32*)(vt + 32);
    ((void (*)(u32))fn)(t6);
    func_002baa60();
    *(u32*)(self + 40) |= 1u;
    return 1;
}
}  // namespace n002beef8

// ---- 002bef78 from src/anon/batch_w2027_nsa.cpp
namespace n002bef78 {
struct W2027Obj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
};
struct W2027Owner { u8 pad[0x24]; W2027Obj* obj; };
struct W2027Pair { s32 x, y; };
struct W2027Tag { u16 a; u8 b; };
void func_002bef78(W2027Owner* p, W2027Pair v, W2027Tag w) asm("func_002bef78");
void func_002bef78(W2027Owner* p, W2027Pair v, W2027Tag w) {
    p->obj->m4();
}
}  // namespace n002bef78

// ---- 002befa8 from src/worldmap/messagewidget.cpp
namespace worldmap {
u32 MessageWidget::isEnd() {
    u32 p = *(u32*)((u32)this + 36);
    u32 v = *(u32*)((u32)p + 112);
    v ^= 0x7u;
    return (v < 1u);
}
}  // namespace worldmap

// ---- 002befc0 from src/anon/batch_w76.cpp
namespace n002befc0 {
void* func_001050c8(void) asm("func_001050c8");
void func_002edf28(u8*) asm("func_002edf28");
void func_002369a0(u8*) asm("func_002369a0");
void func_0023c008(u8*) asm("func_0023c008");
extern u8 D_00363880[] asm("D_00363880");
extern u8 D_003619a8[] asm("D_003619a8");
extern u32 D_00361998 asm("D_00361998");
u8* func_002beb90(void) asm("func_002beb90");
u32 func_001708f8(u8*, s32) asm("func_001708f8");
u8* func_00168b38(u32, s32, s32) asm("func_00168b38");
void func_002ef1f8(u8*, u32, u32) asm("func_002ef1f8");
void func_002bf308(void) asm("func_002bf308");
void func_00102c18(s32, u32, void*) asm("func_00102c18");
void func_002befc0(u8* o) asm("func_002befc0");
void func_002befc0(u8* o)
{
    u32 v = (u32)func_001050c8();
    func_002edf28(o);                    
    *(u32*)(o + 36) = v;
    *(u32*)o = (u32)D_00363880;
    func_002369a0(o + 40);                    
    func_0023c008(o + 64);                    
    *(u32*)o = (u32)D_003619a8;
    D_00361998 = (u32)o;
    *(u32*)(o + 156) = func_001708f8(func_002beb90(), -1);
    u8* x = func_00168b38(*(u32*)(o + 156), 28, 0);                         
    u8* y = func_00168b38(*(u32*)(o + 156), 29, 0);                         
    func_002ef1f8(o, *(u32*)(x + 8), *(u32*)(y + 8));
    *(u32*)(o + 4) |= 1;
    func_00102c18(1, 0x19258, (void*)func_002bf308);
}
}  // namespace n002befc0

// ---- 002bf098 from src/anon/batch_w77.cpp
namespace n002bf098 {
extern u8 D_00363880[] asm("D_00363880");
extern u8 D_003619a8[] asm("D_003619a8");
extern u8* D_00361998 asm("D_00361998");
extern u8 D_002bf308 asm("D_002bf308");
u32 func_001050c8(void) asm("func_001050c8");
void func_002edf28(u8*) asm("func_002edf28");
void func_002369a0(u8*) asm("func_002369a0");
void func_0023c008(u8*) asm("func_0023c008");
u32 func_002beb90(void) asm("func_002beb90");
u32 func_001708f8(u32, s32) asm("func_001708f8");
u8* func_00168b38(u32, s32, s32) asm("func_00168b38");
void func_002ef1f8(u8*, u32, u32) asm("func_002ef1f8");
void func_00102c18(s32, s32, void*) asm("func_00102c18");
void func_002bf098(u8* p) asm("func_002bf098");
void func_002bf098(u8* p)
{
    u32 m = func_001050c8();
    func_002edf28(p);                    
    *(u32*)(p + 36) = m;
    *(u32*)p = (u32)D_00363880;
    func_002369a0(p + 40);                    
    func_0023c008(p + 64);                    
    *(u8**)p = D_003619a8;
    D_00361998 = p;
    *(u32*)(p + 156) = func_001708f8(func_002beb90(), -1);
    u8* a = func_00168b38(*(u32*)(p + 156), 28, 0);                         
    u8* b = func_00168b38(*(u32*)(p + 156), 29, 0);                         
    func_002ef1f8(p, *(u32*)(a + 8), *(u32*)(b + 8));
    *(u32*)(p + 4) |= 1;
    func_00102c18(1, 0x19258, &D_002bf308);
}
}  // namespace n002bf098

// ---- 002bf170 gap
namespace n002bf170 {
extern u8 D_003619a8 asm("D_003619a8");
extern u32 D_00361998 asm("D_00361998");
extern u8 D_00363880 asm("D_00363880");
extern u8 D_003637e0 asm("D_003637e0");
void func_00170950(u32) asm("_ZN2YS10CACHE_BUFF4FreeEPv");
void func_0023c098(void*) asm("func_0023c098");
void func_002369f0(void*) asm("func_002369f0");
void func_002bf170(u8* self) asm("func_002bf170");
void func_002bf170(u8* self) {
    *(u32*)(self + 0) = (u32)&D_003619a8;
    D_00361998 = 0;

    u32 obj = *(u32*)(self + 8);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(u32))*(u32*)(vt + 4))(obj);
    }

    func_00170950(*(u32*)(self + 156));
    *(u32*)(self + 0) = (u32)&D_00363880;
    func_0023c098((void*)(self + 64));
    func_002369f0((void*)(self + 40));
    *(u32*)(self + 0) = (u32)&D_003637e0;
}
}  // namespace n002bf170

// ---- 002bf1f0 from src/anon/auto80_199_queue.cpp
namespace n002bf1f0 {
void func_002bf1f0(u8* self) asm("_Z13func_002bf1f0Ph");
void func_002bf1f0(u8* self) {
    *(u32*)(self + 0) = (u32)&D_003619a8;
    D_00361998 = 0;

    u32 obj = *(u32*)(self + 8);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(u32))*(u32*)(vt + 4))(obj);
    }

    func_00170950(*(u32*)(self + 156));
    *(u32*)(self + 0) = (u32)&D_00363880;
    func_0023c098((void*)(self + 64));                              
    func_002369f0((void*)(self + 40));                              
    *(u32*)(self + 0) = (u32)&D_003637e0;
}
}  // namespace n002bf1f0

// ---- 002bf270 from src/anon/auto80_199_queue.cpp
namespace n002bf270 {
u32 func_002bf270(u8* self) asm("_Z13func_002bf270Ph");
u32 func_002bf270(u8* self) {
    *(u32*)(self + 0) = (u32)&D_003619a8;
    D_00361998 = 0;

    u32 obj = *(u32*)(self + 8);
    if (obj != 0) {
        u32 vt = *(u32*)obj;
        ((void (*)(u32))*(u32*)(vt + 4))(obj);
    }

    func_00170950(*(u32*)(self + 156));
    *(u32*)(self + 0) = (u32)&D_00363880;
    func_0023c098((void*)(self + 64));                              
    func_002369f0((void*)(self + 40));                              
    *(u32*)(self + 0) = (u32)&D_003637e0;
    return func_00105110(self);
}
}  // namespace n002bf270

// ---- 002bf2f8 from src/worldmap/root_window.cpp
namespace worldmap {
void* RootWindow::get() {
    u32 b = (0x0036u << 16);
    return reinterpret_cast<void*>(*(u32*)((u32)b + (6552)));
}
}  // namespace worldmap

// ---- 002bf308 from src/anon/batch_w1771_nsa.cpp
namespace n002bf308 {
struct Pos2bf3 { s32 x, y; Pos2bf3(s32 a, s32 b) { x = a; y = b; } };
struct Col2bf3 { u8 r, g, b, a; Col2bf3(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; } };
struct Drw2bf3 { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void draw(Pos2bf3, Col2bf3); };
extern Drw2bf3* D_00361998 asm("D_00361998");
void func_001024a8(void) asm("func_001024a8");
void func_00236d60(void) asm("func_00236d60");
s32 func_002ee040(Drw2bf3*) asm("func_002ee040");
void func_002bf308(void) asm("func_002bf308");
void func_002bf308(void) {
    if (D_00361998 == 0) {
        func_001024a8();
        return;
    }
    func_00236d60();
    if (func_002ee040(D_00361998)) {
        D_00361998->draw(Pos2bf3(0, 0), Col2bf3(0x80, 0x80, 0x80, 0x80));
    }
    func_00236d60();
}
}  // namespace n002bf308

extern "C" const u32 D_00375420[24] = {
    0x000003a2, 0x00092802,
    0x000003a3, 0x00002a04,
    0x000003a4, 0x00010008,
    0x000003a5, 0x00020005,
    0x000003a6, 0x00050006,
    0x000003a7, 0x0000320c,
    0x000003a8, 0x0007000b,
    0x000003a9, 0x00080010,
    0x000003aa, 0x0003000e,
    0x000003ab, 0x00040007,
    0x000003ac, 0x0006000a,
    0x00000456, 0x00000012,
};

// ---- 002bf398 gap
namespace n002bf398 {
struct Ent_2bf398 { s32 id; u8 b4; u8 pad[3]; };
struct Sub_2bf398 { u8 a, b, c; };
struct Obj_2bf398 {
    void* vt;
    u8 p0[0x584];
    u32 flags;
    u8 p1[0xAE4 - 0x58C];
    Sub_2bf398 sub;
    u8 ae7;
    u8 p2[8];
    f32 af0;
    f32 af4;
    Ent_2bf398* ent;
    s32 afc, b00, b04, b08;
};
extern u8 D_003619c8[] asm("D_003619c8");
extern Ent_2bf398 D_00375420[] asm("D_00375420");
void func_002be770(Obj_2bf398*) asm("func_002be770");
s32 func_001b6d70(u8) asm("func_001b6d70");
void func_002bf650(Obj_2bf398*, s32) asm("func_002bf650");
void func_002bf398(Obj_2bf398* p, s32* key) asm("func_002bf398");
void func_002bf398(Obj_2bf398* p, s32* key) {
    func_002be770(p);
    p->sub.a = 0;
    p->vt = D_003619c8;
    Sub_2bf398* s = &p->sub;
    s->b = 0; s->c = 0;
    p->ae7 = 0;
    p->af4 = p->af0 = 0.0f;
    p->flags |= 0x80000000;
    p->ent = 0;
    p->afc = 0;
    p->b00 = 0;
    p->b04 = 0;
    p->b08 = 0;
    for (u32 i = 0; i < 12; i++) {
        if (D_00375420[i].id == *key) { p->ent = &D_00375420[i]; break; }
    }
    func_002bf650(p, func_001b6d70(p->ent->b4));
}
}  // namespace n002bf398

// ---- 002bf468 from src/anon/batch_w1798_nsa.cpp
namespace n002bf468 {
struct Ent_2bf468 { s32 id; u8 b4; u8 pad[3]; };
struct Sub_2bf468 { u8 a, b, c; };
struct Obj_2bf468 {
    void* vt;                   
    u8 p0[0x584];
    u32 flags;                  
    u8 p1[0xAE4 - 0x58C];
    Sub_2bf468 sub;             
    u8 ae7;                     
    u8 p2[8];
    f32 af0;                    
    f32 af4;                    
    Ent_2bf468* ent;            
    s32 afc, b00, b04, b08;
};
extern u8 D_003619c8[] asm("D_003619c8");
extern Ent_2bf468 D_00375420[] asm("D_00375420");
void func_002be770(Obj_2bf468*) asm("func_002be770");
s32 func_001b6d70(u8) asm("func_001b6d70");
void func_002bf650(Obj_2bf468*, s32) asm("func_002bf650");
void func_002bf468(Obj_2bf468* p, s32* key) asm("func_002bf468");
void func_002bf468(Obj_2bf468* p, s32* key) {
    func_002be770(p);
    p->sub.a = 0;
    p->vt = D_003619c8;
    Sub_2bf468* s = &p->sub;
    s->b = 0; s->c = 0;
    p->ae7 = 0;
    p->af4 = p->af0 = 0.0f;
    p->flags |= 0x80000000;
    p->ent = 0;
    p->afc = 0;
    p->b00 = 0;
    p->b04 = 0;
    p->b08 = 0;
    for (u32 i = 0; i < 12; i++) {
        if (D_00375420[i].id == *key) { p->ent = &D_00375420[i]; break; }
    }
    func_002bf650(p, func_001b6d70(p->ent->b4));
}
}  // namespace n002bf468

// ---- 002bf538 gap
namespace n002bf538 {
void func_0019f490(u8*, s32) asm("func_0019f490");
void func_0016a9a0(u8*) asm("func_0016a9a0");
typedef void (*Msg2bf538)(u8*, s32, s32, u8*, s32);
void func_002bf538(u8* p) asm("func_002bf538");
void func_002bf538(u8* p) {
    if (!(p[2788] < 2) && (p[2791] & 2)) {
        func_0019f490(p + 1140, 1);
        (*(Msg2bf538*)(*(u8**)p + 80))(p, 258, 1, p, 0);
    }
    func_0016a9a0(p);
}
}  // namespace n002bf538

// ---- 002bf5a0 from src/anon/batch_w49.cpp
namespace n002bf5a0 {
struct B2bf5a0 { u8 b0 : 1; };
u8* func_001b6d70(u8) asm("func_001b6d70");
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void func_002bf5a0(u8* p) asm("func_002bf5a0");
void func_002bf5a0(u8* p) {
    u8* v = func_001b6d70((*(u8**)(p + 2808))[4]);                      
    if (!((B2bf5a0*)(p + 2791))->b0 && ((B2bf5a0*)(v + 3))->b0) func_0016ac38(p, 0, 1, 0, 0);
}
}  // namespace n002bf5a0

// ---- 002bf618 from src/anon/batch_w14.cpp
namespace n002bf618 {
s32 func_001b6d70(u8) asm("func_001b6d70");
void func_002bf650(void*, s32) asm("func_002bf650");
void func_002bf618(u8* p) asm("func_002bf618");
void func_002bf618(u8* p) {
    func_002bf650(p, func_001b6d70((*(u8**)(p + 2808))[4]));
}
}  // namespace n002bf618

extern "C" const u32 D_00375480[6] = {0x00000000, 0x80202020, 0x80808080, 0x80808080, 0x80808080, 0x80808080};

// ---- 002bf650 from src/anon/batch_w324.cpp
namespace n002bf650 {
struct W324C4 { u8 r, g, b, a; };
struct W324Sub { u8 pad[4]; u8 kind; u8 id; };
struct W324Obj {
    u8 p0[0x108]; u32 b0:1; u32 b1:1; u32 b2:3; u32 b5:1; u32 b6:1; u32 brest:25;
    u8 p1[0x140 - 0x10c]; u8 mot[0x3ac - 0x140]; W324C4 col;
    u8 p2[0xae4 - 0x3b0]; W324C4 cur;
    u8 p3[0xaf8 - 0xae8]; W324Sub* sub; void* afc; void* b00; u8 p4[4]; u8 eff[4];
};
extern u32 D_00375480[] asm("D_00375480");
void func_002c2228(u8) asm("func_002c2228");
void func_002c2248(u8) asm("func_002c2248");
void func_0017f540(void*, s32, f32, f32) asm("func_0017f540");
void* func_0016abf8(W324Obj*, s32, s32, s32) asm("func_0016abf8");
void* func_0016ac38(W324Obj*, s32, s32, s32, s32) asm("func_0016ac38");
void func_001dc920(void*) asm("func_001dc920");
void func_002f1990(void*) asm("func_002f1990");
s32 func_00181500(s32) asm("func_00181500");
void func_002f1900(void*, s32, W324Obj*) asm("func_002f1900");
static inline bool cf(W324C4* p) { if (p->r < 2) return false; u32 m = p->a & 2; u32 r = m == 0; return r; }
static inline bool big(W324C4* p) { return p->r >= 3; }
void func_002bf650(W324Obj* o, W324C4* p) asm("func_002bf650");
void func_002bf650(W324Obj* o, W324C4* p) {
    s32 m = 151;
    if (p->r != 0) {
        if (p->r != 1) {
            o->b1 = 0; o->b5 = 0;
            func_002c2228(o->sub->id);                         
        } else {
            o->b1 = 0; o->b5 = 1;
            m = 161;
            func_002c2248(o->sub->id);                         
        }
    } else {
        o->b1 = 1; o->b5 = 1;
        m = 161;
        func_002c2248(o->sub->id);                         
    }
    func_0017f540(o->mot, m, 0.0f, 0.0f);
    if (cf(p)) o->b6 = 0;
    else o->b6 = 1;
    if (p->a & 1) {
        if (o->afc == 0) o->afc = func_0016abf8(o, 3, 1, 0);
    } else if (o->afc) {
        func_001dc920(o->afc);
        o->afc = 0;
    }
    if (big(p)) {
        if (o->b00 == 0) o->b00 = func_0016ac38(o, 5, 1, 0, 0);
    } else if (o->b00) {
        func_001dc920(o->b00);
        o->b00 = 0;
    }
    u32 cv = D_00375480[p->r];
    W324C4* d = &o->col; d->r = cv; d->g = cv >> 8; d->b = cv >> 16; d->a = cv >> 24;
    if (o->sub->kind == 18) {
        if (p->r < 2) func_002f1990(o->eff);
        else if (func_00181500(0x481c)) func_002f1900(o->eff, 8, o);
        else func_002f1900(o->eff, 6, o);
    }
    o->cur = *p;
}
}  // namespace n002bf650

// ---- 002bf8a8 gap
namespace n002bf8a8 {
void func_0016ac38(u8*, s32, s32, s32, s32) asm("func_0016ac38");
void start_effect_2bf8a8(u8*, s32, s32, s32) asm("_ZN2YS3OBJ12start_effectEiii");
void func_002bf8a8(u8* p) asm("func_002bf8a8");
void func_002bf8a8(u8* p) {
    func_0016ac38(p, 2, 1, 0, 0);
    start_effect_2bf8a8(p, 1, 1, 0);
}
}  // namespace n002bf8a8

// ---- 002bf8f0 from src/anon/perm_002bf8f0.cpp
namespace n002bf8f0 {
typedef unsigned char u8;
typedef signed int s32;
typedef struct OB2
{
  u8 pad[4];
  u8 b4;
} OB2;
typedef struct O2
{
  u8 pad[0xae4];
  u8 kind;
  u8 pad2[0xaf8 - 0xae5];
  OB2 *q;
  u8 pad3[8];
  u8 w[4];
} O2;
void *func_001c3748(u8, void *) asm("func_001c3748");
s32 func_001c3888(void *) asm("func_001c3888");
void func_002f1900(void *, s32, void *) asm("func_002f1900");
void func_002bf8f0(O2 *p) asm("func_002bf8f0");
void func_002bf8f0(O2 *p)
{
  O2 *new_var;
  void *e;
  if (p->kind < 2)
  {
    return;
  }
  e = 0;
  while ((e = func_001c3748(p->q->b4, e)) != 0)
  {
    if (func_001c3888(e))
    {
      new_var = p;
      func_002f1900(p->w, 4, new_var);
      return;
    }
  }

}
}  // namespace n002bf8f0

// ---- 002bf978 from src/anon/batch_w42.cpp
namespace n002bf978 {
u8* func_002be908(void*) asm("func_002be908");
void func_002bf8f0(void*) asm("func_002bf8f0");
void func_002bf978(void) asm("func_002bf978");
void func_002bf978(void)
{
    u8* o = 0;
    while ((o = func_002be908(o)) != 0) {
        if (*(u32*)(o + 1416) & 0x80000000) func_002bf8f0(o);
    }
}
}  // namespace n002bf978

// ---- 002bf9d8 from src/anon/batch_owner1025.cpp
namespace n002bf9d8 {
void* func_00102c48(s32, s32, void (*)(void), s32) asm("func_00102c48");
void* func_001050d8(s32) asm("func_001050d8");
void func_002bfa98(void*, void*, void*) asm("func_002bfa98");
void func_002bfd90(void) asm("func_002bfd90");
void func_002bfdb0(void) asm("func_002bfdb0");
void func_002bf9d8(void* arg) asm("func_002bf9d8");
void func_002bf9d8(void* arg)
{
    u8* t = (u8*)func_00102c48(1, 15000, func_002bfd90, 16384);
    *(void (**)(void))(t + 48) = func_002bfdb0;
    func_002bfa98(func_001050d8(8), t, arg);
}
}  // namespace n002bf9d8

// ---- 002bfa40 from src/anon/batch_owner1025.cpp
namespace n002bfa40 {
extern u8* D_0034e948 asm("D_0034e948");
extern void* D_00361a50 asm("D_00361a50");
void func_001c1130(s32) asm("func_001c1130");
void func_00197760(void) asm("func_00197760");
void func_00197c90(void) asm("func_00197c90");
void func_001398d0(s32) asm("func_001398d0");
void func_002bfa40(void** p, void* a, void* b) asm("func_002bfa40");
void func_002bfa40(void** p, void* a, void* b)
{
    p[0] = a;
    p[1] = b;
    D_00361a50 = p;
    func_001c1130(12);
    *(u32*)(*(u8**)(D_0034e948 + 2880) + 44) |= 1;
    func_00197760();
    func_00197c90();
    func_001398d0(201);
}
}  // namespace n002bfa40

// ---- 002bfa98 from src/anon/batch_w1671.cpp
namespace n002bfa98 {
extern s32 D_00361a50 asm("D_00361a50");
extern u8* D_0034e948 asm("D_0034e948");
void func_001c1130(s32) asm("func_001c1130");
void func_00197760(void) asm("func_00197760");
void func_00197c90(void) asm("func_00197c90");
void func_001398d0(s32) asm("func_001398d0");
void func_002bfa98(s32* a0, s32 a1, s32 a2) asm("func_002bfa98");
void func_002bfa98(s32* a0, s32 a1, s32 a2) {
    a0[0] = a1; a0[1] = a2;
    D_00361a50 = (s32)a0;
    func_001c1130(12);
    *(u32*)(*(u8**)(D_0034e948 + 0xb40) + 0x2c) |= 1;
    func_00197760();
    func_00197c90();
    func_001398d0(201);
}
}  // namespace n002bfa98

// ---- 002bfaf0 from src/anon/batch_w27.cpp
namespace n002bfaf0 {
extern u32 D_00361a50 asm("D_00361a50");
extern u8* D_0034e948 asm("D_0034e948");
void func_001c11a8(u32) asm("func_001c11a8");
void func_00197780(void) asm("func_00197780");
void func_00197cc0(void) asm("func_00197cc0");
void func_00139858(u32) asm("func_00139858");
void func_002bfaf0(void) asm("func_002bfaf0");
void func_002bfaf0(void) {
    D_00361a50 = 0;
    func_001c11a8(12);
    u8* t = *(u8**)(D_0034e948 + 2880);
    *(u32*)(t + 44) &= ~1;
    func_00197780();
    func_00197cc0();
    func_00139858(201);
}
}  // namespace n002bfaf0

// ---- 002bfb40 from src/anon/batch_w28.cpp
namespace n002bfb40 {
void func_001c11a8(u32) asm("func_001c11a8");
void func_00197780(void) asm("func_00197780");
void func_00197cc0(void) asm("func_00197cc0");
void func_00139858(u32) asm("func_00139858");
extern u32 D_00361a50 asm("D_00361a50");
extern u8* D_0034e948 asm("D_0034e948");
void func_002bfb40(void) asm("func_002bfb40");
void func_002bfb40(void) {
    D_00361a50 = 0;
    func_001c11a8(12);
    u8* q = *(u8**)(D_0034e948 + 0xb40);
    *(u32*)(q + 0x2c) &= ~1;
    func_00197780();
    func_00197cc0();
    func_00139858(201);
}
}  // namespace n002bfb40

// ---- 002bfb90 from src/anon/batch_wcx2.cpp
namespace n002bfb90 {
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
struct V62 {
    f32 x, y, z, w;
    V62() {}
    V62(const V62& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Obj81 { u32 p0; u32 p4; };
struct Ent81 { u8 pad[8]; u32 k; };
void func_002bfd48(Obj81*, u32) asm("func_002bfd48");
u32 func_002c6218(void) asm("func_002c6218");
void func_002c6280(u32, s32) asm("func_002c6280");
s32 func_001b8d60(u8*) asm("func_001b8d60");
void func_00102448(u32, s32) asm("func_00102448");
Ent81* func_001b8800_101452(u8) asm("func_001b8800");
void func_001b8988(Ent81*, s32) asm("func_001b8988");
void qsort(void*, s32, s32, void*) asm("qsort");
s32 func_002bfcf8(const void*, const void*) asm("func_002bfcf8");
void func_002bfb90(Obj81* o) asm("func_002bfb90");
void func_002bfb90(Obj81* o)
{
    if (o->p4) {
        func_002bfd48(o, o->p4);
    } else {
        u8 ids[256];
        u32 seen[256];
        s32 n = func_001b8d60(ids);
        if (!n) return;
        func_00102448(o->p0, 0);
        s32 i;
        s32 cnt = 0;
        for (i = 0; i < n; i++) func_001b8988(func_001b8800_101452(ids[i]), 1);
        qsort(ids, n, 1, (void*)func_002bfcf8);
        for (s32 j = 0; j < n; j++) {
            Ent81* e = func_001b8800_101452(ids[j]);
            u32 k = e->k;
            if (!k) continue;
            s32 t;
            for (t = 0; t < cnt; t++) {
                if (seen[t] == k) break;
            }
            if (t != cnt) continue;
            func_002bfd48(o, e->k);
            seen[cnt++] = e->k;
        }
    }
    func_002c6280(func_002c6218(), 2);
}
}  // namespace n002bfb90

// ---- 002bfcf8 gap
namespace n002bfcf8 {
u8* func_001b8800(u8) asm("func_001b8800");
s32 func_002bfcf8(u8* a, u8* b) asm("func_002bfcf8");
s32 func_002bfcf8(u8* a, u8* b) {
    u8* x = func_001b8800(*a);
    u8* y = func_001b8800(*b);
    return x[2] - y[2];
}
}  // namespace n002bfcf8

// ---- 002bfd48 from src/anon/batch_w29.cpp
namespace n002bfd48 {
void func_002be340(u32) asm("func_002be340");
u32 func_002be4a0(void) asm("func_002be4a0");
void func_00102448(u32, u32) asm("func_00102448");
void func_002bfd48(u32* p, u32 a) asm("func_002bfd48");
void func_002bfd48(u32* p, u32 a) {
    func_002be340(a);
    while (func_002be4a0()) func_00102448(p[0], 0);
}
}  // namespace n002bfd48

// ---- 002bfd90 gap
namespace n002bfd90 {
extern u8* D_00361a50 asm("D_00361a50");
void func_002bfb90(u8*) asm("func_002bfb90");
void func_002bf978(void) asm("func_002bf978");
void func_002bfb40(u8*) asm("func_002bfb40");
void AREA_Free_2bfd90(void*) asm("_ZN4AREA4FreeEPv");
void func_002bfd90(void) asm("func_002bfd90");
void func_002bfd90(void) {
    func_002bfb90(D_00361a50);
}
void func_002bfdb0(void) asm("func_002bfdb0");
void func_002bfdb0(void) {
    func_002bf978();
    u8* p = D_00361a50;
    if (p) {
        struct NoTail { ~NoTail() {} } nt;
        func_002bfb40(p);
        AREA_Free_2bfd90(p);
    }
}
}  // namespace n002bfd90

// ---- 002bfdf8 from src/anon/tiny.cpp
namespace n002bfdf8 {
extern u32 D_00361a50 asm("D_00361a50");
u32 func_002bfdf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002bfdf8jjjj");
u32 func_002bfdf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_00361a50 != 0);
}
}  // namespace n002bfdf8

// ---- 002bfe08 from src/anon/batch_w282.cpp
namespace n002bfe08 {
struct V4w282b {
    f32 x, y, z, w;
    V4w282b() {}
    V4w282b(const V4w282b& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4w282b& operator=(const V4w282b& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V4w282b Lerp_w282(const V4w282b& a, const V4w282b& b, f32 t) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline V4w282b operator-(const V4w282b& a, const V4w282b& b) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4w282b operator+(const V4w282b& a, const V4w282b& b) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V4w282b operator*(const V4w282b& a, f32 s) {
    V4w282b r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct O2bfe08 { u32 vt; u8 pad[12]; V4w282b m16; V4w282b m32; u8 pad2[36]; u32 f84; u8 pad3[4]; u32 f92; u32 f96; f32 f100; u8 pad4[8];
    V4w282b m112; V4w282b m128; V4w282b m144; V4w282b m160; V4w282b m176; V4w282b m192; };
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361a60[] asm("D_00361a60");
void func_002c6420(O2bfe08*) asm("func_002c6420");
void func_002bfe08(O2bfe08* o, V4w282b* a, V4w282b* b, f32 f) asm("func_002bfe08");
void func_002bfe08(O2bfe08* o, V4w282b* a, V4w282b* b, f32 f) {
    o->f84 = 0;
    o->vt = (u32)D_00361da8;
    o->f92 = 0;
    func_002c6420(o);
    o->f96 = 0;
    o->vt = (u32)D_00361a60;
    o->m112 = o->m16;
    o->m160 = *a + *b;
    o->m128 = Lerp_w282(o->m16, o->m160, 0.2f);
    o->m144 = Lerp_w282(o->m16, o->m160, 0.95f);
    o->m176 = o->m32 - o->m16;
    o->m192 = *b * -1.0f;
    o->f100 = f;
    o->f92 = 0;
}
}  // namespace n002bfe08

// ---- 002bff98 from src/anon/batch_w1948.cpp
namespace n002bff98 {
struct V2bff98 {
    f32 x, y, z, w;
    V2bff98() {}
    V2bff98& operator=(const V2bff98& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V2bff98 add_2bff98(const V2bff98& a, const V2bff98& b) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V2bff98 sub_2bff98(const V2bff98& a, const V2bff98& b) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline V2bff98 lerp_2bff98(const V2bff98& a, const V2bff98& b, f32 t) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline V2bff98 scale_2bff98(const V2bff98& a, f32 s) {
    V2bff98 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
struct O2bff98 {
    u32 vt;
    u8 p4[12];
    V2bff98 a;             
    V2bff98 b;             
    u8 p30[0x54 - 0x30];
    u8 sub[8];             
    s32 f5c;               
    s32 f60;               
    f32 f64;               
    u8 p68[8];
    V2bff98 v70;
    V2bff98 v80;
    V2bff98 v90;
    V2bff98 va0;
    V2bff98 vb0;
    V2bff98 vc0;
};
void func_0031cc28(void*) asm("_Z13func_0031cc28Pv");
void func_002c6420(O2bff98*) asm("func_002c6420");
extern u8 D_00361da8 asm("D_00361da8");
extern u8 D_00361a60 asm("D_00361a60");
void func_002bff98(O2bff98* self, V2bff98* p, V2bff98* q, f32 t) asm("func_002bff98");
void func_002bff98(O2bff98* self, V2bff98* p, V2bff98* q, f32 t) {
    self->vt = (u32)&D_00361da8;
    func_0031cc28(self->sub);
    self->f5c = 0;
    func_002c6420(self);
    self->f60 = 0;
    self->vt = (u32)&D_00361a60;
    self->v70 = self->a;
    self->va0 = add_2bff98(*p, *q);
    self->v80 = lerp_2bff98(self->a, self->va0, 0.2f);
    self->v90 = lerp_2bff98(self->a, self->va0, 0.95f);
    self->vb0 = sub_2bff98(self->b, self->a);
    self->vc0 = scale_2bff98(*q, -1.0f);
    self->f64 = t;
    self->f5c = 0;
}
}  // namespace n002bff98

// ---- 002c0130 from src/anon/auto80_199_queue.cpp
namespace n002c0130 {
u32 func_002c0130(u32 a0, u32 a1, f32 a2) asm("_Z13func_002c0130jjf");
u32 func_002c0130(u32 a0, u32 a1, f32 a2) {
    u32 s18 = func_001050d8(208);
    func_002bff98(s18, a0, a1, a2);
    u32 v0 = func_002c6218();
    return func_002c6228(v0, 2, s18);
}
}  // namespace n002c0130

// ---- 002c01a8 gap
namespace n002c01a8 {
typedef n002bff98::V2bff98 V;
struct O2c01a8 {
    u32 vt;
    u8 p4[0x2c];
    V eye;
    V at;
    u8 p50[0x10];
    f32 f60;
    f32 f64;
    u8 p68[8];
    V v70;
    V v80;
    V v90;
    V va0;
    V vb0;
    V vc0;
};
extern f32 D_00349e10 asm("D_00349e10");
V func_0017d748(V*, f32) asm("func_0017d748");
void func_002c6490(O2c01a8*) asm("func_002c6490");
s32 func_002c01a8(O2c01a8* p) asm("func_002c01a8");
s32 func_002c01a8(O2c01a8* p) {
    if (p->f60 < p->f64) {
        p->f60 += D_00349e10;
        if (p->f64 < p->f60) p->f60 = p->f64;
    }
    f32 t;
    if (0.0f < p->f64) {
        f32 r = p->f60 / p->f64;
        t = (r < 1.0f) ? r : 1.0f;
    } else {
        t = 1.0f;
    }
    p->eye = func_0017d748(&p->v70, t);
    {
        V d = n002bff98::lerp_2bff98(p->vb0, p->vc0, t);
        p->at = n002bff98::add_2bff98(p->eye, d);
    }
    func_002c6490(p);
    return 1;
}
}  // namespace n002c01a8

// ---- 002c02d0 gap
namespace n002c02d0 {
union UA_002c02d0 { u32 i; f32 f; u8* p; };
void func_002c6420(u8*) asm("func_002c6420");
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361a80[] asm("D_00361a80");
extern UA_002c02d0 D_00361a70 asm("D_00361a70");
void func_002c02d0(u8* p, u32 a1, UA_002c02d0* a2) asm("func_002c02d0");
void func_002c02d0(u8* p, u32 a1, UA_002c02d0* a2) {
    *(u32*)p = (u32)D_00361da8;
    ((UA_002c02d0*)(p + 84))->i = 0;
    ((UA_002c02d0*)(p + 92))->i = 0;
    func_002c6420(p);
    ((UA_002c02d0*)(p + 96))->i = a1;
    *(u32*)p = (u32)D_00361a80;
    ((UA_002c02d0*)(p + 100))->i = a2[0].i;
    ((UA_002c02d0*)(p + 104))->i = a2[1].i;
    ((UA_002c02d0*)(p + 108))->i = a2[2].i;
    ((UA_002c02d0*)(p + 112))->i = a2[3].i;
    ((UA_002c02d0*)(p + 116))->i = a2[4].i;
    D_00361a70.p = p;
    ((UA_002c02d0*)(p + 92))->f = 30.0f;
}
}  // namespace n002c02d0

// ---- 002c0370 from src/anon/batch_wcx2.cpp
namespace n002c0370 {
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
union UA_002c0370 { u32 i; f32 f; u8* p; };
void func_0031cc28(u8*) asm("func_0031cc28");
void func_002c6420(u8*) asm("func_002c6420");
extern u8 D_00361da8[] asm("D_00361da8");
extern u8 D_00361a80[] asm("D_00361a80");
extern UA_002c0370 D_00361a70 asm("D_00361a70");
void func_002c0370(u8* p, u32 a1, UA_002c0370* a2) asm("func_002c0370");
void func_002c0370(u8* p, u32 a1, UA_002c0370* a2) {
    *(u32*)p = (u32)D_00361da8;
    func_0031cc28(p + 84);
    ((UA_002c0370*)(p + 92))->i = 0;
    func_002c6420(p);
    ((UA_002c0370*)(p + 96))->i = a1;
    *(u32*)p = (u32)D_00361a80;
    ((UA_002c0370*)(p + 100))->i = a2[0].i;
    ((UA_002c0370*)(p + 104))->i = a2[1].i;
    ((UA_002c0370*)(p + 108))->i = a2[2].i;
    ((UA_002c0370*)(p + 112))->i = a2[3].i;
    ((UA_002c0370*)(p + 116))->i = a2[4].i;
    D_00361a70.p = p;
    ((UA_002c0370*)(p + 92))->f = 30.0f;
}
}  // namespace n002c0370

// ---- 002c0418 gap
namespace n002c0418 {
extern u32 D_00361a70 asm("D_00361a70");
extern u8 D_00361da8[] asm("D_00361da8");
void func_002c0418(u8* p) asm("func_002c0418");
void func_002c0418(u8* p) {
    D_00361a70 = 0;
    *(u8**)p = D_00361da8;
}
void func_002c0430(u8* p) asm("func_002c0430");
void func_002c0430(u8* p) {
    D_00361a70 = 0;
    *(u8**)p = D_00361da8;
}
}  // namespace n002c0418

// ---- 002c0448 from src/anon/tiny_wrappers_more80_relaxed.cpp
namespace n002c0448 {
u32 func_00105110(u32, u32, u32, u32) asm("_Z13func_00105110jjjj");
extern u8 D_00360000 asm("D_00360000");
extern u8 D_00361da8 asm("D_00361da8");
u32 func_002c0448(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c0448jjjj");
u32 func_002c0448(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)((u32)&D_00360000) + 6768u) = (u32)(0x00000000u);
    *(u32*)((u32)(a0) + 0u) = (u32)((u32)&D_00361da8);
    return func_00105110(a0, a1, a2, a3);
}
}  // namespace n002c0448

// ---- 002c0470 from src/anon/batch_w34.cpp
namespace n002c0470 {
s32 func_00190140(void*) asm("func_00190140");
void func_002c04c8(void*, void*, void*) asm("func_002c04c8");
void func_002c6490(void*) asm("func_002c6490");
s32 func_002c0470(u8* p) asm("func_002c0470");
s32 func_002c0470(u8* p) {
    if (!func_00190140(p + 100)) return 0;
    func_002c04c8(p, p + 48, p + 64);
    func_002c6490(p);
    return 1;
}
}  // namespace n002c0470

// ---- 002c04c8 from src/anon/batch_w1958_nsa.cpp
namespace n002c04c8 {
struct V58a {
    f32 x, y, z, w;
    V58a() {}
    V58a& operator=(const V58a& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct O58a { u8 pad[0x60]; void* x60; u8 x64[0x10]; };
struct V58e {
    f32 x, y, z, w;
    V58e() {}
    V58e& operator=(const V58e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    void normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
    }
} __attribute__((aligned(16)));
static inline V58e operator-(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
static inline V58e operator+(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
static inline void w1958_lerp(V58a* r, const V58a* a, const V58a* b, f32 t) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline void w1958a_vsub(V58a* r, const V58a* a, const V58a* b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline void w1958a_vadd(V58a* r, const V58a* a, const V58a* b) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(a), "r"(b), "r"(r) : "memory");
}
static inline f32 w1958a_vlen(const V58a* a) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(a) : "$8", "memory");
    return len;
}
void* func_0016c028(void*) asm("func_0016c028");
void func_001904a8(V58a*, void*) asm("func_001904a8");
extern V58a D_01e2bc70 asm("D_01e2bc70");
extern V58a D_01e2bc80 asm("D_01e2bc80");
extern V58a D_01e2bc90 asm("D_01e2bc90");
void func_002c04c8(O58a* o, V58a* out1, V58a* out2) asm("func_002c04c8");
void func_002c04c8(O58a* o, V58a* out1, V58a* out2) {
    V58a c;
    V58a a;
    V58a b;
    V58a* p = (V58a*)func_0016c028(o->x60);
    func_001904a8(&a, o->x64);
    w1958_lerp(&c, p, &a, 0.15f);
    V58a* q = (V58a*)func_0016c028(o->x60);
    func_001904a8(&b, o->x64);
    w1958a_vsub(&a, q, &b);
    f32 len = w1958a_vlen(&a);
    f32 t = 0.0f;
    if (1000.0f < len) {
        if (len < 6000.0f) t = (len - 1000.0f) / 5000.0f;
        else t = 1.0f;
    }
    w1958_lerp(&b, &D_01e2bc80, &D_01e2bc90, t);
    w1958a_vadd(&a, &c, &b);
    *out1 = a;
    w1958a_vadd(&a, &c, &D_01e2bc70);
    *out2 = a;
}
}  // namespace n002c04c8

// ---- 002c0688 from src/anon/auto80_199_queue.cpp
namespace n002c0688 {
u32 func_002c0688(u32 a0, u32 a1) asm("_Z13func_002c0688jj");
u32 func_002c0688(u32 a0, u32 a1) {
    u32 v0 = func_002c6218();
    ((void(*)(u32, u32))func_002c6280)(v0, 1);
    u32 s0 = func_001050d8(128);
    func_002c0370(s0, a0, a1);
    v0 = func_002c6218();
    return func_002c6228(v0, 1, s0);
}
}  // namespace n002c0688

// ---- 002c0700 from src/anon/batch_w3.cpp
namespace n002c0700 {
u32 func_002c6218() asm("func_002c6218");
void func_002c6280(u32, u32) asm("func_002c6280");
void func_002c0700() asm("func_002c0700");
void func_002c0700() { func_002c6280(func_002c6218(), 1); }
}  // namespace n002c0700

// ---- 002c0728 gap
namespace n002c0728 {
extern u32 D_00361a70 asm("D_00361a70");
u32 func_002c0728(void) asm("func_002c0728");
u32 func_002c0728(void) {
    return D_00361a70;
}
}  // namespace n002c0728

// ---- 002c0738 from src/anon/batch_w76.cpp
namespace n002c0738 {
struct V4f { f32 x, y, z, w; };
extern V4f D_01e2bc70 asm("D_01e2bc70");
extern V4f D_01e2bc80 asm("D_01e2bc80");
extern V4f D_01e2bc90 asm("D_01e2bc90");
static inline void Set4(V4f* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
void wtarget_002c0738(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002c0738jjjj");
void wtarget_002c0738(u32 a, u32 b, u32 c, u32 d)
{
    if (b == 0xffff && a == 1) Set4(&D_01e2bc70, 0.0f, -500.0f, 0.0f, 1.0f);
    if (b == 0xffff && a == 1) Set4(&D_01e2bc80, 0.0f, -1840.0f, -2400.0f, 0.0f);
    if (b == 0xffff && a == 1) Set4(&D_01e2bc90, 0.0f, -3450.0f, -3000.0f, 0.0f);
}
}  // namespace n002c0738

// ---- 002c0820 from src/anon/tiny_wrappers_more.cpp
namespace n002c0820 {
u32 func_002c0738(u32, u32, u32, u32) asm("_Z13func_002c0738jjjj");
u32 func_002c0820(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002c0820jjjj");
u32 func_002c0820(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002c0738(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n002c0820

// ---- 002c0840 gap
namespace n002c0840 {
u32 func_002c0738(u32, u32, u32, u32) asm("_Z13func_002c0738jjjj");
u32 func_002c0840(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_002c0840");
u32 func_002c0840(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_002c0738(0x00000000u, 0x0000ffffu, a2, a3);
}
}  // namespace n002c0840

