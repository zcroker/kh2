// Linked unit 0x00253ba8-0x002582f8 (0x253ba8 and 0x2581b0 were whole asm).
#include "../common/types.h"
#include "../tozawa/cmenu_selector.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/obj2d.hpp"
#include "../harata/libdk/sprite.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 00253ba8 (was whole asm, src/anon/batch_w3908.s)
// Menu system init. Plain C++ once it is written with real classes: virtual Alloc calls, class
// operator new / new[] and inline constructors (the C-style emulation with function-pointer
// structs never scheduled the allocator loads like retail), globals reset in address order.
namespace n00253ba8 {
struct Heap3ba8 { virtual void* Alloc(u32 size, void* ra); };
struct Sys3ba8 { u8 pad[20]; Heap3ba8* heap; };
extern Sys3ba8* D_00347f80 asm("D_00347f80");
extern Heap3ba8* D_0032ba14 asm("D_0032ba14");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035ef60 asm("D_0035ef60");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s16 D_0035ef70 asm("D_0035ef70");
void func_00177710(void) asm("func_00177710");
void func_001a3710(void) asm("func_001a3710");
void func_00287b18(s32, s32) asm("func_00287b18");
void func_00253818(s32) asm("func_00253818");
void Tz__CmComm__DataLoad(s32) asm("Tz__CmComm__DataLoad");
void func_0028d068(s32, s32) asm("func_0028d068");
s32 func_001a8bd0(s32) asm("func_001a8bd0");
void func_00280eb0(void*, s32) asm("func_00280eb0");
void func_00281ec8(void*) asm("func_00281ec8");
s32 func_00103570(void) asm("func_00103570");
void* func_001063c0(u32, s32) asm("func_001063c0");
void func_00290b00(void*) asm("func_00290b00");
void* func_00288be8(u32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
void func_00239700(void*) asm("func_00239700");
void func_0028b9b0(void*) asm("func_0028b9b0");
void func_0028d140(void*) asm("func_0028d140");
void func_0031a838(void*) asm("func_0031a838");
void sa__MUSICAL_SCORE2__init(void*) asm("sa__MUSICAL_SCORE2__init");
void func_00285828(void) asm("func_00285828");
void func_0025f698(void) asm("func_0025f698");
void func_002675e8(void) asm("func_002675e8");
void func_0026ba48(void) asm("func_0026ba48");
void Tz__CmStat__Init(void) asm("Tz__CmStat__Init");
void func_0026ec98(void) asm("func_0026ec98");
void func_00276fe8(void) asm("func_00276fe8");
void Tz__CmConfig__Init(void) asm("Tz__CmConfig__Init");
void Tz__CmTutorial__Init(void) asm("Tz__CmTutorial__Init");
void Tz__UnitLoad__Init(s32) asm("Tz__UnitLoad__Init");
void Tz__ItemPicDraw__Init(void) asm("Tz__ItemPicDraw__Init");
void Tz__SimpleStat__Init(void) asm("Tz__SimpleStat__Init");
void func_00293708(void) asm("func_00293708");
void Tz__ChgWeapon__Init(void) asm("Tz__ChgWeapon__Init");
void func_002936d8(void) asm("func_002936d8");
void func_00257c78(void) asm("func_00257c78");
void func_00254568(void) asm("func_00254568");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00283b78(void) asm("func_00283b78");
struct Th3ba8 { s32 f0; s32 f4; };
Th3ba8* func_00103eb0(void) asm("func_00103eb0");
void func_00254648(void) asm("func_00254648");
void TASK_MANAGER__create_thread(s32, s32, s32, void (*)(void), s32) asm("TASK_MANAGER__create_thread");

// Allocated from the main heap; the allocator gets this function's return address.
struct MainObj {
    static void* operator new(u32 size) { return D_0032ba14->Alloc(size, __builtin_return_address(0)); }
};
// Allocated from the menu system's own heap.
struct MenuObj {
    static void* operator new(u32 size) { return D_00347f80->heap->Alloc(size, 0); }
    static void* operator new[](u32 size) { return D_00347f80->heap->Alloc(size, 0); }
};
// 408-byte sequence holder (vtable 0x347e60, YI::SEQUENCE at +24). The destructor makes new[] keep a count.
struct Seq408 : MenuObj {
    void* vt; u8 pad4[8]; s32 f12; u8 pad16[8]; u8 seq[384];
    Seq408() { f12 = 0; vt = D_00347e60; func_00239700(seq); }
    ~Seq408();
};
struct Seq436 : MenuObj {
    void* vt; u8 pad4[8]; s32 f12; u8 pad16[8]; u8 seq[384]; s32 f408; u8 pad412[24];
    Seq436() { vt = D_00347f98; func_0031a838(&f12); vt = D_00347e60; func_00239700(seq); f408 = 0; vt = D_00347e40; }
};
struct Obj88 : MainObj { u8 b[88]; Obj88(s32 x) { func_00280eb0(this, x); } };
struct Obj4196 : MainObj { u8 b[4196]; Obj4196() { func_00281ec8(this); } void func_00281f40(Obj88*) asm("func_00281f40"); };
struct Lay11084 { u8 b[11084]; Lay11084() { func_00290b00(this); } static void* operator new(u32 n, s32 sys) { return func_001063c0(n, sys); } };
struct Obj56 { u8 b[56]; Obj56(s32 a, s32 c) { func_002889f0(this, a, c); } static void* operator new(u32 n) { return func_00288be8(n); } };
struct Obj52 : MainObj { u8 b[52]; Obj52() { func_0028b9b0(this); } };
struct Obj444 : MenuObj { u8 b[444]; Obj444() { func_0028d140(this); } };
struct Lay47212 { u8 b[47212]; Lay47212() { sa__MUSICAL_SCORE2__init(this); } static void* operator new(u32 n, s32 sys) { return func_001063c0(n, sys); } };

extern Obj88* D_0035f010 asm("D_0035f010");
extern Obj4196* D_0035f014 asm("D_0035f014");
extern Lay11084* D_0035f018 asm("D_0035f018");
extern Obj56* D_0035f01c asm("D_0035f01c");
extern Obj56* D_0035f020 asm("D_0035f020");
extern Obj56* D_0035f024 asm("D_0035f024");
extern Seq408* D_0035f028 asm("D_0035f028");
extern Seq408* D_0035f02c asm("D_0035f02c");
extern Seq408* D_0035f030 asm("D_0035f030");
extern Seq436* D_0035f034 asm("D_0035f034");
extern Lay47212* D_0035f038 asm("D_0035f038");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f040 asm("D_0035f040");
extern s32 D_0035f044 asm("D_0035f044");
extern s32 D_0035f048 asm("D_0035f048");
extern Obj52* D_0035f04c asm("D_0035f04c");
extern Obj444* D_0035f050 asm("D_0035f050");
extern u8 D_0035f054 asm("D_0035f054");
extern u8 D_0035f055 asm("D_0035f055");
extern u8 D_0035f057 asm("D_0035f057");
extern u8 D_0035f05b asm("D_0035f05b");
extern u8 D_0035f05c asm("D_0035f05c");

/*TARGET 00253ba8*/
void func_00253ba8(void) asm("func_00253ba8");
void func_00253ba8(void) {
    func_00177710();
    func_001a3710();
    func_00287b18(38, 3);
    func_00253818(2);
    Tz__CmComm__DataLoad(2);

    D_0035ef64 = 0;
    D_0035ef68 = 1;
    D_0035ef6c = 31;
    D_0035f03c = 0;
    D_0035f040 = 0;
    D_0035f044 = 0;
    D_0035f048 = 0;
    D_0035f04c = 0;
    D_0035f050 = 0;
    D_0035f054 = 0;
    D_0035f055 = 1;
    D_0035f057 = 0;

    func_0028d068(30026, -1);
    D_0035f010 = new Obj88(func_001a8bd0(-1));
    D_0035f014 = new Obj4196;
    D_0035f018 = new (func_00103570()) Lay11084;
    D_0035f014->func_00281f40(D_0035f010);
    D_0035f01c = new Obj56(38, 1);
    D_0035f020 = new Obj56(38, 1);
    D_0035f024 = new Obj56(38, 0);
    D_0035f028 = new Seq408[3];
    D_0035f02c = new Seq408;
    D_0035f030 = new Seq408;
    D_0035f04c = new Obj52;
    D_0035f050 = new Obj444;
    D_0035f034 = new Seq436;
    D_0035f038 = new (func_00103570()) Lay47212;
    func_00285828();
    func_0025f698();
    func_002675e8();
    func_0026ba48();
    Tz__CmStat__Init();
    func_0026ec98();
    func_00276fe8();
    Tz__CmConfig__Init();
    Tz__CmTutorial__Init();
    Tz__UnitLoad__Init(0);
    Tz__ItemPicDraw__Init();
    Tz__SimpleStat__Init();
    func_00293708();
    Tz__ChgWeapon__Init();
    func_002936d8();
    func_00257c78();
    func_00254568();
    func_00287bd0(0, 0);
    func_00287cc0(0);
    D_0035ef60 = 0;
    D_0035ef70 = 0;
    D_0035f05b = func_00283b78() != 0;
    D_0035f05c = 0;
    TASK_MANAGER__create_thread(func_00103eb0()->f4, 0, 2000, func_00254648, 4096);
}
}  // namespace n00253ba8

// 00254020 (was src/anon/batch_w1616.cpp)
namespace n00254020 {
struct VT4020 {
    void* f0;
    void (*f4)(void*, void*);
    void* f8;
    void (*fC)(void*);
    void (*f10)(void*);
};
struct VO4020 { VT4020* vt; };
extern u8 D_0035f055 asm("D_0035f055");
extern u8 D_0035ef60 asm("D_0035ef60");
extern u8 D_0035f05b asm("D_0035f05b");
extern VO4020* D_0032ba14 asm("D_0032ba14");
extern u8* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern void* D_0035f010 asm("D_0035f010");
extern void* D_0035f014 asm("D_0035f014");
extern void* D_0035f018 asm("D_0035f018");
extern void* D_0035f01c asm("D_0035f01c");
extern void* D_0035f020 asm("D_0035f020");
extern void* D_0035f024 asm("D_0035f024");
extern u8* D_0035f028 asm("D_0035f028");
extern VO4020* D_0035f02c asm("D_0035f02c");
extern VO4020* D_0035f030 asm("D_0035f030");
extern VO4020* D_0035f034 asm("D_0035f034");
extern u8* D_0035f038 asm("D_0035f038");
extern VO4020* D_0035f03c asm("D_0035f03c");
extern VO4020* D_0035f040 asm("D_0035f040");
extern void* D_0035f044 asm("D_0035f044");
extern void* D_0035f048 asm("D_0035f048");
extern void* D_0035f04c asm("D_0035f04c");
extern VO4020* D_0035f050 asm("D_0035f050");
void func_00280ee0(void*) asm("func_00280ee0");
void func_00290c30(void*) asm("func_00290c30");
void func_00106420(void*) asm("func_00106420");
void func_00281f10(void*) asm("func_00281f10");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_00258158(void*) asm("func_00258158");
void func_0031acc0(void*) asm("func_0031acc0");
void func_0031abd8(void*) asm("func_0031abd8");
void func_00239870(void*) asm("func_00239870");
void func_0028fdd0(void*) asm("func_0028fdd0");
void func_00290300(void*) asm("func_00290300");
void func_0028ba80(void*) asm("func_0028ba80");
void func_00285910(void) asm("func_00285910");
void func_0026ed20(void) asm("func_0026ed20");
void func_0025f6b0(void) asm("func_0025f6b0");
void func_00267608(void) asm("func_00267608");
void func_0026bab8(void) asm("func_0026bab8");
void func_002643d0(void) asm("func_002643d0");
void func_00277008(void) asm("func_00277008");
void func_0027c508(void) asm("func_0027c508");
void func_002830b8(void) asm("func_002830b8");
void Tz__SelHist__Exit(void) asm("Tz__SelHist__Exit");
void func_002639f8(void) asm("func_002639f8");
void Tz__UnitLoad__Exit(void) asm("Tz__UnitLoad__Exit");
void func_002816f0(void) asm("func_002816f0");
void func_0027dd18(void) asm("func_0027dd18");
void func_002932f8(void) asm("func_002932f8");
void func_00293780(void) asm("func_00293780");
void func_001776a8(void) asm("func_001776a8");
void ExitPartyImpl_4020(void) asm("_ZN2Tz5CmTop13ExitPartyImplEz");
/*TARGET 00254020*/
void ExitPartyImpl_4020(void) asm("_ZN2Tz5CmTop13ExitPartyImplEz");
void ExitPartyImpl_4020(void) {
    void* p;
    u8* o;
    u8* q;
    u8* r;

    D_0035f055 = 1;
    D_0035ef60 = 0;
    D_0035f05b = 0;
    p = D_0035f010;
    if (p) {
        func_00280ee0(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f010 = 0;
    }
    p = D_0035f018;
    if (p) {
        func_00290c30(p);
        func_00106420(p);
        D_0035f018 = 0;
    }
    p = D_0035f014;
    if (p) {
        func_00281f10(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f014 = 0;
    }
    p = D_0035f01c;
    if (p) {
        func_00288b00(p);
        func_00288c20(p);
        D_0035f01c = 0;
    }
    p = D_0035f020;
    if (p) {
        func_00288b00(p);
        func_00288c20(p);
        D_0035f020 = 0;
    }
    p = D_0035f024;
    if (p) {
        func_00288b00(p);
        func_00288c20(p);
        D_0035f024 = 0;
    }
    if (D_0035f02c) {
        D_0035f02c->vt->f10(D_0035f02c);
        D_0035f02c = 0;
    }
    if (D_0035f028) {
        q = D_0035f028 + ((s32*)D_0035f028)[-1] * 408;
        for (;;) {
            r = D_0035f028;
            if (r == q) break;
            q -= 408;
            (*(VT4020**)q)->fC(q);
        }
        {
            VO4020* a = *(VO4020**)(D_00347f80 + 20);
            a->vt->f4(a, r - 4);
        }
        D_0035f028 = 0;
    }
    if (D_0035f030) {
        D_0035f030->vt->f10(D_0035f030);
        D_0035f030 = 0;
    }
    if (D_0035f034) {
        D_0035f034->vt->f10(D_0035f034);
        D_0035f034 = 0;
    }
    o = D_0035f038;
    if (o) {
        func_00258158(o + 0xb350);
        if (o + 0x87d0) {
            q = o + 0xae10;
            {
                u8* e = o + 0x87d0;
            l1:
                if (e == q) goto l1x;
                q -= 408;
                (*(VT4020**)q)->fC(q);
                goto l1;
            l1x:;
            }
        }
        if (o + 24304) {
            q = o + 0x87d0;
            {
                u8* e = o + 24304;
            l2:
                if (e == q) goto l2x;
                q -= 436;
                (*(VT4020**)q)->fC(q);
                goto l2;
            l2x:;
            }
        }
        if (o + 13840) {
            q = o + 24304;
            {
                u8* e = o + 13840;
            l3:
                if (e == q) goto l3x;
                q -= 436;
                (*(VT4020**)q)->fC(q);
                goto l3;
            l3x:;
            }
        }
        if (o + 3376) {
            q = o + 13840;
            {
                u8* e = o + 3376;
            l4:
                if (e == q) goto l4x;
                q -= 436;
                (*(VT4020**)q)->fC(q);
                goto l4;
            l4x:;
            }
        }
        func_0031acc0(o + 2940);
        func_0031acc0(o + 2504);
        func_0031acc0(o + 2068);
        func_0031acc0(o + 1632);
        func_0031abd8(o + 1224);
        func_0031abd8(o + 816);
        func_0031abd8(o + 408);
        *(u32*)o = (u32)D_00347e60;
        func_00239870(o + 24);
        *(u32*)o = (u32)D_00347f98;
        func_00106420(o);
        D_0035f038 = 0;
    }
    if (D_0035f03c) {
        D_0035f03c->vt->f10(D_0035f03c);
        D_0035f03c = 0;
    }
    if (D_0035f040) {
        D_0035f040->vt->f10(D_0035f040);
        D_0035f040 = 0;
    }
    p = D_0035f044;
    if (p) {
        func_0028fdd0(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f044 = 0;
    }
    p = D_0035f048;
    if (p) {
        func_00290300(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f048 = 0;
    }
    p = D_0035f04c;
    if (p) {
        func_0028ba80(p);
        D_0032ba14->vt->f4(D_0032ba14, p);
        D_0035f04c = 0;
    }
    if (D_0035f050) {
        D_0035f050->vt->f10(D_0035f050);
        D_0035f050 = 0;
    }
    func_00285910();
    func_0026ed20();
    func_0025f6b0();
    func_00267608();
    func_0026bab8();
    func_002643d0();
    func_00277008();
    func_0027c508();
    func_002830b8();
    Tz__SelHist__Exit();
    func_002639f8();
    Tz__UnitLoad__Exit();
    func_002816f0();
    func_0027dd18();
    func_002932f8();
    func_00293780();
    func_001776a8();
}
}  // namespace n00254020

// 00254508 (was unwritten gap)
namespace n00254508 {
extern u8 D_0035f05b asm("D_0035f05b");
void func_00253ba8(void) asm("func_00253ba8");
s32 func_0026d818(void) asm("func_0026d818");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00254508(void) asm("func_00254508");
void func_00254508(void) {
    func_00253ba8();
    func_00287bd0(func_0026d818() ? 21 : 20, 0);
    func_00287cc0(0);
    D_0035f05b = 0;
}
}  // namespace

// 00254550 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00254550 { // method (was CmTop::ExitParty)
/*TARGET 00254550*/
u32 CmTop_ExitParty() asm("_ZN2Tz5CmTop9ExitPartyEv");
u32 CmTop_ExitParty() { return CmTop::ExitPartyImpl(); }
} }  // Tz

// 00254568 (was src/anon/batch_w1595.cpp)
namespace n00254568 {
// 0x00252ad8: definition moved into src/anon/unit_00250fb8.cpp

s32 func_00281100(s32) asm("func_00281100");
s32 func_002811b0(s32, s32) asm("func_002811b0");
s32 func_001058e8() asm("func_001058e8");
u16* YS__SAVERAM_BATTLE__get_partram(s32, s32) asm("YS__SAVERAM_BATTLE__get_partram");
void func_00293500(s32, s32, u32) asm("func_00293500");
s32 func_00281480(s32, s32) asm("func_00281480");
s32 func_002815b8() asm("func_002815b8");
s32 func_00281388(s32) asm("func_00281388");
u32 func_002814b0(s32) asm("func_002814b0");
extern s32 D_0035f010 asm("D_0035f010");
/*TARGET 00254568*/
void func_00254568(void) asm("func_00254568");
void func_00254568(void) {
    s32 i = 0;
    s32 n = func_00281100(D_0035f010);
    for (; i < n; i++) {
        s32 e = func_002811b0(D_0035f010, i);
        func_00293500(e, 0, *YS__SAVERAM_BATTLE__get_partram(func_001058e8() + 9456, e));
        if (func_00281480(D_0035f010, i)) {
            s32 o = func_002815b8();
            if (func_00281388(o)) func_00293500(e, 1, func_002814b0(o));
        }
    }
}
}  // namespace n00254568

// 00254648 (was src/anon/batch_w99.cpp)
namespace n00254648 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V13f6 {
    f32 x, y, z, w;
    V13f6() {}
    V13f6(const V13f6& o) { QCOPY(this, &o); }
    V13f6& operator=(const V13f6& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
    V13f6& operator*=(f32 s)
    {
        asm("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
    V13f6& operator+=(const V13f6& o)
    {
        asm("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
            : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline V13f6 operator-(const V13f6& a, const V13f6& b)
{
    V13f6 r;
    asm("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
extern u8 D_0035f05c asm("D_0035f05c");
extern u32 D_0035f010 asm("D_0035f010");
void Tz__CmComm__DataLoadWait(s32, u32) asm("Tz__CmComm__DataLoadWait");
void func_00256b40(void) asm("func_00256b40");
void func_00274ea0(void) asm("func_00274ea0");
void func_00170888(u32) asm("func_00170888");
u32 func_00103570(void) asm("func_00103570");
void func_00274ee8(u32) asm("func_00274ee8");
void Tz__JmNewInfo__Init(void) asm("Tz__JmNewInfo__Init");
u8 Tz__JmNewInfo__isAnyNew(void) asm("Tz__JmNewInfo__isAnyNew");
void func_002a9d30(void) asm("func_002a9d30");
void func_00274f50(void) asm("func_00274f50");
void func_00102448(u32, s32) asm("func_00102448");
void Tz__CmTop__Setup(void) asm("Tz__CmTop__Setup");
void func_00242618(s32, s32) asm("func_00242618");
s32 func_00293ba0(void) asm("func_00293ba0");
s32 func_002938e0(void) asm("func_002938e0");
s32 func_002938f0(void) asm("func_002938f0");
u32 func_00293bc0(void) asm("func_00293bc0");
void func_002810c8(u32, u32) asm("func_002810c8");
void func_00293bb0(void) asm("func_00293bb0");
void YI__IMAGE_CACHE__Clear(void) asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
void Tz__ChgWeapon__Update(void) asm("Tz__ChgWeapon__Update");
s32 func_00255588(void) asm("func_00255588");
void func_00255df0(void) asm("func_00255df0");
/*TARGET 00254648*/
void func_00254648(u32 a) asm("func_00254648");
void func_00254648(u32 a)
{
    Tz__CmComm__DataLoadWait(2, a);
    func_00256b40();
    func_00274ea0();
    func_00170888(a);
    func_00274ee8(func_00103570());
    Tz__JmNewInfo__Init();
    D_0035f05c = Tz__JmNewInfo__isAnyNew();
    func_002a9d30();
    func_00274f50();
    func_00102448(a, 1);
    Tz__CmTop__Setup();
    func_00242618(11, 1);
    for (;;) {
        if (!func_00293ba0() && func_002938e0() && func_002938f0()) {
            func_002810c8(D_0035f010, func_00293bc0());
            func_00293bb0();
        }
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        Tz__ChgWeapon__Update();
        if (func_00255588()) break;
        func_00255df0();
        func_00102448(a, 0);
    }
}
}  // namespace n00254648

// 00254770 (was src/anon/batch_wcx2.cpp)
namespace n00254770 {
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
// 0x00226478: definition moved into src/anon/unit_00224780.cpp

// ---- 00254770
struct AllocVt254 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj254 { AllocVt254* vt; };
struct Holder254 { u8 pad[20]; AllocObj254* al; };
extern u8 D_0035f057 asm("D_0035f057");
extern u8* g_menuObj254 asm("D_0035f03c");
extern u8* D_0035f040 asm("D_0035f040");
extern void* g_sel0_254 asm("D_0035f044");
extern void* g_sel1_254 asm("D_0035f048");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f018 asm("D_0035f018");
extern Holder254* D_00347f80 asm("D_00347f80");
extern AllocObj254* D_0032ba14 asm("D_0032ba14");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ebb8[] asm("D_0035ebb8");
extern u8 D_00372988[] asm("D_00372988");
extern u8 D_00372a18[] asm("D_00372a18");
extern u8 D_00372978[] asm("D_00372978");
extern u8 D_003729a8[] asm("D_003729a8");
extern u8 D_003729b0[] asm("D_003729b0");
extern u8 D_003729b8[] asm("D_003729b8");
extern u8 D_00372990[] asm("D_00372990");
extern u8 D_00372998[] asm("D_00372998");
extern u16 D_00372aa6 asm("D_00372aa6");
u8* func_0023ee30(u32 size) asm("func_0023ee30");
void func_0031a838(u8* p) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8* p) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
// obj_ctor_36eac8
void YI__LAYOUT__LAYOUT(u8* p) asm("YI__LAYOUT__LAYOUT");
// obj_ctor_36eae8
void Tz__MenuUtil__CreateLay(u8* a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8* p) asm("Tz__Layout__SetImageCache");
void func_00290cf0(u32 a, u8* b, u32 c, u32 d, s32 e, u8* f, u8* g) asm("func_00290cf0");
void Tz__SelHist__Init(u32 a, u32 b, u8* c, u8* d, u8* e) asm("Tz__SelHist__Init");
void Tz__CMenuHelp__Init(u32 a, u32 b, u8* c, u8* d, u8* e) asm("Tz__CMenuHelp__Init");
// store_globals_and_init
void func_002590b0(u8* a, u32 b, u8* c, u8* d, u8* e, s32 f, u32 g, u32 h) asm("func_002590b0");
u8* GetLayout254(u8* p) asm("func_0023f1b0");
u32 func_0023c4b8(u8* p, u32 a) asm("func_0023c4b8");
u32 func_00236ca8(u32 p, u32 a) asm("func_00236ca8");
void func_0028fc78(void* p, u32 a, u32 b, u8* c) asm("func_0028fc78");
void func_0028fe38(void* p, u32 a, u32 b, u32 c, u32 d) asm("func_0028fe38");
void func_00290198(void* p, u32 a, u32 b, u32 c, u8* d) asm("func_00290198");
void Tz__TimeDraw__Create(void* p, u32 a, u32 b, u32 c, u32 d) asm("Tz__TimeDraw__Create");
void func_00292870(void) asm("func_00292870");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028fb28(u32 a, u32 b) asm("func_0028fb28");
void func_00257050(u32 a, u32 b, u32 c) asm("func_00257050");
void func_0026bc10(void) asm("func_0026bc10");
void func_0026c9c8(void) asm("func_0026c9c8");
void func_002551b8(void) asm("func_002551b8");
s32 func_002887c8(void) asm("func_002887c8");
void func_002550e8(void) asm("func_002550e8");
void func_002551a8(void) asm("func_002551a8");
void func_00288750(void (*fn)(void)) asm("func_00288750");
static inline void* Alloc254(u32 size) { return D_0032ba14->vt->alloc(D_0032ba14, size, __builtin_return_address(0)); }
/*TARGET 00254770*/
// Build the menu layout objects for this screen and start its fade.
void Tz__CmTop__Setup(void) asm("Tz__CmTop__Setup");
// Build the menu layout objects for this screen and start its fade.
void Tz__CmTop__Setup(void) {
    D_0035f057 = 0;
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);  // obj_ctor_36eac8
    YI__LAYOUT__LAYOUT(o + 48);  // obj_ctor_36eae8
    g_menuObj254 = o;
    AllocObj254* al = D_00347f80->al;
    u8* m = (u8*)al->vt->alloc(al, 76, 0);
    *(u32*)(m + 12) = 0;
    *(u8**)m = D_0035ebb8;
    D_0035f040 = m;
    Tz__MenuUtil__CreateLay(g_menuObj254, 30002, 0, 0, 0, 1, 0, 0, 0);
    Tz__Layout__SetImageCache(g_menuObj254);
    func_00290cf0(D_0035f018, g_menuObj254, D_0035ef68, D_0035ef64, D_0035f3d4 + 3, D_00372a18, D_00372978);
    Tz__SelHist__Init(D_0035ef64, D_0035ef68, g_menuObj254, D_003729a8, D_003729b0);
    Tz__CMenuHelp__Init(D_0035ef64, D_0035ef68, g_menuObj254, D_00372988, D_003729b8);  // store_globals_and_init
    func_002590b0(D_0035f040, 30003, g_menuObj254, D_00372988, D_00372990, -1, 0, 0);
    u32 seq = func_0023c4b8(GetLayout254(g_menuObj254), D_0035ef68);
    u8* lay = GetLayout254(g_menuObj254);
    u32 id = D_0035ef64;
    u32 img = func_00236ca8(*(u32*)(lay + 40), id);
    void* p = Alloc254(20);
    func_0028fc78(p, 31, 51, D_00372998);
    g_sel0_254 = p;
    func_0028fe38(p, 30011, seq, img, 0);
    p = Alloc254(20);
    func_00290198(p, 31, 71, 61, D_00372998 + 6);
    g_sel1_254 = p;
    Tz__TimeDraw__Create(p, 30011, seq, img, 0);
    func_00292870();
    s32 mode = func_00287bc0();
    if (mode == 20 || mode == 21) {
        func_0028fb28(0, D_00372aa6);
        func_00257050(0, 3, 0);
        if (mode == 20) func_0026bc10();
        else func_0026c9c8();
    } else {
        func_002551b8();
    }
    if (func_002887c8()) {
        func_002550e8();
        D_0035f057 = 1;
        func_00288750(func_002551a8);
    }
}
}  // namespace n00254770

// 00254ab8 (was src/anon/batch_wcx2.cpp)
namespace n00254ab8 {
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
// 0x002d0290: definition moved into src/anon/unit_002cf260.cpp

// ---- 00254ab8
struct ListVt254 { void* f[6]; void (*setItem)(void* self, s32 i, u32 a, s32 b, s32 c, s32 y, u32 col); };
struct List254 { ListVt254* vt; };
extern u8* D_0035f02c asm("D_0035f02c");
extern u8* D_0035f030_4ab8 asm("D_0035f030");
extern void* D_0035f010_4ab8 asm("D_0035f010");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
extern u8 D_0035f056 asm("D_0035f056");
extern u8 D_0035ef60 asm("D_0035ef60");
extern u32 D_00372974 asm("D_00372974");
extern u32 D_00372970 asm("D_00372970");
s32 func_00139d78_4ab8(u8* p) asm("func_00139d78");
void func_0028d8c0(u8* q, s32 id, u32 a, u32 b, u32 c, s32 d, s32 e, s32 f) asm("func_0028d8c0");
u8* func_00256b68_4ab8(s32 a) asm("func_00256b68");
List254* func_00287dc0_4ab8(void) asm("func_00287dc0");
void func_0023d808(List254* l, s32 id) asm("func_0023d808");
s32 func_00281100_4ab8(void* p) asm("func_00281100");
s32 func_00281128(void* p, s32 i) asm("func_00281128");
// get_entry20_field16
s32 func_00281538(void* p, s32 i) asm("func_00281538");
s32 func_0023ec18(List254* l, s32 i) asm("func_0023ec18");
s32 func_002811e0(void* p, s32 i) asm("func_002811e0");
u32 func_00281238(void* p, s32 i) asm("func_00281238");
s32 func_0027aa78(void) asm("func_0027aa78");
void func_0023e858(List254* l, s32 i, f32 f) asm("func_0023e858");
void func_0023e8b8(List254* l, s32 i, f32 f) asm("func_0023e8b8");
void func_0023e8d8(List254* l, s32 i, f32 f) asm("func_0023e8d8");
s32 func_002811b0(void* p, s32 i) asm("func_002811b0");
void Tz__MenuObj__SetHidePartAll(List254* l, s32 i, s32 a, s32 b) asm("Tz__MenuObj__SetHidePartAll");
void func_0023eac0(List254* l, s32 i, s32 k) asm("func_0023eac0");
// store_byte_2912
void func_0023e958(List254* l, s32 i, s32 a, s32 b, s32 c, s32 d) asm("func_0023e958");
void func_0023e9c8(List254* l, s32 i, u8* p) asm("func_0023e9c8");
void func_0023e9e0(List254* l, s32 i, u8* p) asm("func_0023e9e0");
/*TARGET 00254ab8*/
void Tz__CmTop__SetupPartyObj(void) asm("Tz__CmTop__SetupPartyObj");
void Tz__CmTop__SetupPartyObj(void) {
    u8 any = 0;
    s32 y = 0;
    if (!func_00139d78_4ab8(D_0035f02c)) func_0028d8c0(D_0035f02c, 30003, D_0035ef68, D_0035ef64, D_0035f03c, 46, 47, 0);
    u8* o = func_00256b68_4ab8(0);
    if (!func_00139d78_4ab8(o)) func_0028d8c0(o, 30002, D_0035ef68, D_0035ef64, D_0035f03c, 116, -1, 0);
    List254* lst = func_00287dc0_4ab8();
    if (!func_00139d78_4ab8((u8*)lst)) func_0023d808(lst, 30008);
    s32 n = func_00281100_4ab8(D_0035f010_4ab8);
    if (n >= 4) n = 3;
    s32 step = (n * 98 - 98) / n;
    for (s32 i = 0; i < 4; i++) {
        if (i == 3) break;
        s32 k = 16;
        switch (i) {
        case 0:
            y = 47;
            k = 17;
            break;
        case 1:
            y = 145;
            break;
        case 2:
            y = 243;
            break;
        }
        if (!func_00281128(D_0035f010_4ab8, i)) continue;
        if (!func_00281538(D_0035f010_4ab8, i) || func_0023ec18(lst, i)) {
            if (!func_00281538(D_0035f010_4ab8, i)) any = 1;
            continue;
        }
        if (i != 0 && func_002811e0(D_0035f010_4ab8, i) == 3) k = 0;
        y -= step;
        u32 a = func_00281238(D_0035f010_4ab8, i);
        u32 col = func_0027aa78() ? D_00372974 : D_00372970;
        lst->vt->setItem(lst, i, a | 0x20000000, 139, 2, y, col);
        func_0023e858(lst, i, -100.0f);
        func_0023e8b8(lst, i, 0.0f);
        func_0023e8d8(lst, i, 0.0f);
        if (func_002811b0(D_0035f010_4ab8, i) == 8) Tz__MenuObj__SetHidePartAll(lst, i, 20, 32);
        func_0023eac0(lst, i, k);  // store_byte_2912
        func_0023e958(lst, i, 96, 96, 96, -1);
        func_0023e9c8(lst, i, D_0035f02c);
        if (D_0035ef60) {
            if (!func_00139d78_4ab8(D_0035f030_4ab8)) func_0028d8c0(D_0035f030_4ab8, k, D_0035ef68, D_0035ef64, D_0035f03c, 125, -1, 0);
            func_0023e9e0(lst, i, D_0035f030_4ab8);
        }
    }
    if (!any && !D_0035f056) D_0035f056 = 1;
    D_0035ef60 = any;
}
}  // namespace n00254ab8

// 00254e60 (was src/anon/batch_wcx.cpp)
namespace n00254e60 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// word_table_372368
void func_00138c10(u8*, s32) asm("func_00138c10");
// 0x0024f1a0: definition moved into src/anon/unit_0024e7e8.cpp
extern u8* D_0035f02c asm("D_0035f02c");
extern u8 D_0035f056 asm("D_0035f056");
void func_0028dac8(u8*, s32) asm("func_0028dac8");
s32 func_00256b80(s32) asm("func_00256b80");
u8* func_00256b68(s32) asm("func_00256b68");
u32 func_00287dc0(void) asm("func_00287dc0");
void func_0023d820(u32) asm("func_0023d820");
/*TARGET 00254e60*/
void func_00254e60(void) asm("func_00254e60");
void func_00254e60(void)
{
    if (u_call4_00139d78(D_0035f02c)) func_0028dac8(D_0035f02c, 48);
    if (!func_00256b80(0)) return;
    u8* o = func_00256b68(0);
    if (*(s32*)(o + 388) != 117) { func_00138c10(o, 117); *(s32*)(o + 392) = -1; }
    if (D_0035f056) return;
    func_0023d820(func_00287dc0());
}
}  // namespace n00254e60

// 00254f08 (was src/anon/auto80_199_queue.cpp)
namespace n00254f08 {
/*TARGET 00254f08*/
// 0x00253b30: definition moved into src/anon/unit_002530c8.cpp

void func_00254f08(void) asm("_Z13func_00254f08v");
// 0x00253b30: definition moved into src/anon/unit_002530c8.cpp

void func_00254f08(void) {
    if (func_00139d78(D_0035f02c) != 0) {
        Obj00254f08* obj = (Obj00254f08*)D_0035f02c;
        obj->vtbl->fn20(obj);
    }

    if (func_00256b80(0) != 0) {
        Obj00254f08* obj2 = (Obj00254f08*)func_00256b68(0);
        obj2->vtbl->fn20(obj2);
    }

    u32 v0 = func_00287dc0();
    func_0023d820(v0);
}
}  // namespace n00254f08

// 00254f80 (was src/anon/batch_wcx2.cpp)
namespace n00254f80 {
struct Ob50 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
};
extern Ob50* D_0035f03c__80579 asm("D_0035f03c");
extern Ob50* D_0035f030 asm("D_0035f030");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f024 asm("D_0035f024");
extern u32 D_0035f050 asm("D_0035f050");
extern u32 D_0035f044 asm("D_0035f044");
extern u32 D_0035f048 asm("D_0035f048");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
void func_00254f08(void) asm("func_00254f08");
void Tz__SelHist__LeaveAll(void) asm("Tz__SelHist__LeaveAll");
void func_0028d620(u32) asm("func_0028d620");
void func_00263d28(void) asm("func_00263d28");
void func_002579e0(void) asm("func_002579e0");
void func_00256c40(void) asm("func_00256c40");
void func_00256ea8(void) asm("func_00256ea8");
void func_0028ff68(u32) asm("func_0028ff68");
void func_00290488(u32) asm("func_00290488");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void func_0028ce38(void) asm("func_0028ce38");
void func_00256aa0(void) asm("func_00256aa0");
void func_0025f750(void) asm("func_0025f750");
void func_00267768(void) asm("func_00267768");
void func_0026bbf8(void) asm("func_0026bbf8");
void func_0026ee30(void) asm("func_0026ee30");
void func_00277128(void) asm("func_00277128");
void func_0027c570(void) asm("func_0027c570");
void func_002831b0(void) asm("func_002831b0");
void func_0027e770(void) asm("func_0027e770");
void func_00264458(void) asm("func_00264458");
/*TARGET 00254f80*/
void Tz__CmTop__LeaveAll(void) asm("Tz__CmTop__LeaveAll");
void Tz__CmTop__LeaveAll(void)
{
    if (func_00139d78(D_0035f03c__80579)) D_0035f03c__80579->v5();
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
    if (func_0028acc8(D_0035f024)) func_0028abe0(D_0035f024);
    if (func_00139d78(D_0035f030)) D_0035f030->v5();
    func_00254f08();
    Tz__SelHist__LeaveAll();
    func_0028d620(D_0035f050);
    func_00263d28();
    func_002579e0();
    func_00256c40();
    func_00256ea8();
    func_0028ff68(D_0035f044);
    func_00290488(D_0035f048);
    func_00288018();  // global_zero_4dwords
    func_0028ce38();
    func_00256aa0();
    func_0025f750();
    func_00267768();
    func_0026bbf8();
    func_0026ee30();
    func_00277128();
    func_0027c570();
    func_002831b0();
    func_0027e770();
    func_00264458();
}
}  // namespace n00254f80

// 002550e8 (was src/anon/auto80_199_queue.cpp)
namespace n002550e8 {
/*TARGET 002550e8*/
void func_002550e8(void) asm("_Z13func_002550e8v");
void func_002550e8(void) {
    if (func_00139d78(D_0035f03c) != 0) {
        u32 v0 = func_0023f0c0(D_0035f03c);
        if (v0 != 1) {
            func_0023f070(D_0035f03c, 1, -1);
        }
    }

    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028ab20(D_0035f01c);
    }

    func_0028ff18(D_0035f044);
    func_00290438(D_0035f048);

    if (func_00139d78(D_0035f02c) != 0) {
        u32 p = D_0035f02c;
        if (*(u32*)(p + 388) != 47) {
            func_00138c10(p, 47);
            *(s32*)(D_0035f02c + 392) = -1;
        }
    }
}
}  // namespace n002550e8

// 002551a8 (was unwritten gap)
namespace n002551a8 {
extern u8 D_0035f057 asm("D_0035f057");
void func_002551a8(void) asm("func_002551a8");
void func_002551a8(void) { D_0035f057 = 0; }
}  // namespace

// 002551b8 (was src/anon/batch_w1614.cpp)
namespace n002551b8 {
struct Ent36 { u8 pad[8]; u8 text[10]; u16 id; u8 pad2[16]; };
extern Ent36 D_00372a28[] asm("D_00372a28");
extern s8 D_0035f05b asm("D_0035f05b");
extern s8 D_0035f05c asm("D_0035f05c");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f024 asm("D_0035f024");
extern u8* D_0035f038 asm("D_0035f038");
extern u32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u16 D_0035ef70 asm("D_0035ef70");
extern s32 D_00372968 asm("D_00372968");
extern s32 D_0037296c asm("D_0037296c");
void func_002937c0(void) asm("func_002937c0");
void func_00288f48(u32, s32, s32, s32, s32) asm("func_00288f48");
void func_0028b1e8(u32, s32) asm("func_0028b1e8");
s32 func_00257e00(void) asm("func_00257e00");
void Tz__Select__SetItem(u32, s32, u32, u32, u32, u16, Ent36*, u8*) asm("Tz__Select__SetItem");
void Tz__Select__SetExOffset(u32, s32, u32, s32) asm("Tz__Select__SetExOffset");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
s32 func_00285d58(s32) asm("func_00285d58");
s32 func_00285e30(s32) asm("func_00285e30");
s32 Tz__CmNewFlg__isAbilityNewMember(s32, s32) asm("Tz__CmNewFlg__isAbilityNewMember");
s32 Tz__CmNewFlg__isAbilityNewForm(s32, s32) asm("Tz__CmNewFlg__isAbilityNewForm");
s32 Tz__CmNewFlg__isAbilityHistMember(s32, s32) asm("Tz__CmNewFlg__isAbilityHistMember");
s32 func_00287218(s32, s32) asm("func_00287218");
s32 func_00286068(s32) asm("func_00286068");
s32 func_00286160(s32) asm("func_00286160");
s32 Tz__CmNewFlg__isStatNew(s32) asm("Tz__CmNewFlg__isStatNew");
s32 func_002864f8(s32) asm("func_002864f8");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00257ff8(s32) asm("func_00257ff8");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void Tz__CmTop__SetupPartyObj(void) asm("Tz__CmTop__SetupPartyObj");
void func_0027dee8(s32, s32, s32) asm("func_0027dee8");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002831e0(s32, s32) asm("func_002831e0");
/*TARGET 002551b8*/
void func_002551b8(void) asm("func_002551b8");
void func_002551b8(void)
{
    if (!D_0035f05b) func_002937c0();
    func_00288f48(D_0035f01c, 16, 32, 0, 0);
    func_00288f48(D_0035f020, 16, 32, 0, 0);
    func_00288f48(D_0035f024, 16, 32, 0, 0);
    s32 n = 0;
    s32 r;
    func_0028b1e8(D_0035f024, 0);
    D_0035ef70 = func_00257e00();
    s32 k = D_0035f3d4 + 1;
    for (s32 i = 0; i < 8; i++) {
        if (((D_0035ef70 >> i) ^ 1) & 1 & 0xff) continue;
        r = -1;
        Ent36* e = (Ent36*)((u8*)(i * 36) + (u32)D_00372a28);
        Tz__Select__SetItem(D_0035f01c, n, D_0035ef68, D_0035ef64, D_0035f03c, e->id, e, (u8*)(i * 36) + (u32)D_00372a28[0].text);
        Tz__Select__SetExOffset(D_0035f01c, n, 0, -1);
        u8* o = func_002891b8(D_0035f01c, n);
        func_00139620(o);
        func_001395f8(o);
        u32 a = func_0023aa18(o + 24);
        u32 b = func_0023aa38(o + 24);
        if (i == 0) {
            if (func_00285d58(-1)) r = func_00285e30(-1) ? D_0037296c : D_00372968;
        } else if (i == 1) {
            if (Tz__CmNewFlg__isAbilityNewMember(-1, -1) || Tz__CmNewFlg__isAbilityNewForm(-1, -1)) {
                if (Tz__CmNewFlg__isAbilityHistMember(-1, -1)) r = func_00287218(-1, -1) ? D_0037296c : D_00372968;
                else r = D_00372968;
            }
        } else if (i == 2) {
            if (func_00286068(-1)) r = func_00286160(-1) ? D_0037296c : D_00372968;
        } else if (i == 4) {
            if (Tz__CmNewFlg__isStatNew(-1)) r = func_002864f8(-1) ? D_0037296c : D_00372968;
        } else if (i == 5) {
            if (D_0035f05c) r = 50;
        }
        if (r >= 0) {
            func_0028d8c0(D_0035f038 + i * 408 + 0x87d0, k, D_0035ef68, D_0035ef64, D_0035f03c, r, -1, 0);
            func_0028dcc0(D_0035f038 + i * 408 + 0x87d0, o);
            func_00138c68(D_0035f038 + i * 408 + 0x87d0, a, b);
        }
        n++;
    }
    r = func_00257ff8(func_00257070(0));
    if (r < 0) r = 0;
    Tz__Select__SetCurrent(D_0035f01c, r, 1, 0, 2);
    Tz__CmTop__SetupPartyObj();
    func_0027dee8(0, 0, 4);
    if (D_0035f05b) {
        r = func_00287bc0();
        func_00287bd0(37, 0);
        func_002831e0(-1, r);
        D_0035f05b = 0;
    }
}
}  // namespace n002551b8

// 00255588 (was src/anon/batch_w1580_g.cpp)
namespace n00255588 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
s32 func_00287db0(void) asm("func_00287db0");
struct W1580Word4 { u8 b[4]; };
extern void* D_0035f03c asm("D_0035f03c");
extern void* D_0035f048 asm("D_0035f048");
extern W1580Word4 D_0035f060 asm("D_0035f060");
void func_001039f8(void) asm("func_001039f8");
void func_0013a368(void) asm("func_0013a368");
s32 func_0013a4b8(void) asm("func_0013a4b8");
s32 func_001688b8(void) asm("func_001688b8");
W1580Word4* func_001a8bd0(s32) asm("func_001a8bd0");
void Tz__CmTop__LeaveAll(void) asm("Tz__CmTop__LeaveAll");
void func_00256aa0(void) asm("func_00256aa0");
void func_00256f18(void) asm("func_00256f18");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
void* func_00287dc0(void) asm("func_00287dc0");
s32 Tz__MenuBase__isPressAnyKey(void) asm("Tz__MenuBase__isPressAnyKey");
void func_00290420(void*) asm("func_00290420");
s32 func_00290580(void*) asm("func_00290580");
s32 func_00293668(void) asm("func_00293668");
void func_002936e8(void) asm("func_002936e8");
s32 func_002936f8(void) asm("func_002936f8");
s32 func_002938e0(void) asm("func_002938e0");
s32 func_002938f0(void) asm("func_002938f0");
s32 func_00293948(void) asm("func_00293948");
s32 func_00293b70(void) asm("func_00293b70");
void func_00255900(void) asm("func_00255900");
void func_0025fb48(void) asm("func_0025fb48");
void Tz__CmEquip__SetupEquip(void) asm("Tz__CmEquip__SetupEquip");
void func_002691f8(void) asm("func_002691f8");
void Tz__CmEquip__CtrlAbilityWarning(void) asm("Tz__CmEquip__CtrlAbilityWarning");
void Tz__CmEquip__CtrlEquip(void) asm("Tz__CmEquip__CtrlEquip");
void func_00260418(void) asm("func_00260418");
void func_00260ce0(void) asm("func_00260ce0");
void func_002612c8(void) asm("func_002612c8");
void Tz__CmItem__CtrlItemUseWarning(void) asm("Tz__CmItem__CtrlItemUseWarning");
void Tz__CmItem__CtrlItemDumpConfirm(void) asm("Tz__CmItem__CtrlItemDumpConfirm");
void func_00277938(void) asm("func_00277938");
void func_00278318(void) asm("func_00278318");
void func_00278dd0(void) asm("func_00278dd0");
void func_0026c470(void) asm("func_0026c470");
void Tz__CmParty__CtrlInfo(void) asm("Tz__CmParty__CtrlInfo");
void Tz__CmParty__Ctrl2ndSel(void) asm("Tz__CmParty__Ctrl2ndSel");
void Tz__CmStat__CtrlTop(void) asm("Tz__CmStat__CtrlTop");
void Tz__CmStat__CtrlHelp(void) asm("Tz__CmStat__CtrlHelp");
void Tz__CmCustom__CtrlTop(void) asm("Tz__CmCustom__CtrlTop");
void func_0026f920(void) asm("func_0026f920");
void Tz__CmCustom__CtrlAutoConfirm(void) asm("Tz__CmCustom__CtrlAutoConfirm");
void Tz__CmCustom__CtrlCustom(void) asm("Tz__CmCustom__CtrlCustom");
void Tz__CmConfig__Ctrl(void) asm("Tz__CmConfig__Ctrl");
void Tz__CmTutorial__Ctrl(void) asm("Tz__CmTutorial__Ctrl");
/*TARGET 00255588*/
// 0x00251a70: definition moved into src/anon/unit_00250fb8.cpp

s32 func_00255588(void) asm("func_00255588");
// 0x00251a70: definition moved into src/anon/unit_00250fb8.cpp

s32 func_00255588(void) {
    Tz__MenuBase__SaveMode();
    func_00256f18();
    if (func_00287db0()) {
        if (!func_002938f0()) return 0;
        if (func_00139d78(func_00287dc0())) return 0;
        if (func_00293948() && !func_00293b70() && func_002936f8()) {
            func_002936e8();
            return 0;
        }
        if (func_002938e0() && !func_002938f0()) return 0;
        if (func_00293b70()) return 0;
        if (func_001688b8()) return 0;
        if (func_00293668()) return 0;
        if (func_00139d78(D_0035f03c)) return 0;
        if (func_0013a4b8()) func_0013a368();
        func_00256aa0();
        Tz__CmTop__LeaveAll();
        D_0035f060 = *func_001a8bd0(-1);
        func_001039f8();
        return 1;
    }
    if (func_00290580(D_0035f048)) func_00290420(D_0035f048);
    if (func_00139d78(D_0035f03c) && func_0023f0c0(D_0035f03c) != 1) {
        if (Tz__MenuBase__isPressAnyKey()) func_0023f070(D_0035f03c, 1, -1);
        else return 0;
    }
    switch (func_00287bc0()) {
    case 0: func_00255900(); break;
    case 1: func_0025fb48(); break;
    case 2: Tz__CmEquip__SetupEquip(); break;
    case 3: func_002691f8(); break;
    case 4: Tz__CmEquip__CtrlAbilityWarning(); break;
    case 5: case 6: case 7: case 8: case 9: Tz__CmEquip__CtrlEquip(); break;
    case 10: func_00260418(); break;
    case 11: func_00260ce0(); break;
    case 12: func_002612c8(); break;
    case 13: Tz__CmItem__CtrlItemUseWarning(); break;
    case 14: Tz__CmItem__CtrlItemDumpConfirm(); break;
    case 15: func_00277938(); break;
    case 16: func_00278318(); break;
    case 17: case 18: case 19: func_00278dd0(); break;
    case 20: func_0026c470(); break;
    case 21: Tz__CmParty__CtrlInfo(); break;
    case 22: Tz__CmParty__Ctrl2ndSel(); break;
    case 23: Tz__CmStat__CtrlTop(); break;
    case 24: Tz__CmStat__CtrlHelp(); break;
    case 25: Tz__CmCustom__CtrlTop(); break;
    case 26: case 27: func_0026f920(); break;
    case 28: Tz__CmCustom__CtrlAutoConfirm(); break;
    case 29: case 30: case 31: case 32: case 33: Tz__CmCustom__CtrlCustom(); break;
    case 36: Tz__CmConfig__Ctrl(); break;
    case 37: Tz__CmTutorial__Ctrl(); break;
    }
    return 0;
}
}  // namespace n00255588

// 00255900 (was src/anon/batch_w1616.cpp)
namespace n00255900 {
s32 func_00289380(void*) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_002938e0(void) asm("func_002938e0");
s32 func_002938f0(void) asm("func_002938f0");
void Tz__CmTop__SetupPartyObj(void) asm("Tz__CmTop__SetupPartyObj");
void* func_00287dc0(void) asm("func_00287dc0");
void func_0023d820(void*) asm("func_0023d820");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0027e920(void) asm("func_0027e920");
s32 func_00257970(void) asm("func_00257970");
s32 func_00289310(void*) asm("func_00289310");
void func_00287f90(s32) asm("func_00287f90");
void func_0028abe0(void*) asm("func_0028abe0");
void func_0027e770(void) asm("func_0027e770");
void func_00287c30(void) asm("func_00287c30");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0025f7f0(s32) asm("func_0025f7f0");
void Tz__CmAbility__SetupTop(s32) asm("Tz__CmAbility__SetupTop");
void func_0026bc10(void) asm("func_0026bc10");
void Tz__CmStat__SetupTop(s32) asm("Tz__CmStat__SetupTop");
void Tz__CmCustom__SetupTop(void) asm("Tz__CmCustom__SetupTop");
void Tz__CmConfig__Setup(void) asm("Tz__CmConfig__Setup");
s32 func_0028ae28(void*, s32) asm("func_0028ae28");
void func_0028ab20(void*) asm("func_0028ab20");
void func_0027ead0(void) asm("func_0027ead0");
void Tz__CmTop__UpdateHelpMess(void) asm("Tz__CmTop__UpdateHelpMess");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, void (*)(void), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00258118(void) asm("func_00258118");
u8* func_002891b8(void*, s32) asm("func_002891b8");
void func_0028fb68(s32, s32) asm("func_0028fb68");
s32 func_00257fa8(s32) asm("func_00257fa8");
void func_00257050(s32, s32, s32) asm("func_00257050");
void func_002535b0(s32) asm("func_002535b0");
void func_00288658(s32, s32) asm("func_00288658");
void func_00288670(void (*)(void)) asm("func_00288670");
void Tz__CmTop__LeaveAll(void) asm("Tz__CmTop__LeaveAll");
void func_00287da0(void) asm("func_00287da0");
void func_00287c00(s32) asm("func_00287c00");
void func_0028aa40(void*) asm("func_0028aa40");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
void func_00254e60(void) asm("func_00254e60");
void func_0027e6e0(void) asm("func_0027e6e0");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
extern void* D_0035f01c asm("D_0035f01c");
extern u8 D_0035f056 asm("D_0035f056");
extern u8 D_0035f057 asm("D_0035f057");
extern u8 D_0035ef60 asm("D_0035ef60");
/*TARGET 00255900*/
void func_00255900(void) asm("func_00255900");
void func_00255900(void) {
    s32 r;
    s32 mode;
    void* obj;
    s32 k;

    r = D_0035f057 ? -1 : func_00289380(D_0035f01c);
    mode = func_00287cd0();
    if ((func_002938e0() && func_002938f0()) || !D_0035f056) {
        if (D_0035ef60) {
            if (mode != 2) Tz__CmTop__SetupPartyObj();
            else func_0023d820(func_00287dc0());
        }
    }
    if (D_0035f057) return;
    obj = func_00287dc0();
    if (mode == 2) {
        if (func_0028acc8(D_0035f01c) || func_00139d78(obj) || func_0027e920() || func_00257970()) {
            if (r != -1 || func_00289310(D_0035f01c)) {
                func_00287f90(0);
                func_0028abe0(D_0035f01c);
                func_0027e770();
            }
            return;
        }
        func_00287c30();
        k = func_00287bc0();
        if (k == 1) func_0025f7f0(-1);
        else if (k == 15) Tz__CmAbility__SetupTop(-1);
        else if (k == 20) func_0026bc10();
        else if (k == 23) Tz__CmStat__SetupTop(1);
        else if (k == 25) Tz__CmCustom__SetupTop();
        else if (k == 36) Tz__CmConfig__Setup();
        return;
    }
    if ((r != -1 || func_00289310(D_0035f01c)) && !func_0028ae28(D_0035f01c, 0)) {
        func_0028ab20(D_0035f01c);
        func_0027ead0();
    }
    if (mode == 0 && func_0028ae28(D_0035f01c, 0)) {
        Tz__CmTop__UpdateHelpMess();
        func_00287c90(1);
    }
    if (!func_00242848(func_00287df0(r, func_00289310(D_0035f01c), 1, func_00258118, 1))) {
        switch (r) {
        default:
            k = -1;
            func_0028fb68(0, *(s32*)(func_002891b8(D_0035f01c, r) + 408));
            func_00257050(0, func_00257fa8(r), 0);
            switch (func_00257fa8(r)) {
            case 0:
                k = 1;
                break;
            case 1:
                k = 15;
                break;
            case 2:
                k = 25;
                break;
            case 3:
                k = 20;
                break;
            case 4:
                k = 23;
                break;
            case 5:
            case 6:
                k = -1;
                func_002535b0(func_00257fa8(r) == 5 ? 1 : 2);
                func_00288658(2, 0);
                func_00288670(Tz__CmTop__LeaveAll);
                func_00287da0();
                if (func_002938e0() && !func_002938f0()) func_0023d820(obj);
                break;
            case 7:
                k = 36;
                break;
            }
            if (k >= 0) {
                func_00287c00(k);
                func_0028aa40(D_0035f01c);
                Tz__CMenuHelp__FadeOut();
                func_00254e60();
                func_0027e6e0();
                func_00287c90(1);
            }
            break;
        case -1:
            break;
        case -2:
        case -4:
            func_00287da0();
            func_00257050(0, func_00257fa8(func_002891e8(D_0035f01c)), 0);
            if (func_002938e0() && !func_002938f0()) func_0023d820(obj);
            break;
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00255900

// 00255df0 (was src/anon/batch_w501.cpp)
namespace n00255df0 {
struct VObj;
// Menu/pad-help selector update (Tz menu): keeps the three Select lists,
// the menu cursor slots and the LightCur in sync with the menu mode.

struct SelItem {
    u8 pad[0x18c];
    void* sub;      // 0x18c
    s32 active;     // 0x190
};
struct VObjVt {
    void* f[5];
    void (*update)(VObj*); // 0x14
};
struct VObj {
    VObjVt* vt;
};
struct LightCur {
    VObjVt* vt;
    u8 pad[0x188];
    void* target;   // 0x18c
};
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_002887c8(void) asm("func_002887c8");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(u32) asm("func_0023f0c0");
void func_0023f070(u32, s32, s32) asm("func_0023f070");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_0028acb8(u32) asm("func_0028acb8");
SelItem* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028aa40(u32) asm("func_0028aa40");
void func_00254e60(void) asm("func_00254e60");
void func_0028f7a0(void) asm("func_0028f7a0");
void func_0028d5d0(LightCur*) asm("func_0028d5d0");
void func_0028ffe8(u32, s32) asm("func_0028ffe8");
void func_00290508(u32, s32) asm("func_00290508");
void func_0025f6b8(void) asm("func_0025f6b8");
void func_002676e8(void) asm("func_002676e8");
void func_0026bbe0(void) asm("func_0026bbe0");
void func_0026ede0(void) asm("func_0026ede0");
void func_002770a8(void) asm("func_002770a8");
void func_0027c540(void) asm("func_0027c540");
void func_00283180(void) asm("func_00283180");
void func_0027e6e0(void) asm("func_0027e6e0");
void func_00264408(void) asm("func_00264408");
void func_00263d28(void) asm("func_00263d28");
void func_00288018(void) asm("func_00288018");
void func_0028ce38(void) asm("func_0028ce38");
void func_00256f18(void) asm("func_00256f18");
u32 func_00267248(void) asm("func_00267248");
SelItem* func_002891d0(u32) asm("func_002891d0");
void func_00258080(s32*, s32*) asm("func_00258080");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, u32, u32, u32, s32, s32) asm("Tz__MenuCursor__Create");
void Tz__MenuCursor__SetParent(s32, void*) asm("Tz__MenuCursor__SetParent");
s32 func_0028d6e8(LightCur*) asm("func_0028d6e8");
void Tz__LightCur__Create(LightCur*, s32, u32, u32, u32, void*, s32) asm("Tz__LightCur__Create");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void func_0028d660(LightCur*, void*) asm("func_0028d660");
s32 func_0028cf10(s32) asm("func_0028cf10");
void func_0028cdb8(s32) asm("func_0028cdb8");
void func_002566f0(u32, s32, s32) asm("func_002566f0");
s32 func_00289310(u32) asm("func_00289310");
void Tz__CmEquip__UpdateTopSelActive(s32, s32) asm("Tz__CmEquip__UpdateTopSelActive");
void func_0026d620(s32, s32) asm("func_0026d620");
void Tz__CmCustom__UpdateTopSelActive(s32, s32) asm("Tz__CmCustom__UpdateTopSelActive");
void Tz__CmAbility__UpdateTopSelActive(s32, s32) asm("Tz__CmAbility__UpdateTopSelActive");
void func_002633a8(s32, s32) asm("func_002633a8");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f024 asm("D_0035f024");
extern VObj* D_0035f030 asm("D_0035f030");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035f044 asm("D_0035f044");
extern u32 D_0035f048 asm("D_0035f048");
extern LightCur* D_0035f050 asm("D_0035f050");
extern u8 D_0035f054 asm("D_0035f054");
extern u8 D_0035f055 asm("D_0035f055");
extern u8 D_003729b0[] asm("D_003729b0");
static inline u8 isBusy(SelItem* it)
{
    u8 busy = 0;
    if (it->active || it->sub) busy = 1;
    return busy;
}
#define START_IF_IDLE(sel)                                          \
    if (func_0028acc8(sel) && !func_0028acb8(sel)) {                \
        if (!isBusy(func_002891b8(sel, 0))) func_0028aa40(sel);     \
    }
/*TARGET 00255df0*/
void func_00255df0(void) asm("func_00255df0");
void func_00255df0(void)
{
    s32 mode = func_00287bc0();

    if (func_00287db0()) {
        if (!func_002887c8()) {
            if (func_00139d78((void*)D_0035f03c)) {
                if (func_0023f0c0(D_0035f03c) != 2) func_0023f070(D_0035f03c, 2, -1);
            }
            START_IF_IDLE(D_0035f01c)
            START_IF_IDLE(D_0035f020)
            START_IF_IDLE(D_0035f024)
            func_00254e60();
            func_0028f7a0();
            func_0028d5d0(D_0035f050);
            func_0028ffe8(D_0035f044, 1);
            func_00290508(D_0035f048, 1);
            func_0025f6b8();
            func_002676e8();
            func_0026bbe0();
            func_0026ede0();
            func_002770a8();
            func_0027c540();
            func_00283180();
            func_0027e6e0();
            func_00264408();
        }
        if (func_00139d78(D_0035f030)) D_0035f030->vt->update(D_0035f030);
        func_00263d28();
        func_00288018();
        func_0028ce38();
    }
    func_00256f18();
    if (func_00287db0()) return;

    u32 sel;
    if (mode == 3 || mode == 4 || mode == 22 || mode == 21 || mode == 28 || mode == 13 || mode == 14) {
        sel = D_0035f024;
    } else if (mode == 12) {
        sel = D_0035f020;
    } else if (mode == 24) {
        sel = func_00267248();
    } else {
        sel = D_0035f01c;
    }

    s32 n;
    if (sel == D_0035f020) n = 1;
    else if (sel == D_0035f024 && func_0028acc8(D_0035f01c)) n = (mode == 13) ? 2 : 1;
    else n = 0;
    if (mode == 21 || mode == 24) n = 0;

    if (D_0035f054 == 0) {
        void* target = 0;
        if (func_0028acc8(sel)) {
            if (mode == 36) target = func_002891d0(sel)->sub;
            else target = func_002891d0(sel);
        }
        s32 px, py;
        func_00258080(&px, &py);
        if (func_0028acc8(sel) && func_00287cd0() == 1) {
            if (!func_0028d008(n)) {
                Tz__MenuCursor__Create(n, D_0035ef68, D_0035ef64, D_0035f03c, px, py);
                Tz__MenuCursor__SetParent(n, func_002891d0(sel));
                if (!func_0028d6e8(D_0035f050))
                    Tz__LightCur__Create(D_0035f050, 30026, D_0035ef68, D_0035ef64, D_0035f03c, D_003729b0, 0);
                if (n != 0) {
                    for (s32 i = 0; i < n; i++) {
                        if (func_0028d008(i)) {
                            Tz__MenuCursor__SetType(i, 1);
                        } else {
                            u32 s;
                            if (i == 0) s = D_0035f01c;
                            else s = (sel == D_0035f024) ? D_0035f020 : D_0035f024;
                            Tz__MenuCursor__Create(i, D_0035ef68, D_0035ef64, D_0035f03c, px, py);
                            Tz__MenuCursor__SetParent(i, func_002891d0(s));
                            Tz__MenuCursor__SetType(i, 1);
                        }
                    }
                }
                func_0028d660(D_0035f050, target);
            }
        } else if (func_00287cd0() == 2 && D_0035f055 == 0) {
            if (func_0028d008(n)) {
                if (n == 0) {
                    if (func_0028cf10(0) != 1) Tz__MenuCursor__SetType(0, 1);
                }
            } else {
                Tz__MenuCursor__Create(n, D_0035ef68, D_0035ef64, D_0035f03c, px, py);
                Tz__MenuCursor__SetParent(n, func_002891d0(sel));
                Tz__MenuCursor__SetType(n, 1);
                if (!func_0028d6e8(D_0035f050))
                    Tz__LightCur__Create(D_0035f050, 30026, D_0035ef68, D_0035ef64, D_0035f03c, D_003729b0, 0);
            }
        } else if (func_00287cd0() == 2 && D_0035f055 != 0) {
            if (func_0028d008(n)) {
                func_0028cdb8(n);
                if (n != 0) {
                    Tz__MenuCursor__SetType(n - 1, 0);
                    if (mode == 36) target = func_002891d0(D_0035f01c)->sub;
                    else target = func_002891d0(D_0035f01c);
                    func_0028d660(D_0035f050, target);
                } else {
                    func_0028d5d0(D_0035f050);
                }
            } else if (func_0028d6e8(D_0035f050)) {
                if (n != 0) {
                    if (mode == 36) target = func_002891d0(D_0035f01c)->sub;
                    else if (mode == 13) target = func_002891d0(D_0035f020);
                    else target = func_002891d0(D_0035f01c);
                    func_0028d660(D_0035f050, target);
                } else {
                    func_0028d5d0(D_0035f050);
                }
            }
            if (n != 0) {
                if (func_0028acb8(D_0035f01c) && func_0028d008(0)) {
                    func_0028cdb8(0);
                    func_0028d5d0(D_0035f050);
                }
            }
        }
        if (n != 0 && func_0028acc8(sel) && func_00287cd0() == 0 && func_0028d6e8(D_0035f050)
            && D_0035f050->target != target) {
            func_0028d660(D_0035f050, target);
        }
    } else {
        if (func_0028d008(n)) func_0028ce38();
        if (func_0028d6e8(D_0035f050)) D_0035f050->vt->update((VObj*)D_0035f050);
    }

    if (mode < 0) return;
    if (mode < 37) {
        func_002566f0(sel, mode, n);
        if (mode == 2 || mode == 5 || mode == 6 || mode == 7 || mode == 8 || mode == 9) {
            Tz__CmEquip__UpdateTopSelActive(0, func_00289310(sel));
        } else if (mode == 20 || mode == 22) {
            func_0026d620(n, func_00289310(sel));
        } else if (mode == 26 || mode == 27 || mode == 29 || mode == 30 || mode == 31 || mode == 32 || mode == 33) {
            Tz__CmCustom__UpdateTopSelActive(0, func_00289310(sel));
        } else if (mode >= 16 && mode <= 19) {
            Tz__CmAbility__UpdateTopSelActive(0, func_00289310(sel));
        } else if (mode >= 11 && mode <= 13) {
            func_002633a8(n, func_00289310(sel));
        }
    }
}
}  // namespace n00255df0

// 002566f0 (was src/anon/batch_w1613.cpp)
namespace n002566f0 {
void Tz__CmTop__UpdateHelpMess(void) asm("Tz__CmTop__UpdateHelpMess");
void func_00263340(s32, s32, s32) asm("func_00263340");
void func_00266678(s32, s32, s32) asm("func_00266678");
s32 func_00267270(void) asm("func_00267270");
void Tz__CmEquip__DrawUpdate(s32, s32, s32) asm("Tz__CmEquip__DrawUpdate");
void Tz__CmCustom__DrawUpdate(s32, s32, s32) asm("Tz__CmCustom__DrawUpdate");
void func_0027bbe0(s32, s32, s32) asm("func_0027bbe0");
void func_0027d598(s32, s32, s32) asm("func_0027d598");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00289038(s32, s32, s32, s32, s32, s32, s32) asm("func_00289038");
void func_002890e0(s32, s32, s32, s32, s32) asm("func_002890e0");
void* func_002891d0(s32) asm("func_002891d0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00289358(s32) asm("func_00289358");
void Tz__MenuCursor__SetParent(s32, void*) asm("Tz__MenuCursor__SetParent");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028d660(s32, void*) asm("func_0028d660");
s32 func_0028d6e8(s32) asm("func_0028d6e8");
extern s32 D_0035f050 asm("D_0035f050");
/*TARGET 002566f0*/
void func_002566f0(s32 a0, s32 a1, s32 a2) asm("func_002566f0");
void func_002566f0(s32 a0, s32 a1, s32 a2) {
    s32 s1 = func_00289310(a0);
    if (func_00287cd0() != 1) return;
    if (s1 == 0 && a1 == 24) s1 = func_00267270();
    if (s1 != 0) {
        s32 s4 = func_002891e8(a0);
        if (a1 != 2 && a1 != 5 && a1 != 6 && a1 != 7 && a1 != 8 && a1 != 9) {
            func_002890e0(a0, 1, 2, 0, -1);
            func_00289038(a0, s4, 1, 1, 2, 0, -1);
        }
        if (func_0028d008(a2) != 0) {
            Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
        }
        if (func_0028d6e8(D_0035f050) != 0) {
            void* p;
            if (a1 == 36) p = *(void**)((u8*)func_002891d0(a0) + 0x18c);
            else p = func_002891d0(a0);
            func_0028d660(D_0035f050, p);
        }
    }
    if (s1 == 0 && func_00289358(a0) == 0) return;
    if (a1 == 0) { Tz__CmTop__UpdateHelpMess(); return; }
    if (a1 == 1 || a1 == 10 || a1 == 11 || a1 == 12 || a1 == 13 || a1 == 14) { func_00263340(a0, a1, a2); return; }
    if ((u32)(a1 - 15) < 5) { func_0027bbe0(a0, a1, a2); return; }
    if (a1 == 2 || a1 == 5 || a1 == 6 || a1 == 7 || a1 == 8 || a1 == 9) { Tz__CmEquip__DrawUpdate(a0, a1, a2); return; }
    if ((u32)(a1 - 25) < 3 || a1 == 29 || a1 == 30 || a1 == 31 || a1 == 32 || a1 == 33) { Tz__CmCustom__DrawUpdate(a0, a1, a2); return; }
    if (a1 == 36) { func_0027d598(a0, 36, a2); return; }
    if ((u32)(a1 - 23) < 2) { func_00266678(a0, a1, a2); return; }
}
}  // namespace n002566f0

// 00256a58 (was src/anon/batch_wcx2.cpp)
namespace n00256a58 {
// --------------------
struct E256a58 { u8 pad[20]; u16 id; u8 pad2[14]; };
extern s32 D_0035f01c_256 asm("D_0035f01c");
extern E256a58 D_00372a28[] asm("D_00372a28");
s32 func_0028b040_x10886(s32) asm("func_0028b040");
s32 func_00257fa8(s32) asm("func_00257fa8");
void func_00263a58(s32, s32) asm("func_00263a58");
/*TARGET 00256a58*/
void Tz__CmTop__UpdateHelpMess() asm("Tz__CmTop__UpdateHelpMess");
void Tz__CmTop__UpdateHelpMess() {
    func_00263a58(D_00372a28[func_00257fa8(func_0028b040_x10886(D_0035f01c_256))].id, 1);
}
}  // namespace n00256a58

// 00256aa0 (was src/anon/auto80_199_queue.cpp)
namespace n00256aa0 {
/*TARGET 00256aa0*/
void func_00256aa0(void) asm("_Z13func_00256aa0v");
void func_00256aa0(void) {
    u32 s0 = func_00287dc0();
    if (func_00139d78(s0) != 0) {
        func_0023d820(s0);
    }

    if (func_00139d78(D_0035f040) != 0) {
        Obj00256aa0* obj = (Obj00256aa0*)D_0035f040;
        obj->vtbl->fn20(obj);
    }

    if (func_00290060(D_0035f044) != 0) {
        func_0028ff68(D_0035f044);
    }

    if (func_00290580(D_0035f048) != 0) {
        func_00290488(D_0035f048);
    }

    Tz__SelHist__LeaveAll();
}
}  // namespace n00256aa0

// 00256b40 (was src/anon/batch_w6.cpp)
namespace n00256b40 {
u32 func_002537c8(u32) asm("func_002537c8");
void func_0023fa08(void*, u32) asm("func_0023fa08");
extern u8 D_0035f3a8 asm("D_0035f3a8");
/*TARGET 00256b40*/
void func_00256b40(void) asm("func_00256b40");
void func_00256b40(void) {
    func_0023fa08(&D_0035f3a8, func_002537c8(2));
}
}  // namespace n00256b40

// 00256b68 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00256b68 { // method (was CmTop::GetBaseSprite)
class Sprite;
extern u32 D_0035f028 asm("D_0035f028");
/*TARGET 00256b68*/
// 0x0027d408: definition moved into src/anon/unit_0027d2e8.cpp

dk::Sprite* CmTop_GetBaseSprite(s32 index) asm("_ZN2Tz5CmTop13GetBaseSpriteEi");
dk::Sprite* CmTop_GetBaseSprite(s32 index) {
    u32 base = D_0035f028;
    return reinterpret_cast<dk::Sprite*>(base + ((u32)index * 408));
}
} }  // Tz

// 00256b80 (was src/anon/batch_w6.cpp)
namespace n00256b80 {
struct S408 { u8 d[408]; };
u8 func_00139d78(S408*) asm("func_00139d78");
extern S408* D_0035f028 asm("D_0035f028");
/*TARGET 00256b80*/
u32 func_00256b80(s32 i) asm("func_00256b80");
u32 func_00256b80(s32 i) {
    return func_00139d78(&D_0035f028[i]);
}
}  // namespace n00256b80

// 00256bb0 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00256bb0 { // method (was CmTop::CreateShortCutInfo)
class Sprite;
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035f03c asm("D_0035f03c");
// record884_type_index
extern "C" u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00256bb0*/
void CmTop_CreateShortCutInfo(dk::Sprite* sprite) asm("_ZN2Tz5CmTop18CreateShortCutInfoEPN2dk6SpriteE");
void CmTop_CreateShortCutInfo(dk::Sprite* sprite) {
    u32 s1 = (u32)sprite;
    u32 s0 = CmTop::GetTopBase() + 2504;
    if (func_00139d78(s0) == 0) {
        u32 v0 = MenuCursor::GetPri(0);
        MenuCursor::Create(s0, v0, D_0035ef68, D_0035ef64, D_0035f03c, 24, -1, 0x8454, 0);
        *(u32*)(s0 + 432) = 2;
    }
    MenuCursor::AttachSprite(s0, s1);
}
} }  // Tz

// 00256c40 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00256c40 { // method (was CmTop::LeaveShortCutInfo)
// record884_type_index
extern "C" u32 func_00139d78(...) asm("func_00139d78");
void func_001396b0(...) asm("func_001396b0");
void func_0031a260(...) asm("func_0031a260");
/*TARGET 00256c40*/
void CmTop_LeaveShortCutInfo() asm("_ZN2Tz5CmTop17LeaveShortCutInfoEv");
void CmTop_LeaveShortCutInfo() {
    u32 s0 = CmTop::GetTopBase() + 2504;
    if (func_00139d78(s0) != 0) {
        *(u32*)(s0 + 396) = 0;
        func_001396b0(s0);
        if (*(u32*)(s0 + 396) != 0) {
            *(u32*)(s0 + 400) = 0;
            func_001396b0(s0);
            if (*(u32*)(s0 + 400) != 0) {
                func_0031a260(s0, 0);
            }
        }
        ((dk::Obj2D*)s0)->leave();
    }
}
} }  // Tz

// 00256cc0 (was src/anon/batch_w1893.cpp)
namespace n00256cc0 {
// 00168068: moved to src/anon/unit_00167358.cpp

// --- 00256cc0
extern u8 D_00372940[] asm("D_00372940");
extern u32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
u8* func_00257770(void) asm("func_00257770");
u32 func_00192cc0(u8*, u8*) asm("func_00192cc0");
s32 func_00192b30(u32) asm("func_00192b30");
u32 func_00192048(s32) asm("func_00192048");
s32 func_00192c90(u32, u8*) asm("func_00192c90");
void memcpy(u8*, u8*, s32) asm("memcpy");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0028d980(u8*, u32, u32, u32, u32, s32, s32, s32, s32) asm("func_0028d980");
/*TARGET 00256cc0*/
void Tz__CmTop__CreatePadHelp(s32 a, s32 b, s32 c) asm("Tz__CmTop__CreatePadHelp");
void Tz__CmTop__CreatePadHelp(s32 a, s32 b, s32 c)
{
    u8 sep[16];
    s32 len = 0;
    u8* base = func_00257770();
    s32 seplen = func_00192b30(func_00192cc0(sep, D_00372940));
    u8* buf = base + 0xb290;
    if (c >= 0) {
        len = func_00192c90(func_00192048(c), buf) - 1;
    }
    if (b >= 0) {
        if (len != 0) {
            memcpy(buf + len, sep, seplen);
            len += seplen;
        }
        len = len + func_00192c90(func_00192048(b), buf + len) - 1;
    }
    if (a >= 0) {
        if (len != 0) {
            memcpy(buf + len, sep, seplen);
            len += seplen;
        }
        func_00192c90(func_00192048(a), buf + len);
    }
    u8* o = base + 2940;
    if (!func_00139d78(o)) {
        u32 x = D_0035f3d4;
        func_0028d980(o, x, D_0035ef68, D_0035ef64, D_0035f03c, 237, 238, -1, 0);
        *(u8**)(o + 408) = buf;
        *(s32*)(o + 432) = 1;
    }
}
}  // namespace n00256cc0

// 00256e30 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00256e30 { // method (was CmTop::LoopPadHelp)
// record884_type_index
extern "C" u32 func_00139d78(...) asm("func_00139d78");
void func_0028da70(...) asm("func_0028da70");
/*TARGET 00256e30*/
void CmTop_LoopPadHelp() asm("_ZN2Tz5CmTop11LoopPadHelpEv");
void CmTop_LoopPadHelp() {
    u32 s0 = CmTop::GetTopBase() + 2940;
    u32 v0 = func_00139d78(s0);
    if (v0 != 0) {
        func_0028da70(s0, 238);
    }
}
} }  // Tz

// 00256e80 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00256e80 { // method (was CmTop::FadeOutPadHelp)
void func_0028dac8(...) asm("func_0028dac8");
/*TARGET 00256e80*/
void CmTop_FadeOutPadHelp() asm("_ZN2Tz5CmTop14FadeOutPadHelpEv");
void CmTop_FadeOutPadHelp() {
    func_0028dac8(CmTop::GetTopBase() + 2940, 239);
}
} }  // Tz

// 00256ea8 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00256ea8 { // method (was CmTop::LeavePadHelp)
// record884_type_index
extern "C" u32 func_00139d78(...) asm("func_00139d78");
/*TARGET 00256ea8*/
void CmTop_LeavePadHelp() asm("_ZN2Tz5CmTop12LeavePadHelpEv");
void CmTop_LeavePadHelp() {
    u32 s0 = CmTop::GetTopBase() + 2940;
    if (func_00139d78(s0) != 0) {
        ((dk::Obj2D*)s0)->leave();
    }
}
} }  // Tz

// 00256ef0 (was src/anon/batch_w5.cpp)
namespace n00256ef0 {
// 0x00226f90: definition moved into src/anon/unit_00224780.cpp

u8* func_00257770(void) asm("func_00257770");
u8 func_00139d78(u8*) asm("func_00139d78");
/*TARGET 00256ef0*/
u32 func_00256ef0(void) asm("func_00256ef0");
u32 func_00256ef0(void) {
    return func_00139d78(func_00257770() + 2940);
}
}  // namespace n00256ef0

// 00256f18 (was src/anon/batch_w90.cpp)
namespace n00256f18 {
s32 func_0028acc8(void*) asm("func_0028acc8");
// 0x00248900: definition moved into src/anon/unit_00247ff0.cpp

// 00256f18
extern void* D_0035f01c asm("D_0035f01c");
extern void* D_0035f020 asm("D_0035f020");
extern void* D_0035f024 asm("D_0035f024");
s32 func_002892f8(void*) asm("func_002892f8");
void func_00288e88(void*) asm("func_00288e88");
/*TARGET 00256f18*/
void func_00256f18(void) asm("func_00256f18");
void func_00256f18(void)
{
    if (D_0035f01c) { s32 s = func_002892f8(D_0035f01c); if (!func_0028acc8(D_0035f01c) && s) func_00288e88(D_0035f01c); }
    if (D_0035f020) { s32 s = func_002892f8(D_0035f020); if (!func_0028acc8(D_0035f020) && s) func_00288e88(D_0035f020); }
    if (D_0035f024) { s32 s = func_002892f8(D_0035f024); if (!func_0028acc8(D_0035f024) && s) func_00288e88(D_0035f024); }
}
}  // namespace n00256f18

// 00257000 (was src/anon/auto200_999.cpp)
namespace n00257000 {
extern u8 D_0035ef78 asm("D_0035ef78");
/*TARGET 00257000*/
// 0x001e7650: definition moved into src/anon/unit_001e0cb8.cpp

void func_00257000() asm("_Z13func_00257000v");
// 0x001e7650: definition moved into src/anon/unit_001e0cb8.cpp

void func_00257000() {
    s32 c = 0;
    s32 d = 0;
    do {
        u16 *p = (u16 *)((u8 *)&D_0035ef78 + d);
        s32 e = 37;
        do {
            *p = 0u;
            e -= 1;
            p += 1;
        } while (e >= 0);
        c += 1;
        d += 76;
    } while (c < 2);
}
}  // namespace n00257000

// 00257050 (was src/anon/tiny_auto80_solver.cpp)
namespace n00257050 {
extern u8 D_0035ef78 asm("D_0035ef78");
/*TARGET 00257050*/
void func_00257050(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00257050jjjjjjjj");
void func_00257050(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0035ef78;
    r4 = (u32)(r4 << 1);    r4 = (u32)(r4 + r15);
    *(u16*)((u32)r4 + (s32)(0)) = (u16)r5;
    *(u16*)((u32)r4 + (s32)(76)) = (u16)r6;
}
}  // namespace n00257050

// 00257070 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257070 { // method (was CmTop::GetCurPos)
extern u32 D_0035ef78 asm("D_0035ef78");
/*TARGET 00257070*/
s32 CmTop_GetCurPos(s32 index) asm("_ZN2Tz5CmTop9GetCurPosEi");
s32 CmTop_GetCurPos(s32 index) {
    return (s32)(*(s16*)((u32)&D_0035ef78 + ((u32)index << 1)));
}
} }  // Tz

// 00257088 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257088 { // method (was CmTop::GetCurTopPos)
extern u32 D_0035ef78 asm("D_0035ef78");
/*TARGET 00257088*/
s32 CmTop_GetCurTopPos(s32 index) asm("_ZN2Tz5CmTop12GetCurTopPosEi");
s32 CmTop_GetCurTopPos(s32 index) {
    u32 p = (u32)&D_0035ef78 + ((u32)index << 1);
    return (s32)(*(s16*)(p + 76));
}
} }  // Tz

// 002570a0 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n002570a0 { // method (was CmTop::GetSelectPos)
/*TARGET 002570a0*/
s32 CmTop_GetSelectPos(s32 index) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 CmTop_GetSelectPos(s32 index) {
    return (s32)(CmTop::GetCurPos(index) + CmTop::GetCurTopPos(index));
}
} }  // Tz

// 002570e0 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n002570e0 { // method (was CmTop::GetTopSelSeqTbl)
extern u16 D_00372a28 asm("D_00372a28");
/*TARGET 002570e0*/
u16* CmTop_GetTopSelSeqTbl() asm("_ZN2Tz5CmTop15GetTopSelSeqTblEv");
u16* CmTop_GetTopSelSeqTbl() { return (u16*)&D_00372a28; }
} }  // Tz

// 002570f0 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n002570f0 { // method (was CmTop::GetScrBarSeqTbl)
extern u32 D_003729c8 asm("D_003729c8");
/*TARGET 002570f0*/
void* CmTop_GetScrBarSeqTbl() asm("_ZN2Tz5CmTop15GetScrBarSeqTblEv");
void* CmTop_GetScrBarSeqTbl() { return &D_003729c8; }
} }  // Tz

// 00257100 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257100 { // method (was CmTop::GetTopPlateSeqTbl)
extern u32 D_003729e0 asm("D_003729e0");
/*TARGET 00257100*/
void* CmTop_GetTopPlateSeqTbl(s32 index) asm("_ZN2Tz5CmTop17GetTopPlateSeqTblEi");
void* CmTop_GetTopPlateSeqTbl(s32 index) {
    return reinterpret_cast<void*>((u32)&D_003729e0 + ((u32)index << 3));
}
} }  // Tz

// 00257118 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257118 { // method (was CmTop::GetTopPlate2SeqTbl)
extern u32 D_003729f0 asm("D_003729f0");
/*TARGET 00257118*/
void* CmTop_GetTopPlate2SeqTbl(s32 index) asm("_ZN2Tz5CmTop18GetTopPlate2SeqTblEi");
void* CmTop_GetTopPlate2SeqTbl(s32 index) {
    return reinterpret_cast<void*>((u32)&D_003729f0 + ((u32)index << 3));
}
} }  // Tz

// 00257130 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257130 { // method (was CmTop::GetItemInfo)
extern u32 D_0035f010 asm("D_0035f010");
/*TARGET 00257130*/
void* CmTop_GetItemInfo() asm("_ZN2Tz5CmTop11GetItemInfoEv");
void* CmTop_GetItemInfo() {
    return reinterpret_cast<void*>(*(u32*)((u32)&D_0035f010 + 4));
}
} }  // Tz

// 00257140 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257140 { // method (was CmTop::GetFontColorSeqNum)
extern u32 D_00372978 asm("D_00372978");
/*TARGET 00257140*/
s32 CmTop_GetFontColorSeqNum(s32 index) asm("_ZN2Tz5CmTop18GetFontColorSeqNumEi");
s32 CmTop_GetFontColorSeqNum(s32 index) {
    return (s32)(*(s16*)((u32)&D_00372978 + ((u32)index << 1)));
}
} }  // Tz

// 00257158 (was src/anon/batch_w52.cpp)
namespace n00257158 {
u8* func_001a80c8(u32) asm("func_001a80c8");
// table24_find_by_id
s32 func_001a6598(u16) asm("func_001a6598");
/*TARGET 00257158*/
s32 func_00257158(u32 id, s32 a, u8 b) asm("func_00257158");
s32 func_00257158(u32 id, s32 a, u8 b) {
    if (!id) return 0;
    u8* e = func_001a80c8(id);  // table24_find_by_id
    u8 t = e[2];
    if (t == 0) {
        if (b) {
            s32 r = 3;
            if (a) r = 0;
            return r;
        }
        return 0;
    }
    if (t == 18) return func_001a6598(*(u16*)(e + 4)) == 2 ? b != 0 : 0;
    return 0;
}
}  // namespace n00257158

// 002571e0 (was src/anon/perm_002571e0.cpp)
namespace n002571e0 {
typedef unsigned char u8;
typedef signed int s32;
struct W1950Obj
{
  u8 pad[0x18c];
  s32 f18c;
  s32 f190;
};
struct W1950Mgr
{
  u8 pad[0x18];
  u8 sub[1];
};
void func_00138c68(W1950Obj *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void func_00138c78(W1950Obj *, s32 *, s32 *) asm("_ZN2dk6Sprite12getOffsetPosERiS1_");
void func_001396b0(W1950Obj *) asm("_ZN2Tz6Select10BeginLeaveEz");
s32 func_00139d78(W1950Mgr *) asm("_Z16u_call4_00139d78jjjj");
s32 func_0023aa18(void *) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 func_0023aa38(void *) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void Tz__CmComm__CreateConfirmSelector(void *, s32, s32, s32, s32, s32, void *) asm("Tz__CmComm__CreateConfirmSelector");
void func_00288f48(void *, s32, s32, s32, s32) asm("_ZN2Tz6Select10SetMoveKeyEiiii");
W1950Obj *func_002891b8(void *, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 func_002892f8(void *) asm("_ZN2Tz6Select10GetItemMaxEv");
void func_0028af28(void *, s32) asm("_ZN2Tz6Select16SetDisableButtonEj");
void func_0031a260(W1950Obj *, s32) asm("_ZN2Tz6Select7SetFlagEz");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035f03c asm("D_0035f03c");
extern void *D_0035f024 asm("D_0035f024");
extern W1950Mgr *D_0035f034 asm("D_0035f034");
extern u8 D_00372a10[] asm("D_00372a10");
/*TARGET 002571e0*/
void func_002571e0(s32 arg0) asm("func_002571e0");
void func_002571e0(s32 arg0)
{
  s32 i;
  s32 x;
  s32 y;
  W1950Mgr **new_var;
  W1950Obj *o;
  Tz__CmComm__CreateConfirmSelector(D_0035f024, 0x7549, D_0035ef68, D_0035ef64, D_0035f03c, arg0, D_00372a10);
  func_00288f48(D_0035f024, 0x80, 0x40, 0, 0);
  func_0028af28(D_0035f024, 0x40);
  if (func_00139d78(D_0035f034) == 0)
  {
    return;
  }
  for (i = 0; i < func_002892f8(D_0035f024); i++)
  {
    new_var = &D_0035f034;
    o = func_002891b8(D_0035f024, i);
    o->f18c = (s32) (*new_var);
    func_001396b0(o);
    if (o->f18c != 0)
    {
      o->f190 = 0;
      func_001396b0(o);
      if (o->f190 != 0)
      {
        func_0031a260(o, 0);
 do { } while (0);
      }
    }
    func_00138c78(func_002891b8(D_0035f024, i), &x, &y);
    x += func_0023aa18(D_0035f034->sub);
    y += func_0023aa38(D_0035f034->sub);
    func_00138c68(func_002891b8(D_0035f024, i), x, y);
    func_001396b0(func_002891b8(D_0035f024, i));
  }

}
}  // namespace n002571e0

// 00257388 (was src/anon/batch_w89.cpp)
namespace n00257388 {
struct VObj2 { void (**vt)(VObj2*); };
struct Pt8 { s16 x, p, y, q; };
extern u32 D_0035f034 asm("D_0035f034");
extern Pt8 D_00372a00 asm("D_00372a00");
extern Pt8 D_00372a08 asm("D_00372a08");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
s32 func_00139d78(void*) asm("func_00139d78");
void func_0028d980(u32, u32, u32, u32, u32, s32, s32, u32, u32) asm("func_0028d980");
void func_00139620(u32) asm("func_00139620");
/*TARGET 00257388*/
void func_00257388(u32 a0, s32 a1) asm("func_00257388");
void func_00257388(u32 a0, s32 a1) {
    if (func_00139d78((void*)D_0035f034)) ((VObj2*)D_0035f034)->vt[5]((VObj2*)D_0035f034);
    Pt8* t = !a1 ? &D_00372a00 : &D_00372a08;
    func_0028d980(D_0035f034, 30022, D_0035ef68, D_0035ef64, D_0035f03c, t->x, t->y, a0, 0);
    func_00139620(D_0035f034);
    *(u32*)(D_0035f034 + 432) = 2;
    u32 s = D_0035f034 + 24;
    *(u32*)(s + 184) |= 8;
}
}  // namespace n00257388

// 00257458 (was src/anon/batch_w81.cpp)
namespace n00257458 {
typedef void (*VFnV81)(...);
struct VObjV81 { VFnV81* vt; };
s32 func_00139d78(u32) asm("func_00139d78");
// 0x00252c20: definition moved into src/anon/unit_00250fb8.cpp

// --- 00257458
extern u32 D_0035f034 asm("D_0035f034");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
struct P257 { s16 x, y, z, w; };
extern P257 D_00372a00 asm("D_00372a00");
extern P257 D_00372a08 asm("D_00372a08");
void func_0028d980(u32, u32, u32, u32, u32, s32, s32, s32, u32) asm("func_0028d980");
void func_00139620(u32) asm("func_00139620");
/*TARGET 00257458*/
void func_00257458(u32 a, s32 b) asm("func_00257458");
void func_00257458(u32 a, s32 b) {
    if (func_00139d78(D_0035f034)) (*(VObjV81*)D_0035f034).vt[5](D_0035f034);
    P257* p;
    if (b == 0) p = &D_00372a00; else p = &D_00372a08;
    func_0028d980(D_0035f034, 30022, D_0035ef68, D_0035ef64, D_0035f03c, p->x, p->z, -1, 0);
    *(u32*)(D_0035f034 + 408) = a;
    func_00139620(D_0035f034);
    *(u32*)(D_0035f034 + 432) = 2;
    u8* q = (u8*)D_0035f034 + 24;
    *(u32*)(q + 184) |= 8;
}
}  // namespace n00257458

// 00257530 (was src/anon/auto80_199_queue.cpp)
namespace n00257530 {
/*TARGET 00257530*/
void func_00257530(u32 a0) asm("_Z13func_00257530j");
void func_00257530(u32 a0) {
    u8* p;

    if (a0 != 0) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    func_0028dac8(D_0035f034, *(s16*)(p + 2));

    if (func_0028acc8(D_0035f024) != 0) {
        if (func_0028acb8(D_0035f024) == 0) {
            func_0028aa40(D_0035f024);
        }
    }
}
}  // namespace n00257530

// 002575a8 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n002575a8 { // method (was CmTop::LeaveWarningWin)
extern u32 D_0035f024 asm("D_0035f024");
extern u32 D_0035f034 asm("D_0035f034");
// record884_type_index
extern "C" u32 func_00139d78(...) asm("func_00139d78");
u32 func_0028acc8(...) asm("func_0028acc8");
void func_0028abe0(...) asm("func_0028abe0");
/*TARGET 002575a8*/
void CmTop_LeaveWarningWin() asm("_ZN2Tz5CmTop15LeaveWarningWinEv");
void CmTop_LeaveWarningWin() {
    if (func_00139d78(D_0035f034) != 0) {
        ObjCmTopWarningWin* obj = (ObjCmTopWarningWin*)D_0035f034;
        obj->vtbl->fn20(obj);
    }

    if (func_0028acc8(D_0035f024) != 0) {
        func_0028abe0(D_0035f024);
    }
}
} }  // Tz

// 00257610 (was src/anon/auto80_199_queue.cpp)
namespace n00257610 {
/*TARGET 00257610*/
u32 func_00257610(u32 a0) asm("_Z13func_00257610j");
u32 func_00257610(u32 a0) {
    u32 s0 = a0;
    if (func_002576d0(a0) == 0) {
        return 0;
    }

    u8* p;
    if (s0 != 0) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    s32 t4 = *(s16*)(p + 4);
    u32 t5 = *(u32*)(D_0035f034 + 388);
    u32 t7 = t5 ^ (u32)t4;
    t7 = (t7 < 1) ? 1u : 0u;
    return t7;
}
}  // namespace n00257610

// 00257670 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257670 { // method (was CmTop::LoopWarningWin)
extern u32 D_0035f034 asm("D_0035f034");
extern u8 D_00372a00 asm("D_00372a00");
extern u8 D_00372a08 asm("D_00372a08");
void func_0028da70(...) asm("func_0028da70");
/*TARGET 00257670*/
void CmTop_LoopWarningWin(s32 which) asm("_ZN2Tz5CmTop14LoopWarningWinEi");
void CmTop_LoopWarningWin(s32 which) {
    u32 s0 = (u32)which;
    if (CmTop::IsWarningEnabled(s0) == 0) {
        return;
    }

    u8* p;
    if (s0 != 0u) {
        goto nonzero;
    }
    p = &D_00372a00;
    goto cont;

nonzero:
    p = &D_00372a08;

cont:
    func_0028da70(D_0035f034, *(s16*)(p + 4));
}
} }  // Tz

// 002576d0 (was src/anon/batch_w17.cpp)
namespace n002576d0 {
u32 func_00139d78(void*) asm("func_00139d78");
// 0x00246968: definition moved into src/anon/unit_00242478.cpp

extern u32 D_0035f034 asm("D_0035f034");
extern u32 D_0035f024 asm("D_0035f024");
u32 func_0028acc8(u32) asm("func_0028acc8");
u32 IsWarningEnabled(...) asm("_ZN2Tz5CmTop16IsWarningEnabledEz");
/*TARGET 002576d0*/
u32 IsWarningEnabled(...) asm("_ZN2Tz5CmTop16IsWarningEnabledEz");
u32 IsWarningEnabled(...) {
    u32 r = func_00139d78((void*)D_0035f034);
    if (r == 0) r = func_0028acc8(D_0035f024);
    return r;
}
}  // namespace n002576d0

// 00257708 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257708 { // method (was CmTop::SetHideCursor)
extern u8 D_0035f054 asm("D_0035f054");
/*TARGET 00257708*/
void CmTop_SetHideCursor(bool value) asm("_ZN2Tz5CmTop13SetHideCursorEb");
void CmTop_SetHideCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    *(u8*)&D_0035f054 = (u8)v;
}
} }  // Tz

// 00257718 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257718 { // method (was CmTop::SetDelCursor)
extern u8 D_0035f055 asm("D_0035f055");
/*TARGET 00257718*/
void CmTop_SetDelCursor(bool value) asm("_ZN2Tz5CmTop12SetDelCursorEb");
void CmTop_SetDelCursor(bool value) {
    u32 v = (u32)value & 0xffu;
    D_0035f055 = (u8)v;
}
} }  // Tz

// 00257728 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257728 { // method (was CmTop::DelCursor)
extern u32 D_0035f050 asm("D_0035f050");
/*TARGET 00257728*/
void CmTop_DelCursor() asm("_ZN2Tz5CmTop9DelCursorEv");
void CmTop_DelCursor() {
    MenuCursor::DeleteAll();
    if (MenuCursor::isAlive(D_0035f050) != 0) {
        u32 t7 = D_0035f050;
        u32 t6 = *(u32*)t7;
        u32 t5 = *(u32*)(t6 + 20);
        ((void(*)(u32))t5)(t7);
    }
}
} }  // Tz

// 00257770 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00257770 { // method (was CmTop::GetListBuffer)
extern u32 D_0035f038 asm("D_0035f038");
/*TARGET 00257770*/
void* CmTop_GetListBuffer() asm("_ZN2Tz5CmTop13GetListBufferEv");
void* CmTop_GetListBuffer() { return reinterpret_cast<void*>(D_0035f038); }
} }  // Tz

// 00257780 (was src/anon/tiny_auto80_queue.cpp)
namespace n00257780 {
u32 func_002577b0(...) asm("func_002577b0");
u32 func_00257910(...) asm("func_00257910");
/*TARGET 00257780*/
u32 func_00257780(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00257780jjjjjjjj");
u32 func_00257780(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r2 = ((u32(*)())func_002577b0)();
    if (r2 == 0u) {
        r2 = ((u32(*)())func_00257910)();
    }
    return r2;
}
}  // namespace n00257780

// 002577b0 (was src/anon/batch_w3732.cpp)
namespace n002577b0 {
s32 func_00139d78(u8*) asm("func_00139d78");
extern u8* D_0035f038 asm("D_0035f038");
/*TARGET 002577b0*/
// 002577b0: runs check func_00139d78 over every slot of the D_0035f038 block (7 singles, then 24 rows of 4);
// returns the first nonzero result. The loop result lives in its own variable and leaves by break: that keeps
// a return copy at the loop exit until register allocation, so the exits lose their loop-exit mark and reorg
// fills them from the epilogue (bnezl + ld s0) like the original.
s32 func_002577b0(void) asm("func_002577b0");
// 002577b0: runs check func_00139d78 over every slot of the D_0035f038 block (7 singles, then 24 rows of 4);
// returns the first nonzero result. The loop result lives in its own variable and leaves by break: that keeps
// a return copy at the loop exit until register allocation, so the exits lose their loop-exit mark and reorg
// fills them from the epilogue (bnezl + ld s0) like the original.
s32 func_002577b0(void) {
    s32 i;
    s32 r = 0;
    s32 t;
    if (D_0035f038) {
        r = func_00139d78(D_0035f038);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x198);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x330);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x4c8);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x660);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x814);
        if (r) return r;
        r = func_00139d78(D_0035f038 + 0x9c8);
        if (r) return r;
        for (i = 0; i < 24; i++) {
            t = func_00139d78(D_0035f038 + i * 0x1b4 + 0xd30);
            if (t) break;
            t = func_00139d78(D_0035f038 + i * 0x1b4 + 0x3610);
            if (t) break;
            t = func_00139d78(D_0035f038 + i * 0x1b4 + 0x5ef0);
            if (t) break;
            t = func_00139d78(D_0035f038 + i * 0x198 + 0x87d0);
            if (t) break;
        }
        return t;
    }
    return r;
}
}  // namespace n002577b0

// 00257910 (was src/anon/auto80_199_queue.cpp)
namespace n00257910 {
/*TARGET 00257910*/
u32 func_00257910(void) asm("_Z13func_00257910v");
u32 func_00257910(void) {
    u32 v0 = func_00139d78(D_0035f038 + 0xb350);
    if (v0 != 0) {
        return v0;
    }

    v0 = func_00139d78(D_0035f038 + 0xb504);
    if (v0 != 0) {
        return v0;
    }

    u32 r3 = func_00139d78(D_0035f038 + 0xb6b8);
    v0 = r3;
    return v0;
}
}  // namespace n00257910

// 00257970 (was src/anon/batch_w49.cpp)
namespace n00257970 {
s32 func_00139d78(void*) asm("func_00139d78");
// 0x0024f240: definition moved into src/anon/unit_0024e7e8.cpp

extern u8* D_0035f038 asm("D_0035f038");
/*TARGET 00257970*/
void func_00257970(void) asm("func_00257970");
void func_00257970(void) {
    for (s32 i = 0; i < 24; i++)
        if (func_00139d78(D_0035f038 + i * 408 + 0x87d0)) break;
}
}  // namespace n00257970

// 002579e0 (was src/anon/tiny_jal_tail_wrappers.cpp)
namespace n002579e0 {
u32 func_00257a00() asm("_Z13func_00257a00v");
u32 Tz__CmTop__LeaveListSubWin() asm("_Z26Tz__CmTop__LeaveListSubWinv");
/*TARGET 002579e0*/
u32 func_002579e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002579e0jjjj");
u32 func_002579e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00257a00();
    return Tz__CmTop__LeaveListSubWin();
}
}  // namespace n002579e0

// 00257a00 (was src/anon/batch_w295.cpp)
namespace n00257a00 {
// 0x0022f018: definition moved into src/anon/unit_0022d358.cpp
typedef void (*VF5)(void*);
struct O408a { VF5* vt; u8 pad[404]; };
struct O436a { VF5* vt; u8 pad[432]; };
struct W5 { O408a a[5]; u8 p0[28]; O436a b[2]; O436a x; O436a c[24]; O436a d[24]; O436a e[24]; O408a f[24]; };
extern W5* D_0035f038 asm("D_0035f038");
s32 chk_139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void lv_139510(void*) asm("_ZN2dk5Obj2D5leaveEv");
void ctarget0_00257a00(void) asm("_Z17ctarget0_00257a00v");
/*TARGET 00257a00*/
void ctarget0_00257a00(void) asm("_Z17ctarget0_00257a00v");
void ctarget0_00257a00(void) {
  s32 i;
  if (chk_139d78(&D_0035f038->a[0])) lv_139510(&D_0035f038->a[0]);
  if (chk_139d78(&D_0035f038->a[1])) lv_139510(&D_0035f038->a[1]);
  if (chk_139d78(&D_0035f038->a[2])) lv_139510(&D_0035f038->a[2]);
  if (chk_139d78(&D_0035f038->a[3])) lv_139510(&D_0035f038->a[3]);
  if (chk_139d78(&D_0035f038->a[4])) lv_139510(&D_0035f038->a[4]);
  if (chk_139d78(&D_0035f038->b[0])) lv_139510(&D_0035f038->b[0]);
  if (chk_139d78(&D_0035f038->b[1])) lv_139510(&D_0035f038->b[1]);
  for (i = 0; i < 24; i++) {
    if (chk_139d78(&D_0035f038->c[i])) D_0035f038->c[i].vt[5](&D_0035f038->c[i]);
    if (chk_139d78(&D_0035f038->d[i])) D_0035f038->d[i].vt[5](&D_0035f038->d[i]);
    if (chk_139d78(&D_0035f038->e[i])) D_0035f038->e[i].vt[5](&D_0035f038->e[i]);
    if (chk_139d78(&D_0035f038->f[i])) D_0035f038->f[i].vt[5](&D_0035f038->f[i]);
  }
}
}  // namespace n00257a00

// 00257be0 (was src/anon/batch_w61.cpp)
namespace n00257be0 {
// 0x002282f0: definition moved into src/anon/unit_00224780.cpp

s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
extern u8* D_0035f038 asm("D_0035f038");
void Tz__CmTop__LeaveListSubWin(void*) asm("_Z26Tz__CmTop__LeaveListSubWinPv");
/*TARGET 00257be0*/
void Tz__CmTop__LeaveListSubWin(void*) asm("_Z26Tz__CmTop__LeaveListSubWinPv");
void Tz__CmTop__LeaveListSubWin(void*) {
    if (func_00139d78(D_0035f038 + 0xb350)) func_00139510(D_0035f038 + 0xb350);
    if (func_00139d78(D_0035f038 + 0xb504)) func_00139510(D_0035f038 + 0xb504);
    if (func_00139d78(D_0035f038 + 0xb6b8)) func_00139510(D_0035f038 + 0xb6b8);
}
}  // namespace n00257be0

// 00257c78 (was src/anon/batch_wcx2.cpp)
namespace n00257c78 {
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
extern u8 D_0032bae0 asm("D_0032bae0");
// 0x0024c6a0: definition moved into src/anon/unit_0024ba58.cpp

extern u32 D_0035f010 asm("D_0035f010");
extern s8 D_0035f058 asm("D_0035f058");
extern s8 D_0035f059 asm("D_0035f059");
extern s8 D_0035f05a asm("D_0035f05a");
extern s8 D_0035f064 asm("D_0035f064");
extern u8 D_0035f060[] asm("D_0035f060");
s32 func_00281100(u32) asm("func_00281100");
s32 func_002813b8(void) asm("func_002813b8");
s32 func_0027aa78(void) asm("func_0027aa78");
u8* func_001a8bd0(s32) asm("func_001a8bd0");
s32 func_001a8bf8(u8*, s32) asm("func_001a8bf8");
// get_bits5_at
void func_00257000(void) asm("func_00257000");
/*TARGET 00257c78*/
void func_00257c78(void) asm("func_00257c78");
void func_00257c78(void)
{
    s32 i = 0;
    s32 cnt = 0;
    s32 cur = func_00281100(D_0035f010);
    s32 m = func_002813b8();
    for (; i < 7; i++) cnt += (m >> i) & 1;
    s32 flag = func_0027aa78() != 0;
    s32 d = 0;
    if (cur != D_0035f058 || D_0035f059 != cnt || D_0035f05a != flag || D_0035f064 != D_0032bae0) d = 1;
    s32 chg = d;
    if (!d && cur == D_0035f058) {
        u8* a = func_001a8bd0(-1);
        for (i = 0; i < 4; i++) {
            if (func_001a8bf8(D_0035f060, i) != func_001a8bf8(a, i)) {  // get_bits5_at
                chg = 1;
                break;
            }
        }
    }
    if (chg) func_00257000();
    D_0035f059 = cnt;
    D_0035f05a = flag;
    D_0035f058 = cur;
    D_0035f064 = D_0032bae0;
}
}  // namespace n00257c78

// 00257e00 (was src/anon/batch_w3699.cpp)
namespace n00257e00 {
struct Ent { u8 pad[0x1c]; s8 a[4]; s8 b[4]; };
struct Sub { u8 pad[0x54]; u16 f54; };
struct Obj2 { u8 pad[0x244]; Sub* p244; };
extern Ent D_00372a28[] asm("D_00372a28");
extern void* D_0035f010 asm("D_0035f010");
s32 func_001a6d08(s32) asm("func_001a6d08");
s32 func_00281100(void*) asm("func_00281100");
Obj2* func_00281180(void*, s32) asm("func_00281180");
s32 func_00181500(s32) asm("func_00181500");
/*TARGET 00257e00*/
s32 func_00257e00(void) asm("func_00257e00");
s32 func_00257e00(void) {
    s32 i, j;
    s32 ok;
    s32 mask = 0;
    for (i = 0; i < 8; i++) {
        if (i == 1) continue;
        Ent* e = &D_00372a28[i];
        ok = 1;
        {
            s8* p;
            j = 0;
            p = e->a;
            for (; j < 4; j++) {
                s8 c = *p++;
                if (c < 0) break;
                if (func_001a6d08(c) == 0) { ok = 0; break; }
            }
        }
        if (!ok) continue;
        Ent* f;
        for (j = 0, f = &D_00372a28[i]; j < 4; j++) {
            s8 c = *(f->b + j);
            if (c < 0) break;
            if (func_001a6d08(c) != 0) { ok = 0; break; }
        }
        if (ok) mask |= 1 << i;
    }
    ok = 0;
    for (i = 0; i < func_00281100(D_0035f010); i++) {
        ok = (func_00281180(D_0035f010, i)->p244->f54 & 0x7fff) != 0;
        if (ok) break;
    }
    if (ok) {
        if (func_00181500(0x817) && !func_00181500(0x849)) ok = 0;
        if (ok) mask |= 2;
    }
    return mask;
}
}  // namespace n00257e00

// 00257fa8 (was src/anon/batch_w28.cpp)
namespace n00257fa8 {
extern u16 D_0035ef70 asm("D_0035ef70");
/*TARGET 00257fa8*/
// Index of the n-th set bit (of 8) in the mask, or -1.
s32 func_00257fa8(s32 n) asm("func_00257fa8");
// Index of the n-th set bit (of 8) in the mask, or -1.
s32 func_00257fa8(s32 n) {  // nth_set_bit_index
    s32 r = -1;
    s32 m = D_0035ef70;
    s32 c = 0;
    for (s32 i = 0; i < 8; i++) {
        if ((u8)((m >> i) & 1)) {
            if (c == n) { r = i; break; }
            c++;
        }
    }
    return r;
}
}  // namespace n00257fa8

// 00257ff8 (was src/anon/batch_w29.cpp)
namespace n00257ff8 {
extern u16 D_0035ef70 asm("D_0035ef70");
/*TARGET 00257ff8*/
// Rank of bit n among the set bits of D_0035ef70 (-1 if not set).
s32 func_00257ff8(s32 n) asm("func_00257ff8");
// Rank of bit n among the set bits of D_0035ef70 (-1 if not set).
s32 func_00257ff8(s32 n) {
    s32 r = -1;
    s32 m = D_0035ef70;
    s32 k = 0;
    for (s32 i = 0; i < 8; i++) {
        if ((u8)((m >> i) & 1)) {
            if (i == n) { r = k; break; }
            k++;
        }
    }
    return r;
}
}  // namespace n00257ff8

// 00258048 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00258048 { // method (was CmTop::GetSram)
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 00258048*/
u32 CmTop_GetSram() asm("_ZN2Tz5CmTop7GetSramEv");
u32 CmTop_GetSram() {
    u32 r2 = getSaveRam();
    r2 = (u32)((s32)r2 + 16808);
    return r2;
}
} }  // Tz

// 00258068 (was src/anon/auto200_999.cpp)
namespace n00258068 {
extern u16 D_0035ef70 asm("D_0035ef70");
/*TARGET 00258068*/
// 0x00226f78: definition moved into src/anon/unit_00224780.cpp

u32 func_00258068(u32 a0) asm("_Z13func_00258068j");
// 0x00226f78: definition moved into src/anon/unit_00224780.cpp

u32 func_00258068(u32 a0) {  // get_global_bit
    s32 v = D_0035ef70;
    v >>= a0;
    v &= 1;
    u8 ret = (u8)v;
    return ret;
}
}  // namespace n00258068

// 00258080 (was src/anon/batch_w53.cpp)
namespace n00258080 {
extern s8 D_00372958[] asm("D_00372958");
s32 func_00287bc0(void) asm("func_00287bc0");
/*TARGET 00258080*/
// 0x00252618: definition moved into src/anon/unit_00250fb8.cpp

// Look the current id up in a -1 terminated table.
void func_00258080(s32* a, s32* b) asm("func_00258080");
// 0x00252618: definition moved into src/anon/unit_00250fb8.cpp

// Look the current id up in a -1 terminated table.
void func_00258080(s32* a, s32* b) {
    s32 v = func_00287bc0();
    bool found = false;
    for (s32 i = 0; D_00372958[i] >= 0; i++) {
        if (v == D_00372958[i]) {
            found = true;
            break;
        }
    }
    if (!found) {
        *a = 25;
        *b = 23;
    } else {
        *a = 22;
        *b = 21;
    }
}
}  // namespace n00258080

// 00258108 (was src/tozawa/cmenu_top.cpp)
namespace Tz { namespace n00258108 { // method (was CmTop::GetPartyInfo)
extern u32 D_0035f010 asm("D_0035f010");
/*TARGET 00258108*/
void* CmTop_GetPartyInfo() asm("_ZN2Tz5CmTop12GetPartyInfoEv");
void* CmTop_GetPartyInfo() { return reinterpret_cast<void*>(D_0035f010); }
} }  // Tz

// 00258118 (was unwritten gap)
namespace n00258118 {
s32 func_00258118(void) asm("func_00258118");
s32 func_00258118(void) { return 1; }
}  // namespace

// 00258120 (was src/anon/tiny_auto80_queue.cpp)
namespace n00258120 {
u32 func_001a8bb8(...) asm("func_001a8bb8");
// obj_set_header_bytes
extern u8 D_0035f060 asm("D_0035f060");
/*TARGET 00258120*/
void func_00258120(u32 a0, u32 a1) asm("_Z13func_00258120jj");
void func_00258120(u32 a0, u32 a1) {
    u32 t7 = 0xffffu;
    if (a1 != t7) {
        return;
    }
    t7 = 1u;
    if (a0 != t7) {
        return;
    }
    u32 t0 = (u32)&D_0035f060;
    a0 = t0;
    func_001a8bb8(a0);  // obj_set_header_bytes
}
}  // namespace n00258120

// 00258158 (was src/anon/batch_w18.cpp)
namespace n00258158 {
u8 func_0031acc0(void*) asm("func_0031acc0");
/*TARGET 00258158*/
u8 func_00258158(u8* p) asm("func_00258158");
u8 func_00258158(u8* p) {
    func_0031acc0(p + 872);
    func_0031acc0(p + 436);
    return func_0031acc0(p);
}
}  // namespace n00258158

// 00258190 (was src/anon/tiny_wrappers_more.cpp)
namespace n00258190 {
u32 func_00258120(u32, u32, u32, u32) asm("_Z13func_00258120jjjj");
/*TARGET 00258190*/
// 0x002422a0: definition moved into src/anon/unit_00241fd0.cpp


u32 func_00258190(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00258190jjjj");
// 0x002422a0: definition moved into src/anon/unit_00241fd0.cpp


u32 func_00258190(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00258120(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00258190

// 002581b0 (was whole asm, never written in C): CmTop init. The layout file object is built with a
// new-expression (operator new on the heap, then the Tz::LayFile constructor), which gives retail's store order.
void* operator new(unsigned int, u32) asm("func_001063c0");
namespace Tz {
class LayFile {
public:
    LayFile();
    u8 pad[28];
};
}  // namespace Tz
namespace n002581b0 {
struct AV { void* (*alloc)(void*, u32, u32); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern AH* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_0035f068 asm("D_0035f068");
extern u8 D_0035f069 asm("D_0035f069");
extern u8 D_0035f06a asm("D_0035f06a");
extern s8 D_0035f06b asm("D_0035f06b");
extern s16 D_0035f06c asm("D_0035f06c");
extern s16 D_0035f06e asm("D_0035f06e");
extern void* D_0035f074 asm("D_0035f074");
extern void* D_0035f078 asm("D_0035f078");
extern void* D_0035f07c asm("D_0035f07c");
extern void* D_0035f088 asm("D_0035f088");
void func_002ef7f0(s32) asm("func_002ef7f0");
u32 func_00103570(void) asm("func_00103570");
void* func_001063c0(s32, u32) asm("func_001063c0");
void func_0023f800(void*) asm("func_0023f800");
void func_00239700(u8*) asm("func_00239700");
void func_0026dd18(s32, s32, s32) asm("func_0026dd18");
u8* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, s32, s32, void (*)(u32), s32) asm("TASK_MANAGER__create_thread");
void func_00258468(u32) asm("func_00258468");
static inline u8* mk(void) { AO* a = D_00347f80->a; u8* p = (u8*)a->vt->alloc(a, 408, 0); *(u8**)p = D_00347e60; *(u32*)(p + 12) = 0; func_00239700(p + 24); return p; }
void func_002581b0(void) asm("func_002581b0");
void func_002581b0(void) {
    D_0035f068 = 1;
    func_002ef7f0(1);
    D_0035f074 = new (func_00103570()) Tz::LayFile;
    D_0035f078 = 0;
    D_0035f07c = mk();
    D_0035f06c = 9;
    D_0035f088 = mk();
    D_0035f06e = -1;
    func_0026dd18(0, 0, -1);
    D_0035f069 = 0;
    D_0035f06a = 0;
    D_0035f06b = 0;
    TASK_MANAGER__create_thread(*(u32*)(func_00103eb0() + 4), 0, 1998, func_00258468, 4096);
}
}
