// Linked unit 0x0020e9f8-0x0020edd0 (after whole-asm 0x20e960): fog/colour setters, packet stack allocator, file size helpers (.rodata 0x3707c0).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0020e9f8 (was src/anon/batch_w211.cpp)
namespace n0020e9f8 {
struct W211Q { f32 a; f32 b; };
extern W211Q D_00359110 asm("D_00359110");
// 0x001e1df8: definition moved into src/anon/unit_001e0cb8.cpp

void wtarget_0020e9f8(f32 a, f32 b) asm("_Z16wtarget_0020e9f8jjjj");
/*TARGET 0020e9f8*/
void wtarget_0020e9f8(f32 a, f32 b) asm("_Z16wtarget_0020e9f8jjjj");
void wtarget_0020e9f8(f32 a, f32 b) {
    f32 x = b * 255.0f;
    b = b - a;
    D_00359110.a = -255.0f / b;
    D_00359110.b = x / b;
}
}  // namespace n0020e9f8

// 0020ea48 (was src/anon/batch_w5.cpp)
namespace n0020ea48 {
extern u8 D_00359150[3] asm("D_00359150");
/*TARGET 0020ea48*/
void func_0020ea48(u8 a, u8 b, u8 c) asm("func_0020ea48");
void func_0020ea48(u8 a, u8 b, u8 c) {
    D_00359150[0] = a;
    D_00359150[1] = b;
    D_00359150[2] = c;
}
}  // namespace n0020ea48

// 0020ea70 (was src/anon/batch_w8.cpp)
namespace n0020ea70 {
// Store two byte arguments as floats into D_00359110 (+8, +12).
struct S359110 { u32 pad[2]; f32 x; f32 y; };
extern S359110 D_00359110 asm("D_00359110");
/*TARGET 0020ea70*/
void wtarget_0020ea70(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0020ea70jjjj");
void wtarget_0020ea70(u32 a0, u32 a1, u32, u32) {
    u8 y = a0;
    u8 x = a1;
    D_00359110.x = x;
    D_00359110.y = y;
}
}  // namespace n0020ea70

// 0020eaa0 (was gap)
namespace n0020eaa0 {
void func_0020eaa0(void) asm("func_0020eaa0");
void func_0020eaa0(void) {}
}  // namespace n0020eaa0

// 0020eaa8 (was gap)
namespace n0020eaa8 {
void func_0020eaa8(void) asm("func_0020eaa8");
void func_0020eaa8(void) {}
}  // namespace n0020eaa8

// 0020eab0 (was gap)
namespace n0020eab0 {
void func_0020eab0(void) asm("func_0020eab0");
void func_0020eab0(void) {}
}  // namespace n0020eab0

// 0020eab8 (was gap)
namespace n0020eab8 {
void func_0020eab8(void) asm("func_0020eab8");
void func_0020eab8(void) {}
}  // namespace n0020eab8

// 0020eac0 (was src/anon/batch_w9.cpp)
namespace n0020eac0 {
extern u32 D_00359810 asm("D_00359810");
extern u32 D_00359788 asm("D_00359788");
extern u32 D_00359808 asm("D_00359808");
extern u32 D_00359780 asm("D_00359780");
/*TARGET 0020eac0*/
void func_0020eac0(void) asm("func_0020eac0");
void func_0020eac0(void) {
    D_00359788 = 0x70000000;
    D_00359810 = 0x70004000;
    D_00359780 = 0;
    D_00359808 = 0;
}
}  // namespace n0020eac0

// 0020eaf0 (was gap)
namespace n0020eaf0 {
void func_0020eaf0(void) asm("func_0020eaf0");
void func_0020eaf0(void) {}
}  // namespace n0020eaf0

// 0020eaf8 (was src/anon/batch_w40.cpp)
namespace n0020eaf8 {
extern s32 D_00359780 asm("D_00359780");
extern s32 D_00359788[] asm("D_00359788");
extern s32 D_00359808 asm("D_00359808");
extern s32 D_00359810[] asm("D_00359810");
/*TARGET 0020eaf8*/
// Stack allocator push: returns the current top and records top + size.
s32 func_0020eaf8(s32 size) asm("func_0020eaf8");
// Stack allocator push: returns the current top and records top + size.
s32 func_0020eaf8(s32 size) {
    s32 i = D_00359780;
    if (i < 31) {
        s32 cur = D_00359788[i];
        s32 end = cur + size;
        if (!(D_00359810[D_00359808] < end)) {
            D_00359780 = ++i;
            D_00359788[i] = end;
            return cur;
        }
    }
    *(s32*)0 = 0;
    return 0;
}
}  // namespace n0020eaf8

// 0020eb70 (was gap)
namespace n0020eb70 {
extern s32 D_00359788[] asm("D_00359788");
extern s32 D_00359808 asm("D_00359808");
extern s32 D_00359810[] asm("D_00359810");
// Stack allocator push from the top end: returns top - size and records the old top.
s32 func_0020eb70(s32 size) asm("func_0020eb70");
s32 func_0020eb70(s32 size) {
    s32 i = D_00359808;
    if (i < 31) {
        s32 cur = D_00359810[i];
        s32 p = cur - size;
        if (!(p < D_00359788[i])) {
            D_00359808 = ++i;
            D_00359810[i] = cur;
            return p;
        }
    }
    *(s32*)0 = 0;
    return 0;
}
}  // namespace n0020eb70

// 0020ebd8 (was src/anon/batch_w23.cpp)
namespace n0020ebd8 {
// 0x001d9c68: definition moved into src/anon/unit_001d7458.cpp

extern s32 D_00359780 asm("D_00359780");
extern s32 D_00359788[] asm("D_00359788");
/*TARGET 0020ebd8*/
void func_0020ebd8(s32 v) asm("func_0020ebd8");
void func_0020ebd8(s32 v) {
    s32 n = D_00359780;
    if (n > 0 && D_00359788[n] - D_00359788[n - 1] == v) {
        D_00359780 = n - 1;
        return;
    }
    *(u32*)0 = 0;
}
}  // namespace n0020ebd8

// 0020ec18 (was gap)
namespace n0020ec18 {
extern s32 D_00359808 asm("D_00359808");
extern s32 D_00359810[] asm("D_00359810");
void func_0020ec18(s32 v) asm("func_0020ec18");
void func_0020ec18(s32 v) {
    s32 n = D_00359808;
    if (n > 0) {
        s32 b = D_00359810[n];
        s32 a = D_00359810[n - 1];
        if (a - b == v) {
            D_00359808 = n - 1;
            return;
        }
    }
    *(u32*)0 = 0;
}
}  // namespace n0020ec18

// 0020ec58 (was gap)
namespace n0020ec58 {
extern u8 D_00359788[] asm("D_00359788");
extern s32 D_00359808 asm("D_00359808");
extern s32 D_00359810[] asm("D_00359810");
s32 func_0020ec58(s32 size) asm("func_0020ec58");
s32 func_0020ec58(s32 size) {
    return (D_00359810[D_00359808 + 1] < (s32)(D_00359788 + size)) ? -1 : 0;
}
}  // namespace n0020ec58

// 0020ec90 (was gap)
namespace n0020ec90 {
extern s32 D_00359780 asm("D_00359780");
extern s32 D_00359788[] asm("D_00359788");
extern u8 D_00359810[] asm("D_00359810");
s32 func_0020ec90(s32 size) asm("func_0020ec90");
s32 func_0020ec90(s32 size) {
    return ((s32)(D_00359810 - size) < D_00359788[D_00359780 + 1]) ? -1 : 0;
}
}  // namespace n0020ec90

// 0020ecc8 (was src/anon/auto80_199_queue.cpp)
namespace n0020ecc8 {
/*TARGET 0020ecc8*/
u32 func_0020ecc8(u32 a0, u32 a1) asm("_Z13func_0020ecc8jj");
u32 func_0020ecc8(u32 a0, u32 a1) {
    u32 s18 = a1;
    s32 s17 = sceOpen(a0, 1);
    if (s17 < 0) {
        *(volatile u32*)0 = 0;
        return 0;
    }

    s32 s16 = sceLseek(s17, 0, 2);
    sceLseek(s17, 0, 0);

    s32 t = sceRead(s17, s18, s16);
    if ((s16 ^ t) != 0) {
        s16 = 0;
    }

    sceClose(s17);
    func_003058a0(0);
    return (u32)s16;
}
}  // namespace n0020ecc8

// 0020ed68 (was gap)
namespace n0020ed68 {
// Size of a file (0 and a crash store when it does not open).
s32 func_0020ed68(u32 name) asm("func_0020ed68");
s32 func_0020ed68(u32 name) {
    s32 fd = sceOpen(name, 1);
    if (fd < 0) {
        *(volatile u32*)0 = 0;
        return 0;
    }
    s32 n = sceLseek(fd, 0, 2);
    sceClose(fd);
    return n;
}
}  // namespace n0020ed68

