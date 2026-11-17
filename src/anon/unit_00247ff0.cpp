// Linked unit 0x00247ff0-0x002499b8.
#include "../tozawa/smenu_mu.hpp"
#include "../common/types.h"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/smenu_tr.hpp"

// 00247ff0 (was src/tozawa/smenu_mu.cpp)
namespace Tz { // method 00247ff0
extern u32 D_0035ed48 asm("D_0035ed48");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void func_00248060() asm("func_00248060");
void func_00236d60() asm("func_00236d60");
// clear_64_entries_24
extern "C" u32 func_00248900() asm("func_00248900");
void func_00248d28() asm("func_00248d28");
/*TARGET 00247ff0*/
void MUMI::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ed48);
    func_00102448(s0, 1);
    func_00248060();
    while (1) {
        func_00236d60();  // clear_64_entries_24
        if (func_00248900() != 0) {
            return;
        }
        func_00248d28();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 00248060 (was src/anon/batch_w3784_mam.cpp)
namespace n00248060 {
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; u8 pad11; u16 f12; u8 pad14[8]; s8 req[4]; u8 pad32[4]; };
struct VObj { struct VT { u8 pad[24]; void (*f18)(VObj*, s32, u32, s32, s32, s32, s32); }* vt; };
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void func_002369a0(u8*) asm("func_002369a0");
void func_0023c008(u8*) asm("func_0023c008");
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d7f0");
void func_0023ef50(u8*) asm("func_0023ef50");
s32 func_002431d0(s32, s32) asm("func_002431d0");
void func_00288d80(void*, s32, s32, s32, u8*, s32, u8*, u8*) asm("func_00288d80");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0028dd90(s32) asm("func_0028dd90");
s32 func_0028ddd8(s32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
s32 func_002892f8(void*) asm("func_002892f8");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_002891f0(void*, s32, s32, s32, s32) asm("func_002891f0");
s32 func_002891e8(void*) asm("func_002891e8");
void func_002b4070(void*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32) asm("func_002b4070");
s32 func_00249480(s32) asm("func_00249480");
void func_00249180(void) asm("func_00249180");
void func_00248720(void) asm("func_00248720");
s32 func_001a6d08(s32) asm("func_001a6d08");
VObj* func_00287dc0(void) asm("func_00287dc0");
void func_0023d808(VObj*, s32) asm("func_0023d808");
void func_0023e858(VObj*, s32, f32) asm("func_0023e858");
void func_0023e8b8(VObj*, s32, f32) asm("func_0023e8b8");
void func_0023e8d8(VObj*, s32, f32) asm("func_0023e8d8");
s32 func_00139d78(s32) asm("func_00139d78");
void func_0023e9b0(VObj*, s32, s32) asm("func_0023e9b0");
void func_0023e690(VObj*, s32, s32, s32) asm("func_0023e690");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002887c8(void) asm("func_002887c8");
void func_002488f0(void) asm("func_002488f0");
void func_00288750(void (*)(void)) asm("func_00288750");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);
    func_0023c008(o + 48);
    return o;
}
extern "C" u8 D_0035ed68;
extern "C" u8 D_0035ed69;
extern u8* D_0035ed54 asm("D_0035ed54");
extern u8* D_0035ed58 asm("D_0035ed58");
extern u8* D_0035ed5c asm("D_0035ed5c");
extern u8* D_0035ed60 asm("D_0035ed60");
extern void* D_0035ed4c asm("D_0035ed4c");
extern Ent36 D_00371d90[] asm("D_00371d90");
extern u8 D_00371d80[] asm("D_00371d80");
extern s16 D_00371d40[][3] asm("D_00371d40");
extern "C" u8 D_00371d38[];
extern "C" u8 D_00371d58[];
extern "C" u8 D_00371d60[];
extern "C" u8 D_00371d68[];
extern "C" u8 D_00371d70[];
extern "C" u8 D_00371d78[];
/*TARGET 00248060*/
void func_00248060(void) asm("func_00248060");
void func_00248060(void) {
    s32 i, j, ok;
    s32 sel;
    s32 n, w, half;
    u8* o;
    u8* nm;
    u8* nm2;
    VObj* p;
    sel = 0;
    D_0035ed68 = 0;
    D_0035ed54 = NewLayout();
    func_0028d7f0(D_0035ed54, 30002, 0, 0, 30, 32, 0, 0, 0);
    func_0023ef50(D_0035ed54);
    for (i = 0; i < 3; i++) {
        Ent36* e = &D_00371d90[i];
        s8* r;
        ok = 1;
        for (j = 0, r = e->req; j < 4; j++) {
            s32 t = *r++;
            if (t < 0) break;
            if (!func_001a6d08(t)) { ok = 0; break; }
        }
        if (ok) {
            if (func_002431d0(5, i) == 0) D_0035ed69 |= 1 << i;
            if (D_00371d90[i].f10) sel = i;
            nm = (u8*)&D_00371d90[i];
            nm2 = D_00371d90[i].name;
            if (func_00249480(i) == 0) {
                nm = D_00371d80;
                nm2 = D_00371d80 + 8;
            }
            func_00288d80(D_0035ed4c, i, 0, 0, D_0035ed54, D_00371d90[i].f12, nm, nm2);
            o = func_002891b8(D_0035ed4c, i);
            p = (VObj*)func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90((s32)p);
            *(s32*)(o + 428) = func_0028ddd8((s32)p);
            func_001395f8(o);
        }
    }
    i = 0;
    n = func_002892f8(D_0035ed4c);
    w = func_0023aa78(func_002891b8(D_0035ed4c, 0) + 24);
    half = (w * n) / 2;
    for (; i < n; i++) {
        func_00138c68(func_002891b8(D_0035ed4c, i), 0, -half + w * i);
    }
    func_002891f0(D_0035ed4c, sel, 0, -1, -1);
    func_00249180();
    sel = func_002891e8(D_0035ed4c);
    func_002891f0(D_0035ed4c, sel, 1, 0, 2);
    func_002b4070(D_0035ed60, 30003, D_0035ed54, D_00371d38, D_00371d58, D_00371d60, D_00371d68, D_00371d70, D_00371d78, 4585, &D_00371d90[sel], 0, 0);
    D_0035ed5c = NewLayout();
    func_0028d7f0(D_0035ed5c, 30002, 0, 0, D_00371d40[sel][0], D_00371d40[sel][2], 0, 0, 0);
    func_0023ef50(D_0035ed5c);
    D_0035ed58 = NewLayout();
    func_0028d7f0(D_0035ed58, 30019, 0, 0, 33, 35, 0, 0, 0);
    func_0023ef50(D_0035ed58);
    p = func_00287dc0();
    func_0023d808(p, 30008);
    p->vt->f18(p, 0, 0x2000043f, 134, 2, 184, 441);
    func_0023e858(p, 0, -345.0f);
    func_0023e8b8(p, 0, 8.0f);
    func_0023e8d8(p, 0, 32.0f);
    {
        u8* s = D_0035ed60;
        func_00139d78(*(s32*)(s + 8));
        s32 x = *(s32*)(s + 8);
        func_0023e9b0(p, 0, x);
    }
    func_0023e690(p, 0, 135, 136);
    func_00287bd0(0, 0);
    func_00287cc0(0);
    if (func_002887c8()) {
        func_00248720();
        D_0035ed68 = 1;
        func_00288750(func_002488f0);
    }
}
}  // namespace n00248060

// 002485c8 (was src/anon/batch_w98.cpp)
namespace n002485c8 {
u8* func_002891b8(u8*, s32) asm("func_002891b8");
// 0x002633a8: definition moved into src/anon/unit_002632d0.cpp

struct E248 { u8 pad[8]; u8 name[8]; s8 on; u8 pad2; u16 id; u8 pad3[16]; };
extern E248 D_00371e00[] asm("D_00371e00");
extern u8* D_0035ed50 asm("D_0035ed50");
extern u32 D_0035ed54 asm("D_0035ed54");
extern u32 D_0035ed60 asm("D_0035ed60");
void func_00288d80(u8*, s32, s32, s32, u32, u16, E248*, u8*) asm("func_00288d80");
u32 func_0023aa78(u8*) asm("func_0023aa78");
u32 func_0023aa98(u8*) asm("func_0023aa98");
void func_00288e08(u8*, s32, u32, s32) asm("func_00288e08");
u32 func_0028dd90(u32) asm("func_0028dd90");
// mod10_classify_012
u32 func_0028ddd8(u32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void func_002891f0(u8*, s32, s32, s32, s32) asm("func_002891f0");
void func_002b4388(u32, E248*, s32) asm("func_002b4388");
/*TARGET 002485c8*/
// Builds the two-entry selection list and focuses the active entry.
void func_002485c8(void) asm("func_002485c8");
// Builds the two-entry selection list and focuses the active entry.
void func_002485c8(void) {
    s32 sel = 0;
    for (s32 i = 0; i < 2; i++) {
        if (D_00371e00[i].on) sel = i;
        func_00288d80(D_0035ed50, i, 0, 0, D_0035ed54, D_00371e00[i].id, &D_00371e00[i], D_00371e00[i].name);
        u8* w = func_002891b8(D_0035ed50, i);
        func_00288e08(D_0035ed50, i, func_0023aa78(w + 24), 0);
        u32 x = func_0023aa98(w + 24);
        *(u32*)(w + 432) = func_0028dd90(x);
        *(u32*)(w + 428) = func_0028ddd8(x);
        func_001395f8(w);
    }
    func_002891f0(D_0035ed50, sel, 1, 0, 2);
    func_002b4388(D_0035ed60, &D_00371e00[sel], 0);
}
}  // namespace n002485c8

// 00248720 (was src/anon/batch_w85.cpp)
namespace n00248720 {
extern void* D_0035ed54 asm("D_0035ed54");
extern void* D_0035ed4c asm("D_0035ed4c");
extern void* D_0035ed5c asm("D_0035ed5c");
extern void* D_0035ed58 asm("D_0035ed58");
struct Pair248 { s16 a, b, c; };
extern Pair248 D_00371d40[] asm("D_00371d40");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028ab20(void*) asm("func_0028ab20");
s32 func_002891e8(void*) asm("func_002891e8");
/*TARGET 00248720*/
void func_00248720(void) asm("func_00248720");
void func_00248720(void) {
    if (func_00139d78(D_0035ed54) && func_0023f0c0(D_0035ed54) != 32)
        func_0023f070(D_0035ed54, 32, -1);
    if (func_0028acc8(D_0035ed4c)) {
        s32 v;
        func_0028ab20(D_0035ed4c);
        v = func_002891e8(D_0035ed4c);
        if (func_00139d78(D_0035ed5c) && func_0023f0c0(D_0035ed5c) != D_00371d40[v].c)
            func_0023f070(D_0035ed5c, D_00371d40[v].c, -1);
    }
    if (func_00139d78(D_0035ed58) && func_0023f0c0(D_0035ed58) != 35)
        func_0023f070(D_0035ed58, 35, -1);
}
}  // namespace n00248720

// 00248828 (was src/anon/batch_w81.cpp)
namespace n00248828 {
typedef void (*VFnV81)(...);
struct VObjV81 { VFnV81* vt; };
// 00229728: moved to src/sasa/musical_score.cpp (linked unit)

// --- 00248828
extern VObjV81* D_0035ed54 asm("D_0035ed54");
extern VObjV81* D_0035ed5c asm("D_0035ed5c");
extern VObjV81* D_0035ed58 asm("D_0035ed58");
extern u32 D_0035ed4c asm("D_0035ed4c");
extern u32 D_0035ed50 asm("D_0035ed50");
s32 func_00139d78(u32) asm("func_00139d78");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
void func_00249358(void) asm("func_00249358");
void func_0028ce38(void) asm("func_0028ce38");
/*TARGET 00248828*/
void func_00248828(void) asm("func_00248828");
void func_00248828(void) {
    if (func_00139d78((u32)D_0035ed54)) D_0035ed54->vt[5](D_0035ed54);
    if (func_00139d78((u32)D_0035ed5c)) D_0035ed5c->vt[5](D_0035ed5c);
    if (func_00139d78((u32)D_0035ed58)) D_0035ed58->vt[5](D_0035ed58);
    if (func_0028acc8(D_0035ed4c)) func_0028abe0(D_0035ed4c);
    if (func_0028acc8(D_0035ed50)) func_0028abe0(D_0035ed50);
    func_00249358();
    func_0028ce38();
}
}  // namespace n00248828

// 002488f0 (was unwritten gap: pause callback)
namespace n002488f0 {
extern u8 D_0035ed68 asm("D_0035ed68");
void func_002488f0(void) asm("func_002488f0");
void func_002488f0(void) { D_0035ed68 = 0; }
}  // namespace n002488f0

// 00248900 (was src/anon/batch_w90.cpp)
namespace n00248900 {
// 00248900
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287d68(void) asm("func_00287d68");
// copy_globals_3words
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_001039f8(void) asm("func_001039f8");
void func_00248b38(void) asm("func_00248b38");
void func_002489d8(void) asm("func_002489d8");
extern void* D_0035ed4c asm("D_0035ed4c");
extern void* D_0035ed50 asm("D_0035ed50");
extern void* D_0035ed54 asm("D_0035ed54");
extern void* D_0035ed58 asm("D_0035ed58");
extern void* D_0035ed5c asm("D_0035ed5c");
/*TARGET 00248900*/
s32 func_00248900(void) asm("func_00248900");
s32 func_00248900(void)
{
    s32 m = func_00287bc0();
    func_00287d68();  // copy_globals_3words
    if (func_00287db0()) {
        if (func_0028acc8(D_0035ed4c) || func_0028acc8(D_0035ed50) || func_00139d78(D_0035ed54)
            || func_00139d78(D_0035ed58) || func_00139d78(D_0035ed5c)) return 0;
        func_001039f8();
        return 1;
    }
    switch (m) {
    case 0: func_002489d8(); break;
    case 1: func_00248b38(); break;
    }
    return 0;
}
}  // namespace n00248900

// 002489d8 (was src/anon/batch_wcx2.cpp)
namespace n002489d8 {
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
// 0x00244148: definition moved into src/anon/unit_00242478.cpp

// --------------------
extern u32 D_0035ed4c asm("D_0035ed4c");
extern u8 D_0035ed68 asm("D_0035ed68");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x8715(s32) asm("func_00289380");
s32 func_00289310_x8716(s32) asm("func_00289310");
s32 func_0028ae28_x8717(s32, s32) asm("func_0028ae28");
void func_00248720() asm("func_00248720");
void func_00287c90(s32) asm("func_00287c90");
void func_002491d0() asm("func_002491d0");
void func_00249480() asm("func_00249480");
s32 func_00287df0_b(s32, s32, s32, void (*)(), s32) asm("func_00287df0");
void func_00287da0() asm("func_00287da0");
s32 func_002427d8(s32) asm("func_002427d8");
void func_002485c8() asm("func_002485c8");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 002489d8*/
void func_002489d8() asm("func_002489d8");
void func_002489d8() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8715(D_0035ed4c);
    if (D_0035ed68) return;
    if (r != -1 || func_00289310_x8716(D_0035ed4c)) {
        if (!func_0028ae28_x8717(D_0035ed4c, 0)) func_00248720();
    }
    if (!a && func_0028ae28_x8717(D_0035ed4c, 0)) {
        func_00287c90(1);
        func_002491d0();
    }
    s32 k = func_00287df0_b(r, func_00289310_x8716(D_0035ed4c), 1, func_00249480, 1);
    switch (r) {
    case -3: case -1:
        break;
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1: case 2: case 3: case 4:
        if (func_002427d8(k)) {
            func_002485c8();
            func_00287bd0(1, 0);
            func_00287cc0(0);
        }
        break;
    }
}
}  // namespace n002489d8

// .rodata words read by other code (retail bytes, in place)
namespace r00371d14 {
extern const u32 R_00371d14[1] asm("D_00371d14") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00371d18[2] asm("D_00371d18") __attribute__((aligned(4))) = { 0x30002f, 0x31 };
}  // namespace r00371d14

// 00248b38 (was src/anon/batch_w1604.cpp)
namespace n00248b38 {
struct E36 { u8 b[36]; };
extern s32 D_0035ed4c asm("D_0035ed4c");
extern s32 D_0035ed50 asm("D_0035ed50");
extern s32 D_0035ed60 asm("D_0035ed60");
extern E36 D_00371d90[] asm("D_00371d90");
extern s16 D_00371d18[] asm("D_00371d18");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(s32) asm("func_00289380");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00289310(s32) asm("func_00289310");
void func_0028abe0(s32) asm("func_0028abe0");
s32 func_002891e8(s32) asm("func_002891e8");
void func_002b4388(s32, E36*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28(s32, s32) asm("func_0028ae28");
void func_0028ab20(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_00287b08(s32) asm("func_00287b08");
void func_00287da0(void) asm("func_00287da0");
/*TARGET 00248b38*/
void func_00248b38(void) asm("func_00248b38");
void func_00248b38(void)
{
    s32 mode = func_00287cd0();
    s32 r = func_00289380(D_0035ed50);
    if (mode == 2) {
        if (func_0028acc8(D_0035ed50)) {
            if (r != -1 || func_00289310(D_0035ed50)) func_0028abe0(D_0035ed50);
        } else {
            func_002b4388(D_0035ed60, &D_00371d90[func_002891e8(D_0035ed4c)], 0);
            func_00287bd0(0, 0);
            func_00287cc0(1);
        }
    } else {
        if ((r != -1 || func_00289310(D_0035ed50)) && !func_0028ae28(D_0035ed50, 0))
            func_0028ab20(D_0035ed50);
        if (mode == 0 && func_0028ae28(D_0035ed50, 0)) func_00287c90(1);
        func_00287df0(r, func_00289310(D_0035ed50), 0, 0, 1);
        switch (r) {
        case -4:
        case -3:
        case -1:
            break;
        case -2:
        case 1:
            func_0028aa40(D_0035ed50);
            func_00287c90(1);
            break;
        case 0:
            func_00287b08(D_00371d18[func_002891e8(D_0035ed4c)]);
            func_00287da0();
            break;
        }
    }
}
}  // namespace n00248b38

// 00248d28 (was src/anon/batch_w1579_g.cpp)
namespace n00248d28 {
// 0x00245dd0: definition moved into src/anon/unit_00242478.cpp
struct T1d40 { s16 a; s16 b; s16 c; };
extern T1d40 D_00371d40[] asm("D_00371d40");
extern s32 D_0035ed4c asm("D_0035ed4c");
extern s32 D_0035ed50 asm("D_0035ed50");
extern s32 D_0035ed54 asm("D_0035ed54");
extern s32 D_0035ed58 asm("D_0035ed58");
extern s32 D_0035ed5c asm("D_0035ed5c");
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
void func_00249358(void) asm("func_00249358");
void func_00249098(void) asm("func_00249098");
s32 func_0028d008(s32) asm("func_0028d008");
void func_0028cc78(s32, s32, s32, s32, s32, s32) asm("func_0028cc78");
s32 func_002891d0(s32) asm("func_002891d0");
void func_0028cf28(s32, s32) asm("func_0028cf28");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_00287c50(void) asm("func_00287c50");
void func_0028ce98(s32, s32) asm("func_0028ce98");
void func_00248f50(s32, s32, s32) asm("func_00248f50");
struct NoTail8d28 { ~NoTail8d28() {} };
/*TARGET 00248d28*/
void func_00248d28(void) asm("func_00248d28");
void func_00248d28(void) {
    NoTail8d28 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ed54, 31);
            if (func_0028acc8(D_0035ed4c) != 0 && func_00139d78(D_0035ed5c) != 0) {
                s32 i = func_002891e8(D_0035ed4c);
                func_0028dae0(D_0035ed5c, D_00371d40[i].b);
            }
            func_0028dae0(D_0035ed58, 34);
            if (func_0028acc8(D_0035ed4c) != 0 && func_0028acb8(D_0035ed4c) == 0) {
                func_0028aa40(D_0035ed4c);
            }
            if (func_0028acc8(D_0035ed50) != 0 && func_0028acb8(D_0035ed50) == 0) {
                func_0028aa40(D_0035ed50);
            }
        }
        func_00249358();
        func_0028ce38();
    }
    func_00249098();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ed4c : D_0035ed50;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                func_0028cc78(side, 0, 0, D_0035ed54, 15, 14);
                func_0028cf28(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            func_0028ce98(0, side);
        }
        func_00248f50(obj, mode, side);
    }
}
}  // namespace n00248d28

// 00248f50 (was src/anon/batch_w99.cpp)
namespace n00248f50 {
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
struct S6_248 { s16 a, b, c; };
struct S36_248 { u8 b[36]; };
extern S6_248 D_00371d40[] asm("D_00371d40");
extern S36_248 D_00371d90[] asm("D_00371d90");
extern S36_248 D_00371e00[] asm("D_00371e00");
extern u32 D_0035ed5c asm("D_0035ed5c");
extern u32 D_0035ed60 asm("D_0035ed60");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289310(u32) asm("func_00289310");
s32 func_002891e8(u32) asm("func_002891e8");
void func_002890e0(u32, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(u32, s32, s32, s32, s32, s32, s32) asm("func_00289038");
void func_0023f070(u32, s16, s32) asm("func_0023f070");
void func_002493c8(void) asm("func_002493c8");
s32 func_0028d008(u32) asm("func_0028d008");
u32 func_002891d0(u32) asm("func_002891d0");
void func_0028cf28(u32, u32) asm("func_0028cf28");
// record408_set_and_refresh
void func_002b4388(u32, S36_248*, s32) asm("func_002b4388");
/*TARGET 00248f50*/
void func_00248f50(u32 obj, s32 mode, u32 w) asm("func_00248f50");
void func_00248f50(u32 obj, s32 mode, u32 w)
{
    if (func_00287cd0() != 1) return;
    if (!func_00289310(obj)) return;
    s32 k = func_002891e8(obj);
    func_002890e0(obj, 1, 2, 0, -1);
    func_00289038(obj, k, 1, 1, 2, 0, -1);
    if (!mode) {
        func_0023f070(D_0035ed5c, D_00371d40[k].c, -1);
        func_002493c8();
    }
    if (func_0028d008(w)) func_0028cf28(w, func_002891d0(obj));
    func_002b4388(D_0035ed60, !mode ? &D_00371d90[k] : &D_00371e00[k], 0);
}
}  // namespace n00248f50

// 00249098 (was src/anon/batch_w66.cpp)
namespace n00249098 {
// 0022cae8: moved to src/sasa/event_layout.cpp (linked unit)
// ---- 00249098 / 002b6418
s32 func_002892f8(u32) asm("func_002892f8");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_00288e88(u32) asm("func_00288e88");
extern u32 D_0035ed4c asm("D_0035ed4c");
extern u32 D_0035ed50 asm("D_0035ed50");
/*TARGET 00249098*/
void func_00249098(void) asm("func_00249098");
void func_00249098(void) {
    if (D_0035ed4c) {
        s32 s = func_002892f8(D_0035ed4c);
        if (!func_0028acc8(D_0035ed4c) && s) func_00288e88(D_0035ed4c);
    }
    if (D_0035ed50) {
        s32 s = func_002892f8(D_0035ed50);
        if (!func_0028acc8(D_0035ed50) && s) func_00288e88(D_0035ed50);
    }
}
}  // namespace n00249098

// 00249148 (was src/anon/tiny_auto80_queue.cpp)
namespace n00249148 {
extern u32 D_0035ed4c asm("D_0035ed4c");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 00249148*/
// 0x002468a0: definition moved into src/anon/unit_00242478.cpp

void func_00249148() asm("_Z13func_00249148v");
// 0x002468a0: definition moved into src/anon/unit_00242478.cpp

void func_00249148() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ed4c);
    func_0023fc40(&v0, 4);
}
}  // namespace n00249148

// 00249180 (was src/anon/tiny_auto80_queue.cpp)
namespace n00249180 {
extern u32 D_0035ed4c asm("D_0035ed4c");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void func_002891f0(...) asm("func_002891f0");
/*TARGET 00249180*/
void func_00249180() asm("_Z13func_00249180v");
void func_00249180() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        func_002891f0(D_0035ed4c, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n00249180

// 002491d0 (was src/anon/batch_wcx2.cpp)
namespace n002491d0 {
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
// 00177f50: moved to src/yasui/libys/player.cpp

extern s8 D_0035ed69 asm("D_0035ed69");
extern u8* D_0035ed64 asm("D_0035ed64");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ed4c asm("D_0035ed4c");
extern u32 D_0035ed54 asm("D_0035ed54");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028afa8(u32) asm("func_0028afa8");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028d8c0__58307(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0__58307(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void func_002493c8(void) asm("func_002493c8");
/*TARGET 002491d0*/
void func_002491d0(void) asm("func_002491d0");
void func_002491d0(void)
{
    if (!D_0035ed69) return;
    if (func_00139d78(D_0035ed64)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed4c);
    for (s32 i = 0; i < n; i++) {
        u8* o = func_002891b8(D_0035ed4c, i);
        u8* a = o + 24;
        if ((u8)((D_0035ed69 >> i) & 1)) {
            func_0028d8c0__58307(D_0035ed64 + i * 408, id, 0, 0, D_0035ed54, 38, -1, 0);
            func_0028dcc0__58307(D_0035ed64 + i * 408, o);
            func_00139648(D_0035ed64 + i * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ed64 + i * 408, x, func_0023aa38(a));
        }
    }
    func_002493c8();
}
}  // namespace n002491d0

// 00249358 (was src/anon/batch_w43.cpp)
namespace n00249358 {
s32 func_00139d78(void*) asm("func_00139d78");
struct O408 { void** vt; u8 pad[404]; };
extern O408* D_0035ed64 asm("D_0035ed64");
/*TARGET 00249358*/
void func_00249358(void) asm("func_00249358");
void func_00249358(void) {
    for (s32 i = 0; i < 3; i++) {
        if (func_00139d78(&D_0035ed64[i])) ((void (*)(void*))D_0035ed64[i].vt[5])(&D_0035ed64[i]);
    }
}
}  // namespace n00249358

// 002493c8 (was src/anon/batch_wcx.cpp)
namespace n002493c8 {
// 0x001d1da0: definition moved into src/anon/unit_001d14e0.cpp

extern u8* D_0035ed4c asm("D_0035ed4c");
extern s8 D_0035ed69 asm("D_0035ed69");
extern u8* D_0035ed64 asm("D_0035ed64");
s32 func_002891e8(u8*) asm("func_002891e8");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 002493c8*/
void func_002493c8(void) asm("func_002493c8");
void func_002493c8(void)
{
    s32 i = func_002891e8(D_0035ed4c);
    if (!((D_0035ed69 >> i) & 1)) return;
    if (u_call4_00139d78(D_0035ed64 + i * 408)) {
        u8* o = D_0035ed64 + i * 408;
        if (*(s32*)(o + 388) != 37) func_00138c10(o, 37);
    }
    func_00243230(5, i);
}
}  // namespace n002493c8

// 00249480 (was src/anon/batch_w51.cpp)
namespace n00249480 {
// 0x00243020: definition moved into src/anon/unit_00242478.cpp

struct Ent36 { u8 pad[32]; s8 ids[4]; };
extern Ent36 D_00371d90[] asm("D_00371d90");
s32 func_001a6d08(s32) asm("func_001a6d08");
/*TARGET 00249480*/
s32 func_00249480(s32 idx) asm("func_00249480");
s32 func_00249480(s32 idx) {
    s32 r = 1;
    for (s32 i = 0; i < 4; i++) {
        s8 c = D_00371d90[idx].ids[i];
        if (c < 0) break;
        if (func_001a6d08(c)) {
            r = 0;
            break;
        }
    }
    return r;
}
}  // namespace n00249480

// 00249508 (was unwritten gap: TR menu init, twin of 0x243298)
namespace n00249508 {
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
extern Holder* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347e40 asm("D_00347e40");
extern u8 D_00347f98 asm("D_00347f98");
extern s32 D_0035ed70 asm("D_0035ed70");
extern s32 D_0035ed74 asm("D_0035ed74");
extern s32 D_0035ed78 asm("D_0035ed78");
extern s32 D_0035ed7c asm("D_0035ed7c");
extern s32 D_0035ed80 asm("D_0035ed80");
extern void* D_0035ed84 asm("D_0035ed84");
extern void* D_0035ed88 asm("D_0035ed88");
extern s32 D_0035ed98 asm("D_0035ed98");
void func_00287b18(s32, s32) asm("func_00287b18");
s32 func_00288be8(s32) asm("func_00288be8");
void func_002889f0(s32, s32, s32) asm("func_002889f0");
void func_00288f48(s32, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(s32) asm("func_002b3df8");
s32 func_00103570(void) asm("func_00103570");
s32 func_001063f0(s32, s32) asm("func_001063f0");
void func_002fde18(s32, s32, s32) asm("func_002fde18");
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
void func_0028d068(s32, s32) asm("func_0028d068");
s32* func_00103eb0(void) asm("func_00103eb0");
void func_00102818(s32, s32, s32, void*, s32) asm("func_00102818");
void PauseThread_243(void*) asm("_ZN2Tz4TRTE11PauseThreadEP4TASK");
typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
/*TARGET 00243298*/
void func_00249508(void) asm("func_00249508");
void func_00249508(void) {
    s32 v;
    u8* o;
    void* e60 = &D_00347e60;
    void* e40 = &D_00347e40;
    func_00287b18(2, 3);
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 1);
    D_0035ed70 = v;
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 0);
    D_0035ed74 = v;
    func_00288f48(v, 0x40, 0x80, 0, 0);
    D_0035ed78 = 0;
    D_0035ed7c = 0;
    D_0035ed80 = 0;
    v = (s32)Al(12);
    func_002b3df8(v);
    {
        register u32 h1 asm("$15");
        register u32 h asm("$14");
        asm("lui %0,%%hi(D_0035ed90)" : "=r"(h1));
        asm("lui %0,%%hi(D_0035ed94)" : "=r"(h) : "r"(h1));
        asm("" : "+r"(v) : "r"(h));
        *(s32*)(h1 - 4720) = v;
        *(s8*)(h - 4716) = 0;
    }
    {
        Alloc* al = D_00347f80->al;
        o = (u8*)(*al->vt)(al, 436, 0);
        *(void**)o = e60;
        *(s32*)(o + 12) = 0;
        func_00239700(o + 24);
        *(s32*)(o + 408) = 0;
        *(void**)o = e40;
        D_0035ed84 = o;
    }
    {
        Alloc* al = D_00347f80->al;
        o = (u8*)(*al->vt)(al, 436, 0);
        *(void**)o = &D_00347f98;
        func_0031a838(o + 12);
        *(void**)o = e60;
        func_00239700(o + 24);
        *(void**)o = e40;
        *(s32*)(o + 408) = 0;
        D_0035ed88 = o;
    }
    v = func_001063f0(0x20, func_00103570());
    D_0035ed98 = v;
    func_002fde18(v, 0, 0x20);
    {
        register Holder* hh asm("$15") = D_00347f80;
        Alloc* al = hh->al;
        s32* p = (s32*)(*al->vt)(al, 820, 0);
        u8* base = (u8*)(p + 1);
        u8* q = base;
        register s32 i asm("$20") = 1;
        register void* vt asm("$21") = e60;
        register s32 m1 asm("$22") = -1;
        *p = 2;
        do {
            *(s32*)(q + 12) = 0;
            *(void**)q = vt;
            i--;
            func_00239700(q + 0x18);
            q += 0x198;
        } while (i != m1);
        register u32 h3 asm("$15");
        register u32 h2 asm("$14");
        asm("lui %0,%%hi(D_0035ed8c)" : "=r"(h3));
        asm("lui %0,%%hi(D_0035ed9c)" : "=r"(h2) : "r"(h3));
        asm("" : "+r"(base) : "r"(h2));
        *(u8**)(h3 - 4724) = base;
        register s32 r4 asm("$4") = 30026;
        asm("" : "+r"(h2) : "r"(r4));
        *(s8*)(h2 - 4708) = 0;
        func_0028d068(r4, -1);
    }
    func_00102818(func_00103eb0()[1], 0, 2000, (void*)PauseThread_243, 0x1000);
}
}  // namespace n00249508


// 00249770 (was unwritten gap: menu globals cleanup, like 0x243500)
namespace n00249770 {
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
extern void* D_0035ed70 asm("D_0035ed70");
extern void* D_0035ed74 asm("D_0035ed74");
extern void* D_0035ed90 asm("D_0035ed90");
extern void* D_0035ed98 asm("D_0035ed98");
extern DO* D_0035ed78 asm("D_0035ed78");
extern DO* D_0035ed7c asm("D_0035ed7c");
extern DO* D_0035ed80 asm("D_0035ed80");
extern DO* D_0035ed84 asm("D_0035ed84");
extern DO* D_0035ed88 asm("D_0035ed88");
extern El2* D_0035ed8c asm("D_0035ed8c");
extern AO* D_0032ba14 asm("D_0032ba14");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_002b3fb0(void*) asm("func_002b3fb0");
void func_00106450(void*) asm("func_00106450");
void func_00249770(void) asm("func_00249770");
void func_00249770(void) {
    void* p;
    if ((p = D_0035ed70) != 0) { func_00288b00(p); func_00288c20(p); D_0035ed70 = 0; }
    if ((p = D_0035ed74) != 0) { func_00288b00(p); func_00288c20(p); D_0035ed74 = 0; }
    if (D_0035ed78) { D_0035ed78->vt->del(D_0035ed78); D_0035ed78 = 0; }
    if (D_0035ed7c) { D_0035ed7c->vt->del(D_0035ed7c); D_0035ed7c = 0; }
    if (D_0035ed80) { D_0035ed80->vt->del(D_0035ed80); D_0035ed80 = 0; }
    if ((p = D_0035ed90) != 0) { func_002b3fb0(p); D_0032ba14->vt->free(D_0032ba14, p); D_0035ed90 = 0; }
    if (D_0035ed84) { D_0035ed84->vt->del(D_0035ed84); D_0035ed84 = 0; }
    if (D_0035ed88) { D_0035ed88->vt->del(D_0035ed88); D_0035ed88 = 0; }
    if (D_0035ed98) { func_00106450(D_0035ed98); D_0035ed98 = 0; }
    if (D_0035ed8c) {
        delete[] D_0035ed8c;
        D_0035ed8c = 0;
    }
}
}  // namespace n00249770


// 00249940 (was src/tozawa/smenu_tr.cpp)
namespace Tz { // method 00249940
extern u32 D_0035ed6c asm("D_0035ed6c");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void func_002499b8() asm("func_002499b8");
void func_00242678(u32) asm("func_00242678");
void func_00236d60() asm("func_00236d60");
// clear_64_entries_24
extern "C" u32 func_0024a270() asm("func_0024a270");
void func_0024a710() asm("func_0024a710");
/*TARGET 00249940*/
void TRTE::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    func_002430d8(D_0035ed6c);
    func_00102448(s0, 1);
    func_002499b8();
    func_00242678(18014);
    while (1) {
        func_00236d60();  // clear_64_entries_24
        if (func_0024a270() != 0) {
            return;
        }
        func_0024a710();
        func_00102448(s0, 0);
    }
}
}  // Tz

