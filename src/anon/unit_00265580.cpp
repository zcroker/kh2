// Linked unit 0x00265580-0x00267e00 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/cmenu_stat.hpp"
#include "../tozawa/cmenu_equip.hpp"
#include "../tozawa/cmenu_top.hpp"

// 00265580 (was src/anon/auto80_199_queue.cpp)
namespace n00265580 {
/*TARGET 00265580*/
// 0x00263db0: definition moved into src/anon/unit_002632d0.cpp

void func_00265580(void) asm("_Z13func_00265580v");
// 0x00263db0: definition moved into src/anon/unit_002632d0.cpp

void func_00265580(void) {
    u32 s0 = func_00257770();

    if (func_00287bc0() != 23) {
        return;
    }

    func_0028dac8(s0, 142);
    if (func_0028acb8(D_0035f01c) == 0) {
        func_0028aa40(D_0035f01c);
    }
}
}  // namespace n00265580

// 002655e8 (was src/anon/batch_w82.cpp)
namespace n002655e8 {
struct VObj82 { struct VT { void* f[8]; }* vt; };
extern u8* D_0035f01c asm("D_0035f01c");
static inline void VCall5_82(VObj82* o) { ((void (*)(VObj82*))o->vt->f[5])(o); }
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_0028abe0(u8*) asm("func_0028abe0");
u8* func_00257770(void) asm("func_00257770");
void func_00139510(u8*) asm("func_00139510");
/*TARGET 002655e8*/
// 0x0025e370: definition moved into src/anon/unit_0025da20.cpp

void func_002655e8(void) asm("func_002655e8");
// 0x0025e370: definition moved into src/anon/unit_0025da20.cpp

void func_002655e8(void)
{
    u8* base = func_00257770();
    s32 i;
    if (func_00139d78(base)) func_00139510(base);
    for (i = 0; i < 20; i++) {
        u8* e = base + i * 436;
        if (func_00139d78(e + 13840)) VCall5_82((VObj82*)(e + 13840));
        if (func_00139d78(e + 24304)) VCall5_82((VObj82*)(e + 24304));
    }
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
}
}  // namespace n002655e8

// 002656c0 (was src/anon/batch_w56.cpp)
namespace n002656c0 {
// Local type whose non-trivial destructor keeps gcc from emitting a sibling call.
struct NoTail { ~NoTail() {} };
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// 002656c0
u8* func_00257770(void) asm("func_00257770");
void func_0028acc8(u32) asm("func_0028acc8");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 002656c0*/
void func_002656c0(void) asm("func_002656c0");
void func_002656c0(void)
{
    NoTail g;
    u8* p = func_00257770();
    if (u_call4_00139d78(p)) return;
    for (s32 i = 0; i < 20; i++) {
        if (u_call4_00139d78(p + 13840)) return;
        if (u_call4_00139d78(p + 24304)) return;
        p += 436;
    }
    func_0028acc8(D_0035f01c);
}
}  // namespace n002656c0

// 00265740 (was src/anon/batch_w1581_g.cpp)
namespace n00265740 {
u32 func_00257770() asm("func_00257770");
u32 func_00139d78(u32) asm("func_00139d78");
/*TARGET 00265740*/
// 0x00262f58: definition moved into src/anon/unit_0025f6b8.cpp

s32 func_00265740(void) asm("func_00265740");
// 0x00262f58: definition moved into src/anon/unit_0025f6b8.cpp

s32 func_00265740(void) {
    u32 p = func_00257770();
    func_00139d78(p);
    return *(s32*)(p + 0x184) == 0x8D;
}
}  // namespace n00265740

// 00265780 (was src/anon/batch_w3.cpp)
namespace n00265780 {
u32 func_00257770() asm("func_00257770");
void func_0028da70(u32, u32) asm("func_0028da70");
/*TARGET 00265780*/
void func_00265780() asm("func_00265780");
void func_00265780() { func_0028da70(func_00257770(), 141); }
}  // namespace n00265780

// 002657a8 (was src/anon/batch_w8010.cpp)
namespace n002657a8 {
// ---- 002657a8
struct Rec { u16 id; u16 x; s16 idx; };
struct Row { Rec r[10]; };
struct Elem { u8 pad[0x18]; u8 sub[0x180]; s32 v; u8 pad2[0x18]; };
struct Big { u8 pad[0x3610]; Elem e[20]; };
struct Info { u8 pad[0x18]; u32 mask; };
struct Tex { s16 h; s16 pad; };
Big* func_00257770(void) asm("func_00257770");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_00138c10(Elem*, s32) asm("func_00138c10");
void func_00138c68(Elem*, s32, s32) asm("func_00138c68");
s32 func_0023aa98(void*) asm("func_0023aa98");
s32 func_0023aa78(void*) asm("func_0023aa78");
s32 func_00192048(u16) asm("func_00192048");
s32 func_0028b040(s32) asm("func_0028b040");
u32 func_002670a0(s32) asm("func_002670a0");
void func_00266df8(u32) asm("func_00266df8");
void func_00265c78(void) asm("func_00265c78");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f01c asm("D_0035f01c");
extern u8* D_0035f0e4 asm("D_0035f0e4");
extern Tex D_00373500[] asm("D_00373500");
extern Row D_00373530[2] asm("D_00373530");
extern Row D_003735a8[2] asm("D_003735a8");
extern Row D_00373620[2] asm("D_00373620");
/*TARGET 002657a8*/
void func_002657a8(void) asm("func_002657a8");
void func_002657a8(void) {
    Big* b = func_00257770();
    s32 i;
    Row* tbl[2] = { 0, 0 };
    func_002fde18(D_0035f0e4 + 0x524, 0, 0x280);
    Elem* e = b->e;
    for (i = 19; i >= 0; i--) {
        func_00138c10(e, D_0035ef6c);
        e->v = 0;
        e++;
    }
    u32 t = func_002670a0(func_0028b040(D_0035f01c));
    func_00266df8(t);
    switch (t) {
    case 0: case 7: case 8: case 9:
        for (i = 0; i < 2; i++) tbl[i] = &D_00373530[i];
        break;
    case 1: case 2: case 3: case 4: case 5:
        for (i = 0; i < 2; i++) tbl[i] = &D_003735a8[i];
        break;
    case 6:
        for (i = 0; i < 2; i++) tbl[i] = &D_00373620[i];
        break;
    }
    Row** tp = tbl;
    s32 off = 0;
    for (i = 0; i < 2; i++, tp++, off += 10 * sizeof(Elem)) {
        s32 cnt = 0;
        for (s32 j = 0; j < 10; j++) {
            if (((Info*)D_0035f0e4)->mask & (1 << (i * 10 + j))) {
                Elem* o = &((Big*)(off + (u32)b))->e[j];
                func_00138c10(o, D_00373500[(*tp)->r[j].idx].h);
                s32 a = func_0023aa98(o->sub);
                func_00138c68(o, i * a, cnt * func_0023aa78(o->sub));
                cnt++;
                o->v = func_00192048((*tp)->r[j].id);
            }
        }
    }
    func_00265c78();
}
}  // namespace n002657a8

// 00265a30 (was src/anon/auto80_199_queue.cpp)
namespace n00265a30 {
/*TARGET 00265a30*/
void Tz__CmAbility__FadeOutAll(void) asm("_Z25Tz__CmAbility__FadeOutAllv");
void Tz__CmAbility__FadeOutAll(void) {
    u32 s0 = func_00257770();

    if (func_00287bc0() != 24) {
        return;
    }

    func_0028dac8(s0, 322);

    if (func_0028acb8(D_0035f01c) == 0) {
        func_0028aa40(D_0035f01c);
    }

    if (func_0028acb8(D_0035f020) == 0) {
        func_0028aa40(D_0035f020);
    }
}
}  // namespace n00265a30

// 00265ab8 (was src/anon/batch_w90.cpp)
namespace n00265ab8 {
struct VObj { void** vt; };
s32 func_0028acc8(void*) asm("func_0028acc8");
s32 func_00139d78(void*) asm("func_00139d78");
// 00256f18
extern void* D_0035f01c asm("D_0035f01c");
extern void* D_0035f020 asm("D_0035f020");
// 0x0025d918: definition moved into src/anon/unit_002588e8.cpp

// 00265ab8: stop every active effect slot.
typedef void (*VoidFn)(void*);
static inline void StopIfActive(VObj* o) { if (func_00139d78(o)) ((VoidFn)o->vt[5])(o); }
u8* func_00257770(void) asm("func_00257770");
void func_00139510(void*) asm("func_00139510");
void func_0028abe0(void*) asm("func_0028abe0");
/*TARGET 00265ab8*/
void func_00265ab8(void) asm("func_00265ab8");
void func_00265ab8(void)
{
    u8* w = func_00257770();
    if (func_00139d78(w)) func_00139510(w);
    u8* p = w;
    for (s32 i = 19; i >= 0; i--) {
        StopIfActive((VObj*)(p + 24304));
        p += 436;
    }
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
}
}  // namespace n00265ab8

// 00265b88 (was src/anon/batch_wcx2.cpp)
namespace n00265b88 {
// 0x001c0150: definition moved into src/anon/unit_001bff88.cpp

// ---- 00265b88
u8* func_00257770_5b88() asm("func_00257770");
s32 func_00139d78_5b88(u8*) asm("func_00139d78");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
s32 func_0028acc8(u32) asm("func_0028acc8");
struct NoTail_00265b88 { ~NoTail_00265b88() {} };
/*TARGET 00265b88*/
void func_00265b88() asm("func_00265b88");
void func_00265b88() {
    NoTail_00265b88 nt;
    u8* o = func_00257770_5b88();
    if (func_00139d78_5b88(o)) return;
    o += 24304;
    for (s32 i = 0; i < 20; i++, o += 436) {
        if (func_00139d78_5b88(o)) return;
    }
    if (func_0028acc8(D_0035f01c)) return;
    func_0028acc8(D_0035f020);
}
}  // namespace n00265b88

// 00265c10 (was src/anon/batch_w1581_g.cpp)
namespace n00265c10 {
u32 func_00257770() asm("func_00257770");
u32 func_00139d78(u32) asm("func_00139d78");
/*TARGET 00265c10*/
s32 func_00265c10(void) asm("func_00265c10");
s32 func_00265c10(void) {
    u32 p = func_00257770();
    func_00139d78(p);
    return *(s32*)(p + 0x184) == 0x141;
}
}  // namespace n00265c10

// 00265c50 (was src/anon/batch_w4.cpp)
namespace n00265c50 {
void* func_00257770(void) asm("func_00257770");
void func_0028da70(void*, s32) asm("func_0028da70");
/*TARGET 00265c50*/
void func_00265c50(void) asm("func_00265c50");
void func_00265c50(void) {
    func_0028da70(func_00257770(), 321);
}
}  // namespace n00265c50

// 00265c78 (was src/anon/batch_w3709_g.cpp)
namespace n00265c78 {
u8* func_001058e8() asm("func_001058e8");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
u32 func_002670a0(s32) asm("func_002670a0");
u32 func_00257070(s32) asm("func_00257070");
u8* func_00281180(u32, s32) asm("func_00281180");
s32 func_00192cc0(u8*, const char*, ...) asm("func_00192cc0");
s32 func_00188bb0(u32, u32) asm("func_00188bb0");
u8 func_00267150(s32) asm("func_00267150");
u8* YS__SAVERAM_BATTLE__get_formram(u8*, u32) asm("YS__SAVERAM_BATTLE__get_formram");
u8 func_001d5c70(u32, u8*) asm("func_001d5c70");
u8* func_001d5c10(u32, u8*) asm("func_001d5c10");
u8 func_001d5d20() asm("func_001d5d20");
u8* func_001d5cd0() asm("func_001d5cd0");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f010 asm("D_0035f010");
extern u8* D_0035f0e4 asm("D_0035f0e4");
extern "C" const s32 D_0037336c = 100;  // .rodata word no code loads
extern const char D_00373370[8] asm("D_00373370") __attribute__((aligned(4))) = "%d";
extern const char D_00373378[8] asm("D_00373378") __attribute__((aligned(4))) = "%d/%d";
extern const char D_00373380[8] asm("D_00373380") __attribute__((aligned(4))) = "%d%%";
/*TARGET 00265c78*/
void func_00265c78(void) asm("func_00265c78");
void func_00265c78(void) {
    u8* sv;
    u32 v;
    s32 d;
    u8 lv;
    u8* nx;
    sv = func_001058e8() + 0x24F0;
    if (func_00287bc0() == 23) v = func_002670a0(func_0028b040(D_0035f01c));
    else v = func_00257070(23);
    switch (v) {
    case 0: case 7: case 8: case 9: {
        s32 k = v ? v - 6 : 0;
        u8* o;
        if (v) o = func_00281180(D_0035f010, k);
        else o = *(u8**)D_0035f0e4;
        func_00192cc0(D_0035f0e4 + 0x524, D_00373370, *(u8*)(*(u32*)(o + 0x244) + 0xF));
        func_00192cc0(D_0035f0e4 + 0x544, D_00373370, *(s32*)(sv + 0x11F0));
        u32 y = *(u32*)(o + 0x254);
        func_00192cc0(D_0035f0e4 + 0x564, D_00373370, func_00188bb0(*(u32*)(o + 0x244), y));
        { s32 b = *(s32*)(o + 4); func_00192cc0(D_0035f0e4 + 0x584, D_00373378, *(s32*)(o + 0), b); }
        func_00192cc0(D_0035f0e4 + 0x5A4, D_00373378, *(s32*)(o + 0x180), *(s32*)(o + 0x184));
        func_00192cc0(D_0035f0e4 + 0x5C4, D_00373378, func_00267150(k), *(u16*)(o + 0x18E));
        func_00192cc0(D_0035f0e4 + 0x664, D_00373370, *(u16*)(o + 0x188));
        func_00192cc0(D_0035f0e4 + 0x684, D_00373370, *(u16*)(o + 0x18A));
        func_00192cc0(D_0035f0e4 + 0x6A4, D_00373370, *(u16*)(o + 0x18C));
        func_00192cc0(D_0035f0e4 + 0x6C4, D_00373380, 100 - o[0x1A9]);
        func_00192cc0(D_0035f0e4 + 0x6E4, D_00373380, 100 - o[0x1AA]);
        func_00192cc0(D_0035f0e4 + 0x704, D_00373380, 100 - o[0x1AB]);
        func_00192cc0(D_0035f0e4 + 0x724, D_00373380, 100 - o[0x1AC]);
        if (v == 0) {
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x40) func_00192cc0(D_0035f0e4 + 0x5E4, D_00373378, o[0x1B1], o[0x1B2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x80) func_00192cc0(D_0035f0e4 + 0x604, D_00373370, sv[0x1210]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x20000) func_00192cc0(D_0035f0e4 + 0x744, D_00373370, YS__SAVERAM_BATTLE__get_formram(sv, 1)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x100) func_00192cc0(D_0035f0e4 + 0x624, D_00373370, YS__SAVERAM_BATTLE__get_formram(sv, 2)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x40000) func_00192cc0(D_0035f0e4 + 0x764, D_00373370, YS__SAVERAM_BATTLE__get_formram(sv, 3)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x200) func_00192cc0(D_0035f0e4 + 0x644, D_00373370, YS__SAVERAM_BATTLE__get_formram(sv, 4)[2]);
            if (*(u32*)(D_0035f0e4 + 0x18) & 0x80000) func_00192cc0(D_0035f0e4 + 0x784, D_00373370, YS__SAVERAM_BATTLE__get_formram(sv, 5)[2]);
        }
        break;
    }
    case 1: case 2: case 3: case 4: case 5: {
        u8* o = ((u8**)D_0035f0e4)[v];
        u8* inf = YS__SAVERAM_BATTLE__get_formram(sv, v);
        d = 0;
        func_00192cc0(D_0035f0e4 + 0x524, D_00373370, lv = inf[2]);
        func_00192cc0(D_0035f0e4 + 0x544, D_00373370, func_001d5c70(v, inf));
        nx = func_001d5c10(v, inf);
        if (nx) d = *(s32*)(nx + 4) - *(s32*)(inf + 4);
        func_00192cc0(D_0035f0e4 + 0x564, D_00373370, d);
        func_00192cc0(D_0035f0e4 + 0x584, D_00373370, lv + 2);
        func_00192cc0(D_0035f0e4 + 0x664, D_00373370, *(u16*)(o + 0x188));
        func_00192cc0(D_0035f0e4 + 0x684, D_00373370, *(u16*)(o + 0x18A));
        func_00192cc0(D_0035f0e4 + 0x6A4, D_00373370, *(u16*)(o + 0x18C));
        func_00192cc0(D_0035f0e4 + 0x6C4, D_00373380, 100 - o[0x1A9]);
        func_00192cc0(D_0035f0e4 + 0x6E4, D_00373380, 100 - o[0x1AA]);
        func_00192cc0(D_0035f0e4 + 0x704, D_00373380, 100 - o[0x1AB]);
        func_00192cc0(D_0035f0e4 + 0x724, D_00373380, 100 - o[0x1AC]);
        break;
    }
    case 6: {
        d = 0;
        func_00281180(D_0035f010, 0);
        lv = sv[0x1036];
        func_00192cc0(D_0035f0e4 + 0x524, D_00373370, lv);
        func_00192cc0(D_0035f0e4 + 0x544, D_00373370, func_001d5d20());
        nx = func_001d5cd0();
        if (nx) d = *(s32*)(nx + 4) - *(s32*)(sv + 0x11F4);
        func_00192cc0(D_0035f0e4 + 0x564, D_00373370, d);
        func_00192cc0(D_0035f0e4 + 0x584, D_00373370, lv + 2);
        break;
    }
    }
}
}  // namespace n00265c78

// 00266248 (was src/anon/batch_w3728_g.cpp)
namespace n00266248 {
u32 func_00257770() asm("func_00257770");
u32 func_00257070(s32) asm("func_00257070");
u32 func_002891b8(u32, s32) asm("func_002891b8");
s32 func_00192048(u32) asm("func_00192048");
void func_00288f60(u32, s32, s16*, s16*) asm("func_00288f60");
void func_00138c10(u32, s32) asm("func_00138c10");
void func_00138c68(u32, s32, s32) asm("func_00138c68");
s32 func_0023aa78(u32) asm("func_0023aa78");
s32 func_0023aa98(u32) asm("func_0023aa98");
void func_0028dcc0(u32, u32) asm("func_0028dcc0");
s32 Tz__CmNewFlg__isStatNew(s32) asm("Tz__CmNewFlg__isStatNew");
s32 func_002864f8(s32) asm("func_002864f8");
enum Slot { SLOT0 };
struct Item6 { u16 id; u16 pad; s16 c; };
struct Col4 { u16 a; u16 v; };
extern Item6 D_00373530[] asm("D_00373530");
extern Item6 D_003735a8[] asm("D_003735a8");
extern Item6 D_00373620[] asm("D_00373620");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f0e4 asm("D_0035f0e4");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_003734f8 asm("D_003734f8");
extern s32 D_003734fc asm("D_003734fc");
/*TARGET 00266248*/
void func_00266248(void) asm("func_00266248");
void func_00266248(void) {
    s16 cols[4];
    u32 tbl[2];
    u32 kind;
    u32 base;
    u32* pt;
    s32 i;
    base = func_00257770();
    *(u64*)tbl = 0;
    kind = func_00257070(23);
    switch (kind) {
    case 0: case 7: case 8: case 9:
        for (i = 0; i < 2; i++) tbl[i] = (u32)(D_00373530 + i * 10);
        break;
    case 1: case 2: case 3: case 4: case 5:
        for (i = 0; i < 2; i++) tbl[i] = (u32)(D_003735a8 + i * 10);
        break;
    case 6:
        for (i = 0; i < 2; i++) tbl[i] = (u32)(D_00373620 + i * 10);
        break;
    }
    pt = tbl;
    for (i = 0; i < 2; i++, pt++) {
        u32 sel = i ? D_0035f020 : D_0035f01c;
        s32 n = 0;
        s32 j;
        for (j = 0; j < 10; j++) {
            s32 idx = i * 10 + j;
            if (*(u32*)(D_0035f0e4 + 0x18) & (1 << idx)) {
                u32 item = func_002891b8(sel, n);
                *(u32*)(item + 0x198) = func_00192048(((Item6*)*pt)[j].id);
                // colour table base: lui before the store above, addiu after it, as in the original
                u32 hi;
                asm ("lui %0,%%hi(D_00373500)" : "=r"(hi));
                Col4* ctab;
                asm volatile("addiu %0,%1,%%lo(D_00373500)" : "=r"(ctab) : "r"(hi));
                // cursor pinned to t4 and fenced so its init issues before the pt reload, as in the original
                register s16* cp asm("$12") = cols;
                asm volatile("" : "+r"(cp));
                s32 k;
                for (k = 3; k >= 0; k--) { *cp = ctab[((Item6*)*pt)[j].c].v; cp++; }
                func_00288f60(sel, n, cols, cols);
                func_00138c10(item, cols[0]);
                s32 y = func_0023aa98(item + 0x18);
                func_00138c68(item, i * y, n * func_0023aa78(item + 0x18));
                func_0028dcc0(base + idx * 0x1B4 + 0x5EF0, item);
                u32 fade = base + idx * 0x198 + 0x87D0;
                func_0028dcc0(fade, item);
                func_00138c10(fade, D_0035ef6c);
                if (i != 0 && kind == 6) {
                    register s32 m asm("$17");   // s1 in the original
                    switch ((Slot)idx) {
                    case 10: m = 5; break;
                    case 11: m = 6; break;
                    case 12: m = 7; break;
                    default: m = 8; break;
                    }
                    if (Tz__CmNewFlg__isStatNew(m)) {
                        func_00138c10(base + idx * 0x198 + 0x87D0, func_002864f8(m) ? D_003734fc : D_003734f8);
                    }
                }
                n++;
            }
        }
        for (j = n; j < 10; j++) {
            u32 item = func_002891b8(sel, j);
            func_00138c10(item, D_0035ef6c);
            *(u32*)(item + 0x198) = 0;
        }
        for (j = 0; j < 10; j++) {
            if (!(*(u32*)(D_0035f0e4 + 0x18) & (1 << (i * 10 + j)))) {
                u32 p1 = base + (i * 10 + j) * 0x1B4 + 0x5EF0;
                u32 p2 = base + (i * 10 + j) * 0x198 + 0x87D0;
                func_00138c10(p1, D_0035ef6c);
                *(u32*)(p1 + 0x198) = 0;
                u32 item = func_002891b8(sel, j);
                func_0028dcc0(p1, item);
                func_0028dcc0(p2, item);
            }
        }
    }
}
}  // namespace n00266248

// 00266678 (was src/anon/batch_w1587_g.cpp)
namespace n00266678 {
void func_002657a8(void) asm("func_002657a8");
void Tz__CmStat__UpdateNew(void) asm("Tz__CmStat__UpdateNew");
void func_002666a8(void) asm("func_002666a8");
/*TARGET 00266678*/
void func_00266678(u32 a0, s32 a1) asm("func_00266678");
void func_00266678(u32 a0, s32 a1) {
    if (a1 == 23) func_002657a8();
    Tz__CmStat__UpdateNew();
    func_002666a8();
}
}  // namespace n00266678

// 002666a8 (was src/anon/perm_002666a8.cpp)
namespace n002666a8 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed int s32;
struct W1610Ent
{
  u16 a;
  u16 b;
  u16 c;
};
struct W1610Mn
{
  u8 pad[0x20];
  s8 mode;
  u8 pad2[0x7a4 - 0x21];
  u8 buf[160];
};
extern W1610Mn *D_0035f0e4 asm("D_0035f0e4");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f010 asm("D_0035f010");
extern u16 D_00373518[] asm("D_00373518");
extern W1610Ent D_00373530[][10] asm("D_00373530");
extern W1610Ent D_003735a8[][10] asm("D_003735a8");
extern W1610Ent D_00373620[][10] asm("D_00373620");
extern u16 D_00373698[] asm("D_00373698");
extern u16 D_003736a0[] asm("D_003736a0");
extern u16 D_003736a8[] asm("D_003736a8");
extern u16 D_003736b0[] asm("D_003736b0");
extern u16 D_003736b8[] asm("D_003736b8");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_002fde18(void *, s32, s32) asm("func_002fde18");
s32 func_0028b040(s32) asm("func_0028b040");
u32 func_002670a0(s32) asm("func_002670a0");
s32 func_00192048(u16) asm("func_00192048");
s32 func_00281140(s32, s32) asm("func_00281140");
s32 func_00192e50(s32, void *, s32, s32) asm("func_00192e50");
void func_00192b30(s32) asm("func_00192b30");
void func_00192c90(s32, void *) asm("func_00192c90");
void Tz__CMenuHelp__Create_2(void *, s32) asm("Tz__CMenuHelp__Create_2");
s32 func_00267248(void) asm("func_00267248");
u32 func_00257070(s32) asm("func_00257070");
s32 func_002671e8(s32) asm("func_002671e8");
void func_00263a58(u16, s32) asm("func_00263a58");
/*TARGET 002666a8*/
void func_002666a8(void) asm("func_002666a8");
void func_002666a8(void)
{
  s32 new_var;
  W1610Ent *tab = 0;
  s32 obj;
  u32 st = func_00287bc0();
  func_002fde18(D_0035f0e4->buf, 0, 160);
  if (st == 23)
  {
    u32 v = func_002670a0(func_0028b040(D_0035f01c));
    u16 id = D_00373518[v];
    switch (v)
    {
      case 0:
      {
        ;
        func_00192b30(func_00192e50(func_00192048(id), D_0035f0e4->buf, 160, func_00281140(D_0035f010, 0)));
        break;
      }

      case 1:

      case 2:

      case 3:

      case 4:

      case 5:

      case 6:
        func_00192c90(func_00192048(id), D_0035f0e4->buf);
        break;

      case 7:

      case 8:

      case 9:
      {
        obj = v - 6;
        st = func_00192048(id);
        func_00192b30(func_00192e50(st, D_0035f0e4->buf, 160, func_00281140(D_0035f010, obj)));
        break;
      }

    }

    Tz__CMenuHelp__Create_2(D_0035f0e4->buf, 1);
    return;
  }
  obj = func_0028b040(func_00267248());
  st = func_00257070(23);
  switch (st)
  {
    case 0:

    case 7:

    case 8:

    case 9:
      tab = D_00373530[D_0035f0e4->mode];
      break;

    case 1:

    case 2:

    case 3:

    case 4:

    case 5:
      tab = D_003735a8[D_0035f0e4->mode];
      break;

    case 6:
      tab = D_00373620[D_0035f0e4->mode];
      break;

  }

  s32 r = func_002671e8(obj);
  obj = r;
  if (D_0035f0e4->mode)
  {
    obj = r - 10;
  }
  u16 id = tab[obj].b;
  new_var = r;
  if (((st - 1) < 5) && (((u32) new_var) < 4))
  {
    u16 *t = 0;
    switch (st)
    {
      case 1:
        t = D_00373698;
        break;

      case 2:
        t = D_003736a0;
        break;

      case 3:
        t = D_003736a8;
        break;

      case 4:
        t = D_003736b0;
        break;

      case 5:
        t = D_003736b8;
        break;

    }

    switch (r)
    {
      case 0:
        obj = 0;
        break;

      case 1:
        obj = 1;
        break;

      case 2:
        obj = 2;
        break;

      case 3:
        obj = 3;
        break;

    }

    id = t[obj];
  }
  func_00263a58(id, 1);
}
}  // namespace n002666a8

// 00266988 (was src/anon/batch_w1603.cpp)
namespace n00266988 {
// ---- 00266988: menu panel highlight for the current entry (mode 23 = list, else sub-panel)
enum E00266988 { E00266988_0 };
u32 func_00257770() asm("func_00257770");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
u32 func_002670a0(s32) asm("func_002670a0");
s32 func_00257070(s32) asm("func_00257070");
u32 func_00267248() asm("func_00267248");
s32 func_002671e8(s32) asm("func_002671e8");
s32 Tz__CmNewFlg__isStatNew(s32) asm("Tz__CmNewFlg__isStatNew");
void func_002865d0(s32) asm("func_002865d0");
s32 func_002864f8(s32) asm("func_002864f8");
void func_00138c10(u32, s32) asm("func_00138c10");
extern u32 D_0035f01c asm("D_0035f01c");
extern s32 D_003734f8 asm("D_003734f8");
extern s32 D_003734fc asm("D_003734fc");
/*TARGET 00266988*/
void Tz__CmStat__UpdateNew(void) asm("Tz__CmStat__UpdateNew");
void Tz__CmStat__UpdateNew(void) {
    u32 base = func_00257770();
    s32 mode = func_00287bc0();
    s32 v = func_0028b040(D_0035f01c);
    u32 tgt;
    s32 k, n;
    if (mode == 23) {
        tgt = D_0035f01c;
        switch (func_002670a0(v)) {
        case 1: k = 0; break;
        case 2: k = 1; break;
        case 3: k = 2; break;
        case 4: k = 3; break;
        case 5: k = 4; break;
        default: return;
        }
    } else {
        v = func_00257070(23);
        if (v != 6) return;
        tgt = func_00267248();
        if (tgt == D_0035f01c) return;
        switch ((E00266988)func_002671e8(func_0028b040(tgt))) {
        case 10: k = 5; break;
        case 11: k = 6; break;
        case 12: k = 7; break;
        default: k = 8; break;
        }
    }
    if (Tz__CmNewFlg__isStatNew(k) == 0) return;
    func_002865d0(k);
    if (func_002864f8(k) != 0) k = D_003734fc;
    else k = D_003734f8;
    if (mode == 23 || v == 6) {
        s32 i = func_0028b040(tgt);
        if (mode != 23) i = func_002671e8(i);
        func_00138c10(base + i * 0x198 + 0x87D0, k);
    }
}
}  // namespace n00266988

// 00266b58 (was src/anon/batch_w1592.cpp)
namespace n00266b58 {
// 0x002593b8: definition moved into src/anon/unit_002588e8.cpp


s32 func_00287bc0(void) asm("func_00287bc0");
u32 func_00257070(s32) asm("func_00257070");
s32 Tz__CmNewFlg__isStatNew(s32) asm("Tz__CmNewFlg__isStatNew");
void func_002865d0(s32) asm("func_002865d0");
/*TARGET 00266b58*/
void Tz__CmStat__UpdateTopNew(void) asm("Tz__CmStat__UpdateTopNew");
void Tz__CmStat__UpdateTopNew(void) {
    s32 n;
    if (func_00287bc0() != 24) return;
    switch (func_00257070(23)) {
    case 1: n = 0; break;
    case 2: n = 1; break;
    case 3: n = 2; break;
    case 4: n = 3; break;
    case 5: n = 4; break;
    default: return;
    }
    if (Tz__CmNewFlg__isStatNew(n)) func_002865d0(n);
}
}  // namespace n00266b58

// 00266c00 (was src/anon/auto80_199_queue.cpp)
namespace n00266c00 {
extern const u16 D_00373470_def[4] asm("D_00373470") __attribute__((aligned(4))) = { 0x19, 0x9f, 0xa0, 0x17f };
/*TARGET 00266c00*/
u32 func_00266c00(void) asm("_Z13func_00266c00v");
u32 func_00266c00(void) {
    s32 s0 = 0;
    u32 s2 = 0;

    while (s0 < 4) {
        if (func_001a3570((u32)D_00373470[s0]) != 0) {
            s2 |= (1u << s0);
        }
        s0 += 1;
    }

    return s2;
}
}  // namespace n00266c00

// 00266c70 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00266c70 {
u32 func_00281340(u32, u32, u32, u32) asm("_Z13func_00281340jjjj");
/*TARGET 00266c70*/
// 0x002631d8: definition moved into src/anon/unit_0025f6b8.cpp

u32 func_00266c70(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00266c70jjjj");
// 0x002631d8: definition moved into src/anon/unit_0025f6b8.cpp

u32 func_00266c70(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r4 = (u32)((s32)0u + (1));
    u32 (*fp_call4_00281340)(u32, u32, u32, u32) = func_00281340;
    r2 = fp_call4_00281340(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00266c70

// 00266c90 (was src/anon/batch_wcx2.cpp)
namespace n00266c90 {
// --------------------
struct T266c90 { u8 pad[28]; u16 flags; s8 b30; u8 b31; };
union U266c90 { T266c90* p; u32 i; u16 h; u8 b; };
extern U266c90 D_0035f0e4 asm("D_0035f0e4");
extern s32 D_0035f010_x8910 asm("D_0035f010");
s32 func_00281100_x8911(s32) asm("func_00281100");
s32 func_00281340(s32) asm("func_00281340");
s8 func_00266c00() asm("func_00266c00");
/*TARGET 00266c90*/
void func_00266c90() asm("func_00266c90");
void func_00266c90() {
    s32 i, n;
    D_0035f0e4.p->flags = 0;
    D_0035f0e4.p->b31 = 0;
    n = func_00281100_x8911(D_0035f010_x8910);
    if (n) D_0035f0e4.p->flags |= 1;
    for (i = 1; i < n; i++) D_0035f0e4.p->flags |= 1 << (i + 6);
    for (i = 0; i < 7; i++) {
        if (i == 0 || i == 6) continue;
        if (!func_00281340(i)) continue;
        n = -1;
        switch (i) {
        case 1: n = 1; break;
        case 2: n = 2; break;
        case 3: n = 3; break;
        case 4: n = 4; break;
        case 5: n = 5; break;
        }
        D_0035f0e4.p->flags |= 1 << n;
        D_0035f0e4.p->b31 |= 1 << i;
    }
    D_0035f0e4.p->b30 = func_00266c00();
    if (D_0035f0e4.p->b30) D_0035f0e4.p->flags |= 0x40;
}
}  // namespace n00266c90

// 00266df8 (was src/anon/batch_w1608.cpp)
namespace n00266df8 {
// 00291918: moved to src/anon/unit_00290f78.cpp

struct Info { u8 pad[0x18]; s32 mask; u8 pad2[2]; s8 b1e; s8 b1f; };
s32 func_00266c70(void) asm("func_00266c70");
union InfoP { Info* p; s32 i; };
extern InfoP D_0035f0e4 asm("D_0035f0e4");
/*TARGET 00266df8*/
void func_00266df8(u32 arg0) asm("func_00266df8");
void func_00266df8(u32 arg0) {
    s32 i;
    s32 b;
    D_0035f0e4.p->mask = 0;
    switch (arg0) {
    case 0: case 7: case 8: case 9:
        for (i = 0; i < 6; i++) D_0035f0e4.p->mask |= 1 << i;
        for (i = 10; i < 17; i++) D_0035f0e4.p->mask |= 1 << i;
        if (arg0 == 0) {
            if (func_00266c70()) D_0035f0e4.p->mask |= 0x40;
            D_0035f0e4.p->mask |= 0x80;
            for (i = 0; i < 7; i++) {
                if (((D_0035f0e4.p->b1f >> i) ^ 1) & 1) continue;
                b = 0;
                switch (i) {
                case 1: b = 17; break;
                case 2: b = 8; break;
                case 3: b = 18; break;
                case 4: b = 9; break;
                case 5: b = 19; break;
                }
                D_0035f0e4.p->mask |= 1 << b;
            }
        }
        break;
    case 1: case 2: case 3: case 4: case 5:
        for (i = 0; i < 4; i++) D_0035f0e4.p->mask |= 1 << i;
        for (i = 10; i < 17; i++) D_0035f0e4.p->mask |= 1 << i;
        break;
    case 6:
        for (i = 0; i < 4; i++) D_0035f0e4.p->mask |= 1 << i;
        for (i = 0; i < 4; i++) {
            if ((D_0035f0e4.p->b1e >> i) & 1) {
                b = 0;
                switch (i) {
                case 0: b = 10; break;
                case 1: b = 11; break;
                case 2: b = 12; break;
                case 3: b = 13; break;
                }
                D_0035f0e4.p->mask |= 1 << b;
            }
        }
        break;
    }
}
}  // namespace n00266df8

// 002670a0 (was src/anon/batch_w32.cpp)
namespace n002670a0 {
struct MaskCfg { u16 pad[14]; u16 mask; };
extern MaskCfg* D_0035f0e4 asm("D_0035f0e4");
/*TARGET 002670a0*/
// Index of the n-th set bit among the low 10 bits of the mask, or -1.
s32 func_002670a0(s32 n) asm("func_002670a0");
// Index of the n-th set bit among the low 10 bits of the mask, or -1.
s32 func_002670a0(s32 n) {
    s32 r = -1;
    u16 m = D_0035f0e4->mask;
    s32 c = 0;
    for (s32 i = 0; i < 10; i++) {
        if ((u8)((m >> i) & 1)) {
            if (c == n) { r = i; break; }
            c++;
        }
    }
    return r;
}
}  // namespace n002670a0

// 002670f8 (was src/anon/batch_w33.cpp)
namespace n002670f8 {
struct Pad267 { u8 pad[28]; u16 mask; };
extern Pad267* D_0035f0e4 asm("D_0035f0e4");
/*TARGET 002670f8*/
// Index among the set bits of a 10-bit mask: how many set bits precede bit n (-1 if none).
s32 func_002670f8(s32 n) asm("func_002670f8");
// Index among the set bits of a 10-bit mask: how many set bits precede bit n (-1 if none).
s32 func_002670f8(s32 n) {
    s32 r = -1;
    s32 m = D_0035f0e4->mask;
    s32 c = 0;
    for (s32 i = 0; i < 10; i++) {
        if ((u8)((m >> i) & 1)) {
            if (i == n) { r = c; break; }
            c++;
        }
    }
    return r;
}
}  // namespace n002670f8

// 00267150 (was src/anon/batch_w62.cpp)
namespace n00267150 {
// 0x00262fa0: definition moved into src/anon/unit_0025f6b8.cpp

extern u32 D_0035f010 asm("D_0035f010");
u8* func_00281180(u32, u32) asm("func_00281180");
u8* func_001a80c8(u16) asm("func_001a80c8");
// table24_find_by_id
struct Ent267 { u16 id : 15; u16 on : 1; };
/*TARGET 00267150*/
// Sums byte 7 of every enabled entry's record over the 80-entry list.
s32 func_00267150(u32 a) asm("func_00267150");
// Sums byte 7 of every enabled entry's record over the 80-entry list.
s32 func_00267150(u32 a) {
    u8* o = func_00281180(D_0035f010, a);
    Ent267* p = (Ent267*)(*(u8**)(o + 580) + 84);
    s32 sum = 0;
    for (s32 i = 79; i >= 0; i--) {
        u16 id = p->id;
        if (id && p->on) sum += func_001a80c8(id)[7];
        p++;
    }
    return sum;
}
}  // namespace n00267150

// 002671e8 (was src/anon/batch_w43.cpp)
namespace n002671e8 {
extern u8* D_0035f0e4 asm("D_0035f0e4");
/*TARGET 002671e8*/
s32 func_002671e8(s32 n) asm("func_002671e8");
s32 func_002671e8(s32 n) {  // find_free_bit_index
    s32 r = -1;
    s32 cnt = 0;
    u8* g = D_0035f0e4;
    s32 base = *(s8*)(g + 32) * 10;
    u32 bits = *(u32*)(g + 24);
    for (s32 i = 0; i < 10; i++) {
        s32 b = base + i;
        if (bits & (1 << b)) {
            if (cnt == n) { r = b; break; }
            cnt++;
        }
    }
    return r;
}
}  // namespace n002671e8

// 00267248 (was src/anon/tiny_auto80_queue.cpp)
namespace n00267248 {
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f020 asm("D_0035f020");
extern u32 D_0035f0e4 asm("D_0035f0e4");
/*TARGET 00267248*/
// 0x00264458: definition moved into src/anon/unit_002640a8.cpp

u32 func_00267248() asm("_Z13func_00267248v");
// 0x00264458: definition moved into src/anon/unit_002640a8.cpp

u32 func_00267248() {  // global_ptr_by_flag32
    if (*(s8*)((*(u32*)(u32)&D_0035f0e4) + 32u) != 0) {
        return *(u32*)(u32)&D_0035f020;
    }
    return *(u32*)(u32)&D_0035f01c;
}
}  // namespace n00267248

// 00267270 (was src/tozawa/cmenu_stat.cpp)
namespace Tz { // method 00267270
extern u8 D_0035f0e8 asm("D_0035f0e8");
/*TARGET 00267270*/
u32 CmStat_ChgSelector() asm("_ZN2Tz6CmStat11ChgSelectorEv");
u32 CmStat_ChgSelector() {
    (void)D_0035f0e8;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-3864)));
}
}  // Tz

// 00267280 (was src/anon/batch_w1779_g.cpp)
namespace n00267280 {
u32 func_00267248(void) asm("func_00267248");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
s32 func_0028afa8(u32) asm("func_0028afa8");
s32 func_0028b040(u32) asm("func_0028b040");
extern u8* D_0035f0e4 asm("D_0035f0e4");
extern u8 D_0035f0e8 asm("D_0035f0e8");
/*TARGET 00267280*/
void func_00267280(void) asm("func_00267280");
void func_00267280(void) {
    u32 a, b;
    s32 sel, n;
    D_0035f0e8 = 1;
    a = func_00267248();
    D_0035f0e4[0x20] ^= 1;
    b = func_00267248();
    sel = func_0028b040(a);
    n = func_0028afa8(b);
    if (sel < n) Tz__Select__SetCurrent(b, sel, 0, -1, -1);
    else Tz__Select__SetCurrent(b, n - 1, 0, -1, -1);
}
}  // namespace n00267280

// 00267320 (was src/anon/batch_w39.cpp)
namespace n00267320 {
// Word accessed through a union: gcc treats it as aliasing everything, which
// reproduces the reloads / ordering the original shows at these sites.
union Word { f32 f; u32 u; };
// --- 00267320
extern u32 D_0035f010 asm("D_0035f010");
extern u32* D_0035f0e4 asm("D_0035f0e4");
u32 func_002811b0(u32, int) asm("func_002811b0");
u32 func_001a1728(u32, int) asm("func_001a1728");
/*TARGET 00267320*/
void func_00267320(void) asm("func_00267320");
void func_00267320(void) {
    u32 h = func_002811b0(D_0035f010, 0);
    for (int i = 0; i < 6; i++) ((Word*)&D_0035f0e4[i])->u = func_001a1728(h, i);
}
}  // namespace n00267320

// 00267398 (was src/anon/auto80_199_queue.cpp)
namespace n00267398 {
/*TARGET 00267398*/
void func_00267398(void) asm("_Z13func_00267398v");
void func_00267398(void) {
    s32 s0 = 0;

    while (s0 < 6) {
        u32* base = D_0035f0e4;
        u32 idx = (u32)s0;
        u32 v0 = base[idx];

        if (v0 != 0) {
            YS__SHEET__Free(v0);
            base = D_0035f0e4;
            base[idx] = 0;
        }

        s0 += 1;
    }
}
}  // namespace n00267398

// 00267408 (was src/anon/batch_wcx2.cpp)
namespace n00267408 {
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
extern s32 D_0035f010_x8940 asm("D_0035f010");
u16* func_0026b850(s32) asm("func_0026b850");
s32 func_002670a0_x8942(s32) asm("func_002670a0");
s32 func_00281158(s32, s32) asm("func_00281158");
/*TARGET 00267408*/
s32 Tz__CmStat__GetSelMsg(s32 a) asm("Tz__CmStat__GetSelMsg");
s32 Tz__CmStat__GetSelMsg(s32 a) {
    u16* t = func_0026b850(a);
    s32 n = func_002670a0_x8942(a);
    s32 r = 0;
    switch (n) {
    case 0: r = func_00281158(D_0035f010_x8940, 0); break;
    case 1: r = t[1]; break;
    case 2: r = t[2]; break;
    case 3: r = t[3]; break;
    case 4: r = t[4]; break;
    case 5: r = t[5]; break;
    case 6: r = 0xc5b1; break;
    case 7: case 8: case 9: r = func_00281158(D_0035f010_x8940, n - 6); break;
    }
    return r;
}
}  // namespace n00267408

// 002674b8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002674b8 {
extern u32 D_0035f0e4 asm("D_0035f0e4");
/*TARGET 002674b8*/
u32 func_002674b8() asm("_Z13func_002674b8v");
u32 func_002674b8() {
    u32 v0 = 0u;
    u32 c = 0u;
    s32 bits = *(u16*)((*(u32*)(u32)&D_0035f0e4) + 28u);
    do {
        u32 next = v0 + 1u;
        u32 t = (((bits >> c) ^ 1u) & 1u);
        c += 1u;
        if (t == 0u) {
            v0 = next;
        }
    } while ((s32)c < 10);
    return v0;
}
}  // namespace n002674b8

// 002674f8 (was src/tozawa/cmenu_stat.cpp)
namespace Tz { // method 002674f8
u32 func_00257070(...) asm("func_00257070");
void func_00257050(...) asm("func_00257050");
u32 func_002670f8(...) asm("func_002670f8");
u32 func_002674b8(...) asm("func_002674b8");
u32 func_002670a0(...) asm("func_002670a0");
u32 Tz__CmStat__GetSelMsg(...) asm("Tz__CmStat__GetSelMsg");
u32 func_0028fb28(...) asm("func_0028fb28");
u32 Tz__CmStat__UpdateTopNew(...) asm("Tz__CmStat__UpdateTopNew");
/*TARGET 002674f8*/
u32 CmStat_ChgSelChara(bool a0) asm("_ZN2Tz6CmStat11ChgSelCharaEb");
u32 CmStat_ChgSelChara(bool a0) {
    u32 s0 = (u32)a0 & 0xFF;
    u32 t = func_00257070(23);
    t = func_002670f8(t);
    u32 v0 = func_002674b8();
    u32 s1 = t;
    s32 t6 = (s32)v0 - 1;

    if (s0 != 0) {
        s1 = s1 + 1;
        if (!((s32)s1 < (s32)v0)) {
            s1 = 0;
        }
    } else {
        s1 = s1 - 1;
        if ((s32)s1 < 0) {
            s1 = (u32)t6;
        }
    }

    u32 idx = func_002670a0(s1);
    func_00257050(23, idx, 0);
    func_0028fb28(1, Tz__CmStat__GetSelMsg(s1));
    return Tz__CmStat__UpdateTopNew();
}
}  // Tz

// 00267590 (was gap)
namespace n00267590 {
s32 func_00287bc0() asm("func_00287bc0");
s32 func_002674b8() asm("func_002674b8");
s32 func_00267590(s32 a) asm("func_00267590");
s32 func_00267590(s32 a) {
    s32 m = func_00287bc0();
    s32 r = 1;
    if (m == 23) return r;
    if ((u32)(a + 11) >= 2) return r;
    s32 t = func_002674b8() < 2;
    return t == 0;
}
}  // namespace n00267590

// 002675e8 (was src/anon/batch_w3.cpp)
namespace n002675e8 {
void func_00267620() asm("func_00267620");
extern u32 D_0035f0ec asm("D_0035f0ec");
void CmEquip_Init() asm("_ZN2Tz7CmEquip4InitEv");
void CmEquip_Init() {
    D_0035f0ec = 0;
    func_00267620();
}
}  // namespace n002675e8

// 00267608 (was src/anon/tiny.cpp)
namespace n00267608 {
void func_00267690(void*) asm("_Z13func_00267690Pv");
/*TARGET 00267608*/
// 0x002631f8: definition moved into src/anon/unit_0025f6b8.cpp
void func_00267608(BD_VALUE* bd) asm("_Z13func_00267608P8BD_VALUE");
// 0x002631f8: definition moved into src/anon/unit_0025f6b8.cpp
void func_00267608(BD_VALUE* bd) { func_00267690(bd); }
}  // namespace n00267608

// 00267620 (was src/anon/auto80_199_queue.cpp)
namespace n00267620 {
/*TARGET 00267620*/
u32 func_00267620() asm("_Z13func_00267620v");
u32 func_00267620() {
    if (D_0035f0ec == 0) {
        Obj0* o = D_0032ba14;
        u32 s0 = o->vtbl->fn0(o, 4196, __builtin_return_address(0));
        func_00281ec8(s0);
        D_0035f0ec = s0;
    }
    return func_00281f40(D_0035f0ec, D_0035f010);
}
}  // namespace n00267620

// 00267690 (was src/anon/auto80_199_queue.cpp)
namespace n00267690 {
/*TARGET 00267690*/
void func_00267690() asm("_Z13func_00267690v");
void func_00267690() {
    u32 s0 = D_0035f0ec;
    if (s0 != 0) {
        func_00281f10(s0);
        Obj1* o = (Obj1*)D_0032ba14;
        o->vtbl->fn1(o, s0);
        D_0035f0ec = 0;
    }
}
}  // namespace n00267690

// 002676e8 (was src/tozawa/cmenu_equip.cpp)
namespace Tz { // method 002676e8
u32 func_00287bc0() asm("func_00287bc0");
u32 func_00287db0() asm("func_00287db0");
void Tz__CmEquip__FadeOutList() asm("Tz__CmEquip__FadeOutList");
void func_00281b30() asm("func_00281b30");
/*TARGET 002676e8*/
void CmEquip_FadeOutAll() asm("_ZN2Tz7CmEquip10FadeOutAllEv");
void CmEquip_FadeOutAll() {
    u32 v = func_00287bc0();
    if (v == 2 || v == 5 || v == 6 || v == 7 || v == 8 || v == 9) {
        Tz__CmEquip__FadeOutList();
        CmTop::LeaveShortCutInfo();
        func_00281b30();
        if (func_00287db0() != 0) {
            CmTop::FadeOutPadHelp();
        }
    }
}
}  // Tz

// 00267768 (was src/tozawa/cmenu_equip.cpp)
namespace Tz { // method 00267768
u32 func_00287bc0() asm("func_00287bc0");
void func_00256ea8(...) asm("func_00256ea8");
void func_00269ef8() asm("func_00269ef8");
void func_00281c50() asm("func_00281c50");
/*TARGET 00267768*/
void CmEquip_LeaveAll() asm("_ZN2Tz7CmEquip8LeaveAllEv");
void CmEquip_LeaveAll() {
    u32 v = func_00287bc0();
    if (v == 2 || v == 5 || v == 6 || v == 7 || v == 8 || v == 9) {
        func_00269ef8();
        CmTop::LeaveShortCutInfo();
        func_00281c50();
        func_00256ea8();
    }
}
}  // Tz

// 002677d8 (was src/anon/tiny.cpp)
namespace n002677d8 {
void func_002817b8(void*) asm("_Z13func_002817b8Pv");
/*TARGET 002677d8*/
void func_002677d8(BD_VALUE* bd) asm("_Z13func_002677d8P8BD_VALUE");
void func_002677d8(BD_VALUE* bd) { func_002817b8(bd); }
}  // namespace n002677d8

// 002677f0 (was src/anon/auto80_199_queue.cpp)
namespace n002677f0 {
/*TARGET 002677f0*/
u32 func_002677f0(u32 a0, u32 a1) asm("_Z13func_002677f0jj");
u32 func_002677f0(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;

    u16* p = func_002570e0(s0);
    func_0028fb28(0, p[9]);
    func_00257050(0, 0, 0);

    if (s0 == 1) {
        return func_0025f7f0(s1);
    }

    if (func_00257070(1) != s1) {
        func_00257050(2, 0, 0);
        func_00257050(1, s1, 0);
    }

    u32 v = func_00281140(D_0035f010, s1);
    func_0028fb68(1, v);
    return func_002678a8();
}
}  // namespace n002677f0

// 002678a8 (was src/anon/batch_w2470.cpp)
namespace n002678a8 {
u8* func_00257770(void) asm("func_00257770");
void func_0028d068(s32, s32) asm("func_0028d068");
s32 func_0028f930(s32) asm("func_0028f930");
void func_0028f4d8(s32, s32, s32) asm("func_0028f4d8");
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void Tz__Select__SetItem(s32, s32, s32, s32, s32, s32, u16*, u16*) asm("Tz__Select__SetItem");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_0023aa78(u8*) asm("func_0023aa78");
void Tz__Select__SetExOffset(s32, s32, s32, s32) asm("Tz__Select__SetExOffset");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
s32 func_00257140(s32) asm("func_00257140");
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
u8* func_0023f1b0(s32) asm("func_0023f1b0");
s32 func_0023c4b8(u8*, s32) asm("func_0023c4b8");
s32 func_00236ca8(s32, s32) asm("func_00236ca8");
s32 func_00257130(void) asm("func_00257130");
s32 func_00281f18(s32) asm("func_00281f18");
s32 func_002570f0(void) asm("func_002570f0");
void func_0028bae0(s32, s32, s32, s32, s32, s32, s32, u8*, s32) asm("func_0028bae0");
void func_002817d8(s32, s32, s32, s32, s32, s32, s32) asm("func_002817d8");
void func_00281e70(u8*) asm("func_00281e70");
void func_002677d8(void) asm("func_002677d8");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00281198(s32, s32) asm("func_00281198");
void func_00282240(s32, s32, s32) asm("func_00282240");
void Tz__ItemInfo__MakeMsgTbl(s32, s32, s32) asm("Tz__ItemInfo__MakeMsgTbl");
void Tz__Select__SetSelectMax(s32, s32) asm("Tz__Select__SetSelectMax");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
s32 func_00257088(s32) asm("func_00257088");
void func_0028afd0(s32, s32) asm("func_0028afd0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00269508(s32) asm("func_00269508");
s32 func_0028af88(s32) asm("func_0028af88");
s32 func_00258068(s32) asm("func_00258068");
void func_0028af18(s32, s32) asm("func_0028af18");
void Tz__Select__SetPageMode(s32, s32) asm("Tz__Select__SetPageMode");
void func_0028b248(s32, s32) asm("func_0028b248");
void Tz__CmEquip__UpdateTopList(void) asm("Tz__CmEquip__UpdateTopList");
s32 func_00283ab8(s32) asm("func_00283ab8");
void Tz__CmTop__CreatePadHelp(s32, s32, s32) asm("Tz__CmTop__CreatePadHelp");
void func_00287cc0(s32) asm("func_00287cc0");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035ef68 asm("D_0035ef68");
extern s32 D_0035ef64 asm("D_0035ef64");
extern s32 D_0035f03c asm("D_0035f03c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s32 D_0035f010 asm("D_0035f010");
/* 436-byte menu object (fields at +24, +392, +432). */
struct Obj { u8 b[436]; };
#define OBJ(base, i) ((u8*)&((Obj*)(base))[i])
/*TARGET 002678a8*/
/* Menu screen setup: base object, 9 items with their cursors, 9 icons, footer. */
void func_002678a8(void) asm("func_002678a8");
/* Menu screen setup: base object, 9 items with their cursors, 9 icons, footer. */
void func_002678a8(void) {
    u16 buf[4];
    s32 lay;
    s32 i;
    u8* m;
    s32 id, v, img, t, fl;
    u8* w;
    s32 sz;
    m = func_00257770();
    i = 0;
    func_0028d068(30021, 0);
    for (; i < 4; i++) buf[i] = D_0035ef6c;
    if (!func_0028f930(0)) func_0028f4d8(0, -1, 0);
    if (!func_0028f930(1)) func_0028f4d8(1, -1, 0);
    id = D_0035f3d4;
    func_0028d8c0(m, id, D_0035ef68, D_0035ef64, D_0035f03c, 227, 228, 0);
    id++;
    i = 0;
    v = id + 1;
    sz = 436;
    for (; i < 9; i++) {
        u8* q = m + 24304 + i * sz;
        Tz__Select__SetItem(D_0035f01c, i, D_0035ef68, D_0035ef64, D_0035f03c, -1, buf, buf);
        func_00138c10(func_002891b8(D_0035f01c, i), 265);
        Tz__Select__SetExOffset(D_0035f01c, i, 0, func_0023aa78(func_002891b8(D_0035f01c, i) + 24));
        func_00139620(func_002891b8(D_0035f01c, i));
        func_00138c10(func_002891b8(D_0035f01c, i), D_0035ef6c);
        *(s32*)(func_002891b8(D_0035f01c, i) + 392) = -1;
        func_0028dcc0(func_002891b8(D_0035f01c, i), m);
        func_0028d980(q, v, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(0), -1, -1, 0);
        func_0028dcc0(q, func_002891b8(D_0035f01c, i));
        func_00139620(q);
        func_001395f8(q);
    }
    i = 0;
    for (; i < 9; i++) {
        func_0028d980(OBJ(m + 3376, i), id, D_0035ef68, D_0035ef64, D_0035f03c, 283, -1, -1, 0);
        func_00138c68(OBJ(m + 3376, i), 0, func_0023aa78(OBJ(m + 3376, i) + 24) * i);
        func_00138c10(OBJ(m + 3376, i), D_0035ef6c);
        func_001395f8(OBJ(m + 3376, i));
        func_0028dcc0(OBJ(m + 3376, i), m);
        *(s32*)(OBJ(m + 3376, i) + 432) = 2;
    }
    lay = func_0023c4b8(func_0023f1b0(D_0035f03c), D_0035ef68);
    img = func_00236ca8(*(s32*)(func_0023f1b0(D_0035f03c) + 40), D_0035ef64);
    v = func_00281f18(func_00257130());
    i = 9;
    if (v < 10) i = v;
    func_0028bae0(D_0035f04c, id, lay, img, func_002570f0(), v, i, m, 0);
    w = m + 0xb350;
    id = D_0035f3d4;
    func_0028d980(w, id, D_0035ef68, D_0035ef64, D_0035f03c, 287, 288, -1, 0);
    func_002817d8(30015, D_0035ef68, D_0035ef64, D_0035f03c, 0, 0, 0);
    func_00281e70(w);
    func_002677d8();
    v = func_00281198(D_0035f010, func_00257070(1)) + 5;
    func_00282240(func_00257130(), v, 0);
    v = 0xc000;
    Tz__ItemInfo__MakeMsgTbl(func_00257130(), 0, 0);
    Tz__Select__SetSelectMax(D_0035f01c, func_00281f18(func_00257130()));
    Tz__Select__SetCurrent(D_0035f01c, func_00257070(2), 0, -1, -1);
    func_0028afd0(D_0035f01c, func_00257088(2));
    t = func_00269508(func_0028b040(D_0035f01c));
    fl = func_0028af88(D_0035f01c);
    if (func_00258068(1)) v = 0xc100;
    if (t == 4) v |= 0x200;
    func_0028af18(D_0035f01c, fl | v);
    v = -1;
    Tz__Select__SetPageMode(D_0035f01c, 1);
    func_0028b248(D_0035f01c, 9);
    Tz__CmEquip__UpdateTopList();
    if ((t == 4 && func_00283ab8(0)) || (t == 1 && func_00283ab8(3))) {
        v = 0xcbdd;
        fl = func_0028af88(D_0035f01c) | 0x400;
        func_0028af18(D_0035f01c, fl);
    }
    if (func_00258068(1)) Tz__CmTop__CreatePadHelp(0xb619, 0xb61a, v);
    func_00287cc0(0);
}
}  // namespace n002678a8

