// func_00118da0 (zl90 w2404, 2026-10-26): plain -O2. The add+set tail is written out in loop 1 and crossjump merges it;
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
s32 func_00190730(W2404Tgt*, s32);
s32 func_00135c88(void*, W2404Obj*);
void func_00135bd0(void*, W2404Obj*);
s32 w2404_entry_num(void*) asm("_ZN2kn11ObjObserver11getEntryNumEv");
W2404Obj* func_00135d00(void*, s32);
s32 w2404_is_culling(W2404Obj*) asm("_ZN2YS3OBJ10is_cullingEv");
void func_00112df0(W2404Obj*, W2404Tgt*, s32, f32);
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
void func_00118da0(W2404Self* self) {
    W2404Party* party = w2404_party(0);
    void* obs;
    obs = w2404_obs(self->fr);
    W2404Tgt* ft = &self->fr->tgt;
    W2404Obj* cur = ft->obj;
    func_00190128(ft);
    W2404Tgt t;
    func_00190128(&t);
    func_00190128(&t);
    W2404PC* pc = party->pc;
    bool ok; W2404Tgt* src;
    if (pc) {
        src = &pc->tgt;
        t = *src;
        ok = w2404_valid(&t);
        if (ok && (t.obj->flags & 0x10) && w2404_can_attack(&t) && func_00135c88(obs, t.obj) < 0) {
            func_00135bd0(obs, t.obj);
        set:
            self->fr->tgt = t;
            return;
        }
    }
    {
        func_00190128(&t);
        s32 i = 0;
        while ((i = func_00190730(&t, i)) != 0) {
            if (w2404_can_attack(&t) && !w2404_is_culling(t.obj)) {
                if (func_00135c88(obs, t.obj) < 0) { func_00135bd0(obs, t.obj); self->fr->tgt = t; return; }
            }
        }
        func_00190128(&t);
        s32 n = w2404_entry_num(obs);
        s32 k = w2404_first(obs, cur);
        for (s32 j = k; j < k + n; j++) {
            W2404Obj* o = func_00135d00(obs, j);
            if (!w2404_is_culling(o)) {
                func_00112df0(o, &t, 0, 0.0f);
                ok = w2404_valid(&t);
                if (ok && w2404_can_attack(&t)) goto set;
            }
        }
    }
}
}
