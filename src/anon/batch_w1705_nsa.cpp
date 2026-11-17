#include "../common/types.h"

// 0023de00: per-frame update of the owner's animated props (idle/action motion cycling + matrix build).
// Needs -fno-strict-aliasing (state/time stores stay before the vtable-pointer reloads).

struct W1705Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1705Mtx { W1705Vec r[4]; };

struct W1705Motion {
    virtual void v0();
    virtual void v1();
    virtual s32 GetEnd();      // +0x08
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual f32 GetStart();    // +0x1c
};

struct W1705Prop {
    W1705Vec rot;          // 0x00 degrees
    W1705Vec pos;          // 0x10
    W1705Vec scale;        // 0x20
    s32 model;             // 0x30
    u8 pad34[0x74 - 0x34];
    W1705Motion* idle;     // 0x74
    W1705Motion* act1;     // 0x78
    W1705Motion* act2;     // 0x7c
    W1705Mtx mtx;          // 0x80
    u8 padC0[0x128 - 0xc0];
    s32 state;             // 0x128
    f32 time;              // 0x12c
    f32 wait;              // 0x130
    f32 waitMax;           // 0x134
    u8 pad138[4];
    u8 active;             // 0x13c
    u8 pad13d[3];

};

struct W1705Owner {
    u8 pad0[0x660];
    W1705Prop props[4];         // 0x660
    u8 padB5C[0xb64 - (0x660 + 4 * 0x140)];
    u8 propIdx[8];              // 0xb64
    s32 count;                  // 0xb6c
    u8 padB70[0x14b0 - 0xb70];
    s32 handleA[4];             // 0x14b0
    s32 handleB[4];             // 0x14c0
};

extern "C" {
s32 func_001064a8(s32);
void func_0011b6a8(W1705Mtx*);
void func_0011b7b0(W1705Mtx*, W1705Vec*);
void func_0011c4e8(f32, s32, W1705Mtx*, W1705Motion*, s32, s32, s32);
void func_0011ea40(f32, s32);
u8 u_call4_00139d78(s32) asm("_Z16u_call4_00139d78jjjj");
f32 func_0014ce78(void);
void func_0023d820(W1705Owner*);
f32 func_0023e700(W1705Owner*);

void func_0023de00(W1705Owner* o);  // 0x0023de00: definition moved into src/anon/unit_0023d260.cpp
}
