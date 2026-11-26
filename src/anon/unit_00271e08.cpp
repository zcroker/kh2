// Linked unit 0x00271b78-0x00274460 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/cmenu_custom.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 00271b78 (was whole asm in src/anon/batch_w3931.s)
namespace n00271b78 {
struct Ent8 { u8 pad[8]; s16 h; };
void func_00139d78(u8*) asm("_Z16u_call4_00139d78jjjj");
s32 func_002891e8(s32) asm("func_002891e8");
void func_00271b58(s32) asm("_Z13func_00271b58jjjj");
void func_002713a0(s32, s8**, s32*) asm("func_002713a0");
s32 func_00257140(s32) asm("_ZN2Tz5CmTop18GetFontColorSeqNumEi");
s32 func_00257158(s32, s32, s32) asm("func_00257158");
s32 func_00272c20(s32) asm("func_00272c20");
void setNum(u8*, s32) asm("_ZN2dk6Sprite6setNumEi");
u8* GetListBuffer() asm("_ZN2Tz5CmTop13GetListBufferEv");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern u32 D_0035f01c asm("D_0035f01c");
extern u8* D_0035f12c asm("D_0035f12c");
extern s8* D_01e21ed4 asm("D_01e21ed4");
extern const s16 D_00373990[] asm("D_00373990");
/*TARGET 00271b78*/
void func_00271b78(void) asm("func_00271b78");
// Font colour of list entry idx in group i (kind 3 has the default colour).
static inline s32 EntryColor(s32 i, s32 idx) {
    if (D_01e21ed4[i] != 3) return func_00257140(func_00257158(((Ent8*)(D_0035f12c + idx * 8))->h, 1, D_01e21ed4[i] == 1));
    return func_00257140(0);
}
static inline s8*& Kinds() { return D_01e21ed4; }
// Menu sprite list setup: 72 sprites of 436 bytes at +0xd30 (three banks of 24), 32-byte entries at +0xae10,
// 4-byte entries at +0xb110. Each group starts on an even slot.
void func_00271b78(void) {
    s32 vals[8];
    s32 cnt;
    s32 i, flag, n, tex, base, idx;
    u8* m = GetListBuffer();
    func_00139d78(m);
    flag = func_002891e8(D_0035f01c);
    func_00271b58(flag);
    func_002713a0(flag, &D_01e21ed4, &cnt);
    s32 col = func_00257140(0);
    for (i = 0; i < 18; i++) {
        u8* p = m + i * 436;
        setNum(p + 13840, D_0035ef6c);
        setNum(p + 24304, col);
        *(s32*)(p + 24712) = 0;
        *(s32*)(p + 3784) = 0;
    }
    for (i = 0; i < cnt; i++) vals[i] = func_00272c20(D_01e21ed4[i]);
    idx = 0;
    base = 0;
    for (i = 0; i < cnt; i++) {
        n = vals[i];
        tex = D_00373990[Kinds()[i]];
        for (s32 j = 0; j < n; j++) {
            s32 no = base + j + 24;
            setNum(m + no * 436 + 3376, tex);
            u8* e32b = m + 0xae10; u8* e4b = m + 0xb110;
            u8* e32p = e32b + idx * 32; u8* e4p = e4b + idx * 4;
            u8* sp = m + (base + j) * 436;
            col = EntryColor(i, idx);
            setNum(sp + 24304, col);
            *(u8**)(sp + 24712) = e32p;
            if (flag && D_01e21ed4[i] != 3) *(u8**)(sp + 3784) = e4p;
            idx++;
        }
        base += n;
        base += n & 1;
    }
}
}

// 00271e08 (was src/anon/batch_w40.cpp)
namespace n00271e08 {
u32 func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028dac8(u32, u32) asm("func_0028dac8");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_0028acb8(u32) asm("func_0028acb8");
void func_0028aa40(u32) asm("func_0028aa40");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 00271e08*/
void func_00271e08(void) asm("func_00271e08");
void func_00271e08(void) {
    u32 s = func_00257770();
    if (func_00287bc0() == 25) {
        func_0028dac8(s, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}
}  // namespace n00271e08

// 00271e80 (was src/anon/auto200_999.cpp)
namespace n00271e80 {
void func_002579e0(void) asm("_Z13func_002579e0v");
void func_0028abe0(u32) asm("_Z13func_0028abe0j");
u32 func_0028acc8(u32) asm("_Z13func_0028acc8j");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 00271e80*/
void func_00271e80() asm("_Z13func_00271e80v");
void func_00271e80() {
    func_002579e0();
    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }
}
}  // namespace n00271e80

// 00271ec8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00271ec8 {
u32 func_00257780(u32, u32, u32, u32) asm("_Z13func_00257780jjjj");
/*TARGET 00271ec8*/
/*NOSYM*/
u32 func_00271ec8(u32 a0, u32 a1, u32 a2, u32 a3);
// 0x0026aaf8: definition moved into src/anon/unit_0026a900.cpp

u32 func_00271ec8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00257780)(u32, u32, u32, u32) = func_00257780;
    r2 = fp_call4_00257780(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00271ec8

// 00271ee8 (was src/anon/batch_w3816.cpp)
namespace n00271ee8 {
struct Ent8 { u8 pad[8]; s16 h; };
u8* func_00257770(void) asm("func_00257770");
void func_00139d78(u8*) asm("func_00139d78");
s32 func_0028b038(s32) asm("func_0028b038");
void func_0028be78(s32, s32) asm("func_0028be78");
s32 func_00257070(s32) asm("func_00257070");
void func_002713a0(s32, s8**, s32*) asm("func_002713a0");
s32 func_00257140(s32) asm("func_00257140");
s32 func_002892f8(s32) asm("func_002892f8");
u8* func_002891b8(s32, s32) asm("func_002891b8");
void func_0028b040(s32) asm("func_0028b040");
s32 func_00257158(s32, s32, s32) asm("func_00257158");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00272c20(s32) asm("func_00272c20");
s32 func_00192048(u32) asm("func_00192048");
s32 func_00286068(s32) asm("func_00286068");
s32 func_00286160(s32) asm("func_00286160");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
extern u8* D_0035f12c asm("D_0035f12c");
extern s8* D_01e21ed8 asm("D_01e21ed8");
extern s32 D_003739ec asm("D_003739ec");
extern s32 D_003739f0 asm("D_003739f0");
extern s16 D_003739f8[] asm("D_003739f8");
extern s16 D_00373a08[] asm("D_00373a08");
extern u16 D_00373a18[] asm("D_00373a18");
extern u16 D_00373a28[] asm("D_00373a28");
/*TARGET 00271ee8*/
// Sets up the 9 sprite rows and fills them from the current list.
void func_00271ee8(void) asm("func_00271ee8");
// Sets up the 9 sprite rows and fills them from the current list.
void func_00271ee8(void) {
    s32 vals[8];
    s32 cnt;
    s32 v;
    s32 i;
    u8* b = func_00257770();
    func_00139d78(b);
    s32 nEnt = func_0028b038(D_0035f01c);
    func_0028be78(D_0035f04c, nEnt);
    func_002713a0(func_00257070(25), &D_01e21ed8, &cnt);
    v = func_00257140(0);
    for (i = 0; i < func_002892f8(D_0035f01c); i++)
        func_00138c10(func_002891b8(D_0035f01c, i), D_0035ef6c);
    for (i = 0; i < 9; i++) {
        s32 id = v;
        func_00138c10(b + i * 436 + 24304, id);
        *(s32*)(b + i * 436 + 24712) = 0;
        func_00138c10(b + i * 436 + 3376, D_0035ef6c);
        *(s32*)(b + i * 436 + 3784) = 0;
        func_00138c10(b + i * 408 + 0x87d0, D_0035ef6c);
    }
    func_0028b040(D_0035f01c);
    for (i = 0; i < cnt; i++) vals[i] = func_00272c20(D_01e21ed8[i]);
    s32 lim = ((s8*)D_0035f12c)[4];
    if (func_00257070(25)) lim++;
    if (lim >= 10) lim = 9;
    s32 idx = 0;
    s32 k = 0;
    for (i = 0; i < cnt && k < lim; i++) {
        for (s32 j = 0; j < vals[i] && k < lim; j++, idx++) {
            if (idx < nEnt) continue;
            if (j == 0 || D_01e21ed8[i] == 0) {
                u8* e = b + k * 436 + 3376;
                v = D_00373a08[D_01e21ed8[i]];
                func_00138c10(e, v);
                s8 t = D_01e21ed8[i];
                // pin: the original keeps the label id in a1 and copies it to a0 in the jal delay slot
                register u32 x asm("$5") = D_00373a18[t];
                if (!t) x = D_00373a28[idx];
                *(s32*)(e + 408) = func_00192048(x);
            }
            v = D_003739f8[D_01e21ed8[i]];
            func_00138c10(func_002891b8(D_0035f01c, k), v);
            s8 type = D_01e21ed8[i];
            s32 r;
            if (type != 3) r = func_00257140(func_00257158(((Ent8*)(D_0035f12c + idx * 8))->h, 1, type == 1)); else r = func_00257140(0);
            u8* f = b + k * 436 + 24304;
            func_00138c10(f, r);
            *(u8**)(f + 408) = b + idx * 32 + 0xae10;
            if (func_00286068(((Ent8*)(D_0035f12c + idx * 8))->h))
                func_00138c10(b + k * 408 + 0x87d0, func_00286160(((Ent8*)(D_0035f12c + idx * 8))->h) ? D_003739f0 : D_003739ec);
            k++;
        }
    }
}
}  // namespace n00271ee8

// 00272340 (was src/anon/batch_w67.cpp)
namespace n00272340 {
void* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00272b60(s32) asm("func_00272b60");
void func_0028dac8(void*, s32) asm("func_0028dac8");
s32 func_0028be58(u32) asm("func_0028be58");
void func_0028bdb8(u32) asm("func_0028bdb8");
struct Entry373 { s16 a; s16 b; s16 c; };
extern Entry373 D_00373a30[] asm("D_00373a30");
extern u32 D_0035f04c asm("D_0035f04c");
/*TARGET 00272340*/
// 00272340
void func_00272340(void) asm("func_00272340");
// 00272340
void func_00272340(void)
{
    void* s = func_00257770();
    u32 m = func_00287bc0() - 26;
    if (m < 8) {
        s32 v;
        if (m < 2) v = 229;
        else v = D_00373a30[func_00272b60(func_002570a0(26))].b;
        func_0028dac8(s, v);
        if (func_0028be58(D_0035f04c)) func_0028bdb8(D_0035f04c);
    }
}
}  // namespace n00272340

// 002723e0 (was src/anon/auto200_999.cpp)
namespace n002723e0 {
void func_0028be18(u32) asm("_Z13func_0028be18j");
u32 func_0028be58(u32) asm("_Z13func_0028be58j");
extern u32 D_0035f04c asm("D_0035f04c");
void func_00271e80() asm("_Z13func_00271e80v");
/*TARGET 002723e0*/
void func_002723e0() asm("_Z13func_002723e0v");
void func_002723e0() {
    func_00271e80();
    if (func_0028be58(D_0035f04c) != 0) {
        func_0028be18(D_0035f04c);
    }
}
}  // namespace n002723e0

// 00272428 (was src/anon/tiny_auto80_queue.cpp)
namespace n00272428 {
extern u32 D_0035f04c asm("D_0035f04c");
u32 func_00271ec8(...) asm("func_00271ec8");
u32 func_0028be58(...) asm("func_0028be58");
/*TARGET 00272428*/
/*NOSYM*/ u32 func_00272428();
u32 func_00272428() {
    u32 v0 = func_00271ec8();
    if (v0 == 0u) {
        u32 a0 = *(u32*)(u32)&D_0035f04c;
        if (a0 != 0u) {
            v0 = (u32)(0u < func_0028be58(a0));
        }
    }
    return v0;
}
}  // namespace n00272428

// 00272468 (was src/anon/batch_w91.cpp)
namespace n00272468 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// --- 0024a270
s32 func_00287bc0(void) asm("func_00287bc0");
// 0x00262588: definition moved into src/anon/unit_0025f6b8.cpp

// --- 00272468
u8* cmtop_list_buffer2(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
u32 cmtop_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 func_00272b60(u32) asm("func_00272b60");
struct T6 { u16 a, b; s16 c; };
extern T6 D_00373a30[] asm("D_00373a30");
void func_00138c10(u8*, s32) asm("func_00138c10");
u32 func_0028be58(u32) asm("func_0028be58");
void func_0028bd60(u32) asm("func_0028bd60");
extern u32 D_0035f04c asm("D_0035f04c");
/*TARGET 00272468*/
void func_00272468(void) asm("func_00272468");
void func_00272468(void) {
    s32 v = 228;
    s32 m = func_00287bc0();
    u8* b = cmtop_list_buffer2();
    if (!(m == 26 || m == 27)) v = D_00373a30[func_00272b60(cmtop_select_pos(26))].c;
    if (b && u_call4_00139d78(b) && *(s32*)(b + 388) != v) func_00138c10(b, v);
    if (func_0028be58(D_0035f04c)) func_0028bd60(D_0035f04c);
}
}  // namespace n00272468

// 00272538 (was src/anon/batch_w68.cpp)
namespace n00272538 {
/* ---- 00272538 ---- */
struct E13 { s16 a, b, v; };
extern E13 D_00373a30[] asm("D_00373a30");
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00139d78(void*) asm("func_00139d78");
u32 func_002570a0(s32) asm("func_002570a0");
s32 func_00272b60(u32) asm("func_00272b60");
/*TARGET 00272538*/
s32 func_00272538(void) asm("func_00272538");
s32 func_00272538(void) {
    s32 r = 0;
    u8* p = (u8*)func_00257770();
    s32 id = func_00287bc0();
    if (p && func_00139d78(p)) {
        s32 v = 228;
        if (id != 26 && id != 27) v = D_00373a30[func_00272b60(func_002570a0(26))].v;
        r = *(s32*)(p + 388) == v;
    }
    return r;
}
}  // namespace n00272538

// 002725d8 (was src/anon/batch_w1602.cpp)
namespace n002725d8 {
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f04c asm("D_0035f04c");
u8* func_00257770(void) asm("func_00257770");
s32 func_0028b038(u32) asm("func_0028b038");
void func_0028be78(u32, s32) asm("func_0028be78");
s32 func_00257140(s32) asm("func_00257140");
s32 func_002892f8(u32) asm("func_002892f8");
s32 func_002570a0(s32) asm("func_002570a0");
u32 func_00272b60(s32) asm("func_00272b60");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00272758(void) asm("func_00272758");
void func_002728c8(void) asm("func_002728c8");
void func_00272938(void) asm("func_00272938");
void func_00272a00(void) asm("func_00272a00");
void func_00272a70(void) asm("func_00272a70");
/*TARGET 002725d8*/
void func_002725d8(void) asm("func_002725d8");
void func_002725d8(void) {
    s32 i = 0;
    u8* p = func_00257770() + 24740;
    func_0028be78(D_0035f04c, func_0028b038(D_0035f01c));
    s32 s = func_00257140(0);
    func_002892f8(D_0035f01c);
    for (; i < func_002892f8(D_0035f01c); i++) {
        func_00138c10(p, s);
        *(u32*)(p + 408) = 0;
        p += 436;
    }
    switch (func_00272b60(func_002570a0(26))) {
    case 0: func_00272758(); break;
    case 1: func_002728c8(); break;
    case 2: func_00272938(); break;
    case 3: func_00272a00(); break;
    case 4: func_00272a70(); break;
    }
}
}  // namespace n002725d8

// 00272758 (was src/anon/batch_w2389.cpp)
namespace n00272758 {
struct Ent272 { u8 pad[408]; void* data; u8 pad2[24]; };
struct Base272 { u8 pad[24740]; Ent272 e[16]; };
struct Item272 { u16 id; u8 pad[4]; };
extern s32 D_0035f014 asm("D_0035f014");
extern s32 D_0035f01c asm("D_0035f01c");
Base272* func_00257770(void) asm("func_00257770");
s32 func_0028b038(s32) asm("func_0028b038");
s32 func_00281f18(s32) asm("func_00281f18");
s32 func_00257140(s32) asm("func_00257140");
void func_00138c10(Ent272*, s32) asm("func_00138c10");
void* func_00282d58(s32) asm("func_00282d58");
u8* func_00281f30(s32) asm("func_00281f30");
Item272* func_00281f20(s32) asm("func_00281f20");
s32 func_00257158(s32, s32, s32) asm("func_00257158");
/*TARGET 00272758*/
void func_00272758(void) asm("func_00272758");
void func_00272758(void) {
    s32 k = 0;
    Base272* b = func_00257770();
    s32 skip = func_0028b038(D_0035f01c);
    s32 n = func_00281f18(D_0035f014);
    s32 max, i;
    u8* d;
    if (skip == 0) {
        Ent272* e = &b->e[0];
        k = 1;
        func_00138c10(e, func_00257140(0));
        n++;
        e->data = func_00282d58(D_0035f014);
    } else {
        skip--;
    }
    max = n < 9 ? n : 8;
    d = func_00281f30(D_0035f014);
    for (i = 0; i < n && k < max; i++) {
        if (i >= skip) {
            Item272* l = func_00281f20(D_0035f014);
            Ent272* e = &b->e[k];
            func_00138c10(e, func_00257140(func_00257158(l[i].id, 1, 0)));
            e->data = d + i * 80 + 16;
            k++;
        }
    }
}
}  // namespace n00272758

// 002728c8 (was src/anon/batch_owner1022b.cpp)
namespace n002728c8 {
u8* func_00257770() asm("func_00257770");
s32 func_00257140(s32) asm("func_00257140");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00192048(u16) asm("func_00192048");
extern u16 D_00373a78[] asm("D_00373a78");
/*TARGET 002728c8*/
void func_002728c8() asm("func_002728c8");
void func_002728c8()
{
    u8* p = func_00257770() + 24740;
    u16* id = D_00373a78;
    for (s32 i = 0; i < 2; i++) {
        func_00138c10(p, func_00257140(0));
        *(s32*)(p + 408) = func_00192048(*id++);
        p += 436;
    }
}
}  // namespace n002728c8

// 00272938 (was src/anon/batch_w84.cpp)
namespace n00272938 {
// lookup_by_index_align
void func_00138c10(void*, s32) asm("func_00138c10");
u8* func_00257770(void) asm("func_00257770");
u32 func_00257140(s32) asm("func_00257140");
u32 func_00192048(u16) asm("func_00192048");
s32 func_00257070(s32) asm("func_00257070");
extern u16 D_00373a88[] asm("D_00373a88");
/*TARGET 00272938*/
void func_00272938(void) asm("func_00272938");
void func_00272938(void) {
    s32 i;
    u16* t;
    u8* s;
    u8* b = func_00257770();
    s = b + 24740;
    for (i = 0; i < 2; i++) {
        func_00138c10(s, func_00257140(0));
        *(u32*)(s + 408) = func_00192048(D_00373a88[i]);
        s += 436;
    }
    if (func_00257070(25)) {
        s = b + 25612;
        for (i = 0; i < 2; i++) {
            func_00138c10(s, func_00257140(0));
            *(u32*)(s + 408) = func_00192048(D_00373a88[i]);
            s += 436;
        }
    }
}
}  // namespace n00272938

// 00272a00 (was src/anon/batch_w39.cpp)
namespace n00272a00 {
// table_word_indexed_by_3
void func_00138c10(u8*, u32) asm("func_00138c10");
// 0x00267320: definition moved into src/anon/unit_00265580.cpp

// --- 00272a00
u8* func_00257770(void) asm("func_00257770");
u32 func_00257140(int) asm("func_00257140");
u16* func_00273180(int, int) asm("func_00273180");
// state_dispatch_2_3
u32 func_00192048(u16) asm("func_00192048");
/*TARGET 00272a00*/
void func_00272a00(void) asm("func_00272a00");
void func_00272a00(void) {
    u8* p = func_00257770() + 24740;
    for (int i = 0; i < 6; i++, p += 436) {
        func_00138c10(p, func_00257140(0));
        *(u32*)(p + 408) = func_00192048(*func_00273180(3, i));
    }
}
}  // namespace n00272a00

// 00272a70 (was src/anon/batch_w40.cpp)
namespace n00272a70 {
u32 func_00257770(void) asm("func_00257770");
u32 func_00257140(u32) asm("func_00257140");
void func_00138c10(u8*, u32) asm("func_00138c10");
u16* func_00273180(u32, s32) asm("func_00273180");
// state_dispatch_2_3
u32 func_00192048(u16) asm("func_00192048");
/*TARGET 00272a70*/
void func_00272a70(void) asm("func_00272a70");
void func_00272a70(void) {
    u8* s = (u8*)func_00257770() + 24740;
    for (s32 i = 0; i < 3; i++, s += 436) {
        func_00138c10(s, func_00257140(0));
        *(u32*)(s + 408) = func_00192048(*func_00273180(4, i));
    }
}
}  // namespace n00272a70

// 00272ae0 (was src/anon/debug_g.cpp)
namespace n00272ae0 {
extern s32 D_0035f01c asm("D_0035f01c");
void func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
u32 func_00272b60(s32) asm("func_00272b60");
u16* func_00273140(s32) asm("func_00273140");
s32 func_00286068(u32) asm("func_00286068");
void func_00286280(u32) asm("func_00286280");
/*TARGET 00272ae0*/
void func_00272ae0(void) asm("func_00272ae0");
void func_00272ae0(void) {
    func_00287bc0();
    s32 v = func_0028b040(D_0035f01c);
    if (func_00272b60(v) < 2) {
        u16* r = func_00273140(v);
        if (r) {
            u32 id = *r;
            if (func_00286068(id)) {
                func_00286280(id);
            }
        }
    }
}
}  // namespace n00272ae0

// 00272b60 (was src/anon/perm_00272b60.cpp)
namespace n00272b60 {
typedef signed char s8;
typedef signed int s32;
s32 func_00257070(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
void func_002713a0(s32, s8 **, s32 *) asm("func_002713a0");
s32 func_00272c20(s32) asm("func_00272c20");
extern s8 *D_01e21edc asm("D_01e21edc");
/*TARGET 00272b60*/
s32 func_00272b60(s32 n) asm("func_00272b60");
s32 func_00272b60(s32 n)
{
  s32 cnt;
  s32 sum = 0;
  s32 *new_var;
  s32 r = -1;
  s32 i;
  new_var = &cnt;
  func_002713a0(i = func_00257070(25), &D_01e21edc, new_var);
  for (i = 0; i < cnt; i++)
  {
    sum += func_00272c20(D_01e21edc[i]);
    if (n < sum)
    {
      r = D_01e21edc[i];
      break;
    }
  }

  return r;
}
}  // namespace n00272b60

// 00272c20 (was src/anon/batch_w1519.cpp)
namespace n00272c20 {
extern s8* D_0035f12c asm("D_0035f12c");
/*TARGET 00272c20*/
// 0x001d8f38: definition moved into src/anon/unit_001d7458.cpp

s32 func_00272c20(u32 i) asm("func_00272c20");
// 0x001d8f38: definition moved into src/anon/unit_001d7458.cpp

s32 func_00272c20(u32 i) {
    s32 r = -1;
    switch (i) {
    case 0: return 4;
    case 1: return D_0035f12c[0];
    case 2: return D_0035f12c[1];
    case 3: return 1;
    case 4: r = D_0035f12c[2]; break;
    }
    return r;
}
}  // namespace n00272c20

// 00272c90 (was src/anon/batch_w3803.cpp)
namespace n00272c90 {
struct Slot272 { u8 p0[3]; s8 b3; u8 p4[7]; s8 bb; };
struct Pair272 { u16 a; u16 b; u16 c; u16 d; };
struct Rec272 { u16 a; u16 id; };
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f014 asm("D_0035f014");
extern u8* D_0035f12c asm("D_0035f12c");
extern s32 D_003739c4 asm("D_003739c4");
extern s32 D_003739c8 asm("D_003739c8");
extern u16 D_00373a80[] asm("D_00373a80");
extern u16 D_00373a90[] asm("D_00373a90");
extern Pair272 D_00373af8[] asm("D_00373af8");
s32 func_00287bc0(void) asm("func_00287bc0");
u8* func_00257770(void) asm("func_00257770");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00272b60(s32) asm("func_00272b60");
Rec272* func_00273180(s32, s32) asm("func_00273180");
u8* func_00273140(s32) asm("func_00273140");
u8* func_00281f20(s32) asm("func_00281f20");
u8* func_001a80c8(u32) asm("func_001a80c8");
u32 func_00192048(s32) asm("func_00192048");
s32 func_00192c90(u32, u8*) asm("func_00192c90");
void func_00263a90(u8*, s32) asm("func_00263a90");
/*TARGET 00272c90*/
// Looks up the message id for the current menu mode and draws that message.
// Partial inline asm (asm_review.tsv): register pins for id/mode/has/k/t/i/o and one pinned subu.
void func_00272c90(void) asm("func_00272c90");
// Looks up the message id for the current menu mode and draws that message.
// Partial inline asm (asm_review.tsv): register pins for id/mode/has/k/t/i/o and one pinned subu.
void func_00272c90(void)
{
    s32 id = -1;
    s32 id2 = -1;
    register s32 mode asm("$18") = func_00287bc0();
    u8* base = func_00257770();
    register s32 has asm("$22");
    s32 v;
    s32 r;
    if (mode == 25) has = func_0028b040(D_0035f01c);
    else has = func_002570a0(25);
    if (mode == 25) {
        if (!func_0028b040(D_0035f01c)) id = D_003739c4;
        else id = D_003739c8;
    } else if ((u32)(mode - 26) < 3) {
        v = func_0028b040(D_0035f01c);
        register s32 k asm("$20") = func_00272b60(v);
        if (k == 3) {
            id = func_00273180(3, ((Slot272*)D_0035f12c)->b3)->id;
        } else {
            asm("" : "+r"(k));
            register s32 t asm("$15") = has != 0;
            register s32 i asm("$17");
            asm("subu %0,%1,%2" : "=r"(i) : "r"(v), "r"(t));
            u8* p = func_00273140(i);
            if (p) id = *(u16*)(p + 10);
            if (mode == 27) { register u32 o asm("$14") = i * 8; o += (u32)D_0035f12c; id2 = func_00273180(k, ((Slot272*)o)->bb)->id; }
        }
    } else if (mode == 29) {
        v = func_0028b040(D_0035f01c);
        if (v) id = *(u16*)(func_001a80c8(*(u16*)(func_00281f20(D_0035f014) + v * 6 - 6)) + 10);
        else id = 0x9df7;
    } else if (mode == 30) {
        v = func_0028b040(D_0035f01c);
        u16* o = &D_00373a80[v];
        id = *o;
    } else if (mode == 31) {
        v = func_0028b040(D_0035f01c);
        id = D_00373a90[v % 2];
        if (has) id2 = D_00373af8[v / 2].b;
    } else if (mode == 32) {
        v = func_0028b040(D_0035f01c);
        id = func_00273180(3, v)->id;
    } else {
        v = func_0028b040(D_0035f01c);
        id = func_00273180(4, v)->id;
    }
    r = 0;
    if (id > 0) r = func_00192c90(func_00192048(id), base + 0xb1d0);
    if (id2 > 0) {
        s32 t = r - (r != 0);
        r = t + func_00192c90(func_00192048(id2), base + t + 0xb1d0);
    }
    func_00263a90(r ? base + 0xb1d0 : 0, 1);
}
}  // namespace n00272c90

// 00272f48 (gap, written for the unit)
namespace n00272f48 {
extern u32 D_0035f01c asm("D_0035f01c");
s32 func_00287bc0(void) asm("func_00287bc0");
u8* func_00257770(void) asm("func_00257770");
s32 func_0028b160(u32, u8*) asm("func_0028b160");
s32 func_0028afa8(u32) asm("func_0028afa8");
s32 func_00272b60(s32) asm("func_00272b60");
void func_001a98e8(u8*, u32, u8*, u32, u32) asm("func_001a98e8");
void func_00138c90(u8*, s32*, s32*) asm("func_00138c90");
void func_00138cb8(u8*, s32*, s32*) asm("func_00138cb8");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
u32 func_0023a918(u8*) asm("func_0023a918");
void func_001a9ae8(u8*, s32, s32, u32) asm("func_001a9ae8");
void func_00272f48(s32 a0, s32 a1, u32 a2, u32 a3, u8* o) asm("func_00272f48");
void func_00272f48(s32 a0, s32 a1, u32 a2, u32 a3, u8* o) {
    u8 buf[96];
    s32 x, y, w, h;
    s32 m = func_00287bc0();
    u8* p = func_00257770();
    s32 n = func_0028b160(D_0035f01c, o);
    if ((u32)(m - 27) < 2 && n < func_0028afa8(D_0035f01c) && func_00272b60(n) != 3) {
        func_001a98e8(buf, 1, p + n * 4 + 0xb110, *(u32*)(o + 424), 1);
        func_00138c90(o, &x, &y);
        func_00138cb8(o, &w, &h);
        w += func_0023aa18(o + 24) + x;
        h += func_0023aa38(o + 24) + y;
        func_001a9ae8(buf, w, h, func_0023a918(o + 24));
    }
}
}  // namespace n00272f48

// 00273078 (was src/anon/batch_w85.cpp)
namespace n00273078 {
extern void* D_0035f01c asm("D_0035f01c");
struct Ent273 { u16 id; u8 pad[6]; };
extern Ent273 D_00373af8[] asm("D_00373af8");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b160(void*, u8*) asm("func_0028b160");
// find_index_in_array
u32 func_00192048(u16) asm("func_00192048");
void func_001a98e8(void*, s32, u32, u32, s32) asm("func_001a98e8");
s32 func_0023aa98(void*) asm("func_0023aa98");
u32 func_0023a918(void*) asm("func_0023a918");
void func_001a9ae8(void*, u8*, u32, u32) asm("func_001a9ae8");
/*TARGET 00273078*/
void func_00273078(u8* base, u32 a1, u32 a2, u32 a3, u8* p) asm("func_00273078");
void func_00273078(u8* base, u32 a1, u32 a2, u32 a3, u8* p) {
    u8 buf[96];
    s32 v;
    u32 x;
    if (func_00287bc0() != 31) return;
    v = func_0028b160(D_0035f01c, p);  // find_index_in_array
    x = *(u32*)(p + 424);
    func_001a98e8(buf, 1, func_00192048(D_00373af8[v / 2].id), x, 0);
    func_001a9ae8(buf, base + func_0023aa98(p + 24), a1, func_0023a918(p + 24));
}
}  // namespace n00273078

// 00273140 (was src/tozawa/cmenu_custom.cpp)
namespace Tz { // method 00273140
extern u32 D_0035f12c asm("D_0035f12c");
u32 func_001a80c8(...) asm("func_001a80c8");
/*TARGET 00273140*/
// table24_find_by_id

u32 Tz_CmCustom_GetItemTbl(s32 index) asm("_ZN2Tz8CmCustom10GetItemTblEi");
u32 Tz_CmCustom_GetItemTbl(s32 index) {
    u32 p = ((u32)index << 3) + D_0035f12c;
    s32 v = *(s16*)(p + 8u);
    if (v != 0) {
        return func_001a80c8((u32)v);  // table24_find_by_id
    }
    return 0u;
}
}  // Tz

// 00273180 (was src/anon/batch_wcx.cpp)
namespace n00273180 {
// 0x0026d8c0: definition moved into src/anon/unit_0026c450.cpp
extern u8 D_00373ab0[] asm("D_00373ab0");
extern u8 D_00373af8[] asm("D_00373af8");
extern u8 D_00373ae0[] asm("D_00373ae0");
/*TARGET 00273180*/
u8* func_00273180(s32 k, s32 id) asm("func_00273180");
u8* func_00273180(s32 k, s32 id)
{
    u8* r = 0;
    u8* t = 0;
    s32 n = 0;
    switch (k) {
    case 3: t = D_00373ab0; n = 6; break;
    case 2: t = D_00373af8; n = 2; break;
    case 4: t = D_00373ae0; n = 3; break;
    }
    if (id < 0) return t;
    for (s32 i = 0; i < n; i++)
        if (t[i * 8 + 5] == id) { r = t + i * 8; break; }
    return r;
}
}  // namespace n00273180

// 00273228 (was src/anon/batch_w8003.cpp)
namespace n00273228 {
void func_00271b78(void) asm("func_00271b78");
void func_00272ae0(void) asm("func_00272ae0");
void func_00271ee8(void) asm("func_00271ee8");
void func_002725d8(void) asm("func_002725d8");
void func_00272c90(s32) asm("func_00272c90");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_00272b60(s32) asm("func_00272b60");
u32 func_0028af88(s32) asm("func_0028af88");
s32 func_00283ab8(s32) asm("func_00283ab8");
void func_00256cc0(s32, s32, s32) asm("func_00256cc0");
void func_0028af18(s32, u32) asm("func_0028af18");
/*TARGET 00273228*/
// One func_00272c90(1) call per branch: crossjumping merges them, and the
// merged label gets the original's alignment nop after the a1 == 25 path.
void func_00273228(s32 a0, s32 a1) asm("func_00273228");
// One func_00272c90(1) call per branch: crossjumping merges them, and the
// merged label gets the original's alignment nop after the a1 == 25 path.
void func_00273228(s32 a0, s32 a1)
{
    s32 s1;
    u32 fl;
    s32 snd;
    if (a1 == 25) {
        func_00271b78();
        func_00272c90(1);
    } else if (a1 == 26 || a1 == 27) {
        func_00272ae0();
        func_00271ee8();
        func_00272c90(1);
    } else {
        func_002725d8();
        func_00272c90(1);
    }
    if (a1 == 26 || a1 == 27) {
        s1 = func_00272b60(func_0028b040(a0));
        fl = func_0028af88(a0);
        if (s1) fl |= 0x200; else fl &= ~0x200;
        snd = -1;
        if ((s1 == 2 && func_00283ab8(0)) || (s1 == 1 && func_00283ab8(1))) {
            fl |= 0x400;
            snd = 0xcbdd;
        } else {
            fl &= ~0x400;
        }
        func_00256cc0(0xb61a, snd, -1);
        func_0028af18(a0, fl);
    }
}
}  // namespace n00273228

// 00273368 (was src/anon/batch_w114.cpp)
namespace n00273368 {
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035f03c asm("D_0035f03c");
extern u32 D_0035f01c asm("D_0035f01c");
extern s16 D_00373a60[] asm("D_00373a60");
u8* func_00257770(void) asm("func_00257770");
s32 func_00139d78(u8*) asm("func_00139d78");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028d008(u8*) asm("func_0028d008");
void func_00139510(u8*) asm("func_00139510");
void func_00256c40(void) asm("func_00256c40");
u32 func_002570a0(s32) asm("func_002570a0");
s32 func_00272b60(u32) asm("func_00272b60");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
u8* func_0028d0e0(u8*) asm("func_0028d0e0");
void func_00138c78(u32, s32*, s32*) asm("func_00138c78");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
u32 func_0028b040(u32) asm("func_0028b040");
void func_00256bb0(u8*) asm("func_00256bb0");
void func_00273368(u8* p, u8 flag) asm("func_00273368");
/*TARGET 00273368*/
void func_00273368(u8* p, u8 flag) asm("func_00273368");
void func_00273368(u8* p, u8 flag) {
    u8* m = func_00257770();
    u8* e = m + 816;
    s32 busy = func_00139d78(e);
    s32 mode = func_00287bc0();
    s32 x, y;
    if (func_0028d008(p)) {
        if (!busy) {
            s32 id = D_0035f3d4 + 2;
            s32 c = 249;
            if ((u32)(mode - 26) >= 2) c = D_00373a60[func_00272b60(func_002570a0(26)) + 5];
            func_0028d8c0(e, id, D_0035ef68, D_0035ef64, D_0035f03c, c, -1, 0);
            func_0028dcc0(e, m);
            func_00138c78(*(u32*)(func_0028d0e0(p) + 396), &x, &y);
            func_00138c68(e, x, y);
        }
        if (flag) {
            func_00138c78(*(u32*)(func_0028d0e0(p) + 396), &x, &y);
            func_00138c68(e, x, y);
        }
        if (func_00139d78(m + 2504) && !flag) return;
        if ((u32)(mode - 26) < 2 && func_00272b60(func_0028b040(D_0035f01c))) {
            func_00256bb0(func_0028d0e0(p));
            return;
        }
    } else if (busy) {
        func_00139510(e);
    }
    func_00256c40();
}
}  // namespace n00273368

// .rodata 0x3739c4-0x3739d0
extern const u32 R_003739c4[1] asm("D_003739c4") __attribute__((aligned(4))) = { 0xbb89 };
extern const u32 R_003739c8[2] asm("D_003739c8") __attribute__((aligned(4))) = { 0xbb8a, 0x9df7 };

// 00273530 (was src/anon/batch_wcx2.cpp)
namespace n00273530 {
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
extern "C" u32 D_0035f01c, D_0035f020;
// 0x002691f8: definition moved into src/anon/unit_00268b30.cpp

// --------------------
struct E273530 { u8 pad[2]; s8 a; s8 b; u8 pad2[4]; };
extern E273530* D_0035f12c asm("D_0035f12c");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00272b60(s32) asm("func_00272b60");
s32 func_0028b040_x9020(s32) asm("func_0028b040");
void func_00273678() asm("func_00273678");
void func_002736f8() asm("func_002736f8");
void func_00273818() asm("func_00273818");
void func_00273c40(s32) asm("func_00273c40");
void func_00273cb8(s32) asm("func_00273cb8");
void func_00270c70(s32) asm("func_00270c70");
/*TARGET 00273530*/
void func_00273530() asm("func_00273530");
void func_00273530() {
    s32 i = func_002570a0(26);
    s32 m = func_00272b60(i);
    s32 cur = func_0028b040_x9020(D_0035f01c);
    s32 k;
    switch (m) {
    case 0:
        func_00273678();
        break;
    case 1:
        k = D_0035f12c[i + 1].a != 0;
        if (k != cur) func_002736f8();
        break;
    case 2:
        if (func_002570a0(25)) i = i - 1;
        k = D_0035f12c[i + 1].a != 0;
        if (func_002570a0(25) && D_0035f12c[i + 1].b == 2) k += 2;
        if (k != cur) func_00273818();
        break;
    case 3:
        func_00273c40(cur);
        break;
    case 4:
        func_00273cb8(cur);
        break;
    }
    func_00270c70(func_002570a0(25));
}
}  // namespace n00273530

// 00273678 (was src/anon/perm_00273678.cpp)
namespace n00273678 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef signed int s32;
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f014 asm("D_0035f014");
s32 func_0028b040(s32) asm("_ZN2Tz8JmReport7GetDataEj");
u8 *func_00281f20(s32) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s16 func_001a3820(u16) asm("func_001a3820");
s32 func_002570a0(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
u8 *func_001058e8(void) asm("_Z10getSaveRamv");
typedef struct S6
{
  u16 a;
  u16 b;
  u16 c;
} S6;
typedef struct Q
{
  u8 pad[8];
  s16 a[8];
} Q;
/*TARGET 00273678*/
void func_00273678(void) asm("func_00273678");
void func_00273678(void)
{
  s16 r = 0;
  s32 v = func_0028b040(D_0035f01c);
  if (v != 0)
  {
    r = func_001a3820(((S6 *) func_00281f20(D_0035f014))[v - 1].a);
  }
  v = func_002570a0(0x1a);
  ((Q *) ((func_001058e8() + 0x36f0) + (v * 2)))->a[0] = r;
}
}  // namespace n00273678

// 002736f8 (was src/anon/batch_w1589.cpp)
namespace n002736f8 {
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
u8* func_00273140(s32) asm("func_00273140");
s32 func_001a6598(u16) asm("func_001a6598");
void func_00273760(s32, s32) asm("func_00273760");
extern s32 D_0035f01c asm("D_0035f01c");
/*TARGET 002736f8*/
void func_002736f8(void) asm("func_002736f8");
void func_002736f8(void)
{
    s32 s;
    if (func_00287bc0() == 26) s = func_0028b040(D_0035f01c);
    else s = func_002570a0(26);
    func_00273760(s, func_001a6598(*(u16*)(func_00273140(s) + 4)) == 0);
}
}  // namespace n002736f8

// 00273760 (was src/anon/batch_w1789.cpp)
namespace n00273760 {
struct W1789Ent { s16 id; u8 f; u8 pad; u32 x; };
struct W1789Tbl { u32 a; s8 n; u8 pad[3]; W1789Ent e[1]; };
struct W1789Rec { u32 a; u16 id; };
extern W1789Tbl* D_0035f12c asm("D_0035f12c");
W1789Rec* func_00273140() asm("func_00273140");
void func_001a6510(s32) asm("func_001a6510");
void func_001a6548(s32) asm("func_001a6548");
s32 func_001a6598(s32) asm("func_001a6598");
/*TARGET 00273760*/
void func_00273760(s32 idx, u8 on) asm("func_00273760");
void func_00273760(s32 idx, u8 on) {
    s32 id = func_00273140()->id;
    if (on) func_001a6510(id);
    else func_001a6548(id);
    u8 v = func_001a6598(id) != 0;
    id = D_0035f12c->e[idx].id;
    for (s32 i = 0; i < D_0035f12c->n; i++)
        if (D_0035f12c->e[i].id == id) D_0035f12c->e[i].f = v;
}
}  // namespace n00273760

// 00273818 (was src/anon/batch_w1900_nsa.cpp)
namespace n00273818 {
struct E818 { s16 id; s8 a; s8 b; s32 pad; };
struct T818 { u8 pad0[4]; s8 x4; u8 pad5[3]; E818 e[1]; };
struct O818 { u8 pad[18]; u8 n; u8 pad2[33]; u16 a[8]; u16 b[8]; u8 pad3[161]; u8 c[1]; };
struct H818 { u8 pad[580]; O818* o; };
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_0028b040(u32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
H818* func_00281180(u32, s32) asm("func_00281180");
s32 func_001145b0(s32) asm("func_001145b0");
void func_0026b5a0(s32) asm("func_0026b5a0");
void func_00270c70(s32) asm("func_00270c70");
void func_002713c8(void) asm("func_002713c8");
void func_00273a28(void) asm("func_00273a28");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f010 asm("D_0035f010");
extern T818* D_0035f12c asm("D_0035f12c");
static inline s32 tf(s32 x) { return x != 0; }
/*TARGET 00273818*/
void func_00273818(void) asm("func_00273818");
void func_00273818(void) {
    s32 m = func_00287bc0();
    s32 idx;
    if ((u32)(m - 26) < 3) idx = func_0028b040(D_0035f01c);
    else idx = func_002570a0(26);
    s32 v = func_002570a0(25);
    if (v) idx--;
    s16 id = D_0035f12c->e[idx].id;
    s32 flag;
    s32 r;
    if (!v) {
        flag = D_0035f12c->e[idx].a == 0;
    } else {
        if (m == 31) {
            r = func_0028b040(D_0035f01c);
        } else {
            r = tf(D_0035f12c->e[idx].b);
            r <<= 1;
            r |= D_0035f12c->e[idx].a;
            r++;
            if (r >= 4) r = 0;
        }
        D_0035f12c->e[idx].a = r & 1;
        D_0035f12c->e[idx].b = tf(r & 2) << 1;
        flag = D_0035f12c->e[idx].a != 0;
    }
    O818* o = func_00281180(D_0035f010, v)->o;
    s32 i;
    for (i = 0; i < o->n; i++) {
        if (o->a[i] == id || o->b[i] == id) o->b[i] = flag ? id : 0;
    }
    if (v) {
        r = func_001145b0(D_0035f12c->e[idx].id);
        o->c[r] = D_0035f12c->e[idx].b;
    }
    func_0026b5a0(25);
    if ((u32)(m - 26) < 3) {
        s32 old = D_0035f12c->x4;
        func_00270c70(v);
        func_002713c8();
        if (old != D_0035f12c->x4) func_00273a28();
    }
}
}  // namespace n00273818

// 00273a28 (was src/anon/batch_w1596.cpp)
namespace n00273a28 {
// ---- 00273a28
struct S273a28 { u8 pad[4]; s8 n; };
extern S273a28* D_0035f12c asm("D_0035f12c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f04c asm("D_0035f04c");
s32 func_00257070(s32) asm("func_00257070");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_0028b038(s32) asm("func_0028b038");
s32 func_002892f8(s32) asm("func_002892f8");
void func_0028bfc0(s32, s32) asm("func_0028bfc0");
void func_0028be78(s32, s32) asm("func_0028be78");
void func_002891f0(s32, s32, s32, s32, s32) asm("func_002891f0");
void func_0028afd0(s32, s32) asm("func_0028afd0");
void func_0028af90(s32, s32) asm("func_0028af90");
/*TARGET 00273a28*/
void func_00273a28() asm("func_00273a28");
void func_00273a28() {
    s32 n = D_0035f12c->n;
    if (func_00257070(25)) n++;
    s32 a = func_002891e8(D_0035f01c);
    s32 b = func_0028b038(D_0035f01c);
    s32 c = func_002892f8(D_0035f01c);
    if (a == 0) {
        if (b != 0) b--;
    } else if (b != 0 && n < b + c) {
        b--;
    } else if (a != 0 && a >= n) {
        a--;
    }
    func_0028bfc0(D_0035f04c, n);
    func_0028be78(D_0035f04c, b);
    func_002891f0(D_0035f01c, a, 0, -1, -1);
    func_0028afd0(D_0035f01c, b);
    func_0028af90(D_0035f01c, n);
}
}  // namespace n00273a28

// 00273b30 (was src/anon/batch_w3765.cpp)
namespace n00273b30 {
struct E8 { s16 id; s8 f; u8 pad[5]; };
struct T8 { u8 hdr[8]; E8 e[1]; };
struct X244 { u8 pad[18]; u8 cnt; u8 pad2[33]; u16 a[8]; u16 b[8]; };
struct Y { u8 pad[580]; X244* x; };
extern T8* D_0035f12c asm("D_0035f12c");
extern s32 D_0035f01c asm("D_0035f01c");
extern s32 D_0035f010 asm("D_0035f010");
s32 func_00287bc0() asm("func_00287bc0");
s32 func_0028b040(s32) asm("func_0028b040");
s32 func_002570a0(s32) asm("func_002570a0");
s32 func_00257070(s32) asm("func_00257070");
Y* func_00281180(s32, s32) asm("func_00281180");
/*TARGET 00273b30*/
// Returns 1 when the selected entry's id is in some slot's b list but not in its a list.
// Register pins: ok in t7, table base in t4, the GetData&1 result kept in v0 (tie stops combine
// folding it into ok); without them gcc picks v0 for ok and fills the first branch slot.
s32 func_00273b30(void) asm("func_00273b30");
// Returns 1 when the selected entry's id is in some slot's b list but not in its a list.
// Register pins: ok in t7, table base in t4, the GetData&1 result kept in v0 (tie stops combine
// folding it into ok); without them gcc picks v0 for ok and fills the first branch slot.
s32 func_00273b30(void)
{
    s32 mode = func_00287bc0();
    s32 k;
    switch (mode) {
    case 26: case 27: k = func_0028b040(D_0035f01c); break;
    default: k = func_002570a0(26); break;
    }
    if (func_002570a0(25)) k--;
    register T8* bp asm("$12") = D_0035f12c;
    s16 id = bp->e[k].id;
    register s32 ok asm("$15") = bp->e[k].f != 0;
    switch (mode) {
    case 26: case 27: break;
    default: {
        register s32 v asm("$2") = func_0028b040(D_0035f01c) & 1;
        asm("" : "+r"(v));
        ok = v == 0;
        break;
    }
    }
    if (ok) {
        X244* x = func_00281180(D_0035f010, func_00257070(25))->x;
        s32 n = x->cnt;
        for (s32 i = 0; i < n; i++) {
            if (x->a[i] == id) continue;
            if (x->b[i] != id) continue;
            if (x->a[i] != id) return 1;
        }
    }
    return 0;
}
}  // namespace n00273b30

// 00273c40 (was src/anon/auto80_199_queue.cpp)
namespace n00273c40 {
/*TARGET 00273c40*/
/*NOSYM*/
void func_00273c40(s32 a0);
// 0x0026ed48: definition moved into src/anon/unit_0026c450.cpp

void func_00273c40(s32 a0) {
    u32 v0 = (u32)Tz::CmTop::GetSelectPos(25);
    u32 p = func_00281180(D_0035f010, v0);
    u8* b = (u8*)(*(u32*)(p + 580));

    if (a0 < 0) {
        u32 n = (u32)b[244] + 1;
        b[244] = (u8)n;
        if ((n & 0xffu) >= 6) {
            b[244] = 0;
        }
    } else {
        b[244] = (u8)a0;
    }

    *(u8*)(D_0035f12c + 3) = b[244];
}
}  // namespace n00273c40

// 00273cb8 (was src/anon/batch_w95.cpp)
namespace n00273cb8 {
struct ColEnt { u8 pad[5]; u8 col; u8 pad6[2]; };
struct ColSlot { s16 id; u8 pad2; s8 col; u8 pad4[4]; };
// 0x0026cda0: definition moved into src/anon/unit_0026c450.cpp

extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern ColSlot* D_0035f12c asm("D_0035f12c");
s32 func_00287bc0(void) asm("func_00287bc0");
ColEnt* func_00273180(u32, s32) asm("func_00273180");
// state_dispatch_2_3
u32 func_002570a0(u32) asm("func_002570a0");
u8* func_00281180(u32, u32) asm("func_00281180");
s32 func_0028b040(u32) asm("func_0028b040");
u8* func_001145b0(u32) asm("func_001145b0");
/*TARGET 00273cb8*/
void func_00273cb8(s32 sel) asm("func_00273cb8");
void func_00273cb8(s32 sel) {
    s32 k = func_00287bc0();
    ColEnt* tbl = func_00273180(4, -1);  // state_dispatch_2_3
    u32 alt = (u32)(k - 26) < 2;
    u32 off = *(u32*)(func_00281180(D_0035f010, func_002570a0(25)) + 580);
    s32 idx;
    if (alt) idx = func_0028b040(D_0035f01c);
    else idx = func_002570a0(26);
    u8* r = func_001145b0(D_0035f12c[idx].id);
    if (sel < 0) {
        for (s32 j = 0; j < 3; j++) {
            if (D_0035f12c[idx].col == tbl[j].col) {
                sel = j;
                break;
            }
        }
        sel++;
        if (sel >= 3) sel = 0;
    }
    r[off + 245] = tbl[sel].col;
    D_0035f12c[idx].col = tbl[sel].col;
}
}  // namespace n00273cb8

// 00273de0 (was src/anon/batch_wcx.cpp)
namespace n00273de0 {
// 0x0026c760: definition moved into src/anon/unit_0026c450.cpp

// Tz::Jiminy::Init
extern u8* D_0035f010 asm("D_0035f010");
s32 func_00257070(s32) asm("func_00257070");
s32 func_00281100(u8*) asm("func_00281100");
void func_00257050(s32, s32, s32) asm("func_00257050");
u32 func_00281140(u8*, s32) asm("func_00281140");
void func_0028fb68(s32, u32) asm("func_0028fb68");
s32 Jiminy_Init(u8, u8) asm("_ZN2Tz6Jiminy4InitEv");
/*TARGET 00273de0*/
s32 Jiminy_Init(u8 fwd, u8 apply) asm("_ZN2Tz6Jiminy4InitEv");
s32 Jiminy_Init(u8 fwd, u8 apply)
{
    s32 cur = func_00257070(25);
    s32 n = func_00281100(D_0035f010);
    if (fwd) {
        cur++;
        if (!(cur < n)) cur = 0;
    } else {
        cur--;
        if (cur < 0) cur = n - 1;
    }
    if (apply) {
        func_00257050(25, cur, 0);
        func_0028fb68(1, func_00281140(D_0035f010, cur));
    }
    return cur;
}
}  // namespace n00273de0

// .rodata 0x3739e4-0x373b08: tables that old code reads as extern D_
extern const u32 R_003739e4[2] asm("D_003739e4") __attribute__((aligned(4))) = { 0x2, 0x1 };
extern const u32 R_003739ec[1] asm("D_003739ec") __attribute__((aligned(4))) = { 0x32 };
extern const u32 R_003739f0[2] asm("D_003739f0") __attribute__((aligned(4))) = { 0x31, 0x0 };
extern const u32 R_003739f8[4] asm("D_003739f8") __attribute__((aligned(4))) = { 0x1070108, 0xfa0106, 0xf8, 0x0 };
extern const u32 R_00373a08[4] asm("D_00373a08") __attribute__((aligned(4))) = { 0x119011a, 0x1150118, 0x114, 0x0 };
extern const u32 R_00373a18[4] asm("D_00373a18") __attribute__((aligned(4))) = { 0x8481847d, 0x84838482, 0x8484, 0x0 };
extern const u32 R_00373a28[2] asm("D_00373a28") __attribute__((aligned(4))) = { 0x847e847d, 0x8480847f };
extern const u32 R_00373a30[8] asm("D_00373a30") __attribute__((aligned(4))) = { 0xc800c6, 0xbd00c7, 0xbe00bf, 0xb600b4, 0xa200b5, 0xa300a4, 0x9b0099, 0x9a };
extern const u32 R_00373a50[4] asm("D_00373a50") __attribute__((aligned(4))) = { 0xc500ce, 0xaa00bc, 0xa1, 0x0 };
extern const u32 R_00373a60[6] asm("D_00373a60") __attribute__((aligned(4))) = { 0xc100ca, 0xa600b8, 0xc9009d, 0xb700c0, 0x9c00a5, 0x0 };
extern const u32 R_00373a78[2] asm("D_00373a78") __attribute__((aligned(4))) = { 0x9df89df9, 0x0 };
extern const u32 R_00373a80[2] asm("D_00373a80") __attribute__((aligned(4))) = { 0x9dfa9dfb, 0x0 };
extern const u32 R_00373a88[2] asm("D_00373a88") __attribute__((aligned(4))) = { 0x9dfc9dfd, 0x0 };
extern const u32 R_00373a90[2] asm("D_00373a90") __attribute__((aligned(4))) = { 0x9dfe9dff, 0x0 };
extern const u32 R_00373a98[2] asm("D_00373a98") __attribute__((aligned(4))) = { 0x20100, 0x0 };
extern const u32 R_00373aa0[2] asm("D_00373aa0") __attribute__((aligned(4))) = { 0x20403, 0x0 };
extern const u32 R_00373aa8[2] asm("D_00373aa8") __attribute__((aligned(4))) = { 0x23242225, 0x0 };
extern const u32 R_00373ab0[12] asm("D_00373ab0") __attribute__((aligned(4))) = { 0x9e558486, 0x1d, 0x9e568487, 0x11d, 0x9e578488, 0x21d, 0x9e588489, 0x31d, 0x9e59848a, 0x41d, 0x9e5a848b, 0x51d };
extern const u32 R_00373ae0[6] asm("D_00373ae0") __attribute__((aligned(4))) = { 0x9e5b9e4e, 0x1a, 0x9e5c9e4f, 0x11b, 0x9e5d9e50, 0x21c };
extern const u32 R_00373af8[4] asm("D_00373af8") __attribute__((aligned(4))) = { 0x9e5e9e51, 0x1a, 0x9e5f9e52, 0x21c };

// 00273e88 (was gap, written for the unit): Jiminy menu: is entry k selectable in the current mode
namespace n00273e88 {
struct E8 { s16 id; s16 a; s16 b; s16 c; };
struct H8 { u8 p0[8]; E8 e[1]; };
extern u32 D_0035f010 asm("D_0035f010");
extern u32 D_0035f01c asm("D_0035f01c");
extern H8* D_0035f12c asm("D_0035f12c");
s32 GetMode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 GetPartyMax(u32) asm("_ZN2Tz9PartyInfo11GetPartyMaxEv");
s32 GetSelectPos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 GetData(u32) asm("func_0028b040");
s32 func_00272b60(s32) asm("func_00272b60");
s32 func_00273e88(s32 k) asm("func_00273e88");
s32 func_00273e88(s32 k)
{
    s32 r;
    s32 m = GetMode();
    if (m == 25) {
        r = 1;
    } else if (m == 26 || m == 27) {
        if (k == -11 || k == -10) {
            r = (GetPartyMax(D_0035f010) < 2) == 0;
        } else {
            r = 1;
            if (GetSelectPos(25)) {
                func_00272b60(GetData(D_0035f01c));
            } else {
                m = GetData(D_0035f01c);
                if (func_00272b60(m) == 1 && (k >= 0 || k == -6)) {
                    if (D_0035f12c->e[m].id == 24) r = 0;
                }
            }
        }
    } else {
        m = func_00272b60(GetSelectPos(26));
        r = m != 0x21;
    }
    return r;
}
}  // namespace n00273e88
// 00273fa0: Jiminy menu init (mode 41; exit thread 0x274b40). The store order between the two func_0028d068 calls is the final
// order; the f20c/f21c objects are real new-expressions (their address highs are evaluated before the allocation calls).
namespace n00273fa0 {
struct Sys;
void func_0014b920(void*) asm("func_0014b920");
struct T32 { u8 d[32]; T32() { func_0014b920(this); } ~T32() {} } __attribute__((aligned(16)));
void* operator new[](unsigned int, Sys*) asm("_Znaj");
struct Hp;
struct HpVt { void* (*alloc)(Hp*, u32, void*); void (*free)(Hp*, void*); };
struct Hp { HpVt* vt; };
struct Sys { u8 pad[20]; Hp* heap; };
struct Mm { u32 a; u32 b; };
extern u32 D_0035f138 asm("D_0035f138");
extern s32 D_0035f13c asm("D_0035f13c");
extern u32 D_0035f140 asm("D_0035f140");
extern s32 D_0035f144 asm("D_0035f144");
extern u32 D_0035f148 asm("D_0035f148");
extern u32 D_0035f14c asm("D_0035f14c");
extern u32 D_0035f150 asm("D_0035f150");
extern s8* D_0035f1fc asm("D_0035f1fc");
struct Cur;
extern Cur* D_0035f200 asm("D_0035f200");
extern u32 D_0035f204 asm("D_0035f204");
extern u32 D_0035f208 asm("D_0035f208");
extern u8* D_0035f20c asm("D_0035f20c");
extern u32 D_0035f210 asm("D_0035f210");
struct Lst;
extern Lst* D_0035f214 asm("D_0035f214");
struct IStat;
extern IStat* D_0035f218 asm("D_0035f218");
extern void* D_0035f21c asm("D_0035f21c");
extern u8 D_0035f220 asm("D_0035f220");
extern u8 D_0035f221 asm("D_0035f221");
extern u8 D_0035f222 asm("D_0035f222");
extern T32* D_0035f224 asm("D_0035f224");
extern s8 D_0035f228 asm("D_0035f228");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern Hp* D_0032ba14 asm("D_0032ba14");
extern Sys* D_00347f80 asm("D_00347f80");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
void func_00292540(void) asm("func_00292540");
void SetModeMax(s32, s32) asm("_ZN2Tz8MenuBase10SetModeMaxEii");
void func_00253818(s32) asm("func_00253818");
void func_00259350(s32) asm("func_00259350");
s32 GetPri(s32) asm("_ZN2Tz10MenuCursor6GetPriEi");
void func_0028d068(s32, s32) asm("_Z16wtarget_0028d068jjjj");
void* func_00288be8(s32) asm("func_00288be8");
void func_002889f0(void*, s32, s32) asm("func_002889f0");
struct Cur { u8 d[56]; Cur(s32 a, s32 b) { func_002889f0(this, a, b); } static void* operator new(unsigned int n) { return func_00288be8(n); } };
void func_0028b9b0(void*) asm("func_0028b9b0");
struct Lst { u8 d[52]; Lst() { func_0028b9b0(this); } static void* operator new(unsigned int n, Hp* h) { return h->vt->alloc(h, n, __builtin_return_address(0)); } };
struct IStat { u8 d[444]; IStat(); static void* operator new(unsigned int n, Hp* h, void* ra) { return h->vt->alloc(h, n, ra); } };
void ItemStatCtor(void*) asm("_ZN2Tz8ItemStatC1Ev");
inline IStat::IStat() { ItemStatCtor(this); }
Sys* LoadDataGetSystem(void) asm("func_00103570");
void* LoadDataAlloc(u32, Sys*) asm("func_001063c0");
void SeqCtor(u8*) asm("_ZN2YI8SEQUENCEC1Ev");
void func_0031a838(u8*) asm("func_0031a838");
void func_00323540(void*) asm("func_00323540");
u8* NewArr(u32, void*) asm("_Znaj");
s32 isMonochrome(void) asm("_ZN2dk10Monochrome12isMonochromeEv");
s8 func_0013aa38(s32) asm("func_0013aa38");
s32 func_002535c0(void) asm("func_002535c0");
s8 func_002764b0(u32) asm("func_002764b0");
void func_00293e00(void*) asm("func_00293e00");
void func_00288670(void (*)(void)) asm("func_00288670");
void func_002766c0(void) asm("func_002766c0");
void func_002a1f88(void) asm("func_002a1f88");
void func_002a9ce8(void) asm("func_002a9ce8");
void func_002acda8(void) asm("func_002acda8");
void func_002944f8(void) asm("func_002944f8");
void func_002957b8(void) asm("func_002957b8");
void func_00296fa0(void) asm("func_00296fa0");
void func_00297cf8(void) asm("func_00297cf8");
void func_002994f8(void) asm("func_002994f8");
void func_0029a820(void) asm("func_0029a820");
void func_0029edb8(void) asm("func_0029edb8");
void func_002a0588(void) asm("func_002a0588");
void func_002a4c68(void) asm("func_002a4c68");
void func_002a68e8(void) asm("func_002a68e8");
void func_002a7678(void) asm("func_002a7678");
void func_002a8948(void) asm("func_002a8948");
void func_002aea98(void) asm("func_002aea98");
void func_002926c0(s32) asm("func_002926c0");
void NextModeToMode(s32, s32) asm("func_00287bd0");
void SetState(s32) asm("_ZN2Tz8Selector8SetStateEi");
Mm* getMenuMode(void) asm("func_00103eb0");
void func_00102818(u32, s32, s32, void (*)(void), s32) asm("func_00102818");
void PauseThread(void) asm("func_00274b40");
static inline void CtorA(u8* q) {
    *(u32*)(q + 12) = 0;
    *(u32*)q = (u32)D_00347e60;
    SeqCtor(q + 24);
    *(u32*)q = (u32)D_00347e40;
    *(u32*)(q + 408) = 0;
}
static inline void CtorB1(u8* q, u32 f98) {
    *(u32*)q = f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    SeqCtor(q + 24);
    *(u32*)(q + 408) = 0;
    *(u32*)q = (u32)D_00347e40;
}
static inline void CtorB2(u8* q, u32 f98) {
    *(u32*)q = f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    SeqCtor(q + 24);
    *(u32*)(q + 408) = 0;
    *(u32*)q = (u32)D_00347e40;
}
static inline void CtorB3(u8* q, u32 f98) {
    *(u32*)q = f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    SeqCtor(q + 24);
    *(u32*)q = (u32)D_00347e40;
    *(u32*)(q + 408) = 0;
}
struct Q4 { u8 d[1872]; Q4() { u8* q = (u8*)this; u32 k98 = (u32)D_00347f98; CtorA(q); CtorB1(q + 436, k98); CtorB2(q + 872, k98); CtorB3(q + 1308, k98); } static void* operator new(unsigned int n, Sys* s) { return LoadDataAlloc(n, s); } };
struct Big { u8 d[0x11320]; Big() { func_00323540(this); } static void* operator new(unsigned int n, Sys* s) { return LoadDataAlloc(n, s); } };
void func_00273fa0(void) asm("func_00273fa0");
void func_00273fa0(void) {
    s32 sel;
    s32 mode;
    func_00292540();
    SetModeMax(41, 3);
    func_00253818(3);
    func_00259350(3);
    D_0035f13c = GetPri(0);
    func_0028d068(30065, -1);
    D_0035f214 = 0;
    D_0035f218 = 0;
    if (!(D_0035f140 & 4)) D_0035f140 = 0;
    D_0035f14c = 5;
    D_0035f144 = -1;
    D_0035f148 = 0;
    D_0035f150 = 1;
    D_0035f210 = 0;
    D_0035f204 = 0;
    D_0035f208 = 0;
    func_0028d068(30065, -1);
    D_0035f200 = new Cur(18, 1);
    D_0035f214 = new (D_0032ba14) Lst;
    D_0035f218 = new (D_00347f80->heap, 0) IStat;
    D_0035f20c = (u8*)new (LoadDataGetSystem()) Q4;
    D_0035f1fc = (s8*)LoadDataAlloc(4, LoadDataGetSystem());
    D_0035f21c = new (LoadDataGetSystem()) Big;
    D_0035f224 = new (LoadDataGetSystem()) T32[2];
    D_0035f1fc[0] = -1;
    D_0035f228 = -1;
    if (isMonochrome()) D_0035f228 = func_0013aa38(0);
    D_0035f3d4 = 30045;
    sel = func_002535c0();
    if (sel < 0) sel = 0;
    D_0035f1fc[2] = sel == 2;
    if (sel != 2) {
        s8* p = D_0035f1fc;
        *p = func_002764b0(D_0035f138);
        if (D_0035f1fc[0] < 0) sel = 0;
    }
    mode = 0;
    switch (sel) {
    case 0: D_0035f1fc[0] = -1; break;
    case 1: mode = 2; break;
    case 2: mode = 1; D_0035f1fc[0] = 19; break;
    case 3: mode = 11; break;
    }
    if (!(D_0035f140 & 4)) {
        func_00293e00((void*)LoadDataGetSystem());
        D_0035f222 = 0;
    } else {
        D_0035f222 = 1;
        func_00288670(func_002766c0);
    }
    D_0035f220 = 0;
    D_0035f221 = 0;
    func_002a1f88();
    func_002a9ce8();
    func_002acda8();
    func_002944f8();
    func_002957b8();
    func_00296fa0();
    func_00297cf8();
    func_002994f8();
    func_0029a820();
    func_0029edb8();
    func_002a0588();
    func_002a4c68();
    func_002a68e8();
    func_002a7678();
    func_002a8948();
    func_002aea98();
    func_002926c0(1);
    D_0035f1fc[1] = 0;
    NextModeToMode(mode, 0);
    SetState(0);
    func_00102818(getMenuMode()->b, 0, 2000, PauseThread, 4096);
}
}  // namespace n00273fa0
