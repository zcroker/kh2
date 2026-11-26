#include "../common/types.h"
extern "C" {
struct EffObj { u8 pad[0x230]; void* owner; };
struct EffSlot { s32 w0; s32 w4; EffObj* obj; u8 pad[28]; };
extern EffSlot* D_0035dcfc;
struct Res { u8 pad[0x14]; s32 w14; };
struct Ent {
    s32 w0;
    s32 key;
    s16 h8;
    u8 pad_a[2];
    void* eff;
    u8 sub[0x20];
    s16 slot;
};
struct Cmd { u8 pad[4]; s16 h4; u8 p6[2]; s16 h8; s16 ha; s16 hc; s16 type; s16 h10; };

s32 sa__EVENT__checkStart(s32);
s32 sa__EVENT__isJumpMode(s32);
Ent* func_0022e330(s32);
s32 func_0022e0a8(Ent*);
Res* func_00227bd8(s32, s32);
void YS__OBJ__is_valid(EffObj*);
void* ryj__PAX__start(void*, s32, s32, s32, s32, EffObj*);
void func_0022e368(Cmd*);
void eff_setup_1dddd0(void*, s32) asm("_Z14ryj__PAX__initjjjj");
s32 eff_is_loop(void*) asm("_ZN3ryj6EFFECT7is_loopEv");
void eff_loop_end_kill(void*) asm("_ZN3ryj6EFFECT13loop_end_killEv");
void eff_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
void eff_fadeout_kill(void*, f32) asm("_ZN3ryj6EFFECT12fadeout_killEf");
s32 eff_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
s32 eff_is_active(void*) asm("_ZN3ryj6EFFECT9is_activeEv");

void sa__EVENT__set_effect_seq(Cmd* c);  // 0x0022dd80: definition moved into src/anon/unit_0022d358.cpp
}
