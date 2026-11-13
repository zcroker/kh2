#include "../../common/types.h"

// kn script traps (0x2f0700-0x2f12b0). Linked unit; the trap table is .data at 0x363a40
// and the vector the vector traps return is .bss at 0x1e2c0c0.

namespace kn {

struct FVector {
    f32 x, y, z, w;
    FVector() {}
    ~FVector() {}
    FVector& operator=(const FVector& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

}  // namespace kn

extern "C" {
void func_00117808(void*, s32);
void func_001178b8(kn::FVector*, void*);
s32 func_00117970(void*, s32, s32, s32, s32, s32, s32, s32);
void func_00117aa8(void*, s32);
void func_00118d10(void*, s32);
void func_00119830(void*, s32);
void func_00119e60(void*, s32);
s32 func_00119f08(void*);
void func_0011a900(kn::FVector*, void*);
void func_0011a918(void*, s32);
void func_0011a938(void*, s32, f32, f32);
void* func_0010c7b0(void*);
void func_0010cbc8(void*, s32, s32, s32);
void func_0010f960(void*);
kn::FVector* func_0010fa28(void*);
kn::FVector* func_0010fa58(void*);
void func_00110500(void*);
void func_00111000(void*, f32);
void func_00111020(void*);
void func_001125d8(void*, s32, s32);
kn::FVector* func_001127a0(void*);
void* func_00112a58(s32);
void func_00112c58(void*);
s32 func_00112c70(void*);
void func_001133f8(void*);
void func_00113408(void*);
void func_00113420(void*);
void func_00113438(void*);
void func_00113450(void*, s32, s32);
s32 func_00114438(void*, s32);
void func_00136158(void*, s32);
s32 func_001362a0(void*, s32);
void func_0016c568(void*, s32, f32);
void func_0017f5f8(void*, s32, s32, f32, f32);
s32 func_0017fdc0(void*, void*);
s32 func_00186d18(void*);
void func_002e9fb8(void*, s32);
}

void* Friend_getPersonality(void*) asm("_ZN2kn6Friend14getPersonalityEv");
void Friend_setLastAction(void*, void*, void*) asm("_ZN2kn6Friend13setLastActionEPNS_12FriendActionEPv");
void Friend_followEnemy(void*) asm("_ZN2kn6Friend11followEnemyEv");
s32 Peterpan_receiveNotifyPlayerTarget(void*) asm("_ZN2kn8Peterpan25receiveNotifyPlayerTargetEv");
void Peterpan_acceptNotifyPlayerTarget(void*) asm("_ZN2kn8Peterpan24acceptNotifyPlayerTargetEv");
s32 Friend_isEquipedAbility(void*, s32, s32) asm("_Z16ctarget_0010f7b0jjjj");
void Friend_disableInertia(void*) asm("_Z16wtarget_0010f918jjjj");
void Friend_removePlayerAttacker(void*, s32) asm("_Z16u_tail4_001128d0jjjj");
s32 ATTACK_is_finish(void*) asm("_ZNK2YS6ATTACK9is_finishEv");
void STDOBJ_set_special_command(void*, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void Friend_getTargetLastPosition(void*) asm("_Z16wtarget_00198970jjjj");

static kn::FVector s_ret;

// The object in bd[0] (its +4 is the game object).
#define OBJ(bd) (*(u8**)((u8*)(bd)[0].p + 4))

static inline bool test(u32 v, u32 m) { return (v & m) != 0; }

namespace kn {

static void trap_2f0700(BD_VALUE* bd) {}

void trap_empty_func(BD_VALUE* bd) {
    func_00117808(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

static void trap_2f0740(BD_VALUE* bd) {
    FVector t;
    func_001178b8(&t, Friend_getPersonality(OBJ(bd)));
    s_ret = t;
    bd[0].p = &s_ret;
}

}  // namespace kn

extern "C" {

void func_002f0798(BD_VALUE* bd) {
    void* p = Friend_getPersonality(OBJ(bd));
    (*(void (**)(void*))(*(u8**)p + 40))(p);
}

void func_002f07c8(BD_VALUE* bd) {
    void* p = Friend_getPersonality(OBJ(bd));
    (*(void (**)(void*))(*(u8**)p + 44))(p);
}

void func_002f07f8(BD_VALUE* bd) {
    kn::FVector t;
    func_0011a900(&t, Friend_getPersonality(OBJ(bd)));
    s_ret = t;
    bd[0].p = &s_ret;
}

}

namespace kn {

void trap_obj_set_special_command(BD_VALUE* bd) {
    STDOBJ_set_special_command(OBJ(bd), bd[1].i);
}

void trap_friend_get_target_last_position(BD_VALUE* bd) {
    Friend_getTargetLastPosition(OBJ(bd));
}

static void trap_2f0890(BD_VALUE* bd) {
    s_ret = *func_001127a0(OBJ(bd));
    bd[0].p = &s_ret;
}

void trap_genie_change_form(BD_VALUE* bd) {
    func_00119e60(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

static void trap_2f0910(BD_VALUE* bd) {
    bd[0].i = func_00119f08(Friend_getPersonality(OBJ(bd)));
}

}  // namespace kn

extern "C" void func_002f0948(BD_VALUE* bd) {
    u8* o = OBJ(bd);
    func_0016c568(o, bd[1].i, bd[2].f);
}

namespace kn {

void trap_stitch_effect_start(BD_VALUE* bd) {
    void* p = Friend_getPersonality(OBJ(bd));
    bd[0].i = func_00117970(p, bd[1].i, bd[2].p ? *(s32*)((u8*)bd[2].p + 4) : 0, bd[3].i, bd[4].i,
                            bd[5].i != 0, bd[6].i, bd[7].i);
}

void trap_stitch_shot_effect(BD_VALUE* bd) {
    func_00119830(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

static void trap_2f0a10(BD_VALUE* bd) {
    u8* o = OBJ(bd);
    func_001125d8(o, bd[1].i, bd[2].i);
}

}  // namespace kn

extern "C" void func_002f0a38(BD_VALUE* bd) {
    func_0017f5f8((u8*)bd[0].p + 320, bd[1].i, 0, bd[2].f, 0.0f);
}

namespace kn {

void trap_stitch_effect_kill(BD_VALUE* bd) {
    func_00117aa8(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

static void trap_2f0aa0(BD_VALUE* bd) {
    bd[0].i = test(*(u32*)((u8*)bd[0].p + 1416), 0x800);
}

static void trap_2f0ab8(BD_VALUE* bd) {
    bd[0].i = test(*(u32*)((u8*)bd[0].p + 1416), 0x400);
}

static void trap_2f0ad0(BD_VALUE* bd) {
    bd[0].i = test(*(u32*)((u8*)bd[0].p + 268), 0x10000);
}

}  // namespace kn

extern "C" {

void func_002f0af0(BD_VALUE* bd) {
    u8* o = OBJ(bd);
    func_00110500(o);
    *(kn::FVector*)(o + 16) = *func_0010fa28(o);
    *(kn::FVector*)(o + 32) = *func_0010fa58(o);
}

void func_002f0b60(BD_VALUE* bd) {
    u8* o = OBJ(bd);
    Friend_followEnemy(o);
    *(kn::FVector*)(o + 16) = *func_0010fa28(o);
    *(kn::FVector*)(o + 32) = *func_0010fa58(o);
}

}

namespace kn {

static void trap_2f0bd0(BD_VALUE* bd) {
    u8* t = *(u8**)((u8*)bd[0].p + 12);
    s32 r = 0;
    if (t) r = test(*(u32*)(t + 8), 0x40);
    bd[0].i = r;
}

static void trap_2f0bf8(BD_VALUE* bd) {
    bd[0].i = *(s32*)(OBJ(bd) + 2788) == *(s32*)((u8*)bd[1].p + 4);
}

void tarp_friend_is_equiped_ability(BD_VALUE* bd) {
    bd[0].i = Friend_isEquipedAbility(OBJ(bd), bd[1].i, -1);
}

void trap_peterpan_receive_notify_player_target(BD_VALUE* bd) {
    bd[0].i = Peterpan_receiveNotifyPlayerTarget(Friend_getPersonality(OBJ(bd)));
}

void trap_peterpan_accept_notify_player_target(BD_VALUE* bd) {
    void* p = Friend_getPersonality(OBJ(bd));
    if (Peterpan_receiveNotifyPlayerTarget(p))
        Peterpan_acceptNotifyPlayerTarget(p);
}

void trap_friend_disable_inertia(BD_VALUE* bd) {
    Friend_disableInertia(OBJ(bd));
}

static void trap_2f0d00(BD_VALUE* bd) {
    func_0010f960(OBJ(bd));
}

static void trap_2f0d20(BD_VALUE* bd) {
    func_0010cbc8(OBJ(bd), bd[1].i, *(s32*)((u8*)bd[2].p + 4), bd[3].i);
}

static void trap_2f0d50(BD_VALUE* bd) {
    u8* o = (u8*)bd[0].p;
    u8* t = *(u8**)(o + 12);
    s32 r = 0;
    if (t && (*(u32*)(t + 8) & 0x40))
        r = test(*(u32*)(o + 268), 0x20000);
    bd[0].i = r;
}

static void trap_2f0d88(BD_VALUE* bd) {
    bd[0].i = test(*(u32*)((u8*)bd[0].p + 1416), 0x400000);
}

void trap_friend_get_player_attacker(BD_VALUE* bd) {
    func_00118d10(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

static void trap_2f0de0(BD_VALUE* bd) {
    s32 add = bd[0].p != 0;
    void* p = func_00112a58(-1);
    bd[0].p = p;
    if (add)
        Friend_removePlayerAttacker(p, 1);
}

void trap_friend_remove_player_attacker(BD_VALUE* bd) {
    Friend_removePlayerAttacker(bd[0].p, bd[1].i != 0);
}

void trap_friend_get_action_param(BD_VALUE* bd) {
    bd[0].i = func_00114438(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

static void trap_2f0ea0(BD_VALUE* bd) {
    u32 f = *(u32*)(OBJ(bd) + 352);
    s32 r = 0;
    if (test(f, 4) || test(f, 8) || test(f, 0x10))
        r = 1;
    bd[0].i = r;
}

static void trap_2f0ee0(BD_VALUE* bd) {
    bd[0].i = test(*(u32*)(OBJ(bd) + 352), 0x40000000);
}

void trap_attack_is_finish(BD_VALUE* bd) {
    bd[0].i = ATTACK_is_finish(bd[0].p);
}

void trap_friend_action_clear(BD_VALUE* bd) {
    Friend_setLastAction(OBJ(bd), 0, 0);
}

static void trap_2f0f58(BD_VALUE* bd) {
    bd[0].i = func_0017fdc0(OBJ(bd) + 320, OBJ(bd + 1) + 320);
}

void trap_friend_is_start_leave(BD_VALUE* bd) {
    func_00112c58(OBJ(bd));
}

static void trap_2f0fb8(BD_VALUE* bd) {
    bd[0].i = func_00112c70(OBJ(bd));
}

static void trap_2f0fe8(BD_VALUE* bd) {
    s32 v = bd[1].i;
    *(u8*)(OBJ(bd) + 2804) = v;
}

static void trap_2f1000(BD_VALUE* bd) {
    u8* t = *(u8**)(OBJ(bd) + 12);
    bd[0].i = test(*(u32*)(t + 8), 0x10);
}

static void trap_2f1020(BD_VALUE* bd) {
    bd[0].f = *(f32*)((u8*)bd[0].p + 436);
}

void trap_friend_disable_follow_enemy(BD_VALUE* bd) {
    func_001133f8(OBJ(bd));
}

static void trap_2f1050(BD_VALUE* bd) {
    func_00113408(OBJ(bd));
}

static void trap_2f1070(BD_VALUE* bd) {
    func_00113420(OBJ(bd));
}

static void trap_2f1090(BD_VALUE* bd) {
    func_00113438(OBJ(bd));
}

static void trap_2f10b0(BD_VALUE* bd) {
    bd[0].i = *(s32*)((u8*)bd[0].p + 384);
}

}  // namespace kn

extern "C" void func_002f10c0(BD_VALUE* bd) {
    void* p = Friend_getPersonality(OBJ(bd));
    s32 i = bd[1].i;
    func_0011a938(p, i, bd[2].f, bd[3].f);
}

namespace kn {

static void trap_2f1100(BD_VALUE* bd) {
    bd[0].i = func_00186d18(OBJ(bd));
}

void trap_btlobj_is_reflect_motion(BD_VALUE* bd) {
    func_00136158(func_0010c7b0(OBJ(bd)), bd[1].i);
}

static void trap_2f1168(BD_VALUE* bd) {
    bd[0].i = func_001362a0(func_0010c7b0(OBJ(bd)), bd[1].i) >= 0;
}

void trap_target_searcher_set_check_hide_from_friend(BD_VALUE* bd) {
    func_002e9fb8(bd[0].p, bd[1].i != 0);
}

void trap_friend_invalidate_warp_point(BD_VALUE* bd) {
    func_00111000(bd[0].p, bd[1].f);
}

static void trap_2f11f0(BD_VALUE* bd) {
    func_00111020(bd[0].p);
}

void trap_friend_add_warp_point(BD_VALUE* bd) {
    u8* o = OBJ(bd);
    func_00113450(o, bd[1].i, bd[2].i);
}

void trap_chickenlittle_set_shoot_target(BD_VALUE* bd) {
    func_0011a918(Friend_getPersonality(OBJ(bd)), bd[1].i);
}

struct TRAP { void (*fn)(BD_VALUE*); u32 flags; };

}  // namespace kn

extern "C" {
kn::TRAP D_00363a40[60] = {
    { kn::trap_2f0700, 0 },
    { kn::trap_empty_func, 2 },
    { kn::trap_2f0740, 0x40000001 },
    { func_002f0798, 1 },
    { func_002f07c8, 1 },
    { func_002f07f8, 0x40000001 },
    { kn::trap_obj_set_special_command, 2 },
    { kn::trap_friend_get_target_last_position, 1 },
    { kn::trap_2f0890, 0x40000001 },
    { kn::trap_genie_change_form, 2 },
    { kn::trap_2f0910, 0x40000001 },
    { func_002f0948, 3 },
    { kn::trap_stitch_effect_start, 0x40000008 },
    { kn::trap_stitch_shot_effect, 2 },
    { kn::trap_2f0a10, 3 },
    { func_002f0a38, 3 },
    { kn::trap_stitch_effect_kill, 2 },
    { kn::trap_2f0aa0, 0x40000001 },
    { kn::trap_2f0ab8, 0x40000001 },
    { kn::trap_2f0ad0, 0x40000001 },
    { func_002f0af0, 1 },
    { func_002f0b60, 1 },
    { kn::trap_2f0bd0, 0x40000001 },
    { kn::trap_2f0bf8, 0x40000002 },
    { kn::tarp_friend_is_equiped_ability, 0x40000002 },
    { kn::trap_peterpan_receive_notify_player_target, 0x40000001 },
    { kn::trap_peterpan_accept_notify_player_target, 1 },
    { kn::trap_friend_disable_inertia, 1 },
    { kn::trap_2f0d00, 1 },
    { kn::trap_2f0d20, 4 },
    { kn::trap_2f0d50, 0x40000001 },
    { kn::trap_2f0d88, 0x40000001 },
    { kn::trap_friend_get_player_attacker, 2 },
    { kn::trap_2f0de0, 0x40000001 },
    { kn::trap_friend_remove_player_attacker, 2 },
    { kn::trap_friend_get_action_param, 0x40000002 },
    { kn::trap_2f0ea0, 0x40000001 },
    { kn::trap_2f0ee0, 0x40000001 },
    { kn::trap_attack_is_finish, 0x40000001 },
    { kn::trap_friend_action_clear, 1 },
    { kn::trap_2f0f58, 0x40000002 },
    { kn::trap_friend_is_start_leave, 1 },
    { kn::trap_2f0fb8, 0x40000001 },
    { kn::trap_2f0fe8, 2 },
    { kn::trap_2f1000, 0x40000001 },
    { kn::trap_2f1020, 0x40000001 },
    { kn::trap_friend_disable_follow_enemy, 1 },
    { kn::trap_2f1050, 1 },
    { kn::trap_2f1070, 1 },
    { kn::trap_2f1090, 1 },
    { kn::trap_2f10b0, 0x40000001 },
    { func_002f10c0, 4 },
    { kn::trap_2f1100, 0x40000001 },
    { kn::trap_btlobj_is_reflect_motion, 2 },
    { kn::trap_2f1168, 0x40000002 },
    { kn::trap_target_searcher_set_check_hide_from_friend, 2 },
    { kn::trap_friend_invalidate_warp_point, 2 },
    { kn::trap_2f11f0, 1 },
    { kn::trap_friend_add_warp_point, 3 },
    { kn::trap_chickenlittle_set_shoot_target, 2 },
};
}
