// kn__Stitch__set_target (helper w2404, 2026-10-26): plain -O2. The add+set tail is written out in loop 1 and crossjump merges it;
// this raises obs's block frequency so obs (s2) is allocated before the loop end k+n (s3).
#include "../common/types.h"
extern "C" {
struct W2404Obj { u8 pad[0x588]; u32 flags; };
struct W2404Tgt {
    W2404Obj* obj; s32 a, b, c, d;
};
void func_00190128(W2404Tgt*);
s32 w2404_is_exist(W2404Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 w2404_can_attack(W2404Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
s32 YS__TARGET__each(W2404Tgt*, s32);
s32 func_00135c88(void*, W2404Obj*);
void func_00135bd0(void*, W2404Obj*);
s32 w2404_entry_num(void*) asm("_ZN2kn11ObjObserver11getEntryNumEv");
W2404Obj* func_00135d00(void*, s32);
s32 w2404_is_culling(W2404Obj*) asm("_ZN2YS3OBJ10is_cullingEv");
void kn__Friend__setAttackTarget(W2404Obj*, W2404Tgt*, s32, f32);
struct W2404Party { u8 pad[0xb40]; struct W2404PC* pc; };
struct W2404PC { s32 x; W2404Tgt tgt; };
struct W2404Friend { u8 pad[0x9f4]; W2404Tgt tgt; };
W2404Party* w2404_party(s32) asm("_ZN2kn6Friend13getPartyCharaEi");
void* w2404_obs(W2404Friend*) asm("_ZN2kn6Friend14getObjObserverEv");
struct W2404Self { s32 x; W2404Friend* fr; };

static inline bool w2404_valid(W2404Tgt* t) {
    bool r = false;
    if (w2404_is_exist(t)) r = t->obj != 0;
    return r;
}

static inline s32 w2404_first(void* obs, W2404Obj* cur) {
    s32 v = 0;
    if (cur) {
        v = func_00135c88(obs, cur);
        if (v >= 0) v++; else v = 0;
    }
    return v;
}
void kn__Stitch__set_target(W2404Self* self);  // 0x00118da0: definition moved into src/anon/unit_00118958.cpp
}
