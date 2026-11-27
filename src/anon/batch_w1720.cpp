#include "../common/types.h"

struct W1720Rec { s32 w[5]; };
struct W1720Flags { u8 pad0[8]; u64 flags; };
struct W1720Owner { u8 pad0[0xb38]; W1720Flags* xb38; };
struct W1720Ent { u8 pad0[8]; u64 flags; u8 pad10[0x10]; u8 x20[4]; };
struct W1720Obj {
    s32 state;
    W1720Rec rec;
    s32 x18;
    f32 timer;
    u8 pad20[8];
    W1720Owner* owner;
};

extern "C" {
extern f32 D_00349e10;
void func_00190128(W1720Rec*);
s32 func_00190140(W1720Rec*);
void func_00190920(W1720Rec*, s32, W1720Owner*);
W1720Rec func_00190d10(f32, W1720Rec*, W1720Owner*);
W1720Rec func_001913d8(W1720Rec*, W1720Owner*, void*);
W1720Ent* func_00167bf0(s32);
s32 func_0019bb58(s32);
s32 YS__OBJ__can_lockon(s32);
void func_0019ca90(W1720Obj*, s32, W1720Rec*);
void YS__LOCKON__release(W1720Obj*);
void func_0019cc88(W1720Obj*, W1720Rec*);
s32 func_0019d4a8(W1720Obj*);
void func_002ba2e8(s32, s32);
void func_002c0688(W1720Owner*, W1720Rec*);
void func_0015a6c8(W1720Rec*);

void func_0019ce48(W1720Obj* self);  // 0x0019ce48: definition moved into src/anon/unit_0019ba60.cpp
}
