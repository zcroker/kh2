// Linked unit 0x00282c68-0x00283eb8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/gumi_pause.hpp"
#include "../tozawa/cmenu_config.hpp"
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
#include <stdarg.h>
#include "../tz/ui_accessors.hpp"
#include "../tozawa/item_info.hpp"
#include "../tozawa/multi_seq.hpp"
#include "../tozawa/party_info.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/chg_member.hpp"

// 00282c68 (was src/anon/batch_w32.cpp)
namespace n00282c68 {
struct KeyVal { s16 key, val; };
extern KeyVal D_003741f0[] asm("D_003741f0");
/*TARGET 00282c68*/
// 0x002670a0: definition moved into src/anon/unit_00265580.cpp

// Looks up key in a -1 terminated (key, value) table; last match wins.
s32 func_00282c68(s32 key) asm("func_00282c68");
// 0x002670a0: definition moved into src/anon/unit_00265580.cpp

// Looks up key in a -1 terminated (key, value) table; last match wins.
s32 func_00282c68(s32 key) {
    s32 r = -1;
    for (s32 i = 0; D_003741f0[i].key >= 0; i++)
        if (D_003741f0[i].key == key) r = D_003741f0[i].val;
    return r;
}
}  // namespace n00282c68

// 00282cb8 (was src/anon/batch_w68.cpp)
namespace n00282cb8 {
/* ---- 00282cb8 ---- */
extern s16 D_00374240[] asm("D_00374240");
void* func_002811b0(u32, u32) asm("func_002811b0");
s32 func_00282c68(void*) asm("func_00282c68");
void func_00259570(s32, void*, u32, u32) asm("func_00259570");
s32 func_002595e0(void) asm("func_002595e0");
u32 func_00192048(u32) asm("func_00192048");
void func_002595e8(void*, u32) asm("func_002595e8");
/*TARGET 00282cb8*/
void func_00282cb8(u8* p, s32 n) asm("func_00282cb8");
void func_00282cb8(u8* p, s32 n) {
    if (n < 0) {
        func_002595e8(p + 4132, func_00192048(0x8448));
        return;
    }
    s32 idx;
    if (n == 0) idx = func_00282c68(func_002811b0(*(u32*)(p + 4100), *(u32*)(p + 4108)));
    else idx = D_00374240[n];
    func_00259570(idx, p + 4132, 0, 1);
    func_002595e8(p + func_002595e0() + 4132, func_00192048(0x8448));
}
}  // namespace n00282cb8

// 00282d58 (was src/tozawa/item_info.cpp)
namespace Tz { // method 00282d58
/*TARGET 00282d58*/
// get_indexed_word

// 0x00269508: definition moved into src/anon/unit_00268b30.cpp

u32 ItemInfo::GetItemEmptyMsg(s32 a0) { return (u32)((s32)a0 + 4132); }
}  // Tz

// 00282d68 (was src/tz/ui_accessors.cpp)
namespace Tz { // method 00282d68
/*TARGET 00282d68*/
s64 ItemInfo::GetItemNoneMsgId() { return 0x8449; }
}  // Tz

// 00282d70 (was src/anon/batch_w95.cpp)
namespace n00282d70 {
struct SortEnt { u16 id; u16 x; u16 key; };
struct SortList { union { s32 n; u16 h; }; SortEnt e[1]; };
u8* func_001a8110(u8*) asm("func_001a8110");
/*TARGET 00282d70*/
// Assign each entry its table order (+1000 unless type 18), then sort by it.
void func_00282d70(SortList* l) asm("func_00282d70");
// Assign each entry its table order (+1000 unless type 18), then sort by it.
void func_00282d70(SortList* l) {
    u8* v = 0;
    s32 i = 0;
    for (;;) {
        v = func_001a8110(v);
        if (!v) break;
        for (s32 j = 0; j < l->n; j++) {
            if (*(u16*)v == l->e[j].id) {
                l->e[j].key = i;
                if (v[2] != 18) l->e[j].key = i + 1000;
            }
        }
        i++;
    }
    for (i = 0; i < l->n; i++) {
        for (s32 j = i + 1; j < l->n; j++) {
            if (l->e[j].key < l->e[i].key) {
                SortEnt t = l->e[i];
                l->e[i] = l->e[j];
                l->e[j] = t;
            }
        }
    }
}
}  // namespace n00282d70

// 00282ec0 (was src/anon/auto80_199_queue.cpp)
namespace n00282ec0 {
/*TARGET 00282ec0*/
u32 func_00282ec0(u32 a0) asm("_Z13func_00282ec0j");
u32 func_00282ec0(u32 a0) {
    u32 i = 0;
    u32 found = 0;

    if (D_00374230[0].a != 0) {
        do {
            if ((u32)D_00374230[i].b == a0) {
                if (func_001a6d08((u32)D_00374230[i].a) != 0) {
                    found = 1;
                    break;
                }
            }
            i += 1;
        } while (D_00374230[i].a != 0);
    }

    return found;
}
}  // namespace n00282ec0

// 00282f68 (was src/anon/perm_00282f68.cpp)
namespace n00282f68 {
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
s32 func_00103570() asm("_ZN2Tz17LoadDataGetSystemEv");
u8 *func_001063c0(s32, s32) asm("_ZN2Tz13LoadDataAllocEjj");
void func_002361a0(void *) asm("_ZN2YI5IMAGEC1Ev");
void func_00239700(void *) asm("func_00239700");
void func_002907c0(void *, s32, s32) asm("_ZN2Tz8MenuFileC1EP9ALLOCATORi");
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void func_0031a838(void *) asm("_Z10ErrorRaisePv");
extern short D_00347e40[] asm("D_00347e40");
extern u8 D_00347e60[] asm("D_00347e60");
extern volatile unsigned short D_00347f98[] asm("D_00347f98");
extern u8 *D_0035f2b0 asm("D_0035f2b0");
extern u8 *D_0035f2b4 asm("D_0035f2b4");
extern u8 *D_0035f2b8 asm("D_0035f2b8");
/*TARGET 00282f68*/
void func_00282f68(void) asm("func_00282f68");
void func_00282f68(void)
{
  s32 new_var;
  u8 *a = func_001063c0(0x18, func_00103570());
  new_var = func_00103570();
  func_002907c0(a, new_var, 10);
  D_0035f2b0 = a;
  u8 *b = func_001063c0(0x20, func_00103570());
  D_0035f2b4 = b;
  func_002fde18(b, 0, 0x20);
  u32 v60 = (u32) D_00347e60;
  u8 *p = func_001063c0(0x840, func_00103570());
  func_002361a0(p);
  u32 v98 = (u32) D_00347f98;
  u8 *q = p + 0x1a0;
  *((u32 *) (p + 0x1a0)) = v60;
  *((u32 *) (p + 0x1ac)) = 0;
  func_00239700(p + 0x1b8);
  *((u32 *) (q + 0x198)) = 0;
  *((u32 *) (p + 0x1a0)) = (u32) D_00347e40;
  u8 *r = p + 0x354;
  *((u32 *) (p + 0x354)) = v98;
  func_0031a838(p + 0x360);
  *((u32 *) (p + 0x354)) = v60;
  func_00239700(p + 0x36c);
  *((u32 *) (r + 0x198)) = 0;
  *((u32 *) (p + 0x354)) = (u32) D_00347e40;
  *((u32 *) (p + 0x508)) = v98;
  func_0031a838(p + 0x514);
  *((u32 *) (p + 0x508)) = v60;
  func_00239700(p + 0x520);
  *((u32 *) (p + 0x6a0)) = v98;
  func_0031a838(p + 0x6ac);
  *((u32 *) (p + 0x6a0)) = v60;
  func_00239700(p + 0x6b8);
  D_0035f2b8 = p;
}
}  // namespace n00282f68

// 002830b8 (was src/anon/batch_w88.cpp)
namespace n002830b8 {
void func_00239870(u8*) asm("func_00239870");
void func_00106420(void*) asm("func_00106420");
void func_0031abd8(u8*) asm("func_0031abd8");
void func_0031acc0(u8*) asm("func_0031acc0");
void func_0031a840(u8*) asm("func_0031a840");
void func_002361d0(u8*) asm("func_002361d0");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8* D_0035f2b0 asm("D_0035f2b0");
extern u8* D_0035f2b4 asm("D_0035f2b4");
extern u8* D_0035f2b8 asm("D_0035f2b8");
typedef void (*VF2830b8)(u8*);
/*TARGET 002830b8*/
void func_002830b8(void) asm("func_002830b8");
void func_002830b8(void) {
    if (D_0035f2b0) {
        (*(VF2830b8*)(*(u8**)D_0035f2b0 + 4))(D_0035f2b0);
        D_0035f2b0 = 0;
    }
    if (D_0035f2b4) {
        func_00106420(D_0035f2b4);
        D_0035f2b4 = 0;
    }
    u8* s = D_0035f2b8;
    u8* sub = s + 416;
    if (s) {
        func_0031abd8(s + 1696);
        func_0031abd8(s + 1288);
        func_0031acc0(s + 852);
        *(u32*)sub = (u32)D_00347e60;
        func_00239870(s + 440);
        func_0031a840(sub);
        func_002361d0(s);
        func_00106420(s);
        D_0035f2b8 = 0;
    }
}
}  // namespace n002830b8

// 00283180 (was src/anon/tiny_auto80_queue.cpp)
namespace n00283180 {
void func_002835a8(...) asm("func_002835a8");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 00283180*/
void func_00283180() asm("_Z13func_00283180v");
void func_00283180() {
    if (func_00287bc0() == 37u) {
        func_002835a8();
    }
}
}  // namespace n00283180

// 002831b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002831b0 {
void func_002835d8(...) asm("func_002835d8");
u32 func_00287bc0(...) asm("func_00287bc0");
/*TARGET 002831b0*/
void func_002831b0() asm("_Z13func_002831b0v");
void func_002831b0() {
    if (func_00287bc0() == 37u) {
        func_002835d8();
    }
}
}  // namespace n002831b0

// 002831e0 (was src/anon/batch_w33.cpp)
namespace n002831e0 {
// 0x002670f8: definition moved into src/anon/unit_00265580.cpp

void func_00257708(s32) asm("func_00257708");
extern s32* D_0035f2b4 asm("D_0035f2b4");
void func_00283d00(void*) asm("func_00283d00");
void func_00283f50(void) asm("func_00283f50");
void func_002833f8(void) asm("func_002833f8");
/*TARGET 002831e0*/
void func_002831e0(void* a, s32 b) asm("func_002831e0");
void func_002831e0(void* a, s32 b) {
    func_00257708(1);
    *D_0035f2b4 = b;
    func_00283d00(a);
    func_00283f50();
    func_002833f8();
}
}  // namespace n002831e0

// 00283230 (was src/anon/batch_w291.cpp)
namespace n00283230 {
struct W291P28 { s32 x0; s8 a[9]; s8 b13; s8 b14; };
struct W291T28 { u8 pad[6]; u8 f6; u8 pad7; };
struct W291Q28 { u8 pad[8]; u64 flags; };
// 0x0025b050: definition moved into src/anon/unit_002588e8.cpp

extern W291P28* D_0035f2b4 asm("D_0035f2b4");
extern W291T28 D_003742c8[] asm("D_003742c8");
W291Q28* func_00167f18(s32) asm("func_00167f18");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_002839f0(s32) asm("func_002839f0");
s32 func_00283618() asm("func_00283618");
void func_00284048() asm("func_00284048");
void func_00283f50() asm("func_00283f50");
void func_002833f8() asm("func_002833f8");
void func_00287cc0(s32) asm("func_00287cc0");
void func_00257708(s32) asm("func_00257708");
void func_00283c50() asm("func_00283c50");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_002937c0(s32) asm("func_002937c0");
s32 func_00170cd0() asm("func_00170cd0");
void func_00283fb0() asm("func_00283fb0");
void func_00283790() asm("func_00283790");
s32 func_00283668() asm("func_00283668");
void func_00242618(s32, s32) asm("func_00242618");
void func_00283e48() asm("func_00283e48");
/*TARGET 00283230*/
void func_00283230() asm("func_00283230");
void func_00283230()
{
    W291Q28* q = func_00167f18(0);
    s32 st = func_00287cd0();
    if (st == 2) {
        W291P28* p = D_0035f2b4;
        s32 i = p->b14;
        s32 r;
        if (i + 1 >= p->b13)
            r = func_00283618();
        else
            r = func_002839f0(D_003742c8[p->a[i]].f6 != D_003742c8[p->a[i + 1]].f6);  // entry416_by_masked_index
        if (r) return;
        func_00284048();
        D_0035f2b4->b14++;
        if (D_0035f2b4->b14 >= D_0035f2b4->b13) {
            func_00257708(0);
            func_00283c50();
            func_00287bd0(D_0035f2b4->x0, 0);
            if (D_0035f2b4->x0 == 0) {
                func_002937c0(1);
                return;
            }
            func_00287cc0(1);
            return;
        }
        func_00283f50();
        func_002833f8();
        func_00287cc0(0);
        return;
    }
    if (func_00170cd0()) return;
    if (!func_002839f0(0)) {  // entry416_by_masked_index
        func_00283fb0();
        func_00283790();
    }
    if (st == 0) {
        if (!func_00283668()) return;
        func_00287cc0(1);
    }
    if (q->flags & 4) {
        func_00242618(2, 1);
        func_00283e48();
        func_00287cc0(2);
    }
}
}  // namespace n00283230

// 002833f8 (was src/anon/batch_w1926_nsa.cpp)
namespace n002833f8 {
struct Ent283 { u8 p[6]; u8 idx; u8 p7; };
s32 u_call4_00139d78_283(u8*) asm("_Z16u_call4_00139d78jjjj");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void getXY_283(u8*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void resetA_283(u8*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
u32 u_tail4_00192048_283(u32) asm("_Z16u_tail4_00192048jjjj");
s32 msgcopy_283(u32, s8*) asm("_ZNK2YS7MESSAGE4copyEPc");
void func_00192cc0(s8*, const char*, s32, s32) asm("func_00192cc0");
extern u8* D_0035f2b8 asm("D_0035f2b8");
extern s8* D_0035f2b4 asm("D_0035f2b4");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern char D_00374250[] asm("D_00374250");
extern Ent283 D_003742c8[] asm("D_003742c8");
extern u16 D_00374318[] asm("D_00374318");
/*TARGET 002833f8*/
void func_002833f8(void) asm("func_002833f8");
void func_002833f8(void) {
    if (!u_call4_00139d78_283(D_0035f2b8 + 852)) {
        func_0028d980(D_0035f2b8 + 852, 30022, D_0035ef68, D_0035ef64, D_0035f03c, 18, 19, -1, 0);
        *(s8**)(D_0035f2b8 + 1260) = D_0035f2b4 + 15;
        getXY_283(D_0035f2b8 + 852);
        resetA_283(D_0035f2b8 + 852);
        *(s32*)(D_0035f2b8 + 1284) = 2;
    }
    s8* s = D_0035f2b4 + 15;
    s += msgcopy_283(u_tail4_00192048_283(0xcbd8), s);
    func_00192cc0(s, D_00374250, D_0035f2b4[14] + 1, D_0035f2b4[13]);
    if (!u_call4_00139d78_283(D_0035f2b8 + 416)) {
        func_0028d980(D_0035f2b8 + 416, 30022, D_0035ef68, D_0035ef64, D_0035f03c, 15, 16, -1, 0);
        getXY_283(D_0035f2b8 + 416);
        resetA_283(D_0035f2b8 + 416);
        *(s32*)(D_0035f2b8 + 848) = 2;
    }
    u8* o = D_0035f2b8 + 416;
    *(u32*)(o + 408) = u_tail4_00192048_283(D_00374318[D_003742c8[D_0035f2b4[D_0035f2b4[14] + 4]].idx]);
}
}  // namespace n002833f8

// 002835a8 (was src/anon/tiny_auto80_solver.cpp)
namespace n002835a8 {
u32 func_00283900(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00283900jjjjjjjj");
u32 func_0028dac8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0028dac8jjjjjjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 002835a8*/
u32 func_002835a8(void) asm("_Z13func_002835a8v");
u32 func_002835a8(void) {
    ((u32(*)(u32, u32))func_0028dac8)(*(u32*)((u8*)&D_00360000 - 3400) + 852, 20);
    return ((u32(*)(u32))func_00283900)(1);
}
}  // namespace n002835a8

// 002835d8 (was src/anon/batch_w13.cpp)
namespace n002835d8 {
s32 func_00139d78(void*) asm("func_00139d78");
void func_00139510(void*) asm("func_00139510");
void func_00283960(s32) asm("func_00283960");
extern void (*D_0035e380[])(void) asm("D_0035e380");
extern u8* D_0035f2b8 asm("D_0035f2b8");
/*TARGET 002835d8*/
void func_002835d8(void) asm("func_002835d8");
void func_002835d8(void) {
    if (func_00139d78(D_0035f2b8 + 852)) {
        func_00139510(D_0035f2b8 + 852);
    }
    func_00283960(1);
}
}  // namespace n002835d8

// 00283618 (was src/anon/batch_w34.cpp)
namespace n00283618 {
// vu_store_w_splat
s32 func_00139d78(void*) asm("func_00139d78");
void func_002839f0(s32) asm("func_002839f0");
extern u8* D_0035f2b8 asm("D_0035f2b8");
// Keeps the final call from becoming a sibling call.
struct NoTail {
    ~NoTail() {}
};
/*TARGET 00283618*/
void func_00283618(void) asm("func_00283618");
void func_00283618(void) {
    NoTail g;
    if (func_00139d78(D_0035f2b8 + 852)) return;
    if (!func_00139d78(D_0035f2b8 + 416)) func_002839f0(1);
}
}  // namespace n00283618

// 00283668 (was src/anon/batch_w89.cpp)
namespace n00283668 {
extern u8* D_0035f2b8 asm("D_0035f2b8");
s32 func_00139d78(void*) asm("func_00139d78");
/*TARGET 00283668*/
// True when every active sub-object is in its expected state.
s32 func_00283668(void) asm("func_00283668");
// True when every active sub-object is in its expected state.
s32 func_00283668(void) {
    s32 ok = 1;
    if (func_00139d78(D_0035f2b8 + 852) && *(s32*)(D_0035f2b8 + 1240) != 0x13) ok = 0;
    if (ok) {
        if (func_00139d78(D_0035f2b8 + 416) && *(s32*)(D_0035f2b8 + 804) != 0x10) ok = 0;
        if (ok) {
            if (func_00139d78(D_0035f2b8 + 1288) && *(s32*)(D_0035f2b8 + 1676) != 2) ok = 0;
            if (ok) {
                if (func_00139d78(D_0035f2b8 + 1696) && *(s32*)(D_0035f2b8 + 2084) != 5) ok = 0;
            }
        }
    }
    return ok;
}
}  // namespace n00283668

// 00283730 (was src/anon/auto80_199_queue.cpp)
namespace n00283730 {
/*TARGET 00283730*/
void func_00283730(void) asm("_Z13func_00283730v");
void func_00283730(void) {
    func_0028da70(D_0035f2b8 + 852, 19);
    func_0028da70(D_0035f2b8 + 416, 16);
    func_0028da70(D_0035f2b8 + 1288, 2);
    func_0028da70(D_0035f2b8 + 1696, 5);
}
}  // namespace n00283730

// 00283790 (was src/anon/batch_w8011.cpp)
namespace n00283790 {
struct Sub283790 { u8 pad[184]; u32 flags; };
struct Obj283790 { u8 pad[24]; Sub283790 sub; u8 pad2[392 - 24 - 188]; s32 mode; u8 pad3[405 - 396]; u8 on; u8 pad4[2]; };
struct Ent283790 { u8 pad[6]; u8 g; u8 pad7; };
struct St283790 { u8 pad[4]; s8 list[9]; s8 n; s8 cur; };
extern u8* D_0035f2b8 asm("D_0035f2b8");
extern St283790* D_0035f2b4 asm("D_0035f2b4");
extern u32 D_0035f03c asm("D_0035f03c");
extern Ent283790 D_003742c8[] asm("D_003742c8");
s32 func_00139d78(void*) asm("func_00139d78");
static inline void SetFlag283790(u8* p) { ((Sub283790*)p)->flags |= 8; }
u32 func_0023f1b0(u32) asm("func_0023f1b0");
u32 func_0023c4b8(u32, s32) asm("func_0023c4b8");
void func_001386e0(void*, s32, u32, u8*, s32, s32) asm("func_001386e0");
/*TARGET 00283790*/
void func_00283790(void) asm("func_00283790");
void func_00283790(void)
{
    s32 same = 0;
    u8* b;
    if (!func_00139d78(D_0035f2b8 + 1288)) {
        u32 v = func_0023c4b8(func_0023f1b0(D_0035f03c), 0);
        b = D_0035f2b8;
        Obj283790* o = (Obj283790*)(b + 1288);
        func_001386e0(o, 30022, v, b, 1, 0);
        o->mode = 2;
        o->on = 1;
        SetFlag283790(b + 1312);
    }
    St283790* s = D_0035f2b4;
    if (s->cur + 1 < s->n) same = D_003742c8[s->list[s->cur]].g == D_003742c8[s->list[s->cur + 1]].g;
    if (!func_00139d78(D_0035f2b8 + 1696) && same) {
        u32 v = func_0023c4b8(func_0023f1b0(D_0035f03c), 0);
        b = D_0035f2b8;
        Obj283790* o = (Obj283790*)(b + 1696);
        func_001386e0(o, 30022, v, b, 4, 0);
        o->mode = 5;
        o->on = 1;
        SetFlag283790(b + 1720);
    }
}
}  // namespace n00283790

// 00283900 (was src/anon/auto80_199_queue.cpp)
namespace n00283900 {
/*TARGET 00283900*/
void func_00283900(u32 a0) asm("_Z13func_00283900j");
void func_00283900(u32 a0) {
    if ((a0 & 0xffu) != 0) {
        func_0028dac8(D_0035f2b8 + 416, 17);
    }
    func_0028dac8(D_0035f2b8 + 1288, 3);
    func_0028dac8(D_0035f2b8 + 1696, 6);
}
}  // namespace n00283900

// 00283960 (was src/anon/auto80_199_queue.cpp)
namespace n00283960 {
/*TARGET 00283960*/
void func_00283960(u32 a0) asm("_Z13func_00283960j");
void func_00283960(u32 a0) {
    if ((a0 & 0xffu) != 0) {
        if (func_00139d78(D_0035f2b8 + 416) != 0) {
            func_00139510(D_0035f2b8 + 416);
        }
    }

    if (func_00139d78(D_0035f2b8 + 1288) != 0) {
        func_00139510(D_0035f2b8 + 1288);
    }

    if (func_00139d78(D_0035f2b8 + 1696) != 0) {
        func_00139510(D_0035f2b8 + 1696);
    }
}
}  // namespace n00283960

// 002839f0 (was src/anon/auto80_199_queue.cpp)
namespace n002839f0 {
/*TARGET 002839f0*/
u32 func_002839f0(u32 a0) asm("_Z13func_002839f0j");
u32 func_002839f0(u32 a0) {  // entry416_by_masked_index
    u32 v = 0;
    if ((a0 & 0xffu) != 0) {
        v = func_00139d78(D_0035f2b8 + 416);
    }

    if (v == 0) {
        v = func_00139d78(D_0035f2b8 + 1288);
        if (v == 0) {
            v = func_00139d78(D_0035f2b8 + 1696);
        }
    }
    return v;
}
}  // namespace n002839f0

// 00283a58 (was src/anon/auto80_199_queue.cpp)
namespace n00283a58 {
/*TARGET 00283a58*/
u32 func_00283a58(void) asm("_Z13func_00283a58v");
u32 func_00283a58(void) {
    u32 out;
    if (func_00181500(2267) == 0) {
        goto L80;
    }
    if (func_00181500(2256) == 0) {
        out = 0;
        goto Lend;
    }

L80:
    if (func_00181500(2256) == 0) {
        goto Lset2;
    }
    if (func_00181500(2257) == 0) {
        out = 1;
        goto Lend;
    }
Lset2:
    out = 2;
Lend:
    return out;
}
}  // namespace n00283a58

// 00283ab8 (was src/anon/batch_w80.cpp)
namespace n00283ab8 {
// ---- unit 16 (i.cpp)
struct U16_ShopEnt { u8 pad[4]; u16 id; u8 type; u8 pad2; };
extern U16_ShopEnt D_003742c8[] asm("D_003742c8");
s32 func_00181500(u32) asm("func_00181500");
/*TARGET 00283ab8*/
s32 func_00283ab8(s32 type) asm("func_00283ab8");
s32 func_00283ab8(s32 type) {
    s32 i;
    s32 found = 0;
    for (i = 0; D_003742c8[i].id != 0; i++) {
        if (type == -1 || D_003742c8[i].type == type) {
            if (func_00181500(D_003742c8[i].id)) { found = 1; break; }
        }
    }
    return found;
}
}  // namespace n00283ab8

// 00283b78 (was src/anon/batch_w1595.cpp)
namespace n00283b78 {
static inline bool w1595_TestBit(u32* b, u32 i) { return (b[i >> 5] & (1 << (i & 31))) != 0; }
s32 func_00258048() asm("func_00258048");
s32 func_00283ab8(s32) asm("func_00283ab8");
s32 func_00181500(u16) asm("func_00181500");
struct W1595Rec { s32 a; u16 id; u16 b; };
extern W1595Rec D_003742c8[] asm("D_003742c8");
/*TARGET 00283b78*/
s32 func_00283b78(void) asm("func_00283b78");
s32 func_00283b78(void) {
    s32 r = 0;
    u8* st = (u8*)func_00258048();
    if (!func_00283ab8(-1)) return 0;
    for (u32 i = 0; D_003742c8[i].id != 0; i++) {
        if (func_00181500(D_003742c8[i].id) && !w1595_TestBit((u32*)(st + 200), i)) { r = 1; break; }
    }
    return r;
}
}  // namespace n00283b78

// 00283c50 (was src/anon/batch_w1787_nsa.cpp)
namespace n00283c50 {
/* 00283c50 */
struct E8b283c50 { u32 a; u16 id; u16 b; };
extern E8b283c50 D_003742c8[] asm("D_003742c8");
s32 func_00181500(u16) asm("func_00181500");
struct Sv283c50 { u8 pad[200]; u32 bits[1]; };
Sv283c50* func_00258048() asm("func_00258048");
/*TARGET 00283c50*/
void func_00283c50(void) asm("func_00283c50");
void func_00283c50(void) {
    u32 i = 0;
    Sv283c50* sv = func_00258048();
    while (D_003742c8[i].id) {
        if (func_00181500(D_003742c8[i].id)) {
            u32 m = 1 << (i & 31);
            u32* w = (u32*)((i >> 5) * 4 + (u32)sv->bits);
            if (!(*w & m)) *w |= m;
        }
        i++;
    }
}
}  // namespace n00283c50

// 00283d00 (was src/anon/batch_w1262.cpp)
namespace n00283d00 {
// 0x001d63a8: definition moved into src/anon/unit_001d63a8.cpp



struct T446
{
  u32 a;
  u16 id;
  u8 kind;
  u8 pad;
};
extern T446 D_003742c8[] asm("D_003742c8");
extern u8 *D_0035f2b4 asm("D_0035f2b4");
u8* func_00258048(void) asm("func_00258048");
void func_002fde18(void *, s32, s32) asm("func_002fde18");
s32 func_00181500_c(u16) asm("func_00181500");
inline u8 *inline_fn(u8 *arg0)
{
  return arg0 + 200;
}
/*TARGET 00283d00*/
void func_00283d00(s32 kind) asm("func_00283d00");
void func_00283d00(s32 kind)
{
  u32 i = 0;
  s32 n = 0;
  u8 *save = func_00258048();
  func_002fde18(D_0035f2b4 + 4, 0, 9);
  for (; (&D_003742c8[i])->id != 0; i++)
  {
    if ((kind != (-1)) && (D_003742c8[i].kind != kind))
    {
      continue;
    }
    if (!func_00181500_c(D_003742c8[i].id))
    {
      continue;
    }
    if ((kind == (-1)) && (((u32 *) inline_fn(save))[i >> 5] & (1 << (i & 31))))
    {
      continue;
    }
    D_0035f2b4[n + 4] = i;
    n++;
  }

  D_0035f2b4[13] = n;
  D_0035f2b4[14] = 0;
}
}  // namespace n00283d00

// 00283e48 (was src/anon/batch_w37.cpp)
namespace n00283e48 {
struct E283 { u8 _0[6]; u8 kind; u8 _7; };
extern E283 D_003742c8[] asm("D_003742c8");
extern s8* D_0035f2b4 asm("D_0035f2b4");
void func_002835a8(void) asm("func_002835a8");
void func_00283900(u32) asm("func_00283900");
/*TARGET 00283e48*/
void func_00283e48(void) asm("func_00283e48");
void func_00283e48(void) {
    s8* p = D_0035f2b4;
    s32 i = p[14];
    if (i + 1 >= p[13]) {
        func_002835a8();
        return;
    }
    func_00283900(D_003742c8[p[i + 4]].kind != D_003742c8[p[i + 5]].kind);
}
}  // namespace n00283e48

