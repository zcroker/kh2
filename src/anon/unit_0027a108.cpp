// Linked unit 0x0027a108-0x0027a6d8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 0027a108 (was src/anon/batch_w41.cpp)
namespace n0027a108 {
// 0x00259510: definition moved into src/anon/unit_002588e8.cpp

u32 func_00257770(void) asm("func_00257770");
s32 func_00287bc0(void) asm("func_00287bc0");
void func_0028dac8(u32, u32) asm("func_0028dac8");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_0028acb8(u32) asm("func_0028acb8");
void func_0028aa40(u32) asm("func_0028aa40");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 0027a108*/
void func_0027a108(void) asm("func_0027a108");
void func_0027a108(void) {
    u32 o = func_00257770();
    if (func_00287bc0() == 15) {
        func_0028dac8(o, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}
}  // namespace n0027a108

// 0027a180 (was src/anon/auto200_999.cpp)
namespace n0027a180 {
void func_002579e0(void) asm("_Z13func_002579e0v");
void func_0028abe0(u32) asm("_Z13func_0028abe0j");
u32 func_0028acc8(u32) asm("_Z13func_0028acc8j");
extern u32 D_0035f01c asm("D_0035f01c");
/*TARGET 0027a180*/
// 0x00271e80: definition moved into src/anon/unit_00271e08.cpp

void func_0027a180() asm("_Z13func_0027a180v");
// 0x00271e80: definition moved into src/anon/unit_00271e08.cpp

void func_0027a180() {
    func_002579e0();
    if (func_0028acc8(D_0035f01c) != 0) {
        func_0028abe0(D_0035f01c);
    }
}
}  // namespace n0027a180

// 0027a1c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0027a1c8 {
extern u32 D_0035f01c asm("D_0035f01c");
u32 func_0028acc8(...) asm("func_0028acc8");
// 0x00262118: definition moved into src/anon/unit_0025f6b8.cpp

extern "C" u32 func_00257780(...) asm("func_00257780");
/*TARGET 0027a1c8*/
u32 func_0027a1c8() asm("_Z13func_0027a1c8v");
u32 func_0027a1c8() {
    u32 v0 = func_00257780();
    if (v0 == 0u) {
        u32 a0 = *(u32*)(u32)&D_0035f01c;
        if (a0 != 0u) {
            v0 = (u32)(0u < func_0028acc8(a0));
        }
    }
    return v0;
}
}  // namespace n0027a1c8


// 0027a208 (was src/anon/asm_0027a208.s, whole asm until 2026-11-21)
namespace n0027a208 {
/* List rows: reset every row, then one row per table entry from the scroll top: group header when the
 * group byte changes, name, optional count text, icon and a colour for the equip state.
 * v is the one scratch value of the function (selector, colour, icon byte): it keeps s0 busy, so the
 * table address high part and the row pointers land in s1 like the original. */
struct Ent { s8 b0; s8 b1; s8 b2; u8 b3; u16 h; s8 f; u8 pad; };
struct Tbl { u8 pad[7]; s8 count; Ent e[1]; };
u8* func_00257770(void) asm("func_00257770");
s32 func_002892f8(void*) asm("func_002892f8");
u8* func_002891b8(void*, s32) asm("func_002891b8");
void func_00138c10(void*, s32) asm("func_00138c10");
s32 func_00257140(s32) asm("func_00257140");
s32 func_00192048(s32) asm("func_00192048");
s32 func_0028b038(void*) asm("func_0028b038");
void func_0028be78(void*, s32) asm("func_0028be78");
s32 func_002570a0(s32) asm("func_002570a0");
void func_0027aed8(s32, s32*, s32*) asm("func_0027aed8");
void func_00288fd8(void*, s32, s32, s32) asm("func_00288fd8");
s32 func_0027bf20(s32) asm("func_0027bf20");
s32 func_00259618(u16, u8*, s32) asm("func_00259618");
s32 func_00192cc0(u8*, void*, s32) asm("func_00192cc0");
u8* func_00273180(s32, s32) asm("func_00273180");
s32 func_002595b8(s32, u8*, s32) asm("func_002595b8");
s32 func_00286d28(s32, s32) asm("func_00286d28");
s32 func_00287028(s32, s32) asm("func_00287028");
s32 func_0027ae78(s32) asm("func_0027ae78");
s32 func_00286ec8(s32, s32) asm("func_00286ec8");
s32 func_00287218(s32, s32) asm("func_00287218");
extern void* D_0035f01c asm("D_0035f01c");
extern s32 D_0035ef6c asm("D_0035ef6c");
extern Tbl* D_0035f230 asm("D_0035f230");
extern void* D_0035f04c asm("D_0035f04c");
extern s16 D_00373e18[] asm("D_00373e18");
extern s16 D_00373e20[] asm("D_00373e20");
extern u16 D_00373e28[] asm("D_00373e28");
extern u8 D_00373de0[] asm("D_00373de0");
extern s32 D_00373dfc asm("D_00373dfc");
extern s32 D_00373e00 asm("D_00373e00");
/*TARGET 0027a208*/
void func_0027a208(void) asm("func_0027a208");
void func_0027a208(void) {
    s32 flag;
    s32 id;
    u8* base;
    s32 n;
    s32 i;
    s32 k;
    s32 cur;
    u8* o;
    u8* o2;
    u8* p;
    s32 v;
    u16 h;
    s8 qq;

    i = 0;
    base = func_00257770();
    n = func_002892f8(D_0035f01c);
    for (; i < n; i++) {
        func_00138c10(func_002891b8(D_0035f01c, i), D_0035ef6c);
        o = base + i * 436 + 24304;
        func_00138c10(o, D_0035ef6c);
        *(s32*)(o + 408) = 0;
        o = base + i * 436 + 3376;
        func_00138c10(o, D_0035ef6c);
        *(s32*)(o + 408) = 0;
        o = base + i * 436 + 13840;
        func_00138c10(o, D_0035ef6c);
        *(s32*)(o + 408) = 0;
        func_00138c10(base + i * 408 + 0x87d0, D_0035ef6c);
    }
    if (D_0035f230->count == 0) {
        o = base + 24304;
        func_00138c10(func_002891b8(D_0035f01c, 0), 236);
        func_00138c10(o, func_00257140(0));
        *(s32*)(o + 432) = 2;
        *(s32*)(o + 408) = func_00192048(0xb372);
        return;
    }
    k = func_0028b038(D_0035f01c);
    func_0028be78(D_0035f04c, k);
    v = func_002570a0(15);
    func_0027aed8(v, &flag, &id);
    if (k != 0 && D_0035f230->e[k].b0 == D_0035f230->e[k + 1].b0) cur = D_0035f230->e[k].b0; else cur = -1;
    for (i = 0; i < n; i++, k++) {
        s8 c;
        if (k >= D_0035f230->count) return;
        c = D_0035f230->e[k + 1].b0;
        if (cur != c) {
            u8* p1 = base + i * 436 + 3376;
            func_00138c10(p1, D_00373e20[c]);
            *(s32*)(p1 + 408) = func_00192048(D_00373e28[c]);
        }
        cur = D_0035f230->e[k + 1].b0;
        func_00138c10(func_002891b8(D_0035f01c, i), v = D_00373e18[cur]);
        func_00288fd8(D_0035f01c, i, v, v);
        o2 = base + i * 436;
        h = D_0035f230->e[k].h;
        func_00138c10(p = o2 + 24304, func_00257140(func_0027bf20(k) == 0));
        *(s32*)(p + 408) = func_00259618(h, base + i * 32 + 0xae10, D_0035f230->e[k].f != 0);
        if (!flag) {
            p = o2 + 13840;
            if (D_0035f230->e[k + 1].b1) {
                o = p;
                func_00138c10(o, 251);
                *(s32*)(o + 408) = func_00192cc0(base + i * 4 + 0xb170, D_00373de0, D_0035f230->e[k + 1].b1);
            }
        }
        if (D_0035f230->e[k + 1].b2 >= 0) {
            v = func_00273180(4, D_0035f230->e[k + 1].b2)[4];
            func_002595b8(v, base + i * 4 + 0xb110, 1);
        }
        if (D_0035f230->e[k + 1].b3 != 0xff) {

            if (!flag) {
                if (!func_00286d28(id, (s8)D_0035f230->e[k + 1].b3)) continue;
                v = func_00287028(id, (s8)D_0035f230->e[k + 1].b3) ? D_00373e00 : D_00373dfc;
            } else {
                qq = D_0035f230->e[k + 1].b3 & 0x7f;
                if ((s8)D_0035f230->e[k + 1].b3 & 0x80) {
                    if (!func_00286ec8(func_0027ae78(id), qq)) continue;
                    v = func_00287218(func_0027ae78(id), qq) ? D_00373e00 : D_00373dfc;
                } else {
                    if (!func_00286d28(0, qq)) continue;
                    v = func_00287028(0, qq) ? D_00373e00 : D_00373dfc;
                }
            }
            func_00138c10(base + i * 408 + 0x87d0, v);
        }
    }
}
}  // namespace n0027a208
