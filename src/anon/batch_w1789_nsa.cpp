#include "../common/types.h"

struct W1789Ctx { u32 v; };
struct W1789Node { u8 pad[0x24]; W1789Node* next; };
struct W1789List { u8 pad[0xc]; W1789Node* head; u8 pad2[0x30 - 0x10]; W1789Ctx ctx; s32 count; };
struct W1789Vec { u8 b[16]; };
struct W1789Obj { u8 pad[0x7f8]; u32 flags; u8 pad2[0xb70 - 0x7fc]; s32 state; };

extern "C" {
s32 func_001c18d0(W1789Node*);
void func_001c1a30(W1789Node*, W1789Ctx*);
void func_001c1890(W1789Node*);
void func_001c16a0(W1789List*, s32);

// 001c1428: moved to src/anon/unit_001c0638.cpp
void func_001c1428(W1789List* l);

void YS__OBJ__get_dir(W1789Vec*, W1789Obj*);
void YS__MATH__VectorRotY(W1789Vec*, W1789Vec*, f32);
void func_0016aef0(W1789Obj*, W1789Vec*);
void YS__PLAYER___OVR_exec(W1789Obj*);

void func_001ceef8(W1789Obj* p);  // 0x001ceef8: definition moved into src/anon/unit_001ce6e8.cpp
}
