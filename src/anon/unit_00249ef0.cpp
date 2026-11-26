// Linked unit 0x00249ef0-0x0024b588.
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/smenu_hb.hpp"

// 00249ef0 (was src/anon/batch_w99.cpp)
namespace n00249ef0 {
struct E249e { u8 pad[8]; u8 sub[8]; s8 on; u8 pad2; u16 id; u8 pad3[16]; };
extern E249e D_00371f58[] asm("D_00371f58");
extern u32 D_0035ed74 asm("D_0035ed74");
extern u32 D_0035ed78 asm("D_0035ed78");
extern u32 D_0035ed90 asm("D_0035ed90");
void Tz__Select__SetItem(u32, s32, s32, s32, u32, u16, E249e*, void*) asm("Tz__Select__SetItem");
u8* func_002891b8(u32, s32) asm("func_002891b8");
u32 func_0023aa78(void*) asm("func_0023aa78");
u32 func_0023aa98(void*) asm("func_0023aa98");
void Tz__Select__SetExOffset(u32, s32, u32, s32) asm("Tz__Select__SetExOffset");
u32 func_0028dd90(u32) asm("func_0028dd90");
// mod10_classify_012
u32 func_0028ddd8(u32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002b4388_249ef0(u32, E249e*, s32) asm("func_002b4388");
/*TARGET 00249ef0*/
void Tz__TRTE__SetupSel(void) asm("Tz__TRTE__SetupSel");
void Tz__TRTE__SetupSel(void)
{
    s32 i;
    s32 sel = 0;
    for (i = 0; i < 2; i++) {
        if (D_00371f58[i].on) sel = i;
        Tz__Select__SetItem(D_0035ed74, i, 0, 0, D_0035ed78, D_00371f58[i].id, &D_00371f58[i], D_00371f58[i].sub);
        u8* o = func_002891b8(D_0035ed74, i);
        Tz__Select__SetExOffset(D_0035ed74, i, func_0023aa78(o + 24), 0);
        u32 x = func_0023aa98(o + 24);
        *(u32*)(o + 432) = func_0028dd90(x);
        *(u32*)(o + 428) = func_0028ddd8(x);
        func_001395f8(o);
    }
    Tz__Select__SetCurrent(D_0035ed74, sel, 1, 0, 2);
    func_002b4388_249ef0(D_0035ed90, &D_00371f58[sel], 0);
}
}  // namespace n00249ef0

// 0024a048 (was src/anon/batch_w86.cpp)
namespace n0024a048 {
struct Info { u8 p0[4]; s16 anim; };
extern void* D_0035ed78 asm("D_0035ed78");
extern void* D_0035ed70 asm("D_0035ed70");
extern void* D_0035ed80 asm("D_0035ed80");
extern void* D_0035ed7c asm("D_0035ed7c");
extern void* D_0035ed84 asm("D_0035ed84");
extern void* D_0035ed88 asm("D_0035ed88");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028ab20(void*) asm("func_0028ab20");
void* func_002891e8(void*) asm("func_002891e8");
Info* func_0024b1a0(void*) asm("func_0024b1a0");
void func_0028da70(void*, s32) asm("func_0028da70");
/*TARGET 0024a048*/
// 0x00245be8: definition moved into src/anon/unit_00242478.cpp
void Tz__TRTE__LoopAll(void) asm("Tz__TRTE__LoopAll");
// 0x00245be8: definition moved into src/anon/unit_00242478.cpp
void Tz__TRTE__LoopAll(void)
{
    if (func_00139d78(D_0035ed78) && func_0023f0c0(D_0035ed78) != 32) func_0023f070(D_0035ed78, 32, -1);
    if (func_0028acc8(D_0035ed70)) {
        func_0028ab20(D_0035ed70);
        Info* in = func_0024b1a0(func_002891e8(D_0035ed70));
        if (func_00139d78(D_0035ed80) && func_0023f0c0(D_0035ed80) != in->anim) func_0023f070(D_0035ed80, in->anim, -1);
    }
    if (func_00139d78(D_0035ed7c) && func_0023f0c0(D_0035ed7c) != 35) func_0023f070(D_0035ed7c, 35, -1);
    func_0028da70(D_0035ed84, 33);
    func_0028da70(D_0035ed88, 41);
}
}  // namespace n0024a048

// 0024a150 (was unwritten gap: TR fade-out, like 0x248828)
namespace n0024a150 {
typedef void (*VFn)(...);
struct VObj { VFn* vt; };
extern VObj* D_0035ed78 asm("D_0035ed78");
extern VObj* D_0035ed80 asm("D_0035ed80");
extern VObj* D_0035ed7c asm("D_0035ed7c");
extern VObj* D_0035ed84 asm("D_0035ed84");
extern VObj* D_0035ed88 asm("D_0035ed88");
extern u32 D_0035ed70 asm("D_0035ed70");
extern u32 D_0035ed74 asm("D_0035ed74");
s32 func_00139d78(u32) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
void func_0024b078(void) asm("func_0024b078");
void func_0028ce38(void) asm("func_0028ce38");
void func_0024a150(void) asm("func_0024a150");
void func_0024a150(void) {
    if (func_00139d78((u32)D_0035ed78)) D_0035ed78->vt[5](D_0035ed78);
    if (func_00139d78((u32)D_0035ed80)) D_0035ed80->vt[5](D_0035ed80);
    if (func_00139d78((u32)D_0035ed7c)) D_0035ed7c->vt[5](D_0035ed7c);
    if (func_0028acc8(D_0035ed70)) func_0028abe0(D_0035ed70);
    if (func_0028acc8(D_0035ed74)) func_0028abe0(D_0035ed74);
    if (func_00139d78((u32)D_0035ed84)) D_0035ed84->vt[5](D_0035ed84);
    if (func_00139d78((u32)D_0035ed88)) D_0035ed88->vt[5](D_0035ed88);
    func_0024b078();
    func_0028ce38();
}
}  // namespace n0024a150
// 0024a260 (was unwritten gap: pause callback)
namespace n0024a260 {
extern u8 D_0035ed94 asm("D_0035ed94");
void func_0024a260(void) asm("func_0024a260");
void func_0024a260(void) { D_0035ed94 = 0; }
}  // namespace n0024a260

// 0024a270 (was src/anon/batch_w91.cpp)
namespace n0024a270 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// --- 0024a270
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
// copy_globals_3words
u32 func_00287db0(void) asm("func_00287db0");
u32 func_0028acc8(u32) asm("func_0028acc8");
void func_001039f8(void) asm("func_001039f8");
void func_0024a348(void) asm("func_0024a348");
void func_0024a4d0(void) asm("func_0024a4d0");
extern u32 D_0035ed70 asm("D_0035ed70");
extern u32 D_0035ed74 asm("D_0035ed74");
extern u8* D_0035ed78 asm("D_0035ed78");
extern u8* D_0035ed7c asm("D_0035ed7c");
extern u8* D_0035ed80 asm("D_0035ed80");
/*TARGET 0024a270*/
u32 func_0024a270(void) asm("func_0024a270");
u32 func_0024a270(void) {
    s32 s = func_00287bc0();
    Tz__MenuBase__SaveMode();  // copy_globals_3words
    if (func_00287db0()) {
        if (!func_0028acc8(D_0035ed70) && !func_0028acc8(D_0035ed74) && !u_call4_00139d78(D_0035ed78) && !u_call4_00139d78(D_0035ed7c) && !u_call4_00139d78(D_0035ed80)) {
            func_001039f8();
            return 1;
        }
    } else switch (s) {
        case 0: func_0024a348(); break;
        case 1: func_0024a4d0(); break;
    }
    return 0;
}
}  // namespace n0024a270

// 0024a348 (was src/anon/batch_wcx2.cpp)
namespace n0024a348 {
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
extern u32 D_0035ed70 asm("D_0035ed70");
// 0x00245eb8: definition moved into src/anon/unit_00242478.cpp

// --------------------
extern u8 D_0035ed94 asm("D_0035ed94");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x9460(s32) asm("func_00289380");
s32 func_00289310_x9461(s32) asm("func_00289310");
s32 func_0028ae28_x9462(s32, s32) asm("func_0028ae28");
void func_002426a0(s32) asm("func_002426a0");
void Tz__TRTE__LoopAll() asm("Tz__TRTE__LoopAll");
void func_00287c90(s32) asm("func_00287c90");
void Tz__TRTE__CreateNewMark() asm("Tz__TRTE__CreateNewMark");
void func_0024b1f8() asm("func_0024b1f8");
s32 func_00287df0_k5(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_0024abb0() asm("func_0024abb0");
void func_002535b0(s32) asm("func_002535b0");
void func_00288658(s32, s32) asm("func_00288658");
void func_0024a150() asm("func_0024a150");
void func_00288670(void (*)()) asm("func_00288670");
void func_00287da0() asm("func_00287da0");
void Tz__TRTE__SetupSel() asm("Tz__TRTE__SetupSel");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 0024a348*/
void func_0024a348() asm("func_0024a348");
void func_0024a348() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x9460(D_0035ed70);
    if (D_0035ed94) return;
    if (r != -1 || func_00289310_x9461(D_0035ed70)) {
        if (!func_0028ae28_x9462(D_0035ed70, 0)) {
            func_002426a0(0);
            Tz__TRTE__LoopAll();
        }
    }
    if (!a && func_0028ae28_x9462(D_0035ed70, 0)) {
        func_00287c90(1);
        Tz__TRTE__CreateNewMark();
    }
    if (func_00242848(func_00287df0_k5(r, func_00289310_x9461(D_0035ed70), 1, func_0024b1f8, 1))) return;
    switch (r) {
    case -6:
        func_0024abb0();
        func_002535b0(3);
        func_00288658(2, 104);
        func_00288670(func_0024a150);
    case -4: case -2:
        func_00287da0();
        break;
    case -5: case -3: case -1:
        break;
    case 0: case 1: case 2:
        Tz__TRTE__SetupSel();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}
}  // namespace n0024a348

// .rodata words read by other code (retail bytes, in place)
namespace r00371e78 {
extern const u32 R_00371e78[1] asm("D_00371e78") __attribute__((aligned(4))) = { 0x3d003c };
}  // namespace r00371e78

// 0024a4d0 (was src/anon/batch_wcx2b.cpp)
namespace n0024a4d0 {
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(s32) asm("func_00289380");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00289310(s32) asm("func_00289310");
void func_0028abe0(s32) asm("func_0028abe0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 Tz__TRTE__GetSeqInfo(void) asm("Tz__TRTE__GetSeqInfo");
void func_002b4388(s32, const char*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_0028ab20(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287b08(s32) asm("func_00287b08");
void func_00287da0(void) asm("func_00287da0");
extern s32 D_0035ed70 asm("D_0035ed70");
extern s32 D_0035ed74 asm("D_0035ed74");
extern s32 D_0035ed90 asm("D_0035ed90");
extern char D_00371f30[] asm("D_00371f30");
extern char D_00371ee8[][36] asm("D_00371ee8");
extern s16 D_00371e78[] asm("D_00371e78");
/*TARGET 0024a4d0*/
void func_0024a4d0(void) asm("func_0024a4d0");
void func_0024a4d0(void) {
    s32 mode = func_00287cd0();
    s32 r = func_00289380(D_0035ed74);
    s32 v;
    if (mode == 2) {
        if (func_0028acc8(D_0035ed74)) {
            if (r == -1 && !func_00289310(D_0035ed74)) return;
            func_0028abe0(D_0035ed74);
            return;
        }
        v = func_002891e8(D_0035ed70);
        if (v == 1 && Tz__TRTE__GetSeqInfo()) {
            func_002b4388(D_0035ed90, D_00371f30, 0);
        } else {
            func_002b4388(D_0035ed90, D_00371ee8[v], 0);
        }
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310(D_0035ed74)) {
        if (!func_0028ae28(D_0035ed74, 0)) func_0028ab20(D_0035ed74);
    }
    if (mode == 0 && func_0028ae28(D_0035ed74, 0)) func_00287c90(1);
    func_00287df0(r, func_00289310(D_0035ed74), 0, 0, 1);
    switch (r) {
    case -4:
    case -3:
        break;
    case -2:
    case 1:
        func_0028aa40(D_0035ed74);
        func_00287c90(1);
        break;
    case 0: {
        s32 k = func_002891e8(D_0035ed70);
        if (k == 1 && Tz__TRTE__GetSeqInfo()) v = 62;
        else v = D_00371e78[k];
        func_00287b08(v);
        func_00287da0();
        break;
    }
    }
}
}  // namespace n0024a4d0

// 0024a710 (was src/anon/batch_w1579_g.cpp)
namespace n0024a710 {
struct Ta710 { s16 a; s16 b; s16 c; };
extern s32 D_0035ed70 asm("D_0035ed70");
extern s32 D_0035ed74 asm("D_0035ed74");
extern s32 D_0035ed78 asm("D_0035ed78");
extern s32 D_0035ed7c asm("D_0035ed7c");
extern s32 D_0035ed80 asm("D_0035ed80");
extern s32 D_0035ed84 asm("D_0035ed84");
extern s32 D_0035ed88 asm("D_0035ed88");
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
Ta710* func_0024b1a0(s32) asm("func_0024b1a0");
void func_0028dac8(s32, s32) asm("func_0028dac8");
void func_0028ce38(void) asm("func_0028ce38");
void func_0024ab00(void) asm("func_0024ab00");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, s32, s32, s32) asm("Tz__MenuCursor__Create");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_00287c50(void) asm("func_00287c50");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void func_0024a948(s32, s32, s32) asm("func_0024a948");
struct NoTaila710 { ~NoTaila710() {} };
/*TARGET 0024a710*/
void Tz__TRTE__Draw(void) asm("Tz__TRTE__Draw");
void Tz__TRTE__Draw(void) {
    NoTaila710 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ed78, 31);
            if (func_0028acc8(D_0035ed70) != 0 && func_00139d78(D_0035ed80) != 0) {
                func_0028dae0(D_0035ed80, func_0024b1a0(func_002891e8(D_0035ed70))->b);
            }
            func_0028dae0(D_0035ed7c, 34);
            if (func_0028acc8(D_0035ed70) != 0 && func_0028acb8(D_0035ed70) == 0) {
                func_0028aa40(D_0035ed70);
            }
            if (func_0028acc8(D_0035ed74) != 0 && func_0028acb8(D_0035ed74) == 0) {
                func_0028aa40(D_0035ed74);
            }
            func_0028dac8(D_0035ed84, 32);
            func_0028dac8(D_0035ed88, 40);
        }
        func_0028ce38();
    }
    func_0024ab00();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ed70 : D_0035ed74;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                Tz__MenuCursor__Create(side, 0, 0, D_0035ed78, 15, 14);
                Tz__MenuCursor__SetParent(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            Tz__MenuCursor__SetType(0, side);
        }
        func_0024a948(obj, mode, side);
    }
}
}  // namespace n0024a710

// 0024a948 (was src/anon/batch_w108.cpp)
namespace n0024a948 {
struct Msg24a { u8 data[36]; };
struct Ent24a { u16 f0; u16 f2; s16 id; };
extern u32 D_0035ed80 asm("D_0035ed80");
extern u32 D_0035ed90 asm("D_0035ed90");
extern Msg24a D_00371ee8[] asm("D_00371ee8");
extern Msg24a D_00371f30 asm("D_00371f30");
extern Msg24a D_00371f58[] asm("D_00371f58");
s32 func_00289310(void*) asm("func_00289310");
s32 func_002891e8(void*) asm("func_002891e8");
void func_002890e0(void*, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(void*, s32, s32, s32, s32, s32, s32) asm("func_00289038");
Ent24a* func_0024b1a0(s32) asm("func_0024b1a0");
void func_0023f070(u32, s32, s32) asm("func_0023f070");
void func_0024b0e8(void) asm("func_0024b0e8");
s32 func_0028d008(void*) asm("func_0028d008");
s32 func_002891d0(void*) asm("func_002891d0");
void Tz__MenuCursor__SetParent(void*, s32) asm("Tz__MenuCursor__SetParent");
// record408_set_and_refresh
s32 Tz__TRTE__GetSeqInfo(void) asm("Tz__TRTE__GetSeqInfo");
void func_002b4388(u32, void*, s32) asm("func_002b4388");
s32 func_001a6d08(s32) asm("func_001a6d08");
void func_00139858(s32) asm("func_00139858");
void func_001398d0(s32) asm("func_001398d0");
/*TARGET 0024a948*/
void func_0024a948(void* obj, s32 quiet, void* target) asm("func_0024a948");
void func_0024a948(void* obj, s32 quiet, void* target)
{
    s32 kind;

    if (!func_00289310(obj)) return;
    kind = func_002891e8(obj);
    func_002890e0(obj, 1, 2, 0, -1);
    func_00289038(obj, kind, 1, 1, 2, 0, -1);
    if (!quiet) {
        func_0023f070(D_0035ed80, func_0024b1a0(kind)->id, -1);
        func_0024b0e8();
    }
    if (func_0028d008(target)) {
        Tz__MenuCursor__SetParent(target, func_002891d0(obj));  // record408_set_and_refresh
    }
    if (!quiet) {
        if (kind == 1 && Tz__TRTE__GetSeqInfo()) {
            func_002b4388(D_0035ed90, &D_00371f30, 0);
        } else {
            func_002b4388(D_0035ed90, &D_00371ee8[kind], 0);
        }
    } else {
        func_002b4388(D_0035ed90, &D_00371f58[kind], 0);
    }
    if (!func_001a6d08(9)) return;
    if (Tz__TRTE__GetSeqInfo()) return;
    if (kind == 1) {
        func_00139858(100);
    } else {
        func_001398d0(100);
    }
}
}  // namespace n0024a948

// 0024ab00 (was src/anon/batch_w67.cpp)
namespace n0024ab00 {
// 001c8788: test-and-set of a flag bit
// 0x1c8788: moved to src/yasui/libys/summon.cpp

extern void* D_0035ed70 asm("D_0035ed70");
extern void* D_0035ed74 asm("D_0035ed74");
s32 func_002892f8(void*) asm("func_002892f8");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_00288e88(void*) asm("func_00288e88");
/*TARGET 0024ab00*/
// 0024ab00
void func_0024ab00(void) asm("func_0024ab00");
// 0024ab00
void func_0024ab00(void)
{
    if (D_0035ed70) {
        s32 a = func_002892f8(D_0035ed70);
        if (!func_0028acc8(D_0035ed70) && a) func_00288e88(D_0035ed70);
    }
    if (D_0035ed74) {
        s32 a = func_002892f8(D_0035ed74);
        if (!func_0028acc8(D_0035ed74) && a) func_00288e88(D_0035ed74);
    }
}
}  // namespace n0024ab00

// 0024abb0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024abb0 {
extern u32 D_0035ed70 asm("D_0035ed70");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 0024abb0*/
void func_0024abb0() asm("_Z13func_0024abb0v");
void func_0024abb0() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ed70);
    func_0023fc40(&v0, 4);
}
}  // namespace n0024abb0

// 0024abe8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024abe8 {
extern u32 D_0035ed70 asm("D_0035ed70");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void Tz__Select__SetCurrent(...) asm("Tz__Select__SetCurrent");
/*TARGET 0024abe8*/
void func_0024abe8() asm("_Z13func_0024abe8v");
void func_0024abe8() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        Tz__Select__SetCurrent(D_0035ed70, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n0024abe8

// 0024ac38 (was src/anon/tiny_auto80_queue.cpp)
namespace n0024ac38 {
extern u8  D_00371ee8 asm("D_00371ee8");
extern u8  D_00371f30 asm("D_00371f30");
u32 Tz__TRTE__GetSeqInfo(...) asm("Tz__TRTE__GetSeqInfo");
/*TARGET 0024ac38*/
u32 func_0024ac38(u32 a0) asm("_Z13func_0024ac38j");
u32 func_0024ac38(u32 a0) {
    u32 t6 = a0 * 36;
    u32 s0 = (u32)&D_00371ee8 + t6;
    if (a0 == 1) {
        if (Tz__TRTE__GetSeqInfo() != 0) {
            s0 = (u32)&D_00371f30;
        }
    }
    return s0;
}
}  // namespace n0024ac38

// 0024ac88 (was src/anon/batch_w1796.cpp)
namespace n0024ac88 {
struct S24_w1796 { u8 pad[28]; s8 a[4]; s8 b[4]; };
s32 func_001a6d08(s32) asm("func_001a6d08");
extern S24_w1796 D_00371f30 asm("D_00371f30");
/*TARGET 0024ac88*/
s32 Tz__TRTE__GetSeqInfo(void) asm("Tz__TRTE__GetSeqInfo");
s32 Tz__TRTE__GetSeqInfo(void) {
    s32 r = 1;
    s32 i;
    S24_w1796* d = &D_00371f30;
    s8* p = d->a;
    for (i = 0; i < 4; i++) {
        s32 c = *p++;
        if (c < 0) break;
        if (!func_001a6d08(c)) { r = 0; break; }
    }
    if (r) {
        for (i = 0; i < 4; i++) {
            s32 c = D_00371f30.b[i];
            if (c < 0) break;
            if (func_001a6d08(c)) { r = 0; break; }
        }
    }
    return r;
}
}  // namespace n0024ac88

// 0024ad50 (was src/anon/batch_w26.cpp)
namespace n0024ad50 {
// memcpy16
u8* minigame_get_score(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
s32 jiminy_is_full_open(void) asm("_ZN2Tz6Jiminy10isFullOpenEv");
/*TARGET 0024ad50*/
s32 func_0024ad50(void) asm("func_0024ad50");
s32 func_0024ad50(void) {
    s32 r = 0;
    if (*minigame_get_score(10) >= 2 || jiminy_is_full_open()) r = 1;
    return r;
}
}  // namespace n0024ad50

// 0024ada0 (was src/anon/batch_w97.cpp)
namespace n0024ada0 {
// 0x00245a90: definition moved into src/anon/unit_00242478.cpp

// ---- 0024ada0
struct Sub24a { u8 pad[184]; u32 flags; };
struct Win24a { u8 pad[24]; Sub24a sub; u8 pad2[405 - 24 - 188]; u8 f405; u8 pad406[2]; u8* f408; u8 pad412[20]; u32 f432; };
union WinPtr24a { Win24a* p; u32 u; u8 b; };
extern WinPtr24a D_0035ed88 asm("D_0035ed88");
extern u32 D_0035ed78 asm("D_0035ed78");
union BufPtr24a { u8* p; u32 u; };
extern BufPtr24a D_0035ed98 asm("D_0035ed98");
extern u32 D_0035ed70 asm("D_0035ed70");
extern char D_00371e98[] asm("D_00371e98");
s32 func_001a6d08(s32) asm("func_001a6d08");
void func_0028d980(Win24a*, s32, s32, s32, u32, s32, s32, s32, s32) asm("func_0028d980");
void func_00139620(Win24a*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
void func_002fde18(u8*, s32, s32) asm("func_002fde18");
u8* func_001d56c8(s32) asm("func_001d56c8");
u32 func_00192cc0(u8*, char*, u32) asm("func_00192cc0");
s32 func_00192b30(u32) asm("func_00192b30");
u32 func_00192048(u32) asm("func_00192048");
void func_00192c90(u32, u8*) asm("func_00192c90");
s32 func_002891e8(u32) asm("func_002891e8");
void func_001398d0(s32) asm("func_001398d0");
/*TARGET 0024ada0*/
void Tz__TRTE__CreateScore(void) asm("Tz__TRTE__CreateScore");
void Tz__TRTE__CreateScore(void) {
    if (!func_001a6d08(9)) return;
    func_0028d980(D_0035ed88.p, 30011, 0, 0, D_0035ed78, 39, 41, -1, 100);
    func_00139620(D_0035ed88.p);
    func_001395f8((u8*)D_0035ed88.p);
    D_0035ed88.p->f432 = 2;
    D_0035ed88.p->f405 = 1;
    Sub24a* sb = &D_0035ed88.p->sub;
    sb->flags |= 8;
    func_002fde18(D_0035ed98.p, 0, 32);
    D_0035ed88.p->f408 = D_0035ed98.p;
    u8* buf = D_0035ed98.p;
    u8* v = func_001d56c8(10);
    if (v[0] != 3) {
        func_00192c90(func_00192048(0xcb9b), buf);
    } else {
        s32 n = func_00192b30(func_00192cc0(buf, D_00371e98, *(u32*)(v + 4)));
        func_00192c90(func_00192048(0xcb98), buf + n);
    }
    if (func_002891e8(D_0035ed70)) return;
    func_001398d0(100);
}
}  // namespace n0024ada0

// 0024aef0 (was src/anon/batch_wcx2.cpp)
namespace n0024aef0 {
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
// 0x001d7218: definition moved into src/anon/unit_001d68e0.cpp

extern s8 D_0035ed9c asm("D_0035ed9c");
extern u8* D_0035ed8c asm("D_0035ed8c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ed70 asm("D_0035ed70");
extern u32 D_0035ed78 asm("D_0035ed78");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028afa8(u32) asm("func_0028afa8");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028d8c0__93727(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__93727(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_0024b0e8(void) asm("func_0024b0e8");
/*TARGET 0024aef0*/
void Tz__TRTE__CreateNewMark(void) asm("Tz__TRTE__CreateNewMark");
void Tz__TRTE__CreateNewMark(void)
{
    if (!D_0035ed9c) return;
    if (func_00139d78(D_0035ed8c)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed70);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035ed70, i);
        u8* a = o + 24;
        if ((u8)((D_0035ed9c >> i) & 1)) {
            func_0028d8c0__93727(D_0035ed8c + i * 408, id, 0, 0, D_0035ed78, 38, -1, 0);
            func_0028dcc0__93727(D_0035ed8c + i * 408, o);
            func_00139648(D_0035ed8c + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ed8c + i * 408, x, func_0023aa38(a));
        }
    }
    func_0024b0e8();
}
}  // namespace n0024aef0

// 0024b078 (was src/anon/batch_w44.cpp)
namespace n0024b078 {
typedef void (*VFn)(void*);
s32 func_00139d78(void*) asm("func_00139d78");
// 0x002431d0: definition moved into src/anon/unit_00242478.cpp

extern u8* D_0035ed8c asm("D_0035ed8c");
/*TARGET 0024b078*/
void func_0024b078(void) asm("func_0024b078");
void func_0024b078(void) {
    for (s32 i = 0; i < 2; i++) {
        if (func_00139d78(D_0035ed8c + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ed8c);
            (*(VFn*)(*(u8**)o + 20))(o);
        }
    }
}
}  // namespace n0024b078

// 0024b0e8 (was src/anon/batch_wcx.cpp)
namespace n0024b0e8 {
extern u8* D_0035ed70 asm("D_0035ed70");
extern s8 D_0035ed9c asm("D_0035ed9c");
extern u8* D_0035ed8c asm("D_0035ed8c");
s32 func_002891e8(u8*) asm("func_002891e8");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 0024b0e8*/
void func_0024b0e8(void) asm("func_0024b0e8");
void func_0024b0e8(void)
{
    s32 i = func_002891e8(D_0035ed70);
    if (!((D_0035ed9c >> i) & 1)) return;
    if (u_call4_00139d78(D_0035ed8c + i * 408)) {
        u8* o = D_0035ed8c + i * 408;
        if (*(s32*)(o + 388) != 37) func_00138c10(o, 37);
    }
    func_00243230(2, i);
}
}  // namespace n0024b0e8

// 0024b1a0 (was src/anon/batch_w34.cpp)
namespace n0024b1a0 {
s32 Tz__TRTE__GetSeqInfo(void) asm("Tz__TRTE__GetSeqInfo");
extern u8 D_00371eb8[] asm("D_00371eb8");
struct Entry6 { u8 b[6]; };
extern Entry6 D_00371ea8[] asm("D_00371ea8");
/*TARGET 0024b1a0*/
// 0x00242d10: definition moved into src/anon/unit_00242478.cpp

void* func_0024b1a0(s32 n) asm("func_0024b1a0");
// 0x00242d10: definition moved into src/anon/unit_00242478.cpp

void* func_0024b1a0(s32 n) {
    if (n == 1 && Tz__TRTE__GetSeqInfo()) return D_00371eb8;
    return &D_00371ea8[n];
}
}  // namespace n0024b1a0

// 0024b1f8 (was unwritten gap)
namespace n0024b1f8 {
s32 func_0024b1f8(s32 a) asm("func_0024b1f8");
s32 func_0024b1f8(s32 a) {
    if (a < 0) return 1;
    return (u32)a < 2;
}
}  // namespace n0024b1f8

// 0024b210 (was src/anon/batch_w1925_nsa.cpp)
namespace n0024b210 {
/* Tz__HBTE__Init */
struct W1925_Al { virtual void* alloc(u32, void*); };
}  // namespace n0024b210
inline void* operator new[](unsigned int sz, n0024b210::W1925_Al* a) { return a->alloc(sz, 0); }
namespace n0024b210 {
void func_00239700(void*) asm("func_00239700");
extern u8 D_00347e60 asm("D_00347e60");
struct W1925_T {
    u32 vt; u8 p4[8]; u32 f12; u8 p16[8]; u8 sub[384];
    W1925_T() { f12 = 0; vt = (u32)&D_00347e60; func_00239700(sub); }
    ~W1925_T();
};
void func_00287b18(s32, s32) asm("func_00287b18");
void* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
void func_00288f48(void*, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(void*) asm("func_002b3df8");
void func_0028d068(s32, s32) asm("func_0028d068");
u8* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(u32, s32, s32, void*, s32) asm("TASK_MANAGER__create_thread");
void func_0024b510(void) asm("func_0024b510");
typedef void* (*AllocFn)(void*, u32, void*);
extern void** D_0032ba14 asm("D_0032ba14");
extern u8* D_00347f80 asm("D_00347f80");
extern void* D_0035eda8 asm("D_0035eda8");
extern void* D_0035edac asm("D_0035edac");
extern "C" s32 D_0035edb0;
extern "C" s32 D_0035edb4;
extern "C" s32 D_0035edb8;
extern W1925_T* D_0035edbc asm("D_0035edbc");
extern void* D_0035edc0 asm("D_0035edc0");
extern "C" u8 D_0035edc4;
extern "C" u8 D_0035edc5;
/*TARGET 0024b210*/
void Tz__HBTE__Init(void) asm("Tz__HBTE__Init");
void Tz__HBTE__Init(void) {
    void* o;
    func_00287b18(3, 3);
    o = func_00288be8(56);
    func_002889f0(o, 3, 1);
    D_0035eda8 = o;
    o = func_00288be8(56);
    func_002889f0(o, 2, 0);
    D_0035edac = o;
    func_00288f48(o, 64, 128, 0, 0);
    D_0035edb0 = 0;
    D_0035edb4 = 0;
    D_0035edb8 = 0;
    o = (**(AllocFn**)D_0032ba14)(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(o);
    D_0035edc0 = o;
    D_0035edc4 = 0;
    D_0035edbc = new (*(W1925_Al**)(D_00347f80 + 20)) W1925_T[3];
    D_0035edc5 = 0;
    func_0028d068(30026, -1);
    TASK_MANAGER__create_thread(*(u32*)(func_00103eb0() + 4), 0, 2000, (void*)func_0024b510, 4096);
}
}  // namespace n0024b210

// 0024b3a0 (was src/anon/batch_wcx2.cpp)
namespace n0024b3a0 {
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
// 0x00247e80: definition moved into src/anon/unit_00242478.cpp

// --------------------

// --------------------

// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj0024b3a0 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj0024b3a0*); void (*del)(VObj0024b3a0*); }* vt; };
struct Panel0024b3a0 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel0024b3a0*); }* vt; u8 pad[404]; };
struct Alloc0024b3a0 { struct { void* f0; void (*free)(Alloc0024b3a0*, void*); }* vt; };
struct Heap0024b3a0 { u8 pad[20]; Alloc0024b3a0* a; };
extern void* D_0035eda8_x15319 asm("D_0035eda8");
extern void* D_0035edac asm("D_0035edac");
extern VObj0024b3a0* D_0035edb0_x15321 asm("D_0035edb0");
extern VObj0024b3a0* D_0035edb4 asm("D_0035edb4");
extern VObj0024b3a0* D_0035edb8 asm("D_0035edb8");
extern void* D_0035edc0 asm("D_0035edc0");
extern Panel0024b3a0* D_0035edbc_x15325 asm("D_0035edbc");
extern Alloc0024b3a0* D_0032ba14_x15326 asm("D_0032ba14");
extern Heap0024b3a0* D_00347f80_x15327 asm("D_00347f80");
void func_00288b00(void* w) asm("func_00288b00");
void func_00288c20(void* w) asm("func_00288c20");
void func_002b3fb0(void* o) asm("func_002b3fb0");
/*TARGET 0024b3a0*/
void func_0024b3a0(void) asm("func_0024b3a0");
void func_0024b3a0(void)
{
    void* w;
    if ((w = D_0035eda8_x15319) != 0) { func_00288b00(w); func_00288c20(w); D_0035eda8_x15319 = 0; }
    if ((w = D_0035edac) != 0) { func_00288b00(w); func_00288c20(w); D_0035edac = 0; }
    if (D_0035edb0_x15321) { D_0035edb0_x15321->vt->del(D_0035edb0_x15321); D_0035edb0_x15321 = 0; }
    if (D_0035edb4) { D_0035edb4->vt->del(D_0035edb4); D_0035edb4 = 0; }
    if (D_0035edb8) { D_0035edb8->vt->del(D_0035edb8); D_0035edb8 = 0; }
    if ((w = D_0035edc0) != 0) { func_002b3fb0(w); D_0032ba14_x15326->vt->free(D_0032ba14_x15326, w); D_0035edc0 = 0; }
    if (D_0035edbc_x15325) {
        Panel0024b3a0* e = D_0035edbc_x15325 + ((s32*)D_0035edbc_x15325)[-1];
        Panel0024b3a0* q;
        for (;;) {
            q = D_0035edbc_x15325;
            if (q == e) break;
            e--;
            e->vt->dtor(e);
        }
        D_00347f80_x15327->a->vt->free(D_00347f80_x15327->a, (s32*)q - 1);
        D_0035edbc_x15325 = 0;
    }
}
}  // namespace n0024b3a0

// 0024b510 (was src/tozawa/smenu_hb.cpp)
namespace Tz { // method 0024b510
extern u32 D_0035eda4 asm("D_0035eda4");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void Tz__HBTE__Setup() asm("Tz__HBTE__Setup");
void func_00242678(u32) asm("func_00242678");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
extern "C" u32 func_0024bd90() asm("func_0024bd90");
void Tz__HBTE__Draw() asm("Tz__HBTE__Draw");
/*TARGET 0024b510*/
void HBTE::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035eda4);
    func_00102448(s0, 1);
    Tz__HBTE__Setup();
    func_00242678(5014);
    while (1) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (func_0024bd90() != 0) {
            return;
        }
        Tz__HBTE__Draw();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 0024b588 (was src/anon/batch_w3882_mam.s)
namespace n0024b588 {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; u8 flag; u16 f12; u8 pad14[8]; s8 req[4]; u8 pad32[4]; };
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(u8*) asm("YI__LAYOUT__LAYOUT");
void Tz__MenuUtil__CreateLay(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8*) asm("Tz__Layout__SetImageCache");
s32 Tz__SubMenu__isSetNew(s32, s32) asm("Tz__SubMenu__isSetNew");
void Tz__Select__SetItem(void*, s32, s32, s32, u8*, s32, u8*, u8*) asm("Tz__Select__SetItem");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0028dd90(s32) asm("func_0028dd90");
s32 func_0028ddd8(s32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void func_00139570(u8*) asm("func_00139570");
s32 func_002892f8(void*) asm("func_002892f8");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
s32 func_002891e8(void*) asm("func_002891e8");
void func_002b4070(void*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32) asm("func_002b4070");
void func_0024c650(void) asm("func_0024c650");
void Tz__HBTE__LoopAll(void) asm("Tz__HBTE__LoopAll");
void func_0024bd80(void) asm("func_0024bd80");
s32 func_001a6d08(s32) asm("func_001a6d08");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002887c8(void) asm("func_002887c8");
void func_00288750(void (*)(void)) asm("func_00288750");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);
    YI__LAYOUT__LAYOUT(o + 48);
    return o;
}
extern "C" u8 D_0035edc4;
extern "C" u8 D_0035edc5;
extern u8* D_0035edb0 asm("D_0035edb0");
extern u8* D_0035edb4 asm("D_0035edb4");
extern u8* D_0035edb8 asm("D_0035edb8");
extern u8* D_0035edc0 asm("D_0035edc0");
extern void* D_0035eda8 asm("D_0035eda8");
extern Ent36 D_00372030[] asm("D_00372030");
extern s16 D_00371ff0[][3] asm("D_00371ff0");
extern "C" u8 D_00371fe8[];
extern "C" u8 D_00372008[];
extern "C" u8 D_00372010[];
extern "C" u8 D_00372018[];
extern "C" u8 D_00372020[];
extern "C" u8 D_00372028[];
void Tz__HBTE__Setup(void) asm("Tz__HBTE__Setup");
void Tz__HBTE__Setup(void) {
    s32 i, j, ok;
    s32 sel;
    s32 n, w, half;
    u8* o;
    sel = 0;
    D_0035edc4 = 0;
    D_0035edb0 = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035edb0, 30002, 0, 0, 30, 32, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035edb0);
    for (i = 0; i < 3; i++) {
        o = 0;
        ok = 1;
        for (j = 0; j < 4; j++) {
            s32 t = D_00372030[i].req[j];
            if (t < 0) break;
            if (!func_001a6d08(t)) { ok = 0; break; }
        }
        if (ok) {
            if (Tz__SubMenu__isSetNew(7, i) == 0) D_0035edc5 |= 1 << i;
            if (D_00372030[i].f10) sel = i;
            Tz__Select__SetItem(D_0035eda8, i, 0, 0, D_0035edb0, D_00372030[i].f12, (u8*)&D_00372030[i], D_00372030[i].name);
            o = func_002891b8(D_0035eda8, i);
            s32 p = func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90(p);
            *(s32*)(o + 428) = func_0028ddd8(p);
            func_001395f8(o);
        }
        if (!(D_00372030[i].flag&1)) func_00139570(o);
    }
    i = 0;
    n = func_002892f8(D_0035eda8);
    o = func_002891b8(D_0035eda8, 0);
    w = func_0023aa78(o + 24);
    half = (w * n) / 2;
    for (; i < n; i++) {
        o = func_002891b8(D_0035eda8, i);
        func_00138c68(o, 0, -half + w * i);
    }
    Tz__Select__SetCurrent(D_0035eda8, sel, 0, -1, -1);
    func_0024c650();
    sel = func_002891e8(D_0035eda8);
    o = func_002891b8(D_0035eda8, sel);
    Tz__Select__SetCurrent(D_0035eda8, sel, 1, 0, 2);
    func_002b4070(D_0035edc0, 30003, D_0035edb0, D_00371fe8, D_00372008, D_00372010, D_00372018, D_00372020, D_00372028, 2985, &D_00372030[sel], 0, 0);
    D_0035edb8 = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035edb8, 30002, 0, 0, D_00371ff0[sel][0], D_00371ff0[sel][2], 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035edb8);
    D_0035edb4 = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035edb4, 30019, 0, 0, 33, 35, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035edb4);
    func_00287bd0(0, 0);
    func_00287cc0(0);
    if (func_002887c8()) {
        Tz__HBTE__LoopAll();
        D_0035edc4 = 1;
        func_00288750(func_0024bd80);
    }
}
}
