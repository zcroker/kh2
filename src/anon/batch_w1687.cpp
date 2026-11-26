#include "../common/types.h"
extern "C" {
struct W1687Party { u8 pad[0x48c]; s32 active; };
struct W1687Ability { u8 pad[0x68]; f32 luck; u8 pad2[4]; f32 prizeRate; };
struct W1687PrizeDrop { u16 item; u16 rate; };
struct W1687PrizeTable { u8 pad[0xc]; W1687PrizeDrop drop[3]; };
W1687Party* party_Get(s32) asm("_ZN2YS5PARTY3GetEi");
W1687Ability* party_get_ability(W1687Party*) asm("_ZN2YS5PARTY11get_abilityEv");
s32 YS__OBJ__is_exist(W1687Party*) asm("_Z17YS__OBJ__is_existjjjj");
W1687PrizeTable* prizetable_Get(s32) asm("_ZN2YS10PRIZETABLE3GetEi");
s32 status_GetPrizeRatio(W1687PrizeTable*, s32, f32) asm("_ZN2YS6STATUS13GetPrizeRatioEv");
f32 func_00191b70(void);
s32 func_001d0820(void);
s32 func_001a5af0(s32);
void func_001a5880(u32, s32, s32);
void YS__PRIZEBOX__Appear(u32, u32);
void YS__PRIZE_MU__AppearTable(u32, W1687PrizeTable*);
void func_001ca758(u32, W1687PrizeTable*);
void YS__PRIZE_COLOSSEUM__AppearTable(u32, W1687PrizeTable*);
extern s32 D_00350790;
extern u32 D_0034f240;
extern u32 D_003638d0;

static inline f32 party_prize_rate() {
    f32 r = 1.0f;
    for (s32 i = 0; i < 3; i++) {
        W1687Party* p = party_Get(i);
        if (YS__OBJ__is_exist(p) && p->active)
            r *= party_get_ability(p)->prizeRate;
    }
    return r;
}
static inline f32 party_luck() {
    f32 r = 1.0f;
    for (s32 i = 0; i < 3; i++) {
        W1687Party* p = party_Get(i);
        if (YS__OBJ__is_exist(p) && p->active)
            r += party_get_ability(p)->luck;
    }
    return r;
}
static inline f32 frand(f32 max) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)D_003638d0 * 2.3283064e-10f * max;
}
static inline void drop_items(u32 obj, W1687PrizeTable* t, f32 luck) {
    for (s32 i = 0; i < 3; i++) {
        f32 th = t->drop[i].rate * luck;
        if (frand(100.0f) < th)
            YS__PRIZEBOX__Appear(t->drop[i].item, obj);
    }
}
struct W1687NoTail { ~W1687NoTail() {} } __attribute__((aligned(16)));
// 001a55a8: moved to src/anon/unit_001a4db0.cpp
}
