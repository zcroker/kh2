#include "../common/types.h"

struct W1639Sprite {
    u8 pad0[0x188];
    s32 on188;
    s32 on18c;
    s32 on190;
};

struct W1639Cmd {
    u8 pad0[0xcc];
    s32 cursor[4];     // 0xcc
    s32 count[4];      // 0xdc
};

struct W1639Entry {
    u8 pad0[2];
    u16 id;            // +2
    u8 pad4;
    u8 kind;           // +5
    u8 pad6[6];
};

struct W1639Menu {
    s32 type;          // 0x00
    u8 pad4[4];
    s32 count;         // 0x08
    W1639Entry ent[8]; // 0x0c
    s32 sel;           // 0x6c
};

extern "C" {
extern s32 D_00348060[];
u8* func_0013bb58(W1639Cmd*, W1639Menu*, s32, s32, u8, s32, s32);
u8* func_001b8e88(u16);
void func_0013c080(W1639Cmd*, W1639Entry*, s32, s32, u8*, s32, s32*, s32*);
s32 func_00192048(s32);
s32 func_0013b988(W1639Cmd*, W1639Menu*, s32, s32, s32, s32);
W1639Sprite* func_0013b5d0(f32, W1639Cmd*, s32, s32, void*, u8, s32, s32, s32, s32, s32);
void func_0013c190(W1639Cmd*, W1639Menu*, s32, s32, u8, s32, s32, s32, W1639Entry*);
s32 func_0013bc40(W1639Cmd*, s32);
void func_0013ce08(W1639Cmd*, s32);

// Draws one column of a menu: one sprite per entry, the selected entry is passed to func_0013c190.
void func_0013c3b8(W1639Cmd* self, W1639Menu* m, s32 slot, s32 col, u8 force);  // 0x0013c3b8: definition moved into src/anon/unit_0013a8b8.cpp
}
