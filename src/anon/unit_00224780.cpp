// Linked unit 0x00224780-0x00228490.
#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../sasa/event.hpp"
#include "../tozawa/menu_sound.hpp"

// 00224780 (was src/anon/batch_w32.cpp)
namespace n00224780 {
extern u32 D_0035dad0 asm("D_0035dad0");
extern u8 D_0035dade asm("D_0035dade");
extern u32 D_0035dad4 asm("D_0035dad4");
extern u32 D_0035dac4 asm("D_0035dac4");
extern u8 D_0035dadd asm("D_0035dadd");
extern u32 D_0035dacc asm("D_0035dacc");
extern u32 D_0035dac8 asm("D_0035dac8");
extern u32 D_0035dad8 asm("D_0035dad8");
void func_00224940(void) asm("func_00224940");
void u_call4_00224780(u32, u32, u32, u32) asm("_Z16u_call4_00224780jjjj");
/*TARGET 00224780*/
void u_call4_00224780(u32 a0, u32, u32, u32) asm("_Z16u_call4_00224780jjjj");
void u_call4_00224780(u32 a0, u32, u32, u32) {
    D_0035dad0 = a0;
    D_0035dade = 0;
    D_0035dad4 = 5;
    D_0035dadd = 0;
    D_0035dac4 = 0;
    D_0035dac8 = 0;
    D_0035dacc = 0;
    D_0035dad8 = 0;
    func_00224940();
}
}  // namespace n00224780

// 002247d8 (was src/anon/tiny.cpp)
namespace n002247d8 {
/*TARGET 002247d8*/
// 0x001e70a0: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_002247d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002247d8jjjj");
// 0x001e70a0: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_002247d8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36dad0
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-9520)));
}
}  // namespace n002247d8

// 002247e8 (was src/anon/batch_w22.cpp)
namespace n002247e8 {
// 0x001e0f90: definition moved into src/anon/unit_001e0cb8.cpp

// --- 002247e8
extern s32 D_0035de20 asm("D_0035de20");
extern s32 D_0035dad8 asm("D_0035dad8");
extern s32 D_0035dad4 asm("D_0035dad4");
/*TARGET 002247e8*/
void func_002247e8(void) asm("func_002247e8");
void func_002247e8(void) {
    if (D_0035dad8 != D_0035de20) {
        s32 n = D_0035dad4;
        if (n < 5) {
            D_0035dad4 = n + 1;
            D_0035dad8 = D_0035de20;
        }
    }
}
}  // namespace n002247e8

// 00224828 (was src/anon/tiny_auto80_queue.cpp)
namespace n00224828 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 00224828*/
void func_00224828() asm("_Z13func_00224828v");
void func_00224828() {
    u32 v = *(u32*)((u8*)&D_00360000 - 8672u);
    u32 cur = *(u32*)((u8*)&D_00360000 - 9512u);
    if (cur != v) {
        s32 n = *(s32*)((u8*)&D_00360000 - 9516u);
        if (n > 0) {
            *(s32*)((u8*)&D_00360000 - 9516u) = n - 1;
            *(u32*)((u8*)&D_00360000 - 9512u) = v;
        }
    }
}
}  // namespace n00224828

// 00224860 (was src/anon/tiny.cpp)
namespace n00224860 {
/*TARGET 00224860*/
u32 func_00224860(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224860jjjj");
u32 func_00224860(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36daf4
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-9516)));
}
}  // namespace n00224860

// 00224870 (was src/anon/tiny.cpp)
namespace n00224870 {
extern u32 D_0035dacc asm("D_0035dacc");
/*TARGET 00224870*/
// 0x001e6cf8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00224870(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224870jjjj");
// 0x001e6cf8: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00224870(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0035dacc;
}
}  // namespace n00224870

// 00224880 (was src/anon/tiny.cpp)
namespace n00224880 {
extern u32 D_0035dac8 asm("D_0035dac8");
/*TARGET 00224880*/
u32 func_00224880(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224880jjjj");
u32 func_00224880(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0035dac8;
}
}  // namespace n00224880

// 00224890 (was src/anon/tiny_auto80_queue.cpp)
namespace n00224890 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 00224890*/
s32 func_00224890() asm("_Z13func_00224890v");
s32 func_00224890() {
    s32 a = *(s32*)((u8*)&D_00360000 - 9524u);
    s32 b = *(s32*)((u8*)&D_00360000 - 9528u);
    if (b < a) {
        *(s32*)((u8*)&D_00360000 - 9528u) = a;
        return 1;
    }
    return 0;
}
}  // namespace n00224890

// 002248c0 (was src/anon/tiny.cpp)
namespace n002248c0 {
/*TARGET 002248c0*/
void func_002248c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002248c0jjjj");
void func_002248c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-9524)) = (u32)0;
}
}  // namespace n002248c0

// 002248d0 (was src/anon/tiny_wrappers_more80_relaxed.cpp)
namespace n002248d0 {
u32 func_00224890(u32, u32, u32, u32) asm("_Z13func_00224890jjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 002248d0*/
// 001ac7c8: moved to src/anon/unit_001abb28.cpp

u32 func_002248d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002248d0jjjj");
// 001ac7c8: moved to src/anon/unit_001abb28.cpp

u32 func_002248d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)((u32)&D_00360000) - 9524u) = (u32)(((u32)(((u32)(*(u32*)((u32)((u32)&D_00360000) - 9524u)))) + 1u));
    return func_00224890(a0, a1, a2, a3);
}
}  // namespace n002248d0

// 002248f8 (was src/anon/tiny_more2.cpp)
namespace n002248f8 {
extern u32 D_0035dac4 asm("D_0035dac4");
/*TARGET 002248f8*/
void func_002248f8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002248f8jjjj");
void func_002248f8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 v=D_0035dac4; v=v+a0; D_0035dac4=v; }
}  // namespace n002248f8

// 00224910 (was src/anon/tiny.cpp)
namespace n00224910 {
/*TARGET 00224910*/
u32 func_00224910(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224910jjjj");
u32 func_00224910(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36dac4
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-9532)));
}
}  // namespace n00224910

// 00224920 (was src/anon/tiny.cpp)
namespace n00224920 {
/*TARGET 00224920*/
void func_00224920(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224920jjjj");
void func_00224920(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-9532)) = (u32)a0;
}
}  // namespace n00224920

// 00224930 (was src/anon/tiny.cpp)
namespace n00224930 {
extern u32 D_0035dac4 asm("D_0035dac4");
/*TARGET 00224930*/
u32 func_00224930(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224930jjjj");
u32 func_00224930(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0035dac4;
}
}  // namespace n00224930

// 00224940 (was src/anon/tiny.cpp)
namespace n00224940 {
/*TARGET 00224940*/
void func_00224940(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224940jjjj");
void func_00224940(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-9508)) = (u8)0;
}
}  // namespace n00224940

// 00224950 (was src/anon/batch_w3.cpp)
namespace n00224950 {
extern u8 D_0035dadc asm("D_0035dadc");
extern u32 D_0035dae0 asm("D_0035dae0");
/*TARGET 00224950*/
void func_00224950(u32 a) asm("func_00224950");
void func_00224950(u32 a) {
    D_0035dadc = 1;
    D_0035dae0 = a;
}
}  // namespace n00224950

// 00224968 (was src/anon/tiny.cpp)
namespace n00224968 {
/*TARGET 00224968*/
u32 func_00224968(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224968jjjj");
u32 func_00224968(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-9508)));
}
}  // namespace n00224968

// 00224978 (was src/anon/tiny.cpp)
namespace n00224978 {
/*TARGET 00224978*/
u32 func_00224978(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224978jjjj");
u32 func_00224978(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-9504)));
}
}  // namespace n00224978

// 00224988 (was src/anon/tiny.cpp)
namespace n00224988 {
/*TARGET 00224988*/
u32 func_00224988(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224988jjjj");
u32 func_00224988(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_byte_36dad5
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-9507)));
}
}  // namespace n00224988

// 00224998 (was src/anon/tiny.cpp)
namespace n00224998 {
extern u32 D_0035dadd asm("D_0035dadd");
/*TARGET 00224998*/
// 0x001e7008: definition moved into src/anon/unit_001e0cb8.cpp

void func_00224998(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224998jjjj");
// 0x001e7008: definition moved into src/anon/unit_001e0cb8.cpp

void func_00224998(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035dadd = (u8)v;
}
}  // namespace n00224998

// 002249a8 (was src/anon/tiny.cpp)
namespace n002249a8 {
/*TARGET 002249a8*/
void func_002249a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002249a8jjjj");
void func_002249a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-9536)) = (u32)a0;
}
}  // namespace n002249a8

// 002249b8 (was src/anon/tiny.cpp)
namespace n002249b8 {
/*TARGET 002249b8*/
u32 func_002249b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002249b8jjjj");
u32 func_002249b8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_36dac0
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-9536)));
}
}  // namespace n002249b8

// 002249c8 (was src/anon/tiny.cpp)
namespace n002249c8 {
extern u32 D_0035dade asm("D_0035dade");
/*TARGET 002249c8*/
void func_002249c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002249c8jjjj");
void func_002249c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035dade = (u8)v;
}
}  // namespace n002249c8

// 002249d8 (was src/anon/tiny.cpp)
namespace n002249d8 {
/*TARGET 002249d8*/
void func_002249d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002249d8jjjj");
void func_002249d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-9506)) = (u8)0;
}
}  // namespace n002249d8

// 002249e8 (was src/anon/tiny.cpp)
namespace n002249e8 {
/*TARGET 002249e8*/
u32 func_002249e8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002249e8jjjj");
u32 func_002249e8(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_byte_36dad6
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-9506)));
}
}  // namespace n002249e8

// 002249f8 (was src/anon/batch_w1821.cpp)
namespace n002249f8 {
void func_001c1130(s32) asm("func_001c1130");
void func_001c11a8(s32) asm("func_001c11a8");
s32 func_00224860() asm("func_00224860");
s32 func_00224910() asm("func_00224910");
u32 func_002249b8() asm("func_002249b8");
void func_002249c8() asm("func_002249c8");
void func_002249d8() asm("func_002249d8");
s32 func_002249e8() asm("func_002249e8");
s32 func_00225260() asm("func_00225260");
void func_00228518() asm("func_00228518");
void func_00228590() asm("func_00228590");
extern s32 D_0035dac8 asm("D_0035dac8");
/*TARGET 002249f8*/
void func_002249f8(void) asm("func_002249f8");
void func_002249f8(void) {
    func_001c11a8(8);
    func_001c1130(0xC);
    func_002249c8();
    if (func_00225260() == 0) {
        switch (func_002249b8()) {
        case 1:
            if (func_00224860() == 5) func_002249d8();
            break;
        case 2:
            if (D_0035dac8 < 5) func_002249d8();
            break;
        case 3:
            if (func_00224910() < 6000) func_002249d8();
            break;
        case 4:
            if (func_00224910() < 8000) func_002249d8();
            break;
        case 5:
            if (func_00224910() < 30000) func_002249d8();
            break;
        default:
            if (func_00224910() == 0) func_002249d8();
            break;
        }
    }
    if (func_002249e8() == 1) {
        func_00228518();
        return;
    }
    func_00228590();
}
}  // namespace n002249f8

// 00224b08 (was src/anon/auto80_199_queue.cpp)
namespace n00224b08 {
/*TARGET 00224b08*/
void func_00224b08(u32 a0) asm("_Z13func_00224b08j");
void func_00224b08(u32 a0) {
    u32 s0 = a0;
    if (func_00224e90(s0) == 0) {
        return;
    }

    func_00224998();
    sa__MUSICAL_2D__leave();  // to_1397d8_arg11
    func_00102448(s0, 1);
    func_0022b948();
}
}  // namespace n00224b08

// 00224b60 (was src/anon/tiny_auto80.cpp)
namespace n00224b60 {
u32 func_00224780(u32, u32, u32, u32) asm("_Z13func_00224780jjjj");
u32 sa__MUSICAL_2D__read() asm("_Z20sa__MUSICAL_2D__readv");
/*TARGET 00224b60*/
// 0x001e2a50: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00224b60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224b60jjjj");
// 0x001e2a50: definition moved into src/anon/unit_001e0cb8.cpp

u32 func_00224b60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(-8667)) = (u8)r14;
    r4 = (u32)(s32)(*(s16*)((u32)r4 + (s32)(4)));
    r2 = func_00224780(r4, r5, r6, r7);
    return sa__MUSICAL_2D__read();
}
}  // namespace n00224b60

// 00224b88 (was src/anon/tiny_auto80_queue.cpp)
namespace n00224b88 {
// get_global_36dac0
extern "C" s32 func_002249e8(...) asm("func_002249e8");
// 0x0013f1e8: definition moved into src/anon/unit_0013ef70.cpp

extern "C" u32 func_001024a8(...) asm("func_001024a8");
// 0x0019ac30: definition moved into src/anon/unit_00199688.cpp

extern "C" u32 func_001991a8(...) asm("func_001991a8");
/*TARGET 00224b88*/
void func_00224b88(u32 a0) asm("_Z13func_00224b88j");
void func_00224b88(u32 a0) {
    u32 s0 = a0;
    s32 v = func_002249e8(a0);  // get_global_byte_36dad6
    if (v == 1) {
        func_001991a8(18, 0);
    } else {
        func_001991a8(99, 0);
    }
    func_001024a8(s0);
}
}  // namespace n00224b88

// 00224bd0 (was src/anon/tiny_auto80_queue.cpp)
namespace n00224bd0 {
extern u8  D_00220000 asm("D_00220000");
u32 func_00224988(...) asm("func_00224988");
u32 func_00224e90(...) asm("func_00224e90");
// 001a7530: static initialiser, now made by gcc in src/anon/unit_001a6a10.cpp

extern "C" u32 func_00102c18(...) asm("func_00102c18");
/*TARGET 00224bd0*/
void func_00224bd0() asm("_Z13func_00224bd0v");
void func_00224bd0() {
    if (func_00224e90() == 0) {
        return;
    }
    if (func_00224988() != 0) {  // get_global_byte_36dad5
        func_00102c18(1, 14990, (u32)((u8*)&D_00220000 + 19336u));
    }
}
}  // namespace n00224bd0

// 00224c20 (was src/anon/batch_w85.cpp)
namespace n00224c20 {
char* func_00227120(void) asm("func_00227120");
// get_data_1dbd8f8
s32 strncmp(const char*, const char*, s32) asm("strncmp");
extern const char R_00370cd8[16] asm("D_00370cd8") __attribute__((aligned(4))) = "lm_event_901";
extern const char R_00370ce8[16] asm("D_00370ce8") __attribute__((aligned(4))) = "lm_event_902";
extern const char R_00370cf8[16] asm("D_00370cf8") __attribute__((aligned(4))) = "lm_event_903";
extern const char R_00370d08[16] asm("D_00370d08") __attribute__((aligned(4))) = "lm_event_904";
extern const char R_00370d18[16] asm("D_00370d18") __attribute__((aligned(4))) = "lm_event_905";
/*TARGET 00224c20*/
s32 func_00224c20(void) asm("func_00224c20");
s32 func_00224c20(void) {
    if (!strncmp(func_00227120(), R_00370cd8, 12)) return 1;
    if (!strncmp(func_00227120(), R_00370ce8, 12)) return 2;
    if (!strncmp(func_00227120(), R_00370cf8, 12)) return 3;
    if (!strncmp(func_00227120(), R_00370d08, 12)) return 4;
    if (!strncmp(func_00227120(), R_00370d18, 12)) return 5;
    return -1;
}
}  // namespace n00224c20

// 00224cf0 (was src/anon/batch_w1756.cpp)
namespace n00224cf0 {
u32 func_00224c20() asm("func_00224c20");
extern u32 D_0035db18 asm("D_0035db18");
/*TARGET 00224cf0*/
void func_00224cf0() asm("func_00224cf0");
void func_00224cf0()
{
    switch (func_00224c20()) {
    case 0:
        break;
    case 1:
    case 2:
        D_0035db18 = 0x700000;
        break;
    case 3:
    case 4:
    case 5:
        D_0035db18 = 0x600000;
        break;
    }
}
}  // namespace n00224cf0

// 00224d48 (was src/anon/batch_w1806.cpp)
namespace n00224d48 {
s32 func_00224e90(void) asm("func_00224e90");
void func_0014ce20(s32) asm("func_0014ce20");
void func_0022b898(void) asm("func_0022b898");
void func_0022b730(void) asm("func_0022b730");
void func_00225208(void) asm("func_00225208");
s32 func_00224c20(void) asm("func_00224c20");
void func_00229370(void) asm("func_00229370");
void func_00228f18(void) asm("func_00228f18");
void sa__MUSICAL_GAUGE3__init(void) asm("sa__MUSICAL_GAUGE3__init");
void func_002289f0(void) asm("func_002289f0");
void func_00228618(void) asm("func_00228618");
s32 func_002249a8(s32) asm("func_002249a8");
/*TARGET 00224d48*/
// The default call stores into r and returns through the shared return,
// so it stays a jal; the case calls are direct returns (sibcalls).
s32 func_00224d48(void) asm("func_00224d48");
// The default call stores into r and returns through the shared return,
// so it stays a jal; the case calls are direct returns (sibcalls).
s32 func_00224d48(void) {
    s32 v;
    s32 r = func_00224e90();
    if (r) {
        func_0014ce20(0);
        func_0022b898();
        func_0022b730();
        func_00225208();
        v = func_00224c20();
        switch (v) {
        case 1: func_00229370(); return func_002249a8(v);
        case 2: func_00228f18(); return func_002249a8(v);
        case 3: sa__MUSICAL_GAUGE3__init(); return func_002249a8(v);
        case 4: func_002289f0(); return func_002249a8(v);
        case 5: func_00228618(); return func_002249a8(v);
        default: r = func_002249a8(0); break;
        }
    }
    return r;
}
}  // namespace n00224d48

// 00224e28 (was src/anon/auto80_199_queue.cpp)
namespace n00224e28 {
/*TARGET 00224e28*/
void func_00224e28() asm("_Z13func_00224e28v");
void func_00224e28() {
    if (func_00224e90() == 0) {
        return;
    }

    if (func_00224988() == 0) {  // get_global_byte_36dad5
        sa__MUSICAL_2D__leave();  // to_1397d8_arg11
        dk__Obj2D__destroyLoopExec();
        func_0022b948();
    }

    func_0022b968();
    func_0022b7b0();
    func_0014ce20(1);
}
}  // namespace n00224e28

// 00224e90 (was src/anon/tiny.cpp)
namespace n00224e90 {
/*TARGET 00224e90*/
u32 func_00224e90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00224e90jjjj");
u32 func_00224e90(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-8667)));
}
}  // namespace n00224e90

// 00224ea0 (was src/anon/auto80_199_queue.cpp)
namespace n00224ea0 {
/*TARGET 00224ea0*/
void func_00224ea0(u32 a0) asm("_Z13func_00224ea0j");
void func_00224ea0(u32 a0) {
    u32 s0 = a0;
    if (sa__EVENT__checkStart(*(s16*)(a0 + 4)) != 0) {
        return;
    }

    s32 v = func_00224968() ? func_00224978() : *(s16*)(s0 + 6);
    func_00224940();
    func_00226f78(v);
}
}  // namespace n00224ea0

// 00224f08 (was src/anon/tiny_auto80_queue.cpp)
namespace n00224f08 {
u32 func_00105110(...) asm("func_00105110");
/*TARGET 00224f08*/
void func_00224f08(u8* a0) asm("_Z13func_00224f08Ph");
void func_00224f08(u8* a0) {
    u32 v = *(u32*)(a0 + 4);
    if (v != 0) {
        func_00105110(v);
    }
}
}  // namespace n00224f08

// 00224f38 (was src/anon/batch_w220.cpp)
namespace n00224f38 {
extern u8 D_0022b108[] asm("D_0022b108");
void* func_00102c18(int, void*, void*) asm("func_00102c18");
void* func_0022a368(void*) asm("func_0022a368");
void func_00224f08() asm("func_00224f08");
/*TARGET 00224f38*/
void func_00224f38(void* a0, u32* a1, u32* a2, void* a3) asm("func_00224f38");
void func_00224f38(void* a0, u32* a1, u32* a2, void* a3) {
  u32* r = (u32*)func_00102c18(1, a0, D_0022b108);
  *a1 = (u32)r;
  r[12] = (u32)func_00224f08;
  *a2 = (u32)func_0022a368(a3);
}
}  // namespace n00224f38

// 00224fa0 (was src/anon/batch_w2350_nsa.cpp)
namespace n00224fa0 {
struct Obj_f;
struct VT_f { void* pad[8]; void (*f20)(Obj_f*, s32); };
struct Obj_f { VT_f* vt; };
struct Data_f { s32 type; s32 f4; s32 f8; s32 fc; s32 f10; s32 f14; s32 f18; s32 f1c; s32 f20; s32 f24; s32 f28; Obj_f* f2c; s32 f30; s32 f34; u8 b38; u8 pad39[3]; s32 f3c; };
struct Task_f { u8 pad0[4]; Data_f* data; u8 pad8[0x30 - 8]; void (*f30)(Task_f*); };
struct Arg_f { u8 pad0[4]; s16 f4; s16 type; s16 f8; s16 fa; s16 fc; s16 fe; s16 f10; s16 f12; s16 f14; };
Task_f* CreateTask_f(s32, s32, void (*)(Task_f*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* Alloc_f(u32) asm("_ZN4AREA5AllocEj");
Obj_f* ComboStart_f(s32) asm("_ZN2sa13MUSICAL_COMBO5startEi");
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
s32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
s32 func_002247d8(void) asm("func_002247d8");
void func_00224f38(s32, Task_f**, Obj_f**, s32) asm("func_00224f38");
void func_00224f08(Task_f*) asm("func_00224f08");
void sa__MUSICAL_COMBO__printTask(Task_f*) asm("sa__MUSICAL_COMBO__printTask");
/*TARGET 00224fa0*/
// Spawns a task for a grid cell: picks the task kind from p->type, then fills its data block
// with cell offsets (centre, up, left/right neighbours) relative to p->f4.
void func_00224fa0(Arg_f* p) asm("func_00224fa0");
// Spawns a task for a grid cell: picks the task kind from p->type, then fills its data block
// with cell offsets (centre, up, left/right neighbours) relative to p->f4.
void func_00224fa0(Arg_f* p)
{
    if (sa__EVENT__checkStart(p->f4) != 0)
        return;
    s32 id = sa__EVENT__getEventPriority() + 1;
    s32 w = func_002247d8();
    Task_f* t = 0;
    Obj_f* b = 0;
    switch (p->type) {
    case 2: func_00224f38(id, &t, &b, 0); break;
    case 0: func_00224f38(id, &t, &b, 2); break;
    case 1: func_00224f38(id, &t, &b, 3); break;
    case 3: func_00224f38(id, &t, &b, 4); break;
    case 5: func_00224f38(id, &t, &b, 1); break;
    case 6: {
        t = CreateTask_f(1, id, sa__MUSICAL_COMBO__printTask);
        t->f30 = func_00224f08;
        s32 small = p->f8 < 4;
        b = ComboStart_f(small == 0);
        break;
    }
    }
    s32 x = p->f4 + p->fa;
    s32 c = p->fc;
    s32 m = x + p->f8 * w;
    s32 a = m - w;
    s32 e = m - c - 1;
    s32 f = m + c;
    Data_f* d = (Data_f*)Alloc_f(0x40);
    t->data = d;
    d->type = p->type;
    d->f4 = p->f8;
    d->f1c = 0;
    d->f20 = 0;
    d->f8 = x - p->f4;
    d->fc = a - p->f4;
    d->f10 = e - p->f4;
    d->f14 = m - p->f4;
    d->f18 = f - p->f4;
    d->f24 = p->f12;
    d->f28 = p->f14;
    d->f2c = b;
    d->f34 = p->f10;
    d->b38 = 0;
    d->f3c = 0;
    if (p->type == 1)
        d->f30 = -p->fe;
    else
        d->f30 = p->fe;
    b->vt->f20(b, d->f4);
}
}  // namespace n00224fa0

// 002251c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002251c8 {
u32 func_00242ea8(...) asm("func_00242ea8");
u32 func_002bc1e8(...) asm("func_002bc1e8");
/*TARGET 002251c8*/
void func_002251c8(u32 a0) asm("_Z13func_002251c8j");
void func_002251c8(u32 a0) {
    u32 s0 = a0;
    if (func_00242ea8(a0) == 0u) {
        func_002bc1e8(s0);
        return;
    }
}
}  // namespace n002251c8

// 00225208 (was src/anon/tiny_auto80_queue.cpp)
namespace n00225208 {
extern u8  D_00220000 asm("D_00220000");
// 001a7530: static initialiser, now made by gcc in src/anon/unit_001a6a10.cpp

extern "C" u32 func_00102c18(...) asm("func_00102c18");
u32 func_00242ea8(...) asm("func_00242ea8");
/*TARGET 00225208*/
void func_00225208() asm("_Z13func_00225208v");
void func_00225208() {
    if (func_00242ea8() != 0) {
        u32 a0 = 1;
        u32 a1 = 0x00017318;
        u32 a2 = (u32)((u8*)&D_00220000 + 21064u);
        func_00102c18(a0, a1, a2);
    }
}
}  // namespace n00225208

// 00225248 (was src/anon/tiny.cpp)
namespace n00225248 {
void func_001398d0(s32) asm("_Z13func_001398d0i");
/*TARGET 00225248*/
// 0x001ae690: definition moved into src/anon/unit_001ada38.cpp
void func_00225248(BD_VALUE* bd) asm("_Z13func_00225248P8BD_VALUE");
// 0x001ae690: definition moved into src/anon/unit_001ada38.cpp
void func_00225248(BD_VALUE* bd) { func_001398d0(11); }
}  // namespace n00225248

// 00225260 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00225260 {
u32 func_00242ea8(u32, u32, u32, u32) asm("_Z13func_00242ea8jjjj");
/*TARGET 00225260*/
u32 func_00225260(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225260jjjj");
u32 func_00225260(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call4_00242ea8)(u32, u32, u32, u32) = func_00242ea8;
    r2 = fp_call4_00242ea8(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00225260

// 00225280 (was src/anon/tiny.cpp)
namespace n00225280 {
extern u32 D_01dad910 asm("D_01dad910");
/*TARGET 00225280*/
void func_00225280(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225280jjjj");
void func_00225280(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a2;
    (void)a3;
    *(u32*)((u32)&D_01dad910 + ((u32)a0 << 2) + (0)) = a1;
}
}  // namespace n00225280

// 00225298 (was src/anon/batch_w4.cpp)
namespace n00225298 {
extern s32 D_01dad910[2] asm("D_01dad910");
/*TARGET 00225298*/
void func_00225298(void) asm("func_00225298");
void func_00225298(void) {
    D_01dad910[0] = -1;
    D_01dad910[1] = -1;
}
}  // namespace n00225298

// 002252b0 (was src/anon/batch_w42.cpp)
namespace n002252b0 {
// 0x001e65d0: definition moved into src/anon/unit_001e0cb8.cpp

// 002252b0
extern s32 D_01dad910[2] asm("D_01dad910");
s32 func_00225540(void) asm("func_00225540");
// get_global_byte_36de29
void func_00136b78(s32, s32) asm("func_00136b78");
/*TARGET 002252b0*/
// entry16_set_field8
void func_002252b0(void) asm("func_002252b0");
// entry16_set_field8
void func_002252b0(void)
{
    if (!func_00225540()) return;
    if (D_01dad910[0] != -1) func_00136b78(0, D_01dad910[0]);  // entry16_set_field8
    if (D_01dad910[1] != -1) func_00136b78(1, D_01dad910[1]);  // entry16_set_field8
}
}  // namespace n002252b0

// .rodata tables at 0x370d78/0x370d88 (read by 0x225328, 0x2253a0)
extern "C" const u32 D_00370d74 = 0;
extern const u32 R_00370d78[4] asm("D_00370d78") __attribute__((aligned(4))) = { 0x14, 0x28, 0x50, 0x1 };
extern const u32 R_00370d88[4] asm("D_00370d88") __attribute__((aligned(4))) = { 0x3000, 0x1800, 0x0, 0x0 };

// 00225328 (was src/anon/batch_w43.cpp)
namespace n00225328 {
void func_00225530(void*) asm("func_00225530");
void func_00225280(u32, u32) asm("func_00225280");
extern u32 D_00370d88[] asm("D_00370d88");
/*TARGET 00225328*/
// 0x001e7cc0: definition moved into src/anon/unit_001e0cb8.cpp

void func_00225328(u8* p) asm("func_00225328");
// 0x001e7cc0: definition moved into src/anon/unit_001e0cb8.cpp

void func_00225328(u8* p) {
    if (*(u16*)(p + 6)) func_00225530(p);
    u16 t = *(u16*)(p + 8);
    if (t == 0) func_00225280(p[11], 12288);
    else if (t == 257) func_00225280(p[11], 6144);
    else func_00225280(p[11], D_00370d88[p[9]]);
}
}  // namespace n00225328

// 002253a0 (was src/anon/batch_w109.cpp)
namespace n002253a0 {
// ---- f2.cpp
s32 sa__EVENT__checkStart(u16) asm("sa__EVENT__checkStart");
void func_00225530(void) asm("func_00225530");
s32 func_002ba200(void) asm("func_002ba200");
void func_002259f0(void) asm("func_002259f0");
void func_00225a00(void) asm("func_00225a00");
// zero_global_byte_e
void func_00102448(s32, s32) asm("func_00102448");
void func_002ba220(u8, s32, s32, s32, s32, s32) asm("func_002ba220");
void func_002ba830(u8, s32, s32) asm("func_002ba830");
s32 func_002b7148(s32) asm("func_002b7148");
void func_00136b78(u8, s32) asm("func_00136b78");
// entry16_set_field8
extern s32 D_00370d88[] asm("D_00370d88");
extern s32 D_00370d78[] asm("D_00370d78");
/*TARGET 002253a0*/
void func_002253a0(u8* p, s32 arg) asm("func_002253a0");
void func_002253a0(u8* p, s32 arg) {
    if (sa__EVENT__checkStart(*(u16*)(p + 4))) return;
    if (*(u16*)(p + 6)) func_00225530();
    u16 m = *(u16*)(p + 8);
    if (m == 0) {
        while (func_002ba200()) {
            func_002259f0();
            func_00102448(arg, 0);
        }
        func_00225a00();  // zero_global_byte_e
        func_002ba220(p[11], 12288, 12288, 0, 0, 0);
        func_00136b78(p[11], 12288);  // entry16_set_field8
    } else if (m == 257) {
        while (func_002ba200()) {
            func_002259f0();
            func_00102448(arg, 0);
        }
        func_00225a00();  // zero_global_byte_e
        if (func_002b7148(0)) func_002ba830(p[11], 6144, 6144);
        else func_002ba220(p[11], 6144, 6144, 0, 0, 0);
        func_00136b78(p[11], 6144);  // entry16_set_field8
    } else {
        s32 a = D_00370d88[p[9]];
        func_002ba830(p[11], a, D_00370d78[p[10]]);
        func_00136b78(p[11], a);  // entry16_set_field8
    }
}
}  // namespace n002253a0

// 00225530 (was src/anon/tiny.cpp)
namespace n00225530 {
extern u32 D_0035de09 asm("D_0035de09");
/*TARGET 00225530*/
void func_00225530(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225530jjjj");
void func_00225530(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035de09 = (u8)v;
}
}  // namespace n00225530

// 00225540 (was src/anon/tiny.cpp)
namespace n00225540 {
/*TARGET 00225540*/
u32 func_00225540(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225540jjjj");
u32 func_00225540(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_global_byte_36de29
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-8695)));
}
}  // namespace n00225540

// 00225550 (was src/anon/batch_wcx2.cpp)
namespace n00225550 {
// 0x00265b88: definition moved into src/anon/unit_00265580.cpp

// ---- 00225550
s32 func_00224e90() asm("func_00224e90");
u32 func_001050c8() asm("func_001050c8");
u32* func_001063c0_5550(u32, u32) asm("func_001063c0");
u32 func_00170b30_5550(u32) asm("func_00170b30");
void func_00225e70(u32*, u32, u32) asm("func_00225e70");
union UP_00225550 { u32* p; u32 i; };
extern u32 D_0035db18_5550 asm("D_0035db18");
extern UP_00225550 D_0035dae4 asm("D_0035dae4");
extern u32 D_0035dae8 asm("D_0035dae8");
/*TARGET 00225550*/
void func_00225550() asm("func_00225550");
void func_00225550() {
    if (func_00224e90()) return;
    if (D_0035db18_5550 != 0x400000) return;
    if (D_0035dae4.p) return;
    u32* o = func_001063c0_5550(12, func_001050c8());
    o[0] = 0;
    o[1] = 0;
    o[2] = 0;
    D_0035dae4.p = o;
    D_0035dae8 = func_00170b30_5550(0x200000);
    func_00225e70(D_0035dae4.p, D_0035dae8, 0x200000);
}
}  // namespace n00225550

// 002255f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002255f0 {
extern u8  D_00360000 asm("D_00360000");
u32 func_00170c00(...) asm("func_00170c00");
u32 func_00106420(...) asm("func_00106420");
/*TARGET 002255f0*/
void func_002255f0() asm("_Z13func_002255f0v");
void func_002255f0() {
    if (*(u32*)((u8*)&D_00360000 - 9500u) != 0) {
        func_00170c00(*(u32*)((u8*)&D_00360000 - 9496u));
        *(u32*)((u8*)&D_00360000 - 9496u) = 0;
        func_00106420(*(u32*)((u8*)&D_00360000 - 9500u));
        *(u32*)((u8*)&D_00360000 - 9500u) = 0;
    }
}
}  // namespace n002255f0

// 00225640 (was src/anon/batch_w35.cpp)
namespace n00225640 {
extern u32 D_0035dae4 asm("D_0035dae4");
u32 func_00227818(u32) asm("func_00227818");
u32 func_00225eb8(u32, u32, u32) asm("func_00225eb8");
u32 func_00227858(u32, u32, u32) asm("func_00227858");
/*TARGET 00225640*/
u32 func_00225640(u32 a, u32 b, u32 c) asm("func_00225640");
u32 func_00225640(u32 a, u32 b, u32 c) {
    return func_00227858(func_00225eb8(D_0035dae4, func_00227818(a), c), b, c);
}
}  // namespace n00225640

// 00225690 (was src/anon/batch_w17.cpp)
namespace n00225690 {
// 0x001e6648: definition moved into src/anon/unit_001e0cb8.cpp

extern u32 D_0035dae4 asm("D_0035dae4");
void func_00225fa0(u32, u32) asm("func_00225fa0");
void func_00227930(void*) asm("func_00227930");
/*TARGET 00225690*/
void func_00225690(u8* p) asm("func_00225690");
void func_00225690(u8* p) {
    func_00225fa0(D_0035dae4, *(u32*)(p + 24));
    func_00227930(p);
}
}  // namespace n00225690

// 002256c8 (was src/anon/batch_w46.cpp)
namespace n002256c8 {
// ---- 002256c8
s32 func_00224e90(u8*, u32) asm("func_00224e90");
u32 func_00227870(u32, u8*, u32) asm("func_00227870");
u32 func_00225640(u32, u8*, u32) asm("func_00225640");
extern u32 D_0035db18 asm("D_0035db18");
/*TARGET 002256c8*/
void func_002256c8(u8* p, u32 b) asm("func_002256c8");
void func_002256c8(u8* p, u32 b) {
    if (func_00224e90(p, b) || D_0035db18 != 0x400000) *(u32*)(p + 20) = func_00227870(b, p, 0);
    else *(u32*)(p + 20) = func_00225640(b, p, 0);
}
}  // namespace n002256c8

// 00225738: gap (unwritten before), callback passed by 0x225898
namespace n00225738 {
extern u32 D_0035db18 asm("D_0035db18");
u32 isMusical_(void) asm("_ZN2sa5EVENT9isMusicalEv");
void func_00225690(void*) asm("func_00225690");
void func_002278e0(void*) asm("func_002278e0");
void func_00225738(void* p) asm("func_00225738");
void func_00225738(void* p) {
    if (isMusical_() != 0 || D_0035db18 != 0x400000) {
        func_002278e0(p);
        return;
    }
    func_00225690(p);
}
}  // namespace n00225738

// 00225788 (was src/anon/batch_w92.cpp)
namespace n00225788 {
union K225 { s32 i; s16 h; };
struct R225 { K225 kind; u32 pad[4]; u32 f20; u32 pad2[6]; char name[16]; };
struct S225 { u32 f0; u16 f4; s16 h6; };
void func_00225550(S225*) asm("func_00225550");
void func_00136cc8(void*, s16) asm("func_00136cc8");
R225* func_00227a28(void) asm("func_00227a28");
u32 func_002bd260(s16) asm("func_002bd260");
u32 func_002bd2f0(u32, u32*) asm("func_002bd2f0");
char* func_002ff2e8(char*, u32) asm("func_002ff2e8");
void func_002256c8(R225*, u32) asm("func_002256c8");
void YS__FILE__ReadBack(u32, u32, void (*)(void), R225*) asm("YS__FILE__ReadBack");
void func_00226030(void) asm("func_00226030");
s32 func_001688b8(void) asm("func_001688b8");
void func_00102448(void*, s32) asm("func_00102448");
static inline void setup225(R225* r, u32 o) {
    func_002ff2e8(r->name, o);
    func_002256c8(r, o);
    YS__FILE__ReadBack(o, r->f20, func_00226030, r);
}
/*TARGET 00225788*/
void func_00225788(S225* s, void* x) asm("func_00225788");
void func_00225788(S225* s, void* x) {
    func_00225550(s);
    func_00136cc8(x, s->h6);
    R225* r = func_00227a28();
    r->kind.i = 6;
    setup225(r, func_002bd260(s->h6));
    while (func_001688b8()) func_00102448(x, 0);
    R225* r2 = func_00227a28();
    r2->kind.i = 5;
    u32 tmp = 0;
    setup225(r2, func_002bd2f0(*(u32*)((u8*)r + 20), &tmp));
}
}  // namespace n00225788

// 00225898 (was src/anon/batch_w94.cpp)
namespace n00225898 {
s32 sa__EVENT__checkStart(s32) asm("sa__EVENT__checkStart");
s32 func_002b7148(s32) asm("func_002b7148");
void func_002ba298(s32) asm("func_002ba298");
u32 func_002bd260(s16) asm("func_002bd260");
u8* func_00227a60(u32, s32) asm("func_00227a60");
u32 func_002bd2f0(u32, u32*) asm("func_002bd2f0");
void func_002bd230(u32, s16) asm("func_002bd230");
void func_00136b48(s32, s16) asm("func_00136b48");
// entry16_set_word0
void func_00136b60(s32, s16) asm("func_00136b60");
void func_00136b78(s32, s32) asm("func_00136b78");
// entry16_set_field8
void func_00225738(void) asm("func_00225738");
void func_002baf48(s32, s32, u32, u32, void (*)(void), u8*) asm("func_002baf48");
/*TARGET 00225898*/
void func_00225898(u8* p) asm("func_00225898");
void func_00225898(u8* p) {
    if (sa__EVENT__checkStart(*(u16*)(p + 4))) return;
    if (func_002b7148(1)) func_002ba298(1);
    u8* a = func_00227a60(func_002bd260(*(s16*)(p + 8)), 6);
    u32 id = 0;
    u32 q = func_002bd2f0(*(u32*)(a + 20), &id);
    func_002bd230(id, *(s16*)(p + 8));
    u8* b = func_00227a60(q, 5);
    s32 m = *(s16*)(p + 6);
    if (m == 2) {
        m = 0;
        func_00136b48(0, *(s16*)(p + 8));  // entry16_set_word0
        func_00136b48(1, *(s16*)(p + 8));  // entry16_set_word0
        func_00136b60(0, *(s16*)(p + 8));
        func_00136b60(1, *(s16*)(p + 8));
    } else {
        func_00136b48(m, *(s16*)(p + 8));  // entry16_set_word0
        func_00136b60(m, *(s16*)(p + 8));
    }
    func_00136b78(m, 0);  // entry16_set_field8
    func_002baf48(m, 2, *(u32*)(a + 20), *(u32*)(a + 28), func_00225738, a);
    func_002baf48(0, 1, *(u32*)(b + 20), *(u32*)(b + 28), func_00225738, b);
}
}  // namespace n00225898

// 002259f0 (was src/anon/tiny.cpp)
namespace n002259f0 {
extern u32 D_0035daec asm("D_0035daec");
/*TARGET 002259f0*/
void func_002259f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002259f0jjjj");
void func_002259f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035daec = (u8)v;
}
}  // namespace n002259f0

// 00225a00 (was src/anon/tiny.cpp)
namespace n00225a00 {
/*TARGET 00225a00*/
void func_00225a00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225a00jjjj");
void func_00225a00(u32 a0, u32 a1, u32 a2, u32 a3) {  // zero_global_byte_e
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-9492)) = (u8)0;
}
}  // namespace n00225a00

// 00225a10 (was src/anon/tiny.cpp)
namespace n00225a10 {
extern u32 D_0035daed asm("D_0035daed");
/*TARGET 00225a10*/
void sa__EVENT__waitMessageOn(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z24sa__EVENT__waitMessageOnjjjj");
void sa__EVENT__waitMessageOn(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0035daed = (u8)v;
}
}  // namespace n00225a10

// 00225a20 (was src/anon/tiny.cpp)
namespace n00225a20 {
/*TARGET 00225a20*/
void func_00225a20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225a20jjjj");
void func_00225a20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u8*)((u32)b + (-9491)) = (u8)0;
}
}  // namespace n00225a20

// 00225a30 (was src/anon/tiny_auto80_queue.cpp)
namespace n00225a30 {
u32 func_001688b8(...) asm("func_001688b8");
u32 func_00170c50(...) asm("func_00170c50");
/*TARGET 00225a30*/
u32 func_00225a30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00225a30jjjjjjjj");
u32 func_00225a30(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_001688b8)();
    r15 = (u32)((s32)0u + (1));
    if (r2 == 0u) {
        r2 = ((u32(*)())func_00170c50)();
        r15 = r2;
    }
    r2 = r15;
    return r2;
}
}  // namespace n00225a30

// 00225a68 (was src/anon/tiny_auto80_queue.cpp)
namespace n00225a68 {
extern u8  D_00360000 asm("D_00360000");
u32 func_00225a30(...) asm("func_00225a30");
/*TARGET 00225a68*/
s32 func_00225a68() asm("_Z13func_00225a68v");
s32 func_00225a68() {
    s32 ok = func_00225a30();
    if (ok == 0) {
        return 0;
    }
    s32 a = *(s32*)((u8*)&D_00360000 - 9488u);
    s32 b = *(s32*)((u8*)&D_00360000 - 8672u);
    u32 x = (u32)(b < a);
    return x < 1;
}
}  // namespace n00225a68

// 00225aa8 (was src/anon/batch_w27.cpp)
namespace n00225aa8 {
extern u8 D_0035daec asm("D_0035daec");
extern u8 D_0035daed asm("D_0035daed");
s32 func_00225a68(void) asm("func_00225a68");
/*TARGET 00225aa8*/
s32 func_00225aa8(void) asm("func_00225aa8");
s32 func_00225aa8(void) {
    s32 r = 0;
    if (D_0035daec || D_0035daed || func_00225a68()) r = 1;
    return r;
}
}  // namespace n00225aa8

// 00225b00 (was src/anon/batch_w30.cpp)
namespace n00225b00 {
extern u8 D_0035de54 asm("D_0035de54");
extern s32 D_0035de20 asm("D_0035de20");
extern s32 D_0035de5c asm("D_0035de5c");
/*TARGET 00225b00*/
u8 sa__EVENT__isJumpMode(s32 n) asm("sa__EVENT__isJumpMode");
u8 sa__EVENT__isJumpMode(s32 n) {  // flag_query_by_index
    if (n == -1) return D_0035de54;
    u8 r = 0;
    if (D_0035de54 || (n < D_0035de20 && D_0035de20 == D_0035de5c)) r = 1;
    return r;
}
}  // namespace n00225b00

// 00225b50 (was src/anon/tiny_auto80_queue.cpp)
namespace n00225b50 {
u32 func_00224e90(...) asm("func_00224e90");
u32 sa__EVENT__isJumpMode(...) asm("sa__EVENT__isJumpMode");
/*TARGET 00225b50*/
// flag_query_by_index

u32 func_00225b50(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00225b50jjjjjjjj");
// flag_query_by_index

u32 func_00225b50(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())sa__EVENT__isJumpMode)();
    r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_00224e90)();
        r15 = ((u32)0u < (u32)r2);
    }
    r2 = r15;
    return r2;
}
}  // namespace n00225b50

// 00225b88 (was src/anon/batch_w2387.cpp)
namespace n00225b88 {
// 0x001e0e50: definition moved into src/anon/unit_001e0cb8.cpp

s32 func_002ef7b8() asm("func_002ef7b8");
s32 func_0022bb38() asm("func_0022bb38");
void func_00226dc8() asm("func_00226dc8");
s32 func_00228378() asm("func_00228378");
u8* func_0014ac08() asm("func_0014ac08");
void dk__Vsync__initGameSpeed() asm("dk__Vsync__initGameSpeed");
s32 func_002bc7a8(s32) asm("func_002bc7a8");
extern s32 D_0035de20 asm("D_0035de20");
extern s32 D_0035de28 asm("D_0035de28");
extern s32 D_0035de2c asm("D_0035de2c");
extern u8 D_0035de56 asm("D_0035de56");
static inline s32 is4_w2387() { return *(s32*)(func_0014ac08() + 0xfc) == 4; }
/*TARGET 00225b88*/
void func_00225b88(void) asm("func_00225b88");
void func_00225b88(void) {
    if (func_002ef7b8()) {
        if (func_0022bb38()) func_00226dc8();
        return;
    }
    if (D_0035de28 != -1 && D_0035de20 >= D_0035de28) {
        func_00226dc8();
        return;
    }
    s32 lim = D_0035de28 - 40;
    if (lim <= 0) lim = 0;
    if (!func_00228378() && D_0035de20 >= lim && D_0035de28 != -1 && is4_w2387()) {
        dk__Vsync__initGameSpeed();
    }
    if (D_0035de20 >= lim && D_0035de28 != -1 && D_0035de56 == 1 && D_0035de2c == 0
        && !func_002bc7a8(3) && is4_w2387()) {
        func_00226dc8();
    }
}
}  // namespace n00225b88

// 00225cd8 (was src/anon/auto80_199_queue.cpp)
namespace n00225cd8 {
/*TARGET 00225cd8*/
void func_00225cd8() asm("_Z13func_00225cd8v");
void func_00225cd8() {
    if (*(u8*)((u32)&D_00360000 - 8696) != 1) {
        return;
    }

    func_002ba620();
    u32 v0 = func_0014ac08();
    ((dk::Fade*)v0)->fadeOut(0, false);
    func_002252b0();
    func_00226dc8();
}
}  // namespace n00225cd8

// 00225d30 (was src/anon/batch_w1579_g.cpp)
namespace n00225d30 {
void func_00225b88(void) asm("func_00225b88");
void func_00225cd8(void) asm("func_00225cd8");
s32 func_00225aa8(void) asm("func_00225aa8");
s32 sa__EVENT__isJumpMode(s32) asm("sa__EVENT__isJumpMode");
s32 func_002263f0(s32*, void*) asm("func_002263f0");
s32 func_002ef7b8(void) asm("func_002ef7b8");
s32 func_002ef7a0(s32, s32) asm("func_002ef7a0");
extern s32 D_0035de20 asm("D_0035de20");
extern f32 D_0035de1c asm("D_0035de1c");
extern s32 D_0035de5c asm("D_0035de5c");
extern u8 D_0035de54 asm("D_0035de54");
extern char D_0035daf0[] asm("D_0035daf0");
extern f32 D_00349e10 asm("D_00349e10");
/*TARGET 00225d30*/
void func_00225d30(void) asm("func_00225d30");
void func_00225d30(void) {
    func_00225b88();
    func_00225cd8();
    if (func_00225aa8() == 0) {
        if (sa__EVENT__isJumpMode(-1) != 0) {
            if (func_002263f0(&D_0035de20, D_0035daf0) != 0) {
                D_0035de1c = (f32)D_0035de20 * 2.0f;
            } else {
                D_0035de54 = 0;
                D_0035de1c = (f32)D_0035de5c * 2.0f;
            }
        } else {
            D_0035de1c = D_0035de1c + D_00349e10;
        }
    }
    if (func_002ef7b8() != 0) {
        D_0035de20 = func_002ef7a0(7, 0);
    } else {
        D_0035de20 = (s32)(D_0035de1c * 0.5f);
    }
}
}  // namespace n00225d30

// 00225e28 (was src/anon/tiny_wrappers_imp.cpp)
namespace n00225e28 {
u32 func_001d5a38(u32, u32, u32, u32) asm("_Z13func_001d5a38jjjj");
/*TARGET 00225e28*/
// 0x001eb000: definition moved into src/anon/unit_001e8ac8.cpp

u32 func_00225e28(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225e28jjjj");
// 0x001eb000: definition moved into src/anon/unit_001e8ac8.cpp

u32 func_00225e28(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)((s32)0u + (1));
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(-8696)) = (u8)r14;
    return func_001d5a38(r4, r5, r6, r7);
}
}  // namespace n00225e28

// 00225e48 (was src/anon/tiny.cpp)
namespace n00225e48 {
/*TARGET 00225e48*/
u32 func_00225e48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00225e48jjjj");
u32 func_00225e48(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u8*)((u32)b + (-8696)));
}
}  // namespace n00225e48

// 00225e58-00225e70: gap getters (unwritten before)
namespace n00225e58 {
u32 func_00225e58(u32* p) asm("func_00225e58");
u32 func_00225e58(u32* p) { return p[0]; }
u32 func_00225e60(u32* p) asm("func_00225e60");
u32 func_00225e60(u32* p) { return p[1]; }
u32 func_00225e68(u32* p) asm("func_00225e68");
u32 func_00225e68(u32* p) { return p[2]; }
}  // namespace n00225e58

// 00225e70 (was src/anon/tiny_auto80_solver.cpp)
namespace n00225e70 {
/*TARGET 00225e70*/
void func_00225e70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00225e70jjjjjjjj");
void func_00225e70(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 mask = (u32)-64;
    *(u32*)(a0 + 4) = a1;
    u32 start = (a1 + 63) & mask;
    *(u32*)a0 = a2;
    *(u32*)(a0 + 8) = start;
    *(u32*)start = 0;
    *(u32*)(*(u32*)(a0 + 8) + 4) = 0;
    *(u8*)(*(u32*)(a0 + 8) + 8) = 0;
    u32 end = (*(u32*)(a0 + 4) + a2) & mask;
    *(u32*)(*(u32*)(a0 + 8) + 12) = end - *(u32*)(a0 + 8);
}
}  // namespace n00225e70

// 00225eb8 (was src/anon/batch_w85.cpp)
namespace n00225eb8 {
struct Blk225 { Blk225* next; Blk225* prev; u8 used; u32 size; u8 pad[48]; };
struct Heap225 { u8 pad[8]; Blk225* head; };
/*TARGET 00225eb8*/
// first-fit (mode 1: last fit, carved from the top) block allocator
void* func_00225eb8(Heap225* h, u32 size, s32 mode) asm("func_00225eb8");
// first-fit (mode 1: last fit, carved from the top) block allocator
void* func_00225eb8(Heap225* h, u32 size, s32 mode) {
    Blk225* b;
    Blk225* best = 0;
    Blk225* nb;
    Blk225* nx;
    u32 rem;
    size += 63;
    size &= ~63;
    size += 64;
    for (b = h->head; b; b = b->next) {
        if (b->used) continue;
        if (size < b->size) {
            best = b;
            if (mode != 1) break;
        }
    }
    if (!best) return 0;
    rem = best->size - size;
    if (rem >= 128) {
        if (mode != 1) {
            nb = (Blk225*)((u8*)best + size);
            nx = best->next;
            nb->size = rem;
            nb->next = nx;
            nb->prev = best;
            nb->used = 0;
            if (nx) nx->prev = nb;
            best->next = nb;
            best->used = 1;
            best->size = size;
        } else {
            Blk225* old = best;
            nx = best->next;
            best = (Blk225*)((u8*)best + rem);
            best->used = mode;
            best->size = size;
            best->next = nx;
            best->prev = old;
            if (nx) nx->prev = best;
            old->size = rem;
            old->used = 0;
            old->next = best;
        }
    } else {
        best->used = 1;
    }
    return best + 1;
}
}  // namespace n00225eb8

// 00225fa0 (was src/anon/batch_w1552.cpp)
namespace n00225fa0 {
// 00198040: moved to src/anon/unit_00197fe0.cpp

/* heap block free + coalesce with free neighbours */
struct Blk_225fa0 { Blk_225fa0* next; Blk_225fa0* prev; u8 used; u8 pad[3]; s32 size; };
/*TARGET 00225fa0*/
void func_00225fa0(void* a0, void* p) asm("func_00225fa0");
void func_00225fa0(void* a0, void* p) {
    Blk_225fa0* b = (Blk_225fa0*)((u8*)p - 0x40);
    b->used = 0;
    Blk_225fa0* lo = b;
    while (lo->prev && !lo->prev->used) lo = lo->prev;
    Blk_225fa0* hi = b;
    while (hi->next && !hi->next->used) hi = hi->next;
    Blk_225fa0* n = hi->next;
    if (n) n->prev = lo;
    lo->next = n;
    lo->size = (u8*)hi + hi->size - (u8*)lo;
}
}  // namespace n00225fa0

// 00226030 (was src/anon/tiny_auto80_queue.cpp)
namespace n00226030 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 00226030*/
void func_00226030(u32 a0, u32 a1, u8* a2) asm("_Z13func_00226030jjPh");
void func_00226030(u32 a0, u32 a1, u8* a2) {
    (void)a0;
    (void)a1;
    if (*(u32*)((u8*)&D_00360000 - 8976u) != 0) {
        *(u32*)(a2 + 4) = 3;
    }
}
}  // namespace n00226030

// 00226050 (was src/anon/batch_w11.cpp)
namespace n00226050 {
extern u32 D_0035dd08[64] asm("D_0035dd08");
/*TARGET 00226050*/
void func_00226050(u32 v) asm("func_00226050");
void func_00226050(u32 v) {
    s32 i;
    for (i = 0; i < 64; i++) {
        if (D_0035dd08[i] == 0) break;
    }
    D_0035dd08[i] = v;
}
}  // namespace n00226050

// 00226090 (was src/anon/batch_w1966.cpp)
namespace n00226090 {
struct W1966Hdr {
    s16 f0, f2;
    s16 count;
    s16 start;
    s16 end;
    s16 fa;
};
struct W1966Cmd {
    u16 op;
    s16 size;
    s16 a4, a6, a8;
};
struct W1966CmdU {
    u16 op;
    u16 size;
    s16 a4, a6, a8;
};
extern s32 D_0035daf0 asm("D_0035daf0");
extern u32 D_0035dd04 asm("D_0035dd04");
extern W1966Hdr* D_0035dd08[64] asm("D_0035dd08");
extern s32 D_0035de20 asm("D_0035de20");
extern s32 D_0035de28 asm("D_0035de28");
extern u32 D_0035de60 asm("D_0035de60");
void func_00170888(s32) asm("func_00170888");
void sa__EVENT__readNextMapFile(void) asm("sa__EVENT__readNextMapFile");
void func_0022c508(void*) asm("func_0022c508");
void sa__EVENT__effect_read_set(void*, s32) asm("sa__EVENT__effect_read_set");
void func_0022f5a0(void*, s32, s32) asm("func_0022f5a0");
void sa__EVENT__audio_read_set(void*, s32) asm("sa__EVENT__audio_read_set");
void func_002331a0(void*, s32, s32, s32, s32) asm("func_002331a0");
/*TARGET 00226090*/
void sa__EVENT__read_ctrl(void) asm("sa__EVENT__read_ctrl");
void sa__EVENT__read_ctrl(void) {
    W1966Hdr* h;
    W1966Cmd* c;
    s32 i, n, odd;
    u32 next;
    if (D_0035dd04 >= 64) return;
    h = D_0035dd08[D_0035dd04];
    if (h != 0) {
    if (D_0035de20 < h->start) return;
    if (h->end < D_0035de20) return;
    n = h->count;
    odd = D_0035dd04 & 1;
    c = (W1966Cmd*)(h + 1);
    for (i = 0; i < n; i++) {
        switch ((s32)(u16)(c->op - 37)) {
        case 0:
            func_002331a0((u8*)c + 10, odd, c->a4, c->a6, c->a8);
            c = (W1966Cmd*)((u8*)c + c->size);
            break;
        case 1:
            sa__EVENT__audio_read_set((u8*)c + 4, odd);
            c = (W1966Cmd*)((u8*)c + c->size);
            break;
        case 19:
            func_0022f5a0((u8*)c + 8, c->a4, c->a6);
            c = (W1966Cmd*)((u8*)c + c->size);
            break;
        case 20:
            sa__EVENT__effect_read_set((u8*)c + 6, c->a4);
            c = (W1966Cmd*)((u8*)c + ((W1966CmdU*)c)->size);
            break;
        case 25:
            func_0022c508((u8*)c + 4);
            c = (W1966Cmd*)((u8*)c + ((W1966CmdU*)c)->size);
            break;
        }
    }
    D_0035daf0 = D_0035dd08[D_0035dd04]->end - 1;
    if (D_0035daf0 < 0) D_0035daf0 = D_0035de28;
    next = D_0035dd04 + 1;
    D_0035dd04 = next;
    D_0035de60 = next;
    if (next != 1) func_00170888(0);
    } else {
        sa__EVENT__readNextMapFile();
    }
}
}  // namespace n00226090

// 00226268 (was src/anon/perm_00226268.cpp)
namespace n00226268 {
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct Area
{
  u8 world;
  u8 area;
  u8 entrance;
  u8 pad3;
  u16 layout;
  u16 event;
  u16 btl;
} Area;
extern Area D_0032bae0 asm("D_0032bae0");
extern s32 D_0035de58 asm("D_0035de58");
u32 func_00225a30(void) asm("func_00225a30");
u32 func_00228378(void) asm("func_00228378");
s32 func_002ef7b8(void) asm("func_002ef7b8");
s32 func_001979d8(Area *) asm("func_001979d8");
s32 func_001051a0(Area *, Area *) asm("func_001051a0");
void func_00168808(u32) asm("func_00168808");
s32 func_00170e80(void) asm("func_00170e80");
void func_00149370(Area *, char *) asm("func_00149370");
s32 func_001688c8(const char *) asm("func_001688c8");
void func_00170518(const char *, s32, u32) asm("func_00170518");
void func_00170888(void *) asm("func_00170888");
const char *YS__MESSAGE__GetFilename(u32) asm("YS__MESSAGE__GetFilename");
void func_00192260(u32, s32) asm("func_00192260");
/*TARGET 00226268*/
void sa__EVENT__readNextMapFile(void) asm("sa__EVENT__readNextMapFile");
void sa__EVENT__readNextMapFile(void)
{
  Area area;
  unsigned char new_var;
  char name[48];
  s32 avail;
  s32 need;
  s32 st;
  if (func_00225a30())
  {
    return;
  }
  st = D_0035de58;
  if (st == 2)
  {
    return;
  }
  if (st == 0)
  {
    st = 2;
  }
  D_0035de58 = st;
  if (!func_00228378())
  {
    return;
  }
  if (func_002ef7b8())
  {
    return;
  }
  {
    u32 v = 0xffff;
    area.world = v;
    area.area = v;
    area.entrance = v;
    area.layout = v;
    area.event = v;
    area.btl = v;
  }
  if (!func_001979d8(&area))
  {
    return;
  }
  if (func_001051a0(&D_0032bae0, &area))
  {
    return;
  }
  if (D_0035de58 != 1)
  {
    if (new_var = D_0032bae0.world != area.world)
    {
      func_00168808(area.world);
      D_0035de58 = 1;
      return;
    }
  }
  D_0035de58 = 2;
  avail = func_00170e80();
  func_00149370(&area, name);
  need = (func_001688c8(name) + 0x7ff) & (~0x7ff);
  if (avail < need)
  {
    return;
  }
  func_00170518(name, -200, 0);
  if (D_0032bae0.world != area.world)
  {
    avail -= need;
    if (avail >= ((func_001688c8(YS__MESSAGE__GetFilename(area.world)) + 0x7ff) & (~0x7ff)))
    {
      func_00192260(area.world, -200);
    }
  }
  func_00170888(0);
}
}  // namespace n00226268

// 002263f0 (was src/anon/auto80_199_queue.cpp)
namespace n002263f0 {
/*TARGET 002263f0*/
u32 func_002263f0(u32 a0, u32 a1) asm("_Z13func_002263f0jj");
u32 func_002263f0(u32 a0, u32 a1) {
    u32 t4;
    s32 t5;
    u32 t7;
    u32 p;
    s32 n;

    t4 = D_0035dd08[D_0035de60];

    if (t4 == 0) {
        goto FAIL;
    }

    t5 = *(s16*)(t4 + 8);
    t7 = D_0035de5c;
    if ((s32)t7 < t5) {
        goto STORE_FAIL;
    }

    *(u32*)(a0 + 0) = (u32)t5;

    p = D_0035dd08[D_0035de60];

    n = *(s16*)(p + 8);
    n = n - 1;
    *(u32*)(a1 + 0) = (u32)n;

    D_0035de60 = D_0035de60 + 1;
    return 1;

STORE_FAIL:
    *(u32*)(a0 + 0) = t7;
FAIL:
    return 0;
}
}  // namespace n002263f0

// 00226468: gap (unwritten before)
namespace n00226468 {
extern u8 D_0035db00[] asm("D_0035db00");
u8* func_00226468(void) asm("func_00226468");
u8* func_00226468(void) { return D_0035db00; }
}  // namespace n00226468

// 00226478 (was src/anon/batch_wcx2.cpp)
namespace n00226478 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct HeapE;
void* operator new[](unsigned int, HeapE*) asm("func_001063f0");
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
// 0x002c40d8: definition moved into src/anon/unit_002c3c90.cpp

// ---- 00226478
HeapE* GetAllocatorE(void) asm("_ZN4AREA12GetAllocatorEv");
void* AllocE(u32 n) asm("_ZN4AREA5AllocEj");
void PaxCtorE(void* p) asm("_ZN3ryj3PAXC1Ev");
void EvAllocInitE(void* self, void* buf, s32 n) asm("_ZN2sa11EVENT_ALLOC4initEPvi");
void* func_00170b30(s32 n) asm("func_00170b30");
// alloc_align128
void func_00134668(void* p) asm("func_00134668");
struct PoolA { u32 v; PoolA() { v = 0; } };
struct PoolB { s32 id; u32 v; PoolB() { id = -1; } };
struct PoolC { u32 a, b; PoolC() { a = 0; b = 0; } };
struct PoolD { u32 a, b, c; PoolD() { a = 0; b = 0; c = 0; } };
struct PoolE {
    u32 f0; s32 f4; u8 pad8[8]; u8 pax[32]; s16 f48; s16 pad50;
    PoolE() { PaxCtorE(pax); f4 = -1; f48 = -1; }
    ~PoolE() {}
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolF {
    s32 f0; u32 f4; u8 f8; u8 pad9[7]; s32 f16; u32 f20; u32 f24; u32 f28; u8 f32; u8 pad33[15]; u8 f48; u8 pad49[35];
    PoolF() { f16 = -1; f0 = -1; f4 = 0; f20 = 0; f28 = 0; f8 = 0; f32 = 0; f48 = 0; }
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolG {
    s32 f0; s32 f4; u32 f8; u8 pad[52];
    PoolG() { f0 = -1; f4 = -1; f8 = 0; }
    ~PoolG() {}
    static void* operator new[](unsigned int n) { return AllocE(n); }
} __attribute__((aligned(16)));
struct PoolH {
    s32 f0; s32 f4; u32 f8; u8 pad[10]; u8 f22; u8 f23; u8 pad2[16];
    PoolH() { f0 = -1; f4 = -1; f8 = 0; f22 = 0; f23 = 0; }
    static void* operator new[](unsigned int n) { return AllocE(n); }
};
struct PoolI {
    u8 d[112];
    PoolI() { func_00134668(this); }
    ~PoolI() {}
} __attribute__((aligned(16)));
extern PoolA* D_0035dce0 asm("D_0035dce0");
extern PoolB* D_0035dce4 asm("D_0035dce4");
extern PoolC* D_0035dce8 asm("D_0035dce8");
extern PoolD* D_0035dcec asm("D_0035dcec");
extern u8 D_0035db00[] asm("D_0035db00");
extern void* D_0035db14 asm("D_0035db14");
extern s32 D_0035db18 asm("D_0035db18");
extern PoolF* D_0035dcf0 asm("D_0035dcf0");
extern PoolE* D_0035dcf4 asm("D_0035dcf4");
extern PoolG* D_0035dcf8 asm("D_0035dcf8");
extern PoolH* D_0035dcfc asm("D_0035dcfc");
extern PoolI* D_0035dd00 asm("D_0035dd00");
/*TARGET 00226478*/
// Allocate and construct the event/effect object pools.
void sa__EVENT__fixAlloc(void) asm("sa__EVENT__fixAlloc");
// Allocate and construct the event/effect object pools.
void sa__EVENT__fixAlloc(void) {
    HeapE* heap = GetAllocatorE();
    if (!D_0035dce0) D_0035dce0 = new (heap) PoolA[128];
    if (!D_0035dce4) D_0035dce4 = new (heap) PoolB[128];
    if (!D_0035dce8) D_0035dce8 = new (heap) PoolC[64];
    if (!D_0035dcec) D_0035dcec = new (heap) PoolD[64];
    if (!D_0035db18) {
        D_0035db14 = 0;
        D_0035dcf4 = 0;
        D_0035dcf0 = 0;
        D_0035dcf8 = 0;
        D_0035dcfc = 0;
        D_0035dd00 = 0;
        return;
    }
    void* buf = func_00170b30(D_0035db18);  // alloc_align128
    EvAllocInitE(D_0035db00, buf, D_0035db18);
    D_0035db14 = buf;
    D_0035dcf4 = new PoolE[96];
    D_0035dcf0 = new PoolF[128];
    D_0035dcf8 = new PoolG[64];
    D_0035dcfc = new PoolH[96];
    D_0035dd00 = new (heap) PoolI[96];
}
}  // namespace n00226478

// 002267a0 (was src/anon/batch_w112.cpp)
namespace n002267a0 {
void func_002255f0(void) asm("func_002255f0");
void func_00106450(void*) asm("func_00106450");
void func_00105110(void*) asm("func_00105110");
void func_001ddd88(void*) asm("func_001ddd88");
void func_00170c00(void*) asm("func_00170c00");
struct E52 {
    u8 a[16];
    u8 b[36];
    ~E52() { func_001ddd88(b); }
    static void operator delete[](void*) asm("func_00105110");
};
struct E64 {
    u8 d[64];
    ~E64() {}
    static void operator delete[](void*) asm("func_00105110");
} __attribute__((aligned(16)));
struct E112 {
    u8 d[112];
    ~E112() {}
    static void operator delete[](void*) asm("func_00106450");
} __attribute__((aligned(16)));
extern void* D_0035dce0 asm("D_0035dce0");
extern void* D_0035dce4 asm("D_0035dce4");
extern void* D_0035dce8 asm("D_0035dce8");
extern void* D_0035dcec asm("D_0035dcec");
extern void* D_0035dcf0 asm("D_0035dcf0");
extern E52* D_0035dcf4 asm("D_0035dcf4");
extern E64* D_0035dcf8 asm("D_0035dcf8");
extern void* D_0035dcfc asm("D_0035dcfc");
extern E112* D_0035dd00 asm("D_0035dd00");
extern void* D_0035db14 asm("D_0035db14");
/*TARGET 002267a0*/
// Frees all of this module's buffers.
void sa__EVENT__fixFree(void) asm("sa__EVENT__fixFree");
// Frees all of this module's buffers.
void sa__EVENT__fixFree(void) {
    func_002255f0();
    if (D_0035dce0) { func_00106450(D_0035dce0); D_0035dce0 = 0; }
    if (D_0035dce4) { func_00106450(D_0035dce4); D_0035dce4 = 0; }
    if (D_0035dce8) { func_00106450(D_0035dce8); D_0035dce8 = 0; }
    if (D_0035dcec) { func_00106450(D_0035dcec); D_0035dcec = 0; }
    if (D_0035dcf4) { delete[] D_0035dcf4; D_0035dcf4 = 0; }
    if (D_0035dcf0) { func_00105110(D_0035dcf0); D_0035dcf0 = 0; }
    if (D_0035dcf8) { delete[] D_0035dcf8; D_0035dcf8 = 0; }
    if (D_0035dcfc) { func_00105110(D_0035dcfc); D_0035dcfc = 0; }
    if (D_0035dd00) { delete[] D_0035dd00; D_0035dd00 = 0; }
    if (D_0035db14) { func_00170c00(D_0035db14); D_0035db14 = 0; }
}
}  // namespace n002267a0

// 00226968 (was src/anon/tiny.cpp)
namespace n00226968 {
/*TARGET 00226968*/
void func_00226968(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00226968jjjj");
void func_00226968(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-8680)) = (u32)0;
}
}  // namespace n00226968

// 00226978 (was src/anon/batch_w77.cpp)
namespace n00226978 {
extern u8 D_0035de14 asm("D_0035de14");
extern u8 D_0035de15 asm("D_0035de15");
extern u32 D_0035de80 asm("D_0035de80");
extern u32 D_0035de84 asm("D_0035de84");
extern u32 D_0035de88 asm("D_0035de88");
extern u8 D_0035de0c asm("D_0035de0c");
extern u32 D_0035db10 asm("D_0035db10");
extern u32 D_0035db14 asm("D_0035db14");
extern u32 D_0035db18 asm("D_0035db18");
extern u32 D_0035de30 asm("D_0035de30");
extern u32 D_0035de34 asm("D_0035de34");
extern u32 D_0035de38 asm("D_0035de38");
extern u32 D_0035de3c asm("D_0035de3c");
struct St { u32 a, b, c, d, e, f; f32 g; u32 h, i, j; };
extern St D_0035db20 asm("D_0035db20");
extern u8 D_0035de44 asm("D_0035de44");
extern f32 D_0035de48 asm("D_0035de48");
extern u32 D_0035de40 asm("D_0035de40");
void func_00227108(s32) asm("func_00227108");
void func_00226968(void) asm("func_00226968");
void func_00226ee8(s32) asm("func_00226ee8");
void func_00226f90(void) asm("func_00226f90");
void func_00226fa8(void) asm("func_00226fa8");
void func_00226fc8(void) asm("func_00226fc8");
/*TARGET 00226978*/
void func_00226978(void) asm("func_00226978");
void func_00226978(void)
{
    func_00227108(0);
    func_00226968();
    D_0035de14 = 0;
    D_0035de15 = 0;
    D_0035de80 = 0;
    D_0035de84 = 0;
    D_0035de88 = 0;
    D_0035de0c = 0;
    D_0035db10 = 0;
    D_0035db14 = 0;
    D_0035db18 = 0;
    D_0035de30 = 0;
    D_0035de34 = 0;
    D_0035de38 = 0;
    D_0035de3c = 0;
    func_00226ee8(0);
    D_0035db20.a = 0;
    D_0035db20.b = 0;
    D_0035db20.c = 0;
    D_0035db20.d = 0;
    D_0035db20.e = 0;
    D_0035db20.f = 0;
    D_0035db20.g = 1.0f;
    D_0035db20.h = 0;
    D_0035db20.i = 0;
    D_0035db20.j = 0;
    D_0035de40 = 0;
    D_0035de44 = 0;
    D_0035de48 = 1.0f;
    func_00226f90();
    func_00226fa8();
    func_00226fc8();
}
}  // namespace n00226978

// 00226a70 (was src/anon/misc_2.cpp)
namespace n00226a70 {
/*TARGET 00226a70*/
void func_00226a70(void* self) asm("_Z13func_00226a70Pv");
void func_00226a70(void* self) {}
}  // namespace n00226a70

// 00226a78 (was src/anon/batch_w18.cpp)
namespace n00226a78 {
// 0x001e6c00: definition moved into src/anon/unit_001e0cb8.cpp

extern u32 D_0035db10 asm("D_0035db10");
extern u8 D_0035de27 asm("D_0035de27");
extern u32 D_0035de30 asm("D_0035de30");
extern u32 D_0035de34 asm("D_0035de34");
extern u32 D_0035de38 asm("D_0035de38");
extern u32 D_0035de3c asm("D_0035de3c");
/*TARGET 00226a78*/
void func_00226a78(void) asm("func_00226a78");
void func_00226a78(void) {
    D_0035db10 = 0;
    D_0035de27 = 0;
    D_0035de30 = 0;
    D_0035de34 = 0;
    D_0035de38 = 0;
    D_0035de3c = 0;
}
}  // namespace n00226a78

// 00226ab0: gap (unwritten before)
namespace n00226ab0 {
extern u32 D_0035db10 asm("D_0035db10");
u32 func_00226ab0(void) asm("func_00226ab0");
u32 func_00226ab0(void) { return D_0035db10; }
}  // namespace n00226ab0

// 00226ac0 (was src/anon/batch_w94.cpp)
namespace n00226ac0 {
s32 func_00197920(void) asm("func_00197920");
void func_00226ea0(void) asm("func_00226ea0");
void func_00227200(s32) asm("func_00227200");
void func_00227130(u32) asm("func_00227130");
void func_00228150(s32) asm("func_00228150");
void func_002272a8(void) asm("func_002272a8");
extern u32 D_0035de8c asm("D_0035de8c");
extern u32 D_0035de18 asm("D_0035de18");
extern u32 D_0035de80 asm("D_0035de80");
extern u32 D_0035de68 asm("D_0035de68");
extern u32 D_0035de6c asm("D_0035de6c");
extern u32 D_0035de84 asm("D_0035de84");
extern u8 D_0035de14 asm("D_0035de14");
extern f32 D_0035de48 asm("D_0035de48");
extern u32 D_0035de88 asm("D_0035de88");
extern u8 D_0035de15 asm("D_0035de15");
extern u8 D_0035de0c asm("D_0035de0c");
extern u8 D_0035de44 asm("D_0035de44");
/*TARGET 00226ac0*/
s32 func_00226ac0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) asm("func_00226ac0");
s32 func_00226ac0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    if (func_00197920()) func_00226ea0();
    D_0035de8c = e;
    D_0035de18 = b;
    D_0035de80 = c;
    D_0035de68 = f;
    D_0035de6c = g;
    D_0035de84 = d;
    D_0035de14 = 0;
    D_0035de48 = 1.0f;
    D_0035de15 = 0;
    D_0035de88 = 0;
    D_0035de44 = 0;
    D_0035de0c = 0;
    func_00227200(0);
    func_00227130(a);
    func_00228150(1);
    func_002272a8();
    return 0;
}
}  // namespace n00226ac0

// 00226bd0 (was src/anon/batch_w97.cpp)
namespace n00226bd0 {
// 0x001d4180: definition moved into src/anon/unit_001d3c08.cpp

// ---- 00226bd0
extern u8 D_0035de55 asm("D_0035de55");
extern u8 D_0035de0c asm("D_0035de0c");
void dk__EventCamera__end(u8) asm("dk__EventCamera__end");
s32 func_0022d7d8(void) asm("func_0022d7d8");
u32 func_0014abb8(void) asm("func_0014abb8");
// get_data_359840
u32 func_0014abc8(void) asm("func_0014abc8");
// get_data_359950
void func_0014aa80(u32, s32, s32) asm("func_0014aa80");
s32 func_001069a8(void) asm("func_001069a8");
void func_001618f0(void) asm("func_001618f0");
void func_001623b0(void) asm("func_001623b0");
void func_002bbe80(void) asm("func_002bbe80");
s32 func_0022bd90(void) asm("func_0022bd90");
void SOUND__silentBgSeOff(void) asm("SOUND__silentBgSeOff");
void func_00224b08(u32) asm("func_00224b08");
s32 func_0022f5e8(void) asm("func_0022f5e8");
void func_00102448(u32, s32) asm("func_00102448");
s32 func_001a84f0(void) asm("func_001a84f0");
// compare_two_globals
u32 func_001a8510(void) asm("func_001a8510");
// mod8_of_difference
void func_001382b8(u32) asm("func_001382b8");
void func_001978f0(f32) asm("func_001978f0");
void wtarget_00226bd0(u32 a0, u32, u32, u32) asm("_Z16wtarget_00226bd0jjjj");
/*TARGET 00226bd0*/
void wtarget_00226bd0(u32 a0, u32, u32, u32) asm("_Z16wtarget_00226bd0jjjj");
void wtarget_00226bd0(u32 a0, u32, u32, u32) {
    if (D_0035de55 == 1) dk__EventCamera__end(D_0035de0c);
    if (func_0022d7d8()) {
        func_0014aa80(func_0014abb8(), 15, 0);
        func_0014aa80(func_0014abc8(), 15, 0);
    }
    if (func_001069a8() == 1) {
        func_001618f0();
        func_001623b0();
    }
    func_002bbe80();
    if (!func_0022bd90()) SOUND__silentBgSeOff();
    func_00224b08(a0);
    if (func_0022f5e8()) func_00102448(a0, 1);
    if (!func_001a84f0()) {  // compare_two_globals
        func_001382b8(func_001a8510());
        func_00102448(a0, 0);
    }
    func_001978f0(0.0f);
}
}  // namespace n00226bd0

// 00226ce8 (was src/anon/auto80_199_queue.cpp)
namespace n00226ce8 {
/*TARGET 00226ce8*/
u32 func_00226ce8(u32 a0) asm("_Z13func_00226ce8j");
u32 func_00226ce8(u32 a0) {
    s32 s1;
    u32 v0;

    func_0022bb60();
    func_0022bbc8();
    s1 = 0;

    if (a0 != 0) {
LOOP:
        v0 = YS__CACHE_BUFF__IsFlushing();
        if (v0 != 0) {
            goto LOOP_CALL;
        }
        if (func_00225e48(a0) == 0) {
            goto CLEANUP;
        }
        if (s1 != 0) {
            goto CLEANUP;
        }
        func_00102448(a0, 0);
    }

CLEANUP:
    func_00226bd0(a0);
    func_00228240();
    sa__EVENT__last_countdown();
    return func_0015f288();

LOOP_CALL:
    func_00102448(a0, 0);
    s1 = 1;
    goto LOOP;
}
}  // namespace n00226ce8

// 00226d88 (was src/anon/batch_w5.cpp)
namespace n00226d88 {
void func_0014a4b0(void) asm("func_0014a4b0");
void func_00138480(u32) asm("func_00138480");
/*TARGET 00226d88*/
void func_00226d88(void) asm("func_00226d88");
void func_00226d88(void) {
    func_0014a4b0();
    func_00138480(0);
}
}  // namespace n00226d88

// 00226da8 (was src/anon/tiny_auto80_solver.cpp)
namespace n00226da8 {
u32 func_0014a4c0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0014a4c0jjjjjjjj");
void func_001384a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_001384a0jjjjjjjj");
/*TARGET 00226da8*/
u32 func_00226da8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00226da8jjjjjjjj");
u32 func_00226da8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r4 = 0u;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001384a0)(r4, r5, r6, r7, r8, r9, r10, r11);
    return ((u32(*)())func_0014a4c0)();
}
}  // namespace n00226da8

// 00226dc8 (was src/anon/batch_w56.cpp)
namespace n00226dc8 {
// 00226dc8
extern s32 D_0035db10 asm("D_0035db10");
extern u8 D_0035de27 asm("D_0035de27");
void func_00226d88(void) asm("func_00226d88");
void func_00232988(void) asm("func_00232988");
void func_002bc518(void) asm("func_002bc518");
s32 func_00228378(void) asm("func_00228378");
void func_0023d230(s32) asm("func_0023d230");
u32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
// limit_15000_or_25000
void func_00102c48(s32, u32, void*, s32) asm("func_00102c48");
void func_00226ce8(s32) asm("func_00226ce8");
/*TARGET 00226dc8*/
void func_00226dc8(void) asm("func_00226dc8");
void func_00226dc8(void)
{
    if (D_0035db10 == 4) return;
    D_0035db10 = 4;
    func_00226d88();
    func_00232988();
    func_002bc518();
    if (func_00228378()) {
        func_0023d230(0);
        func_00102c48(1, sa__EVENT__getEventPriority(), (void*)func_00226ce8, 4096);
    } else {
        D_0035de27 = 1;
        func_00226ce8(0);
    }
}
}  // namespace n00226dc8

// 00226e60 (was src/anon/batch_w12.cpp)
namespace n00226e60 {
s32 func_00197920(void) asm("func_00197920");
void func_00226dc8(void) asm("func_00226dc8");
extern u8 D_0035de0c asm("D_0035de0c");
/*TARGET 00226e60*/
// 0x001e2788: definition moved into src/anon/unit_001e0cb8.cpp

void func_00226e60(u8 v) asm("func_00226e60");
// 0x001e2788: definition moved into src/anon/unit_001e0cb8.cpp

void func_00226e60(u8 v) {
    if (func_00197920()) {
        D_0035de0c = v;
        func_00226dc8();
    }
}
}  // namespace n00226e60

// 00226ea0 (was src/anon/tiny_wrappers_more80_relaxed.cpp)
namespace n00226ea0 {
u32 func_00226bd0(u32, u32, u32, u32) asm("_Z13func_00226bd0jjjj");
extern u8 D_00360000 asm("D_00360000");
/*TARGET 00226ea0*/
u32 func_00226ea0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00226ea0jjjj");
u32 func_00226ea0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u8*)((u32)((u32)&D_00360000) - 8665u) = (u8)(0x00000000u);
    *(u32*)((u32)((u32)&D_00360000) - 9456u) = (u32)(0x00000004u);
    return func_00226bd0(0x00000000u, a1, a2, a3);
}
}  // namespace n00226ea0

// 00226ed0 (was src/sasa/event.cpp)
namespace sa { // method 00226ed0
/*TARGET 00226ed0*/
void EVENT_readWaitInit() asm("_ZN2sa5EVENT12readWaitInitEv");
void EVENT_readWaitInit() {
    u32 r15 = (u32)(0x004cu << 16);
    u32 r14 = (u32)(0x0036u << 16);
    r15 = (u32)(r15 | 0x4b40u);
    *(u32*)((u32)r14 + (s32)(-9488)) = r15;
}
}  // sa

// 00226ee8 (was src/anon/batch_w1732.cpp)
namespace n00226ee8 {
void func_00226ed0(void*) asm("func_00226ed0");
void func_00226f20(void*) asm("func_00226f20");
extern s32 D_0035de60 asm("D_0035de60");
/*TARGET 00226ee8*/
// 0x00197ac0: definition moved into src/anon/unit_00195d00.cpp

void func_00226ee8(void* p) asm("func_00226ee8");
// 0x00197ac0: definition moved into src/anon/unit_00195d00.cpp

void func_00226ee8(void* p) {
    func_00226ed0(p);
    D_0035de60 = 1;
    func_00226f20(p);
}
}  // namespace n00226ee8

// 00226f20 (was src/anon/batch_w1671.cpp)
namespace n00226f20 {
// 0x001d1820: definition moved into src/anon/unit_001d14e0.cpp

extern s32 D_0035de5c asm("D_0035de5c");
extern u8 D_0035de54 asm("D_0035de54");
extern f32 D_0035de1c asm("D_0035de1c");
extern s32 D_0035de20 asm("D_0035de20");
/*TARGET 00226f20*/
void func_00226f20(s32 a0) asm("func_00226f20");
void func_00226f20(s32 a0) {
    D_0035de5c = a0;
    if (a0 == 0) { D_0035de54 = 0; D_0035de1c = 0.0f; D_0035de20 = 0; return; }
    D_0035de54 = 1; D_0035de1c = -2.0f; D_0035de20 = -1;
}
}  // namespace n00226f20

// 00226f78 (was src/anon/auto200_999.cpp)
namespace n00226f78 {
extern u32 D_0035de5c asm("D_0035de5c");
extern u8 D_0035de54 asm("D_0035de54");
/*TARGET 00226f78*/
// 0x001a8ff8: definition moved into src/anon/unit_001a8618.cpp

void func_00226f78(u32 a0) asm("_Z13func_00226f78j");
// 0x001a8ff8: definition moved into src/anon/unit_001a8618.cpp

void func_00226f78(u32 a0) {
    D_0035de5c = a0;
    D_0035de54 = 1;
}
}  // namespace n00226f78

// 00226f90 (was src/anon/batch_w5.cpp)
namespace n00226f90 {
struct Tri { u32 a, b, c; };
extern Tri D_0035db50 asm("D_0035db50");
/*TARGET 00226f90*/
void func_00226f90(void) asm("func_00226f90");
void func_00226f90(void) {
    D_0035db50.a = 0;
    D_0035db50.b = 0;
    D_0035db50.c = 0;
}
}  // namespace n00226f90

// 00226fa8 (was src/anon/tiny_wrappers_imp.cpp)
namespace n00226fa8 {
u32 func_00225298(u32, u32, u32, u32) asm("_Z13func_00225298jjjj");
/*TARGET 00226fa8*/
u32 func_00226fa8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00226fa8jjjj");
u32 func_00226fa8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r15 = (u32)(0x0036u << 16);
    *(u8*)((u32)r15 + (s32)(-8695)) = (u8)0u;
    return func_00225298(r4, r5, r6, r7);
}
}  // namespace n00226fa8

// 00226fc8 (was src/anon/batch_wcx.cpp)
namespace n00226fc8 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" u8 D_0035de24, D_0035de25, D_0035de56;
extern "C" s32 D_0035de28, D_0035dd04;
extern "C" u32 D_0035de4c, D_0035de50, D_0035de2c;
extern u32 D_0035dd08[64] asm("D_0035dd08");
extern V4 D_0035de70 asm("D_0035de70");
void func_0022d7c8(void) asm("func_0022d7c8");
void func_00225a00(void) asm("func_00225a00");
// zero_global_byte_e
void func_00225a20(void) asm("func_00225a20");
void func_0022d7e8(void) asm("func_0022d7e8");
/*TARGET 00226fc8*/
void func_00226fc8(void) asm("func_00226fc8");
void func_00226fc8(void)
{
    D_0035de24 = 0;
    D_0035de25 = 0;
    D_0035de28 = -1;
    func_0022d7c8();
    func_00225a00();  // zero_global_byte_e
    func_00225a20();
    D_0035de4c = 0;
    D_0035de50 = 0;
    D_0035de2c = 0;
    D_0035de56 = 0;
    D_0035dd04 = -1;
    u32* w = D_0035dd08;
    s32 i = 63;
    do {
        *w = 0;
        i--;
        // R5900 short-loop padding

        w++;
    } while (i >= 0);
    func_0022d7e8();
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&D_0035de70) : "memory");
}
}  // namespace n00226fc8

// 00227078 (was src/anon/batch_w52.cpp)
namespace n00227078 {
extern u8* D_0035dcf0 asm("D_0035dcf0");
void func_002278e0(u8*) asm("func_002278e0");
/*TARGET 00227078*/
void func_00227078(void) asm("func_00227078");
void func_00227078(void) {
    s32 i;
    if (!D_0035dcf0) return;
    for (i = 0; i < 128; i++) {
        u8* e = (u8*)(i * 84 + (u32)D_0035dcf0);
        u32 st = *(u32*)(e + 4);
        if (st == 0) continue;
        if (st == 2) func_002278e0(e);
    }
}
}  // namespace n00227078

// 002270f8: gap (unwritten before)
namespace n002270f8 {
extern u32 D_0035db00_w[] asm("D_0035db00");
u32 func_002270f8(void) asm("func_002270f8");
u32 func_002270f8(void) { return D_0035db00_w[3]; }
}  // namespace n002270f8

// 00227108 (was src/anon/tiny.cpp)
namespace n00227108 {
/*TARGET 00227108*/
void func_00227108(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00227108jjjj");
void func_00227108(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0036u << 16);
    *(u32*)((u32)b + (-9460)) = (u32)a0;
}
}  // namespace n00227108

// 00227118 (was src/anon/misc_2.cpp)
namespace n00227118 {
/*TARGET 00227118*/
u8 func_00227118(void* self) asm("_Z13func_00227118Pv");
u8 func_00227118(void* self) { return (u8)(*(u8*)((char*)self + 9)); }
}  // namespace n00227118

// 00227120 (was src/anon/tiny.cpp)
namespace n00227120 {
extern u32 D_01dad918 asm("D_01dad918");
/*TARGET 00227120*/
u32 func_00227120(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00227120jjjj");
u32 func_00227120(u32 a0, u32 a1, u32 a2, u32 a3) {  // get_data_1dbd8f8
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_01dad918;
}
}  // namespace n00227120

// 00227130 (was src/anon/batch_w84.cpp)
namespace n00227130 {
s32 strlen(const char*) asm("strlen");
// Lazily records the owner, copies the name and sets the size limit.
struct G3 { void* a; s32 b, c; };
extern G3 D_0035db50 asm("D_0035db50");
extern u32 D_0035db18 asm("D_0035db18");
extern char D_01dad918[] asm("D_01dad918");
void func_002ff2e8(char*, const char*) asm("func_002ff2e8");
void func_00224cf0(u32) asm("func_00224cf0");
/*TARGET 00227130*/
void func_00227130(u8* p) asm("func_00227130");
void func_00227130(u8* p) {
    if (D_0035db50.a == 0) goto init;
cont:
    for (s32 i = 0; i < 32; i++) D_01dad918[i] = 0;
    func_002ff2e8(D_01dad918, (char*)p + 10);
    strlen(D_01dad918);  // strlen
    {
        u32 x = *(u32*)(p + 4);
        D_0035db18 = x;
        if (x) {
            s32 y = x + 0x40000;
            if (0x400000 < y) y = 0x400000;
            D_0035db18 = y;
            func_00224cf0(x);
        }
    }
    return;
init:
    D_0035db50.a = p;
    D_0035db50.b = 0;
    D_0035db50.c = 0;
    goto cont;
}
}  // namespace n00227130

// 00227200 (was src/anon/auto80_199_queue.cpp)
namespace n00227200 {
/*TARGET 00227200*/
void func_00227200(u32 a0) asm("_Z13func_00227200j");
void func_00227200(u32 a0) {
    func_002bbe38(a0);
    func_00161ee8();
    D_0035db10 = 1;
    func_00226ee8(a0);
    func_00226f90();
    func_00226fa8();
    func_00226fc8();
    func_0022bd80();
    D_0035de10 = -1;
    D_0035de64 = 0;
    D_0035de55 = 0;
    D_0035de08 = 0;
    D_0035de58 = 0;
    D_0035de0a = 0;
    D_0035de0b = 0;
    D_0035de26 = 0;
}
}  // namespace n00227200

// 002272a8 (was src/anon/tiny.cpp)
namespace n002272a8 {
extern u32 D_0035db10 asm("D_0035db10");
/*TARGET 002272a8*/
void func_002272a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002272a8jjjj");
void func_002272a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_0035db10 = (u32)((s32)2);
}
}  // namespace n002272a8

// 002272b8 (was src/anon/batch_w2358.cpp)
namespace n002272b8 {
struct Ent { u8* base; s32 ofs; s32 pad; };
struct Cmd { u16 size; s16 type; };
extern u8 D_0035de44 asm("D_0035de44");
extern s32 D_0035db10 asm("D_0035db10");
extern u8 D_0035de24 asm("D_0035de24");
extern s32 D_0035de40 asm("D_0035de40");
extern u8 D_0035de55 asm("D_0035de55");
extern u8 D_0035de56 asm("D_0035de56");
extern Ent D_0035db50[] asm("D_0035db50");
void func_00102448(void*, s32) asm("func_00102448");
s32 func_00197800(void) asm("func_00197800");
void func_00197828(f32) asm("func_00197828");
void func_001397d8(s32) asm("func_001397d8");
s32 func_00228378(void) asm("func_00228378");
void func_0015f278(void) asm("func_0015f278");
void* func_0014ac08(void) asm("func_0014ac08");
void* func_0014abd8(void) asm("func_0014abd8");
void func_0014aa80(void*, s32, s32) asm("func_0014aa80");
void func_0015cdb0(void) asm("func_0015cdb0");
void func_0022f7c0(Cmd*, void*) asm("func_0022f7c0");
void func_00230d78(Cmd*) asm("func_00230d78");
void sa__EVENT__set_effect_seq(Cmd*, void*) asm("sa__EVENT__set_effect_seq");
void func_0022f018(Cmd*, void*) asm("func_0022f018");
void sa__EVENT__set_kage_seq(Cmd*, void*) asm("sa__EVENT__set_kage_seq");
void sa__EVENT__set_bgcol_seq(Cmd*, void*) asm("sa__EVENT__set_bgcol_seq");
void sa__EVENT__set_part_seq(Cmd*, void*) asm("sa__EVENT__set_part_seq");
void sa__EVENT__set_alpha_seq(Cmd*, void*) asm("sa__EVENT__set_alpha_seq");
void func_0022cc38(Cmd*, void*) asm("func_0022cc38");
void func_0022d880(Cmd*, void*) asm("func_0022d880");
void func_0022d618(Cmd*, void*) asm("func_0022d618");
void sa__EVENT__set_bin_seq_blur(Cmd*, void*) asm("sa__EVENT__set_bin_seq_blur");
void sa__EVENT__set_bin_seq_focus(Cmd*, void*) asm("sa__EVENT__set_bin_seq_focus");
void func_0022f280(Cmd*, void*) asm("func_0022f280");
void func_0022f308(Cmd*, void*) asm("func_0022f308");
void sa__EVENT__set_bin_seq_crossfade(Cmd*, void*) asm("sa__EVENT__set_bin_seq_crossfade");
void sa__EVENT__set_ik_seq(Cmd*, void*) asm("sa__EVENT__set_ik_seq");
void func_002308c8(Cmd*) asm("func_002308c8");
void func_0022d3c8(Cmd*, void*) asm("func_0022d3c8");
void func_0022e5f8(Cmd*, void*) asm("func_0022e5f8");
void func_0022d728(Cmd*, void*) asm("func_0022d728");
void func_0022cf60(Cmd*, void*) asm("func_0022cf60");
void sa__EVENT__set_scale_seq(Cmd*, void*) asm("sa__EVENT__set_scale_seq");
void func_0022ea28(Cmd*, void*) asm("func_0022ea28");
void sa__EVENT__set_se_seq(Cmd*, void*) asm("sa__EVENT__set_se_seq");
void func_002332a8(Cmd*, void*) asm("func_002332a8");
void func_0022d9b0(Cmd*, void*) asm("func_0022d9b0");
void func_002253a0(Cmd*, void*) asm("func_002253a0");
void func_00225898(Cmd*, void*) asm("func_00225898");
void sa__EVENT__set_bin_seq_objcamera(Cmd*, void*) asm("sa__EVENT__set_bin_seq_objcamera");
void func_00224fa0(Cmd*, void*) asm("func_00224fa0");
void func_00224ea0(Cmd*, void*) asm("func_00224ea0");
void func_0022cae8(Cmd*, void*) asm("func_0022cae8");
void func_0022eb80(Cmd*, void*) asm("func_0022eb80");
void sa__EVENT__set_shadow_alpha_seq(Cmd*, void*) asm("sa__EVENT__set_shadow_alpha_seq");
void sa__EVENT__set_mirror_seq(Cmd*, void*) asm("sa__EVENT__set_mirror_seq");
void func_0022c998(Cmd*, void*) asm("func_0022c998");
void sa__EVENT__set_bin_seq_mission_effect(Cmd*, void*) asm("sa__EVENT__set_bin_seq_mission_effect");
void sa__EVENT__set_bin_seq_layout_noname(Cmd*, void*) asm("sa__EVENT__set_bin_seq_layout_noname");
void func_0022dd40(Cmd*, void*) asm("func_0022dd40");
void func_0022d598(Cmd*, void*) asm("func_0022d598");
void sa__EVENT__set_bin_seq_obj_pause(Cmd*, void*) asm("sa__EVENT__set_bin_seq_obj_pause");
void func_00232d60(Cmd*, void*) asm("func_00232d60");
void func_0022ce50(Cmd*, void*) asm("func_0022ce50");
void sa__EVENT__set_bin_seq_movie(Cmd*, void*) asm("sa__EVENT__set_bin_seq_movie");
void func_00233410(Cmd*, void*) asm("func_00233410");
void func_00230b50(Cmd*, void*) asm("func_00230b50");
void sa__EVENT__set_bin_black_fog(Cmd*, void*) asm("sa__EVENT__set_bin_black_fog");
void func_0022d1d8(Cmd*, void*) asm("func_0022d1d8");
void func_002322b8(Cmd*, void*) asm("func_002322b8");
void func_0022d238(Cmd*, void*) asm("func_0022d238");
void sa__EVENT__set_bin_hide_fobj(Cmd*, void*) asm("sa__EVENT__set_bin_hide_fobj");
void func_00233490(Cmd*, void*) asm("func_00233490");
void sa__EVENT__set_bin_countdown(Cmd*, void*) asm("sa__EVENT__set_bin_countdown");
void func_0022c7c0(Cmd*, void*) asm("func_0022c7c0");
void sa__EVENT__set_bin_wall_clip(Cmd*, void*) asm("sa__EVENT__set_bin_wall_clip");
void func_002328c0(Cmd*, void*) asm("func_002328c0");
/*TARGET 002272b8*/
// Event-script thread: waits for the event system to be ready, then runs the
// command stream of D_0035db50 (u16 size, s16 opcode) one command per step.
void func_002272b8(void* th) asm("func_002272b8");
// Event-script thread: waits for the event system to be ready, then runs the
// command stream of D_0035db50 (u16 size, s16 opcode) one command per step.
void func_002272b8(void* th) {
    for (;;) {
        for (;;) { if (D_0035de44 == 1) break; func_00102448(th, 0); }
        for (;;) { if (D_0035db10 == 2 && D_0035de24 && func_00197800()) break; func_00102448(th, 0); }
        func_00197828((f32)(D_0035de40 * 2));
        func_001397d8(16);
        if (func_00228378()) {
            func_0015f278();
            func_0014aa80(func_0014ac08(), 0, 0);
            func_0014aa80(func_0014abd8(), 0, 0);
        }
        D_0035db10 = 3;
        if (D_0035de55 == 1) func_0015cdb0();
        s32 i = 0;
    next:
          {
            if (D_0035db50[i].base) {
                Cmd* c = (Cmd*)(D_0035db50[i].base + D_0035db50[i].ofs);
                u32 size = c->size;
                if (size == 0) {
                    D_0035de56 = 1;
                    for (;;) func_00102448(th, 0);
                }
                switch (c->type + 0) {
        case 2: func_0022f7c0(c, th); break;
        case 6: func_00230d78(c); break;
        case 9: sa__EVENT__set_effect_seq(c, th); break;
        case 10: func_0022f018(c, th); break;
        case 11: sa__EVENT__set_kage_seq(c, th); break;
        case 12: sa__EVENT__set_bgcol_seq(c, th); break;
        case 13: sa__EVENT__set_part_seq(c, th); break;
        case 14: sa__EVENT__set_alpha_seq(c, th); break;
        case 18: func_0022cc38(c, th); break;
        case 21: func_0022d880(c, th); break;
        case 22: func_0022d618(c, th); break;
        case 23: sa__EVENT__set_bin_seq_blur(c, th); break;
        case 24: sa__EVENT__set_bin_seq_focus(c, th); break;
        case 25: func_0022f280(c, th); break;
        case 26: func_0022f308(c, th); break;
        case 27: sa__EVENT__set_bin_seq_crossfade(c, th); break;
        case 28: sa__EVENT__set_ik_seq(c, th); break;
        case 31: func_002308c8(c); break;
        case 32: func_0022d3c8(c, th); break;
        case 33: func_0022e5f8(c, th); break;
        case 34: func_0022d728(c, th); break;
        case 39: func_0022cf60(c, th); break;
        case 40: sa__EVENT__set_scale_seq(c, th); break;
        case 41: func_0022ea28(c, th); break;
        case 43: sa__EVENT__set_se_seq(c, th); break;
        case 44: func_002332a8(c, th); break;
        case 45: func_0022d9b0(c, th); break;
        case 46: func_002253a0(c, th); break;
        case 48: func_00225898(c, th); break;
        case 49: sa__EVENT__set_bin_seq_objcamera(c, th); break;
        case 51: func_00224fa0(c, th); break;
        case 52: func_00224ea0(c, th); break;
        case 53: func_0022cae8(c, th); break;
        case 54: func_0022eb80(c, th); break;
        case 55: sa__EVENT__set_shadow_alpha_seq(c, th); break;
        case 58: sa__EVENT__set_mirror_seq(c, th); break;
        case 59: func_0022c998(c, th); break;
        case 60: sa__EVENT__set_bin_seq_mission_effect(c, th); break;
        case 61: sa__EVENT__set_bin_seq_layout_noname(c, th); break;
        case 63: func_0022dd40(c, th); break;
        case 64: func_0022d598(c, th); break;
        case 65: sa__EVENT__set_bin_seq_obj_pause(c, th); break;
        case 66: func_00232d60(c, th); break;
        case 67: func_0022ce50(c, th); break;
        case 68: sa__EVENT__set_bin_seq_movie(c, th); break;
        case 69: func_00233410(c, th); break;
        case 71: func_00230b50(c, th); break;
        case 72: sa__EVENT__set_bin_black_fog(c, th); break;
        case 73: func_0022d1d8(c, th); break;
        case 74: func_002322b8(c, th); break;
        case 75: func_0022d238(c, th); break;
        case 77: sa__EVENT__set_bin_hide_fobj(c, th); break;
        case 79: func_00233490(c, th); break;
        case 80: sa__EVENT__set_bin_countdown(c, th); break;
        case 81: func_0022c7c0(c, th); break;
        case 82: sa__EVENT__set_bin_wall_clip(c, th); break;
        case 83: func_002328c0(c, th); break;
                }
                D_0035db50[i].ofs += size;
            }
            if (D_0035db10 != 3) continue;
            if (++i >= 1) i = 0;
            goto next;
          }
    }
}
}  // namespace n002272b8

// 00227818 (was src/anon/tiny_auto80_solver.cpp)
namespace n00227818 {
u32 func_001688c8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001688c8jjjjjjjj");
u32 func_00227818(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00227818jjjjjjjj");
/*TARGET 00227818*/
u32 func_00227818(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00227818jjjjjjjj");
u32 func_00227818(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a1;
    u32 v = func_001688c8(a0, a1, a2, a3, a4, a5, a6, a7);
    if (v == 0) {
        v = 2048;
    }
    *(u32*)(s0 + 28) = v;
    return (v + 2047) & -2048;
}
}  // namespace n00227818

// 00227858 (was src/anon/tiny_leaf.cpp)
namespace n00227858 {
/*TARGET 00227858*/
u32 func_00227858(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00227858jjjj");
u32 func_00227858(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = (u32)((s32)0u + (2));
    *(u32*)((u32)r5 + (s32)(24)) = r4;
    *(u32*)((u32)r5 + (s32)(4)) = r15;
    r2 = r4;
    return r2;
}
}  // namespace n00227858

// 00227870 (was src/anon/auto80_199_queue.cpp)
namespace n00227870 {
/*TARGET 00227870*/
u32 func_00227870(u32 a0, u32 a1, u32 a2) asm("_Z13func_00227870jjj");
u32 func_00227870(u32 a0, u32 a1, u32 a2) {
    u32 s0;
    u32 s1;
    u32 s2;

    (void)a0;
    s1 = a2;
    s2 = a1;

    s0 = func_00225eb8((u32)&D_0035db00, func_00227818(), s1);
    func_002fde18(s0, 0, 2048);
    return func_00227858(s0, s2, s1);
}
}  // namespace n00227870

// 002278e0 (was src/anon/batch_w62.cpp)
namespace n002278e0 {
extern s32 D_0035dcf0 asm("D_0035dcf0");
extern u8 D_0035db00[] asm("D_0035db00");
void func_00225fa0(u8*, u32) asm("func_00225fa0");
void func_00227930(u8*) asm("func_00227930");
/*TARGET 002278e0*/
void func_002278e0(u8* p) asm("func_002278e0");
void func_002278e0(u8* p) {
    if (D_0035dcf0 == 0) return;
    func_00225fa0(D_0035db00, *(u32*)(p + 24));
    func_00227930(p);
}
}  // namespace n002278e0

// 00227930 (was src/anon/tiny_auto80_solver.cpp)
namespace n00227930 {
void func_00227930(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00227930jjjjjjjj");
/*TARGET 00227930*/
void func_00227930(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00227930jjjjjjjj");
void func_00227930(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r15;
    r15 = (u32)((s32)0u + (-1));
    *(u8*)(r4 + 8) = (u8)0u;
    *(u32*)(r4 + 16) = r15;
    *(u32*)(r4 + 4) = 0u;
    *(u32*)(r4 + 28) = 0u;
    *(u32*)(r4 + 0) = r15;
}
}  // namespace n00227930

// 00227950 (was src/anon/batch_w68.cpp)
namespace n00227950 {
/* ---- 00227950 ---- */
struct E11 { s32 kind; s32 sub; u8 off; u8 pad[3]; s32 key; u8 rest[68]; };
extern E11* D_0035dcf0 asm("D_0035dcf0");
void func_002278e0(E11*) asm("func_002278e0");
void func_001024a8(void*) asm("func_001024a8");
/*TARGET 00227950*/
void func_00227950(u8* p) asm("func_00227950");
void func_00227950(u8* p) {
    s32 key = *(s32*)(p + 4);
    s32 i;
    for (i = 0; i < 128; i++) {
        E11* e = (E11*)(i * sizeof(E11) + (u32)D_0035dcf0);
        if (e->key == key && e->kind == 1 && e->sub == 4 && e->off == 0) func_002278e0(e);
    }
    func_001024a8(p);
}
}  // namespace n00227950

// 00227a08 (was src/anon/tiny_wrappers_more.cpp)
namespace n00227a08 {
u32 func_001024a8(u32, u32, u32, u32) asm("_Z13func_001024a8jjjj");
/*TARGET 00227a08*/
u32 func_00227a08(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00227a08jjjj");
u32 func_00227a08(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 4u)))) + 4u) = (u32)(0x00000004u);
    return func_001024a8(a0, a1, a2, a3);
}
}  // namespace n00227a08

// 00227a28 (was src/anon/batch_w22.cpp)
namespace n00227a28 {
// --- 00227a28
extern u8* D_0035dcf0 asm("D_0035dcf0");
/*TARGET 00227a28*/
u8* func_00227a28(void) asm("func_00227a28");
u8* func_00227a28(void) {
    u8* p = D_0035dcf0;
    for (s32 i = 0; i < 128; i++) {
        if (*(u32*)(p + 4) == 0) return p;
        p += 84;
    }
    return 0;
}
}  // namespace n00227a28

// 00227a60 (was src/anon/batch_wcx.cpp)
namespace n00227a60 {
s32 strcmp(u8*, u32) asm("strcmp");
// strcmp
struct E84 { s32 id; u32 used; u8 pad[40]; u8 name[36]; };
extern E84* D_0035dcf0b asm("D_0035dcf0");
/*TARGET 00227a60*/
E84* func_00227a60(u32 name, s32 id) asm("func_00227a60");
E84* func_00227a60(u32 name, s32 id)
{
    for (s32 i = 0; i < 128; i++) {
        if (D_0035dcf0b[i].used && D_0035dcf0b[i].id == id && !strcmp(D_0035dcf0b[i].name, name)) return &D_0035dcf0b[i];
    }
    return 0;
}
}  // namespace n00227a60

// 00227b00 (was src/anon/batch_w77.cpp)
namespace n00227b00 {
struct Ent { u32 type; s32 state; u8 pad[24]; char name[16]; char sub[16]; u8 pad2[20]; };
extern Ent* D_0035dcf0 asm("D_0035dcf0");
s32 strcmp(const char*, const char*) asm("strcmp");
/*TARGET 00227b00*/
// strcmp
Ent* func_00227b00(const char* name, u32 type, const char* sub) asm("func_00227b00");
// strcmp
Ent* func_00227b00(const char* name, u32 type, const char* sub)
{
    for (s32 i = 0; i < 128; i++) {
        if (D_0035dcf0[i].type != type) continue;
        if (D_0035dcf0[i].state != 3) continue;
        if (strcmp(D_0035dcf0[i].name, name)) continue;
        if (strcmp(D_0035dcf0[i].sub, sub)) continue;
        return &D_0035dcf0[i];
    }
    return 0;
}
}  // namespace n00227b00

// 00227bd8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00227bd8 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 00227bd8*/
u8* func_00227bd8(u32 a0, u32 a1) asm("_Z13func_00227bd8jj");
u8* func_00227bd8(u32 a0, u32 a1) {
    s32 i = 0;
    u8* p = *(u8**)((u8*)&D_00360000 - 8976u);
    while (1) {
        u8* out = p;
        if (*(u32*)(p + 0) != a1) {
            i += 1;
        } else {
            if (*(u32*)(p + 4) != 3) {
                i += 1;
            } else {
                if (*(u32*)(p + 12) == a0) {
                    return out;
                }
                i += 1;
            }
        }
        if (i < 128) {
            p += 84;
            continue;
        }
        return (u8*)0;
    }
}
}  // namespace n00227bd8

// 00227c28: gap (unwritten before): find the entry whose id (+24) matches, return its first word
namespace n00227c28 {
extern u32 D_0035dcf0 asm("D_0035dcf0");
s32 func_00227c28(s32 id) asm("func_00227c28");
s32 func_00227c28(s32 id) {
    if (D_0035dcf0 == 0) return -1;
    for (s32 i = 0; i < 128; i++) {
        u32 e = D_0035dcf0 + i * 84;
        if (*(s32*)(e + 24) == id) return *(s32*)e;
    }
    return -1;
}
}  // namespace n00227c28

// 00227c78 (was src/anon/tiny_auto80_queue.cpp)
namespace n00227c78 {
/*TARGET 00227c78*/
f32 func_00227c78(u16* a0) asm("_Z13func_00227c78Pt");
f32 func_00227c78(u16* a0) {
    union {
        u32 u;
        f32 f;
    } v;
    u32 w = v.u;
    w &= 0xffff0000u;
    w |= (u32)a0[0];
    u32* pu = (u32*)&v.u;
    u16* ph = (u16*)&v.u;
    *pu = w;
    ph[1] = a0[1];
    return v.f;
}
}  // namespace n00227c78

// 00227ca8 (was src/anon/tiny_auto80_queue.cpp)
namespace n00227ca8 {
/*TARGET 00227ca8*/
u32 func_00227ca8(u16* a0) asm("_Z13func_00227ca8Pt");
u32 func_00227ca8(u16* a0) {
    union {
        u32 u;
        f32 f;
    } v;
    u32 w = v.u;
    w &= 0xffff0000u;
    w |= (u32)a0[0];
    u32* pu = (u32*)&v.u;
    u16* ph = (u16*)&v.u;
    *pu = w;
    ph[1] = a0[1];
    return v.u;
}
}  // namespace n00227ca8

// 00227cd8 (was src/anon/batch_w23.cpp)
namespace n00227cd8 {
struct E40 { s32 id; u8 pad[36]; };
extern E40* D_0035dcfc asm("D_0035dcfc");
/*TARGET 00227cd8*/
E40* func_00227cd8(s32 id) asm("func_00227cd8");
E40* func_00227cd8(s32 id) {
    E40* e = D_0035dcfc;
    s32 i;
    for (i = 0; i < 96; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}
}  // namespace n00227cd8

// 00227d10 (was src/anon/tiny_auto80_queue.cpp)
namespace n00227d10 {
extern u8  D_00360000 asm("D_00360000");
u32 func_00227d10(...) asm("func_00227d10");
/*TARGET 00227d10*/
u8* func_00227d10(u32 a0) asm("_Z13func_00227d10j");
u8* func_00227d10(u32 a0) {
    s32 i = 0;
    u8* p = *(u8**)((u8*)&D_00360000 - 8964u);
    while (i < 96) {
        if (*(s32*)(p + 0) != -1) {
            if (*(u32*)(p + 4) == a0) {
                return p;
            }
        }
        i += 1;
        p += 40;
    }
    return (u8*)0;
}
}  // namespace n00227d10

// 00227d58 (was src/anon/tiny_auto80_queue.cpp)
namespace n00227d58 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 00227d58*/
u8* func_00227d58(u32 a0) asm("_Z13func_00227d58j");
u8* func_00227d58(u32 a0) {
    s32 i = 0;
    u8* p_data = *(u8**)((u8*)&D_00360000 - 8960u);
    u8* p_idx = *(u8**)((u8*)&D_00360000 - 8964u);
    while (i < 96) {
        if (*(s32*)(p_idx + 0) != -1) {
            if (*(u32*)(p_idx + 4) == a0) {
                return p_data;
            }
        }
        i += 1;
        p_data += 112;
        p_idx += 40;
    }
    return (u8*)0;
}
}  // namespace n00227d58

// 00227da8 (was src/anon/batch_w65.cpp)
namespace n00227da8 {
// Store a copy of the 40-byte record in the first free (-1) slot.
struct Rec40 { s32 id; u8 b[36]; };
extern Rec40* D_0035dcfc asm("D_0035dcfc");
/*TARGET 00227da8*/
void func_00227da8(Rec40* src) asm("func_00227da8");
void func_00227da8(Rec40* src) {
    s32 i;
    for (i = 0; i < 96; i++) {
        if (D_0035dcfc[i].id == -1) { D_0035dcfc[i] = *src; return; }
    }
}
}  // namespace n00227da8

// 00227e30 (was src/anon/batch_wcx2.cpp)
namespace n00227e30 {
// 001d3148: moved to src/anon/unit_001d30b0.cpp

// --------------------
struct S227e30 { u8* base; s32 pad; s32 ofs; };
struct C227e30 { u16 size; s16 type; };
extern S227e30 D_0035db50[] asm("D_0035db50");
extern s32 D_0035dd04 asm("D_0035dd04");
extern s32 D_0035db18 asm("D_0035db18");
extern u8 D_0035de24 asm("D_0035de24");
extern u8 D_0035de55 asm("D_0035de55");
void sa__EVENT__read_ctrl() asm("sa__EVENT__read_ctrl");
void func_00170888(void*) asm("func_00170888");
void func_00224d48() asm("func_00224d48");
void func_00102448_x9334(void*, s32) asm("func_00102448");
void func_0022f528(C227e30*, void*) asm("func_0022f528");
void func_0022d3b8(C227e30*) asm("func_0022d3b8");
void func_0022d358(void*) asm("func_0022d358");
void func_0022d3a8(C227e30*, void*) asm("func_0022d3a8");
void func_00231928(C227e30*) asm("func_00231928");
void func_00230838_x9340(C227e30*) asm("func_00230838");
void func_00230878_x9341(C227e30*) asm("func_00230878");
void func_00232398(C227e30*) asm("func_00232398");
void func_00226050(C227e30*) asm("func_00226050");
void sa__EVENT__read_se_data(C227e30*, void*) asm("sa__EVENT__read_se_data");
void func_00225328(C227e30*, void*) asm("func_00225328");
void func_00225788(C227e30*, void*) asm("func_00225788");
void func_00224b60(C227e30*, void*) asm("func_00224b60");
void func_0022ba08(C227e30*, void*) asm("func_0022ba08");
void func_00232110(C227e30*, void*) asm("func_00232110");
void func_00232100(C227e30*, void*) asm("func_00232100");
void func_0022c9f0(C227e30*) asm("func_0022c9f0");
/*TARGET 00227e30*/
void func_00227e30(void* th) asm("func_00227e30");
void func_00227e30(void* th) {
    s32 cnt = 0;
    for (;;) {
        s32 i;
        for (i = 0; i < 1; i++) {
            if (!D_0035db50[i].base) continue;
            C227e30* c = (C227e30*)(D_0035db50[i].base + D_0035db50[i].ofs);
            u32 size = c->size;
            cnt++;
            if (size == 0) {
                D_0035dd04 = 0;
                if (D_0035db18) {
                    sa__EVENT__read_ctrl();
                    func_00170888(th);
                }
                func_00224d48();
                D_0035de24 = 1;
                for (;;) func_00102448_x9334(th, 0);
            }
            switch (c->type + 0) {
            case 1: func_0022f528(c, th); break;
            case 8: func_0022d3b8(c); break;
            case 15: func_0022d358(th); break;
            case 16: func_0022d3a8(c, th); break;
            case 19: func_00231928(c); D_0035de55 = 1; break;
            case 29: func_00230838_x9340(c); break;
            case 30: func_00230878_x9341(c); break;
            case 35: func_00232398(c); break;
            case 36: func_00226050(c); break;
            case 42: sa__EVENT__read_se_data(c, th); break;
            case 46: func_00225328(c, th); break;
            case 47: func_00225788(c, th); break;
            case 50: func_00224b60(c, th); break;
            case 68: func_0022ba08(c, th); break;
            case 70: func_00232110(c, th); break;
            case 76: func_00232100(c, th); break;
            case 78: func_0022c9f0(c); break;
            }
            D_0035db50[i].ofs += size;
        }
        if (cnt == 0) func_00102448_x9334(th, 0);
        cnt = 0;
    }
}
}  // namespace n00227e30

// 00228058: gap (unwritten before)
namespace n00228058 {
extern u32 D_0035db10 asm("D_0035db10");
extern u8 D_0035de27 asm("D_0035de27");
extern u32 D_0035de38 asm("D_0035de38");
void sa__EVENT__camera_ctrl(void) asm("sa__EVENT__camera_ctrl");
void func_0022f3a8(void) asm("func_0022f3a8");
void func_00232f08(void) asm("func_00232f08");
void func_002306a8(void) asm("func_002306a8");
void sa__EVENT__light_ctrl(void) asm("sa__EVENT__light_ctrl");
void sa__EVENT__audio_ctrl(void) asm("sa__EVENT__audio_ctrl");
void sa__EVENT__read_ctrl(void) asm("sa__EVENT__read_ctrl");
void func_00225d30(void) asm("func_00225d30");
void func_001024a8(void*) asm("func_001024a8");
void func_00228058(void* t) asm("func_00228058");
void func_00228058(void* t) {
    if (D_0035db10 == 3) {
        sa__EVENT__camera_ctrl();
        func_0022f3a8();
        func_00232f08();
        func_002306a8();
        sa__EVENT__light_ctrl();
        sa__EVENT__audio_ctrl();
        sa__EVENT__read_ctrl();
        func_00225d30();
    }
    if (D_0035de27 == 1) {
        func_001024a8(t);
        D_0035de27 = 0;
        D_0035de38 = 0;
    }
}
}  // namespace n00228058

// 002280f8 (was src/anon/auto80_199_queue.cpp)
namespace n002280f8 {
void func_00224e28() asm("_Z13func_00224e28v");
/*TARGET 002280f8*/
void func_002280f8() asm("_Z13func_002280f8v");
void func_002280f8() {
    func_0022d820();
    sa__EVENT__leaveAllEffect();
    func_00227078();
    func_00224e28();
    func_00224bd0();
    func_00226fc8();
    sa__EVENT__fixFree();
    D_0035db10 = 0;
}
}  // namespace n002280f8

// 00228150 (was src/anon/batch_w78.cpp)
namespace n00228150 {
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }
u8* TASK_MANAGER__create_thread(u32, s32, s32, void*, s32) asm("TASK_MANAGER__create_thread");
void func_00228240(void) asm("func_00228240");
u32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
// limit_15000_or_25000
u8* func_00102c80(void) asm("func_00102c80");
u8* func_00102788(u32, u32, u32, void*) asm("func_00102788");
void func_00227e30(void) asm("func_00227e30");
void func_002272b8(void) asm("func_002272b8");
void func_00228058(void) asm("func_00228058");
void func_002280f8(void) asm("func_002280f8");
extern u8* D_0035de30 asm("D_0035de30");
extern u8* D_0035de34 asm("D_0035de34");
extern u8* D_0035de38 asm("D_0035de38");
extern u32 D_0035de3c asm("D_0035de3c");
extern u8 D_0035de27 asm("D_0035de27");
/*TARGET 00228150*/
void func_00228150(u32 a) asm("func_00228150");
void func_00228150(u32 a) {
    func_00228240();
    u32 w = sa__EVENT__getEventPriority();  // limit_15000_or_25000
    D_0035de3c = *(u32*)(func_00102c80() + 4);
    if (!D_0035de30) D_0035de30 = TASK_MANAGER__create_thread(D_0035de3c, a, w, (void*)func_00227e30, 0x2000);
    if (!D_0035de34) D_0035de34 = TASK_MANAGER__create_thread(D_0035de3c, a, w, (void*)func_002272b8, 0x2000);
    if (!D_0035de38) {
        u8* v = func_00102788(D_0035de3c, a, w, (void*)func_00228058);
        D_0035de38 = v;
        *(u8**)(v + 48) = (u8*)func_002280f8;
        D_0035de27 = 0;
    }
}
}  // namespace n00228150

// 00228240 (was src/anon/batch_w58.cpp)
namespace n00228240 {
// Frees up to three buffers from the current heap, then clears the heap.
void func_00102670(u32, u32) asm("func_00102670");
// to_1025f8
extern u32 D_0035de3c asm("D_0035de3c");
extern u32 D_0035de30 asm("D_0035de30");
extern u32 D_0035de34 asm("D_0035de34");
extern u32 D_0035de38 asm("D_0035de38");
extern u8 D_0035de27 asm("D_0035de27");
/*TARGET 00228240*/
void func_00228240(void) asm("func_00228240");
void func_00228240(void) {
    if (!D_0035de3c) return;
    if (D_0035de30) {
        func_00102670(D_0035de3c, D_0035de30);  // to_1025f8
        D_0035de30 = 0;
    }
    if (D_0035de34) {
        func_00102670(D_0035de3c, D_0035de34);  // to_1025f8
        D_0035de34 = 0;
    }
    if (D_0035de38 && !D_0035de27) {
        func_00102670(D_0035de3c, D_0035de38);  // to_1025f8
        D_0035de38 = 0;
    }
    D_0035de3c = 0;
}
}  // namespace n00228240

// 002282d8 (was src/anon/batch_w1.cpp)
namespace n002282d8 {
extern s32 D_0035db18 asm("D_0035db18");
/*TARGET 002282d8*/
s32 sa__EVENT__getEventPriority(void) asm("sa__EVENT__getEventPriority");
s32 sa__EVENT__getEventPriority(void) {  // limit_15000_or_25000
    return D_0035db18 == 0 ? 25000 : 15000;
}
}  // namespace n002282d8

// 002282f0 (was src/anon/batch_w61.cpp)
namespace n002282f0 {
void func_00102448(u32, u32) asm("func_00102448");
s32 func_00225b50(s32) asm("func_00225b50");
extern s32 D_0035db10 asm("D_0035db10");
extern s32 D_0035de20 asm("D_0035de20");
/*TARGET 002282f0*/
s32 sa__EVENT__checkStart(s32 a, u32 b) asm("sa__EVENT__checkStart");
s32 sa__EVENT__checkStart(s32 a, u32 b) {
    for (;;) {
        if (D_0035db10 != 3) return 1;
        if (!(D_0035de20 < a)) break;
        func_00102448(b, 0);
    }
    return func_00225b50(a) != 0;
}
}  // namespace n002282f0

// 00228378 (was src/sasa/event.cpp)
namespace sa { // method 00228378
u32 func_00197920(...) asm("_ZN2YS5EVENT6IsExecEv");
u32 func_002ba620(...) asm("func_002ba620");
/*TARGET 00228378*/
u32 EVENT_isSceneEventExec() asm("_ZN2sa5EVENT16isSceneEventExecEv");
u32 EVENT_isSceneEventExec() {
    u32 r2 = ((u32(*)())func_00197920)();
    u32 r15 = 0u;
    if (r2 != 0u) {
        r2 = ((u32(*)())func_002ba620)();
        r15 = ((u32)0u < (u32)r2);
    }
    r2 = r15;
    return r2;
}
}  // sa

// 002283b0 (was src/sasa/event.cpp)
namespace sa { // method 002283b0
extern u32 D_0032bae0 asm("D_0032bae0");
/*TARGET 002283b0*/
u32 EVENT_isLM() asm("_ZN2sa5EVENT4isLMEv");
u32 EVENT_isLM() {
    u32 v = *(u8*)&D_0032bae0;
    v ^= 0xbu;
    return (v < 1u);
}
}  // sa

// 002283c8 (was src/sasa/event.cpp)
namespace sa { // method 002283c8
extern u32 D_0032bae0 asm("D_0032bae0");
/*TARGET 002283c8*/
u32 EVENT_isLK() asm("_ZN2sa5EVENT4isLKEv");
u32 EVENT_isLK() {
    u32 v = *(u8*)&D_0032bae0;
    v ^= 0xau;
    return (v < 1u);
}
}  // sa

// 002283e0 (was src/anon/tiny_more.cpp)
namespace n002283e0 {
extern u32 D_0032bae0 asm("D_0032bae0");
/*TARGET 002283e0*/
u32 func_002283e0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_002283e0jjjj");
u32 func_002283e0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v = *(u8*)&D_0032bae0; v ^= 0x2u; return (v < 1u); }
}  // namespace n002283e0

// 002283f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002283f8 {
extern u8  D_00360000 asm("D_00360000");
/*TARGET 002283f8*/
s32 func_002283f8() asm("_Z13func_002283f8v");
s32 func_002283f8() {
    s32 a = *(s32*)((u8*)&D_00360000 - 8664u);
    if (a == -1) {
        return 0;
    }
    s32 b = *(s32*)((u8*)&D_00360000 - 8672u);
    return a - b;
}
}  // namespace n002283f8

// 00228420 (was src/anon/batch_w10.cpp)
namespace n00228420 {
extern struct { u32 a, b, c; } D_0035db00 asm("D_0035db00");
void wtarget_00228420(u32, u32, u32, u32) asm("_Z16wtarget_00228420jjjj");
/*TARGET 00228420*/
void wtarget_00228420(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00228420jjjj");
void wtarget_00228420(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0035db00.a = 0;
        D_0035db00.b = 0;
        D_0035db00.c = 0;
    }
}
}  // namespace n00228420

// 00228450 (was src/anon/tiny_wrappers_more.cpp)
namespace n00228450 {
u32 func_00228420(u32, u32, u32, u32) asm("_Z13func_00228420jjjj");
/*TARGET 00228450*/
u32 func_00228450(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00228450jjjj");
u32 func_00228450(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00228420(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n00228450


// 00228470: _GLOBAL__D_ stub (unwritten before)
namespace n00228470 {
u32 func_00228420(u32, u32, u32, u32) asm("_Z13func_00228420jjjj");
u32 func_00228470(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00228470");
u32 func_00228470(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00228420(0, 0x0000ffffu, a2, a3);
}
}  // namespace n00228470
