// Linked unit 0x00268b30-0x00269658 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/item_info.hpp"

// 00268b30 (was src/anon/batch_w94.cpp)
namespace n00268b30 {
u8* func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
u32 func_002570a0(s32) asm("func_002570a0");
u32 Tz__CmEquip__GetItemTbl(u32, s32) asm("Tz__CmEquip__GetItemTbl");
u16* YS__ITEM_TABLE__get_param(u32) asm("YS__ITEM_TABLE__get_param");
u16* func_001a80c8(u16) asm("func_001a80c8");
// table24_find_by_id
u32 func_00257140(s32) asm("func_00257140");
void func_0028d980(u8*, s32, u32, u32, u32, u32, s32, s32, s32) asm("func_0028d980");
u32 func_00192048(u16) asm("func_00192048");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
u32 func_0023aa98(u8*) asm("func_0023aa98");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
extern u32 D_0035ef64 asm("D_0035ef64");
extern u32 D_0035ef68 asm("D_0035ef68");
extern u32 D_0035f03c asm("D_0035f03c");
/*TARGET 00268b30*/
void func_00268b30(s32 idx) asm("func_00268b30");
void func_00268b30(s32 idx) {
    u8* w = func_00257770();
    u32 st = func_00287bc0();
    if (st - 5 >= 2) return;
    u16 id = YS__ITEM_TABLE__get_param(Tz__CmEquip__GetItemTbl(func_002570a0(2), 2))[1];
    if (!id) return;
    u8* o = w + 2504;
    id = func_001a80c8(id)[4];
    u8* m = w + 1656;
    func_0028d980(o, idx + 1, D_0035ef68, D_0035ef64, D_0035f03c, func_00257140(2), -1, -1, 0);
    *(u32*)(o + 408) = func_00192048(id);
    func_0028dcc0(o, w + 1632);
    func_00139620(o);
    func_001395f8(o);
    u32 a = func_0023aa18(m);
    u32 b = func_0023aa38(m);
    u32 c = func_0023aa98(m);
    func_00138c68(o, a, b);
    *(u32*)(o + 424) = c;
    *(u32*)(o + 432) = 1;
}
}  // namespace n00268b30

// 00268c68 (was src/anon/batch_w92.cpp)
namespace n00268c68 {
struct E268 { u16 id; u16 pad[2]; };
s32 func_002570a0(s32) asm("func_002570a0");
u32 func_00269508(s32) asm("func_00269508");
s32 func_00281f18(u32) asm("func_00281f18");
u32 func_00257130(void) asm("func_00257130");
E268* func_00281f20(u32) asm("func_00281f20");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_0028afd0(u32, s32) asm("func_0028afd0");
// obj_set_signed18
void Tz__ScrollBar__SetPos(u32, s32) asm("Tz__ScrollBar__SetPos");
extern u32 D_0035f0ec asm("D_0035f0ec");
extern u32 D_0035f01c asm("D_0035f01c");
extern u32 D_0035f04c asm("D_0035f04c");
/*TARGET 00268c68*/
void func_00268c68(void) asm("func_00268c68");
void func_00268c68(void) {
    s32 cur = 0;
    s32 top = 0;
    s32 k = func_002570a0(2);
    u32 mode = func_00269508(k);
    s32 n = func_00281f18(D_0035f0ec);
    u16 id = func_00281f20(func_00257130())[k].id;
    if (id) {
        E268* p = func_00281f20(D_0035f0ec);
        for (s32 i = 0; i < n; i++, p++) {
            if (p->id == id) {
                cur = i;
                if (mode >= 2) cur = i + 1;
                break;
            }
        }
    }
    if (mode >= 2) n++;
    if (cur >= 8) {
        top = cur - 7;
        cur = 7;
    }
    if (n != 0 && top + cur >= n) {
        top = cur - n + 1;
        cur = n - 1;
    }
    Tz__Select__SetCurrent(D_0035f01c, cur, 0, -1, -1);
    func_0028afd0(D_0035f01c, top);  // obj_set_signed18
    Tz__ScrollBar__SetPos(D_0035f04c, top);
}
}  // namespace n00268c68

// 00268db8 (was src/anon/batch_wcx2.cpp)
namespace n00268db8 {
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
// 0x002648b8: definition moved into src/anon/unit_002640a8.cpp

// ---- 00268db8
extern void* D_0035f01c_8db8 asm("D_0035f01c");
extern void* D_0035f018_8db8 asm("D_0035f018");
extern void* D_0035f010_8db8 asm("D_0035f010");
extern void* D_0035f0ec asm("D_0035f0ec");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(void* s) asm("func_00289380");
s32 func_00289310_8db8(void* s) asm("func_00289310");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00269f58(void) asm("func_00269f58");
s32 func_002911f8(void* p) asm("func_002911f8");
s32 func_0028f930(s32 a) asm("func_0028f930");
s32 func_00256ef0(void) asm("func_00256ef0");
s32 func_00257970(void) asm("func_00257970");
void func_00287f90(s32 a) asm("func_00287f90");
void func_00256c40(void) asm("func_00256c40");
void func_00269ef8(void) asm("func_00269ef8");
void func_00291288(void* p) asm("func_00291288");
s32 func_00287c10(void) asm("func_00287c10");
void func_00287c30(void) asm("func_00287c30");
void func_0028f7e8(s32 a) asm("func_0028f7e8");
void Tz__CmEquip__CheckAutoReplenishment(void) asm("Tz__CmEquip__CheckAutoReplenishment");
s32 func_00257070(s32 a) asm("func_00257070");
u8* func_00281180(void* p, s32 i) asm("func_00281180");
void func_00188ac8(u32 a) asm("func_00188ac8");
void func_002678a8(void) asm("func_002678a8");
s32 Tz__CmEquip__isBaseLoop(void) asm("Tz__CmEquip__isBaseLoop");
void Tz__CmEquip__SetLoopList(void) asm("Tz__CmEquip__SetLoopList");
void func_0028fa98(s32 a) asm("func_0028fa98");
void func_00269a60(void) asm("func_00269a60");
void func_00287c90(s32 a) asm("func_00287c90");
s32 func_0028afa8_8db8(void* s) asm("func_0028afa8");
void func_0026b8f0(void) asm("func_0026b8f0");
s32 func_00287df0_8db8(s32 a, s32 b, s32 c, void (*d)(void), s32 e) asm("func_00287df0");
s32 func_00242848(s32 a) asm("func_00242848");
struct Ent268 { u16 id; u8 pad[4]; };
Ent268* func_00281f20(void* p) asm("func_00281f20");
s32 func_0026b2c0(void) asm("func_0026b2c0");
void func_00269378(void) asm("func_00269378");
void func_00287bd0(s32 a, s32 b) asm("func_00287bd0");
void func_00287c00(s32 m) asm("func_00287c00");
void func_00281d48(void) asm("func_00281d48");
void func_00281e20(void) asm("func_00281e20");
s32 func_00288040(void) asm("func_00288040");
void func_00288018(void) asm("func_00288018");
// global_zero_4dwords
void func_0026ab18(u32 id) asm("func_0026ab18");
void Tz__SelHist__FadeOut(s32 a) asm("Tz__SelHist__FadeOut");
// record884_refresh_by_index
void func_00256e80(void) asm("func_00256e80");
void Tz__CMenuHelp__FadeOut(void) asm("Tz__CMenuHelp__FadeOut");
// sync_global_index_if_changed
void Tz__CmEquip__FadeOutList(void) asm("Tz__CmEquip__FadeOutList");
void func_00281b30_8db8(void) asm("func_00281b30");
void func_002831e0(s32 a, s32 b) asm("func_002831e0");
void func_00287cc0(s32 s) asm("func_00287cc0");
void func_0026b448(void) asm("func_0026b448");
void func_00287da0(void) asm("func_00287da0");
/*TARGET 00268db8*/
// Item-list menu: per-frame state update.
void Tz__CmEquip__CtrlEquip(void) asm("Tz__CmEquip__CtrlEquip");
// Item-list menu: per-frame state update.
void Tz__CmEquip__CtrlEquip(void) {
    s32 busy = 0;
    s32 cur = func_00289380(D_0035f01c_8db8);
    s32 st = func_00287cd0();
    s32 mode = func_00287bc0();
    if (st == 2) {
        if (func_00269f58() || func_002911f8(D_0035f018_8db8) || func_0028f930(2) || func_00256ef0()) busy = 1;
        if (busy || func_00257970()) {
            if (cur == -1 && !func_00289310_8db8(D_0035f01c_8db8)) return;
            func_00287f90(0);
            func_00256c40();
            func_00269ef8();
            func_00291288(D_0035f018_8db8);
            return;
        }
        func_00287c10();
        func_00287c30();
        func_0028f7e8(2);
        Tz__CmEquip__CheckAutoReplenishment();
        func_00188ac8(*(u32*)(func_00281180(D_0035f010_8db8, func_00257070(1)) + 580));
        func_002678a8();
        return;
    }
    if (cur != -1 || func_00289310_8db8(D_0035f01c_8db8)) {
        if (!Tz__CmEquip__isBaseLoop()) {
            Tz__CmEquip__SetLoopList();
            func_0028fa98(-1);
        }
    }
    if (st == 0 && Tz__CmEquip__isBaseLoop()) {
        func_00269a60();
        func_00287c90(1);
    }
    s32 max = func_0028afa8_8db8(D_0035f01c_8db8);
    if (!func_00242848(func_00287df0_8db8(cur, func_00289310_8db8(D_0035f01c_8db8), 1, func_0026b8f0, 1))) {
        switch (cur) {
        case -4:
            func_0026b448();
            func_00291288(D_0035f018_8db8);
            Tz__CmEquip__CheckAutoReplenishment();
            func_00188ac8(*(u32*)(func_00281180(D_0035f010_8db8, func_00257070(1)) + 580));
            func_00287da0();
            break;
        case -7:
            func_00287bd0(37, 0);
            if (mode == 9) func_002831e0(0, 9);
            else if (mode == 6) func_002831e0(3, 6);
            break;
        case -2:
            Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
            Tz__SelHist__FadeOut(2);  // record884_refresh_by_index
            func_00256e80();
            Tz__CmEquip__FadeOutList();
            func_00281b30_8db8();
            func_00287cc0(2);
            func_00287c00(2);
            break;
        case -1:
            break;
        default:
            if (cur >= 0 && cur < max) {
                Ent268* tbl = func_00281f20(D_0035f0ec);
                if (func_0026b2c0()) {
                    func_00269378();
                    func_00287bd0(4, 0);
                    func_00287c00(mode);
                } else {
                    s32 idx = cur - (mode != 5 && mode != 6);
                    func_0026ab18(idx >= 0 ? tbl[idx].id : 0);
                    Tz__SelHist__FadeOut(2);  // record884_refresh_by_index
                    func_00256e80();
                    Tz__CMenuHelp__FadeOut();  // sync_global_index_if_changed
                    Tz__CmEquip__FadeOutList();
                    func_00281b30_8db8();
                    func_00287c90(1);
                    func_00287c00(2);
                }
            }
            break;
        }
    }
    if (func_00287cd0() == 1) {
        func_00281d48();
        func_00281e20();
    }
    if (func_00288040()) func_00288018();
}
}  // namespace n00268db8

// 002691c8 (was src/anon/batch_w7.cpp)
namespace n002691c8 {
void func_00257388(u32, u32) asm("func_00257388");
void func_002571e0(u32) asm("func_002571e0");
void func_00287cc0(u32) asm("func_00287cc0");
/*TARGET 002691c8*/
// 0x00258a88: definition moved into src/anon/unit_002588e8.cpp

void func_002691c8(void) asm("func_002691c8");
// 0x00258a88: definition moved into src/anon/unit_002588e8.cpp

void func_002691c8(void) {
    func_00257388(0x846a, 0);
    func_002571e0(1);
    func_00287cc0(0);
}
}  // namespace n002691c8

// 002691f8 (was src/anon/batch_wcx2.cpp)
namespace n002691f8 {
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
extern u32 D_0035f024 asm("D_0035f024");
// --------------------
s32 func_00289380_x8962(s32) asm("func_00289380");
s32 func_00287cd0() asm("func_00287cd0");
void func_00287bc0_x8964() asm("func_00287bc0");
s32 func_002576d0() asm("func_002576d0");
void func_002575a8() asm("func_002575a8");
void func_00287c30() asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00289310_x8969(s32) asm("func_00289310");
s32 func_00257610(s32) asm("func_00257610");
void func_00257670(s32) asm("func_00257670");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void Tz__CmEquip__CtrlAutoConfirm() asm("Tz__CmEquip__CtrlAutoConfirm");
void Tz__CmEquip__UpdateTopList() asm("Tz__CmEquip__UpdateTopList");
void func_00257530(s32) asm("func_00257530");
void func_00287c00(s32) asm("func_00287c00");
void func_00281d48() asm("func_00281d48");
void func_00281e20() asm("func_00281e20");
/*TARGET 002691f8*/
void func_002691f8() asm("func_002691f8");
void func_002691f8() {
    s32 r = func_00289380_x8962(D_0035f024);
    s32 a = func_00287cd0();
    func_00287bc0_x8964();
    if (a == 2) {
        if (!func_002576d0()) {
            func_002575a8();
            func_00287c30();
            func_00287cc0(1);
        }
        return;
    }
    if (r != -1 || func_00289310_x8969(D_0035f024)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (!a && func_00257610(0)) func_00287c90(1);
    if (!func_00242848(func_00287df0(r, func_00289310_x8969(D_0035f024), 0, 0, 1))) {
        switch (r) {
        case 1:
            Tz__CmEquip__CtrlAutoConfirm();
            Tz__CmEquip__UpdateTopList();
        case -2: case 0:
            func_00257530(0);
            func_00287cc0(2);
            func_00287c00(2);
            break;
        case -4: case -3: case -1:
            break;
        }
    }
    func_00281d48();
    func_00281e20();
}
}  // namespace n002691f8

// 00269378 (was src/anon/batch_w8.cpp)
namespace n00269378 {
// 0x00258dc8: definition moved into src/anon/unit_002588e8.cpp

void func_00257388(u32, u32) asm("func_00257388");
void func_002571e0(u32) asm("func_002571e0");
void func_00287cc0(u32) asm("func_00287cc0");
/*TARGET 00269378*/
void func_00269378(void) asm("func_00269378");
void func_00269378(void) {
    func_00257388(0xc22e, 0);
    func_002571e0(0);
    func_00287cc0(0);
}
}  // namespace n00269378

// 002693a8 (was src/anon/batch_w272.cpp)
namespace n002693a8 {
extern s32 D_0035f024 asm("D_0035f024");
s32 func_00289380(s32) asm("func_00289380");
s32 func_00287cd0(void) asm("func_00287cd0");
void func_00287bc0(void) asm("func_00287bc0");
s32 func_002576d0(void) asm("func_002576d0");
void func_002575a8(void) asm("func_002575a8");
void func_00287c30(void) asm("func_00287c30");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_00289310(s32) asm("func_00289310");
s32 func_00257610(s32) asm("func_00257610");
void func_00257670(s32) asm("func_00257670");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 func_00242848(s32) asm("func_00242848");
void func_00257530(s32) asm("func_00257530");
void func_00281d48(void) asm("func_00281d48");
void func_00281e20(void) asm("func_00281e20");
/*TARGET 002693a8*/
void Tz__CmEquip__CtrlAbilityWarning(void) asm("Tz__CmEquip__CtrlAbilityWarning");
void Tz__CmEquip__CtrlAbilityWarning(void) {
    s32 a = func_00289380(D_0035f024);
    s32 b = func_00287cd0();
    func_00287bc0();
    if (b == 2) {
        if (func_002576d0()) return;
        func_002575a8();
        func_00287c30();
        func_00287cc0(1);
        return;
    }
    if (a != -1 || func_00289310(D_0035f024)) {
        if (!func_00257610(0)) func_00257670(0);
    }
    if (b == 0 && func_00257610(0)) func_00287c90(1);
    if (!func_00242848(func_00287df0(a, func_00289310(D_0035f024), 0, 0, 1))) {
        if (a == -2) goto d;
        if (a < -1) goto e;
        if (a == -1) goto e;
        if (a != 0) goto e;
    d:
        func_00257530(0);
        func_00287cc0(2);
    e:;
    }
    func_00281d48();
    func_00281e20();
}
}  // namespace n002693a8

// 00269508 (was src/tozawa/item_info.cpp)
namespace Tz { // method 00269508
u32 func_00257130(...) asm("func_00257130");
u32 func_002827e0(...) asm("func_002827e0");
/*TARGET 00269508*/
// get_indexed_word

u32 ItemInfo::GetEquipMax(s32 a0) {
    u32 arr[5];
    s32 i = 0;
    while (i < 5) {
        u32 v = func_00257130();
        v = func_002827e0(v, i);  // get_indexed_word
        arr[i] = v;
        i = i + 1;
    }

    s32 sum = 0;
    i = 0;
    while (1) {
        sum += (s32)arr[i];
        if (a0 < sum) {
            break;
        }
        i = i + 1;
        if (i >= 5) {
            break;
        }
    }

    return (u32)i;
}
}  // Tz

// 002695a0 (was src/anon/batch_w1593.cpp)
namespace n002695a0 {
// 0x00258630: definition moved into src/anon/unit_002584c8.cpp

// ---- 002695a0
u32 func_00257130() asm("func_00257130");
s32 func_002827e0(u32, s32) asm("func_002827e0");
s32 func_002813b8() asm("func_002813b8");
s32 func_00281420() asm("func_00281420");
/*TARGET 002695a0*/
s32 Tz__CmEquip__CurPos2FormType(s32 a) asm("Tz__CmEquip__CurPos2FormType");
s32 Tz__CmEquip__CurPos2FormType(s32 a) {
    s32 v[5];
    s32 i, n;
    s32 m;
    for (i = 0; i < 5; i++) v[i] = func_002827e0(func_00257130(), i);
    i = 0;
    m = func_002813b8() & func_00281420();
    a -= v[0];
    n = 0;
    for (; i < 7; i++) {
        if ((u8)((m >> i) & 1)) {
            if (a == n) return i;
            n++;
        }
    }
    return i;
}
}  // namespace n002695a0

