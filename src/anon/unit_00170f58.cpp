// YS script traps, first part of the file 0x170f58-0x175590 (object/actor traps of the VM trap
// table at 0x34dd00). The file is linked as two units: unit_00170f58.cpp (up to and including the
// gap trap 0x171e00, whose flags word is volatile for the reload after the call) and unit_00171e58.cpp.
// Each function keeps the declarations of the source it was matched in (one namespace per
// function); functions marked "gap" were never written before and come from the trap table.
#include "../common/types.h"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/progress.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"

// ---- 00170f58 gap
namespace g00170f58 {
u32 YS__OBJ__is_exist(s32) asm("YS__OBJ__is_exist");
void func_00170f58(BD_VALUE* bd) asm("func_00170f58");
void func_00170f58(BD_VALUE* bd) {
    s32 r = 0;
    if (bd->i) r = YS__OBJ__is_exist(bd->i) != 0;
    bd->i = r;
}
}  // namespace g00170f58

// ---- 00170f98 from src/anon/batch_w62.cpp
namespace n00170f98 {
struct V4 { f32 x, y, z, w; };
extern s8 D_01c5f490 asm("D_01c5f490");
extern V4 D_01c5f4a0 asm("D_01c5f4a0");
void func_00175528(void) asm("func_00175528");
void func_002fd188(void (*)(void)) asm("func_002fd188");
u32 func_0016f000(u32, V4*, f32) asm("func_0016f000");
void func_00170f98(u32* p) asm("func_00170f98");
void func_00170f98(u32* p) {
    if (D_01c5f490 == 0) {
        f32 z = 0.0f;
        D_01c5f4a0.x = z;
        D_01c5f4a0.y = z;
        D_01c5f4a0.z = z;
        D_01c5f4a0.w = 1.0f;
        D_01c5f490 = 1;
        func_002fd188(func_00175528);                     
    }
    *p = func_0016f000(*p, &D_01c5f4a0, 3.14159274f);
}
}  // namespace n00170f98

// ---- 00171030 gap
namespace g00171030 {
f32 func_001837c0(s32, s32, f32) asm("func_001837c0");
void func_00171030(BD_VALUE* bd) asm("func_00171030");
void func_00171030(BD_VALUE* bd) { bd->f = func_001837c0(bd[0].i, bd[1].i, bd[2].f); }
}  // namespace g00171030

// ---- 00171068 from src/ys/traps.cpp
namespace n00171068 {
extern s32 YS_OBJ_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
void trap_sysobj_moveto(BD_VALUE* bd) asm("_ZN2YS18trap_sysobj_movetoEP8BD_VALUE");
void trap_sysobj_moveto(BD_VALUE* bd) { bd->i = YS_OBJ_GetPlayer(); }
}  // namespace n00171068

// ---- 00171090 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00171090 {
u32 YS__OBJ__is_exist(u32, u32, u32, u32) asm("_Z17YS__OBJ__is_existjjjj");
u32 func_00171090(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00171090jjjj");
u32 func_00171090(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r2 = YS__OBJ__is_exist(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(0));
    r15 = *(u32*)((u32)r14 + (s32)(1416));
    r15 = (u32)(r15 & 0x0080u);
    r15 = ((u32)0u < (u32)r15);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00171090

// ---- 001710d0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001710d0 {
u32 YS__OBJ__is_exist(u32, u32, u32, u32) asm("_Z17YS__OBJ__is_existjjjj");
u32 func_001710d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001710d0jjjj");
u32 func_001710d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r2 = YS__OBJ__is_exist(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(0));
    r13 = (u32)(0x0100u << 16);
    r15 = *(u32*)((u32)r14 + (s32)(1416));
    r15 = (u32)(r15 & r13);
    r15 = ((u32)0u < (u32)r15);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n001710d0

// ---- 00171110 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00171110 {
u32 YS__OBJ__is_exist(u32, u32, u32, u32) asm("_Z17YS__OBJ__is_existjjjj");
u32 func_00171110(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00171110jjjj");
u32 func_00171110(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r2 = YS__OBJ__is_exist(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(0));
    r13 = (u32)(0x0001u << 16);
    r15 = *(u32*)((u32)r14 + (s32)(1416));
    r15 = (u32)(r15 & r13);
    r15 = ((u32)0u < (u32)r15);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00171110

// ---- 00171150 from src/anon/batch_w6.cpp
namespace n00171150 {
void func_0017f488(u32, u32, f32, f32) asm("func_0017f488");
void YS__trap_sysobj_motion_start(u32* p) asm("YS__trap_sysobj_motion_start");
void YS__trap_sysobj_motion_start(u32* p) {
    func_0017f488(p[0] + 320, p[1], *(f32*)&p[2], 0.0f);
}
}  // namespace n00171150

// ---- 00171180 gap
namespace g00171180 {
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_00171180(BD_VALUE* bd) asm("func_00171180");
void func_00171180(BD_VALUE* bd) { func_0017f488((u8*)bd[0].p + 320, bd[1].i, bd[3].f, bd[2].f); }
void func_0017f540(u8*, s32, f32, f32) asm("func_0017f540");
void func_001711b0(BD_VALUE* bd) asm("func_001711b0");
void func_001711b0(BD_VALUE* bd) { func_0017f540((u8*)bd[0].p + 320, bd[1].i, bd[2].f, 0.0f); }
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
void func_001711e0(BD_VALUE* bd) asm("func_001711e0");
void func_001711e0(BD_VALUE* bd) { func_0017f5e0((u8*)bd[0].p + 320, bd[1].i, 0, bd[2].f, 0.0f); }
}  // namespace g00171180

// ---- 00171210 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00171210 {
u32 YS__OBJ__is_exist(u32, u32, u32, u32) asm("_Z17YS__OBJ__is_existjjjj");
u32 func_00171210(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00171210jjjj");
u32 func_00171210(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u, r17 = 0u;
    r17 = r4;
    r16 = *(u32*)((u32)r4 + (s32)(0));
    r4 = r16;
    r2 = YS__OBJ__is_exist(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(352));
    r15 = (u32)(r15 & 0x0002u);
    r15 = ((u32)0u < (u32)r15);
    *(u32*)((u32)r17 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00171210

// ---- 00171258 gap
namespace g00171258 {
void func_00171258(BD_VALUE* bd) asm("func_00171258");
void func_00171258(BD_VALUE* bd) { bd->i = *(s32*)((u8*)bd[0].p + 340); }
}  // namespace g00171258

// ---- 00171268 from src/anon/batch_w210.cpp
namespace n00171268 {
struct O171 { char p[0x7f8]; u32 fl; char q[0x30]; };
struct A171 { O171* o; f32 f; };
void func_001ad990(void* a, f32 b, f32 c, f32 d) asm("_Z13func_001ad990jfff");
void func_00171268(A171* a) asm("func_00171268");
void func_00171268(A171* a) {
    O171* o = a->o;
    f32 f = a->f;
    if (!(o->fl & 0x10)) func_001ad990((char*)o + 2092, 1.0f, 0.0f, f);
}
}  // namespace n00171268

// ---- 001712b0 from src/anon/batch_w210.cpp
namespace n001712b0 {
struct O171 { char p[0x7f8]; u32 fl; char q[0x30]; };
struct A171 { O171* o; f32 f; };
void func_001ad990(void* a, f32 b, f32 c, f32 d) asm("_Z13func_001ad990jfff");
void func_001712b0(A171* a) asm("func_001712b0");
void func_001712b0(A171* a) {
    O171* o = a->o;
    f32 f = a->f;
    if (!(o->fl & 0x10)) func_001ad990((char*)o + 2092, 0.0f, 1.0f, f);
}
}  // namespace n001712b0

// ---- 001712f8 from src/ys/traps.cpp
namespace n001712f8 {
u32 func_00186888(u32, u32, u32, u32) asm("func_00186888");
u32 trap_obj_blow(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS13trap_obj_blowEP8BD_VALUE");
u32 trap_obj_blow(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00186888(*(u32*)(*(u32*)(a0 + 0u) + 4u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n001712f8

// ---- 00171318 gap
namespace g00171318 {
void func_00171318(BD_VALUE* bd) asm("func_00171318");
void func_00171318(BD_VALUE* bd) {
    u8* a = (u8*)bd[0].p;
    u8* b;
    if (!a || !(b = (u8*)bd[1].p)) {
        bd->i = 0;
        return;
    }
    bd->i = *(s32*)(a + 4) - *(s32*)(b + 4);
}
}  // namespace g00171318

// ---- 00171348 from src/anon/batch_w7.cpp
namespace n00171348 {
struct VObj { void** vtbl; };
void trap_obj_hide_impl(u32* bd) asm("_ZN2YS13trap_obj_hideEP8BD_VALUE");
void trap_obj_hide_impl(u32* bd) {
    VObj* o = *(VObj**)(*bd + 4);
    ((void (*)(VObj*))o->vtbl[17])(o);
}
}  // namespace n00171348

// ---- 00171378 from src/anon/batch_w8.cpp
namespace n00171378 {
typedef void (*VFn)(void*);
void trap_obj_show(void** p) asm("_ZN2YS13trap_obj_showEP8BD_VALUE");
void trap_obj_show(void** p) {
    void** o = ((void***)p[0])[1];
    ((VFn)(*(void***)o)[18])(o);
}
}  // namespace n00171378

// ---- 001713a8 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001713a8 {
extern "C" u32 func_0016bff0(u32, u32, u32, u32) asm("_ZN2YS3OBJ10get_serialEv");
u32 func_001713a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001713a8jjjj");
u32 func_001713a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_0016bff0(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001713a8

// ---- 001713d8 gap
namespace g001713d8 {
void func_001713d8(BD_VALUE* bd) asm("func_001713d8");
void func_001713d8(BD_VALUE* bd) { bd->i = *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 2728); }
}  // namespace g001713d8

// ---- 001713f0 from src/anon/batch_w1.cpp
namespace n001713f0 {
void YS__BTLOBJ__set_hitback(void*, s32, f32) asm("YS__BTLOBJ__set_hitback");
void func_001713f0(BD_VALUE* bd) asm("func_001713f0");
void func_001713f0(BD_VALUE* bd) {
    void* o = *(void**)((u8*)bd[0].p + 4);
    s32 i = bd[1].i;
    YS__BTLOBJ__set_hitback(o, i, bd[2].f);
}
}  // namespace n001713f0

// ---- 00171418 from src/anon/batch_w28.cpp
namespace n00171418 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
Q16* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
extern Q16 D_01c5f480 asm("D_01c5f480");
void func_00171418(u8** p) asm("func_00171418");
void func_00171418(u8** p) {
    Q16* v = YS__OBJ__get_pos(*(u32*)(*p + 4));                          
    if (v != &D_01c5f480) QCOPY(&D_01c5f480, v);
    *p = (u8*)&D_01c5f480;
}
}  // namespace n00171418

// ---- 00171460 from src/ys/traps.cpp
namespace n00171460 {
extern void YS_OBJ_set_pos(void*, s32) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void trap_obj_set_pos(BD_VALUE* bd) asm("_ZN2gb16trap_obj_set_posEP8BD_VALUE");
void trap_obj_set_pos(BD_VALUE* bd) {
    YS_OBJ_set_pos(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n00171460

// ---- 00171480 from src/anon/batch_w10.cpp
namespace n00171480 {
void func_0016adc8(void*, void*) asm("func_0016adc8");
void func_00171480(u8* p) asm("func_00171480");
void func_00171480(u8* p) {
    u32 tmp[4] __attribute__((aligned(16)));
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(*(void**)(p + 4)) : "$8", "memory");
    func_0016adc8(*(void**)(*(u8**)p + 4), tmp);
}
}  // namespace n00171480

// ---- 001714b0 from src/ys/traps.cpp
namespace n001714b0 {
extern void YS_OBJ_set_pos_trans(void*, s32) asm("_ZN2YS3OBJ13set_pos_transERKN2kn7FVectorE");
void trap_obj_set_pos_trans(BD_VALUE* bd) asm("_ZN2YS22trap_obj_set_pos_transEP8BD_VALUE");
void trap_obj_set_pos_trans(BD_VALUE* bd) {
    YS_OBJ_set_pos_trans(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n001714b0

// ---- 001714d0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001714d0 {
extern "C" u32 YS_OBJ_is_attach(u32, u32, u32, u32) asm("_ZN2YS3OBJ9is_attachEv");
u32 func_001714d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001714d0jjjj");
u32 func_001714d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_OBJ_is_attach(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001714d0

// ---- 00171500 gap
namespace g00171500 {
void func_00171500(BD_VALUE* bd) asm("func_00171500");
void func_00171500(BD_VALUE* bd) { bd->p = *(u8**)(*(u8**)((u8*)bd[0].p + 4) + 2880) + 4; }
}  // namespace g00171500

// ---- 00171518 from src/anon/batch_w27.cpp
namespace n00171518 {
void YS__OBJ__get_dir(void*, u32) asm("YS__OBJ__get_dir");
extern u32 D_01c5f480[4] asm("D_01c5f480");
void func_00171518(u32** p) asm("func_00171518");
void func_00171518(u32** p) {
    u32 t[4] __attribute__((aligned(16)));
    YS__OBJ__get_dir(t, (*p)[1]);
    u32* d = D_01c5f480;
    if (d != t) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(t) : "$8", "memory");
    }
    *p = d;
}
}  // namespace n00171518

// ---- 00171568 gap
namespace g00171568 {
void func_00171568(BD_VALUE* bd) asm("func_00171568");
void func_00171568(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 2748) |= 1 << bd[1].i; }
void func_00171590(BD_VALUE* bd) asm("func_00171590");
void func_00171590(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 2748) &= ~(1 << bd[1].i); }
void func_001715b8(BD_VALUE* bd) asm("func_001715b8");
void func_001715b8(BD_VALUE* bd) { *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 2748) &= ~(1 << bd[1].i); }
}  // namespace g00171568

// ---- 001715e0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001715e0 {
extern "C" u32 YS_OBJ_get_part_num(u32, u32, u32, u32) asm("_ZN2YS3OBJ12get_part_numEv");
u32 func_001715e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001715e0jjjj");
u32 func_001715e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_OBJ_get_part_num(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001715e0

// ---- 00171610 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00171610 {
extern "C" u32 YS_OBJ_get_entry_id(u32, u32, u32, u32) asm("_ZN2YS3OBJ12get_entry_idEv");
u32 func_00171610(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00171610jjjj");
u32 func_00171610(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_OBJ_get_entry_id(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00171610

// ---- 00171640 from src/anon/batch_w25.cpp
namespace n00171640 {
extern u8 D_01c5f480 asm("D_01c5f480");
void func_00185138(u32, void*, s32, float) asm("func_00185138");
void func_00171640(u32* p) asm("func_00171640");
void func_00171640(u32* p) {
    func_00185138(*(u32*)(p[0] + 4), &D_01c5f480, p[2] != 0, *(float*)&p[1]);
    p[0] = (u32)&D_01c5f480;
}
}  // namespace n00171640

// ---- 00171690 from src/anon/batch_w9.cpp
namespace n00171690 {
void func_00185278(u32, f32, u32) asm("func_00185278");
struct Args171690 { u32* obj; f32 f; u32 flag; };
void func_00171690(Args171690* p) asm("func_00171690");
void func_00171690(Args171690* p) {
    u32 x = p->obj[1];
    func_00185278(x, p->f, p->flag != 0);
}
}  // namespace n00171690

// ---- 001716c0 gap
namespace g001716c0 {
u32 YS__COMMAND_ELEM__Get(s32) asm("YS__COMMAND_ELEM__Get");
void func_00190128(void*) asm("func_00190128");
void func_00190878(void*, u32, u32) asm("func_00190878");
s32 func_001b8f10(u32, u32, void*) asm("func_001b8f10");
void func_001716c0(BD_VALUE* bd) asm("func_001716c0");
void func_001716c0(BD_VALUE* bd) {
    u8 t[32];
    u32 o = *(u32*)((u8*)bd[0].p + 4);
    u32 r = YS__COMMAND_ELEM__Get(bd[1].i);
    u32 x = *(u32*)((u8*)bd[2].p + 4);
    func_00190128(t);
    func_00190878(t, x, 0);
    bd->i = func_001b8f10(r, o, t);
}
}  // namespace g001716c0

// ---- 00171740 from src/anon/auto80_199_queue.cpp
namespace n00171740 {
void func_00171740(u32* a0) asm("_Z13func_00171740Pj");
void func_00171740(u32* a0) {
    u32* s0 = a0;
    u32 t6 = *(u32*)a0;
    t6 = *(u32*)(t6 + 4);

    u32 t7 = *(u32*)(t6 + 1416);
    if ((t7 & 2) != 0) {
        t6 = *(u32*)(t6 + 4);
        t7 = *(u32*)t6;
        u32 fn = *(u32*)(t7 + 96);
        u32 v0 = ((u32(*)(u32))fn)(t6);
        *s0 = v0;
    } else {
        *(u32*)a0 = 0;
    }
}
}  // namespace n00171740

// ---- 00171798 gap
namespace g00171798 {
void func_00171798(BD_VALUE* bd) asm("func_00171798");
void func_00171798(BD_VALUE* bd) { *(s32*)(*(u8**)((u8*)bd[0].p + 4) + 944) = bd[1].i; }
}  // namespace g00171798

// ---- 001717b0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001717b0 {
u32 func_0019c440(u32, u32, u32, u32) asm("_Z13func_0019c440jjjj");
u32 func_001717b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001717b0jjjj");
u32 func_001717b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_0019c440(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001717b0

// ---- 001717e0 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n001717e0 {
extern "C" u32 YS_OBJ_can_capture_control(u32, u32, u32, u32) asm("_ZN2YS3OBJ19can_capture_controlEv");
u32 func_001717e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001717e0jjjj");
u32 func_001717e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_OBJ_can_capture_control(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n001717e0

// ---- 00171810 from src/anon/batch_w20.cpp
namespace n00171810 {
void trap_obj_voice(u32* v) asm("_ZN2YS14trap_obj_voiceEP8BD_VALUE");
void trap_obj_voice(u32* v) {
    u8* o = *(u8**)(v[0] + 4);
    (*(void (**)(u8*, u32, u32))(*(u8**)o + 84))(o, v[1], v[2]);
}
}  // namespace n00171810

// ---- 00171848 from src/anon/batch_w26.cpp
namespace n00171848 {
inline void* operator new(unsigned int, void* p) { return p; }
void YS__OBJ__is_exist(void*) asm("_Z17YS__OBJ__is_existjjjj");
void party_use_mp(void*) asm("_ZN2YS5PARTY6use_mpEv");
void func_00171848(void** p) asm("func_00171848");
void func_00171848(void** p) {
    if (*p) YS__OBJ__is_exist(((void**)*p)[1]);
    u8* o = (u8*)((void**)*p)[1];
    if (*(u32*)(o + 1416) & 4) party_use_mp(o);
}
}  // namespace n00171848

// ---- 00171898 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n00171898 {
extern "C" u32 YS_STDOBJ_show_picture(u32, u32, u32, u32) asm("_ZN2YS6STDOBJ12show_pictureEi");
u32 func_00171898(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00171898jjjj");
u32 func_00171898(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r4 + (s32)(4));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS_STDOBJ_show_picture(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n00171898

// ---- 001718d0 from src/ys/traps.cpp
namespace n001718d0 {
extern void YS_SORA_set_skateboard_mode(void*, s32) asm("_ZN2YS4SORA19set_skateboard_modeEi");
void trap_obj_set_skateboard_mode(BD_VALUE* bd) asm("_ZN2YS28trap_obj_set_skateboard_modeEP8BD_VALUE");
void trap_obj_set_skateboard_mode(BD_VALUE* bd) {
    YS_SORA_set_skateboard_mode(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n001718d0

// ---- 001718f0 from src/ys/traps.cpp
namespace n001718f0 {
extern void YS_STDOBJ_set_special_command(void*, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void trap_obj_capture_command(BD_VALUE* bd) asm("_ZN2YS24trap_obj_capture_commandEP8BD_VALUE");
void trap_obj_capture_command(BD_VALUE* bd) {
    YS_STDOBJ_set_special_command(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n001718f0

// ---- 00171910 from src/anon/batch_w2.cpp
namespace n00171910 {
struct ObjRef { u32 pad0; void* obj; };
struct BdObjFloat { ObjRef* ref; f32 value; };
void func_0016aeb8(void* obj, f32 v) asm("func_0016aeb8");
void func_00171910(BdObjFloat* a) asm("func_00171910");
void func_00171910(BdObjFloat* a) {
    func_0016aeb8(a->ref->obj, a->value);                     
}
}  // namespace n00171910

// ---- 00171930 from src/anon/batch_w18.cpp
namespace n00171930 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
void YS__OBJ__set_wish_dir(void*, Vec4*) asm("YS__OBJ__set_wish_dir");
void func_00171930(u8** p) asm("func_00171930");
void func_00171930(u8** p) {
    Vec4 v;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&v), "r"(p[1]) : "$8", "memory");
    YS__OBJ__set_wish_dir(*(void**)(p[0] + 4), &v);                                
}
}  // namespace n00171930

// ---- 00171960 gap
namespace g00171960 {
void func_00171960(BD_VALUE* bd) asm("func_00171960");
void func_00171960(BD_VALUE* bd) { bd->f = *(f32*)(*(u8**)(*(u8**)((u8*)bd[0].p + 4) + 8) + 80); }
}  // namespace g00171960

// ---- 00171978 from src/ys/traps.cpp
namespace n00171978 {
u32 func_00198580(u32, u32) asm("func_00198580");
u32 trap_obj_get_weight(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_obj_get_weightEP8BD_VALUE");
u32 trap_obj_get_weight(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00198580(*(u32*)(*(u32*)(a0 + 0u) + 4u), *(u32*)(a0 + 4u));                      
}
}  // namespace n00171978

// ---- 00171998 from src/anon/auto80_199_queue.cpp
namespace n00171998 {
void func_00171998(u32 a0) asm("_Z13func_00171998j");
void func_00171998(u32 a0) {
    u8 local[32];
    u32 s0 = a0;

    u32 t7a = *(u32*)(a0 + 12);
    u32 s1 = *(u32*)(t7a + 4);

    func_00190128(local);
    func_00190878(local, s1, 0);

    u32 t6 = *(u32*)(s0 + 4);
    u32 t7 = *(u32*)(s0 + 0);
    u32 a2 = *(u32*)(s0 + 8);
    u32 a1 = *(u32*)(t6 + 4);
    u32 a0v = *(u32*)(t7 + 4);

    func_0016bae8(a0v, a1, a2, local);
}
}  // namespace n00171998

// ---- 00171a00 gap
namespace g00171a00 {
void func_00171a00(BD_VALUE* bd) asm("func_00171a00");
void func_00171a00(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    kn::FVector* a = (kn::FVector*)bd[1].p;
    kn::FVector* b = (kn::FVector*)bd[2].p;
    *(kn::FVector*)(o + 2928) = *a;
    *(kn::FVector*)(o + 2944) = *b;
}
}  // namespace g00171a00

// ---- 00171a40 from src/anon/batch_w6.cpp
namespace n00171a40 {
void func_001cfac0(u32, f32, f32, f32, f32) asm("func_001cfac0");
struct S1a40 { u32* obj; f32 a, b, c, d; };
void func_00171a40(S1a40* p) asm("func_00171a40");
void func_00171a40(S1a40* p) {
    func_001cfac0(p->obj[1], p->a, p->b, p->c, p->d);
}
}  // namespace n00171a40

// ---- 00171a70 from src/anon/batch_w29.cpp
namespace n00171a70 {
u32* party_get_ability(u32 p) asm("_ZN2YS5PARTY11get_abilityEv");
void func_00171a70(u32* v) asm("func_00171a70");
void func_00171a70(u32* v) {
    u32* bits = party_get_ability(*(u32*)(v[0] + 4));
    u32 n = v[1];
    v[0] = (bits[n >> 5] & (1 << (n & 31))) != 0;
}
}  // namespace n00171a70

// ---- 00171ac8 from src/anon/auto80_199_queue.cpp
namespace n00171ac8 {
u32 YS__OBJ__get_target_pos(u32 a0, u32 a1) asm("_Z23YS__OBJ__get_target_posjj");
void func_00171ac8(u32* a0) asm("_Z13func_00171ac8Pj");
void func_00171ac8(u32* a0) {
    u8 local[32];
    u8* s1 = local + 16;
    u32* s0 = a0;

    u32 t7 = *(u32*)(a0 + 1);
    YS__OBJ__get_target_pos(local, *(u32*)(t7 + 4));

    t7 = *(u32*)(s0 + 0);
    YS__OBJ__get_target_pos(s1, *(u32*)(t7 + 4));

    *s0 = func_001a75d8((u32)s1, (u32)local, 4);
}
}  // namespace n00171ac8

// ---- 00171b28 from src/ys/traps.cpp
namespace n00171b28 {
extern void YS_STDOBJ_hook_command_image(void*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
void trap_obj_hook_command_image(BD_VALUE* bd) asm("_ZN2YS27trap_obj_hook_command_imageEP8BD_VALUE");
void trap_obj_hook_command_image(BD_VALUE* bd) {
    YS_STDOBJ_hook_command_image(*(void**)((char*)bd->i + 4));
}
}  // namespace n00171b28

// ---- 00171b48 gap
namespace g00171b48 {
void func_00198a90(u8*) asm("func_00198a90");
void func_00171b48(BD_VALUE* bd) asm("func_00171b48");
void func_00171b48(BD_VALUE* bd) { func_00198a90(*(u8**)((u8*)bd[0].p + 4)); }
void func_00171b68(BD_VALUE* bd) asm("func_00171b68");
void func_00171b68(BD_VALUE* bd) { bd->i = *(u32*)(*(u8**)((u8*)bd[0].p + 4) + 2064) != 0; }
}  // namespace g00171b48

// ---- 00171b80 from src/ys/traps.cpp
namespace n00171b80 {
extern void YS_OCC_disable(void*) asm("_ZN2YS6OBJOCC11disable_allEv");
void trap_obj_disable_occ(BD_VALUE* bd) asm("_ZN2YS20trap_obj_disable_occEP8BD_VALUE");
void trap_obj_disable_occ(BD_VALUE* bd) {
    YS_OCC_disable((char*)*(void**)((char*)bd->i + 4) + 2048);
}
}  // namespace n00171b80

// ---- 00171ba0 from src/ys/traps.cpp
namespace n00171ba0 {
extern void YS_OCC_enable(void*) asm("_ZN2YS6OBJOCC10enable_allEv");
void trap_obj_enable_occ(BD_VALUE* bd) asm("_ZN2YS19trap_obj_enable_occEP8BD_VALUE");
void trap_obj_enable_occ(BD_VALUE* bd) {
    YS_OCC_enable((char*)*(void**)((char*)bd->i + 4) + 2048);
}
}  // namespace n00171ba0

// ---- 00171bc0 from src/ys/traps.cpp
namespace n00171bc0 {
extern void YS_OCC_disable_bone(void*, s32) asm("_ZN2YS6OBJOCC7disableEi");
void trap_obj_disable_occ_bone(BD_VALUE* bd) asm("_ZN2YS25trap_obj_disable_occ_boneEP8BD_VALUE");
void trap_obj_disable_occ_bone(BD_VALUE* bd) {
    YS_OCC_disable_bone((char*)*(void**)((char*)bd->i + 4) + 2048, bd[1].i);
}
}  // namespace n00171bc0

// ---- 00171be8 gap
namespace g00171be8 {
void func_001b32c8(u8*, s32) asm("func_001b32c8");
void func_00171be8(BD_VALUE* bd) asm("func_00171be8");
void func_00171be8(BD_VALUE* bd) { func_001b32c8(*(u8**)((u8*)bd[0].p + 4) + 2048, bd[1].i); }
struct W4 {
    u32 a, b, c, d;
    void clr() { a = 0; b = 0; c = 0; d = 0; }
};
void func_00171c10(BD_VALUE* bd) asm("func_00171c10");
void func_00171c10(BD_VALUE* bd) { ((W4*)(*(u8**)((u8*)bd[0].p + 4) + 2048))->clr(); }
}  // namespace g00171be8

// ---- 00171c30 from src/ys/traps.cpp
namespace n00171c30 {
extern void YS_OBJ_ControlOff(s32) asm("_ZN2YS3OBJ10ControlOffEi");
void func_obj_control_off(BD_VALUE* bd) asm("_ZN2YS20func_obj_control_offEP8BD_VALUE");
void func_obj_control_off(BD_VALUE* bd) { YS_OBJ_ControlOff(bd->i); }
}  // namespace n00171c30

// ---- 00171c48 from src/ys/traps.cpp
namespace n00171c48 {
extern void YS_OBJ_ControlOn(s32) asm("_ZN2YS3OBJ9ControlOnEi");
void func_obj_control_on(BD_VALUE* bd) asm("_ZN2YS19func_obj_control_onEP8BD_VALUE");
void func_obj_control_on(BD_VALUE* bd) { YS_OBJ_ControlOn(bd->i); }
}  // namespace n00171c48

// ---- 00171c60 from src/anon/batch_w2366.cpp
namespace n00171c60 {
struct In171 { u32 x0; u32 x4; };
struct R171 { u32 x0, x4, x8, xc, x10, x14; };
struct A171 { In171* p0; In171* p4; u32 p8; u32 pc; u32 p10; u32 p14; };
extern u32 D_0034d8a0 asm("D_0034d8a0");
R171* u_tail4(u32, u32, u32, u32) asm("_Z15YS__OBJ__attachjjjj");
void func_00171c60(A171* a) asm("func_00171c60");
void func_00171c60(A171* a) {
    u32 y = a->p4->x4;
    u32 x = a->p0->x4;
    R171* r = u_tail4(x, y, a->p8, a->pc);
    u32 t = a->p10;
    if (t) {
        u32 d = D_0034d8a0;
        u32 q = a->p14;
        r->xc = d;
        r->x10 = t;
        r->x14 = q;
    }
}
}  // namespace n00171c60

// ---- 00171cc0 from src/ys/traps.cpp
namespace n00171cc0 {
extern void YS_OBJ_detach(void*) asm("_ZN2YS3OBJ6detachEv");
void trap_obj_detach(BD_VALUE* bd) asm("_ZN2YS15trap_obj_detachEP8BD_VALUE");
void trap_obj_detach(BD_VALUE* bd) { YS_OBJ_detach(*(void**)((char*)bd->i + 4)); }
}  // namespace n00171cc0

// ---- 00171ce0 gap
namespace g00171ce0 {
void func_00171ce0(BD_VALUE* bd) asm("func_00171ce0");
void func_00171ce0(BD_VALUE* bd) {}
void func_00171ce8(BD_VALUE* bd) asm("func_00171ce8");
void func_00171ce8(BD_VALUE* bd) {
    u8* a = (u8*)bd[0].p;
    s32 v = bd[1].i;
    u8* q = *(u8**)(a + 4) + 768;
    *(u8**)(q + 136) = a;
    *(s32*)(q + 140) = v;
}
}  // namespace g00171ce0

// ---- 00171d08 from src/ys/traps.cpp
namespace n00171d08 {
extern void YS_ACT_clear(void*) asm("_ZN2YS3ACT5clearEv");
void trap_obj_act_clear(BD_VALUE* bd) asm("_ZN2YS18trap_obj_act_clearEP8BD_VALUE");
void trap_obj_act_clear(BD_VALUE* bd) {
    YS_ACT_clear((char*)*(void**)((char*)bd->i + 4) + 768);
}
}  // namespace n00171d08

// ---- 00171d28 from src/ys/traps.cpp
namespace n00171d28 {
u32 func_001880b0(u32, u32, u32, u32) asm("func_001880b0");
u32 trap_obj_act_push(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS17trap_obj_act_pushEP8BD_VALUE");
u32 trap_obj_act_push(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001880b0(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 768u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n00171d28

// ---- 00171d50 gap
namespace g00171d50 {
void func_001881f8(u8*, s32) asm("func_001881f8");
void func_00171d50(BD_VALUE* bd) asm("func_00171d50");
void func_00171d50(BD_VALUE* bd) { func_001881f8(*(u8**)((u8*)bd[0].p + 4) + 768, bd[1].i); }
void func_001882a8(u8*, s32) asm("func_001882a8");
void func_00171d78(BD_VALUE* bd) asm("func_00171d78");
void func_00171d78(BD_VALUE* bd) { func_001882a8(*(u8**)((u8*)bd[0].p + 4) + 768, bd[1].i); }
void func_00171da0(BD_VALUE* bd) asm("func_00171da0");
void func_00171da0(BD_VALUE* bd) {
    u32* q = (u32*)(*(u8**)((u8*)bd[0].p + 4) + 768);
    bd->i = q[1] != q[0] || q[36];
}
}  // namespace g00171d50

// ---- 00171dd8 from src/ys/traps.cpp
namespace n00171dd8 {
u32 func_00188170(u32, u32, u32, u32) asm("func_00188170");
u32 trap_obj_act_start_pri(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_obj_act_start_priEP8BD_VALUE");
u32 trap_obj_act_start_pri(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00188170(((u32)(*(u32*)(*(u32*)(a0 + 0u) + 4u)) + 768u), *(u32*)(a0 + 4u), a2, a3);
}
}  // namespace n00171dd8

// ---- 00171e00 gap
namespace g00171e00 {
struct O171 { char p[0x7f8]; volatile u32 fl; char q[0x30]; };
void func_001ad990(void* a, f32 b, f32 c, f32 d) asm("_Z13func_001ad990jfff");
void func_00171e00(BD_VALUE* bd) asm("func_00171e00");
void func_00171e00(BD_VALUE* bd) {
    O171* o = *(O171**)((u8*)bd[0].p + 4);
    if (!(o->fl & 0x10)) func_001ad990((char*)o + 2092, 1.0f, 0.0f, 0.0f);
    o->fl |= 0x10;
}
}  // namespace g00171e00
