#include "../common/types.h"
extern "C" void func_00190128(void*);
struct W1650QW {
    f32 x, y, z, w;
    W1650QW() {}
    W1650QW(const W1650QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1650QW& operator=(const W1650QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1650Tgt {
    s32 a, b, c, d, e;
    W1650Tgt() { func_00190128(this); }
    void clear() { func_00190128(this); }
};
struct W1650Lock;
struct W1650LockVt { void* f[7]; void (*setPos)(W1650Lock*, W1650QW); };
struct W1650Lock { W1650LockVt* vt; };
struct W1650Friend { u8 p0[0x9f4]; W1650Tgt target; };
struct W1650Party { u8 p0[0xb40]; void* lockon; };
struct W1650Input { u64 trig; u64 press; };
struct W1650Fps { u8 p0[4]; W1650Friend* fr; u8 p8[0x2c - 8]; s32 kind; W1650Lock* lock; u8 p34[0x40 - 0x34]; W1650QW pos; };
extern "C" {
s32 W1650_is_exist(W1650Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
s32 W1650_can_attack(W1650Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
void W1650_set_obj(W1650Tgt*, s32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 W1650_is_culling(s32) asm("_ZN2YS3OBJ10is_cullingEv");
void* W1650_getObjObserver(W1650Friend*) asm("_ZN2kn6Friend14getObjObserverEv");
W1650Party* W1650_getPartyChara(s32) asm("_ZN2kn6Friend13getPartyCharaEi");
W1650Input* W1650_GetInputState(...) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
s32 W1650_getEntryNum(void*) asm("_ZN2kn11ObjObserver11getEntryNumEv");
void W1650_lockon_start(void*, s32, W1650Tgt*) asm("_ZN2YS6LOCKON5startEiPNS_6TARGETE");
void W1650_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
s32 W1650_IsExec() asm("_ZN2YS5EVENT6IsExecEv");
void W1650_LockOn_show() asm("_ZN2dk6LockOn4showEv");
void W1650_FPSCamera_adjust() asm("_ZN2dk9FPSCamera6adjustEv");
s32 YS__TARGET__each(W1650Tgt*, s32);
s32 func_00135c88(void*, s32);
s32 func_00135d00(void*, s32);
void func_00135bd0(void*, s32);
void dk__LockOn__end(W1650Lock*);
W1650Lock* func_0013e610(s32);
W1650QW func_00190388(W1650Tgt*);
W1650QW func_0011a858(W1650Fps*);
static inline s32 W1650_next(void* obs, s32 prev) {
    s32 i = 0;
    if (prev != 0) {
        i = func_00135c88(obs, prev);
        i = i < 0 ? 0 : i + 1;
    }
    return i;
}
static inline bool W1650_valid(W1650Tgt* t) { return W1650_is_exist(t) && t->a != 0; }
void func_0011ac10(W1650Fps* self);  // 0x0011ac10: definition moved into src/anon/unit_0011a660.cpp
}
