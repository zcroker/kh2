// Linked unit 0x0024cda8-0x0024e7e8 (one namespace per old matched source; class methods in their own namespace).
#include "../tozawa/smenu_ttpt.hpp"
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/smenu_ttmy.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/smenu_lm.hpp"

// 0024cda8 (was src/tozawa/smenu_ttpt.cpp)
namespace Tz { // method 0024cda8
extern u32 D_0035edc8 asm("D_0035edc8");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void Tz__TTPT__Setup() asm("Tz__TTPT__Setup");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
extern "C" u32 func_0024d6c8() asm("func_0024d6c8");
void Tz__TTPT__Draw() asm("Tz__TTPT__Draw");
/*TARGET 0024cda8*/
void TTPT::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035edc8);
    func_00102448(s0, 1);
    Tz__TTPT__Setup();
    while (1) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (func_0024d6c8() != 0) {
            return;
        }
        Tz__TTPT__Draw();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 0024ce18 (was src/anon/batch_w3968_mam.cpp)
namespace n0024ce18 {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; bool on; u16 f12; u8 pad14[8]; s8 req[4]; u8 pad32[4]; };
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(u8*) asm("YI__LAYOUT__LAYOUT");
void Tz__MenuUtil__CreateLay(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8*) asm("Tz__Layout__SetImageCache");
s32 Tz__SubMenu__isSetNew(s32, s32) asm("Tz__SubMenu__isSetNew");
void Tz__Select__SetItem(void*, s32, s32, s32, u8*, s32, void*, u8*) asm("Tz__Select__SetItem");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0028dd90(s32) asm("func_0028dd90");
s32 func_0028ddd8(s32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void func_00139620(u8*) asm("func_00139620");
void func_00139570(u8*) asm("func_00139570");
s32 func_002892f8(void*) asm("func_002892f8");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
s32 func_002891e8(void*) asm("func_002891e8");
void func_002b4070(u8*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32) asm("func_002b4070");
s32 func_001a6d08(s32) asm("func_001a6d08");
void func_0028af40(void*, s32) asm("func_0028af40");
void func_0028d980(u8*, s32, s32, s32, u8*, s32, s32, s32, s32) asm("func_0028d980");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002887c8(void) asm("func_002887c8");
void func_00288750(void (*)(void)) asm("func_00288750");
s32 func_0024dfe0(void) asm("func_0024dfe0");
Ent36* func_0024e058(void) asm("func_0024e058");
void func_0024df90(void) asm("func_0024df90");
s16* func_0024e008(s32) asm("func_0024e008");
s32 func_0024e080(void) asm("func_0024e080");
void func_0024e158(void) asm("func_0024e158");
void Tz__TTPT__LoopAll(void) asm("Tz__TTPT__LoopAll");
void func_0024d6b8(void) asm("func_0024d6b8");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035edf0 asm("D_0035edf0");
extern s32 D_0035edf4 asm("D_0035edf4");
extern u8 D_0035edfc asm("D_0035edfc");
extern u8* D_0035edd4 asm("D_0035edd4");
extern u8* D_0035edd8 asm("D_0035edd8");
extern u8* D_0035eddc asm("D_0035eddc");
extern u8* D_0035ede0 asm("D_0035ede0");
extern u8* D_0035edec asm("D_0035edec");
extern void* D_0035edcc asm("D_0035edcc");
extern "C" u8 D_00372158[];
extern "C" u8 D_00372190[];
extern "C" u8 D_00372198[];
extern "C" u8 D_003721a0[];
extern "C" u8 D_003721a8[];
extern "C" u8 D_003721b0[];
static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);
    YI__LAYOUT__LAYOUT(o + 48);
    return o;
}
/*TARGET 0024ce18*/
void Tz__TTPT__Setup(void) asm("Tz__TTPT__Setup");
void Tz__TTPT__Setup(void) {
    s32 i, j, ok;
    s32 sel;
    s32 n, w, half;
    s32 cnt;
    u8* o;
    Ent36* e;
    Ent36* tbl;
    s32 p;
    sel = 0;
    i = 0;
    D_0035edf0 = 0;
    D_0035edd4 = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035edd4, 30002, 0, 0, 30, 32, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035edd4);
    cnt = func_0024dfe0();
    tbl = func_0024e058();
    for (; i < cnt; i++) {
        s8* r;
        e = &tbl[i];
        o = 0;
        ok = 1;
        for (j = 0, r = e->req; j < 4; j++) {
            s32 t = *r++;
            if (t < 0) break;
            if (!func_001a6d08(t)) { ok = 0; break; }
        }
        if (ok) {
            n = i; if (D_0035edf4) n = i + 3; if (Tz__SubMenu__isSetNew(0, n) == 0) D_0035edfc |= 1 << i;
            if (e->f10) sel = i;
            Tz__Select__SetItem(D_0035edcc, i, 0, 0, D_0035edd4, e->f12, e, e->name);
            o = func_002891b8(D_0035edcc, i);
            p = func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90(p);
            *(s32*)(o + 428) = func_0028ddd8(p);
            func_001395f8(o);
        }
        if (!(*(u8*)&e->on & 1)) func_00139570(o);
    }
    i = 0;
    cnt = func_002892f8(D_0035edcc);
    o = func_002891b8(D_0035edcc, 0); w = func_0023aa78(o + 24);
    half = (w * cnt) / 2; n = half;
    for (; i < cnt; i++) {
        func_00138c68(func_002891b8(D_0035edcc, i), 0, w * i - n);
    }
    Tz__Select__SetCurrent(D_0035edcc, sel, 0, -1, -1);
    func_0024df90();
    sel = func_002891e8(D_0035edcc);
    Tz__Select__SetCurrent(D_0035edcc, sel, 1, 0, 2);
    n = 0xcb96; func_002b4070(D_0035edec, 30003, D_0035edd4, D_00372158, D_00372190, D_00372198, D_003721a0, D_003721a8, D_003721b0, n, &tbl[sel], 0, 0);
    D_0035eddc = NewLayout();
    {
        s16* r = func_0024e008(sel);
        Tz__MenuUtil__CreateLay(D_0035eddc, 30002, 0, 0, r[0], r[2], 0, 0, 0);
    }
    Tz__Layout__SetImageCache(D_0035eddc);
    D_0035edd8 = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035edd8, 30019, 0, 0, 33, 35, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035edd8);
    if (func_001a6d08(7) && func_0024e080()) {
        func_0028af40(D_0035edcc, 512);
        func_0028d980(D_0035ede0, 30011, 0, 0, D_0035edd4, 31, 33, 2887, 0);
        func_00139620(D_0035ede0);
        func_001395f8(D_0035ede0);
        *(u8*)(D_0035ede0 + 405) = 1;
        { u8* a = D_0035ede0 + 24; *(u32*)(a + 184) |= 8; }
    }
    func_0024e158();
    func_00287bd0(0, 0);
    n = 0;
    func_00287cc0(n);
    if (func_002887c8()) {
        Tz__TTPT__LoopAll();
        D_0035edf0 = 1;
        func_00288750(func_0024d6b8);
    }
}
}  // namespace n0024ce18

// 0024d348 (was src/anon/batch_wcx2.cpp)
namespace n0024d348 {
struct Opt28 { u8 pad[8]; u8 text[8]; s8 def; u8 pad2; u16 id; u8 pad3[16]; };
extern Opt28 D_00372298[] asm("D_00372298");
extern u32 D_0035edd0 asm("D_0035edd0");
extern u32 D_0035edd4 asm("D_0035edd4");
extern u32 D_0035edec asm("D_0035edec");
void Tz__Select__SetItem(u32, s32, s32, s32, u32, u16, Opt28*, u8*) asm("Tz__Select__SetItem");
u8* func_002891b8(u32, s32) asm("func_002891b8");
u32 func_0023aa78(u8*) asm("func_0023aa78");
u32 func_0023aa98(u8*) asm("func_0023aa98");
void Tz__Select__SetExOffset(u32, s32, u32, s32) asm("Tz__Select__SetExOffset");
u32 func_0028dd90(u32) asm("func_0028dd90");
// mod10_classify_012
u32 func_0028ddd8(u32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002b4388(u32, Opt28*, s32) asm("func_002b4388");
/*TARGET 0024d348*/
void Tz__TTPT__SetupSel(void) asm("Tz__TTPT__SetupSel");
void Tz__TTPT__SetupSel(void)
{
    s32 sel = 0;
    for (s32 i = 0; i < 2; i++) {
        Opt28* e = (Opt28*)((u8*)(i * 36) + (u32)D_00372298);
        if (e->def) sel = i;
        Tz__Select__SetItem(D_0035edd0, i, 0, 0, D_0035edd4, e->id, e, (u8*)(i * 36) + (u32)D_00372298[0].text);
        u8* o = func_002891b8(D_0035edd0, i);
        Tz__Select__SetExOffset(D_0035edd0, i, func_0023aa78(o + 24), 0);
        u32 x = func_0023aa98(o + 24);
        *(u32*)(o + 432) = func_0028dd90(x);
        *(u32*)(o + 428) = func_0028ddd8(x);
        func_001395f8(o);
    }
    Tz__Select__SetCurrent(D_0035edd0, sel, 1, 0, 2);
    func_002b4388(D_0035edec, &D_00372298[sel], 0);
}
}  // namespace n0024d348

// 0024d4a0 (was src/anon/batch_w88.cpp)
namespace n0024d4a0 {
s32 func_00139d78(u32) asm("func_00139d78");
s32 func_0023f0c0(u32) asm("func_0023f0c0");
void func_0023f070(u32, s32, s32) asm("func_0023f070");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028ab20(u32) asm("func_0028ab20");
u32 func_002891e8(u32) asm("func_002891e8");
u8* func_0024e008(u32) asm("func_0024e008");
void func_0028da70(u32, u32) asm("func_0028da70");
extern u32 D_0035edd4 asm("D_0035edd4");
extern u32 D_0035edcc asm("D_0035edcc");
extern u32 D_0035eddc asm("D_0035eddc");
extern u32 D_0035edd8 asm("D_0035edd8");
extern u32 D_0035ede0 asm("D_0035ede0");
extern u32 D_0035ede4 asm("D_0035ede4");
#define SETANIM(o, id) if (func_00139d78(o)) { if (func_0023f0c0(o) != (id)) func_0023f070(o, id, -1); }
/*TARGET 0024d4a0*/
void Tz__TTPT__LoopAll(void) asm("Tz__TTPT__LoopAll");
void Tz__TTPT__LoopAll(void) {
    SETANIM(D_0035edd4, 32);
    if (func_0028acc8(D_0035edcc)) {
        func_0028ab20(D_0035edcc);
        u8* s = func_0024e008(func_002891e8(D_0035edcc));
        SETANIM(D_0035eddc, *(s16*)(s + 4));
    }
    SETANIM(D_0035edd8, 35);
    func_0028da70(D_0035ede0, 33);
    func_0028da70(D_0035ede4, 41);
}
}  // namespace n0024d4a0

// 0024d5a8 (was unwritten gap: TTPT fade-out, like 0x248828)
namespace n0024d5a8 {
typedef void (*VFn)(...);
struct VObj { VFn* vt; };
extern VObj* D_0035edd4 asm("D_0035edd4");
extern VObj* D_0035eddc asm("D_0035eddc");
extern VObj* D_0035edd8 asm("D_0035edd8");
extern VObj* D_0035ede0 asm("D_0035ede0");
extern VObj* D_0035ede4 asm("D_0035ede4");
extern u32 D_0035edcc asm("D_0035edcc");
extern u32 D_0035edd0 asm("D_0035edd0");
s32 func_00139d78(u32) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
void func_0024e530(void) asm("func_0024e530");
void func_0028ce38(void) asm("func_0028ce38");
void func_0024d5a8(void) asm("func_0024d5a8");
void func_0024d5a8(void) {
    if (func_00139d78((u32)D_0035edd4)) D_0035edd4->vt[5](D_0035edd4);
    if (func_00139d78((u32)D_0035eddc)) D_0035eddc->vt[5](D_0035eddc);
    if (func_00139d78((u32)D_0035edd8)) D_0035edd8->vt[5](D_0035edd8);
    if (func_0028acc8(D_0035edcc)) func_0028abe0(D_0035edcc);
    if (func_0028acc8(D_0035edd0)) func_0028abe0(D_0035edd0);
    if (func_00139d78((u32)D_0035ede0)) D_0035ede0->vt[5](D_0035ede0);
    if (func_00139d78((u32)D_0035ede4)) D_0035ede4->vt[5](D_0035ede4);
    func_0024e530();
    func_0028ce38();
}
}  // namespace n0024d5a8
// 0024d6b8 (was unwritten gap: pause callback)
namespace n0024d6b8 {
extern u8 D_0035edf0 asm("D_0035edf0");
void func_0024d6b8(void) asm("func_0024d6b8");
void func_0024d6b8(void) { D_0035edf0 = 0; }
}  // namespace n0024d6b8

// 0024d6c8 (was src/anon/batch_w77.cpp)
namespace n0024d6c8 {
extern u32 D_0035edcc asm("D_0035edcc");
extern u32 D_0035edd0 asm("D_0035edd0");
extern u32 D_0035edd4 asm("D_0035edd4");
extern u32 D_0035edd8 asm("D_0035edd8");
extern u32 D_0035eddc asm("D_0035eddc");
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
// copy_globals_3words
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00139d78(u32) asm("func_00139d78");
void func_001039f8(void) asm("func_001039f8");
void func_0024d910(void) asm("func_0024d910");
void func_0024d7a0(void) asm("func_0024d7a0");
/*TARGET 0024d6c8*/
s32 func_0024d6c8(void) asm("func_0024d6c8");
s32 func_0024d6c8(void)
{
    s32 st = func_00287bc0();
    Tz__MenuBase__SaveMode();  // copy_globals_3words
    if (func_00287db0()) {
        if (func_0028acc8(D_0035edcc) || func_0028acc8(D_0035edd0) || func_00139d78(D_0035edd4) || func_00139d78(D_0035edd8) || func_00139d78(D_0035eddc)) return 0;
        func_001039f8();
        return 1;
    }
    switch (st) {
    case 0: func_0024d7a0(); break;
    case 1: func_0024d910(); break;
    }
    return 0;
}
}  // namespace n0024d6c8

// 0024d7a0 (was src/anon/batch_wcx2.cpp)
namespace n0024d7a0 {
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
// 0028fe38: moved to src/anon/unit_0028f1e0.cpp
// ---- 0024e5b0
extern u32 D_0035edcc asm("D_0035edcc");
// 0x0024be68: definition moved into src/anon/unit_0024ba58.cpp

// --------------------
extern u8 D_0035edf0 asm("D_0035edf0");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x8809(s32) asm("func_00289380");
s32 func_00289310_x8810(s32) asm("func_00289310");
s32 func_0028ae28_x8811(s32, s32) asm("func_0028ae28");
void Tz__TTPT__LoopAll() asm("Tz__TTPT__LoopAll");
void func_00287c90(s32) asm("func_00287c90");
void Tz__TTPT__CreateNewMark() asm("Tz__TTPT__CreateNewMark");
void func_00287df0_x8815(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0024df58() asm("func_0024df58");
void func_002535b0(s32) asm("func_002535b0");
void func_00288658(s32, s32) asm("func_00288658");
void func_0024d5a8() asm("func_0024d5a8");
void func_00288670(void (*)()) asm("func_00288670");
void func_00287da0() asm("func_00287da0");
void Tz__TTPT__SetupSel() asm("Tz__TTPT__SetupSel");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0024d7a0*/
void func_0024d7a0() asm("func_0024d7a0");
void func_0024d7a0() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8809(D_0035edcc);
    if (D_0035edf0) return;
    if (r != -1 || func_00289310_x8810(D_0035edcc)) {
        if (!func_0028ae28_x8811(D_0035edcc, 0)) Tz__TTPT__LoopAll();
    }
    if (!a && func_0028ae28_x8811(D_0035edcc, 0)) {
        func_00287c90(1);
        Tz__TTPT__CreateNewMark();
    }
    func_00287df0_x8815(r, func_00289310_x8810(D_0035edcc), 1, 0, 1);
    switch (r) {
    case -6:
        func_0024df58();
        func_002535b0(3);
        func_00288658(2, 106);
        func_00288670(func_0024d5a8);
    case -4: case -2:
        func_00287da0();
        break;
    case -5: case -3: case -1:
        break;
    case 0: case 1: case 2:
        Tz__TTPT__SetupSel();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}
}  // namespace n0024d7a0

// .rodata words 0x372118 read by other code (retail bytes, in place)
namespace r00372118 {
extern const u32 R_00372118[2] asm("D_00372118") __attribute__((aligned(4))) = { 0x3d003c, 0x3e };
extern const u32 R_00372120[2] asm("D_00372120") __attribute__((aligned(4))) = { 0x40003f, 0x41 };
}  // namespace r00372118

// 0024d910 (was src/anon/batch_wcx2.cpp)
namespace n0024d910 {
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
extern s32 D_0035edd0_24d asm("D_0035edd0");
extern s32 D_0035edcc_24d asm("D_0035edcc");
extern s32 D_0035edec_24d asm("D_0035edec");
extern s32 D_0035edf4_24d asm("D_0035edf4");
extern s16 D_00372118[] asm("D_00372118");
extern s16 D_00372120[] asm("D_00372120");
u8* func_0024e058() asm("func_0024e058");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x10264(s32) asm("func_00289380");
s32 func_0028acc8_x10265(s32) asm("func_0028acc8");
s32 func_00289310_x10266(s32) asm("func_00289310");
void func_0028abe0_x10267(s32) asm("func_0028abe0");
s32 func_002891e8_x10268(s32) asm("func_002891e8");
void func_002b4388_x10270(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28_x10273(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10274(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0_x10276(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287b08(s32) asm("func_00287b08");
void func_00287da0() asm("func_00287da0");
/*TARGET 0024d910*/
void func_0024d910() asm("func_0024d910");
void func_0024d910() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10264(D_0035edd0_24d);
    if (a == 2) {
        if (func_0028acc8_x10265(D_0035edd0_24d)) {
            if (r != -1 || func_00289310_x10266(D_0035edd0_24d)) func_0028abe0_x10267(D_0035edd0_24d);
            return;
        }
        u8* base = func_0024e058();
        func_002b4388_x10270(D_0035edec_24d, base + func_002891e8_x10268(D_0035edcc_24d) * 36, 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10266(D_0035edd0_24d)) {
        if (!func_0028ae28_x10273(D_0035edd0_24d, 0)) func_0028ab20_x10274(D_0035edd0_24d);
    }
    if (!a && func_0028ae28_x10273(D_0035edd0_24d, 0)) func_00287c90(1);
    func_00287df0_x10276(r, func_00289310_x10266(D_0035edd0_24d), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035edd0_24d);
        func_00287c90(1);
        break;
    case 0: {
        s32 n = func_002891e8_x10268(D_0035edcc_24d);
        func_00287b08((D_0035edf4_24d == 0 ? D_00372118 : D_00372120)[n]);
        func_00287da0();
        break;
    }
    case -4: case -3: case -1:
        break;
    }
}
}  // namespace n0024d910

// 0024db28 (was src/anon/batch_w1579_g.cpp)
namespace n0024db28 {
// 0x0024c1a8: definition moved into src/anon/unit_0024ba58.cpp
struct Tdb28 { s16 a; s16 b; s16 c; };
extern s32 D_0035edcc asm("D_0035edcc");
extern s32 D_0035edd0 asm("D_0035edd0");
extern s32 D_0035edd4 asm("D_0035edd4");
extern s32 D_0035edd8 asm("D_0035edd8");
extern s32 D_0035eddc asm("D_0035eddc");
extern s32 D_0035ede0 asm("D_0035ede0");
extern s32 D_0035ede4 asm("D_0035ede4");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_002887c8(void) asm("func_002887c8");
void func_0028dae0(s32, s32) asm("func_0028dae0");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_0028acb8(s32) asm("func_0028acb8");
void func_0028aa40(s32) asm("func_0028aa40");
s32 func_00139d78(s32) asm("func_00139d78");
s32 func_002891e8(s32) asm("func_002891e8");
Tdb28* func_0024e008(s32) asm("func_0024e008");
void func_0028dac8(s32, s32) asm("func_0028dac8");
void func_0028ce38(void) asm("func_0028ce38");
void func_0024e530(void) asm("func_0024e530");
void func_0024dea8(void) asm("func_0024dea8");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, s32, s32, s32) asm("Tz__MenuCursor__Create");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_00287c50(void) asm("func_00287c50");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void Tz__TTPT__DrawSelector(s32, s32, s32) asm("Tz__TTPT__DrawSelector");
struct NoTaildb28 { ~NoTaildb28() {} };
/*TARGET 0024db28*/
void Tz__TTPT__Draw(void) asm("Tz__TTPT__Draw");
void Tz__TTPT__Draw(void) {
    NoTaildb28 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035edd4, 31);
            if (func_0028acc8(D_0035edcc) != 0 && func_00139d78(D_0035eddc) != 0) {
                func_0028dae0(D_0035eddc, func_0024e008(func_002891e8(D_0035edcc))->b);
            }
            func_0028dae0(D_0035edd8, 34);
            if (func_0028acc8(D_0035edcc) != 0 && func_0028acb8(D_0035edcc) == 0) {
                func_0028aa40(D_0035edcc);
            }
            if (func_0028acc8(D_0035edd0) != 0 && func_0028acb8(D_0035edd0) == 0) {
                func_0028aa40(D_0035edd0);
            }
            func_0028dac8(D_0035ede0, 32);
            func_0028dac8(D_0035ede4, 40);
        }
        func_0024e530();
        func_0028ce38();
    }
    func_0024dea8();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035edcc : D_0035edd0;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                Tz__MenuCursor__Create(side, 0, 0, D_0035edd4, 15, 14);
                Tz__MenuCursor__SetParent(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            Tz__MenuCursor__SetType(0, side);
        }
        Tz__TTPT__DrawSelector(obj, mode, side);
    }
}
}  // namespace n0024db28

// 0024dd68 (was src/anon/batch_w1262.cpp)
namespace n0024dd68 {
extern s32 D_0035eddc asm("D_0035eddc");
extern s32 D_0035edec asm("D_0035edec");
extern u8 D_00372298[] asm("D_00372298");
s32 func_00287cd0_a(s32) asm("func_00287cd0");
s32 func_00289310_a(s32) asm("func_00289310");
s32 func_002891e8_a(s32) asm("func_002891e8");
void func_002890e0(s32, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(s32, s32, s32, s32, s32, s32, s32) asm("func_00289038");
s16* func_0024e008(s32) asm("func_0024e008");
void func_0023f070(s32, s32, s32) asm("func_0023f070");
void func_0024e5b0(void) asm("func_0024e5b0");
s32 func_0028d008(s32) asm("func_0028d008");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
u8* func_0024e058(void) asm("func_0024e058");
void func_002b4388(s32, void *, s32) asm("func_002b4388");
void Tz__TTPT__UpdateScore(void) asm("Tz__TTPT__UpdateScore");
/*TARGET 0024dd68*/
void Tz__TTPT__DrawSelector(s32 a0, s32 a1, s32 a2) asm("Tz__TTPT__DrawSelector");
void Tz__TTPT__DrawSelector(s32 a0, s32 a1, s32 a2)
{
  s32 idx;
  u8 *p;
  if ((func_00287cd0_a(a0) == 1) && (func_00289310_a(a0) != 0))
  {
    idx = func_002891e8_a(a0);
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, idx, 1, 1, 2, 0, -1);
    if (a1 == 0)
    {
      func_0023f070(D_0035eddc, func_0024e008(idx)[2], -1);
      func_0024e5b0();
    }
    if (func_0028d008(a2) != 0)
    {
      Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
    }
    p = D_00372298;
    if (a1 == 0)
    {
      if (a0 || p)
      {
        p = func_0024e058();
      }
      else
      {
        p = func_0024e058();
      }
    }
    func_002b4388(D_0035edec, p + (idx * 36), 0);
    Tz__TTPT__UpdateScore();
  }
}
}  // namespace n0024dd68

// 0024dea8 (was src/anon/batch_wcx.cpp)
namespace n0024dea8 {
// 0x002493c8: definition moved into src/anon/unit_00247ff0.cpp

extern u8* D_0035edcc asm("D_0035edcc");
extern u8* D_0035edd0 asm("D_0035edd0");
s32 func_002892f8(u8*) asm("func_002892f8");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_00288e88(u8*) asm("func_00288e88");
/*TARGET 0024dea8*/
void func_0024dea8(void) asm("func_0024dea8");
void func_0024dea8(void)
{
    if (D_0035edcc) {
        s32 a = func_002892f8(D_0035edcc);
        if (!func_0028acc8(D_0035edcc) && a) func_00288e88(D_0035edcc);
    }
    if (D_0035edd0) {
        s32 a = func_002892f8(D_0035edd0);
        if (!func_0028acc8(D_0035edd0) && a) func_00288e88(D_0035edd0);
    }
}
}  // namespace n0024dea8

// 0024df58 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024df58 {
extern u32 D_0035edcc asm("D_0035edcc");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 0024df58*/
// 0x0024c650: definition moved into src/anon/unit_0024ba58.cpp

void func_0024df58() asm("_Z13func_0024df58v");
// 0x0024c650: definition moved into src/anon/unit_0024ba58.cpp

void func_0024df58() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035edcc);
    func_0023fc40(&v0, 4);
}
}  // namespace n0024df58

// 0024df90 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024df90 {
extern u32 D_0035edcc asm("D_0035edcc");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void Tz__Select__SetCurrent(...) asm("Tz__Select__SetCurrent");
/*TARGET 0024df90*/
void func_0024df90() asm("_Z13func_0024df90v");
void func_0024df90() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        Tz__Select__SetCurrent(D_0035edcc, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n0024df90

// 0024dfe0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024dfe0 {
extern u32 D_0035edf4 asm("D_0035edf4");
extern u32 D_003722ec asm("D_003722ec");
extern u32 D_003722f0 asm("D_003722f0");
/*TARGET 0024dfe0*/
u32 func_0024dfe0() asm("_Z13func_0024dfe0v");
u32 func_0024dfe0() {
    if (D_0035edf4 != 0) {
        return D_003722f0;
    }
    return D_003722ec;
}
}  // namespace n0024dfe0

// 0024e008 (was src/anon/batch_w27.cpp)
namespace n0024e008 {
// 0x00225aa8: definition moved into src/anon/unit_00224780.cpp



struct S6 { u8 b[6]; };
extern S6 D_00372160[] asm("D_00372160");
extern S6 D_00372178[] asm("D_00372178");
extern u32 D_0035edf4 asm("D_0035edf4");
void func_0024dfe0(void) asm("func_0024dfe0");
/*TARGET 0024e008*/
S6* func_0024e008(s32 i) asm("func_0024e008");
S6* func_0024e008(s32 i) {
    func_0024dfe0();
    if (D_0035edf4 == 0) return &D_00372160[i];
    return &D_00372178[i];
}
}  // namespace n0024e008

// 0024e058 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024e058 {
extern u32 D_0035edf4 asm("D_0035edf4");
extern u8  D_003721b8 asm("D_003721b8");
extern u8  D_00372228 asm("D_00372228");
/*TARGET 0024e058*/
u32 func_0024e058() asm("_Z13func_0024e058v");
u32 func_0024e058() {
    if (D_0035edf4 == 0) {
        return (u32)&D_003721b8;
    }
    return (u32)&D_00372228;
}
}  // namespace n0024e058

// 0024e080 (was src/anon/batch_w78.cpp)
namespace n0024e080 {
s32 func_00276c18(void) asm("func_00276c18");
u8* func_001d56c8(u8) asm("func_001d56c8");
extern u32 D_0035edf4 asm("D_0035edf4");
extern s32 D_003722ec asm("D_003722ec");
extern s32 D_003722f0 asm("D_003722f0");
extern u8 D_003722e0[] asm("D_003722e0");
extern u8 D_003722e8[] asm("D_003722e8");
/*TARGET 0024e080*/
s32 func_0024e080(void) asm("func_0024e080");
s32 func_0024e080(void) {
    if (func_00276c18()) return 1;
    s32 any = 0;
    s32 n;
    if (!D_0035edf4) n = D_003722ec;
    else n = D_003722f0;
    for (s32 i = 0; i < n; i++) {
        u8* e;
        if (!D_0035edf4) e = func_001d56c8(D_003722e0[i]);
        else e = func_001d56c8(D_003722e8[i]);
        if (*e >= 2) { any = 1; break; }
    }
    return any;
}
}  // namespace n0024e080

// 0024e158 (was src/anon/batch_w88.cpp)
namespace n0024e158 {
s32 func_001a6d08(u32) asm("func_001a6d08");
void func_0028d980(u32, u32, u32, u32, u32, u32, u32, s32, u32) asm("func_0028d980");
void func_00139620(u32) asm("func_00139620");
void func_001395f8(u32) asm("func_001395f8");
void func_002fde18(u32, u32, u32) asm("func_002fde18");
void Tz__TTPT__UpdateScore(void) asm("Tz__TTPT__UpdateScore");
extern u32 D_0035edd4 asm("D_0035edd4");
extern u32 D_0035ede4 asm("D_0035ede4");
extern u32 D_0035edf8 asm("D_0035edf8");
static inline void Or8(u8* o) { *(u32*)(o + 184) |= 8; }
/*TARGET 0024e158*/
void func_0024e158(void) asm("func_0024e158");
void func_0024e158(void) {
    if (!func_001a6d08(7)) return;
    func_0028d980(D_0035ede4, 30011, 0, 0, D_0035edd4, 39, 41, -1, 0);
    func_00139620(D_0035ede4);
    func_001395f8(D_0035ede4);
    *(u32*)(D_0035ede4 + 432) = 2;
    *(u8*)(D_0035ede4 + 405) = 1;
    Or8((u8*)(D_0035ede4 + 24));
    func_002fde18(D_0035edf8, 0, 32);
    *(u32*)(D_0035ede4 + 408) = D_0035edf8;
    Tz__TTPT__UpdateScore();
}
}  // namespace n0024e158

// 0024e228 (was src/anon/batch_wcx2.cpp)
namespace n0024e228 {
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
// 0x0024aef0: definition moved into src/anon/unit_00249ef0.cpp

struct It70 { u8 type; u8 pad[3]; u32 v; };
extern u8* D_0035ede4 asm("D_0035ede4");
extern char* D_0035edf8 asm("D_0035edf8");
extern u32 D_0035edcc asm("D_0035edcc");
extern s32 D_0035edf4 asm("D_0035edf4");
extern u8 D_003722e0[] asm("D_003722e0");
extern u8 D_003722e8[] asm("D_003722e8");
extern char D_00372140[] asm("D_00372140");
extern char D_00372150[] asm("D_00372150");
s32 func_00139d78(void*) asm("func_00139d78");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_002891e8(u32) asm("func_002891e8");
It70* func_001d56c8(u8) asm("func_001d56c8");
u32 func_00192048__94859(s32) asm("func_00192048");
s32 func_00192c40(u32, char*) asm("func_00192c40");
void dk__Clock__vCountToHMSMS(u32, s32*, s32*, s32*, s32*) asm("dk__Clock__vCountToHMSMS");
char* func_00192cc0(char*, const char*, ...) asm("func_00192cc0");
s32 func_00192b30(char*) asm("func_00192b30");
void func_00192c90(u32, char*) asm("func_00192c90");
/*TARGET 0024e228*/
void Tz__TTPT__UpdateScore(void) asm("Tz__TTPT__UpdateScore");
void Tz__TTPT__UpdateScore(void)
{
    if (!func_00139d78(D_0035ede4)) return;
    func_002fde18(D_0035edf8, 0, 32);
    char* buf = D_0035edf8;
    s32 n;
    s32 i = func_002891e8(D_0035edcc);
    It70* it = func_001d56c8((!D_0035edf4 ? D_003722e0 : D_003722e8)[i]);
    if (it->type == 4) {
        n = func_00192c40(func_00192048__94859(0xcb99), buf);
        s32 a, b, c, d;
        dk__Clock__vCountToHMSMS(it->v, &a, &b, &c, &d);
        func_00192cc0(buf + n, D_00372140, b, c, d);
    } else if (it->type == 3) {
        n = func_00192b30(func_00192cc0(buf, D_00372150, it->v));
        u32 msg = func_00192048__94859(0xcb98);
        func_00192c90(msg, buf + n);
    } else if (it->type == 6) {
        n = func_00192b30(func_00192cc0(buf, D_00372150, it->v));
        u32 msg = func_00192048__94859(0xcc90);
        func_00192c90(msg, buf + n);
    } else {
        func_00192c90(func_00192048__94859(0xcb9b), buf);
    }
}
}  // namespace n0024e228

// 0024e3a8 (was src/anon/batch_wcx2.cpp)
namespace n0024e3a8 {
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
// 0x002491d0: definition moved into src/anon/unit_00247ff0.cpp

extern s8 D_0035edfc asm("D_0035edfc");
extern u8* D_0035ede8 asm("D_0035ede8");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035edcc asm("D_0035edcc");
extern u32 D_0035edd4 asm("D_0035edd4");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028afa8(u32) asm("func_0028afa8");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028d8c0__59439(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__59439(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_0024e5b0(void) asm("func_0024e5b0");
/*TARGET 0024e3a8*/
void Tz__TTPT__CreateNewMark(void) asm("Tz__TTPT__CreateNewMark");
void Tz__TTPT__CreateNewMark(void)
{
    if (!D_0035edfc) return;
    if (func_00139d78(D_0035ede8)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035edcc);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035edcc, i);
        u8* a = o + 24;
        if ((u8)((D_0035edfc >> i) & 1)) {
            func_0028d8c0__59439(D_0035ede8 + i * 408, id, 0, 0, D_0035edd4, 38, -1, 0);
            func_0028dcc0__59439(D_0035ede8 + i * 408, o);
            func_00139648(D_0035ede8 + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ede8 + i * 408, x, func_0023aa38(a));
        }
    }
    func_0024e5b0();
}
}  // namespace n0024e3a8

// 0024e530 (was src/anon/batch_w54.cpp)
namespace n0024e530 {
// 0x00232510: definition moved into src/anon/unit_00231500.cpp

s32 func_0024dfe0(void) asm("func_0024dfe0");
s32 func_00139d78(void*) asm("func_00139d78");
struct Obj408 {
    void** vtbl;
    u8 pad[404];
};
extern Obj408* D_0035ede8 asm("D_0035ede8");
/*TARGET 0024e530*/
void func_0024e530(void) asm("func_0024e530");
void func_0024e530(void) {
    s32 i;
    for (i = 0; i < func_0024dfe0(); i++) {
        if (func_00139d78(&D_0035ede8[i])) {
            Obj408* o = (Obj408*)((u8*)(i * 408) + (u32)D_0035ede8);
            ((void (*)(Obj408*))o->vtbl[5])(o);
        }
    }
}
}  // namespace n0024e530

// 0024e5b0 (was src/anon/batch_wcx2.cpp)
namespace n0024e5b0 {
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
void func_0024e5b0(void) asm("func_0024e5b0");
// 0028fe38: moved to src/anon/unit_0028f1e0.cpp
// ---- 0024e5b0
extern u32 D_0035edcc asm("D_0035edcc");
extern s8 D_0035edfc asm("D_0035edfc");
extern u8* D_0035ede8 asm("D_0035ede8");
extern s32 D_0035edf4 asm("D_0035edf4");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_00139d78_e5b0(u8*) asm("func_00139d78");
void func_00138c10_e5b0(u8*, u32) asm("func_00138c10");
void func_00243230(u32, s32) asm("func_00243230");
/*TARGET 0024e5b0*/
void func_0024e5b0() asm("func_0024e5b0");
void func_0024e5b0() {
    s32 i = func_002891e8(D_0035edcc);
    if (!((D_0035edfc >> i) & 1)) return;
    if (func_00139d78_e5b0(D_0035ede8 + i * 408)) {
        u8* a = D_0035ede8 + i * 408;
        if (*(s32*)(a + 388) != 37) func_00138c10_e5b0(a, 37);
    }
    func_00243230(0, D_0035edf4 ? i + 3 : i);
}
}  // namespace n0024e5b0

// 0024e678 (was src/anon/batch_w80.cpp)
namespace n0024e678 {
// ---- unit 13 (good24e.cpp)
extern void* D_0035ee04 asm("D_0035ee04");
extern s32 D_0035ee08 asm("D_0035ee08");
extern s32 D_0035ee0c asm("D_0035ee0c");
extern s32 D_0035ee2c asm("D_0035ee2c");
extern s32 D_0035ee10 asm("D_0035ee10");
extern s32 D_0035ee18[5] asm("D_0035ee18");
struct U13_SysInfo { u32 f0; u32 f4; };
void func_00287b18(u32, u32) asm("func_00287b18");
void* func_00288be8(u32) asm("func_00288be8");
void func_002889f0(void*, u32, u32) asm("func_002889f0");
void func_00288f48(void*, u32, u32, u32, u32) asm("func_00288f48");
void func_00287bd0(u32, u32) asm("func_00287bd0");
U13_SysInfo* func_00103eb0(void) asm("func_00103eb0");
void func_0024e7e8(void) asm("func_0024e7e8");
void TASK_MANAGER__create_thread(u32, u32, u32, void (*)(void), u32) asm("TASK_MANAGER__create_thread");
/*TARGET 0024e678*/
// 0x002a67a8: definition moved into src/anon/unit_002a5a90.cpp


void func_0024e678(void) asm("func_0024e678");
// 0x002a67a8: definition moved into src/anon/unit_002a5a90.cpp


void func_0024e678(void) {
    void* o;
    s32 i;
    func_00287b18(5, 3);
    o = func_00288be8(56);
    func_002889f0(o, 5, 1);
    D_0035ee04 = o;
    func_00288f48(o, 64, 128, 0, 0);
    D_0035ee08 = 0;
    D_0035ee0c = 0;
    D_0035ee10 = 0;
    D_0035ee2c = -1;
    for (i = 0; i < 5; i++) D_0035ee18[i] = 0;
    func_00287bd0(0, 0);
    TASK_MANAGER__create_thread(func_00103eb0()->f4, 0, 2000, func_0024e7e8, 4096);
}
}  // namespace n0024e678

// 0024e758 (was unwritten gap: TTMY globals cleanup)
namespace n0024e758 {
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
extern void* D_0035ee04 asm("D_0035ee04");
extern DO* D_0035ee08 asm("D_0035ee08");
extern DO* D_0035ee0c asm("D_0035ee0c");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_0024e758(void) asm("func_0024e758");
void func_0024e758(void) {
    void* p;
    DO* o;
    if ((p = D_0035ee04) != 0) { func_00288b00(p); func_00288c20(p); D_0035ee04 = 0; }
    if ((o = D_0035ee08) != 0) { o->vt->del(o); D_0035ee08 = 0; }
    if ((o = D_0035ee0c) != 0) { o->vt->del(o); D_0035ee0c = 0; }
}
}  // namespace n0024e758

