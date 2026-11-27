// Linked unit 0x002039c0-0x00203b48 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
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
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 002039c0 (was gap, written for the unit)
namespace n002039c0 {
struct StG { s32 w0; u8 b4; u8 b5; u8 pad6[2]; s32 w8; };
extern u8* D_01d9e6e0 asm("D_01d9e6e0");
void func_002039c0(u8* base, u8* c) asm("func_002039c0");
void func_002039c0(u8* base, u8* c) {
    StG* s = (StG*)(base + (*(s32**)(c + 12))[1] + 160);
    s->w0 = 0;
    s->b4 = 0;
    s->b5 = 1;
    s->w8 = 0;
    D_01d9e6e0[171] = 1;
}
}  // namespace n002039c0

// 002039f8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002039f8 {
extern u8  D_01da0000 asm("D_01da0000");
// alloc_aligned16
extern "C" void func_001e7798(...) asm("func_001e7798");
/*TARGET 002039f8*/
void func_002039f8(u32 a0, u8* a1) asm("_Z13func_002039f8jPh");
void func_002039f8(u32 a0, u8* a1) {
    u8* s0 = (u8*)(a0 + *(u32*)(*(u32*)(a1 + 12) + 4) + 160);
    u32 v = *(u32*)(s0 + 8);
    if (v != 0) {
        func_001e7798(*(u32*)((u32)&D_01da0000 - 6428u), v);
        *(u32*)(s0 + 8) = 0;
    }
}
}  // namespace n002039f8

// 00203a40 (was src/anon/batch_w33.cpp)
namespace n00203a40 {
/*TARGET 00203a40*/
// 0x001dc790: definition moved into src/anon/unit_001dbfd8.cpp

// VU0 random: five vrnext steps seeded with -1, plus 1.0 (hand-written VU0 macro code).
f32 func_00203a40(void) asm("func_00203a40");
// 0x001dc790: definition moved into src/anon/unit_001dbfd8.cpp

// VU0 random: five vrnext steps seeded with -1, plus 1.0 (hand-written VU0 macro code).
f32 func_00203a40(void) {  // vu_const_5f
    u32 r;
    asm volatile(
        "addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
        "vitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\t"
        "qmfc2 %0, $vf1"
        : "=r"(r) : : "$8");
    union { u32 i; f32 f; } u;
    u.i = r;
    return u.f;
}
}  // namespace n00203a40

// 00203a88 (was src/anon/auto80_199_queue.cpp)
namespace n00203a88 {
/*TARGET 00203a88*/
// 0x001fc678: definition moved into src/anon/unit_001fb350.cpp

s32 func_00203a88(u32 a0) asm("_Z13func_00203a88j");
// 0x001fc678: definition moved into src/anon/unit_001fb350.cpp

s32 func_00203a88(u32 a0) {
    u32 s0 = a0 & 0xFF;
    u32 t7 = s0 << 1;
    f32 f20 = (f32)(s32)t7;
    s0 = s0 >> 1;
    f32 f0 = func_00203a40();  // vu_const_5f
    f20 = f20 * f0;
    f0 = (f32)(s32)s0;
    f20 = f20 - f0;
    s32 v0 = (s32)f20;
    v0 = (v0 << 24) >> 24;
    return v0;
}
}  // namespace n00203a88

// 00203ae8 (was src/anon/batch_w56.cpp)
namespace n00203ae8 {
/*TARGET 00203ae8*/
// 0x001ef1a0: definition moved into src/anon/unit_001ec098.cpp

// 00203ae8
s32 func_00203ae8(u8* a, u8* b) asm("func_00203ae8");
// 0x001ef1a0: definition moved into src/anon/unit_001ec098.cpp

// 00203ae8
s32 func_00203ae8(u8* a, u8* b)
{
    if (!*(u32*)(a + 80)) return 0;
    u8 t = b[204];
    if (t == 1 || t == 3 || t == 2) { if (!*(u32*)(a + 84)) return 0; }
    if (b[201] && !*(u32*)(a + 88)) return 0;
    return 1;
}
}  // namespace n00203ae8

