#include "../common/types.h"
#include "../yasui/libys/attack.hpp"
#include "../yasui/libys/battlereport.hpp"
#include "../yasui/libys/progress.hpp"

namespace {

void set_game_speed_value(f32 value) { *reinterpret_cast<volatile f32*>(0x00349e0c) = value; }

void reset_sysobj_state(s32 type, s32 index) {
    if ((index == 0xffff) && (type == 1)) {
        u32* state = reinterpret_cast<u32*>(0x0034dca0);
        state[0] = 0;
        state[1] = 0;
    }
    if ((index == 0xffff) && (type == 1)) {
        u32* state = reinterpret_cast<u32*>(0x0034dcb8);
        state[0] = 0;
        state[1] = 0;
    }
}

void reset_btlobj_target_state(s32 type, s32 index) {
    if ((index == 0xffff) && (type == 1)) {
        *reinterpret_cast<volatile f32*>(0x001c60000 + 3280) =
            *reinterpret_cast<const f32*>(0x00370000 - 13096);
    }
    if ((index == 0xffff) && (type == 1)) {
        u32* state = reinterpret_cast<u32*>(0x001c60000 + 3288);
        state[0] = 0;
        state[1] = 0;
    }
}

void increment_effect_counter() {
    volatile u16* counter = reinterpret_cast<volatile u16*>(0x0032fb00);
    if (*counter < 999) {
        *counter = static_cast<u16>(*counter + 1);
    }
}

void update_limit_reference(s32 limit) {
    if ((*(u32*)(limit + 0x40) & 8) != 0) {
        u32 obj = *(u32*)(*(u32*)(limit + 0x0c) + 0x0b44);
        typedef void (*VirtualCall)(u32);
        VirtualCall fn = reinterpret_cast<VirtualCall>(*(u32*)(*(u32*)obj + 0x18));
        fn(obj);
        *(u32*)(limit + 0x3c) = *(u32*)(limit + 0x3c) - 1;
        *(u32*)(limit + 0x40) &= ~8u;
    }
}

u32 get_current_friend_value() {
    u32 current = *reinterpret_cast<u32*>(0x01d48cb0);
    if (current == 0) {
        return 0;
    }
    if ((*(u32*)(current + 64) & 4) == 0) {
        return *(u16*)(*(u32*)current + 40);
    }
    return 0;
}

void player_push_ability_button_impl(void* player) {
    reinterpret_cast<void (*)(void*)>(0x001e29e0)(player);
}

s32 bghit_get_cross_pos_impl(s32 hit) { return reinterpret_cast<s32 (*)(s32)>(0x001d36e8)(hit); }

void camera_apply_pos_impl(s32 enabled) {
    reinterpret_cast<void (*)(s32)>(0x00226e60)(enabled);
}

}  // namespace

extern "C" void* func_00102c80(void*);
extern "C" void* func_00102788(void*, s32, s32, const char*);
extern "C" void* func_001050d8(s32);
extern "C" void func_001e27c0(void*);
extern "C" void func_001d97c8(BD_VALUE*);
extern "C" void func_00170ee8(s32, s32);
extern "C" void func_0018f0b0(s32, s32);
extern "C" u32 func_001b5af0(void);
extern "C" void func_001e29e0(void*);

extern s32 YS_abs_int(s32) asm("_ZN2YS3absEi");
extern s32 YS_FILE_IsReading(void) asm("_ZN2YS4FILE9IsReadingEv");
extern void YS_CACHE_BUFF_Flush(s32) asm("_ZN2YS10CACHE_BUFF5FlushEP4TASK");
extern void YS_PROGRESS_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
extern s32 YS_WORLDFLAG_Check(s32) asm("_ZN2YS9WORLDFLAG5CheckEi");
extern void ryj_EFFECT_loop_end(s32) asm("_ZN3ryj6EFFECT8loop_endEv");
extern void ryj_EFFECT_loop_end_kill(s32) asm("_ZN3ryj6EFFECT13loop_end_killEv");
extern void ryj_EFFECT_kill(s32) asm("_ZN3ryj6EFFECT4killEv");
extern void AREA_Free(s32) asm("_ZN4AREA4FreeEPv");
extern void dk_Timer_setCountDown(s32) asm("_ZN2dk5Timer12setCountDownEj");
extern void dk_Timer_start(void) asm("_ZN2dk5Timer5startEv");
extern void YS_SAVEFLAG_Reset(s32) asm("_ZN2YS8SAVEFLAG5ResetEj");
extern s32 YS_SAVEFLAG_Check(s32) asm("_ZN2YS8SAVEFLAG5CheckEj");
extern void YS_MENUFLAG_Reset(s32) asm("_ZN2YS8MENUFLAG5ResetEi");
extern void YS_OBJ_set_pos(void*, s32) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
extern void YS_OBJ_set_pos_trans(void*, s32) asm("_ZN2YS3OBJ13set_pos_transERKN2kn7FVectorE");
extern void YS_STDOBJ_set_special_command(void*, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
extern void YS_STDOBJ_hook_command_image(void*) asm("_ZN2YS6STDOBJ18hook_command_imageEv");
extern void YS_OBJ_scatter_prize(void*, s32) asm("_ZN2YS3OBJ13scatter_prizeEi");
extern void YS_FIELDOBJ_mark_history(void*) asm("_ZN2YS8FIELDOBJ12mark_historyEv");
extern void YS_BLUR_init(void) asm("_ZN2YS4BLUR4initEv");
extern void dk_Camera_singleCrossFadeStart(f32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
extern void YS_ITEM_Reduce(s32, s32) asm("_ZN2YS4ITEM6ReduceEii");
extern void YS_BTLOBJ_blow(void*) asm("_ZN2YS6BTLOBJ4blowERKN2kn7FVectorE");
extern "C" void func_0014ce50(f32);
extern "C" void func_0019ec88(u32);
extern "C" u32 func_00198580(u32, u32);  // check_div1000_500
extern "C" f32 func_0018cb30(s32);
extern "C" void func_0018e040(s32);
extern "C" u32 func_00153f08(u32, u32, u32, u32);
extern "C" u32 func_00186888(u32, u32, u32, u32);
extern "C" u32 func_001880b0(u32, u32, u32, u32);
extern "C" u32 func_00188170(u32, u32, u32, u32);
extern "C" u32 func_00177460(u32, u32, u32, u32);
extern "C" u32 func_00180d40(u32, u32, u32, u32);
extern "C" u32 func_001de508(u32, u32, u32, u32);
extern "C" u32 func_0019eb60(u32, u32, u32, u32);
extern "C" u32 func_0017ec30(u32, u32, u32, u32);
extern "C" u32 func_00190878(u32, u32, u32, u32);
extern "C" void func_00226e60(u32);
extern "C" u32 func_001a27d8(u32, u32, u32, u32);
extern "C" u32 func_0023f070(u32, u32, u32, u32);
extern "C" void func_001b57f8(s32);
extern "C" s32 func_001d36e8(s32);
extern void YS_SORA_set_skateboard_mode(void*, s32) asm("_ZN2YS4SORA19set_skateboard_modeEi");
extern void YS_OCC_disable(void*) asm("_ZN2YS6OBJOCC11disable_allEv");
extern void YS_OCC_enable(void*) asm("_ZN2YS6OBJOCC10enable_allEv");
extern void YS_OCC_disable_bone(void*, s32) asm("_ZN2YS6OBJOCC7disableEi");
extern void YS_OBJ_ControlOff(s32) asm("_ZN2YS3OBJ10ControlOffEi");
extern void YS_OBJ_ControlOn(s32) asm("_ZN2YS3OBJ9ControlOnEi");
extern void YS_OBJ_detach(void*) asm("_ZN2YS3OBJ6detachEv");
extern void YS_ACT_clear(void*) asm("_ZN2YS3ACT5clearEv");
extern void YS_ACT_push(void*) asm("_ZN2YS3ACT4pushEPc");
extern void YS_ACT_start_pri(void*) asm("_ZN2YS3ACT9pri_startEPc");
extern void YS_OBJ_change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern void YS_PARTY_hook(void*) asm("_ZN2YS5PARTY4hookEPNS_2VME");
extern void YS_EFFECT_unbind(void*) asm("_ZN3ryj3PAX6unbindEPNS_6EFFECTE");
extern void YS_UNIT_Activate(char*) asm("_ZN2YS4UNIT8ActivateEPc");
extern void YS_PLAYER_set_exec_rc(void*, s32) asm("_ZN2YS6PLAYER11set_exec_rcEi");
extern void YS_TARGET_set_obj(void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
extern void YS_TARGET_ClearBeforePlayer(void) asm("_ZN2YS6TARGET17ClearBeforePlayerEv");
extern void Tz_Layout_setNum(s32, s32) asm("_ZN2Tz6Layout6setNumEii");

namespace YS {

// 0016d2e0: moved to src/anon/unit_0016d2e0.cpp

// 0016ded8: moved to src/anon/unit_0016d2e0.cpp

// 0016dc28: moved to src/anon/unit_0016d2e0.cpp

// 0016dc50: moved to src/anon/unit_0016d2e0.cpp

// 0016dc68: moved to src/anon/unit_0016d2e0.cpp

// 0016de90: moved to src/anon/unit_0016d2e0.cpp

// 0016e290: moved to src/anon/unit_0016d2e0.cpp

// 0016e2a8: moved to src/anon/unit_0016d2e0.cpp

// 0016e320: moved to src/anon/unit_0016d2e0.cpp

// 0016e5c8: moved to src/anon/unit_0016d2e0.cpp

// 0016e5e0: moved to src/anon/unit_0016d2e0.cpp

// 0016e638: moved to src/anon/unit_0016d2e0.cpp

// 0016e650: moved to src/anon/unit_0016d2e0.cpp

// 0016e7b8: moved to src/anon/unit_0016d2e0.cpp

u32 trap_screen_cross_fade(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_screen_cross_fadeEP8BD_VALUE");
// 0016dfb8: moved to src/anon/unit_0016d2e0.cpp

// 0016e838: moved to src/anon/unit_0016d2e0.cpp

void trap_obj_set_pos_trans(BD_VALUE* bd);  // 0x001714b0: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_capture_command(BD_VALUE* bd);  // 0x001718f0: definition moved into src/anon/unit_00170f58.cpp

u32 trap_obj_get_weight(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_obj_get_weightEP8BD_VALUE");
u32 trap_obj_get_weight(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00171978: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_hook_command_image(BD_VALUE* bd);  // 0x00171b28: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_scatter_prize(BD_VALUE* bd);  // 0x00171f00: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_history_mark(BD_VALUE* bd);  // 0x00172028: definition moved into src/anon/unit_00171e58.cpp

u32 trap_obj_blow(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS13trap_obj_blowEP8BD_VALUE");
u32 trap_obj_blow(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001712f8: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_set_skateboard_mode(BD_VALUE* bd);  // 0x001718d0: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_disable_occ(BD_VALUE* bd);  // 0x00171b80: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_enable_occ(BD_VALUE* bd);  // 0x00171ba0: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_disable_occ_bone(BD_VALUE* bd);  // 0x00171bc0: definition moved into src/anon/unit_00170f58.cpp

void func_obj_control_off(BD_VALUE* bd);  // 0x00171c30: definition moved into src/anon/unit_00170f58.cpp

void func_obj_control_on(BD_VALUE* bd);  // 0x00171c48: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_detach(BD_VALUE* bd);  // 0x00171cc0: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_act_clear(BD_VALUE* bd);  // 0x00171d08: definition moved into src/anon/unit_00170f58.cpp

u32 trap_obj_act_push(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS17trap_obj_act_pushEP8BD_VALUE");
u32 trap_obj_act_push(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00171d28: definition moved into src/anon/unit_00170f58.cpp

u32 trap_obj_act_start_pri(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_obj_act_start_priEP8BD_VALUE");
u32 trap_obj_act_start_pri(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00171dd8: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_action_lightcycle(BD_VALUE* bd);  // 0x00171e88: definition moved into src/anon/unit_00171e58.cpp

u32 trap_obj_hook_stop(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS18trap_obj_hook_stopEP8BD_VALUE");
u32 trap_obj_hook_stop(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00172008: definition moved into src/anon/unit_00171e58.cpp

u32 trap_obj_motion_capture_id(u32 a0, u32 a1, u32 a2, u32 a3)
    asm("_ZN2YS26trap_obj_motion_capture_idEP8BD_VALUE");
u32 trap_obj_motion_capture_id(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x001725b8: definition moved into src/anon/unit_00171e58.cpp

u32 trap_obj_effect_unbind(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS22trap_obj_effect_unbindEP8BD_VALUE");
u32 trap_obj_effect_unbind(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00172710: definition moved into src/anon/unit_00171e58.cpp

}  // namespace YS

namespace gb {

void trap_obj_set_pos(BD_VALUE* bd);  // 0x00171460: definition moved into src/anon/unit_00170f58.cpp

}  // namespace gb
extern s32 ryj_EFFECT_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
extern s32 ryj_EFFECT_is_active(void*) asm("_ZN3ryj6EFFECT9is_activeEv");
extern s32 AREA_Alloc(u32) asm("_ZN4AREA5AllocEj");
extern void SOUND_SE3DDisable(void*) asm("_ZN5SOUND11SE3DDisableEv");
extern s32 YS_MENUFLAG_Check(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
extern void YS_BTLOBJ_sys_dead(void*) asm("_ZN2YS6BTLOBJ8sys_deadEv");
extern void YS_PRIZE_CA_Appear(void*, s32) asm("_ZN2YS8PRIZE_CA6AppearEPNS_6BTLOBJEi");
extern void YS_MICKEY_recov_holylight(void*) asm("_ZN2YS6MICKEY15recov_holylightEv");
extern void dk_Map_setHideGroup(s32) asm("_ZN2dk3Map12setHideGroupEj");
extern void dk_Map_setVisibleGroup(s32) asm("_ZN2dk3Map15setVisibleGroupEj");
extern void YS_OBJ_set_dir(void*, s32) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
extern void YS_OBJ_texanm_start(void*, s32) asm("_ZN2YS3OBJ12texanm_startEi");
extern void YS_OBJ_texanm_stop(void*, s32) asm("_ZN2YS3OBJ11texanm_stopEi");
extern void YS_OBJ_show_part(void*, s32) asm("_ZN2YS3OBJ9show_partEi");
extern void YS_OBJ_hide_part(void*, s32) asm("_ZN2YS3OBJ9hide_partEi");
extern void YS_STATUS_CageOn(void) asm("_ZN2YS6STATUS6CageOnEv");
extern void YS_EVENT_ControlOff(void) asm("_ZN2YS5EVENT10ControlOffEv");
extern void dk_ScopeCamera_destroy(void) asm("_ZN2dk11ScopeCamera7destroyEv");
extern void YS_UNIT_GROUP_Disable(s32) asm("_ZN2YS10UNIT_GROUP7DisableEi");
extern void YS_UNIT_GROUP_Enable(s32) asm("_ZN2YS10UNIT_GROUP6EnableEi");
extern void YS_PRIZE_TR_GetAll(void*) asm("_ZN2YS8PRIZE_TR6GetAllEPNS_6BTLOBJE");
extern void YS_PIERROT_set_sheet(void*, s32) asm("_ZN2YS7PIERROT9set_sheetEi");
extern void YS_ATTACK_destroy(s32) asm("_ZN2YS6ATTACK7destroyEv");
extern void YS_LIMIT_close_gauge(s32) asm("_ZN2YS5LIMIT11close_gaugeEv");
extern void YS_BONUSLEVEL_Up(s32) asm("_ZN2YS10BONUSLEVEL2UpEi");
extern s32 YS_EVENT_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
extern void YS_MISSION_Complete(s32) asm("_ZN2YS7MISSION8CompleteEi");
extern void YS_MISSION_DeadBoss(s32) asm("_ZN2YS7MISSION8DeadBossEi");
extern void YS_MISSION_Failed(void) asm("_ZN2YS7MISSION6FailedEv");
extern void YS_MISSION_Activate2d(void) asm("_ZN2YS7MISSION10Activate2dEv");
extern void YS_MISSION_Return(void) asm("_ZN2YS7MISSION6ReturnEv");
extern void YS_MISSION_RestartTimer(s32, s32) asm("_ZN2YS7MISSION12RestartTimerEii");
extern void dk_Timer_pauseOn(s32) asm("_ZN2dk5Timer7pauseOnEj");
extern void dk_Timer_pauseOff(s32) asm("_ZN2dk5Timer8pauseOffEj");
extern void YS_MISSION_WarningTimer(s32) asm("_ZN2YS7MISSION12WarningTimerEi");
extern void YS_MISSION_DisableTimer(s32) asm("_ZN2YS7MISSION12DisableTimerEi");
extern void YS_MISSION_SetWatch(s32, s32) asm("_ZN2YS7MISSION8SetWatchEii");
extern void YS_MISSION_SetCount(s32, s32) asm("_ZN2YS7MISSION8SetCountEii");
extern void YS_MISSION_AddCount(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
extern void YS_MISSION_DisableCount(s32, s32) asm("_ZN2YS7MISSION12DisableCountEi");
extern void YS_MISSION_ResetComboCounter(s32) asm("_ZN2YS7MISSION17ResetComboCounterEi");
extern void YS_MISSION_SetMaxComboCounter(s32, s32) asm("_ZN2YS7MISSION18SetMaxComboCounterEii");
extern void YS_MISSION_WarningComboCounter(s32) asm("_ZN2YS7MISSION19WarningComboCounterEi");
extern void Ti_MG_EHSidecar_MoveToBeforePoint(void*) asm("_ZN2Ti12MG_EHSidecar17MoveToBeforePointEv");
extern void dk_LockOn_show(void*) asm("_ZN2dk6LockOn4showEv");
extern void Ts_FLARE_Init(void*) asm("_ZN2Ts5FLARE4InitEv");
extern void Ts_TRINITY_SHOT_OBJ_Init(void*) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");

namespace YS {

// 0016e168: moved to src/anon/unit_0016d2e0.cpp

// 0016e2c0: moved to src/anon/unit_0016d2e0.cpp

// 0016e2f0: moved to src/anon/unit_0016d2e0.cpp

// 0016e598: moved to src/anon/unit_0016d2e0.cpp

// 0016e740: moved to src/anon/unit_0016d2e0.cpp

// 0016e7d0: moved to src/anon/unit_0016d2e0.cpp

void trap_obj_dead_mark(BD_VALUE* bd);  // 0x00172b68: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_scatter_medal(BD_VALUE* bd);  // 0x00172e88: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_recov_holylight(BD_VALUE* bd);  // 0x00172ea8: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_motion_is_hook(BD_VALUE* bd);  // 0x00173c18: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_sheet(BD_VALUE* bd);  // 0x00173d80: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_texanm_stop(BD_VALUE* bd);  // 0x00173da0: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_motion_speed(BD_VALUE* bd);  // 0x001740f8: definition moved into src/anon/unit_00171e58.cpp

void trap_command_cage_off(BD_VALUE* bd);  // 0x001742f8: definition moved into src/anon/unit_00171e58.cpp

void trap_event_control_off(BD_VALUE* bd);  // 0x001747a8: definition moved into src/anon/unit_00171e58.cpp

void trap_camera_end_scope(BD_VALUE* bd);  // 0x00174d38: definition moved into src/anon/unit_00171e58.cpp

void trap_unit_disable(BD_VALUE* bd);  // 0x00174f58: definition moved into src/anon/unit_00171e58.cpp

void trap_unit_enable(BD_VALUE* bd);  // 0x00174f70: definition moved into src/anon/unit_00171e58.cpp

void trap_prize_get_all_tr(BD_VALUE* bd);  // 0x00175240: definition moved into src/anon/unit_00171e58.cpp

void trap_btlobj_set_sheet(BD_VALUE* bd);  // 0x0018f1c0: definition moved into src/anon/unit_0018f140.cpp

void trap_attack_free(BD_VALUE* bd);  // 0x0018f790: definition moved into src/anon/unit_0018f140.cpp

void trap_limit_reference(BD_VALUE* bd);  // 0x0018ff48: definition moved into src/anon/unit_0018f140.cpp

void trap_limit_close_gauge(BD_VALUE* bd);  // 0x0018ff60: definition moved into src/anon/unit_0018f140.cpp

void trap_bonuslevel_up(BD_VALUE* bd);  // 0x0018ff78: definition moved into src/anon/unit_0018f140.cpp

void trap_event_is_exec(BD_VALUE* bd);  // 0x0019ff90: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_complete(BD_VALUE* bd);  // 0x0019ffe8: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_dead_boss(BD_VALUE* bd);  // 0x001a0000: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_failed(BD_VALUE* bd);  // 0x001a0018: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_activate2d(BD_VALUE* bd);  // 0x001a0048: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_is_activate2d(BD_VALUE* bd);  // 0x001a00b8: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_restart_timer(BD_VALUE* bd);  // 0x001a0128: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_pause_timer(BD_VALUE* bd);  // 0x001a0170: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_cancel_pause_timer(BD_VALUE* bd);  // 0x001a0188: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_warning_timer(BD_VALUE* bd);  // 0x001a0200: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_disable_timer(BD_VALUE* bd);  // 0x001a0218: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_set_watch(BD_VALUE* bd);  // 0x001a0230: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_decrement_count(BD_VALUE* bd);  // 0x001a0268: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_add_count(BD_VALUE* bd);  // 0x001a0320: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_disable_count(BD_VALUE* bd);  // 0x001a0358: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_start_combo_counter(BD_VALUE* bd);  // 0x001a0540: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_set_combo_counter_param(BD_VALUE* bd);  // 0x001a05d8: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_warning_combo_counter(BD_VALUE* bd);  // 0x001a0620: definition moved into src/anon/unit_0019fb70.cpp

}  // namespace YS

namespace gb {

void trap_bg_hide(BD_VALUE* bd);  // 0x00173298: definition moved into src/anon/unit_00171e58.cpp

void trap_bg_show(BD_VALUE* bd);  // 0x001732b0: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_hide_part(BD_VALUE* bd);  // 0x00174118: definition moved into src/anon/unit_00171e58.cpp

}  // namespace gb

namespace ryj {

// 001e0b60: moved to src/rikeda/saveram_gumibattle.cpp

}  // namespace ryj

namespace Ti {

// 002e3e50: moved to src/anon/unit_002e2f08.cpp

}  // namespace Ti

namespace Ts {

void trap_lockon_hide(BD_VALUE* bd) { dk_LockOn_show(bd); }

// 002e8bd0: moved to src/anon/unit_002e8b50.cpp

// 002e9010: moved to src/anon/unit_002e8b50.cpp

}  // namespace Ts
extern s32 YS_OBJ_GetPlayer(void) asm("_ZN2YS3OBJ9GetPlayerEv");
extern s32 YS_CHANGEFORM_CanCaptureForm(BD_VALUE*) asm("_ZN2YS10CHANGEFORM14CanCaptureFormEv");
extern f32 YS_EVENT_GetRestTime(void) asm("_ZN2YS5EVENT11GetRestTimeEv");
extern s32 YS_STATUS_IsBattleMode(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
extern s32 Tz_Munny_Get(void) asm("_ZN2Tz5Munny3GetEv");
extern s32 YS_PRIZE_GetAppearNum(void) asm("_ZN2YS5PRIZE12GetAppearNumEv");
extern s32 YS_PRIZE_CA_GetAppearNum(void) asm("_ZN2YS8PRIZE_CA12GetAppearNumEv");
extern s32 YS_WINDOW_SYSTEM_TUTORIAL_IsOpen(void) asm("_ZN2YS22WINDOW_SYSTEM_TUTORIAL6IsOpenEv");
extern s32 YS_ATTACK_CHECK_NewComboGroup(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
extern s32 YS_SUMMON_IsTinkExist(void) asm("_ZN2YS6SUMMON11IsTinkExistEv");
extern s32 Ti_MG_EHSidecar_GetCurrentPoint(void) asm("_ZN2Ti12MG_EHSidecar15GetCurrentPointEv");
extern s32 Ts_FLARE_IsEmpty(void) asm("_ZN2Ts5FLARE7IsEmptyEv");
extern f32 YS_MATH_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
extern s32 YS_OBJ_CountEntry(s32) asm("_ZN2YS3OBJ10CountEntryEj");
extern s32 YS_PARTY_Get(s32) asm("_ZN2YS5PARTY3GetEi");
extern s32 YS_TARGET_dup(s32) asm("_ZN2YS6TARGET3dupEv");
extern s32 YS_TARGET_is_exist(s32) asm("_ZNK2YS6TARGET8is_existEv");
extern s32 Tz_Munny_Add(u32) asm("_ZN2Tz5Munny3AddEj");
extern s32 YS_DAMAGE_GetReactionType(s32) asm("_ZN2YS6DAMAGE15GetReactionTypeEi");
extern s32 YS_DAMAGE_is_finish(s32) asm("_ZNK2YS6DAMAGE9is_finishEv");
extern s32 YS_DAMAGE_is_normal(s32) asm("_ZNK2YS6DAMAGE9is_normalEv");
extern s32 YS_ATTACK_is_hit(s32) asm("_ZN2YS6ATTACK6is_hitEv");
extern s32 YS_MAGIC_CanAddCost(f32) asm("_ZN2YS5MAGIC10CanAddCostEf");
extern s32 YS_MISSION_GetTimer(s32) asm("_ZN2YS7MISSION8GetTimerEi");
extern s32 YS_MISSION_GetTimerSecond(s32) asm("_ZN2YS7MISSION14GetTimerSecondEi");
extern s32 YS_MISSION_GetCount(s32) asm("_ZN2YS7MISSION8GetCountEi");
extern s32 YS_MISSION_IsExec(void) asm("_ZN2YS7MISSION6IsExecEv");
extern f32 YS_MISSION_GetGaugeRatio(s32) asm("_ZN2YS7MISSION13GetGaugeRatioEi");
extern f32 YS_MISSION_GetGaugeWarningRatio(s32) asm("_ZN2YS7MISSION20GetGaugeWarningRatioEi");
extern s32 YS_MISSION_IsGaugeWarning(s32) asm("_ZN2YS7MISSION14IsGaugeWarningEi");
extern s32 YS_MINIGAME_GetScore(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
extern void YS_MISSION_SetComboCounterWarningSe(s32, s32) asm("_ZN2YS7MISSION24SetComboCounterWarningSeEii");
extern s32 YS_SUMMON_GetMode(void) asm("_ZN2YS6SUMMON7GetModeEv");
extern s32 YS_LIMIT_reset_hit_counter(s32) asm("_ZN2YS5LIMIT17reset_hit_counterEv");
extern s32 YS_ATTACK_is_finish(s32) asm("_ZNK2YS6ATTACK9is_finishEv");
extern void YS_EVENT_ContinueControlOff(void) asm("_ZN2YS5EVENT18ContinueControlOffEv");
extern void YS_EFFECT_AddDeadEffect(s32) asm("_ZN2YS6EFFECT13AddDeadEffectEPN3ryj6EFFECTE");
extern void YS_TARGET_free(s32) asm("_ZN2YS6TARGET4freeEv");
extern void YS_STATUS_SetPrizeRatio(f32) asm("_ZN2YS6STATUS13SetPrizeRatioEf");
extern s32 YS_LIGHT_Create(s32) asm("_ZN2YS5LIGHT6CreateEi");
extern void YS_LIGHT_fadeout(f32) asm("_ZN2YS5LIGHT7fadeoutEf");
extern void YS_LIGHT_fadein(f32) asm("_ZN2YS5LIGHT6fadeinEf");
extern void YS_BLUR_start(s32, f32) asm("_ZN2YS4BLUR5startEf");
extern void YS_BTLOBJ_dead(void*) asm("_ZN2YS6BTLOBJ4deadEv");
extern void dk_Map_setAnimationSpeedRatio(s32, f32) asm("_ZN2dk3Map22setAnimationSpeedRatioEN2kn13AnimationWork4TYPEEf");
extern void YS_OBJ_fly_to_jump(void*) asm("_ZN2YS3OBJ11fly_to_jumpEv");
extern void YS_JIGSAW_Get(s32, s32) asm("_ZN2YS6JIGSAW3GetEii");

namespace YS {

// 0016dec0: moved to src/anon/unit_0016d2e0.cpp

// 0016def0: moved to src/anon/unit_0016d2e0.cpp

// 0016e540: moved to src/anon/unit_0016d2e0.cpp

// 0016e568: moved to src/anon/unit_0016d2e0.cpp

void trap_sysobj_is_exist(BD_VALUE* bd);  // 0x00170f38: definition moved into src/anon/unit_0016e8f8.cpp

void trap_sysobj_moveto(BD_VALUE* bd);  // 0x00171068: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_dead(BD_VALUE* bd);  // 0x00172b28: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_count_entry(BD_VALUE* bd);  // 0x00172d78: definition moved into src/anon/unit_00171e58.cpp

void trap_bg_set_animation_speed(BD_VALUE* bd);  // 0x00173610: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_star(BD_VALUE* bd);  // 0x00173e88: definition moved into src/anon/unit_00171e58.cpp

void trap_obj_fly_to_jump(BD_VALUE* bd);  // 0x00173eb8: definition moved into src/anon/unit_00171e58.cpp

u32 func_area_activate_unit(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS23func_area_activate_unitEP8BD_VALUE");
u32 func_area_activate_unit(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00173680: definition moved into src/anon/unit_00171e58.cpp

u32 trap_obj_check_flag(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_obj_check_flagEP8BD_VALUE");
u32 trap_obj_check_flag(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00173b98: definition moved into src/anon/unit_00171e58.cpp

void trap_player_can_capture_form(BD_VALUE* bd);  // 0x00174230: definition moved into src/anon/unit_00171e58.cpp

void trap_player_set_exec_rc(BD_VALUE* bd);  // 0x00174258: definition moved into src/anon/unit_00171e58.cpp

void trap_target_dup(BD_VALUE* bd);  // 0x001745c8: definition moved into src/anon/unit_00171e58.cpp

void trap_target_free(BD_VALUE* bd);  // 0x001745f8: definition moved into src/anon/unit_00171e58.cpp

void trap_target_is_exist(BD_VALUE* bd);  // 0x00174610: definition moved into src/anon/unit_00171e58.cpp

u32 trap_target_set_obj(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_target_set_objEP8BD_VALUE");
u32 trap_target_set_obj(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00174640: definition moved into src/anon/unit_00171e58.cpp

void trap_target_clear_before_player(BD_VALUE* bd);  // 0x00174688: definition moved into src/anon/unit_00171e58.cpp

void trap_event_get_rest_time(BD_VALUE* bd);  // 0x00174780: definition moved into src/anon/unit_00171e58.cpp

void trap_event_continue_control_off(BD_VALUE* bd);  // 0x0019ffb8: definition moved into src/anon/unit_0019fb70.cpp

void trap_status_is_mission(BD_VALUE* bd);  // 0x001748a0: definition moved into src/anon/unit_00171e58.cpp

void trap_status_force_leave_end(BD_VALUE* bd);  // 0x00174988: definition moved into src/anon/unit_00171e58.cpp

void trap_status_set_prize_ratio(BD_VALUE* bd);  // 0x001749b0: definition moved into src/anon/unit_00171e58.cpp

void trap_camera_apply_pos(BD_VALUE* bd);  // 0x00174c30: definition moved into src/anon/unit_00171e58.cpp

void trap_light_fadeout(BD_VALUE* bd) { YS_LIGHT_fadeout(bd->f); }

void trap_light_fadein(BD_VALUE* bd) { YS_LIGHT_fadein(bd->f); }

void trap_light_create(BD_VALUE* bd);  // 0x00174a90: definition moved into src/anon/unit_00171e58.cpp

void trap_sheet_munny(BD_VALUE* bd);  // 0x001750b0: definition moved into src/anon/unit_00171e58.cpp

void trap_sheet_add_munny(BD_VALUE* bd);  // 0x001750d8: definition moved into src/anon/unit_00171e58.cpp

u32 trap_sheet_attack_level(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS23trap_sheet_attack_levelEP8BD_VALUE");
u32 trap_sheet_attack_level(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00175170: definition moved into src/anon/unit_00171e58.cpp

void trap_prize_num(BD_VALUE* bd);  // 0x00175218: definition moved into src/anon/unit_00171e58.cpp

void trap_prize_num_ca(BD_VALUE* bd);  // 0x00175300: definition moved into src/anon/unit_00171e58.cpp

void trap_tutorial_is_open(BD_VALUE* bd);  // 0x00175438: definition moved into src/anon/unit_00171e58.cpp

u32 trap_picture_change(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN2YS19trap_picture_changeEP8BD_VALUE");
u32 trap_picture_change(u32 a0, u32 a1, u32 a2, u32 a3);  // 0x00175460: definition moved into src/anon/unit_00171e58.cpp

void trap_jigsaw_get(BD_VALUE* bd);  // 0x00175500: definition moved into src/anon/unit_00171e58.cpp

void trap_btlobj_target(BD_VALUE* bd);  // 0x0018f100: definition moved into src/anon/unit_0018d050.cpp

void trap_attack_is_hit_bg(BD_VALUE* bd);  // 0x0018f7d8: definition moved into src/anon/unit_0018f140.cpp

void trap_attack_exec_reflect(BD_VALUE* bd);  // 0x0018fbf8: definition moved into src/anon/unit_0018f140.cpp

void trap_summon_is_tink_exist(BD_VALUE* bd);  // 0x0018ff90: definition moved into src/anon/unit_0018f140.cpp

void trap_damage_element(BD_VALUE* bd);  // 0x0018f600: definition moved into src/anon/unit_0018f140.cpp

void trap_damage_get_reaction_type(BD_VALUE* bd);  // 0x0018f630: definition moved into src/anon/unit_0018f140.cpp

void trap_damage_is_finish(BD_VALUE* bd);  // 0x0018f660: definition moved into src/anon/unit_0018f140.cpp

void trap_damage_is_normal(BD_VALUE* bd);  // 0x0018f690: definition moved into src/anon/unit_0018f140.cpp

void trap_magic_can_add_cost(BD_VALUE* bd);  // 0x0018fce0: definition moved into src/anon/unit_0018f140.cpp

void trap_mission_get_timer(BD_VALUE* bd);  // 0x001a01a0: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_get_timer_second(BD_VALUE* bd);  // 0x001a01d0: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_get_count(BD_VALUE* bd);  // 0x001a02f0: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_get_gauge_ratio(BD_VALUE* bd);  // 0x001a0440: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_get_gauge_warning_ratio(BD_VALUE* bd);  // 0x001a0498: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_is_gauge_warning(BD_VALUE* bd);  // 0x001a04c8: definition moved into src/anon/unit_0019fb70.cpp

void trap_mission_set_combo_counter_warning_se(BD_VALUE* bd);  // 0x001a0638: definition moved into src/anon/unit_0019fb70.cpp

void trap_score_get(BD_VALUE* bd);  // 0x001a06b0: definition moved into src/anon/unit_0019fb70.cpp

}  // namespace YS

namespace Ti {

// 002e3ea8: moved to src/anon/unit_002e2f08.cpp

}  // namespace Ti

namespace Ts {

// 002e8ce0: moved to src/anon/unit_002e8b50.cpp

// 002e9120: moved to src/anon/unit_002e8b50.cpp

void trap_bghit_get_cross_pos(BD_VALUE* bd) { bd->i = func_001d36e8(bd->i); }

// 002e91a0: moved to src/anon/unit_002e8b50.cpp

// 002e91d0: moved to src/anon/unit_002e8b50.cpp

}  // namespace Ts

namespace kn {

// 002f0f00: moved to src/naka/libkn/trapfunctions.cpp

}  // namespace kn
namespace YS {

// 0016dc80: moved to src/anon/unit_0016d2e0.cpp

// 0016dcb0: moved to src/anon/unit_0016d2e0.cpp

// 0016dcd8: moved to src/anon/unit_0016d2e0.cpp

// 0016dd00: moved to src/anon/unit_0016d2e0.cpp

void trap_camera_set_scope_zoom(BD_VALUE* bd);  // 0x00174de0: definition moved into src/anon/unit_00171e58.cpp

void trap_camera_set_scope_closeup_distance(BD_VALUE* bd);  // 0x00174df8: definition moved into src/anon/unit_00171e58.cpp

void trap_attack_is_hit(BD_VALUE* bd);  // 0x0018f7a8: definition moved into src/anon/unit_0018f140.cpp

}  // namespace YS
