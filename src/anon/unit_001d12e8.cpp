#include "../common/types.h"
#include "../tozawa/cmenu_top.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// ---- 001d1190 (was whole asm, never written in C): message handler. The result variable starts as the message
// pointer (r = (s32)m): that copy is what puts m in v0 at entry, and `r = base(); return r;` keeps the base call a jal.
namespace n001d1190 {
struct Msg { u16 a; u16 id; s16 arg; };
s32 YS__PLAYER___OVR_exec_command_player(u8*, Msg*) asm("YS__PLAYER___OVR_exec_command_player");
u8* YS__ANTI_FORM__CheckForm(u8*, s32) asm("YS__ANTI_FORM__CheckForm");
u8* func_001b90c8(u8*) asm("func_001b90c8");
void func_001a1b30(u8*, u8) asm("func_001a1b30");
void func_001d97f0(u8*) asm("func_001d97f0");
s32 func_001b6b10(u8*, u8*) asm("func_001b6b10");
s32 func_001d1380(u8*, Msg*) asm("func_001d1380");
s32 func_001b4430(u16, u8*) asm("func_001b4430");
s32 func_001d1408(u8*, Msg*) asm("func_001d1408");
s32 func_001d12e8(u8*, u32) asm("func_001d12e8");
s32 func_001d1190(u8* p, Msg* m) asm("func_001d1190");
s32 func_001d1190(u8* p, Msg* m) {
    s32 r = (s32)m;
    switch (m->id) {
    default: r = YS__PLAYER___OVR_exec_command_player(p, m); break;
    case 5: r = func_001b6b10(p, 0); *(u32*)(p + 264) |= 0x100; break;
    case 4: {
        u8* e = YS__ANTI_FORM__CheckForm(p, m->arg);
        func_001a1b30(*(u8**)(p + 1164), func_001b90c8(e)[28]);
        func_001d97f0(e);
        return func_001b6b10(p, e);
    }
    case 72: return func_001d1380(p, m);
    case 81: case 707: return func_001b4430(*(u16*)(*(u8**)(p + 2884) + 6), p);
    case 316: return func_001d1408(p, m);
    case 73: return func_001d12e8(p, *(u32*)(*(u8**)(p + 2884) + 12));
    }
    return r;
}
}  // namespace n001d1190


// ---- 001d12e8 from src/anon/batch_w1672.cpp
namespace n001d12e8 {
void f17f488_w1672(u8*, int, float, float) asm("_Z13func_0017f488iiff");
void motion_push_w1672(u8*, u32, f32, f32, u32) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
u32 member_Get_w1672(s32) asm("_ZN2YS6MEMBER3GetEi");
u32 member_get_part_w1672(u32, s32) asm("_ZNK2YS6MEMBER8get_partEi");
void party_voice_part_w1672(u8*, u32) asm("_ZN2YS5PARTY10voice_partEi");
void YS__CHANGEIN__Start(u32) asm("YS__CHANGEIN__Start");
void func_001d12e8(u8* p, u32 b) asm("func_001d12e8");
void func_001d12e8(u8* p, u32 b) {
    f17f488_w1672(p + 0x140, 0x89, 0.0f, 0.0f);
    motion_push_w1672(p + 0x140, 0, 0.0f, 0.0f, 0);
    party_voice_part_w1672(p, member_get_part_w1672(member_Get_w1672(-1), 3));
    YS__CHANGEIN__Start(b);
}
}  // namespace n001d12e8

// ---- 001d1380 from src/anon/batch_w1672.cpp
namespace n001d1380 {
void f17f488_w1672(u8*, int, float, float) asm("_Z13func_0017f488iiff");
u32 GetSystemPax_w1672(void) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
u32 ryj__PAX__start(u32, u32, u32, u32, u32, u8*) asm("ryj__PAX__start");
void func_001a1b30(u32, u32) asm("func_001a1b30");
void func_001c8300(u8*, u32) asm("func_001c8300");
void func_001d1380(u8* p, u8* q) asm("func_001d1380");
void func_001d1380(u8* p, u8* q) {
    f17f488_w1672(p + 0x140, 0x8a, 8.0f, 0.0f);
    *(u32*)(p + 0xb68) = ryj__PAX__start(GetSystemPax_w1672(), 0x13, 0, 1, 0, p);
    func_001a1b30(*(u32*)(p + 0x48c), q[0x1c]);
    func_001c8300(p, *(u16*)q);
}
}  // namespace n001d1380

// ---- 001d1408 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001d1408 {
u32 func_001c8948(u32, u32, u32, u32) asm("_Z13func_001c8948jjjj");
u32 func_001d1408(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001d1408jjjj");
u32 func_001d1408(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_001c8948(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(1164));
    r15 = (u32)((s32)0u + (1));
    *(u8*)((u32)r14 + (s32)(431)) = (u8)r15;
    return r2;
}
}  // namespace n001d1408

// ---- 001d1438 from src/yasui/libys/sora.cpp (YS::SORA, plain functions bound by asm label so the build
// registry does not mix up the short method names)
namespace n001d1438 {
extern "C" u32 func_001a8b28();  // get_data_1c7cc10
extern "C" u32 func_001a8bd0(s32);
extern "C" u32 func_001a8bf8(u32, u32);  // get_bits5_at

u32 SORA_GetEntryId(s32 a0) asm("_ZN2YS4SORA10GetEntryIdEi");
u32 SORA_GetEntryId(s32 a0) {
    u32 s1 = func_001a8b28();  // get_data_1c7cc10
    u32 t = (u32)a0 << 1;
    u32 p = t + s1;
    if (a0 == 0) {
        u32 v = func_001a8bd0(-1);
        u32 idx = func_001a8bf8(v, 0);  // get_bits5_at
        u32 q = (idx << 1) + s1;
        return *(u16*)(q + 16);
    }
    return *(u16*)(p + 22);
}

// ---- 001d14a0 from src/yasui/libys/sora.cpp
u32 SORA_Get() asm("_ZN2YS4SORA3GetEv");
u32 SORA_Get() {
    u32 b = (0x0035u << 16);
    return *(u32*)((u32)b + 9216);
}

// ---- 001d14b0 from src/yasui/libys/sora.cpp
struct SORALayout {
    char _pad0[2928];
    s32 skateboard_mode;
};
void SORA_set_skateboard_mode(SORALayout* self, s32 v) asm("_ZN2YS4SORA19set_skateboard_modeEi");
void SORA_set_skateboard_mode(SORALayout* self, s32 v) {
    self->skateboard_mode = v;
}
}  // namespace n001d1438

// ---- 001d14b8 from src/anon/batch_w9.cpp
namespace n001d14b8 {
void YS__PARTY___OVR_voice(void*) asm("YS__PARTY___OVR_voice");
void func_001d14b8(u8* p) asm("func_001d14b8");
void func_001d14b8(u8* p) {
    if (*(s32*)(p + 2896) != 6) YS__PARTY___OVR_voice(p);
}
}  // namespace n001d14b8

