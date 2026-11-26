// Linked unit 0x002a0908-0x002a1d38 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_diagram.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/jm_treasure.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002a0908 (was src/anon/batch_w3733_nsa.cpp)
namespace n002a0908 {
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_001395f8(u8*) asm("func_001395f8");
void func_00139620(u8*) asm("func_00139620");
u8* func_00276348(void) asm("func_00276348");
u8* func_002766d0(void) asm("func_002766d0");
void Tz__Jiminy__CreateCover(void) asm("Tz__Jiminy__CreateCover");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
s32 func_0028f930(s32) asm("func_0028f930");
void Tz__JmDiagram__SetCharaName(void) asm("Tz__JmDiagram__SetCharaName");
void Tz__JmDiagram__GetCharaIdx(s32, s32) asm("Tz__JmDiagram__GetCharaIdx");
u8* func_002a1bc0(u16) asm("func_002a1bc0");
void func_002a1cd8(void) asm("func_002a1cd8");
void func_002a1f40(void) asm("func_002a1f40");
s32 Tz__JmNewInfo__isCharaNew(u16) asm("Tz__JmNewInfo__isCharaNew");
s32 func_002a9f50(u16) asm("func_002a9f50");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
union U5d4 { u8* p; s16 h; u8 c; };
union U5d8 { u8* p; s32 i; };
extern U5d4 D_0035f5d4 asm("D_0035f5d4");
extern U5d8 D_0035f5d8 asm("D_0035f5d8");
extern s32 D_00374b4c asm("D_00374b4c");
extern s32 D_00374b50 asm("D_00374b50");
extern s32 D_00374b54 asm("D_00374b54");
extern s32 D_00374b58 asm("D_00374b58");
extern s16 D_00374b70[] asm("D_00374b70");
struct It8 { u16 id; s16 x; s16 y; s16 pad; };
struct Sel5d4 { s8 n; u8 sel; s8 kind; u8 pad[77]; It8 it[1]; };
/*TARGET 002a0908*/
// Builds the selection menu items. Register pins: loop index i in s7, the loop-end
// count pointer/value in t5/t7 and the 408 stride constant in a1 (gcc swaps s6/s7 otherwise).
void func_002a0908(s32 sel) asm("func_002a0908");
// Builds the selection menu items. Register pins: loop index i in s7, the loop-end
// count pointer/value in t5/t7 and the 408 stride constant in a1 (gcc swaps s6/s7 otherwise).
void func_002a0908(s32 sel)
{
    u8* w = func_00276348();
    u8* base = func_002766d0();
    Tz__JmDiagram__GetCharaIdx(func_00287bc0() != 6, -1);
    func_002a1cd8();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s32 z = D_0035f3d4;
    s32 zm = z - 1;
    D_0035f5d4.p[1] = sel;
    if (sel < 0) {
        *(s16*)(D_0035f5d4.p + 68) = 0;
        *(s16*)(D_0035f5d4.p + 70) = 0;
    }
    Tz__Jiminy__CreateCover();
    func_0028d8c0(base, zm, D_0035f14c, D_0035f148, D_0035f210, 83, -1, 0);
    register s32 i asm("$23") = 0;
    func_00139620(base);
    func_0028dcc0(base, w);
    func_0028d8c0(D_0035f5d8.p, z, D_0035f14c, D_0035f148, D_0035f210, 84, -1, 0);
    *(s16*)(D_0035f5d4.p + 72) = -999;
    *(s16*)(D_0035f5d4.p + 76) = -999;
    *(s16*)(D_0035f5d4.p + 74) = -999;
    *(s16*)(D_0035f5d4.p + 78) = -999;
    func_0028d980(D_0035f5d8.p + 1224, z, D_0035f14c, D_0035f148, D_0035f210, 85, -1, -1, 0);
    func_0028dcc0(D_0035f5d8.p + 1224, w);
    func_00139620(D_0035f5d8.p + 1224);
    *(s32*)(D_0035f5d8.p + 1656) = 2;
    *(s32*)(D_0035f5d8.p + 1652) = 3;
    *(u32*)(D_0035f5d8.p + 1644) = 0x60000008;
    func_001395f8(D_0035f5d8.p + 1224);
    s32 y = D_0035f3d4;
    zm = y + 2;
    s32 flag = ((s8*)D_0035f5d4.p)[2] == 16;
    if (((s8*)D_0035f5d4.p)[0] > 0) {
        s32 f6 = flag * 6;
        s32 z6 = y + 6;
        u8* q = base;
        register s8* np asm("$13"); register s32 nn asm("$15");
        do {
            u8* o1 = q + 4248;
            u8* it = func_002a1bc0(((Sel5d4*)D_0035f5d4.p)->it[i].id);
            s32 c = D_00374b70[f6 + (s8)it[2]];
            func_0028d8c0(o1, zm, D_0035f14c, D_0035f148, D_0035f210, c, -1, 0);
            c = 2;
            func_0028dcc0(o1, base);
            func_00138c68(o1, ((Sel5d4*)D_0035f5d4.p)->it[i].x, ((Sel5d4*)D_0035f5d4.p)->it[i].y);
            u8* o2 = q + 0xa998;
            u16 id = ((Sel5d4*)D_0035f5d4.p)->it[i].id;
            if (Tz__JmNewInfo__isCharaNew(id)) {
                if (func_002a9f50(id)) {
                    if (flag) c = D_00374b58; else c = D_00374b50;
                } else {
                    if (flag) c = D_00374b54; else c = D_00374b4c;
                }
            }
            q += 408;
            func_0028d8c0(o2, z6, D_0035f14c, D_0035f148, D_0035f210, c, -1, 0);
            { register s32 m asm("$5") = 408; m = i * m; i++; func_0028dcc0(o2, base + m + 4248); }
            { u8* s = o2 + 24; *(s32*)(s + 184) |= 8; }
            np = (s8*)D_0035f5d4.p; nn = np[0];
        } while (i < nn);
    }
    Tz__JmDiagram__SetCharaName();
    func_002a1f40();
}
}  // namespace n002a0908

// 002a0cb8 (was src/anon/batch_wcx2.cpp)
namespace n002a0cb8 {
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
// 0x0025fb48: definition moved into src/anon/unit_0025f6b8.cpp

// ---- 002a0cb8
struct Pad2a0 { u64 trig; u64 rep; };
struct Ent2a0 { u16 a; u16 b; u16 c; u16 d; };
struct Win2a0 { u8 pad0; s8 idx; u8 pad1[70]; s16 x; s16 w; s16 y; s16 h; Ent2a0 ent[1]; };
extern u8 D_0035f5e1 asm("D_0035f5e1");
extern u8 D_0035f5e0 asm("D_0035f5e0");
// Read through a union: the original reloads it after every halfword store (no strict aliasing).
extern union { Win2a0* p; s16 h; } D_0035f5d4_0cb8 asm("D_0035f5d4");
extern union { u8* p; s16 h; } D_0035f5d8_0cb8 asm("D_0035f5d8");
Pad2a0* func_00167f18_0cb8(s32 a) asm("func_00167f18");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_002a1cd8(void) asm("func_002a1cd8");
void func_002a1bf8(void) asm("func_002a1bf8");
void Tz__JmDiagram__UpdateGra(void) asm("Tz__JmDiagram__UpdateGra");
s32 func_00276368(void) asm("func_00276368");
s32 func_00276888(void) asm("func_00276888");
void func_00287f90(s32 a) asm("func_00287f90");
s32 func_00287c10(void) asm("func_00287c10");
void func_002a07f0(s32 m) asm("func_002a07f0");
s32 func_00292630(void) asm("func_00292630");
void func_002a1c68(void) asm("func_002a1c68");
void func_00287c30(void) asm("func_00287c30");
s32 func_00276358(void) asm("func_00276358");
void Tz__Jiminy__SetParentSeqNum(s32 a, s32 b) asm("Tz__Jiminy__SetParentSeqNum");
void Tz__Jiminy__LoadData(s32 a) asm("Tz__Jiminy__LoadData");
// state_dispatch_0_1_2
void func_002925c0(void) asm("func_002925c0");
void Tz__JmReport__Setup(void) asm("Tz__JmReport__Setup");
void func_002995e8(void) asm("func_002995e8");
void func_002aa048(u16 a) asm("func_002aa048");
void Tz__JmDic__SetupDiagramCharaInfo(Win2a0* w, s32 m) asm("Tz__JmDic__SetupDiagramCharaInfo");
void func_00138cb8(u8* p, s32* x, s32* y) asm("func_00138cb8");
s16 func_0023aa18_0cb8(u8* p) asm("func_0023aa18");
s16 func_0023aa38_0cb8(u8* p) asm("func_0023aa38");
s32 func_00276398(void) asm("func_00276398");
// state_is_150
void func_00275b60(void) asm("func_00275b60");
void func_00287c90(s32 a) asm("func_00287c90");
s32 func_00139d78_0cb8(u8* p) asm("func_00139d78");
void func_002a10e0(void) asm("func_002a10e0");
void Tz__JmDiagram__CalcSelIdx(void) asm("Tz__JmDiagram__CalcSelIdx");
void Tz__JmDiagram__SetCharaName(void) asm("Tz__JmDiagram__SetCharaName");
void Tz__JmDiagram__CreateActive(void) asm("Tz__JmDiagram__CreateActive");
void func_002a13e0(Pad2a0* p) asm("func_002a13e0");
s32 func_00242618_0cb8(s32 a, s32 b) asm("func_00242618");
void func_002a1398(void) asm("func_002a1398");
void func_00287da0(void) asm("func_00287da0");
void Tz__SelHist__FadeOut(s32 a) asm("Tz__SelHist__FadeOut");
// record884_refresh_by_index
void func_002a0780(void) asm("func_002a0780");
void Tz__Jiminy__FadeOutHelp(void) asm("Tz__Jiminy__FadeOutHelp");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00287cc0(s32 s) asm("func_00287cc0");
s32 func_00242848(s32 a) asm("func_00242848");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
/*TARGET 002a0cb8*/
// global_zero_4dwords

void func_002a0cb8(void) asm("func_002a0cb8");
// global_zero_4dwords

void func_002a0cb8(void) {
    Pad2a0* pad = func_00167f18_0cb8(0);
    s32 st = func_00287cd0();
    s32 mode = func_00287bc0();
    if (st != 2) {
        if (!D_0035f5e1) func_002a1cd8();
        if (!D_0035f5e0) func_002a1bf8();
        if (D_0035f5e0) Tz__JmDiagram__UpdateGra();
    }
    if (st == 2) {
        if (func_00276368() || func_00276888()) {
            if (pad->rep & 0x1fc) {
                func_00287f90(0);
                func_002a07f0(func_00287c10());
            }
            return;
        }
        if (func_00292630()) return;
        func_002a1c68();
        func_002a07f0(func_00287c10());
        s32 prev = func_00287bc0();
        func_00287c30();
        mode = func_00287bc0();
        Tz__Jiminy__SetParentSeqNum(func_00276358(), 0);
        if (mode == 2) {
            Tz__Jiminy__LoadData(2);  // state_dispatch_0_1_2
            func_002925c0();
            Tz__JmReport__Setup();
        } else if (mode == 13) {
            Tz__Jiminy__LoadData(13);  // state_dispatch_0_1_2
            func_002925c0();
            func_002995e8();
        } else if (mode == 16) {
            func_002aa048(D_0035f5d4_0cb8.p->ent[D_0035f5d4_0cb8.p->idx].a);
            Tz__JmDic__SetupDiagramCharaInfo(D_0035f5d4_0cb8.p, prev);
        }
        return;
    }
    if (D_0035f5d4_0cb8.p->x == -999) {
        union { s32 v; s16 h; } x, y;
        func_00138cb8(D_0035f5d8_0cb8.p, &x.v, &y.v);
        D_0035f5d4_0cb8.p->x = x.v;
        D_0035f5d4_0cb8.p->y = y.v;
        D_0035f5d4_0cb8.p->w = func_0023aa18_0cb8(D_0035f5d8_0cb8.p + 24);
        D_0035f5d4_0cb8.p->h = func_0023aa38_0cb8(D_0035f5d8_0cb8.p + 24);
    }
    if (pad->rep & 0x1fc) {
        if (!func_00276398()) {  // state_is_150
            Tz__Jiminy__SetParentSeqNum(0, 2);
            func_00275b60();
        }
    }
    if (st == 0 && func_00276398()) {  // state_is_150
        func_00287c90(1);
    } else {
        if (!func_00139d78_0cb8(D_0035f5d8_0cb8.p + 816)) func_002a10e0();
        s8 idx = D_0035f5d4_0cb8.p->idx;
        Tz__JmDiagram__CalcSelIdx();
        Tz__JmDiagram__SetCharaName();
        if (idx < 0 && D_0035f5d4_0cb8.p->idx != 0) Tz__JmDiagram__CreateActive();
        if (pad->trig & 0xf0) {
            func_002a13e0(pad);
        } else if (pad->rep & 0x100) {
            func_00242618_0cb8(5, 1);
            func_002a1398();
            func_00287da0();
        } else if (pad->rep & 8) {
            func_00242618_0cb8(3, 1);
            Tz__SelHist__FadeOut(0);  // record884_refresh_by_index
            func_002a0780();
            Tz__Jiminy__FadeOutHelp();
            func_002a1398();
            Tz__Jiminy__SetParentSeqNum(1, 1);
            func_00287c00(mode == 40 ? 13 : 2);
            func_00287cc0(2);
        } else if (pad->rep & 4) {
            if (func_00242848(func_00242618_0cb8(D_0035f5d4_0cb8.p->idx < 0 ? 4 : 2, 1))) return;
            func_002a1398();
            Tz__Jiminy__FadeOutHelp();
            func_002a0780();
            Tz__Jiminy__SetParentSeqNum(0, 1);
            func_00287c00(16);
            func_00287cc0(2);
        }
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n002a0cb8
#undef QCOPY

// 002a10e0 (was src/anon/batch_w92.cpp)
namespace n002a10e0 {
struct T2a1 { u8 f0; s8 slot; u8 pad[66]; s16 x; s16 y; s16 x0, x1, y0, y1; };
union I2a1 { s32 i; s16 h; };
union PT2a1 { T2a1* p; u16 h; };
union PU2a1 { u8* p; u32 w; };
struct Sub2a1 { u8 pad[184]; u32 flags; };
u8* func_002766d0(void) asm("func_002766d0");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00138cd0(u8*, I2a1*, I2a1*) asm("func_00138cd0");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void Tz__JmDiagram__CalcSelIdx(void) asm("Tz__JmDiagram__CalcSelIdx");
void Tz__JmDiagram__CreateActive(void) asm("Tz__JmDiagram__CreateActive");
extern PU2a1 D_0035f5d8 asm("D_0035f5d8");
extern PT2a1 D_0035f5d4 asm("D_0035f5d4");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
static inline Sub2a1* sub2a1(u8* p) { return (Sub2a1*)(p + 840); }
/*TARGET 002a10e0*/
void func_002a10e0(void) asm("func_002a10e0");
void func_002a10e0(void) {
    u8* r = func_002766d0();
    func_0028d8c0(D_0035f5d8.p + 816, 30065, D_0035f14c, D_0035f148, D_0035f210, 34, -1, 0);
    func_0028dcc0(D_0035f5d8.p + 816, r);
    I2a1 x, y;
    T2a1* t = D_0035f5d4.p;
    if (t->slot < 0) {
        x.i = t->x0 + (t->x1 - t->x0) / 2;
        y.i = t->y0 + (t->y1 - t->y0) / 2;
    } else {
        func_00138cd0(r + t->slot * 408 + 4248, &x, &y);
    }
    sub2a1(D_0035f5d8.p)->flags |= 8;
    func_00138c68(D_0035f5d8.p + 816, x.i, y.i);
    D_0035f5d4.p->x = x.i;
    D_0035f5d4.p->y = y.i;
    Tz__JmDiagram__CalcSelIdx();
    Tz__JmDiagram__CreateActive();
}
}  // namespace n002a10e0

// 002a1220 (was src/anon/batch_wcx2.cpp)
namespace n002a1220 {
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
struct Sub96 { u8 pad[184]; u32 fl; };
union UA96 { u8* p; u32 u; };
union UB96 { s8* p; u32 u; };
extern UA96 D_0035f5d8 asm("D_0035f5d8");
extern UB96 D_0035f5d4 asm("D_0035f5d4");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f210 asm("D_0035f210");
extern u32 D_00374b3c asm("D_00374b3c");
extern u32 D_00374b40 asm("D_00374b40");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510_113723(void*) asm("func_00139510");
u8* func_002766d0(void) asm("func_002766d0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028d8c0_113723(u8*, s32, u32, u32, u32, u32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_113723(u8*, u8*) asm("func_0028dcc0");
static inline void Flag96(u8* e) { Sub96* sb = (Sub96*)(e + 24); sb->fl |= 8; }
/*TARGET 002a1220*/
void Tz__JmDiagram__CreateActive(void) asm("Tz__JmDiagram__CreateActive");
void Tz__JmDiagram__CreateActive(void)
{
    s32 a = func_00139d78(D_0035f5d8.p + 816);
    s32 b = func_00139d78(D_0035f5d8.p + 408);
    u8* w = func_002766d0();
    if (!a) {
        if (b) func_00139510_113723(D_0035f5d8.p + 408);
        return;
    }
    if (!b) {
        if (D_0035f5d4.p[1] < 0) return;
        s32 id = D_0035f3d4 + 4;
        u32 x = func_00287bc0() == 6 ? D_00374b3c : D_00374b40;
        func_0028d8c0_113723(D_0035f5d8.p + 408, id, D_0035f14c, D_0035f148, D_0035f210, x, -1, 0);
        Flag96(D_0035f5d8.p + 408);
        func_0028dcc0_113723(D_0035f5d8.p + 408, w + D_0035f5d4.p[1] * 408 + 17304);
    } else {
        s32 k = D_0035f5d4.p[1];
        if (k < 0) {
            func_00139510_113723(D_0035f5d8.p + 408);
            return;
        }
        func_0028dcc0_113723(D_0035f5d8.p + 408, w + k * 408 + 17304);
        return;
    }
}
}  // namespace n002a1220
#undef QCOPY

// 002a1398 (was src/tozawa/jm_diagram.cpp)
namespace Tz { // method 002a1398
extern u32 D_0035f5d8 asm("D_0035f5d8");
u32 func_00139d78(u32) asm("func_00139d78");
void func_00139510(u32) asm("func_00139510");
/*TARGET 002a1398*/
void JmDiagram_LeaveSeq(void) asm("_ZN2Tz9JmDiagram8LeaveSeqEv");
void JmDiagram_LeaveSeq(void) {
    u32 p = D_0035f5d8 + 408;
    if (func_00139d78(p) == 0u) {
        return;
    }
    func_00139510(D_0035f5d8 + 408);
}
}  // Tz

// 002a13e0 (was src/anon/batch_w1610.cpp)
namespace n002a13e0 {
struct W1610Cur { u8 pad[0x44]; s16 x, y, xmin, xmax, ymin, ymax; };
struct W1610Pad { u64 btn; u8 pad[0x28]; f32 lx; f32 ly; u8 pad2[4]; f32 mag; };
union W1610CU { W1610Cur* p; s16 h; };
extern W1610CU D_0035f5d4 asm("D_0035f5d4");
extern u8* D_0035f5d8 asm("D_0035f5d8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void Tz__JmDiagram__CalcSelIdx(void) asm("Tz__JmDiagram__CalcSelIdx");
void Tz__JmDiagram__SetCharaName(void) asm("Tz__JmDiagram__SetCharaName");
void Tz__JmDiagram__CreateActive(void) asm("Tz__JmDiagram__CreateActive");
/*TARGET 002a13e0*/
void func_002a13e0(W1610Pad* p) asm("func_002a13e0");
void func_002a13e0(W1610Pad* p) {
    if (!func_00139d78(D_0035f5d8 + 0x330)) return;
    u64 b = p->btn;
    s32 x = D_0035f5d4.p->x;
    s32 y = D_0035f5d4.p->y;
    if (b & 0x40) {
        if (p->mag != 0.0f && p->lx < 0.0f) {
            x += (s32)(p->lx * 6.0f - 0.5f);
        } else {
            if (D_0035f5d4.p->xmin < x) x -= 3;
        }
        if (x < D_0035f5d4.p->xmin) x = D_0035f5d4.p->xmin;
    } else if (b & 0x80) {
        if (p->mag != 0.0f && 0.0f < p->lx) {
            x += (s32)(p->lx * 6.0f + 0.5f);
        } else {
            if (x < D_0035f5d4.p->xmax) x += 3;
        }
        if (D_0035f5d4.p->xmax < x) x = D_0035f5d4.p->xmax;
    }
    if (b & 0x10) {
        if (p->mag != 0.0f && p->ly < 0.0f) {
            y += (s32)(p->ly * 6.0f - 0.5f);
        } else {
            if (D_0035f5d4.p->ymin < y) y -= 3;
        }
        if (y < D_0035f5d4.p->ymin) y = D_0035f5d4.p->ymin;
    } else if (b & 0x20) {
        if (p->mag != 0.0f && 0.0f < p->ly) {
            y += (s32)(p->ly * 6.0f + 0.5f);
        } else {
            if (y < D_0035f5d4.p->ymax) y += 3;
        }
        if (D_0035f5d4.p->ymax < y) y = D_0035f5d4.p->ymax;
    }
    if (x != D_0035f5d4.p->x || y != D_0035f5d4.p->y) {
        func_00138c68(D_0035f5d8 + 0x330, x, y);
        D_0035f5d4.p->x = x;
        D_0035f5d4.p->y = y;
    }
    Tz__JmDiagram__CalcSelIdx();
    Tz__JmDiagram__SetCharaName();
    Tz__JmDiagram__CreateActive();
}
}  // namespace n002a13e0

// 002a16b8 (was src/anon/batch_w95.cpp)
namespace n002a16b8 {
struct PickCur { s8 n; s8 sel; u8 pad2[66]; s16 x; s16 y; };
// 0x002968d8: definition moved into src/anon/unit_00295d28.cpp

extern PickCur* D_0035f5d4 asm("D_0035f5d4");
u8* func_002766d0(void) asm("func_002766d0");
s32 func_0023aa98(u8*) asm("func_0023aa98");
void dk__Sprite__getPosAddOffset(u8*, s32*, s32*) asm("dk__Sprite__getPosAddOffset");
/*TARGET 002a16b8*/
// sum_fields_to_out
// Pick the icon under the cursor.
void Tz__JmDiagram__CalcSelIdx(void) asm("Tz__JmDiagram__CalcSelIdx");
// sum_fields_to_out
// Pick the icon under the cursor.
void Tz__JmDiagram__CalcSelIdx(void) {
    u8* w = func_002766d0();
    s16 x = D_0035f5d4->x;
    s16 y = D_0035f5d4->y;
    s32 r = func_0023aa98(w + 4272) / 2;
    s32 i;
    for (i = 0; i < D_0035f5d4->n; i++) {
        s32 py, px;
        dk__Sprite__getPosAddOffset(w + 4248 + i * 408, &px, &py);  // sum_fields_to_out
        if (x < px - r || px + r < x) continue;
        if (y < py - r || py + r < y) continue;
        D_0035f5d4->sel = i;
        break;
    }
    if (i >= D_0035f5d4->n) D_0035f5d4->sel = -1;
}
}  // namespace n002a16b8

// 002a17e8 (was src/anon/batch_w91.cpp)
namespace n002a17e8 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
u32 func_00192048(u32) asm("func_00192048");
// 0x0029ad40: definition moved into src/anon/unit_00299920.cpp

// --- 002a17e8
// Shows the help text for the highlighted entry (or clears it when nothing is selected).
extern u8* D_0035f5d8 asm("D_0035f5d8");
extern u8* D_0035f5d4 asm("D_0035f5d4");
u8* func_002a1bc0(u16) asm("func_002a1bc0");
u32 Tz__JmWorldSel__GetId2WorldName(s32, s32) asm("Tz__JmWorldSel__GetId2WorldName");
void func_00192e50(u32, u8*, s32, u32) asm("func_00192e50");
void func_002595e8(u8*, u32) asm("func_002595e8");
/*TARGET 002a17e8*/
void Tz__JmDiagram__SetCharaName(void) asm("Tz__JmDiagram__SetCharaName");
void Tz__JmDiagram__SetCharaName(void) {
    u_call4_00139d78(D_0035f5d8 + 1224);
    s8 k = ((s8*)D_0035f5d4)[1];
    if (k < 0) {
        *(u32*)(D_0035f5d8 + 1632) = 0;
        return;
    }
    u8* it = func_002a1bc0(*(u16*)(D_0035f5d4 + k * 8 + 80));
    if (*(u16*)(it + 16) & 0x400) {
        u32 m = func_00192048(*(u16*)(it + 6));
        u32 m2 = func_00192048(Tz__JmWorldSel__GetId2WorldName(((s8*)D_0035f5d4)[2], 1));
        func_00192e50(m, D_0035f5d4 + 4, 64, m2);
    } else {
        func_002595e8(D_0035f5d4 + 4, func_00192048(*(u16*)(it + 6)));
    }
    *(u8**)(D_0035f5d8 + 1632) = D_0035f5d4 + 4;
}
}  // namespace n002a17e8

// 002a18d0 (was src/anon/batch_w2501_nsa.cpp)
namespace n002a18d0 {
struct Item { u8 a[6]; s8 on; u8 b; };
struct Grp { u16 id; u16 x; s8 sel; s8 cnt; s8 flag; u8 pad; s32 off; };
struct Tab { u8 pad[8]; s32 n; u8 pad2[4]; Grp g[1]; };
struct Dst { s8 count; u8 p1; s8 sel; u8 pad[77]; Item items[1]; };
s8* func_00276568(void) asm("func_00276568");
Tab* func_00294000(s32) asm("func_00294000");
s32 func_00294408(Grp*) asm("func_00294408");
extern Dst* D_0035f5d4 asm("D_0035f5d4");
/*TARGET 002a18d0*/
void Tz__JmDiagram__GetCharaIdx(s32 all, s32 sel) asm("Tz__JmDiagram__GetCharaIdx");
void Tz__JmDiagram__GetCharaIdx(s32 all, s32 sel) {
    if (!all) {
        if (sel < 0) sel = *func_00276568();
    } else sel = 16;
    D_0035f5d4->sel = sel;
    s32 found = 0;
    s32 idx = -1;
    s32 i = 0;
    s32 j;
    s32 n;
    Item* it;
    Tab* t = func_00294000(5);
    Grp* g = t->g;
    for (; i < t->n; i++) {
        if (g[i].sel != sel) {
            if (found) break;
            continue;
        }
        if (!found) found = 1;
        if (g[i].flag) continue;
        if (!func_00294408(&g[i])) break;
        idx = i;
    }
    n = 0;
    Grp* q = (Grp*)(idx * 12 + (u32)g);
    it = (Item*)((u8*)t + q->off);
    for (j = 0; j < g[idx].cnt; j++) {
        if (it[j].on) D_0035f5d4->items[n++] = it[j];
    }
    found = 0;
    for (i = 0; i < t->n; i++) {
        if (g[i].sel != sel) {
            if (found) break;
            continue;
        }
        if (!found) found = 1;
        if (!g[i].flag) continue;
        if (!func_00294408(&g[i])) continue;
        it = (Item*)((u8*)t + g[i].off);
        for (j = 0; j < g[i].cnt; j++) {
            if (it[j].on) D_0035f5d4->items[n++] = it[j];
        }
    }
    D_0035f5d4->count = n;
}
}  // namespace n002a18d0

// 002a1b18 (was src/anon/batch_w1592.cpp)
namespace n002a1b18 {
// 0x0028b258: definition moved into src/anon/unit_00288b00.cpp

struct E1592b { u16 id; u16 p[3]; };
struct T1592b { s8 n; u8 pad[0x4f]; E1592b e[1]; };
extern T1592b* D_0035f5d4 asm("D_0035f5d4");
void Tz__JmDiagram__GetCharaIdx(void) asm("Tz__JmDiagram__GetCharaIdx");
s32 Tz__JmNewInfo__isCharaNew(u16) asm("Tz__JmNewInfo__isCharaNew");
s32 func_002a9f50(u16) asm("func_002a9f50");
/*TARGET 002a1b18*/
s32 Tz__JmDiagram__GetNewInfo(void) asm("Tz__JmDiagram__GetNewInfo");
s32 Tz__JmDiagram__GetNewInfo(void) {
    s32 i = 0; s32 r = 0;
    Tz__JmDiagram__GetCharaIdx();
    for (; i < D_0035f5d4->n; i++) {
        u16 id = D_0035f5d4->e[i].id;
        if (Tz__JmNewInfo__isCharaNew(id)) {
            r = 1;
            if (!func_002a9f50(id)) break;
            r = 2;
        }
    }
    return r;
}
}  // namespace n002a1b18

// 002a1bc0 (was src/anon/tiny_auto80_solver.cpp)
namespace n002a1bc0 {
u32 func_00294000(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00294000jjjjjjjj");
/*TARGET 002a1bc0*/
u32 func_002a1bc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_002a1bc0jjjjjjjj");
u32 func_002a1bc0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15, r16;
    r16 = r4;
    r4 = (u32)((s32)0u + (3));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00294000)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = (u32)((s32)0u + (36));
    r16 = (u32)(r16 * r15);
    r2 = (u32)((s32)r2 + (16));
    r2 = (u32)(r2 + r16);
    return r2;
}
}  // namespace n002a1bc0

// 002a1bf8 (was src/tozawa/jm_diagram.cpp)
namespace Tz { // method 002a1bf8
extern u32 D_0035f5dc asm("D_0035f5dc");
extern u8* D_0035f5d4 asm("D_0035f5d4");
extern u8 D_0035f5e0 asm("D_0035f5e0");
u32 func_0023f900(u32) asm("func_0023f900");
u32 func_00292630() asm("func_00292630");
u32 func_00293de8(u32) asm("func_00293de8");
u32 func_00293db8(u32, u32) asm("func_00293db8");
void func_0023fa08(u32, u32) asm("func_0023fa08");
/*TARGET 002a1bf8*/
void JmDiagram_FileAlloc(void) asm("_ZN2Tz9JmDiagram9FileAllocEv");
void JmDiagram_FileAlloc(void) {
    u32* s0 = &D_0035f5dc;
    func_0023f900(*s0);
    if (func_00292630() != 0) {
        return;
    }

    u8* t6 = D_0035f5d4;
    u32 r = func_00293de8((s8)t6[2]);
    u32 r2 = func_00293db8(4, r);
    func_0023fa08(*s0, r2);
    D_0035f5e0 = 1;
}
}  // Tz

// 002a1c68 (was src/anon/batch_w44.cpp)
namespace n002a1c68 {
s32 LoadDataIsFlushing_at(void) asm("func_00292630");
s32 func_0023f900(void*) asm("func_0023f900");
void func_0023fad0(void*) asm("func_0023fad0");
void func_00293d80(s32) asm("func_00293d80");
// 0x00293668: definition moved into src/anon/unit_00292e60.cpp

extern u8 D_0035f5e0 asm("D_0035f5e0");
extern u8 D_0035f5e1 asm("D_0035f5e1");
extern void* D_0035f5dc asm("D_0035f5dc");
/*TARGET 002a1c68*/
void func_002a1c68(void) asm("func_002a1c68");
void func_002a1c68(void) {
    if (LoadDataIsFlushing_at()) return;
    if (D_0035f5e0 && func_0023f900(D_0035f5dc)) func_0023fad0(D_0035f5dc);
    func_00293d80(5101);
    D_0035f5e0 = 0;
    D_0035f5e1 = 0;
}
}  // namespace n002a1c68

// 002a1cd8 (was src/tozawa/layfile.cpp)
namespace Tz { // method 002a1cd8
u32 func_00292630() asm("func_00292630");
void func_002a1c68() asm("func_002a1c68");
extern u8* D_0035f5d4 asm("D_0035f5d4");
u32 func_00293de8(u32) asm("func_00293de8");
void func_00293bd0(u32, u32, u32) asm("func_00293bd0");
void func_002925c0() asm("func_002925c0");
extern u8 D_0035f5e1 asm("D_0035f5e1");
/*TARGET 002a1cd8*/
void LayFile_free(void) asm("_ZN2Tz7LayFile4freeEv");
void LayFile_free(void) {
    if (func_00292630() != 0) {
        return;
    }

    func_002a1c68();
    u32 r = func_00293de8((s8)D_0035f5d4[2]);
    func_00293bd0(4, r, 0);
    func_002925c0();
    D_0035f5e1 = 1;
}
}  // Tz

