// Linked unit 0x0014c7f0-0x0014d298 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int W1820u128 __attribute__((mode(TI)));
#include "../tozawa/menu_sound.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../harata/libdk/timer.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../harata/libdk/clock.hpp"

// 0014c7f0 (was gap)
namespace n0014c7f0 {
// dk::Timer per-frame update (registered by 0x14c908)
extern s32 D_00349de8 asm("D_00349de8");
extern s32 D_00349df0 asm("D_00349df0");
extern s32 D_00349df4 asm("D_00349df4");
extern s32 D_00349df8 asm("D_00349df8");
extern u32 D_00349dfc asm("D_00349dfc");
extern u8 D_00349e00 asm("D_00349e00");
u32 func_0014ca10_7f0() asm("_Z13func_0014ca10jjjj");
void func_001991a8_7f0(s32, s32) asm("func_001991a8");
void gap_0014c7f0() asm("gap_0014c7f0");
void gap_0014c7f0() {
    if (func_0014ca10_7f0()) return;
    switch (D_00349dfc) {
    case 0:
        return;
    case 1:
        D_00349dfc = 2;
        return;
    case 2:
        break;
    default:
        return;
    }
    if (D_00349e00 == 1) {
        D_00349df8 = D_00349df4 - (D_00349de8 - D_00349df0);
        if (D_00349df8 > 0) return;
        D_00349df8 = 0;
        D_00349dfc = 0;
        func_001991a8_7f0(74, 0);
    } else {
        D_00349df8 = D_00349de8 - D_00349df0;
        if (D_00349df8 > 0x34bbf) {
            D_00349df8 = 0x34bbf;
            return;
        }
        if (D_00349df4 <= 0) return;
        if (D_00349df8 < D_00349df4) return;
        D_00349df8 = D_00349df4;
        D_00349dfc = 0;
        func_001991a8_7f0(74, 0);
    }
}
}  // namespace n0014c7f0

// 0014c8e0 (was src/anon/tiny_auto80_solver.cpp)
namespace n0014c8e0 {
void func_0014c8e0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0014c8e0jjjjjjjj");
extern u8 D_00349de8 asm("D_00349de8");
extern u8 D_00349dec asm("D_00349dec");
extern u8 D_00349df8 asm("D_00349df8");
extern u8 D_00349dfc asm("D_00349dfc");
/*TARGET 0014c8e0*/
void func_0014c8e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0014c8e0jjjjjjjj");
void func_0014c8e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32* r15 = (u32*)&D_00349de8;
    u32* r14 = (u32*)&D_00349df8;
    *r15 = 0;
    *r14 = 0;
    r15 = (u32*)&D_00349dec;
    r14 = (u32*)&D_00349dfc;
    *r15 = 0;
    *r14 = 0;
}
}  // namespace n0014c8e0

// 0014c908 (was src/anon/auto200_999.cpp)
namespace n0014c908 {
// to_1025f8
u32 func_00102788(u32, u32, u32, u32) asm("_Z13func_00102788jjjj");
void func_0014c8e0() asm("_Z13func_0014c8e0v");
extern u8 D_0014c7f0 asm("D_0014c7f0");
extern u32 D_0032b91c asm("D_0032b91c");
/*TARGET 0014c908*/
// 0x0011ee18: definition moved into src/anon/unit_0011c128.cpp

u32 func_0014c908() asm("_Z13func_0014c908v");
// 0x0011ee18: definition moved into src/anon/unit_0011c128.cpp

u32 func_0014c908() {
    func_0014c8e0();
    u32 a0 = D_0032b91c;
    return func_00102788(a0, 0, 1, (u32)&D_0014c7f0);
}
}  // namespace n0014c908

// 0014c940 (was src/anon/batch_w10.cpp)
namespace n0014c940 {
extern s32 D_00349df4 asm("D_00349df4");
extern u8 D_00349e00 asm("D_00349e00");
extern s32 D_00349df8 asm("D_00349df8");
extern s32 D_00349dfc asm("D_00349dfc");
void Timer_setCountDown(u32) asm("_ZN2dk5Timer12setCountDownEj");
/*TARGET 0014c940*/
// 0x00123dd0: definition moved into src/anon/unit_00123990.cpp

// 00135ff0: moved to src/naka/libkn/effect_observer.cpp

void Timer_setCountDown(u32 n) asm("_ZN2dk5Timer12setCountDownEj");
// 0x00123dd0: definition moved into src/anon/unit_00123990.cpp

// 00135ff0: moved to src/naka/libkn/effect_observer.cpp

void Timer_setCountDown(u32 n) {
    n *= 60;
    D_00349dfc = 0;
    D_00349df8 = n;
    D_00349e00 = 1;
    D_00349df4 = n;
}
}  // namespace n0014c940

// 0014c970 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014c970 {
extern u32 D_00349df4 asm("D_00349df4");
extern u32 D_00349df8 asm("D_00349df8");
extern u32 D_00349dfc asm("D_00349dfc");
extern u32 D_00349e00 asm("D_00349e00");
/*TARGET 0014c970*/
// 0x00146e88: definition moved into src/anon/unit_00145600.cpp

void func_0014c970(u32 a0) asm("_Z13func_0014c970j");
// 0x00146e88: definition moved into src/anon/unit_00145600.cpp

void func_0014c970(u32 a0) {
    a0 = a0 * 60;
    *(u8*)&D_00349e00 = 0;
    D_00349df4 = a0;
    D_00349dfc = 0;
    D_00349df8 = 0;
}
}  // namespace n0014c970

// 0014c9a0 (was src/harata/libdk/timer.cpp)
namespace dk { // method 0014c9a0
extern u32 D_00349e00 asm("D_00349e00");
/*TARGET 0014c9a0*/
u32 Timer::isDown() {
    u32 v = *(u8*)&D_00349e00;
    v ^= 0x1u;
    return (v < 1u);
}
}  // dk

// 0014c9b8 (was src/anon/batch_w5.cpp)
namespace dk { // method 0014c9b8
extern u32 D_00349de8 asm("D_00349de8");
extern u32 D_00349df0 asm("D_00349df0");
extern u32 D_00349dfc asm("D_00349dfc");
void Timer::start() {
    D_00349df0 = D_00349de8;
    D_00349dfc = 1;
}
}  // dk

// 0014c9d8 (was src/anon/batch_w1725_g.cpp)
namespace n0014c9d8 {
// dk::Timer pause flags. + -g: the original keeps the store before
// jr ra with an unfilled (nop) delay slot.
extern volatile u32 D_00349dec asm("D_00349dec");
void Timer_pauseOn(u32 f) asm("_ZN2dk5Timer7pauseOnEj");
/*TARGET 0014c9d8*/
void Timer_pauseOn(u32 f) asm("_ZN2dk5Timer7pauseOnEj");
void Timer_pauseOn(u32 f) { D_00349dec |= f; }
}  // namespace n0014c9d8

// 0014c9f0 (was src/anon/batch_w1725_g.cpp)
namespace n0014c9f0 {
// dk::Timer pause flags. + -g: the original keeps the store before
// jr ra with an unfilled (nop) delay slot.
extern volatile u32 D_00349dec asm("D_00349dec");
void Timer_pauseOff(u32 f) asm("_ZN2dk5Timer8pauseOffEj");
/*TARGET 0014c9f0*/
void Timer_pauseOff(u32 f) asm("_ZN2dk5Timer8pauseOffEj");
void Timer_pauseOff(u32 f) { D_00349dec &= ~f; }
}  // namespace n0014c9f0

// 0014ca10 (was src/anon/tiny.cpp)
namespace n0014ca10 {
extern u32 D_00349dec asm("D_00349dec");
/*TARGET 0014ca10*/
// 0x0014ac08: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ca10(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014ca10jjjj");
// 0x0014ac08: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ca10(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_359e0c
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (D_00349dec != 0);
}
}  // namespace n0014ca10

// 0014ca20 (was src/anon/batch_w2.cpp)
namespace n0014ca20 {
extern u32 D_00349df8 asm("D_00349df8");
extern u32 D_00349dfc asm("D_00349dfc");
/*TARGET 0014ca20*/
// 0x00143448: definition moved into src/anon/unit_00142c90.cpp

u32 func_0014ca20(void) asm("func_0014ca20");
// 0x00143448: definition moved into src/anon/unit_00142c90.cpp

u32 func_0014ca20(void) {
    u32 r = D_00349df8;
    D_00349dfc = 0;
    return r;
}
}  // namespace n0014ca20

// 0014ca38 (was src/anon/tiny.cpp)
namespace n0014ca38 {
void func_0014ca38(void*) asm("_Z13func_0014ca38jjjj");
/*TARGET 0014ca38*/
// 0x0014ace8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ca38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014ca38jjjj");
// 0x0014ace8: definition moved into src/harata/libdk/fade.cpp

u32 func_0014ca38(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-25096)));
}
}  // namespace n0014ca38

// 0014ca48 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014ca48 {
u32 func_0014ca10(...) asm("func_0014ca10");
/*TARGET 0014ca48*/
// get_global_359e0c

u32 func_0014ca48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0014ca48jjjjjjjj");
// get_global_359e0c

u32 func_0014ca48(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r2 = ((u32(*)())func_0014ca10)();
    r14 = (u32)(0x0035u << 16);
    if (r2 == 0u) {
        r15 = *(u32*)((u32)r14 + (s32)(-25112));
        r15 = (u32)((s32)r15 + (1));
        *(u32*)((u32)r14 + (s32)(-25112)) = r15;
    }
    return r2;
}
}  // namespace n0014ca48

// 0014ca78 (was src/anon/misc_1.cpp)
namespace n0014ca78 {
/*TARGET 0014ca78*/
s64 func_0014ca78(s64 param0, s64 param1, s64 param2, s64 param3) asm("_Z13func_0014ca78xxxx");
s64 func_0014ca78(s64 param0, s64 param1, s64 param2, s64 param3) {
    s64 result = 0, arg0 = param0, arg1 = param1, arg2 = param2, arg3 = param3, returnAddr = 0;
    result = arg0 + 0;
    return result;
}
}  // namespace n0014ca78

// 0014ca80 (was src/anon/batch_w90.cpp)
namespace n0014ca80 {
// 0x00146128: definition moved into src/anon/unit_00145600.cpp

// 0014ca80: split a 60 Hz frame counter into hours/minutes/seconds/hundredths.
u32 func_0014ca78(u32) asm("func_0014ca78");
s32 __fixunssfsi(f32) asm("__fixunssfsi");
/*TARGET 0014ca80*/
void dk__Clock__vCountToHMSMS(u32 a0, u32* h, u32* m, u32* s, s32* cs) asm("dk__Clock__vCountToHMSMS");
void dk__Clock__vCountToHMSMS(u32 a0, u32* h, u32* m, u32* s, s32* cs)
{
    u32 t = func_0014ca78(a0);
    *h = t / 216000; t %= 216000;
    *m = t / 3600; t %= 3600;
    *s = t / 60; t %= 60;
    f32 k = 1.6666666f;
    f32 x = t;
    x *= k;
    *cs = __fixunssfsi(x);
}
}  // namespace n0014ca80

// 0014cb58 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014cb58 {
u32 func_001058e8(...) asm("func_001058e8");
/*TARGET 0014cb58*/
void dk__Clock__newGame() asm("_Z18dk__Clock__newGamev");
void dk__Clock__newGame() {
    u32 v0 = func_001058e8();
    *(volatile u32*)((u32)v0 + (s32)(9284)) = 0u;
    u32 t7 = (u32)((s32)v0 + (9284));
    s32 t6 = 18;
    *(volatile u32*)((u32)v0 + (s32)(9288)) = 0u;
    do {
        *(u32*)((u32)t7 + (s32)(8)) = 0u;
        t6 = (s32)(t6 + (-1));
        t7 = (u32)((s32)t7 + (4));
    } while (t6 >= 0);
}
}  // namespace n0014cb58

// 0014cba0 (was src/anon/tiny_jal_wrappers.cpp)
namespace n0014cba0 {
u32 func_001058e8(u32, u32, u32, u32) asm("_Z13func_001058e8jjjj");
/*TARGET 0014cba0*/
// 0014a2c8: moved to src/anon/unit_00149fa8.cpp

u32 dk__Clock__getPlayTime(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z22dk__Clock__getPlayTimejjjj");
// 0014a2c8: moved to src/anon/unit_00149fa8.cpp

u32 dk__Clock__getPlayTime(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(9284));
    return r2;
}
}  // namespace n0014cba0

// 0014cbc0 (was src/anon/tiny_jal_wrappers.cpp)
namespace n0014cbc0 {
u32 func_001058e8(u32, u32, u32, u32) asm("_Z13func_001058e8jjjj");
/*TARGET 0014cbc0*/
u32 func_0014cbc0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014cbc0jjjj");
u32 func_0014cbc0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(9288));
    return r2;
}
}  // namespace n0014cbc0

// 0014cbe0 (was src/harata/libdk/clock.cpp)
namespace dk { // method 0014cbe0
u32 func_001058e8(...) asm("func_001058e8");
u32 dk__Clock__vCountToHMSMS(...) asm("dk__Clock__vCountToHMSMS");
/*TARGET 0014cbe0*/
u32 Clock::getPlayTimeToHMSMS(u32& a0, u32& a1, u32& a2, u32& a3) {
    u32 s0 = (u32)&a0;
    u32 s1 = (u32)&a1;
    u32 s2 = (u32)&a2;
    u32 s3 = (u32)&a3;
    u32 v0 = func_001058e8();
    return dk__Clock__vCountToHMSMS(*(u32*)(v0 + 9284), s0, s1, s2, s3);
}
}  // dk

// 0014cc40 (was src/anon/batch_w1521.cpp)
namespace n0014cc40 {
void* getSaveRam_w1521(void) asm("_Z10getSaveRamv");
void dk__Clock__vCountToHMSMS(s32, s32, s32, s32, s32) asm("dk__Clock__vCountToHMSMS");
/*TARGET 0014cc40*/
void func_0014cc40(s32 a0, s32 a1, s32 a2, s32 a3, s32 idx) asm("func_0014cc40");
void func_0014cc40(s32 a0, s32 a1, s32 a2, s32 a3, s32 idx) {
    u8* b = (u8*)getSaveRam_w1521() + 0x2444;
    asm("" : "+r"(b)); /* keeps base+0x2444 apart from the +8 field offset */
    dk__Clock__vCountToHMSMS(((s32*)b)[idx + 2], a0, a1, a2, a3);
}
}  // namespace n0014cc40

// 0014ccb8 (was src/anon/batch_w1804_nsa.cpp)
namespace n0014ccb8 {
struct W1804CntS { u32 a; u32 b; u32 arr[19]; };
struct W1804CntP { u8 pad[0x2444]; W1804CntS s; };
W1804CntP* func_001058e8(void) asm("func_001058e8");
extern s32 D_0032b984 asm("D_0032b984");
extern u8 D_0032bae0 asm("D_0032bae0");
/*TARGET 0014ccb8*/
// Saturating counters (limit 0xCDFE5C3) kept in locals.
void func_0014ccb8(void) asm("func_0014ccb8");
// Saturating counters (limit 0xCDFE5C3) kept in locals.
void func_0014ccb8(void)
{
    W1804CntP* q = func_001058e8();
    volatile u32 a = q->s.a;
    volatile u32 b = q->s.b;
    if (a <= 0xCDFE5C3) a++;
    q->s.a = a;
    q->s.b = b;
    if (D_0032b984) {
        volatile s32 i = D_0032bae0;
        if (i >= 0 && i < 19) {
            W1804CntS* s = &q->s;
            volatile u32 c = s->arr[i];
            if (c <= 0xCDFE5C3) c++;
            s->arr[i] = c;
        }
    }
}
}  // namespace n0014ccb8

// 0014cd98 (was src/anon/tiny_auto80_queue.cpp)
namespace n0014cd98 {
u32 func_0014ce50(f32) asm("_Z13func_0014ce50f");
// 0x0013f1e8: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_001024a8(...) asm("func_001024a8");
extern u8 D_004574b8 asm("D_004574b8");
u32 func_0014f0b0(...) asm("func_0014f0b0");
/*TARGET 0014cd98*/
u32 func_0014cd98(u32 a0) asm("_Z13func_0014cd98j");
u32 func_0014cd98(u32 a0) {
    if (func_0014f0b0(&D_004574b8) == 0u) {
        func_001024a8(a0);
    }
    return func_0014ce50(*(f32*)&D_004574b8);
}
}  // namespace n0014cd98

// 0014cde0 (was src/anon/batch_w11.cpp)
namespace n0014cde0 {
// 00135900: moved to src/naka/libkn/obj_observer.cpp

extern u32 D_004574b8 asm("D_004574b8");
extern u32 D_0032b91c asm("D_0032b91c");
void func_0014f030(void*, f32, f32, f32) asm("func_0014f030");
// obj_set_lerp_params
void func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");
void func_0014cd98(void) asm("func_0014cd98");
void Vsync_setGameSpeed(f32, f32, f32) asm("_ZN2dk5Vsync12setGameSpeedEfff");
/*TARGET 0014cde0*/
void Vsync_setGameSpeed(f32 a, f32 b, f32 c) asm("_ZN2dk5Vsync12setGameSpeedEfff");
void Vsync_setGameSpeed(f32 a, f32 b, f32 c) {
    func_0014f030(&D_004574b8, a, b, c);  // obj_set_lerp_params
    func_00102788(D_0032b91c, 0, 800000, func_0014cd98);
}
}  // namespace n0014cde0

// 0014ce20 (was src/anon/tiny.cpp)
namespace n0014ce20 {
extern u32 D_00349e20 asm("D_00349e20");
/*TARGET 0014ce20*/
void func_0014ce20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014ce20jjjj");
void func_0014ce20(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = a0 & 0xffu;
    *(u8*)&D_00349e20 = (u8)v;
}
}  // namespace n0014ce20

// 0014ce30 (was src/anon/tiny_wrappers_imp.cpp)
namespace n0014ce30 {
u32 func_0014ce88(u32, u32, u32, u32) asm("_Z13func_0014ce88jjjj");
/*TARGET 0014ce30*/
// 0x00143328: definition moved into src/anon/unit_00142c90.cpp

u32 func_0014ce30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014ce30jjjj");
// 0x00143328: definition moved into src/anon/unit_00142c90.cpp

u32 func_0014ce30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0035u << 16);
    *(u32*)((u32)r15 + (s32)(-25060)) = r4;
    return func_0014ce88(r4, r5, r6, r7);
}
}  // namespace n0014ce30

// 0014ce50 (was src/anon/tiny.cpp)
namespace n0014ce50 {
extern u32 D_00349e0c asm("D_00349e0c");
/*TARGET 0014ce50*/
// 0x0014acd8: definition moved into src/harata/libdk/fade.cpp

// 0014b248: moved to src/anon/unit_0014b150.cpp

void func_0014ce50(f32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014ce50fjjj");
// 0x0014acd8: definition moved into src/harata/libdk/fade.cpp

// 0014b248: moved to src/anon/unit_0014b150.cpp

void func_0014ce50(f32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    *(f32*)&D_00349e0c = a0;
}
}  // namespace n0014ce50

// 0014ce60 (was src/anon/batch_wlit.cpp)
namespace n0014ce60 {
extern f32 D_00349e0c asm("D_00349e0c");
/*TARGET 0014ce60*/
void dk__Vsync__initGameSpeed(void) asm("dk__Vsync__initGameSpeed");
void dk__Vsync__initGameSpeed(void) { D_00349e0c = 1.0f; }
}  // namespace n0014ce60

// 0014ce78 (was src/anon/tiny.cpp)
namespace n0014ce78 {
extern u32 D_00349e10 asm("D_00349e10");
/*TARGET 0014ce78*/
f32 func_0014ce78(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014ce78jjjj");
f32 func_0014ce78(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return *(f32*)&D_00349e10;
}
}  // namespace n0014ce78

// 0014ce88 (was src/anon/batch_w56.cpp)
namespace n0014ce88 {
void wtarget_0014ce88(void) asm("_Z16wtarget_0014ce88jjjj");
// 0x00143ae0: definition moved into src/anon/unit_00142c90.cpp

// 0014ce88: count frames then derive a scaled time step and its reciprocal
extern s32 D_00349e1c asm("D_00349e1c");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e0c asm("D_00349e0c");
extern f32 D_00349e14 asm("D_00349e14");
extern f32 D_00349e18 asm("D_00349e18");
/*TARGET 0014ce88*/
void wtarget_0014ce88(void) asm("_Z16wtarget_0014ce88jjjj");
void wtarget_0014ce88(void)
{
    D_00349e10 = 0.0f;
    for (s32 i = 0; i < D_00349e1c + 1; i++) D_00349e10 += 1.0f;
    f32 s = D_00349e10;
    D_00349e14 = s;
    D_00349e10 = s * D_00349e0c;
    D_00349e18 = 1.0f / D_00349e10;
}
}  // namespace n0014ce88

// 0014cf18 (was src/anon/batch_w1762_g.cpp)
namespace n0014cf18 {
// C++ linkage: the build binds these to their absolute addresses.
void func_0014ccb8(void) asm("_Z13func_0014ccb8v");
void func_003058d0(s32) asm("_Z13func_003058d0i");
void func_0014ca48(void) asm("func_0014ca48");
void func_0014d4e8(void) asm("func_0014d4e8");
extern volatile s32 D_00349e04 asm("D_00349e04");
extern volatile s32 D_00349e08 asm("D_00349e08");
/*TARGET 0014cf18*/
s32 func_0014cf18(void) asm("func_0014cf18");
s32 func_0014cf18(void) {
    func_0014ccb8();
    func_0014ca48();
    D_00349e04++;
    D_00349e08++;
    func_0014d4e8();
    func_003058d0(0);
    func_003058d0(2);
    asm volatile("sync.l\n\tei");  // gcc cannot emit sync.l / ei
    return 0;
}
}  // namespace n0014cf18

// 0014cf80 (was src/anon/misc_1.cpp)
namespace n0014cf80 {
/*TARGET 0014cf80*/
void func_0014cf80(void* self) asm("_Z13func_0014cf80Pv");
void func_0014cf80(void* self) {}
}  // namespace n0014cf80

// 0014cf88 (was src/anon/batch_w17.cpp)
namespace n0014cf88 {
void func_0014cf80(void) asm("func_0014cf80");
void func_001b7f88(void) asm("func_001b7f88");
void func_002ef7c8(void) asm("func_002ef7c8");
void func_0014d060(void) asm("func_0014d060");
u32 func_0014e088(void) asm("func_0014e088");
void func_0014e5f0(u32) asm("func_0014e5f0");
/*TARGET 0014cf88*/
void func_0014cf88(void) asm("func_0014cf88");
void func_0014cf88(void) {
    func_0014cf80();
    func_001b7f88();
    func_002ef7c8();
    func_0014d060();
    func_0014e5f0(func_0014e088());
}
}  // namespace n0014cf88

// 0014cfc8 (was src/anon/batch_w12.cpp)
namespace n0014cfc8 {
// obj_dispatch_bitfield64
void func_0014ce20(s32) asm("func_0014ce20");
void func_0014ce30(s32) asm("func_0014ce30");
void dk__Vsync__initGameSpeed(void) asm("dk__Vsync__initGameSpeed");
extern volatile s32 D_00349e04 asm("D_00349e04");
extern volatile s32 D_00349e08 asm("D_00349e08");
/*TARGET 0014cfc8*/
// 0x00138698: definition moved into src/anon/unit_00138480.cpp

void func_0014cfc8(void) asm("func_0014cfc8");
// 0x00138698: definition moved into src/anon/unit_00138480.cpp

void func_0014cfc8(void) {
    func_0014ce20(1);
    func_0014ce30(1);
    dk__Vsync__initGameSpeed();
    D_00349e04 = 0;
    D_00349e08 = 0;
}
}  // namespace n0014cfc8

// 0014d008 (was src/anon/batch_w34.cpp)
namespace n0014d008 {
void u_tail0_0014d008(void) asm("_Z16u_tail0_0014d008v");
void func_0014cfc8(void) asm("func_0014cfc8");
void func_0014c908(void) asm("func_0014c908");
void sceGsSyncVCallback(void*) asm("sceGsSyncVCallback");
void func_0014d308(void) asm("func_0014d308");
void func_0014cf18(void) asm("func_0014cf18");
void func_0014cf88(void) asm("func_0014cf88");
void func_00102788(u32, u32, u32, void*) asm("func_00102788");
extern u32 D_0032b91c asm("D_0032b91c");
/*TARGET 0014d008*/
void u_tail0_0014d008(void) asm("_Z16u_tail0_0014d008v");
void u_tail0_0014d008(void) {
    func_0014cfc8();
    func_0014c908();
    sceGsSyncVCallback((void*)func_0014cf18);
    func_0014d308();
    func_00102788(D_0032b91c, 0, 0xc3500, (void*)func_0014cf88);
}
}  // namespace n0014d008

// 0014d060 (was src/anon/batch_w111.cpp)
namespace n0014d060 {
extern u8 D_00349e20 asm("D_00349e20");
extern u32 D_00349e1c asm("D_00349e1c");
extern u32 D_00349e08 asm("D_00349e08");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e0c asm("D_00349e0c");
extern f32 D_00349e14 asm("D_00349e14");
extern f32 D_00349e18 asm("D_00349e18");
void func_0014d478(void) asm("func_0014d478");
void u_tail0_0014d060(void) asm("_Z16u_tail0_0014d060v");
/*TARGET 0014d060*/
// Per-frame timing step: catch up on missed ticks, then derive the clamped frame delta and its rate.
void u_tail0_0014d060(void) asm("_Z16u_tail0_0014d060v");
// Per-frame timing step: catch up on missed ticks, then derive the clamped frame delta and its rate.
void u_tail0_0014d060(void)
{
    func_0014d478();
    if (!D_00349e20) {
        D_00349e10 = 2.0f;
        if (D_00349e08 < D_00349e1c + 1)
            for (u32 i = 0; i < D_00349e1c; i++) func_0014d478();
    } else {
        D_00349e10 = D_00349e08;
        if (D_00349e08 < D_00349e1c + 1)
            for (u32 i = 0; i < D_00349e1c; i++) {
                func_0014d478();
                D_00349e10 = D_00349e08;
            }
    }
    D_00349e14 = D_00349e10;
    D_00349e10 = D_00349e10 * D_00349e0c;
    if (6.0f < D_00349e10) D_00349e10 = 6.0f;
    if (6.0f < D_00349e14) D_00349e14 = 6.0f;
    D_00349e08 = 0;
    D_00349e18 = 1.0f / D_00349e10;
}
}  // namespace n0014d060

// 0014d240 (was src/anon/batch_w1669.cpp)
namespace n0014d240 {
struct W1669Tri { u32 a, b; f32 c; };
extern W1669Tri D_004574b8 asm("D_004574b8");
// 0x001cbf20: definition moved into src/anon/unit_001ca8e0.cpp
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0014d240jjjj");
/*TARGET 0014d240*/
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0014d240jjjj");
void wtarget_0014d240(u32 a0, u32 a1, u32, u32) {
    if (a1 == 0xffff && a0 == 1) { D_004574b8.a = 0; D_004574b8.b = 0; D_004574b8.c = 1.0f; }
}
}  // namespace n0014d240

// 0014d278 (was src/anon/tiny_wrappers_more.cpp)
namespace n0014d278 {
u32 func_0014d240(u32, u32, u32, u32) asm("_Z13func_0014d240jjjj");
/*TARGET 0014d278*/
// 0x001445e8: definition moved into src/anon/unit_00144450.cpp

// 00149428: moved to src/harata/libdk/mapfile.cpp

// 00149bd0: moved to src/harata/libdk/mapfile.cpp

u32 func_0014d278(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0014d278jjjj");
// 0x001445e8: definition moved into src/anon/unit_00144450.cpp

// 00149428: moved to src/harata/libdk/mapfile.cpp

// 00149bd0: moved to src/harata/libdk/mapfile.cpp

u32 func_0014d278(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0014d240(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n0014d278

