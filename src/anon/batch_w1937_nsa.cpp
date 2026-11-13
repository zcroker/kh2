#include "../common/types.h"

namespace w1937_a {
struct W1937Obj;
struct W1937Msk { s32 m0, m1, m2; };
struct W1937VT {
    u8 pad[0x58];
    s32 (*f58)(W1937Obj*);
    u8 pad2[0x78 - 0x5c];
    s32 (*f78)(W1937Obj*, s32, u8, s32);
};
struct W1937Ent { s32 a; s32 b; s32 c; };
struct W1937Obj {
    W1937VT* vt;
    u8 pad[0x48c - 4];
    W1937Ent* ents;
    u8 pad2[0xabc - 0x490];
    W1937Msk m;
};
struct W1937Kind { u8 pad[4]; u8 k; u8 pad2[0x12 - 5]; u8 fl; };
struct W1937Owner { u8 pad[0xc]; W1937Obj* o; };
struct W1937Arg {
    u8 pad[0x18];
    s32 flags;
    W1937Owner* own;
    W1937Kind* kind;
    u8 pad2;
    u8 idx;
    u8 pad3[2];
    s32 val;
};
static inline u8 w1937_isKind(W1937Kind* k) { return k->k == 5 || k->k == 6; }
extern "C" {
s32 func_0018caf8(W1937Arg*);
s32 func_0018cef8(W1937Arg*);
// 00186d48: moved to src/anon/unit_00185d10.cpp
void func_00186d48(W1937Obj* self, W1937Arg* a);
}
}

namespace w1937_b {
struct W1937V4 { f32 v[4]; };
extern "C" {
f32 func_002f8b30(f32, f32);
// 0017d748: moved to src/anon/unit_0017c400.cpp
}
}
