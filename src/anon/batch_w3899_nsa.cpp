#include "../common/types.h"
extern "C" {
struct K850 { u16 type:4; s16 off:12; };
struct Anim850 { u8 pad[4]; u16 n; };
struct Obj850 {
    u8 pad0[0x14]; u32 flags; f32 speed; u8 pad1[4]; Obj850* link;
    u8 pad2[0x274 - 0x24]; s32 f274; u8* base; K850* cur; f32 dur; f32 time;
};
Anim850* func_00132c68(Obj850*);
void func_00132720(Obj850*, s32);
u32 func_00106520(u16, s32);

// Advance an object's key-frame cursor by dt * speed. A linked object copies
// the cursor and timing of its link. Type-2 keys jump, type-3 keys stop.
// Partial asm: the f0..f3 pins and empty "+f" ties keep the loop values in
// the original's FP registers and keep its mov.s copies; the .p2align gives
// the original's aligned loop head (the goto loop has no loop notes, so the
// li 2/li 3 constants stay in the loop as in the original).
void func_00132850(Obj850* o, f32 dt);  // 0x00132850: definition moved into src/anon/unit_00131418.cpp
}
