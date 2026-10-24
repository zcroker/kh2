#include "../common/types.h"

// 00194218: per-object sound handles (one s32 per index, 8 bytes into the block at +0x7b0).
struct W2368Snd { u8 pad[0xc]; f32 vol; };
struct W2368Slot { u8 pad[8]; s32 h; };
struct W2368Obj { u8 pad0[0x9c]; u8 res[0x7b0 - 0x9c]; s32 arr[8]; };

extern "C" {
s32 func_001de168(void*, s32, s32, s32, s32, W2368Obj*);
W2368Snd* func_001dc670(s32);
void func_001dc920(s32);

static inline W2368Slot* w2368_slot(W2368Obj* o, s32 i) { return (W2368Slot*)(i * 4 + (u32)o + 0x7b0); }

// v > 0: start sound i if needed and scale its volume by v; otherwise stop it.
void func_00194218(W2368Obj* o, s32 i, f32 v) {
    if (v > 0.0f) {
        if (w2368_slot(o, i)->h == 0) w2368_slot(o, i)->h = func_001de168(o->res, i, 0, 1, 0, o);
        func_001dc670(w2368_slot(o, i)->h)->vol *= v;
    } else if (w2368_slot(o, i)->h) {
        func_001dc920(w2368_slot(o, i)->h);
        w2368_slot(o, i)->h = 0;
    }
}
}
