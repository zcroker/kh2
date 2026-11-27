// Linked unit 0x002a1d38-0x002a3318 (one namespace per old matched source; class methods in their own namespace).
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

// 002a1d38 (was src/anon/batch_w3736.cpp)
namespace n002a1d38 {
void func_001386e0(void*, s32, s32, void*, s32, s32) asm("func_001386e0");
void func_00139620(void*) asm("func_00139620");
s32 func_00139d78(void*) asm("func_00139d78");
void func_002362b0(void*, s32) asm("func_002362b0");
s32 func_0023c4b8(s32, s32) asm("func_0023c4b8");
s32 func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023f988(s32, s32) asm("func_0023f988");
u8* func_002766d0(void) asm("func_002766d0");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
s8* func_002a1bc0(u16) asm("func_002a1bc0");
struct S2a1d38 { s16 a, b, c; };
struct T2a1d38 { s8 n; s8 p1; s8 kind; u8 pad[0x4d]; struct { u16 id; u8 p[6]; } e[1]; };
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern T2a1d38* D_0035f5d4 asm("D_0035f5d4");
struct G1 { s32 dc; u8 e0; };
extern G1 D_0035f5dc asm("D_0035f5dc");
extern u8 D_0035f5e0 asm("D_0035f5e0");
extern S2a1d38 D_00374b60[] asm("D_00374b60");
/*TARGET 002a1d38*/
// Per-entry setup loop. Partial asm (step 4): the in-loop lui of D_0035f5d4 is hand-written (pinned to t7,
// ordered after p) so loop/cse2 do not hoist it and give it a register; the empty asm around the pre-loop
// load keeps t6 busy so its high half lands in t7. No code is emitted by the empty asm statements.
void func_002a1d38(void) asm("func_002a1d38");
// Per-entry setup loop. Partial asm (step 4): the in-loop lui of D_0035f5d4 is hand-written (pinned to t7,
// ordered after p) so loop/cse2 do not hoist it and give it a register; the empty asm around the pre-loop
// load keeps t6 busy so its high half lands in t7. No code is emitted by the empty asm statements.
void func_002a1d38(void) {
    u8* w = func_002766d0();
    if (D_0035f5e0 == 0) return;
    if (func_00139d78(w + 0x4398)) return;
    s32 i = 0;
    s32 k = D_0035f3d4 + 3;
    s32 m = func_0023c4b8(func_0023f1b0(D_0035f210), 0);
    s32 ph; asm("" : "=r"(ph));
    T2a1d38* t = D_0035f5d4;
    asm("" : : "r"(ph), "r"(t));
    s32 idx = t->kind == 0x10;
    if (t->n > 0) {
        u8* p = w;
        u8* q = w + 0xdca0;
        do {
            u8* o = p + 0x4398;
            func_002362b0(q, func_0023f988(D_0035f5dc.dc, func_002a1bc0(t->e[i++].id)[1]));
            bool on = 1; *(bool*)(q + 400) = on;
            func_001386e0(o, k, m, q, D_00374b60[idx].a, 0);
            q += 0x1a0;
            *(s32*)(p + 0x4520) = D_00374b60[idx].c;
            func_00139620(o);
            *(s8*)(p + 0x452d) = 1;
            *(s32*)(p + 0x4468) |= 8;
            func_0028dcc0(o, p + 0x1098);
            u32 hi; asm("lui %0,%%hi(D_0035f5d4)" : "=r"(hi) : "r"(p)); t = *(T2a1d38**)(hi - 2604); p += 0x198;
        } while (i < t->n);
    }
}
}  // namespace n002a1d38

// 002a1ec8 (was src/anon/batch_w48.cpp)
namespace n002a1ec8 {
void func_0028dac8(void*, s32) asm("func_0028dac8");
struct T2a1 { s16 a; s16 b; s16 c; };
extern T2a1 D_00374b60[2] asm("D_00374b60");
extern s8* D_0035f5d4 asm("D_0035f5d4");
void* func_002766d0(void) asm("func_002766d0");
/*TARGET 002a1ec8*/
void func_002a1ec8(void) asm("func_002a1ec8");
void func_002a1ec8(void) {
    u8* p = (u8*)func_002766d0() + 17304;
    s32 idx = D_0035f5d4[2] == 16;
    T2a1* t = &D_00374b60[idx];
    for (s32 i = 31; i >= 0; i--) {
        func_0028dac8(p, t->b);
        p += 408;
    }
}
}  // namespace n002a1ec8

// 002a1f40 (was src/anon/batch_w20.cpp)
namespace n002a1f40 {
u32 func_00287bc0(void) asm("func_00287bc0");
void func_00276c50(u32, u32) asm("func_00276c50");
extern u32 D_00374b44 asm("D_00374b44");
extern u32 D_00374b48 asm("D_00374b48");
/*TARGET 002a1f40*/
// 0x00288be8: definition moved into src/anon/unit_00288b00.cpp

void func_002a1f40(void) asm("func_002a1f40");
// 0x00288be8: definition moved into src/anon/unit_00288b00.cpp

void func_002a1f40(void) {
    u32 a;
    if (func_00287bc0() == 6) a = D_00374b44; else a = D_00374b48;
    func_00276c50(a, 0);
}
}  // namespace n002a1f40

// 002a1f80 (gap: empty query)
namespace g002a1f80 {
s32 func_002a1f80(void) asm("func_002a1f80");
s32 func_002a1f80(void) { return 0; }
}  // namespace g002a1f80

// 002a1f88 (was src/anon/batch_w1585_g.cpp)
namespace n002a1f88 {
void* tz_lsys(void) asm("_ZN2Tz17LoadDataGetSystemEv");
void* menu_alloc(void) asm("_ZN4MENU15GetObjAllocatorEv");
void* tz_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
void func_003241a0(void*) asm("func_003241a0");
/* 002a1f88 */
struct E8 { u32 a, b; };
struct Big { u8 pad[0x108c]; E8 e[10]; };
extern Big* D_0035f5e4 asm("D_0035f5e4");
extern void* D_0035f5e8 asm("D_0035f5e8");
/*TARGET 002a1f88*/
void func_002a1f88(void) asm("func_002a1f88");
void func_002a1f88(void) {
    Big* p = (Big*)tz_alloc(0x10dc, tz_lsys());
    E8* e = p->e;
    s32 n = 9;
    do { e->a = 0; e->b = 0; n--; e++; } while (n != -1);
    D_0035f5e4 = p;
    void* q = tz_alloc(0x984c, menu_alloc());
    func_003241a0(q);
    D_0035f5e8 = q;
}
}  // namespace n002a1f88

// 002a2010 (was src/anon/batch_w1599.cpp)
namespace n002a2010 {
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[432];
};
struct Ab {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Ab();
    u8 pad[0x194];
};
extern void* D_0035f5e4 asm("D_0035f5e4");
extern u8* D_0035f5e8 asm("D_0035f5e8");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347f98[] asm("D_00347f98");
void func_00106420(void*) asm("func_00106420");
void func_0031acc0(void*) asm("func_0031acc0");
void func_00239870(void*) asm("func_00239870");
/*TARGET 002a2010*/
void func_002a2010(void) asm("func_002a2010");
void func_002a2010(void) {
    if (D_0035f5e4) { func_00106420(D_0035f5e4); D_0035f5e4 = 0; }
    u8* q = D_0035f5e8;
    if (q) {
        if (q + 0x88c8) {
            El* e = (El*)(q + 0x981c);
            El* end = (El*)(q + 0x88c8);
        t1:
            if (end == e) goto o1;
            e--;
            e->~El();
            goto t1;
        o1:;
        }
        if (q + 0x7974) {
            El* e = (El*)(q + 0x88c8);
            El* end = (El*)(q + 0x7974);
        t2:
            if (end == e) goto o2;
            e--;
            e->~El();
            goto t2;
        o2:;
        }
        Ab* a = (Ab*)(q + 0x72c0);
        func_0031acc0(q + 0x77c0);
        func_0031acc0(q + 0x760c);
        func_0031acc0(q + 0x7458);
        *(u8**)(q + 0x72c0) = D_00347e60;
        func_00239870(q + 0x72d8);
        *(u8**)(q + 0x72c0) = D_00347f98;
        if (q) {
        t3:
            if ((Ab*)q == a) goto o3;
            a--;
            a->~Ab();
            goto t3;
        o3:;
        }
        func_00106420(q);
        D_0035f5e8 = 0;
    }
}
}  // namespace n002a2010

// 002a2148 (was src/anon/misc_2.cpp)
namespace n002a2148 {
/*TARGET 002a2148*/
// 0x0029ee30: definition moved into src/anon/unit_0029d008.cpp

void func_002a2148(void* self) asm("_Z13func_002a2148Pv");
// 0x0029ee30: definition moved into src/anon/unit_0029d008.cpp

void func_002a2148(void* self) {}
}  // namespace n002a2148

// 002a2150 (was src/tozawa/jm_treasure.cpp)
namespace Tz { // method 002a2150
u32 func_00287bc0_t(...) asm("func_00287bc0");
void func_002a41f0(...) asm("func_002a41f0");
void func_00274ac8(...) asm("_ZN2Tz6Jiminy13JmCommonLeaveEv");
/*TARGET 002a2150*/
void JmTreasure_LeaveAll(void) asm("_ZN2Tz10JmTreasure8LeaveAllEv");
void JmTreasure_LeaveAll(void) {
    u32 v0 = func_00287bc0_t();
    if (v0 == 7 || v0 == 26 || v0 == 9 || v0 == 34 || v0 == 8 || v0 == 33) {
        func_002a41f0();
        func_00274ac8();
    }
}
}  // Tz

// 002a21b0 (was src/anon/batch_w1585_g.cpp)
namespace n002a21b0 {
/* 002a1f88 */
struct E8 { u32 a, b; };
struct Big { u8 pad[0x108c]; E8 e[10]; };
extern Big* D_0035f5e4 asm("D_0035f5e4");
/* 002a21b0 */
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_002a43f0(void) asm("func_002a43f0");
void func_002a2a80(void) asm("func_002a2a80");
void func_002a2c40(void) asm("func_002a2c40");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_00276e78(void) asm("func_00276e78");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_002a3ba8(void) asm("func_002a3ba8");
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void func_002a4b78(void) asm("func_002a4b78");
void func_002a3aa8(void) asm("func_002a3aa8");
void func_002a3910(void) asm("func_002a3910");
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
struct Lay { u8 pad[40]; void* img; };
struct BigV { u8 pad[0x1080]; s32 v; };
/*TARGET 002a21b0*/
void func_002a21b0(void) asm("func_002a21b0");
void func_002a21b0(void) {
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    if (func_002a43f0()) func_002a2a80();
    else func_002a2c40();
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    s16 h[4];
    for (s32 i = 0; i < 4; i++) h[i] = 2;
    s32 n = D_0035f3d4;
    u8* seq2 = seq + 1224;
    func_00276e78();
    n--;
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 59, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 69, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    func_002a3ba8();
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 im = yi_img(((Lay*)lay_get(D_0035f210))->img, D_0035f148);
    func_0028bae0(D_0035f214, n, u, im, jm_scrbar(), ((BigV*)D_0035f5e4)->v, 9, seq2, 0);
    func_002a4b78();
    func_002a3aa8();
    func_002a3910();
    sel_set(0);
}
}  // namespace n002a21b0

// 002a23a0 (was src/anon/batch_w1607.cpp)
namespace n002a23a0 {
struct Pad2a23a0 { u64 a; u64 b; u64 c; u64 d; };
Pad2a23a0* func_00167f18(s32) asm("func_00167f18");
void func_00242618(s32, s32) asm("func_00242618");
void func_00274cf0(s32) asm("func_00274cf0");
void func_00276220(s32, s32) asm("func_00276220");
s32 func_00276358(void) asm("func_00276358");
s32 func_00276368(void) asm("func_00276368");
s32 func_00276398(void) asm("func_00276398");
s32 func_00276888(void) asm("func_00276888");
void func_00276dc0(void) asm("func_00276dc0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287da0(void) asm("func_00287da0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_002925c0(void) asm("func_002925c0");
s32 func_00292630(void) asm("func_00292630");
void func_002958b0(void) asm("func_002958b0");
void func_002995e8(void) asm("func_002995e8");
void func_002a2148(void) asm("func_002a2148");
void func_002a2150(void) asm("func_002a2150");
s32 func_002a40c8(void) asm("func_002a40c8");
void func_002a4470(void) asm("func_002a4470");
void func_002a45a0(void) asm("func_002a45a0");
void func_002a4620(Pad2a23a0*) asm("func_002a4620");
/*TARGET 002a23a0*/
void func_002a23a0(void) asm("func_002a23a0");
void func_002a23a0(void) {
    Pad2a23a0* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    s32 sub = func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_00276888() || func_002a40c8()) {
            if (pad->b & 0xc1fc) {
                func_00287f90(0);
                func_002a2150();
            }
        } else if (func_00292630() == 0) {
            func_002a2150();
            func_00287c30();
            sub = func_00287bc0();
            func_00276220(func_00276358(), 0);
            func_00274cf0(sub);
            func_002925c0();
            if (sub == 13) {
                func_002995e8();
                return;
            }
            if (sub == st) {
                func_002958b0();
            }
        }
    } else {
        if ((pad->b & 0xc1fc) && func_00276398() == 0) {
            func_00276220(0, 2);
        }
        if (st == 0 && func_00276398()) {
            func_002a4470();
            func_00287cc0(1);
        }
        if (pad->d & 0xc0f0) {
            func_002a4620(pad);
        } else {
            u64 b = pad->b;
            if (b & 0x100) {
                func_00242618(5, 1);
                func_002a45a0();
                func_00287da0();
            } else if (b & 8) {
                s32 m;
                func_00242618(3, 1);
                func_0028f6f0(0);
                func_002a2148();
                func_00276dc0();
                func_002a45a0();
                func_00276220(1, 1);
                if (sub == 26 || sub == 34) m = 13; else m = 2;
                func_00287c00(m);
                func_00287cc0(2);
            }
        }
        if (func_00288040()) {
            func_00288018();
        }
    }
}
}  // namespace n002a23a0

// 002a2600 (was src/anon/batch_w1585_g.cpp)
namespace n002a2600 {
/* 002a1f88 */
struct E8 { u32 a, b; };
struct Big { u8 pad[0x108c]; E8 e[10]; };
extern Big* D_0035f5e4 asm("D_0035f5e4");
/* 002a21b0 */
u8* jm_parent(void) asm("_ZN2Tz6Jiminy9GetParentEv");
u8* jm_seqtbl(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8* jm_scrbar(void) asm("_ZN2Tz6Jiminy15GetScrBarSeqTblEv");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_00276e78(void) asm("func_00276e78");
void pz_cfo(void*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void obj_xyoff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void mc_as(void*, void*) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");
void func_002a3ba8(void) asm("func_002a3ba8");
void* lay_get(s32) asm("_ZN2Tz6Layout9getLayoutEv");
s32 yi_unit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
s32 yi_img(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_0028bae0(s32, s32, s32, s32, u8*, s32, s32, u8*, s32) asm("func_0028bae0");
void func_002a4b78(void) asm("func_002a4b78");
void func_002a3aa8(void) asm("func_002a3aa8");
void func_002a3910(void) asm("func_002a3910");
void sel_set(s32) asm("_ZN2Tz8Selector8SetStateEi");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f14c asm("D_0035f14c");
extern s32 D_0035f148 asm("D_0035f148");
extern s32 D_0035f210 asm("D_0035f210");
extern s32 D_0035f214 asm("D_0035f214");
struct Lay { u8 pad[40]; void* img; };
struct BigV { u8 pad[0x1080]; s32 v; };
/* 002a2600 */
s32 mb_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_002a2de8(void) asm("func_002a2de8");
s32 func_002b3b60(s32) asm("func_002b3b60");
/*TARGET 002a2600*/
void func_002a2600(void) asm("func_002a2600");
void func_002a2600(void) {
    s32 m = mb_mode();
    u8* par = jm_parent();
    u8* seq = jm_seqtbl();
    func_002a2de8();
    if (m == 8 && !func_0028f930(0)) func_0028f4d8(0, -1, 0);
    if (m == 33 && !func_0028f930(1)) func_0028f4d8(1, func_002b3b60(1), 0);
    s16 h[4];
    for (s32 i = 0; i < 4; i++) h[i] = 2;
    s32 n = D_0035f3d4;
    u8* seq2 = seq + 1224;
    func_00276e78();
    n--;
    pz_cfo(seq, n, D_0035f14c, D_0035f148, D_0035f210, 59, -1, 0);
    obj_xyoff(seq);
    mc_as(seq, par);
    pz_cfo(seq2, n, D_0035f14c, D_0035f148, D_0035f210, 69, -1, 0);
    obj_xyoff(seq2);
    mc_as(seq2, par);
    func_002a3ba8();
    s32 u = yi_unit(lay_get(D_0035f210), D_0035f14c);
    s32 im = yi_img(((Lay*)lay_get(D_0035f210))->img, D_0035f148);
    func_0028bae0(D_0035f214, n, u, im, jm_scrbar(), ((BigV*)D_0035f5e4)->v, 9, seq2, 0);
    func_002a4b78();
    func_002a3aa8();
    func_002a3910();
    sel_set(0);
}
}  // namespace n002a2600

// 002a2818 (was src/anon/batch_w1607.cpp)
namespace n002a2818 {
struct Pad2a23a0 { u64 a; u64 b; u64 c; u64 d; };
Pad2a23a0* func_00167f18(s32) asm("func_00167f18");
void func_00242618(s32, s32) asm("func_00242618");
void func_00274cf0(s32) asm("func_00274cf0");
void func_00276220(s32, s32) asm("func_00276220");
s32 func_00276358(void) asm("func_00276358");
s32 func_00276368(void) asm("func_00276368");
s32 func_00276398(void) asm("func_00276398");
s32 func_00276888(void) asm("func_00276888");
void func_00276dc0(void) asm("func_00276dc0");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_00287c00(s32) asm("func_00287c00");
void func_00287c30(void) asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287da0(void) asm("func_00287da0");
void func_00287f90(s32) asm("func_00287f90");
void func_00288018(void) asm("func_00288018");
s32 func_00288040(void) asm("func_00288040");
void func_0028f6f0(s32) asm("func_0028f6f0");
void func_002925c0(void) asm("func_002925c0");
s32 func_00292630(void) asm("func_00292630");
void func_002958b0(void) asm("func_002958b0");
void func_002a2148(void) asm("func_002a2148");
void func_002a2150(void) asm("func_002a2150");
s32 func_002a40c8(void) asm("func_002a40c8");
void func_002a4470(void) asm("func_002a4470");
void func_002a45a0(void) asm("func_002a45a0");
void func_002a4620(Pad2a23a0*) asm("func_002a4620");
void func_002aed60(void) asm("func_002aed60");
/*TARGET 002a2818*/
void func_002a2818(void) asm("func_002a2818");
void func_002a2818(void) {
    Pad2a23a0* pad = func_00167f18(0);
    s32 st = func_00287cd0();
    s32 sub = func_00287bc0();
    if (st == 2) {
        if (func_00276368() || func_00276888() || func_002a40c8()) {
            if (pad->b & 0xc1fc) {
                func_00287f90(0);
                func_002a2150();
            }
        } else if (func_00292630() == 0) {
            func_002a2150();
            func_00287c30();
            sub = func_00287bc0();
            func_00276220(func_00276358(), 0);
            func_00274cf0(sub);
            func_002925c0();
            if (sub == 27) {
                func_002aed60();
                return;
            }
            if (sub == st) {
                func_002958b0();
            }
        }
    } else {
        if ((pad->b & 0xc1fc) && func_00276398() == 0) {
            func_00276220(0, 2);
        }
        if (st == 0 && func_00276398()) {
            func_002a4470();
            func_00287cc0(1);
        }
        if (pad->d & 0xc0f0) {
            func_002a4620(pad);
        } else {
            u64 b = pad->b;
            if (b & 0x100) {
                func_00242618(5, 1);
                func_002a45a0();
                func_00287da0();
            } else if (b & 8) {
                s32 m;
                func_00242618(3, 1);
                if (sub == 33) {
                    func_0028f6f0(1);
                    m = 27;
                } else {
                    func_0028f6f0(0);
                    m = 2;
                }
                func_00287c00(m);
                func_002a2148();
                func_00276dc0();
                func_002a45a0();
                func_00276220(1, 1);
                func_00287cc0(2);
            }
        }
        if (func_00288040()) {
            func_00288018();
        }
    }
}
}  // namespace n002a2818

// 002a2a80 (was src/anon/batch_w1957_nsa.cpp)
namespace n002a2a80 {
struct Ent8 { u8 f0, f1, f2, f3; u16 f4, f6; };
struct EntTbl { Ent8 list[512]; Ent8 sub[15]; s32 count; s32 active; };
struct ItemRec { u8 f0, f1; u16 id; u8 f4; u8 f5; u16 f6; u16 f8; };
union TblPtr { EntTbl* p; u32 w; u16 h; u8 b; };
extern TblPtr D_0035f5e4 asm("D_0035f5e4");
u32 func_00276c18(void) asm("func_00276c18");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
ItemRec* func_001a82b0(ItemRec*) asm("func_001a82b0");
s32 func_00181500(u16) asm("func_00181500");
s32 func_002a4390(ItemRec*) asm("func_002a4390");
u8 func_002764b0(u8) asm("func_002764b0");
void func_002a2ff8(void) asm("func_002a2ff8");
s32 func_002ab540(s32) asm("func_002ab540");
s32 func_002ab620(s32) asm("func_002ab620");
/*TARGET 002a2a80*/
void func_002a2a80(void) asm("func_002a2a80");
void func_002a2a80(void) {
    ItemRec* it = 0;
    s32 idx = 0;
    s32 n = 0;
    s32 cnt = 0;
    s32 r;
    u32 all = func_00276c18();
    func_002fde18(D_0035f5e4.p, 0, 4316);
    for (;;) {
        it = func_001a82b0(it);
        if (!it) break;
        if (it->f4 == 0 && it->f8 != 0 && it->f8 != 2048) {
            if (func_00181500(it->f8) || all) {
                r = func_002a4390(it);
                u8 v = func_002764b0(it->f5);
                D_0035f5e4.p->list[n].f0 = v;
                if (r) cnt++;
                D_0035f5e4.p->list[n].f4 = idx;
                D_0035f5e4.p->list[n].f6 = it->id;
                D_0035f5e4.p->list[n].f1 = r != 0;
                n++;
            }
        }
        idx++;
    }
    D_0035f5e4.p->count = n;
    D_0035f5e4.p->active = cnt;
    func_002a2ff8();
    for (s32 i = 0; i < 15; i++) {
        r = i * 8;
        Ent8* e = (Ent8*)(r + (u32)D_0035f5e4.p + 4096);
        if (e->f0 == 0) {
            e->f2 = 0;
            D_0035f5e4.p->sub[i].f3 = 0;
        } else {
            e->f2 = func_002ab540(i) != 0;
            D_0035f5e4.p->sub[i].f3 = func_002ab620(i) != 0;
        }
    }
}
}  // namespace n002a2a80

// 002a2c40 (was src/anon/batch_w110.cpp)
namespace n002a2c40 {
struct Ent8 { u8 f0, f1, f2, f3; u16 f4, f6; };
struct EntTbl { Ent8 list[512]; Ent8 sub[15]; s32 count; s32 active; };
struct ItemRec { u8 f0, f1; u16 id; u8 pad4; u8 f5; };
struct ItemDef { u8 f0, f1, type; };
union TblPtr { EntTbl* p; u32 w; u16 h; u8 b; };
extern TblPtr D_0035f5e4 asm("D_0035f5e4");
u32 func_00276c18(void) asm("func_00276c18");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
ItemRec* func_001a82b0(ItemRec*) asm("func_001a82b0");
ItemDef* func_001a80c8(u16) asm("func_001a80c8");
// table24_find_by_id
s32 func_002a43b0(ItemRec*) asm("func_002a43b0");
u8 func_002764b0(u8) asm("func_002764b0");
void func_002a2ff8(void) asm("func_002a2ff8");
s32 func_002ab8e8(s32) asm("func_002ab8e8");
s32 func_002ab9c8(s32) asm("func_002ab9c8");
/*TARGET 002a2c40*/
// Rebuilds the item list table (entries of type 22) and refreshes the 15 slot flags.
void func_002a2c40(void) asm("func_002a2c40");
// Rebuilds the item list table (entries of type 22) and refreshes the 15 slot flags.
void func_002a2c40(void) {
    ItemRec* it = 0;
    s32 idx = 0;
    s32 n = 0;
    s32 cnt = 0;
    u32 all = func_00276c18();
    func_002fde18(D_0035f5e4.p, 0, 4316);
    for (;;) {
        it = func_001a82b0(it);
        if (!it) break;
        if (func_001a80c8(it->id)->type == 22) {  // table24_find_by_id
            s32 r = func_002a43b0(it);
            if (r || all) {
                u8 v = func_002764b0(it->f5);
                D_0035f5e4.p->list[n].f0 = v;
                if (r) cnt++;
                D_0035f5e4.p->list[n].f4 = idx;
                D_0035f5e4.p->list[n].f6 = it->id;
                D_0035f5e4.p->list[n].f1 = r != 0;
                n++;
            }
        }
        idx++;
    }
    D_0035f5e4.p->count = n;
    D_0035f5e4.p->active = cnt;
    func_002a2ff8();
    for (s32 i = 0; i < 15; i++) {
        Ent8* e = (Ent8*)(i * 8 + (u32)D_0035f5e4.p + 4096);
        if (e->f0 == 0) {
            e->f2 = 0;
            D_0035f5e4.p->sub[i].f3 = 0;
        } else {
            e->f2 = func_002ab8e8(i) != 0;
            D_0035f5e4.p->sub[i].f3 = func_002ab9c8(i) != 0;
        }
    }
}
}  // namespace n002a2c40

// 002a2de8 (was src/anon/batch_w1910.cpp)
namespace n002a2de8 {
struct Ent { u8 a; u8 b; u16 v; u8 c4; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct Rec { u8 id; s8 f; u8 c2; u8 c3; s16 n; u16 v; };
struct Tbl { Rec r[512]; Rec s[15]; s32 count; s32 cnt2; u8 pad[12]; Bits bits[10]; };
union TU { Tbl* p; s16 h; u8 c; };
extern TU D_0035f5e4 asm("D_0035f5e4");
s32 func_00276c18(void) asm("func_00276c18");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
Ent* func_001d9e30(Ent*) asm("func_001d9e30");
s32 func_001d9d88(Ent*) asm("func_001d9d88");
s32 func_002a43d0(Ent*) asm("func_002a43d0");
u8 func_002764b0(u8) asm("func_002764b0");
void func_002a2ff8(void) asm("func_002a2ff8");
s32 func_002ac748(s32) asm("func_002ac748");
s32 func_002ac800(s32) asm("func_002ac800");
/*TARGET 002a2de8*/
void func_002a2de8(void) asm("func_002a2de8");
void func_002a2de8(void) {
    Ent* e; s32 n; s32 cnt; s32 cnt2; s32 flag; s32 i;
    flag = func_00276c18();
    func_002fde18(D_0035f5e4.p, 0, 4316);
    e = 0;
    n = 0;
    cnt = 0;
    cnt2 = 0;
top:
    e = func_001d9e30(e);
    if (!e) goto out;
    if (func_001d9d88(e) || flag) {
        if (!D_0035f5e4.p->bits[e->a].Test(e->b)) {
            s32 r = func_002a43d0(e);
            u8 id = func_002764b0(e->c4);
            if (r) cnt2++;
            D_0035f5e4.p->r[cnt].id = id;
            D_0035f5e4.p->r[cnt].n = n;
            D_0035f5e4.p->r[cnt].v = e->v;
            D_0035f5e4.p->r[cnt].f = r != 0;
            cnt++;
            D_0035f5e4.p->bits[e->a].Set(e->b);
        }
    }
    n++;
    goto top;
out:
    D_0035f5e4.p->count = cnt;
    D_0035f5e4.p->cnt2 = cnt2;
    func_002a2ff8();
    for (i = 0; i < 15; i++) {
        if (!D_0035f5e4.p->r[i + 512].id) {
            D_0035f5e4.p->r[i + 512].c2 = 0;
            D_0035f5e4.p->r[i + 512].c3 = 0;
        } else {
            D_0035f5e4.p->r[i + 512].c2 = func_002ac748(i) != 0;
            D_0035f5e4.p->r[i + 512].c3 = func_002ac800(i) != 0;
        }
    }
}
}  // namespace n002a2de8

// 002a2ff8 (was src/anon/batch_wcx2.cpp)
namespace n002a2ff8 {
#define first(b) ((b)->fd)
// --------------------
// Sort the item list by kind, then by id within each kind; build per-kind groups and page counts.
struct Item2a2ff8 { u8 kind; u8 b1; u8 b2; u8 b3; u16 id; u16 x6; };
struct Grp2a2ff8 { u8 count; u8 pages; u16 pad; Item2a2ff8* first; };
struct Mgr2a2ff8 { Item2a2ff8 items[512]; Grp2a2ff8 grp[15]; s32 num; s32 x4220; s32 total; };
union MgrP2a2ff8 { Mgr2a2ff8* p; u32 u; u8 c; };
extern MgrP2a2ff8 D_0035f5e4 asm("D_0035f5e4");
#define G2a2ff8 D_0035f5e4.p
s32 func_002a43f0(void) asm("func_002a43f0");
s32 func_002a4380(s32 i) asm("func_002a4380");
s32 func_002954e0(s32 i) asm("func_002954e0");
/*TARGET 002a2ff8*/
void func_002a2ff8(void) asm("func_002a2ff8");
void func_002a2ff8(void)
{
    s32 i, j, n;
    Item2a2ff8 t;

    for (i = 0; i < G2a2ff8->num; i++) {
        for (j = i + 1; j < G2a2ff8->num; j++) {
            if (G2a2ff8->items[i].kind > G2a2ff8->items[j].kind) {
                t = G2a2ff8->items[i];
                G2a2ff8->items[i] = G2a2ff8->items[j];
                G2a2ff8->items[j] = t;
            }
        }
    }
    for (i = 0; i < G2a2ff8->num; i++) {
        for (j = i + 1; j < G2a2ff8->num; j++) {
            if (G2a2ff8->items[i].kind != G2a2ff8->items[j].kind) break;
            if (G2a2ff8->items[i].id > G2a2ff8->items[j].id) {
                t = G2a2ff8->items[i];
                G2a2ff8->items[i] = G2a2ff8->items[j];
                G2a2ff8->items[j] = t;
            }
        }
    }
    for (i = 0; i < G2a2ff8->num; i += n) {
        u8 k = G2a2ff8->items[i].kind;
        G2a2ff8->grp[k].first = &G2a2ff8->items[i];
        n = 1;
        for (j = i + 1; j < G2a2ff8->num; j++) {
            if (G2a2ff8->items[i].kind != G2a2ff8->items[j].kind) break;
            n++;
        }
        G2a2ff8->grp[k].count = n;
        G2a2ff8->grp[k].pages = n / 8;
        if (n % 8) G2a2ff8->grp[k].pages++;
    }
    for (i = 0; i < 15; i++) {
        if (func_002a43f0() && func_002a4380(i)) continue;
        if (G2a2ff8->grp[i].pages == 0) {
            if (func_002954e0(i)) G2a2ff8->grp[i].pages = 1;
        }
        G2a2ff8->total += G2a2ff8->grp[i].pages;
    }
}
}  // namespace n002a2ff8
#undef first
#undef G2a2ff8

