// Linked unit 0x0024ba58-0x0024cda8.
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0024ba58 (was src/anon/batch_w271.cpp)
namespace n0024ba58 {
struct E_w271 { u8 a[8]; u8 b[8]; s8 c; u8 pad; u16 h; u8 rest[16]; };
extern void* D_0035edac asm("D_0035edac");
extern u32 D_0035edb0 asm("D_0035edb0");
extern void* D_0035edc0 asm("D_0035edc0");
extern E_w271 D_003720a0[] asm("D_003720a0");
void Tz__Select__SetItem(void*, s32, s32, s32, u32, u32, E_w271*, void*) asm("Tz__Select__SetItem");
u8* func_002891b8(void*, s32) asm("func_002891b8");
u32 func_0023aa78(void*) asm("func_0023aa78");
u32 func_0023aa98(void*) asm("func_0023aa98");
void Tz__Select__SetExOffset(void*, s32, u32, s32) asm("Tz__Select__SetExOffset");
u32 func_0028dd90(u32) asm("func_0028dd90");
// mod10_classify_012
u32 func_0028ddd8(u32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002b4388(void*, E_w271*, s32) asm("func_002b4388");
/*TARGET 0024ba58*/
void Tz__HBTE__SetupSel(void) asm("Tz__HBTE__SetupSel");
void Tz__HBTE__SetupSel(void) {
    s32 sel = 0;
    s32 i;
    for (i = 0; i < 2; i++) {
        if (D_003720a0[i].c) sel = i;
        Tz__Select__SetItem(D_0035edac, i, 0, 0, D_0035edb0, D_003720a0[i].h, &D_003720a0[i], D_003720a0[i].b);
        u8* v = func_002891b8(D_0035edac, i);
        Tz__Select__SetExOffset(D_0035edac, i, func_0023aa78(v + 24), 0);
        u32 s = func_0023aa98(v + 24);
        *(u32*)(v + 432) = func_0028dd90(s);
        *(u32*)(v + 428) = func_0028ddd8(s);
        func_001395f8(v);
    }
    Tz__Select__SetCurrent(D_0035edac, sel, 1, 0, 2);
    func_002b4388(D_0035edc0, &D_003720a0[sel], 0);
}
}  // namespace n0024ba58

// 0024bbb0 (was src/anon/batch_w87.cpp)
namespace n0024bbb0 {
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_00139d78(void*) asm("func_00139d78");
// 0x00247c20: definition moved into src/anon/unit_00242478.cpp

// ---- 0x24bbb0 ----
extern void* D_0035edb0 asm("D_0035edb0");
extern void* D_0035eda8 asm("D_0035eda8");
extern void* D_0035edb8 asm("D_0035edb8");
extern void* D_0035edb4 asm("D_0035edb4");
struct E6 { s16 a, b, c; };
extern E6 D_00371ff0[] asm("D_00371ff0");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028ab20(void*) asm("func_0028ab20");
/*TARGET 0024bbb0*/
void Tz__HBTE__LoopAll(void) asm("Tz__HBTE__LoopAll");
void Tz__HBTE__LoopAll(void) {
    if (func_00139d78(D_0035edb0)) {
        if (func_0023f0c0(D_0035edb0) != 32) func_0023f070(D_0035edb0, 32, -1);
    }
    if (func_0028acc8(D_0035eda8)) {
        func_0028ab20(D_0035eda8);
        s32 k = func_002891e8(D_0035eda8);
        if (func_00139d78(D_0035edb8)) {
            if (func_0023f0c0(D_0035edb8) != D_00371ff0[k].c) func_0023f070(D_0035edb8, D_00371ff0[k].c, -1);
        }
    }
    if (func_00139d78(D_0035edb4)) {
        if (func_0023f0c0(D_0035edb4) != 35) func_0023f070(D_0035edb4, 35, -1);
    }
}
}  // namespace n0024bbb0

// 0024bcb8 (was src/anon/batch_w82.cpp)
namespace n0024bcb8 {
struct VObj82 { struct VT { void* f[8]; }* vt; };
extern VObj82* D_0035edb0 asm("D_0035edb0");
extern VObj82* D_0035edb8 asm("D_0035edb8");
extern VObj82* D_0035edb4 asm("D_0035edb4");
extern u8* D_0035eda8 asm("D_0035eda8");
extern u8* D_0035edac asm("D_0035edac");
static inline void VCall5_82(VObj82* o) { ((void (*)(VObj82*))o->vt->f[5])(o); }
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_0028abe0(u8*) asm("func_0028abe0");
void func_0024c828(void) asm("func_0024c828");
void func_0028ce38(void) asm("func_0028ce38");
/*TARGET 0024bcb8*/
void func_0024bcb8(void) asm("func_0024bcb8");
void func_0024bcb8(void)
{
    if (func_00139d78(D_0035edb0)) VCall5_82(D_0035edb0);
    if (func_00139d78(D_0035edb8)) VCall5_82(D_0035edb8);
    if (func_00139d78(D_0035edb4)) VCall5_82(D_0035edb4);
    if (func_0028acc8(D_0035eda8)) func_0028abe0(D_0035eda8);
    if (func_0028acc8(D_0035edac)) func_0028abe0(D_0035edac);
    func_0024c828();
    func_0028ce38();
}
}  // namespace n0024bcb8

// 0024bd80 (was unwritten gap: pause callback)
namespace n0024bd80 {
extern u8 D_0035edc4 asm("D_0035edc4");
void func_0024bd80(void) asm("func_0024bd80");
void func_0024bd80(void) { D_0035edc4 = 0; }
}  // namespace n0024bd80

// 0024bd90 (was src/anon/batch_w76.cpp)
namespace n0024bd90 {
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
// copy_globals_3words
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_001039f8(void) asm("func_001039f8");
void func_0024be68(void) asm("func_0024be68");
void Tz__HBTE__CtrlSel(void) asm("Tz__HBTE__CtrlSel");
extern u32 D_0035eda8 asm("D_0035eda8");
extern u32 D_0035edac asm("D_0035edac");
extern void* D_0035edb0 asm("D_0035edb0");
extern void* D_0035edb4 asm("D_0035edb4");
extern void* D_0035edb8 asm("D_0035edb8");
/*TARGET 0024bd90*/
s32 func_0024bd90(void) asm("func_0024bd90");
s32 func_0024bd90(void)
{
    s32 mode = func_00287bc0();
    Tz__MenuBase__SaveMode();  // copy_globals_3words
    if (func_00287db0()) {
        if (func_0028acc8(D_0035eda8) || func_0028acc8(D_0035edac) || func_00139d78(D_0035edb0)
            || func_00139d78(D_0035edb4) || func_00139d78(D_0035edb8))
            return 0;
        func_001039f8();
        return 1;
    } else {
        switch (mode) {
        case 0: func_0024be68(); break;
        case 1: Tz__HBTE__CtrlSel(); break;
        }
    }
    return 0;
}
}  // namespace n0024bd90

// 0024be68 (was src/anon/batch_wcx2.cpp)
namespace n0024be68 {
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
extern u32 D_0035eda8 asm("D_0035eda8");
// --------------------
extern u8 D_0035edc4 asm("D_0035edc4");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x8759(s32) asm("func_00289380");
s32 func_00289310_x8760(s32) asm("func_00289310");
s32 func_0028ae28_x8761(s32, s32) asm("func_0028ae28");
void func_002426a0(s32) asm("func_002426a0");
void Tz__HBTE__LoopAll() asm("Tz__HBTE__LoopAll");
void Tz__HBTE__SetupSel() asm("Tz__HBTE__SetupSel");
void func_00287c90(s32) asm("func_00287c90");
void Tz__HBTE__CreateNewMark() asm("Tz__HBTE__CreateNewMark");
void func_00287df0_x8767(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00287da0() asm("func_00287da0");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0024be68*/
void func_0024be68() asm("func_0024be68");
void func_0024be68() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8759(D_0035eda8);
    if (D_0035edc4) return;
    if (r != -1 || func_00289310_x8760(D_0035eda8)) {
        if (!func_0028ae28_x8761(D_0035eda8, 0)) {
            func_002426a0(0);
            Tz__HBTE__LoopAll();
        }
    }
    if (!a && func_0028ae28_x8761(D_0035eda8, 0)) {
        func_00287c90(1);
        Tz__HBTE__CreateNewMark();
    }
    func_00287df0_x8767(r, func_00289310_x8760(D_0035eda8), 1, 0, 1);
    switch (r) {
    case -3: case -1:
        break;
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1: case 2:
        Tz__HBTE__SetupSel();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}
}  // namespace n0024be68

// .rodata words read by other code (retail bytes, in place)
namespace r00371fc8 {
extern const u32 R_00371fc8[2] asm("D_00371fc8") __attribute__((aligned(4))) = { 0x3d003c, 0x3e };
}  // namespace r00371fc8

// 0024bfb8 (was src/anon/batch_wcx2.cpp)
namespace n0024bfb8 {
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
// 0x002a5a90: definition moved into src/anon/unit_002a5a90.cpp

// --------------------
struct E24bfb8 { u8 b[36]; };
extern s32 D_0035edac_24b asm("D_0035edac");
extern s32 D_0035eda8_24b asm("D_0035eda8");
extern s32 D_0035edc0_24b asm("D_0035edc0");
extern E24bfb8 D_00372030[] asm("D_00372030");
extern s16 D_00371fc8[] asm("D_00371fc8");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x10206(s32) asm("func_00289380");
s32 func_0028acc8_x10207(s32) asm("func_0028acc8");
s32 func_00289310_x10208(s32) asm("func_00289310");
void func_0028abe0_x10209(s32) asm("func_0028abe0");
s32 func_002891e8_x10210(s32) asm("func_002891e8");
void func_002b4388_x10212(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28_x10215(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10216(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0_x10218(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287b08(s32) asm("func_00287b08");
void func_00287da0() asm("func_00287da0");
/*TARGET 0024bfb8*/
void Tz__HBTE__CtrlSel() asm("Tz__HBTE__CtrlSel");
void Tz__HBTE__CtrlSel() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10206(D_0035edac_24b);
    if (a == 2) {
        if (func_0028acc8_x10207(D_0035edac_24b)) {
            if (r != -1 || func_00289310_x10208(D_0035edac_24b)) func_0028abe0_x10209(D_0035edac_24b);
            return;
        }
        func_002b4388_x10212(D_0035edc0_24b, &D_00372030[func_002891e8_x10210(D_0035eda8_24b)], 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10208(D_0035edac_24b)) {
        if (!func_0028ae28_x10215(D_0035edac_24b, 0)) func_0028ab20_x10216(D_0035edac_24b);
    }
    if (!a && func_0028ae28_x10215(D_0035edac_24b, 0)) func_00287c90(1);
    func_00287df0_x10218(r, func_00289310_x10208(D_0035edac_24b), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035edac_24b);
        func_00287c90(1);
        break;
    case 0:
        func_00287b08(D_00371fc8[func_002891e8_x10210(D_0035eda8_24b)]);
        func_00287da0();
        break;
    case -4: case -3: case -1:
        break;
    }
}
}  // namespace n0024bfb8

// 0024c1a8 (was src/anon/batch_w1579_g.cpp)
namespace n0024c1a8 {
struct Tc1a8 { s16 a; s16 b; s16 c; };
extern Tc1a8 D_00371ff0[] asm("D_00371ff0");
extern s32 D_0035eda8 asm("D_0035eda8");
extern s32 D_0035edac asm("D_0035edac");
extern s32 D_0035edb0 asm("D_0035edb0");
extern s32 D_0035edb4 asm("D_0035edb4");
extern s32 D_0035edb8 asm("D_0035edb8");
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
void func_0024c828(void) asm("func_0024c828");
void func_0024c568(void) asm("func_0024c568");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, s32, s32, s32) asm("Tz__MenuCursor__Create");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_00287c50(void) asm("func_00287c50");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void Tz__HBTE__DrawSelector(s32, s32, s32) asm("Tz__HBTE__DrawSelector");
struct NoTailc1a8 { ~NoTailc1a8() {} };
/*TARGET 0024c1a8*/
void Tz__HBTE__Draw(void) asm("Tz__HBTE__Draw");
void Tz__HBTE__Draw(void) {
    NoTailc1a8 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035edb0, 31);
            if (func_0028acc8(D_0035eda8) != 0 && func_00139d78(D_0035edb8) != 0) {
                s32 i = func_002891e8(D_0035eda8);
                func_0028dae0(D_0035edb8, D_00371ff0[i].b);
            }
            func_0028dae0(D_0035edb4, 34);
            if (func_0028acc8(D_0035eda8) != 0 && func_0028acb8(D_0035eda8) == 0) {
                func_0028aa40(D_0035eda8);
            }
            if (func_0028acc8(D_0035edac) != 0 && func_0028acb8(D_0035edac) == 0) {
                func_0028aa40(D_0035edac);
            }
        }
        func_0024c828();
        func_0028ce38();
    }
    func_0024c568();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035eda8 : D_0035edac;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                Tz__MenuCursor__Create(side, 0, 0, D_0035edb0, 15, 14);
                Tz__MenuCursor__SetParent(side, func_002891d0(obj));
                if (side != 0 && func_0028d008(0) == 0) {
                    Tz__MenuCursor__Create(0, 0, 0, D_0035edb0, 15, 14);
                    Tz__MenuCursor__SetParent(0, func_002891d0(D_0035eda8));
                    Tz__MenuCursor__SetType(0, 1);
                }
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            Tz__MenuCursor__SetType(0, side);
        }
        Tz__HBTE__DrawSelector(obj, mode, side);
    }
}
}  // namespace n0024c1a8

// 0024c420 (was src/anon/batch_w268.cpp)
namespace n0024c420 {
extern s32 func_00287cd0(void*) asm("func_00287cd0");
extern s32 func_00289310(void*) asm("func_00289310");
extern s32 func_002891e8(void*) asm("func_002891e8");
extern void func_002890e0(void*, s32, s32, s32, s32) asm("func_002890e0");
extern void func_00289038(void*, s32, s32, s32, s32, s32, s32) asm("func_00289038");
extern void func_0023f070(void*, s32, s32) asm("func_0023f070");
extern void func_0024c898(void) asm("func_0024c898");
extern s32 func_0028d008(s32) asm("func_0028d008");
extern s32 func_002891d0(void*) asm("func_002891d0");
extern void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
// record408_set_and_refresh
extern void func_002b4388(void*, void*, s32) asm("func_002b4388");
struct W268E6 { s16 a, b, c; };
struct W268E36 { u8 d[36]; };
extern W268E6 D_00371ff0[] asm("D_00371ff0");
extern void* D_0035edb8 asm("D_0035edb8");
extern void* D_0035edc0 asm("D_0035edc0");
extern W268E36 D_00372030[] asm("D_00372030");
extern W268E36 D_003720a0[] asm("D_003720a0");
/*TARGET 0024c420*/
void Tz__HBTE__DrawSelector(void* a0, s32 a1, s32 a2) asm("Tz__HBTE__DrawSelector");
void Tz__HBTE__DrawSelector(void* a0, s32 a1, s32 a2)
{
    s32 cur;
    if (func_00287cd0(a0) != 1) return;
    if (func_00289310(a0) == 0) return;
    cur = func_002891e8(a0);
    func_002890e0(a0, 1, 2, 0, -1);
    func_00289038(a0, cur, 1, 1, 2, 0, -1);
    if (a1 == 0) {
        func_0023f070(D_0035edb8, D_00371ff0[cur].c, -1);
        func_0024c898();
    }
    if (func_0028d008(a2)) Tz__MenuCursor__SetParent(a2, func_002891d0(a0));
    func_002b4388(D_0035edc0, a1 == 0 ? &D_00372030[cur] : &D_003720a0[cur], 0);
}
}  // namespace n0024c420

// 0024c568 (was src/anon/batch_w68.cpp)
namespace n0024c568 {
/* ---- 0024c568 ---- */
extern void* D_0035eda8 asm("D_0035eda8");
extern void* D_0035edac asm("D_0035edac");
s32 func_002892f8(void*) asm("func_002892f8");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_00288e88(void*) asm("func_00288e88");
/*TARGET 0024c568*/
void func_0024c568(void) asm("func_0024c568");
void func_0024c568(void) {
    if (D_0035eda8) {
        s32 r = func_002892f8(D_0035eda8);
        if (!func_0028acc8(D_0035eda8) && r) func_00288e88(D_0035eda8);
    }
    if (D_0035edac) {
        s32 r = func_002892f8(D_0035edac);
        if (!func_0028acc8(D_0035edac) && r) func_00288e88(D_0035edac);
    }
}
}  // namespace n0024c568

// 0024c618 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024c618 {
extern u32 D_0035eda8 asm("D_0035eda8");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 0024c618*/
void func_0024c618() asm("_Z13func_0024c618v");
void func_0024c618() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035eda8);
    func_0023fc40(&v0, 4);
}
}  // namespace n0024c618

// 0024c650 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024c650 {
extern u32 D_0035eda8 asm("D_0035eda8");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void Tz__Select__SetCurrent(...) asm("Tz__Select__SetCurrent");
/*TARGET 0024c650*/
void func_0024c650() asm("_Z13func_0024c650v");
void func_0024c650() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        Tz__Select__SetCurrent(D_0035eda8, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n0024c650

// 0024c6a0 (was src/anon/batch_wcx2.cpp)
namespace n0024c6a0 {
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
// 0x00244c30: definition moved into src/anon/unit_00242478.cpp

extern s8 D_0035edc5 asm("D_0035edc5");
extern u8* D_0035edbc asm("D_0035edbc");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035eda8 asm("D_0035eda8");
extern u32 D_0035edb0 asm("D_0035edb0");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028afa8(u32) asm("func_0028afa8");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028d8c0_111552(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_111552(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_0024c898(void) asm("func_0024c898");
/*TARGET 0024c6a0*/
void Tz__HBTE__CreateNewMark(void) asm("Tz__HBTE__CreateNewMark");
void Tz__HBTE__CreateNewMark(void)
{
    if (!D_0035edc5) return;
    if (func_00139d78(D_0035edbc)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035eda8);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035eda8, i);
        u8* a = o + 24;
        if ((u8)((D_0035edc5 >> i) & 1)) {
            func_0028d8c0_111552(D_0035edbc + i * 408, id, 0, 0, D_0035edb0, 38, -1, 0);
            func_0028dcc0_111552(D_0035edbc + i * 408, o);
            func_00139648(D_0035edbc + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035edbc + i * 408, x, func_0023aa38(a));
        }
    }
    func_0024c898();
}
}  // namespace n0024c6a0

// 0024c828 (was src/anon/batch_w45.cpp)
namespace n0024c828 {
typedef void (*VFn)(u8*);
s32 func_00139d78(u8*) asm("func_00139d78");
extern u8* D_0035edbc asm("D_0035edbc");
/*TARGET 0024c828*/
// 0x00243230: definition moved into src/anon/unit_00242478.cpp

void func_0024c828(void) asm("func_0024c828");
// 0x00243230: definition moved into src/anon/unit_00242478.cpp

void func_0024c828(void) {
    u32 off = 0;
    for (s32 i = 2; i >= 0; i--) {
        if (func_00139d78(D_0035edbc + off)) {
            u8* o = (u8*)(off + (u32)D_0035edbc);
            (*(VFn*)(*(u8**)o + 20))(o);
        }
        off += 408;
    }
}
}  // namespace n0024c828

// 0024c898 (was src/anon/batch_wcx.cpp)
namespace n0024c898 {
extern u8* D_0035eda8 asm("D_0035eda8");
extern s8 D_0035edc5 asm("D_0035edc5");
extern u8* D_0035edbc asm("D_0035edbc");
s32 func_002891e8(u8*) asm("func_002891e8");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 0024c898*/
void func_0024c898(void) asm("func_0024c898");
void func_0024c898(void)
{
    s32 i = func_002891e8(D_0035eda8);
    if (!((D_0035edc5 >> i) & 1)) return;
    if (u_call4_00139d78(D_0035edbc + i * 408)) {
        u8* o = D_0035edbc + i * 408;
        if (*(s32*)(o + 388) != 37) func_00138c10(o, 37);
    }
    func_00243230(7, i);
}
}  // namespace n0024c898

// 0024c950 (was src/anon/batch_w3714_nsa.cpp)
namespace n0024c950 {
struct Alloc;
struct AllocVt { u8* (*alloc)(Alloc*, u32, void*); };
struct Alloc { AllocVt* vt; };
struct HeapHolder { u8 pad[0x14]; Alloc* heap; };
extern Alloc* D_0032ba14 asm("D_0032ba14");
extern HeapHolder* D_00347f80 asm("D_00347f80");
extern u8 D_0032bae1 asm("D_0032bae1");
extern u32 D_00347e40 asm("D_00347e40");
extern u32 D_00347e60 asm("D_00347e60");
extern u32 D_00347f98 asm("D_00347f98");
extern u32 D_0024cda8 asm("D_0024cda8");
extern u32 D_0035edcc asm("D_0035edcc");
extern u32 D_0035edd0 asm("D_0035edd0");
extern s32 D_0035edd4 asm("D_0035edd4");
extern s32 D_0035edd8 asm("D_0035edd8");
extern s32 D_0035eddc asm("D_0035eddc");
extern u8* D_0035ede0 asm("D_0035ede0");
extern u8* D_0035ede4 asm("D_0035ede4");
extern s32 D_0035edf4 asm("D_0035edf4");
extern u32 D_0035edf8 asm("D_0035edf8");
s32 func_0024dfe0(void) asm("func_0024dfe0");
void func_00287b18(s32, s32) asm("func_00287b18");
u32 func_00288be8(s32) asm("func_00288be8");
void func_002889f0(u32, s32, s32) asm("func_002889f0");
void func_00288f48(u32, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(u8*) asm("func_002b3df8");
void func_00239700(u8*) asm("func_00239700");
void func_0031a838(u8*) asm("func_0031a838");
u32 func_00103570(void) asm("func_00103570");
u32 func_001063f0(s32, u32) asm("func_001063f0");
void func_002fde18(u32, s32, s32) asm("func_002fde18");
void func_0028d068(s32, s32) asm("func_0028d068");
u8* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, s32, s32, u32*, s32) asm("TASK_MANAGER__create_thread");
/*TARGET 0024c950*/
void func_0024c950(void) asm("func_0024c950");
void func_0024c950(void) {
    D_0035edf4 = D_0032bae1 != 6;
    s32 n = func_0024dfe0();
        func_00287b18(n, 3);
    u32 a = func_00288be8(56);
    func_002889f0(a, n, 1);
    D_0035edcc = a;
    u32 b = func_00288be8(56);
    func_002889f0(b, 2, 0);
    D_0035edd0 = b;
    func_00288f48(b, 64, 128, 0, 0);
    D_0035edd4 = 0;
    D_0035edd8 = 0;
    D_0035eddc = 0;
    u8* c = D_0032ba14->vt->alloc(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(c);
    u8* f7; u8* f0;
    asm("lui %0,%%hi(D_0035edec)\n\tlui %1,%%hi(D_0035edf0)" : "=r"(f7), "=r"(f0));
    asm("sw %1,%%lo(D_0035edec)(%2)" : "=m"(*(u8**)f7) : "r"(c), "r"(f7));
    s32 a1;
    asm("li %1,436\n\tsb $0,%%lo(D_0035edf0)(%2)" : "=m"(*f0), "=r"(a1) : "r"(f0));
    Alloc* h = D_00347f80->heap;
    u8* p = h->vt->alloc(h, a1, 0);
    *(s32*)(p + 0xc) = 0;
    *(u32**)p = &D_00347e60;
    func_00239700(p + 0x18);
    *(s32*)(p + 0x198) = 0;
    *(u32**)p = &D_00347e40;
    D_0035ede0 = p;
    Alloc* h2 = D_00347f80->heap;
    u8* q = h2->vt->alloc(h2, 436, 0);
    *(u32**)q = &D_00347f98;
    func_0031a838(q + 0xc);
    *(u32**)q = &D_00347e60;
    func_00239700(q + 0x18);
    *(u32**)q = &D_00347e40;
    *(s32*)(q + 0x198) = 0;
    D_0035ede4 = q;
    u32 w = func_001063f0(32, func_00103570());
    D_0035edf8 = w;
    func_002fde18(w, 0, 32);
    register HeapHolder* hp asm("$15") = D_00347f80;
    Alloc* h3 = hp->heap;
    s32 i = n - 1;
    u8* r = h3->vt->alloc(h3, n * 408 + 4, 0);
    u8* arr = r + 4;
    *(s32*)r = n;
    u8* e = arr;
    if (n != 0) {
        do {
            *(s32*)(e + 0xc) = 0;
            *(u32**)e = &D_00347e60;
            func_00239700(e + 0x18);
            i--;
            e += 408;
        } while (i != -1);
    }
    u8* t7;
    asm volatile("lui %0,%%hi(D_0035ede8)" : "=r"(t7));
    u8* fc;
    asm volatile("lui %0,%%hi(D_0035edfc)" : "=r"(fc));
    {register u8* ar asm("$19") = arr; asm volatile("sw %0,%%lo(D_0035ede8)(%1)" : : "r"(ar), "r"(t7));}
    s32 a0;
    asm volatile("li %0,30026" : "=r"(a0));
    asm volatile("sb $0,%%lo(D_0035edfc)(%0)" : : "r"(fc));
    func_0028d068(a0, -1);
    TASK_MANAGER__create_thread(*(u32*)(func_00103eb0() + 4), 0, 2000, &D_0024cda8, 4096);
}
}  // namespace n0024c950

// 0024cbd8 (was unwritten gap: menu globals cleanup, like 0x243500)
namespace n0024cbd8 {
struct AV { void* a; void (*free)(void*, void*); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern AH* D_00347f80 asm("D_00347f80");
struct El2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El2();
    u8 pad[404];
    static void operator delete[](void* p) { D_00347f80->a->vt->free(D_00347f80->a, p); }
};
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
extern void* D_0035edcc asm("D_0035edcc");
extern void* D_0035edd0 asm("D_0035edd0");
extern void* D_0035edec asm("D_0035edec");
extern void* D_0035edf8 asm("D_0035edf8");
extern DO* D_0035edd4 asm("D_0035edd4");
extern DO* D_0035edd8 asm("D_0035edd8");
extern DO* D_0035eddc asm("D_0035eddc");
extern DO* D_0035ede0 asm("D_0035ede0");
extern DO* D_0035ede4 asm("D_0035ede4");
extern El2* D_0035ede8 asm("D_0035ede8");
extern AO* D_0032ba14 asm("D_0032ba14");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_002b3fb0(void*) asm("func_002b3fb0");
void func_00106450(void*) asm("func_00106450");
void func_0024cbd8(void) asm("func_0024cbd8");
void func_0024cbd8(void) {
    void* p;
    if ((p = D_0035edcc) != 0) { func_00288b00(p); func_00288c20(p); D_0035edcc = 0; }
    if ((p = D_0035edd0) != 0) { func_00288b00(p); func_00288c20(p); D_0035edd0 = 0; }
    if (D_0035edd4) { D_0035edd4->vt->del(D_0035edd4); D_0035edd4 = 0; }
    if (D_0035edd8) { D_0035edd8->vt->del(D_0035edd8); D_0035edd8 = 0; }
    if (D_0035eddc) { D_0035eddc->vt->del(D_0035eddc); D_0035eddc = 0; }
    if ((p = D_0035edec) != 0) { func_002b3fb0(p); D_0032ba14->vt->free(D_0032ba14, p); D_0035edec = 0; }
    if (D_0035ede0) { D_0035ede0->vt->del(D_0035ede0); D_0035ede0 = 0; }
    if (D_0035ede4) { D_0035ede4->vt->del(D_0035ede4); D_0035ede4 = 0; }
    if (D_0035edf8) { func_00106450(D_0035edf8); D_0035edf8 = 0; }
    if (D_0035ede8) {
        delete[] D_0035ede8;
        D_0035ede8 = 0;
    }
}
}  // namespace n0024cbd8

