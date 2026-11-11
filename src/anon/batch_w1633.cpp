#include "../common/types.h"
extern "C" {
struct W1633Sprite {
    u8 pad0[0x188];
    s32 id;             // 0x188
    W1633Sprite* parent;// 0x18c
    s32 flag;           // 0x190
    u8 pad1[8];
};
struct W1633Gauge {
    u8 pad0[0x20];
    u8 barA[0x120];     // 0x20
    u8 barB[0x100];     // 0x140
    W1633Sprite* parent;// 0x240
    u8 pad1[0xc];
};
struct W1633Owner2 { u8 pad[0x250]; u32 flags; };
struct W1633Owner { u8 pad[0x48c]; W1633Owner2* sub; };
struct W1633Hud {
    u8 pad0[0x18];
    u32 f18;                    // 0x18
    u8 pad1[0x34 - 0x1c];
    W1633Owner* owner;          // 0x34
    u8 pad2[8];
    W1633Sprite header;         // 0x40
    u8 pad3[0x1a30 - 0x1dc];
    W1633Sprite spr[12];        // 0x1a30
    u8 pad4[0x33b0 - 0x2d80];
    W1633Gauge gauge[4];        // 0x33b0
    u8 pad5[0x3cf0 - 0x3cf0];
    s32 f3cf0;                  // 0x3cf0
    s8 b3cf4, b3cf5, b3cf6, b3cf7, b3cf8, b3cf9, b3cfa, b3cfb;
};
void func_0013e0f8(W1633Gauge*, u32, u32, u32);
void func_00158050(W1633Sprite*, u32, u32, u32, u32, u32, u32);
void func_00139d78(void*);
void func_0014b200(void*, u32);
void func_00139598(void*);

// HUD gauge panel (owner of 3 gauges + icon sprites): create gauge bars and icons.
// 001565c0: moved to src/anon/unit_00153ea0.cpp
void func_001565c0(W1633Hud* self, u32 a1, u32 a2, u32 a3);
}
