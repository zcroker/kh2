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
void func_00189e18(W1645Obj*, u16, u16);
s32 func_00187400(W1645Obj*, f32);
s32 func_001874a0(W1645Obj*, f32);
void func_001940a0(W1645Obj*, u16);
void func_00198aa8(W1645Obj*, u16, u16, u16);

static inline u32 W1645_F588(W1645Obj* o) { return o->flags588 & 1; }
static inline bool W1645_Flag588b0(W1645Obj* o) { return (u8)W1645_F588(o); }

void func_001892d8(W1645Cmd* cmd, W1645Ctx* ctx)
{
    W1645Obj* obj = ctx->obj;
    switch (cmd->op) {
    case 0: ctx->f20 |= 0x4; break;
    case 1: ctx->f20 |= 0x8; break;
    case 2: ctx->f20 |= 0x10; break;
    case 3: ctx->f20 |= 0x20; break;
    case 4: func_0019f490(obj->sub474, cmd->a); break;
    case 5: func_0019f4b8(obj->sub474, cmd->a); break;
    case 6: func_0019f610(obj->sub3b4, cmd->a, cmd->b); break;
    case 7: W1645_Ctarget(obj->sub3b4, cmd->a, cmd->b); break;
    case 9: ctx->f20 |= 0x200; break;
    case 10: if (W1645_Flag588b0(obj)) func_00198ae0(obj, cmd->a, cmd->b, 0); break;
    case 11: ctx->f20 |= 0x400; break;
    case 12: ctx->f20 |= 0x800; break;
    case 13: ctx->f20 |= 0x8000; break;
    case 14: ctx->f20 |= 0x80000; break;
    case 15: ctx->f20 |= 0x10000; break;
    case 16: ctx->bf8 |= 0x1; break;
    case 17: ctx->bf8 |= 0x2; break;
    case 18: ctx->bf8 |= 0x4; break;
    case 19: ctx->bf8 |= 0x8; break;
    case 20: {
        func_00189e18(obj, cmd->a, (cmd->argc < 2) ? 0 : cmd->b);
        break;
    }
    case 21: ctx->f20 |= 0x40000; break;
    case 22:
        if (obj->flags588 & 2) {
            if (func_00187400(obj, cmd->a * 0.017453292f)) ctx->f28 |= 0x8;
        }
        break;
    case 23: func_001940a0(obj, cmd->a); break;
    case 24:
        ctx->f20 |= 0x40;
        obj->ff0 = cmd->a * 0.01f;
        break;
    case 25:
        ctx->f20 |= 0x100000;
        obj->x50c = cmd->a;
        break;
    case 26:
        ctx->f20 |= 0x200000;
        obj->x50c = cmd->a;
        break;
    case 27: ctx->f20 |= 0x400000; break;
    case 28:
        if (obj->flags588 & 2) {
            if (func_001874a0(obj, cmd->a * 0.017453292f)) ctx->f28 |= 0x8;
        }
        break;
    case 29: ctx->f20 |= 0x800000; break;
    case 30: ctx->f20 |= 0x1000000; break;
    case 31: ctx->f20 |= 0x2000000; break;
    case 32: ctx->f20 |= 0x4000000; break;
    case 33: if (W1645_Flag588b0(obj)) func_00198ae0(obj, cmd->a, cmd->b, cmd->c); break;
    case 34: ctx->f20 |= 0x8000000; break;
    case 35: if (cmd->a == ctx->x14) ctx->f20 |= 0x400; break;
    case 36: if (obj->flags588 & 2) obj->masks.set1(cmd->a); break;
    case 37: if (obj->flags588 & 2) obj->masks.set2(cmd->a); break;
    case 38: ctx->f20 |= 0x10000000; break;
    case 39: ctx->f20 |= 0x20000000; break;
    case 40: ctx->f20 |= 0x40000000; break;
    case 41: ctx->f20 |= 0x80000000; break;
    case 42: ctx->f24 |= 0x1; break;
    case 44: ctx->f24 |= 0x2; break;
    case 45: ctx->f28 |= 0x1; break;
    case 46: ctx->f28 |= 0x2; break;
    case 47: ctx->f28 |= 0x4; break;
    case 49: ctx->f28 |= 0x10; break;
    case 50: ctx->f28 |= 0x20; break;
    case 51: {
        u16 c = 0;
        if (cmd->argc >= 3) c = cmd->c;
        func_00198aa8(obj, cmd->a, cmd->b, c);
        break;
    }
    case 52: ctx->f28 |= 0x40; break;
    case 53: ctx->f28 |= 0x80; break;
    }
}
}
