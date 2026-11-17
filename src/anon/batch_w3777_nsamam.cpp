#include "../common/types.h"
extern "C" {
struct Clip { u8 pad[8]; u16 n; u16 pad2; u8 data[1]; };
struct ClipRef { Clip* clip; s32 b; };
struct Obj { u8 pad[6]; u16 start; u16 end; };
struct Ent { Obj* o; ClipRef* r; s32 w; };
struct V4 { f32 x, y, z, w; };
struct S2 { f32 a, b; };
extern Ent* D_0035dcec;
extern s32 D_0035de20;
extern f32 D_0035de1c;
void func_001ba028(s32);
void func_0016ace0(s32, V4*);
void func_0016aeb8(s32, f32);
s32 func_002302c0(f32, s32, V4*, S2*);
f32 func_00230f10(f32, void*, u32, s32);
}

// Updates the 64 clip players: drops finished ones, samples active ones at the current time and applies the pose.
extern "C" {
void func_002306a8(void);  // 0x002306a8: definition moved into src/anon/unit_002302c0.cpp
}
