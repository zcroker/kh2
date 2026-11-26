#include "../common/types.h"

// Script-command handler near the motion code (0x1892d8).

// Three bit masks at obj+0xabc.
struct W1645Masks {
    u32 m0;
    u32 m1;
    u32 m2;
    void set1(s32 i) { m1 |= 1 << i; }
    void set2(s32 i) { m2 |= 1 << i; }
};

// Game object (only the fields this file touches).
struct W1645Obj {
    u8 pad0[0xf0];
    f32 ff0;                  // 0xf0
    u8 padF4[0x3b4 - 0xf4];
    u8 sub3b4[0x474 - 0x3b4]; // 0x3b4
    u8 sub474[0x50c - 0x474]; // 0x474
    s32 x50c;                 // 0x50c
    u8 pad510[0x588 - 0x510];
    u32 flags588;             // 0x588
    u8 pad58C[0xabc - 0x58c];
    W1645Masks masks;         // 0xabc
} __attribute__((aligned(16)));

// Script command block (8+ bytes).
struct W1645Cmd {
    u8 pad0[4];
    u8 op;      // +4
    u8 argc;    // +5
    union {
        u16 a;  // +6
        u8 a_b[2];
    };
    u16 b;      // +8
    u16 c;      // +10
};

struct W1645Ctx {
    u8 pad0[8];
    W1645Obj* obj;  // +8
    u8 padC[0x14 - 0xc];
    s32 x14;        // +0x14
    u8 pad18[0x20 - 0x18];
    u32 f20;        // +0x20
    u32 f24;        // +0x24
    u32 f28;        // +0x28
    u8 pad2c[0xf8 - 0x2c];
    u8 bf8;         // +0xf8
};

extern "C" {
void func_0019f490(void*, u16);
void func_0019f4b8(void*, u16);
void func_0019f610(void*, u16, u16);
void W1645_Ctarget(void*, u32, u32) asm("_Z16ctarget_0019f670jjjj");
void func_00198ae0(W1645Obj*, u16, u16, u16);
void YS__ANMATR__ReactionCommand(W1645Obj*, u16, u16);
s32 func_00187400(W1645Obj*, f32);
s32 YS__BTLOBJ__turn_to_lockon_range(W1645Obj*, f32);
void func_001940a0(W1645Obj*, u16);
void func_00198aa8(W1645Obj*, u16, u16, u16);

static inline u32 W1645_F588(W1645Obj* o) { return o->flags588 & 1; }
static inline bool W1645_Flag588b0(W1645Obj* o) { return (u8)W1645_F588(o); }

void YS__ANMATR__CheckRangeCallback(W1645Cmd* cmd, W1645Ctx* ctx);  // 0x001892d8: definition moved into src/anon/unit_00188848.cpp
}
