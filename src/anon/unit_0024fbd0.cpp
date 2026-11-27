// Linked unit 0x0024fbd0-0x00250fb8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/smenu_cana.hpp"
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
#include "../tozawa/campmenu.hpp"
#include "../tozawa/cmenu_data.hpp"
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"

// 0024fbd0 (was src/anon/batch_wcx2.cpp)
namespace n0024fbd0 {
struct Opt28 { u8 pad[8]; u8 text[8]; s8 def; u8 pad2; u16 id; u8 pad3[16]; };
extern Opt28 D_00372548[] asm("D_00372548");
extern u32 D_0035ee38 asm("D_0035ee38");
extern u32 D_0035ee3c asm("D_0035ee3c");
extern u32 D_0035ee4c asm("D_0035ee4c");
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
/*TARGET 0024fbd0*/
void Tz__LMMU__SetupSel(void) asm("Tz__LMMU__SetupSel");
void Tz__LMMU__SetupSel(void)
{
    s32 sel = 0;
    for (s32 i = 0; i < 2; i++) {
        Opt28* e = (Opt28*)((u8*)(i * 36) + (u32)D_00372548);
        if (e->def) sel = i;
        Tz__Select__SetItem(D_0035ee38, i, 0, 0, D_0035ee3c, e->id, e, (u8*)(i * 36) + (u32)D_00372548[0].text);
        u8* o = func_002891b8(D_0035ee38, i);
        Tz__Select__SetExOffset(D_0035ee38, i, func_0023aa78(o + 24), 0);
        u32 x = func_0023aa98(o + 24);
        *(u32*)(o + 432) = func_0028dd90(x);
        *(u32*)(o + 428) = func_0028ddd8(x);
        func_001395f8(o);
    }
    Tz__Select__SetCurrent(D_0035ee38, sel, 1, 0, 2);
    func_002b4388(D_0035ee4c, &D_00372548[sel], 0);
}
}  // namespace n0024fbd0

// 0024fd28 (was src/anon/batch_w89.cpp)
namespace n0024fd28 {
struct Tbl6 { s16 a, b, c; };
extern void* D_0035ee3c asm("D_0035ee3c");
extern void* D_0035ee34 asm("D_0035ee34");
extern void* D_0035ee44 asm("D_0035ee44");
extern void* D_0035ee40 asm("D_0035ee40");
extern Tbl6 D_00372448[] asm("D_00372448");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
void func_0028ab20(void*) asm("func_0028ab20");
/*TARGET 0024fd28*/
void Tz__LMMU__LoopAll(void) asm("Tz__LMMU__LoopAll");
void Tz__LMMU__LoopAll(void) {
    if (func_00139d78(D_0035ee3c)) {
        if (func_0023f0c0(D_0035ee3c) != 32) func_0023f070(D_0035ee3c, 32, -1);
    }
    if (func_0028acc8(D_0035ee34)) {
        func_0028ab20(D_0035ee34);
        s32 i = func_002891e8((u32)D_0035ee34);
        if (func_00139d78(D_0035ee44)) {
            if (func_0023f0c0(D_0035ee44) != D_00372448[i].c) func_0023f070(D_0035ee44, D_00372448[i].c, -1);
        }
    }
    if (func_00139d78(D_0035ee40)) {
        if (func_0023f0c0(D_0035ee40) != 35) func_0023f070(D_0035ee40, 35, -1);
    }
}
}  // namespace n0024fd28

// 0024fe30 (was src/anon/batch_w83.cpp)
namespace n0024fe30 {
// 0x0022e4f0: definition moved into src/anon/unit_0022d358.cpp

struct VObj20 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); virtual void f16(); virtual void f20(); };
extern VObj20* D_0035ee3c asm("D_0035ee3c");
extern VObj20* D_0035ee44 asm("D_0035ee44");
extern VObj20* D_0035ee40 asm("D_0035ee40");
extern void* D_0035ee34 asm("D_0035ee34");
extern void* D_0035ee38 asm("D_0035ee38");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028abe0(void*) asm("func_0028abe0");
void func_00250928(void) asm("func_00250928");
void func_0028ce38(void) asm("func_0028ce38");
/*TARGET 0024fe30*/
void func_0024fe30(void) asm("func_0024fe30");
void func_0024fe30(void) {
    if (func_00139d78(D_0035ee3c)) D_0035ee3c->f20();
    if (func_00139d78(D_0035ee44)) D_0035ee44->f20();
    if (func_00139d78(D_0035ee40)) D_0035ee40->f20();
    if (func_0028acc8(D_0035ee34)) func_0028abe0(D_0035ee34);
    if (func_0028acc8(D_0035ee38)) func_0028abe0(D_0035ee38);
    func_00250928();
    func_0028ce38();
}
}  // namespace n0024fe30

// 0024fef8 (was unwritten gap: pause callback)
namespace n0024fef8 {
extern u8 D_0035ee50 asm("D_0035ee50");
void func_0024fef8(void) asm("func_0024fef8");
void func_0024fef8(void) { D_0035ee50 = 0; }
}  // namespace n0024fef8

// 0024ff08 (was src/anon/batch_w1595.cpp)
namespace n0024ff08 {
// 0x00283b78: definition moved into src/anon/unit_00282c68.cpp

void func_001039f8() asm("func_001039f8");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0024ffe0() asm("func_0024ffe0");
void func_00250130() asm("func_00250130");
s32 func_00287bc0() asm("func_00287bc0");
void Tz__MenuBase__SaveMode() asm("Tz__MenuBase__SaveMode");
s32 func_00287db0() asm("func_00287db0");
extern void* D_0035ee34 asm("D_0035ee34");
extern void* D_0035ee38 asm("D_0035ee38");
extern void* D_0035ee3c asm("D_0035ee3c");
extern void* D_0035ee40 asm("D_0035ee40");
extern void* D_0035ee44 asm("D_0035ee44");
/*TARGET 0024ff08*/
// The || chain with a single "return 0" keeps the result in v0 (separate returns put it in t7).
s32 Tz__LMMU__Control(void) asm("Tz__LMMU__Control");
// The || chain with a single "return 0" keeps the result in v0 (separate returns put it in t7).
s32 Tz__LMMU__Control(void) {
    s32 s = func_00287bc0();
    Tz__MenuBase__SaveMode();
    if (func_00287db0()) {
        if (func_0028acc8(D_0035ee34) || func_0028acc8(D_0035ee38) || func_00139d78(D_0035ee3c)
            || func_00139d78(D_0035ee40) || func_00139d78(D_0035ee44)) return 0;
        func_001039f8();
        return 1;
    }
    switch (s) {
    case 0: func_0024ffe0(); return 0;
    case 1: func_00250130(); return 0;
    }
    return 0;
}
}  // namespace n0024ff08

// 0024ffe0 (was src/anon/batch_wcx2.cpp)
namespace n0024ffe0 {
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
extern u32 D_0035ee34 asm("D_0035ee34");
// --------------------
extern u8 D_0035ee50 asm("D_0035ee50");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x8859(s32) asm("func_00289380");
s32 func_00289310_x8860(s32) asm("func_00289310");
s32 func_0028ae28_x8861(s32, s32) asm("func_0028ae28");
void func_002426a0(s32) asm("func_002426a0");
void Tz__LMMU__LoopAll() asm("Tz__LMMU__LoopAll");
void Tz__LMMU__SetupSel() asm("Tz__LMMU__SetupSel");
void func_00287c90(s32) asm("func_00287c90");
void func_002507a0() asm("func_002507a0");
void func_00287df0_x8867(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00287da0() asm("func_00287da0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0024ffe0*/
void func_0024ffe0() asm("func_0024ffe0");
void func_0024ffe0() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8859(D_0035ee34);
    if (D_0035ee50) return;
    if (r != -1 || func_00289310_x8860(D_0035ee34)) {
        if (!func_0028ae28_x8861(D_0035ee34, 0)) {
            func_002426a0(0);
            Tz__LMMU__LoopAll();
        }
    }
    if (!a && func_0028ae28_x8861(D_0035ee34, 0)) {
        func_00287c90(1);
        func_002507a0();
    }
    func_00287df0_x8867(r, func_00289310_x8860(D_0035ee34), 1, 0, 1);
    switch (r) {
    case -3: case -1:
        break;
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1: case 2: case 3: case 4:
        Tz__LMMU__SetupSel();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}
}  // namespace n0024ffe0

// .rodata words 0x372410 read by other code (retail bytes, in place)
namespace r00372410 {
extern const u32 R_00372410[3] asm("D_00372410") __attribute__((aligned(4))) = { 0x3d003c, 0x3f003e, 0x40 };
}  // namespace r00372410

// 00250130 (was src/anon/batch_wcx2.cpp)
namespace n00250130 {
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
struct E250130 { u8 b[36]; };
extern s32 D_0035ee38_250 asm("D_0035ee38");
extern s32 D_0035ee34_250 asm("D_0035ee34");
extern s32 D_0035ee4c_250 asm("D_0035ee4c");
extern E250130 D_00372490[] asm("D_00372490");
extern s16 D_00372410[] asm("D_00372410");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x10323(s32) asm("func_00289380");
s32 func_0028acc8_x10324(s32) asm("func_0028acc8");
s32 func_00289310_x10325(s32) asm("func_00289310");
void func_0028abe0_x10326(s32) asm("func_0028abe0");
s32 func_002891e8_x10327(s32) asm("func_002891e8");
void func_002b4388_x10329(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28_x10332(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10333(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0_x10335(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287b08(s32) asm("func_00287b08");
void func_00287da0() asm("func_00287da0");
void func_00250748() asm("func_00250748");
/*TARGET 00250130*/
void func_00250130() asm("func_00250130");
void func_00250130() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10323(D_0035ee38_250);
    if (a == 2) {
        if (func_0028acc8_x10324(D_0035ee38_250)) {
            if (r != -1 || func_00289310_x10325(D_0035ee38_250)) func_0028abe0_x10326(D_0035ee38_250);
            return;
        }
        func_002b4388_x10329(D_0035ee4c_250, &D_00372490[func_002891e8_x10327(D_0035ee34_250)], 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10325(D_0035ee38_250)) {
        if (!func_0028ae28_x10332(D_0035ee38_250, 0)) func_0028ab20_x10333(D_0035ee38_250);
    }
    if (!a && func_0028ae28_x10332(D_0035ee38_250, 0)) func_00287c90(1);
    func_00287df0_x10335(r, func_00289310_x10325(D_0035ee38_250), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035ee38_250);
        func_00287c90(1);
        break;
    case 0:
        func_00250748();
        func_00287b08(D_00372410[func_002891e8_x10327(D_0035ee34_250)]);
        func_00287da0();
        break;
    case -4: case -3: case -1:
        break;
    }
}
}  // namespace n00250130

// 00250328 (was src/anon/batch_w1579_g.cpp)
namespace n00250328 {
struct T0328 { s16 a; s16 b; s16 c; };
extern T0328 D_00372448[] asm("D_00372448");
extern s32 D_0035ee34 asm("D_0035ee34");
extern s32 D_0035ee38 asm("D_0035ee38");
extern s32 D_0035ee3c asm("D_0035ee3c");
extern s32 D_0035ee40 asm("D_0035ee40");
extern s32 D_0035ee44 asm("D_0035ee44");
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
void func_0028ce38(void) asm("func_0028ce38");
void func_00250928(void) asm("func_00250928");
void func_00250698(void) asm("func_00250698");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, s32, s32, s32) asm("Tz__MenuCursor__Create");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_00287c50(void) asm("func_00287c50");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void Tz__LMMU__DrawSelector(s32, s32, s32) asm("Tz__LMMU__DrawSelector");
struct NoTail0328 { ~NoTail0328() {} };
/*TARGET 00250328*/
void Tz__LMMU__Draw(void) asm("Tz__LMMU__Draw");
void Tz__LMMU__Draw(void) {
    NoTail0328 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ee3c, 31);
            if (func_0028acc8(D_0035ee34) != 0 && func_00139d78(D_0035ee44) != 0) {
                s32 i = func_002891e8(D_0035ee34);
                func_0028dae0(D_0035ee44, D_00372448[i].b);
            }
            func_0028dae0(D_0035ee40, 34);
            if (func_0028acc8(D_0035ee34) != 0 && func_0028acb8(D_0035ee34) == 0) {
                func_0028aa40(D_0035ee34);
            }
            if (func_0028acc8(D_0035ee38) != 0 && func_0028acb8(D_0035ee38) == 0) {
                func_0028aa40(D_0035ee38);
            }
        }
        func_00250928();
        func_0028ce38();
    }
    func_00250698();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ee34 : D_0035ee38;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                Tz__MenuCursor__Create(side, 0, 0, D_0035ee3c, 15, 14);
                Tz__MenuCursor__SetParent(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            Tz__MenuCursor__SetType(0, side);
        }
        Tz__LMMU__DrawSelector(obj, mode, side);
    }
}
}  // namespace n00250328

// 00250550 (was src/anon/batch_w268.cpp)
namespace n00250550 {
extern s32 func_00287cd0(void*) asm("func_00287cd0");
extern s32 func_00289310(void*) asm("func_00289310");
extern s32 func_002891e8(void*) asm("func_002891e8");
extern void func_002890e0(void*, s32, s32, s32, s32) asm("func_002890e0");
extern void func_00289038(void*, s32, s32, s32, s32, s32, s32) asm("func_00289038");
extern void func_0023f070(void*, s32, s32) asm("func_0023f070");
extern s32 func_0028d008(s32) asm("func_0028d008");
extern s32 func_002891d0(void*) asm("func_002891d0");
extern void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
// record408_set_and_refresh
extern void func_002b4388(void*, void*, s32) asm("func_002b4388");
struct W268E6 { s16 a, b, c; };
struct W268E36 { u8 d[36]; };
extern void func_00250998(void) asm("func_00250998");
extern W268E6 D_00372448[] asm("D_00372448");
extern void* D_0035ee44 asm("D_0035ee44");
extern void* D_0035ee4c asm("D_0035ee4c");
extern W268E36 D_00372490[] asm("D_00372490");
extern W268E36 D_00372548[] asm("D_00372548");
/*TARGET 00250550*/
// 0x0024c420: definition moved into src/anon/unit_0024ba58.cpp

void Tz__LMMU__DrawSelector(void* a0, s32 a1, s32 a2) asm("Tz__LMMU__DrawSelector");
// 0x0024c420: definition moved into src/anon/unit_0024ba58.cpp

void Tz__LMMU__DrawSelector(void* a0, s32 a1, s32 a2)
{
    s32 cur;
    if (func_00287cd0(a0) != 1) return;
    if (func_00289310(a0) == 0) return;
    cur = func_002891e8(a0);
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, cur, 1, 1, 2, 0, -1);
    if (a1 == 0) {
        func_0023f070(D_0035ee44, D_00372448[cur].c, -1);
        func_00250998();
    }
    if (func_0028d008(a2)) Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
    func_002b4388(D_0035ee4c, a1 == 0 ? &D_00372490[cur] : &D_00372548[cur], 0);
}
}  // namespace n00250550

// 00250698 (was src/anon/batch_wcx.cpp)
namespace n00250698 {
// 0x0024b0e8: definition moved into src/anon/unit_00249ef0.cpp

extern u8* D_0035ee34 asm("D_0035ee34");
extern u8* D_0035ee38 asm("D_0035ee38");
s32 func_002892f8(u8*) asm("func_002892f8");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_00288e88(u8*) asm("func_00288e88");
/*TARGET 00250698*/
void func_00250698(void) asm("func_00250698");
void func_00250698(void)
{
    if (D_0035ee34) {
        s32 a = func_002892f8(D_0035ee34);
        if (!func_0028acc8(D_0035ee34) && a) func_00288e88(D_0035ee34);
    }
    if (D_0035ee38) {
        s32 a = func_002892f8(D_0035ee38);
        if (!func_0028acc8(D_0035ee38) && a) func_00288e88(D_0035ee38);
    }
}
}  // namespace n00250698

// 00250748 (was src/anon/batch_w26.cpp)
namespace n00250748 {
s32 select_get_current(void*) asm("_ZN2Tz6Select10GetCurrentEv");
s32 menuflag_check(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
void func_001a6c90(s32) asm("func_001a6c90");
void ctrl_sel(void) asm("_ZN2Tz4LMMU7CtrlSelEv");
extern void* D_0035ee34 asm("D_0035ee34");
extern u8 D_00372438[] asm("D_00372438");
/*TARGET 00250748*/
// 0x0024ad50: definition moved into src/anon/unit_00249ef0.cpp

void ctrl_sel(void) asm("_ZN2Tz4LMMU7CtrlSelEv");
// 0x0024ad50: definition moved into src/anon/unit_00249ef0.cpp

void ctrl_sel(void) {
    s32 f = D_00372438[select_get_current(D_0035ee34)];
    if (!menuflag_check(f)) func_001a6c90(f);  // set_bit_in_array_b
}
}  // namespace n00250748

// 002507a0 (was src/anon/batch_wcx2.cpp)
namespace n002507a0 {
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
extern s8 D_0035ee51 asm("D_0035ee51");
extern u8* D_0035ee48 asm("D_0035ee48");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ee34 asm("D_0035ee34");
extern u32 D_0035ee3c asm("D_0035ee3c");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_002892f8(u32) asm("func_002892f8");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028d8c0__96362(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__96362(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_00250998(void) asm("func_00250998");
/*TARGET 002507a0*/
void func_002507a0(void) asm("func_002507a0");
void func_002507a0(void)
{
    if (!D_0035ee51) return;
    if (func_00139d78(D_0035ee48)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_002892f8(D_0035ee34);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035ee34, i);
        u8* a = o + 24;
        if ((u8)((D_0035ee51 >> i) & 1)) {
            func_0028d8c0__96362(D_0035ee48 + i * 408, id, 0, 0, D_0035ee3c, 35, -1, 0);
            func_0028dcc0__96362(D_0035ee48 + i * 408, o);
            func_00139648(D_0035ee48 + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ee48 + i * 408, x, func_0023aa38(a));
        }
    }
    func_00250998();
}
}  // namespace n002507a0

// 00250928 (was src/anon/batch_w47.cpp)
namespace n00250928 {
s32 func_00139d78(void*) asm("func_00139d78");
// 0x002322b8: definition moved into src/anon/unit_00231500.cpp

extern u8* D_0035ee48 asm("D_0035ee48");
/*TARGET 00250928*/
void func_00250928(void) asm("func_00250928");
void func_00250928(void) {
    for (s32 i = 0; i < 5; i++) {
        if (func_00139d78(D_0035ee48 + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ee48);
            (*(void (**)(u8*))(*(u8**)o + 20))(o);
        }
    }
}
}  // namespace n00250928

// 00250998 (was src/anon/batch_wcx.cpp)
namespace n00250998 {
extern u8* D_0035ee34 asm("D_0035ee34");
extern s8 D_0035ee51 asm("D_0035ee51");
extern u8* D_0035ee48 asm("D_0035ee48");
s32 func_002891e8(u8*) asm("func_002891e8");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 00250998*/
void func_00250998(void) asm("func_00250998");
void func_00250998(void)
{
    s32 i = func_002891e8(D_0035ee34);
    if (!((D_0035ee51 >> i) & 1)) return;
    if (u_call4_00139d78(D_0035ee48 + i * 408)) {
        u8* o = D_0035ee48 + i * 408;
        if (*(s32*)(o + 388) != 34) func_00138c10(o, 34);
    }
    func_00243230(6, i);
}
}  // namespace n00250998

// 00250a50 (was src/anon/batch_w3904_nsa.cpp)
namespace n00250a50 {
struct AV { void* (*alloc)(void*, u32, s32); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern AH* D_00347f80 asm("D_00347f80");
extern u8 D_00347e40[] asm("D_00347e40");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035f380[] asm("D_0035f380");
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
struct Alloc {
    static void* operator new(u32 n) { return D_00347f80->a->vt->alloc(D_00347f80->a, n, 0); }
    static void* operator new(u32 n, AH* h) { return h->a->vt->alloc(h->a, n, 0); }
    static void* operator new[](u32 n) { return D_00347f80->a->vt->alloc(D_00347f80->a, n, 0); }
};
struct X : Alloc {
    u32 vt; u8 pad[8]; s32 f12; u8 pad2[392]; s32 f408; u8 pad3[24];
    X() { vt = (u32)D_00347f98; vt = (u32)D_00347e60; f12 = 0; func_00239700(pad2 + 8); f408 = 0; vt = (u32)D_00347e40; }
};
struct Z : Alloc {
    u32 vt; u8 pad[8]; s32 f12; u8 pad2[392];
    Z() { vt = (u32)D_00347e60; f12 = 0; func_00239700(pad2 + 8); }
};
struct Y : Alloc {
    u32 vt; u8 pad[8]; u8 m12[12]; u8 pad2[408];
    Y() { vt = (u32)D_00347f98; func_0031a838(m12); vt = (u32)D_00347e60; func_00239700(m12 + 12); vt = (u32)D_0035f380; }
    ~Y();
};
extern void* D_0035ee58 asm("D_0035ee58");
extern void* D_0035ee5c asm("D_0035ee5c");
extern s32 D_0035ee60 asm("D_0035ee60");
extern s32 D_0035ee64 asm("D_0035ee64");
extern X* D_0035ee68 asm("D_0035ee68");
extern Y* D_0035ee6c asm("D_0035ee6c");
extern Y* D_0035ee70 asm("D_0035ee70");
extern Y* D_0035ee74 asm("D_0035ee74");
extern Y* D_0035ee78 asm("D_0035ee78");
extern Z* D_0035ee7c asm("D_0035ee7c");
extern Z* D_0035ee80 asm("D_0035ee80");
struct R { u8 pad[4]; s32 f4; };
void func_00287b18(s32, s32) asm("func_00287b18");
void* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
R* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(s32, s32, s32, void*, s32) asm("TASK_MANAGER__create_thread");
void func_002510d0(void) asm("func_002510d0");
/*TARGET 00250a50*/
// Sets up two work buffers, then allocates and constructs the module objects.
void Tz__CANA__Init(void) asm("Tz__CANA__Init");
// Sets up two work buffers, then allocates and constructs the module objects.
void Tz__CANA__Init(void) {
    void* p;
    func_00287b18(4, 3);
    p = func_00288be8(56);
    func_002889f0(p, 4, 1);
    D_0035ee58 = p;
    func_00288f48(p, 64, 128, 0, 0);
    p = func_00288be8(56);
    func_002889f0(p, 2, 0);
    // Register pin: the hard-register copy raises the allocator load's sched1
    // priority so it issues before the three global stores, as in the original.
    register AH* h asm("$14") = D_00347f80;
    D_0035ee5c = p;
    D_0035ee60 = 0;
    D_0035ee64 = 0;
    D_0035ee68 = new (h) X;
    D_0035ee6c = new Y;
    D_0035ee70 = new Y[4];
    D_0035ee74 = new Y[4];
    D_0035ee78 = new Y;
    D_0035ee7c = new Z;
    D_0035ee80 = new Z;
    TASK_MANAGER__create_thread(func_00103eb0()->f4, 0, 2000, (void*)func_002510d0, 4096);
}
}  // namespace n00250a50

// 00250da8 (was unwritten gap: LMMU globals cleanup)
namespace n00250da8 {
struct AV { void* a; void (*free)(void*, void*); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern AH* D_00347f80 asm("D_00347f80");
struct El3 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El3();
    u8 pad[428];
    static void operator delete[](void* p) { D_00347f80->a->vt->free(D_00347f80->a, p); }
};
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
extern void* D_0035ee5c asm("D_0035ee5c");
extern void* D_0035ee58 asm("D_0035ee58");
extern DO* D_0035ee60 asm("D_0035ee60");
extern DO* D_0035ee64 asm("D_0035ee64");
extern DO* D_0035ee6c asm("D_0035ee6c");
extern El3* D_0035ee70 asm("D_0035ee70");
extern El3* D_0035ee74 asm("D_0035ee74");
extern DO* D_0035ee78 asm("D_0035ee78");
extern DO* D_0035ee7c asm("D_0035ee7c");
extern DO* D_0035ee80 asm("D_0035ee80");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_00250da8(void) asm("func_00250da8");
void func_00250da8(void) {
    void* p;
    if ((p = D_0035ee5c) != 0) { func_00288b00(p); func_00288c20(p); D_0035ee5c = 0; }
    if ((p = D_0035ee58) != 0) { func_00288b00(p); func_00288c20(p); D_0035ee58 = 0; }
    if (D_0035ee60) { D_0035ee60->vt->del(D_0035ee60); D_0035ee60 = 0; }
    if (D_0035ee64) { D_0035ee64->vt->del(D_0035ee64); D_0035ee64 = 0; }
    if (D_0035ee6c) { D_0035ee6c->vt->del(D_0035ee6c); D_0035ee6c = 0; }
    if (D_0035ee70) {
        delete[] D_0035ee70;
        D_0035ee70 = 0;
    }
    if (D_0035ee74) {
        delete[] D_0035ee74;
        D_0035ee74 = 0;
    }
    if (D_0035ee78) { D_0035ee78->vt->del(D_0035ee78); D_0035ee78 = 0; }
    if (D_0035ee7c) { D_0035ee7c->vt->del(D_0035ee7c); D_0035ee7c = 0; }
    if (D_0035ee80) { D_0035ee80->vt->del(D_0035ee80); D_0035ee80 = 0; }
}
}  // namespace n00250da8

