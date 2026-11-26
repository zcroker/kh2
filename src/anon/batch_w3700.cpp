#include "../common/types.h"
struct QW2d3 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Sub2d3 { u8 pad[24]; s16 h; };
struct Act2d3 {
    u8 p0[1416]; u32 flags;            /* 0x588 */
    u8 p1[2040 - 1420]; u32 f7f8;      /* 0x7f8 */
    u8 p2[2092 - 2044]; u8 snd[2780 - 2092]; f32 fadc; /* 0x82c, 0xadc */
    u8 p3[2808 - 2784]; Sub2d3* sub;   /* 0xaf8 */
    u8 p4[2936 - 2812]; f32 fb78; u8 p5[4]; u8 bb80; /* 0xb78, 0xb80 */
};
struct Hit2d3 { u8 pad[16]; Act2d3* other; };
static inline u8 IsPos2d3(f32 v) { return v > 0.0f; }
void func_001ad990(void*, f32, f32, f32);
extern "C" {
void YS__OBJ__get_target_pos(QW2d3*, Act2d3*) asm("_Z23YS__OBJ__get_target_posjjjj");
void YS__BTLOBJ__set_hitback(Act2d3*, QW2d3*, f32) asm("_Z23YS__BTLOBJ__set_hitbackjjjj");
void func_0016ac38(Act2d3*, s32, s32, s32, s32);
f32 fabsf(f32);
void Ti__MGOarashiGimObj__exec_damage_self(Act2d3* a, Hit2d3* h);  // 0x002d39c8: definition moved into src/anon/unit_002d2498.cpp
}


struct W1640Info {
    u16 flags;
    u16 id;
    u8 pad4;
    u8 kind;
};

struct W1640Owner {
    u8 pad0[0xa1c];
    W1640Info info;
};

struct W1640Cmd {
    u8 pad0[0xf0];
    s32 lastId;
    s32 lastCol;
    u8 padF8[0xfc - 0xf8];
    u8 active;
    u8 padFD;
    u8 flash;
    u8 padFF;
    s32 tag;
    u8 pad104[0x29c - 0x104];
    W1640Owner* owner;
    u8 pad2a0[4];
    s32 unk2A4;
};

struct W1640Spr {
    u8 pad0[0x110];
    s32 unk110;
    u8 pad114[0x198 - 0x114];
};

struct W1640Pool {
    u8 pad0[0x3300];
    s32 freeIdx[32];
    s32 nFree;
};

extern "C" {

extern s32 D_00348548[][6];
extern s32 D_003484f8[];
extern f32 D_0036ad70[];
extern W1640Pool* D_00348054;
s32 func_0013cb90(void);
s32 func_0013cb80(void);
s32 func_0013cb30(void);
u8* YS__COMMAND_ELEM__Get(u32);
u32 func_00192048(u32);
void* func_0013b5d0(W1640Cmd*, s32, s32, void*, u32, s32, s32, u32, f32, u32, s32);
void func_00139580(void*);
void func_00139570(void*);
void func_00139740(void*);
s32 func_001396c0(void*);
void func_0013cdc8(W1640Cmd*, void*);
void dk__Sprite__create(W1640Spr*, s32, s32, s32, s32, s32);
void func_00138c40(W1640Spr*, s32, s32);
f32 func_0013b2e8(void);
void func_00138d48(f32, f32, f32, f32, W1640Spr*);

static inline __attribute__((always_inline)) W1640Spr* W1640_Alloc(void)
{
    W1640Pool* o = D_00348054;
    o->nFree--;
    return (W1640Spr*)((u8*)o + o->freeIdx[o->nFree] * 0x198);
}

void func_0013ce08(W1640Cmd* self, s32 n);  // 0x0013ce08: definition moved into src/anon/unit_0013a8b8.cpp

}
