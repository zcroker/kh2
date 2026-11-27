#include "../common/types.h"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/progress.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// YS battle traps (0x18f140-0x1900d0): script traps for attack, damage, magic, limit and summon objects.
// Linked unit; trap table .data at 0x34ef30 (98 entries). The local static of 0x18f940 (guard 0x1c60cf0,
// vector 0x1c60d00) stays extern, its __tcf_0 (0x1900c8) is written as a plain empty function.

static inline bool trap_bit_test(u32 v, u32 m) { return (v & m) != 0; }

// ---- 0018f140 (gap trap, written)
namespace n0018f140 {
u32 tgt_is_exist(u8*) asm("_ZNK2YS6TARGET8is_existEv");
void tgt_set(u8*, s32, u8*) asm("func_00190920");
void func_0018f140(BD_VALUE* bd) asm("func_0018f140");
void func_0018f140(BD_VALUE* bd) {
    u8* o = *(u8**)((u8*)bd[0].p + 4);
    u8* t = o + 2548;
    if (!tgt_is_exist(t)) {
        if (*(u32*)(o + 1416) & 0x10) {
            if (*(s32*)(t + 12) != 3) tgt_set(t, 2, *(u8**)((u8*)bd[0].p + 4));
        }
    }
    bd[0].p = t;
}
}  // namespace n0018f140

// ---- 0018f1c0 from src/ys/traps.cpp
namespace n0018f1c0 {
extern void YS_PIERROT_set_sheet(void*, s32) asm("_ZN2YS7PIERROT9set_sheetEi");
void trap_btlobj_set_sheet(BD_VALUE* bd) asm("_ZN2YS21trap_btlobj_set_sheetEP8BD_VALUE");
void trap_btlobj_set_sheet(BD_VALUE* bd) {
    YS_PIERROT_set_sheet(*(void**)((char*)bd->i + 4), bd[1].i);
}
}  // namespace n0018f1c0

// ---- 0018f1e0 from src/anon/tiny_wrappers_more.cpp
namespace n0018f1e0 {
u32 func_001b3c58(u32, u32, u32, u32) asm("_Z13func_001b3c58jjjj");
u32 func_0018f1e0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018f1e0jjjj");
u32 func_0018f1e0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001b3c58(((u32)(*(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 0u)))) + 4u))), ((u32)(*(u32*)((u32)(a0) + 4u))), a2, a3);
}
}  // namespace n0018f1e0

// ---- 0018f200 (gap trap, written)
namespace n0018f200 {
void func_0018f200(BD_VALUE* bd) asm("func_0018f200");
void func_0018f200(BD_VALUE* bd) {
    bd[0].p = *(u8**)((*(u8**)((u8*)bd[0].p + 4)) + 2880) + 4;
}
}  // namespace n0018f200

// ---- 0018f218 from src/anon/batch_w10.cpp
namespace n0018f218 {
void func_0018f218(u8* p) asm("func_0018f218");
void func_0018f218(u8* p) {
    void* o = *(void**)(*(u8**)p + 4);
    (*(void (**)(void*, void*))(*(u8**)o + 104))(o, *(void**)(p + 4));
}
}  // namespace n0018f218

// ---- 0018f248 from src/anon/batch_w19.cpp
namespace n0018f248 {
void func_00186740(u32, u32, u32, u32, f32, f32) asm("func_00186740");
struct Args18 { u32* a; u32 b, c, d; f32 e, f; };
void func_0018f248(Args18* p) asm("func_0018f248");
void func_0018f248(Args18* p) {
    u32 b = p->b;
    func_00186740(p->a[1], b, p->c, p->d, p->e, p->f);
}
}  // namespace n0018f248

// ---- 0018f280 (gap trap, written)
namespace n0018f280 {
void YS__BTLOBJ__exec_damage_large(void*, s32, f32) asm("YS__BTLOBJ__exec_damage_large");
void func_0018f280(BD_VALUE* bd) asm("func_0018f280");
void func_0018f280(BD_VALUE* bd) {
    void* o = *(void**)((u8*)bd[0].p + 4);
    s32 i = bd[1].i;
    YS__BTLOBJ__exec_damage_large(o, i, bd[2].f);
}
}  // namespace n0018f280

// ---- 0018f2a8 from src/anon/batch_w5.cpp
namespace n0018f2a8 {
struct Obj18f { u32 pad; s32 id; };
void func_001863a8(s32, s32, f32) asm("func_001863a8");
void func_0018f2a8(BD_VALUE* bd) asm("func_0018f2a8");
void func_0018f2a8(BD_VALUE* bd) {
    Obj18f* o = (Obj18f*)bd[0].p;
    s32 i = bd[1].i;
    s32 id = o->id;
    func_001863a8(id, i, bd[2].f);
}
}  // namespace n0018f2a8

// ---- 0018f2d0 from src/anon/batch_w1.cpp
namespace n0018f2d0 {
void func_00186378(void*, s32, f32) asm("func_00186378");
void func_0018f2d0(BD_VALUE* bd) asm("func_0018f2d0");
void func_0018f2d0(BD_VALUE* bd) {
    void* o = *(void**)((u8*)bd[0].p + 4);
    s32 i = bd[1].i;
    func_00186378(o, i, bd[2].f);
}
}  // namespace n0018f2d0

// ---- 0018f2f8 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0018f2f8 {
u32 YS__ENEMY__Each(u32, u32, u32, u32) asm("_Z15YS__ENEMY__Eachjjjj");
u32 func_0018f2f8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018f2f8jjjj");
u32 func_0018f2f8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r2 = YS__ENEMY__Each(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n0018f2f8

// ---- 0018f328 (gap trap, written)
namespace n0018f328 {
void func_0018f328(BD_VALUE* bd) asm("func_0018f328");
void func_0018f328(BD_VALUE* bd) {
    bd[0].i = trap_bit_test(*(u32*)((*(u8**)((u8*)bd[0].p + 4)) + 352), 0x200);
}
}  // namespace n0018f328

// ---- 0018f348 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0018f348 {
u32 YS__BTLOBJ__is_damage_motion(u32, u32, u32, u32) asm("_Z28YS__BTLOBJ__is_damage_motionjjjj");
u32 func_0018f348(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018f348jjjj");
u32 func_0018f348(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    r2 = YS__BTLOBJ__is_damage_motion(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n0018f348

// ---- 0018f378 (gap trap, written)
namespace n0018f378 {
void func_0018f378(BD_VALUE* bd) asm("func_0018f378");
void func_0018f378(BD_VALUE* bd) {
}
}  // namespace n0018f378

// ---- 0018f380 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0018f380 {
u32 func_00185de0(u32, u32, u32, u32) asm("_Z13func_00185de0jjjj");
u32 func_0018f380(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018f380jjjj");
u32 func_0018f380(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00185de0(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n0018f380

// ---- 0018f3a8 from src/anon/batch_w37.cpp
namespace n0018f3a8 {
void* YS__ENEMY__Each(void*) asm("YS__ENEMY__Each");
s32 YS__BTLOBJ__is_damage_motion(void*) asm("YS__BTLOBJ__is_damage_motion");
void func_0018f3a8(s32* out) asm("func_0018f3a8");
void func_0018f3a8(s32* out) {
    void* v = 0;
    s32 n = 0;
    while ((v = YS__ENEMY__Each(v)) != 0) {
        if (YS__BTLOBJ__is_damage_motion(v)) n++;
    }
    *out = n;
}
}  // namespace n0018f3a8

// ---- 0018f410 (gap trap, written)
namespace n0018f410 {
void func_0018f410(BD_VALUE* bd) asm("func_0018f410");
void func_0018f410(BD_VALUE* bd) {
    *(f32*)((*(u8**)((u8*)bd[0].p + 4)) + 2804) = bd[1].f;
}
}  // namespace n0018f410

// ---- 0018f428 from src/anon/tiny_auto80_queue.cpp
namespace n0018f428 {
u32 YS__OBJ__is_exist(...) asm("YS__OBJ__is_exist");
void func_0018f428(u32 a0) asm("_Z13func_0018f428j");
void func_0018f428(u32 a0) {
    u32 s1 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 t6 = *(u32*)((u32)t7 + (s32)(4));
    u32 s0 = *(u32*)((u32)t6 + (s32)(2788));
    if (YS__OBJ__is_exist(s0) != 0u) {
        *(u32*)((u32)s1 + (s32)(0)) = s0;
        return;
    }
    u32 t7b = (u32)(0x0035u << 16);
    s0 = *(u32*)((u32)t7b + (s32)(-5816));
    *(u32*)((u32)s1 + (s32)(0)) = s0;
}
}  // namespace n0018f428

// ---- 0018f478 from src/anon/tiny_wrappers_imp.cpp
namespace n0018f478 {
u32 func_001b3cb0(u32, u32, u32, u32) asm("_Z13func_001b3cb0jjjj");
u32 func_0018f478(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018f478jjjj");
u32 func_0018f478(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = *(u32*)((u32)r4 + (s32)(4));
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r14 + (s32)(4));
    r4 = *(u32*)((u32)r15 + (s32)(4));
    return func_001b3cb0(r4, r5, r6, r7);
}
}  // namespace n0018f478

// ---- 0018f4a0 (gap trap, written)
namespace n0018f4a0 {
void func_0018f4a0(BD_VALUE* bd) asm("func_0018f4a0");
void func_0018f4a0(BD_VALUE* bd) {
    bd[0].i = *(u8*)((u8*)bd[0].p + 38);
}
}  // namespace n0018f4a0

// ---- 0018f4b0 (gap trap, written)
namespace n0018f4b0 {
void func_0018f4b0(BD_VALUE* bd) asm("func_0018f4b0");
void func_0018f4b0(BD_VALUE* bd) {
    bd[0].i = *(u8*)((u8*)bd[0].p + 39);
}
}  // namespace n0018f4b0

// ---- 0018f4c0 from src/anon/tiny_auto80_queue.cpp
namespace n0018f4c0 {
u32 func_0018ca48(...) asm("func_0018ca48");
void func_0018f4c0(u32 a0) asm("_Z13func_0018f4c0j");
void func_0018f4c0(u32 a0) {
    u32 s0 = a0;
    u32 t7 = *(u32*)((u32)a0 + (s32)(0));
    u32 v0 = func_0018ca48(*(u8*)((u32)t7 + (s32)(38)));
    if ((u32)(v0 < 2u) != 0u) {
        *(u32*)((u32)s0 + (s32)(0)) = 0u;
    } else {
        *(u32*)((u32)s0 + (s32)(0)) = 1u;
    }
}
}  // namespace n0018f4c0

// ---- 0018f508 (gap trap, written)
namespace n0018f508 {
void func_0018f508(BD_VALUE* bd) asm("func_0018f508");
void func_0018f508(BD_VALUE* bd) {
    bd[0].f = *(s16*)(*(u8**)((u8*)bd[0].p + 32) + 12);
}
}  // namespace n0018f508

// ---- 0018f528 (gap trap, written)
namespace n0018f528 {
void func_0018f528(BD_VALUE* bd) asm("func_0018f528");
void func_0018f528(BD_VALUE* bd) {
    bd[0].f = *(s16*)(*(u8**)((u8*)bd[0].p + 32) + 14);
}
}  // namespace n0018f528

// ---- 0018f548 (gap trap, written)
namespace n0018f548 {
void func_0018f548(BD_VALUE* bd) asm("func_0018f548");
void func_0018f548(BD_VALUE* bd) {
    bd[0].i = *(u8*)(*(u8**)((u8*)bd[0].p + 32) + 4);
}
}  // namespace n0018f548

// ---- 0018f560 (gap trap, written)
namespace n0018f560 {
void func_0018f560(BD_VALUE* bd) asm("func_0018f560");
void func_0018f560(BD_VALUE* bd) {
    *(u32*)((u8*)bd[0].p + 24) |= 1;
}
}  // namespace n0018f560

// ---- 0018f578 (gap trap, written)
namespace n0018f578 {
void func_0018f578(BD_VALUE* bd) asm("func_0018f578");
void func_0018f578(BD_VALUE* bd) {
    bd[0].i = *(u32*)((u8*)bd[0].p + 24) & 1;
}
}  // namespace n0018f578

// ---- 0018f590 (gap trap, written)
namespace n0018f590 {
void func_0018f590(BD_VALUE* bd) asm("func_0018f590");
void func_0018f590(BD_VALUE* bd) {
    bd[0].i = *(u16*)(*(u8**)((u8*)bd[0].p + 32) + 2);
}
}  // namespace n0018f590

// ---- 0018f5a8 (gap trap, written)
namespace n0018f5a8 {
void func_0018f5a8(BD_VALUE* bd) asm("func_0018f5a8");
void func_0018f5a8(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 40);
}
}  // namespace n0018f5a8

// ---- 0018f5b8 (gap trap, written)
namespace n0018f5b8 {
void func_0018f5b8(BD_VALUE* bd) asm("func_0018f5b8");
void func_0018f5b8(BD_VALUE* bd) {
    bd[0].i = *(u8*)((u8*)bd[0].p + 37);
}
}  // namespace n0018f5b8

// ---- 0018f5c8 (gap trap, written)
namespace n0018f5c8 {
void func_0018f5c8(BD_VALUE* bd) asm("func_0018f5c8");
void func_0018f5c8(BD_VALUE* bd) {
    bd[0].i = (u32)(*(u8*)(*(u8**)((u8*)bd[0].p + 32) + 4) - 5) < 2;
}
}  // namespace n0018f5c8

// ---- 0018f5e8 (gap trap, written)
namespace n0018f5e8 {
void func_0018f5e8(BD_VALUE* bd) asm("func_0018f5e8");
void func_0018f5e8(BD_VALUE* bd) {
    bd[0].i = *(u8*)(*(u8**)((u8*)bd[0].p + 32) + 9);
}
}  // namespace n0018f5e8

// ---- 0018f600 from src/ys/traps.cpp
namespace n0018f600 {
f32 YS__DAMAGE__get_hitback(s32) asm("YS__DAMAGE__get_hitback");
void trap_damage_element(BD_VALUE* bd) asm("_ZN2YS19trap_damage_elementEP8BD_VALUE");
void trap_damage_element(BD_VALUE* bd) { bd->f = YS__DAMAGE__get_hitback(bd->i); }
}  // namespace n0018f600

// ---- 0018f630 from src/ys/traps.cpp
namespace n0018f630 {
extern s32 YS_DAMAGE_GetReactionType(s32) asm("_ZN2YS6DAMAGE15GetReactionTypeEi");
void trap_damage_get_reaction_type(BD_VALUE* bd) asm("_ZN2YS29trap_damage_get_reaction_typeEP8BD_VALUE");
void trap_damage_get_reaction_type(BD_VALUE* bd) { bd->i = YS_DAMAGE_GetReactionType(bd->i); }
}  // namespace n0018f630

// ---- 0018f660 from src/ys/traps.cpp
namespace n0018f660 {
extern s32 YS_DAMAGE_is_finish(s32) asm("_ZNK2YS6DAMAGE9is_finishEv");
void trap_damage_is_finish(BD_VALUE* bd) asm("_ZN2YS21trap_damage_is_finishEP8BD_VALUE");
void trap_damage_is_finish(BD_VALUE* bd) { bd->i = YS_DAMAGE_is_finish(bd->i); }
}  // namespace n0018f660

// ---- 0018f690 from src/ys/traps.cpp
namespace n0018f690 {
extern s32 YS_DAMAGE_is_normal(s32) asm("_ZNK2YS6DAMAGE9is_normalEv");
void trap_damage_is_normal(BD_VALUE* bd) asm("_ZN2YS21trap_damage_is_normalEP8BD_VALUE");
void trap_damage_is_normal(BD_VALUE* bd) { bd->i = YS_DAMAGE_is_normal(bd->i); }
}  // namespace n0018f690

// ---- 0018f6c0 from src/anon/auto80_199_queue.cpp
namespace n0018f6c0 {
void func_0018f6c0(u32 a0) asm("_Z13func_0018f6c0j");
void func_0018f6c0(u32 a0) {
    u32 s0 = a0;
    u32 s1 = func_001050d8(320);

    u32 t = *(u32*)s0;
    u32 a2 = *(u32*)(s0 + 4);
    u32 a3 = *(u32*)(s0 + 8);
    u32 t0 = *(u32*)(s0 + 12);
    func_001a4498(s1, *(u32*)(t + 4), a2, a3, t0, 0xffffffffu);
    *(u32*)s0 = s1;
}
}  // namespace n0018f6c0

// ---- 0018f718 from src/anon/auto80_199_queue.cpp
namespace n0018f718 {
void func_0018f718(u32 a0) asm("_Z13func_0018f718j");
void func_0018f718(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)a0;
    if (YS__ATTACK__is_exist(s0) != 0) {
        func_001a49d8(s0, *(f32*)(s1 + 4), *(f32*)(s1 + 8));
    }
}
}  // namespace n0018f718

// ---- 0018f770 from src/anon/batch_w1.cpp
namespace n0018f770 {
void func_001a48c0(s32, s32) asm("func_001a48c0");
void trap_attack_set_pos(BD_VALUE* bd) asm("_ZN2YS19trap_attack_set_posEP8BD_VALUE");
void trap_attack_set_pos(BD_VALUE* bd) {
    s32 a = bd[0].i;
    func_001a48c0(a, bd[1].i);
}
}  // namespace n0018f770

// ---- 0018f790 from src/ys/traps.cpp
namespace n0018f790 {
extern void YS_ATTACK_destroy(s32) asm("_ZN2YS6ATTACK7destroyEv");
void trap_attack_free(BD_VALUE* bd) asm("_ZN2YS16trap_attack_freeEP8BD_VALUE");
void trap_attack_free(BD_VALUE* bd) { YS_ATTACK_destroy(bd->i); }
}  // namespace n0018f790

// ---- 0018f7a8 from src/ys/traps.cpp
namespace n0018f7a8 {
void trap_attack_is_hit(BD_VALUE* bd) asm("_ZN2YS18trap_attack_is_hitEP8BD_VALUE");
void trap_attack_is_hit(BD_VALUE* bd) { bd->i = ((YS::ATTACK*)bd->i)->is_hit(); }
}  // namespace n0018f7a8

// ---- 0018f7d8 from src/ys/traps.cpp
namespace n0018f7d8 {
void func_0018e040(s32) asm("func_0018e040");
void trap_attack_is_hit_bg(BD_VALUE* bd) asm("_ZN2YS21trap_attack_is_hit_bgEP8BD_VALUE");
void trap_attack_is_hit_bg(BD_VALUE* bd) { func_0018e040(bd->i); }
}  // namespace n0018f7d8

// ---- 0018f7f0 (gap trap, written)
namespace n0018f7f0 {
void func_0018f7f0(BD_VALUE* bd) asm("func_0018f7f0");
void func_0018f7f0(BD_VALUE* bd) {
    u32 f = *(u32*)((u8*)bd[0].p + 4);
    bd[0].i = trap_bit_test(f, 8) || trap_bit_test(f, 0x10);
}
}  // namespace n0018f7f0

// ---- 0018f820 (gap trap, written)
namespace n0018f820 {
void func_0018f820(BD_VALUE* bd) asm("func_0018f820");
void func_0018f820(BD_VALUE* bd) {
    *(s32*)((u8*)bd[0].p + 36) = bd[1].i;
}
}  // namespace n0018f820

// ---- 0018f830 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0018f830 {
extern "C" u32 YS_EFFECT_GetSystemPax(u32, u32, u32, u32) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
u32 func_0018f830(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018f830jjjj");
u32 func_0018f830(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = *(u32*)((u32)r4 + (s32)(0));
    r2 = YS_EFFECT_GetSystemPax(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(36)) = r2;
    return r2;
}
}  // namespace n0018f830

// ---- 0018f858 from src/anon/batch_w20.cpp
namespace n0018f858 {
u32 func_001a4550(u32, u32) asm("func_001a4550");
void func_0018f858(u32* p) asm("func_0018f858");
void func_0018f858(u32* p) {
    p[0] = func_001a4550(p[0], p[1]);
}
}  // namespace n0018f858

// ---- 0018f888 (gap trap, written)
namespace n0018f888 {
void func_0018f888(BD_VALUE* bd) asm("func_0018f888");
void func_0018f888(BD_VALUE* bd) {
    bd[0].i = *(u8*)(*(u8**)((u8*)bd[0].p + 40) + 4);
}
}  // namespace n0018f888

// ---- 0018f8a0 from src/anon/batch_w2.cpp
namespace n0018f8a0 {
struct TRAP;
s32 func_0018e0d8(TRAP*, s32) asm("func_0018e0d8");
s32 trap_attack_get_type(BD_VALUE* v) asm("_ZN2YS20trap_attack_get_typeEP8BD_VALUE");
s32 trap_attack_get_type(BD_VALUE* v) {
    TRAP* t = (TRAP*)v[0].p;
    return func_0018e0d8(t, v[1].i);
}
}  // namespace n0018f8a0

// ---- 0018f8c0 (gap trap, written)
namespace n0018f8c0 {
struct HITPOS_0018f8c0 { u32 a, b, c; };
extern u32 D_0034d8a0 asm("D_0034d8a0");
void func_0018f8c0(BD_VALUE* bd) asm("func_0018f8c0");
void func_0018f8c0(BD_VALUE* bd) {
    HITPOS_0018f8c0* h = (HITPOS_0018f8c0*)((u8*)bd[0].p + 140);
    u32 d = D_0034d8a0;
    s32 b = bd[1].i;
    s32 c = bd[2].i;
    h->a = d;
    h->b = b;
    h->c = c;
}
}  // namespace n0018f8c0

// ---- 0018f8e8 (gap trap, written)
namespace n0018f8e8 {
void func_0018f8e8(BD_VALUE* bd) asm("func_0018f8e8");
void func_0018f8e8(BD_VALUE* bd) {
    bd[0].i = trap_bit_test(*(u32*)((u8*)bd[0].p + 4), 0x200);
}
}  // namespace n0018f8e8

// ---- 0018f900 (gap trap, written)
namespace n0018f900 {
void func_0018f900(BD_VALUE* bd) asm("func_0018f900");
void func_0018f900(BD_VALUE* bd) {
    bd[0].i = trap_bit_test(*(u32*)((u8*)bd[0].p + 4), 0x8);
}
}  // namespace n0018f900

// ---- 0018f918 (gap trap, written)
namespace n0018f918 {
void func_0018f918(BD_VALUE* bd) asm("func_0018f918");
void func_0018f918(BD_VALUE* bd) {
    bd[0].i = trap_bit_test(*(u32*)((u8*)bd[0].p + 4), 0x10);
}
}  // namespace n0018f918

// ---- 0018f930 (gap trap, written)
namespace n0018f930 {
void func_0018f930(BD_VALUE* bd) asm("func_0018f930");
void func_0018f930(BD_VALUE* bd) {
    bd[0].p = (u8*)bd[0].p + 176;
}
}  // namespace n0018f930

// ---- 0018f940 from src/anon/batch_w49.cpp
namespace n0018f940 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern s8 D_01c60cf0 asm("D_01c60cf0");
extern Vq D_01c60d00 asm("D_01c60d00");
void func_002fd188(void (*)(void)) asm("func_002fd188");
void func_001900c8(void) asm("func_001900c8");
Vq func_001a4b78(u32) asm("func_001a4b78");
void func_0018f940(u32* p) asm("func_0018f940");
void func_0018f940(u32* p) {
    if (!D_01c60cf0) {
        D_01c60cf0 = 1;
        func_002fd188(func_001900c8);
    }
    D_01c60d00 = func_001a4b78(*p);
    *p = (u32)&D_01c60d00;
}
}  // namespace n0018f940

// ---- 0018f9a8 (gap trap, written)
namespace n0018f9a8 {
void func_0018f9a8(BD_VALUE* bd) asm("func_0018f9a8");
void func_0018f9a8(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 132);
}
}  // namespace n0018f9a8

// ---- 0018f9b8 from src/anon/batch_w18.cpp
namespace n0018f9b8 {
struct Arg18f { void* a; u32 b; u32 c; f32 d; f32 e; };
void YS__ATTACK_MAGIC__set_reaction_command(void*, u32, u32, f32, f32) asm("YS__ATTACK_MAGIC__set_reaction_command");
void func_0018f9b8(Arg18f* p) asm("func_0018f9b8");
void func_0018f9b8(Arg18f* p) {
    void* a = p->a;
    YS__ATTACK_MAGIC__set_reaction_command(a, p->b, p->c, p->d, p->e);
}
}  // namespace n0018f9b8

// ---- 0018f9e8 (gap trap, written)
namespace n0018f9e8 {
void func_0018f9e8(BD_VALUE* bd) asm("func_0018f9e8");
void func_0018f9e8(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 272);
}
}  // namespace n0018f9e8

// ---- 0018f9f8 from src/anon/auto80_199_queue.cpp
namespace n0018f9f8 {
void func_0018f9f8(u32 a0) asm("_Z13func_0018f9f8j");
void func_0018f9f8(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)a0;
    if (YS__ATTACK__is_exist(s0) != 0) {
        func_001a4d70(s0, *(u32*)(s1 + 4));
    }
}
}  // namespace n0018f9f8

// ---- 0018fa50 from src/anon/auto80_199_queue.cpp
namespace n0018fa50 {
void func_0018fa50(u32 a0) asm("_Z13func_0018fa50j");
void func_0018fa50(u32 a0) {
    u32 s1 = a0;
    u32 s0 = *(u32*)a0;
    if (YS__ATTACK__is_exist(s0) != 0) {
        func_001a4d78(s0, *(f32*)(s1 + 4), *(f32*)(s1 + 8), *(f32*)(s1 + 12));
    }
}
}  // namespace n0018fa50

// ---- 0018fab0 from src/anon/batch_w51.cpp
namespace n0018fab0 {
typedef void (*VFn1)(void*, u32);
void YS__OBJ__is_valid(u32) asm("YS__OBJ__is_valid");
u32 YS__ATTACK__strike(u32, void*, u32, u32) asm("YS__ATTACK__strike");
void func_0018ca10(u32) asm("func_0018ca10");
void func_0018fab0(u32* p) asm("func_0018fab0");
void func_0018fab0(u32* p) {
    YS__OBJ__is_valid(*(u32*)(p[1] + 4));
    u8* o = *(u8**)(p[1] + 4);
    u32 r = YS__ATTACK__strike(p[0], o, p[2], p[3]);
    if (r) {
        (*(VFn1*)(*(u8**)o + 100))(o, r);
        func_0018ca10(r);
    }
}
}  // namespace n0018fab0

// ---- 0018fb38 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0018fb38 {
u32 func_0018d940(u32, u32, u32, u32) asm("_Z13func_0018d940jjjj");
u32 func_0018fb38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018fb38jjjj");
u32 func_0018fb38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r15 = *(u32*)((u32)r4 + (s32)(4));
    r4 = *(u32*)((u32)r4 + (s32)(0));
    r5 = *(u32*)((u32)r15 + (s32)(4));
    r2 = func_0018d940(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n0018fb38

// ---- 0018fb70 from src/anon/batch_w2.cpp
namespace n0018fb70 {
void func_001a49a0(u32, u32, u32) asm("func_001a49a0");
void func_0018fb70(u32* v) asm("func_0018fb70");
void func_0018fb70(u32* v) {
    u32 a = v[0];
    func_001a49a0(a, v[1], v[2]);
}
}  // namespace n0018fb70

// ---- 0018fb98 (gap trap, written)
namespace n0018fb98 {
void func_0018fb98(BD_VALUE* bd) asm("func_0018fb98");
void func_0018fb98(BD_VALUE* bd) {
    *(s32*)((u8*)bd[0].p + 36) = *(s32*)((u8*)bd[1].p + 4) + 128;
}
}  // namespace n0018fb98

// ---- 0018fbb0 (gap trap, written)
namespace n0018fbb0 {
void func_0018fbb0(BD_VALUE* bd) asm("func_0018fbb0");
void func_0018fbb0(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 12);
}
}  // namespace n0018fbb0

// ---- 0018fbc0 (gap trap, written)
namespace n0018fbc0 {
void func_0018fbc0(BD_VALUE* bd) asm("func_0018fbc0");
void func_0018fbc0(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 20);
}
}  // namespace n0018fbc0

// ---- 0018fbd0 (gap trap, written)
namespace n0018fbd0 {
void func_0018fbd0(BD_VALUE* bd) asm("func_0018fbd0");
void func_0018fbd0(BD_VALUE* bd) {
    *(u32*)((u8*)bd[0].p + 4) |= 0x40;
}
}  // namespace n0018fbd0

// ---- 0018fbe8 (gap trap, written)
namespace n0018fbe8 {
void func_0018fbe8(BD_VALUE* bd) asm("func_0018fbe8");
void func_0018fbe8(BD_VALUE* bd) {
    bd[0].i = *(u8*)((u8*)bd[0].p + 164);
}
}  // namespace n0018fbe8

// ---- 0018fbf8 from src/ys/traps.cpp
namespace n0018fbf8 {
extern s32 YS_ATTACK_CHECK_NewComboGroup(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
void trap_attack_exec_reflect(BD_VALUE* bd) asm("_ZN2YS24trap_attack_exec_reflectEP8BD_VALUE");
void trap_attack_exec_reflect(BD_VALUE* bd) { bd->i = YS_ATTACK_CHECK_NewComboGroup(); }
}  // namespace n0018fbf8

// ---- 0018fc20 from src/anon/batch_w3.cpp
namespace n0018fc20 {
void trap_attack_set_hitmark_pos(BD_VALUE* bd) asm("_ZN2YS27trap_attack_set_hitmark_posEP8BD_VALUE");
void func_0018e108(s32, s32) asm("func_0018e108");
void trap_attack_set_hitmark_pos(BD_VALUE* bd) asm("_ZN2YS27trap_attack_set_hitmark_posEP8BD_VALUE");
void trap_attack_set_hitmark_pos(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_0018e108(a.i, bd[1].i);
}
}  // namespace n0018fc20

// ---- 0018fc40 (gap trap, written)
namespace n0018fc40 {
struct HITPOS_0018fc40 { u32 a, b, c; };
extern u32 D_0034d8a0 asm("D_0034d8a0");
void func_0018fc40(BD_VALUE* bd) asm("func_0018fc40");
void func_0018fc40(BD_VALUE* bd) {
    HITPOS_0018fc40* h = (HITPOS_0018fc40*)((u8*)bd[0].p + 152);
    u32 d = D_0034d8a0;
    s32 b = bd[1].i;
    s32 c = bd[2].i;
    h->a = d;
    h->b = b;
    h->c = c;
}
}  // namespace n0018fc40

// ---- 0018fc68 (gap trap, written)
namespace n0018fc68 {
void func_0018fc68(BD_VALUE* bd) asm("func_0018fc68");
void func_0018fc68(BD_VALUE* bd) {
    bd[0].i = trap_bit_test(*(u32*)((u8*)bd[0].p + 4), 0x1000);
}
}  // namespace n0018fc68

// ---- 0018fc80 from src/anon/tiny_jal_wrappers_flex.cpp
namespace n0018fc80 {
u32 func_001a6118(u32, u32, u32, u32) asm("_Z13func_001a6118jjjj");
u32 func_0018fc80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0018fc80jjjj");
u32 func_0018fc80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)(0x0035u << 16);
    r7 = (u32)((s32)0u + (1));
    r16 = r4;
    r5 = *(u32*)((u32)r16 + (s32)(0));
    r6 = (u32)((s32)r16 + (4));
    r4 = *(u32*)((u32)r15 + (s32)(-10080));
    r2 = func_001a6118(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(0)) = r2;
    return r2;
}
}  // namespace n0018fc80

// ---- 0018fcc0 from src/anon/batch_w4.cpp
namespace n0018fcc0 {
void func_001a6490(u32, f32) asm("func_001a6490");
struct ArgsUF {
    u32 a;
    f32 f;
};
void func_0018fcc0(ArgsUF* p) asm("func_0018fcc0");
void func_0018fcc0(ArgsUF* p) {
    u32 a = p->a;
    func_001a6490(a, p->f);
}
}  // namespace n0018fcc0

// ---- 0018fce0 from src/ys/traps.cpp
namespace n0018fce0 {
extern s32 YS_MAGIC_CanAddCost(f32) asm("_ZN2YS5MAGIC10CanAddCostEf");
void trap_magic_can_add_cost(BD_VALUE* bd) asm("_ZN2YS23trap_magic_can_add_costEP8BD_VALUE");
void trap_magic_can_add_cost(BD_VALUE* bd) { bd->i = YS_MAGIC_CanAddCost(bd->f); }
}  // namespace n0018fce0

// ---- 0018fd10 from src/anon/batch_w6.cpp
namespace n0018fd10 {
u32 func_001a6a20(u32, u32) asm("func_001a6a20");
void func_0018fd10(u32* p) asm("func_0018fd10");
void func_0018fd10(u32* p) {
    p[0] = func_001a6a20(p[0], p[1]);
}
}  // namespace n0018fd10

// ---- 0018fd40 from src/anon/batch_w6.cpp
namespace n0018fd40 {
void YS__BTLOBJ__exec_reflect_default(u32, u32, u32, u32, f32) asm("YS__BTLOBJ__exec_reflect_default");
void func_0018fd40(u32* p) asm("func_0018fd40");
void func_0018fd40(u32* p) {
    u32 c = p[2];
    u32 b = p[1];
    u32 a = p[0];
    YS__BTLOBJ__exec_reflect_default(a, b, c, p[3], *(f32*)&p[4]);
}
}  // namespace n0018fd40

// ---- 0018fd70 (gap trap, written)
namespace n0018fd70 {
s32 func_001b50b0(s32, s32, s32, f32) asm("func_001b50b0");
void func_0018fd70(BD_VALUE* bd) asm("func_0018fd70");
void func_0018fd70(BD_VALUE* bd) {
    bd[0].i = func_001b50b0(bd[0].i, *(s32*)((u8*)bd[1].p + 4), bd[2].i, bd[3].f);
}
}  // namespace n0018fd70

// ---- 0018fdb0 (gap trap, written)
namespace n0018fdb0 {
void func_0018fdb0(BD_VALUE* bd) asm("func_0018fdb0");
void func_0018fdb0(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 12);
}
}  // namespace n0018fdb0

// ---- 0018fdc0 (gap trap, written)
namespace n0018fdc0 {
void func_0018fdc0(BD_VALUE* bd) asm("func_0018fdc0");
void func_0018fdc0(BD_VALUE* bd) {
    bd[0].i = ((s32*)((u8*)bd[0].p + 16))[bd[1].i];
}
}  // namespace n0018fdc0

// ---- 0018fde0 from src/anon/batch_w7.cpp
namespace n0018fde0 {
void func_001b50e0(u32, u32, f32, u32) asm("func_001b50e0");
struct Args { u32 a; u32 b; f32 c; u32 d; };
void func_0018fde0(Args* a) asm("func_0018fde0");
void func_0018fde0(Args* a) {
    u32 p = a->a;
    func_001b50e0(p, a->b, a->c, a->d != 0);
}
}  // namespace n0018fde0

// ---- 0018fe10 (gap trap, written)
namespace n0018fe10 {
void func_001b58b8(s32, BD_VALUE*, s32) asm("func_001b58b8");
void func_0018fe10(BD_VALUE* bd) asm("func_0018fe10");
void func_0018fe10(BD_VALUE* bd) {
    func_001b58b8(bd[0].i, &bd[1], 1);
}
}  // namespace n0018fe10

// ---- 0018fe38 (gap trap, written)
namespace n0018fe38 {
void func_0018fe38(BD_VALUE* bd) asm("func_0018fe38");
void func_0018fe38(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 56);
}
}  // namespace n0018fe38

// ---- 0018fe48 from src/anon/batch_w21.cpp
namespace n0018fe48 {
u32 func_001b58f0(u32, u32, u32, u32) asm("func_001b58f0");
void func_0018fe48(u32* p) asm("func_0018fe48");
void func_0018fe48(u32* p) {
    p[0] = func_001b58f0(p[0], p[1], p[2], 0);
}
}  // namespace n0018fe48

// ---- 0018fe80 from src/anon/batch_w36.cpp
namespace n0018fe80 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
u8* func_001b58f0(u32, u32, u32, u32) asm("func_001b58f0");
Q16* func_001dc5f8(u8*) asm("func_001dc5f8");
void func_0018fe80(u32* p) asm("func_0018fe80");
void func_0018fe80(u32* p) {
    u8* v = func_001b58f0(p[0], p[1], p[3], 0);
    if (v) {
        Q16* d = func_001dc5f8(v);
        Q16* s = (Q16*)p[2];
        if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
    p[0] = (u32)v;
}
}  // namespace n0018fe80

// ---- 0018fee8 from src/anon/batch_w15.cpp
namespace n0018fee8 {
u32 func_001b58f0(u32, u32, u32, u32) asm("func_001b58f0");
void func_0018fee8(u32* p) asm("func_0018fee8");
void func_0018fee8(u32* p) {
    p[0] = func_001b58f0(p[0], p[1], p[3], ((u32*)p[2])[1]);
}
}  // namespace n0018fee8

// ---- 0018ff28 (gap trap, written)
namespace n0018ff28 {
void func_0018ff28(BD_VALUE* bd) asm("func_0018ff28");
void func_0018ff28(BD_VALUE* bd) {
    bd[0].f = *(f32*)((u8*)bd[0].p + 212);
}
}  // namespace n0018ff28

// ---- 0018ff38 (gap trap, written)
namespace n0018ff38 {
void func_0018ff38(BD_VALUE* bd) asm("func_0018ff38");
void func_0018ff38(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 60);
}
}  // namespace n0018ff38

// ---- 0018ff48 from src/ys/traps.cpp
namespace n0018ff48 {
void func_001b57f8(s32) asm("func_001b57f8");
void trap_limit_reference(BD_VALUE* bd) asm("_ZN2YS20trap_limit_referenceEP8BD_VALUE");
void trap_limit_reference(BD_VALUE* bd) { func_001b57f8(bd->i); }
}  // namespace n0018ff48

// ---- 0018ff60 from src/ys/traps.cpp
namespace n0018ff60 {
extern void YS_LIMIT_close_gauge(s32) asm("_ZN2YS5LIMIT11close_gaugeEv");
void trap_limit_close_gauge(BD_VALUE* bd) asm("_ZN2YS22trap_limit_close_gaugeEP8BD_VALUE");
void trap_limit_close_gauge(BD_VALUE* bd) { YS_LIMIT_close_gauge(bd->i); }
}  // namespace n0018ff60

// ---- 0018ff78 from src/ys/traps.cpp
namespace n0018ff78 {
extern void YS_BONUSLEVEL_Up(s32) asm("_ZN2YS10BONUSLEVEL2UpEi");
void trap_bonuslevel_up(BD_VALUE* bd) asm("_ZN2YS18trap_bonuslevel_upEP8BD_VALUE");
void trap_bonuslevel_up(BD_VALUE* bd) { YS_BONUSLEVEL_Up(bd->i); }
}  // namespace n0018ff78

// ---- 0018ff90 from src/ys/traps.cpp
namespace n0018ff90 {
extern s32 YS_SUMMON_IsTinkExist(void) asm("_ZN2YS6SUMMON11IsTinkExistEv");
void trap_summon_is_tink_exist(BD_VALUE* bd) asm("_ZN2YS25trap_summon_is_tink_existEP8BD_VALUE");
void trap_summon_is_tink_exist(BD_VALUE* bd) { bd->i = YS_SUMMON_IsTinkExist(); }
}  // namespace n0018ff90

// ---- 0018ffb8 from src/anon/tiny_auto80_queue.cpp
namespace n0018ffb8 {
u32 func_001050d8(...) asm("func_001050d8");
u32 func_001d37a0(...) asm("func_001d37a0");
void func_0018ffb8(u32 a0) asm("_Z13func_0018ffb8j");
void func_0018ffb8(u32 a0) {
    u32 s0 = a0;
    u32 s1 = func_001050d8(64u);
    ((void(*)(u32, u32, f32))func_001d37a0)(s1, *(u32*)((u32)s0 + (s32)(0)), *(f32*)((u32)s0 + (s32)(4)));
    *(u32*)((u32)s0 + (s32)(0)) = s1;
}
}  // namespace n0018ffb8

// ---- 00190000 from src/anon/tiny_auto80_queue.cpp
namespace n00190000 {
u32 func_00105110(...) asm("func_00105110");
u32 func_001d3878(...) asm("func_001d3878");
void func_00190000(u32 a0) asm("_Z13func_00190000j");
void func_00190000(u32 a0) {
    u32 r4 = a0, r16;
    r16 = *(u32*)((u32)r4 + (s32)(0));
    r4 = r16;
    if (r16 != 0u) {
    u32 (*fp_call4_001d3878)(u32) = (u32(*)(u32))func_001d3878;
        ((void(*)(u32))fp_call4_001d3878)(r4);
        r4 = r16;
    u32 (*fp_call4_00105110)(u32) = (u32(*)(u32))func_00105110;
        ((void(*)(u32))fp_call4_00105110)(r4);
    }
}
}  // namespace n00190000

// ---- 00190038 (gap trap, written)
namespace n00190038 {
void func_00190038(BD_VALUE* bd) asm("func_00190038");
void func_00190038(BD_VALUE* bd) {
    *(u32*)((u8*)bd[0].p + 16) |= 1 << bd[1].i;
}
}  // namespace n00190038

// ---- 00190058 (gap trap, written)
namespace n00190058 {
struct Q_00190058 {
    u32 w[4];
    Q_00190058& operator=(const Q_00190058& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_00190058(BD_VALUE* bd) asm("func_00190058");
void func_00190058(BD_VALUE* bd) {
    *(Q_00190058*)bd[0].p = *(Q_00190058*)bd[1].p;
}
}  // namespace n00190058

// ---- 00190078 (gap trap, written)
namespace n00190078 {
void func_00190078(BD_VALUE* bd) asm("func_00190078");
void func_00190078(BD_VALUE* bd) {
    u8* o = (u8*)bd[0].p;
    f32 x = bd[1].f;
    f32 y = bd[2].f;
    f32 z = bd[3].f;
    *(f32*)(o + 24) = x;
    *(f32*)(o + 28) = y;
    *(f32*)(o + 32) = z;
}
}  // namespace n00190078

// ---- 00190098 (gap trap, written)
namespace n00190098 {
void func_00190098(BD_VALUE* bd) asm("func_00190098");
void func_00190098(BD_VALUE* bd) {
    *(f32*)((u8*)bd[0].p + 36) = bd[1].f;
}
}  // namespace n00190098

// ---- 001900a8 (gap trap, written)
namespace n001900a8 {
void func_001900a8(BD_VALUE* bd) asm("func_001900a8");
void func_001900a8(BD_VALUE* bd) {
    *(f32*)((u8*)bd[0].p + 40) = bd[1].f;
}
}  // namespace n001900a8

// ---- 001900b8 (gap trap, written)
namespace n001900b8 {
void func_001900b8(BD_VALUE* bd) asm("func_001900b8");
void func_001900b8(BD_VALUE* bd) {
    *(f32*)((u8*)bd[0].p + 44) = bd[1].f;
}
}  // namespace n001900b8

// ---- 001900c8 (gap trap, written)
namespace n001900c8 {
// __tcf_0 of the local static used by 0x18f940 (empty destructor)
void func_001900c8(void) asm("func_001900c8");
void func_001900c8(void) {
}
}  // namespace n001900c8


// ---- trap table (.data 0x34ef30): function, argument flags
namespace ntraptable {
struct TRAP { void (*fn)(BD_VALUE*); u32 flags; };
void t_0018f218(BD_VALUE*) asm("func_0018f218");
void t_0018f248(BD_VALUE*) asm("func_0018f248");
void t_0018f2a8(BD_VALUE*) asm("func_0018f2a8");
void t_0018f2d0(BD_VALUE*) asm("func_0018f2d0");
void t_0018f2f8(BD_VALUE*) asm("_Z13func_0018f2f8jjjj");
void t_0018f328(BD_VALUE*) asm("func_0018f328");
void t_0018f348(BD_VALUE*) asm("_Z13func_0018f348jjjj");
void t_0018f4a0(BD_VALUE*) asm("func_0018f4a0");
void t_0018f4c0(BD_VALUE*) asm("_Z13func_0018f4c0j");
void t_0018f1c0(BD_VALUE*) asm("_ZN2YS21trap_btlobj_set_sheetEP8BD_VALUE");
void t_0018f6c0(BD_VALUE*) asm("_Z13func_0018f6c0j");
void t_0018f718(BD_VALUE*) asm("_Z13func_0018f718j");
void t_0018f770(BD_VALUE*) asm("_ZN2YS19trap_attack_set_posEP8BD_VALUE");
void t_0018f790(BD_VALUE*) asm("_ZN2YS16trap_attack_freeEP8BD_VALUE");
void t_0018f7a8(BD_VALUE*) asm("_ZN2YS18trap_attack_is_hitEP8BD_VALUE");
void t_0018f560(BD_VALUE*) asm("func_0018f560");
void t_0018f578(BD_VALUE*) asm("func_0018f578");
void t_0018fab0(BD_VALUE*) asm("func_0018fab0");
void t_0018fb38(BD_VALUE*) asm("_Z13func_0018fb38jjjj");
void t_0018fb70(BD_VALUE*) asm("func_0018fb70");
void t_0018fc80(BD_VALUE*) asm("_Z13func_0018fc80jjjj");
void t_0018fd10(BD_VALUE*) asm("func_0018fd10");
void t_0018fb98(BD_VALUE*) asm("func_0018fb98");
void t_0018f140(BD_VALUE*) asm("func_0018f140");
void t_0018fbb0(BD_VALUE*) asm("func_0018fbb0");
void t_0018fbc0(BD_VALUE*) asm("func_0018fbc0");
void t_0018fbd0(BD_VALUE*) asm("func_0018fbd0");
void t_0018fd40(BD_VALUE*) asm("func_0018fd40");
void t_0018f7d8(BD_VALUE*) asm("_ZN2YS21trap_attack_is_hit_bgEP8BD_VALUE");
void t_0018f7f0(BD_VALUE*) asm("func_0018f7f0");
void t_0018f820(BD_VALUE*) asm("func_0018f820");
void t_0018f858(BD_VALUE*) asm("func_0018f858");
void t_0018f508(BD_VALUE*) asm("func_0018f508");
void t_0018f528(BD_VALUE*) asm("func_0018f528");
void t_0018f888(BD_VALUE*) asm("func_0018f888");
void t_0018f548(BD_VALUE*) asm("func_0018f548");
void t_0018f378(BD_VALUE*) asm("func_0018f378");
void t_0018f8a0(BD_VALUE*) asm("_ZN2YS20trap_attack_get_typeEP8BD_VALUE");
void t_0018f8c0(BD_VALUE*) asm("func_0018f8c0");
void t_0018f8e8(BD_VALUE*) asm("func_0018f8e8");
void t_0018f900(BD_VALUE*) asm("func_0018f900");
void t_0018f918(BD_VALUE*) asm("func_0018f918");
void t_0018f930(BD_VALUE*) asm("func_0018f930");
void t_0018f940(BD_VALUE*) asm("func_0018f940");
void t_0018f9a8(BD_VALUE*) asm("func_0018f9a8");
void t_0018f590(BD_VALUE*) asm("func_0018f590");
void t_0018f5a8(BD_VALUE*) asm("func_0018f5a8");
void t_0018fd70(BD_VALUE*) asm("func_0018fd70");
void t_0018fdb0(BD_VALUE*) asm("func_0018fdb0");
void t_0018fdc0(BD_VALUE*) asm("func_0018fdc0");
void t_0018fde0(BD_VALUE*) asm("func_0018fde0");
void t_0018f9b8(BD_VALUE*) asm("func_0018f9b8");
void t_0018f9e8(BD_VALUE*) asm("func_0018f9e8");
void t_0018f380(BD_VALUE*) asm("_Z13func_0018f380jjjj");
void t_0018fe10(BD_VALUE*) asm("func_0018fe10");
void t_0018fe38(BD_VALUE*) asm("func_0018fe38");
void t_0018f200(BD_VALUE*) asm("func_0018f200");
void t_0018fe48(BD_VALUE*) asm("func_0018fe48");
void t_0018fe80(BD_VALUE*) asm("func_0018fe80");
void t_0018fee8(BD_VALUE*) asm("func_0018fee8");
void t_0018ff28(BD_VALUE*) asm("func_0018ff28");
void t_0018f9f8(BD_VALUE*) asm("_Z13func_0018f9f8j");
void t_0018fa50(BD_VALUE*) asm("_Z13func_0018fa50j");
void t_0018ff38(BD_VALUE*) asm("func_0018ff38");
void t_0018f4b0(BD_VALUE*) asm("func_0018f4b0");
void t_0018f3a8(BD_VALUE*) asm("func_0018f3a8");
void t_0018fbe8(BD_VALUE*) asm("func_0018fbe8");
void t_0018fbf8(BD_VALUE*) asm("_ZN2YS24trap_attack_exec_reflectEP8BD_VALUE");
void t_0018fcc0(BD_VALUE*) asm("func_0018fcc0");
void t_0018fce0(BD_VALUE*) asm("_ZN2YS23trap_magic_can_add_costEP8BD_VALUE");
void t_0018f5b8(BD_VALUE*) asm("func_0018f5b8");
void t_0018fc20(BD_VALUE*) asm("_ZN2YS27trap_attack_set_hitmark_posEP8BD_VALUE");
void t_0018f5c8(BD_VALUE*) asm("func_0018f5c8");
void t_0018ff78(BD_VALUE*) asm("_ZN2YS18trap_bonuslevel_upEP8BD_VALUE");
void t_0018fc40(BD_VALUE*) asm("func_0018fc40");
void t_0018ff90(BD_VALUE*) asm("_ZN2YS25trap_summon_is_tink_existEP8BD_VALUE");
void t_0018f410(BD_VALUE*) asm("func_0018f410");
void t_0018ffb8(BD_VALUE*) asm("_Z13func_0018ffb8j");
void t_00190000(BD_VALUE*) asm("_Z13func_00190000j");
void t_00190038(BD_VALUE*) asm("func_00190038");
void t_00190058(BD_VALUE*) asm("func_00190058");
void t_00190078(BD_VALUE*) asm("func_00190078");
void t_00190098(BD_VALUE*) asm("func_00190098");
void t_001900a8(BD_VALUE*) asm("func_001900a8");
void t_001900b8(BD_VALUE*) asm("func_001900b8");
void t_0018f5e8(BD_VALUE*) asm("func_0018f5e8");
void t_0018f600(BD_VALUE*) asm("_ZN2YS19trap_damage_elementEP8BD_VALUE");
void t_0018f280(BD_VALUE*) asm("func_0018f280");
void t_0018f428(BD_VALUE*) asm("_Z13func_0018f428j");
void t_0018ff48(BD_VALUE*) asm("_ZN2YS20trap_limit_referenceEP8BD_VALUE");
void t_0018ff60(BD_VALUE*) asm("_ZN2YS22trap_limit_close_gaugeEP8BD_VALUE");
void t_0018f630(BD_VALUE*) asm("_ZN2YS29trap_damage_get_reaction_typeEP8BD_VALUE");
void t_0018f660(BD_VALUE*) asm("_ZN2YS21trap_damage_is_finishEP8BD_VALUE");
void t_0018f690(BD_VALUE*) asm("_ZN2YS21trap_damage_is_normalEP8BD_VALUE");
void t_0018f830(BD_VALUE*) asm("_Z13func_0018f830jjjj");
void t_0018f1e0(BD_VALUE*) asm("_Z13func_0018f1e0jjjj");
void t_0018fc68(BD_VALUE*) asm("func_0018fc68");
void t_0018f478(BD_VALUE*) asm("_Z13func_0018f478jjjj");
}  // namespace ntraptable
ntraptable::TRAP D_0034ef30[98] asm("D_0034ef30") = {
    { ntraptable::t_0018f218, 0x2 },
    { ntraptable::t_0018f248, 0x6 },
    { ntraptable::t_0018f2a8, 0x3 },
    { ntraptable::t_0018f2d0, 0x3 },
    { ntraptable::t_0018f2f8, 0x40000001 },
    { ntraptable::t_0018f328, 0x40000001 },
    { ntraptable::t_0018f348, 0x40000001 },
    { ntraptable::t_0018f4a0, 0x40000001 },
    { ntraptable::t_0018f4c0, 0x40000001 },
    { ntraptable::t_0018f1c0, 0x3 },
    { ntraptable::t_0018f6c0, 0x40000004 },
    { ntraptable::t_0018f718, 0x3 },
    { ntraptable::t_0018f770, 0x2 },
    { ntraptable::t_0018f790, 0x1 },
    { ntraptable::t_0018f7a8, 0x40000001 },
    { ntraptable::t_0018f560, 0x1 },
    { ntraptable::t_0018f578, 0x40000001 },
    { ntraptable::t_0018fab0, 0x4 },
    { ntraptable::t_0018fb38, 0x40000002 },
    { ntraptable::t_0018fb70, 0x3 },
    { ntraptable::t_0018fc80, 0x40000002 },
    { ntraptable::t_0018fd10, 0x40000002 },
    { ntraptable::t_0018fb98, 0x2 },
    { ntraptable::t_0018f140, 0x40000001 },
    { ntraptable::t_0018fbb0, 0x40000001 },
    { ntraptable::t_0018fbc0, 0x40000001 },
    { ntraptable::t_0018fbd0, 0x1 },
    { ntraptable::t_0018fd40, 0x5 },
    { ntraptable::t_0018f7d8, 0x1 },
    { ntraptable::t_0018f7f0, 0x40000001 },
    { ntraptable::t_0018f820, 0x2 },
    { ntraptable::t_0018f858, 0x40000002 },
    { ntraptable::t_0018f508, 0x40000001 },
    { ntraptable::t_0018f528, 0x40000001 },
    { ntraptable::t_0018f888, 0x40000001 },
    { ntraptable::t_0018f548, 0x40000001 },
    { ntraptable::t_0018f378, 0x2 },
    { ntraptable::t_0018f8a0, 0x2 },
    { ntraptable::t_0018f8c0, 0x3 },
    { ntraptable::t_0018f8e8, 0x40000001 },
    { ntraptable::t_0018f900, 0x40000001 },
    { ntraptable::t_0018f918, 0x40000001 },
    { ntraptable::t_0018f930, 0x40000001 },
    { ntraptable::t_0018f940, 0x40000001 },
    { ntraptable::t_0018f9a8, 0x40000001 },
    { ntraptable::t_0018f590, 0x40000001 },
    { ntraptable::t_0018f5a8, 0x40000001 },
    { ntraptable::t_0018fd70, 0x40000004 },
    { ntraptable::t_0018fdb0, 0x40000001 },
    { ntraptable::t_0018fdc0, 0x40000002 },
    { ntraptable::t_0018fde0, 0x4 },
    { ntraptable::t_0018f9b8, 0x5 },
    { ntraptable::t_0018f9e8, 0x40000001 },
    { ntraptable::t_0018f380, 0x40000000 },
    { ntraptable::t_0018fe10, 0x2 },
    { ntraptable::t_0018fe38, 0x40000001 },
    { ntraptable::t_0018f200, 0x40000001 },
    { ntraptable::t_0018fe48, 0x40000003 },
    { ntraptable::t_0018fe80, 0x40000004 },
    { ntraptable::t_0018fee8, 0x40000004 },
    { ntraptable::t_0018ff28, 0x40000001 },
    { ntraptable::t_0018f9f8, 0x2 },
    { ntraptable::t_0018fa50, 0x4 },
    { ntraptable::t_0018ff38, 0x40000001 },
    { ntraptable::t_0018f4b0, 0x40000001 },
    { ntraptable::t_0018f3a8, 0x40000000 },
    { ntraptable::t_0018fbe8, 0x40000001 },
    { ntraptable::t_0018fbf8, 0x40000000 },
    { ntraptable::t_0018fcc0, 0x2 },
    { ntraptable::t_0018fce0, 0x40000001 },
    { ntraptable::t_0018f5b8, 0x40000001 },
    { ntraptable::t_0018fc20, 0x2 },
    { ntraptable::t_0018f5c8, 0x40000001 },
    { ntraptable::t_0018ff78, 0x1 },
    { ntraptable::t_0018fc40, 0x3 },
    { ntraptable::t_0018ff90, 0x40000000 },
    { ntraptable::t_0018f410, 0x2 },
    { ntraptable::t_0018ffb8, 0x40000002 },
    { ntraptable::t_00190000, 0x1 },
    { ntraptable::t_00190038, 0x2 },
    { ntraptable::t_00190058, 0x2 },
    { ntraptable::t_00190078, 0x4 },
    { ntraptable::t_00190098, 0x2 },
    { ntraptable::t_001900a8, 0x2 },
    { ntraptable::t_001900b8, 0x2 },
    { ntraptable::t_0018f5e8, 0x40000001 },
    { ntraptable::t_0018f600, 0x40000001 },
    { ntraptable::t_0018f280, 0x3 },
    { ntraptable::t_0018f428, 0x40000001 },
    { ntraptable::t_0018ff48, 0x1 },
    { ntraptable::t_0018ff60, 0x1 },
    { ntraptable::t_0018f630, 0x40000001 },
    { ntraptable::t_0018f660, 0x40000001 },
    { ntraptable::t_0018f690, 0x40000001 },
    { ntraptable::t_0018f830, 0x1 },
    { ntraptable::t_0018f1e0, 0x2 },
    { ntraptable::t_0018fc68, 0x40000001 },
    { ntraptable::t_0018f478, 0x2 },
};
