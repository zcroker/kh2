#include "../common/types.h"

namespace w1805_a {
struct B;
struct A { s32 x; s32 y; B* b; s32 z; };
struct B { A* a; s32 p; s32 q; s32 r; u8 pad[28]; };
struct R { u8 pad[8]; s32 m8; s32 m12; };
}

namespace w1805_b {
struct Sub { u8 pad[16]; f32 a; f32 c; f32 b; Sub* link; };
struct Ent { s32 x; u8* base; s32 y; s32 z; };
struct Mgr { u8 pad[0x80]; Ent* ents; u8 pad2[0xa8 - 0x84]; u64 flags; };
struct In { s32 id; f32 f4; f32 f8; f32 f12; s32 idx; s32 off; };
struct Obj { u8 pad[12]; s32 id; };
struct Ctx { u8 pad[12]; s32* off; };
}

extern "C" {
extern w1805_a::A D_0034d800[];
extern w1805_a::B D_01c6cf00[];
w1805_a::R* func_001ae460();

w1805_a::A* func_001ae6a8();  // 0x001ae6a8: definition moved into src/anon/unit_001ada38.cpp

extern w1805_b::Mgr* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e8;
extern w1805_b::Sub D_01d9e360;
void func_002226b8(w1805_b::Sub*, u8*);

void func_001f4eb8(w1805_b::Obj* obj, w1805_b::In* in, w1805_b::Ctx* ctx);  // 0x001f4eb8: definition moved into src/anon/unit_001f45f8.cpp
}
